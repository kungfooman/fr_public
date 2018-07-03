#include "../imgui/include_imgui.h"
#include "all_wz4.h"

// custom docks
#include "dock_portaudio.h"
#include "../imgui_docks/dock_console.h"
#include <portaudio.h>



#define PINK_MAX_RANDOM_ROWS   (30)
#define PINK_RANDOM_BITS       (24)
#define PINK_RANDOM_SHIFT      ((sizeof(long)*8)-PINK_RANDOM_BITS)

typedef struct
{
	long      pink_Rows[PINK_MAX_RANDOM_ROWS];
	long      pink_RunningSum;   /* Used to optimize summing of generators. */
	int       pink_Index;        /* Incremented each sample. */
	int       pink_IndexMask;    /* Index wrapped by ANDing with this mask. */
	float     pink_Scalar;       /* Used to scale within range of -1.0 to +1.0 */
}
PinkNoise;

/* Prototypes */
static unsigned long GenerateRandomNumber(void);
void InitializePinkNoise(PinkNoise *pink, int numRows);
float GeneratePinkNoise(PinkNoise *pink);

/************************************************************/
/* Calculate pseudo-random 32 bit number based on linear congruential method. */
static unsigned long GenerateRandomNumber(void)
{
	/* Change this seed for different random sequences. */
	static unsigned long randSeed = 22222;
	randSeed = (randSeed * 196314165) + 907633515;
	return randSeed;
}

/************************************************************/
/* Setup PinkNoise structure for N rows of generators. */
void InitializePinkNoise(PinkNoise *pink, int numRows)
{
	int i;
	long pmax;
	pink->pink_Index = 0;
	pink->pink_IndexMask = (1 << numRows) - 1;
	/* Calculate maximum possible signed random value. Extra 1 for white noise always added. */
	pmax = (numRows + 1) * (1 << (PINK_RANDOM_BITS - 1));
	pink->pink_Scalar = 1.0f / pmax;
	/* Initialize rows. */
	for (i = 0; i<numRows; i++) pink->pink_Rows[i] = 0;
	pink->pink_RunningSum = 0;
}

#define PINK_MEASURE
#ifdef PINK_MEASURE
float pinkMax = -999.0;
float pinkMin = 999.0;
#endif

/* Generate Pink noise values between -1.0 and +1.0 */
float GeneratePinkNoise(PinkNoise *pink)
{
	long newRandom;
	long sum;
	float output;
	/* Increment and mask index. */
	pink->pink_Index = (pink->pink_Index + 1) & pink->pink_IndexMask;
	/* If index is zero, don't update any random values. */
	if (pink->pink_Index != 0)
	{
		/* Determine how many trailing zeros in PinkIndex. */
		/* This algorithm will hang if n==0 so test first. */
		int numZeros = 0;
		int n = pink->pink_Index;
		while ((n & 1) == 0)
		{
			n = n >> 1;
			numZeros++;
		}
		/* Replace the indexed ROWS random value.
		* Subtract and add back to RunningSum instead of adding all the random
		* values together. Only one changes each time.
		*/
		pink->pink_RunningSum -= pink->pink_Rows[numZeros];
		newRandom = ((long)GenerateRandomNumber()) >> PINK_RANDOM_SHIFT;
		pink->pink_RunningSum += newRandom;
		pink->pink_Rows[numZeros] = newRandom;
	}

	/* Add extra white noise value. */
	newRandom = ((long)GenerateRandomNumber()) >> PINK_RANDOM_SHIFT;
	sum = pink->pink_RunningSum + newRandom;
	/* Scale to range of -1.0 to 0.9999. */
	output = pink->pink_Scalar * sum;
#ifdef PINK_MEASURE
	/* Check Min/Max */
	if (output > pinkMax) pinkMax = output;
	else if (output < pinkMin) pinkMin = output;
#endif
	return output;
}


/* Context for callback routine. */
typedef struct
{
	PinkNoise   leftPink;
	PinkNoise   rightPink;
	unsigned int sampsToGo;
}
paTestData;

/* This routine will be called by the PortAudio engine when audio is needed.
** It may called at interrupt level on some machines so don't do anything
** that could mess up the system like calling malloc() or free().
*/
static int patestCallback(const void*                     inputBuffer,
	void*                           outputBuffer,
	unsigned long                   framesPerBuffer,
	const PaStreamCallbackTimeInfo* timeInfo,
	PaStreamCallbackFlags           statusFlags,
	void*                           userData)
{
	int finished;
	int i;
	int numFrames;
	paTestData *data = (paTestData*)userData;
	float *out = (float*)outputBuffer;
	(void)inputBuffer; /* Prevent "unused variable" warnings. */

					   /* Are we almost at end. */
	if (data->sampsToGo < framesPerBuffer)
	{
		numFrames = data->sampsToGo;
		finished = 1;
	}
	else
	{
		numFrames = framesPerBuffer;
		finished = 0;
	}
	for (i = 0; i<numFrames; i++)
	{
		*out++ = GeneratePinkNoise(&data->leftPink);
		*out++ = GeneratePinkNoise(&data->rightPink);
	}
	data->sampsToGo -= numFrames;
	return finished;
}

void startPinkNoise() {
	PaStream*           stream;
	PaError             err;
	paTestData          data;
	PaStreamParameters  outputParameters;
	int                 totalSamps;
	static const double SR = 44100.0;
	static const int    FPB = 2048; /* Frames per buffer: 46 ms buffers. */

									/* Initialize two pink noise signals with different numbers of rows. */
	InitializePinkNoise(&data.leftPink, 12);
	InitializePinkNoise(&data.rightPink, 16);

	/* Look at a few values. */
	{
		int i;
		float pink;
		for (i = 0; i<20; i++)
		{
			pink = GeneratePinkNoise(&data.leftPink);
			imgui_log("Pink = %f\n", pink);
		}
	}

	data.sampsToGo = totalSamps = (int)(60.0 * SR);   /* Play a whole minute. */
	err = Pa_Initialize();
	//if (err != paNoError) goto error;

	/* Open a stereo PortAudio stream so we can hear the result. */
	outputParameters.device = Pa_GetDefaultOutputDevice(); /* Take the default output device. */
	if (outputParameters.device == paNoDevice) {
		imgui_log("Error: No default output device.\n");
		//goto error;
		return;
	}
	outputParameters.channelCount = 2;                     /* Stereo output, most likely supported. */
	outputParameters.hostApiSpecificStreamInfo = NULL;
	outputParameters.sampleFormat = paFloat32;             /* 32 bit floating point output. */
	outputParameters.suggestedLatency =
		Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
	err = Pa_OpenStream(&stream,
		NULL,                              /* No input. */
		&outputParameters,
		SR,                                /* Sample rate. */
		FPB,                               /* Frames per buffer. */
		paClipOff, /* we won't output out of range samples so don't bother clipping them */
		patestCallback,
		&data);
	if (err != paNoError) {
		return;
		//goto error;
	}

	err = Pa_StartStream(stream);
	if (err != paNoError) {
		//goto error;
		return;
	}

	imgui_log("Stereo pink noise for one minute...\n");


	while ((err = Pa_IsStreamActive(stream)) == 1) Pa_Sleep(100);
	//if (err < 0) goto error;
}


DockPortaudio::DockPortaudio() {}

const char *DockPortaudio::label() {
	return "Portaudio";
}

#include <Windows.h>

DWORD WINAPI thread_portaudio(LPVOID lpParam)
{
	startPinkNoise();
	return 0;
}

void DockPortaudio::imgui() {
	//depth = 0;
	ImGui::Text("Root=%p", 321);
	if (ImGui::Button("startPinkNoise()")) {
		CreateThread(NULL, 0, thread_portaudio, 0, 0, 0);
	}


}
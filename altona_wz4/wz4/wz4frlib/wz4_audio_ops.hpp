/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_audio_ops
#define HEADER_WZ4OPS_wz4_audio_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "wz4_audio_ops.ops"

#include "wz4lib/poc_ops.hpp"
#include "wz4lib/basic_ops.hpp"
#include "wz4frlib/wz4_audio.hpp"
#include "wz4frlib/wz3_bitmap_ops.hpp"

#line 24 "wz4_audio_ops.hpp"
struct PocBitmapParaAudioRMS
{
  sInt Width;
  sInt Height;
  sInt ChunkSize;
};

struct PocBitmapParaAudioSpectogram
{
  sInt Width;
  sInt FFTSize;
};


/****************************************************************************/

struct PocBitmapAnimAudioRMS
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,PocBitmapParaAudioRMS *para);

};

struct PocBitmapAnimAudioSpectogram
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,PocBitmapParaAudioSpectogram *para);

};


/****************************************************************************/

void AddTypes_wz4_audio_ops(sBool secondary=0);
void AddOps_wz4_audio_ops(sBool secondary=0);

/****************************************************************************/

#endif

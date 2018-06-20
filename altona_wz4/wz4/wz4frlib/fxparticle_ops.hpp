/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fxparticle_ops
#define HEADER_WZ4OPS_fxparticle_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4ExplosionType_ *Wz4ExplosionType;

/****************************************************************************/

#line 9 "fxparticle_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 22 "fxparticle_ops.hpp"
class Wz4ExplosionType_ : public AnyTypeType_
{
public:
  Wz4ExplosionType_() { Parent = AnyTypeType; Color= 0xffff7800; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"Wz4Explosion"; Label = L"Wz4 Explosion";  Init(); }
  ~Wz4ExplosionType_() { Exit(); }
#line 120 "fxparticle_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 31 "fxparticle_ops.hpp"
};

struct Wz4ParticlesParaCloud
{
  sInt Count;
  sF32 CloudSize[2];
  sF32 CloudFreq[2];
  sVector30 CloudPos;
};

struct Wz4ParticlesParaBallistic
{
  sInt Count;
  sInt Seed;
  sInt CreateFlags;
  sVector30 Gravity;
  sVector31 PosStart;
  sVector30 PosRand;
  sVector30 SpeedStart;
  sVector30 SpeedRand;
  sF32 BurstPercent;
  sInt TimeFlags;
  sF32 LifeTime;
  sF32 Delay;
};

struct Wz4ParticlesParaMesh
{
};

struct Wz4ExplosionParaExplosion
{
  sVector31 Position;
  sF32 Falloff;
  sVector30 SpeedConstant;
  sVector30 SpeedExplode;
  sVector30 SpeedRandom;
  sInt TimingFlags;
  sVector31 IgnitionPos;
  sF32 IgnitionTime;
  sF32 IgnitionRand;
  sF32 IgnitionSpeed;
  sVector30 Shape;
  sVector30 Rotation;
  sF32 DistancePower;
  sF32 TimeMin;
  sF32 TimeMax;
};

struct Wz4ParticlesParaExploder
{
  sInt Seed;
  sVector30 Gravity;
  sF32 Density;
  sF32 MaxAngularVelocity;
  sF32 AirDrag;
  sF32 RotationAirDrag;
};

struct Wz4ParticlesParaCloud2
{
  sF32 Speed;
  sF32 SpeedSpread;
};

struct Wz4ParticlesArrayCloud2
{
  sVector30 Pos;
  sVector30 Scale;
  sF32 Speed;
  sF32 Rot;
  sInt Count;
};

struct Wz4ParticlesParaFromVertex
{
  sF32 Random;
  sInt RandomSeed;
  sInt Selection;
};

struct Wz4ParticlesParaWobble
{
  sInt Source;
  sInt Function;
  sVector31 Freq;
  sVector30 Amp;
  sInt Seed;
  sVector30 Phase;
  sF32 Spread;
  sF32 TimeFactor;
  sF32 DeltaFactor;
};

struct Wz4ParticlesParaAdd
{
};

struct Wz4ParticlesParaLissajous
{
  sInt Count;
  sF32 Lifetime;
  sF32 Spread;
  sVector31 Scale;
  sInt Flags;
  sVector30 Tweak;
  sF32 LinearTwirl;
  sVector30 LinearStretch;
  sInt Seed;
  sF32 MasterPhase;
  sF32 TubeRandom;
  sF32 MasterScale;
  sF32 SpeedSpread;
  sF32 LinearTwist;
  sF32 Randomness;
  sVector31 Translate;
};

struct Wz4ParticlesArrayLissajous
{
  sInt Axis;
  sF32 Phase;
  sF32 Freq;
  sF32 Amp;
};

struct Wz4ParticlesParaSplinedParticles
{
  sInt Count;
  sF32 Lifetime;
  sF32 Spread;
  sVector31 Scale;
  sInt Flags;
  sVector30 Tweak;
  sF32 LinearTwirl;
  sF32 Epsilon;
  sF32 AltShift;
  sInt Seed;
  sF32 TubeRandom;
  sF32 Randomness;
  sF32 MasterPhase;
};

struct Wz4ParticlesParaTrails
{
  sInt Lifetime;
  sInt Count;
  sF32 Delta;
};

struct Wz4ParticlesParaStaticParticles
{
  sInt Flags;
};

struct Wz4ParticlesArrayStaticParticles
{
  sF32 Time;
  sVector31 Pos;
  sVector30 Rot;
  sU32 Color;
};

struct Wz4RenderParaSprites
{
  sVector31 Trans;
  sF32 Size;
  sF32 Aspect;
  sInt Mode;
  sU32 Color;
  sInt _pad7;
  sF32 RotStart;
  sF32 RotSpeed;
  sF32 RotRand;
  sF32 RotSpread;
  sF32 SizeRand;
  sInt GrowMode;
  sF32 FadeIn;
  sF32 FadeOut;
  sInt Renderpass;
  sF32 TexAnimSpeed;
  sF32 TexAnimRand;
  sInt GroupCount;
  sF32 NearFadeDistance;
  sF32 FarFadeDistance;
  sF32 FarFadeRange;
  sVector30 AlignDir;
  sInt FadeType;
};

struct Wz4RenderParaChunks
{
  sVector31 Trans;
  sF32 Scale;
  sInt Direction;
  sInt Seed;
  sF32 LookAhead;
  sVector30 RotStart;
  sVector30 RotSpeed;
  sVector30 RotRand;
  sInt UpVector;
  sF32 SpiralRand;
  sF32 SpiralSpeed;
  sF32 SpiralRandSpeed;
  sInt Renderpass;
  sInt LightEnv;
  sF32 AnimRand;
  sF32 AnimSpeed;
  sF32 AnimSpeedRand;
  sInt AnimDifferent;
  sF32 ScaleRand;
};

struct Wz4RenderParaDebris
{
  sInt Renderpass;
  sInt LightEnv;
};

struct Wz4RenderParaTrails
{
  sInt Count;
  sF32 Delta;
  sF32 Width;
  sInt LightEnv;
  sInt _pad4;
  sInt Orientation;
  sInt Renderpass;
  sVector30 Tweak;
  sInt TrailStep;
};

struct Wz4RenderParaMetaballs
{
  sInt Renderpass;
  sInt Peels;
  sVector31 Trans;
  sF32 Size;
  sInt Debug;
  sInt Flags;
};

struct Wz4RenderParaMarchingCubes
{
  sF32 GridSize;
  sF32 Influence;
  sF32 IsoValue;
  sInt LightEnv;
  sInt Renderpass;
  sInt BaseGrid;
  sInt Subdivide;
  sInt Multithreading;
};

struct Wz4RenderParaMarchingCubesColor
{
  sF32 GridSize;
  sF32 Influence;
  sF32 IsoValue;
  sInt LightEnv;
  sInt Renderpass;
  sInt BaseGrid;
  sInt Subdivide;
  sInt Multithreading;
};

struct Wz4ParticlesParaBulge
{
  sInt Function;
  sVector31 Center;
  sVector30 Size;
  sVector30 Stretch;
  sF32 FadeGamma;
  sF32 Warp;
};

struct Wz4ParticlesParaSparcle
{
  sInt SamplePoints;
  sF32 Percentage;
  sF32 Lifetime;
  sF32 RandomSpeed;
  sF32 DirectionSpeed;
  sF32 Gravity;
  sInt RandomSeed;
};

struct Wz4ParticlesParaFromMesh
{
  sF32 Raster;
  sVector31 Offset;
  sInt Flags;
  sF32 Random;
  sInt RandomSeed;
};

struct Wz4ParticlesParaMorph
{
  sF32 Transition;
  sVector31 DirFactor;
  sInt NewVertexPos;
  sVector31 BigBangOrigin;
  sVector31 BigBangDirFactor;
};


/****************************************************************************/

struct Wz4ParticlesAnimCloud
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaCloud *para);

  struct ScriptSymbol *_CloudSize;
  struct ScriptSymbol *_CloudFreq;
  struct ScriptSymbol *_CloudPos;
};

struct Wz4ParticlesAnimBallistic
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaBallistic *para);

  struct ScriptSymbol *_Gravity;
  struct ScriptSymbol *_PosStart;
  struct ScriptSymbol *_PosRand;
  struct ScriptSymbol *_SpeedStart;
  struct ScriptSymbol *_SpeedRand;
  struct ScriptSymbol *_BurstPercent;
  struct ScriptSymbol *_LifeTime;
  struct ScriptSymbol *_Delay;
};

struct Wz4ParticlesAnimMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaMesh *para);

};

struct Wz4ExplosionAnimExplosion
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ExplosionParaExplosion *para);

};

struct Wz4ParticlesAnimExploder
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaExploder *para);

  struct ScriptSymbol *_Gravity;
};

struct Wz4ParticlesAnimCloud2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaCloud2 *para);

};

struct Wz4ParticlesAnimFromVertex
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaFromVertex *para);

};

struct Wz4ParticlesAnimWobble
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaWobble *para);

  struct ScriptSymbol *_Freq;
  struct ScriptSymbol *_Amp;
  struct ScriptSymbol *_Phase;
  struct ScriptSymbol *_Spread;
  struct ScriptSymbol *_TimeFactor;
  struct ScriptSymbol *_DeltaFactor;
};

struct Wz4ParticlesAnimAdd
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaAdd *para);

};

struct Wz4ParticlesAnimLissajous
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaLissajous *para);

  struct ScriptSymbol *_Lifetime;
  struct ScriptSymbol *_Spread;
  struct ScriptSymbol *_Tweak;
  struct ScriptSymbol *_LinearTwirl;
  struct ScriptSymbol *_LinearStretch;
  struct ScriptSymbol *_MasterPhase;
  struct ScriptSymbol *_TubeRandom;
  struct ScriptSymbol *_MasterScale;
  struct ScriptSymbol *_SpeedSpread;
  struct ScriptSymbol *_LinearTwist;
  struct ScriptSymbol *_Randomness;
  struct ScriptSymbol *_Translate;
};

struct Wz4ParticlesAnimSplinedParticles
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaSplinedParticles *para);

  struct ScriptSymbol *_Lifetime;
  struct ScriptSymbol *_Spread;
  struct ScriptSymbol *_Tweak;
  struct ScriptSymbol *_LinearTwirl;
  struct ScriptSymbol *_Epsilon;
  struct ScriptSymbol *_AltShift;
  struct ScriptSymbol *_TubeRandom;
  struct ScriptSymbol *_Randomness;
  struct ScriptSymbol *_MasterPhase;
};

struct Wz4ParticlesAnimTrails
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaTrails *para);

};

struct Wz4ParticlesAnimStaticParticles
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaStaticParticles *para);

};

struct Wz4RenderAnimSprites
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSprites *para);

  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Size;
  struct ScriptSymbol *_Aspect;
  struct ScriptSymbol *_Color;
  struct ScriptSymbol *_RotStart;
  struct ScriptSymbol *_RotSpeed;
  struct ScriptSymbol *_RotRand;
  struct ScriptSymbol *_RotSpread;
  struct ScriptSymbol *_FadeIn;
  struct ScriptSymbol *_FadeOut;
  struct ScriptSymbol *_TexAnimSpeed;
  struct ScriptSymbol *_TexAnimRand;
};

struct Wz4RenderAnimChunks
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaChunks *para);

  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_LookAhead;
  struct ScriptSymbol *_RotStart;
  struct ScriptSymbol *_RotSpeed;
  struct ScriptSymbol *_RotRand;
  struct ScriptSymbol *_SpiralRand;
  struct ScriptSymbol *_SpiralSpeed;
  struct ScriptSymbol *_SpiralRandSpeed;
  struct ScriptSymbol *_AnimRand;
  struct ScriptSymbol *_AnimSpeed;
  struct ScriptSymbol *_AnimSpeedRand;
  struct ScriptSymbol *_AnimDifferent;
  struct ScriptSymbol *_ScaleRand;
};

struct Wz4RenderAnimDebris
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaDebris *para);

  struct ScriptSymbol *_LightEnv;
};

struct Wz4RenderAnimTrails
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaTrails *para);

  struct ScriptSymbol *_Delta;
  struct ScriptSymbol *_Width;
  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_Tweak;
  struct ScriptSymbol *_TrailStep;
};

struct Wz4RenderAnimMetaballs
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaMetaballs *para);

  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Size;
};

struct Wz4RenderAnimMarchingCubes
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaMarchingCubes *para);

};

struct Wz4RenderAnimMarchingCubesColor
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaMarchingCubesColor *para);

};

struct Wz4ParticlesAnimBulge
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaBulge *para);

  struct ScriptSymbol *_Center;
  struct ScriptSymbol *_Size;
  struct ScriptSymbol *_Stretch;
  struct ScriptSymbol *_FadeGamma;
  struct ScriptSymbol *_Warp;
};

struct Wz4ParticlesAnimSparcle
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaSparcle *para);

};

struct Wz4ParticlesAnimFromMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaFromMesh *para);

};

struct Wz4ParticlesAnimMorph
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaMorph *para);

  struct ScriptSymbol *_Transition;
  struct ScriptSymbol *_DirFactor;
  struct ScriptSymbol *_NewVertexPos;
  struct ScriptSymbol *_BigBangOrigin;
  struct ScriptSymbol *_BigBangDirFactor;
};


/****************************************************************************/

void AddTypes_fxparticle_ops(sBool secondary=0);
void AddOps_fxparticle_ops(sBool secondary=0);

/****************************************************************************/

#endif

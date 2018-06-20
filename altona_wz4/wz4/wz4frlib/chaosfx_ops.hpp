/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_chaosfx_ops
#define HEADER_WZ4OPS_chaosfx_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "chaosfx_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 21 "chaosfx_ops.hpp"
struct Wz4RenderParaCubeExample
{
  sInt _pad0;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt LightEnv;
  sInt Renderpass;
};

struct Wz4RenderParaPrint
{
  sInt Renderpass;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sU32 Color;
};

struct Wz4RenderParaRibbons
{
  sVector31 Trans;
  sF32 Forward;
  sF32 Side;
  sInt Steps;
  sInt Around;
  sF32 Waber[3];
  sF32 Freq[3];
  sF32 Spread[3];
  sF32 Start[3];
  sInt LightEnv;
  sInt Renderpass;
};

struct Wz4RenderParaRibbons2
{
  sInt Renderpass;
  sInt Count;
  sInt Length;
  sVector31 Trans;
  sVector30 Spread;
  sF32 Forward;
  sF32 Side;
  sInt LightEnv;
  sVector31 Source0;
  sF32 Power0;
  sVector31 Source1;
  sF32 Power1;
  sVector31 Source2;
  sF32 Power2;
  sVector31 Source3;
  sF32 Power3;
};

struct Wz4RenderParaBlowNoise
{
  sInt Tess[2];
  sF32 Scale;
  sF32 Scroll;
  sInt LightEnv;
  sInt Renderpass;
};

struct Wz4RenderArrayBlowNoise
{
  sInt Octave;
  sF32 Depth;
  sF32 Blow;
  sF32 Scroll[2];
  sInt Flags;
};

struct Wz4RenderParaDebrisClassic
{
  sInt Renderpass;
  sInt LightEnv;
  sF32 Displace;
  sF32 Tumble;
  sInt Flags;
  sF32 Trans[2];
  sF32 Scale[2];
  sF32 Scroll[2];
  sF32 Rotate;
  sInt FlagsB;
  sF32 TransB[2];
  sF32 ScaleB[2];
  sF32 ScrollB[2];
  sF32 RotateB;
  sF32 DisplaceB;
  sF32 TumbleB;
  sInt FlagsC;
  sF32 TransC[2];
  sF32 ScaleC[2];
  sF32 ScrollC[2];
  sF32 RotateC;
  sF32 DisplaceC;
  sF32 TumbleC;
  sF32 Size;
  sF32 SizeB;
  sF32 SizeC;
  sF32 TexBias;
  sF32 TexBiasB;
  sF32 TexBiasC;
  sInt Mode;
  sVector30 Normal;
  sVector31 Trans0;
  sInt Count1;
  sVector30 Trans1;
  sInt Count2;
  sVector30 Trans2;
  sInt Count3;
  sVector30 Trans3;
};

struct Wz4RenderParaBoneVibrate
{
  sInt Renderpass;
  sInt LightEnv;
  sInt Seed;
  sF32 Freq;
  sF32 Trans;
  sF32 Rot;
  sF32 Phase;
  sInt FirstBone;
};


/****************************************************************************/

struct Wz4RenderAnimCubeExample
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCubeExample *para);

  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
};

struct Wz4RenderAnimPrint
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaPrint *para);

  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Color;
};

struct Wz4RenderAnimRibbons
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaRibbons *para);

  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Forward;
  struct ScriptSymbol *_Side;
  struct ScriptSymbol *_Steps;
  struct ScriptSymbol *_Around;
  struct ScriptSymbol *_Waber;
  struct ScriptSymbol *_Freq;
  struct ScriptSymbol *_Spread;
  struct ScriptSymbol *_Start;
};

struct Wz4RenderAnimRibbons2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaRibbons2 *para);

  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Forward;
  struct ScriptSymbol *_Side;
};

struct Wz4RenderAnimBlowNoise
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBlowNoise *para);

  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Scroll;
};

struct Wz4RenderAnimDebrisClassic
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaDebrisClassic *para);

  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Scroll;
  struct ScriptSymbol *_Rotate;
  struct ScriptSymbol *_Displace;
  struct ScriptSymbol *_Tumble;
  struct ScriptSymbol *_Size;
  struct ScriptSymbol *_TexBias;
  struct ScriptSymbol *_TransB;
  struct ScriptSymbol *_ScaleB;
  struct ScriptSymbol *_ScrollB;
  struct ScriptSymbol *_RotateB;
  struct ScriptSymbol *_DisplaceB;
  struct ScriptSymbol *_TumbleB;
  struct ScriptSymbol *_SizeB;
  struct ScriptSymbol *_TexBiasB;
  struct ScriptSymbol *_TransC;
  struct ScriptSymbol *_ScaleC;
  struct ScriptSymbol *_ScrollC;
  struct ScriptSymbol *_RotateC;
  struct ScriptSymbol *_DisplaceC;
  struct ScriptSymbol *_TumbleC;
  struct ScriptSymbol *_SizeC;
  struct ScriptSymbol *_TexBiasC;
  struct ScriptSymbol *_Normal;
  struct ScriptSymbol *_Trans0;
  struct ScriptSymbol *_Count1;
  struct ScriptSymbol *_Trans1;
  struct ScriptSymbol *_Count2;
  struct ScriptSymbol *_Trans2;
  struct ScriptSymbol *_Count3;
  struct ScriptSymbol *_Trans3;
};

struct Wz4RenderAnimBoneVibrate
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBoneVibrate *para);

  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_Freq;
  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Phase;
};


/****************************************************************************/

void AddTypes_chaosfx_ops(sBool secondary=0);
void AddOps_chaosfx_ops(sBool secondary=0);

/****************************************************************************/

#endif

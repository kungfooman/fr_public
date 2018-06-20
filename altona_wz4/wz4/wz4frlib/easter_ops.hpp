/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_easter_ops
#define HEADER_WZ4OPS_easter_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "easter_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 21 "easter_ops.hpp"
struct Wz4RenderParaCubeTrees
{
  sInt Renderpass;
  sInt LightEnv;
  sF32 StartWidth;
  sF32 GrowSpeed;
  sF32 SegmentLength;
  sF32 WidthDecay;
  sInt Seed;
  sF32 MinWidth;
  sF32 Bend;
  sF32 CubeSize;
  sF32 CubeGrowTime;
  sF32 CubeWobbleTime;
  sVector30 CubeRot;
  sF32 SpawnDelay;
};

struct Wz4RenderArrayCubeTrees
{
  sVector31 Pos;
  sF32 Rot;
  sInt Seed;
};

struct Wz4RenderParaTVNoise
{
  sInt Renderpass;
  sF32 Alpha;
};

struct Wz4RenderParaJulia4D
{
  sInt Renderpass;
  sVector4 C;
  sU32 Color;
  sInt Flags;
  sU32 Specular;
  sF32 Power;
};


/****************************************************************************/

struct Wz4RenderAnimCubeTrees
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCubeTrees *para);

  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_StartWidth;
  struct ScriptSymbol *_GrowSpeed;
  struct ScriptSymbol *_SegmentLength;
  struct ScriptSymbol *_WidthDecay;
  struct ScriptSymbol *_MinWidth;
  struct ScriptSymbol *_Bend;
  struct ScriptSymbol *_CubeSize;
  struct ScriptSymbol *_CubeGrowTime;
  struct ScriptSymbol *_CubeWobbleTime;
  struct ScriptSymbol *_CubeRot;
  struct ScriptSymbol *_SpawnDelay;
};

struct Wz4RenderAnimTVNoise
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaTVNoise *para);

  struct ScriptSymbol *_Alpha;
};

struct Wz4RenderAnimJulia4D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaJulia4D *para);

  struct ScriptSymbol *_C;
};


/****************************************************************************/

void AddTypes_easter_ops(sBool secondary=0);
void AddOps_easter_ops(sBool secondary=0);

/****************************************************************************/

#endif

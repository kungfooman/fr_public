/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fr067_ops
#define HEADER_WZ4OPS_fr067_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "fr067_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 21 "fr067_ops.hpp"
struct Wz4RenderParaFR067_IsoSplash
{
  sInt LightEnv;
  sInt Renderpass;
  sInt Multithreading;
  sF32 IsoValue;
  sInt OctreeDivisions;
  sF32 GridSize;
  sF32 SphereAmp;
  sVector30 SphereDirections;
  sF32 CubeAmp;
  sVector30 CubeDirections;
  sF32 NoiseAmp1;
  sVector30 NoiseFreq1;
  sVector30 NoisePhase1;
  sInt NoiseSeed1;
  sVector30 Rot;
  sVector30 Rubber;
  sInt RubberToNoise;
  sF32 QuickOutSaveGuard;
  sF32 PolarAmp;
  sF32 PolarCenter;
  sF32 PolarY;
  sF32 PolarXZ;
  sF32 PolarCenterAmount;
  sInt Shells[4];
  sF32 NoiseAmp2;
  sVector30 NoiseFreq2;
  sVector30 NoisePhase2;
  sInt NoiseSeed2;
};


/****************************************************************************/

struct Wz4RenderAnimFR067_IsoSplash
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR067_IsoSplash *para);

  struct ScriptSymbol *_IsoValue;
  struct ScriptSymbol *_SphereAmp;
  struct ScriptSymbol *_SphereDirections;
  struct ScriptSymbol *_CubeAmp;
  struct ScriptSymbol *_CubeDirections;
  struct ScriptSymbol *_NoiseAmp1;
  struct ScriptSymbol *_NoiseFreq1;
  struct ScriptSymbol *_NoisePhase1;
  struct ScriptSymbol *_NoiseSeed1;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Rubber;
  struct ScriptSymbol *_QuickOutSaveGuard;
  struct ScriptSymbol *_PolarAmp;
  struct ScriptSymbol *_PolarCenter;
  struct ScriptSymbol *_PolarY;
  struct ScriptSymbol *_PolarXZ;
  struct ScriptSymbol *_PolarCenterAmount;
  struct ScriptSymbol *_Shells;
  struct ScriptSymbol *_NoiseAmp2;
  struct ScriptSymbol *_NoiseFreq2;
  struct ScriptSymbol *_NoisePhase2;
  struct ScriptSymbol *_NoiseSeed2;
};


/****************************************************************************/

void AddTypes_fr067_ops(sBool secondary=0);
void AddOps_fr067_ops(sBool secondary=0);

/****************************************************************************/

#endif

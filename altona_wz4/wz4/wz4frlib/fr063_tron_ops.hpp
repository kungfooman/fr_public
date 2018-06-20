/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fr063_tron_ops
#define HEADER_WZ4OPS_fr063_tron_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "fr063_tron_ops.ops"

#include "wz4lib/basic_ops.hpp"

#line 21 "fr063_tron_ops.hpp"
struct Wz4RenderParaFR063_SpritesADF
{
  sVector31 Trans;
  sF32 Size;
  sF32 Aspect;
  sInt Mode;
  sInt _pad6;
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
  sF32 SDFFadeOffset;
  sF32 SDFFadeMult;
  sVector31 LightPos;
  sF32 DiffusePower;
  sF32 SpecHardness;
  sF32 SpecPower;
  sU32 InAmbientColor;
  sU32 InDiffuseColor;
  sU32 InSpecColor;
  sU32 OutAmbientColor;
  sU32 OutDiffuseColor;
  sU32 OutSpecColor;
  sInt DropMode;
  sInt CollMode;
  sF32 WrapOffset;
};

struct Wz4RenderParaFR063_ClothGridSimRender
{
  sVector31 Pos;
  sVector30 AX;
  sVector30 AY;
  sInt XC;
  sInt YC;
  sF32 C1;
  sF32 C2;
  sF32 Mass;
  sVector30 Gravity;
  sVector30 Force;
  sF32 Damping;
  sF32 CollisionGuard;
  sF32 SlideFactor;
  sF32 TimeScale;
  sF32 TimeOffset;
  sInt LightEnv;
  sInt Renderpass;
  sInt DebugDoSim;
  sInt DebugUseMulticore;
  sInt DebugSubdivide;
  sInt DebugFlipEdges;
};

struct Wz4RenderArrayFR063_ClothGridSimRender
{
  sInt GridX;
  sInt GridY;
  sInt Type;
  sF32 DragRadius;
  sString<32> SplineName;
};

struct Wz4RenderParaFR063_MassBallColl
{
  sInt NbOfBalls;
  sInt Seed;
  sVector31 PosStart;
  sVector30 PosRand;
  sF32 RadiusStart;
  sF32 RadiusRand;
  sF32 MassStart;
  sF32 MassScale;
  sVector30 Gravity;
  sF32 TimeScale;
  sF32 TimeOffset;
  sF32 SimStep;
  sF32 ReactPower;
  sF32 ReflPower;
  sF32 SlidePower;
  sVector31 LightPos;
  sU32 AmbientColor;
  sF32 AmbientPower;
  sU32 DiffuseColor;
  sF32 DiffusePower;
  sU32 SpecColor;
  sF32 SpecPower;
  sF32 SpecHardness;
  sInt Renderpass;
};

struct SphCollisionParaSphSDFColl
{
  sInt Flags;
};

struct SphCollisionParaSphSDFMorph
{
  sF32 Factor;
  sF32 Time;
};

struct SphCollisionParaSphPDFColl
{
  sInt Flags;
};

struct Wz4RenderParaFR063_SpritesExt
{
  sF32 Aspect;
  sInt Mode;
  sInt _pad2;
  sInt Renderpass;
  sF32 TexAnimSpeed;
  sF32 TexAnimRand;
  sF32 NearFadeDistance;
  sF32 FarFadeDistance;
  sF32 FarFadeRange;
};

struct Wz4RenderArrayFR063_SpritesExt
{
  sVector31 Pos;
  sU32 Color;
  sF32 Size;
  sVector30 AlignDir;
  sF32 FixAngle;
  sF32 Range;
  sInt Mode;
};

struct Wz4RenderParaFR063_AermelKanal
{
  sInt Slices;
  sInt Segments;
  sF32 RadiusOffset[2];
  sF32 RadiusScale[2];
  sF32 RotationOffset;
  sInt Range;
  sInt LightEnv;
  sInt Renderpass;
  sInt DebugMode;
};


/****************************************************************************/

struct Wz4RenderAnimFR063_SpritesADF
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_SpritesADF *para);

  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Size;
  struct ScriptSymbol *_Aspect;
  struct ScriptSymbol *_RotStart;
  struct ScriptSymbol *_RotSpeed;
  struct ScriptSymbol *_RotRand;
  struct ScriptSymbol *_RotSpread;
  struct ScriptSymbol *_FadeIn;
  struct ScriptSymbol *_FadeOut;
  struct ScriptSymbol *_TexAnimSpeed;
  struct ScriptSymbol *_TexAnimRand;
  struct ScriptSymbol *_SDFFadeOffset;
  struct ScriptSymbol *_SDFFadeMult;
  struct ScriptSymbol *_LightPos;
  struct ScriptSymbol *_DiffusePower;
  struct ScriptSymbol *_SpecHardness;
  struct ScriptSymbol *_SpecPower;
  struct ScriptSymbol *_InAmbientColor;
  struct ScriptSymbol *_InDiffuseColor;
  struct ScriptSymbol *_InSpecColor;
  struct ScriptSymbol *_OutAmbientColor;
  struct ScriptSymbol *_OutDiffuseColor;
  struct ScriptSymbol *_OutSpecColor;
  struct ScriptSymbol *_WrapOffset;
};

struct Wz4RenderAnimFR063_ClothGridSimRender
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_ClothGridSimRender *para);

  struct ScriptSymbol *_Force;
};

struct Wz4RenderAnimFR063_MassBallColl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_MassBallColl *para);

  struct ScriptSymbol *_LightPos;
  struct ScriptSymbol *_AmbientColor;
  struct ScriptSymbol *_AmbientPower;
  struct ScriptSymbol *_DiffuseColor;
  struct ScriptSymbol *_DiffusePower;
  struct ScriptSymbol *_SpecColor;
  struct ScriptSymbol *_SpecPower;
  struct ScriptSymbol *_SpecHardness;
};

struct SphCollisionAnimSphSDFColl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphCollisionParaSphSDFColl *para);

};

struct SphCollisionAnimSphSDFMorph
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphCollisionParaSphSDFMorph *para);

};

struct SphCollisionAnimSphPDFColl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphCollisionParaSphPDFColl *para);

};

struct Wz4RenderAnimFR063_SpritesExt
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_SpritesExt *para);

  struct ScriptSymbol *_Aspect;
  struct ScriptSymbol *_TexAnimSpeed;
  struct ScriptSymbol *_TexAnimRand;
};

struct Wz4RenderAnimFR063_AermelKanal
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_AermelKanal *para);

};


/****************************************************************************/

void AddTypes_fr063_tron_ops(sBool secondary=0);
void AddOps_fr063_tron_ops(sBool secondary=0);

/****************************************************************************/

#endif

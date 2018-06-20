/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_tron_ops
#define HEADER_WZ4OPS_tron_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "tron_ops.ops"

#include "wz4frlib/wz4_demo2.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4lib/basic_ops.hpp"
#include "wz4lib/basic.hpp"

#line 24 "tron_ops.hpp"
struct Wz4ParticlesParaPlaceOnMesh
{
  sInt PlaneThickness;
  sF32 Length;
  sVector30 Direction;
  sInt Mode;
};

struct Wz4ParticlesParaSingleForceField
{
  sInt FieldType;
  sInt ForceType;
  sVector31 Position;
  sF32 Scale;
  sVector30 Size;
  sVector30 Rotation;
  sF32 Distance;
};

struct Wz4MeshParaRetexturizer
{
};

struct Wz4ParticlesParaFR033_MeteorShowerSim
{
  sInt MF_Seed;
  sInt MF_Count;
  sVector31 MF_StartPos;
  sVector31 MF_RandPos;
  sVector31 MF_StartSpeed;
  sVector31 MF_RandSpeed;
  sF32 MF_StartTime;
  sF32 MF_RandTime;
  sF32 MF_OnTime;
  sF32 MF_OffTime;
};

struct Wz4RenderParaFR033_WaterSimRender
{
  sInt WG_VertXZ[2];
  sVector31 WG_Pos;
  sF32 WG_SizeXZ[2];
  sF32 WG_ScaleUV[2];
  sF32 WG_OffsetUV[2];
  sF32 WS_Amplitude;
  sF32 WS_DampingTime;
  sF32 WS_DampingExpansion;
  sF32 WS_Freq;
  sF32 WS_FreqTime;
  sF32 WS_FreqExpansion;
  sInt DP_Seed;
  sInt DP_Count;
  sF32 DP_Scale[2];
  sF32 DP_RandScale[2];
  sF32 DP_StartPos[3];
  sF32 DP_DimXZ[2];
};

struct Wz4RenderParaSharpen
{
  sF32 Strength;
};

struct Wz4RenderParaSBlur
{
  sF32 Radius;
  sF32 Amp;
  sF32 Intensity;
};

struct Wz4RenderParaBloom
{
  sInt CalcMaskFromScreen;
  sU32 HighlightCol;
  sU32 MaskCol;
  sF32 MaskAmp;
  sF32 MaskBias;
  sInt UseAlpha;
  sF32 AlphaAmp;
  sF32 AlphaBias;
  sInt UseZBuf;
  sF32 ZBufAmp;
  sF32 ZBufBias;
  sInt MultiplyScreenCol;
  sVector4 BlendFactor;
  sU32 GrayMaskCol;
  sF32 GrayMaskAmp;
  sF32 GrayMaskBias;
  sF32 BlurRadius;
  sF32 BlurAmp;
  sU32 CompBloomCol;
  sF32 CompBloomAmp;
  sU32 CompScreenCol;
  sF32 CompScreenAmp;
  sInt CompFormula;
  sInt DebugShow;
  sInt PreBlurMode;
  sF32 PreBlurSize;
};

struct Wz4RenderParaPromist
{
  sInt CalcMaskFromScreen;
  sU32 HighlightCol;
  sU32 MaskCol;
  sF32 MaskAmp;
  sF32 MaskBias;
  sInt UseAlpha;
  sF32 AlphaAmp;
  sF32 AlphaBias;
  sInt UseZBuf;
  sF32 ZBufAmp;
  sF32 ZBufBias;
  sInt MultiplyScreenCol;
  sVector4 BlendFactor;
  sU32 GrayMaskCol;
  sF32 GrayMaskAmp;
  sF32 GrayMaskBias;
  sF32 BlurRadius;
  sF32 BlurAmp;
  sF32 BlurScreenRadius;
  sF32 BlurScreenAmp;
  sU32 CompBloomCol;
  sF32 CompBloomAmp;
  sU32 CompScreenCol;
  sF32 CompScreenAmp;
  sInt DebugShow;
};

struct Wz4RenderParaDepthOfField3
{
  sF32 FocalDepth;
  sF32 FocusRange;
  sF32 UnfocusRangeBefore;
  sF32 UnfocusRangeAfter;
  sF32 BlurMaskRadius;
  sF32 BlurMaskAmb;
  sInt Advanced;
  sF32 BlurScreenRadius;
  sF32 BlurScreenAmb;
  sF32 CompScreenAmb;
  sF32 CompMaskAmb;
  sInt DebugShow;
};

struct Wz4RenderParaGlow
{
  sU32 GradInColor;
  sU32 GradOutColor;
  sF32 GradShift;
  sF32 GradIntensity;
  sF32 GradOffset;
  sInt MaskEdgeGlow;
  sF32 MaskThres;
  sF32 MaskSoftenThres;
  sF32 BlurMaskRadius;
  sF32 BlurMaskAmp;
  sInt CombineMode;
  sInt DebugShow;
};

struct Wz4RenderParaFocusBlur
{
  sF32 FocusPoint[2];
  sF32 FocusAmp;
  sF32 FocusBias;
  sF32 BlurScreenRadius;
  sF32 BlurScreenAmp;
};

struct GenBitmapParaTronFont
{
  sInt Size;
  sInt Height;
  sInt Width;
  sInt Style;
  sInt Safety;
  sInt SpacePreCellPost[3];
  sU32 Col;
};

struct Wz4MeshParaTronPrint
{
  sU32 Color;
  sF32 Zoom;
  sInt Width;
  sF32 Space[2];
};


/****************************************************************************/

struct Wz4ParticlesAnimPlaceOnMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaPlaceOnMesh *para);

};

struct Wz4ParticlesAnimSingleForceField
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaSingleForceField *para);

  struct ScriptSymbol *_Position;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Size;
  struct ScriptSymbol *_Rotation;
  struct ScriptSymbol *_Distance;
};

struct Wz4MeshAnimRetexturizer
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaRetexturizer *para);

};

struct Wz4ParticlesAnimFR033_MeteorShowerSim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaFR033_MeteorShowerSim *para);

};

struct Wz4RenderAnimFR033_WaterSimRender
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR033_WaterSimRender *para);

};

struct Wz4RenderAnimSharpen
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSharpen *para);

  struct ScriptSymbol *_Strength;
};

struct Wz4RenderAnimSBlur
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSBlur *para);

};

struct Wz4RenderAnimBloom
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBloom *para);

  struct ScriptSymbol *_HighlightCol;
  struct ScriptSymbol *_MaskCol;
  struct ScriptSymbol *_MaskAmp;
  struct ScriptSymbol *_MaskBias;
  struct ScriptSymbol *_AlphaAmp;
  struct ScriptSymbol *_AlphaBias;
  struct ScriptSymbol *_ZBufAmp;
  struct ScriptSymbol *_ZBufBias;
  struct ScriptSymbol *_BlendFactor;
  struct ScriptSymbol *_GrayMaskCol;
  struct ScriptSymbol *_GrayMaskAmp;
  struct ScriptSymbol *_GrayMaskBias;
  struct ScriptSymbol *_BlurRadius;
  struct ScriptSymbol *_BlurAmp;
  struct ScriptSymbol *_CompBloomCol;
  struct ScriptSymbol *_CompBloomAmp;
  struct ScriptSymbol *_CompScreenCol;
  struct ScriptSymbol *_CompScreenAmp;
  struct ScriptSymbol *_PreBlurSize;
};

struct Wz4RenderAnimPromist
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaPromist *para);

  struct ScriptSymbol *_HighlightCol;
  struct ScriptSymbol *_MaskCol;
  struct ScriptSymbol *_MaskAmp;
  struct ScriptSymbol *_MaskBias;
  struct ScriptSymbol *_AlphaAmp;
  struct ScriptSymbol *_AlphaBias;
  struct ScriptSymbol *_ZBufAmp;
  struct ScriptSymbol *_ZBufBias;
  struct ScriptSymbol *_BlendFactor;
  struct ScriptSymbol *_GrayMaskCol;
  struct ScriptSymbol *_GrayMaskAmp;
  struct ScriptSymbol *_GrayMaskBias;
  struct ScriptSymbol *_BlurRadius;
  struct ScriptSymbol *_BlurAmp;
  struct ScriptSymbol *_BlurScreenRadius;
  struct ScriptSymbol *_BlurScreenAmp;
  struct ScriptSymbol *_CompBloomCol;
  struct ScriptSymbol *_CompBloomAmp;
  struct ScriptSymbol *_CompScreenCol;
  struct ScriptSymbol *_CompScreenAmp;
};

struct Wz4RenderAnimDepthOfField3
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaDepthOfField3 *para);

  struct ScriptSymbol *_FocalDepth;
  struct ScriptSymbol *_FocusRange;
  struct ScriptSymbol *_UnfocusRangeBefore;
  struct ScriptSymbol *_UnfocusRangeAfter;
  struct ScriptSymbol *_BlurMaskRadius;
  struct ScriptSymbol *_BlurMaskAmb;
  struct ScriptSymbol *_BlurScreenRadius;
  struct ScriptSymbol *_BlurScreenAmb;
  struct ScriptSymbol *_CompScreenAmb;
  struct ScriptSymbol *_CompMaskAmb;
};

struct Wz4RenderAnimGlow
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaGlow *para);

  struct ScriptSymbol *_GradInColor;
  struct ScriptSymbol *_GradOutColor;
  struct ScriptSymbol *_GradShift;
  struct ScriptSymbol *_GradIntensity;
  struct ScriptSymbol *_GradOffset;
  struct ScriptSymbol *_MaskThres;
  struct ScriptSymbol *_MaskSoftenThres;
  struct ScriptSymbol *_BlurMaskRadius;
  struct ScriptSymbol *_BlurMaskAmp;
};

struct Wz4RenderAnimFocusBlur
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFocusBlur *para);

  struct ScriptSymbol *_FocusPoint;
  struct ScriptSymbol *_FocusAmp;
  struct ScriptSymbol *_FocusBias;
  struct ScriptSymbol *_BlurScreenRadius;
  struct ScriptSymbol *_BlurScreenAmp;
};

struct GenBitmapAnimTronFont
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaTronFont *para);

};

struct Wz4MeshAnimTronPrint
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTronPrint *para);

};


/****************************************************************************/

void AddTypes_tron_ops(sBool secondary=0);
void AddOps_tron_ops(sBool secondary=0);

/****************************************************************************/

#endif

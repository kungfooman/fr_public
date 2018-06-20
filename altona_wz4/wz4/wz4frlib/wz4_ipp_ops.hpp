/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_ipp_ops
#define HEADER_WZ4OPS_wz4_ipp_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "wz4_ipp_ops.ops"

#include "wz4frlib/wz4_demo2.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"

#line 22 "wz4_ipp_ops.hpp"
struct Wz4RenderParaColorCorrect
{
  sInt Renderpass;
  sU32 Color0;
  sU32 Color1;
};

struct Wz4RenderParaDebugZ
{
  sInt Channel;
  sInt Renderpass;
};

struct Wz4RenderParaBlur
{
  sInt Renderpass;
  sF32 Radius;
  sF32 Amp;
  sInt Unit;
  sInt MaxPasses;
  sInt SharpenFlag;
  sF32 Sharpen;
  sU32 Sharpen0;
  sF32 Sharpen0Amp;
  sU32 Sharpen1;
  sF32 Sharpen1Amp;
};

struct Wz4RenderParaDepthOfField
{
  sInt Renderpass;
  sF32 Depth[3];
  sF32 Blur[3];
  sF32 CenterSize;
  sF32 BlurRadius[2];
  sInt Debug;
};

struct Wz4RenderParaDepthOfField2
{
  sInt Renderpass;
  sF32 FocalDepth;
  sF32 FocusRange;
  sF32 UnfocusRange;
  sF32 MediumBlur;
  sF32 LargeBlur;
  sInt Debug;
};

struct Wz4RenderParaSSAO
{
  sInt Renderpass;
  sF32 MinOcclude;
  sF32 MaxOcclude;
  sF32 SampleRadius;
  sF32 NormalThreshold;
  sInt Output;
  sU32 Color;
  sInt Quality;
  sF32 Intensity;
  sInt Fog;
  sF32 FogNear;
  sF32 FogFar;
  sVector31 FogCenter;
  sF32 FogDensity;
};

struct Wz4RenderParaColorBalance
{
  sInt Renderpass;
  sVector30 Shadows;
  sVector30 Midtones;
  sVector30 Highlights;
};

struct Wz4RenderParaColorSaw
{
  sInt Renderpass;
  sInt Repeat[3];
  sVector30 Threshold;
  sVector30 Softness;
  sF32 Gamma[3];
};

struct Wz4RenderParaColorGrade
{
  sInt Renderpass;
  sInt Flags;
  sF32 ShadWidth;
  sF32 ShadContrast;
  sF32 ShadBrightness;
  sF32 ShadSaturation;
  sF32 ShadHue;
  sF32 ShadBalHue;
  sF32 ShadBalStrength;
  sVector30 ShadGain;
  sU32 ShadColor;
  sF32 MidContrast;
  sF32 MidBrightness;
  sF32 MidSaturation;
  sF32 MidHue;
  sF32 MidBalHue;
  sF32 MidBalStrength;
  sVector30 MidGain;
  sU32 MidColor;
  sF32 HighWidth;
  sF32 HighContrast;
  sF32 HighBrightness;
  sF32 HighSaturation;
  sF32 HighHue;
  sF32 HighBalHue;
  sF32 HighBalStrength;
  sVector30 HighGain;
  sU32 HighColor;
  sVector4 Gamma;
};

struct Wz4RenderParaCrashZoom
{
  sInt Renderpass;
  sInt Flags;
  sVector31 Center3D;
  sF32 Center2D[2];
  sF32 Amplify;
  sF32 Amount[4];
};

struct Wz4RenderParaGrabScreen
{
  sInt Renderpass;
  sInt Enable;
};

struct Wz4RenderParaCrackFixer
{
  sF32 AlphaDistance;
  sInt OffCounts;
  sInt Renderpass;
};

struct Wz4RenderParaFXAA3
{
  sInt Renderpass;
};

struct Wz4RenderParaColorMath
{
  sInt Renderpass;
  sU32 Add;
  sF32 AddFactor;
  sU32 Mul;
  sF32 MulFactor;
};

struct Wz4RenderParaCustomIPP
{
  sInt Renderpass;
  sInt Filter;
  sF32 vs_var0[4];
  sF32 vs_var1[4];
  sF32 vs_var2[4];
  sF32 vs_var3[4];
  sF32 vs_var4[4];
  sF32 ps_var0[4];
  sF32 ps_var1[4];
  sF32 ps_var2[4];
  sF32 ps_var3[4];
  sF32 ps_var4[4];
  sInt TexFilter1;
  sInt TexFilter2;
  sInt TexFilter3;
  sInt TexFilter4;
  sInt TexFilter5;
  sInt TexFilter6;
  sInt TexFilter7;
  sInt TexFilter8;
  sInt TexFilter9;
  sInt TexFilter10;
  sInt TexFilter11;
  sInt TexFilter12;
  sInt TexFilter13;
  sInt TexFilter14;
  sInt TexFilter15;
};


/****************************************************************************/

struct Wz4RenderAnimColorCorrect
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaColorCorrect *para);

  struct ScriptSymbol *_Color0;
  struct ScriptSymbol *_Color1;
};

struct Wz4RenderAnimDebugZ
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaDebugZ *para);

};

struct Wz4RenderAnimBlur
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBlur *para);

  struct ScriptSymbol *_Radius;
  struct ScriptSymbol *_Amp;
  struct ScriptSymbol *_Sharpen;
  struct ScriptSymbol *_Sharpen0;
  struct ScriptSymbol *_Sharpen0Amp;
  struct ScriptSymbol *_Sharpen1;
  struct ScriptSymbol *_Sharpen1Amp;
};

struct Wz4RenderAnimDepthOfField
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaDepthOfField *para);

  struct ScriptSymbol *_Depth;
  struct ScriptSymbol *_Blur;
  struct ScriptSymbol *_CenterSize;
  struct ScriptSymbol *_BlurRadius;
};

struct Wz4RenderAnimDepthOfField2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaDepthOfField2 *para);

  struct ScriptSymbol *_FocalDepth;
  struct ScriptSymbol *_FocusRange;
  struct ScriptSymbol *_UnfocusRange;
  struct ScriptSymbol *_MediumBlur;
  struct ScriptSymbol *_LargeBlur;
};

struct Wz4RenderAnimSSAO
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSSAO *para);

  struct ScriptSymbol *_MinOcclude;
  struct ScriptSymbol *_MaxOcclude;
  struct ScriptSymbol *_SampleRadius;
  struct ScriptSymbol *_NormalThreshold;
  struct ScriptSymbol *_Color;
  struct ScriptSymbol *_Intensity;
  struct ScriptSymbol *_FogNear;
  struct ScriptSymbol *_FogFar;
  struct ScriptSymbol *_FogDensity;
};

struct Wz4RenderAnimColorBalance
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaColorBalance *para);

};

struct Wz4RenderAnimColorSaw
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaColorSaw *para);

};

struct Wz4RenderAnimColorGrade
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaColorGrade *para);

};

struct Wz4RenderAnimCrashZoom
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCrashZoom *para);

  struct ScriptSymbol *_Center3D;
  struct ScriptSymbol *_Center2D;
  struct ScriptSymbol *_Amplify;
  struct ScriptSymbol *_Amount;
};

struct Wz4RenderAnimGrabScreen
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaGrabScreen *para);

  struct ScriptSymbol *_Enable;
};

struct Wz4RenderAnimCrackFixer
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCrackFixer *para);

};

struct Wz4RenderAnimFXAA3
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFXAA3 *para);

};

struct Wz4RenderAnimColorMath
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaColorMath *para);

};

struct Wz4RenderAnimCustomIPP
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCustomIPP *para);

  struct ScriptSymbol *_vs_var0;
  struct ScriptSymbol *_vs_var1;
  struct ScriptSymbol *_vs_var2;
  struct ScriptSymbol *_vs_var3;
  struct ScriptSymbol *_vs_var4;
  struct ScriptSymbol *_ps_var0;
  struct ScriptSymbol *_ps_var1;
  struct ScriptSymbol *_ps_var2;
  struct ScriptSymbol *_ps_var3;
  struct ScriptSymbol *_ps_var4;
};


/****************************************************************************/

void AddTypes_wz4_ipp_ops(sBool secondary=0);
void AddOps_wz4_ipp_ops(sBool secondary=0);

/****************************************************************************/

#endif

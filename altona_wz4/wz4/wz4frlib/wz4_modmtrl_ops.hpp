/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_modmtrl_ops
#define HEADER_WZ4OPS_wz4_modmtrl_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class ModMtrlType_ *ModMtrlType;
extern class ModShaderType_ *ModShaderType;
extern class ModShaderSamplerType_ *ModShaderSamplerType;

/****************************************************************************/

#line 9 "wz4_modmtrl_ops.ops"

#include "wz4frlib/wz4_modmtrl.hpp"
#include "wz4frlib/wz4_modmtrlsc.hpp"
#include "wz4frlib/wz4_mtrl2.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/gui.hpp"

#line 28 "wz4_modmtrl_ops.hpp"

/****************************************************************************/

#line 20 "wz4_modmtrl_ops.ops"

  enum ModMtrlRTMode
  {
    MMRTM_DirShadow = 1,
    MMRTM_SpotShadow,
    MMRTM_PointShadow,
  };

#line 41 "wz4_modmtrl_ops.hpp"

/****************************************************************************/

#line 74 "wz4_modmtrl_ops.ops"

  class ModShaderSampler : public ModShader
  {
  public:
    ModShaderSampler();
  };
//  typedef ModShader ModShaderSampler;

#line 54 "wz4_modmtrl_ops.hpp"
class ModMtrlType_ : public Wz4MtrlType_
{
public:
  ModMtrlType_() { Parent = Wz4MtrlType; Color= 0xff60e060; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"ModMtrl"; Label = L"Modular Material";  Init(); }
  ~ModMtrlType_() { Exit(); }
#line 37 "wz4_modmtrl_ops.ops"

    void Init();
    void Exit();
    void PrepareRenderR(Wz4RenderContext *ctx);
    void BeginRenderR(Wz4RenderContext *ctx);
    void PrepareViewR(sViewport &view);
    void EndRenderR(Wz4RenderContext *ctx);
    void BeginShow(wPaintInfo &pi);

    ModLightEnv *LightEnv[sMAX_LIGHTENV];
    sInt RenderShadowsForLightEnv;
//    sMatrix34 ViewMatrix;
    sFrustum ViewFrustum;
    sAABBox ShadowCaster;
    class ShaderCreator *sc;

    Texture2D *SinCosTex;
    Texture2D *DummyTex2D;
    TextureCube *DummyTexCube;
  
#line 81 "wz4_modmtrl_ops.hpp"
#line 83 "wz4_modmtrl_ops.hpp"
};

class ModShaderType_ : public AnyTypeType_
{
public:
  ModShaderType_() { Parent = AnyTypeType; Color= 0xff40c040; Flags = 0x0001; GuiSets = 0x0000; Symbol = L"ModShader"; Label = L"Material Shader";  Init(); }
  ~ModShaderType_() { Exit(); }
#line 91 "wz4_modmtrl_ops.hpp"
};

class ModShaderSamplerType_ : public ModShaderType_
{
public:
  ModShaderSamplerType_() { Parent = ModShaderType; Color= 0xff20a020; Flags = 0x0001; GuiSets = 0x0000; Symbol = L"ModShaderSampler"; Label = L"Material Shader (Sampler)";  Init(); }
  ~ModShaderSamplerType_() { Exit(); }
#line 99 "wz4_modmtrl_ops.hpp"
};

struct ModMtrlParaModMaterial
{
  sInt Flags;
  sInt Blend;
  sInt AlphaTest;
  sInt AlphaRef;
  sInt dummy0[2];
  sInt AllowLight;
  sInt AllowShadow;
  sInt AllowFeatures;
  sInt FeatureFlags;
};

struct Wz4RenderParaModLight
{
  sInt Index;
  sInt Renderpass;
  sU32 Ambient;
  sInt Mode0;
  sU32 Front0;
  sF32 FrontAmp0;
  sU32 Middle0;
  sF32 MiddleAmp0;
  sU32 Back0;
  sF32 BackAmp0;
  sVector31 Pos0;
  sVector30 Dir0;
  sF32 Range0;
  sF32 Inner0;
  sF32 Outer0;
  sF32 Falloff0;
  sInt ShadowSize0;
  sF32 ShadowBaseBias0;
  sF32 ShadowFilter0;
  sF32 ShadowSlopeBias0;
  sF32 dummya0[3];
  sF32 dummyb0[4];
  sInt Mode1;
  sU32 Front1;
  sF32 FrontAmp1;
  sU32 Middle1;
  sF32 MiddleAmp1;
  sU32 Back1;
  sF32 BackAmp1;
  sVector31 Pos1;
  sVector30 Dir1;
  sF32 Range1;
  sF32 Inner1;
  sF32 Outer1;
  sF32 Falloff1;
  sInt ShadowSize1;
  sF32 ShadowBaseBias1;
  sF32 ShadowFilter1;
  sF32 ShadowSlopeBias1;
  sF32 dummya1[3];
  sF32 dummyb1[4];
  sInt Mode2;
  sU32 Front2;
  sF32 FrontAmp2;
  sU32 Middle2;
  sF32 MiddleAmp2;
  sU32 Back2;
  sF32 BackAmp2;
  sVector31 Pos2;
  sVector30 Dir2;
  sF32 Range2;
  sF32 Inner2;
  sF32 Outer2;
  sF32 Falloff2;
  sInt ShadowSize2;
  sF32 ShadowBaseBias2;
  sF32 ShadowFilter2;
  sF32 ShadowSlopeBias2;
  sF32 dummya2[3];
  sF32 dummyb2[4];
  sInt Mode3;
  sU32 Front3;
  sF32 FrontAmp3;
  sU32 Middle3;
  sF32 MiddleAmp3;
  sU32 Back3;
  sF32 BackAmp3;
  sVector31 Pos3;
  sVector30 Dir3;
  sF32 Range3;
  sF32 Inner3;
  sF32 Outer3;
  sF32 Falloff3;
  sInt ShadowSize3;
  sF32 ShadowBaseBias3;
  sF32 ShadowFilter3;
  sF32 ShadowSlopeBias3;
  sF32 dummya3[3];
  sF32 dummyb3[4];
  sInt Mode4;
  sU32 Front4;
  sF32 FrontAmp4;
  sU32 Middle4;
  sF32 MiddleAmp4;
  sU32 Back4;
  sF32 BackAmp4;
  sVector31 Pos4;
  sVector30 Dir4;
  sF32 Range4;
  sF32 Inner4;
  sF32 Outer4;
  sF32 Falloff4;
  sInt ShadowSize4;
  sF32 ShadowBaseBias4;
  sF32 ShadowFilter4;
  sF32 ShadowSlopeBias4;
  sF32 dummya4[3];
  sF32 dummyb4[4];
  sInt Mode5;
  sU32 Front5;
  sF32 FrontAmp5;
  sU32 Middle5;
  sF32 MiddleAmp5;
  sU32 Back5;
  sF32 BackAmp5;
  sVector31 Pos5;
  sVector30 Dir5;
  sF32 Range5;
  sF32 Inner5;
  sF32 Outer5;
  sF32 Falloff5;
  sInt ShadowSize5;
  sF32 ShadowBaseBias5;
  sF32 ShadowFilter5;
  sF32 ShadowSlopeBias5;
  sF32 dummya5[3];
  sF32 dummyb5[4];
  sInt Mode6;
  sU32 Front6;
  sF32 FrontAmp6;
  sU32 Middle6;
  sF32 MiddleAmp6;
  sU32 Back6;
  sF32 BackAmp6;
  sVector31 Pos6;
  sVector30 Dir6;
  sF32 Range6;
  sF32 Inner6;
  sF32 Outer6;
  sF32 Falloff6;
  sInt ShadowSize6;
  sF32 ShadowBaseBias6;
  sF32 ShadowFilter6;
  sF32 ShadowSlopeBias6;
  sF32 dummya6[3];
  sF32 dummyb6[4];
  sInt Mode7;
  sU32 Front7;
  sF32 FrontAmp7;
  sU32 Middle7;
  sF32 MiddleAmp7;
  sU32 Back7;
  sF32 BackAmp7;
  sVector31 Pos7;
  sVector30 Dir7;
  sF32 Range7;
  sF32 Inner7;
  sF32 Outer7;
  sF32 Falloff7;
  sInt ShadowSize7;
  sF32 ShadowBaseBias7;
  sF32 ShadowFilter7;
  sF32 ShadowSlopeBias7;
  sF32 dummya7[3];
  sF32 dummyb7[4];
  sInt LimitShadows;
  sVector31 LimitCenter;
  sVector30 LimitRadius;
  sInt TransformEnable;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct Wz4RenderParaModMisc
{
  sInt Index;
  sInt Renderpass;
  sU32 Color0;
  sF32 Amp0;
  sU32 Color1;
  sF32 Amp1;
  sU32 Color2;
  sF32 Amp2;
  sU32 Color3;
  sF32 Amp3;
  sU32 Color4;
  sF32 Amp4;
  sU32 Color5;
  sF32 Amp5;
  sU32 Color6;
  sF32 Amp6;
  sU32 Color7;
  sF32 Amp7;
  sVector30 Vector0;
  sVector30 Vector1;
  sVector30 Vector2;
  sVector30 Vector3;
  sVector30 Vector4;
  sVector30 Vector5;
  sVector30 Vector6;
  sVector30 Vector7;
  sVector31 Scale0;
  sVector30 Rot0;
  sVector31 Trans0;
  sVector31 Scale1;
  sVector30 Rot1;
  sVector31 Trans1;
  sVector31 Scale2;
  sVector30 Rot2;
  sVector31 Trans2;
  sVector31 Scale3;
  sVector30 Rot3;
  sVector31 Trans3;
};

struct Wz4RenderParaModLightEnv
{
  sInt Index;
  sInt Renderpass;
  sInt Features;
  sF32 FogNear;
  sF32 FogFar;
  sF32 FogDensity;
  sU32 FogColor;
  sInt dummya[2];
  sF32 GroundFogNear;
  sF32 GroundFogFar;
  sF32 GroundFogDensity;
  sU32 GroundFogColor;
  sVector4 GroundFogPlane;
  sInt dummyb[2];
  sInt ClipEnable;
  sVector4 Clip0;
  sVector4 Clip1;
  sVector4 Clip2;
  sVector4 Clip3;
};

struct Wz4RenderParaModClipTwister
{
  sInt Index;
  sInt Renderpass;
  sInt ClipEnable;
  sVector4 Clip0;
  sVector4 Clip1;
  sVector4 Clip2;
  sVector4 Clip3;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};


/****************************************************************************/

struct ModMtrlAnimModMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModMtrlParaModMaterial *para);

};

struct Wz4RenderAnimModLight
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaModLight *para);

  struct ScriptSymbol *_Front0;
  struct ScriptSymbol *_FrontAmp0;
  struct ScriptSymbol *_Middle0;
  struct ScriptSymbol *_MiddleAmp0;
  struct ScriptSymbol *_Back0;
  struct ScriptSymbol *_BackAmp0;
  struct ScriptSymbol *_Pos0;
  struct ScriptSymbol *_Dir0;
  struct ScriptSymbol *_Range0;
  struct ScriptSymbol *_Inner0;
  struct ScriptSymbol *_Outer0;
  struct ScriptSymbol *_Falloff0;
  struct ScriptSymbol *_ShadowSize0;
  struct ScriptSymbol *_ShadowBaseBias0;
  struct ScriptSymbol *_ShadowFilter0;
  struct ScriptSymbol *_ShadowSlopeBias0;
  struct ScriptSymbol *_Front1;
  struct ScriptSymbol *_FrontAmp1;
  struct ScriptSymbol *_Middle1;
  struct ScriptSymbol *_MiddleAmp1;
  struct ScriptSymbol *_Back1;
  struct ScriptSymbol *_BackAmp1;
  struct ScriptSymbol *_Pos1;
  struct ScriptSymbol *_Dir1;
  struct ScriptSymbol *_Range1;
  struct ScriptSymbol *_Inner1;
  struct ScriptSymbol *_Outer1;
  struct ScriptSymbol *_Falloff1;
  struct ScriptSymbol *_ShadowSize1;
  struct ScriptSymbol *_ShadowBaseBias1;
  struct ScriptSymbol *_ShadowFilter1;
  struct ScriptSymbol *_ShadowSlopeBias1;
  struct ScriptSymbol *_Front2;
  struct ScriptSymbol *_FrontAmp2;
  struct ScriptSymbol *_Middle2;
  struct ScriptSymbol *_MiddleAmp2;
  struct ScriptSymbol *_Back2;
  struct ScriptSymbol *_BackAmp2;
  struct ScriptSymbol *_Pos2;
  struct ScriptSymbol *_Dir2;
  struct ScriptSymbol *_Range2;
  struct ScriptSymbol *_Inner2;
  struct ScriptSymbol *_Outer2;
  struct ScriptSymbol *_Falloff2;
  struct ScriptSymbol *_ShadowSize2;
  struct ScriptSymbol *_ShadowBaseBias2;
  struct ScriptSymbol *_ShadowFilter2;
  struct ScriptSymbol *_ShadowSlopeBias2;
  struct ScriptSymbol *_Front3;
  struct ScriptSymbol *_FrontAmp3;
  struct ScriptSymbol *_Middle3;
  struct ScriptSymbol *_MiddleAmp3;
  struct ScriptSymbol *_Back3;
  struct ScriptSymbol *_BackAmp3;
  struct ScriptSymbol *_Pos3;
  struct ScriptSymbol *_Dir3;
  struct ScriptSymbol *_Range3;
  struct ScriptSymbol *_Inner3;
  struct ScriptSymbol *_Outer3;
  struct ScriptSymbol *_Falloff3;
  struct ScriptSymbol *_ShadowSize3;
  struct ScriptSymbol *_ShadowBaseBias3;
  struct ScriptSymbol *_ShadowFilter3;
  struct ScriptSymbol *_ShadowSlopeBias3;
  struct ScriptSymbol *_Front4;
  struct ScriptSymbol *_FrontAmp4;
  struct ScriptSymbol *_Middle4;
  struct ScriptSymbol *_MiddleAmp4;
  struct ScriptSymbol *_Back4;
  struct ScriptSymbol *_BackAmp4;
  struct ScriptSymbol *_Pos4;
  struct ScriptSymbol *_Dir4;
  struct ScriptSymbol *_Range4;
  struct ScriptSymbol *_Inner4;
  struct ScriptSymbol *_Outer4;
  struct ScriptSymbol *_Falloff4;
  struct ScriptSymbol *_ShadowSize4;
  struct ScriptSymbol *_ShadowBaseBias4;
  struct ScriptSymbol *_ShadowFilter4;
  struct ScriptSymbol *_ShadowSlopeBias4;
  struct ScriptSymbol *_Front5;
  struct ScriptSymbol *_FrontAmp5;
  struct ScriptSymbol *_Middle5;
  struct ScriptSymbol *_MiddleAmp5;
  struct ScriptSymbol *_Back5;
  struct ScriptSymbol *_BackAmp5;
  struct ScriptSymbol *_Pos5;
  struct ScriptSymbol *_Dir5;
  struct ScriptSymbol *_Range5;
  struct ScriptSymbol *_Inner5;
  struct ScriptSymbol *_Outer5;
  struct ScriptSymbol *_Falloff5;
  struct ScriptSymbol *_ShadowSize5;
  struct ScriptSymbol *_ShadowBaseBias5;
  struct ScriptSymbol *_ShadowFilter5;
  struct ScriptSymbol *_ShadowSlopeBias5;
  struct ScriptSymbol *_Front6;
  struct ScriptSymbol *_FrontAmp6;
  struct ScriptSymbol *_Middle6;
  struct ScriptSymbol *_MiddleAmp6;
  struct ScriptSymbol *_Back6;
  struct ScriptSymbol *_BackAmp6;
  struct ScriptSymbol *_Pos6;
  struct ScriptSymbol *_Dir6;
  struct ScriptSymbol *_Range6;
  struct ScriptSymbol *_Inner6;
  struct ScriptSymbol *_Outer6;
  struct ScriptSymbol *_Falloff6;
  struct ScriptSymbol *_ShadowSize6;
  struct ScriptSymbol *_ShadowBaseBias6;
  struct ScriptSymbol *_ShadowFilter6;
  struct ScriptSymbol *_ShadowSlopeBias6;
  struct ScriptSymbol *_Front7;
  struct ScriptSymbol *_FrontAmp7;
  struct ScriptSymbol *_Middle7;
  struct ScriptSymbol *_MiddleAmp7;
  struct ScriptSymbol *_Back7;
  struct ScriptSymbol *_BackAmp7;
  struct ScriptSymbol *_Pos7;
  struct ScriptSymbol *_Dir7;
  struct ScriptSymbol *_Range7;
  struct ScriptSymbol *_Inner7;
  struct ScriptSymbol *_Outer7;
  struct ScriptSymbol *_Falloff7;
  struct ScriptSymbol *_ShadowSize7;
  struct ScriptSymbol *_ShadowBaseBias7;
  struct ScriptSymbol *_ShadowFilter7;
  struct ScriptSymbol *_ShadowSlopeBias7;
  struct ScriptSymbol *_LimitCenter;
  struct ScriptSymbol *_LimitRadius;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
};

struct Wz4RenderAnimModMisc
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaModMisc *para);

  struct ScriptSymbol *_Color0;
  struct ScriptSymbol *_Color1;
  struct ScriptSymbol *_Color2;
  struct ScriptSymbol *_Color3;
  struct ScriptSymbol *_Color4;
  struct ScriptSymbol *_Color5;
  struct ScriptSymbol *_Color6;
  struct ScriptSymbol *_Color7;
  struct ScriptSymbol *_Vector0;
  struct ScriptSymbol *_Vector1;
  struct ScriptSymbol *_Vector2;
  struct ScriptSymbol *_Vector3;
  struct ScriptSymbol *_Vector4;
  struct ScriptSymbol *_Vector5;
  struct ScriptSymbol *_Vector6;
  struct ScriptSymbol *_Vector7;
  struct ScriptSymbol *_Scale0;
  struct ScriptSymbol *_Rot0;
  struct ScriptSymbol *_Trans0;
  struct ScriptSymbol *_Scale1;
  struct ScriptSymbol *_Rot1;
  struct ScriptSymbol *_Trans1;
  struct ScriptSymbol *_Scale2;
  struct ScriptSymbol *_Rot2;
  struct ScriptSymbol *_Trans2;
  struct ScriptSymbol *_Scale3;
  struct ScriptSymbol *_Rot3;
  struct ScriptSymbol *_Trans3;
};

struct Wz4RenderAnimModLightEnv
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaModLightEnv *para);

  struct ScriptSymbol *_FogNear;
  struct ScriptSymbol *_FogFar;
  struct ScriptSymbol *_FogDensity;
  struct ScriptSymbol *_FogColor;
  struct ScriptSymbol *_GroundFogNear;
  struct ScriptSymbol *_GroundFogFar;
  struct ScriptSymbol *_GroundFogDensity;
  struct ScriptSymbol *_GroundFogColor;
  struct ScriptSymbol *_GroundFogPlane;
  struct ScriptSymbol *_Clip0;
  struct ScriptSymbol *_Clip1;
  struct ScriptSymbol *_Clip2;
  struct ScriptSymbol *_Clip3;
};

struct Wz4RenderAnimModClipTwister
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaModClipTwister *para);

  struct ScriptSymbol *_Clip0;
  struct ScriptSymbol *_Clip1;
  struct ScriptSymbol *_Clip2;
  struct ScriptSymbol *_Clip3;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
};


/****************************************************************************/

void AddTypes_wz4_modmtrl_ops(sBool secondary=0);
void AddOps_wz4_modmtrl_ops(sBool secondary=0);

/****************************************************************************/

#line 212 "wz4_modmtrl_ops.ops"

  class RNModLight : public Wz4RenderNode
  {
  public:
    Wz4RenderParaModLight Para,ParaBase;
    Wz4RenderAnimModLight Anim;

    RNModLight();
    ~RNModLight();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 601 "wz4_modmtrl_ops.hpp"

/****************************************************************************/

#line 687 "wz4_modmtrl_ops.ops"

  class RNModMisc : public Wz4RenderNode
  {
  public:
    Wz4RenderParaModMisc Para,ParaBase;
    Wz4RenderAnimModMisc Anim;

    RNModMisc();
    ~RNModMisc();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 620 "wz4_modmtrl_ops.hpp"

/****************************************************************************/

#line 759 "wz4_modmtrl_ops.ops"

  class RNModLightEnv : public Wz4RenderNode
  {
  public:
    Wz4RenderParaModLightEnv Para,ParaBase;
    Wz4RenderAnimModLightEnv Anim;

    RNModLightEnv();
    ~RNModLightEnv();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 639 "wz4_modmtrl_ops.hpp"

/****************************************************************************/

#line 837 "wz4_modmtrl_ops.ops"

  class RNModClipTwister : public Wz4RenderNode
  {
  public:
    Wz4RenderParaModClipTwister Para,ParaBase;
    Wz4RenderAnimModClipTwister Anim;

    RNModClipTwister();
    ~RNModClipTwister();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 658 "wz4_modmtrl_ops.hpp"

/****************************************************************************/

#endif

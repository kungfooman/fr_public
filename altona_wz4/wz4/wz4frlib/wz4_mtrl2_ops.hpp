/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_mtrl2_ops
#define HEADER_WZ4OPS_wz4_mtrl2_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4MtrlType_ *Wz4MtrlType;
extern class SimpleMtrlType_ *SimpleMtrlType;
extern class CustomMtrlType_ *CustomMtrlType;

/****************************************************************************/

#line 9 "wz4_mtrl2_ops.ops"

#include "wz4lib/gui.hpp"
#include "wz4lib/poc_ops.hpp"
#include "base/graphics.hpp"
#include "wz4frlib/wz4_mtrl2_shader.hpp"
#include "wz4frlib/wz4_mtrl2.hpp"
#include "wz4frlib/wz4_demo2.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"

#line 30 "wz4_mtrl2_ops.hpp"
class Wz4MtrlType_ : public AnyTypeType_
{
public:
  Wz4MtrlType_() { Parent = AnyTypeType; Color= 0xff60e160; Flags = 0x0002; GuiSets = 0x0002; Symbol = L"Wz4Mtrl"; Label = L"New Wz4 Material";  Init(); }
  ~Wz4MtrlType_() { Exit(); }
#line 35 "wz4_mtrl2_ops.ops"

  friend class Wz4Mtrl;
  private:
    sGeometry *Torus;

    sMaterial *Shaders[sRF_TOTAL];
    sVertexFormatHandle *Formats[sRF_TOTAL];

    sCBuffer<Wz4MtrlWireframePara> WireCB;
    sCBuffer<Wz4MtrlModelPara> WireCBModel;
    sCBuffer<Wz4MtrlZOnlyPara> ZOnlyCB;

    sArray<Wz4MtrlType_ *> Materials;    // used to reset all LightEnv's when camera changes
    sCBufferBase SkinCB;
    sArray<sMatrix34CM> SkinCBBuffer;
    sMatrix34CM *SkinCBPtr;
  public:
    void Init();
    void Exit();
    void Show(wObject *obj,wPaintInfo &pi);
    void MakeTorus();

    sCBufferBase *MakeSkinCB(sInt SkinMatCount,const sMatrix34CM *SkinMats,sInt *SkinMatMap,sInt cb);
    void SetDefaultShader(sInt flags,const sMatrix34CM *mat,sInt variant,sInt SkinCount,const sMatrix34CM *SkinMats,sInt *SkinMatMap);  // variant: culloff, cullon, cullinv
    sVertexFormatHandle *GetDefaultFormat(sInt flags);
    sCBuffer<Wz4MtrlModelPara> IdentCBModel;

    void PrepareRender(Wz4RenderContext *ctx);  // called first. then Mtrl->BeforeFrame will be called. here you can query the viewport of the main render pass
    void BeginRender(Wz4RenderContext *ctx);    // after Mtrl->BeforeFrame and before actual painting
    void PrepareView(sViewport &view);          // called before each pass is actrually painted, with the appropriate viewport
    void EndRender(Wz4RenderContext *ctx);      // after actual painting
    void RegisterMtrl(Wz4MtrlType_ *);
    virtual void PrepareViewR(sViewport &view) {}
    virtual void PrepareRenderR(Wz4RenderContext *ctx) {}
    virtual void BeginRenderR(Wz4RenderContext *ctx) {}
    virtual void EndRenderR(Wz4RenderContext *ctx) {}

    sMatrix34 View;
    sMatrix44 Proj;
    sMatrix44 VP;
  
#line 78 "wz4_mtrl2_ops.hpp"
#line 80 "wz4_mtrl2_ops.hpp"
};

class SimpleMtrlType_ : public Wz4MtrlType_
{
public:
  SimpleMtrlType_() { Parent = Wz4MtrlType; Color= 0xff60e060; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"SimpleMtrl"; Label = L"Simple Material";  Init(); }
  ~SimpleMtrlType_() { Exit(); }
#line 88 "wz4_mtrl2_ops.ops"

    void Init();
    void Exit();
    void BeginShow(wPaintInfo &pi);
    void PrepareViewR(sViewport &view);

    struct LightEnv_
    {
      sCBuffer<SimpleShaderVEnv> cbv;
      sCBuffer<SimpleShaderPEnv> cbp;
      sCBuffer<Wz4MtrlModelPara> cbm;
      sMatrix34 TexTrans;
    };
    
    LightEnv_ *LightEnv[sMAX_LIGHTENV];
    sMatrix34 ViewMatrix;
  
#line 105 "wz4_mtrl2_ops.hpp"
#line 107 "wz4_mtrl2_ops.hpp"
};

class CustomMtrlType_ : public Wz4MtrlType_
{
public:
  CustomMtrlType_() { Parent = Wz4MtrlType; Color= 0xff60e060; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"CustomMtrl"; Label = L"Custom Material";  Init(); }
  ~CustomMtrlType_() { Exit(); }
#line 220 "wz4_mtrl2_ops.ops"

    void Init();
    void Exit();
    void BeginShow(wPaintInfo &pi);
    void PrepareViewR(sViewport &view);

    const sViewport *Viewport;
  
#line 123 "wz4_mtrl2_ops.hpp"
#line 125 "wz4_mtrl2_ops.hpp"
};

struct SimpleMtrlParaSimpleMaterial
{
  sInt Flags;
  sInt Blend;
  sInt Texture0;
  sInt Texture1;
  sInt AlphaTest;
  sInt AlphaRef;
  sInt Extras;
  sInt UVTrans;
  sF32 SimpleScale;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Texture2;
  sF32 VertexScale;
};

struct CustomMtrlParaCustomMaterial2
{
  sInt Flags;
  sInt Blend;
  sInt AlphaTest;
  sInt AlphaRef;
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
  sInt TexFilter0;
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
};

struct CustomMtrlParaCustomMaterial
{
  sInt Flags;
  sInt Blend;
  sInt AlphaTest;
  sInt AlphaRef;
};

struct Wz4RenderParaSimpleMtrlEnv
{
  sInt Index;
  sU32 Ambient;
  sU32 Color0;
  sVector30 Dir0;
  sU32 Color1;
  sVector30 Dir1;
  sU32 Color2;
  sVector30 Dir2;
  sU32 Color3;
  sVector30 Dir3;
  sF32 FogNear;
  sF32 FogFar;
  sU32 FogColor;
  sInt _pad21;
  sInt Headlights;
  sInt Renderpass;
  sInt ClipPlanes;
  sVector30 Plane0Dir;
  sF32 Plane0Dist;
  sVector30 Plane1Dir;
  sF32 Plane1Dist;
  sVector30 Plane2Dir;
  sF32 Plane2Dist;
  sVector30 Plane3Dir;
  sF32 Plane3Dist;
  sF32 Color0Amp;
  sF32 Color1Amp;
  sF32 Color2Amp;
  sF32 Color3Amp;
  sVector31 TexScale;
  sVector30 TexRot;
  sVector31 TexTrans;
};


/****************************************************************************/

struct SimpleMtrlAnimSimpleMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SimpleMtrlParaSimpleMaterial *para);

};

struct CustomMtrlAnimCustomMaterial2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,CustomMtrlParaCustomMaterial2 *para);

};

struct CustomMtrlAnimCustomMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,CustomMtrlParaCustomMaterial *para);

};

struct Wz4RenderAnimSimpleMtrlEnv
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSimpleMtrlEnv *para);

  struct ScriptSymbol *_Ambient;
  struct ScriptSymbol *_Color0;
  struct ScriptSymbol *_Color0Amp;
  struct ScriptSymbol *_Dir0;
  struct ScriptSymbol *_Color1;
  struct ScriptSymbol *_Color1Amp;
  struct ScriptSymbol *_Dir1;
  struct ScriptSymbol *_Color2;
  struct ScriptSymbol *_Color2Amp;
  struct ScriptSymbol *_Dir2;
  struct ScriptSymbol *_Color3;
  struct ScriptSymbol *_Color3Amp;
  struct ScriptSymbol *_Dir3;
  struct ScriptSymbol *_FogNear;
  struct ScriptSymbol *_FogFar;
  struct ScriptSymbol *_FogColor;
  struct ScriptSymbol *_Plane0Dir;
  struct ScriptSymbol *_Plane0Dist;
  struct ScriptSymbol *_Plane1Dir;
  struct ScriptSymbol *_Plane1Dist;
  struct ScriptSymbol *_Plane2Dir;
  struct ScriptSymbol *_Plane2Dist;
  struct ScriptSymbol *_Plane3Dir;
  struct ScriptSymbol *_Plane3Dist;
  struct ScriptSymbol *_TexScale;
  struct ScriptSymbol *_TexRot;
  struct ScriptSymbol *_TexTrans;
};


/****************************************************************************/

void AddTypes_wz4_mtrl2_ops(sBool secondary=0);
void AddOps_wz4_mtrl2_ops(sBool secondary=0);

/****************************************************************************/

#line 470 "wz4_mtrl2_ops.ops"

  class RNSimpleMtrlEnv : public Wz4RenderNode
  {
  public: 
    Wz4RenderParaSimpleMtrlEnv Para,ParaBase;
    Wz4RenderAnimSimpleMtrlEnv Anim;

    RNSimpleMtrlEnv();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 302 "wz4_mtrl2_ops.hpp"

/****************************************************************************/

#endif

/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_rovemtrl_ops
#define HEADER_WZ4OPS_wz4_rovemtrl_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class RoveMtrlType_ *RoveMtrlType;

/****************************************************************************/

#line 9 "wz4_rovemtrl_ops.ops"

#include "wz4frlib/wz4_rovemtrl.hpp"
#include "wz4frlib/wz4_rovemtrl_shader.hpp"
#include "wz4frlib/wz4_mtrl2.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"

#line 25 "wz4_rovemtrl_ops.hpp"
class RoveMtrlType_ : public Wz4MtrlType_
{
public:
  RoveMtrlType_() { Parent = Wz4MtrlType; Color= 0xff60e060; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"RoveMtrl"; Label = L"Rove Material";  Init(); }
  ~RoveMtrlType_() { Exit(); }
#line 26 "wz4_rovemtrl_ops.ops"

    void Init();
    void Exit();
    void PrepareViewR(sViewport &view);

    sTextureCube *EmptyCube;

    struct LightEnv_
    {
      sCBuffer<RoveShaderVEnv> cbv;
      sCBuffer<RoveShaderPEnv> cbp;
      sCBuffer<Wz4MtrlModelPara> cbm;
      sMatrix34 TexTrans;
      sTextureCube *LightCube; // no ownership
    };

    LightEnv_ *LightEnv[sMAX_LIGHTENV];
    sMatrix34 ViewMatrix;
  
#line 51 "wz4_rovemtrl_ops.hpp"
#line 53 "wz4_rovemtrl_ops.hpp"
};

struct RoveMtrlParaRoveMaterial
{
  sInt Flags;
  sInt Texture0;
  sInt Texture1;
  sInt Extras;
  sInt UVTrans;
  sF32 SimpleScale;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct Wz4RenderParaRoveMtrlEnv
{
  sInt Index;
  sInt Renderpass;
  sU32 Ambient;
  sU32 Color0;
  sF32 Color0Amp;
  sVector31 Pos0;
  sF32 Range0;
  sInt LightType;
  sU32 Color1;
  sF32 Color1Amp;
  sVector31 Pos1;
  sF32 Range1;
  sU32 Color2;
  sF32 Color2Amp;
  sVector31 Pos2;
  sF32 Range2;
  sU32 Color3;
  sF32 Color3Amp;
  sVector31 Pos3;
  sF32 Range3;
  sF32 FogNear;
  sF32 FogFar;
  sU32 FogColor;
  sInt ClipPlanes;
  sVector30 Plane0Dir;
  sF32 Plane0Dist;
  sVector30 Plane1Dir;
  sF32 Plane1Dist;
  sVector30 Plane2Dir;
  sF32 Plane2Dist;
  sVector30 Plane3Dir;
  sF32 Plane3Dist;
  sVector31 TexScale;
  sVector30 TexRot;
  sVector31 TexTrans;
};


/****************************************************************************/

struct RoveMtrlAnimRoveMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,RoveMtrlParaRoveMaterial *para);

};

struct Wz4RenderAnimRoveMtrlEnv
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaRoveMtrlEnv *para);

  struct ScriptSymbol *_Ambient;
  struct ScriptSymbol *_Color0;
  struct ScriptSymbol *_Color0Amp;
  struct ScriptSymbol *_Pos0;
  struct ScriptSymbol *_Range0;
  struct ScriptSymbol *_Color1;
  struct ScriptSymbol *_Color1Amp;
  struct ScriptSymbol *_Pos1;
  struct ScriptSymbol *_Range1;
  struct ScriptSymbol *_Color2;
  struct ScriptSymbol *_Color2Amp;
  struct ScriptSymbol *_Pos2;
  struct ScriptSymbol *_Range2;
  struct ScriptSymbol *_Color3;
  struct ScriptSymbol *_Color3Amp;
  struct ScriptSymbol *_Pos3;
  struct ScriptSymbol *_Range3;
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

void AddTypes_wz4_rovemtrl_ops(sBool secondary=0);
void AddOps_wz4_rovemtrl_ops(sBool secondary=0);

/****************************************************************************/

#line 124 "wz4_rovemtrl_ops.ops"

  class RNRoveMtrlEnv : public Wz4RenderNode
  {
  public:
    Wz4RenderParaRoveMtrlEnv Para,ParaBase;
    Wz4RenderAnimRoveMtrlEnv Anim;

    TextureCube *LightCube;

    RNRoveMtrlEnv();
    ~RNRoveMtrlEnv();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 180 "wz4_rovemtrl_ops.hpp"

/****************************************************************************/

#endif

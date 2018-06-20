/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#define sPEDANTIC_OBSOLETE 1
#define sPEDANTIC_WARN 1
#include "gui/gui.hpp"
#include "gui/textwindow.hpp"
#include "wz4lib/script.hpp"
#include "fr063_mandelbulb_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class MandelbulbIsoDataType_ *MandelbulbIsoDataType;

/****************************************************************************/

#line 13 "fr063_mandelbulb_ops.ops"

#include "wz4frlib/fr063_mandelbulb.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 

#line 31 "fr063_mandelbulb_ops.cpp"

/****************************************************************************/

#line 75 "fr063_mandelbulb_ops.ops"
void MandelbulbIsoDataType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 76 "fr063_mandelbulb_ops.ops"
 sSetTarget(sTargetPara(sCLEAR_ALL,pi.BackColor,pi.Spec)); ;
#line 40 "fr063_mandelbulb_ops.cpp"
}

/****************************************************************************/

sBool Wz4RenderCmdFR063_Mandelbulb(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_Mandelbulb sUNUSED *para = (Wz4RenderParaFR063_Mandelbulb *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 52 "fr063_mandelbulb_ops.ops"

    RNFR063_Mandelbulb *node = new RNFR063_Mandelbulb();
    node->ParaBase = node->Para = *para;
    node->Mtrl = in0; in0->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
    if(cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out;
      cmd->Op->RefObj->AddRef();
    }
  ;
#line 68 "fr063_mandelbulb_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFR063_Mandelbulb(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_Mandelbulb sUNUSED *para = (Wz4RenderParaFR063_Mandelbulb *)(op->EditData); para;

  gh.Group(L"Lod");

  gh.Label(L"LodSplit");
  sFloatControl *float_LodSplit = gh.Float(&para->LodSplit,0.000000f,16.00000f,0.001000f);
  float_LodSplit->Default = 0.075000f; float_LodSplit->RightStep = 0.125000f;

  gh.Label(L"LodDraw");
  sFloatControl *float_LodDraw = gh.Float(&para->LodDraw,0.000000f,16.00000f,0.001000f);
  float_LodDraw->Default = 0.070000f; float_LodDraw->RightStep = 0.125000f;

  gh.Label(L"LodDrop");
  sFloatControl *float_LodDrop = gh.Float(&para->LodDrop,0.000000f,16.00000f,0.001000f);
  float_LodDrop->Default = 0.060000f; float_LodDrop->RightStep = 0.125000f;

  gh.Label(L"LodAll");
  sFloatControl *float_LodAll = gh.Float(&para->LodAll,0.000000f,16.00000f,0.001000f);
  float_LodAll->Default = 1.000000f; float_LodAll->RightStep = 0.125000f;

  gh.Group(L"Fractal");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Reset",gh.ActionMsg);

  gh.Label(L"IsoValue");
  sFloatControl *float_IsoValue = gh.Float(&para->IsoValue,0.000000f,16.00000f,0.010000f);
  float_IsoValue->Default = 0.500000f; float_IsoValue->RightStep = 0.125000f;

  gh.Label(L"Iterations");
  sIntControl *int_Iterations = gh.Int(&para->Iterations,1,16,0.125000f);
  int_Iterations->Default = 0x00000005; int_Iterations->RightStep = 0.125000f;

  gh.Label(L"Scale");
  sFloatControl *float_Scale = gh.Float(&para->Scale,0.000000f,1024.000f,0.010000f);
  float_Scale->Default = 1.000000f; float_Scale->RightStep = 0.125000f;

  gh.Group(L"Render");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"new paras");

  gh.Label(L"directional shadow level");
  gh.Flags(&para->ShadowLevel,L" 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"-|limited|pipelined",gh.ChangeMsg);

  gh.Label(L"NodesPerFrame");
  sIntControl *int_NodesPerFrame = gh.Int(&para->NodesPerFrame,1,1024,0.250000f);
  int_NodesPerFrame->Default = 0x00000010; int_NodesPerFrame->RightStep = 0.125000f;

  gh.Label(L"GeoBufferCount");
  sIntControl *int_GeoBufferCount = gh.Int(&para->GeoBufferCount,4,64,0.125000f);
  int_GeoBufferCount->Default = 0x00000018; int_GeoBufferCount->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFR063_Mandelbulb(wOp *op)
{
  Wz4RenderParaFR063_Mandelbulb sUNUSED *para = (Wz4RenderParaFR063_Mandelbulb *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->LodSplit = 0.075000f;
  para->LodDraw = 0.070000f;
  para->LodDrop = 0.060000f;
  para->LodAll = 1.000000f;
  para->IsoValue = 0.500000f;
  para->Iterations = 0x00000005;
  para->Scale = 1.000000f;
  para->NodesPerFrame = 0x00000010;
  para->GeoBufferCount = 0x00000018;
}

void Wz4RenderBindFR063_Mandelbulb(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lodsplit"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"loddraw"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"loddrop"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"lodall"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"isovalue"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"iterations"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"nodesperframe"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"geobuffercount"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_Mandelbulb(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[20];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lod");
    name[1] = sPoolString(L"lodsplit");
    name[2] = sPoolString(L"loddraw");
    name[3] = sPoolString(L"loddrop");
    name[4] = sPoolString(L"lodall");
    name[5] = sPoolString(L"fractal");
    name[6] = sPoolString(L"reset");
    name[7] = sPoolString(L"isovalue");
    name[8] = sPoolString(L"iterations");
    name[9] = sPoolString(L"scale");
    name[10] = sPoolString(L"render");
    name[11] = sPoolString(L"lightenv");
    name[12] = sPoolString(L"renderpass");
    name[13] = sPoolString(L"");
    name[14] = sPoolString(L"shadowlevel");
    name[15] = sPoolString(L"multithreading");
    name[16] = sPoolString(L"nodesperframe");
    name[17] = sPoolString(L"geobuffercount");
    name[18] = sPoolString(L"");
    name[19] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[11],ScriptTypeInt,1,cmd->Data+7);
  ctx->AddImport(name[12],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[16],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[17],ScriptTypeInt,1,cmd->Data+12);
  ctx->AddImport(name[19],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_Mandelbulb(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lodsplit : float;\n");
  tb.PrintF(L"  import loddraw : float;\n");
  tb.PrintF(L"  import loddrop : float;\n");
  tb.PrintF(L"  import lodall : float;\n");
  tb.PrintF(L"  import isovalue : float;\n");
  tb.PrintF(L"  import iterations : int;\n");
  tb.PrintF(L"  import scale : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import nodesperframe : int;\n");
  tb.PrintF(L"  import geobuffercount : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_Mandelbulb =
L"= Wz4Render : FR063_Mandelbulb\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_Mandelbulb\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Render\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Wz4Mtrl\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i LodSplit\n"
L" !i LodSplit\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LodDraw\n"
L" !i LodDraw\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LodDrop\n"
L" !i LodDrop\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LodAll\n"
L" !i LodAll\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Reset\n"
L" !i Reset\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i IsoValue\n"
L" !i IsoValue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Iterations\n"
L" !i Iterations\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i directional shadow level\n"
L" !i ShadowLevel\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Multithreading\n"
L" !i Multithreading\n"
L" !i limited\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pipelined\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i NodesPerFrame\n"
L" !i NodesPerFrame\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i GeoBufferCount\n"
L" !i GeoBufferCount\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Script\n"
L" !i Script\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool MandelbulbIsoDataCmdFR063_MandelbulbIsoData(wExecutive *exe,wCommand *cmd)
{
  MandelbulbIsoDataParaFR063_MandelbulbIsoData sUNUSED *para = (MandelbulbIsoDataParaFR063_MandelbulbIsoData *)(cmd->Data); para;
  MandelbulbIsoData *out = (MandelbulbIsoData *) cmd->Output;
  if(!out) { out=new MandelbulbIsoData; cmd->Output=out; }

  {
#line 90 "fr063_mandelbulb_ops.ops"

    out->Para = *para;
    out->Init();
  ;
#line 424 "fr063_mandelbulb_ops.cpp"
    return 1;
  }
}

void MandelbulbIsoDataGuiFR063_MandelbulbIsoData(wGridFrameHelper &gh,wOp *op)
{
  MandelbulbIsoDataParaFR063_MandelbulbIsoData sUNUSED *para = (MandelbulbIsoDataParaFR063_MandelbulbIsoData *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Iterations");
  sIntControl *int_Iterations = gh.Int(&para->Iterations,1,16,0.125000f);
  int_Iterations->Default = 0x00000005; int_Iterations->RightStep = 0.125000f;

  gh.Label(L"OctreeDivisions");
  gh.Flags(&para->OctreeDivisions,L" 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"*2-|initialization",gh.ChangeMsg);
}

void MandelbulbIsoDataDefFR063_MandelbulbIsoData(wOp *op)
{
  MandelbulbIsoDataParaFR063_MandelbulbIsoData sUNUSED *para = (MandelbulbIsoDataParaFR063_MandelbulbIsoData *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Iterations = 0x00000005;
  para->OctreeDivisions = 0x00000002;
}

void MandelbulbIsoDataBindFR063_MandelbulbIsoData(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"iterations"),val);
}
void MandelbulbIsoDataBind2FR063_MandelbulbIsoData(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"iterations");
    name[1] = sPoolString(L"octreedivisions");
    name[2] = sPoolString(L"multithreading");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
}
void MandelbulbIsoDataBind3FR063_MandelbulbIsoData(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import iterations : int;\n");
}
const sChar *MandelbulbIsoDataWikiFR063_MandelbulbIsoData =
L"= MandelbulbIsoData : FR063_MandelbulbIsoData\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_MandelbulbIsoData\n"
L"\n"
L"  !i Output Type\n"
L"  !i MandelbulbIsoData\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Iterations\n"
L" !i Iterations\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i OctreeDivisions\n"
L" !i OctreeDivisions\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Multithreading\n"
L" !i Multithreading\n"
L" !i initialization\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4RenderCmdFR063_MandelbulbIso(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_MandelbulbIso sUNUSED *para = (Wz4RenderParaFR063_MandelbulbIso *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  MandelbulbIsoData sUNUSED *in1 = cmd->GetInput<MandelbulbIsoData *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 116 "fr063_mandelbulb_ops.ops"

    RNFR063_MandelbulbIso *node = new RNFR063_MandelbulbIso();
    node->ParaBase = node->Para = *para;
    node->IsoData = in1; in1->AddRef();
    node->Mtrl = in0; in0->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 572 "fr063_mandelbulb_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFR063_MandelbulbIso(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_MandelbulbIso sUNUSED *para = (Wz4RenderParaFR063_MandelbulbIso *)(op->EditData); para;

  gh.Group(L"Fractal");

  gh.Label(L"* IsoValue");
  sFloatControl *float_IsoValue = gh.Float(&para->IsoValue,0.000000f,16.00000f,0.010000f);
  float_IsoValue->Default = 0.500000f; float_IsoValue->RightStep = 0.125000f;

  if(0x0000)
  {
    gh.Label(L"* Iterations_");
    sIntControl *int_Iterations_ = gh.Int(&para->Iterations_,1,16,0.125000f);
    int_Iterations_->Default = 0x00000005; int_Iterations_->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"* Scale_");
    sFloatControl *float_Scale_ = gh.Float(&para->Scale_,0.000000f,1024.000f,0.010000f);
    float_Scale_->Default = 1.000000f; float_Scale_->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"OctreeDivisions_");
    gh.Flags(&para->OctreeDivisions_,L" 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

  }
  gh.Group(L"Render");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"dynamic|static",gh.ChangeMsg);

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"-|limited",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFR063_MandelbulbIso(wOp *op)
{
  Wz4RenderParaFR063_MandelbulbIso sUNUSED *para = (Wz4RenderParaFR063_MandelbulbIso *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->IsoValue = 0.500000f;
  para->Iterations_ = 0x00000005;
  para->Scale_ = 1.000000f;
  para->OctreeDivisions_ = 0x00000002;
}

void Wz4RenderBindFR063_MandelbulbIso(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"isovalue"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"iterations_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"scale_"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_MandelbulbIso(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"fractal");
    name[1] = sPoolString(L"isovalue");
    name[2] = sPoolString(L"iterations_");
    name[3] = sPoolString(L"scale_");
    name[4] = sPoolString(L"octreedivisions_");
    name[5] = sPoolString(L"render");
    name[6] = sPoolString(L"lightenv");
    name[7] = sPoolString(L"renderpass");
    name[8] = sPoolString(L"flags");
    name[9] = sPoolString(L"multithreading");
    name[10] = sPoolString(L"");
    name[11] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[11],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_MandelbulbIso(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import isovalue : float;\n");
  tb.PrintF(L"  import iterations_ : int;\n");
  tb.PrintF(L"  import scale_ : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_MandelbulbIso =
L"= Wz4Render : FR063_MandelbulbIso\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_MandelbulbIso\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Render\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Wz4Mtrl\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i MandelbulbIsoData\n"
L" !i defaults to: FR063_MandelbulbIsoData\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i IsoValue\n"
L" !i IsoValue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Iterations_\n"
L" !i Iterations_\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Scale_\n"
L" !i Scale_\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i OctreeDivisions_\n"
L" !i OctreeDivisions_\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i dynamic\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i static\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Multithreading\n"
L" !i Multithreading\n"
L" !i limited\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Script\n"
L" !i Script\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

void Wz4RenderAnimFR063_Mandelbulb::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimFR063_Mandelbulb::Bind(class ScriptContext *sc,Wz4RenderParaFR063_Mandelbulb *para)
{
};

void MandelbulbIsoDataAnimFR063_MandelbulbIsoData::Init(class ScriptContext *sc)
{
};

void MandelbulbIsoDataAnimFR063_MandelbulbIsoData::Bind(class ScriptContext *sc,MandelbulbIsoDataParaFR063_MandelbulbIsoData *para)
{
};

void Wz4RenderAnimFR063_MandelbulbIso::Init(class ScriptContext *sc)
{
  _IsoValue = sc->AddSymbol(L"isovalue");
  _Iterations_ = sc->AddSymbol(L"iterations_");
  _Scale_ = sc->AddSymbol(L"scale_");
};

void Wz4RenderAnimFR063_MandelbulbIso::Bind(class ScriptContext *sc,Wz4RenderParaFR063_MandelbulbIso *para)
{
  sc->BindLocalFloat(_IsoValue,1,&para->IsoValue);
  sc->BindLocalInt(_Iterations_,1,&para->Iterations_);
  sc->BindLocalFloat(_Scale_,1,&para->Scale_);
};


/****************************************************************************/

void AddTypes_fr063_mandelbulb_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(MandelbulbIsoDataType = new MandelbulbIsoDataType_);
  MandelbulbIsoDataType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_fr063_mandelbulb_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"FR063_Mandelbulb";
  cl->Label = L"FR063_Mandelbulb";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_Mandelbulb;
  cl->MakeGui = Wz4RenderGuiFR063_Mandelbulb;
  cl->SetDefaults = Wz4RenderDefFR063_Mandelbulb;
  cl->BindPara = Wz4RenderBindFR063_Mandelbulb;
  cl->Bind2Para = Wz4RenderBind2FR063_Mandelbulb;
  cl->Bind3Para = Wz4RenderBind3FR063_Mandelbulb;
  cl->WikiText = Wz4RenderWikiFR063_Mandelbulb;
  cl->ParaStrings = 1;
  cl->ParaWords = 13;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  cl->ActionIds.AddMany(1)->Init(L"Reset",1);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_MandelbulbIsoData";
  cl->Label = L"FR063_MandelbulbIsoData";
  cl->OutputType = MandelbulbIsoDataType;
  cl->TabType = Wz4RenderType;
  cl->Command = MandelbulbIsoDataCmdFR063_MandelbulbIsoData;
  cl->MakeGui = MandelbulbIsoDataGuiFR063_MandelbulbIsoData;
  cl->SetDefaults = MandelbulbIsoDataDefFR063_MandelbulbIsoData;
  cl->BindPara = MandelbulbIsoDataBindFR063_MandelbulbIsoData;
  cl->Bind2Para = MandelbulbIsoDataBind2FR063_MandelbulbIsoData;
  cl->Bind3Para = MandelbulbIsoDataBind3FR063_MandelbulbIsoData;
  cl->WikiText = MandelbulbIsoDataWikiFR063_MandelbulbIsoData;
  cl->ParaWords = 3;
  cl->Column = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_MandelbulbIso";
  cl->Label = L"FR063_MandelbulbIso";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_MandelbulbIso;
  cl->MakeGui = Wz4RenderGuiFR063_MandelbulbIso;
  cl->SetDefaults = Wz4RenderDefFR063_MandelbulbIso;
  cl->BindPara = Wz4RenderBindFR063_MandelbulbIso;
  cl->Bind2Para = Wz4RenderBind2FR063_MandelbulbIso;
  cl->Bind3Para = Wz4RenderBind3FR063_MandelbulbIso;
  cl->WikiText = Wz4RenderWikiFR063_MandelbulbIso;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = MandelbulbIsoDataType;
  in[1].DefaultClass = Doc->FindClass(L"FR063_MandelbulbIsoData",L"MandelbulbIsoData");
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fr063_mandelbulb_ops,0x110,AddOps_fr063_mandelbulb_ops,0);


/****************************************************************************/


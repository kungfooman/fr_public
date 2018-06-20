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
#include "wz4_demo2_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4RenderType_ *Wz4RenderType;
class Wz4ParticlesType_ *Wz4ParticlesType;
class Rendertarget2DType_ *Rendertarget2DType;

/****************************************************************************/

#line 15 "wz4_demo2_ops.ops"

#include "wz4frlib/wz4_demo2.hpp"
#include "wz4frlib/wz4_demo2nodes.hpp"
//#include "wz4frlib/chaosmesh_code.hpp"
#include "wz4lib/script.hpp"
#include "wz4frlib/wz4_gui.hpp"

#line 33 "wz4_demo2_ops.cpp"

/****************************************************************************/

#line 297 "wz4_demo2_ops.ops"

  void RenderCode(GenBitmapParaRender *para,Wz4Render *in0,GenBitmap *out);

#line 41 "wz4_demo2_ops.cpp"

/****************************************************************************/

#line 83 "wz4_demo2_ops.ops"
void Rendertarget2DType_::EndShow(wPaintInfo &pi)
{
#line 84 "wz4_demo2_ops.ops"

    Rendertarget2D *rt;
    sFORALL(Targets,rt)
      rt->EndShow();
    Targets.Clear();
  ;
#line 55 "wz4_demo2_ops.cpp"
}

/****************************************************************************/

sBool Rendertarget2DCmdRendertarget2(wExecutive *exe,wCommand *cmd)
{
  Rendertarget2DParaRendertarget2 sUNUSED *para = (Rendertarget2DParaRendertarget2 *)(cmd->Data); para;
  Rendertarget2D *out = (Rendertarget2D *) cmd->Output;
  if(!out) { out=new Rendertarget2D; cmd->Output=out; }

  {
#line 110 "wz4_demo2_ops.ops"

    static int modes[] = { sTEX_ARGB8888,sTEX_ARGB32F };
    out->Flags = para->Flags;
    out->Format = modes[para->Mode];
    switch(para->Flags & 3)
    {
    case 0:
      out->SizeX = 1<<((para->Size2>>0)&255);
      out->SizeY = 1<<((para->Size2>>8)&255);
      break;
    case 1:
      out->SizeX = para->Divider[0];
      out->SizeY = para->Divider[1];
      break;
    case 2:
      out->SizeX = para->Size[0];
      out->SizeY = para->Size[1];
      break;
    }
    out->AtlasPower = para->AtlasCount;
    out->Init();
  ;
#line 90 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Rendertarget2DGuiRendertarget2(wGridFrameHelper &gh,wOp *op)
{
  Rendertarget2DParaRendertarget2 sUNUSED *para = (Rendertarget2DParaRendertarget2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0power2|relative|absolute:*4discard|keep",gh.LayoutMsg);

  if(((para->Flags&0x0003)==0x0000))
  {
    gh.Label(L"Size");
    gh.Flags(&para->Size2,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  }
  if(((para->Flags&0x0003)==0x0001))
  {
    gh.Label(L"Divider");
    gh.BeginTied();
    sIntControl *int_Divider_0 = gh.Int(&para->Divider[0],1,256,0.125000f);
    int_Divider_0->Default = 0x00000001; int_Divider_0->RightStep = 0.125000f;
    sIntControl *int_Divider_1 = gh.Int(&para->Divider[1],1,256,0.125000f);
    int_Divider_1->Default = 0x00000001; int_Divider_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Flags&0x0003)==0x0002))
  {
    gh.Label(L"Size");
    gh.BeginTied();
    sIntControl *int_Size_0 = gh.Int(&para->Size[0],1,16384,0.125000f);
    int_Size_0->Default = 0x00000100; int_Size_0->RightStep = 0.125000f;
    sIntControl *int_Size_1 = gh.Int(&para->Size[1],1,16384,0.125000f);
    int_Size_1->Default = 0x00000100; int_Size_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"argb8888|argb32f",gh.ChangeMsg);

  gh.Label(L"AtlasCount");
  gh.Flags(&para->AtlasCount,L" 1| 2| 4| 8| 16| 32",gh.ChangeMsg);
}

void Rendertarget2DDefRendertarget2(wOp *op)
{
  Rendertarget2DParaRendertarget2 sUNUSED *para = (Rendertarget2DParaRendertarget2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size2 = 0x00000808;
  para->Divider[0] = 0x00000001;
  para->Divider[1] = 0x00000001;
  para->Size[0] = 0x00000100;
  para->Size[1] = 0x00000100;
}

void Rendertarget2DBindRendertarget2(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"divider"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"divider"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
}
void Rendertarget2DBind2Rendertarget2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"size");
    name[2] = sPoolString(L"divider");
    name[3] = sPoolString(L"size");
    name[4] = sPoolString(L"mode");
    name[5] = sPoolString(L"atlascount");
  }
  ctx->AddImport(name[2],ScriptTypeInt,2,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,2,cmd->Data+4);
}
void Rendertarget2DBind3Rendertarget2(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import divider : int[2];\n");
  tb.PrintF(L"  import size : int[2];\n");
}
const sChar *Rendertarget2DWikiRendertarget2 =
L"= Rendertarget2D : Rendertarget2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Rendertarget2\n"
L"\n"
L"  !i Output Type\n"
L"  !i Rendertarget2D\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i power2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i relative\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i absolute\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i discard\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i keep\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Size\n"
L" !i Size2\n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
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
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Divider\n"
L" !i Divider\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i argb8888\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i argb32f\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i AtlasCount\n"
L" !i AtlasCount\n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
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

sBool Wz4RenderCmdRender(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaRender sUNUSED *para = (Wz4RenderParaRender *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 145 "wz4_demo2_ops.ops"

    if(cmd->Strings[0][0]==0)
    {
      out->RootNode = new Wz4RenderNode;
      out->RootNode->MayCollapse = 1;
    }
    else
    {
      out->RootNode = new RNAdd;
    }
    out->AddChilds(cmd,0);
  ;
#line 430 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiRender(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaRender sUNUSED *para = (Wz4RenderParaRender *)(op->EditData); para;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefRender(wOp *op)
{
  Wz4RenderParaRender sUNUSED *para = (Wz4RenderParaRender *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindRender(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Render(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"");
    name[1] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Render(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiRender =
L"= Wz4Render : Render\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Render\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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

sBool Wz4RenderCmdRenderNull(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaRenderNull sUNUSED *para = (Wz4RenderParaRenderNull *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 169 "wz4_demo2_ops.ops"

    out->RootNode = new RNAdd;
    out->AddChilds(cmd,0);
  ;
#line 541 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiRenderNull(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaRenderNull sUNUSED *para = (Wz4RenderParaRenderNull *)(op->EditData); para;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefRenderNull(wOp *op)
{
  Wz4RenderParaRenderNull sUNUSED *para = (Wz4RenderParaRenderNull *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindRenderNull(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2RenderNull(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"");
    name[1] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3RenderNull(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiRenderNull =
L"= Wz4Render : RenderNull\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i RenderNull\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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

sBool Wz4RenderCmdCamera(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCamera sUNUSED *para = (Wz4RenderParaCamera *)(cmd->Data); para;
  Rendertarget2D sUNUSED *in0 = cmd->GetInput<Rendertarget2D *>(0); in0;
  Wz4Render sUNUSED *in1 = cmd->GetInput<Wz4Render *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 251 "wz4_demo2_ops.ops"

    RNCamera *node = new RNCamera();
    node->ParaBase = node->Para = *para;
    node->Init(cmd->Strings[1]);
    node->Target = in0; in0->AddRef();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass,1);
  ;
#line 657 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndCamera(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaCamera sUNUSED *para = (Wz4RenderParaCamera *)(op->EditData); para;
#line 240 "wz4_demo2_ops.ops"

    if(pi.CamOverride)
    {
      if(para->Mode==0 || para->Mode==1)
        pi.Handle3D(op,1,para->Position,wHM_PLANE);
      if(para->Mode==0 || para->Mode==2)
        pi.Handle3D(op,2,para->Target,wHM_PLANE);
    }
  ;
#line 675 "wz4_demo2_ops.cpp"
}

sInt Wz4RenderActCamera(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaCamera sUNUSED *para = (Wz4RenderParaCamera *)(op->EditData); para;
#line 224 "wz4_demo2_ops.ops"

    if(code==1)
    {
      para->Position = Doc->LastView.Camera.l;
      para->Target = para->Position + Doc->LastView.Camera.k;
      para->Zoom = Doc->LastView.ZoomY;

      return 1;
    }
    else
    {
      return 0;
    }
  ;
#line 696 "wz4_demo2_ops.cpp"
}

void Wz4RenderGuiCamera(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCamera sUNUSED *para = (Wz4RenderParaCamera *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"CopyCam",gh.ActionMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"target|rot|schleuder|spline",gh.LayoutMsg);

  if((para->Mode==0x0003))
  {
    gh.Label(L"Spline");
    gh.String(op->EditString[1]);

    gh.Label(L"* SplineTime");
    sFloatControl *float_SplineTime = gh.Float(&para->SplineTime,0.000000f,1.000000f,0.010000f);
    float_SplineTime->Default = 0.000000f; float_SplineTime->RightStep = 0.125000f;

  }
  if(((para->Mode!=0x0003)&&((para->Mode==0x0000)||(para->Mode==0x0001))))
  {
    gh.Label(L"* Position");
    gh.BeginTied();
    sFloatControl *float_Position_0 = gh.Float(&para->Position.x,-1024.00f,1024.000f,0.010000f);
    float_Position_0->Default = 0.000000f; float_Position_0->RightStep = 0.125000f;
    sFloatControl *float_Position_1 = gh.Float(&para->Position.y,-1024.00f,1024.000f,0.010000f);
    float_Position_1->Default = 0.000000f; float_Position_1->RightStep = 0.125000f;
    sFloatControl *float_Position_2 = gh.Float(&para->Position.z,-1024.00f,1024.000f,0.010000f);
    float_Position_2->Default = -5.00000f; float_Position_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode!=0x0003)&&((para->Mode==0x0000)||(para->Mode==0x0002))))
  {
    gh.Label(L"* Target");
    gh.BeginTied();
    sFloatControl *float_Target_0 = gh.Float(&para->Target.x,-1024.00f,1024.000f,0.010000f);
    float_Target_0->Default = 0.000000f; float_Target_0->RightStep = 0.125000f;
    sFloatControl *float_Target_1 = gh.Float(&para->Target.y,-1024.00f,1024.000f,0.010000f);
    float_Target_1->Default = 0.000000f; float_Target_1->RightStep = 0.125000f;
    sFloatControl *float_Target_2 = gh.Float(&para->Target.z,-1024.00f,1024.000f,0.010000f);
    float_Target_2->Default = 0.000000f; float_Target_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode!=0x0003)&&((para->Mode==0x0001)||(para->Mode==0x0002))))
  {
    gh.Label(L"* Rot");
    gh.BeginTied();
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-64.0000f,64.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-64.0000f,64.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-64.0000f,64.00000f,0.001000f);
    float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode!=0x0003)&&(para->Mode==0x0002)))
  {
    gh.Label(L"* Distance");
    sFloatControl *float_Distance = gh.Float(&para->Distance,-1024.00f,1024.000f,0.010000f);
    float_Distance->Default = 5.000000f; float_Distance->RightStep = 0.125000f;

  }
  if((para->Mode!=0x0003))
  {
    gh.Label(L"* Tilt");
    sFloatControl *float_Tilt = gh.Float(&para->Tilt,-16.0000f,16.00000f,0.001000f);
    float_Tilt->Default = 0.000000f; float_Tilt->RightStep = 0.125000f;

  }
  gh.Group(L"Projection");

  if((para->Mode!=0x0003))
  {
    gh.Label(L"* Zoom");
    sFloatControl *float_Zoom = gh.Float(&para->Zoom,0.000000f,64.00000f,0.001000f);
    float_Zoom->Default = 1.500000f; float_Zoom->RightStep = 0.125000f;

  }
  gh.Label(L"* ClipNear");
  sFloatControl *float_ClipNear = gh.Float(&para->ClipNear,0.000000f,65536.00f,0.010000f);
  float_ClipNear->Default = 0.125000f; float_ClipNear->RightStep = 0.125000f;

  gh.Label(L"* ClipFar");
  sFloatControl *float_ClipFar = gh.Float(&para->ClipFar,0.000000f,65536.00f,1.000000f);
  float_ClipFar->Default = 1024.000f; float_ClipFar->RightStep = 0.125000f;

  gh.Group(L"Rendering");

  gh.Label(L"Clear");
  gh.Flags(&para->Clear,L"nothing|color|z|both",gh.LayoutMsg);

  if((para->Clear&0x0001))
  {
    gh.Label(L"* ClearColor");
    gh.ColorPick(&para->ClearColor,L"rgba",0);

  }
  gh.Label(L"Perpective");
  gh.Flags(&para->Clear,L"*4-|ortho",gh.ChangeMsg);

  gh.Label(L"Override FreeCam");
  gh.Flags(&para->Clear,L"*5default|off",gh.ChangeMsg);

  gh.Label(L"React to FreeCam");
  gh.Flags(&para->Clear,L"*6default|off",gh.ChangeMsg);

  gh.Label(L"Other");
  gh.Flags(&para->Clear,L"*7-|Disable Shadows",gh.ChangeMsg);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Rendertarget");
  {
    sControl *con=gh.String(op->Links[0].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 0;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 0;
    gh.Box(L"..",msg);
    if(!op->Links[0].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 0;
      gh.Box(L"->",msg);
    }
  }

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefCamera(wOp *op)
{
  Wz4RenderParaCamera sUNUSED *para = (Wz4RenderParaCamera *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Position.z = -5.00000f;
  para->Distance = 5.000000f;
  para->Zoom = 1.500000f;
  para->ClipNear = 0.125000f;
  para->ClipFar = 1024.000f;
  para->Clear = 0x00000003;
  para->ClearColor = 0xff000000;
}

void Wz4RenderBindCamera(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"spline"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"splinetime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"target"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"target"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"target"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"distance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"tilt"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"zoom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"clipnear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"clipfar"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"clearcolor"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Camera(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[24];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"copycam");
    name[1] = sPoolString(L"mode");
    name[2] = sPoolString(L"spline");
    name[3] = sPoolString(L"splinetime");
    name[4] = sPoolString(L"position");
    name[5] = sPoolString(L"target");
    name[6] = sPoolString(L"rot");
    name[7] = sPoolString(L"distance");
    name[8] = sPoolString(L"tilt");
    name[9] = sPoolString(L"projection");
    name[10] = sPoolString(L"zoom");
    name[11] = sPoolString(L"clipnear");
    name[12] = sPoolString(L"clipfar");
    name[13] = sPoolString(L"rendering");
    name[14] = sPoolString(L"clear");
    name[15] = sPoolString(L"clearcolor");
    name[16] = sPoolString(L"perpective");
    name[17] = sPoolString(L"clear");
    name[18] = sPoolString(L"clear");
    name[19] = sPoolString(L"other");
    name[20] = sPoolString(L"renderpass");
    name[21] = sPoolString(L"rendertarget");
    name[22] = sPoolString(L"");
    name[23] = sPoolString(L"script");
  }
  ctx->AddImport(name[2],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+14);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[15],ScriptTypeColor,1,cmd->Data+11);
  ctx->AddImport(name[20],ScriptTypeInt,1,cmd->Data+12);
  ctx->AddImport(name[23],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Camera(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import spline : string;\n");
  tb.PrintF(L"  import splinetime : float;\n");
  tb.PrintF(L"  import position : float[3];\n");
  tb.PrintF(L"  import target : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import distance : float;\n");
  tb.PrintF(L"  import tilt : float;\n");
  tb.PrintF(L"  import zoom : float;\n");
  tb.PrintF(L"  import clipnear : float;\n");
  tb.PrintF(L"  import clipfar : float;\n");
  tb.PrintF(L"  import clearcolor : color;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCamera =
L"= Wz4Render : Camera\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Camera\n"
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
L" !i Rendertarget2D\n"
L" !i optional link Rendertarget\n"
L" !i *\n"
L"\n"
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i CopyCam\n"
L" !i CopyCam\n"
L" !i action\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i target\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i rot\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i schleuder\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spline\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Spline\n"
L" !i Spline\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i SplineTime\n"
L" !i SplineTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Position\n"
L" !i Position\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Target\n"
L" !i Target\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Distance\n"
L" !i Distance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Tilt\n"
L" !i Tilt\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Zoom\n"
L" !i Zoom\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipNear\n"
L" !i ClipNear\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipFar\n"
L" !i ClipFar\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clear\n"
L" !i Clear\n"
L" !i nothing\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i z\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i both\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ClearColor\n"
L" !i ClearColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Perpective\n"
L" !i Clear\n"
L" !i ortho\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Override FreeCam\n"
L" !i Clear\n"
L" !i default\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i off\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i React to FreeCam\n"
L" !i Clear\n"
L" !i default\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i off\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Other\n"
L" !i Clear\n"
L" !i Disable Shadows\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Rendertarget\n"
L" !i Rendertarget\n"
L" !i link\n"
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

sBool Wz4RenderCmdBillboardCamera(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBillboardCamera sUNUSED *para = (Wz4RenderParaBillboardCamera *)(cmd->Data); para;
  Rendertarget2D sUNUSED *in0 = cmd->GetInput<Rendertarget2D *>(0); in0;
  Wz4Render sUNUSED *in1 = cmd->GetInput<Wz4Render *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 284 "wz4_demo2_ops.ops"

    RNBillboardCamera *node = new RNBillboardCamera();
    node->ParaBase = node->Para = *para;
    node->Init(cmd->Strings[1]);
    node->Target = in0; in0->AddRef();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass,1);
  ;
#line 1186 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiBillboardCamera(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBillboardCamera sUNUSED *para = (Wz4RenderParaBillboardCamera *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Rendertarget");
  {
    sControl *con=gh.String(op->Links[0].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 0;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 0;
    gh.Box(L"..",msg);
    if(!op->Links[0].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 0;
      gh.Box(L"->",msg);
    }
  }

  gh.Label(L"* ClearColor");
  gh.ColorPick(&para->ClearColor,L"rgba",0);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L" around| copy",gh.ChangeMsg);

  gh.Group(L"Projection");

  gh.Label(L"* Distance");
  sFloatControl *float_Distance = gh.Float(&para->Distance,0.000000f,1024.000f,0.001000f);
  float_Distance->Default = 5.000000f; float_Distance->RightStep = 0.125000f;

  gh.Label(L"* Zoom");
  sFloatControl *float_Zoom = gh.Float(&para->Zoom,0.000000f,64.00000f,0.001000f);
  float_Zoom->Default = 1.500000f; float_Zoom->RightStep = 0.125000f;

  gh.Label(L"* ClipNear");
  sFloatControl *float_ClipNear = gh.Float(&para->ClipNear,0.000000f,65536.00f,0.010000f);
  float_ClipNear->Default = 0.125000f; float_ClipNear->RightStep = 0.125000f;

  gh.Label(L"* ClipFar");
  sFloatControl *float_ClipFar = gh.Float(&para->ClipFar,0.000000f,65536.00f,1.000000f);
  float_ClipFar->Default = 1024.000f; float_ClipFar->RightStep = 0.125000f;

  gh.Label(L"AtlasId");
  sIntControl *int_AtlasId = gh.Int(&para->AtlasId,0,31,0.125000f);
  int_AtlasId->Default = 0x00000000; int_AtlasId->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefBillboardCamera(wOp *op)
{
  Wz4RenderParaBillboardCamera sUNUSED *para = (Wz4RenderParaBillboardCamera *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->ClearColor = 0x40000000;
  para->Distance = 5.000000f;
  para->Zoom = 1.500000f;
  para->ClipNear = 0.125000f;
  para->ClipFar = 1024.000f;
}

void Wz4RenderBindBillboardCamera(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"clearcolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"distance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"zoom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"clipnear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"clipfar"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"atlasid"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2BillboardCamera(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"rendertarget");
    name[2] = sPoolString(L"clearcolor");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"projection");
    name[5] = sPoolString(L"distance");
    name[6] = sPoolString(L"zoom");
    name[7] = sPoolString(L"clipnear");
    name[8] = sPoolString(L"clipfar");
    name[9] = sPoolString(L"atlasid");
    name[10] = sPoolString(L"");
    name[11] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[9],ScriptTypeInt,1,cmd->Data+7);
  ctx->AddImport(name[11],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3BillboardCamera(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import clearcolor : color;\n");
  tb.PrintF(L"  import distance : float;\n");
  tb.PrintF(L"  import zoom : float;\n");
  tb.PrintF(L"  import clipnear : float;\n");
  tb.PrintF(L"  import clipfar : float;\n");
  tb.PrintF(L"  import atlasid : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBillboardCamera =
L"= Wz4Render : BillboardCamera\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BillboardCamera\n"
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
L" !i Rendertarget2D\n"
L" !i optional link Rendertarget\n"
L" !i *\n"
L"\n"
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Rendertarget\n"
L" !i Rendertarget\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i ClearColor\n"
L" !i ClearColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i around\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i copy\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Distance\n"
L" !i Distance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Zoom\n"
L" !i Zoom\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipNear\n"
L" !i ClipNear\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipFar\n"
L" !i ClipFar\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AtlasId\n"
L" !i AtlasId\n"
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

sBool GenBitmapCmdRender(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaRender sUNUSED *para = (GenBitmapParaRender *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 317 "wz4_demo2_ops.ops"

    RenderCode(para,in0,out);
  ;
#line 1449 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiRender(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaRender sUNUSED *para = (GenBitmapParaRender *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0power2|relative|absolute:*4color|depth",gh.LayoutMsg);

  if(((para->Flags&0x0003)==0x0000))
  {
    gh.Label(L"Size");
    gh.Flags(&para->Size2,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  }
  if(((para->Flags&0x0003)==0x0001))
  {
    gh.Label(L"Divider");
    gh.BeginTied();
    sIntControl *int_Divider_0 = gh.Int(&para->Divider[0],1,256,0.125000f);
    int_Divider_0->Default = 0x00000001; int_Divider_0->RightStep = 0.125000f;
    sIntControl *int_Divider_1 = gh.Int(&para->Divider[1],1,256,0.125000f);
    int_Divider_1->Default = 0x00000001; int_Divider_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Flags&0x0003)==0x0002))
  {
    gh.Label(L"Size");
    gh.BeginTied();
    sIntControl *int_Size_0 = gh.Int(&para->Size[0],1,16384,0.125000f);
    int_Size_0->Default = 0x00000100; int_Size_0->RightStep = 0.125000f;
    sIntControl *int_Size_1 = gh.Int(&para->Size[1],1,16384,0.125000f);
    int_Size_1->Default = 0x00000100; int_Size_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Time");
  sFloatControl *float_Time = gh.Float(&para->Time,0.000000f,1.000000f,0.125000f);
  float_Time->Default = 0.000000f; float_Time->RightStep = 0.125000f;

  gh.Label(L"BaseTime");
  sFloatControl *float_BaseTime = gh.Float(&para->BaseTime,0.000000f,65536.00f,0.125000f);
  float_BaseTime->Default = 0.000000f; float_BaseTime->RightStep = 0.125000f;
}

void GenBitmapDefRender(wOp *op)
{
  GenBitmapParaRender sUNUSED *para = (GenBitmapParaRender *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size2 = 0x00000808;
  para->Divider[0] = 0x00000001;
  para->Divider[1] = 0x00000001;
  para->Size[0] = 0x00000100;
  para->Size[1] = 0x00000100;
}

void GenBitmapBindRender(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"divider"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"divider"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"time"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"basetime"),val);
}
void GenBitmapBind2Render(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"size");
    name[2] = sPoolString(L"divider");
    name[3] = sPoolString(L"size");
    name[4] = sPoolString(L"time");
    name[5] = sPoolString(L"basetime");
  }
  ctx->AddImport(name[2],ScriptTypeInt,2,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,2,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+7);
}
void GenBitmapBind3Render(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import divider : int[2];\n");
  tb.PrintF(L"  import size : int[2];\n");
  tb.PrintF(L"  import time : float;\n");
  tb.PrintF(L"  import basetime : float;\n");
}
const sChar *GenBitmapWikiRender =
L"= GenBitmap : Render\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Render\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Wz4Render\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i power2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i relative\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i absolute\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i color\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i depth\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Size\n"
L" !i Size2\n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
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
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Divider\n"
L" !i Divider\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Time\n"
L" !i Time\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BaseTime\n"
L" !i BaseTime\n"
L" !i float\n"
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

sBool Wz4RenderCmdRenderMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaRenderMesh sUNUSED *para = (Wz4RenderParaRenderMesh *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 338 "wz4_demo2_ops.ops"

    RNRenderMesh *node = new RNRenderMesh();
    node->ParaBase = node->Para = *para;
    in0->Charge();
    node->Mesh = in0; in0->AddRef();


    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 1787 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiRenderMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaRenderMesh sUNUSED *para = (Wz4RenderParaRenderMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"* BoneTime");
  sFloatControl *float_BoneTime = gh.Float(&para->BoneTime,0.000000f,1024.000f,0.001000f);
  float_BoneTime->Default = 0.000000f; float_BoneTime->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Instances");
  gh.Flags(&para->Instances,L"off|on",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefRenderMesh(wOp *op)
{
  Wz4RenderParaRenderMesh sUNUSED *para = (Wz4RenderParaRenderMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindRenderMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"bonetime"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2RenderMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"bonetime");
    name[2] = sPoolString(L"renderpass");
    name[3] = sPoolString(L"instances");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3RenderMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import bonetime : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiRenderMesh =
L"= Wz4Render : RenderMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i RenderMesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i BoneTime\n"
L" !i BoneTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Instances\n"
L" !i Instances\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
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

sBool Wz4RenderCmdMultiplyMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaMultiplyMesh sUNUSED *para = (Wz4RenderParaMultiplyMesh *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 391 "wz4_demo2_ops.ops"

    RNMultiplyMesh *node = new RNMultiplyMesh();
    node->ParaBase = node->Para = *para;
    in0->Charge();
    node->Mesh = in0; in0->AddRef();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 1962 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiMultiplyMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaMultiplyMesh sUNUSED *para = (Wz4RenderParaMultiplyMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Center:*1-|reverse",gh.ChangeMsg);

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Pre-Transform");

  gh.Label(L"* Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot");
  gh.BeginTied();
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-65536.0f,65536.00f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-65536.0f,65536.00f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-65536.0f,65536.00f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"First Multiply");

  gh.Label(L"* Count1");
  sIntControl *int_Count1 = gh.Int(&para->Count1,0,1024,0.125000f);
  int_Count1->Default = 0x00000002; int_Count1->RightStep = 0.125000f;

  gh.Label(L"* Scale1");
  gh.BeginTied();
  sFloatControl *float_Scale1_0 = gh.Float(&para->Scale1.x,-1024.00f,1024.000f,0.010000f);
  float_Scale1_0->Default = 1.000000f; float_Scale1_0->RightStep = 0.125000f;
  sFloatControl *float_Scale1_1 = gh.Float(&para->Scale1.y,-1024.00f,1024.000f,0.010000f);
  float_Scale1_1->Default = 1.000000f; float_Scale1_1->RightStep = 0.125000f;
  sFloatControl *float_Scale1_2 = gh.Float(&para->Scale1.z,-1024.00f,1024.000f,0.010000f);
  float_Scale1_2->Default = 1.000000f; float_Scale1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot1");
  gh.BeginTied();
  sFloatControl *float_Rot1_0 = gh.Float(&para->Rot1.x,-16.0000f,16.00000f,0.010000f);
  float_Rot1_0->Default = 0.000000f; float_Rot1_0->RightStep = 0.125000f;
  sFloatControl *float_Rot1_1 = gh.Float(&para->Rot1.y,-16.0000f,16.00000f,0.010000f);
  float_Rot1_1->Default = 0.000000f; float_Rot1_1->RightStep = 0.125000f;
  sFloatControl *float_Rot1_2 = gh.Float(&para->Rot1.z,-16.0000f,16.00000f,0.010000f);
  float_Rot1_2->Default = 0.000000f; float_Rot1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans1");
  gh.BeginTied();
  sFloatControl *float_Trans1_0 = gh.Float(&para->Trans1.x,-65536.0f,65536.00f,0.010000f);
  float_Trans1_0->Default = 0.000000f; float_Trans1_0->RightStep = 0.125000f;
  sFloatControl *float_Trans1_1 = gh.Float(&para->Trans1.y,-65536.0f,65536.00f,0.010000f);
  float_Trans1_1->Default = 0.000000f; float_Trans1_1->RightStep = 0.125000f;
  sFloatControl *float_Trans1_2 = gh.Float(&para->Trans1.z,-65536.0f,65536.00f,0.010000f);
  float_Trans1_2->Default = 0.000000f; float_Trans1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Second Multiply");

  gh.Label(L"* Count2");
  sIntControl *int_Count2 = gh.Int(&para->Count2,1,1024,0.125000f);
  int_Count2->Default = 0x00000001; int_Count2->RightStep = 0.125000f;
  int_Count2->DoneMsg = gh.LayoutMsg;

  if((para->Count2!=0x0001))
  {
    gh.Label(L"* Scale2");
    gh.BeginTied();
    sFloatControl *float_Scale2_0 = gh.Float(&para->Scale2.x,-1024.00f,1024.000f,0.010000f);
    float_Scale2_0->Default = 1.000000f; float_Scale2_0->RightStep = 0.125000f;
    sFloatControl *float_Scale2_1 = gh.Float(&para->Scale2.y,-1024.00f,1024.000f,0.010000f);
    float_Scale2_1->Default = 1.000000f; float_Scale2_1->RightStep = 0.125000f;
    sFloatControl *float_Scale2_2 = gh.Float(&para->Scale2.z,-1024.00f,1024.000f,0.010000f);
    float_Scale2_2->Default = 1.000000f; float_Scale2_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Rot2");
    gh.BeginTied();
    sFloatControl *float_Rot2_0 = gh.Float(&para->Rot2.x,-16.0000f,16.00000f,0.010000f);
    float_Rot2_0->Default = 0.000000f; float_Rot2_0->RightStep = 0.125000f;
    sFloatControl *float_Rot2_1 = gh.Float(&para->Rot2.y,-16.0000f,16.00000f,0.010000f);
    float_Rot2_1->Default = 0.000000f; float_Rot2_1->RightStep = 0.125000f;
    sFloatControl *float_Rot2_2 = gh.Float(&para->Rot2.z,-16.0000f,16.00000f,0.010000f);
    float_Rot2_2->Default = 0.000000f; float_Rot2_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Trans2");
    gh.BeginTied();
    sFloatControl *float_Trans2_0 = gh.Float(&para->Trans2.x,-65536.0f,65536.00f,0.010000f);
    float_Trans2_0->Default = 0.000000f; float_Trans2_0->RightStep = 0.125000f;
    sFloatControl *float_Trans2_1 = gh.Float(&para->Trans2.y,-65536.0f,65536.00f,0.010000f);
    float_Trans2_1->Default = 0.000000f; float_Trans2_1->RightStep = 0.125000f;
    sFloatControl *float_Trans2_2 = gh.Float(&para->Trans2.z,-65536.0f,65536.00f,0.010000f);
    float_Trans2_2->Default = 0.000000f; float_Trans2_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Group(L"Last Multiply");

    gh.Label(L"* Count3");
    sIntControl *int_Count3 = gh.Int(&para->Count3,1,1024,0.125000f);
    int_Count3->Default = 0x00000001; int_Count3->RightStep = 0.125000f;
    int_Count3->DoneMsg = gh.LayoutMsg;

  }
  if(((para->Count2!=0x0001)&&(para->Count3!=0x0001)))
  {
    gh.Label(L"* Scale3");
    gh.BeginTied();
    sFloatControl *float_Scale3_0 = gh.Float(&para->Scale3.x,-1024.00f,1024.000f,0.010000f);
    float_Scale3_0->Default = 1.000000f; float_Scale3_0->RightStep = 0.125000f;
    sFloatControl *float_Scale3_1 = gh.Float(&para->Scale3.y,-1024.00f,1024.000f,0.010000f);
    float_Scale3_1->Default = 1.000000f; float_Scale3_1->RightStep = 0.125000f;
    sFloatControl *float_Scale3_2 = gh.Float(&para->Scale3.z,-1024.00f,1024.000f,0.010000f);
    float_Scale3_2->Default = 1.000000f; float_Scale3_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Rot3");
    gh.BeginTied();
    sFloatControl *float_Rot3_0 = gh.Float(&para->Rot3.x,-16.0000f,16.00000f,0.010000f);
    float_Rot3_0->Default = 0.000000f; float_Rot3_0->RightStep = 0.125000f;
    sFloatControl *float_Rot3_1 = gh.Float(&para->Rot3.y,-16.0000f,16.00000f,0.010000f);
    float_Rot3_1->Default = 0.000000f; float_Rot3_1->RightStep = 0.125000f;
    sFloatControl *float_Rot3_2 = gh.Float(&para->Rot3.z,-16.0000f,16.00000f,0.010000f);
    float_Rot3_2->Default = 0.000000f; float_Rot3_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Trans3");
    gh.BeginTied();
    sFloatControl *float_Trans3_0 = gh.Float(&para->Trans3.x,-65536.0f,65536.00f,0.010000f);
    float_Trans3_0->Default = 0.000000f; float_Trans3_0->RightStep = 0.125000f;
    sFloatControl *float_Trans3_1 = gh.Float(&para->Trans3.y,-65536.0f,65536.00f,0.010000f);
    float_Trans3_1->Default = 0.000000f; float_Trans3_1->RightStep = 0.125000f;
    sFloatControl *float_Trans3_2 = gh.Float(&para->Trans3.z,-65536.0f,65536.00f,0.010000f);
    float_Trans3_2->Default = 0.000000f; float_Trans3_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefMultiplyMesh(wOp *op)
{
  Wz4RenderParaMultiplyMesh sUNUSED *para = (Wz4RenderParaMultiplyMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Count1 = 0x00000002;
  para->Scale1.x = 1.000000f;
  para->Scale1.y = 1.000000f;
  para->Scale1.z = 1.000000f;
  para->Count2 = 0x00000001;
  para->Scale2.x = 1.000000f;
  para->Scale2.y = 1.000000f;
  para->Scale2.z = 1.000000f;
  para->Count3 = 0x00000001;
  para->Scale3.x = 1.000000f;
  para->Scale3.y = 1.000000f;
  para->Scale3.z = 1.000000f;
}

void Wz4RenderBindMultiplyMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+41;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"count1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rot1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rot1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rot1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"count2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"rot2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"rot2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"rot2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"count3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"scale3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"scale3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"scale3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"rot3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"rot3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"rot3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2MultiplyMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[24];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"renderpass");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"scale");
    name[5] = sPoolString(L"rot");
    name[6] = sPoolString(L"trans");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"count1");
    name[9] = sPoolString(L"scale1");
    name[10] = sPoolString(L"rot1");
    name[11] = sPoolString(L"trans1");
    name[12] = sPoolString(L"");
    name[13] = sPoolString(L"count2");
    name[14] = sPoolString(L"scale2");
    name[15] = sPoolString(L"rot2");
    name[16] = sPoolString(L"trans2");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"count3");
    name[19] = sPoolString(L"scale3");
    name[20] = sPoolString(L"rot3");
    name[21] = sPoolString(L"trans3");
    name[22] = sPoolString(L"");
    name[23] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+40);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+41);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+11);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+14);
  ctx->AddImport(name[11],ScriptTypeFloat,3,cmd->Data+17);
  ctx->AddImport(name[13],ScriptTypeInt,1,cmd->Data+20);
  ctx->AddImport(name[14],ScriptTypeFloat,3,cmd->Data+21);
  ctx->AddImport(name[15],ScriptTypeFloat,3,cmd->Data+24);
  ctx->AddImport(name[16],ScriptTypeFloat,3,cmd->Data+27);
  ctx->AddImport(name[18],ScriptTypeInt,1,cmd->Data+30);
  ctx->AddImport(name[19],ScriptTypeFloat,3,cmd->Data+31);
  ctx->AddImport(name[20],ScriptTypeFloat,3,cmd->Data+34);
  ctx->AddImport(name[21],ScriptTypeFloat,3,cmd->Data+37);
  ctx->AddImport(name[23],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3MultiplyMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import count1 : int;\n");
  tb.PrintF(L"  import scale1 : float[3];\n");
  tb.PrintF(L"  import rot1 : float[3];\n");
  tb.PrintF(L"  import trans1 : float[3];\n");
  tb.PrintF(L"  import count2 : int;\n");
  tb.PrintF(L"  import scale2 : float[3];\n");
  tb.PrintF(L"  import rot2 : float[3];\n");
  tb.PrintF(L"  import trans2 : float[3];\n");
  tb.PrintF(L"  import count3 : int;\n");
  tb.PrintF(L"  import scale3 : float[3];\n");
  tb.PrintF(L"  import rot3 : float[3];\n");
  tb.PrintF(L"  import trans3 : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiMultiplyMesh =
L"= Wz4Render : MultiplyMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MultiplyMesh\n"
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
L" !i Wz4Mesh\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Center\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i reverse\n"
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
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count1\n"
L" !i Count1\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Scale1\n"
L" !i Scale1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot1\n"
L" !i Rot1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans1\n"
L" !i Trans1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count2\n"
L" !i Count2\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Scale2\n"
L" !i Scale2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot2\n"
L" !i Rot2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans2\n"
L" !i Trans2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count3\n"
L" !i Count3\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Scale3\n"
L" !i Scale3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot3\n"
L" !i Rot3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans3\n"
L" !i Trans3\n"
L" !i float[3]\n"
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

sBool Wz4RenderCmdScript(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaScript sUNUSED *para = (Wz4RenderParaScript *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 413 "wz4_demo2_ops.ops"

    Wz4RenderNode *node = new Wz4RenderNode();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 2528 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiScript(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaScript sUNUSED *para = (Wz4RenderParaScript *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],15,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefScript(wOp *op)
{
  Wz4RenderParaScript sUNUSED *para = (Wz4RenderParaScript *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindScript(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Script(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"");
    name[2] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Script(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiScript =
L"= Wz4Render : Script\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Script\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
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

sBool Wz4RenderCmdTransform(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaTransform sUNUSED *para = (Wz4RenderParaTransform *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 435 "wz4_demo2_ops.ops"

    RNTransform *node = new RNTransform();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 2657 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndTransform(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaTransform sUNUSED *para = (Wz4RenderParaTransform *)(op->EditData); para;
#line 442 "wz4_demo2_ops.ops"

    sSRT srt;
    sMatrix34 mul;

    pi.Handle3D(op,1,para->Trans,wHM_PLANE);

    srt.Scale = para->Scale;
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.MakeMatrix(mul);

    pi.Transform3D(mul);
  ;
#line 2679 "wz4_demo2_ops.cpp"
}

void Wz4RenderGuiTransform(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaTransform sUNUSED *para = (Wz4RenderParaTransform *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot");
  gh.BeginTied();
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-65536.0f,65536.00f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-65536.0f,65536.00f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-65536.0f,65536.00f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefTransform(wOp *op)
{
  Wz4RenderParaTransform sUNUSED *para = (Wz4RenderParaTransform *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4RenderBindTransform(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Transform(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"renderpass");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Transform(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiTransform =
L"= Wz4Render : Transform\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Transform\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
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

sBool Wz4RenderCmdTransformPivot(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaTransformPivot sUNUSED *para = (Wz4RenderParaTransformPivot *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 474 "wz4_demo2_ops.ops"

    RNTransformPivot *node = new RNTransformPivot();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 2890 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndTransformPivot(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaTransformPivot sUNUSED *para = (Wz4RenderParaTransformPivot *)(op->EditData); para;
#line 481 "wz4_demo2_ops.ops"

    sSRT srt;
    sMatrix34 mat0,mat1;

    pi.Handle3D(op,1,para->Trans,wHM_PLANE);
    pi.Handle3D(op,2,para->Pivot,wHM_PLANE);

    srt.Scale = para->Scale;
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.MakeMatrix(mat1);
    mat1.l = mat1.l + sVector30(para->Pivot*mat1);
    mat0.l = -para->Pivot;

    pi.Transform3D(mat0*mat1);
  ;
#line 2915 "wz4_demo2_ops.cpp"
}

void Wz4RenderGuiTransformPivot(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaTransformPivot sUNUSED *para = (Wz4RenderParaTransformPivot *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot");
  gh.BeginTied();
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x, -1000000,  1000000,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y, -1000000,  1000000,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z, -1000000,  1000000,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Pivot");
  gh.BeginTied();
  sFloatControl *float_Pivot_0 = gh.Float(&para->Pivot.x, -1000000,  1000000,0.010000f);
  float_Pivot_0->Default = 0.000000f; float_Pivot_0->RightStep = 0.125000f;
  sFloatControl *float_Pivot_1 = gh.Float(&para->Pivot.y, -1000000,  1000000,0.010000f);
  float_Pivot_1->Default = 0.000000f; float_Pivot_1->RightStep = 0.125000f;
  sFloatControl *float_Pivot_2 = gh.Float(&para->Pivot.z, -1000000,  1000000,0.010000f);
  float_Pivot_2->Default = 0.000000f; float_Pivot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefTransformPivot(wOp *op)
{
  Wz4RenderParaTransformPivot sUNUSED *para = (Wz4RenderParaTransformPivot *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4RenderBindTransformPivot(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pivot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pivot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pivot"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2TransformPivot(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"renderpass");
    name[4] = sPoolString(L"pivot");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3TransformPivot(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import pivot : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiTransformPivot =
L"= Wz4Render : TransformPivot\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TransformPivot\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Pivot\n"
L" !i Pivot\n"
L" !i float[3]\n"
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

sBool Wz4RenderCmdSplinedObject(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSplinedObject sUNUSED *para = (Wz4RenderParaSplinedObject *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 517 "wz4_demo2_ops.ops"

    RNSplinedObject *node = new RNSplinedObject();
    node->ParaBase = node->Para = *para;
    node->Init(cmd->Strings[1]);
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 3154 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSplinedObject(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSplinedObject sUNUSED *para = (Wz4RenderParaSplinedObject *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"SplineName");
  gh.String(op->EditString[1]);

  gh.Label(L"* Tick");
  sFloatControl *float_Tick = gh.Float(&para->Tick,0.000000f,1.000000f,0.002000f);
  float_Tick->Default = 0.000000f; float_Tick->RightStep = 0.125000f;

  gh.Label(L"* TimeDelta");
  sFloatControl *float_TimeDelta = gh.Float(&para->TimeDelta,0.000000f,0.250000f,0.000100f);
  float_TimeDelta->Default = 0.000500f; float_TimeDelta->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"Forward|Fly|rotate only:*4y is up|center is up",gh.LayoutMsg);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  if(((para->Mode&0x0003)==0x0002))
  {
    gh.Label(L"RotateAmount");
    sFloatControl *float_RotateAmount = gh.Float(&para->RotateAmount,-1024.00f,1024.000f,0.010000f);
    float_RotateAmount->Default = 0.000000f; float_RotateAmount->RightStep = 0.125000f;

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefSplinedObject(wOp *op)
{
  Wz4RenderParaSplinedObject sUNUSED *para = (Wz4RenderParaSplinedObject *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->TimeDelta = 0.000500f;
}

void Wz4RenderBindSplinedObject(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"splinename"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tick"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"timedelta"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rotateamount"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2SplinedObject(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"splinename");
    name[1] = sPoolString(L"tick");
    name[2] = sPoolString(L"timedelta");
    name[3] = sPoolString(L"mode");
    name[4] = sPoolString(L"renderpass");
    name[5] = sPoolString(L"rotateamount");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3SplinedObject(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import splinename : string;\n");
  tb.PrintF(L"  import tick : float;\n");
  tb.PrintF(L"  import timedelta : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import rotateamount : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSplinedObject =
L"= Wz4Render : SplinedObject\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SplinedObject\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i SplineName\n"
L" !i SplineName\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Tick\n"
L" !i Tick\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeDelta\n"
L" !i TimeDelta\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i Forward\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Fly\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i rotate only\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i y is up\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i center is up\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i RotateAmount\n"
L" !i RotateAmount\n"
L" !i float\n"
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

sBool Wz4RenderCmdLookAt(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaLookAt sUNUSED *para = (Wz4RenderParaLookAt *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 542 "wz4_demo2_ops.ops"

    RNLookAt *node = new RNLookAt();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 3377 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiLookAt(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaLookAt sUNUSED *para = (Wz4RenderParaLookAt *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Pos");
  gh.BeginTied();
  sFloatControl *float_Pos_0 = gh.Float(&para->Pos.x,-65536.0f,65536.00f,0.010000f);
  float_Pos_0->Default = 0.000000f; float_Pos_0->RightStep = 0.125000f;
  sFloatControl *float_Pos_1 = gh.Float(&para->Pos.y,-65536.0f,65536.00f,0.010000f);
  float_Pos_1->Default = 0.000000f; float_Pos_1->RightStep = 0.125000f;
  sFloatControl *float_Pos_2 = gh.Float(&para->Pos.z,-65536.0f,65536.00f,0.010000f);
  float_Pos_2->Default = 0.000000f; float_Pos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Target");
  gh.BeginTied();
  sFloatControl *float_Target_0 = gh.Float(&para->Target.x,-65536.0f,65536.00f,0.010000f);
  float_Target_0->Default = 0.000000f; float_Target_0->RightStep = 0.125000f;
  sFloatControl *float_Target_1 = gh.Float(&para->Target.y,-65536.0f,65536.00f,0.010000f);
  float_Target_1->Default = 0.000000f; float_Target_1->RightStep = 0.125000f;
  sFloatControl *float_Target_2 = gh.Float(&para->Target.z,-65536.0f,65536.00f,0.010000f);
  float_Target_2->Default = 0.000000f; float_Target_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* UpVector");
  gh.BeginTied();
  sFloatControl *float_UpVector_0 = gh.Float(&para->UpVector.x,-16.0000f,16.00000f,0.010000f);
  float_UpVector_0->Default = 0.000000f; float_UpVector_0->RightStep = 0.125000f;
  sFloatControl *float_UpVector_1 = gh.Float(&para->UpVector.y,-16.0000f,16.00000f,0.010000f);
  float_UpVector_1->Default = 1.000000f; float_UpVector_1->RightStep = 0.125000f;
  sFloatControl *float_UpVector_2 = gh.Float(&para->UpVector.z,-16.0000f,16.00000f,0.010000f);
  float_UpVector_2->Default = 0.000000f; float_UpVector_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Tilt");
  sFloatControl *float_Tilt = gh.Float(&para->Tilt,-16.0000f,16.00000f,0.010000f);
  float_Tilt->Default = 0.000000f; float_Tilt->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefLookAt(wOp *op)
{
  Wz4RenderParaLookAt sUNUSED *para = (Wz4RenderParaLookAt *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->UpVector.y = 1.000000f;
}

void Wz4RenderBindLookAt(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"target"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"target"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"target"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"tilt"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2LookAt(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"pos");
    name[1] = sPoolString(L"target");
    name[2] = sPoolString(L"upvector");
    name[3] = sPoolString(L"tilt");
    name[4] = sPoolString(L"renderpass");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3LookAt(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import pos : float[3];\n");
  tb.PrintF(L"  import target : float[3];\n");
  tb.PrintF(L"  import upvector : float[3];\n");
  tb.PrintF(L"  import tilt : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiLookAt =
L"= Wz4Render : LookAt\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i LookAt\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Pos\n"
L" !i Pos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Target\n"
L" !i Target\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i UpVector\n"
L" !i UpVector\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Tilt\n"
L" !i Tilt\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
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

sBool Wz4RenderCmdSkyCube(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSkyCube sUNUSED *para = (Wz4RenderParaSkyCube *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 561 "wz4_demo2_ops.ops"

    RNSkyCube *node = new RNSkyCube();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 3603 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSkyCube(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSkyCube sUNUSED *para = (Wz4RenderParaSkyCube *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefSkyCube(wOp *op)
{
  Wz4RenderParaSkyCube sUNUSED *para = (Wz4RenderParaSkyCube *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindSkyCube(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2SkyCube(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"");
    name[2] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3SkyCube(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSkyCube =
L"= Wz4Render : SkyCube\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SkyCube\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
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

sBool Wz4RenderCmdShaker(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaShaker sUNUSED *para = (Wz4RenderParaShaker *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 594 "wz4_demo2_ops.ops"

    RNShaker *node = new RNShaker();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);  
  ;
#line 3732 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiShaker(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaShaker sUNUSED *para = (Wz4RenderParaShaker *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"fadein|fadeout|smooth|always:*4around cam|around center:*5sin|perlin",gh.LayoutMsg);

  if(((para->Mode&0x000f)!=0x0003))
  {
    gh.Label(L"* Animate");
    sFloatControl *float_Animate = gh.Float(&para->Animate,0.000000f,1.000000f,0.001000f);
    float_Animate->Default = 0.000000f; float_Animate->RightStep = 0.125000f;

  }
  if((para->Mode&0x0010))
  {
    gh.Label(L"* Center");
    gh.BeginTied();
    sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-4096.00f,4096.000f,0.100000f);
    float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
    sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-4096.00f,4096.000f,0.100000f);
    float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
    sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-4096.00f,4096.000f,0.100000f);
    float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"* Amp");
  sFloatControl *float_Amp = gh.Float(&para->Amp,0.000000f,1.000000f,0.001000f);
  float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;

  gh.Label(L"* TimeRange");
  gh.BeginTied();
  sFloatControl *float_TimeRange_0 = gh.Float(&para->TimeRange[0],0.000000f,1.000000f,0.010000f);
  float_TimeRange_0->Default = 0.000000f; float_TimeRange_0->RightStep = 0.125000f;
  sFloatControl *float_TimeRange_1 = gh.Float(&para->TimeRange[1],0.000000f,1.000000f,0.010000f);
  float_TimeRange_1->Default = 1.000000f; float_TimeRange_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"shaking");

  gh.Label(L"* TranslateAmp");
  gh.BeginTied();
  sFloatControl *float_TranslateAmp_0 = gh.Float(&para->TranslateAmp.x,-256.000f,256.0000f,0.010000f);
  float_TranslateAmp_0->Default = 0.000000f; float_TranslateAmp_0->RightStep = 0.125000f;
  sFloatControl *float_TranslateAmp_1 = gh.Float(&para->TranslateAmp.y,-256.000f,256.0000f,0.010000f);
  float_TranslateAmp_1->Default = 0.000000f; float_TranslateAmp_1->RightStep = 0.125000f;
  sFloatControl *float_TranslateAmp_2 = gh.Float(&para->TranslateAmp.z,-256.000f,256.0000f,0.010000f);
  float_TranslateAmp_2->Default = 0.000000f; float_TranslateAmp_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* TranslateFreq");
  gh.BeginTied();
  sFloatControl *float_TranslateFreq_0 = gh.Float(&para->TranslateFreq.x,-4096.00f,4096.000f,0.010000f);
  float_TranslateFreq_0->Default = 0.000000f; float_TranslateFreq_0->RightStep = 0.125000f;
  sFloatControl *float_TranslateFreq_1 = gh.Float(&para->TranslateFreq.y,-4096.00f,4096.000f,0.010000f);
  float_TranslateFreq_1->Default = 0.000000f; float_TranslateFreq_1->RightStep = 0.125000f;
  sFloatControl *float_TranslateFreq_2 = gh.Float(&para->TranslateFreq.z,-4096.00f,4096.000f,0.010000f);
  float_TranslateFreq_2->Default = 0.000000f; float_TranslateFreq_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* RotateAmp");
  gh.BeginTied();
  sFloatControl *float_RotateAmp_0 = gh.Float(&para->RotateAmp.x,-16.0000f,16.00000f,0.000100f);
  float_RotateAmp_0->Default = 0.000000f; float_RotateAmp_0->RightStep = 0.125000f;
  sFloatControl *float_RotateAmp_1 = gh.Float(&para->RotateAmp.y,-16.0000f,16.00000f,0.000100f);
  float_RotateAmp_1->Default = 0.000000f; float_RotateAmp_1->RightStep = 0.125000f;
  sFloatControl *float_RotateAmp_2 = gh.Float(&para->RotateAmp.z,-16.0000f,16.00000f,0.000100f);
  float_RotateAmp_2->Default = 0.000000f; float_RotateAmp_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* RotateFreq");
  gh.BeginTied();
  sFloatControl *float_RotateFreq_0 = gh.Float(&para->RotateFreq.x,-4096.00f,4096.000f,0.010000f);
  float_RotateFreq_0->Default = 0.000000f; float_RotateFreq_0->RightStep = 0.125000f;
  sFloatControl *float_RotateFreq_1 = gh.Float(&para->RotateFreq.y,-4096.00f,4096.000f,0.010000f);
  float_RotateFreq_1->Default = 0.000000f; float_RotateFreq_1->RightStep = 0.125000f;
  sFloatControl *float_RotateFreq_2 = gh.Float(&para->RotateFreq.z,-4096.00f,4096.000f,0.010000f);
  float_RotateFreq_2->Default = 0.000000f; float_RotateFreq_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefShaker(wOp *op)
{
  Wz4RenderParaShaker sUNUSED *para = (Wz4RenderParaShaker *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Amp = 1.000000f;
  para->TimeRange[1] = 1.000000f;
}

void Wz4RenderBindShaker(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"animate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"timerange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"timerange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"translateamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"translateamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"translateamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"translatefreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"translatefreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"translatefreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rotateamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rotateamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rotateamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"rotatefreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"rotatefreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"rotatefreq"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Shaker(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"animate");
    name[2] = sPoolString(L"center");
    name[3] = sPoolString(L"amp");
    name[4] = sPoolString(L"timerange");
    name[5] = sPoolString(L"shaking");
    name[6] = sPoolString(L"translateamp");
    name[7] = sPoolString(L"translatefreq");
    name[8] = sPoolString(L"rotateamp");
    name[9] = sPoolString(L"rotatefreq");
    name[10] = sPoolString(L"renderpass");
    name[11] = sPoolString(L"");
    name[12] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+6);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+11);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+14);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+17);
  ctx->AddImport(name[10],ScriptTypeInt,1,cmd->Data+20);
  ctx->AddImport(name[12],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Shaker(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import animate : float;\n");
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import amp : float;\n");
  tb.PrintF(L"  import timerange : float[2];\n");
  tb.PrintF(L"  import translateamp : float[3];\n");
  tb.PrintF(L"  import translatefreq : float[3];\n");
  tb.PrintF(L"  import rotateamp : float[3];\n");
  tb.PrintF(L"  import rotatefreq : float[3];\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiShaker =
L"= Wz4Render : Shaker\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Shaker\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i fadein\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fadeout\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i smooth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i always\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i around cam\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i around center\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i sin\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i perlin\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Animate\n"
L" !i Animate\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeRange\n"
L" !i TimeRange\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i TranslateAmp\n"
L" !i TranslateAmp\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TranslateFreq\n"
L" !i TranslateFreq\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i RotateAmp\n"
L" !i RotateAmp\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i RotateFreq\n"
L" !i RotateFreq\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
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

sBool Wz4RenderCmdMultiply(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaMultiply sUNUSED *para = (Wz4RenderParaMultiply *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 625 "wz4_demo2_ops.ops"

    RNMultiply *node = new RNMultiply();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 4107 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiMultiply(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaMultiply sUNUSED *para = (Wz4RenderParaMultiply *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Center",gh.ChangeMsg);

  gh.Group(L"Pre-Transform");

  gh.Label(L"* PreScale");
  gh.BeginTied();
  sFloatControl *float_PreScale_0 = gh.Float(&para->PreScale.x,-1024.00f,1024.000f,0.010000f);
  float_PreScale_0->Default = 1.000000f; float_PreScale_0->RightStep = 0.125000f;
  sFloatControl *float_PreScale_1 = gh.Float(&para->PreScale.y,-1024.00f,1024.000f,0.010000f);
  float_PreScale_1->Default = 1.000000f; float_PreScale_1->RightStep = 0.125000f;
  sFloatControl *float_PreScale_2 = gh.Float(&para->PreScale.z,-1024.00f,1024.000f,0.010000f);
  float_PreScale_2->Default = 1.000000f; float_PreScale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* PreRot");
  gh.BeginTied();
  sFloatControl *float_PreRot_0 = gh.Float(&para->PreRot.x,-16.0000f,16.00000f,0.010000f);
  float_PreRot_0->Default = 0.000000f; float_PreRot_0->RightStep = 0.125000f;
  sFloatControl *float_PreRot_1 = gh.Float(&para->PreRot.y,-16.0000f,16.00000f,0.010000f);
  float_PreRot_1->Default = 0.000000f; float_PreRot_1->RightStep = 0.125000f;
  sFloatControl *float_PreRot_2 = gh.Float(&para->PreRot.z,-16.0000f,16.00000f,0.010000f);
  float_PreRot_2->Default = 0.000000f; float_PreRot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* PreTrans");
  gh.BeginTied();
  sFloatControl *float_PreTrans_0 = gh.Float(&para->PreTrans.x,-65536.0f,65536.00f,0.010000f);
  float_PreTrans_0->Default = 0.000000f; float_PreTrans_0->RightStep = 0.125000f;
  sFloatControl *float_PreTrans_1 = gh.Float(&para->PreTrans.y,-65536.0f,65536.00f,0.010000f);
  float_PreTrans_1->Default = 0.000000f; float_PreTrans_1->RightStep = 0.125000f;
  sFloatControl *float_PreTrans_2 = gh.Float(&para->PreTrans.z,-65536.0f,65536.00f,0.010000f);
  float_PreTrans_2->Default = 0.000000f; float_PreTrans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Multiply Transform");

  gh.Label(L"* Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,1024,0.125000f);
  int_Count->Default = 0x00000002; int_Count->RightStep = 0.125000f;

  gh.Label(L"* Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot");
  gh.BeginTied();
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-65536.0f,65536.00f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-65536.0f,65536.00f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-65536.0f,65536.00f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefMultiply(wOp *op)
{
  Wz4RenderParaMultiply sUNUSED *para = (Wz4RenderParaMultiply *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->PreScale.x = 1.000000f;
  para->PreScale.y = 1.000000f;
  para->PreScale.z = 1.000000f;
  para->Count = 0x00000002;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4RenderBindMultiply(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"prescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"prescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"prescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"prerot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"prerot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"prerot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"pretrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"pretrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"pretrans"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Multiply(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"prescale");
    name[4] = sPoolString(L"prerot");
    name[5] = sPoolString(L"pretrans");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"count");
    name[8] = sPoolString(L"scale");
    name[9] = sPoolString(L"rot");
    name[10] = sPoolString(L"trans");
    name[11] = sPoolString(L"");
    name[12] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+15);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+18);
  ctx->AddImport(name[12],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Multiply(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import prescale : float[3];\n");
  tb.PrintF(L"  import prerot : float[3];\n");
  tb.PrintF(L"  import pretrans : float[3];\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiMultiply =
L"= Wz4Render : Multiply\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Multiply\n"
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
L" !i Wz4Render\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Center\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i PreScale\n"
L" !i PreScale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i PreRot\n"
L" !i PreRot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i PreTrans\n"
L" !i PreTrans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
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

sBool Wz4RenderCmdClip(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaClip sUNUSED *para = (Wz4RenderParaClip *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 657 "wz4_demo2_ops.ops"

    RNClip *node = new RNClip();
    node->ParaBase = node->Para = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 4437 "wz4_demo2_ops.cpp"
    return 1;
  }
}

wCustomEditor *Wz4RenderCedClip(wOp *op)
{
  return new Wz4TimelineCed(op);
}

void Wz4RenderGuiClip(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaClip sUNUSED *para = (Wz4RenderParaClip *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"StartTime");
  sFloatControl *float_StartTime = gh.Float(&para->StartTime,0.000000f,65536.00f,0.250000f);
  float_StartTime->Default = 0.000000f; float_StartTime->RightStep = 0.125000f;

  gh.Label(L"Length");
  sFloatControl *float_Length = gh.Float(&para->Length,0.000000f,65536.00f,0.250000f);
  float_Length->Default = 16.00000f; float_Length->RightStep = 0.125000f;

  gh.Label(L"Line");
  sIntControl *int_Line = gh.Int(&para->Line,0,32,0.125000f);
  int_Line->Default = 0x00000001; int_Line->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|OffsetTime:*2-|Local:*3-|Hide:*4-|Cache Warmup",gh.LayoutMsg);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Time0");
  sFloatControl *float_Time0 = gh.Float(&para->Time0,-1024.00f,1024.000f,0.001000f);
  float_Time0->Default = 0.000000f; float_Time0->RightStep = 0.125000f;

  gh.Label(L"Time1");
  sFloatControl *float_Time1 = gh.Float(&para->Time1,-1024.00f,1024.000f,0.001000f);
  float_Time1->Default = 1.000000f; float_Time1->RightStep = 0.125000f;

  gh.Label(L"* Enable");
  gh.Flags(&para->Enable,L"Disable|Enable",gh.ChangeMsg);

  if((para->Flags&0x0004))
  {
    gh.Label(L"LocalOffset");
    sFloatControl *float_LocalOffset = gh.Float(&para->LocalOffset,-65536.0f,65536.00f,0.250000f);
    float_LocalOffset->Default = 0.000000f; float_LocalOffset->RightStep = 0.125000f;

  }
  gh.Label(L"Color");
  gh.Flags(&para->Color,L"white|red|yellow|green|cyan|blue|pink|gray",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefClip(wOp *op)
{
  Wz4RenderParaClip sUNUSED *para = (Wz4RenderParaClip *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Length = 16.00000f;
  para->Line = 0x00000001;
  para->Flags = 0x00000001;
  para->Time1 = 1.000000f;
  para->Enable = 0x00000001;
  para->Color = 0x00000007;
}

void Wz4RenderBindClip(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"starttime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"length"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"line"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"time0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"time1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"localoffset"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Clip(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"starttime");
    name[1] = sPoolString(L"length");
    name[2] = sPoolString(L"line");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"renderpass");
    name[5] = sPoolString(L"time0");
    name[6] = sPoolString(L"time1");
    name[7] = sPoolString(L"enable");
    name[8] = sPoolString(L"localoffset");
    name[9] = sPoolString(L"color_");
    name[10] = sPoolString(L"");
    name[11] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[11],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Clip(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import starttime : float;\n");
  tb.PrintF(L"  import length : float;\n");
  tb.PrintF(L"  import line : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import time0 : float;\n");
  tb.PrintF(L"  import time1 : float;\n");
  tb.PrintF(L"  import localoffset : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiClip =
L"= Wz4Render : Clip\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Clip\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i StartTime\n"
L" !i StartTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Length\n"
L" !i Length\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Line\n"
L" !i Line\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i OffsetTime\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Local\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Hide\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Cache Warmup\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Time0\n"
L" !i Time0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Time1\n"
L" !i Time1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Enable\n"
L" !i Enable\n"
L" !i Disable\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Enable\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i LocalOffset\n"
L" !i LocalOffset\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color\n"
L" !i Color\n"
L" !i white\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i red\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i yellow\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i green\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i cyan\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i blue\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pink\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i gray\n"
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

sBool Wz4RenderCmdClipRandomizer(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaClipRandomizer sUNUSED *para = (Wz4RenderParaClipRandomizer *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 684 "wz4_demo2_ops.ops"

    RNClipRand *node = new RNClipRand();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
    node->Init();
  ;
#line 4760 "wz4_demo2_ops.cpp"
    return 1;
  }
}

wCustomEditor *Wz4RenderCedClipRandomizer(wOp *op)
{
  return new Wz4TimelineCed(op);
}

sInt Wz4RenderActClipRandomizer(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaClipRandomizer sUNUSED *para = (Wz4RenderParaClipRandomizer *)(op->EditData); para;
#line 692 "wz4_demo2_ops.ops"

    return 1;         // just returning 1 will reevaluate the op. that causes reshuffling
  ;
#line 4777 "wz4_demo2_ops.cpp"
}

void Wz4RenderGuiClipRandomizer(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaClipRandomizer sUNUSED *para = (Wz4RenderParaClipRandomizer *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"StartTime");
  sFloatControl *float_StartTime = gh.Float(&para->StartTime,0.000000f,65536.00f,0.250000f);
  float_StartTime->Default = 0.000000f; float_StartTime->RightStep = 0.125000f;

  gh.Label(L"Length");
  sFloatControl *float_Length = gh.Float(&para->Length,0.000000f,65536.00f,0.250000f);
  float_Length->Default = 16.00000f; float_Length->RightStep = 0.125000f;

  gh.Label(L"Line");
  sIntControl *int_Line = gh.Int(&para->Line,0,32,0.125000f);
  int_Line->Default = 0x00000001; int_Line->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Enable");
  gh.Flags(&para->Enable,L"Disable|Enable",gh.ChangeMsg);

  gh.Label(L"DefaultClipLength");
  sFloatControl *float_DefaultClipLength = gh.Float(&para->DefaultClipLength,0.000000f,65536.00f,0.250000f);
  float_DefaultClipLength->Default = 16.00000f; float_DefaultClipLength->RightStep = 0.125000f;

  gh.Label(L"Action");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Shuffle",gh.ActionMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefClipRandomizer(wOp *op)
{
  Wz4RenderParaClipRandomizer sUNUSED *para = (Wz4RenderParaClipRandomizer *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Length = 16.00000f;
  para->Line = 0x00000001;
  para->Enable = 0x00000001;
  para->DefaultClipLength = 16.00000f;
}

void Wz4RenderBindClipRandomizer(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"starttime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"length"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"line"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"defaultcliplength"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ClipRandomizer(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"starttime");
    name[1] = sPoolString(L"length");
    name[2] = sPoolString(L"line");
    name[3] = sPoolString(L"renderpass");
    name[4] = sPoolString(L"enable");
    name[5] = sPoolString(L"defaultcliplength");
    name[6] = sPoolString(L"action");
    name[7] = sPoolString(L"shuffle");
    name[8] = sPoolString(L"");
    name[9] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ClipRandomizer(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import starttime : float;\n");
  tb.PrintF(L"  import length : float;\n");
  tb.PrintF(L"  import line : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import defaultcliplength : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiClipRandomizer =
L"= Wz4Render : ClipRandomizer\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ClipRandomizer\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i StartTime\n"
L" !i StartTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Length\n"
L" !i Length\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Line\n"
L" !i Line\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Enable\n"
L" !i Enable\n"
L" !i Disable\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Enable\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DefaultClipLength\n"
L" !i DefaultClipLength\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Shuffle\n"
L" !i Shuffle\n"
L" !i action\n"
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

sBool Wz4RenderCmdClipRandDuration(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaClipRandDuration sUNUSED *para = (Wz4RenderParaClipRandDuration *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 705 "wz4_demo2_ops.ops"

    Wz4RenderNode *node = new Wz4RenderNode;
    node->ClipRandDuration = para->Length;
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 4994 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiClipRandDuration(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaClipRandDuration sUNUSED *para = (Wz4RenderParaClipRandDuration *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Length");
  sFloatControl *float_Length = gh.Float(&para->Length,0.000000f,65536.00f,0.250000f);
  float_Length->Default = 16.00000f; float_Length->RightStep = 0.125000f;
}

void Wz4RenderDefClipRandDuration(wOp *op)
{
  Wz4RenderParaClipRandDuration sUNUSED *para = (Wz4RenderParaClipRandDuration *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Length = 16.00000f;
}

void Wz4RenderBindClipRandDuration(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"length"),val);
}
void Wz4RenderBind2ClipRandDuration(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"length");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+1);
}
void Wz4RenderBind3ClipRandDuration(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import length : float;\n");
}
const sChar *Wz4RenderWikiClipRandDuration =
L"= Wz4Render : ClipRandDuration\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ClipRandDuration\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Length\n"
L" !i Length\n"
L" !i float\n"
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

sBool Wz4RenderCmdMultiClip(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaMultiClip sUNUSED *para = (Wz4RenderParaMultiClip *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 736 "wz4_demo2_ops.ops"

    RNMultiClip *node = new RNMultiClip();
    node->Init(*para,cmd->ArrayCount,(const Wz4RenderArrayMultiClip *)cmd->Array);
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 5103 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderArrMultiClip(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaMultiClip sUNUSED *para = (Wz4RenderParaMultiClip *)(op->EditData); para;
  Wz4RenderArrayMultiClip *e = (Wz4RenderArrayMultiClip *)(mem);
#line 744 "wz4_demo2_ops.ops"

    Wz4RenderArrayMultiClip *f;
    sInt max = op->ArrayData.GetCount();

    if(max==0 || pos==0)
    {
      e->Start = 0;
      e->Length = 16;
      e->Time0 = 0;
      e->Time1 = 1;
      e->Enable = 1;
    }
    else
    {
      f = (Wz4RenderArrayMultiClip *) op->ArrayData[pos-1];
      e->Start = f->Start + f->Length;
      e->Length = f->Length;
      e->Time0 = f->Time0;
      e->Time1 = f->Time1;
      e->Enable = 1;
    }
  ;
#line 5135 "wz4_demo2_ops.cpp"
}

wCustomEditor *Wz4RenderCedMultiClip(wOp *op)
{
  return new Wz4TimelineCed(op);
}

void Wz4RenderGuiMultiClip(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaMultiClip sUNUSED *para = (Wz4RenderParaMultiClip *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|OffsetTime:*4-|Cache Warmup",gh.ChangeMsg);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Line");
  sIntControl *int_Line = gh.Int(&para->Line,0,32,0.125000f);
  int_Line->Default = 0x00000001; int_Line->RightStep = 0.125000f;

  gh.Label(L"* MasterEnable");
  gh.Flags(&para->MasterEnable,L"Disable|Enable",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Start",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Length",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Time0",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Time1",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Enable",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Color",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArrayMultiClip *elem = (Wz4RenderArrayMultiClip *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    sFloatControl *float_Start = gh.Float(&elem->Start,0.000000f,65536.00f,0.250000f);
    float_Start->Default = 0.000000f; float_Start->RightStep = 0.125000f;

    sFloatControl *float_Length = gh.Float(&elem->Length,0.000000f,65536.00f,0.250000f);
    float_Length->Default = 16.00000f; float_Length->RightStep = 0.125000f;

    sFloatControl *float_Time0 = gh.Float(&elem->Time0,0.000000f,1.000000f,0.001000f);
    float_Time0->Default = 0.000000f; float_Time0->RightStep = 0.125000f;

    sFloatControl *float_Time1 = gh.Float(&elem->Time1,0.000000f,1.000000f,0.001000f);
    float_Time1->Default = 1.000000f; float_Time1->RightStep = 0.125000f;

    gh.Flags(&elem->Enable,L"disable|enable",gh.ChangeMsg);

    gh.Flags(&elem->Color,L"white|red|yellow|green|cyan|blue|pink|gray",gh.ChangeMsg);
      if(hidesome)
      {
        gh.RemArrayGroupMsg.Code = _i;
        gh.Box(L"Rem",gh.RemArrayGroupMsg);
      }
      else
      {
        gh.AddArrayMsg.Code = _i;
        gh.RemArrayMsg.Code = _i;
        gh.Box(L"Add",gh.AddArrayMsg,sGFLF_HALFUP);
        gh.Box(L"Rem",gh.RemArrayMsg)->InitRadio(&op->HighlightArrayLine,_i);
      }
      if(gh.Left<gh.Right && !(_i&1)) gh.Grid->AddLabel(0,gh.Left,gh.Line,gh.Right-gh.Left,1,sGFLF_LEAD);
      gh.NextLine();
    }
    gh.AddArrayMsg.Code = op->ArrayData.GetCount();
    if(!hidesome)
      gh.Box(L"Add",gh.AddArrayMsg,sGFLF_HALFUP);
  }
}

void Wz4RenderDefMultiClip(wOp *op)
{
  Wz4RenderParaMultiClip sUNUSED *para = (Wz4RenderParaMultiClip *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000001;
  para->Line = 0x00000001;
  para->MasterEnable = 0x00000001;
}

void Wz4RenderBindMultiClip(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"line"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2MultiClip(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"line");
    name[3] = sPoolString(L"masterenable");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3MultiClip(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import line : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiMultiClip =
L"= Wz4Render : MultiClip\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MultiClip\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i OffsetTime\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Cache Warmup\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Line\n"
L" !i Line\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i MasterEnable\n"
L" !i MasterEnable\n"
L" !i Disable\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Enable\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Script\n"
L" !i Script\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"== Array Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i OffsetTime\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Cache Warmup\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Line\n"
L" !i Line\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i MasterEnable\n"
L" !i MasterEnable\n"
L" !i Disable\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Enable\n"
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

sBool Wz4RenderCmdFader(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFader sUNUSED *para = (Wz4RenderParaFader *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 784 "wz4_demo2_ops.ops"

    RNFader *node = new RNFader();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 5428 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFader(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFader sUNUSED *para = (Wz4RenderParaFader *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Fader[0..3]");
  gh.BeginTied();
  sFloatControl *float_FaderA_0 = gh.Float(&para->FaderA.x,0.000000f,1.000000f,0.001000f);
  float_FaderA_0->Default = 0.500000f; float_FaderA_0->RightStep = 0.125000f;
  sFloatControl *float_FaderA_1 = gh.Float(&para->FaderA.y,0.000000f,1.000000f,0.001000f);
  float_FaderA_1->Default = 0.500000f; float_FaderA_1->RightStep = 0.125000f;
  sFloatControl *float_FaderA_2 = gh.Float(&para->FaderA.z,0.000000f,1.000000f,0.001000f);
  float_FaderA_2->Default = 0.500000f; float_FaderA_2->RightStep = 0.125000f;
  sFloatControl *float_FaderA_3 = gh.Float(&para->FaderA.w,0.000000f,1.000000f,0.001000f);
  float_FaderA_3->Default = 0.500000f; float_FaderA_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Fader[4..7]");
  gh.BeginTied();
  sFloatControl *float_FaderB_0 = gh.Float(&para->FaderB.x,0.000000f,1.000000f,0.001000f);
  float_FaderB_0->Default = 0.500000f; float_FaderB_0->RightStep = 0.125000f;
  sFloatControl *float_FaderB_1 = gh.Float(&para->FaderB.y,0.000000f,1.000000f,0.001000f);
  float_FaderB_1->Default = 0.500000f; float_FaderB_1->RightStep = 0.125000f;
  sFloatControl *float_FaderB_2 = gh.Float(&para->FaderB.z,0.000000f,1.000000f,0.001000f);
  float_FaderB_2->Default = 0.500000f; float_FaderB_2->RightStep = 0.125000f;
  sFloatControl *float_FaderB_3 = gh.Float(&para->FaderB.w,0.000000f,1.000000f,0.001000f);
  float_FaderB_3->Default = 0.500000f; float_FaderB_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rotor[0..3]");
  gh.BeginTied();
  sFloatControl *float_RotorA_0 = gh.Float(&para->RotorA.x,0.000000f,1.000000f,0.001000f);
  float_RotorA_0->Default = 0.500000f; float_RotorA_0->RightStep = 0.125000f;
  sFloatControl *float_RotorA_1 = gh.Float(&para->RotorA.y,0.000000f,1.000000f,0.001000f);
  float_RotorA_1->Default = 0.500000f; float_RotorA_1->RightStep = 0.125000f;
  sFloatControl *float_RotorA_2 = gh.Float(&para->RotorA.z,0.000000f,1.000000f,0.001000f);
  float_RotorA_2->Default = 0.500000f; float_RotorA_2->RightStep = 0.125000f;
  sFloatControl *float_RotorA_3 = gh.Float(&para->RotorA.w,0.000000f,1.000000f,0.001000f);
  float_RotorA_3->Default = 0.500000f; float_RotorA_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rotor[4..7]");
  gh.BeginTied();
  sFloatControl *float_RotorB_0 = gh.Float(&para->RotorB.x,0.000000f,1.000000f,0.001000f);
  float_RotorB_0->Default = 0.500000f; float_RotorB_0->RightStep = 0.125000f;
  sFloatControl *float_RotorB_1 = gh.Float(&para->RotorB.y,0.000000f,1.000000f,0.001000f);
  float_RotorB_1->Default = 0.500000f; float_RotorB_1->RightStep = 0.125000f;
  sFloatControl *float_RotorB_2 = gh.Float(&para->RotorB.z,0.000000f,1.000000f,0.001000f);
  float_RotorB_2->Default = 0.500000f; float_RotorB_2->RightStep = 0.125000f;
  sFloatControl *float_RotorB_3 = gh.Float(&para->RotorB.w,0.000000f,1.000000f,0.001000f);
  float_RotorB_3->Default = 0.500000f; float_RotorB_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFader(wOp *op)
{
  Wz4RenderParaFader sUNUSED *para = (Wz4RenderParaFader *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->FaderA.x = 0.500000f;
  para->FaderA.y = 0.500000f;
  para->FaderA.z = 0.500000f;
  para->FaderA.w = 0.500000f;
  para->FaderB.x = 0.500000f;
  para->FaderB.y = 0.500000f;
  para->FaderB.z = 0.500000f;
  para->FaderB.w = 0.500000f;
  para->RotorA.x = 0.500000f;
  para->RotorA.y = 0.500000f;
  para->RotorA.z = 0.500000f;
  para->RotorA.w = 0.500000f;
  para->RotorB.x = 0.500000f;
  para->RotorB.y = 0.500000f;
  para->RotorB.z = 0.500000f;
  para->RotorB.w = 0.500000f;
}

void Wz4RenderBindFader(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Fader(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"fadera");
    name[2] = sPoolString(L"faderb");
    name[3] = sPoolString(L"rotora");
    name[4] = sPoolString(L"rotorb");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,4,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,4,cmd->Data+5);
  ctx->AddImport(name[3],ScriptTypeFloat,4,cmd->Data+9);
  ctx->AddImport(name[4],ScriptTypeFloat,4,cmd->Data+13);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Fader(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import fadera : float[4];\n");
  tb.PrintF(L"  import faderb : float[4];\n");
  tb.PrintF(L"  import rotora : float[4];\n");
  tb.PrintF(L"  import rotorb : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFader =
L"= Wz4Render : Fader\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Fader\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Fader[0..3]\n"
L" !i FaderA\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Fader[4..7]\n"
L" !i FaderB\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Rotor[0..3]\n"
L" !i RotorA\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Rotor[4..7]\n"
L" !i RotorB\n"
L" !i float[4]\n"
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

sBool Wz4RenderCmdFader2(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFader2 sUNUSED *para = (Wz4RenderParaFader2 *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 808 "wz4_demo2_ops.ops"

    RNFader *node = new RNFader();
    node->ParaBase = node->Para = *(Wz4RenderParaFader *)para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 5701 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFader2(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFader2 sUNUSED *para = (Wz4RenderParaFader2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Fader[0..3]");
  gh.BeginTied();
  sFloatControl *float_FaderA_0 = gh.Float(&para->FaderA.x, -1000000,  1000000,0.010000f);
  float_FaderA_0->Default = 0.000000f; float_FaderA_0->RightStep = 0.125000f;
  sFloatControl *float_FaderA_1 = gh.Float(&para->FaderA.y, -1000000,  1000000,0.010000f);
  float_FaderA_1->Default = 0.000000f; float_FaderA_1->RightStep = 0.125000f;
  sFloatControl *float_FaderA_2 = gh.Float(&para->FaderA.z, -1000000,  1000000,0.010000f);
  float_FaderA_2->Default = 0.000000f; float_FaderA_2->RightStep = 0.125000f;
  sFloatControl *float_FaderA_3 = gh.Float(&para->FaderA.w, -1000000,  1000000,0.010000f);
  float_FaderA_3->Default = 0.000000f; float_FaderA_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Fader[4..7]");
  gh.BeginTied();
  sFloatControl *float_FaderB_0 = gh.Float(&para->FaderB.x, -1000000,  1000000,0.010000f);
  float_FaderB_0->Default = 0.000000f; float_FaderB_0->RightStep = 0.125000f;
  sFloatControl *float_FaderB_1 = gh.Float(&para->FaderB.y, -1000000,  1000000,0.010000f);
  float_FaderB_1->Default = 0.000000f; float_FaderB_1->RightStep = 0.125000f;
  sFloatControl *float_FaderB_2 = gh.Float(&para->FaderB.z, -1000000,  1000000,0.010000f);
  float_FaderB_2->Default = 0.000000f; float_FaderB_2->RightStep = 0.125000f;
  sFloatControl *float_FaderB_3 = gh.Float(&para->FaderB.w, -1000000,  1000000,0.010000f);
  float_FaderB_3->Default = 0.000000f; float_FaderB_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rotor[0..3]");
  gh.BeginTied();
  sFloatControl *float_RotorA_0 = gh.Float(&para->RotorA.x, -1000000,  1000000,0.010000f);
  float_RotorA_0->Default = 0.000000f; float_RotorA_0->RightStep = 0.125000f;
  sFloatControl *float_RotorA_1 = gh.Float(&para->RotorA.y, -1000000,  1000000,0.010000f);
  float_RotorA_1->Default = 0.000000f; float_RotorA_1->RightStep = 0.125000f;
  sFloatControl *float_RotorA_2 = gh.Float(&para->RotorA.z, -1000000,  1000000,0.010000f);
  float_RotorA_2->Default = 0.000000f; float_RotorA_2->RightStep = 0.125000f;
  sFloatControl *float_RotorA_3 = gh.Float(&para->RotorA.w, -1000000,  1000000,0.010000f);
  float_RotorA_3->Default = 0.000000f; float_RotorA_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rotor[4..7]");
  gh.BeginTied();
  sFloatControl *float_RotorB_0 = gh.Float(&para->RotorB.x, -1000000,  1000000,0.010000f);
  float_RotorB_0->Default = 0.000000f; float_RotorB_0->RightStep = 0.125000f;
  sFloatControl *float_RotorB_1 = gh.Float(&para->RotorB.y, -1000000,  1000000,0.010000f);
  float_RotorB_1->Default = 0.000000f; float_RotorB_1->RightStep = 0.125000f;
  sFloatControl *float_RotorB_2 = gh.Float(&para->RotorB.z, -1000000,  1000000,0.010000f);
  float_RotorB_2->Default = 0.000000f; float_RotorB_2->RightStep = 0.125000f;
  sFloatControl *float_RotorB_3 = gh.Float(&para->RotorB.w, -1000000,  1000000,0.010000f);
  float_RotorB_3->Default = 0.000000f; float_RotorB_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFader2(wOp *op)
{
  Wz4RenderParaFader2 sUNUSED *para = (Wz4RenderParaFader2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindFader2(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"fadera"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"faderb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotora"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotorb"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Fader2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"fadera");
    name[2] = sPoolString(L"faderb");
    name[3] = sPoolString(L"rotora");
    name[4] = sPoolString(L"rotorb");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,4,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,4,cmd->Data+5);
  ctx->AddImport(name[3],ScriptTypeFloat,4,cmd->Data+9);
  ctx->AddImport(name[4],ScriptTypeFloat,4,cmd->Data+13);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Fader2(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import fadera : float[4];\n");
  tb.PrintF(L"  import faderb : float[4];\n");
  tb.PrintF(L"  import rotora : float[4];\n");
  tb.PrintF(L"  import rotorb : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFader2 =
L"= Wz4Render : Fader2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Fader2\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Fader[0..3]\n"
L" !i FaderA\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Fader[4..7]\n"
L" !i FaderB\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Rotor[0..3]\n"
L" !i RotorA\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Rotor[4..7]\n"
L" !i RotorB\n"
L" !i float[4]\n"
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

sBool Wz4RenderCmdVariable(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaVariable sUNUSED *para = (Wz4RenderParaVariable *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 831 "wz4_demo2_ops.ops"

    RNVariable *node = new RNVariable();
    node->Init(para,cmd->Strings[1]);
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 5958 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiVariable(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaVariable sUNUSED *para = (Wz4RenderParaVariable *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Name");
  gh.String(op->EditString[1]);

  gh.Label(L"Count");
  gh.Flags(&para->Count,L"| 1| 2| 3| 4",gh.ChangeMsg);

  gh.Label(L"Value");
  gh.BeginTied();
  sFloatControl *float_Value_0 = gh.Float(&para->Value.x, -1000000,  1000000,0.001000f);
  float_Value_0->Default = 0.000000f; float_Value_0->RightStep = 0.125000f;
  sFloatControl *float_Value_1 = gh.Float(&para->Value.y, -1000000,  1000000,0.001000f);
  float_Value_1->Default = 0.000000f; float_Value_1->RightStep = 0.125000f;
  sFloatControl *float_Value_2 = gh.Float(&para->Value.z, -1000000,  1000000,0.001000f);
  float_Value_2->Default = 0.000000f; float_Value_2->RightStep = 0.125000f;
  sFloatControl *float_Value_3 = gh.Float(&para->Value.w, -1000000,  1000000,0.001000f);
  float_Value_3->Default = 0.000000f; float_Value_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[2],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefVariable(wOp *op)
{
  Wz4RenderParaVariable sUNUSED *para = (Wz4RenderParaVariable *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000003;
}

void Wz4RenderBindVariable(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"value"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"value"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"value"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"value"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+2;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Variable(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"name");
    name[2] = sPoolString(L"count");
    name[3] = sPoolString(L"value");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[3],ScriptTypeFloat,4,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+2);
}
void Wz4RenderBind3Variable(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import name : string;\n");
  tb.PrintF(L"  import value : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiVariable =
L"= Wz4Render : Variable\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Variable\n"
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
L" !i Wz4Render\n"
L" !i multiple optional\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Count\n"
L" !i Count\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Value\n"
L" !i Value\n"
L" !i float[4]\n"
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

sBool Wz4RenderCmdSpline(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSpline sUNUSED *para = (Wz4RenderParaSpline *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 976 "wz4_demo2_ops.ops"

    RNSpline *node = new RNSpline();
    node->Init(para,cmd->ArrayCount,(Wz4RenderArraySpline *)cmd->Array,cmd->Strings[0]);
    out->RootNode = node;
    cmd->Strings[0] = 0; // we don't want code..
    out->AddChilds(cmd,0);

    if(cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();
    }
  ;
#line 6163 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndSpline(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaSpline sUNUSED *para = (Wz4RenderParaSpline *)(op->EditData); para;
#line 990 "wz4_demo2_ops.ops"
    
    Wz4Render *rn = (Wz4Render *)op->RefObj;
    RNSpline *rns = (RNSpline *)rn->RootNode;
    ScriptSpline *spline = rns->Spline;
    if(para->Dimensions+1>=3 && spline)
    {
      sVector31 v0,v1;
      spline->Eval(0,&v0.x,3);
      for(sInt i=1;i<256;i++)
      {
        spline->Eval(spline->MaxTime*i/256,&v1.x,3);
        pi.Line3D(v0,v1,(i&1)?0xffff0000:0xff00ff00);
        v0 = v1;
      }
    }
    sF32 time = 0;
    sF32 *slots[3] = { 0,0,0 };
    sInt n = 1;
    for(sInt i=0;i<op->ArrayData.GetCount();i++)
    {
      Wz4RenderArraySpline *e = (Wz4RenderArraySpline *)op->ArrayData[i];
      if(e->Time!=time)
      {
        time = e->Time;
        sClear(slots);
      }
      if(e->Time==time && e->Use>=0 && e->Use<3)
        slots[e->Use] = &e->Value;
      if(slots[0] && slots[1] && slots[2])
      {
        pi.Handle3D(op,n++,slots[0],slots[1],slots[2],wHM_PLANE);
        pi.Line3D(sVector31(*slots[0],*slots[1],*slots[2]),sVector31(*slots[0],0,*slots[2]),0);
        sClear(slots);
      }
    }
  ;
#line 6208 "wz4_demo2_ops.cpp"
}

void Wz4RenderArrSpline(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaSpline sUNUSED *para = (Wz4RenderParaSpline *)(op->EditData); para;
  Wz4RenderArraySpline *e = (Wz4RenderArraySpline *)(mem);
  e->Time = 0.000000f;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Use = 0x00000000;
  e->Value = 0.000000f;
  e->Select = 0x00000000;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4RenderArraySpline *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4RenderArraySpline *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4RenderArraySpline *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4RenderArraySpline *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4RenderArraySpline *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4RenderArraySpline *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4RenderArraySpline *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4RenderArraySpline *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4RenderArraySpline *)op->ArrayData[pos  ];
    }
    e->Time = f0*p0->Time + f1*p1->Time;
    e->Value = f0*p0->Value + f1*p1->Value;
  }
}

wCustomEditor *Wz4RenderCedSpline(wOp *op)
{
  return new Wz4SplineCed(op);
}

sInt Wz4RenderActSpline(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaSpline sUNUSED *para = (Wz4RenderParaSpline *)(op->EditData); para;
#line 882 "wz4_demo2_ops.ops"

    if(code==2)
    {
      Wz4RenderArraySpline *key;
      sInt max = para->Dimensions+1;

      sDeleteAll(op->ArrayData);
      for(sInt i=0;i<max*2;i++)
        op->ArrayData.AddTail(new Wz4RenderArraySpline);
      for(sInt i=0;i<max;i++)
      {
        key = (Wz4RenderArraySpline *) op->ArrayData[i*2+0];
        key->Time = 0;
        key->Value = 0;
        key->Use = i;
        key->Select = 0;
        key = (Wz4RenderArraySpline *) op->ArrayData[i*2+1];
        key->Time = 1;
        key->Value = 0;
        key->Use = i;
        key->Select = 0;
      }
      Doc->Change(op);
      App->CustomWin->ChangeOp();

      // fall through
//      return 1;
    }
    if(code==1 || code==2 || code==3) // relax by arclength auto-sorts
    {
      sInt max = op->ArrayData.GetCount();
      for(sInt i=0;i<max-1;i++)
      {
        for(sInt j=i+1;j<max;j++)
        {
          Wz4RenderArraySpline *a = (Wz4RenderArraySpline *) op->ArrayData[i];
          Wz4RenderArraySpline *b = (Wz4RenderArraySpline *) op->ArrayData[j];

          if(a->Time > b->Time || (a->Time==b->Time && a->Use > b->Use))
            op->ArrayData.Swap(i,j);
        }
      }
      if(code != 3)
        return 1;
    }
    if(code==3) // relax by arclength
    {
      static const sInt nDim = 8;
      sF64 currentArclen[nDim] = { 0.0 };
      sF32 currentTime[nDim] = { 0.0f };

      Wz4Render *rn = (Wz4Render *)op->RefObj;
      RNSpline *rns = (RNSpline *)rn->RootNode;
      ScriptSpline *spline = rns->Spline;

      sInt max = op->ArrayData.GetCount();

      // accumulate arclengths over all partial segments
      for(sInt i=0;i<max;i++)
      {
        Wz4RenderArraySpline *a = (Wz4RenderArraySpline *) op->ArrayData[i];
        sVERIFY(a->Use < nDim);

        // we subtract a bit from the end points to work around discontinuities at the transition
        // between spline segments
        sF32 time0 = currentTime[a->Use];
        sF32 time1 = a->Time;
        sF32 startTime = sFade(0.0001f,time0,time1);
        sF32 endTime = sFade(0.9999f,time0,time1);

        sF32 partialArcLen = spline->ArcLength(startTime,endTime);
        currentTime[a->Use] = a->Time;
        currentArclen[a->Use] += partialArcLen;
        a->Time = sF32(currentArclen[a->Use]);
      }

      // renormalize
      sF64 rescale[nDim];
      for(sInt i=0;i<nDim;i++)
        rescale[i] = currentArclen[i] ? currentTime[i] / currentArclen[i] : 0.0;

      for(sInt i=0;i<max;i++)
      {
        Wz4RenderArraySpline *a = (Wz4RenderArraySpline *) op->ArrayData[i];
        a->Time *= sF32(rescale[a->Use]);
      }

      Doc->Change(op);
      App->CustomWin->ChangeOp();
      return 1;
    }
    return 0;
  ;
#line 6358 "wz4_demo2_ops.cpp"
}

void Wz4RenderGuiSpline(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSpline sUNUSED *para = (Wz4RenderParaSpline *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);

  gh.Label(L"Dimensions");
  gh.Flags(&para->Dimensions,L" 1D| 2D| 3D| 4D| 5D| 6D | 7D| 8D",gh.LayoutMsg);

  gh.Label(L"Spline");
  gh.Flags(&para->Spline,L"step|linear|uni. hermite|hermite|uni. bspline",gh.ChangeMsg);

  gh.Label(L"MaxTime");
  sFloatControl *float_MaxTime = gh.Float(&para->MaxTime,0.000000f,1024.000f,0.125000f);
  float_MaxTime->Default = 1.000000f; float_MaxTime->RightStep = 0.125000f;

  gh.Flags(&para->Flags,L"-|Loop|zero|extrapolate",gh.ChangeMsg);

  gh.Label(L"GrabCamMode");
  gh.Flags(&para->GrabCamMode,L"pos|rot|pos-rot-zoom|pos-target-zoom-tilt",gh.ChangeMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"CreateNew",gh.ActionMsg);

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Sort",gh.ActionMsg);

  gh.ActionMsg.Code = 3;
  gh.PushButton(L"RelaxByArclength",gh.ActionMsg);
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide|group",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Time",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  if((para->Dimensions==0x0000))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0001))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0002))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0003))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0004))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0005))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0006))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  if((para->Dimensions==0x0007))
  {
    gh.Grid->AddLabel(L"Use",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  }
  gh.Grid->AddLabel(L"Value",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Select",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hidesome=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArraySpline *elem = (Wz4RenderArraySpline *)ap;
      if(hidesome && ((sU32 *)elem)[3]==0) continue;

    sFloatControl *float_Time = gh.Float(&elem->Time,-1024.00f,1024.000f,0.010000f);
    float_Time->Default = 0.000000f; float_Time->RightStep = 0.125000f;

    if((para->Dimensions==0x0000))
    {
      gh.Flags(&elem->Use,L"#X",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0001))
    {
      gh.Flags(&elem->Use,L"#X|Y",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0002))
    {
      gh.Flags(&elem->Use,L"#X|Y|Z",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0003))
    {
      gh.Flags(&elem->Use,L"#X|Y|Z|W",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0004))
    {
      gh.Flags(&elem->Use,L"# 0| 1| 2| 3| 4",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0005))
    {
      gh.Flags(&elem->Use,L"# 0| 1| 2| 3| 4| 5",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0006))
    {
      gh.Flags(&elem->Use,L"# 0| 1| 2| 3| 4| 5| 6",gh.ChangeMsg);

    }
    if((para->Dimensions==0x0007))
    {
      gh.Flags(&elem->Use,L"# 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

    }
    sFloatControl *float_Value = gh.Float(&elem->Value,-65536.0f,65536.00f,0.010000f);
    float_Value->Default = 0.000000f; float_Value->RightStep = 0.125000f;

    gh.Flags(&elem->Select,L"-|Select",gh.ChangeMsg);
      if(hidesome)
      {
        gh.RemArrayGroupMsg.Code = _i;
        gh.Box(L"Rem",gh.RemArrayGroupMsg);
      }
      else
      {
        gh.AddArrayMsg.Code = _i;
        gh.RemArrayMsg.Code = _i;
        gh.Box(L"Add",gh.AddArrayMsg,sGFLF_HALFUP);
        gh.Box(L"Rem",gh.RemArrayMsg)->InitRadio(&op->HighlightArrayLine,_i);
      }
      if(gh.Left<gh.Right && !(_i&1)) gh.Grid->AddLabel(0,gh.Left,gh.Line,gh.Right-gh.Left,1,sGFLF_LEAD);
      gh.NextLine();
    }
    gh.AddArrayMsg.Code = op->ArrayData.GetCount();
    if(!hidesome)
      gh.Box(L"Add",gh.AddArrayMsg,sGFLF_HALFUP);
  }
}

void Wz4RenderDefSpline(wOp *op)
{
  Wz4RenderParaSpline sUNUSED *para = (Wz4RenderParaSpline *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Dimensions = 0x00000002;
  para->Spline = 0x00000002;
  para->MaxTime = 1.000000f;
  para->GrabCamMode = 0x00000003;
}

void Wz4RenderBindSpline(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"maxtime"),val);
}
void Wz4RenderBind2Spline(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"name");
    name[1] = sPoolString(L"dimensions");
    name[2] = sPoolString(L"spline");
    name[3] = sPoolString(L"maxtime");
    name[4] = sPoolString(L"flags");
    name[5] = sPoolString(L"grabcammode");
    name[6] = sPoolString(L"createnew");
    name[7] = sPoolString(L"sort");
    name[8] = sPoolString(L"relaxbyarclength");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4RenderBind3Spline(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
  tb.PrintF(L"  import maxtime : float;\n");
}
const sChar *Wz4RenderWikiSpline =
L"= Wz4Render : Spline\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Spline\n"
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
L" !i Wz4Render\n"
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
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Dimensions\n"
L" !i Dimensions\n"
L" !i 1D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6D \n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8D\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Spline\n"
L" !i Spline\n"
L" !i step\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uni. hermite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i hermite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uni. bspline\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MaxTime\n"
L" !i MaxTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Flags\n"
L" !i Loop\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zero\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i extrapolate\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i GrabCamMode\n"
L" !i GrabCamMode\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i rot\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pos-rot-zoom\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pos-target-zoom-tilt\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CreateNew\n"
L" !i CreateNew\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Sort\n"
L" !i Sort\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i RelaxByArclength\n"
L" !i RelaxByArclength\n"
L" !i action\n"
L" !i *\n"
L"\n"
L"== Array Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Dimensions\n"
L" !i Dimensions\n"
L" !i 1D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6D \n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8D\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Spline\n"
L" !i Spline\n"
L" !i step\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uni. hermite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i hermite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uni. bspline\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MaxTime\n"
L" !i MaxTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Flags\n"
L" !i Loop\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zero\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i extrapolate\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i GrabCamMode\n"
L" !i GrabCamMode\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i rot\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pos-rot-zoom\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pos-target-zoom-tilt\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CreateNew\n"
L" !i CreateNew\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Sort\n"
L" !i Sort\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i RelaxByArclength\n"
L" !i RelaxByArclength\n"
L" !i action\n"
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

sBool Wz4RenderCmdLayer2D(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaLayer2D sUNUSED *para = (Wz4RenderParaLayer2D *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 1060 "wz4_demo2_ops.ops"

    RNLayer2D *node = new RNLayer2D();
    node->ParaBase = node->Para = *para;
    node->Texture[0] = in0; in0->AddRef();
    node->Texture[1] = in1; in1->AddRef();
    node->DocScreenY = sF32(Doc->DocOptions.ScreenY);
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 6857 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiLayer2D(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaLayer2D sUNUSED *para = (Wz4RenderParaLayer2D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-128,128,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center[0],-4.00000f,4.000000f,0.010000f);
  float_Center_0->Default = 0.500000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center[1],-4.00000f,4.000000f,0.010000f);
  float_Center_1->Default = 0.500000f; float_Center_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Size");
  gh.BeginTied();
  sFloatControl *float_Size_0 = gh.Float(&para->Size[0],-1024.00f,1024.000f,0.010000f);
  float_Size_0->Default = 1.000000f; float_Size_0->RightStep = 0.125000f;
  sFloatControl *float_Size_1 = gh.Float(&para->Size[1],-1024.00f,1024.000f,0.010000f);
  float_Size_1->Default = 1.000000f; float_Size_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ScaleUV");
  gh.BeginTied();
  sFloatControl *float_ScaleUV_0 = gh.Float(&para->ScaleUV[0],-1024.00f,1024.000f,0.010000f);
  float_ScaleUV_0->Default = 1.000000f; float_ScaleUV_0->RightStep = 0.125000f;
  sFloatControl *float_ScaleUV_1 = gh.Float(&para->ScaleUV[1],-1024.00f,1024.000f,0.010000f);
  float_ScaleUV_1->Default = 1.000000f; float_ScaleUV_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ScrollUV");
  gh.BeginTied();
  sFloatControl *float_ScrollUV_0 = gh.Float(&para->ScrollUV[0],-1024.00f,1024.000f,0.010000f);
  float_ScrollUV_0->Default = 0.000000f; float_ScrollUV_0->RightStep = 0.125000f;
  sFloatControl *float_ScrollUV_1 = gh.Float(&para->ScrollUV[1],-1024.00f,1024.000f,0.010000f);
  float_ScrollUV_1->Default = 0.000000f; float_ScrollUV_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Group(L"modes");

  gh.Label(L"Aspect");
  gh.Flags(&para->Aspect,L"Square|Screen|Image",gh.ChangeMsg);

  gh.Label(L"Size Ref");
  gh.Flags(&para->Aspect,L"*2screen|image",gh.ChangeMsg);

  gh.Label(L"Blend");
  gh.Flags(&para->Blend,L"solid|alpha premul|add|sub|mul|mul2|addsmooth|alpha plain|monochrome|add dest alpha|add inv dest alpha:*16dest alpha from shader|dest alpha unchanged|dest alpha = 0|dest alpha blend",gh.ChangeMsg);

  gh.Label(L"Align");
  gh.Flags(&para->Align,L"left|center|right:*2top|center|bottom",gh.ChangeMsg);

  gh.Label(L"Filter");
  gh.Flags(&para->Filter,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  gh.Group(L"second texture");

  gh.Label(L"SecondTexture");
  gh.Flags(&op->Links[1].Select,L"input|link",gh.ConnectLayoutMsg);
  if(op->Links[1].Select==1)
  {
    sControl *con=gh.String(op->Links[1].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 1;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 1;
    gh.Box(L"..",msg);
    if(!op->Links[1].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 1;
      gh.Box(L"->",msg);
    }
  }

  if((op->ConnectionMask & (1<<1))!=0)
  {
    gh.Label(L"Mix");
    gh.Flags(&para->Mix,L"mul|add|sub",gh.ChangeMsg);

    gh.Label(L"* ScaleUV2");
    gh.BeginTied();
    sFloatControl *float_ScaleUV2_0 = gh.Float(&para->ScaleUV2[0],-1024.00f,1024.000f,0.010000f);
    float_ScaleUV2_0->Default = 1.000000f; float_ScaleUV2_0->RightStep = 0.125000f;
    sFloatControl *float_ScaleUV2_1 = gh.Float(&para->ScaleUV2[1],-1024.00f,1024.000f,0.010000f);
    float_ScaleUV2_1->Default = 1.000000f; float_ScaleUV2_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* ScrollUV2");
    gh.BeginTied();
    sFloatControl *float_ScrollUV2_0 = gh.Float(&para->ScrollUV2[0],-1024.00f,1024.000f,0.010000f);
    float_ScrollUV2_0->Default = 0.000000f; float_ScrollUV2_0->RightStep = 0.125000f;
    sFloatControl *float_ScrollUV2_1 = gh.Float(&para->ScrollUV2[1],-1024.00f,1024.000f,0.010000f);
    float_ScrollUV2_1->Default = 0.000000f; float_ScrollUV2_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefLayer2D(wOp *op)
{
  Wz4RenderParaLayer2D sUNUSED *para = (Wz4RenderParaLayer2D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Center[0] = 0.500000f;
  para->Center[1] = 0.500000f;
  para->Size[0] = 1.000000f;
  para->Size[1] = 1.000000f;
  para->ScaleUV[0] = 1.000000f;
  para->ScaleUV[1] = 1.000000f;
  para->Color = 0xffffffff;
  para->Align = 0x00000005;
  para->ScaleUV2[0] = 1.000000f;
  para->ScaleUV2[1] = 1.000000f;
}

void Wz4RenderBindLayer2D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scaleuv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scaleuv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scrolluv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scrolluv"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"scaleuv2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"scaleuv2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"scrolluv2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"scrolluv2"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Layer2D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[19];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"center");
    name[2] = sPoolString(L"size");
    name[3] = sPoolString(L"scaleuv");
    name[4] = sPoolString(L"scrolluv");
    name[5] = sPoolString(L"color_");
    name[6] = sPoolString(L"modes");
    name[7] = sPoolString(L"aspect");
    name[8] = sPoolString(L"aspect");
    name[9] = sPoolString(L"blend");
    name[10] = sPoolString(L"align");
    name[11] = sPoolString(L"filter");
    name[12] = sPoolString(L"");
    name[13] = sPoolString(L"secondtexture");
    name[14] = sPoolString(L"mix");
    name[15] = sPoolString(L"scaleuv2");
    name[16] = sPoolString(L"scrolluv2");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeFloat,2,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeColor,1,cmd->Data+9);
  ctx->AddImport(name[15],ScriptTypeFloat,2,cmd->Data+15);
  ctx->AddImport(name[16],ScriptTypeFloat,2,cmd->Data+17);
  ctx->AddImport(name[18],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Layer2D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import center : float[2];\n");
  tb.PrintF(L"  import size : float[2];\n");
  tb.PrintF(L"  import scaleuv : float[2];\n");
  tb.PrintF(L"  import scrolluv : float[2];\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import scaleuv2 : float[2];\n");
  tb.PrintF(L"  import scrolluv2 : float[2];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiLayer2D =
L"= Wz4Render : Layer2D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Layer2D\n"
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
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link SecondTexture\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScaleUV\n"
L" !i ScaleUV\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScrollUV\n"
L" !i ScrollUV\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aspect\n"
L" !i Aspect\n"
L" !i Square\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Image\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Size Ref\n"
L" !i Aspect\n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i image\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Blend\n"
L" !i Blend\n"
L" !i solid\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha premul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i addsmooth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha plain\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i monochrome\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add dest alpha\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add inv dest alpha\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i dest alpha from shader\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dest alpha unchanged\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dest alpha = 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dest alpha blend\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Align\n"
L" !i Align\n"
L" !i left\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i center\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i right\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i top\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i center\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bottom\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Filter\n"
L" !i Filter\n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bilinear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mirror\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_black\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_white\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SecondTexture\n"
L" !i SecondTexture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mix\n"
L" !i Mix\n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ScaleUV2\n"
L" !i ScaleUV2\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScrollUV2\n"
L" !i ScrollUV2\n"
L" !i float[2]\n"
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

sBool Wz4RenderCmdBeat(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBeat sUNUSED *para = (Wz4RenderParaBeat *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 1365 "wz4_demo2_ops.ops"

    RNBeat *node = new RNBeat();
    node->Init(para,cmd->ArrayCount,(Wz4RenderArrayBeat *)cmd->Array,cmd->Strings[0]);
    out->RootNode = node;
    cmd->Strings[0] = 0; // we don't want code..
    out->AddChilds(cmd,0);
  ;
#line 7379 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderArrBeat(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaBeat sUNUSED *para = (Wz4RenderParaBeat *)(op->EditData); para;
  Wz4RenderArrayBeat *e = (Wz4RenderArrayBeat *)(mem);
  e->Hex[0] = 0x00000000;
  e->Hex[1] = 0x00000000;
  e->Hex[2] = 0x00000000;
  e->Hex[3] = 0x00000000;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4RenderArrayBeat *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4RenderArrayBeat *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4RenderArrayBeat *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4RenderArrayBeat *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4RenderArrayBeat *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4RenderArrayBeat *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4RenderArrayBeat *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4RenderArrayBeat *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4RenderArrayBeat *)op->ArrayData[pos  ];
    }
  }
}

wCustomEditor *Wz4RenderCedBeat(wOp *op)
{
  return new Wz4BeatCed(op);
}

sInt Wz4RenderActBeat(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaBeat sUNUSED *para = (Wz4RenderParaBeat *)(op->EditData); para;
#line 1249 "wz4_demo2_ops.ops"

    if(code==1)
    {
      sInt beats = Doc->DocOptions.Beats;
      sInt lines = ((beats<<para->Tempo)+15)/16;
      sInt old = op->ArrayData.GetCount();

      if(lines>old)
      {
        for(sInt i=old;i<lines;i++)
          op->AddArray(i);
      }
      else if(lines<old)
      {
        for(sInt i=old-1;i>=lines;i--)
          op->RemArray(i);
      }
      Doc->Change(op);
      App->ChangeDoc();
    }
    else if(code==2)
    {
      if(para->Tempo<7)
      {
        para->Tempo++;
        sInt len = op->ArrayData.GetCount();

        for(sInt i=0;i<len;i++)
          op->AddArray(len+i);

        for(sInt i=len-1;i>=0;i--)
        {
          sU8 *s = (sU8 *) op->ArrayData[i];    s+=15;
          sU8 *d0 = (sU8 *) op->ArrayData[i*2+0]; d0+=15;
          sU8 *d1 = (sU8 *) op->ArrayData[i*2+1]; d1+=15;

          for(sInt j=0;j<8;j++)
          {
            *d1-- = 0;
            *d1-- = *s--;
          }
          for(sInt j=0;j<8;j++)
          {
            *d0-- = 0;
            *d0-- = *s--;
          }
        }
      }
      Doc->Change(op);
      App->ChangeDoc();
    }
    else if(code==3)
    {
      if(para->Tempo>0)
      {
        sU8 null[16];
        sSetMem(null,0,16);

        para->Tempo--;
        sInt oldlen = op->ArrayData.GetCount();
        sInt len = (oldlen+1)/2;

        for(sInt i=0;i<len;i++)
        {
          sU8 *s0 = (sU8 *) op->ArrayData[i*2+0];  
          sU8 *s1 = null;
          if(i*2+1<oldlen)
            s1 = (sU8 *) op->ArrayData[i*2+1];  
          sU8 *d = (sU8 *) op->ArrayData[i];

          for(sInt j=0;j<8;j++)
          {
            sU8 loop=0,level=0;

            if(s0[0]&RNB_LoopMask) loop=s0[0]&RNB_LoopMask;
            if(s0[1]&RNB_LoopMask) loop=s0[1]&RNB_LoopMask;
            level = sU8(sMax(s0[0]&RNB_LevelMask,s0[1]&RNB_LevelMask));

            *d++ = loop|level;
            s0+=2;
          }
          for(sInt j=0;j<8;j++)
          {
            sU8 loop=0,level=0;

            if(s1[0]&RNB_LoopMask) loop=s1[0]&RNB_LoopMask;
            if(s1[1]&RNB_LoopMask) loop=s1[1]&RNB_LoopMask;
            level = sU8(sMax(s1[0]&RNB_LevelMask,s1[1]&RNB_LevelMask));

            *d++ = loop|level;
            s1+=2;
          }
        }

        for(sInt i=oldlen-1;i>=len;i--)
          op->RemArray(i);
      }
      Doc->Change(op);
      App->ChangeDoc();
    }
    else if(code==4)
    {
      for(sInt i=0;i<=para->Levels;i++)
        (&para->Level0)[i*3] = sF32(i)/para->Levels;
      for(sInt i=para->Levels+1;i<16;i++)
        (&para->Level0)[i*3] = 1;
      Doc->Change(op);
      App->ChangeDoc();
    }
    else
    {
      return 0;
    }
    return 1;
  ;
#line 7544 "wz4_demo2_ops.cpp"
}

void Wz4RenderGuiBeat(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBeat sUNUSED *para = (Wz4RenderParaBeat *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);

  gh.Label(L"Tempo");
  gh.Flags(&para->Tempo,L" 1/1| 1/2 | 1/4| 1/8| 1/16| 1/32| 1/64| 1/128| 1/256",gh.ChangeMsg);

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Init",gh.ActionMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"DoubleSpeed",gh.ActionMsg);

  gh.ActionMsg.Code = 3;
  gh.PushButton(L"HalfSpeed",gh.ActionMsg);

  gh.Label(L"Levels");
  sIntControl *int_Levels = gh.Int(&para->Levels,2,15,0.125000f);
  int_Levels->Default = 0x00000002; int_Levels->RightStep = 0.125000f;
  int_Levels->DoneMsg = gh.LayoutMsg;

  gh.ActionMsg.Code = 4;
  gh.PushButton(L"MakeLevels",gh.ActionMsg);

  gh.Group(L"shape");

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"linear|spline:*4preattack|normal attack:*5-|individual control",gh.LayoutMsg);

  gh.Label(L"Attack");
  sFloatControl *float_Attack = gh.Float(&para->Attack,0.000000f,100.0000f,0.010000f);
  float_Attack->Default = 0.000000f; float_Attack->RightStep = 0.125000f;

  gh.Label(L"Release");
  sFloatControl *float_Release = gh.Float(&para->Release,0.000000f,100.0000f,0.010000f);
  float_Release->Default = 1.000000f; float_Release->RightStep = 0.125000f;

  gh.Group(L"scale");

  gh.Label(L"Amp");
  sFloatControl *float_Amp = gh.Float(&para->Amp,-1000.00f,1000.000f,0.001000f);
  float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;

  gh.Label(L"Bias");
  sFloatControl *float_Bias = gh.Float(&para->Bias,-1000.00f,1000.000f,0.001000f);
  float_Bias->Default = 0.000000f; float_Bias->RightStep = 0.125000f;

  gh.Label(L"Timeshift");
  sFloatControl *float_Timeshift = gh.Float(&para->Timeshift,-16.0000f,16.00000f,0.001000f);
  float_Timeshift->Default = 0.000000f; float_Timeshift->RightStep = 0.125000f;

  gh.Label(L"SplineFlags");
  gh.Flags(&para->SplineFlags,L"clamp|wrap|zero",gh.ChangeMsg);

  gh.Group(L"levels");

  if(0x0000)
  {
    gh.Label(L"Level0");
    sFloatControl *float_Level0 = gh.Float(&para->Level0,0.000000f,1.000000f,0.010000f);
    float_Level0->Default = 0.000000f; float_Level0->RightStep = 0.125000f;

  }
  if((0x0000&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att0 = gh.Float(&para->Att0,0.000000f,100.0000f,0.010000f);
    float_Att0->Default = 1.000000f; float_Att0->RightStep = 0.125000f;

    sFloatControl *float_Rel0 = gh.Float(&para->Rel0,0.000000f,100.0000f,0.010000f);
    float_Rel0->Default = 1.000000f; float_Rel0->RightStep = 0.125000f;

  }
  gh.Label(L"Level1");
  sFloatControl *float_Level1 = gh.Float(&para->Level1,0.000000f,1.000000f,0.010000f);
  float_Level1->Default = 0.500000f; float_Level1->RightStep = 0.125000f;

  if((para->Mode&0x0020))
  {
    sFloatControl *float_Att1 = gh.Float(&para->Att1,0.000000f,100.0000f,0.010000f);
    float_Att1->Default = 1.000000f; float_Att1->RightStep = 0.125000f;

    sFloatControl *float_Rel1 = gh.Float(&para->Rel1,0.000000f,100.0000f,0.010000f);
    float_Rel1->Default = 1.000000f; float_Rel1->RightStep = 0.125000f;

  }
  gh.Label(L"Level2");
  sFloatControl *float_Level2 = gh.Float(&para->Level2,0.000000f,1.000000f,0.010000f);
  float_Level2->Default = 1.000000f; float_Level2->RightStep = 0.125000f;

  if((para->Mode&0x0020))
  {
    sFloatControl *float_Att2 = gh.Float(&para->Att2,0.000000f,100.0000f,0.010000f);
    float_Att2->Default = 1.000000f; float_Att2->RightStep = 0.125000f;

    sFloatControl *float_Rel2 = gh.Float(&para->Rel2,0.000000f,100.0000f,0.010000f);
    float_Rel2->Default = 1.000000f; float_Rel2->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0003))
  {
    gh.Label(L"Level3");
    sFloatControl *float_Level3 = gh.Float(&para->Level3,0.000000f,1.000000f,0.010000f);
    float_Level3->Default = 1.000000f; float_Level3->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0003)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att3 = gh.Float(&para->Att3,0.000000f,100.0000f,0.010000f);
    float_Att3->Default = 1.000000f; float_Att3->RightStep = 0.125000f;

    sFloatControl *float_Rel3 = gh.Float(&para->Rel3,0.000000f,100.0000f,0.010000f);
    float_Rel3->Default = 1.000000f; float_Rel3->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0004))
  {
    gh.Label(L"Level4");
    sFloatControl *float_Level4 = gh.Float(&para->Level4,0.000000f,1.000000f,0.010000f);
    float_Level4->Default = 1.000000f; float_Level4->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0004)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att4 = gh.Float(&para->Att4,0.000000f,100.0000f,0.010000f);
    float_Att4->Default = 1.000000f; float_Att4->RightStep = 0.125000f;

    sFloatControl *float_Rel4 = gh.Float(&para->Rel4,0.000000f,100.0000f,0.010000f);
    float_Rel4->Default = 1.000000f; float_Rel4->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0005))
  {
    gh.Label(L"Level5");
    sFloatControl *float_Level5 = gh.Float(&para->Level5,0.000000f,1.000000f,0.010000f);
    float_Level5->Default = 1.000000f; float_Level5->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0005)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att5 = gh.Float(&para->Att5,0.000000f,100.0000f,0.010000f);
    float_Att5->Default = 1.000000f; float_Att5->RightStep = 0.125000f;

    sFloatControl *float_Rel5 = gh.Float(&para->Rel5,0.000000f,100.0000f,0.010000f);
    float_Rel5->Default = 1.000000f; float_Rel5->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0006))
  {
    gh.Label(L"Level6");
    sFloatControl *float_Level6 = gh.Float(&para->Level6,0.000000f,1.000000f,0.010000f);
    float_Level6->Default = 1.000000f; float_Level6->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0006)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att6 = gh.Float(&para->Att6,0.000000f,100.0000f,0.010000f);
    float_Att6->Default = 1.000000f; float_Att6->RightStep = 0.125000f;

    sFloatControl *float_Rel6 = gh.Float(&para->Rel6,0.000000f,100.0000f,0.010000f);
    float_Rel6->Default = 1.000000f; float_Rel6->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0007))
  {
    gh.Label(L"Level7");
    sFloatControl *float_Level7 = gh.Float(&para->Level7,0.000000f,1.000000f,0.010000f);
    float_Level7->Default = 1.000000f; float_Level7->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0007)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att7 = gh.Float(&para->Att7,0.000000f,100.0000f,0.010000f);
    float_Att7->Default = 1.000000f; float_Att7->RightStep = 0.125000f;

    sFloatControl *float_Rel7 = gh.Float(&para->Rel7,0.000000f,100.0000f,0.010000f);
    float_Rel7->Default = 1.000000f; float_Rel7->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0008))
  {
    gh.Label(L"Level8");
    sFloatControl *float_Level8 = gh.Float(&para->Level8,0.000000f,1.000000f,0.010000f);
    float_Level8->Default = 1.000000f; float_Level8->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0008)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att8 = gh.Float(&para->Att8,0.000000f,100.0000f,0.010000f);
    float_Att8->Default = 1.000000f; float_Att8->RightStep = 0.125000f;

    sFloatControl *float_Rel8 = gh.Float(&para->Rel8,0.000000f,100.0000f,0.010000f);
    float_Rel8->Default = 1.000000f; float_Rel8->RightStep = 0.125000f;

  }
  if((para->Levels>=0x0009))
  {
    gh.Label(L"Level9");
    sFloatControl *float_Level9 = gh.Float(&para->Level9,0.000000f,1.000000f,0.010000f);
    float_Level9->Default = 1.000000f; float_Level9->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x0009)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att9 = gh.Float(&para->Att9,0.000000f,100.0000f,0.010000f);
    float_Att9->Default = 1.000000f; float_Att9->RightStep = 0.125000f;

    sFloatControl *float_Rel9 = gh.Float(&para->Rel9,0.000000f,100.0000f,0.010000f);
    float_Rel9->Default = 1.000000f; float_Rel9->RightStep = 0.125000f;

  }
  if((para->Levels>=0x000a))
  {
    gh.Label(L"Level10");
    sFloatControl *float_Level10 = gh.Float(&para->Level10,0.000000f,1.000000f,0.010000f);
    float_Level10->Default = 1.000000f; float_Level10->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x000a)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att10 = gh.Float(&para->Att10,0.000000f,100.0000f,0.010000f);
    float_Att10->Default = 1.000000f; float_Att10->RightStep = 0.125000f;

    sFloatControl *float_Rel10 = gh.Float(&para->Rel10,0.000000f,100.0000f,0.010000f);
    float_Rel10->Default = 1.000000f; float_Rel10->RightStep = 0.125000f;

  }
  if((para->Levels>=0x000b))
  {
    gh.Label(L"Level11");
    sFloatControl *float_Level11 = gh.Float(&para->Level11,0.000000f,1.000000f,0.010000f);
    float_Level11->Default = 1.000000f; float_Level11->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x000b)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att11 = gh.Float(&para->Att11,0.000000f,100.0000f,0.010000f);
    float_Att11->Default = 1.000000f; float_Att11->RightStep = 0.125000f;

    sFloatControl *float_Rel11 = gh.Float(&para->Rel11,0.000000f,100.0000f,0.010000f);
    float_Rel11->Default = 1.000000f; float_Rel11->RightStep = 0.125000f;

  }
  if((para->Levels>=0x000c))
  {
    gh.Label(L"Level12");
    sFloatControl *float_Level12 = gh.Float(&para->Level12,0.000000f,1.000000f,0.010000f);
    float_Level12->Default = 1.000000f; float_Level12->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x000c)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att12 = gh.Float(&para->Att12,0.000000f,100.0000f,0.010000f);
    float_Att12->Default = 1.000000f; float_Att12->RightStep = 0.125000f;

    sFloatControl *float_Rel12 = gh.Float(&para->Rel12,0.000000f,100.0000f,0.010000f);
    float_Rel12->Default = 1.000000f; float_Rel12->RightStep = 0.125000f;

  }
  if((para->Levels>=0x000d))
  {
    gh.Label(L"Level13");
    sFloatControl *float_Level13 = gh.Float(&para->Level13,0.000000f,1.000000f,0.010000f);
    float_Level13->Default = 1.000000f; float_Level13->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x000d)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att13 = gh.Float(&para->Att13,0.000000f,100.0000f,0.010000f);
    float_Att13->Default = 1.000000f; float_Att13->RightStep = 0.125000f;

    sFloatControl *float_Rel13 = gh.Float(&para->Rel13,0.000000f,100.0000f,0.010000f);
    float_Rel13->Default = 1.000000f; float_Rel13->RightStep = 0.125000f;

  }
  if((para->Levels>=0x000e))
  {
    gh.Label(L"Level14");
    sFloatControl *float_Level14 = gh.Float(&para->Level14,0.000000f,1.000000f,0.010000f);
    float_Level14->Default = 1.000000f; float_Level14->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x000e)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att14 = gh.Float(&para->Att14,0.000000f,100.0000f,0.010000f);
    float_Att14->Default = 1.000000f; float_Att14->RightStep = 0.125000f;

    sFloatControl *float_Rel14 = gh.Float(&para->Rel14,0.000000f,100.0000f,0.010000f);
    float_Rel14->Default = 1.000000f; float_Rel14->RightStep = 0.125000f;

  }
  if((para->Levels>=0x000f))
  {
    gh.Label(L"Level15");
    sFloatControl *float_Level15 = gh.Float(&para->Level15,0.000000f,1.000000f,0.010000f);
    float_Level15->Default = 1.000000f; float_Level15->RightStep = 0.125000f;

  }
  if(((para->Levels>=0x000f)&&(para->Mode&0x0020)))
  {
    sFloatControl *float_Att15 = gh.Float(&para->Att15,0.000000f,100.0000f,0.010000f);
    float_Att15->Default = 1.000000f; float_Att15->RightStep = 0.125000f;

    sFloatControl *float_Rel15 = gh.Float(&para->Rel15,0.000000f,100.0000f,0.010000f);
    float_Rel15->Default = 1.000000f; float_Rel15->RightStep = 0.125000f;
  }
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Hex",pos,gh.Line,4,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=4;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArrayBeat *elem = (Wz4RenderArrayBeat *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    gh.BeginTied();
    sIntControl *int_Hex_0 = gh.Int(&elem->Hex[0],0,2139062144,0.125000f,0,L"%08x");
    int_Hex_0->Default = 0x00000000; int_Hex_0->RightStep = 0.125000f;
    sIntControl *int_Hex_1 = gh.Int(&elem->Hex[1],0,2139062144,0.125000f,0,L"%08x");
    int_Hex_1->Default = 0x00000000; int_Hex_1->RightStep = 0.125000f;
    sIntControl *int_Hex_2 = gh.Int(&elem->Hex[2],0,2139062144,0.125000f,0,L"%08x");
    int_Hex_2->Default = 0x00000000; int_Hex_2->RightStep = 0.125000f;
    sIntControl *int_Hex_3 = gh.Int(&elem->Hex[3],0,2139062144,0.125000f,0,L"%08x");
    int_Hex_3->Default = 0x00000000; int_Hex_3->RightStep = 0.125000f;
    gh.EndTied();
      if(hidesome)
      {
        gh.RemArrayGroupMsg.Code = _i;
        gh.Box(L"Rem",gh.RemArrayGroupMsg);
      }
      else
      {
        gh.AddArrayMsg.Code = _i;
        gh.RemArrayMsg.Code = _i;
        gh.Box(L"Add",gh.AddArrayMsg,sGFLF_HALFUP);
        gh.Box(L"Rem",gh.RemArrayMsg)->InitRadio(&op->HighlightArrayLine,_i);
      }
      if(gh.Left<gh.Right && !(_i&1)) gh.Grid->AddLabel(0,gh.Left,gh.Line,gh.Right-gh.Left,1,sGFLF_LEAD);
      gh.NextLine();
    }
    gh.AddArrayMsg.Code = op->ArrayData.GetCount();
    if(!hidesome)
      gh.Box(L"Add",gh.AddArrayMsg,sGFLF_HALFUP);
  }
}

void Wz4RenderDefBeat(wOp *op)
{
  Wz4RenderParaBeat sUNUSED *para = (Wz4RenderParaBeat *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Levels = 0x00000002;
  para->Release = 1.000000f;
  para->Amp = 1.000000f;
  para->Att0 = 1.000000f;
  para->Rel0 = 1.000000f;
  para->Level1 = 0.500000f;
  para->Att1 = 1.000000f;
  para->Rel1 = 1.000000f;
  para->Level2 = 1.000000f;
  para->Att2 = 1.000000f;
  para->Rel2 = 1.000000f;
  para->Level3 = 1.000000f;
  para->Att3 = 1.000000f;
  para->Rel3 = 1.000000f;
  para->Level4 = 1.000000f;
  para->Att4 = 1.000000f;
  para->Rel4 = 1.000000f;
  para->Level5 = 1.000000f;
  para->Att5 = 1.000000f;
  para->Rel5 = 1.000000f;
  para->Level6 = 1.000000f;
  para->Att6 = 1.000000f;
  para->Rel6 = 1.000000f;
  para->Level7 = 1.000000f;
  para->Att7 = 1.000000f;
  para->Rel7 = 1.000000f;
  para->Level8 = 1.000000f;
  para->Att8 = 1.000000f;
  para->Rel8 = 1.000000f;
  para->Level9 = 1.000000f;
  para->Att9 = 1.000000f;
  para->Rel9 = 1.000000f;
  para->Level10 = 1.000000f;
  para->Att10 = 1.000000f;
  para->Rel10 = 1.000000f;
  para->Level11 = 1.000000f;
  para->Att11 = 1.000000f;
  para->Rel11 = 1.000000f;
  para->Level12 = 1.000000f;
  para->Att12 = 1.000000f;
  para->Rel12 = 1.000000f;
  para->Level13 = 1.000000f;
  para->Att13 = 1.000000f;
  para->Rel13 = 1.000000f;
  para->Level14 = 1.000000f;
  para->Att14 = 1.000000f;
  para->Rel14 = 1.000000f;
  para->Level15 = 1.000000f;
  para->Att15 = 1.000000f;
  para->Rel15 = 1.000000f;
}

void Wz4RenderBindBeat(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+59;
  ctx->BindLocal(ctx->AddSymbol(L"levels"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"attack"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+52;
  ctx->BindLocal(ctx->AddSymbol(L"release"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+53;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+55;
  ctx->BindLocal(ctx->AddSymbol(L"timeshift"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"level0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"att0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"rel0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"level1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"att1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"rel1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"level2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"att2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"rel2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"level3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"att3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"rel3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"level4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"att4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"rel4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"level5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"att5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"rel5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"level6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"att6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"rel6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"level7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"att7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"rel7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"level8"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"att8"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"rel8"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"level9"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"att9"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"rel9"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"level10"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"att10"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"rel10"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"level11"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"att11"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"rel11"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"level12"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"att12"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"rel12"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"level13"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"att13"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+41;
  ctx->BindLocal(ctx->AddSymbol(L"rel13"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"level14"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+43;
  ctx->BindLocal(ctx->AddSymbol(L"att14"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+44;
  ctx->BindLocal(ctx->AddSymbol(L"rel14"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"level15"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+46;
  ctx->BindLocal(ctx->AddSymbol(L"att15"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+47;
  ctx->BindLocal(ctx->AddSymbol(L"rel15"),val);
}
void Wz4RenderBind2Beat(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[65];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"name");
    name[1] = sPoolString(L"tempo");
    name[2] = sPoolString(L"init");
    name[3] = sPoolString(L"doublespeed");
    name[4] = sPoolString(L"halfspeed");
    name[5] = sPoolString(L"levels");
    name[6] = sPoolString(L"makelevels");
    name[7] = sPoolString(L"shape");
    name[8] = sPoolString(L"mode");
    name[9] = sPoolString(L"attack");
    name[10] = sPoolString(L"release");
    name[11] = sPoolString(L"scale");
    name[12] = sPoolString(L"amp");
    name[13] = sPoolString(L"bias");
    name[14] = sPoolString(L"timeshift");
    name[15] = sPoolString(L"splineflags");
    name[16] = sPoolString(L"levels");
    name[17] = sPoolString(L"level0");
    name[18] = sPoolString(L"att0");
    name[19] = sPoolString(L"rel0");
    name[20] = sPoolString(L"level1");
    name[21] = sPoolString(L"att1");
    name[22] = sPoolString(L"rel1");
    name[23] = sPoolString(L"level2");
    name[24] = sPoolString(L"att2");
    name[25] = sPoolString(L"rel2");
    name[26] = sPoolString(L"level3");
    name[27] = sPoolString(L"att3");
    name[28] = sPoolString(L"rel3");
    name[29] = sPoolString(L"level4");
    name[30] = sPoolString(L"att4");
    name[31] = sPoolString(L"rel4");
    name[32] = sPoolString(L"level5");
    name[33] = sPoolString(L"att5");
    name[34] = sPoolString(L"rel5");
    name[35] = sPoolString(L"level6");
    name[36] = sPoolString(L"att6");
    name[37] = sPoolString(L"rel6");
    name[38] = sPoolString(L"level7");
    name[39] = sPoolString(L"att7");
    name[40] = sPoolString(L"rel7");
    name[41] = sPoolString(L"level8");
    name[42] = sPoolString(L"att8");
    name[43] = sPoolString(L"rel8");
    name[44] = sPoolString(L"level9");
    name[45] = sPoolString(L"att9");
    name[46] = sPoolString(L"rel9");
    name[47] = sPoolString(L"level10");
    name[48] = sPoolString(L"att10");
    name[49] = sPoolString(L"rel10");
    name[50] = sPoolString(L"level11");
    name[51] = sPoolString(L"att11");
    name[52] = sPoolString(L"rel11");
    name[53] = sPoolString(L"level12");
    name[54] = sPoolString(L"att12");
    name[55] = sPoolString(L"rel12");
    name[56] = sPoolString(L"level13");
    name[57] = sPoolString(L"att13");
    name[58] = sPoolString(L"rel13");
    name[59] = sPoolString(L"level14");
    name[60] = sPoolString(L"att14");
    name[61] = sPoolString(L"rel14");
    name[62] = sPoolString(L"level15");
    name[63] = sPoolString(L"att15");
    name[64] = sPoolString(L"rel15");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+59);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+51);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+52);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+53);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+54);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+55);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[26],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[27],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[28],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[29],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[30],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[31],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[32],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[33],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[34],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[35],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[36],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[37],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[38],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[39],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[40],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[41],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[42],ScriptTypeFloat,1,cmd->Data+25);
  ctx->AddImport(name[43],ScriptTypeFloat,1,cmd->Data+26);
  ctx->AddImport(name[44],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[45],ScriptTypeFloat,1,cmd->Data+28);
  ctx->AddImport(name[46],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[47],ScriptTypeFloat,1,cmd->Data+30);
  ctx->AddImport(name[48],ScriptTypeFloat,1,cmd->Data+31);
  ctx->AddImport(name[49],ScriptTypeFloat,1,cmd->Data+32);
  ctx->AddImport(name[50],ScriptTypeFloat,1,cmd->Data+33);
  ctx->AddImport(name[51],ScriptTypeFloat,1,cmd->Data+34);
  ctx->AddImport(name[52],ScriptTypeFloat,1,cmd->Data+35);
  ctx->AddImport(name[53],ScriptTypeFloat,1,cmd->Data+36);
  ctx->AddImport(name[54],ScriptTypeFloat,1,cmd->Data+37);
  ctx->AddImport(name[55],ScriptTypeFloat,1,cmd->Data+38);
  ctx->AddImport(name[56],ScriptTypeFloat,1,cmd->Data+39);
  ctx->AddImport(name[57],ScriptTypeFloat,1,cmd->Data+40);
  ctx->AddImport(name[58],ScriptTypeFloat,1,cmd->Data+41);
  ctx->AddImport(name[59],ScriptTypeFloat,1,cmd->Data+42);
  ctx->AddImport(name[60],ScriptTypeFloat,1,cmd->Data+43);
  ctx->AddImport(name[61],ScriptTypeFloat,1,cmd->Data+44);
  ctx->AddImport(name[62],ScriptTypeFloat,1,cmd->Data+45);
  ctx->AddImport(name[63],ScriptTypeFloat,1,cmd->Data+46);
  ctx->AddImport(name[64],ScriptTypeFloat,1,cmd->Data+47);
}
void Wz4RenderBind3Beat(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
  tb.PrintF(L"  import levels : int;\n");
  tb.PrintF(L"  import attack : float;\n");
  tb.PrintF(L"  import release : float;\n");
  tb.PrintF(L"  import amp : float;\n");
  tb.PrintF(L"  import bias : float;\n");
  tb.PrintF(L"  import timeshift : float;\n");
  tb.PrintF(L"  import level0 : float;\n");
  tb.PrintF(L"  import att0 : float;\n");
  tb.PrintF(L"  import rel0 : float;\n");
  tb.PrintF(L"  import level1 : float;\n");
  tb.PrintF(L"  import att1 : float;\n");
  tb.PrintF(L"  import rel1 : float;\n");
  tb.PrintF(L"  import level2 : float;\n");
  tb.PrintF(L"  import att2 : float;\n");
  tb.PrintF(L"  import rel2 : float;\n");
  tb.PrintF(L"  import level3 : float;\n");
  tb.PrintF(L"  import att3 : float;\n");
  tb.PrintF(L"  import rel3 : float;\n");
  tb.PrintF(L"  import level4 : float;\n");
  tb.PrintF(L"  import att4 : float;\n");
  tb.PrintF(L"  import rel4 : float;\n");
  tb.PrintF(L"  import level5 : float;\n");
  tb.PrintF(L"  import att5 : float;\n");
  tb.PrintF(L"  import rel5 : float;\n");
  tb.PrintF(L"  import level6 : float;\n");
  tb.PrintF(L"  import att6 : float;\n");
  tb.PrintF(L"  import rel6 : float;\n");
  tb.PrintF(L"  import level7 : float;\n");
  tb.PrintF(L"  import att7 : float;\n");
  tb.PrintF(L"  import rel7 : float;\n");
  tb.PrintF(L"  import level8 : float;\n");
  tb.PrintF(L"  import att8 : float;\n");
  tb.PrintF(L"  import rel8 : float;\n");
  tb.PrintF(L"  import level9 : float;\n");
  tb.PrintF(L"  import att9 : float;\n");
  tb.PrintF(L"  import rel9 : float;\n");
  tb.PrintF(L"  import level10 : float;\n");
  tb.PrintF(L"  import att10 : float;\n");
  tb.PrintF(L"  import rel10 : float;\n");
  tb.PrintF(L"  import level11 : float;\n");
  tb.PrintF(L"  import att11 : float;\n");
  tb.PrintF(L"  import rel11 : float;\n");
  tb.PrintF(L"  import level12 : float;\n");
  tb.PrintF(L"  import att12 : float;\n");
  tb.PrintF(L"  import rel12 : float;\n");
  tb.PrintF(L"  import level13 : float;\n");
  tb.PrintF(L"  import att13 : float;\n");
  tb.PrintF(L"  import rel13 : float;\n");
  tb.PrintF(L"  import level14 : float;\n");
  tb.PrintF(L"  import att14 : float;\n");
  tb.PrintF(L"  import rel14 : float;\n");
  tb.PrintF(L"  import level15 : float;\n");
  tb.PrintF(L"  import att15 : float;\n");
  tb.PrintF(L"  import rel15 : float;\n");
}
const sChar *Wz4RenderWikiBeat =
L"= Wz4Render : Beat\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Beat\n"
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
L" !i Wz4Render\n"
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
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Tempo\n"
L" !i Tempo\n"
L" !i 1/1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/2 \n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/256\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Init\n"
L" !i Init\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i DoubleSpeed\n"
L" !i DoubleSpeed\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i HalfSpeed\n"
L" !i HalfSpeed\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Levels\n"
L" !i Levels\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MakeLevels\n"
L" !i MakeLevels\n"
L" !i action\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spline\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i preattack\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal attack\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i individual control\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Attack\n"
L" !i Attack\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Release\n"
L" !i Release\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Timeshift\n"
L" !i Timeshift\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i SplineFlags\n"
L" !i SplineFlags\n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i wrap\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zero\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Level0\n"
L" !i Level0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att0\n"
L" !i Att0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel0\n"
L" !i Rel0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level1\n"
L" !i Level1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att1\n"
L" !i Att1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel1\n"
L" !i Rel1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level2\n"
L" !i Level2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att2\n"
L" !i Att2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel2\n"
L" !i Rel2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level3\n"
L" !i Level3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att3\n"
L" !i Att3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel3\n"
L" !i Rel3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level4\n"
L" !i Level4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att4\n"
L" !i Att4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel4\n"
L" !i Rel4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level5\n"
L" !i Level5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att5\n"
L" !i Att5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel5\n"
L" !i Rel5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level6\n"
L" !i Level6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att6\n"
L" !i Att6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel6\n"
L" !i Rel6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level7\n"
L" !i Level7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att7\n"
L" !i Att7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel7\n"
L" !i Rel7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level8\n"
L" !i Level8\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att8\n"
L" !i Att8\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel8\n"
L" !i Rel8\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level9\n"
L" !i Level9\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att9\n"
L" !i Att9\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel9\n"
L" !i Rel9\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level10\n"
L" !i Level10\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att10\n"
L" !i Att10\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel10\n"
L" !i Rel10\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level11\n"
L" !i Level11\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att11\n"
L" !i Att11\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel11\n"
L" !i Rel11\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level12\n"
L" !i Level12\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att12\n"
L" !i Att12\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel12\n"
L" !i Rel12\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level13\n"
L" !i Level13\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att13\n"
L" !i Att13\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel13\n"
L" !i Rel13\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level14\n"
L" !i Level14\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att14\n"
L" !i Att14\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel14\n"
L" !i Rel14\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level15\n"
L" !i Level15\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att15\n"
L" !i Att15\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel15\n"
L" !i Rel15\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"== Array Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Tempo\n"
L" !i Tempo\n"
L" !i 1/1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/2 \n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1/256\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Init\n"
L" !i Init\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i DoubleSpeed\n"
L" !i DoubleSpeed\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i HalfSpeed\n"
L" !i HalfSpeed\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Levels\n"
L" !i Levels\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MakeLevels\n"
L" !i MakeLevels\n"
L" !i action\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spline\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i preattack\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal attack\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i individual control\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Attack\n"
L" !i Attack\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Release\n"
L" !i Release\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Timeshift\n"
L" !i Timeshift\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i SplineFlags\n"
L" !i SplineFlags\n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i wrap\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zero\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Level0\n"
L" !i Level0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att0\n"
L" !i Att0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel0\n"
L" !i Rel0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level1\n"
L" !i Level1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att1\n"
L" !i Att1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel1\n"
L" !i Rel1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level2\n"
L" !i Level2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att2\n"
L" !i Att2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel2\n"
L" !i Rel2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level3\n"
L" !i Level3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att3\n"
L" !i Att3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel3\n"
L" !i Rel3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level4\n"
L" !i Level4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att4\n"
L" !i Att4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel4\n"
L" !i Rel4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level5\n"
L" !i Level5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att5\n"
L" !i Att5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel5\n"
L" !i Rel5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level6\n"
L" !i Level6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att6\n"
L" !i Att6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel6\n"
L" !i Rel6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level7\n"
L" !i Level7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att7\n"
L" !i Att7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel7\n"
L" !i Rel7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level8\n"
L" !i Level8\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att8\n"
L" !i Att8\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel8\n"
L" !i Rel8\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level9\n"
L" !i Level9\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att9\n"
L" !i Att9\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel9\n"
L" !i Rel9\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level10\n"
L" !i Level10\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att10\n"
L" !i Att10\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel10\n"
L" !i Rel10\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level11\n"
L" !i Level11\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att11\n"
L" !i Att11\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel11\n"
L" !i Rel11\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level12\n"
L" !i Level12\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att12\n"
L" !i Att12\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel12\n"
L" !i Rel12\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level13\n"
L" !i Level13\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att13\n"
L" !i Att13\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel13\n"
L" !i Rel13\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level14\n"
L" !i Level14\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att14\n"
L" !i Att14\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel14\n"
L" !i Rel14\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Level15\n"
L" !i Level15\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Att15\n"
L" !i Att15\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rel15\n"
L" !i Rel15\n"
L" !i float\n"
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

sBool Wz4RenderCmdBoneTrain(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBoneTrain sUNUSED *para = (Wz4RenderParaBoneTrain *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 1397 "wz4_demo2_ops.ops"

    RNBoneTrain *node = new RNBoneTrain();
    node->ParaBase = node->Para = *para;
    in0->Charge();
    node->Mesh = in0; in0->AddRef();
    node->Init(cmd->Strings[1]);
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 9151 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiBoneTrain(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBoneTrain sUNUSED *para = (Wz4RenderParaBoneTrain *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"SplineName");
  gh.String(op->EditString[1]);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"* Start");
  sFloatControl *float_Start = gh.Float(&para->Start,-4.00000f,4.000000f,0.010000f);
  float_Start->Default = 0.000000f; float_Start->RightStep = 0.125000f;

  gh.Label(L"* Length");
  sFloatControl *float_Length = gh.Float(&para->Length,-4.00000f,4.000000f,0.010000f);
  float_Length->Default = 1.000000f; float_Length->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"free|upvector|shear",gh.ChangeMsg);

  gh.Label(L"* UpVector");
  gh.BeginTied();
  sFloatControl *float_UpVector_0 = gh.Float(&para->UpVector.x,-16.0000f,16.00000f,0.001000f);
  float_UpVector_0->Default = 0.000000f; float_UpVector_0->RightStep = 0.125000f;
  sFloatControl *float_UpVector_1 = gh.Float(&para->UpVector.y,-16.0000f,16.00000f,0.001000f);
  float_UpVector_1->Default = 0.000000f; float_UpVector_1->RightStep = 0.125000f;
  sFloatControl *float_UpVector_2 = gh.Float(&para->UpVector.z,-16.0000f,16.00000f,0.001000f);
  float_UpVector_2->Default = 0.000000f; float_UpVector_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Twist");
  sFloatControl *float_Twist = gh.Float(&para->Twist,-1024.00f,1024.000f,0.001000f);
  float_Twist->Default = 0.000000f; float_Twist->RightStep = 0.125000f;

  gh.Label(L"* Twirl");
  sFloatControl *float_Twirl = gh.Float(&para->Twirl,-1024.00f,1024.000f,0.001000f);
  float_Twirl->Default = 0.000000f; float_Twirl->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefBoneTrain(wOp *op)
{
  Wz4RenderParaBoneTrain sUNUSED *para = (Wz4RenderParaBoneTrain *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Length = 1.000000f;
  para->Flags = 0x00000001;
}

void Wz4RenderBindBoneTrain(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"splinename"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"length"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"twist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"twirl"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2BoneTrain(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"splinename");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"lightenv");
    name[3] = sPoolString(L"start");
    name[4] = sPoolString(L"length");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"upvector");
    name[7] = sPoolString(L"twist");
    name[8] = sPoolString(L"twirl");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[10],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3BoneTrain(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import splinename : string;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import start : float;\n");
  tb.PrintF(L"  import length : float;\n");
  tb.PrintF(L"  import upvector : float[3];\n");
  tb.PrintF(L"  import twist : float;\n");
  tb.PrintF(L"  import twirl : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBoneTrain =
L"= Wz4Render : BoneTrain\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BoneTrain\n"
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
L" !i Wz4Mesh\n"
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
L" !i SplineName\n"
L" !i SplineName\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Start\n"
L" !i Start\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Length\n"
L" !i Length\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i free\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upvector\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shear\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UpVector\n"
L" !i UpVector\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Twist\n"
L" !i Twist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Twirl\n"
L" !i Twirl\n"
L" !i float\n"
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

sBool UnitTestCmdUnitTestWz4(wExecutive *exe,wCommand *cmd)
{
  UnitTestParaUnitTestWz4 sUNUSED *para = (UnitTestParaUnitTestWz4 *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  UnitTest *out = (UnitTest *) cmd->Output;
  if(!out) { out=new UnitTest; cmd->Output=out; }

  {
#line 1422 "wz4_demo2_ops.ops"

    sImage img;
    UnitTestWz4Render(img,para,in0);
    return out->Test(img,cmd->Strings[0],para->Flags);
  ;
#line 9415 "wz4_demo2_ops.cpp"
    return 1;
  }
}

void UnitTestGuiUnitTestWz4(wGridFrameHelper &gh,wOp *op)
{
  UnitTestParaUnitTestWz4 sUNUSED *para = (UnitTestParaUnitTestWz4 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"TestName");
  {
    sControl *con = gh.String(op->EditString[0]);
    con->DoneMsg = con->ChangeMsg;
    con->ChangeMsg = sMessage();
    gh.FileSaveDialogMsg.Code = 0;
    gh.Box(L"...",gh.FileSaveDialogMsg);
  }

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Always Pass");
  gh.Flags(&para->Flags,L"-|compare:*1-|cross compare",gh.ChangeMsg);
}

void UnitTestDefUnitTestWz4(wOp *op)
{
  UnitTestParaUnitTestWz4 sUNUSED *para = (UnitTestParaUnitTestWz4 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
}

void UnitTestBindUnitTestWz4(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"testname"),val);
}
void UnitTestBind2UnitTestWz4(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"testname");
    name[1] = sPoolString(L"size");
    name[2] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void UnitTestBind3UnitTestWz4(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import testname : string;\n");
}
const sChar *UnitTestWikiUnitTestWz4 =
L"= UnitTest : UnitTestWz4\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i UnitTestWz4\n"
L"\n"
L"  !i Output Type\n"
L"  !i UnitTest\n"
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
L" !i Wz4Render\n"
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
L" !i TestName\n"
L" !i TestName\n"
L" !i save file\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Size\n"
L" !i Size\n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
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
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Always Pass\n"
L" !i Flags\n"
L" !i compare\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i cross compare\n"
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

void Rendertarget2DAnimRendertarget2::Init(class ScriptContext *sc)
{
};

void Rendertarget2DAnimRendertarget2::Bind(class ScriptContext *sc,Rendertarget2DParaRendertarget2 *para)
{
};

void Wz4RenderAnimRender::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimRender::Bind(class ScriptContext *sc,Wz4RenderParaRender *para)
{
};

void Wz4RenderAnimRenderNull::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimRenderNull::Bind(class ScriptContext *sc,Wz4RenderParaRenderNull *para)
{
};

void Wz4RenderAnimCamera::Init(class ScriptContext *sc)
{
  _SplineTime = sc->AddSymbol(L"splinetime");
  _Position = sc->AddSymbol(L"position");
  _Target = sc->AddSymbol(L"target");
  _Rot = sc->AddSymbol(L"rot");
  _Distance = sc->AddSymbol(L"distance");
  _Tilt = sc->AddSymbol(L"tilt");
  _Zoom = sc->AddSymbol(L"zoom");
  _ClipNear = sc->AddSymbol(L"clipnear");
  _ClipFar = sc->AddSymbol(L"clipfar");
  _ClearColor = sc->AddSymbol(L"clearcolor");
};

void Wz4RenderAnimCamera::Bind(class ScriptContext *sc,Wz4RenderParaCamera *para)
{
  sc->BindLocalFloat(_SplineTime,1,&para->SplineTime);
  sc->BindLocalFloat(_Position,3,&para->Position.x);
  sc->BindLocalFloat(_Target,3,&para->Target.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Distance,1,&para->Distance);
  sc->BindLocalFloat(_Tilt,1,&para->Tilt);
  sc->BindLocalFloat(_Zoom,1,&para->Zoom);
  sc->BindLocalFloat(_ClipNear,1,&para->ClipNear);
  sc->BindLocalFloat(_ClipFar,1,&para->ClipFar);
  sc->BindLocalColor(_ClearColor,&para->ClearColor);
};

void Wz4RenderAnimBillboardCamera::Init(class ScriptContext *sc)
{
  _ClearColor = sc->AddSymbol(L"clearcolor");
  _Distance = sc->AddSymbol(L"distance");
  _Zoom = sc->AddSymbol(L"zoom");
  _ClipNear = sc->AddSymbol(L"clipnear");
  _ClipFar = sc->AddSymbol(L"clipfar");
};

void Wz4RenderAnimBillboardCamera::Bind(class ScriptContext *sc,Wz4RenderParaBillboardCamera *para)
{
  sc->BindLocalColor(_ClearColor,&para->ClearColor);
  sc->BindLocalFloat(_Distance,1,&para->Distance);
  sc->BindLocalFloat(_Zoom,1,&para->Zoom);
  sc->BindLocalFloat(_ClipNear,1,&para->ClipNear);
  sc->BindLocalFloat(_ClipFar,1,&para->ClipFar);
};

void GenBitmapAnimRender::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimRender::Bind(class ScriptContext *sc,GenBitmapParaRender *para)
{
};

void Wz4RenderAnimRenderMesh::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
  _BoneTime = sc->AddSymbol(L"bonetime");
};

void Wz4RenderAnimRenderMesh::Bind(class ScriptContext *sc,Wz4RenderParaRenderMesh *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_BoneTime,1,&para->BoneTime);
};

void Wz4RenderAnimMultiplyMesh::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
  _Count1 = sc->AddSymbol(L"count1");
  _Scale1 = sc->AddSymbol(L"scale1");
  _Rot1 = sc->AddSymbol(L"rot1");
  _Trans1 = sc->AddSymbol(L"trans1");
  _Count2 = sc->AddSymbol(L"count2");
  _Scale2 = sc->AddSymbol(L"scale2");
  _Rot2 = sc->AddSymbol(L"rot2");
  _Trans2 = sc->AddSymbol(L"trans2");
  _Count3 = sc->AddSymbol(L"count3");
  _Scale3 = sc->AddSymbol(L"scale3");
  _Rot3 = sc->AddSymbol(L"rot3");
  _Trans3 = sc->AddSymbol(L"trans3");
};

void Wz4RenderAnimMultiplyMesh::Bind(class ScriptContext *sc,Wz4RenderParaMultiplyMesh *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalInt(_Count1,1,&para->Count1);
  sc->BindLocalFloat(_Scale1,3,&para->Scale1.x);
  sc->BindLocalFloat(_Rot1,3,&para->Rot1.x);
  sc->BindLocalFloat(_Trans1,3,&para->Trans1.x);
  sc->BindLocalInt(_Count2,1,&para->Count2);
  sc->BindLocalFloat(_Scale2,3,&para->Scale2.x);
  sc->BindLocalFloat(_Rot2,3,&para->Rot2.x);
  sc->BindLocalFloat(_Trans2,3,&para->Trans2.x);
  sc->BindLocalInt(_Count3,1,&para->Count3);
  sc->BindLocalFloat(_Scale3,3,&para->Scale3.x);
  sc->BindLocalFloat(_Rot3,3,&para->Rot3.x);
  sc->BindLocalFloat(_Trans3,3,&para->Trans3.x);
};

void Wz4RenderAnimScript::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimScript::Bind(class ScriptContext *sc,Wz4RenderParaScript *para)
{
};

void Wz4RenderAnimTransform::Init(class ScriptContext *sc)
{
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
};

void Wz4RenderAnimTransform::Bind(class ScriptContext *sc,Wz4RenderParaTransform *para)
{
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
};

void Wz4RenderAnimTransformPivot::Init(class ScriptContext *sc)
{
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
  _Pivot = sc->AddSymbol(L"pivot");
};

void Wz4RenderAnimTransformPivot::Bind(class ScriptContext *sc,Wz4RenderParaTransformPivot *para)
{
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Pivot,3,&para->Pivot.x);
};

void Wz4RenderAnimSplinedObject::Init(class ScriptContext *sc)
{
  _Tick = sc->AddSymbol(L"tick");
  _TimeDelta = sc->AddSymbol(L"timedelta");
};

void Wz4RenderAnimSplinedObject::Bind(class ScriptContext *sc,Wz4RenderParaSplinedObject *para)
{
  sc->BindLocalFloat(_Tick,1,&para->Tick);
  sc->BindLocalFloat(_TimeDelta,1,&para->TimeDelta);
};

void Wz4RenderAnimLookAt::Init(class ScriptContext *sc)
{
  _Pos = sc->AddSymbol(L"pos");
  _Target = sc->AddSymbol(L"target");
  _UpVector = sc->AddSymbol(L"upvector");
  _Tilt = sc->AddSymbol(L"tilt");
};

void Wz4RenderAnimLookAt::Bind(class ScriptContext *sc,Wz4RenderParaLookAt *para)
{
  sc->BindLocalFloat(_Pos,3,&para->Pos.x);
  sc->BindLocalFloat(_Target,3,&para->Target.x);
  sc->BindLocalFloat(_UpVector,3,&para->UpVector.x);
  sc->BindLocalFloat(_Tilt,1,&para->Tilt);
};

void Wz4RenderAnimSkyCube::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimSkyCube::Bind(class ScriptContext *sc,Wz4RenderParaSkyCube *para)
{
};

void Wz4RenderAnimShaker::Init(class ScriptContext *sc)
{
  _Animate = sc->AddSymbol(L"animate");
  _Center = sc->AddSymbol(L"center");
  _Amp = sc->AddSymbol(L"amp");
  _TimeRange = sc->AddSymbol(L"timerange");
  _TranslateAmp = sc->AddSymbol(L"translateamp");
  _TranslateFreq = sc->AddSymbol(L"translatefreq");
  _RotateAmp = sc->AddSymbol(L"rotateamp");
  _RotateFreq = sc->AddSymbol(L"rotatefreq");
};

void Wz4RenderAnimShaker::Bind(class ScriptContext *sc,Wz4RenderParaShaker *para)
{
  sc->BindLocalFloat(_Animate,1,&para->Animate);
  sc->BindLocalFloat(_Center,3,&para->Center.x);
  sc->BindLocalFloat(_Amp,1,&para->Amp);
  sc->BindLocalFloat(_TimeRange,2,para->TimeRange);
  sc->BindLocalFloat(_TranslateAmp,3,&para->TranslateAmp.x);
  sc->BindLocalFloat(_TranslateFreq,3,&para->TranslateFreq.x);
  sc->BindLocalFloat(_RotateAmp,3,&para->RotateAmp.x);
  sc->BindLocalFloat(_RotateFreq,3,&para->RotateFreq.x);
};

void Wz4RenderAnimMultiply::Init(class ScriptContext *sc)
{
  _PreScale = sc->AddSymbol(L"prescale");
  _PreRot = sc->AddSymbol(L"prerot");
  _PreTrans = sc->AddSymbol(L"pretrans");
  _Count = sc->AddSymbol(L"count");
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
};

void Wz4RenderAnimMultiply::Bind(class ScriptContext *sc,Wz4RenderParaMultiply *para)
{
  sc->BindLocalFloat(_PreScale,3,&para->PreScale.x);
  sc->BindLocalFloat(_PreRot,3,&para->PreRot.x);
  sc->BindLocalFloat(_PreTrans,3,&para->PreTrans.x);
  sc->BindLocalInt(_Count,1,&para->Count);
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
};

void Wz4RenderAnimClip::Init(class ScriptContext *sc)
{
  _Enable = sc->AddSymbol(L"enable");
};

void Wz4RenderAnimClip::Bind(class ScriptContext *sc,Wz4RenderParaClip *para)
{
  sc->BindLocalInt(_Enable,1,&para->Enable);
};

void Wz4RenderAnimClipRandomizer::Init(class ScriptContext *sc)
{
  _Enable = sc->AddSymbol(L"enable");
};

void Wz4RenderAnimClipRandomizer::Bind(class ScriptContext *sc,Wz4RenderParaClipRandomizer *para)
{
  sc->BindLocalInt(_Enable,1,&para->Enable);
};

void Wz4RenderAnimClipRandDuration::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimClipRandDuration::Bind(class ScriptContext *sc,Wz4RenderParaClipRandDuration *para)
{
};

void Wz4RenderAnimMultiClip::Init(class ScriptContext *sc)
{
  _MasterEnable = sc->AddSymbol(L"masterenable");
};

void Wz4RenderAnimMultiClip::Bind(class ScriptContext *sc,Wz4RenderParaMultiClip *para)
{
  sc->BindLocalInt(_MasterEnable,1,&para->MasterEnable);
};

void Wz4RenderAnimFader::Init(class ScriptContext *sc)
{
  _FaderA = sc->AddSymbol(L"fadera");
  _FaderB = sc->AddSymbol(L"faderb");
  _RotorA = sc->AddSymbol(L"rotora");
  _RotorB = sc->AddSymbol(L"rotorb");
};

void Wz4RenderAnimFader::Bind(class ScriptContext *sc,Wz4RenderParaFader *para)
{
  sc->BindLocalFloat(_FaderA,4,&para->FaderA.x);
  sc->BindLocalFloat(_FaderB,4,&para->FaderB.x);
  sc->BindLocalFloat(_RotorA,4,&para->RotorA.x);
  sc->BindLocalFloat(_RotorB,4,&para->RotorB.x);
};

void Wz4RenderAnimFader2::Init(class ScriptContext *sc)
{
  _FaderA = sc->AddSymbol(L"fadera");
  _FaderB = sc->AddSymbol(L"faderb");
  _RotorA = sc->AddSymbol(L"rotora");
  _RotorB = sc->AddSymbol(L"rotorb");
};

void Wz4RenderAnimFader2::Bind(class ScriptContext *sc,Wz4RenderParaFader2 *para)
{
  sc->BindLocalFloat(_FaderA,4,&para->FaderA.x);
  sc->BindLocalFloat(_FaderB,4,&para->FaderB.x);
  sc->BindLocalFloat(_RotorA,4,&para->RotorA.x);
  sc->BindLocalFloat(_RotorB,4,&para->RotorB.x);
};

void Wz4RenderAnimVariable::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimVariable::Bind(class ScriptContext *sc,Wz4RenderParaVariable *para)
{
};

void Wz4RenderAnimSpline::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimSpline::Bind(class ScriptContext *sc,Wz4RenderParaSpline *para)
{
};

void Wz4RenderAnimLayer2D::Init(class ScriptContext *sc)
{
  _Center = sc->AddSymbol(L"center");
  _Size = sc->AddSymbol(L"size");
  _ScaleUV = sc->AddSymbol(L"scaleuv");
  _ScrollUV = sc->AddSymbol(L"scrolluv");
  _Color = sc->AddSymbol(L"color_");
  _ScaleUV2 = sc->AddSymbol(L"scaleuv2");
  _ScrollUV2 = sc->AddSymbol(L"scrolluv2");
};

void Wz4RenderAnimLayer2D::Bind(class ScriptContext *sc,Wz4RenderParaLayer2D *para)
{
  sc->BindLocalFloat(_Center,2,para->Center);
  sc->BindLocalFloat(_Size,2,para->Size);
  sc->BindLocalFloat(_ScaleUV,2,para->ScaleUV);
  sc->BindLocalFloat(_ScrollUV,2,para->ScrollUV);
  sc->BindLocalColor(_Color,&para->Color);
  sc->BindLocalFloat(_ScaleUV2,2,para->ScaleUV2);
  sc->BindLocalFloat(_ScrollUV2,2,para->ScrollUV2);
};

void Wz4RenderAnimBeat::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimBeat::Bind(class ScriptContext *sc,Wz4RenderParaBeat *para)
{
};

void Wz4RenderAnimBoneTrain::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
  _Start = sc->AddSymbol(L"start");
  _Length = sc->AddSymbol(L"length");
  _UpVector = sc->AddSymbol(L"upvector");
  _Twist = sc->AddSymbol(L"twist");
  _Twirl = sc->AddSymbol(L"twirl");
};

void Wz4RenderAnimBoneTrain::Bind(class ScriptContext *sc,Wz4RenderParaBoneTrain *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_Start,1,&para->Start);
  sc->BindLocalFloat(_Length,1,&para->Length);
  sc->BindLocalFloat(_UpVector,3,&para->UpVector.x);
  sc->BindLocalFloat(_Twist,1,&para->Twist);
  sc->BindLocalFloat(_Twirl,1,&para->Twirl);
};

void UnitTestAnimUnitTestWz4::Init(class ScriptContext *sc)
{
};

void UnitTestAnimUnitTestWz4::Bind(class ScriptContext *sc,UnitTestParaUnitTestWz4 *para)
{
};


/****************************************************************************/

void AddTypes_wz4_demo2_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4RenderType = new Wz4RenderType_);
  Wz4RenderType->Secondary = secondary;
  Wz4RenderType->ColumnHeaders[0] = L"system";
  Wz4RenderType->ColumnHeaders[1] = L"effects";
  Wz4RenderType->ColumnHeaders[2] = L"part render";
  Wz4RenderType->ColumnHeaders[3] = L"part node";
  Wz4RenderType->ColumnHeaders[4] = L"ipp";

  Doc->Types.AddTail(Wz4ParticlesType = new Wz4ParticlesType_);
  Wz4ParticlesType->Secondary = secondary;

  Doc->Types.AddTail(Rendertarget2DType = new Rendertarget2DType_);
  Rendertarget2DType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_demo2_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Rendertarget2";
  cl->Label = L"Rendertarget";
  cl->OutputType = Rendertarget2DType;
  cl->TabType = Rendertarget2DType;
  cl->Command = Rendertarget2DCmdRendertarget2;
  cl->MakeGui = Rendertarget2DGuiRendertarget2;
  cl->SetDefaults = Rendertarget2DDefRendertarget2;
  cl->BindPara = Rendertarget2DBindRendertarget2;
  cl->Bind2Para = Rendertarget2DBind2Rendertarget2;
  cl->Bind3Para = Rendertarget2DBind3Rendertarget2;
  cl->WikiText = Rendertarget2DWikiRendertarget2;
  cl->ParaWords = 8;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Render";
  cl->Label = L"Add";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdRender;
  cl->MakeGui = Wz4RenderGuiRender;
  cl->SetDefaults = Wz4RenderDefRender;
  cl->BindPara = Wz4RenderBindRender;
  cl->Bind2Para = Wz4RenderBind2Render;
  cl->Bind3Para = Wz4RenderBind3Render;
  cl->WikiText = Wz4RenderWikiRender;
  cl->ParaStrings = 1;
  cl->Shortcut = 'a';
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"RenderNull";
  cl->Label = L"Null";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdRenderNull;
  cl->MakeGui = Wz4RenderGuiRenderNull;
  cl->SetDefaults = Wz4RenderDefRenderNull;
  cl->BindPara = Wz4RenderBindRenderNull;
  cl->Bind2Para = Wz4RenderBind2RenderNull;
  cl->Bind3Para = Wz4RenderBind3RenderNull;
  cl->WikiText = Wz4RenderWikiRenderNull;
  cl->ParaStrings = 1;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Camera";
  cl->Label = L"Camera";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCamera;
  cl->MakeGui = Wz4RenderGuiCamera;
  cl->SetDefaults = Wz4RenderDefCamera;
  cl->BindPara = Wz4RenderBindCamera;
  cl->Bind2Para = Wz4RenderBind2Camera;
  cl->Bind3Para = Wz4RenderBind3Camera;
  cl->WikiText = Wz4RenderWikiCamera;
  cl->Handles = Wz4RenderHndCamera;
  cl->Actions = Wz4RenderActCamera;
  cl->ParaStrings = 2;
  cl->ParaWords = 19;
  cl->Shortcut = 'C';
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Rendertarget2DType;
  in[0].DefaultClass = 0;
  in[0].Name = L"Rendertarget";
  in[0].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  in[1].Type = Wz4RenderType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"CopyCam",1);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BillboardCamera";
  cl->Label = L"BillboardCamera";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBillboardCamera;
  cl->MakeGui = Wz4RenderGuiBillboardCamera;
  cl->SetDefaults = Wz4RenderDefBillboardCamera;
  cl->BindPara = Wz4RenderBindBillboardCamera;
  cl->Bind2Para = Wz4RenderBind2BillboardCamera;
  cl->Bind3Para = Wz4RenderBind3BillboardCamera;
  cl->WikiText = Wz4RenderWikiBillboardCamera;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Rendertarget2DType;
  in[0].DefaultClass = 0;
  in[0].Name = L"Rendertarget";
  in[0].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  in[1].Type = Wz4RenderType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Render";
  cl->Label = L"Render";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdRender;
  cl->MakeGui = GenBitmapGuiRender;
  cl->SetDefaults = GenBitmapDefRender;
  cl->BindPara = GenBitmapBindRender;
  cl->Bind2Para = GenBitmapBind2Render;
  cl->Bind3Para = GenBitmapBind3Render;
  cl->WikiText = GenBitmapWikiRender;
  cl->ParaWords = 8;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"RenderMesh";
  cl->Label = L"RenderMesh";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdRenderMesh;
  cl->MakeGui = Wz4RenderGuiRenderMesh;
  cl->SetDefaults = Wz4RenderDefRenderMesh;
  cl->BindPara = Wz4RenderBindRenderMesh;
  cl->Bind2Para = Wz4RenderBind2RenderMesh;
  cl->Bind3Para = Wz4RenderBind3RenderMesh;
  cl->WikiText = Wz4RenderWikiRenderMesh;
  cl->ParaStrings = 1;
  cl->ParaWords = 4;
  cl->Shortcut = 'r';
  cl->Flags = 0x0080;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MultiplyMesh";
  cl->Label = L"MultiplyMesh";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdMultiplyMesh;
  cl->MakeGui = Wz4RenderGuiMultiplyMesh;
  cl->SetDefaults = Wz4RenderDefMultiplyMesh;
  cl->BindPara = Wz4RenderBindMultiplyMesh;
  cl->Bind2Para = Wz4RenderBind2MultiplyMesh;
  cl->Bind3Para = Wz4RenderBind3MultiplyMesh;
  cl->WikiText = Wz4RenderWikiMultiplyMesh;
  cl->ParaStrings = 1;
  cl->ParaWords = 42;
  cl->Shortcut = 'M';
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Script";
  cl->Label = L"Script";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdScript;
  cl->MakeGui = Wz4RenderGuiScript;
  cl->SetDefaults = Wz4RenderDefScript;
  cl->BindPara = Wz4RenderBindScript;
  cl->Bind2Para = Wz4RenderBind2Script;
  cl->Bind3Para = Wz4RenderBind3Script;
  cl->WikiText = Wz4RenderWikiScript;
  cl->ParaStrings = 1;
  cl->ParaWords = 1;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Transform";
  cl->Label = L"Transform";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdTransform;
  cl->MakeGui = Wz4RenderGuiTransform;
  cl->SetDefaults = Wz4RenderDefTransform;
  cl->BindPara = Wz4RenderBindTransform;
  cl->Bind2Para = Wz4RenderBind2Transform;
  cl->Bind3Para = Wz4RenderBind3Transform;
  cl->WikiText = Wz4RenderWikiTransform;
  cl->Handles = Wz4RenderHndTransform;
  cl->ParaStrings = 1;
  cl->ParaWords = 10;
  cl->Shortcut = 't';
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TransformPivot";
  cl->Label = L"TransformPivot";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdTransformPivot;
  cl->MakeGui = Wz4RenderGuiTransformPivot;
  cl->SetDefaults = Wz4RenderDefTransformPivot;
  cl->BindPara = Wz4RenderBindTransformPivot;
  cl->Bind2Para = Wz4RenderBind2TransformPivot;
  cl->Bind3Para = Wz4RenderBind3TransformPivot;
  cl->WikiText = Wz4RenderWikiTransformPivot;
  cl->Handles = Wz4RenderHndTransformPivot;
  cl->ParaStrings = 1;
  cl->ParaWords = 13;
  cl->Shortcut = 'p';
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SplinedObject";
  cl->Label = L"SplinedObject";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSplinedObject;
  cl->MakeGui = Wz4RenderGuiSplinedObject;
  cl->SetDefaults = Wz4RenderDefSplinedObject;
  cl->BindPara = Wz4RenderBindSplinedObject;
  cl->Bind2Para = Wz4RenderBind2SplinedObject;
  cl->Bind3Para = Wz4RenderBind3SplinedObject;
  cl->WikiText = Wz4RenderWikiSplinedObject;
  cl->ParaStrings = 2;
  cl->ParaWords = 5;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"LookAt";
  cl->Label = L"LookAt";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdLookAt;
  cl->MakeGui = Wz4RenderGuiLookAt;
  cl->SetDefaults = Wz4RenderDefLookAt;
  cl->BindPara = Wz4RenderBindLookAt;
  cl->Bind2Para = Wz4RenderBind2LookAt;
  cl->Bind3Para = Wz4RenderBind3LookAt;
  cl->WikiText = Wz4RenderWikiLookAt;
  cl->ParaStrings = 1;
  cl->ParaWords = 11;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SkyCube";
  cl->Label = L"SkyCube";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSkyCube;
  cl->MakeGui = Wz4RenderGuiSkyCube;
  cl->SetDefaults = Wz4RenderDefSkyCube;
  cl->BindPara = Wz4RenderBindSkyCube;
  cl->Bind2Para = Wz4RenderBind2SkyCube;
  cl->Bind3Para = Wz4RenderBind3SkyCube;
  cl->WikiText = Wz4RenderWikiSkyCube;
  cl->ParaStrings = 1;
  cl->ParaWords = 1;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Shaker";
  cl->Label = L"Shaker";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdShaker;
  cl->MakeGui = Wz4RenderGuiShaker;
  cl->SetDefaults = Wz4RenderDefShaker;
  cl->BindPara = Wz4RenderBindShaker;
  cl->Bind2Para = Wz4RenderBind2Shaker;
  cl->Bind3Para = Wz4RenderBind3Shaker;
  cl->WikiText = Wz4RenderWikiShaker;
  cl->ParaStrings = 1;
  cl->ParaWords = 21;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Multiply";
  cl->Label = L"Multiply";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdMultiply;
  cl->MakeGui = Wz4RenderGuiMultiply;
  cl->SetDefaults = Wz4RenderDefMultiply;
  cl->BindPara = Wz4RenderBindMultiply;
  cl->Bind2Para = Wz4RenderBind2Multiply;
  cl->Bind3Para = Wz4RenderBind3Multiply;
  cl->WikiText = Wz4RenderWikiMultiply;
  cl->ParaStrings = 1;
  cl->ParaWords = 21;
  cl->Shortcut = 'm';
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Clip";
  cl->Label = L"Clip";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdClip;
  cl->MakeGui = Wz4RenderGuiClip;
  cl->SetDefaults = Wz4RenderDefClip;
  cl->BindPara = Wz4RenderBindClip;
  cl->Bind2Para = Wz4RenderBind2Clip;
  cl->Bind3Para = Wz4RenderBind3Clip;
  cl->WikiText = Wz4RenderWikiClip;
  cl->ParaStrings = 1;
  cl->ParaWords = 10;
  cl->Shortcut = 'c';
  cl->Flags = 0x0001;
  cl->CustomEd = Wz4RenderCedClip;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ClipRandomizer";
  cl->Label = L"ClipRandomizer";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdClipRandomizer;
  cl->MakeGui = Wz4RenderGuiClipRandomizer;
  cl->SetDefaults = Wz4RenderDefClipRandomizer;
  cl->BindPara = Wz4RenderBindClipRandomizer;
  cl->Bind2Para = Wz4RenderBind2ClipRandomizer;
  cl->Bind3Para = Wz4RenderBind3ClipRandomizer;
  cl->WikiText = Wz4RenderWikiClipRandomizer;
  cl->Actions = Wz4RenderActClipRandomizer;
  cl->ParaStrings = 1;
  cl->ParaWords = 9;
  cl->Flags = 0x0001;
  cl->CustomEd = Wz4RenderCedClipRandomizer;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"Shuffle",1);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ClipRandDuration";
  cl->Label = L"ClipRandDuration";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdClipRandDuration;
  cl->MakeGui = Wz4RenderGuiClipRandDuration;
  cl->SetDefaults = Wz4RenderDefClipRandDuration;
  cl->BindPara = Wz4RenderBindClipRandDuration;
  cl->Bind2Para = Wz4RenderBind2ClipRandDuration;
  cl->Bind3Para = Wz4RenderBind3ClipRandDuration;
  cl->WikiText = Wz4RenderWikiClipRandDuration;
  cl->ParaWords = 2;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MultiClip";
  cl->Label = L"MultiClip";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdMultiClip;
  cl->MakeGui = Wz4RenderGuiMultiClip;
  cl->SetDefaults = Wz4RenderDefMultiClip;
  cl->BindPara = Wz4RenderBindMultiClip;
  cl->Bind2Para = Wz4RenderBind2MultiClip;
  cl->Bind3Para = Wz4RenderBind3MultiClip;
  cl->WikiText = Wz4RenderWikiMultiClip;
  cl->SetDefaultsArray = Wz4RenderArrMultiClip;
  cl->ArrayCount = 6;
  cl->ParaStrings = 1;
  cl->ParaWords = 4;
  cl->Flags = 0x0001;
  cl->CustomEd = Wz4RenderCedMultiClip;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Fader";
  cl->Label = L"Fader";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFader;
  cl->MakeGui = Wz4RenderGuiFader;
  cl->SetDefaults = Wz4RenderDefFader;
  cl->BindPara = Wz4RenderBindFader;
  cl->Bind2Para = Wz4RenderBind2Fader;
  cl->Bind3Para = Wz4RenderBind3Fader;
  cl->WikiText = Wz4RenderWikiFader;
  cl->ParaStrings = 1;
  cl->ParaWords = 17;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Fader2";
  cl->Label = L"Fader2";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFader2;
  cl->MakeGui = Wz4RenderGuiFader2;
  cl->SetDefaults = Wz4RenderDefFader2;
  cl->BindPara = Wz4RenderBindFader2;
  cl->Bind2Para = Wz4RenderBind2Fader2;
  cl->Bind3Para = Wz4RenderBind3Fader2;
  cl->WikiText = Wz4RenderWikiFader2;
  cl->ParaStrings = 1;
  cl->ParaWords = 17;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Variable";
  cl->Label = L"Variable";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdVariable;
  cl->MakeGui = Wz4RenderGuiVariable;
  cl->SetDefaults = Wz4RenderDefVariable;
  cl->BindPara = Wz4RenderBindVariable;
  cl->Bind2Para = Wz4RenderBind2Variable;
  cl->Bind3Para = Wz4RenderBind3Variable;
  cl->WikiText = Wz4RenderWikiVariable;
  cl->ParaStrings = 3;
  cl->ParaWords = 6;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Spline";
  cl->Label = L"Spline";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSpline;
  cl->MakeGui = Wz4RenderGuiSpline;
  cl->SetDefaults = Wz4RenderDefSpline;
  cl->BindPara = Wz4RenderBindSpline;
  cl->Bind2Para = Wz4RenderBind2Spline;
  cl->Bind3Para = Wz4RenderBind3Spline;
  cl->WikiText = Wz4RenderWikiSpline;
  cl->Handles = Wz4RenderHndSpline;
  cl->SetDefaultsArray = Wz4RenderArrSpline;
  cl->Actions = Wz4RenderActSpline;
  cl->ArrayCount = 4;
  cl->ParaStrings = 1;
  cl->ParaWords = 5;
  cl->Shortcut = 'S';
  cl->Flags = 0x0000;
  cl->CustomEd = Wz4RenderCedSpline;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  cl->ActionIds.AddMany(1)->Init(L"CreateNew",2);
  cl->ActionIds.AddMany(1)->Init(L"Sort",1);
  cl->ActionIds.AddMany(1)->Init(L"RelaxByArclength",3);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Layer2D";
  cl->Label = L"Layer2D";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdLayer2D;
  cl->MakeGui = Wz4RenderGuiLayer2D;
  cl->SetDefaults = Wz4RenderDefLayer2D;
  cl->BindPara = Wz4RenderBindLayer2D;
  cl->Bind2Para = Wz4RenderBind2Layer2D;
  cl->Bind3Para = Wz4RenderBind3Layer2D;
  cl->WikiText = Wz4RenderWikiLayer2D;
  cl->ParaStrings = 1;
  cl->ParaWords = 19;
  cl->Shortcut = 'L';
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Name = L"SecondTexture";
  in[1].Flags = 0|wCIF_OPTIONAL|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Beat";
  cl->Label = L"Beat";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBeat;
  cl->MakeGui = Wz4RenderGuiBeat;
  cl->SetDefaults = Wz4RenderDefBeat;
  cl->BindPara = Wz4RenderBindBeat;
  cl->Bind2Para = Wz4RenderBind2Beat;
  cl->Bind3Para = Wz4RenderBind3Beat;
  cl->WikiText = Wz4RenderWikiBeat;
  cl->SetDefaultsArray = Wz4RenderArrBeat;
  cl->Actions = Wz4RenderActBeat;
  cl->ArrayCount = 4;
  cl->ParaStrings = 1;
  cl->ParaWords = 60;
  cl->Flags = 0x0000;
  cl->CustomEd = Wz4RenderCedBeat;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  cl->ActionIds.AddMany(1)->Init(L"Init",1);
  cl->ActionIds.AddMany(1)->Init(L"DoubleSpeed",2);
  cl->ActionIds.AddMany(1)->Init(L"HalfSpeed",3);
  cl->ActionIds.AddMany(1)->Init(L"MakeLevels",4);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BoneTrain";
  cl->Label = L"BoneTrain";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBoneTrain;
  cl->MakeGui = Wz4RenderGuiBoneTrain;
  cl->SetDefaults = Wz4RenderDefBoneTrain;
  cl->BindPara = Wz4RenderBindBoneTrain;
  cl->Bind2Para = Wz4RenderBind2BoneTrain;
  cl->Bind3Para = Wz4RenderBind3BoneTrain;
  cl->WikiText = Wz4RenderWikiBoneTrain;
  cl->ParaStrings = 2;
  cl->ParaWords = 10;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"UnitTestWz4";
  cl->Label = L"UnitTestWz4";
  cl->OutputType = UnitTestType;
  cl->TabType = Wz4RenderType;
  cl->Command = UnitTestCmdUnitTestWz4;
  cl->MakeGui = UnitTestGuiUnitTestWz4;
  cl->SetDefaults = UnitTestDefUnitTestWz4;
  cl->BindPara = UnitTestBindUnitTestWz4;
  cl->Bind2Para = UnitTestBind2UnitTestWz4;
  cl->Bind3Para = UnitTestBind3UnitTestWz4;
  cl->WikiText = UnitTestWikiUnitTestWz4;
  cl->ParaStrings = 1;
  cl->ParaWords = 2;
  cl->FileOutMask = 1;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_demo2_ops,0x110,AddOps_wz4_demo2_ops,0);


/****************************************************************************/


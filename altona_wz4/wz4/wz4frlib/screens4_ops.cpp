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
#include "screens4_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 13 "screens4_ops.ops"

#include "wz4frlib/screens4fx.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 

#line 30 "screens4_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdSiegmeister(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSiegmeister sUNUSED *para = (Wz4RenderParaSiegmeister *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 46 "screens4_ops.ops"

    RNSiegmeister *node = new RNSiegmeister();
    node->ParaBase = node->Para = *para;
    node->Texture = in0; sAddRef(in0);
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 55 "screens4_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSiegmeister(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSiegmeister sUNUSED *para = (Wz4RenderParaSiegmeister *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"* BlinkSpeed");
  sFloatControl *float_BlinkSpeed = gh.Float(&para->BlinkSpeed,0.000000f,10.00000f,0.100000f);
  float_BlinkSpeed->Default = 1.000000f; float_BlinkSpeed->RightStep = 0.125000f;

  gh.Label(L"Aspect");
  sIntControl *int_AspNum = gh.Int(&para->AspNum,0,50,0.125000f);
  int_AspNum->Default = 0x00000010; int_AspNum->RightStep = 0.125000f;

  sIntControl *int_AspDen = gh.Int(&para->AspDen,0,50,0.125000f);
  int_AspDen->Default = 0x00000009; int_AspDen->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefSiegmeister(wOp *op)
{
  Wz4RenderParaSiegmeister sUNUSED *para = (Wz4RenderParaSiegmeister *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->BlinkSpeed = 1.000000f;
  para->AspNum = 0x00000010;
  para->AspDen = 0x00000009;
}

void Wz4RenderBindSiegmeister(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"blinkspeed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"aspect"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"aspden"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Siegmeister(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"blinkspeed");
    name[3] = sPoolString(L"aspect");
    name[4] = sPoolString(L"aspden");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Siegmeister(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import blinkspeed : float;\n");
  tb.PrintF(L"  import aspect : int;\n");
  tb.PrintF(L"  import aspden : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSiegmeister =
L"= Wz4Render : Siegmeister\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Siegmeister\n"
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
L" !i optional\n"
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
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i BlinkSpeed\n"
L" !i BlinkSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Aspect\n"
L" !i AspNum\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i AspDen\n"
L" !i AspDen\n"
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

sBool Wz4RenderCmdCustom2DFS(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCustom2DFS sUNUSED *para = (Wz4RenderParaCustom2DFS *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 71 "screens4_ops.ops"

    RNCustomFullscreen2D *node = new RNCustomFullscreen2D();
    node->ParaBase = node->Para = *para;
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 248 "screens4_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiCustom2DFS(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCustom2DFS sUNUSED *para = (Wz4RenderParaCustom2DFS *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"letterbox|crop",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefCustom2DFS(wOp *op)
{
  Wz4RenderParaCustom2DFS sUNUSED *para = (Wz4RenderParaCustom2DFS *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0xffffffff;
}

void Wz4RenderBindCustom2DFS(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Custom2DFS(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"color_");
    name[2] = sPoolString(L"flags");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Custom2DFS(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCustom2DFS =
L"= Wz4Render : Custom2DFS\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Custom2DFS\n"
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
L" !i optional\n"
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
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i letterbox\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i crop\n"
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

void Wz4RenderAnimSiegmeister::Init(class ScriptContext *sc)
{
  _BlinkSpeed = sc->AddSymbol(L"blinkspeed");
};

void Wz4RenderAnimSiegmeister::Bind(class ScriptContext *sc,Wz4RenderParaSiegmeister *para)
{
  sc->BindLocalFloat(_BlinkSpeed,1,&para->BlinkSpeed);
};

void Wz4RenderAnimCustom2DFS::Init(class ScriptContext *sc)
{
  _Color = sc->AddSymbol(L"color_");
};

void Wz4RenderAnimCustom2DFS::Bind(class ScriptContext *sc,Wz4RenderParaCustom2DFS *para)
{
  sc->BindLocalColor(_Color,&para->Color);
};


/****************************************************************************/

void AddTypes_screens4_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_screens4_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Siegmeister";
  cl->Label = L"Siegmeister";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSiegmeister;
  cl->MakeGui = Wz4RenderGuiSiegmeister;
  cl->SetDefaults = Wz4RenderDefSiegmeister;
  cl->BindPara = Wz4RenderBindSiegmeister;
  cl->Bind2Para = Wz4RenderBind2Siegmeister;
  cl->Bind3Para = Wz4RenderBind3Siegmeister;
  cl->WikiText = Wz4RenderWikiSiegmeister;
  cl->ParaStrings = 1;
  cl->ParaWords = 5;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Custom2DFS";
  cl->Label = L"Screens4 Fullscreen";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCustom2DFS;
  cl->MakeGui = Wz4RenderGuiCustom2DFS;
  cl->SetDefaults = Wz4RenderDefCustom2DFS;
  cl->BindPara = Wz4RenderBindCustom2DFS;
  cl->Bind2Para = Wz4RenderBind2Custom2DFS;
  cl->Bind3Para = Wz4RenderBind3Custom2DFS;
  cl->WikiText = Wz4RenderWikiCustom2DFS;
  cl->ParaStrings = 1;
  cl->ParaWords = 3;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(screens4_ops,0x110,AddOps_screens4_ops,0);


/****************************************************************************/


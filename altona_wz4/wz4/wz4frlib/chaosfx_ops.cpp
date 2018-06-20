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
#include "chaosfx_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 13 "chaosfx_ops.ops"

#include "wz4frlib/chaosfx.hpp"
//#include "wz4frlib/wz4_demo_ops.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 
#include "wz4frlib/chaos_font.hpp"
#include "wz4frlib/chaos_font_ops.hpp"

#line 33 "chaosfx_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdCubeExample(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCubeExample sUNUSED *para = (Wz4RenderParaCubeExample *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 41 "chaosfx_ops.ops"

    RNCubeExample *node = new RNCubeExample();
    node->ParaBase = node->Para = *para;
    node->Mtrl = in0; in0->AddRef();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 56 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiCubeExample(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCubeExample sUNUSED *para = (Wz4RenderParaCubeExample *)(op->EditData); para;
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

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

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

void Wz4RenderDefCubeExample(wOp *op)
{
  Wz4RenderParaCubeExample sUNUSED *para = (Wz4RenderParaCubeExample *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4RenderBindCubeExample(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
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
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2CubeExample(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"lightenv");
    name[4] = sPoolString(L"renderpass");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3CubeExample(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCubeExample =
L"= Wz4Render : CubeExample\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CubeExample\n"
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

sBool Wz4RenderCmdPrint(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaPrint sUNUSED *para = (Wz4RenderParaPrint *)(cmd->Data); para;
  ChaosFont sUNUSED *in0 = cmd->GetInput<ChaosFont *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 67 "chaosfx_ops.ops"

    RNPrint *node = new RNPrint();
    node->ParaBase = node->Para = *para;
    node->Font = in0; in0->AddRef();
    node->Text = cmd->Strings[1];
    node->Font->PreparePrint();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 287 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiPrint(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaPrint sUNUSED *para = (Wz4RenderParaPrint *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

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

  gh.Label(L"* Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Group(L"Text");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[1],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
  }

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefPrint(wOp *op)
{
  Wz4RenderParaPrint sUNUSED *para = (Wz4RenderParaPrint *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Color = 0xffffffff;
  *op->EditString[1] = L"hund.";
}

void Wz4RenderBindPrint(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
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
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"text"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Print(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"scale");
    name[2] = sPoolString(L"rot");
    name[3] = sPoolString(L"trans");
    name[4] = sPoolString(L"color_");
    name[5] = sPoolString(L"text");
    name[6] = sPoolString(L"text");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+10);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Print(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import text : string;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiPrint =
L"= Wz4Render : Print\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Print\n"
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
L" !i ChaosFont\n"
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
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Text\n"
L" !i Text\n"
L" !i string\n"
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

sBool Wz4RenderCmdRibbons(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaRibbons sUNUSED *para = (Wz4RenderParaRibbons *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 100 "chaosfx_ops.ops"

    RNRibbons *node = new RNRibbons();
    node->ParaBase = node->Para = *para;

    if(in0)
    {
      node->MtrlEx = in0;
      in0->AddRef();
    }

    out->RootNode = node;

    if(in0)
      out->AddCode(cmd,para->Renderpass);
    else
      out->AddChilds(cmd,para->Renderpass);
  ;
#line 547 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiRibbons(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaRibbons sUNUSED *para = (Wz4RenderParaRibbons *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.125000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.125000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.125000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Forward");
  sFloatControl *float_Forward = gh.Float(&para->Forward,0.000000f,4.000000f,0.001000f);
  float_Forward->Default = 0.100000f; float_Forward->RightStep = 0.125000f;

  gh.Label(L"* Side");
  sFloatControl *float_Side = gh.Float(&para->Side,0.000000f,4.000000f,0.001000f);
  float_Side->Default = 0.050000f; float_Side->RightStep = 0.125000f;

  gh.Label(L"* Steps");
  sIntControl *int_Steps = gh.Int(&para->Steps,0,1000,0.125000f);
  int_Steps->Default = 0x00000032; int_Steps->RightStep = 0.125000f;

  gh.Label(L"* Around");
  sIntControl *int_Around = gh.Int(&para->Around,0,100,0.125000f);
  int_Around->Default = 0x00000008; int_Around->RightStep = 0.125000f;

  gh.Label(L"* Waber");
  gh.BeginTied();
  sFloatControl *float_Waber_0 = gh.Float(&para->Waber[0],-1024.00f,1024.000f,0.100000f);
  float_Waber_0->Default = 40.00000f; float_Waber_0->RightStep = 0.125000f;
  sFloatControl *float_Waber_1 = gh.Float(&para->Waber[1],-1024.00f,1024.000f,0.100000f);
  float_Waber_1->Default = 50.00000f; float_Waber_1->RightStep = 0.125000f;
  sFloatControl *float_Waber_2 = gh.Float(&para->Waber[2],-1024.00f,1024.000f,0.100000f);
  float_Waber_2->Default = 60.00000f; float_Waber_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Freq");
  gh.BeginTied();
  sFloatControl *float_Freq_0 = gh.Float(&para->Freq[0],-1024.00f,1024.000f,0.001000f);
  float_Freq_0->Default = 2.000000f; float_Freq_0->RightStep = 0.125000f;
  sFloatControl *float_Freq_1 = gh.Float(&para->Freq[1],-1024.00f,1024.000f,0.001000f);
  float_Freq_1->Default = 3.000000f; float_Freq_1->RightStep = 0.125000f;
  sFloatControl *float_Freq_2 = gh.Float(&para->Freq[2],-1024.00f,1024.000f,0.001000f);
  float_Freq_2->Default = 4.000000f; float_Freq_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Spread");
  gh.BeginTied();
  sFloatControl *float_Spread_0 = gh.Float(&para->Spread[0],-1024.00f,1024.000f,0.001000f);
  float_Spread_0->Default = 0.100000f; float_Spread_0->RightStep = 0.125000f;
  sFloatControl *float_Spread_1 = gh.Float(&para->Spread[1],-1024.00f,1024.000f,0.001000f);
  float_Spread_1->Default = 0.100000f; float_Spread_1->RightStep = 0.125000f;
  sFloatControl *float_Spread_2 = gh.Float(&para->Spread[2],-1024.00f,1024.000f,0.001000f);
  float_Spread_2->Default = 0.100000f; float_Spread_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Start");
  gh.BeginTied();
  sFloatControl *float_Start_0 = gh.Float(&para->Start[0],-1024.00f,1024.000f,0.000100f);
  float_Start_0->Default = 0.000000f; float_Start_0->RightStep = 0.125000f;
  sFloatControl *float_Start_1 = gh.Float(&para->Start[1],-1024.00f,1024.000f,0.000100f);
  float_Start_1->Default = 0.000000f; float_Start_1->RightStep = 0.125000f;
  sFloatControl *float_Start_2 = gh.Float(&para->Start[2],-1024.00f,1024.000f,0.000100f);
  float_Start_2->Default = 0.000000f; float_Start_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

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

void Wz4RenderDefRibbons(wOp *op)
{
  Wz4RenderParaRibbons sUNUSED *para = (Wz4RenderParaRibbons *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Forward = 0.100000f;
  para->Side = 0.050000f;
  para->Steps = 0x00000032;
  para->Around = 0x00000008;
  para->Waber[0] = 40.00000f;
  para->Waber[1] = 50.00000f;
  para->Waber[2] = 60.00000f;
  para->Freq[0] = 2.000000f;
  para->Freq[1] = 3.000000f;
  para->Freq[2] = 4.000000f;
  para->Spread[0] = 0.100000f;
  para->Spread[1] = 0.100000f;
  para->Spread[2] = 0.100000f;
}

void Wz4RenderBindRibbons(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"forward"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"side"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"steps"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"around"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"waber"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"waber"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"waber"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Ribbons(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"trans");
    name[1] = sPoolString(L"forward");
    name[2] = sPoolString(L"side");
    name[3] = sPoolString(L"steps");
    name[4] = sPoolString(L"around");
    name[5] = sPoolString(L"waber");
    name[6] = sPoolString(L"freq");
    name[7] = sPoolString(L"spread");
    name[8] = sPoolString(L"start");
    name[9] = sPoolString(L"lightenv");
    name[10] = sPoolString(L"renderpass");
    name[11] = sPoolString(L"");
    name[12] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+13);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+16);
  ctx->AddImport(name[9],ScriptTypeInt,1,cmd->Data+19);
  ctx->AddImport(name[10],ScriptTypeInt,1,cmd->Data+20);
  ctx->AddImport(name[12],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Ribbons(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import forward : float;\n");
  tb.PrintF(L"  import side : float;\n");
  tb.PrintF(L"  import steps : int;\n");
  tb.PrintF(L"  import around : int;\n");
  tb.PrintF(L"  import waber : float[3];\n");
  tb.PrintF(L"  import freq : float[3];\n");
  tb.PrintF(L"  import spread : float[3];\n");
  tb.PrintF(L"  import start : float[3];\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiRibbons =
L"= Wz4Render : Ribbons\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Ribbons\n"
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
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Forward\n"
L" !i Forward\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Side\n"
L" !i Side\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Steps\n"
L" !i Steps\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Around\n"
L" !i Around\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Waber\n"
L" !i Waber\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Freq\n"
L" !i Freq\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i Spread\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Start\n"
L" !i Start\n"
L" !i float[3]\n"
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

sBool Wz4RenderCmdRibbons2(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaRibbons2 sUNUSED *para = (Wz4RenderParaRibbons2 *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 147 "chaosfx_ops.ops"

    RNRibbons2 *node = new RNRibbons2();
    node->ParaBase = node->Para = *para;

    if(in0)
    {
      node->MtrlEx = in0;
      in0->AddRef();
    }


    out->RootNode = node;

    if(in0)
      out->AddCode(cmd,para->Renderpass);
    else
      out->AddChilds(cmd,para->Renderpass);
    //out->AddChilds(cmd,para->Renderpass);
  ;
#line 912 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndRibbons2(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaRibbons2 sUNUSED *para = (Wz4RenderParaRibbons2 *)(op->EditData); para;
#line 167 "chaosfx_ops.ops"

    pi.Handle3D(op,1,para->Source0,wHM_PLANE);
    pi.Handle3D(op,2,para->Source1,wHM_PLANE);
    pi.Handle3D(op,3,para->Source2,wHM_PLANE);
    pi.Handle3D(op,4,para->Source3,wHM_PLANE);
  ;
#line 927 "chaosfx_ops.cpp"
}

void Wz4RenderGuiRibbons2(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaRibbons2 sUNUSED *para = (Wz4RenderParaRibbons2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,0,1024,0.125000f);
  int_Count->Default = 0x00000000; int_Count->RightStep = 0.125000f;

  gh.Label(L"Length");
  sIntControl *int_Length = gh.Int(&para->Length,2,1024,0.125000f);
  int_Length->Default = 0x00000002; int_Length->RightStep = 0.125000f;

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.125000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.125000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.125000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Spread");
  gh.BeginTied();
  sFloatControl *float_Spread_0 = gh.Float(&para->Spread.x,-16.0000f,16.00000f,0.100000f);
  float_Spread_0->Default = 1.000000f; float_Spread_0->RightStep = 0.125000f;
  sFloatControl *float_Spread_1 = gh.Float(&para->Spread.y,-16.0000f,16.00000f,0.100000f);
  float_Spread_1->Default = 1.000000f; float_Spread_1->RightStep = 0.125000f;
  sFloatControl *float_Spread_2 = gh.Float(&para->Spread.z,-16.0000f,16.00000f,0.100000f);
  float_Spread_2->Default = 1.000000f; float_Spread_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Forward");
  sFloatControl *float_Forward = gh.Float(&para->Forward,0.000000f,4.000000f,0.001000f);
  float_Forward->Default = 0.100000f; float_Forward->RightStep = 0.125000f;

  gh.Label(L"* Side");
  sFloatControl *float_Side = gh.Float(&para->Side,0.000000f,4.000000f,0.001000f);
  float_Side->Default = 0.050000f; float_Side->RightStep = 0.125000f;

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Group(L"Sources");

  gh.Label(L"Source0");
  gh.BeginTied();
  sFloatControl *float_Source0_0 = gh.Float(&para->Source0.x,-16.0000f,16.00000f,0.010000f);
  float_Source0_0->Default = 0.000000f; float_Source0_0->RightStep = 0.125000f;
  sFloatControl *float_Source0_1 = gh.Float(&para->Source0.y,-16.0000f,16.00000f,0.010000f);
  float_Source0_1->Default = 0.000000f; float_Source0_1->RightStep = 0.125000f;
  sFloatControl *float_Source0_2 = gh.Float(&para->Source0.z,-16.0000f,16.00000f,0.010000f);
  float_Source0_2->Default = 0.000000f; float_Source0_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Power0 = gh.Float(&para->Power0,-16.0000f,16.00000f,0.001000f);
  float_Power0->Default = 0.000000f; float_Power0->RightStep = 0.125000f;

  gh.Label(L"Source1");
  gh.BeginTied();
  sFloatControl *float_Source1_0 = gh.Float(&para->Source1.x,-16.0000f,16.00000f,0.010000f);
  float_Source1_0->Default = 0.000000f; float_Source1_0->RightStep = 0.125000f;
  sFloatControl *float_Source1_1 = gh.Float(&para->Source1.y,-16.0000f,16.00000f,0.010000f);
  float_Source1_1->Default = 0.000000f; float_Source1_1->RightStep = 0.125000f;
  sFloatControl *float_Source1_2 = gh.Float(&para->Source1.z,-16.0000f,16.00000f,0.010000f);
  float_Source1_2->Default = 0.000000f; float_Source1_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Power1 = gh.Float(&para->Power1,-16.0000f,16.00000f,0.001000f);
  float_Power1->Default = 0.000000f; float_Power1->RightStep = 0.125000f;

  gh.Label(L"Source2");
  gh.BeginTied();
  sFloatControl *float_Source2_0 = gh.Float(&para->Source2.x,-16.0000f,16.00000f,0.010000f);
  float_Source2_0->Default = 0.000000f; float_Source2_0->RightStep = 0.125000f;
  sFloatControl *float_Source2_1 = gh.Float(&para->Source2.y,-16.0000f,16.00000f,0.010000f);
  float_Source2_1->Default = 0.000000f; float_Source2_1->RightStep = 0.125000f;
  sFloatControl *float_Source2_2 = gh.Float(&para->Source2.z,-16.0000f,16.00000f,0.010000f);
  float_Source2_2->Default = 0.000000f; float_Source2_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Power2 = gh.Float(&para->Power2,-16.0000f,16.00000f,0.001000f);
  float_Power2->Default = 0.000000f; float_Power2->RightStep = 0.125000f;

  gh.Label(L"Source3");
  gh.BeginTied();
  sFloatControl *float_Source3_0 = gh.Float(&para->Source3.x,-16.0000f,16.00000f,0.010000f);
  float_Source3_0->Default = 0.000000f; float_Source3_0->RightStep = 0.125000f;
  sFloatControl *float_Source3_1 = gh.Float(&para->Source3.y,-16.0000f,16.00000f,0.010000f);
  float_Source3_1->Default = 0.000000f; float_Source3_1->RightStep = 0.125000f;
  sFloatControl *float_Source3_2 = gh.Float(&para->Source3.z,-16.0000f,16.00000f,0.010000f);
  float_Source3_2->Default = 0.000000f; float_Source3_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Power3 = gh.Float(&para->Power3,-16.0000f,16.00000f,0.001000f);
  float_Power3->Default = 0.000000f; float_Power3->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefRibbons2(wOp *op)
{
  Wz4RenderParaRibbons2 sUNUSED *para = (Wz4RenderParaRibbons2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Length = 0x00000002;
  para->Spread.x = 1.000000f;
  para->Spread.y = 1.000000f;
  para->Spread.z = 1.000000f;
  para->Forward = 0.100000f;
  para->Side = 0.050000f;
}

void Wz4RenderBindRibbons2(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"length"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"forward"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"side"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"source0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"source0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"source0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"power0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"source1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"source1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"source1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"power1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"source2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"source2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"source2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"power2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"source3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"source3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"source3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"power3"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Ribbons2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[19];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"count");
    name[2] = sPoolString(L"length");
    name[3] = sPoolString(L"trans");
    name[4] = sPoolString(L"spread");
    name[5] = sPoolString(L"forward");
    name[6] = sPoolString(L"side");
    name[7] = sPoolString(L"lightenv");
    name[8] = sPoolString(L"sources");
    name[9] = sPoolString(L"source0");
    name[10] = sPoolString(L"power0");
    name[11] = sPoolString(L"source1");
    name[12] = sPoolString(L"power1");
    name[13] = sPoolString(L"source2");
    name[14] = sPoolString(L"power2");
    name[15] = sPoolString(L"source3");
    name[16] = sPoolString(L"power3");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[11],ScriptTypeFloat,3,cmd->Data+16);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[13],ScriptTypeFloat,3,cmd->Data+20);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[15],ScriptTypeFloat,3,cmd->Data+24);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[18],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Ribbons2(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import length : int;\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import spread : float[3];\n");
  tb.PrintF(L"  import forward : float;\n");
  tb.PrintF(L"  import side : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import source0 : float[3];\n");
  tb.PrintF(L"  import power0 : float;\n");
  tb.PrintF(L"  import source1 : float[3];\n");
  tb.PrintF(L"  import power1 : float;\n");
  tb.PrintF(L"  import source2 : float[3];\n");
  tb.PrintF(L"  import power2 : float;\n");
  tb.PrintF(L"  import source3 : float[3];\n");
  tb.PrintF(L"  import power3 : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiRibbons2 =
L"= Wz4Render : Ribbons2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Ribbons2\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Length\n"
L" !i Length\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i Spread\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Forward\n"
L" !i Forward\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Side\n"
L" !i Side\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Source0\n"
L" !i Source0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Power0\n"
L" !i Power0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Source1\n"
L" !i Source1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Power1\n"
L" !i Power1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Source2\n"
L" !i Source2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Power2\n"
L" !i Power2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Source3\n"
L" !i Source3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Power3\n"
L" !i Power3\n"
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

sBool Wz4RenderCmdBlowNoise(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBlowNoise sUNUSED *para = (Wz4RenderParaBlowNoise *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 200 "chaosfx_ops.ops"

    RNBlowNoise *node = new RNBlowNoise();
    node->ParaBase = node->Para = *para;

    Wz4RenderArrayBlowNoise *src = (Wz4RenderArrayBlowNoise *) cmd->Array;
    for(sInt i=0;i<cmd->ArrayCount;i++)
    {
      Wz4RenderArrayBlowNoise *dest = new Wz4RenderArrayBlowNoise;
      *dest = src[i];
      node->Layers.AddTail(dest);
    }
    node->Mtrl = in0; in0->AddRef();

    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 1368 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderArrBlowNoise(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaBlowNoise sUNUSED *para = (Wz4RenderParaBlowNoise *)(op->EditData); para;
  Wz4RenderArrayBlowNoise *e = (Wz4RenderArrayBlowNoise *)(mem);
  e->Octave = 0x00000000;
  e->Depth = 0.000000f;
  e->Blow = 0.000000f;
  e->Scroll[0] = 0.000000f;
  e->Scroll[1] = 0.000000f;
  e->Flags = 0x00000001;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4RenderArrayBlowNoise *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4RenderArrayBlowNoise *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4RenderArrayBlowNoise *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4RenderArrayBlowNoise *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4RenderArrayBlowNoise *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4RenderArrayBlowNoise *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4RenderArrayBlowNoise *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4RenderArrayBlowNoise *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4RenderArrayBlowNoise *)op->ArrayData[pos  ];
    }
    e->Depth = f0*p0->Depth + f1*p1->Depth;
    e->Blow = f0*p0->Blow + f1*p1->Blow;
    e->Scroll[0] = f0*p0->Scroll[0] + f1*p1->Scroll[0];
    e->Scroll[1] = f0*p0->Scroll[1] + f1*p1->Scroll[1];
  }
}

void Wz4RenderGuiBlowNoise(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBlowNoise sUNUSED *para = (Wz4RenderParaBlowNoise *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Tess");
  gh.BeginTied();
  sIntControl *int_Tess_0 = gh.Int(&para->Tess[0],4,1024,0.125000f);
  int_Tess_0->Default = 0x00000040; int_Tess_0->RightStep = 0.125000f;
  sIntControl *int_Tess_1 = gh.Int(&para->Tess[1],4,1024,0.125000f);
  int_Tess_1->Default = 0x00000040; int_Tess_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Scale");
  sFloatControl *float_Scale = gh.Float(&para->Scale,0.000000f,64.00000f,0.010000f);
  float_Scale->Default = 16.00000f; float_Scale->RightStep = 0.125000f;

  gh.Label(L"* Scroll");
  sFloatControl *float_Scroll = gh.Float(&para->Scroll,-1024.00f,1024.000f,0.010000f);
  float_Scroll->Default = 0.000000f; float_Scroll->RightStep = 0.125000f;

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

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
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Octave",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Depth",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Blow",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Scroll",pos,gh.Line,2,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=2;
  gh.Grid->AddLabel(L"Enable",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArrayBlowNoise *elem = (Wz4RenderArrayBlowNoise *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    sIntControl *int_Octave = gh.Int(&elem->Octave,0,16,0.125000f);
    int_Octave->Default = 0x00000000; int_Octave->RightStep = 0.125000f;

    sFloatControl *float_Depth = gh.Float(&elem->Depth,-64.0000f,64.00000f,0.010000f);
    float_Depth->Default = 0.000000f; float_Depth->RightStep = 0.125000f;

    sFloatControl *float_Blow = gh.Float(&elem->Blow,-64.0000f,64.00000f,0.010000f);
    float_Blow->Default = 0.000000f; float_Blow->RightStep = 0.125000f;

    gh.BeginTied();
    sFloatControl *float_Scroll_0 = gh.Float(&elem->Scroll[0],-64.0000f,64.00000f,0.001000f);
    float_Scroll_0->Default = 0.000000f; float_Scroll_0->RightStep = 0.125000f;
    sFloatControl *float_Scroll_1 = gh.Float(&elem->Scroll[1],-64.0000f,64.00000f,0.001000f);
    float_Scroll_1->Default = 0.000000f; float_Scroll_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Flags(&elem->Flags,L"off|on",gh.ChangeMsg);
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

void Wz4RenderDefBlowNoise(wOp *op)
{
  Wz4RenderParaBlowNoise sUNUSED *para = (Wz4RenderParaBlowNoise *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Tess[0] = 0x00000040;
  para->Tess[1] = 0x00000040;
  para->Scale = 16.00000f;
}

void Wz4RenderBindBlowNoise(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tess"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tess"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scroll"),val);
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
void Wz4RenderBind2BlowNoise(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"tess");
    name[1] = sPoolString(L"scale");
    name[2] = sPoolString(L"scroll");
    name[3] = sPoolString(L"lightenv");
    name[4] = sPoolString(L"renderpass");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,2,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3BlowNoise(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import tess : int[2];\n");
  tb.PrintF(L"  import scale : float;\n");
  tb.PrintF(L"  import scroll : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBlowNoise =
L"= Wz4Render : BlowNoise\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BlowNoise\n"
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
L" !i Tess\n"
L" !i Tess\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scroll\n"
L" !i Scroll\n"
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
L" !i Tess\n"
L" !i Tess\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scroll\n"
L" !i Scroll\n"
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

sBool Wz4RenderCmdDebrisClassic(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaDebrisClassic sUNUSED *para = (Wz4RenderParaDebrisClassic *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  BitmapBase sUNUSED *in1 = cmd->GetInput<BitmapBase *>(1); in1;
  BitmapBase sUNUSED *in2 = cmd->GetInput<BitmapBase *>(2); in2;
  BitmapBase sUNUSED *in3 = cmd->GetInput<BitmapBase *>(3); in3;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 303 "chaosfx_ops.ops"

    RNDebrisClassic *node = new RNDebrisClassic();
    node->ParaBase = node->Para = *para;
    in0->Charge();
    node->Mesh   = in0; in0->AddRef();
    in1->CopyTo(&node->Bitmap[0]);
    if(in2) in2->CopyTo(&node->Bitmap[1]);
    if(in3) in3->CopyTo(&node->Bitmap[2]);
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 1720 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiDebrisClassic(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaDebrisClassic sUNUSED *para = (Wz4RenderParaDebrisClassic *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"chunks|instances",gh.LayoutMsg);

  gh.Group(L"Projection A");

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*3-|enable:xy|yz|xz:*2plane|circular:*4border|tile|clamp",gh.ChangeMsg);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*7-|bias",gh.ChangeMsg);

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans[0],-1024.00f,1024.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans[1],-1024.00f,1024.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale[0],-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale[1],-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Scroll");
  gh.BeginTied();
  sFloatControl *float_Scroll_0 = gh.Float(&para->Scroll[0],-1024.00f,1024.000f,0.001000f);
  float_Scroll_0->Default = 0.000000f; float_Scroll_0->RightStep = 0.125000f;
  sFloatControl *float_Scroll_1 = gh.Float(&para->Scroll[1],-1024.00f,1024.000f,0.001000f);
  float_Scroll_1->Default = 0.000000f; float_Scroll_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rotate");
  sFloatControl *float_Rotate = gh.Float(&para->Rotate,-16.0000f,16.00000f,0.001000f);
  float_Rotate->Default = 0.000000f; float_Rotate->RightStep = 0.125000f;

  gh.Label(L"* Displace");
  sFloatControl *float_Displace = gh.Float(&para->Displace,-1024.00f,1024.000f,0.010000f);
  float_Displace->Default = 1.000000f; float_Displace->RightStep = 0.125000f;

  gh.Label(L"* Tumble");
  sFloatControl *float_Tumble = gh.Float(&para->Tumble,-16.0000f,16.00000f,0.010000f);
  float_Tumble->Default = 0.000000f; float_Tumble->RightStep = 0.125000f;

  gh.Label(L"* Size");
  sFloatControl *float_Size = gh.Float(&para->Size,-1024.00f,1024.000f,0.010000f);
  float_Size->Default = 0.000000f; float_Size->RightStep = 0.125000f;

  gh.Label(L"* TexBias");
  sFloatControl *float_TexBias = gh.Float(&para->TexBias,-1024.00f,1024.000f,0.010000f);
  float_TexBias->Default = 0.000000f; float_TexBias->RightStep = 0.125000f;

  if((op->ConnectionMask & (1<<2))!=0)
  {
    gh.Group(L"Projection B");

    gh.Label(L"FlagsB");
    gh.Flags(&para->FlagsB,L"*3-|enable:xy|yz|xz:*2plane|circular:*4border|tile|clamp",gh.ChangeMsg);

    gh.Label(L"FlagsB");
    gh.Flags(&para->FlagsB,L"*8add|mul|min|max:*7-|bias",gh.ChangeMsg);

    gh.Label(L"* TransB");
    gh.BeginTied();
    sFloatControl *float_TransB_0 = gh.Float(&para->TransB[0],-1024.00f,1024.000f,0.010000f);
    float_TransB_0->Default = 0.000000f; float_TransB_0->RightStep = 0.125000f;
    sFloatControl *float_TransB_1 = gh.Float(&para->TransB[1],-1024.00f,1024.000f,0.010000f);
    float_TransB_1->Default = 0.000000f; float_TransB_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* ScaleB");
    gh.BeginTied();
    sFloatControl *float_ScaleB_0 = gh.Float(&para->ScaleB[0],-1024.00f,1024.000f,0.010000f);
    float_ScaleB_0->Default = 1.000000f; float_ScaleB_0->RightStep = 0.125000f;
    sFloatControl *float_ScaleB_1 = gh.Float(&para->ScaleB[1],-1024.00f,1024.000f,0.010000f);
    float_ScaleB_1->Default = 1.000000f; float_ScaleB_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* ScrollB");
    gh.BeginTied();
    sFloatControl *float_ScrollB_0 = gh.Float(&para->ScrollB[0],-1024.00f,1024.000f,0.001000f);
    float_ScrollB_0->Default = 0.000000f; float_ScrollB_0->RightStep = 0.125000f;
    sFloatControl *float_ScrollB_1 = gh.Float(&para->ScrollB[1],-1024.00f,1024.000f,0.001000f);
    float_ScrollB_1->Default = 0.000000f; float_ScrollB_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* RotateB");
    sFloatControl *float_RotateB = gh.Float(&para->RotateB,-16.0000f,16.00000f,0.001000f);
    float_RotateB->Default = 0.000000f; float_RotateB->RightStep = 0.125000f;

    gh.Label(L"* DisplaceB");
    sFloatControl *float_DisplaceB = gh.Float(&para->DisplaceB,-1024.00f,1024.000f,0.010000f);
    float_DisplaceB->Default = 1.000000f; float_DisplaceB->RightStep = 0.125000f;

    gh.Label(L"* TumbleB");
    sFloatControl *float_TumbleB = gh.Float(&para->TumbleB,-16.0000f,16.00000f,0.010000f);
    float_TumbleB->Default = 0.000000f; float_TumbleB->RightStep = 0.125000f;

    gh.Label(L"* SizeB");
    sFloatControl *float_SizeB = gh.Float(&para->SizeB,-1024.00f,1024.000f,0.010000f);
    float_SizeB->Default = 0.000000f; float_SizeB->RightStep = 0.125000f;

    gh.Label(L"* TexBiasB");
    sFloatControl *float_TexBiasB = gh.Float(&para->TexBiasB,-1024.00f,1024.000f,0.010000f);
    float_TexBiasB->Default = 0.000000f; float_TexBiasB->RightStep = 0.125000f;

  }
  if((op->ConnectionMask & (1<<3))!=0)
  {
    gh.Group(L"Projection C");

    gh.Label(L"FlagsC");
    gh.Flags(&para->FlagsC,L"*3-|enable:xy|yz|xz:*2plane|circular:*4border|tile|clamp",gh.ChangeMsg);

    gh.Label(L"FlagsC");
    gh.Flags(&para->FlagsC,L"*8add|mul|min|max:*7-|bias",gh.ChangeMsg);

    gh.Label(L"* TransC");
    gh.BeginTied();
    sFloatControl *float_TransC_0 = gh.Float(&para->TransC[0],-1024.00f,1024.000f,0.010000f);
    float_TransC_0->Default = 0.000000f; float_TransC_0->RightStep = 0.125000f;
    sFloatControl *float_TransC_1 = gh.Float(&para->TransC[1],-1024.00f,1024.000f,0.010000f);
    float_TransC_1->Default = 0.000000f; float_TransC_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* ScaleC");
    gh.BeginTied();
    sFloatControl *float_ScaleC_0 = gh.Float(&para->ScaleC[0],-1024.00f,1024.000f,0.010000f);
    float_ScaleC_0->Default = 1.000000f; float_ScaleC_0->RightStep = 0.125000f;
    sFloatControl *float_ScaleC_1 = gh.Float(&para->ScaleC[1],-1024.00f,1024.000f,0.010000f);
    float_ScaleC_1->Default = 1.000000f; float_ScaleC_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* ScrollC");
    gh.BeginTied();
    sFloatControl *float_ScrollC_0 = gh.Float(&para->ScrollC[0],-1024.00f,1024.000f,0.001000f);
    float_ScrollC_0->Default = 0.000000f; float_ScrollC_0->RightStep = 0.125000f;
    sFloatControl *float_ScrollC_1 = gh.Float(&para->ScrollC[1],-1024.00f,1024.000f,0.001000f);
    float_ScrollC_1->Default = 0.000000f; float_ScrollC_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* RotateC");
    sFloatControl *float_RotateC = gh.Float(&para->RotateC,-16.0000f,16.00000f,0.001000f);
    float_RotateC->Default = 0.000000f; float_RotateC->RightStep = 0.125000f;

    gh.Label(L"* DisplaceC");
    sFloatControl *float_DisplaceC = gh.Float(&para->DisplaceC,-1024.00f,1024.000f,0.010000f);
    float_DisplaceC->Default = 1.000000f; float_DisplaceC->RightStep = 0.125000f;

    gh.Label(L"* TumbleC");
    sFloatControl *float_TumbleC = gh.Float(&para->TumbleC,-16.0000f,16.00000f,0.010000f);
    float_TumbleC->Default = 0.000000f; float_TumbleC->RightStep = 0.125000f;

    gh.Label(L"* SizeC");
    sFloatControl *float_SizeC = gh.Float(&para->SizeC,-1024.00f,1024.000f,0.010000f);
    float_SizeC->Default = 0.000000f; float_SizeC->RightStep = 0.125000f;

    gh.Label(L"* TexBiasC");
    sFloatControl *float_TexBiasC = gh.Float(&para->TexBiasC,-1024.00f,1024.000f,0.010000f);
    float_TexBiasC->Default = 0.000000f; float_TexBiasC->RightStep = 0.125000f;

  }
  if((para->Mode&0x0001))
  {
    gh.Group(L"Instance Multiplies");

    gh.Label(L"Mode");
    gh.Flags(&para->Mode,L"*2-|Center:*3-|reverse",gh.ChangeMsg);

    gh.Label(L"* Normal");
    gh.BeginTied();
    sFloatControl *float_Normal_0 = gh.Float(&para->Normal.x,-1024.00f,1024.000f,0.010000f);
    float_Normal_0->Default = 0.000000f; float_Normal_0->RightStep = 0.125000f;
    sFloatControl *float_Normal_1 = gh.Float(&para->Normal.y,-1024.00f,1024.000f,0.010000f);
    float_Normal_1->Default = 1.000000f; float_Normal_1->RightStep = 0.125000f;
    sFloatControl *float_Normal_2 = gh.Float(&para->Normal.z,-1024.00f,1024.000f,0.010000f);
    float_Normal_2->Default = 0.000000f; float_Normal_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Pretransform");
    gh.BeginTied();
    sFloatControl *float_Trans0_0 = gh.Float(&para->Trans0.x,-65536.0f,65536.00f,0.010000f);
    float_Trans0_0->Default = 0.000000f; float_Trans0_0->RightStep = 0.125000f;
    sFloatControl *float_Trans0_1 = gh.Float(&para->Trans0.y,-65536.0f,65536.00f,0.010000f);
    float_Trans0_1->Default = 0.000000f; float_Trans0_1->RightStep = 0.125000f;
    sFloatControl *float_Trans0_2 = gh.Float(&para->Trans0.z,-65536.0f,65536.00f,0.010000f);
    float_Trans0_2->Default = 0.000000f; float_Trans0_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Count1");
    sIntControl *int_Count1 = gh.Int(&para->Count1,1,1024,0.125000f);
    int_Count1->Default = 0x00000002; int_Count1->RightStep = 0.125000f;

    gh.Label(L"* Trans1");
    gh.BeginTied();
    sFloatControl *float_Trans1_0 = gh.Float(&para->Trans1.x,-65536.0f,65536.00f,0.010000f);
    float_Trans1_0->Default = 0.000000f; float_Trans1_0->RightStep = 0.125000f;
    sFloatControl *float_Trans1_1 = gh.Float(&para->Trans1.y,-65536.0f,65536.00f,0.010000f);
    float_Trans1_1->Default = 0.000000f; float_Trans1_1->RightStep = 0.125000f;
    sFloatControl *float_Trans1_2 = gh.Float(&para->Trans1.z,-65536.0f,65536.00f,0.010000f);
    float_Trans1_2->Default = 0.000000f; float_Trans1_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Count2");
    sIntControl *int_Count2 = gh.Int(&para->Count2,1,1024,0.125000f);
    int_Count2->Default = 0x00000001; int_Count2->RightStep = 0.125000f;
    int_Count2->DoneMsg = gh.LayoutMsg;

  }
  if(((para->Mode&0x0001)&&(para->Count2!=0x0001)))
  {
    gh.Label(L"* Trans2");
    gh.BeginTied();
    sFloatControl *float_Trans2_0 = gh.Float(&para->Trans2.x,-65536.0f,65536.00f,0.010000f);
    float_Trans2_0->Default = 0.000000f; float_Trans2_0->RightStep = 0.125000f;
    sFloatControl *float_Trans2_1 = gh.Float(&para->Trans2.y,-65536.0f,65536.00f,0.010000f);
    float_Trans2_1->Default = 0.000000f; float_Trans2_1->RightStep = 0.125000f;
    sFloatControl *float_Trans2_2 = gh.Float(&para->Trans2.z,-65536.0f,65536.00f,0.010000f);
    float_Trans2_2->Default = 0.000000f; float_Trans2_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Count3");
    sIntControl *int_Count3 = gh.Int(&para->Count3,1,1024,0.125000f);
    int_Count3->Default = 0x00000001; int_Count3->RightStep = 0.125000f;
    int_Count3->DoneMsg = gh.LayoutMsg;

  }
  if((((para->Mode&0x0001)&&(para->Count2!=0x0001))&&(para->Count3!=0x0001)))
  {
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

void Wz4RenderDefDebrisClassic(wOp *op)
{
  Wz4RenderParaDebrisClassic sUNUSED *para = (Wz4RenderParaDebrisClassic *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x0000000a;
  para->Scale[0] = 1.000000f;
  para->Scale[1] = 1.000000f;
  para->Displace = 1.000000f;
  para->FlagsB = 0x0000000a;
  para->ScaleB[0] = 1.000000f;
  para->ScaleB[1] = 1.000000f;
  para->DisplaceB = 1.000000f;
  para->FlagsC = 0x0000000a;
  para->ScaleC[0] = 1.000000f;
  para->ScaleC[1] = 1.000000f;
  para->DisplaceC = 1.000000f;
  para->Normal.y = 1.000000f;
  para->Count1 = 0x00000002;
  para->Count2 = 0x00000001;
  para->Count3 = 0x00000001;
}

void Wz4RenderBindDebrisClassic(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"scroll"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"scroll"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"displace"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"tumble"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"texbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"transb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"transb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"scaleb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"scaleb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"scrollb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"scrollb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"rotateb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"displaceb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"tumbleb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"sizeb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"texbiasb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"transc"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"transc"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"scalec"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"scalec"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"scrollc"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"scrollc"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"rotatec"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"displacec"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"tumblec"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"sizec"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"texbiasc"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"normal"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"normal"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"normal"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"pretransform"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"pretransform"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"pretransform"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"count1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+46;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+46;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+46;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+49;
  ctx->BindLocal(ctx->AddSymbol(L"count2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+50;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+50;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+50;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+53;
  ctx->BindLocal(ctx->AddSymbol(L"count3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2DebrisClassic(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[48];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"mode");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"flags");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"trans");
    name[7] = sPoolString(L"scale");
    name[8] = sPoolString(L"scroll");
    name[9] = sPoolString(L"rotate");
    name[10] = sPoolString(L"displace");
    name[11] = sPoolString(L"tumble");
    name[12] = sPoolString(L"size");
    name[13] = sPoolString(L"texbias");
    name[14] = sPoolString(L"");
    name[15] = sPoolString(L"flagsb");
    name[16] = sPoolString(L"flagsb");
    name[17] = sPoolString(L"transb");
    name[18] = sPoolString(L"scaleb");
    name[19] = sPoolString(L"scrollb");
    name[20] = sPoolString(L"rotateb");
    name[21] = sPoolString(L"displaceb");
    name[22] = sPoolString(L"tumbleb");
    name[23] = sPoolString(L"sizeb");
    name[24] = sPoolString(L"texbiasb");
    name[25] = sPoolString(L"");
    name[26] = sPoolString(L"flagsc");
    name[27] = sPoolString(L"flagsc");
    name[28] = sPoolString(L"transc");
    name[29] = sPoolString(L"scalec");
    name[30] = sPoolString(L"scrollc");
    name[31] = sPoolString(L"rotatec");
    name[32] = sPoolString(L"displacec");
    name[33] = sPoolString(L"tumblec");
    name[34] = sPoolString(L"sizec");
    name[35] = sPoolString(L"texbiasc");
    name[36] = sPoolString(L"");
    name[37] = sPoolString(L"mode");
    name[38] = sPoolString(L"normal");
    name[39] = sPoolString(L"pretransform");
    name[40] = sPoolString(L"count1");
    name[41] = sPoolString(L"trans1");
    name[42] = sPoolString(L"count2");
    name[43] = sPoolString(L"trans2");
    name[44] = sPoolString(L"count3");
    name[45] = sPoolString(L"trans3");
    name[46] = sPoolString(L"");
    name[47] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[6],ScriptTypeFloat,2,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeFloat,2,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeFloat,2,cmd->Data+9);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+32);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+35);
  ctx->AddImport(name[17],ScriptTypeFloat,2,cmd->Data+13);
  ctx->AddImport(name[18],ScriptTypeFloat,2,cmd->Data+15);
  ctx->AddImport(name[19],ScriptTypeFloat,2,cmd->Data+17);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+33);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+36);
  ctx->AddImport(name[28],ScriptTypeFloat,2,cmd->Data+23);
  ctx->AddImport(name[29],ScriptTypeFloat,2,cmd->Data+25);
  ctx->AddImport(name[30],ScriptTypeFloat,2,cmd->Data+27);
  ctx->AddImport(name[31],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[32],ScriptTypeFloat,1,cmd->Data+30);
  ctx->AddImport(name[33],ScriptTypeFloat,1,cmd->Data+31);
  ctx->AddImport(name[34],ScriptTypeFloat,1,cmd->Data+34);
  ctx->AddImport(name[35],ScriptTypeFloat,1,cmd->Data+37);
  ctx->AddImport(name[38],ScriptTypeFloat,3,cmd->Data+39);
  ctx->AddImport(name[39],ScriptTypeFloat,3,cmd->Data+42);
  ctx->AddImport(name[40],ScriptTypeInt,1,cmd->Data+45);
  ctx->AddImport(name[41],ScriptTypeFloat,3,cmd->Data+46);
  ctx->AddImport(name[42],ScriptTypeInt,1,cmd->Data+49);
  ctx->AddImport(name[43],ScriptTypeFloat,3,cmd->Data+50);
  ctx->AddImport(name[44],ScriptTypeInt,1,cmd->Data+53);
  ctx->AddImport(name[45],ScriptTypeFloat,3,cmd->Data+54);
  ctx->AddImport(name[47],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3DebrisClassic(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import trans : float[2];\n");
  tb.PrintF(L"  import scale : float[2];\n");
  tb.PrintF(L"  import scroll : float[2];\n");
  tb.PrintF(L"  import rotate : float;\n");
  tb.PrintF(L"  import displace : float;\n");
  tb.PrintF(L"  import tumble : float;\n");
  tb.PrintF(L"  import size : float;\n");
  tb.PrintF(L"  import texbias : float;\n");
  tb.PrintF(L"  import transb : float[2];\n");
  tb.PrintF(L"  import scaleb : float[2];\n");
  tb.PrintF(L"  import scrollb : float[2];\n");
  tb.PrintF(L"  import rotateb : float;\n");
  tb.PrintF(L"  import displaceb : float;\n");
  tb.PrintF(L"  import tumbleb : float;\n");
  tb.PrintF(L"  import sizeb : float;\n");
  tb.PrintF(L"  import texbiasb : float;\n");
  tb.PrintF(L"  import transc : float[2];\n");
  tb.PrintF(L"  import scalec : float[2];\n");
  tb.PrintF(L"  import scrollc : float[2];\n");
  tb.PrintF(L"  import rotatec : float;\n");
  tb.PrintF(L"  import displacec : float;\n");
  tb.PrintF(L"  import tumblec : float;\n");
  tb.PrintF(L"  import sizec : float;\n");
  tb.PrintF(L"  import texbiasc : float;\n");
  tb.PrintF(L"  import normal : float[3];\n");
  tb.PrintF(L"  import pretransform : float[3];\n");
  tb.PrintF(L"  import count1 : int;\n");
  tb.PrintF(L"  import trans1 : float[3];\n");
  tb.PrintF(L"  import count2 : int;\n");
  tb.PrintF(L"  import trans2 : float[3];\n");
  tb.PrintF(L"  import count3 : int;\n");
  tb.PrintF(L"  import trans3 : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiDebrisClassic =
L"= Wz4Render : DebrisClassic\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DebrisClassic\n"
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
L" !i BitmapBase\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i BitmapBase\n"
L" !i optional\n"
L" !i *\n"
L"\n"
L" !i BitmapBase\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i chunks\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i instances\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i enable\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i xy\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i yz\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i xz\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i plane\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i circular\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i border\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i bias\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Scroll\n"
L" !i Scroll\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Rotate\n"
L" !i Rotate\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Displace\n"
L" !i Displace\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Tumble\n"
L" !i Tumble\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexBias\n"
L" !i TexBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i FlagsB\n"
L" !i FlagsB\n"
L" !i enable\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i xy\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i yz\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i xz\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i plane\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i circular\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i border\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i FlagsB\n"
L" !i FlagsB\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i min\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i max\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i bias\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i TransB\n"
L" !i TransB\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScaleB\n"
L" !i ScaleB\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScrollB\n"
L" !i ScrollB\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i RotateB\n"
L" !i RotateB\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DisplaceB\n"
L" !i DisplaceB\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TumbleB\n"
L" !i TumbleB\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SizeB\n"
L" !i SizeB\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexBiasB\n"
L" !i TexBiasB\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i FlagsC\n"
L" !i FlagsC\n"
L" !i enable\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i xy\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i yz\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i xz\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i plane\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i circular\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i border\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i FlagsC\n"
L" !i FlagsC\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i min\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i max\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i bias\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i TransC\n"
L" !i TransC\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScaleC\n"
L" !i ScaleC\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i ScrollC\n"
L" !i ScrollC\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i RotateC\n"
L" !i RotateC\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DisplaceC\n"
L" !i DisplaceC\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TumbleC\n"
L" !i TumbleC\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SizeC\n"
L" !i SizeC\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexBiasC\n"
L" !i TexBiasC\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
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
L" !i Normal\n"
L" !i Normal\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Pretransform\n"
L" !i Trans0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count1\n"
L" !i Count1\n"
L" !i int\n"
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

sBool Wz4RenderCmdBoneVibrate(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBoneVibrate sUNUSED *para = (Wz4RenderParaBoneVibrate *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 338 "chaosfx_ops.ops"

    RNBoneVibrate *node = new RNBoneVibrate();
    node->ParaBase = node->Para = *para;
    in0->Charge();
    node->Mesh = in0; in0->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 2800 "chaosfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiBoneVibrate(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBoneVibrate sUNUSED *para = (Wz4RenderParaBoneVibrate *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Group(L"Vibrate");

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"* Freq");
  sFloatControl *float_Freq = gh.Float(&para->Freq,0.000000f,1024.000f,0.010000f);
  float_Freq->Default = 1.000000f; float_Freq->RightStep = 0.125000f;

  gh.Label(L"* Trans");
  sFloatControl *float_Trans = gh.Float(&para->Trans,-1024.00f,1024.000f,0.001000f);
  float_Trans->Default = 1.000000f; float_Trans->RightStep = 0.125000f;

  gh.Label(L"* Rot");
  sFloatControl *float_Rot = gh.Float(&para->Rot,-1024.00f,1024.000f,0.001000f);
  float_Rot->Default = 0.000000f; float_Rot->RightStep = 0.125000f;

  gh.Label(L"* Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,-1024.00f,1024.000f,0.010000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;

  gh.Label(L"FirstBone");
  sIntControl *int_FirstBone = gh.Int(&para->FirstBone,0,1024,0.125000f);
  int_FirstBone->Default = 0x00000000; int_FirstBone->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefBoneVibrate(wOp *op)
{
  Wz4RenderParaBoneVibrate sUNUSED *para = (Wz4RenderParaBoneVibrate *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Freq = 1.000000f;
  para->Trans = 1.000000f;
}

void Wz4RenderBindBoneVibrate(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"firstbone"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2BoneVibrate(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"vibrate");
    name[3] = sPoolString(L"seed");
    name[4] = sPoolString(L"freq");
    name[5] = sPoolString(L"trans");
    name[6] = sPoolString(L"rot");
    name[7] = sPoolString(L"phase");
    name[8] = sPoolString(L"firstbone");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+7);
  ctx->AddImport(name[10],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3BoneVibrate(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import freq : float;\n");
  tb.PrintF(L"  import trans : float;\n");
  tb.PrintF(L"  import rot : float;\n");
  tb.PrintF(L"  import phase : float;\n");
  tb.PrintF(L"  import firstbone : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBoneVibrate =
L"= Wz4Render : BoneVibrate\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BoneVibrate\n"
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
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Freq\n"
L" !i Freq\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Phase\n"
L" !i Phase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FirstBone\n"
L" !i FirstBone\n"
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

void Wz4RenderAnimCubeExample::Init(class ScriptContext *sc)
{
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
};

void Wz4RenderAnimCubeExample::Bind(class ScriptContext *sc,Wz4RenderParaCubeExample *para)
{
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
};

void Wz4RenderAnimPrint::Init(class ScriptContext *sc)
{
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
  _Color = sc->AddSymbol(L"color_");
};

void Wz4RenderAnimPrint::Bind(class ScriptContext *sc,Wz4RenderParaPrint *para)
{
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalColor(_Color,&para->Color);
};

void Wz4RenderAnimRibbons::Init(class ScriptContext *sc)
{
  _Trans = sc->AddSymbol(L"trans");
  _Forward = sc->AddSymbol(L"forward");
  _Side = sc->AddSymbol(L"side");
  _Steps = sc->AddSymbol(L"steps");
  _Around = sc->AddSymbol(L"around");
  _Waber = sc->AddSymbol(L"waber");
  _Freq = sc->AddSymbol(L"freq");
  _Spread = sc->AddSymbol(L"spread");
  _Start = sc->AddSymbol(L"start");
};

void Wz4RenderAnimRibbons::Bind(class ScriptContext *sc,Wz4RenderParaRibbons *para)
{
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Forward,1,&para->Forward);
  sc->BindLocalFloat(_Side,1,&para->Side);
  sc->BindLocalInt(_Steps,1,&para->Steps);
  sc->BindLocalInt(_Around,1,&para->Around);
  sc->BindLocalFloat(_Waber,3,para->Waber);
  sc->BindLocalFloat(_Freq,3,para->Freq);
  sc->BindLocalFloat(_Spread,3,para->Spread);
  sc->BindLocalFloat(_Start,3,para->Start);
};

void Wz4RenderAnimRibbons2::Init(class ScriptContext *sc)
{
  _Trans = sc->AddSymbol(L"trans");
  _Forward = sc->AddSymbol(L"forward");
  _Side = sc->AddSymbol(L"side");
};

void Wz4RenderAnimRibbons2::Bind(class ScriptContext *sc,Wz4RenderParaRibbons2 *para)
{
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Forward,1,&para->Forward);
  sc->BindLocalFloat(_Side,1,&para->Side);
};

void Wz4RenderAnimBlowNoise::Init(class ScriptContext *sc)
{
  _Scale = sc->AddSymbol(L"scale");
  _Scroll = sc->AddSymbol(L"scroll");
};

void Wz4RenderAnimBlowNoise::Bind(class ScriptContext *sc,Wz4RenderParaBlowNoise *para)
{
  sc->BindLocalFloat(_Scale,1,&para->Scale);
  sc->BindLocalFloat(_Scroll,1,&para->Scroll);
};

void Wz4RenderAnimDebrisClassic::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
  _Trans = sc->AddSymbol(L"trans");
  _Scale = sc->AddSymbol(L"scale");
  _Scroll = sc->AddSymbol(L"scroll");
  _Rotate = sc->AddSymbol(L"rotate");
  _Displace = sc->AddSymbol(L"displace");
  _Tumble = sc->AddSymbol(L"tumble");
  _Size = sc->AddSymbol(L"size");
  _TexBias = sc->AddSymbol(L"texbias");
  _TransB = sc->AddSymbol(L"transb");
  _ScaleB = sc->AddSymbol(L"scaleb");
  _ScrollB = sc->AddSymbol(L"scrollb");
  _RotateB = sc->AddSymbol(L"rotateb");
  _DisplaceB = sc->AddSymbol(L"displaceb");
  _TumbleB = sc->AddSymbol(L"tumbleb");
  _SizeB = sc->AddSymbol(L"sizeb");
  _TexBiasB = sc->AddSymbol(L"texbiasb");
  _TransC = sc->AddSymbol(L"transc");
  _ScaleC = sc->AddSymbol(L"scalec");
  _ScrollC = sc->AddSymbol(L"scrollc");
  _RotateC = sc->AddSymbol(L"rotatec");
  _DisplaceC = sc->AddSymbol(L"displacec");
  _TumbleC = sc->AddSymbol(L"tumblec");
  _SizeC = sc->AddSymbol(L"sizec");
  _TexBiasC = sc->AddSymbol(L"texbiasc");
  _Normal = sc->AddSymbol(L"normal");
  _Trans0 = sc->AddSymbol(L"pretransform");
  _Count1 = sc->AddSymbol(L"count1");
  _Trans1 = sc->AddSymbol(L"trans1");
  _Count2 = sc->AddSymbol(L"count2");
  _Trans2 = sc->AddSymbol(L"trans2");
  _Count3 = sc->AddSymbol(L"count3");
  _Trans3 = sc->AddSymbol(L"trans3");
};

void Wz4RenderAnimDebrisClassic::Bind(class ScriptContext *sc,Wz4RenderParaDebrisClassic *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_Trans,2,para->Trans);
  sc->BindLocalFloat(_Scale,2,para->Scale);
  sc->BindLocalFloat(_Scroll,2,para->Scroll);
  sc->BindLocalFloat(_Rotate,1,&para->Rotate);
  sc->BindLocalFloat(_Displace,1,&para->Displace);
  sc->BindLocalFloat(_Tumble,1,&para->Tumble);
  sc->BindLocalFloat(_Size,1,&para->Size);
  sc->BindLocalFloat(_TexBias,1,&para->TexBias);
  sc->BindLocalFloat(_TransB,2,para->TransB);
  sc->BindLocalFloat(_ScaleB,2,para->ScaleB);
  sc->BindLocalFloat(_ScrollB,2,para->ScrollB);
  sc->BindLocalFloat(_RotateB,1,&para->RotateB);
  sc->BindLocalFloat(_DisplaceB,1,&para->DisplaceB);
  sc->BindLocalFloat(_TumbleB,1,&para->TumbleB);
  sc->BindLocalFloat(_SizeB,1,&para->SizeB);
  sc->BindLocalFloat(_TexBiasB,1,&para->TexBiasB);
  sc->BindLocalFloat(_TransC,2,para->TransC);
  sc->BindLocalFloat(_ScaleC,2,para->ScaleC);
  sc->BindLocalFloat(_ScrollC,2,para->ScrollC);
  sc->BindLocalFloat(_RotateC,1,&para->RotateC);
  sc->BindLocalFloat(_DisplaceC,1,&para->DisplaceC);
  sc->BindLocalFloat(_TumbleC,1,&para->TumbleC);
  sc->BindLocalFloat(_SizeC,1,&para->SizeC);
  sc->BindLocalFloat(_TexBiasC,1,&para->TexBiasC);
  sc->BindLocalFloat(_Normal,3,&para->Normal.x);
  sc->BindLocalFloat(_Trans0,3,&para->Trans0.x);
  sc->BindLocalInt(_Count1,1,&para->Count1);
  sc->BindLocalFloat(_Trans1,3,&para->Trans1.x);
  sc->BindLocalInt(_Count2,1,&para->Count2);
  sc->BindLocalFloat(_Trans2,3,&para->Trans2.x);
  sc->BindLocalInt(_Count3,1,&para->Count3);
  sc->BindLocalFloat(_Trans3,3,&para->Trans3.x);
};

void Wz4RenderAnimBoneVibrate::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
  _Freq = sc->AddSymbol(L"freq");
  _Trans = sc->AddSymbol(L"trans");
  _Rot = sc->AddSymbol(L"rot");
  _Phase = sc->AddSymbol(L"phase");
};

void Wz4RenderAnimBoneVibrate::Bind(class ScriptContext *sc,Wz4RenderParaBoneVibrate *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_Freq,1,&para->Freq);
  sc->BindLocalFloat(_Trans,1,&para->Trans);
  sc->BindLocalFloat(_Rot,1,&para->Rot);
  sc->BindLocalFloat(_Phase,1,&para->Phase);
};


/****************************************************************************/

void AddTypes_chaosfx_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_chaosfx_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"CubeExample";
  cl->Label = L"CubeExample";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCubeExample;
  cl->MakeGui = Wz4RenderGuiCubeExample;
  cl->SetDefaults = Wz4RenderDefCubeExample;
  cl->BindPara = Wz4RenderBindCubeExample;
  cl->Bind2Para = Wz4RenderBind2CubeExample;
  cl->Bind3Para = Wz4RenderBind3CubeExample;
  cl->WikiText = Wz4RenderWikiCubeExample;
  cl->ParaStrings = 1;
  cl->ParaWords = 12;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Print";
  cl->Label = L"Print";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdPrint;
  cl->MakeGui = Wz4RenderGuiPrint;
  cl->SetDefaults = Wz4RenderDefPrint;
  cl->BindPara = Wz4RenderBindPrint;
  cl->Bind2Para = Wz4RenderBind2Print;
  cl->Bind3Para = Wz4RenderBind3Print;
  cl->WikiText = Wz4RenderWikiPrint;
  cl->ParaStrings = 2;
  cl->ParaWords = 11;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosFontType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Ribbons";
  cl->Label = L"Ribbons";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdRibbons;
  cl->MakeGui = Wz4RenderGuiRibbons;
  cl->SetDefaults = Wz4RenderDefRibbons;
  cl->BindPara = Wz4RenderBindRibbons;
  cl->Bind2Para = Wz4RenderBind2Ribbons;
  cl->Bind3Para = Wz4RenderBind3Ribbons;
  cl->WikiText = Wz4RenderWikiRibbons;
  cl->ParaStrings = 1;
  cl->ParaWords = 21;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Ribbons2";
  cl->Label = L"Ribbons2";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdRibbons2;
  cl->MakeGui = Wz4RenderGuiRibbons2;
  cl->SetDefaults = Wz4RenderDefRibbons2;
  cl->BindPara = Wz4RenderBindRibbons2;
  cl->Bind2Para = Wz4RenderBind2Ribbons2;
  cl->Bind3Para = Wz4RenderBind3Ribbons2;
  cl->WikiText = Wz4RenderWikiRibbons2;
  cl->Handles = Wz4RenderHndRibbons2;
  cl->ParaStrings = 1;
  cl->ParaWords = 28;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BlowNoise";
  cl->Label = L"BlowNoise";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBlowNoise;
  cl->MakeGui = Wz4RenderGuiBlowNoise;
  cl->SetDefaults = Wz4RenderDefBlowNoise;
  cl->BindPara = Wz4RenderBindBlowNoise;
  cl->Bind2Para = Wz4RenderBind2BlowNoise;
  cl->Bind3Para = Wz4RenderBind3BlowNoise;
  cl->WikiText = Wz4RenderWikiBlowNoise;
  cl->SetDefaultsArray = Wz4RenderArrBlowNoise;
  cl->ArrayCount = 6;
  cl->ParaStrings = 1;
  cl->ParaWords = 6;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DebrisClassic";
  cl->Label = L"Debris";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdDebrisClassic;
  cl->MakeGui = Wz4RenderGuiDebrisClassic;
  cl->SetDefaults = Wz4RenderDefDebrisClassic;
  cl->BindPara = Wz4RenderBindDebrisClassic;
  cl->Bind2Para = Wz4RenderBind2DebrisClassic;
  cl->Bind3Para = Wz4RenderBind3DebrisClassic;
  cl->WikiText = Wz4RenderWikiDebrisClassic;
  cl->ParaStrings = 1;
  cl->ParaWords = 57;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(4);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = BitmapBaseType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = BitmapBaseType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0|wCIF_OPTIONAL;
  in[3].Type = BitmapBaseType;
  in[3].DefaultClass = 0;
  in[3].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BoneVibrate";
  cl->Label = L"BoneVibrate";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBoneVibrate;
  cl->MakeGui = Wz4RenderGuiBoneVibrate;
  cl->SetDefaults = Wz4RenderDefBoneVibrate;
  cl->BindPara = Wz4RenderBindBoneVibrate;
  cl->Bind2Para = Wz4RenderBind2BoneVibrate;
  cl->Bind3Para = Wz4RenderBind3BoneVibrate;
  cl->WikiText = Wz4RenderWikiBoneVibrate;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(chaosfx_ops,0x110,AddOps_chaosfx_ops,0);


/****************************************************************************/


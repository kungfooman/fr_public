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
#include "wz4_ipp_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 14 "wz4_ipp_ops.ops"

#include "wz4frlib/wz4_ipp.hpp"

#line 26 "wz4_ipp_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdColorCorrect(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaColorCorrect sUNUSED *para = (Wz4RenderParaColorCorrect *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 32 "wz4_ipp_ops.ops"

    RNColorCorrect *node = new RNColorCorrect();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 48 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiColorCorrect(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaColorCorrect sUNUSED *para = (Wz4RenderParaColorCorrect *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  gh.Label(L"* Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefColorCorrect(wOp *op)
{
  Wz4RenderParaColorCorrect sUNUSED *para = (Wz4RenderParaColorCorrect *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color0 = 0xffffffff;
  para->Color1 = 0xff000000;
}

void Wz4RenderBindColorCorrect(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ColorCorrect(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"color0");
    name[2] = sPoolString(L"color1");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ColorCorrect(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiColorCorrect =
L"= Wz4Render : ColorCorrect\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ColorCorrect\n"
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
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
L" !i color\n"
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

sBool Wz4RenderCmdDebugZ(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaDebugZ sUNUSED *para = (Wz4RenderParaDebugZ *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 53 "wz4_ipp_ops.ops"

    RNDebugZ *node = new RNDebugZ();
    node->ParaBase = node->Para = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 208 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiDebugZ(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaDebugZ sUNUSED *para = (Wz4RenderParaDebugZ *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Channel");
  gh.Flags(&para->Channel,L"z|normal|alpha",gh.ChangeMsg);

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

void Wz4RenderDefDebugZ(wOp *op)
{
  Wz4RenderParaDebugZ sUNUSED *para = (Wz4RenderParaDebugZ *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindDebugZ(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2DebugZ(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"channel");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3DebugZ(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiDebugZ =
L"= Wz4Render : DebugZ\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DebugZ\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Channel\n"
L" !i Channel\n"
L" !i z\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdBlur(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBlur sUNUSED *para = (Wz4RenderParaBlur *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 89 "wz4_ipp_ops.ops"

    RNBlur *node = new RNBlur();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 355 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiBlur(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBlur sUNUSED *para = (Wz4RenderParaBlur *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,0.000000f,4096.000f,0.010000f);
  float_Radius->Default = 1.000000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"* Amp");
  sFloatControl *float_Amp = gh.Float(&para->Amp,0.000000f,256.0000f,0.010000f);
  float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;

  gh.Label(L"Unit");
  gh.Flags(&para->Unit,L"pixel|hd-pixel",gh.ChangeMsg);

  gh.Label(L"MaxPasses");
  sIntControl *int_MaxPasses = gh.Int(&para->MaxPasses,1,16,0.125000f);
  int_MaxPasses->Default = 0x00000003; int_MaxPasses->RightStep = 0.125000f;

  gh.Label(L"* Sharpen");
  gh.Flags(&para->SharpenFlag,L"-|on|control",gh.LayoutMsg);

  if((para->SharpenFlag==0x0001))
  {
    gh.Label(L"* Sharpen");
    sFloatControl *float_Sharpen = gh.Float(&para->Sharpen,0.000000f,4.000000f,0.010000f);
    float_Sharpen->Default = 0.250000f; float_Sharpen->RightStep = 0.125000f;

  }
  if((para->SharpenFlag==0x0002))
  {
    gh.Label(L"* Sharpen0");
    gh.ColorPick(&para->Sharpen0,L"rgba",0);

    sFloatControl *float_Sharpen0Amp = gh.Float(&para->Sharpen0Amp,-64.0000f,64.00000f,0.010000f);
    float_Sharpen0Amp->Default = 0.500000f; float_Sharpen0Amp->RightStep = 0.125000f;

    gh.Label(L"* Sharpen1");
    gh.ColorPick(&para->Sharpen1,L"rgba",0);

    sFloatControl *float_Sharpen1Amp = gh.Float(&para->Sharpen1Amp,-64.0000f,64.00000f,0.010000f);
    float_Sharpen1Amp->Default = 2.000000f; float_Sharpen1Amp->RightStep = 0.125000f;

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefBlur(wOp *op)
{
  Wz4RenderParaBlur sUNUSED *para = (Wz4RenderParaBlur *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Radius = 1.000000f;
  para->Amp = 1.000000f;
  para->Unit = 0x00000001;
  para->MaxPasses = 0x00000003;
  para->Sharpen = 0.250000f;
  para->Sharpen0 = 0xffffffff;
  para->Sharpen0Amp = 0.500000f;
  para->Sharpen1 = 0xffffffff;
  para->Sharpen1Amp = 2.000000f;
}

void Wz4RenderBindBlur(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"maxpasses"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"sharpen"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"sharpen0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"sharpen0amp"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"sharpen1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"sharpen1amp"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Blur(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"radius");
    name[2] = sPoolString(L"amp");
    name[3] = sPoolString(L"unit");
    name[4] = sPoolString(L"maxpasses");
    name[5] = sPoolString(L"sharpenflag");
    name[6] = sPoolString(L"sharpen");
    name[7] = sPoolString(L"sharpen0");
    name[8] = sPoolString(L"sharpen0amp");
    name[9] = sPoolString(L"sharpen1");
    name[10] = sPoolString(L"sharpen1amp");
    name[11] = sPoolString(L"");
    name[12] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeColor,1,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeColor,1,cmd->Data+9);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[12],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Blur(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import radius : float;\n");
  tb.PrintF(L"  import amp : float;\n");
  tb.PrintF(L"  import maxpasses : int;\n");
  tb.PrintF(L"  import sharpen : float;\n");
  tb.PrintF(L"  import sharpen0 : color;\n");
  tb.PrintF(L"  import sharpen0amp : float;\n");
  tb.PrintF(L"  import sharpen1 : color;\n");
  tb.PrintF(L"  import sharpen1amp : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBlur =
L"= Wz4Render : Blur\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Blur\n"
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
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Unit\n"
L" !i Unit\n"
L" !i pixel\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i hd-pixel\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MaxPasses\n"
L" !i MaxPasses\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i * Sharpen\n"
L" !i SharpenFlag\n"
L" !i on\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i control\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Sharpen\n"
L" !i Sharpen\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Sharpen0\n"
L" !i Sharpen0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Sharpen0Amp\n"
L" !i Sharpen0Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Sharpen1\n"
L" !i Sharpen1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Sharpen1Amp\n"
L" !i Sharpen1Amp\n"
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

sBool Wz4RenderCmdDepthOfField(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaDepthOfField sUNUSED *para = (Wz4RenderParaDepthOfField *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 116 "wz4_ipp_ops.ops"

    RNDof *node = new RNDof();
    node->ParaBase = node->Para = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 644 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiDepthOfField(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaDepthOfField sUNUSED *para = (Wz4RenderParaDepthOfField *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Depth");
  gh.BeginTied();
  sFloatControl *float_Depth_0 = gh.Float(&para->Depth[0],-65536.0f,65536.00f,0.125000f);
  float_Depth_0->Default = 8.000000f; float_Depth_0->RightStep = 0.125000f;
  sFloatControl *float_Depth_1 = gh.Float(&para->Depth[1],-65536.0f,65536.00f,0.125000f);
  float_Depth_1->Default = 16.00000f; float_Depth_1->RightStep = 0.125000f;
  sFloatControl *float_Depth_2 = gh.Float(&para->Depth[2],-65536.0f,65536.00f,0.125000f);
  float_Depth_2->Default = 256.0000f; float_Depth_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Blur");
  gh.BeginTied();
  sFloatControl *float_Blur_0 = gh.Float(&para->Blur[0],0.000000f,1.000000f,0.001000f);
  float_Blur_0->Default = 1.000000f; float_Blur_0->RightStep = 0.125000f;
  sFloatControl *float_Blur_1 = gh.Float(&para->Blur[1],0.000000f,1.000000f,0.001000f);
  float_Blur_1->Default = 0.000000f; float_Blur_1->RightStep = 0.125000f;
  sFloatControl *float_Blur_2 = gh.Float(&para->Blur[2],0.000000f,1.000000f,0.001000f);
  float_Blur_2->Default = 1.000000f; float_Blur_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* CenterSize");
  sFloatControl *float_CenterSize = gh.Float(&para->CenterSize,0.000000f,65536.00f,0.125000f);
  float_CenterSize->Default = 4.000000f; float_CenterSize->RightStep = 0.125000f;

  gh.Group(L"blur");

  gh.Label(L"* BlurRadius");
  gh.BeginTied();
  sFloatControl *float_BlurRadius_0 = gh.Float(&para->BlurRadius[0],0.000000f,16.00000f,0.010000f);
  float_BlurRadius_0->Default = 0.010000f; float_BlurRadius_0->RightStep = 0.125000f;
  sFloatControl *float_BlurRadius_1 = gh.Float(&para->BlurRadius[1],0.000000f,16.00000f,0.010000f);
  float_BlurRadius_1->Default = 0.010000f; float_BlurRadius_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Debug");
  gh.Flags(&para->Debug,L"normal operation|bypass|blur0|blur1|z|fade",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefDepthOfField(wOp *op)
{
  Wz4RenderParaDepthOfField sUNUSED *para = (Wz4RenderParaDepthOfField *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Depth[0] = 8.000000f;
  para->Depth[1] = 16.00000f;
  para->Depth[2] = 256.0000f;
  para->Blur[0] = 1.000000f;
  para->Blur[2] = 1.000000f;
  para->CenterSize = 4.000000f;
  para->BlurRadius[0] = 0.010000f;
  para->BlurRadius[1] = 0.010000f;
}

void Wz4RenderBindDepthOfField(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"depth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"depth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"depth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"centersize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"blurradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"blurradius"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2DepthOfField(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"depth");
    name[2] = sPoolString(L"blur");
    name[3] = sPoolString(L"centersize");
    name[4] = sPoolString(L"blur");
    name[5] = sPoolString(L"blurradius");
    name[6] = sPoolString(L"debug");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,2,cmd->Data+8);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3DepthOfField(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import depth : float[3];\n");
  tb.PrintF(L"  import blur : float[3];\n");
  tb.PrintF(L"  import centersize : float;\n");
  tb.PrintF(L"  import blurradius : float[2];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiDepthOfField =
L"= Wz4Render : DepthOfField\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DepthOfField\n"
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
L" !i Depth\n"
L" !i Depth\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Blur\n"
L" !i Blur\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i CenterSize\n"
L" !i CenterSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurRadius\n"
L" !i BlurRadius\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Debug\n"
L" !i Debug\n"
L" !i normal operation\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bypass\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i blur0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i blur1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i z\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fade\n"
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

sBool Wz4RenderCmdDepthOfField2(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaDepthOfField2 sUNUSED *para = (Wz4RenderParaDepthOfField2 *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 144 "wz4_ipp_ops.ops"

    RNDof2 *node = new RNDof2();
    node->ParaBase = node->Para = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 906 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiDepthOfField2(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaDepthOfField2 sUNUSED *para = (Wz4RenderParaDepthOfField2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* FocalDepth");
  sFloatControl *float_FocalDepth = gh.Float(&para->FocalDepth,-65536.0f,65536.00f,0.125000f);
  float_FocalDepth->Default = 16.00000f; float_FocalDepth->RightStep = 0.125000f;

  gh.Label(L"* FocusRange");
  sFloatControl *float_FocusRange = gh.Float(&para->FocusRange,0.000000f,65536.00f,0.125000f);
  float_FocusRange->Default = 1.500000f; float_FocusRange->RightStep = 0.125000f;

  gh.Label(L"* UnfocusRange");
  sFloatControl *float_UnfocusRange = gh.Float(&para->UnfocusRange,0.000000f,65536.00f,0.125000f);
  float_UnfocusRange->Default = 3.500000f; float_UnfocusRange->RightStep = 0.125000f;

  gh.Label(L"* MediumBlur");
  sFloatControl *float_MediumBlur = gh.Float(&para->MediumBlur,1.000000f,256.0000f,0.010000f);
  float_MediumBlur->Default = 5.000000f; float_MediumBlur->RightStep = 0.125000f;

  gh.Label(L"* LargeBlur");
  sFloatControl *float_LargeBlur = gh.Float(&para->LargeBlur,1.000000f,256.0000f,0.010000f);
  float_LargeBlur->Default = 10.00000f; float_LargeBlur->RightStep = 0.125000f;

  gh.Label(L"Debug");
  gh.Flags(&para->Debug,L"None|Focus|Small blur|Med blur|Large blur",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefDepthOfField2(wOp *op)
{
  Wz4RenderParaDepthOfField2 sUNUSED *para = (Wz4RenderParaDepthOfField2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->FocalDepth = 16.00000f;
  para->FocusRange = 1.500000f;
  para->UnfocusRange = 3.500000f;
  para->MediumBlur = 5.000000f;
  para->LargeBlur = 10.00000f;
}

void Wz4RenderBindDepthOfField2(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"focaldepth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"focusrange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"unfocusrange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"mediumblur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"largeblur"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2DepthOfField2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"focaldepth");
    name[2] = sPoolString(L"focusrange");
    name[3] = sPoolString(L"unfocusrange");
    name[4] = sPoolString(L"mediumblur");
    name[5] = sPoolString(L"largeblur");
    name[6] = sPoolString(L"debug");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3DepthOfField2(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import focaldepth : float;\n");
  tb.PrintF(L"  import focusrange : float;\n");
  tb.PrintF(L"  import unfocusrange : float;\n");
  tb.PrintF(L"  import mediumblur : float;\n");
  tb.PrintF(L"  import largeblur : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiDepthOfField2 =
L"= Wz4Render : DepthOfField2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DepthOfField2\n"
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
L" !i FocalDepth\n"
L" !i FocalDepth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FocusRange\n"
L" !i FocusRange\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i UnfocusRange\n"
L" !i UnfocusRange\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MediumBlur\n"
L" !i MediumBlur\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LargeBlur\n"
L" !i LargeBlur\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Debug\n"
L" !i Debug\n"
L" !i None\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Focus\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Small blur\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Med blur\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Large blur\n"
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

sBool Wz4RenderCmdSSAO(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSSAO sUNUSED *para = (Wz4RenderParaSSAO *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 187 "wz4_ipp_ops.ops"

    RNSSAO *node = new RNSSAO();
    node->ParaBase = node->Para = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 1142 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndSSAO(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaSSAO sUNUSED *para = (Wz4RenderParaSSAO *)(op->EditData); para;
#line 196 "wz4_ipp_ops.ops"

    if(para->Fog==2)
      pi.Handle3D(op,1,para->FogCenter,wHM_PLANE);  
  ;
#line 1155 "wz4_ipp_ops.cpp"
}

void Wz4RenderGuiSSAO(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSSAO sUNUSED *para = (Wz4RenderParaSSAO *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* MinOcclude");
  sFloatControl *float_MinOcclude = gh.Float(&para->MinOcclude,0.000000f,65536.00f,0.001000f);
  float_MinOcclude->Default = 0.010000f; float_MinOcclude->RightStep = 0.125000f;

  gh.Label(L"* MaxOcclude");
  sFloatControl *float_MaxOcclude = gh.Float(&para->MaxOcclude,0.000000f,65536.00f,0.001000f);
  float_MaxOcclude->Default = 24.00000f; float_MaxOcclude->RightStep = 0.125000f;

  gh.Label(L"* SampleRadius");
  sFloatControl *float_SampleRadius = gh.Float(&para->SampleRadius,0.000000f,65536.00f,0.001000f);
  float_SampleRadius->Default = 1.000000f; float_SampleRadius->RightStep = 0.125000f;

  gh.Label(L"* NormalThreshold");
  sFloatControl *float_NormalThreshold = gh.Float(&para->NormalThreshold,-1.00000f,1.000000f,0.001000f);
  float_NormalThreshold->Default = 0.500000f; float_NormalThreshold->RightStep = 0.125000f;

  gh.Label(L"Output");
  gh.Flags(&para->Output,L"Result|Normals|SSAO",gh.ChangeMsg);

  gh.Label(L"* Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.Label(L"Quality");
  gh.Flags(&para->Quality,L" 4 Samples| 8 Samples| 16 Samples",gh.ChangeMsg);

  gh.Label(L"* Intensity");
  sFloatControl *float_Intensity = gh.Float(&para->Intensity,-16.0000f,16.00000f,0.002000f);
  float_Intensity->Default = 1.000000f; float_Intensity->RightStep = 0.125000f;

  gh.Label(L"Fog");
  gh.Flags(&para->Fog,L"-|Fog|Centered",gh.LayoutMsg);

  if((para->Fog!=0x0000))
  {
    gh.Label(L"* FogNear");
    sFloatControl *float_FogNear = gh.Float(&para->FogNear,0.000000f,65536.00f,0.010000f);
    float_FogNear->Default = 16.00000f; float_FogNear->RightStep = 0.125000f;

    gh.Label(L"* FogFar");
    sFloatControl *float_FogFar = gh.Float(&para->FogFar,0.000000f,65536.00f,16.00000f);
    float_FogFar->Default = 4096.000f; float_FogFar->RightStep = 0.125000f;

  }
  if((para->Fog==0x0002))
  {
    gh.Label(L"FogCenter");
    gh.BeginTied();
    sFloatControl *float_FogCenter_0 = gh.Float(&para->FogCenter.x,-65536.0f,65536.00f,0.125000f);
    float_FogCenter_0->Default = 0.000000f; float_FogCenter_0->RightStep = 0.125000f;
    sFloatControl *float_FogCenter_1 = gh.Float(&para->FogCenter.y,-65536.0f,65536.00f,0.125000f);
    float_FogCenter_1->Default = 0.000000f; float_FogCenter_1->RightStep = 0.125000f;
    sFloatControl *float_FogCenter_2 = gh.Float(&para->FogCenter.z,-65536.0f,65536.00f,0.125000f);
    float_FogCenter_2->Default = 0.000000f; float_FogCenter_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Fog!=0x0000))
  {
    gh.Label(L"* FogDensity");
    sFloatControl *float_FogDensity = gh.Float(&para->FogDensity,0.000000f,1.000000f,0.002000f);
    float_FogDensity->Default = 1.000000f; float_FogDensity->RightStep = 0.125000f;

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefSSAO(wOp *op)
{
  Wz4RenderParaSSAO sUNUSED *para = (Wz4RenderParaSSAO *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->MinOcclude = 0.010000f;
  para->MaxOcclude = 24.00000f;
  para->SampleRadius = 1.000000f;
  para->NormalThreshold = 0.500000f;
  para->Quality = 0x00000002;
  para->Intensity = 1.000000f;
  para->FogNear = 16.00000f;
  para->FogFar = 4096.000f;
  para->FogDensity = 1.000000f;
}

void Wz4RenderBindSSAO(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"minocclude"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"maxocclude"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"sampleradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"normalthreshold"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"intensity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"fognear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"fogfar"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"fogcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"fogcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"fogcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"fogdensity"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2SSAO(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[16];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"minocclude");
    name[2] = sPoolString(L"maxocclude");
    name[3] = sPoolString(L"sampleradius");
    name[4] = sPoolString(L"normalthreshold");
    name[5] = sPoolString(L"output");
    name[6] = sPoolString(L"color_");
    name[7] = sPoolString(L"quality");
    name[8] = sPoolString(L"intensity");
    name[9] = sPoolString(L"fog");
    name[10] = sPoolString(L"fognear");
    name[11] = sPoolString(L"fogfar");
    name[12] = sPoolString(L"fogcenter");
    name[13] = sPoolString(L"fogdensity");
    name[14] = sPoolString(L"");
    name[15] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[12],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[15],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3SSAO(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import minocclude : float;\n");
  tb.PrintF(L"  import maxocclude : float;\n");
  tb.PrintF(L"  import sampleradius : float;\n");
  tb.PrintF(L"  import normalthreshold : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import intensity : float;\n");
  tb.PrintF(L"  import fognear : float;\n");
  tb.PrintF(L"  import fogfar : float;\n");
  tb.PrintF(L"  import fogcenter : float[3];\n");
  tb.PrintF(L"  import fogdensity : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSSAO =
L"= Wz4Render : SSAO\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SSAO\n"
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
L" !i MinOcclude\n"
L" !i MinOcclude\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaxOcclude\n"
L" !i MaxOcclude\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SampleRadius\n"
L" !i SampleRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i NormalThreshold\n"
L" !i NormalThreshold\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Output\n"
L" !i Output\n"
L" !i Result\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Normals\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i SSAO\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Quality\n"
L" !i Quality\n"
L" !i 4 Samples\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8 Samples\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16 Samples\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Intensity\n"
L" !i Intensity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Fog\n"
L" !i Fog\n"
L" !i Fog\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Centered\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i FogNear\n"
L" !i FogNear\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FogFar\n"
L" !i FogFar\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FogCenter\n"
L" !i FogCenter\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i FogDensity\n"
L" !i FogDensity\n"
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

sBool Wz4RenderCmdColorBalance(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaColorBalance sUNUSED *para = (Wz4RenderParaColorBalance *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 219 "wz4_ipp_ops.ops"

    RNColorBalance *node = new RNColorBalance();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 1511 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiColorBalance(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaColorBalance sUNUSED *para = (Wz4RenderParaColorBalance *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Shadows");
  gh.BeginTied();
  sFloatControl *float_Shadows_0 = gh.Float(&para->Shadows.x,-1.00000f,1.000000f,0.001000f);
  float_Shadows_0->Default = 0.000000f; float_Shadows_0->RightStep = 0.125000f;
  sFloatControl *float_Shadows_1 = gh.Float(&para->Shadows.y,-1.00000f,1.000000f,0.001000f);
  float_Shadows_1->Default = 0.000000f; float_Shadows_1->RightStep = 0.125000f;
  sFloatControl *float_Shadows_2 = gh.Float(&para->Shadows.z,-1.00000f,1.000000f,0.001000f);
  float_Shadows_2->Default = 0.000000f; float_Shadows_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Midtones");
  gh.BeginTied();
  sFloatControl *float_Midtones_0 = gh.Float(&para->Midtones.x,-1.00000f,1.000000f,0.001000f);
  float_Midtones_0->Default = 0.000000f; float_Midtones_0->RightStep = 0.125000f;
  sFloatControl *float_Midtones_1 = gh.Float(&para->Midtones.y,-1.00000f,1.000000f,0.001000f);
  float_Midtones_1->Default = 0.000000f; float_Midtones_1->RightStep = 0.125000f;
  sFloatControl *float_Midtones_2 = gh.Float(&para->Midtones.z,-1.00000f,1.000000f,0.001000f);
  float_Midtones_2->Default = 0.000000f; float_Midtones_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Highlights");
  gh.BeginTied();
  sFloatControl *float_Highlights_0 = gh.Float(&para->Highlights.x,-1.00000f,1.000000f,0.001000f);
  float_Highlights_0->Default = 0.000000f; float_Highlights_0->RightStep = 0.125000f;
  sFloatControl *float_Highlights_1 = gh.Float(&para->Highlights.y,-1.00000f,1.000000f,0.001000f);
  float_Highlights_1->Default = 0.000000f; float_Highlights_1->RightStep = 0.125000f;
  sFloatControl *float_Highlights_2 = gh.Float(&para->Highlights.z,-1.00000f,1.000000f,0.001000f);
  float_Highlights_2->Default = 0.000000f; float_Highlights_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefColorBalance(wOp *op)
{
  Wz4RenderParaColorBalance sUNUSED *para = (Wz4RenderParaColorBalance *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindColorBalance(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"shadows"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"shadows"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"shadows"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"midtones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"midtones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"midtones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"highlights"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"highlights"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"highlights"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ColorBalance(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"shadows");
    name[2] = sPoolString(L"midtones");
    name[3] = sPoolString(L"highlights");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ColorBalance(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import shadows : float[3];\n");
  tb.PrintF(L"  import midtones : float[3];\n");
  tb.PrintF(L"  import highlights : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiColorBalance =
L"= Wz4Render : ColorBalance\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ColorBalance\n"
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
L" !i Shadows\n"
L" !i Shadows\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Midtones\n"
L" !i Midtones\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Highlights\n"
L" !i Highlights\n"
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

sBool Wz4RenderCmdColorSaw(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaColorSaw sUNUSED *para = (Wz4RenderParaColorSaw *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 245 "wz4_ipp_ops.ops"

    RNColorSaw *node = new RNColorSaw();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 1721 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiColorSaw(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaColorSaw sUNUSED *para = (Wz4RenderParaColorSaw *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Repeat");
  gh.BeginTied();
  sIntControl *int_Repeat_0 = gh.Int(&para->Repeat[0],1,64,0.125000f);
  int_Repeat_0->Default = 0x00000001; int_Repeat_0->RightStep = 0.125000f;
  sIntControl *int_Repeat_1 = gh.Int(&para->Repeat[1],1,64,0.125000f);
  int_Repeat_1->Default = 0x00000001; int_Repeat_1->RightStep = 0.125000f;
  sIntControl *int_Repeat_2 = gh.Int(&para->Repeat[2],1,64,0.125000f);
  int_Repeat_2->Default = 0x00000001; int_Repeat_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Threshold");
  gh.BeginTied();
  sFloatControl *float_Threshold_0 = gh.Float(&para->Threshold.x,0.000000f,1.000000f,0.001000f);
  float_Threshold_0->Default = 0.500000f; float_Threshold_0->RightStep = 0.125000f;
  sFloatControl *float_Threshold_1 = gh.Float(&para->Threshold.y,0.000000f,1.000000f,0.001000f);
  float_Threshold_1->Default = 0.500000f; float_Threshold_1->RightStep = 0.125000f;
  sFloatControl *float_Threshold_2 = gh.Float(&para->Threshold.z,0.000000f,1.000000f,0.001000f);
  float_Threshold_2->Default = 0.500000f; float_Threshold_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Softness");
  gh.BeginTied();
  sFloatControl *float_Softness_0 = gh.Float(&para->Softness.x,0.000000f,1.000000f,0.001000f);
  float_Softness_0->Default = 1.000000f; float_Softness_0->RightStep = 0.125000f;
  sFloatControl *float_Softness_1 = gh.Float(&para->Softness.y,0.000000f,1.000000f,0.001000f);
  float_Softness_1->Default = 1.000000f; float_Softness_1->RightStep = 0.125000f;
  sFloatControl *float_Softness_2 = gh.Float(&para->Softness.z,0.000000f,1.000000f,0.001000f);
  float_Softness_2->Default = 1.000000f; float_Softness_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Gamma");
  gh.BeginTied();
  sFloatControl *float_Gamma_0 = gh.Float(&para->Gamma[0],0.000000f,64.00000f,0.001000f);
  float_Gamma_0->Default = 1.000000f; float_Gamma_0->RightStep = 0.125000f;
  sFloatControl *float_Gamma_1 = gh.Float(&para->Gamma[1],0.000000f,64.00000f,0.001000f);
  float_Gamma_1->Default = 1.000000f; float_Gamma_1->RightStep = 0.125000f;
  sFloatControl *float_Gamma_2 = gh.Float(&para->Gamma[2],0.000000f,64.00000f,0.001000f);
  float_Gamma_2->Default = 1.000000f; float_Gamma_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefColorSaw(wOp *op)
{
  Wz4RenderParaColorSaw sUNUSED *para = (Wz4RenderParaColorSaw *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Repeat[0] = 0x00000001;
  para->Repeat[1] = 0x00000001;
  para->Repeat[2] = 0x00000001;
  para->Threshold.x = 0.500000f;
  para->Threshold.y = 0.500000f;
  para->Threshold.z = 0.500000f;
  para->Softness.x = 1.000000f;
  para->Softness.y = 1.000000f;
  para->Softness.z = 1.000000f;
  para->Gamma[0] = 1.000000f;
  para->Gamma[1] = 1.000000f;
  para->Gamma[2] = 1.000000f;
}

void Wz4RenderBindColorSaw(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"repeat"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"repeat"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"repeat"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"threshold"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"threshold"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"threshold"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"softness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"softness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"softness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ColorSaw(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"repeat");
    name[2] = sPoolString(L"threshold");
    name[3] = sPoolString(L"softness");
    name[4] = sPoolString(L"gamma");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ColorSaw(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import repeat : int[3];\n");
  tb.PrintF(L"  import threshold : float[3];\n");
  tb.PrintF(L"  import softness : float[3];\n");
  tb.PrintF(L"  import gamma : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiColorSaw =
L"= Wz4Render : ColorSaw\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ColorSaw\n"
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
L" !i Repeat\n"
L" !i Repeat\n"
L" !i int[3]\n"
L" !i *\n"
L"\n"
L" !i Threshold\n"
L" !i Threshold\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Softness\n"
L" !i Softness\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Gamma\n"
L" !i Gamma\n"
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

sBool Wz4RenderCmdColorGrade(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaColorGrade sUNUSED *para = (Wz4RenderParaColorGrade *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 309 "wz4_ipp_ops.ops"

    RNColorGrade *node = new RNColorGrade();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 1970 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiColorGrade(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaColorGrade sUNUSED *para = (Wz4RenderParaColorGrade *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|ShadowMidHigh",gh.LayoutMsg);

  if((para->Flags&0x0001))
  {
    gh.Group(L"Shadows");

    gh.Label(L"Width");
    sFloatControl *float_ShadWidth = gh.Float(&para->ShadWidth,0.000000f,1.000000f,0.010000f);
    float_ShadWidth->Default = 0.500000f; float_ShadWidth->RightStep = 0.125000f;

    gh.Label(L"Contr/Bright/Sat/Hue");
    sFloatControl *float_ShadContrast = gh.Float(&para->ShadContrast,-10.0000f,10.00000f,0.010000f);
    float_ShadContrast->Default = 1.000000f; float_ShadContrast->RightStep = 0.125000f;

    sFloatControl *float_ShadBrightness = gh.Float(&para->ShadBrightness,-10.0000f,10.00000f,0.010000f);
    float_ShadBrightness->Default = 0.000000f; float_ShadBrightness->RightStep = 0.125000f;

    sFloatControl *float_ShadSaturation = gh.Float(&para->ShadSaturation,-10.0000f,10.00000f,0.010000f);
    float_ShadSaturation->Default = 1.000000f; float_ShadSaturation->RightStep = 0.125000f;

    sFloatControl *float_ShadHue = gh.Float(&para->ShadHue,-1.00000f,1.000000f,0.010000f);
    float_ShadHue->Default = 0.000000f; float_ShadHue->RightStep = 0.125000f;

    gh.Label(L"Balance");
    sFloatControl *float_ShadBalHue = gh.Float(&para->ShadBalHue,0.000000f,1.000000f,0.010000f);
    float_ShadBalHue->Default = 0.000000f; float_ShadBalHue->RightStep = 0.125000f;

    sFloatControl *float_ShadBalStrength = gh.Float(&para->ShadBalStrength,0.000000f,1.000000f,0.010000f);
    float_ShadBalStrength->Default = 0.000000f; float_ShadBalStrength->RightStep = 0.125000f;

    gh.Label(L"Gain");
    gh.BeginTied();
    sFloatControl *float_ShadGain_0 = gh.Float(&para->ShadGain.x,-10.0000f,10.00000f,0.010000f);
    float_ShadGain_0->Default = 1.000000f; float_ShadGain_0->RightStep = 0.125000f;
    sFloatControl *float_ShadGain_1 = gh.Float(&para->ShadGain.y,-10.0000f,10.00000f,0.010000f);
    float_ShadGain_1->Default = 1.000000f; float_ShadGain_1->RightStep = 0.125000f;
    sFloatControl *float_ShadGain_2 = gh.Float(&para->ShadGain.z,-10.0000f,10.00000f,0.010000f);
    float_ShadGain_2->Default = 1.000000f; float_ShadGain_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Colourize");
    gh.ColorPick(&para->ShadColor,L"rgba",0);

    gh.Group(L"Midtones");

  }
  gh.Label(L"Contr/Bright/Sat/Hue");
  sFloatControl *float_MidContrast = gh.Float(&para->MidContrast,-10.0000f,10.00000f,0.010000f);
  float_MidContrast->Default = 1.000000f; float_MidContrast->RightStep = 0.125000f;

  sFloatControl *float_MidBrightness = gh.Float(&para->MidBrightness,-10.0000f,10.00000f,0.010000f);
  float_MidBrightness->Default = 0.000000f; float_MidBrightness->RightStep = 0.125000f;

  sFloatControl *float_MidSaturation = gh.Float(&para->MidSaturation,-10.0000f,10.00000f,0.010000f);
  float_MidSaturation->Default = 1.000000f; float_MidSaturation->RightStep = 0.125000f;

  sFloatControl *float_MidHue = gh.Float(&para->MidHue,-1.00000f,1.000000f,0.010000f);
  float_MidHue->Default = 0.000000f; float_MidHue->RightStep = 0.125000f;

  gh.Label(L"Balance");
  sFloatControl *float_MidBalHue = gh.Float(&para->MidBalHue,0.000000f,1.000000f,0.010000f);
  float_MidBalHue->Default = 0.000000f; float_MidBalHue->RightStep = 0.125000f;

  sFloatControl *float_MidBalStrength = gh.Float(&para->MidBalStrength,0.000000f,1.000000f,0.010000f);
  float_MidBalStrength->Default = 0.000000f; float_MidBalStrength->RightStep = 0.125000f;

  gh.Label(L"Gain");
  gh.BeginTied();
  sFloatControl *float_MidGain_0 = gh.Float(&para->MidGain.x,-10.0000f,10.00000f,0.010000f);
  float_MidGain_0->Default = 1.000000f; float_MidGain_0->RightStep = 0.125000f;
  sFloatControl *float_MidGain_1 = gh.Float(&para->MidGain.y,-10.0000f,10.00000f,0.010000f);
  float_MidGain_1->Default = 1.000000f; float_MidGain_1->RightStep = 0.125000f;
  sFloatControl *float_MidGain_2 = gh.Float(&para->MidGain.z,-10.0000f,10.00000f,0.010000f);
  float_MidGain_2->Default = 1.000000f; float_MidGain_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Colourize");
  gh.ColorPick(&para->MidColor,L"rgba",0);

  if((para->Flags&0x0001))
  {
    gh.Group(L"Highlights");

    gh.Label(L"Width");
    sFloatControl *float_HighWidth = gh.Float(&para->HighWidth,0.000000f,1.000000f,0.010000f);
    float_HighWidth->Default = 0.500000f; float_HighWidth->RightStep = 0.125000f;

    gh.Label(L"Contr/Bright/Sat/Hue");
    sFloatControl *float_HighContrast = gh.Float(&para->HighContrast,-10.0000f,10.00000f,0.010000f);
    float_HighContrast->Default = 1.000000f; float_HighContrast->RightStep = 0.125000f;

    sFloatControl *float_HighBrightness = gh.Float(&para->HighBrightness,-10.0000f,10.00000f,0.010000f);
    float_HighBrightness->Default = 0.000000f; float_HighBrightness->RightStep = 0.125000f;

    sFloatControl *float_HighSaturation = gh.Float(&para->HighSaturation,-10.0000f,10.00000f,0.010000f);
    float_HighSaturation->Default = 1.000000f; float_HighSaturation->RightStep = 0.125000f;

    sFloatControl *float_HighHue = gh.Float(&para->HighHue,-1.00000f,1.000000f,0.010000f);
    float_HighHue->Default = 0.000000f; float_HighHue->RightStep = 0.125000f;

    gh.Label(L"Balance");
    sFloatControl *float_HighBalHue = gh.Float(&para->HighBalHue,0.000000f,1.000000f,0.010000f);
    float_HighBalHue->Default = 0.000000f; float_HighBalHue->RightStep = 0.125000f;

    sFloatControl *float_HighBalStrength = gh.Float(&para->HighBalStrength,0.000000f,1.000000f,0.010000f);
    float_HighBalStrength->Default = 0.000000f; float_HighBalStrength->RightStep = 0.125000f;

    gh.Label(L"Gain");
    gh.BeginTied();
    sFloatControl *float_HighGain_0 = gh.Float(&para->HighGain.x,-10.0000f,10.00000f,0.010000f);
    float_HighGain_0->Default = 1.000000f; float_HighGain_0->RightStep = 0.125000f;
    sFloatControl *float_HighGain_1 = gh.Float(&para->HighGain.y,-10.0000f,10.00000f,0.010000f);
    float_HighGain_1->Default = 1.000000f; float_HighGain_1->RightStep = 0.125000f;
    sFloatControl *float_HighGain_2 = gh.Float(&para->HighGain.z,-10.0000f,10.00000f,0.010000f);
    float_HighGain_2->Default = 1.000000f; float_HighGain_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Colourize");
    gh.ColorPick(&para->HighColor,L"rgba",0);

  }
  gh.Group(L"General");

  gh.Label(L"Gamma");
  gh.BeginTied();
  sFloatControl *float_Gamma_0 = gh.Float(&para->Gamma.x,0.100000f,10.00000f,0.010000f);
  float_Gamma_0->Default = 1.000000f; float_Gamma_0->RightStep = 0.125000f;
  sFloatControl *float_Gamma_1 = gh.Float(&para->Gamma.y,0.100000f,10.00000f,0.010000f);
  float_Gamma_1->Default = 1.000000f; float_Gamma_1->RightStep = 0.125000f;
  sFloatControl *float_Gamma_2 = gh.Float(&para->Gamma.z,0.100000f,10.00000f,0.010000f);
  float_Gamma_2->Default = 1.000000f; float_Gamma_2->RightStep = 0.125000f;
  sFloatControl *float_Gamma_3 = gh.Float(&para->Gamma.w,0.100000f,10.00000f,0.010000f);
  float_Gamma_3->Default = 1.000000f; float_Gamma_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefColorGrade(wOp *op)
{
  Wz4RenderParaColorGrade sUNUSED *para = (Wz4RenderParaColorGrade *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000001;
  para->ShadWidth = 0.500000f;
  para->ShadContrast = 1.000000f;
  para->ShadSaturation = 1.000000f;
  para->ShadGain.x = 1.000000f;
  para->ShadGain.y = 1.000000f;
  para->ShadGain.z = 1.000000f;
  para->ShadColor = 0x00ff007f;
  para->MidContrast = 1.000000f;
  para->MidSaturation = 1.000000f;
  para->MidGain.x = 1.000000f;
  para->MidGain.y = 1.000000f;
  para->MidGain.z = 1.000000f;
  para->MidColor = 0x00ff007f;
  para->HighWidth = 0.500000f;
  para->HighContrast = 1.000000f;
  para->HighSaturation = 1.000000f;
  para->HighGain.x = 1.000000f;
  para->HighGain.y = 1.000000f;
  para->HighGain.z = 1.000000f;
  para->HighColor = 0x00ff007f;
  para->Gamma.x = 1.000000f;
  para->Gamma.y = 1.000000f;
  para->Gamma.z = 1.000000f;
  para->Gamma.w = 1.000000f;
}

void Wz4RenderBindColorGrade(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"shadcontrast"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"shadbrightness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"shadsaturation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"shadhue"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"balance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"shadbalstrength"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"colourize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"midcontrast"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"midbrightness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"midsaturation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"midhue"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"balance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"midbalstrength"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"colourize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"highcontrast"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"highbrightness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"highsaturation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"highhue"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"balance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"highbalstrength"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"gain"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"colourize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ColorGrade(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[35];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"shadows");
    name[3] = sPoolString(L"width");
    name[4] = sPoolString(L"shadcontrast");
    name[5] = sPoolString(L"shadbrightness");
    name[6] = sPoolString(L"shadsaturation");
    name[7] = sPoolString(L"shadhue");
    name[8] = sPoolString(L"balance");
    name[9] = sPoolString(L"shadbalstrength");
    name[10] = sPoolString(L"gain");
    name[11] = sPoolString(L"colourize");
    name[12] = sPoolString(L"midtones");
    name[13] = sPoolString(L"midcontrast");
    name[14] = sPoolString(L"midbrightness");
    name[15] = sPoolString(L"midsaturation");
    name[16] = sPoolString(L"midhue");
    name[17] = sPoolString(L"balance");
    name[18] = sPoolString(L"midbalstrength");
    name[19] = sPoolString(L"gain");
    name[20] = sPoolString(L"colourize");
    name[21] = sPoolString(L"highlights");
    name[22] = sPoolString(L"width");
    name[23] = sPoolString(L"highcontrast");
    name[24] = sPoolString(L"highbrightness");
    name[25] = sPoolString(L"highsaturation");
    name[26] = sPoolString(L"highhue");
    name[27] = sPoolString(L"balance");
    name[28] = sPoolString(L"highbalstrength");
    name[29] = sPoolString(L"gain");
    name[30] = sPoolString(L"colourize");
    name[31] = sPoolString(L"general");
    name[32] = sPoolString(L"gamma");
    name[33] = sPoolString(L"");
    name[34] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[11],ScriptTypeColor,1,cmd->Data+12);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[19],ScriptTypeFloat,3,cmd->Data+19);
  ctx->AddImport(name[20],ScriptTypeColor,1,cmd->Data+22);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+25);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+26);
  ctx->AddImport(name[26],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[27],ScriptTypeFloat,1,cmd->Data+28);
  ctx->AddImport(name[28],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[29],ScriptTypeFloat,3,cmd->Data+30);
  ctx->AddImport(name[30],ScriptTypeColor,1,cmd->Data+33);
  ctx->AddImport(name[32],ScriptTypeFloat,4,cmd->Data+34);
  ctx->AddImport(name[34],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ColorGrade(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import width : float;\n");
  tb.PrintF(L"  import shadcontrast : float;\n");
  tb.PrintF(L"  import shadbrightness : float;\n");
  tb.PrintF(L"  import shadsaturation : float;\n");
  tb.PrintF(L"  import shadhue : float;\n");
  tb.PrintF(L"  import balance : float;\n");
  tb.PrintF(L"  import shadbalstrength : float;\n");
  tb.PrintF(L"  import gain : float[3];\n");
  tb.PrintF(L"  import colourize : color;\n");
  tb.PrintF(L"  import midcontrast : float;\n");
  tb.PrintF(L"  import midbrightness : float;\n");
  tb.PrintF(L"  import midsaturation : float;\n");
  tb.PrintF(L"  import midhue : float;\n");
  tb.PrintF(L"  import balance : float;\n");
  tb.PrintF(L"  import midbalstrength : float;\n");
  tb.PrintF(L"  import gain : float[3];\n");
  tb.PrintF(L"  import colourize : color;\n");
  tb.PrintF(L"  import width : float;\n");
  tb.PrintF(L"  import highcontrast : float;\n");
  tb.PrintF(L"  import highbrightness : float;\n");
  tb.PrintF(L"  import highsaturation : float;\n");
  tb.PrintF(L"  import highhue : float;\n");
  tb.PrintF(L"  import balance : float;\n");
  tb.PrintF(L"  import highbalstrength : float;\n");
  tb.PrintF(L"  import gain : float[3];\n");
  tb.PrintF(L"  import colourize : color;\n");
  tb.PrintF(L"  import gamma : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiColorGrade =
L"= Wz4Render : ColorGrade\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ColorGrade\n"
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
L" !i ShadowMidHigh\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Width\n"
L" !i ShadWidth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Contr/Bright/Sat/Hue\n"
L" !i ShadContrast\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadBrightness\n"
L" !i ShadBrightness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadSaturation\n"
L" !i ShadSaturation\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadHue\n"
L" !i ShadHue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Balance\n"
L" !i ShadBalHue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadBalStrength\n"
L" !i ShadBalStrength\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gain\n"
L" !i ShadGain\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Colourize\n"
L" !i ShadColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Contr/Bright/Sat/Hue\n"
L" !i MidContrast\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MidBrightness\n"
L" !i MidBrightness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MidSaturation\n"
L" !i MidSaturation\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MidHue\n"
L" !i MidHue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Balance\n"
L" !i MidBalHue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MidBalStrength\n"
L" !i MidBalStrength\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gain\n"
L" !i MidGain\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Colourize\n"
L" !i MidColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Width\n"
L" !i HighWidth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Contr/Bright/Sat/Hue\n"
L" !i HighContrast\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i HighBrightness\n"
L" !i HighBrightness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i HighSaturation\n"
L" !i HighSaturation\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i HighHue\n"
L" !i HighHue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Balance\n"
L" !i HighBalHue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i HighBalStrength\n"
L" !i HighBalStrength\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gain\n"
L" !i HighGain\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Colourize\n"
L" !i HighColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Gamma\n"
L" !i Gamma\n"
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

sBool Wz4RenderCmdCrashZoom(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCrashZoom sUNUSED *para = (Wz4RenderParaCrashZoom *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 338 "wz4_ipp_ops.ops"

    RNCrashZoom *node = new RNCrashZoom();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 2595 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiCrashZoom(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCrashZoom sUNUSED *para = (Wz4RenderParaCrashZoom *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*4center2d|center3d",gh.LayoutMsg);

  gh.Label(L"Steps");
  gh.Flags(&para->Flags,L"|| 2| 3| 4",gh.ChangeMsg);

  if((para->Flags&0x0010))
  {
    gh.Label(L"* Center3D");
    gh.BeginTied();
    sFloatControl *float_Center3D_0 = gh.Float(&para->Center3D.x,-1024.00f,1024.000f,0.125000f);
    float_Center3D_0->Default = 0.000000f; float_Center3D_0->RightStep = 0.125000f;
    sFloatControl *float_Center3D_1 = gh.Float(&para->Center3D.y,-1024.00f,1024.000f,0.125000f);
    float_Center3D_1->Default = 0.000000f; float_Center3D_1->RightStep = 0.125000f;
    sFloatControl *float_Center3D_2 = gh.Float(&para->Center3D.z,-1024.00f,1024.000f,0.125000f);
    float_Center3D_2->Default = 0.000000f; float_Center3D_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(!(para->Flags&0x0010))
  {
    gh.Label(L"* Center2D");
    gh.BeginTied();
    sFloatControl *float_Center2D_0 = gh.Float(&para->Center2D[0],-1024.00f,1024.000f,0.010000f);
    float_Center2D_0->Default = 0.500000f; float_Center2D_0->RightStep = 0.125000f;
    sFloatControl *float_Center2D_1 = gh.Float(&para->Center2D[1],-1024.00f,1024.000f,0.010000f);
    float_Center2D_1->Default = 0.500000f; float_Center2D_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"* Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,0.000000f,1024.000f,0.010000f);
  float_Amplify->Default = 1.000000f; float_Amplify->RightStep = 0.125000f;

  gh.Label(L"* Amount");
  gh.BeginTied();
  sFloatControl *float_Amount_0 = gh.Float(&para->Amount[0],0.000000f,1.000000f,0.001000f);
  float_Amount_0->Default = 0.010000f; float_Amount_0->RightStep = 0.125000f;
  sFloatControl *float_Amount_1 = gh.Float(&para->Amount[1],0.000000f,1.000000f,0.001000f);
  float_Amount_1->Default = 0.010000f; float_Amount_1->RightStep = 0.125000f;
  sFloatControl *float_Amount_2 = gh.Float(&para->Amount[2],0.000000f,1.000000f,0.001000f);
  float_Amount_2->Default = 0.010000f; float_Amount_2->RightStep = 0.125000f;
  sFloatControl *float_Amount_3 = gh.Float(&para->Amount[3],0.000000f,1.000000f,0.001000f);
  float_Amount_3->Default = 0.010000f; float_Amount_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefCrashZoom(wOp *op)
{
  Wz4RenderParaCrashZoom sUNUSED *para = (Wz4RenderParaCrashZoom *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000001;
  para->Center2D[0] = 0.500000f;
  para->Center2D[1] = 0.500000f;
  para->Amplify = 1.000000f;
  para->Amount[0] = 0.010000f;
  para->Amount[1] = 0.010000f;
  para->Amount[2] = 0.010000f;
  para->Amount[3] = 0.010000f;
}

void Wz4RenderBindCrashZoom(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center3d"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center3d"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center3d"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"center2d"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"center2d"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2CrashZoom(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"steps");
    name[3] = sPoolString(L"center3d");
    name[4] = sPoolString(L"center2d");
    name[5] = sPoolString(L"amplify");
    name[6] = sPoolString(L"amount");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[6],ScriptTypeFloat,4,cmd->Data+8);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3CrashZoom(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import center3d : float[3];\n");
  tb.PrintF(L"  import center2d : float[2];\n");
  tb.PrintF(L"  import amplify : float;\n");
  tb.PrintF(L"  import amount : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCrashZoom =
L"= Wz4Render : CrashZoom\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CrashZoom\n"
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
L" !i center2d\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i center3d\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Steps\n"
L" !i Flags\n"
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
L" !i Center3D\n"
L" !i Center3D\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Center2D\n"
L" !i Center2D\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amount\n"
L" !i Amount\n"
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

sBool Wz4RenderCmdGrabScreen(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaGrabScreen sUNUSED *para = (Wz4RenderParaGrabScreen *)(cmd->Data); para;
  Rendertarget2D sUNUSED *in0 = cmd->GetInput<Rendertarget2D *>(0); in0;
  Wz4Render sUNUSED *in1 = cmd->GetInput<Wz4Render *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 360 "wz4_ipp_ops.ops"

    RNGrabScreen *node = new RNGrabScreen();
    node->ParaBase = node->Para = *para;
    node->Target = in0;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass,1);
  ;
#line 2867 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiGrabScreen(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaGrabScreen sUNUSED *para = (Wz4RenderParaGrabScreen *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Enable");
  gh.Flags(&para->Enable,L"-|Enable",gh.ChangeMsg);

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

void Wz4RenderDefGrabScreen(wOp *op)
{
  Wz4RenderParaGrabScreen sUNUSED *para = (Wz4RenderParaGrabScreen *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindGrabScreen(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2GrabScreen(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"enable");
    name[2] = sPoolString(L"rendertarget");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[4],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3GrabScreen(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiGrabScreen =
L"= Wz4Render : GrabScreen\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i GrabScreen\n"
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
L" !i link Rendertarget\n"
L" !i *\n"
L"\n"
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
L" !i Enable\n"
L" !i Enable\n"
L" !i Enable\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdCrackFixer(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCrackFixer sUNUSED *para = (Wz4RenderParaCrackFixer *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 385 "wz4_ipp_ops.ops"

    RNCrackFixer *node = new RNCrackFixer();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 3032 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiCrackFixer(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCrackFixer sUNUSED *para = (Wz4RenderParaCrackFixer *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"AlphaDistance");
  sFloatControl *float_AlphaDistance = gh.Float(&para->AlphaDistance,-1.00000f,1.000000f,0.001000f);
  float_AlphaDistance->Default = 0.100000f; float_AlphaDistance->RightStep = 0.125000f;

  gh.Label(L"OffCounts");
  sIntControl *int_OffCounts = gh.Int(&para->OffCounts,1,12,0.125000f);
  int_OffCounts->Default = 0x00000006; int_OffCounts->RightStep = 0.125000f;

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

void Wz4RenderDefCrackFixer(wOp *op)
{
  Wz4RenderParaCrackFixer sUNUSED *para = (Wz4RenderParaCrackFixer *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->AlphaDistance = 0.100000f;
  para->OffCounts = 0x00000006;
}

void Wz4RenderBindCrackFixer(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"alphadistance"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"offcounts"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2CrackFixer(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"alphadistance");
    name[1] = sPoolString(L"offcounts");
    name[2] = sPoolString(L"renderpass");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3CrackFixer(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import alphadistance : float;\n");
  tb.PrintF(L"  import offcounts : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCrackFixer =
L"= Wz4Render : CrackFixer\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CrackFixer\n"
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
L" !i AlphaDistance\n"
L" !i AlphaDistance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i OffCounts\n"
L" !i OffCounts\n"
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

sBool Wz4RenderCmdFXAA3(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFXAA3 sUNUSED *para = (Wz4RenderParaFXAA3 *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 404 "wz4_ipp_ops.ops"

    RNFXAA3 *node = new RNFXAA3();
    node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 3193 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFXAA3(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFXAA3 sUNUSED *para = (Wz4RenderParaFXAA3 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;
}

void Wz4RenderDefFXAA3(wOp *op)
{
  Wz4RenderParaFXAA3 sUNUSED *para = (Wz4RenderParaFXAA3 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindFXAA3(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
}
void Wz4RenderBind2FXAA3(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
}
void Wz4RenderBind3FXAA3(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
}
const sChar *Wz4RenderWikiFXAA3 =
L"= Wz4Render : FXAA3\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FXAA3\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4RenderCmdColorMath(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaColorMath sUNUSED *para = (Wz4RenderParaColorMath *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 428 "wz4_ipp_ops.ops"

	RNColorMath *node = new RNColorMath();
	node->Para = *para;
	out->RootNode = node;
	out->AddChilds(cmd,para->Renderpass);
  ;
#line 3301 "wz4_ipp_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiColorMath(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaColorMath sUNUSED *para = (Wz4RenderParaColorMath *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Add");
  gh.ColorPick(&para->Add,L"rgba",0);

  gh.Label(L"AddFactor");
  sFloatControl *float_AddFactor = gh.Float(&para->AddFactor,-1000.00f,1000.000f,0.125000f);
  float_AddFactor->Default = 1.000000f; float_AddFactor->RightStep = 0.125000f;

  gh.Label(L"Mul");
  gh.ColorPick(&para->Mul,L"rgba",0);

  gh.Label(L"MulFactor");
  sFloatControl *float_MulFactor = gh.Float(&para->MulFactor,-1000.00f,1000.000f,0.125000f);
  float_MulFactor->Default = 1.000000f; float_MulFactor->RightStep = 0.125000f;
}

void Wz4RenderDefColorMath(wOp *op)
{
  Wz4RenderParaColorMath sUNUSED *para = (Wz4RenderParaColorMath *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->AddFactor = 1.000000f;
  para->Mul = 0xffffffff;
  para->MulFactor = 1.000000f;
}

void Wz4RenderBindColorMath(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"add"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"addfactor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"mul"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"mulfactor"),val);
}
void Wz4RenderBind2ColorMath(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"add");
    name[2] = sPoolString(L"addfactor");
    name[3] = sPoolString(L"mul");
    name[4] = sPoolString(L"mulfactor");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
}
void Wz4RenderBind3ColorMath(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import add : color;\n");
  tb.PrintF(L"  import addfactor : float;\n");
  tb.PrintF(L"  import mul : color;\n");
  tb.PrintF(L"  import mulfactor : float;\n");
}
const sChar *Wz4RenderWikiColorMath =
L"= Wz4Render : ColorMath\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ColorMath\n"
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
L" !i Add\n"
L" !i Add\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i AddFactor\n"
L" !i AddFactor\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Mul\n"
L" !i Mul\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MulFactor\n"
L" !i MulFactor\n"
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

sBool Wz4RenderCmdCustomIPP(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCustomIPP sUNUSED *para = (Wz4RenderParaCustomIPP *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  TextObject sUNUSED *in1 = cmd->GetInput<TextObject *>(1); in1;
  TextObject sUNUSED *in2 = cmd->GetInput<TextObject *>(2); in2;
  Texture2D sUNUSED *in3 = cmd->GetInput<Texture2D *>(3); in3;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 484 "wz4_ipp_ops.ops"

    RNCustomIPP *node = new RNCustomIPP();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass,0,1);

    if(cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out;
      out->AddRef();
    }

    sInt firstInTex = 3;    // first texture input position
    sInt indexTexture = 1;  // current material texture index (start to 1; 0 is reserved to current view)
    for(sInt i=firstInTex; i<cmd->InputCount && indexTexture<16; i++)
    {
      Texture2D *inTex = cmd->GetInput<Texture2D *>(i);
      if(inTex)
      {
        node->Mtrl->Texture[indexTexture] = inTex->Texture;
        sInt tmpFilter = sMTF_TILE;
        switch(indexTexture)
        {
          case 1:  tmpFilter = sConvertOldUvFlags(para->TexFilter1) ; break;
          case 2:  tmpFilter = sConvertOldUvFlags(para->TexFilter2) ; break;
          case 3:  tmpFilter = sConvertOldUvFlags(para->TexFilter3) ; break;
          case 4:  tmpFilter = sConvertOldUvFlags(para->TexFilter4) ; break;
          case 5:  tmpFilter = sConvertOldUvFlags(para->TexFilter5) ; break;
          case 6:  tmpFilter = sConvertOldUvFlags(para->TexFilter6) ; break;
          case 7:  tmpFilter = sConvertOldUvFlags(para->TexFilter7) ; break;
          case 8:  tmpFilter = sConvertOldUvFlags(para->TexFilter8) ; break;
          case 9:  tmpFilter = sConvertOldUvFlags(para->TexFilter9) ; break;
          case 10: tmpFilter = sConvertOldUvFlags(para->TexFilter10); break;
          case 11: tmpFilter = sConvertOldUvFlags(para->TexFilter11); break;
          case 12: tmpFilter = sConvertOldUvFlags(para->TexFilter12); break;
          case 13: tmpFilter = sConvertOldUvFlags(para->TexFilter13); break;
          case 14: tmpFilter = sConvertOldUvFlags(para->TexFilter14); break;
          case 15: tmpFilter = sConvertOldUvFlags(para->TexFilter15); break;
        }
        node->Mtrl->TFlags[indexTexture] = sMTF_LEVEL2 | tmpFilter | sMTF_EXTERN;
        inTex->AddRef();
        indexTexture++;
      }
    }

    node->Init();
    node->Log.Clear();

    // compile vertex shader
    sShader *vs=node->CompileShader(sSTF_VERTEX|sSTF_HLSL23,in1->Text.Get());
    if (!vs)
    {
      cmd->SetError(L"Vertex shader compile failed");
      return 0;
    }
    else
    {
      node->Mtrl->VertexShader = vs;
    }

    // compile pixel shader
    sShader *ps=node->CompileShader(sSTF_PIXEL|sSTF_HLSL23,in2->Text.Get());
    if (!ps)
    {
      cmd->SetError(L"Pixel shader compile failed");
      return 0;
    }
    else
    {
      node->Mtrl->PixelShader = ps;
    }
  ;
#line 3540 "wz4_ipp_ops.cpp"
    return 1;
  }
}

sInt Wz4RenderActCustomIPP(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaCustomIPP sUNUSED *para = (Wz4RenderParaCustomIPP *)(op->EditData); para;
#line 558 "wz4_ipp_ops.ops"

    if(code==1)
    {
      if(op->RefObj)
      {
        Wz4Render *r = (Wz4Render*) op->RefObj;
        if(r)
        {
          RNCustomIPP *n = (RNCustomIPP*) r->RootNode;
          if(n && n->Log.GetCount())
            App->PopupText(n->Log.Get());
        }
      }
      return 0;
    }

    if(code==2)
    {
      return 1;
    }

    return 0;
  ;
#line 3572 "wz4_ipp_ops.cpp"
}

void Wz4RenderGuiCustomIPP(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCustomIPP sUNUSED *para = (Wz4RenderParaCustomIPP *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Filter");
  gh.Flags(&para->Filter,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  gh.Group(L"Debug");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Shadercode",gh.ActionMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"FlushShaders",gh.ActionMsg);

  gh.Group(L"Vertex shader variables");

  gh.Label(L"* vs_var0");
  gh.BeginTied();
  sFloatControl *float_vs_var0_0 = gh.Float(&para->vs_var0[0],-1024.00f,1024.000f,0.001000f);
  float_vs_var0_0->Default = 0.000000f; float_vs_var0_0->RightStep = 0.125000f;
  sFloatControl *float_vs_var0_1 = gh.Float(&para->vs_var0[1],-1024.00f,1024.000f,0.001000f);
  float_vs_var0_1->Default = 0.000000f; float_vs_var0_1->RightStep = 0.125000f;
  sFloatControl *float_vs_var0_2 = gh.Float(&para->vs_var0[2],-1024.00f,1024.000f,0.001000f);
  float_vs_var0_2->Default = 0.000000f; float_vs_var0_2->RightStep = 0.125000f;
  sFloatControl *float_vs_var0_3 = gh.Float(&para->vs_var0[3],-1024.00f,1024.000f,0.001000f);
  float_vs_var0_3->Default = 0.000000f; float_vs_var0_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* vs_var1");
  gh.BeginTied();
  sFloatControl *float_vs_var1_0 = gh.Float(&para->vs_var1[0],-1024.00f,1024.000f,0.001000f);
  float_vs_var1_0->Default = 0.000000f; float_vs_var1_0->RightStep = 0.125000f;
  sFloatControl *float_vs_var1_1 = gh.Float(&para->vs_var1[1],-1024.00f,1024.000f,0.001000f);
  float_vs_var1_1->Default = 0.000000f; float_vs_var1_1->RightStep = 0.125000f;
  sFloatControl *float_vs_var1_2 = gh.Float(&para->vs_var1[2],-1024.00f,1024.000f,0.001000f);
  float_vs_var1_2->Default = 0.000000f; float_vs_var1_2->RightStep = 0.125000f;
  sFloatControl *float_vs_var1_3 = gh.Float(&para->vs_var1[3],-1024.00f,1024.000f,0.001000f);
  float_vs_var1_3->Default = 0.000000f; float_vs_var1_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* vs_var2");
  gh.BeginTied();
  sFloatControl *float_vs_var2_0 = gh.Float(&para->vs_var2[0],-1024.00f,1024.000f,0.001000f);
  float_vs_var2_0->Default = 0.000000f; float_vs_var2_0->RightStep = 0.125000f;
  sFloatControl *float_vs_var2_1 = gh.Float(&para->vs_var2[1],-1024.00f,1024.000f,0.001000f);
  float_vs_var2_1->Default = 0.000000f; float_vs_var2_1->RightStep = 0.125000f;
  sFloatControl *float_vs_var2_2 = gh.Float(&para->vs_var2[2],-1024.00f,1024.000f,0.001000f);
  float_vs_var2_2->Default = 0.000000f; float_vs_var2_2->RightStep = 0.125000f;
  sFloatControl *float_vs_var2_3 = gh.Float(&para->vs_var2[3],-1024.00f,1024.000f,0.001000f);
  float_vs_var2_3->Default = 0.000000f; float_vs_var2_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* vs_var3");
  gh.BeginTied();
  sFloatControl *float_vs_var3_0 = gh.Float(&para->vs_var3[0],-1024.00f,1024.000f,0.001000f);
  float_vs_var3_0->Default = 0.000000f; float_vs_var3_0->RightStep = 0.125000f;
  sFloatControl *float_vs_var3_1 = gh.Float(&para->vs_var3[1],-1024.00f,1024.000f,0.001000f);
  float_vs_var3_1->Default = 0.000000f; float_vs_var3_1->RightStep = 0.125000f;
  sFloatControl *float_vs_var3_2 = gh.Float(&para->vs_var3[2],-1024.00f,1024.000f,0.001000f);
  float_vs_var3_2->Default = 0.000000f; float_vs_var3_2->RightStep = 0.125000f;
  sFloatControl *float_vs_var3_3 = gh.Float(&para->vs_var3[3],-1024.00f,1024.000f,0.001000f);
  float_vs_var3_3->Default = 0.000000f; float_vs_var3_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* vs_var4");
  gh.BeginTied();
  sFloatControl *float_vs_var4_0 = gh.Float(&para->vs_var4[0],-1024.00f,1024.000f,0.001000f);
  float_vs_var4_0->Default = 0.000000f; float_vs_var4_0->RightStep = 0.125000f;
  sFloatControl *float_vs_var4_1 = gh.Float(&para->vs_var4[1],-1024.00f,1024.000f,0.001000f);
  float_vs_var4_1->Default = 0.000000f; float_vs_var4_1->RightStep = 0.125000f;
  sFloatControl *float_vs_var4_2 = gh.Float(&para->vs_var4[2],-1024.00f,1024.000f,0.001000f);
  float_vs_var4_2->Default = 0.000000f; float_vs_var4_2->RightStep = 0.125000f;
  sFloatControl *float_vs_var4_3 = gh.Float(&para->vs_var4[3],-1024.00f,1024.000f,0.001000f);
  float_vs_var4_3->Default = 0.000000f; float_vs_var4_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Pixel shader variables");

  gh.Label(L"* ps_var0");
  gh.BeginTied();
  sFloatControl *float_ps_var0_0 = gh.Float(&para->ps_var0[0],-1024.00f,1024.000f,0.001000f);
  float_ps_var0_0->Default = 0.000000f; float_ps_var0_0->RightStep = 0.125000f;
  sFloatControl *float_ps_var0_1 = gh.Float(&para->ps_var0[1],-1024.00f,1024.000f,0.001000f);
  float_ps_var0_1->Default = 0.000000f; float_ps_var0_1->RightStep = 0.125000f;
  sFloatControl *float_ps_var0_2 = gh.Float(&para->ps_var0[2],-1024.00f,1024.000f,0.001000f);
  float_ps_var0_2->Default = 0.000000f; float_ps_var0_2->RightStep = 0.125000f;
  sFloatControl *float_ps_var0_3 = gh.Float(&para->ps_var0[3],-1024.00f,1024.000f,0.001000f);
  float_ps_var0_3->Default = 0.000000f; float_ps_var0_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ps_var1");
  gh.BeginTied();
  sFloatControl *float_ps_var1_0 = gh.Float(&para->ps_var1[0],-1024.00f,1024.000f,0.001000f);
  float_ps_var1_0->Default = 0.000000f; float_ps_var1_0->RightStep = 0.125000f;
  sFloatControl *float_ps_var1_1 = gh.Float(&para->ps_var1[1],-1024.00f,1024.000f,0.001000f);
  float_ps_var1_1->Default = 0.000000f; float_ps_var1_1->RightStep = 0.125000f;
  sFloatControl *float_ps_var1_2 = gh.Float(&para->ps_var1[2],-1024.00f,1024.000f,0.001000f);
  float_ps_var1_2->Default = 0.000000f; float_ps_var1_2->RightStep = 0.125000f;
  sFloatControl *float_ps_var1_3 = gh.Float(&para->ps_var1[3],-1024.00f,1024.000f,0.001000f);
  float_ps_var1_3->Default = 0.000000f; float_ps_var1_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ps_var2");
  gh.BeginTied();
  sFloatControl *float_ps_var2_0 = gh.Float(&para->ps_var2[0],-1024.00f,1024.000f,0.001000f);
  float_ps_var2_0->Default = 0.000000f; float_ps_var2_0->RightStep = 0.125000f;
  sFloatControl *float_ps_var2_1 = gh.Float(&para->ps_var2[1],-1024.00f,1024.000f,0.001000f);
  float_ps_var2_1->Default = 0.000000f; float_ps_var2_1->RightStep = 0.125000f;
  sFloatControl *float_ps_var2_2 = gh.Float(&para->ps_var2[2],-1024.00f,1024.000f,0.001000f);
  float_ps_var2_2->Default = 0.000000f; float_ps_var2_2->RightStep = 0.125000f;
  sFloatControl *float_ps_var2_3 = gh.Float(&para->ps_var2[3],-1024.00f,1024.000f,0.001000f);
  float_ps_var2_3->Default = 0.000000f; float_ps_var2_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ps_var3");
  gh.BeginTied();
  sFloatControl *float_ps_var3_0 = gh.Float(&para->ps_var3[0],-1024.00f,1024.000f,0.001000f);
  float_ps_var3_0->Default = 0.000000f; float_ps_var3_0->RightStep = 0.125000f;
  sFloatControl *float_ps_var3_1 = gh.Float(&para->ps_var3[1],-1024.00f,1024.000f,0.001000f);
  float_ps_var3_1->Default = 0.000000f; float_ps_var3_1->RightStep = 0.125000f;
  sFloatControl *float_ps_var3_2 = gh.Float(&para->ps_var3[2],-1024.00f,1024.000f,0.001000f);
  float_ps_var3_2->Default = 0.000000f; float_ps_var3_2->RightStep = 0.125000f;
  sFloatControl *float_ps_var3_3 = gh.Float(&para->ps_var3[3],-1024.00f,1024.000f,0.001000f);
  float_ps_var3_3->Default = 0.000000f; float_ps_var3_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ps_var4");
  gh.BeginTied();
  sFloatControl *float_ps_var4_0 = gh.Float(&para->ps_var4[0],-1024.00f,1024.000f,0.001000f);
  float_ps_var4_0->Default = 0.000000f; float_ps_var4_0->RightStep = 0.125000f;
  sFloatControl *float_ps_var4_1 = gh.Float(&para->ps_var4[1],-1024.00f,1024.000f,0.001000f);
  float_ps_var4_1->Default = 0.000000f; float_ps_var4_1->RightStep = 0.125000f;
  sFloatControl *float_ps_var4_2 = gh.Float(&para->ps_var4[2],-1024.00f,1024.000f,0.001000f);
  float_ps_var4_2->Default = 0.000000f; float_ps_var4_2->RightStep = 0.125000f;
  sFloatControl *float_ps_var4_3 = gh.Float(&para->ps_var4[3],-1024.00f,1024.000f,0.001000f);
  float_ps_var4_3->Default = 0.000000f; float_ps_var4_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Texture filtering");

  if((op->ConnectionMask & (1<<3))!=0)
  {
    gh.Label(L"TexFilter1");
    gh.Flags(&para->TexFilter1,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<4))!=0)
  {
    gh.Label(L"TexFilter2");
    gh.Flags(&para->TexFilter2,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<5))!=0)
  {
    gh.Label(L"TexFilter3");
    gh.Flags(&para->TexFilter3,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<6))!=0)
  {
    gh.Label(L"TexFilter4");
    gh.Flags(&para->TexFilter4,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<7))!=0)
  {
    gh.Label(L"TexFilter5");
    gh.Flags(&para->TexFilter5,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<8))!=0)
  {
    gh.Label(L"TexFilter6");
    gh.Flags(&para->TexFilter6,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<9))!=0)
  {
    gh.Label(L"TexFilter7");
    gh.Flags(&para->TexFilter7,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<10))!=0)
  {
    gh.Label(L"TexFilter8");
    gh.Flags(&para->TexFilter8,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<11))!=0)
  {
    gh.Label(L"TexFilter9");
    gh.Flags(&para->TexFilter9,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<12))!=0)
  {
    gh.Label(L"TexFilter10");
    gh.Flags(&para->TexFilter10,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<13))!=0)
  {
    gh.Label(L"TexFilter11");
    gh.Flags(&para->TexFilter11,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<14))!=0)
  {
    gh.Label(L"TexFilter12");
    gh.Flags(&para->TexFilter12,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<15))!=0)
  {
    gh.Label(L"TexFilter13");
    gh.Flags(&para->TexFilter13,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<16))!=0)
  {
    gh.Label(L"TexFilter14");
    gh.Flags(&para->TexFilter14,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<17))!=0)
  {
    gh.Label(L"TexFilter15");
    gh.Flags(&para->TexFilter15,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefCustomIPP(wOp *op)
{
  Wz4RenderParaCustomIPP sUNUSED *para = (Wz4RenderParaCustomIPP *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindCustomIPP(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2CustomIPP(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[35];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"filter");
    name[2] = sPoolString(L"debug");
    name[3] = sPoolString(L"shadercode");
    name[4] = sPoolString(L"flushshaders");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"vs_var0");
    name[7] = sPoolString(L"vs_var1");
    name[8] = sPoolString(L"vs_var2");
    name[9] = sPoolString(L"vs_var3");
    name[10] = sPoolString(L"vs_var4");
    name[11] = sPoolString(L"");
    name[12] = sPoolString(L"ps_var0");
    name[13] = sPoolString(L"ps_var1");
    name[14] = sPoolString(L"ps_var2");
    name[15] = sPoolString(L"ps_var3");
    name[16] = sPoolString(L"ps_var4");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"texfilter1");
    name[19] = sPoolString(L"texfilter2");
    name[20] = sPoolString(L"texfilter3");
    name[21] = sPoolString(L"texfilter4");
    name[22] = sPoolString(L"texfilter5");
    name[23] = sPoolString(L"texfilter6");
    name[24] = sPoolString(L"texfilter7");
    name[25] = sPoolString(L"texfilter8");
    name[26] = sPoolString(L"texfilter9");
    name[27] = sPoolString(L"texfilter10");
    name[28] = sPoolString(L"texfilter11");
    name[29] = sPoolString(L"texfilter12");
    name[30] = sPoolString(L"texfilter13");
    name[31] = sPoolString(L"texfilter14");
    name[32] = sPoolString(L"texfilter15");
    name[33] = sPoolString(L"");
    name[34] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[6],ScriptTypeFloat,4,cmd->Data+2);
  ctx->AddImport(name[7],ScriptTypeFloat,4,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,4,cmd->Data+10);
  ctx->AddImport(name[9],ScriptTypeFloat,4,cmd->Data+14);
  ctx->AddImport(name[10],ScriptTypeFloat,4,cmd->Data+18);
  ctx->AddImport(name[12],ScriptTypeFloat,4,cmd->Data+22);
  ctx->AddImport(name[13],ScriptTypeFloat,4,cmd->Data+26);
  ctx->AddImport(name[14],ScriptTypeFloat,4,cmd->Data+30);
  ctx->AddImport(name[15],ScriptTypeFloat,4,cmd->Data+34);
  ctx->AddImport(name[16],ScriptTypeFloat,4,cmd->Data+38);
  ctx->AddImport(name[34],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3CustomIPP(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import vs_var0 : float[4];\n");
  tb.PrintF(L"  import vs_var1 : float[4];\n");
  tb.PrintF(L"  import vs_var2 : float[4];\n");
  tb.PrintF(L"  import vs_var3 : float[4];\n");
  tb.PrintF(L"  import vs_var4 : float[4];\n");
  tb.PrintF(L"  import ps_var0 : float[4];\n");
  tb.PrintF(L"  import ps_var1 : float[4];\n");
  tb.PrintF(L"  import ps_var2 : float[4];\n");
  tb.PrintF(L"  import ps_var3 : float[4];\n");
  tb.PrintF(L"  import ps_var4 : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCustomIPP =
L"= Wz4Render : CustomIPP\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CustomIPP\n"
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
L" !i TextObject\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i TextObject\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
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
L" !i Shadercode\n"
L" !i Shadercode\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i FlushShaders\n"
L" !i FlushShaders\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i vs_var0\n"
L" !i vs_var0\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i vs_var1\n"
L" !i vs_var1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i vs_var2\n"
L" !i vs_var2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i vs_var3\n"
L" !i vs_var3\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i vs_var4\n"
L" !i vs_var4\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i ps_var0\n"
L" !i ps_var0\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i ps_var1\n"
L" !i ps_var1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i ps_var2\n"
L" !i ps_var2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i ps_var3\n"
L" !i ps_var3\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i ps_var4\n"
L" !i ps_var4\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i TexFilter1\n"
L" !i TexFilter1\n"
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
L" !i TexFilter2\n"
L" !i TexFilter2\n"
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
L" !i TexFilter3\n"
L" !i TexFilter3\n"
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
L" !i TexFilter4\n"
L" !i TexFilter4\n"
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
L" !i TexFilter5\n"
L" !i TexFilter5\n"
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
L" !i TexFilter6\n"
L" !i TexFilter6\n"
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
L" !i TexFilter7\n"
L" !i TexFilter7\n"
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
L" !i TexFilter8\n"
L" !i TexFilter8\n"
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
L" !i TexFilter9\n"
L" !i TexFilter9\n"
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
L" !i TexFilter10\n"
L" !i TexFilter10\n"
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
L" !i TexFilter11\n"
L" !i TexFilter11\n"
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
L" !i TexFilter12\n"
L" !i TexFilter12\n"
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
L" !i TexFilter13\n"
L" !i TexFilter13\n"
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
L" !i TexFilter14\n"
L" !i TexFilter14\n"
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
L" !i TexFilter15\n"
L" !i TexFilter15\n"
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

void Wz4RenderAnimColorCorrect::Init(class ScriptContext *sc)
{
  _Color0 = sc->AddSymbol(L"color0");
  _Color1 = sc->AddSymbol(L"color1");
};

void Wz4RenderAnimColorCorrect::Bind(class ScriptContext *sc,Wz4RenderParaColorCorrect *para)
{
  sc->BindLocalColor(_Color0,&para->Color0);
  sc->BindLocalColor(_Color1,&para->Color1);
};

void Wz4RenderAnimDebugZ::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimDebugZ::Bind(class ScriptContext *sc,Wz4RenderParaDebugZ *para)
{
};

void Wz4RenderAnimBlur::Init(class ScriptContext *sc)
{
  _Radius = sc->AddSymbol(L"radius");
  _Amp = sc->AddSymbol(L"amp");
  _Sharpen = sc->AddSymbol(L"sharpen");
  _Sharpen0 = sc->AddSymbol(L"sharpen0");
  _Sharpen0Amp = sc->AddSymbol(L"sharpen0amp");
  _Sharpen1 = sc->AddSymbol(L"sharpen1");
  _Sharpen1Amp = sc->AddSymbol(L"sharpen1amp");
};

void Wz4RenderAnimBlur::Bind(class ScriptContext *sc,Wz4RenderParaBlur *para)
{
  sc->BindLocalFloat(_Radius,1,&para->Radius);
  sc->BindLocalFloat(_Amp,1,&para->Amp);
  sc->BindLocalFloat(_Sharpen,1,&para->Sharpen);
  sc->BindLocalColor(_Sharpen0,&para->Sharpen0);
  sc->BindLocalFloat(_Sharpen0Amp,1,&para->Sharpen0Amp);
  sc->BindLocalColor(_Sharpen1,&para->Sharpen1);
  sc->BindLocalFloat(_Sharpen1Amp,1,&para->Sharpen1Amp);
};

void Wz4RenderAnimDepthOfField::Init(class ScriptContext *sc)
{
  _Depth = sc->AddSymbol(L"depth");
  _Blur = sc->AddSymbol(L"blur");
  _CenterSize = sc->AddSymbol(L"centersize");
  _BlurRadius = sc->AddSymbol(L"blurradius");
};

void Wz4RenderAnimDepthOfField::Bind(class ScriptContext *sc,Wz4RenderParaDepthOfField *para)
{
  sc->BindLocalFloat(_Depth,3,para->Depth);
  sc->BindLocalFloat(_Blur,3,para->Blur);
  sc->BindLocalFloat(_CenterSize,1,&para->CenterSize);
  sc->BindLocalFloat(_BlurRadius,2,para->BlurRadius);
};

void Wz4RenderAnimDepthOfField2::Init(class ScriptContext *sc)
{
  _FocalDepth = sc->AddSymbol(L"focaldepth");
  _FocusRange = sc->AddSymbol(L"focusrange");
  _UnfocusRange = sc->AddSymbol(L"unfocusrange");
  _MediumBlur = sc->AddSymbol(L"mediumblur");
  _LargeBlur = sc->AddSymbol(L"largeblur");
};

void Wz4RenderAnimDepthOfField2::Bind(class ScriptContext *sc,Wz4RenderParaDepthOfField2 *para)
{
  sc->BindLocalFloat(_FocalDepth,1,&para->FocalDepth);
  sc->BindLocalFloat(_FocusRange,1,&para->FocusRange);
  sc->BindLocalFloat(_UnfocusRange,1,&para->UnfocusRange);
  sc->BindLocalFloat(_MediumBlur,1,&para->MediumBlur);
  sc->BindLocalFloat(_LargeBlur,1,&para->LargeBlur);
};

void Wz4RenderAnimSSAO::Init(class ScriptContext *sc)
{
  _MinOcclude = sc->AddSymbol(L"minocclude");
  _MaxOcclude = sc->AddSymbol(L"maxocclude");
  _SampleRadius = sc->AddSymbol(L"sampleradius");
  _NormalThreshold = sc->AddSymbol(L"normalthreshold");
  _Color = sc->AddSymbol(L"color_");
  _Intensity = sc->AddSymbol(L"intensity");
  _FogNear = sc->AddSymbol(L"fognear");
  _FogFar = sc->AddSymbol(L"fogfar");
  _FogDensity = sc->AddSymbol(L"fogdensity");
};

void Wz4RenderAnimSSAO::Bind(class ScriptContext *sc,Wz4RenderParaSSAO *para)
{
  sc->BindLocalFloat(_MinOcclude,1,&para->MinOcclude);
  sc->BindLocalFloat(_MaxOcclude,1,&para->MaxOcclude);
  sc->BindLocalFloat(_SampleRadius,1,&para->SampleRadius);
  sc->BindLocalFloat(_NormalThreshold,1,&para->NormalThreshold);
  sc->BindLocalColor(_Color,&para->Color);
  sc->BindLocalFloat(_Intensity,1,&para->Intensity);
  sc->BindLocalFloat(_FogNear,1,&para->FogNear);
  sc->BindLocalFloat(_FogFar,1,&para->FogFar);
  sc->BindLocalFloat(_FogDensity,1,&para->FogDensity);
};

void Wz4RenderAnimColorBalance::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimColorBalance::Bind(class ScriptContext *sc,Wz4RenderParaColorBalance *para)
{
};

void Wz4RenderAnimColorSaw::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimColorSaw::Bind(class ScriptContext *sc,Wz4RenderParaColorSaw *para)
{
};

void Wz4RenderAnimColorGrade::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimColorGrade::Bind(class ScriptContext *sc,Wz4RenderParaColorGrade *para)
{
};

void Wz4RenderAnimCrashZoom::Init(class ScriptContext *sc)
{
  _Center3D = sc->AddSymbol(L"center3d");
  _Center2D = sc->AddSymbol(L"center2d");
  _Amplify = sc->AddSymbol(L"amplify");
  _Amount = sc->AddSymbol(L"amount");
};

void Wz4RenderAnimCrashZoom::Bind(class ScriptContext *sc,Wz4RenderParaCrashZoom *para)
{
  sc->BindLocalFloat(_Center3D,3,&para->Center3D.x);
  sc->BindLocalFloat(_Center2D,2,para->Center2D);
  sc->BindLocalFloat(_Amplify,1,&para->Amplify);
  sc->BindLocalFloat(_Amount,4,para->Amount);
};

void Wz4RenderAnimGrabScreen::Init(class ScriptContext *sc)
{
  _Enable = sc->AddSymbol(L"enable");
};

void Wz4RenderAnimGrabScreen::Bind(class ScriptContext *sc,Wz4RenderParaGrabScreen *para)
{
  sc->BindLocalInt(_Enable,1,&para->Enable);
};

void Wz4RenderAnimCrackFixer::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimCrackFixer::Bind(class ScriptContext *sc,Wz4RenderParaCrackFixer *para)
{
};

void Wz4RenderAnimFXAA3::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimFXAA3::Bind(class ScriptContext *sc,Wz4RenderParaFXAA3 *para)
{
};

void Wz4RenderAnimColorMath::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimColorMath::Bind(class ScriptContext *sc,Wz4RenderParaColorMath *para)
{
};

void Wz4RenderAnimCustomIPP::Init(class ScriptContext *sc)
{
  _vs_var0 = sc->AddSymbol(L"vs_var0");
  _vs_var1 = sc->AddSymbol(L"vs_var1");
  _vs_var2 = sc->AddSymbol(L"vs_var2");
  _vs_var3 = sc->AddSymbol(L"vs_var3");
  _vs_var4 = sc->AddSymbol(L"vs_var4");
  _ps_var0 = sc->AddSymbol(L"ps_var0");
  _ps_var1 = sc->AddSymbol(L"ps_var1");
  _ps_var2 = sc->AddSymbol(L"ps_var2");
  _ps_var3 = sc->AddSymbol(L"ps_var3");
  _ps_var4 = sc->AddSymbol(L"ps_var4");
};

void Wz4RenderAnimCustomIPP::Bind(class ScriptContext *sc,Wz4RenderParaCustomIPP *para)
{
  sc->BindLocalFloat(_vs_var0,4,para->vs_var0);
  sc->BindLocalFloat(_vs_var1,4,para->vs_var1);
  sc->BindLocalFloat(_vs_var2,4,para->vs_var2);
  sc->BindLocalFloat(_vs_var3,4,para->vs_var3);
  sc->BindLocalFloat(_vs_var4,4,para->vs_var4);
  sc->BindLocalFloat(_ps_var0,4,para->ps_var0);
  sc->BindLocalFloat(_ps_var1,4,para->ps_var1);
  sc->BindLocalFloat(_ps_var2,4,para->ps_var2);
  sc->BindLocalFloat(_ps_var3,4,para->ps_var3);
  sc->BindLocalFloat(_ps_var4,4,para->ps_var4);
};


/****************************************************************************/

void AddTypes_wz4_ipp_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_wz4_ipp_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"ColorCorrect";
  cl->Label = L"ColorCorrect";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdColorCorrect;
  cl->MakeGui = Wz4RenderGuiColorCorrect;
  cl->SetDefaults = Wz4RenderDefColorCorrect;
  cl->BindPara = Wz4RenderBindColorCorrect;
  cl->Bind2Para = Wz4RenderBind2ColorCorrect;
  cl->Bind3Para = Wz4RenderBind3ColorCorrect;
  cl->WikiText = Wz4RenderWikiColorCorrect;
  cl->ParaStrings = 1;
  cl->ParaWords = 3;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DebugZ";
  cl->Label = L"DebugChannel";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdDebugZ;
  cl->MakeGui = Wz4RenderGuiDebugZ;
  cl->SetDefaults = Wz4RenderDefDebugZ;
  cl->BindPara = Wz4RenderBindDebugZ;
  cl->Bind2Para = Wz4RenderBind2DebugZ;
  cl->Bind3Para = Wz4RenderBind3DebugZ;
  cl->WikiText = Wz4RenderWikiDebugZ;
  cl->ParaStrings = 1;
  cl->ParaWords = 2;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Blur";
  cl->Label = L"Blur";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBlur;
  cl->MakeGui = Wz4RenderGuiBlur;
  cl->SetDefaults = Wz4RenderDefBlur;
  cl->BindPara = Wz4RenderBindBlur;
  cl->Bind2Para = Wz4RenderBind2Blur;
  cl->Bind3Para = Wz4RenderBind3Blur;
  cl->WikiText = Wz4RenderWikiBlur;
  cl->ParaStrings = 1;
  cl->ParaWords = 11;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DepthOfField";
  cl->Label = L"DepthOfField";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdDepthOfField;
  cl->MakeGui = Wz4RenderGuiDepthOfField;
  cl->SetDefaults = Wz4RenderDefDepthOfField;
  cl->BindPara = Wz4RenderBindDepthOfField;
  cl->Bind2Para = Wz4RenderBind2DepthOfField;
  cl->Bind3Para = Wz4RenderBind3DepthOfField;
  cl->WikiText = Wz4RenderWikiDepthOfField;
  cl->ParaStrings = 1;
  cl->ParaWords = 11;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DepthOfField2";
  cl->Label = L"DepthOfField2";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdDepthOfField2;
  cl->MakeGui = Wz4RenderGuiDepthOfField2;
  cl->SetDefaults = Wz4RenderDefDepthOfField2;
  cl->BindPara = Wz4RenderBindDepthOfField2;
  cl->Bind2Para = Wz4RenderBind2DepthOfField2;
  cl->Bind3Para = Wz4RenderBind3DepthOfField2;
  cl->WikiText = Wz4RenderWikiDepthOfField2;
  cl->ParaStrings = 1;
  cl->ParaWords = 7;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SSAO";
  cl->Label = L"SSAO";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSSAO;
  cl->MakeGui = Wz4RenderGuiSSAO;
  cl->SetDefaults = Wz4RenderDefSSAO;
  cl->BindPara = Wz4RenderBindSSAO;
  cl->Bind2Para = Wz4RenderBind2SSAO;
  cl->Bind3Para = Wz4RenderBind3SSAO;
  cl->WikiText = Wz4RenderWikiSSAO;
  cl->Handles = Wz4RenderHndSSAO;
  cl->ParaStrings = 1;
  cl->ParaWords = 16;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ColorBalance";
  cl->Label = L"ColorBalance";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdColorBalance;
  cl->MakeGui = Wz4RenderGuiColorBalance;
  cl->SetDefaults = Wz4RenderDefColorBalance;
  cl->BindPara = Wz4RenderBindColorBalance;
  cl->Bind2Para = Wz4RenderBind2ColorBalance;
  cl->Bind3Para = Wz4RenderBind3ColorBalance;
  cl->WikiText = Wz4RenderWikiColorBalance;
  cl->ParaStrings = 1;
  cl->ParaWords = 10;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ColorSaw";
  cl->Label = L"ColorSaw";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdColorSaw;
  cl->MakeGui = Wz4RenderGuiColorSaw;
  cl->SetDefaults = Wz4RenderDefColorSaw;
  cl->BindPara = Wz4RenderBindColorSaw;
  cl->Bind2Para = Wz4RenderBind2ColorSaw;
  cl->Bind3Para = Wz4RenderBind3ColorSaw;
  cl->WikiText = Wz4RenderWikiColorSaw;
  cl->ParaStrings = 1;
  cl->ParaWords = 13;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ColorGrade";
  cl->Label = L"ColorGrade";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdColorGrade;
  cl->MakeGui = Wz4RenderGuiColorGrade;
  cl->SetDefaults = Wz4RenderDefColorGrade;
  cl->BindPara = Wz4RenderBindColorGrade;
  cl->Bind2Para = Wz4RenderBind2ColorGrade;
  cl->Bind3Para = Wz4RenderBind3ColorGrade;
  cl->WikiText = Wz4RenderWikiColorGrade;
  cl->ParaStrings = 1;
  cl->ParaWords = 38;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"CrashZoom";
  cl->Label = L"CrashZoom";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCrashZoom;
  cl->MakeGui = Wz4RenderGuiCrashZoom;
  cl->SetDefaults = Wz4RenderDefCrashZoom;
  cl->BindPara = Wz4RenderBindCrashZoom;
  cl->Bind2Para = Wz4RenderBind2CrashZoom;
  cl->Bind3Para = Wz4RenderBind3CrashZoom;
  cl->WikiText = Wz4RenderWikiCrashZoom;
  cl->ParaStrings = 1;
  cl->ParaWords = 12;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"GrabScreen";
  cl->Label = L"GrabScreen";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdGrabScreen;
  cl->MakeGui = Wz4RenderGuiGrabScreen;
  cl->SetDefaults = Wz4RenderDefGrabScreen;
  cl->BindPara = Wz4RenderBindGrabScreen;
  cl->Bind2Para = Wz4RenderBind2GrabScreen;
  cl->Bind3Para = Wz4RenderBind3GrabScreen;
  cl->WikiText = Wz4RenderWikiGrabScreen;
  cl->ParaStrings = 1;
  cl->ParaWords = 2;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Rendertarget2DType;
  in[0].DefaultClass = 0;
  in[0].Name = L"Rendertarget";
  in[0].Flags = 0|wCIF_METHODLINK;
  in[1].Type = Wz4RenderType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"CrackFixer";
  cl->Label = L"CrackFixer";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCrackFixer;
  cl->MakeGui = Wz4RenderGuiCrackFixer;
  cl->SetDefaults = Wz4RenderDefCrackFixer;
  cl->BindPara = Wz4RenderBindCrackFixer;
  cl->Bind2Para = Wz4RenderBind2CrackFixer;
  cl->Bind3Para = Wz4RenderBind3CrackFixer;
  cl->WikiText = Wz4RenderWikiCrackFixer;
  cl->ParaStrings = 1;
  cl->ParaWords = 3;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FXAA3";
  cl->Label = L"FXAA3";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFXAA3;
  cl->MakeGui = Wz4RenderGuiFXAA3;
  cl->SetDefaults = Wz4RenderDefFXAA3;
  cl->BindPara = Wz4RenderBindFXAA3;
  cl->Bind2Para = Wz4RenderBind2FXAA3;
  cl->Bind3Para = Wz4RenderBind3FXAA3;
  cl->WikiText = Wz4RenderWikiFXAA3;
  cl->ParaWords = 1;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ColorMath";
  cl->Label = L"ColorMath";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdColorMath;
  cl->MakeGui = Wz4RenderGuiColorMath;
  cl->SetDefaults = Wz4RenderDefColorMath;
  cl->BindPara = Wz4RenderBindColorMath;
  cl->Bind2Para = Wz4RenderBind2ColorMath;
  cl->Bind3Para = Wz4RenderBind3ColorMath;
  cl->WikiText = Wz4RenderWikiColorMath;
  cl->ParaWords = 5;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"CustomIPP";
  cl->Label = L"CustomIPP";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCustomIPP;
  cl->MakeGui = Wz4RenderGuiCustomIPP;
  cl->SetDefaults = Wz4RenderDefCustomIPP;
  cl->BindPara = Wz4RenderBindCustomIPP;
  cl->Bind2Para = Wz4RenderBind2CustomIPP;
  cl->Bind3Para = Wz4RenderBind3CustomIPP;
  cl->WikiText = Wz4RenderWikiCustomIPP;
  cl->Actions = Wz4RenderActCustomIPP;
  cl->ParaStrings = 1;
  cl->ParaWords = 57;
  cl->Column = 4;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(4);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = TextObjectType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = TextObjectType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0;
  in[3].Type = Texture2DType;
  in[3].DefaultClass = 0;
  in[3].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"Shadercode",1);
  cl->ActionIds.AddMany(1)->Init(L"FlushShaders",2);
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_ipp_ops,0x110,AddOps_wz4_ipp_ops,0);


/****************************************************************************/


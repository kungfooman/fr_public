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
#include "kbfx_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 14 "kbfx_ops.ops"

#include "wz4frlib/wz4_ipp.hpp"
#include "wz4frlib/kbfx.hpp"


#line 28 "kbfx_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdVideoDistort(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaVideoDistort sUNUSED *para = (Wz4RenderParaVideoDistort *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 35 "kbfx_ops.ops"

        RNVideoDistort *node = new RNVideoDistort();
        node->ParaBase = node->Para = *para;
        out->RootNode = node;
        out->AddChilds(cmd, para->Renderpass);
        out->AddCode(cmd, para->Renderpass);
    ;
#line 51 "kbfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiVideoDistort(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaVideoDistort sUNUSED *para = (Wz4RenderParaVideoDistort *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"KeyFrameInterval");
  sFloatControl *float_KeyFrameInterval = gh.Float(&para->KeyFrameInterval,0.100000f,100.0000f,0.100000f);
  float_KeyFrameInterval->Default = 2.000000f; float_KeyFrameInterval->RightStep = 0.125000f;

  gh.Label(L"Chance");
  sFloatControl *float_Chance = gh.Float(&para->Chance,0.000000f,1.000000f,0.010000f);
  float_Chance->Default = 0.500000f; float_Chance->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefVideoDistort(wOp *op)
{
  Wz4RenderParaVideoDistort sUNUSED *para = (Wz4RenderParaVideoDistort *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->KeyFrameInterval = 2.000000f;
  para->Chance = 0.500000f;
}

void Wz4RenderBindVideoDistort(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"keyframeinterval"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"chance"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2VideoDistort(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"keyframeinterval");
    name[2] = sPoolString(L"chance");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3VideoDistort(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import keyframeinterval : float;\n");
  tb.PrintF(L"  import chance : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiVideoDistort =
L"= Wz4Render : VideoDistort\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i VideoDistort\n"
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
L" !i KeyFrameInterval\n"
L" !i KeyFrameInterval\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Chance\n"
L" !i Chance\n"
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

sBool Wz4RenderCmdBlockTransition(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBlockTransition sUNUSED *para = (Wz4RenderParaBlockTransition *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 65 "kbfx_ops.ops"

        RNBlockTransition *node = new RNBlockTransition();
        node->ParaBase = node->Para = *para;
		node->Texture = in0; in0->AddRef();
		node->Init();
        out->RootNode = node;
        out->AddCode(cmd, para->Renderpass);
    ;
#line 214 "kbfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiBlockTransition(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBlockTransition sUNUSED *para = (Wz4RenderParaBlockTransition *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* BlockSize");
  sIntControl *int_BlockSize = gh.Int(&para->BlockSize,1,256,0.125000f);
  int_BlockSize->Default = 0x00000010; int_BlockSize->RightStep = 0.125000f;

  gh.Label(L"* StreakSize");
  sIntControl *int_StreakSize = gh.Int(&para->StreakSize,1,2000,0.125000f);
  int_StreakSize->Default = 0x000000c8; int_StreakSize->RightStep = 0.125000f;

  gh.Label(L"* StreakDeviate");
  sIntControl *int_StreakDeviate = gh.Int(&para->StreakDeviate,0,1000,0.125000f);
  int_StreakDeviate->Default = 0x00000064; int_StreakDeviate->RightStep = 0.125000f;

  gh.Label(L"* SrcDeviate");
  sIntControl *int_SrcDeviate = gh.Int(&para->SrcDeviate,0,100,0.125000f);
  int_SrcDeviate->Default = 0x00000002; int_SrcDeviate->RightStep = 0.125000f;

  gh.Label(L"* Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"* Chance");
  sFloatControl *float_Chance = gh.Float(&para->Chance,0.000000f,1.000000f,0.010000f);
  float_Chance->Default = 0.500000f; float_Chance->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefBlockTransition(wOp *op)
{
  Wz4RenderParaBlockTransition sUNUSED *para = (Wz4RenderParaBlockTransition *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->BlockSize = 0x00000010;
  para->StreakSize = 0x000000c8;
  para->StreakDeviate = 0x00000064;
  para->SrcDeviate = 0x00000002;
  para->Chance = 0.500000f;
}

void Wz4RenderBindBlockTransition(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"blocksize"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"streaksize"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"streakdeviate"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"srcdeviate"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"chance"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2BlockTransition(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"blocksize");
    name[2] = sPoolString(L"streaksize");
    name[3] = sPoolString(L"streakdeviate");
    name[4] = sPoolString(L"srcdeviate");
    name[5] = sPoolString(L"seed");
    name[6] = sPoolString(L"chance");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3BlockTransition(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import blocksize : int;\n");
  tb.PrintF(L"  import streaksize : int;\n");
  tb.PrintF(L"  import streakdeviate : int;\n");
  tb.PrintF(L"  import srcdeviate : int;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import chance : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBlockTransition =
L"= Wz4Render : BlockTransition\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BlockTransition\n"
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
L" !i BlockSize\n"
L" !i BlockSize\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i StreakSize\n"
L" !i StreakSize\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i StreakDeviate\n"
L" !i StreakDeviate\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i SrcDeviate\n"
L" !i SrcDeviate\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Chance\n"
L" !i Chance\n"
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

sBool Wz4RenderCmdGlitch2D(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaGlitch2D sUNUSED *para = (Wz4RenderParaGlitch2D *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 95 "kbfx_ops.ops"

    RNGlitch2D *node = new RNGlitch2D();
    node->ParaBase = node->Para = *para;
    node->Texture = in0; in0->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd, para->Renderpass);

  ;
#line 441 "kbfx_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiGlitch2D(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaGlitch2D sUNUSED *para = (Wz4RenderParaGlitch2D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"* LineSize");
  sIntControl *int_LineSize = gh.Int(&para->LineSize,1,1000,0.125000f);
  int_LineSize->Default = 0x00000008; int_LineSize->RightStep = 0.125000f;

  gh.Label(L"* Chance");
  sFloatControl *float_Chance = gh.Float(&para->Chance,0.000000f,1.000000f,0.010000f);
  float_Chance->Default = 0.500000f; float_Chance->RightStep = 0.125000f;

  gh.Label(L"* ShiftX");
  sFloatControl *float_ShiftX = gh.Float(&para->ShiftX,0.000000f,1.000000f,0.010000f);
  float_ShiftX->Default = 0.100000f; float_ShiftX->RightStep = 0.125000f;

  gh.Label(L"* ShiftY");
  sFloatControl *float_ShiftY = gh.Float(&para->ShiftY,0.000000f,1.000000f,0.010000f);
  float_ShiftY->Default = 0.000000f; float_ShiftY->RightStep = 0.125000f;

  gh.Label(L"* ShiftRGB");
  sFloatControl *float_ShiftRGB = gh.Float(&para->ShiftRGB,0.000000f,1.000000f,0.010000f);
  float_ShiftRGB->Default = 0.010000f; float_ShiftRGB->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefGlitch2D(wOp *op)
{
  Wz4RenderParaGlitch2D sUNUSED *para = (Wz4RenderParaGlitch2D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->LineSize = 0x00000008;
  para->Chance = 0.500000f;
  para->ShiftX = 0.100000f;
  para->ShiftRGB = 0.010000f;
}

void Wz4RenderBindGlitch2D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"linesize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"chance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"shiftx"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"shifty"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"shiftrgb"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Glitch2D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"seed");
    name[2] = sPoolString(L"linesize");
    name[3] = sPoolString(L"chance");
    name[4] = sPoolString(L"shiftx");
    name[5] = sPoolString(L"shifty");
    name[6] = sPoolString(L"shiftrgb");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Glitch2D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import linesize : int;\n");
  tb.PrintF(L"  import chance : float;\n");
  tb.PrintF(L"  import shiftx : float;\n");
  tb.PrintF(L"  import shifty : float;\n");
  tb.PrintF(L"  import shiftrgb : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiGlitch2D =
L"= Wz4Render : Glitch2D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Glitch2D\n"
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
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i LineSize\n"
L" !i LineSize\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Chance\n"
L" !i Chance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShiftX\n"
L" !i ShiftX\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShiftY\n"
L" !i ShiftY\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShiftRGB\n"
L" !i ShiftRGB\n"
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

void Wz4RenderAnimVideoDistort::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimVideoDistort::Bind(class ScriptContext *sc,Wz4RenderParaVideoDistort *para)
{
};

void Wz4RenderAnimBlockTransition::Init(class ScriptContext *sc)
{
  _BlockSize = sc->AddSymbol(L"blocksize");
  _StreakSize = sc->AddSymbol(L"streaksize");
  _StreakDeviate = sc->AddSymbol(L"streakdeviate");
  _SrcDeviate = sc->AddSymbol(L"srcdeviate");
  _Seed = sc->AddSymbol(L"seed");
  _Chance = sc->AddSymbol(L"chance");
};

void Wz4RenderAnimBlockTransition::Bind(class ScriptContext *sc,Wz4RenderParaBlockTransition *para)
{
  sc->BindLocalInt(_BlockSize,1,&para->BlockSize);
  sc->BindLocalInt(_StreakSize,1,&para->StreakSize);
  sc->BindLocalInt(_StreakDeviate,1,&para->StreakDeviate);
  sc->BindLocalInt(_SrcDeviate,1,&para->SrcDeviate);
  sc->BindLocalInt(_Seed,1,&para->Seed);
  sc->BindLocalFloat(_Chance,1,&para->Chance);
};

void Wz4RenderAnimGlitch2D::Init(class ScriptContext *sc)
{
  _Seed = sc->AddSymbol(L"seed");
  _LineSize = sc->AddSymbol(L"linesize");
  _Chance = sc->AddSymbol(L"chance");
  _ShiftX = sc->AddSymbol(L"shiftx");
  _ShiftY = sc->AddSymbol(L"shifty");
  _ShiftRGB = sc->AddSymbol(L"shiftrgb");
};

void Wz4RenderAnimGlitch2D::Bind(class ScriptContext *sc,Wz4RenderParaGlitch2D *para)
{
  sc->BindLocalInt(_Seed,1,&para->Seed);
  sc->BindLocalInt(_LineSize,1,&para->LineSize);
  sc->BindLocalFloat(_Chance,1,&para->Chance);
  sc->BindLocalFloat(_ShiftX,1,&para->ShiftX);
  sc->BindLocalFloat(_ShiftY,1,&para->ShiftY);
  sc->BindLocalFloat(_ShiftRGB,1,&para->ShiftRGB);
};


/****************************************************************************/

void AddTypes_kbfx_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_kbfx_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"VideoDistort";
  cl->Label = L"VideoDistort";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdVideoDistort;
  cl->MakeGui = Wz4RenderGuiVideoDistort;
  cl->SetDefaults = Wz4RenderDefVideoDistort;
  cl->BindPara = Wz4RenderBindVideoDistort;
  cl->Bind2Para = Wz4RenderBind2VideoDistort;
  cl->Bind3Para = Wz4RenderBind3VideoDistort;
  cl->WikiText = Wz4RenderWikiVideoDistort;
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
  cl->Name = L"BlockTransition";
  cl->Label = L"BlockTransition";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBlockTransition;
  cl->MakeGui = Wz4RenderGuiBlockTransition;
  cl->SetDefaults = Wz4RenderDefBlockTransition;
  cl->BindPara = Wz4RenderBindBlockTransition;
  cl->Bind2Para = Wz4RenderBind2BlockTransition;
  cl->Bind3Para = Wz4RenderBind3BlockTransition;
  cl->WikiText = Wz4RenderWikiBlockTransition;
  cl->ParaStrings = 1;
  cl->ParaWords = 7;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Glitch2D";
  cl->Label = L"Glitch2D";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdGlitch2D;
  cl->MakeGui = Wz4RenderGuiGlitch2D;
  cl->SetDefaults = Wz4RenderDefGlitch2D;
  cl->BindPara = Wz4RenderBindGlitch2D;
  cl->Bind2Para = Wz4RenderBind2Glitch2D;
  cl->Bind3Para = Wz4RenderBind3Glitch2D;
  cl->WikiText = Wz4RenderWikiGlitch2D;
  cl->ParaStrings = 1;
  cl->ParaWords = 7;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(kbfx_ops,0x110,AddOps_kbfx_ops,0);


/****************************************************************************/


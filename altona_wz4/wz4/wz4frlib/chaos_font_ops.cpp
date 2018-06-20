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
#include "chaos_font_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class ChaosFontType_ *ChaosFontType;

/****************************************************************************/

#line 16 "chaos_font_ops.ops"

  #include "wz4frlib/chaos_font.hpp"

#line 27 "chaos_font_ops.cpp"

/****************************************************************************/

#line 28 "chaos_font_ops.ops"
void ChaosFontType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 29 "chaos_font_ops.ops"

    sImage *img = 0;
    img = ((ChaosFont *) obj)->Image;
    pi.SetSizeTex2D(img->SizeX,img->SizeY);
    pi.PaintTex2D(img);
    pi.PaintHandles();
  ;
#line 42 "chaos_font_ops.cpp"
}

/****************************************************************************/

sBool ChaosFontCmdFont(wExecutive *exe,wCommand *cmd)
{
  ChaosFontParaFont sUNUSED *para = (ChaosFontParaFont *)(cmd->Data); para;
  ChaosFont *out = (ChaosFont *) cmd->Output;
  if(!out) { out=new ChaosFont; cmd->Output=out; }

  {
#line 56 "chaos_font_ops.ops"

    out->Init(1<<(para->Size&0xff),1<<((para->Size>>8)&0xff));
    out->InitFont(cmd->Strings[0],para->Height,para->Width,para->Style,para->Safety,para->Outline);
    out->LineFeed = para->LineFeed;
    const sChar *s = cmd->Strings[1];
    while(*s)
    {
      if(s[0]==0x5c && s[1]!=0)
      {
        out->Letter(s[1]);  
        s+=2;
      }
      else if(s[1]=='-')
      {
        sInt c0 = s[0];
        sInt c1 = s[2];
        s+=3;

        for(sInt i=c0;i<=c1;i++)
          out->Letter(i);
      }
      else
      {
        out->Letter(*s);
        s++;
      }
    }
    out->Finish();
  ;
#line 84 "chaos_font_ops.cpp"
    return 1;
  }
}

void ChaosFontGuiFont(wGridFrameHelper &gh,wOp *op)
{
  ChaosFontParaFont sUNUSED *para = (ChaosFontParaFont *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);

  gh.Label(L"Letters");
  gh.String(op->EditString[1]);

  gh.Label(L"Height");
  sIntControl *int_Height = gh.Int(&para->Height,1,1024,0.125000f);
  int_Height->Default = 0x0000000e; int_Height->RightStep = 0.125000f;

  gh.Label(L"Width");
  sIntControl *int_Width = gh.Int(&para->Width,0,1024,0.125000f);
  int_Width->Default = 0x00000000; int_Width->RightStep = 0.125000f;

  gh.Label(L"Style");
  gh.Flags(&para->Style,L"*0-|Bold:*1-|Italics:*2-|Underline:*3-|Strikeout:*4-|symbols",gh.ChangeMsg);

  gh.Label(L"Safety");
  sIntControl *int_Safety = gh.Int(&para->Safety,0,1024,0.125000f);
  int_Safety->Default = 0x00000001; int_Safety->RightStep = 0.125000f;

  gh.Label(L"Outline");
  sIntControl *int_Outline = gh.Int(&para->Outline,0,1024,0.125000f);
  int_Outline->Default = 0x00000000; int_Outline->RightStep = 0.125000f;

  gh.Label(L"LineFeed");
  sIntControl *int_LineFeed = gh.Int(&para->LineFeed,-1024,1024,0.125000f);
  int_LineFeed->Default = 0x00000000; int_LineFeed->RightStep = 0.125000f;
}

void ChaosFontDefFont(wOp *op)
{
  ChaosFontParaFont sUNUSED *para = (ChaosFontParaFont *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Height = 0x0000000e;
  para->Safety = 0x00000001;
}

void ChaosFontBindFont(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"letters"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"height"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"safety"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"outline"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"linefeed"),val);
}
void ChaosFontBind2Font(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"name");
    name[2] = sPoolString(L"letters");
    name[3] = sPoolString(L"height");
    name[4] = sPoolString(L"width");
    name[5] = sPoolString(L"style");
    name[6] = sPoolString(L"safety");
    name[7] = sPoolString(L"outline");
    name[8] = sPoolString(L"linefeed");
  }
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[2],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+6);
}
void ChaosFontBind3Font(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
  tb.PrintF(L"  import letters : string;\n");
  tb.PrintF(L"  import height : int;\n");
  tb.PrintF(L"  import width : int;\n");
  tb.PrintF(L"  import safety : int;\n");
  tb.PrintF(L"  import outline : int;\n");
  tb.PrintF(L"  import linefeed : int;\n");
}
const sChar *ChaosFontWikiFont =
L"= ChaosFont : Font\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Font\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosFont\n"
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
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Letters\n"
L" !i Letters\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Height\n"
L" !i Height\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Width\n"
L" !i Width\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Style\n"
L" !i Style\n"
L" !i Bold\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Italics\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Underline\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Strikeout\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i symbols\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Safety\n"
L" !i Safety\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Outline\n"
L" !i Outline\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i LineFeed\n"
L" !i LineFeed\n"
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

sBool ChaosFontCmdMergeFont(wExecutive *exe,wCommand *cmd)
{
  ChaosFontParaMergeFont sUNUSED *para = (ChaosFontParaMergeFont *)(cmd->Data); para;
  ChaosFont sUNUSED *in0 = cmd->GetInput<ChaosFont *>(0); in0;
  BitmapBase sUNUSED *in1 = cmd->GetInput<BitmapBase *>(1); in1;
  ChaosFont *out = (ChaosFont *) cmd->Output;
  if(!out) { out=new ChaosFont; cmd->Output=out; }

  {
#line 92 "chaos_font_ops.ops"

    out->CopyFrom(in0);
    in1->CopyTo(out->Image)
  ;
#line 439 "chaos_font_ops.cpp"
    return 1;
  }
}

void ChaosFontGuiMergeFont(wGridFrameHelper &gh,wOp *op)
{
  ChaosFontParaMergeFont sUNUSED *para = (ChaosFontParaMergeFont *)(op->EditData); para;
}

void ChaosFontDefMergeFont(wOp *op)
{
  ChaosFontParaMergeFont sUNUSED *para = (ChaosFontParaMergeFont *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosFontBindMergeFont(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosFontBind2MergeFont(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosFontBind3MergeFont(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosFontWikiMergeFont =
L"= ChaosFont : MergeFont\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MergeFont\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosFont\n"
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
L" !i BitmapBase\n"
L" !i\n"
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

sBool ChaosFontCmdAddSymbol(wExecutive *exe,wCommand *cmd)
{
  ChaosFontParaAddSymbol sUNUSED *para = (ChaosFontParaAddSymbol *)(cmd->Data); para;
  ChaosFont sUNUSED *in0 = cmd->GetInput<ChaosFont *>(0); in0;
  BitmapBase sUNUSED *in1 = cmd->GetInput<BitmapBase *>(1); in1;
  ChaosFont *out = (ChaosFont *) cmd->Output;
  if(!out) { out=new ChaosFont; cmd->Output=out; }

  {
#line 113 "chaos_font_ops.ops"

    out->CopyFrom(in0);
    sImage img;
    in1->CopyTo(&img);
    sRect r;
    r.Init(para->Start[0],para->Start[1],para->Start[0]+para->Size[0],para->Start[1]+para->Size[1]);
    for(sInt i=0;i<para->Count;i++)
    {
      out->Symbol(para->Char+i,r,&img,para->AdjustY);
      r.x0 += para->OffsetX;
      r.x1 += para->OffsetX;
    }
  ;
#line 526 "chaos_font_ops.cpp"
    return 1;
  }
}

void ChaosFontGuiAddSymbol(wGridFrameHelper &gh,wOp *op)
{
  ChaosFontParaAddSymbol sUNUSED *para = (ChaosFontParaAddSymbol *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Start");
  gh.BeginTied();
  sIntControl *int_Start_0 = gh.Int(&para->Start[0],0,4096,16.00000f);
  int_Start_0->Default = 0x00000000; int_Start_0->RightStep = 0.125000f;
  sIntControl *int_Start_1 = gh.Int(&para->Start[1],0,4096,16.00000f);
  int_Start_1->Default = 0x00000000; int_Start_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Size");
  gh.BeginTied();
  sIntControl *int_Size_0 = gh.Int(&para->Size[0],0,4096,16.00000f);
  int_Size_0->Default = 0x00000010; int_Size_0->RightStep = 0.125000f;
  sIntControl *int_Size_1 = gh.Int(&para->Size[1],0,4096,16.00000f);
  int_Size_1->Default = 0x00000010; int_Size_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Char");
  sIntControl *int_Char = gh.Int(&para->Char,0,65535,0.125000f);
  int_Char->Default = 0x00000000; int_Char->RightStep = 0.125000f;

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,256,0.125000f);
  int_Count->Default = 0x00000001; int_Count->RightStep = 0.125000f;

  gh.Label(L"OffsetX");
  sIntControl *int_OffsetX = gh.Int(&para->OffsetX,0,4096,16.00000f);
  int_OffsetX->Default = 0x00000010; int_OffsetX->RightStep = 0.125000f;

  gh.Label(L"AdjustY");
  sIntControl *int_AdjustY = gh.Int(&para->AdjustY,-1024,1024,1.000000f);
  int_AdjustY->Default = 0x00000000; int_AdjustY->RightStep = 0.125000f;

  gh.Label(L"Image");
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
}

void ChaosFontDefAddSymbol(wOp *op)
{
  ChaosFontParaAddSymbol sUNUSED *para = (ChaosFontParaAddSymbol *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size[0] = 0x00000010;
  para->Size[1] = 0x00000010;
  para->Count = 0x00000001;
  para->OffsetX = 0x00000010;
}

void ChaosFontBindAddSymbol(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"char"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"offsetx"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"adjusty"),val);
}
void ChaosFontBind2AddSymbol(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"start");
    name[1] = sPoolString(L"size");
    name[2] = sPoolString(L"char");
    name[3] = sPoolString(L"count");
    name[4] = sPoolString(L"offsetx");
    name[5] = sPoolString(L"adjusty");
    name[6] = sPoolString(L"image");
  }
  ctx->AddImport(name[0],ScriptTypeInt,2,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,2,cmd->Data+2);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+7);
}
void ChaosFontBind3AddSymbol(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import start : int[2];\n");
  tb.PrintF(L"  import size : int[2];\n");
  tb.PrintF(L"  import char : int;\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import offsetx : int;\n");
  tb.PrintF(L"  import adjusty : int;\n");
}
const sChar *ChaosFontWikiAddSymbol =
L"= ChaosFont : AddSymbol\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i AddSymbol\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosFont\n"
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
L" !i BitmapBase\n"
L" !i link Image\n"
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
L" !i Start\n"
L" !i Start\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Char\n"
L" !i Char\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i OffsetX\n"
L" !i OffsetX\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i AdjustY\n"
L" !i AdjustY\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Image\n"
L" !i Image\n"
L" !i link\n"
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

void ChaosFontAnimFont::Init(class ScriptContext *sc)
{
};

void ChaosFontAnimFont::Bind(class ScriptContext *sc,ChaosFontParaFont *para)
{
};

void ChaosFontAnimMergeFont::Init(class ScriptContext *sc)
{
};

void ChaosFontAnimMergeFont::Bind(class ScriptContext *sc,ChaosFontParaMergeFont *para)
{
};

void ChaosFontAnimAddSymbol::Init(class ScriptContext *sc)
{
};

void ChaosFontAnimAddSymbol::Bind(class ScriptContext *sc,ChaosFontParaAddSymbol *para)
{
};


/****************************************************************************/

void AddTypes_chaos_font_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(ChaosFontType = new ChaosFontType_);
  ChaosFontType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_chaos_font_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Font";
  cl->Label = L"Font";
  cl->OutputType = ChaosFontType;
  cl->TabType = ChaosFontType;
  cl->Command = ChaosFontCmdFont;
  cl->MakeGui = ChaosFontGuiFont;
  cl->SetDefaults = ChaosFontDefFont;
  cl->BindPara = ChaosFontBindFont;
  cl->Bind2Para = ChaosFontBind2Font;
  cl->Bind3Para = ChaosFontBind3Font;
  cl->WikiText = ChaosFontWikiFont;
  cl->ParaStrings = 2;
  cl->ParaWords = 7;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MergeFont";
  cl->Label = L"MergeFont";
  cl->OutputType = ChaosFontType;
  cl->TabType = ChaosFontType;
  cl->Command = ChaosFontCmdMergeFont;
  cl->MakeGui = ChaosFontGuiMergeFont;
  cl->SetDefaults = ChaosFontDefMergeFont;
  cl->BindPara = ChaosFontBindMergeFont;
  cl->Bind2Para = ChaosFontBind2MergeFont;
  cl->Bind3Para = ChaosFontBind3MergeFont;
  cl->WikiText = ChaosFontWikiMergeFont;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = ChaosFontType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = BitmapBaseType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"AddSymbol";
  cl->Label = L"AddSymbol";
  cl->OutputType = ChaosFontType;
  cl->TabType = ChaosFontType;
  cl->Command = ChaosFontCmdAddSymbol;
  cl->MakeGui = ChaosFontGuiAddSymbol;
  cl->SetDefaults = ChaosFontDefAddSymbol;
  cl->BindPara = ChaosFontBindAddSymbol;
  cl->Bind2Para = ChaosFontBind2AddSymbol;
  cl->Bind3Para = ChaosFontBind3AddSymbol;
  cl->WikiText = ChaosFontWikiAddSymbol;
  cl->ParaWords = 8;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = ChaosFontType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = BitmapBaseType;
  in[1].DefaultClass = 0;
  in[1].Name = L"Image";
  in[1].Flags = 0|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(chaos_font_ops,0x110,AddOps_chaos_font_ops,0);


/****************************************************************************/


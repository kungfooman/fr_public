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
#include "fr063_chaos_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 13 "fr063_chaos_ops.ops"

#include "wz4frlib/fr063_chaos.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 

#line 30 "fr063_chaos_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdFR063_Water(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_Water sUNUSED *para = (Wz4RenderParaFR063_Water *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 48 "fr063_chaos_ops.ops"

    RNFR063_Water *node = new RNFR063_Water();
    node->ParaBase = node->Para = *para;
    node->Mtrl = in0; in0->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 54 "fr063_chaos_ops.cpp"
    return 1;
  }
}

sInt Wz4RenderActFR063_Water(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaFR063_Water sUNUSED *para = (Wz4RenderParaFR063_Water *)(op->EditData); para;
#line 57 "fr063_chaos_ops.ops"

    if(code==1)
    {
      return 1;
    }
    return 0;
  ;
#line 70 "fr063_chaos_ops.cpp"
}

void Wz4RenderGuiFR063_Water(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_Water sUNUSED *para = (Wz4RenderParaFR063_Water *)(op->EditData); para;

  gh.Group(L"Water");

  gh.Label(L"BowlCount");
  sIntControl *int_BowlCount = gh.Int(&para->BowlCount,1,60000,0.125000f);
  int_BowlCount->Default = 0x00002710; int_BowlCount->RightStep = 0.125000f;

  if(0x0000)
  {
    gh.Label(L"BowlSize");
    sFloatControl *float_BowlSize = gh.Float(&para->BowlSize,0.000000f,1024.000f,0.125000f);
    float_BowlSize->Default = 2.000000f; float_BowlSize->RightStep = 0.125000f;

  }
  gh.Label(L"DropCount");
  sIntControl *int_DropCount = gh.Int(&para->DropCount,1,2000,0.125000f);
  int_DropCount->Default = 0x000001f4; int_DropCount->RightStep = 0.125000f;

  gh.Label(L"DropSize");
  sFloatControl *float_DropSize = gh.Float(&para->DropSize,0.000000f,1024.000f,0.125000f);
  float_DropSize->Default = 0.500000f; float_DropSize->RightStep = 0.125000f;

  gh.Group(L"Pyhsics");

  gh.Label(L"Gravity");
  sFloatControl *float_Gravity = gh.Float(&para->Gravity,-1024.00f,1024.000f,0.000001f);
  float_Gravity->Default = -0.000050f; float_Gravity->RightStep = 0.125000f;

  gh.Label(L"OuterForce");
  sFloatControl *float_OuterForce = gh.Float(&para->OuterForce,0.000000f,1.000000f,0.000001f);
  float_OuterForce->Default = 0.000100f; float_OuterForce->RightStep = 0.125000f;

  gh.Label(L"InnerForce");
  sFloatControl *float_InnerForce = gh.Float(&para->InnerForce,0.000000f,1.000000f,0.000100f);
  float_InnerForce->Default = 0.010000f; float_InnerForce->RightStep = 0.125000f;

  gh.Label(L"InteractRadius");
  sFloatControl *float_InteractRadius = gh.Float(&para->InteractRadius,0.000000f,1.000000f,0.000100f);
  float_InteractRadius->Default = 0.100000f; float_InteractRadius->RightStep = 0.125000f;

  gh.Label(L"Friction");
  sFloatControl *float_Friction = gh.Float(&para->Friction,0.000000f,1.000000f,0.000100f);
  float_Friction->Default = 0.995000f; float_Friction->RightStep = 0.125000f;

  gh.Group(L"Render");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Reset",gh.ActionMsg);

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

void Wz4RenderDefFR063_Water(wOp *op)
{
  Wz4RenderParaFR063_Water sUNUSED *para = (Wz4RenderParaFR063_Water *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->BowlCount = 0x00002710;
  para->BowlSize = 2.000000f;
  para->DropCount = 0x000001f4;
  para->DropSize = 0.500000f;
  para->Gravity = -0.000050f;
  para->OuterForce = 0.000100f;
  para->InnerForce = 0.010000f;
  para->InteractRadius = 0.100000f;
  para->Friction = 0.995000f;
}

void Wz4RenderBindFR063_Water(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"bowlcount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"bowlsize"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"dropcount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"dropsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"outerforce"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"innerforce"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"interactradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"friction"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_Water(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[17];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"water");
    name[1] = sPoolString(L"bowlcount");
    name[2] = sPoolString(L"bowlsize");
    name[3] = sPoolString(L"dropcount");
    name[4] = sPoolString(L"dropsize");
    name[5] = sPoolString(L"pyhsics");
    name[6] = sPoolString(L"gravity");
    name[7] = sPoolString(L"outerforce");
    name[8] = sPoolString(L"innerforce");
    name[9] = sPoolString(L"interactradius");
    name[10] = sPoolString(L"friction");
    name[11] = sPoolString(L"render");
    name[12] = sPoolString(L"reset");
    name[13] = sPoolString(L"lightenv");
    name[14] = sPoolString(L"renderpass");
    name[15] = sPoolString(L"");
    name[16] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[13],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[14],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[16],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_Water(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import bowlcount : int;\n");
  tb.PrintF(L"  import bowlsize : float;\n");
  tb.PrintF(L"  import dropcount : int;\n");
  tb.PrintF(L"  import dropsize : float;\n");
  tb.PrintF(L"  import gravity : float;\n");
  tb.PrintF(L"  import outerforce : float;\n");
  tb.PrintF(L"  import innerforce : float;\n");
  tb.PrintF(L"  import interactradius : float;\n");
  tb.PrintF(L"  import friction : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_Water =
L"= Wz4Render : FR063_Water\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_Water\n"
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
L" !i BowlCount\n"
L" !i BowlCount\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i BowlSize\n"
L" !i BowlSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DropCount\n"
L" !i DropCount\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i DropSize\n"
L" !i DropSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i OuterForce\n"
L" !i OuterForce\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i InnerForce\n"
L" !i InnerForce\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i InteractRadius\n"
L" !i InteractRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Friction\n"
L" !i Friction\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Reset\n"
L" !i Reset\n"
L" !i action\n"
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

sBool Wz4RenderCmdFR063_MultiProgress(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_MultiProgress sUNUSED *para = (Wz4RenderParaFR063_MultiProgress *)(cmd->Data); para;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 79 "fr063_chaos_ops.ops"

    RNFR063_MultiProgress *node = new RNFR063_MultiProgress();    
    node->ParaBase = node->Para = *para;
/*
    node->Mtrl = in0; in0->AddRef();
    node->Init();
    */
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 379 "fr063_chaos_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFR063_MultiProgress(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_MultiProgress sUNUSED *para = (Wz4RenderParaFR063_MultiProgress *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Cores (0=actual)");
  sIntControl *int_Cores = gh.Int(&para->Cores,0,64,0.125000f);
  int_Cores->Default = 0x00000000; int_Cores->RightStep = 0.125000f;

  gh.Label(L"* Animate");
  sFloatControl *float_Animate = gh.Float(&para->Animate,0.000000f,1.000000f,0.125000f);
  float_Animate->Default = 0.000000f; float_Animate->RightStep = 0.125000f;

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

void Wz4RenderDefFR063_MultiProgress(wOp *op)
{
  Wz4RenderParaFR063_MultiProgress sUNUSED *para = (Wz4RenderParaFR063_MultiProgress *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindFR063_MultiProgress(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"cores"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"animate"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_MultiProgress(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"cores");
    name[1] = sPoolString(L"animate");
    name[2] = sPoolString(L"renderpass");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_MultiProgress(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import cores : int;\n");
  tb.PrintF(L"  import animate : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_MultiProgress =
L"= Wz4Render : FR063_MultiProgress\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_MultiProgress\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Render\n"
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
L" !i Cores (0=actual)\n"
L" !i Cores\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Animate\n"
L" !i Animate\n"
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

void Wz4RenderAnimFR063_Water::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimFR063_Water::Bind(class ScriptContext *sc,Wz4RenderParaFR063_Water *para)
{
};

void Wz4RenderAnimFR063_MultiProgress::Init(class ScriptContext *sc)
{
  _Animate = sc->AddSymbol(L"animate");
};

void Wz4RenderAnimFR063_MultiProgress::Bind(class ScriptContext *sc,Wz4RenderParaFR063_MultiProgress *para)
{
  sc->BindLocalFloat(_Animate,1,&para->Animate);
};


/****************************************************************************/

void AddTypes_fr063_chaos_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_fr063_chaos_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"FR063_Water";
  cl->Label = L"FR063_Water";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_Water;
  cl->MakeGui = Wz4RenderGuiFR063_Water;
  cl->SetDefaults = Wz4RenderDefFR063_Water;
  cl->BindPara = Wz4RenderBindFR063_Water;
  cl->Bind2Para = Wz4RenderBind2FR063_Water;
  cl->Bind3Para = Wz4RenderBind3FR063_Water;
  cl->WikiText = Wz4RenderWikiFR063_Water;
  cl->Actions = Wz4RenderActFR063_Water;
  cl->ParaStrings = 1;
  cl->ParaWords = 11;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  cl->ActionIds.AddMany(1)->Init(L"Reset",1);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_MultiProgress";
  cl->Label = L"FR063_MultiProgress";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_MultiProgress;
  cl->MakeGui = Wz4RenderGuiFR063_MultiProgress;
  cl->SetDefaults = Wz4RenderDefFR063_MultiProgress;
  cl->BindPara = Wz4RenderBindFR063_MultiProgress;
  cl->Bind2Para = Wz4RenderBind2FR063_MultiProgress;
  cl->Bind3Para = Wz4RenderBind3FR063_MultiProgress;
  cl->WikiText = Wz4RenderWikiFR063_MultiProgress;
  cl->ParaStrings = 1;
  cl->ParaWords = 3;
  cl->Column = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fr063_chaos_ops,0x110,AddOps_fr063_chaos_ops,0);


/****************************************************************************/


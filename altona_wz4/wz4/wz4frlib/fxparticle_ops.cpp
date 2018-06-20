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
#include "fxparticle_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4ExplosionType_ *Wz4ExplosionType;

/****************************************************************************/

#line 13 "fxparticle_ops.ops"

#include "wz4frlib/fxparticle.hpp"
#include "wz4frlib/fxparticle_mc.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 

#line 32 "fxparticle_ops.cpp"

/****************************************************************************/

#line 120 "fxparticle_ops.ops"
void Wz4ExplosionType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 121 "fxparticle_ops.ops"

    sSetTarget(sTargetPara(sCLEAR_ALL,pi.BackColor,pi.Spec));
  ;
#line 43 "fxparticle_ops.cpp"
}

/****************************************************************************/

sBool Wz4ParticlesCmdCloud(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaCloud sUNUSED *para = (Wz4ParticlesParaCloud *)(cmd->Data); para;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 40 "fxparticle_ops.ops"

    RPCloud *node = new RPCloud();
    node->ParaBase = node->Para = *para;
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 63 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiCloud(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaCloud sUNUSED *para = (Wz4ParticlesParaCloud *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,65536,0.125000f);
  int_Count->Default = 0x00000100; int_Count->RightStep = 0.125000f;

  gh.Label(L"* CloudSize");
  gh.BeginTied();
  sFloatControl *float_CloudSize_0 = gh.Float(&para->CloudSize[0],-1024.00f,1024.000f,0.010000f);
  float_CloudSize_0->Default = 1.000000f; float_CloudSize_0->RightStep = 0.125000f;
  sFloatControl *float_CloudSize_1 = gh.Float(&para->CloudSize[1],-1024.00f,1024.000f,0.010000f);
  float_CloudSize_1->Default = 1.000000f; float_CloudSize_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* CloudFreq");
  gh.BeginTied();
  sFloatControl *float_CloudFreq_0 = gh.Float(&para->CloudFreq[0],-1024.00f,1024.000f,0.010000f);
  float_CloudFreq_0->Default = 1.000000f; float_CloudFreq_0->RightStep = 0.125000f;
  sFloatControl *float_CloudFreq_1 = gh.Float(&para->CloudFreq[1],-1024.00f,1024.000f,0.010000f);
  float_CloudFreq_1->Default = 4.000000f; float_CloudFreq_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* CloudPos");
  gh.BeginTied();
  sFloatControl *float_CloudPos_0 = gh.Float(&para->CloudPos.x, -1000000,  1000000,0.000100f);
  float_CloudPos_0->Default = 0.000000f; float_CloudPos_0->RightStep = 0.125000f;
  sFloatControl *float_CloudPos_1 = gh.Float(&para->CloudPos.y, -1000000,  1000000,0.000100f);
  float_CloudPos_1->Default = 0.000000f; float_CloudPos_1->RightStep = 0.125000f;
  sFloatControl *float_CloudPos_2 = gh.Float(&para->CloudPos.z, -1000000,  1000000,0.000100f);
  float_CloudPos_2->Default = 0.000000f; float_CloudPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefCloud(wOp *op)
{
  Wz4ParticlesParaCloud sUNUSED *para = (Wz4ParticlesParaCloud *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000100;
  para->CloudSize[0] = 1.000000f;
  para->CloudSize[1] = 1.000000f;
  para->CloudFreq[0] = 1.000000f;
  para->CloudFreq[1] = 4.000000f;
}

void Wz4ParticlesBindCloud(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"cloudsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"cloudsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"cloudfreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"cloudfreq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"cloudpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"cloudpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"cloudpos"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2Cloud(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"count");
    name[1] = sPoolString(L"cloudsize");
    name[2] = sPoolString(L"cloudfreq");
    name[3] = sPoolString(L"cloudpos");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3Cloud(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import cloudsize : float[2];\n");
  tb.PrintF(L"  import cloudfreq : float[2];\n");
  tb.PrintF(L"  import cloudpos : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiCloud =
L"= Wz4Particles : Cloud\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Cloud\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i CloudSize\n"
L" !i CloudSize\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i CloudFreq\n"
L" !i CloudFreq\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i CloudPos\n"
L" !i CloudPos\n"
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

sBool Wz4ParticlesCmdBallistic(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaBallistic sUNUSED *para = (Wz4ParticlesParaBallistic *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 78 "fxparticle_ops.ops"

    RPBallistic *node = new RPBallistic();
    node->ParaBase = node->Para = *para;
    if(in0)
    {
      node->Source = in0->RootNode; in0->RootNode->AddRef();
    }
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 261 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiBallistic(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaBallistic sUNUSED *para = (Wz4ParticlesParaBallistic *)(op->EditData); para;
  gh.Group(op->Class->Label);

  if(!(op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Count");
    sIntControl *int_Count = gh.Int(&para->Count,1,65536,0.125000f);
    int_Count->Default = 0x00000100; int_Count->RightStep = 0.125000f;

  }
  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Group(L"Movement");

  gh.Label(L"CreateFlags");
  gh.Flags(&para->CreateFlags,L"Sphere|Square|Bouble",gh.ChangeMsg);

  gh.Label(L"* Gravity");
  gh.BeginTied();
  sFloatControl *float_Gravity_0 = gh.Float(&para->Gravity.x, -1000000,  1000000,0.001000f);
  float_Gravity_0->Default = 0.000000f; float_Gravity_0->RightStep = 0.125000f;
  sFloatControl *float_Gravity_1 = gh.Float(&para->Gravity.y, -1000000,  1000000,0.001000f);
  float_Gravity_1->Default = -0.010000f; float_Gravity_1->RightStep = 0.125000f;
  sFloatControl *float_Gravity_2 = gh.Float(&para->Gravity.z, -1000000,  1000000,0.001000f);
  float_Gravity_2->Default = 0.000000f; float_Gravity_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* PosStart");
  gh.BeginTied();
  sFloatControl *float_PosStart_0 = gh.Float(&para->PosStart.x,-1024.00f,1024.000f,0.010000f);
  float_PosStart_0->Default = 0.000000f; float_PosStart_0->RightStep = 0.125000f;
  sFloatControl *float_PosStart_1 = gh.Float(&para->PosStart.y,-1024.00f,1024.000f,0.010000f);
  float_PosStart_1->Default = 0.000000f; float_PosStart_1->RightStep = 0.125000f;
  sFloatControl *float_PosStart_2 = gh.Float(&para->PosStart.z,-1024.00f,1024.000f,0.010000f);
  float_PosStart_2->Default = 0.000000f; float_PosStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* PosRand");
  gh.BeginTied();
  sFloatControl *float_PosRand_0 = gh.Float(&para->PosRand.x,-1024.00f,1024.000f,0.010000f);
  float_PosRand_0->Default = 1.000000f; float_PosRand_0->RightStep = 0.125000f;
  sFloatControl *float_PosRand_1 = gh.Float(&para->PosRand.y,-1024.00f,1024.000f,0.010000f);
  float_PosRand_1->Default = 1.000000f; float_PosRand_1->RightStep = 0.125000f;
  sFloatControl *float_PosRand_2 = gh.Float(&para->PosRand.z,-1024.00f,1024.000f,0.010000f);
  float_PosRand_2->Default = 1.000000f; float_PosRand_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* SpeedStart");
  gh.BeginTied();
  sFloatControl *float_SpeedStart_0 = gh.Float(&para->SpeedStart.x,-1024.00f,1024.000f,0.010000f);
  float_SpeedStart_0->Default = 0.000000f; float_SpeedStart_0->RightStep = 0.125000f;
  sFloatControl *float_SpeedStart_1 = gh.Float(&para->SpeedStart.y,-1024.00f,1024.000f,0.010000f);
  float_SpeedStart_1->Default = 0.250000f; float_SpeedStart_1->RightStep = 0.125000f;
  sFloatControl *float_SpeedStart_2 = gh.Float(&para->SpeedStart.z,-1024.00f,1024.000f,0.010000f);
  float_SpeedStart_2->Default = 0.000000f; float_SpeedStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* SpeedRand");
  gh.BeginTied();
  sFloatControl *float_SpeedRand_0 = gh.Float(&para->SpeedRand.x,-1024.00f,1024.000f,0.010000f);
  float_SpeedRand_0->Default = 0.250000f; float_SpeedRand_0->RightStep = 0.125000f;
  sFloatControl *float_SpeedRand_1 = gh.Float(&para->SpeedRand.y,-1024.00f,1024.000f,0.010000f);
  float_SpeedRand_1->Default = 0.250000f; float_SpeedRand_1->RightStep = 0.125000f;
  sFloatControl *float_SpeedRand_2 = gh.Float(&para->SpeedRand.z,-1024.00f,1024.000f,0.010000f);
  float_SpeedRand_2->Default = 0.250000f; float_SpeedRand_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Timing");

  gh.Label(L"* BurstPercent");
  sFloatControl *float_BurstPercent = gh.Float(&para->BurstPercent,0.000000f,1.000000f,0.010000f);
  float_BurstPercent->Default = 0.000000f; float_BurstPercent->RightStep = 0.125000f;

  gh.Label(L"TimeFlags");
  gh.Flags(&para->TimeFlags,L"Once|Loop|Clamp",gh.LayoutMsg);

  gh.Label(L"* LifeTime");
  sFloatControl *float_LifeTime = gh.Float(&para->LifeTime,0.000000f,1024.000f,0.250000f);
  float_LifeTime->Default = 16.00000f; float_LifeTime->RightStep = 0.125000f;

  gh.Label(L"* Delay");
  sFloatControl *float_Delay = gh.Float(&para->Delay,0.000000f,1.000000f,0.010000f);
  float_Delay->Default = 0.000000f; float_Delay->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefBallistic(wOp *op)
{
  Wz4ParticlesParaBallistic sUNUSED *para = (Wz4ParticlesParaBallistic *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000100;
  para->Seed = 0x00000001;
  para->Gravity.y = -0.010000f;
  para->PosRand.x = 1.000000f;
  para->PosRand.y = 1.000000f;
  para->PosRand.z = 1.000000f;
  para->SpeedStart.y = 0.250000f;
  para->SpeedRand.x = 0.250000f;
  para->SpeedRand.y = 0.250000f;
  para->SpeedRand.z = 0.250000f;
  para->LifeTime = 16.00000f;
}

void Wz4ParticlesBindBallistic(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"posstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"posstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"posstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"posrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"posrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"posrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"speedstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"speedstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"speedstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"speedrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"speedrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"speedrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"burstpercent"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"lifetime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"delay"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2Ballistic(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[16];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"count");
    name[1] = sPoolString(L"seed");
    name[2] = sPoolString(L"movement");
    name[3] = sPoolString(L"createflags");
    name[4] = sPoolString(L"gravity");
    name[5] = sPoolString(L"posstart");
    name[6] = sPoolString(L"posrand");
    name[7] = sPoolString(L"speedstart");
    name[8] = sPoolString(L"speedrand");
    name[9] = sPoolString(L"timing");
    name[10] = sPoolString(L"burstpercent");
    name[11] = sPoolString(L"timeflags");
    name[12] = sPoolString(L"lifetime");
    name[13] = sPoolString(L"delay");
    name[14] = sPoolString(L"");
    name[15] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+15);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[15],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3Ballistic(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import gravity : float[3];\n");
  tb.PrintF(L"  import posstart : float[3];\n");
  tb.PrintF(L"  import posrand : float[3];\n");
  tb.PrintF(L"  import speedstart : float[3];\n");
  tb.PrintF(L"  import speedrand : float[3];\n");
  tb.PrintF(L"  import burstpercent : float;\n");
  tb.PrintF(L"  import lifetime : float;\n");
  tb.PrintF(L"  import delay : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiBallistic =
L"= Wz4Particles : Ballistic\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Ballistic\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i CreateFlags\n"
L" !i CreateFlags\n"
L" !i Sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Square\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Bouble\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i PosStart\n"
L" !i PosStart\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i PosRand\n"
L" !i PosRand\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i SpeedStart\n"
L" !i SpeedStart\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i SpeedRand\n"
L" !i SpeedRand\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i BurstPercent\n"
L" !i BurstPercent\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i TimeFlags\n"
L" !i TimeFlags\n"
L" !i Once\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Loop\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Clamp\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i LifeTime\n"
L" !i LifeTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Delay\n"
L" !i Delay\n"
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

sBool Wz4ParticlesCmdMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaMesh sUNUSED *para = (Wz4ParticlesParaMesh *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 98 "fxparticle_ops.ops"

    if(!in0)
      return 0;

    RPMesh *node = new RPMesh();
    in0->Charge();
    node->Init(in0);
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 645 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaMesh sUNUSED *para = (Wz4ParticlesParaMesh *)(op->EditData); para;
}

void Wz4ParticlesDefMesh(wOp *op)
{
  Wz4ParticlesParaMesh sUNUSED *para = (Wz4ParticlesParaMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4ParticlesBindMesh(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4ParticlesBind2Mesh(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4ParticlesBind3Mesh(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4ParticlesWikiMesh =
L"= Wz4Particles : Mesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Mesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4ExplosionCmdExplosion(wExecutive *exe,wCommand *cmd)
{
  Wz4ExplosionParaExplosion sUNUSED *para = (Wz4ExplosionParaExplosion *)(cmd->Data); para;
  Wz4Explosion *out = (Wz4Explosion *) cmd->Output;
  if(!out) { out=new Wz4Explosion; cmd->Output=out; }

  {
#line 155 "fxparticle_ops.ops"

    out->Para = *para;
  ;
#line 716 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ExplosionHndExplosion(wPaintInfo &pi,wOp *op)
{
  Wz4ExplosionParaExplosion sUNUSED *para = (Wz4ExplosionParaExplosion *)(op->EditData); para;
#line 160 "fxparticle_ops.ops"

    pi.Handle3D(op,1,para->Position,wHM_PLANE);
  ;
#line 728 "fxparticle_ops.cpp"
}

void Wz4ExplosionGuiExplosion(wGridFrameHelper &gh,wOp *op)
{
  Wz4ExplosionParaExplosion sUNUSED *para = (Wz4ExplosionParaExplosion *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Position");
  gh.BeginTied();
  sFloatControl *float_Position_0 = gh.Float(&para->Position.x,-65536.0f,65536.00f,0.001000f);
  float_Position_0->Default = 0.000000f; float_Position_0->RightStep = 0.125000f;
  sFloatControl *float_Position_1 = gh.Float(&para->Position.y,-65536.0f,65536.00f,0.001000f);
  float_Position_1->Default = 0.000000f; float_Position_1->RightStep = 0.125000f;
  sFloatControl *float_Position_2 = gh.Float(&para->Position.z,-65536.0f,65536.00f,0.001000f);
  float_Position_2->Default = 0.000000f; float_Position_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Falloff");
  sFloatControl *float_Falloff = gh.Float(&para->Falloff,-1024.00f,1024.000f,0.001000f);
  float_Falloff->Default = -2.00000f; float_Falloff->RightStep = 0.125000f;

  gh.Label(L"SpeedConstant");
  gh.BeginTied();
  sFloatControl *float_SpeedConstant_0 = gh.Float(&para->SpeedConstant.x,-65536.0f,65536.00f,0.001000f);
  float_SpeedConstant_0->Default = 0.000000f; float_SpeedConstant_0->RightStep = 0.125000f;
  sFloatControl *float_SpeedConstant_1 = gh.Float(&para->SpeedConstant.y,-65536.0f,65536.00f,0.001000f);
  float_SpeedConstant_1->Default = 0.000000f; float_SpeedConstant_1->RightStep = 0.125000f;
  sFloatControl *float_SpeedConstant_2 = gh.Float(&para->SpeedConstant.z,-65536.0f,65536.00f,0.001000f);
  float_SpeedConstant_2->Default = 0.000000f; float_SpeedConstant_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"SpeedExplode");
  gh.BeginTied();
  sFloatControl *float_SpeedExplode_0 = gh.Float(&para->SpeedExplode.x,-65536.0f,65536.00f,0.001000f);
  float_SpeedExplode_0->Default = 1.000000f; float_SpeedExplode_0->RightStep = 0.125000f;
  sFloatControl *float_SpeedExplode_1 = gh.Float(&para->SpeedExplode.y,-65536.0f,65536.00f,0.001000f);
  float_SpeedExplode_1->Default = 1.000000f; float_SpeedExplode_1->RightStep = 0.125000f;
  sFloatControl *float_SpeedExplode_2 = gh.Float(&para->SpeedExplode.z,-65536.0f,65536.00f,0.001000f);
  float_SpeedExplode_2->Default = 1.000000f; float_SpeedExplode_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"SpeedRandom");
  gh.BeginTied();
  sFloatControl *float_SpeedRandom_0 = gh.Float(&para->SpeedRandom.x,-65536.0f,65536.00f,0.001000f);
  float_SpeedRandom_0->Default = 0.100000f; float_SpeedRandom_0->RightStep = 0.125000f;
  sFloatControl *float_SpeedRandom_1 = gh.Float(&para->SpeedRandom.y,-65536.0f,65536.00f,0.001000f);
  float_SpeedRandom_1->Default = 0.100000f; float_SpeedRandom_1->RightStep = 0.125000f;
  sFloatControl *float_SpeedRandom_2 = gh.Float(&para->SpeedRandom.z,-65536.0f,65536.00f,0.001000f);
  float_SpeedRandom_2->Default = 0.100000f; float_SpeedRandom_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Timing");

  gh.Label(L"TimingFlags");
  gh.Flags(&para->TimingFlags,L"use position|separate origin:*1clamp time|reject time",gh.LayoutMsg);

  if((para->TimingFlags&0x0001))
  {
    gh.Label(L"IgnitionPos");
    gh.BeginTied();
    sFloatControl *float_IgnitionPos_0 = gh.Float(&para->IgnitionPos.x,-65536.0f,65536.00f,0.001000f);
    float_IgnitionPos_0->Default = 0.000000f; float_IgnitionPos_0->RightStep = 0.125000f;
    sFloatControl *float_IgnitionPos_1 = gh.Float(&para->IgnitionPos.y,-65536.0f,65536.00f,0.001000f);
    float_IgnitionPos_1->Default = 0.000000f; float_IgnitionPos_1->RightStep = 0.125000f;
    sFloatControl *float_IgnitionPos_2 = gh.Float(&para->IgnitionPos.z,-65536.0f,65536.00f,0.001000f);
    float_IgnitionPos_2->Default = 0.000000f; float_IgnitionPos_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"IgnitionTime");
  sFloatControl *float_IgnitionTime = gh.Float(&para->IgnitionTime,0.000000f,256.0000f,0.001000f);
  float_IgnitionTime->Default = 0.000000f; float_IgnitionTime->RightStep = 0.125000f;

  gh.Label(L"IgnitionRand");
  sFloatControl *float_IgnitionRand = gh.Float(&para->IgnitionRand,0.000000f,256.0000f,0.001000f);
  float_IgnitionRand->Default = 0.100000f; float_IgnitionRand->RightStep = 0.125000f;

  gh.Label(L"IgnitionSpeed");
  sFloatControl *float_IgnitionSpeed = gh.Float(&para->IgnitionSpeed,-65536.0f,65536.00f,0.001000f);
  float_IgnitionSpeed->Default = 1.000000f; float_IgnitionSpeed->RightStep = 0.125000f;

  gh.Label(L"Shape");
  gh.BeginTied();
  sFloatControl *float_Shape_0 = gh.Float(&para->Shape.x,-65536.0f,65536.00f,0.001000f);
  float_Shape_0->Default = 1.000000f; float_Shape_0->RightStep = 0.125000f;
  sFloatControl *float_Shape_1 = gh.Float(&para->Shape.y,-65536.0f,65536.00f,0.001000f);
  float_Shape_1->Default = 1.000000f; float_Shape_1->RightStep = 0.125000f;
  sFloatControl *float_Shape_2 = gh.Float(&para->Shape.z,-65536.0f,65536.00f,0.001000f);
  float_Shape_2->Default = 1.000000f; float_Shape_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Rotation");
  gh.BeginTied();
  sFloatControl *float_Rotation_0 = gh.Float(&para->Rotation.x,-64.0000f,64.00000f,0.001000f);
  float_Rotation_0->Default = 0.000000f; float_Rotation_0->RightStep = 0.125000f;
  sFloatControl *float_Rotation_1 = gh.Float(&para->Rotation.y,-64.0000f,64.00000f,0.001000f);
  float_Rotation_1->Default = 0.000000f; float_Rotation_1->RightStep = 0.125000f;
  sFloatControl *float_Rotation_2 = gh.Float(&para->Rotation.z,-64.0000f,64.00000f,0.001000f);
  float_Rotation_2->Default = 0.000000f; float_Rotation_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"DistancePower");
  sFloatControl *float_DistancePower = gh.Float(&para->DistancePower,-256.000f,256.0000f,0.001000f);
  float_DistancePower->Default = 1.000000f; float_DistancePower->RightStep = 0.125000f;

  gh.Label(L"TimeMin");
  sFloatControl *float_TimeMin = gh.Float(&para->TimeMin,-1024.00f,1024.000f,0.001000f);
  float_TimeMin->Default = -256.000f; float_TimeMin->RightStep = 0.125000f;

  gh.Label(L"TimeMax");
  sFloatControl *float_TimeMax = gh.Float(&para->TimeMax,-1024.00f,1024.000f,0.001000f);
  float_TimeMax->Default = 256.0000f; float_TimeMax->RightStep = 0.125000f;
}

void Wz4ExplosionDefExplosion(wOp *op)
{
  Wz4ExplosionParaExplosion sUNUSED *para = (Wz4ExplosionParaExplosion *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Falloff = -2.00000f;
  para->SpeedExplode.x = 1.000000f;
  para->SpeedExplode.y = 1.000000f;
  para->SpeedExplode.z = 1.000000f;
  para->SpeedRandom.x = 0.100000f;
  para->SpeedRandom.y = 0.100000f;
  para->SpeedRandom.z = 0.100000f;
  para->IgnitionRand = 0.100000f;
  para->IgnitionSpeed = 1.000000f;
  para->Shape.x = 1.000000f;
  para->Shape.y = 1.000000f;
  para->Shape.z = 1.000000f;
  para->DistancePower = 1.000000f;
  para->TimeMin = -256.000f;
  para->TimeMax = 256.0000f;
}

void Wz4ExplosionBindExplosion(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"falloff"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"speedconstant"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"speedconstant"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"speedconstant"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"speedexplode"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"speedexplode"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"speedexplode"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"speedrandom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"speedrandom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"speedrandom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"ignitionpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"ignitionpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"ignitionpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"ignitiontime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"ignitionrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"ignitionspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"shape"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"shape"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"shape"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"distancepower"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"timemin"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"timemax"),val);
}
void Wz4ExplosionBind2Explosion(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[16];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"position");
    name[1] = sPoolString(L"falloff");
    name[2] = sPoolString(L"speedconstant");
    name[3] = sPoolString(L"speedexplode");
    name[4] = sPoolString(L"speedrandom");
    name[5] = sPoolString(L"timing");
    name[6] = sPoolString(L"timingflags");
    name[7] = sPoolString(L"ignitionpos");
    name[8] = sPoolString(L"ignitiontime");
    name[9] = sPoolString(L"ignitionrand");
    name[10] = sPoolString(L"ignitionspeed");
    name[11] = sPoolString(L"shape");
    name[12] = sPoolString(L"rotation");
    name[13] = sPoolString(L"distancepower");
    name[14] = sPoolString(L"timemin");
    name[15] = sPoolString(L"timemax");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+14);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[11],ScriptTypeFloat,3,cmd->Data+20);
  ctx->AddImport(name[12],ScriptTypeFloat,3,cmd->Data+23);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+26);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+28);
}
void Wz4ExplosionBind3Explosion(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import position : float[3];\n");
  tb.PrintF(L"  import falloff : float;\n");
  tb.PrintF(L"  import speedconstant : float[3];\n");
  tb.PrintF(L"  import speedexplode : float[3];\n");
  tb.PrintF(L"  import speedrandom : float[3];\n");
  tb.PrintF(L"  import ignitionpos : float[3];\n");
  tb.PrintF(L"  import ignitiontime : float;\n");
  tb.PrintF(L"  import ignitionrand : float;\n");
  tb.PrintF(L"  import ignitionspeed : float;\n");
  tb.PrintF(L"  import shape : float[3];\n");
  tb.PrintF(L"  import rotation : float[3];\n");
  tb.PrintF(L"  import distancepower : float;\n");
  tb.PrintF(L"  import timemin : float;\n");
  tb.PrintF(L"  import timemax : float;\n");
}
const sChar *Wz4ExplosionWikiExplosion =
L"= Wz4Explosion : Explosion\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Explosion\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Explosion\n"
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
L" !i Position\n"
L" !i Position\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Falloff\n"
L" !i Falloff\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpeedConstant\n"
L" !i SpeedConstant\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i SpeedExplode\n"
L" !i SpeedExplode\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i SpeedRandom\n"
L" !i SpeedRandom\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i TimingFlags\n"
L" !i TimingFlags\n"
L" !i use position\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i separate origin\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i clamp time\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i reject time\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i IgnitionPos\n"
L" !i IgnitionPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i IgnitionTime\n"
L" !i IgnitionTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i IgnitionRand\n"
L" !i IgnitionRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i IgnitionSpeed\n"
L" !i IgnitionSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Shape\n"
L" !i Shape\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rotation\n"
L" !i Rotation\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i DistancePower\n"
L" !i DistancePower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeMin\n"
L" !i TimeMin\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeMax\n"
L" !i TimeMax\n"
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

sBool Wz4ParticlesCmdExploder(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaExploder sUNUSED *para = (Wz4ParticlesParaExploder *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Explosion sUNUSED *in1 = cmd->GetInput<Wz4Explosion *>(1); in1;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 181 "fxparticle_ops.ops"

    if(!in0)
      return 0;

    RPExploder *node = new RPExploder();
    node->Para = *para;
    in0->Charge();
    node->Init(in0,cmd);
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 1155 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiExploder(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaExploder sUNUSED *para = (Wz4ParticlesParaExploder *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Group(L"Physics");

  gh.Label(L"* Gravity");
  gh.BeginTied();
  sFloatControl *float_Gravity_0 = gh.Float(&para->Gravity.x,-65536.0f,65536.00f,0.001000f);
  float_Gravity_0->Default = 0.000000f; float_Gravity_0->RightStep = 0.125000f;
  sFloatControl *float_Gravity_1 = gh.Float(&para->Gravity.y,-65536.0f,65536.00f,0.001000f);
  float_Gravity_1->Default = -0.010000f; float_Gravity_1->RightStep = 0.125000f;
  sFloatControl *float_Gravity_2 = gh.Float(&para->Gravity.z,-65536.0f,65536.00f,0.001000f);
  float_Gravity_2->Default = 0.000000f; float_Gravity_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Density");
  sFloatControl *float_Density = gh.Float(&para->Density,0.000000f,65536.00f,0.010000f);
  float_Density->Default = 100.0000f; float_Density->RightStep = 0.125000f;

  gh.Label(L"MaxAngularVelocity");
  sFloatControl *float_MaxAngularVelocity = gh.Float(&para->MaxAngularVelocity,0.000000f,1024.000f,0.010000f);
  float_MaxAngularVelocity->Default = 20.00000f; float_MaxAngularVelocity->RightStep = 0.125000f;

  gh.Label(L"AirDrag");
  sFloatControl *float_AirDrag = gh.Float(&para->AirDrag,0.000000f,256.0000f,0.001000f);
  float_AirDrag->Default = 1.000000f; float_AirDrag->RightStep = 0.125000f;

  gh.Label(L"RotationAirDrag");
  sFloatControl *float_RotationAirDrag = gh.Float(&para->RotationAirDrag,0.000000f,256.0000f,0.001000f);
  float_RotationAirDrag->Default = 0.300000f; float_RotationAirDrag->RightStep = 0.125000f;
}

void Wz4ParticlesDefExploder(wOp *op)
{
  Wz4ParticlesParaExploder sUNUSED *para = (Wz4ParticlesParaExploder *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Seed = 0x00000001;
  para->Gravity.y = -0.010000f;
  para->Density = 100.0000f;
  para->MaxAngularVelocity = 20.00000f;
  para->AirDrag = 1.000000f;
  para->RotationAirDrag = 0.300000f;
}

void Wz4ParticlesBindExploder(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"density"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"maxangularvelocity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"airdrag"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotationairdrag"),val);
}
void Wz4ParticlesBind2Exploder(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"seed");
    name[1] = sPoolString(L"physics");
    name[2] = sPoolString(L"gravity");
    name[3] = sPoolString(L"density");
    name[4] = sPoolString(L"maxangularvelocity");
    name[5] = sPoolString(L"airdrag");
    name[6] = sPoolString(L"rotationairdrag");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+7);
}
void Wz4ParticlesBind3Exploder(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import gravity : float[3];\n");
  tb.PrintF(L"  import density : float;\n");
  tb.PrintF(L"  import maxangularvelocity : float;\n");
  tb.PrintF(L"  import airdrag : float;\n");
  tb.PrintF(L"  import rotationairdrag : float;\n");
}
const sChar *Wz4ParticlesWikiExploder =
L"= Wz4Particles : Exploder\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Exploder\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Explosion\n"
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
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Density\n"
L" !i Density\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaxAngularVelocity\n"
L" !i MaxAngularVelocity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AirDrag\n"
L" !i AirDrag\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RotationAirDrag\n"
L" !i RotationAirDrag\n"
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

sBool Wz4ParticlesCmdCloud2(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaCloud2 sUNUSED *para = (Wz4ParticlesParaCloud2 *)(cmd->Data); para;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 215 "fxparticle_ops.ops"

    RPCloud2 *node = new RPCloud2();
    node->ParaBase = node->Para = *para;
    node->Init((Wz4ParticlesArrayCloud2 *) cmd->Array,cmd->ArrayCount);
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 1363 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesArrCloud2(wOp *op,sInt pos,void *mem)
{
  Wz4ParticlesParaCloud2 sUNUSED *para = (Wz4ParticlesParaCloud2 *)(op->EditData); para;
  Wz4ParticlesArrayCloud2 *e = (Wz4ParticlesArrayCloud2 *)(mem);
  e->Pos.x = 0.000000f;
  e->Pos.y = 0.000000f;
  e->Pos.z = 0.000000f;
  e->Scale.x = 1.000000f;
  e->Scale.y = 1.000000f;
  e->Scale.z = 1.000000f;
  e->Speed = 0.000000f;
  e->Rot = 0.000000f;
  e->Count = 0x00000000;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4ParticlesArrayCloud2 *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4ParticlesArrayCloud2 *)op->ArrayData[pos  ];
    }
    e->Pos.x = f0*p0->Pos.x + f1*p1->Pos.x;
    e->Pos.y = f0*p0->Pos.y + f1*p1->Pos.y;
    e->Pos.z = f0*p0->Pos.z + f1*p1->Pos.z;
    e->Scale.x = f0*p0->Scale.x + f1*p1->Scale.x;
    e->Scale.y = f0*p0->Scale.y + f1*p1->Scale.y;
    e->Scale.z = f0*p0->Scale.z + f1*p1->Scale.z;
    e->Speed = f0*p0->Speed + f1*p1->Speed;
    e->Rot = f0*p0->Rot + f1*p1->Rot;
  }
}

void Wz4ParticlesGuiCloud2(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaCloud2 sUNUSED *para = (Wz4ParticlesParaCloud2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Speed");
  sFloatControl *float_Speed = gh.Float(&para->Speed, -1000000,  1000000,0.010000f);
  float_Speed->Default = 0.000000f; float_Speed->RightStep = 0.125000f;

  gh.Label(L"SpeedSpread");
  sFloatControl *float_SpeedSpread = gh.Float(&para->SpeedSpread,0.000000f,2.000000f,0.001000f);
  float_SpeedSpread->Default = 0.000000f; float_SpeedSpread->RightStep = 0.125000f;
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Pos",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  gh.Grid->AddLabel(L"Scale",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  gh.Grid->AddLabel(L"Speed",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Rot",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Count",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4ParticlesArrayCloud2 *elem = (Wz4ParticlesArrayCloud2 *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&elem->Pos.x, -1000000,  1000000,0.010000f);
    float_Pos_0->Default = 0.000000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&elem->Pos.y, -1000000,  1000000,0.010000f);
    float_Pos_1->Default = 0.000000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&elem->Pos.z, -1000000,  1000000,0.010000f);
    float_Pos_2->Default = 0.000000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.BeginTied();
    sFloatControl *float_Scale_0 = gh.Float(&elem->Scale.x, -1000000,  1000000,0.010000f);
    float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Scale_1 = gh.Float(&elem->Scale.y, -1000000,  1000000,0.010000f);
    float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
    sFloatControl *float_Scale_2 = gh.Float(&elem->Scale.z, -1000000,  1000000,0.010000f);
    float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Speed = gh.Float(&elem->Speed, -1000000,  1000000,0.010000f);
    float_Speed->Default = 0.000000f; float_Speed->RightStep = 0.125000f;

    sFloatControl *float_Rot = gh.Float(&elem->Rot,-16.0000f,16.00000f,0.010000f);
    float_Rot->Default = 0.000000f; float_Rot->RightStep = 0.125000f;

    sIntControl *int_Count = gh.Int(&elem->Count,1,65536,16.00000f);
    int_Count->Default = 0x00000000; int_Count->RightStep = 0.125000f;
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

void Wz4ParticlesDefCloud2(wOp *op)
{
  Wz4ParticlesParaCloud2 sUNUSED *para = (Wz4ParticlesParaCloud2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4ParticlesBindCloud2(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"speedspread"),val);
}
void Wz4ParticlesBind2Cloud2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"speed");
    name[1] = sPoolString(L"speedspread");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void Wz4ParticlesBind3Cloud2(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import speed : float;\n");
  tb.PrintF(L"  import speedspread : float;\n");
}
const sChar *Wz4ParticlesWikiCloud2 =
L"= Wz4Particles : Cloud2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Cloud2\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Speed\n"
L" !i Speed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpeedSpread\n"
L" !i SpeedSpread\n"
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
L" !i Speed\n"
L" !i Speed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpeedSpread\n"
L" !i SpeedSpread\n"
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

sBool Wz4ParticlesCmdFromVertex(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaFromVertex sUNUSED *para = (Wz4ParticlesParaFromVertex *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 237 "fxparticle_ops.ops"

    RPFromVertex *node = new RPFromVertex();
    node->ParaBase = node->Para = *para;
    node->Init(in0);
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 1614 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiFromVertex(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaFromVertex sUNUSED *para = (Wz4ParticlesParaFromVertex *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Random");
  sFloatControl *float_Random = gh.Float(&para->Random,0.000000f,1.000000f,0.010000f);
  float_Random->Default = 1.000000f; float_Random->RightStep = 0.125000f;

  gh.Label(L"RandomSeed");
  sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
  int_RandomSeed->Default = 0x00000000; int_RandomSeed->RightStep = 0.125000f;
}

void Wz4ParticlesDefFromVertex(wOp *op)
{
  Wz4ParticlesParaFromVertex sUNUSED *para = (Wz4ParticlesParaFromVertex *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Random = 1.000000f;
}

void Wz4ParticlesBindFromVertex(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"randomseed"),val);
}
void Wz4ParticlesBind2FromVertex(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
    name[1] = sPoolString(L"random");
    name[2] = sPoolString(L"randomseed");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
}
void Wz4ParticlesBind3FromVertex(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import random : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
}
const sChar *Wz4ParticlesWikiFromVertex =
L"= Wz4Particles : FromVertex\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FromVertex\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Random\n"
L" !i Random\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomSeed\n"
L" !i RandomSeed\n"
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

sBool Wz4ParticlesCmdWobble(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaWobble sUNUSED *para = (Wz4ParticlesParaWobble *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 271 "fxparticle_ops.ops"

    RPWobble *node = new RPWobble();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 1762 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiWobble(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaWobble sUNUSED *para = (Wz4ParticlesParaWobble *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Source");
  gh.Flags(&para->Source,L"Part Time|Part Pos|Abs Time",gh.LayoutMsg);

  gh.Label(L"Function");
  gh.Flags(&para->Function,L"Perlin|Lissajous:*4flow|center",gh.LayoutMsg);

  gh.Label(L"* Freq");
  gh.BeginTied();
  sFloatControl *float_Freq_0 = gh.Float(&para->Freq.x,-1024.00f,1024.000f,0.010000f);
  float_Freq_0->Default = 0.000000f; float_Freq_0->RightStep = 0.125000f;
  sFloatControl *float_Freq_1 = gh.Float(&para->Freq.y,-1024.00f,1024.000f,0.010000f);
  float_Freq_1->Default = 0.000000f; float_Freq_1->RightStep = 0.125000f;
  sFloatControl *float_Freq_2 = gh.Float(&para->Freq.z,-1024.00f,1024.000f,0.010000f);
  float_Freq_2->Default = 0.000000f; float_Freq_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Amp");
  gh.BeginTied();
  sFloatControl *float_Amp_0 = gh.Float(&para->Amp.x,-1024.00f,1024.000f,0.010000f);
  float_Amp_0->Default = 0.000000f; float_Amp_0->RightStep = 0.125000f;
  sFloatControl *float_Amp_1 = gh.Float(&para->Amp.y,-1024.00f,1024.000f,0.010000f);
  float_Amp_1->Default = 0.000000f; float_Amp_1->RightStep = 0.125000f;
  sFloatControl *float_Amp_2 = gh.Float(&para->Amp.z,-1024.00f,1024.000f,0.010000f);
  float_Amp_2->Default = 0.000000f; float_Amp_2->RightStep = 0.125000f;
  gh.EndTied();

  if(((para->Function&0x0001)==0x0000))
  {
    gh.Label(L"Seed");
    sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
    int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  }
  gh.Label(L"* Phase");
  gh.BeginTied();
  sFloatControl *float_Phase_0 = gh.Float(&para->Phase.x,-16.0000f,16.00000f,0.001000f);
  float_Phase_0->Default = 0.000000f; float_Phase_0->RightStep = 0.125000f;
  sFloatControl *float_Phase_1 = gh.Float(&para->Phase.y,-16.0000f,16.00000f,0.001000f);
  float_Phase_1->Default = 0.000000f; float_Phase_1->RightStep = 0.125000f;
  sFloatControl *float_Phase_2 = gh.Float(&para->Phase.z,-16.0000f,16.00000f,0.001000f);
  float_Phase_2->Default = 0.000000f; float_Phase_2->RightStep = 0.125000f;
  gh.EndTied();

  if(((para->Source==0x0000)||(para->Source==0x0002)))
  {
    gh.Label(L"* Spread");
    sFloatControl *float_Spread = gh.Float(&para->Spread,0.000000f,256.0000f,0.010000f);
    float_Spread->Default = 0.000000f; float_Spread->RightStep = 0.125000f;

    gh.Label(L"* TimeFactor");
    sFloatControl *float_TimeFactor = gh.Float(&para->TimeFactor,-256.000f,256.0000f,0.010000f);
    float_TimeFactor->Default = 1.000000f; float_TimeFactor->RightStep = 0.125000f;

    gh.Label(L"* DeltaFactor");
    sFloatControl *float_DeltaFactor = gh.Float(&para->DeltaFactor,-256.000f,256.0000f,0.010000f);
    float_DeltaFactor->Default = 1.000000f; float_DeltaFactor->RightStep = 0.125000f;

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefWobble(wOp *op)
{
  Wz4ParticlesParaWobble sUNUSED *para = (Wz4ParticlesParaWobble *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Seed = 0x00000001;
  para->TimeFactor = 1.000000f;
  para->DeltaFactor = 1.000000f;
}

void Wz4ParticlesBindWobble(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"timefactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"deltafactor"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2Wobble(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"source");
    name[1] = sPoolString(L"function");
    name[2] = sPoolString(L"freq");
    name[3] = sPoolString(L"amp");
    name[4] = sPoolString(L"seed");
    name[5] = sPoolString(L"phase");
    name[6] = sPoolString(L"spread");
    name[7] = sPoolString(L"timefactor");
    name[8] = sPoolString(L"deltafactor");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"script");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[10],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3Wobble(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import freq : float[3];\n");
  tb.PrintF(L"  import amp : float[3];\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import phase : float[3];\n");
  tb.PrintF(L"  import spread : float;\n");
  tb.PrintF(L"  import timefactor : float;\n");
  tb.PrintF(L"  import deltafactor : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiWobble =
L"= Wz4Particles : Wobble\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Wobble\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i Source\n"
L" !i Source\n"
L" !i Part Time\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Part Pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Abs Time\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Function\n"
L" !i Function\n"
L" !i Perlin\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Lissajous\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i flow\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i center\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Freq\n"
L" !i Freq\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Phase\n"
L" !i Phase\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i Spread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeFactor\n"
L" !i TimeFactor\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DeltaFactor\n"
L" !i DeltaFactor\n"
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

sBool Wz4ParticlesCmdAdd(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaAdd sUNUSED *para = (Wz4ParticlesParaAdd *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 288 "fxparticle_ops.ops"

    RPAdd *node = new RPAdd();
    //node->ParaBase = *para;
    node->Sources.HintSize(cmd->InputCount);
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      Wz4Particles *in = cmd->GetInput<Wz4Particles *>(i);
      if(in && in->RootNode)
      {
        node->Sources.AddTail(in->RootNode);
        in->RootNode->AddRef();
      }
    }
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 2081 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiAdd(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaAdd sUNUSED *para = (Wz4ParticlesParaAdd *)(op->EditData); para;
}

void Wz4ParticlesDefAdd(wOp *op)
{
  Wz4ParticlesParaAdd sUNUSED *para = (Wz4ParticlesParaAdd *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4ParticlesBindAdd(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4ParticlesBind2Add(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4ParticlesBind3Add(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4ParticlesWikiAdd =
L"= Wz4Particles : Add\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Add\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
L" !i multiple optional\n"
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

sBool Wz4ParticlesCmdLissajous(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaLissajous sUNUSED *para = (Wz4ParticlesParaLissajous *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 345 "fxparticle_ops.ops"

    RPLissajous *node = new RPLissajous();
    node->ParaBase = node->Para = *para;
    node->Curves.Resize(cmd->ArrayCount);
    Wz4ParticlesArrayLissajous *ar = (Wz4ParticlesArrayLissajous *) cmd->Array;
    for(sInt i=0;i<cmd->ArrayCount;i++)
    {
      node->Curves[i].Axis  = ar[i].Axis;
      node->Curves[i].Phase = ar[i].Phase;
      node->Curves[i].Freq  = ar[i].Freq;
      node->Curves[i].Amp   = ar[i].Amp;
    }
    if(in0)
    {
      node->Source = in0->RootNode; 
      in0->RootNode->AddRef();
    }
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 2171 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesArrLissajous(wOp *op,sInt pos,void *mem)
{
  Wz4ParticlesParaLissajous sUNUSED *para = (Wz4ParticlesParaLissajous *)(op->EditData); para;
  Wz4ParticlesArrayLissajous *e = (Wz4ParticlesArrayLissajous *)(mem);
  e->Axis = 0x00000000;
  e->Phase = 0.000000f;
  e->Freq = 1.000000f;
  e->Amp = 1.000000f;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4ParticlesArrayLissajous *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4ParticlesArrayLissajous *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4ParticlesArrayLissajous *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4ParticlesArrayLissajous *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4ParticlesArrayLissajous *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4ParticlesArrayLissajous *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4ParticlesArrayLissajous *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4ParticlesArrayLissajous *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4ParticlesArrayLissajous *)op->ArrayData[pos  ];
    }
    e->Phase = f0*p0->Phase + f1*p1->Phase;
    e->Freq = f0*p0->Freq + f1*p1->Freq;
    e->Amp = f0*p0->Amp + f1*p1->Amp;
  }
}

void Wz4ParticlesGuiLissajous(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaLissajous sUNUSED *para = (Wz4ParticlesParaLissajous *)(op->EditData); para;
  gh.Group(op->Class->Label);

  if(!(op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Count");
    sIntControl *int_Count = gh.Int(&para->Count,1,65536,0.125000f);
    int_Count->Default = 0x00000001; int_Count->RightStep = 0.125000f;

  }
  gh.Label(L"* Lifetime");
  sFloatControl *float_Lifetime = gh.Float(&para->Lifetime,0.000000f,1024.000f,0.010000f);
  float_Lifetime->Default = 1.000000f; float_Lifetime->RightStep = 0.125000f;

  gh.Label(L"* Spread");
  sFloatControl *float_Spread = gh.Float(&para->Spread,0.000000f,1.000000f,0.010000f);
  float_Spread->Default = 1.000000f; float_Spread->RightStep = 0.125000f;

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 0.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 0.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 0.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Clamp:*1-|Tube:*2Random|Ordered",gh.LayoutMsg);

  gh.Label(L"* Tweak");
  gh.BeginTied();
  sFloatControl *float_Tweak_0 = gh.Float(&para->Tweak.x,-16.0000f,16.00000f,0.001000f);
  float_Tweak_0->Default = 0.000000f; float_Tweak_0->RightStep = 0.125000f;
  sFloatControl *float_Tweak_1 = gh.Float(&para->Tweak.y,-16.0000f,16.00000f,0.001000f);
  float_Tweak_1->Default = 0.000000f; float_Tweak_1->RightStep = 0.125000f;
  sFloatControl *float_Tweak_2 = gh.Float(&para->Tweak.z,-16.0000f,16.00000f,0.001000f);
  float_Tweak_2->Default = 0.000000f; float_Tweak_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* LinearTwirl");
  sFloatControl *float_LinearTwirl = gh.Float(&para->LinearTwirl,-256.000f,256.0000f,0.010000f);
  float_LinearTwirl->Default = 0.000000f; float_LinearTwirl->RightStep = 0.125000f;

  gh.Label(L"* LinearStretch");
  gh.BeginTied();
  sFloatControl *float_LinearStretch_0 = gh.Float(&para->LinearStretch.x,-1024.00f,1024.000f,0.010000f);
  float_LinearStretch_0->Default = 0.000000f; float_LinearStretch_0->RightStep = 0.125000f;
  sFloatControl *float_LinearStretch_1 = gh.Float(&para->LinearStretch.y,-1024.00f,1024.000f,0.010000f);
  float_LinearStretch_1->Default = 0.000000f; float_LinearStretch_1->RightStep = 0.125000f;
  sFloatControl *float_LinearStretch_2 = gh.Float(&para->LinearStretch.z,-1024.00f,1024.000f,0.010000f);
  float_LinearStretch_2->Default = 0.000000f; float_LinearStretch_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,256,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Label(L"* MasterPhase");
  sFloatControl *float_MasterPhase = gh.Float(&para->MasterPhase,-16.0000f,16.00000f,0.001000f);
  float_MasterPhase->Default = 0.000000f; float_MasterPhase->RightStep = 0.125000f;

  if((para->Flags&0x0002))
  {
    gh.Label(L"* TubeRandom");
    sFloatControl *float_TubeRandom = gh.Float(&para->TubeRandom,0.000000f,1024.000f,0.001000f);
    float_TubeRandom->Default = 0.000000f; float_TubeRandom->RightStep = 0.125000f;

  }
  gh.Label(L"* MasterScale");
  sFloatControl *float_MasterScale = gh.Float(&para->MasterScale,0.000000f,1024.000f,0.001000f);
  float_MasterScale->Default = 1.000000f; float_MasterScale->RightStep = 0.125000f;

  gh.Label(L"* SpeedSpread");
  sFloatControl *float_SpeedSpread = gh.Float(&para->SpeedSpread,0.000000f,1.000000f,0.001000f);
  float_SpeedSpread->Default = 0.000000f; float_SpeedSpread->RightStep = 0.125000f;

  gh.Label(L"* LinearTwist");
  sFloatControl *float_LinearTwist = gh.Float(&para->LinearTwist,-256.000f,256.0000f,0.010000f);
  float_LinearTwist->Default = 0.000000f; float_LinearTwist->RightStep = 0.125000f;

  if((para->Flags&0x0004))
  {
    gh.Label(L"* Randomness");
    sFloatControl *float_Randomness = gh.Float(&para->Randomness,0.000000f,16.00000f,0.001000f);
    float_Randomness->Default = 0.000000f; float_Randomness->RightStep = 0.125000f;

  }
  gh.Label(L"* Translate");
  gh.BeginTied();
  sFloatControl *float_Translate_0 = gh.Float(&para->Translate.x, -1000000,  1000000,0.010000f);
  float_Translate_0->Default = 0.000000f; float_Translate_0->RightStep = 0.125000f;
  sFloatControl *float_Translate_1 = gh.Float(&para->Translate.y, -1000000,  1000000,0.010000f);
  float_Translate_1->Default = 0.000000f; float_Translate_1->RightStep = 0.125000f;
  sFloatControl *float_Translate_2 = gh.Float(&para->Translate.z, -1000000,  1000000,0.010000f);
  float_Translate_2->Default = 0.000000f; float_Translate_2->RightStep = 0.125000f;
  gh.EndTied();

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
  gh.Grid->AddLabel(L"* Axis",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"* Phase",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"* Freq",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"* Amp",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4ParticlesArrayLissajous *elem = (Wz4ParticlesArrayLissajous *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    gh.Flags(&elem->Axis,L"x|y|z|twirl|scale",gh.ChangeMsg);

    sFloatControl *float_Phase = gh.Float(&elem->Phase,-16.0000f,16.00000f,0.001000f);
    float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;

    sFloatControl *float_Freq = gh.Float(&elem->Freq,-1024.00f,1024.000f,0.001000f);
    float_Freq->Default = 1.000000f; float_Freq->RightStep = 0.125000f;

    sFloatControl *float_Amp = gh.Float(&elem->Amp,-65536.0f,65536.00f,0.010000f);
    float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;
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

void Wz4ParticlesDefLissajous(wOp *op)
{
  Wz4ParticlesParaLissajous sUNUSED *para = (Wz4ParticlesParaLissajous *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000001;
  para->Lifetime = 1.000000f;
  para->Spread = 1.000000f;
  para->Seed = 0x00000001;
  para->MasterScale = 1.000000f;
}

void Wz4ParticlesBindLissajous(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lifetime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"lineartwirl"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"linearstretch"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"linearstretch"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"linearstretch"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"masterphase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"tuberandom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"masterscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"speedspread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"lineartwist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"randomness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"translate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"translate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"translate"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2Lissajous(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[18];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"count");
    name[1] = sPoolString(L"lifetime");
    name[2] = sPoolString(L"spread");
    name[3] = sPoolString(L"scale");
    name[4] = sPoolString(L"flags");
    name[5] = sPoolString(L"tweak");
    name[6] = sPoolString(L"lineartwirl");
    name[7] = sPoolString(L"linearstretch");
    name[8] = sPoolString(L"seed");
    name[9] = sPoolString(L"masterphase");
    name[10] = sPoolString(L"tuberandom");
    name[11] = sPoolString(L"masterscale");
    name[12] = sPoolString(L"speedspread");
    name[13] = sPoolString(L"lineartwist");
    name[14] = sPoolString(L"randomness");
    name[15] = sPoolString(L"translate");
    name[16] = sPoolString(L"");
    name[17] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+11);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+14);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[15],ScriptTypeFloat,3,cmd->Data+21);
  ctx->AddImport(name[17],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3Lissajous(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import lifetime : float;\n");
  tb.PrintF(L"  import spread : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import tweak : float[3];\n");
  tb.PrintF(L"  import lineartwirl : float;\n");
  tb.PrintF(L"  import linearstretch : float[3];\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import masterphase : float;\n");
  tb.PrintF(L"  import tuberandom : float;\n");
  tb.PrintF(L"  import masterscale : float;\n");
  tb.PrintF(L"  import speedspread : float;\n");
  tb.PrintF(L"  import lineartwist : float;\n");
  tb.PrintF(L"  import randomness : float;\n");
  tb.PrintF(L"  import translate : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiLissajous =
L"= Wz4Particles : Lissajous\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Lissajous\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Lifetime\n"
L" !i Lifetime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i Spread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Clamp\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Tube\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Random\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Ordered\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Tweak\n"
L" !i Tweak\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i LinearTwirl\n"
L" !i LinearTwirl\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LinearStretch\n"
L" !i LinearStretch\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MasterPhase\n"
L" !i MasterPhase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TubeRandom\n"
L" !i TubeRandom\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MasterScale\n"
L" !i MasterScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpeedSpread\n"
L" !i SpeedSpread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LinearTwist\n"
L" !i LinearTwist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Randomness\n"
L" !i Randomness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Translate\n"
L" !i Translate\n"
L" !i float[3]\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Lifetime\n"
L" !i Lifetime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i Spread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Clamp\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Tube\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Random\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Ordered\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Tweak\n"
L" !i Tweak\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i LinearTwirl\n"
L" !i LinearTwirl\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LinearStretch\n"
L" !i LinearStretch\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MasterPhase\n"
L" !i MasterPhase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TubeRandom\n"
L" !i TubeRandom\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MasterScale\n"
L" !i MasterScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpeedSpread\n"
L" !i SpeedSpread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LinearTwist\n"
L" !i LinearTwist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Randomness\n"
L" !i Randomness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Translate\n"
L" !i Translate\n"
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

sBool Wz4ParticlesCmdSplinedParticles(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaSplinedParticles sUNUSED *para = (Wz4ParticlesParaSplinedParticles *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 401 "fxparticle_ops.ops"

    RPSplinedParticles *node = new RPSplinedParticles();
    node->ParaBase = node->Para = *para;
    node->Name = cmd->Strings[1] && cmd->Strings[1][0] ? cmd->Strings[1] : L"spline";
    node->AltName = cmd->Strings[2] && cmd->Strings[2][0] ? cmd->Strings[2] : L"altspline";
    if(in0)
    {
      node->Source = in0->RootNode; 
      in0->RootNode->AddRef();
    }
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 2822 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiSplinedParticles(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaSplinedParticles sUNUSED *para = (Wz4ParticlesParaSplinedParticles *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Spline");
  gh.String(op->EditString[1]);

  gh.Label(L"AltSpline");
  gh.String(op->EditString[2]);

  if(!(op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Count");
    sIntControl *int_Count = gh.Int(&para->Count,1,65536,0.125000f);
    int_Count->Default = 0x00000001; int_Count->RightStep = 0.125000f;

  }
  gh.Label(L"* Lifetime");
  sFloatControl *float_Lifetime = gh.Float(&para->Lifetime,0.000000f,1024.000f,0.010000f);
  float_Lifetime->Default = 1.000000f; float_Lifetime->RightStep = 0.125000f;

  gh.Label(L"* Spread");
  sFloatControl *float_Spread = gh.Float(&para->Spread,0.000000f,100.0000f,0.010000f);
  float_Spread->Default = 1.000000f; float_Spread->RightStep = 0.125000f;

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 0.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 0.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 0.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Clamp Begin:*4Wrap|-:*1-|Tube:*2Random|Ordered",gh.LayoutMsg);

  gh.Label(L"Upvector");
  gh.Flags(&para->Flags,L"*3auto|specify",gh.ChangeMsg);

  if((para->Flags&0x0008))
  {
    gh.Label(L"* Tweak Upvector");
    gh.BeginTied();
    sFloatControl *float_Tweak_0 = gh.Float(&para->Tweak.x,-16.0000f,16.00000f,0.001000f);
    float_Tweak_0->Default = 0.000000f; float_Tweak_0->RightStep = 0.125000f;
    sFloatControl *float_Tweak_1 = gh.Float(&para->Tweak.y,-16.0000f,16.00000f,0.001000f);
    float_Tweak_1->Default = 0.000000f; float_Tweak_1->RightStep = 0.125000f;
    sFloatControl *float_Tweak_2 = gh.Float(&para->Tweak.z,-16.0000f,16.00000f,0.001000f);
    float_Tweak_2->Default = 0.000000f; float_Tweak_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"* LinearTwirl");
  sFloatControl *float_LinearTwirl = gh.Float(&para->LinearTwirl,-256.000f,256.0000f,0.010000f);
  float_LinearTwirl->Default = 0.000000f; float_LinearTwirl->RightStep = 0.125000f;

  gh.Label(L"* Epsilon");
  sFloatControl *float_Epsilon = gh.Float(&para->Epsilon,0.000000f,1.000000f,0.001000f);
  float_Epsilon->Default = 0.010000f; float_Epsilon->RightStep = 0.125000f;

  gh.Label(L"* AltShift");
  sFloatControl *float_AltShift = gh.Float(&para->AltShift,-64.0000f,64.00000f,0.010000f);
  float_AltShift->Default = 0.000000f; float_AltShift->RightStep = 0.125000f;

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,256,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  if((para->Flags&0x0002))
  {
    gh.Label(L"* TubeRandom");
    sFloatControl *float_TubeRandom = gh.Float(&para->TubeRandom,0.000000f,1024.000f,0.001000f);
    float_TubeRandom->Default = 0.000000f; float_TubeRandom->RightStep = 0.125000f;

  }
  if((para->Flags&0x0004))
  {
    gh.Label(L"* Randomness");
    sFloatControl *float_Randomness = gh.Float(&para->Randomness,0.000000f,15.00000f,0.001000f);
    float_Randomness->Default = 0.000000f; float_Randomness->RightStep = 0.125000f;

  }
  gh.Label(L"* MasterPhase");
  sFloatControl *float_MasterPhase = gh.Float(&para->MasterPhase,-16.0000f,16.00000f,0.001000f);
  float_MasterPhase->Default = 0.000000f; float_MasterPhase->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefSplinedParticles(wOp *op)
{
  Wz4ParticlesParaSplinedParticles sUNUSED *para = (Wz4ParticlesParaSplinedParticles *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000001;
  para->Lifetime = 1.000000f;
  para->Spread = 1.000000f;
  para->Epsilon = 0.010000f;
  para->Seed = 0x00000001;
}

void Wz4ParticlesBindSplinedParticles(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"spline"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+2;
  ctx->BindLocal(ctx->AddSymbol(L"altspline"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lifetime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"lineartwirl"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"epsilon"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"altshift"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"tuberandom"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"randomness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"masterphase"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2SplinedParticles(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[18];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"spline");
    name[1] = sPoolString(L"altspline");
    name[2] = sPoolString(L"count");
    name[3] = sPoolString(L"lifetime");
    name[4] = sPoolString(L"spread");
    name[5] = sPoolString(L"scale");
    name[6] = sPoolString(L"flags");
    name[7] = sPoolString(L"upvector");
    name[8] = sPoolString(L"tweak");
    name[9] = sPoolString(L"lineartwirl");
    name[10] = sPoolString(L"epsilon");
    name[11] = sPoolString(L"altshift");
    name[12] = sPoolString(L"seed");
    name[13] = sPoolString(L"tuberandom");
    name[14] = sPoolString(L"randomness");
    name[15] = sPoolString(L"masterphase");
    name[16] = sPoolString(L"");
    name[17] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+2);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[12],ScriptTypeInt,1,cmd->Data+13);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[17],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3SplinedParticles(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import spline : string;\n");
  tb.PrintF(L"  import altspline : string;\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import lifetime : float;\n");
  tb.PrintF(L"  import spread : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import tweak : float[3];\n");
  tb.PrintF(L"  import lineartwirl : float;\n");
  tb.PrintF(L"  import epsilon : float;\n");
  tb.PrintF(L"  import altshift : float;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import tuberandom : float;\n");
  tb.PrintF(L"  import randomness : float;\n");
  tb.PrintF(L"  import masterphase : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiSplinedParticles =
L"= Wz4Particles : SplinedParticles\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SplinedParticles\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i Spline\n"
L" !i Spline\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i AltSpline\n"
L" !i AltSpline\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Lifetime\n"
L" !i Lifetime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i Spread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Clamp Begin\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Wrap\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Tube\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Random\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Ordered\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Upvector\n"
L" !i Flags\n"
L" !i auto\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i specify\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Tweak Upvector\n"
L" !i Tweak\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i LinearTwirl\n"
L" !i LinearTwirl\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Epsilon\n"
L" !i Epsilon\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AltShift\n"
L" !i AltShift\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i TubeRandom\n"
L" !i TubeRandom\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Randomness\n"
L" !i Randomness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MasterPhase\n"
L" !i MasterPhase\n"
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

sBool Wz4ParticlesCmdTrails(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaTrails sUNUSED *para = (Wz4ParticlesParaTrails *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 430 "fxparticle_ops.ops"

    RPTrails *node = new RPTrails();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 3240 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiTrails(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaTrails sUNUSED *para = (Wz4ParticlesParaTrails *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Lifetime");
  gh.Flags(&para->Lifetime,L"Source|Trail|Both",gh.ChangeMsg);

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,255,0.125000f);
  int_Count->Default = 0x00000005; int_Count->RightStep = 0.125000f;

  gh.Label(L"Delta");
  sFloatControl *float_Delta = gh.Float(&para->Delta,-1024.00f,1024.000f,0.001000f);
  float_Delta->Default = 0.050000f; float_Delta->RightStep = 0.125000f;
}

void Wz4ParticlesDefTrails(wOp *op)
{
  Wz4ParticlesParaTrails sUNUSED *para = (Wz4ParticlesParaTrails *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000005;
  para->Delta = 0.050000f;
}

void Wz4ParticlesBindTrails(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"delta"),val);
}
void Wz4ParticlesBind2Trails(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lifetime");
    name[1] = sPoolString(L"count");
    name[2] = sPoolString(L"delta");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4ParticlesBind3Trails(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import delta : float;\n");
}
const sChar *Wz4ParticlesWikiTrails =
L"= Wz4Particles : Trails\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Trails\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i Lifetime\n"
L" !i Lifetime\n"
L" !i Source\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Trail\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Both\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Delta\n"
L" !i Delta\n"
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

sBool Wz4ParticlesCmdStaticParticles(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaStaticParticles sUNUSED *para = (Wz4ParticlesParaStaticParticles *)(cmd->Data); para;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 460 "fxparticle_ops.ops"

    RPStaticParticles *node = new RPStaticParticles();
    node->ParaBase = node->Para = *para;
    node->Init((Wz4ParticlesArrayStaticParticles *) cmd->Array,cmd->ArrayCount);
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 3383 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesHndStaticParticles(wPaintInfo &pi,wOp *op)
{
  Wz4ParticlesParaStaticParticles sUNUSED *para = (Wz4ParticlesParaStaticParticles *)(op->EditData); para;
#line 468 "fxparticle_ops.ops"

    void *data;
    sFORALL(op->ArrayData,data)
    {
      Wz4ParticlesArrayStaticParticles *e = (Wz4ParticlesArrayStaticParticles *)data;
      pi.Handle3D(op,_i+1,e->Pos,wHM_PLANE);
      sVector31 p0 =e->Pos;
      p0.y = 0;
      pi.Line3D(e->Pos,p0);
    }
  ;
#line 3403 "fxparticle_ops.cpp"
}

void Wz4ParticlesArrStaticParticles(wOp *op,sInt pos,void *mem)
{
  Wz4ParticlesParaStaticParticles sUNUSED *para = (Wz4ParticlesParaStaticParticles *)(op->EditData); para;
  Wz4ParticlesArrayStaticParticles *e = (Wz4ParticlesArrayStaticParticles *)(mem);
  e->Time = 0.000000f;
  e->Pos.x = 0.000000f;
  e->Pos.y = 0.000000f;
  e->Pos.z = 0.000000f;
  e->Rot.x = 0.000000f;
  e->Rot.y = 0.000000f;
  e->Rot.z = 0.000000f;
  e->Color = 0xffffffff;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4ParticlesArrayStaticParticles *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4ParticlesArrayStaticParticles *)op->ArrayData[pos  ];
    }
    e->Time = f0*p0->Time + f1*p1->Time;
    e->Pos.x = f0*p0->Pos.x + f1*p1->Pos.x;
    e->Pos.y = f0*p0->Pos.y + f1*p1->Pos.y;
    e->Pos.z = f0*p0->Pos.z + f1*p1->Pos.z;
    e->Rot.x = f0*p0->Rot.x + f1*p1->Rot.x;
    e->Rot.y = f0*p0->Rot.y + f1*p1->Rot.y;
    e->Rot.z = f0*p0->Rot.z + f1*p1->Rot.z;
  }
}

void Wz4ParticlesGuiStaticParticles(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaStaticParticles sUNUSED *para = (Wz4ParticlesParaStaticParticles *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0-|Rotation:*1-|Color",gh.LayoutMsg);
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Time",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Pos",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  if((para->Flags&0x0001))
  {
    gh.Grid->AddLabel(L"Rot",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  }
  if((para->Flags&0x0002))
  {
    gh.Grid->AddLabel(L"Color",pos,gh.Line,4,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=4;
  }
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4ParticlesArrayStaticParticles *elem = (Wz4ParticlesArrayStaticParticles *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    sFloatControl *float_Time = gh.Float(&elem->Time,0.000000f,1.000000f,0.001000f);
    float_Time->Default = 0.000000f; float_Time->RightStep = 0.125000f;

    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&elem->Pos.x, -1000000,  1000000,0.010000f);
    float_Pos_0->Default = 0.000000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&elem->Pos.y, -1000000,  1000000,0.010000f);
    float_Pos_1->Default = 0.000000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&elem->Pos.z, -1000000,  1000000,0.010000f);
    float_Pos_2->Default = 0.000000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

    if((para->Flags&0x0001))
    {
      gh.BeginTied();
      sFloatControl *float_Rot_0 = gh.Float(&elem->Rot.x,-4.00000f,4.000000f,0.001000f);
      float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
      sFloatControl *float_Rot_1 = gh.Float(&elem->Rot.y,-4.00000f,4.000000f,0.001000f);
      float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
      sFloatControl *float_Rot_2 = gh.Float(&elem->Rot.z,-4.00000f,4.000000f,0.001000f);
      float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
      gh.EndTied();

    }
    if((para->Flags&0x0002))
    {
      gh.Color(&elem->Color,L"rgba");
    }
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

void Wz4ParticlesDefStaticParticles(wOp *op)
{
  Wz4ParticlesParaStaticParticles sUNUSED *para = (Wz4ParticlesParaStaticParticles *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4ParticlesBindStaticParticles(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4ParticlesBind2StaticParticles(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
  }
}
void Wz4ParticlesBind3StaticParticles(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4ParticlesWikiStaticParticles =
L"= Wz4Particles : StaticParticles\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i StaticParticles\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Rotation\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Color\n"
L" !i *\n"
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
L" !i Rotation\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Color\n"
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

sBool Wz4RenderCmdSprites(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSprites sUNUSED *para = (Wz4RenderParaSprites *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Texture2D sUNUSED *in2 = cmd->GetInput<Texture2D *>(2); in2;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 534 "fxparticle_ops.ops"

    RNSprites *node = new RNSprites();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    node->TextureDiff = in1; in1->AddRef();
    node->TextureFade = in2; in2->AddRef();
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 3654 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSprites(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSprites sUNUSED *para = (Wz4RenderParaSprites *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Size");
  sFloatControl *float_Size = gh.Float(&para->Size,0.000000f,1024.000f,0.010000f);
  float_Size->Default = 0.125000f; float_Size->RightStep = 0.125000f;

  gh.Label(L"* Aspect");
  sFloatControl *float_Aspect = gh.Float(&para->Aspect,-16.0000f,16.00000f,0.010000f);
  float_Aspect->Default = 0.000000f; float_Aspect->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*0add|premul alpha|mul|mul2|smooth|alpha (please use pm-alpha):*4zoff|zread|zwrite|zon:*8-|sort",gh.LayoutMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*9atlas anim|atlas multi:*11fade in out|-:*12screen align|vector align:*13-|particle color:*14-|scale by transform",gh.LayoutMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*16dest alpha from shader|dest alpha unchanged|dest alpha = 0|dest alpha blend:*20Center|Button:*24-|Tree Lock :*28Alpha Test Off|Alpha Test On",gh.LayoutMsg);

  gh.Label(L"* Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Group(L"Randomization");

  gh.Label(L"* RotStart");
  sFloatControl *float_RotStart = gh.Float(&para->RotStart,-1024.00f,1024.000f,0.010000f);
  float_RotStart->Default = 0.000000f; float_RotStart->RightStep = 0.125000f;

  gh.Label(L"* RotSpeed");
  sFloatControl *float_RotSpeed = gh.Float(&para->RotSpeed,-1024.00f,1024.000f,0.010000f);
  float_RotSpeed->Default = 0.000000f; float_RotSpeed->RightStep = 0.125000f;

  gh.Label(L"* RotRand");
  sFloatControl *float_RotRand = gh.Float(&para->RotRand,-1024.00f,1024.000f,0.010000f);
  float_RotRand->Default = 0.000000f; float_RotRand->RightStep = 0.125000f;

  gh.Label(L"* RotSpread");
  sFloatControl *float_RotSpread = gh.Float(&para->RotSpread,0.000000f,1024.000f,0.010000f);
  float_RotSpread->Default = 0.000000f; float_RotSpread->RightStep = 0.125000f;

  gh.Label(L"SizeRand");
  sFloatControl *float_SizeRand = gh.Float(&para->SizeRand,0.000000f,1.000000f,0.010000f);
  float_SizeRand->Default = 0.000000f; float_SizeRand->RightStep = 0.125000f;

  gh.Group(L"Particle Fade");

  gh.Label(L"Fade type");
  gh.Flags(&para->FadeType,L"grow|fade",gh.ChangeMsg);

  gh.Label(L"Fade mode");
  gh.Flags(&para->GrowMode,L"const|linear|sine|smoothstep",gh.ChangeMsg);

  gh.Label(L"* FadeIn");
  sFloatControl *float_FadeIn = gh.Float(&para->FadeIn,0.000000f,1.000000f,0.010000f);
  float_FadeIn->Default = 0.000000f; float_FadeIn->RightStep = 0.125000f;

  gh.Label(L"* FadeOut");
  sFloatControl *float_FadeOut = gh.Float(&para->FadeOut,0.000000f,1.000000f,0.010000f);
  float_FadeOut->Default = 0.000000f; float_FadeOut->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  if(!(para->Mode&0x0200))
  {
    gh.Group(L"Texture Animation");

    gh.Label(L"* TexAnimSpeed");
    sFloatControl *float_TexAnimSpeed = gh.Float(&para->TexAnimSpeed,-1024.00f,1024.000f,0.010000f);
    float_TexAnimSpeed->Default = 1.000000f; float_TexAnimSpeed->RightStep = 0.125000f;

    gh.Label(L"* TexAnimRand");
    sFloatControl *float_TexAnimRand = gh.Float(&para->TexAnimRand,0.000000f,1.000000f,0.010000f);
    float_TexAnimRand->Default = 0.000000f; float_TexAnimRand->RightStep = 0.125000f;

  }
  gh.Group(L"Misc");

  gh.Label(L"GroupCount");
  sIntControl *int_GroupCount = gh.Int(&para->GroupCount,1,256,0.125000f);
  int_GroupCount->Default = 0x00000001; int_GroupCount->RightStep = 0.125000f;

  if(!(para->Mode&0x0800))
  {
    gh.Label(L"NearFadeDistance");
    sFloatControl *float_NearFadeDistance = gh.Float(&para->NearFadeDistance,0.000000f,  1048576,0.125000f);
    float_NearFadeDistance->Default = 1.000000f; float_NearFadeDistance->RightStep = 0.125000f;

    gh.Label(L"FarFadeDistance");
    sFloatControl *float_FarFadeDistance = gh.Float(&para->FarFadeDistance,0.000000f,  1048576,0.125000f);
    float_FarFadeDistance->Default = 1000.000f; float_FarFadeDistance->RightStep = 0.125000f;

    gh.Label(L"FarFadeRange");
    sFloatControl *float_FarFadeRange = gh.Float(&para->FarFadeRange,0.000000f,  1048576,0.125000f);
    float_FarFadeRange->Default = 100.0000f; float_FarFadeRange->RightStep = 0.125000f;

  }
  if((para->Mode&0x1000))
  {
    gh.Label(L"AlignDir");
    gh.BeginTied();
    sFloatControl *float_AlignDir_0 = gh.Float(&para->AlignDir.x,-1.00000f,1.000000f,0.001000f);
    float_AlignDir_0->Default = 0.000000f; float_AlignDir_0->RightStep = 0.125000f;
    sFloatControl *float_AlignDir_1 = gh.Float(&para->AlignDir.y,-1.00000f,1.000000f,0.001000f);
    float_AlignDir_1->Default = 0.000000f; float_AlignDir_1->RightStep = 0.125000f;
    sFloatControl *float_AlignDir_2 = gh.Float(&para->AlignDir.z,-1.00000f,1.000000f,0.001000f);
    float_AlignDir_2->Default = 0.000000f; float_AlignDir_2->RightStep = 0.125000f;
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

void Wz4RenderDefSprites(wOp *op)
{
  Wz4RenderParaSprites sUNUSED *para = (Wz4RenderParaSprites *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0.125000f;
  para->Mode = 0x00004000;
  para->Color = 0xffffffff;
  para->TexAnimSpeed = 1.000000f;
  para->GroupCount = 0x00000001;
  para->NearFadeDistance = 1.000000f;
  para->FarFadeDistance = 1000.000f;
  para->FarFadeRange = 100.0000f;
}

void Wz4RenderBindSprites(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"aspect"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"rotstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"rotspread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"sizerand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"fadein"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"fadeout"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"texanimspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"texanimrand"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"groupcount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"nearfadedistance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"farfadedistance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"farfaderange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"aligndir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"aligndir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"aligndir"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Sprites(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[30];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"trans");
    name[1] = sPoolString(L"size");
    name[2] = sPoolString(L"aspect");
    name[3] = sPoolString(L"mode");
    name[4] = sPoolString(L"mode");
    name[5] = sPoolString(L"mode");
    name[6] = sPoolString(L"color_");
    name[7] = sPoolString(L"randomization");
    name[8] = sPoolString(L"rotstart");
    name[9] = sPoolString(L"rotspeed");
    name[10] = sPoolString(L"rotrand");
    name[11] = sPoolString(L"rotspread");
    name[12] = sPoolString(L"sizerand");
    name[13] = sPoolString(L"");
    name[14] = sPoolString(L"fadetype");
    name[15] = sPoolString(L"growmode");
    name[16] = sPoolString(L"fadein");
    name[17] = sPoolString(L"fadeout");
    name[18] = sPoolString(L"renderpass");
    name[19] = sPoolString(L"");
    name[20] = sPoolString(L"texanimspeed");
    name[21] = sPoolString(L"texanimrand");
    name[22] = sPoolString(L"misc");
    name[23] = sPoolString(L"groupcount");
    name[24] = sPoolString(L"nearfadedistance");
    name[25] = sPoolString(L"farfadedistance");
    name[26] = sPoolString(L"farfaderange");
    name[27] = sPoolString(L"aligndir");
    name[28] = sPoolString(L"");
    name[29] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[18],ScriptTypeInt,1,cmd->Data+16);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[23],ScriptTypeInt,1,cmd->Data+19);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[26],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[27],ScriptTypeFloat,3,cmd->Data+23);
  ctx->AddImport(name[29],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Sprites(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import size : float;\n");
  tb.PrintF(L"  import aspect : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import rotstart : float;\n");
  tb.PrintF(L"  import rotspeed : float;\n");
  tb.PrintF(L"  import rotrand : float;\n");
  tb.PrintF(L"  import rotspread : float;\n");
  tb.PrintF(L"  import sizerand : float;\n");
  tb.PrintF(L"  import fadein : float;\n");
  tb.PrintF(L"  import fadeout : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import texanimspeed : float;\n");
  tb.PrintF(L"  import texanimrand : float;\n");
  tb.PrintF(L"  import groupcount : int;\n");
  tb.PrintF(L"  import nearfadedistance : float;\n");
  tb.PrintF(L"  import farfadedistance : float;\n");
  tb.PrintF(L"  import farfaderange : float;\n");
  tb.PrintF(L"  import aligndir : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSprites =
L"= Wz4Render : Sprites\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sprites\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
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
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Aspect\n"
L" !i Aspect\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i premul alpha\n"
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
L" !i smooth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha (please use pm-alpha)\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i zoff\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zread\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zwrite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i zon\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i sort\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i atlas anim\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i atlas multi\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i fade in out\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i screen align\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i vector align\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i particle color\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i scale by transform\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Center\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Button\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Tree Lock \n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Alpha Test Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Alpha Test On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i RotStart\n"
L" !i RotStart\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RotSpeed\n"
L" !i RotSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RotRand\n"
L" !i RotRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RotSpread\n"
L" !i RotSpread\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SizeRand\n"
L" !i SizeRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Fade type\n"
L" !i FadeType\n"
L" !i grow\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fade\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Fade mode\n"
L" !i GrowMode\n"
L" !i const\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sine\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i smoothstep\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i FadeIn\n"
L" !i FadeIn\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FadeOut\n"
L" !i FadeOut\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i TexAnimSpeed\n"
L" !i TexAnimSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexAnimRand\n"
L" !i TexAnimRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GroupCount\n"
L" !i GroupCount\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i NearFadeDistance\n"
L" !i NearFadeDistance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FarFadeDistance\n"
L" !i FarFadeDistance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FarFadeRange\n"
L" !i FarFadeRange\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AlignDir\n"
L" !i AlignDir\n"
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

sBool Wz4RenderCmdChunks(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaChunks sUNUSED *para = (Wz4RenderParaChunks *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 587 "fxparticle_ops.ops"

    RNChunks *node = new RNChunks();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    for(sInt i=1;i<cmd->InputCount;i++)
    {
      Wz4Mesh *in = cmd->GetInput<Wz4Mesh *>(i);
      if(in)
      {
        in->Charge();
        node->Meshes.AddTail(in);
        in->AddRef();
      }
    }
    if(!node->Init())
      cmd->SetError(L"only one bone object allowed");

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 4332 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiChunks(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaChunks sUNUSED *para = (Wz4RenderParaChunks *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Scale");
  sFloatControl *float_Scale = gh.Float(&para->Scale,0.000000f,1024.000f,0.010000f);
  float_Scale->Default = 1.000000f; float_Scale->RightStep = 0.125000f;

  gh.Label(L"Direction");
  gh.Flags(&para->Direction,L"random|forward|fly",gh.LayoutMsg);

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Label(L"* LookAhead");
  sFloatControl *float_LookAhead = gh.Float(&para->LookAhead,-1024.00f,1024.000f,0.001000f);
  float_LookAhead->Default = 0.050000f; float_LookAhead->RightStep = 0.125000f;

  gh.Label(L"* RotStart");
  gh.BeginTied();
  sFloatControl *float_RotStart_0 = gh.Float(&para->RotStart.x,0.000000f,1.000000f,0.010000f);
  float_RotStart_0->Default = 0.000000f; float_RotStart_0->RightStep = 0.125000f;
  sFloatControl *float_RotStart_1 = gh.Float(&para->RotStart.y,0.000000f,1.000000f,0.010000f);
  float_RotStart_1->Default = 0.000000f; float_RotStart_1->RightStep = 0.125000f;
  sFloatControl *float_RotStart_2 = gh.Float(&para->RotStart.z,0.000000f,1.000000f,0.010000f);
  float_RotStart_2->Default = 0.000000f; float_RotStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* RotSpeed");
  gh.BeginTied();
  sFloatControl *float_RotSpeed_0 = gh.Float(&para->RotSpeed.x,-1024.00f,1024.000f,0.010000f);
  float_RotSpeed_0->Default = 0.000000f; float_RotSpeed_0->RightStep = 0.125000f;
  sFloatControl *float_RotSpeed_1 = gh.Float(&para->RotSpeed.y,-1024.00f,1024.000f,0.010000f);
  float_RotSpeed_1->Default = 0.000000f; float_RotSpeed_1->RightStep = 0.125000f;
  sFloatControl *float_RotSpeed_2 = gh.Float(&para->RotSpeed.z,-1024.00f,1024.000f,0.010000f);
  float_RotSpeed_2->Default = 0.000000f; float_RotSpeed_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* RotRand");
  gh.BeginTied();
  sFloatControl *float_RotRand_0 = gh.Float(&para->RotRand.x,-1024.00f,1024.000f,0.010000f);
  float_RotRand_0->Default = 0.000000f; float_RotRand_0->RightStep = 0.125000f;
  sFloatControl *float_RotRand_1 = gh.Float(&para->RotRand.y,-1024.00f,1024.000f,0.010000f);
  float_RotRand_1->Default = 0.000000f; float_RotRand_1->RightStep = 0.125000f;
  sFloatControl *float_RotRand_2 = gh.Float(&para->RotRand.z,-1024.00f,1024.000f,0.010000f);
  float_RotRand_2->Default = 0.000000f; float_RotRand_2->RightStep = 0.125000f;
  gh.EndTied();

  if(((para->Direction&0x000f)==0x0001))
  {
    gh.Label(L"UpVector");
    gh.Flags(&para->UpVector,L"x|y|z",gh.ChangeMsg);

    gh.Label(L"* SpiralRand");
    sFloatControl *float_SpiralRand = gh.Float(&para->SpiralRand,0.000000f,1.000000f,0.010000f);
    float_SpiralRand->Default = 0.000000f; float_SpiralRand->RightStep = 0.125000f;

    gh.Label(L"* SpiralSpeed");
    sFloatControl *float_SpiralSpeed = gh.Float(&para->SpiralSpeed,-1024.00f,1024.000f,0.010000f);
    float_SpiralSpeed->Default = 0.000000f; float_SpiralSpeed->RightStep = 0.125000f;

    gh.Label(L"* SpiralRandSpeed");
    sFloatControl *float_SpiralRandSpeed = gh.Float(&para->SpiralRandSpeed,-1024.00f,1024.000f,0.010000f);
    float_SpiralRandSpeed->Default = 0.000000f; float_SpiralRandSpeed->RightStep = 0.125000f;

  }
  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Direction,L"*4-|animated (SLOW):*5-|Color:*6-|NoRandom",gh.LayoutMsg);

  if((para->Direction&0x0010))
  {
    gh.Label(L"* AnimRand");
    sFloatControl *float_AnimRand = gh.Float(&para->AnimRand,0.000000f,1.000000f,0.010000f);
    float_AnimRand->Default = 1.000000f; float_AnimRand->RightStep = 0.125000f;

    gh.Label(L"* AnimSpeed");
    sFloatControl *float_AnimSpeed = gh.Float(&para->AnimSpeed,-1000.00f,1000.000f,0.010000f);
    float_AnimSpeed->Default = 16.00000f; float_AnimSpeed->RightStep = 0.125000f;

    gh.Label(L"* AnimSpeedRand");
    sFloatControl *float_AnimSpeedRand = gh.Float(&para->AnimSpeedRand,-1000.00f,1000.000f,0.010000f);
    float_AnimSpeedRand->Default = 0.000000f; float_AnimSpeedRand->RightStep = 0.125000f;

    gh.Label(L"* AnimDifferent");
    sIntControl *int_AnimDifferent = gh.Int(&para->AnimDifferent,1,100000,0.125000f);
    int_AnimDifferent->Default = 0x0000000a; int_AnimDifferent->RightStep = 0.125000f;

  }
  gh.Label(L"* ScaleRand");
  sFloatControl *float_ScaleRand = gh.Float(&para->ScaleRand,0.000000f,1.000000f,0.001000f);
  float_ScaleRand->Default = 0.000000f; float_ScaleRand->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefChunks(wOp *op)
{
  Wz4RenderParaChunks sUNUSED *para = (Wz4RenderParaChunks *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale = 1.000000f;
  para->Seed = 0x00000001;
  para->LookAhead = 0.050000f;
  para->UpVector = 0x00000001;
  para->AnimRand = 1.000000f;
  para->AnimSpeed = 16.00000f;
  para->AnimDifferent = 0x0000000a;
}

void Wz4RenderBindChunks(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"lookahead"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"rotrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"spiralrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"spiralspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"spiralrandspeed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"animrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"animspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"animspeedrand"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"animdifferent"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"scalerand"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Chunks(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[22];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"trans");
    name[1] = sPoolString(L"scale");
    name[2] = sPoolString(L"direction");
    name[3] = sPoolString(L"seed");
    name[4] = sPoolString(L"lookahead");
    name[5] = sPoolString(L"rotstart");
    name[6] = sPoolString(L"rotspeed");
    name[7] = sPoolString(L"rotrand");
    name[8] = sPoolString(L"upvector");
    name[9] = sPoolString(L"spiralrand");
    name[10] = sPoolString(L"spiralspeed");
    name[11] = sPoolString(L"spiralrandspeed");
    name[12] = sPoolString(L"renderpass");
    name[13] = sPoolString(L"lightenv");
    name[14] = sPoolString(L"flags");
    name[15] = sPoolString(L"animrand");
    name[16] = sPoolString(L"animspeed");
    name[17] = sPoolString(L"animspeedrand");
    name[18] = sPoolString(L"animdifferent");
    name[19] = sPoolString(L"scalerand");
    name[20] = sPoolString(L"");
    name[21] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+13);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[12],ScriptTypeInt,1,cmd->Data+20);
  ctx->AddImport(name[13],ScriptTypeInt,1,cmd->Data+21);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[18],ScriptTypeInt,1,cmd->Data+25);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+26);
  ctx->AddImport(name[21],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Chunks(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import scale : float;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import lookahead : float;\n");
  tb.PrintF(L"  import rotstart : float[3];\n");
  tb.PrintF(L"  import rotspeed : float[3];\n");
  tb.PrintF(L"  import rotrand : float[3];\n");
  tb.PrintF(L"  import spiralrand : float;\n");
  tb.PrintF(L"  import spiralspeed : float;\n");
  tb.PrintF(L"  import spiralrandspeed : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import animrand : float;\n");
  tb.PrintF(L"  import animspeed : float;\n");
  tb.PrintF(L"  import animspeedrand : float;\n");
  tb.PrintF(L"  import animdifferent : int;\n");
  tb.PrintF(L"  import scalerand : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiChunks =
L"= Wz4Render : Chunks\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Chunks\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Wz4Mesh\n"
L" !i multiple\n"
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
L" !i Scale\n"
L" !i Scale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Direction\n"
L" !i Direction\n"
L" !i random\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i forward\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fly\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i LookAhead\n"
L" !i LookAhead\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RotStart\n"
L" !i RotStart\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i RotSpeed\n"
L" !i RotSpeed\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i RotRand\n"
L" !i RotRand\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i UpVector\n"
L" !i UpVector\n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i z\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SpiralRand\n"
L" !i SpiralRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpiralSpeed\n"
L" !i SpiralSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpiralRandSpeed\n"
L" !i SpiralRandSpeed\n"
L" !i float\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Direction\n"
L" !i animated (SLOW)\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Color\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i NoRandom\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i AnimRand\n"
L" !i AnimRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AnimSpeed\n"
L" !i AnimSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AnimSpeedRand\n"
L" !i AnimSpeedRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AnimDifferent\n"
L" !i AnimDifferent\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i ScaleRand\n"
L" !i ScaleRand\n"
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

sBool Wz4RenderCmdDebris(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaDebris sUNUSED *para = (Wz4RenderParaDebris *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 623 "fxparticle_ops.ops"

    RNDebris *node = new RNDebris();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    if(in1)
    {
      node->Mesh = in1;
      in1->AddRef();
    }
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 4839 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiDebris(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaDebris sUNUSED *para = (Wz4RenderParaDebris *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefDebris(wOp *op)
{
  Wz4RenderParaDebris sUNUSED *para = (Wz4RenderParaDebris *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4RenderBindDebris(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Debris(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Debris(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiDebris =
L"= Wz4Render : Debris\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Debris\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
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

sBool Wz4RenderCmdTrails(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaTrails sUNUSED *para = (Wz4RenderParaTrails *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 662 "fxparticle_ops.ops"

    RNTrails *node = new RNTrails();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    node->Mtrl = in1; in1->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 4991 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiTrails(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaTrails sUNUSED *para = (Wz4RenderParaTrails *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,3,255,0.125000f);
  int_Count->Default = 0x00000005; int_Count->RightStep = 0.125000f;

  gh.Label(L"* Delta");
  sFloatControl *float_Delta = gh.Float(&para->Delta,-1024.00f,1024.000f,0.001000f);
  float_Delta->Default = 0.050000f; float_Delta->RightStep = 0.125000f;

  gh.Label(L"* Width");
  sFloatControl *float_Width = gh.Float(&para->Width,0.000000f,1024.000f,0.001000f);
  float_Width->Default = 0.125000f; float_Width->RightStep = 0.125000f;

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Orientation");
  gh.Flags(&para->Orientation,L"camera|x|y|z|fly",gh.LayoutMsg);

  gh.Label(L"Faces");
  gh.Flags(&para->Orientation,L"*4flat|round|square",gh.ChangeMsg);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  if(((para->Orientation&0x000f)==0x0004))
  {
    gh.Label(L"* Tweak");
    gh.BeginTied();
    sFloatControl *float_Tweak_0 = gh.Float(&para->Tweak.x,-16.0000f,16.00000f,0.001000f);
    float_Tweak_0->Default = 0.000000f; float_Tweak_0->RightStep = 0.125000f;
    sFloatControl *float_Tweak_1 = gh.Float(&para->Tweak.y,-16.0000f,16.00000f,0.001000f);
    float_Tweak_1->Default = 0.000000f; float_Tweak_1->RightStep = 0.125000f;
    sFloatControl *float_Tweak_2 = gh.Float(&para->Tweak.z,-16.0000f,16.00000f,0.001000f);
    float_Tweak_2->Default = 0.000000f; float_Tweak_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"* TrailStep");
  sIntControl *int_TrailStep = gh.Int(&para->TrailStep,1,127,0.125000f);
  int_TrailStep->Default = 0x00000001; int_TrailStep->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefTrails(wOp *op)
{
  Wz4RenderParaTrails sUNUSED *para = (Wz4RenderParaTrails *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000005;
  para->Delta = 0.050000f;
  para->Width = 0.125000f;
  para->TrailStep = 0x00000001;
}

void Wz4RenderBindTrails(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"delta"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"tweak"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"trailstep"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Trails(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"count");
    name[1] = sPoolString(L"delta");
    name[2] = sPoolString(L"width");
    name[3] = sPoolString(L"lightenv");
    name[4] = sPoolString(L"orientation");
    name[5] = sPoolString(L"faces");
    name[6] = sPoolString(L"renderpass");
    name[7] = sPoolString(L"tweak");
    name[8] = sPoolString(L"trailstep");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[10],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Trails(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import delta : float;\n");
  tb.PrintF(L"  import width : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import tweak : float[3];\n");
  tb.PrintF(L"  import trailstep : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiTrails =
L"= Wz4Render : Trails\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Trails\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Delta\n"
L" !i Delta\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Width\n"
L" !i Width\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LightEnv\n"
L" !i LightEnv\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Orientation\n"
L" !i Orientation\n"
L" !i camera\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i z\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fly\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Faces\n"
L" !i Orientation\n"
L" !i flat\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i round\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i square\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Tweak\n"
L" !i Tweak\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TrailStep\n"
L" !i TrailStep\n"
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

sBool Wz4RenderCmdMetaballs(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaMetaballs sUNUSED *para = (Wz4RenderParaMetaballs *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 691 "fxparticle_ops.ops"

    RNMetaballs *node = new RNMetaballs();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 5279 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiMetaballs(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaMetaballs sUNUSED *para = (Wz4RenderParaMetaballs *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Peels");
  sIntControl *int_Peels = gh.Int(&para->Peels,0,8,0.125000f);
  int_Peels->Default = 0x00000004; int_Peels->RightStep = 0.125000f;

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Size");
  sFloatControl *float_Size = gh.Float(&para->Size,0.000000f,1024.000f,0.010000f);
  float_Size->Default = 0.125000f; float_Size->RightStep = 0.125000f;

  gh.Label(L"Debug");
  gh.Flags(&para->Debug,L"off|show peel",gh.ChangeMsg);

  gh.Label(L"Binning");
  gh.Flags(&para->Flags,L"tiny|small|large",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefMetaballs(wOp *op)
{
  Wz4RenderParaMetaballs sUNUSED *para = (Wz4RenderParaMetaballs *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Peels = 0x00000004;
  para->Size = 0.125000f;
}

void Wz4RenderBindMetaballs(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"peels"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Metaballs(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"peels");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"size");
    name[4] = sPoolString(L"debug");
    name[5] = sPoolString(L"binning");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Metaballs(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import peels : int;\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import size : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiMetaballs =
L"= Wz4Render : Metaballs\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Metaballs\n"
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
L" !i Wz4Particles\n"
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
L" !i Peels\n"
L" !i Peels\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Debug\n"
L" !i Debug\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i show peel\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Binning\n"
L" !i Flags\n"
L" !i tiny\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i small\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i large\n"
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

sBool Wz4RenderCmdMarchingCubes(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaMarchingCubes sUNUSED *para = (Wz4RenderParaMarchingCubes *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 723 "fxparticle_ops.ops"

    RNMarchingCubes *node = new RNMarchingCubes();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    node->Mtrl = in1; in1->AddRef();
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 5503 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiMarchingCubes(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaMarchingCubes sUNUSED *para = (Wz4RenderParaMarchingCubes *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"GridSize");
  sFloatControl *float_GridSize = gh.Float(&para->GridSize,0.001000f,16.00000f,0.001000f);
  float_GridSize->Default = 1.000000f; float_GridSize->RightStep = 0.125000f;

  gh.Label(L"Influence");
  sFloatControl *float_Influence = gh.Float(&para->Influence,0.000000f,16.00000f,0.010000f);
  float_Influence->Default = 0.500000f; float_Influence->RightStep = 0.125000f;

  gh.Label(L"IsoValue");
  sFloatControl *float_IsoValue = gh.Float(&para->IsoValue,0.000000f,1000.000f,0.010000f);
  float_IsoValue->Default = 10.00000f; float_IsoValue->RightStep = 0.125000f;

  gh.Label(L"BaseGrid");
  gh.Flags(&para->BaseGrid,L" 1| 2| 4| 8| 16| 32",gh.ChangeMsg);

  gh.Label(L"Subdivide");
  gh.Flags(&para->Subdivide,L" 0| 1",gh.ChangeMsg);

  gh.Group(L"render");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"off|limited on|pipelined on",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefMarchingCubes(wOp *op)
{
  Wz4RenderParaMarchingCubes sUNUSED *para = (Wz4RenderParaMarchingCubes *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->GridSize = 1.000000f;
  para->Influence = 0.500000f;
  para->IsoValue = 10.00000f;
  para->BaseGrid = 0x00000003;
}

void Wz4RenderBindMarchingCubes(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"gridsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"influence"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"isovalue"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2MarchingCubes(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"gridsize");
    name[1] = sPoolString(L"influence");
    name[2] = sPoolString(L"isovalue");
    name[3] = sPoolString(L"basegrid");
    name[4] = sPoolString(L"subdivide");
    name[5] = sPoolString(L"render");
    name[6] = sPoolString(L"lightenv");
    name[7] = sPoolString(L"renderpass");
    name[8] = sPoolString(L"multithreading");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[10],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3MarchingCubes(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import gridsize : float;\n");
  tb.PrintF(L"  import influence : float;\n");
  tb.PrintF(L"  import isovalue : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiMarchingCubes =
L"= Wz4Render : MarchingCubes\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MarchingCubes\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
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
L" !i GridSize\n"
L" !i GridSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Influence\n"
L" !i Influence\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i IsoValue\n"
L" !i IsoValue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i BaseGrid\n"
L" !i BaseGrid\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Subdivide\n"
L" !i Subdivide\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
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
L" !i Multithreading\n"
L" !i Multithreading\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i limited on\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pipelined on\n"
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

sBool Wz4RenderCmdMarchingCubesColor(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaMarchingCubesColor sUNUSED *para = (Wz4RenderParaMarchingCubesColor *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 756 "fxparticle_ops.ops"

    RNMarchingCubesColor *node = new RNMarchingCubesColor();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    node->Mtrl = in1; in1->AddRef();
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 5769 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiMarchingCubesColor(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaMarchingCubesColor sUNUSED *para = (Wz4RenderParaMarchingCubesColor *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"GridSize");
  sFloatControl *float_GridSize = gh.Float(&para->GridSize,0.001000f,16.00000f,0.001000f);
  float_GridSize->Default = 1.000000f; float_GridSize->RightStep = 0.125000f;

  gh.Label(L"Influence");
  sFloatControl *float_Influence = gh.Float(&para->Influence,0.000000f,16.00000f,0.010000f);
  float_Influence->Default = 0.500000f; float_Influence->RightStep = 0.125000f;

  gh.Label(L"IsoValue");
  sFloatControl *float_IsoValue = gh.Float(&para->IsoValue,0.000000f,1000.000f,0.010000f);
  float_IsoValue->Default = 10.00000f; float_IsoValue->RightStep = 0.125000f;

  gh.Label(L"BaseGrid");
  gh.Flags(&para->BaseGrid,L" 1| 2| 4| 8| 16| 32",gh.ChangeMsg);

  gh.Label(L"Subdivide");
  gh.Flags(&para->Subdivide,L" 0| 1",gh.ChangeMsg);

  gh.Group(L"render");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"off|limited on|pipelined on",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefMarchingCubesColor(wOp *op)
{
  Wz4RenderParaMarchingCubesColor sUNUSED *para = (Wz4RenderParaMarchingCubesColor *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->GridSize = 1.000000f;
  para->Influence = 0.500000f;
  para->IsoValue = 10.00000f;
  para->BaseGrid = 0x00000003;
}

void Wz4RenderBindMarchingCubesColor(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"gridsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"influence"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"isovalue"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2MarchingCubesColor(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"gridsize");
    name[1] = sPoolString(L"influence");
    name[2] = sPoolString(L"isovalue");
    name[3] = sPoolString(L"basegrid");
    name[4] = sPoolString(L"subdivide");
    name[5] = sPoolString(L"render");
    name[6] = sPoolString(L"lightenv");
    name[7] = sPoolString(L"renderpass");
    name[8] = sPoolString(L"multithreading");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[10],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3MarchingCubesColor(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import gridsize : float;\n");
  tb.PrintF(L"  import influence : float;\n");
  tb.PrintF(L"  import isovalue : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiMarchingCubesColor =
L"= Wz4Render : MarchingCubesColor\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MarchingCubesColor\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
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
L" !i GridSize\n"
L" !i GridSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Influence\n"
L" !i Influence\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i IsoValue\n"
L" !i IsoValue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i BaseGrid\n"
L" !i BaseGrid\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Subdivide\n"
L" !i Subdivide\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
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
L" !i Multithreading\n"
L" !i Multithreading\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i limited on\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i pipelined on\n"
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

sBool Wz4ParticlesCmdBulge(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaBulge sUNUSED *para = (Wz4ParticlesParaBulge *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 787 "fxparticle_ops.ops"

    RPBulge *node= new RPBulge();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 6032 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiBulge(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaBulge sUNUSED *para = (Wz4ParticlesParaBulge *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Function");
  gh.Flags(&para->Function,L" 3D Bulge|S-Bulge",gh.LayoutMsg);

  gh.Label(L"* Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-65536.0f,65536.00f,0.010000f);
  float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-65536.0f,65536.00f,0.010000f);
  float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
  sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-65536.0f,65536.00f,0.010000f);
  float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Size");
  gh.BeginTied();
  sFloatControl *float_Size_0 = gh.Float(&para->Size.x,-65536.0f,65536.00f,0.010000f);
  float_Size_0->Default = 1.000000f; float_Size_0->RightStep = 0.125000f;
  sFloatControl *float_Size_1 = gh.Float(&para->Size.y,-65536.0f,65536.00f,0.010000f);
  float_Size_1->Default = 1.000000f; float_Size_1->RightStep = 0.125000f;
  sFloatControl *float_Size_2 = gh.Float(&para->Size.z,-65536.0f,65536.00f,0.010000f);
  float_Size_2->Default = 1.000000f; float_Size_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Stretch");
  gh.BeginTied();
  sFloatControl *float_Stretch_0 = gh.Float(&para->Stretch.x,-65536.0f,65536.00f,0.010000f);
  float_Stretch_0->Default = 1.000000f; float_Stretch_0->RightStep = 0.125000f;
  sFloatControl *float_Stretch_1 = gh.Float(&para->Stretch.y,-65536.0f,65536.00f,0.010000f);
  float_Stretch_1->Default = 1.000000f; float_Stretch_1->RightStep = 0.125000f;
  sFloatControl *float_Stretch_2 = gh.Float(&para->Stretch.z,-65536.0f,65536.00f,0.010000f);
  float_Stretch_2->Default = 1.000000f; float_Stretch_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* FadeGamma");
  sFloatControl *float_FadeGamma = gh.Float(&para->FadeGamma,0.000000f,256.0000f,0.001000f);
  float_FadeGamma->Default = 0.000000f; float_FadeGamma->RightStep = 0.125000f;

  gh.Label(L"* Warp");
  sFloatControl *float_Warp = gh.Float(&para->Warp,-1.00000f,16.00000f,0.001000f);
  float_Warp->Default = 1.000000f; float_Warp->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefBulge(wOp *op)
{
  Wz4ParticlesParaBulge sUNUSED *para = (Wz4ParticlesParaBulge *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size.x = 1.000000f;
  para->Size.y = 1.000000f;
  para->Size.z = 1.000000f;
  para->Stretch.x = 1.000000f;
  para->Stretch.y = 1.000000f;
  para->Stretch.z = 1.000000f;
  para->Warp = 1.000000f;
}

void Wz4ParticlesBindBulge(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"stretch"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"stretch"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"stretch"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"fadegamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"warp"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2Bulge(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"function");
    name[1] = sPoolString(L"center");
    name[2] = sPoolString(L"size");
    name[3] = sPoolString(L"stretch");
    name[4] = sPoolString(L"fadegamma");
    name[5] = sPoolString(L"warp");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[7],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3Bulge(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import size : float[3];\n");
  tb.PrintF(L"  import stretch : float[3];\n");
  tb.PrintF(L"  import fadegamma : float;\n");
  tb.PrintF(L"  import warp : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiBulge =
L"= Wz4Particles : Bulge\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bulge\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i Function\n"
L" !i Function\n"
L" !i 3D Bulge\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i S-Bulge\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Stretch\n"
L" !i Stretch\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i FadeGamma\n"
L" !i FadeGamma\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Warp\n"
L" !i Warp\n"
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

sBool Wz4ParticlesCmdSparcle(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaSparcle sUNUSED *para = (Wz4ParticlesParaSparcle *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 814 "fxparticle_ops.ops"

    RPSparcle *node = new RPSparcle();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 6280 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiSparcle(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaSparcle sUNUSED *para = (Wz4ParticlesParaSparcle *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"SamplePoints");
  sIntControl *int_SamplePoints = gh.Int(&para->SamplePoints,1,4096,0.125000f);
  int_SamplePoints->Default = 0x00000064; int_SamplePoints->RightStep = 0.125000f;

  gh.Label(L"Percentage");
  sFloatControl *float_Percentage = gh.Float(&para->Percentage,0.000000f,1.000000f,0.001000f);
  float_Percentage->Default = 0.010000f; float_Percentage->RightStep = 0.125000f;

  gh.Label(L"Lifetime");
  sFloatControl *float_Lifetime = gh.Float(&para->Lifetime,0.000000f,1.000000f,0.001000f);
  float_Lifetime->Default = 0.040000f; float_Lifetime->RightStep = 0.125000f;

  gh.Label(L"RandomSpeed");
  sFloatControl *float_RandomSpeed = gh.Float(&para->RandomSpeed,-1024.00f,1024.000f,0.001000f);
  float_RandomSpeed->Default = 0.500000f; float_RandomSpeed->RightStep = 0.125000f;

  gh.Label(L"DirectionSpeed");
  sFloatControl *float_DirectionSpeed = gh.Float(&para->DirectionSpeed,-1024.00f,1024.000f,0.001000f);
  float_DirectionSpeed->Default = 0.000000f; float_DirectionSpeed->RightStep = 0.125000f;

  gh.Label(L"Gravity");
  sFloatControl *float_Gravity = gh.Float(&para->Gravity,-1024.00f,1024.000f,0.001000f);
  float_Gravity->Default = 0.000000f; float_Gravity->RightStep = 0.125000f;

  gh.Label(L"RandomSeed");
  sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
  int_RandomSeed->Default = 0x00000000; int_RandomSeed->RightStep = 0.125000f;
}

void Wz4ParticlesDefSparcle(wOp *op)
{
  Wz4ParticlesParaSparcle sUNUSED *para = (Wz4ParticlesParaSparcle *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->SamplePoints = 0x00000064;
  para->Percentage = 0.010000f;
  para->Lifetime = 0.040000f;
  para->RandomSpeed = 0.500000f;
}

void Wz4ParticlesBindSparcle(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"samplepoints"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"percentage"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"lifetime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"randomspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"directionspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"randomseed"),val);
}
void Wz4ParticlesBind2Sparcle(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"samplepoints");
    name[1] = sPoolString(L"percentage");
    name[2] = sPoolString(L"lifetime");
    name[3] = sPoolString(L"randomspeed");
    name[4] = sPoolString(L"directionspeed");
    name[5] = sPoolString(L"gravity");
    name[6] = sPoolString(L"randomseed");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+6);
}
void Wz4ParticlesBind3Sparcle(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import samplepoints : int;\n");
  tb.PrintF(L"  import percentage : float;\n");
  tb.PrintF(L"  import lifetime : float;\n");
  tb.PrintF(L"  import randomspeed : float;\n");
  tb.PrintF(L"  import directionspeed : float;\n");
  tb.PrintF(L"  import gravity : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
}
const sChar *Wz4ParticlesWikiSparcle =
L"= Wz4Particles : Sparcle\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sparcle\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i SamplePoints\n"
L" !i SamplePoints\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Percentage\n"
L" !i Percentage\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Lifetime\n"
L" !i Lifetime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomSpeed\n"
L" !i RandomSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DirectionSpeed\n"
L" !i DirectionSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomSeed\n"
L" !i RandomSeed\n"
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

sBool Wz4ParticlesCmdFromMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaFromMesh sUNUSED *para = (Wz4ParticlesParaFromMesh *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 840 "fxparticle_ops.ops"

    RPFromMesh *node = new RPFromMesh();
    node->ParaBase = node->Para = *para;
    node->Init(in0);
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 6483 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiFromMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaFromMesh sUNUSED *para = (Wz4ParticlesParaFromMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Raster");
  sFloatControl *float_Raster = gh.Float(&para->Raster,0.000000f,1024.000f,0.010000f);
  float_Raster->Default = 0.125000f; float_Raster->RightStep = 0.125000f;

  gh.Label(L"Offset");
  gh.BeginTied();
  sFloatControl *float_Offset_0 = gh.Float(&para->Offset.x,-1024.00f,1024.000f,0.001000f);
  float_Offset_0->Default = 0.000000f; float_Offset_0->RightStep = 0.125000f;
  sFloatControl *float_Offset_1 = gh.Float(&para->Offset.y,-1024.00f,1024.000f,0.001000f);
  float_Offset_1->Default = 0.000000f; float_Offset_1->RightStep = 0.125000f;
  sFloatControl *float_Offset_2 = gh.Float(&para->Offset.z,-1024.00f,1024.000f,0.001000f);
  float_Offset_2->Default = 0.000000f; float_Offset_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Hollow",gh.ChangeMsg);

  gh.Label(L"Random");
  sFloatControl *float_Random = gh.Float(&para->Random,0.000000f,1.000000f,0.010000f);
  float_Random->Default = 1.000000f; float_Random->RightStep = 0.125000f;

  gh.Label(L"RandomSeed");
  sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
  int_RandomSeed->Default = 0x00000000; int_RandomSeed->RightStep = 0.125000f;
}

void Wz4ParticlesDefFromMesh(wOp *op)
{
  Wz4ParticlesParaFromMesh sUNUSED *para = (Wz4ParticlesParaFromMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Raster = 0.125000f;
  para->Random = 1.000000f;
}

void Wz4ParticlesBindFromMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"raster"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"randomseed"),val);
}
void Wz4ParticlesBind2FromMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"raster");
    name[1] = sPoolString(L"offset");
    name[2] = sPoolString(L"flags");
    name[3] = sPoolString(L"random");
    name[4] = sPoolString(L"randomseed");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+6);
}
void Wz4ParticlesBind3FromMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import raster : float;\n");
  tb.PrintF(L"  import offset : float[3];\n");
  tb.PrintF(L"  import random : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
}
const sChar *Wz4ParticlesWikiFromMesh =
L"= Wz4Particles : FromMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FromMesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Raster\n"
L" !i Raster\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Offset\n"
L" !i Offset\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Hollow\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Random\n"
L" !i Random\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomSeed\n"
L" !i RandomSeed\n"
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

sBool Wz4ParticlesCmdMorph(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaMorph sUNUSED *para = (Wz4ParticlesParaMorph *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 868 "fxparticle_ops.ops"

    sInt nMesh = cmd->InputCount;
    sArray<Wz4Mesh*> meshArray;
    meshArray.AddMany(nMesh);
    for(sInt i=0; i<nMesh; i++)
    {
      meshArray[i] = cmd->GetInput<Wz4Mesh *>(i);
    }

    RPMorph *node = new RPMorph();
    node->ParaBase = node->Para = *para;
    node->Init(meshArray);
    out->RootNode = node;
    out->AddCode(cmd);
  ;
#line 6670 "fxparticle_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiMorph(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaMorph sUNUSED *para = (Wz4ParticlesParaMorph *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Transition");
  sFloatControl *float_Transition = gh.Float(&para->Transition,0.000000f,1.000000f,0.010000f);
  float_Transition->Default = 0.000000f; float_Transition->RightStep = 0.125000f;

  gh.Label(L"* DirFactor");
  gh.BeginTied();
  sFloatControl *float_DirFactor_0 = gh.Float(&para->DirFactor.x,-1024.00f,1024.000f,0.010000f);
  float_DirFactor_0->Default = 0.000000f; float_DirFactor_0->RightStep = 0.125000f;
  sFloatControl *float_DirFactor_1 = gh.Float(&para->DirFactor.y,-1024.00f,1024.000f,0.010000f);
  float_DirFactor_1->Default = 0.000000f; float_DirFactor_1->RightStep = 0.125000f;
  sFloatControl *float_DirFactor_2 = gh.Float(&para->DirFactor.z,-1024.00f,1024.000f,0.010000f);
  float_DirFactor_2->Default = 0.000000f; float_DirFactor_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NewVertexPos");
  gh.Flags(&para->NewVertexPos,L"random|firstindex|manual",gh.LayoutMsg);

  if((para->NewVertexPos&0x0002))
  {
    gh.Label(L"* BigBangOrigin");
    gh.BeginTied();
    sFloatControl *float_BigBangOrigin_0 = gh.Float(&para->BigBangOrigin.x,-1024.00f,1024.000f,0.001000f);
    float_BigBangOrigin_0->Default = 0.000000f; float_BigBangOrigin_0->RightStep = 0.125000f;
    sFloatControl *float_BigBangOrigin_1 = gh.Float(&para->BigBangOrigin.y,-1024.00f,1024.000f,0.001000f);
    float_BigBangOrigin_1->Default = 0.000000f; float_BigBangOrigin_1->RightStep = 0.125000f;
    sFloatControl *float_BigBangOrigin_2 = gh.Float(&para->BigBangOrigin.z,-1024.00f,1024.000f,0.001000f);
    float_BigBangOrigin_2->Default = 0.000000f; float_BigBangOrigin_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* BigBangDirFactor");
    gh.BeginTied();
    sFloatControl *float_BigBangDirFactor_0 = gh.Float(&para->BigBangDirFactor.x,-1024.00f,1024.000f,0.010000f);
    float_BigBangDirFactor_0->Default = 0.000000f; float_BigBangDirFactor_0->RightStep = 0.125000f;
    sFloatControl *float_BigBangDirFactor_1 = gh.Float(&para->BigBangDirFactor.y,-1024.00f,1024.000f,0.010000f);
    float_BigBangDirFactor_1->Default = 0.000000f; float_BigBangDirFactor_1->RightStep = 0.125000f;
    sFloatControl *float_BigBangDirFactor_2 = gh.Float(&para->BigBangDirFactor.z,-1024.00f,1024.000f,0.010000f);
    float_BigBangDirFactor_2->Default = 0.000000f; float_BigBangDirFactor_2->RightStep = 0.125000f;
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

void Wz4ParticlesDefMorph(wOp *op)
{
  Wz4ParticlesParaMorph sUNUSED *para = (Wz4ParticlesParaMorph *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4ParticlesBindMorph(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"transition"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"dirfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"dirfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"dirfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"bigbangorigin"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"bigbangorigin"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"bigbangorigin"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"bigbangdirfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"bigbangdirfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"bigbangdirfactor"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2Morph(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"transition");
    name[1] = sPoolString(L"dirfactor");
    name[2] = sPoolString(L"newvertexpos");
    name[3] = sPoolString(L"bigbangorigin");
    name[4] = sPoolString(L"bigbangdirfactor");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3Morph(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import transition : float;\n");
  tb.PrintF(L"  import dirfactor : float[3];\n");
  tb.PrintF(L"  import bigbangorigin : float[3];\n");
  tb.PrintF(L"  import bigbangdirfactor : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiMorph =
L"= Wz4Particles : Morph\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Morph\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Transition\n"
L" !i Transition\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DirFactor\n"
L" !i DirFactor\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i NewVertexPos\n"
L" !i NewVertexPos\n"
L" !i random\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i firstindex\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i manual\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i BigBangOrigin\n"
L" !i BigBangOrigin\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i BigBangDirFactor\n"
L" !i BigBangDirFactor\n"
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

void Wz4ParticlesAnimCloud::Init(class ScriptContext *sc)
{
  _CloudSize = sc->AddSymbol(L"cloudsize");
  _CloudFreq = sc->AddSymbol(L"cloudfreq");
  _CloudPos = sc->AddSymbol(L"cloudpos");
};

void Wz4ParticlesAnimCloud::Bind(class ScriptContext *sc,Wz4ParticlesParaCloud *para)
{
  sc->BindLocalFloat(_CloudSize,2,para->CloudSize);
  sc->BindLocalFloat(_CloudFreq,2,para->CloudFreq);
  sc->BindLocalFloat(_CloudPos,3,&para->CloudPos.x);
};

void Wz4ParticlesAnimBallistic::Init(class ScriptContext *sc)
{
  _Gravity = sc->AddSymbol(L"gravity");
  _PosStart = sc->AddSymbol(L"posstart");
  _PosRand = sc->AddSymbol(L"posrand");
  _SpeedStart = sc->AddSymbol(L"speedstart");
  _SpeedRand = sc->AddSymbol(L"speedrand");
  _BurstPercent = sc->AddSymbol(L"burstpercent");
  _LifeTime = sc->AddSymbol(L"lifetime");
  _Delay = sc->AddSymbol(L"delay");
};

void Wz4ParticlesAnimBallistic::Bind(class ScriptContext *sc,Wz4ParticlesParaBallistic *para)
{
  sc->BindLocalFloat(_Gravity,3,&para->Gravity.x);
  sc->BindLocalFloat(_PosStart,3,&para->PosStart.x);
  sc->BindLocalFloat(_PosRand,3,&para->PosRand.x);
  sc->BindLocalFloat(_SpeedStart,3,&para->SpeedStart.x);
  sc->BindLocalFloat(_SpeedRand,3,&para->SpeedRand.x);
  sc->BindLocalFloat(_BurstPercent,1,&para->BurstPercent);
  sc->BindLocalFloat(_LifeTime,1,&para->LifeTime);
  sc->BindLocalFloat(_Delay,1,&para->Delay);
};

void Wz4ParticlesAnimMesh::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimMesh::Bind(class ScriptContext *sc,Wz4ParticlesParaMesh *para)
{
};

void Wz4ExplosionAnimExplosion::Init(class ScriptContext *sc)
{
};

void Wz4ExplosionAnimExplosion::Bind(class ScriptContext *sc,Wz4ExplosionParaExplosion *para)
{
};

void Wz4ParticlesAnimExploder::Init(class ScriptContext *sc)
{
  _Gravity = sc->AddSymbol(L"gravity");
};

void Wz4ParticlesAnimExploder::Bind(class ScriptContext *sc,Wz4ParticlesParaExploder *para)
{
  sc->BindLocalFloat(_Gravity,3,&para->Gravity.x);
};

void Wz4ParticlesAnimCloud2::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimCloud2::Bind(class ScriptContext *sc,Wz4ParticlesParaCloud2 *para)
{
};

void Wz4ParticlesAnimFromVertex::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimFromVertex::Bind(class ScriptContext *sc,Wz4ParticlesParaFromVertex *para)
{
};

void Wz4ParticlesAnimWobble::Init(class ScriptContext *sc)
{
  _Freq = sc->AddSymbol(L"freq");
  _Amp = sc->AddSymbol(L"amp");
  _Phase = sc->AddSymbol(L"phase");
  _Spread = sc->AddSymbol(L"spread");
  _TimeFactor = sc->AddSymbol(L"timefactor");
  _DeltaFactor = sc->AddSymbol(L"deltafactor");
};

void Wz4ParticlesAnimWobble::Bind(class ScriptContext *sc,Wz4ParticlesParaWobble *para)
{
  sc->BindLocalFloat(_Freq,3,&para->Freq.x);
  sc->BindLocalFloat(_Amp,3,&para->Amp.x);
  sc->BindLocalFloat(_Phase,3,&para->Phase.x);
  sc->BindLocalFloat(_Spread,1,&para->Spread);
  sc->BindLocalFloat(_TimeFactor,1,&para->TimeFactor);
  sc->BindLocalFloat(_DeltaFactor,1,&para->DeltaFactor);
};

void Wz4ParticlesAnimAdd::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimAdd::Bind(class ScriptContext *sc,Wz4ParticlesParaAdd *para)
{
};

void Wz4ParticlesAnimLissajous::Init(class ScriptContext *sc)
{
  _Lifetime = sc->AddSymbol(L"lifetime");
  _Spread = sc->AddSymbol(L"spread");
  _Tweak = sc->AddSymbol(L"tweak");
  _LinearTwirl = sc->AddSymbol(L"lineartwirl");
  _LinearStretch = sc->AddSymbol(L"linearstretch");
  _MasterPhase = sc->AddSymbol(L"masterphase");
  _TubeRandom = sc->AddSymbol(L"tuberandom");
  _MasterScale = sc->AddSymbol(L"masterscale");
  _SpeedSpread = sc->AddSymbol(L"speedspread");
  _LinearTwist = sc->AddSymbol(L"lineartwist");
  _Randomness = sc->AddSymbol(L"randomness");
  _Translate = sc->AddSymbol(L"translate");
};

void Wz4ParticlesAnimLissajous::Bind(class ScriptContext *sc,Wz4ParticlesParaLissajous *para)
{
  sc->BindLocalFloat(_Lifetime,1,&para->Lifetime);
  sc->BindLocalFloat(_Spread,1,&para->Spread);
  sc->BindLocalFloat(_Tweak,3,&para->Tweak.x);
  sc->BindLocalFloat(_LinearTwirl,1,&para->LinearTwirl);
  sc->BindLocalFloat(_LinearStretch,3,&para->LinearStretch.x);
  sc->BindLocalFloat(_MasterPhase,1,&para->MasterPhase);
  sc->BindLocalFloat(_TubeRandom,1,&para->TubeRandom);
  sc->BindLocalFloat(_MasterScale,1,&para->MasterScale);
  sc->BindLocalFloat(_SpeedSpread,1,&para->SpeedSpread);
  sc->BindLocalFloat(_LinearTwist,1,&para->LinearTwist);
  sc->BindLocalFloat(_Randomness,1,&para->Randomness);
  sc->BindLocalFloat(_Translate,3,&para->Translate.x);
};

void Wz4ParticlesAnimSplinedParticles::Init(class ScriptContext *sc)
{
  _Lifetime = sc->AddSymbol(L"lifetime");
  _Spread = sc->AddSymbol(L"spread");
  _Tweak = sc->AddSymbol(L"tweak");
  _LinearTwirl = sc->AddSymbol(L"lineartwirl");
  _Epsilon = sc->AddSymbol(L"epsilon");
  _AltShift = sc->AddSymbol(L"altshift");
  _TubeRandom = sc->AddSymbol(L"tuberandom");
  _Randomness = sc->AddSymbol(L"randomness");
  _MasterPhase = sc->AddSymbol(L"masterphase");
};

void Wz4ParticlesAnimSplinedParticles::Bind(class ScriptContext *sc,Wz4ParticlesParaSplinedParticles *para)
{
  sc->BindLocalFloat(_Lifetime,1,&para->Lifetime);
  sc->BindLocalFloat(_Spread,1,&para->Spread);
  sc->BindLocalFloat(_Tweak,3,&para->Tweak.x);
  sc->BindLocalFloat(_LinearTwirl,1,&para->LinearTwirl);
  sc->BindLocalFloat(_Epsilon,1,&para->Epsilon);
  sc->BindLocalFloat(_AltShift,1,&para->AltShift);
  sc->BindLocalFloat(_TubeRandom,1,&para->TubeRandom);
  sc->BindLocalFloat(_Randomness,1,&para->Randomness);
  sc->BindLocalFloat(_MasterPhase,1,&para->MasterPhase);
};

void Wz4ParticlesAnimTrails::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimTrails::Bind(class ScriptContext *sc,Wz4ParticlesParaTrails *para)
{
};

void Wz4ParticlesAnimStaticParticles::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimStaticParticles::Bind(class ScriptContext *sc,Wz4ParticlesParaStaticParticles *para)
{
};

void Wz4RenderAnimSprites::Init(class ScriptContext *sc)
{
  _Trans = sc->AddSymbol(L"trans");
  _Size = sc->AddSymbol(L"size");
  _Aspect = sc->AddSymbol(L"aspect");
  _Color = sc->AddSymbol(L"color_");
  _RotStart = sc->AddSymbol(L"rotstart");
  _RotSpeed = sc->AddSymbol(L"rotspeed");
  _RotRand = sc->AddSymbol(L"rotrand");
  _RotSpread = sc->AddSymbol(L"rotspread");
  _FadeIn = sc->AddSymbol(L"fadein");
  _FadeOut = sc->AddSymbol(L"fadeout");
  _TexAnimSpeed = sc->AddSymbol(L"texanimspeed");
  _TexAnimRand = sc->AddSymbol(L"texanimrand");
};

void Wz4RenderAnimSprites::Bind(class ScriptContext *sc,Wz4RenderParaSprites *para)
{
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Size,1,&para->Size);
  sc->BindLocalFloat(_Aspect,1,&para->Aspect);
  sc->BindLocalColor(_Color,&para->Color);
  sc->BindLocalFloat(_RotStart,1,&para->RotStart);
  sc->BindLocalFloat(_RotSpeed,1,&para->RotSpeed);
  sc->BindLocalFloat(_RotRand,1,&para->RotRand);
  sc->BindLocalFloat(_RotSpread,1,&para->RotSpread);
  sc->BindLocalFloat(_FadeIn,1,&para->FadeIn);
  sc->BindLocalFloat(_FadeOut,1,&para->FadeOut);
  sc->BindLocalFloat(_TexAnimSpeed,1,&para->TexAnimSpeed);
  sc->BindLocalFloat(_TexAnimRand,1,&para->TexAnimRand);
};

void Wz4RenderAnimChunks::Init(class ScriptContext *sc)
{
  _Trans = sc->AddSymbol(L"trans");
  _Scale = sc->AddSymbol(L"scale");
  _LookAhead = sc->AddSymbol(L"lookahead");
  _RotStart = sc->AddSymbol(L"rotstart");
  _RotSpeed = sc->AddSymbol(L"rotspeed");
  _RotRand = sc->AddSymbol(L"rotrand");
  _SpiralRand = sc->AddSymbol(L"spiralrand");
  _SpiralSpeed = sc->AddSymbol(L"spiralspeed");
  _SpiralRandSpeed = sc->AddSymbol(L"spiralrandspeed");
  _AnimRand = sc->AddSymbol(L"animrand");
  _AnimSpeed = sc->AddSymbol(L"animspeed");
  _AnimSpeedRand = sc->AddSymbol(L"animspeedrand");
  _AnimDifferent = sc->AddSymbol(L"animdifferent");
  _ScaleRand = sc->AddSymbol(L"scalerand");
};

void Wz4RenderAnimChunks::Bind(class ScriptContext *sc,Wz4RenderParaChunks *para)
{
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Scale,1,&para->Scale);
  sc->BindLocalFloat(_LookAhead,1,&para->LookAhead);
  sc->BindLocalFloat(_RotStart,3,&para->RotStart.x);
  sc->BindLocalFloat(_RotSpeed,3,&para->RotSpeed.x);
  sc->BindLocalFloat(_RotRand,3,&para->RotRand.x);
  sc->BindLocalFloat(_SpiralRand,1,&para->SpiralRand);
  sc->BindLocalFloat(_SpiralSpeed,1,&para->SpiralSpeed);
  sc->BindLocalFloat(_SpiralRandSpeed,1,&para->SpiralRandSpeed);
  sc->BindLocalFloat(_AnimRand,1,&para->AnimRand);
  sc->BindLocalFloat(_AnimSpeed,1,&para->AnimSpeed);
  sc->BindLocalFloat(_AnimSpeedRand,1,&para->AnimSpeedRand);
  sc->BindLocalInt(_AnimDifferent,1,&para->AnimDifferent);
  sc->BindLocalFloat(_ScaleRand,1,&para->ScaleRand);
};

void Wz4RenderAnimDebris::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
};

void Wz4RenderAnimDebris::Bind(class ScriptContext *sc,Wz4RenderParaDebris *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
};

void Wz4RenderAnimTrails::Init(class ScriptContext *sc)
{
  _Delta = sc->AddSymbol(L"delta");
  _Width = sc->AddSymbol(L"width");
  _LightEnv = sc->AddSymbol(L"lightenv");
  _Tweak = sc->AddSymbol(L"tweak");
  _TrailStep = sc->AddSymbol(L"trailstep");
};

void Wz4RenderAnimTrails::Bind(class ScriptContext *sc,Wz4RenderParaTrails *para)
{
  sc->BindLocalFloat(_Delta,1,&para->Delta);
  sc->BindLocalFloat(_Width,1,&para->Width);
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_Tweak,3,&para->Tweak.x);
  sc->BindLocalInt(_TrailStep,1,&para->TrailStep);
};

void Wz4RenderAnimMetaballs::Init(class ScriptContext *sc)
{
  _Trans = sc->AddSymbol(L"trans");
  _Size = sc->AddSymbol(L"size");
};

void Wz4RenderAnimMetaballs::Bind(class ScriptContext *sc,Wz4RenderParaMetaballs *para)
{
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Size,1,&para->Size);
};

void Wz4RenderAnimMarchingCubes::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimMarchingCubes::Bind(class ScriptContext *sc,Wz4RenderParaMarchingCubes *para)
{
};

void Wz4RenderAnimMarchingCubesColor::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimMarchingCubesColor::Bind(class ScriptContext *sc,Wz4RenderParaMarchingCubesColor *para)
{
};

void Wz4ParticlesAnimBulge::Init(class ScriptContext *sc)
{
  _Center = sc->AddSymbol(L"center");
  _Size = sc->AddSymbol(L"size");
  _Stretch = sc->AddSymbol(L"stretch");
  _FadeGamma = sc->AddSymbol(L"fadegamma");
  _Warp = sc->AddSymbol(L"warp");
};

void Wz4ParticlesAnimBulge::Bind(class ScriptContext *sc,Wz4ParticlesParaBulge *para)
{
  sc->BindLocalFloat(_Center,3,&para->Center.x);
  sc->BindLocalFloat(_Size,3,&para->Size.x);
  sc->BindLocalFloat(_Stretch,3,&para->Stretch.x);
  sc->BindLocalFloat(_FadeGamma,1,&para->FadeGamma);
  sc->BindLocalFloat(_Warp,1,&para->Warp);
};

void Wz4ParticlesAnimSparcle::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimSparcle::Bind(class ScriptContext *sc,Wz4ParticlesParaSparcle *para)
{
};

void Wz4ParticlesAnimFromMesh::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimFromMesh::Bind(class ScriptContext *sc,Wz4ParticlesParaFromMesh *para)
{
};

void Wz4ParticlesAnimMorph::Init(class ScriptContext *sc)
{
  _Transition = sc->AddSymbol(L"transition");
  _DirFactor = sc->AddSymbol(L"dirfactor");
  _NewVertexPos = sc->AddSymbol(L"newvertexpos");
  _BigBangOrigin = sc->AddSymbol(L"bigbangorigin");
  _BigBangDirFactor = sc->AddSymbol(L"bigbangdirfactor");
};

void Wz4ParticlesAnimMorph::Bind(class ScriptContext *sc,Wz4ParticlesParaMorph *para)
{
  sc->BindLocalFloat(_Transition,1,&para->Transition);
  sc->BindLocalFloat(_DirFactor,3,&para->DirFactor.x);
  sc->BindLocalInt(_NewVertexPos,1,&para->NewVertexPos);
  sc->BindLocalFloat(_BigBangOrigin,3,&para->BigBangOrigin.x);
  sc->BindLocalFloat(_BigBangDirFactor,3,&para->BigBangDirFactor.x);
};


/****************************************************************************/

void AddTypes_fxparticle_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4ExplosionType = new Wz4ExplosionType_);
  Wz4ExplosionType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_fxparticle_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Cloud";
  cl->Label = L"Cloud";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdCloud;
  cl->MakeGui = Wz4ParticlesGuiCloud;
  cl->SetDefaults = Wz4ParticlesDefCloud;
  cl->BindPara = Wz4ParticlesBindCloud;
  cl->Bind2Para = Wz4ParticlesBind2Cloud;
  cl->Bind3Para = Wz4ParticlesBind3Cloud;
  cl->WikiText = Wz4ParticlesWikiCloud;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Column = 3;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Ballistic";
  cl->Label = L"Ballistic";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdBallistic;
  cl->MakeGui = Wz4ParticlesGuiBallistic;
  cl->SetDefaults = Wz4ParticlesDefBallistic;
  cl->BindPara = Wz4ParticlesBindBallistic;
  cl->Bind2Para = Wz4ParticlesBind2Ballistic;
  cl->Bind3Para = Wz4ParticlesBind3Ballistic;
  cl->WikiText = Wz4ParticlesWikiBallistic;
  cl->ParaStrings = 1;
  cl->ParaWords = 22;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Mesh";
  cl->Label = L"Mesh";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdMesh;
  cl->MakeGui = Wz4ParticlesGuiMesh;
  cl->SetDefaults = Wz4ParticlesDefMesh;
  cl->BindPara = Wz4ParticlesBindMesh;
  cl->Bind2Para = Wz4ParticlesBind2Mesh;
  cl->Bind3Para = Wz4ParticlesBind3Mesh;
  cl->WikiText = Wz4ParticlesWikiMesh;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Explosion";
  cl->Label = L"Explosion";
  cl->OutputType = Wz4ExplosionType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ExplosionCmdExplosion;
  cl->MakeGui = Wz4ExplosionGuiExplosion;
  cl->SetDefaults = Wz4ExplosionDefExplosion;
  cl->BindPara = Wz4ExplosionBindExplosion;
  cl->Bind2Para = Wz4ExplosionBind2Explosion;
  cl->Bind3Para = Wz4ExplosionBind3Explosion;
  cl->WikiText = Wz4ExplosionWikiExplosion;
  cl->Handles = Wz4ExplosionHndExplosion;
  cl->ParaWords = 29;
  cl->Column = 3;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Exploder";
  cl->Label = L"Exploder";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdExploder;
  cl->MakeGui = Wz4ParticlesGuiExploder;
  cl->SetDefaults = Wz4ParticlesDefExploder;
  cl->BindPara = Wz4ParticlesBindExploder;
  cl->Bind2Para = Wz4ParticlesBind2Exploder;
  cl->Bind3Para = Wz4ParticlesBind3Exploder;
  cl->WikiText = Wz4ParticlesWikiExploder;
  cl->ParaWords = 8;
  cl->Column = 3;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4ExplosionType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Cloud2";
  cl->Label = L"Cloud2";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdCloud2;
  cl->MakeGui = Wz4ParticlesGuiCloud2;
  cl->SetDefaults = Wz4ParticlesDefCloud2;
  cl->BindPara = Wz4ParticlesBindCloud2;
  cl->Bind2Para = Wz4ParticlesBind2Cloud2;
  cl->Bind3Para = Wz4ParticlesBind3Cloud2;
  cl->WikiText = Wz4ParticlesWikiCloud2;
  cl->SetDefaultsArray = Wz4ParticlesArrCloud2;
  cl->ArrayCount = 9;
  cl->ParaWords = 2;
  cl->Column = 3;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FromVertex";
  cl->Label = L"FromVertex";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdFromVertex;
  cl->MakeGui = Wz4ParticlesGuiFromVertex;
  cl->SetDefaults = Wz4ParticlesDefFromVertex;
  cl->BindPara = Wz4ParticlesBindFromVertex;
  cl->Bind2Para = Wz4ParticlesBind2FromVertex;
  cl->Bind3Para = Wz4ParticlesBind3FromVertex;
  cl->WikiText = Wz4ParticlesWikiFromVertex;
  cl->ParaWords = 3;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Wobble";
  cl->Label = L"Wobble";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdWobble;
  cl->MakeGui = Wz4ParticlesGuiWobble;
  cl->SetDefaults = Wz4ParticlesDefWobble;
  cl->BindPara = Wz4ParticlesBindWobble;
  cl->Bind2Para = Wz4ParticlesBind2Wobble;
  cl->Bind3Para = Wz4ParticlesBind3Wobble;
  cl->WikiText = Wz4ParticlesWikiWobble;
  cl->ParaStrings = 1;
  cl->ParaWords = 15;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Add";
  cl->Label = L"Add";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdAdd;
  cl->MakeGui = Wz4ParticlesGuiAdd;
  cl->SetDefaults = Wz4ParticlesDefAdd;
  cl->BindPara = Wz4ParticlesBindAdd;
  cl->Bind2Para = Wz4ParticlesBind2Add;
  cl->Bind3Para = Wz4ParticlesBind3Add;
  cl->WikiText = Wz4ParticlesWikiAdd;
  cl->Column = 3;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Lissajous";
  cl->Label = L"Lissajous";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdLissajous;
  cl->MakeGui = Wz4ParticlesGuiLissajous;
  cl->SetDefaults = Wz4ParticlesDefLissajous;
  cl->BindPara = Wz4ParticlesBindLissajous;
  cl->Bind2Para = Wz4ParticlesBind2Lissajous;
  cl->Bind3Para = Wz4ParticlesBind3Lissajous;
  cl->WikiText = Wz4ParticlesWikiLissajous;
  cl->SetDefaultsArray = Wz4ParticlesArrLissajous;
  cl->ArrayCount = 4;
  cl->ParaStrings = 1;
  cl->ParaWords = 24;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SplinedParticles";
  cl->Label = L"SplinedParticles";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdSplinedParticles;
  cl->MakeGui = Wz4ParticlesGuiSplinedParticles;
  cl->SetDefaults = Wz4ParticlesDefSplinedParticles;
  cl->BindPara = Wz4ParticlesBindSplinedParticles;
  cl->Bind2Para = Wz4ParticlesBind2SplinedParticles;
  cl->Bind3Para = Wz4ParticlesBind3SplinedParticles;
  cl->WikiText = Wz4ParticlesWikiSplinedParticles;
  cl->ParaStrings = 3;
  cl->ParaWords = 17;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Trails";
  cl->Label = L"Trails";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdTrails;
  cl->MakeGui = Wz4ParticlesGuiTrails;
  cl->SetDefaults = Wz4ParticlesDefTrails;
  cl->BindPara = Wz4ParticlesBindTrails;
  cl->Bind2Para = Wz4ParticlesBind2Trails;
  cl->Bind3Para = Wz4ParticlesBind3Trails;
  cl->WikiText = Wz4ParticlesWikiTrails;
  cl->ParaWords = 3;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"StaticParticles";
  cl->Label = L"StaticParticles";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdStaticParticles;
  cl->MakeGui = Wz4ParticlesGuiStaticParticles;
  cl->SetDefaults = Wz4ParticlesDefStaticParticles;
  cl->BindPara = Wz4ParticlesBindStaticParticles;
  cl->Bind2Para = Wz4ParticlesBind2StaticParticles;
  cl->Bind3Para = Wz4ParticlesBind3StaticParticles;
  cl->WikiText = Wz4ParticlesWikiStaticParticles;
  cl->Handles = Wz4ParticlesHndStaticParticles;
  cl->SetDefaultsArray = Wz4ParticlesArrStaticParticles;
  cl->ArrayCount = 8;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sprites";
  cl->Label = L"Sprites";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSprites;
  cl->MakeGui = Wz4RenderGuiSprites;
  cl->SetDefaults = Wz4RenderDefSprites;
  cl->BindPara = Wz4RenderBindSprites;
  cl->Bind2Para = Wz4RenderBind2Sprites;
  cl->Bind3Para = Wz4RenderBind3Sprites;
  cl->WikiText = Wz4RenderWikiSprites;
  cl->ParaStrings = 1;
  cl->ParaWords = 27;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(3);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = Texture2DType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Chunks";
  cl->Label = L"Chunks";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdChunks;
  cl->MakeGui = Wz4RenderGuiChunks;
  cl->SetDefaults = Wz4RenderDefChunks;
  cl->BindPara = Wz4RenderBindChunks;
  cl->Bind2Para = Wz4RenderBind2Chunks;
  cl->Bind3Para = Wz4RenderBind3Chunks;
  cl->WikiText = Wz4RenderWikiChunks;
  cl->ParaStrings = 1;
  cl->ParaWords = 27;
  cl->Column = 2;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Debris";
  cl->Label = L"ExplodeChunks";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdDebris;
  cl->MakeGui = Wz4RenderGuiDebris;
  cl->SetDefaults = Wz4RenderDefDebris;
  cl->BindPara = Wz4RenderBindDebris;
  cl->Bind2Para = Wz4RenderBind2Debris;
  cl->Bind3Para = Wz4RenderBind3Debris;
  cl->WikiText = Wz4RenderWikiDebris;
  cl->ParaStrings = 1;
  cl->ParaWords = 2;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Trails";
  cl->Label = L"Trails";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdTrails;
  cl->MakeGui = Wz4RenderGuiTrails;
  cl->SetDefaults = Wz4RenderDefTrails;
  cl->BindPara = Wz4RenderBindTrails;
  cl->Bind2Para = Wz4RenderBind2Trails;
  cl->Bind3Para = Wz4RenderBind3Trails;
  cl->WikiText = Wz4RenderWikiTrails;
  cl->ParaStrings = 1;
  cl->ParaWords = 11;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Metaballs";
  cl->Label = L"Metaballs";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdMetaballs;
  cl->MakeGui = Wz4RenderGuiMetaballs;
  cl->SetDefaults = Wz4RenderDefMetaballs;
  cl->BindPara = Wz4RenderBindMetaballs;
  cl->Bind2Para = Wz4RenderBind2Metaballs;
  cl->Bind3Para = Wz4RenderBind3Metaballs;
  cl->WikiText = Wz4RenderWikiMetaballs;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Column = 2;
  cl->Flags = 0x0040;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MarchingCubes";
  cl->Label = L"MarchingCubes";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdMarchingCubes;
  cl->MakeGui = Wz4RenderGuiMarchingCubes;
  cl->SetDefaults = Wz4RenderDefMarchingCubes;
  cl->BindPara = Wz4RenderBindMarchingCubes;
  cl->Bind2Para = Wz4RenderBind2MarchingCubes;
  cl->Bind3Para = Wz4RenderBind3MarchingCubes;
  cl->WikiText = Wz4RenderWikiMarchingCubes;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MarchingCubesColor";
  cl->Label = L"MarchingCubesColor";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdMarchingCubesColor;
  cl->MakeGui = Wz4RenderGuiMarchingCubesColor;
  cl->SetDefaults = Wz4RenderDefMarchingCubesColor;
  cl->BindPara = Wz4RenderBindMarchingCubesColor;
  cl->Bind2Para = Wz4RenderBind2MarchingCubesColor;
  cl->Bind3Para = Wz4RenderBind3MarchingCubesColor;
  cl->WikiText = Wz4RenderWikiMarchingCubesColor;
  cl->ParaStrings = 1;
  cl->ParaWords = 8;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bulge";
  cl->Label = L"Bulge";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdBulge;
  cl->MakeGui = Wz4ParticlesGuiBulge;
  cl->SetDefaults = Wz4ParticlesDefBulge;
  cl->BindPara = Wz4ParticlesBindBulge;
  cl->Bind2Para = Wz4ParticlesBind2Bulge;
  cl->Bind3Para = Wz4ParticlesBind3Bulge;
  cl->WikiText = Wz4ParticlesWikiBulge;
  cl->ParaStrings = 1;
  cl->ParaWords = 12;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sparcle";
  cl->Label = L"Sparcle";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdSparcle;
  cl->MakeGui = Wz4ParticlesGuiSparcle;
  cl->SetDefaults = Wz4ParticlesDefSparcle;
  cl->BindPara = Wz4ParticlesBindSparcle;
  cl->Bind2Para = Wz4ParticlesBind2Sparcle;
  cl->Bind3Para = Wz4ParticlesBind3Sparcle;
  cl->WikiText = Wz4ParticlesWikiSparcle;
  cl->ParaWords = 7;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FromMesh";
  cl->Label = L"FromMesh";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdFromMesh;
  cl->MakeGui = Wz4ParticlesGuiFromMesh;
  cl->SetDefaults = Wz4ParticlesDefFromMesh;
  cl->BindPara = Wz4ParticlesBindFromMesh;
  cl->Bind2Para = Wz4ParticlesBind2FromMesh;
  cl->Bind3Para = Wz4ParticlesBind3FromMesh;
  cl->WikiText = Wz4ParticlesWikiFromMesh;
  cl->ParaWords = 7;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Morph";
  cl->Label = L"Morph";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdMorph;
  cl->MakeGui = Wz4ParticlesGuiMorph;
  cl->SetDefaults = Wz4ParticlesDefMorph;
  cl->BindPara = Wz4ParticlesBindMorph;
  cl->Bind2Para = Wz4ParticlesBind2Morph;
  cl->Bind3Para = Wz4ParticlesBind3Morph;
  cl->WikiText = Wz4ParticlesWikiMorph;
  cl->ParaStrings = 1;
  cl->ParaWords = 11;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fxparticle_ops,0x110,AddOps_fxparticle_ops,0);


/****************************************************************************/


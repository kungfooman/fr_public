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
#include "fr063_sph_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class SphGeneratorType_ *SphGeneratorType;
class SphCollisionType_ *SphCollisionType;

/****************************************************************************/

#line 19 "fr063_sph_ops.ops"

#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/fxparticle_ops.hpp"
#include "wz4frlib/fr063_sph.hpp"
#include "wz4lib/script.hpp" 

#line 31 "fr063_sph_ops.cpp"

/****************************************************************************/

#line 37 "fr063_sph_ops.ops"
void SphGeneratorType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 38 "fr063_sph_ops.ops"
 sSetTarget(sTargetPara(sCLEAR_ALL,pi.BackColor,pi.Spec)); ;
#line 40 "fr063_sph_ops.cpp"
}
#line 47 "fr063_sph_ops.ops"
void SphCollisionType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 48 "fr063_sph_ops.ops"
 sSetTarget(sTargetPara(sCLEAR_ALL,pi.BackColor,pi.Spec)); ;
#line 47 "fr063_sph_ops.cpp"
}

/****************************************************************************/

sBool Wz4ParticlesCmdSphSimulator(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaSphSimulator sUNUSED *para = (Wz4ParticlesParaSphSimulator *)(cmd->Data); para;
  AnyType sUNUSED *in0 = cmd->GetInput<AnyType *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 105 "fr063_sph_ops.ops"

    RPSPH *node = new RPSPH();
    node->ParaBase = node->Para = *para;
    out->RootNode = node;

    for(sInt i=0;i<cmd->InputCount;i++)
    {
      wObject *obj = cmd->GetInput<wObject *>(i);
      if(obj)
      {
        if(obj->Type==SphGeneratorType)
        {
          node->Gens.AddTail((SphGenerator *)obj);
          obj->AddRef();
        }
        if(obj->Type==SphCollisionType)
        {
          node->Colls.AddTail((SphCollision *)obj);
          obj->AddRef();
        }
      }
    }
    node->Init();

    out->AddCode(cmd);
  ;
#line 87 "fr063_sph_ops.cpp"
    return 1;
  }
}

sInt Wz4ParticlesActSphSimulator(wOp *op,sInt code,sInt pos)
{
  Wz4ParticlesParaSphSimulator sUNUSED *para = (Wz4ParticlesParaSphSimulator *)(op->EditData); para;
#line 97 "fr063_sph_ops.ops"

    if(code==1)
      return 1;
    else
      return 0;
  ;
#line 102 "fr063_sph_ops.cpp"
}

void Wz4ParticlesGuiSphSimulator(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaSphSimulator sUNUSED *para = (Wz4ParticlesParaSphSimulator *)(op->EditData); para;
  gh.Group(op->Class->Label);

  if(0x0000)
  {
    gh.Label(L"TimeStep (ms)");
    sIntControl *int_TimeStep_Old = gh.Int(&para->TimeStep_Old,0,1000,0.125000f);
    int_TimeStep_Old->Default = 0x00000000; int_TimeStep_Old->RightStep = 0.125000f;

  }
  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Restart",gh.ActionMsg);

  gh.Label(L"Gravity");
  sFloatControl *float_Gravity = gh.Float(&para->Gravity,-1024.00f,1024.000f,0.000001f);
  float_Gravity->Default = 0.000000f; float_Gravity->RightStep = 0.125000f;

  gh.Label(L"CentralGravity");
  sFloatControl *float_CentralGravity = gh.Float(&para->CentralGravity,-1024.00f,1024.000f,0.000001f);
  float_CentralGravity->Default = 0.000000f; float_CentralGravity->RightStep = 0.125000f;

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

  gh.Label(L"BasePressure");
  sFloatControl *float_BasePressure = gh.Float(&para->BasePressure,0.000000f,1.000000f,0.002000f);
  float_BasePressure->Default = 0.000000f; float_BasePressure->RightStep = 0.125000f;

  gh.Label(L"Viscosity");
  sFloatControl *float_Viscosity = gh.Float(&para->Viscosity,0.000000f,1.000000f,0.002000f);
  float_Viscosity->Default = 0.000000f; float_Viscosity->RightStep = 0.125000f;

  gh.Group(L"Control");

  gh.Label(L"MaxPart");
  sIntControl *int_MaxPart = gh.Int(&para->MaxPart,0,1000000,100.0000f);
  int_MaxPart->Default = 0x00002710; int_MaxPart->RightStep = 0.125000f;

  gh.Label(L"StartSteps");
  sIntControl *int_StartSteps = gh.Int(&para->StartSteps,0,100000,0.125000f);
  int_StartSteps->Default = 0x00000000; int_StartSteps->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"synchonized|as fas as possible:*1-|Colors:*3can break|no breaking",gh.LayoutMsg);

  if((para->Flags&0x0001))
  {
    gh.Label(L"TicksPerFrame");
    sIntControl *int_TicksPerFrame = gh.Int(&para->TicksPerFrame,1,1024,0.125000f);
    int_TicksPerFrame->Default = 0x00000001; int_TicksPerFrame->RightStep = 0.125000f;

  }
  if(!(para->Flags&0x0001))
  {
    gh.Label(L"TimeStep");
    sFloatControl *float_TimeStep = gh.Float(&para->TimeStep,0.000100f,10.00000f,0.125000f);
    float_TimeStep->Default = 0.020000f; float_TimeStep->RightStep = 0.125000f;

    gh.Flags(&para->Flags,L"*2s|ms",gh.ChangeMsg);

    gh.Label(L"MaxSteps");
    sIntControl *int_MaxSteps = gh.Int(&para->MaxSteps,1,100,0.125000f);
    int_MaxSteps->Default = 0x0000000a; int_MaxSteps->RightStep = 0.125000f;

  }
  gh.Group(L"other");

  gh.Label(L"ColorSmooth");
  sFloatControl *float_ColorSmooth = gh.Float(&para->ColorSmooth,0.000000f,1.000000f,0.001000f);
  float_ColorSmooth->Default = 0.000000f; float_ColorSmooth->RightStep = 0.125000f;

  gh.Label(L"SpringForce");
  sFloatControl *float_SpringForce = gh.Float(&para->SpringForce,0.000000f,1024.000f,0.000100f);
  float_SpringForce->Default = 0.000000f; float_SpringForce->RightStep = 0.125000f;

  gh.Label(L"SpringBreakForce");
  sFloatControl *float_SpringBreakForce = gh.Float(&para->SpringBreakForce,0.000000f,1024.000f,0.000100f);
  float_SpringBreakForce->Default = 1.000000f; float_SpringBreakForce->RightStep = 0.125000f;

  gh.Label(L"PhysicsCycles");
  sIntControl *int_PhysicsCycles = gh.Int(&para->PhysicsCycles,1,1024,0.125000f);
  int_PhysicsCycles->Default = 0x00000001; int_PhysicsCycles->RightStep = 0.125000f;

  gh.Label(L"SpringBreakForceDot");
  sFloatControl *float_SpringBreakForceDot = gh.Float(&para->SpringBreakForceDot,0.000000f,1024.000f,0.000100f);
  float_SpringBreakForceDot->Default = 1.000000f; float_SpringBreakForceDot->RightStep = 0.125000f;

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"off|limited",gh.ChangeMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefSphSimulator(wOp *op)
{
  Wz4ParticlesParaSphSimulator sUNUSED *para = (Wz4ParticlesParaSphSimulator *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->OuterForce = 0.000100f;
  para->InnerForce = 0.010000f;
  para->InteractRadius = 0.100000f;
  para->Friction = 0.995000f;
  para->MaxPart = 0x00002710;
  para->TicksPerFrame = 0x00000001;
  para->TimeStep = 0.020000f;
  para->MaxSteps = 0x0000000a;
  para->SpringBreakForce = 1.000000f;
  para->PhysicsCycles = 0x00000001;
  para->SpringBreakForceDot = 1.000000f;
}

void Wz4ParticlesBindSphSimulator(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"timestep_old"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"centralgravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"outerforce"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"innerforce"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"interactradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"friction"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"basepressure"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"viscosity"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"maxpart"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"startsteps"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"ticksperframe"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"timestep"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"maxsteps"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"colorsmooth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"springforce"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"springbreakforce"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"physicscycles"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"springbreakforcedot"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2SphSimulator(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[27];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"timestep_old");
    name[1] = sPoolString(L"restart");
    name[2] = sPoolString(L"gravity");
    name[3] = sPoolString(L"centralgravity");
    name[4] = sPoolString(L"outerforce");
    name[5] = sPoolString(L"innerforce");
    name[6] = sPoolString(L"interactradius");
    name[7] = sPoolString(L"friction");
    name[8] = sPoolString(L"basepressure");
    name[9] = sPoolString(L"viscosity");
    name[10] = sPoolString(L"control");
    name[11] = sPoolString(L"maxpart");
    name[12] = sPoolString(L"startsteps");
    name[13] = sPoolString(L"flags");
    name[14] = sPoolString(L"ticksperframe");
    name[15] = sPoolString(L"timestep");
    name[16] = sPoolString(L"flags");
    name[17] = sPoolString(L"maxsteps");
    name[18] = sPoolString(L"other");
    name[19] = sPoolString(L"colorsmooth");
    name[20] = sPoolString(L"springforce");
    name[21] = sPoolString(L"springbreakforce");
    name[22] = sPoolString(L"physicscycles");
    name[23] = sPoolString(L"springbreakforcedot");
    name[24] = sPoolString(L"multithreading");
    name[25] = sPoolString(L"");
    name[26] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[11],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[12],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[14],ScriptTypeInt,1,cmd->Data+12);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[17],ScriptTypeInt,1,cmd->Data+14);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[22],ScriptTypeInt,1,cmd->Data+18);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[26],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3SphSimulator(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import timestep_old : int;\n");
  tb.PrintF(L"  import gravity : float;\n");
  tb.PrintF(L"  import centralgravity : float;\n");
  tb.PrintF(L"  import outerforce : float;\n");
  tb.PrintF(L"  import innerforce : float;\n");
  tb.PrintF(L"  import interactradius : float;\n");
  tb.PrintF(L"  import friction : float;\n");
  tb.PrintF(L"  import basepressure : float;\n");
  tb.PrintF(L"  import viscosity : float;\n");
  tb.PrintF(L"  import maxpart : int;\n");
  tb.PrintF(L"  import startsteps : int;\n");
  tb.PrintF(L"  import ticksperframe : int;\n");
  tb.PrintF(L"  import timestep : float;\n");
  tb.PrintF(L"  import maxsteps : int;\n");
  tb.PrintF(L"  import colorsmooth : float;\n");
  tb.PrintF(L"  import springforce : float;\n");
  tb.PrintF(L"  import springbreakforce : float;\n");
  tb.PrintF(L"  import physicscycles : int;\n");
  tb.PrintF(L"  import springbreakforcedot : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiSphSimulator =
L"= Wz4Particles : SphSimulator\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphSimulator\n"
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
L" !i AnyType\n"
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
L" !i TimeStep (ms)\n"
L" !i TimeStep_Old\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Restart\n"
L" !i Restart\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CentralGravity\n"
L" !i CentralGravity\n"
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
L" !i BasePressure\n"
L" !i BasePressure\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Viscosity\n"
L" !i Viscosity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaxPart\n"
L" !i MaxPart\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i StartSteps\n"
L" !i StartSteps\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i synchonized\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i as fas as possible\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Colors\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i can break\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i no breaking\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i TicksPerFrame\n"
L" !i TicksPerFrame\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i TimeStep\n"
L" !i TimeStep\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Flags\n"
L" !i s\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ms\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MaxSteps\n"
L" !i MaxSteps\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i ColorSmooth\n"
L" !i ColorSmooth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpringForce\n"
L" !i SpringForce\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpringBreakForce\n"
L" !i SpringBreakForce\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i PhysicsCycles\n"
L" !i PhysicsCycles\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i SpringBreakForceDot\n"
L" !i SpringBreakForceDot\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Multithreading\n"
L" !i Multithreading\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
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

sBool SphGeneratorCmdSphObject(wExecutive *exe,wCommand *cmd)
{
  SphGeneratorParaSphObject sUNUSED *para = (SphGeneratorParaSphObject *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  SphGenObject *out = (SphGenObject *) cmd->Output;
  if(!out) { out=new SphGenObject; cmd->Output=out; }

  {
#line 158 "fr063_sph_ops.ops"
    
    out->Para = *para;
    out->Init(in0);
  ;
#line 595 "fr063_sph_ops.cpp"
    return 1;
  }
}

void SphGeneratorGuiSphObject(wGridFrameHelper &gh,wOp *op)
{
  SphGeneratorParaSphObject sUNUSED *para = (SphGeneratorParaSphObject *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Shape,L"*4-|springs",gh.ChangeMsg);

  if(!(op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Shape");
    gh.Flags(&para->Shape,L"box|sphere",gh.ChangeMsg);

    gh.Label(L"Center");
    gh.BeginTied();
    sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-1024.00f,1024.000f,0.010000f);
    float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
    sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-1024.00f,1024.000f,0.010000f);
    float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
    sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-1024.00f,1024.000f,0.010000f);
    float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Radius");
    gh.BeginTied();
    sFloatControl *float_Radius_0 = gh.Float(&para->Radius.x,0.000000f,1024.000f,0.010000f);
    float_Radius_0->Default = 0.000000f; float_Radius_0->RightStep = 0.125000f;
    sFloatControl *float_Radius_1 = gh.Float(&para->Radius.y,0.000000f,1024.000f,0.010000f);
    float_Radius_1->Default = 0.000000f; float_Radius_1->RightStep = 0.125000f;
    sFloatControl *float_Radius_2 = gh.Float(&para->Radius.z,0.000000f,1024.000f,0.010000f);
    float_Radius_2->Default = 0.000000f; float_Radius_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Raster");
  sFloatControl *float_Raster = gh.Float(&para->Raster,0.000000f,1024.000f,0.001000f);
  float_Raster->Default = 1.000000f; float_Raster->RightStep = 0.125000f;

  gh.Label(L"Randomness");
  sFloatControl *float_Randomness = gh.Float(&para->Randomness,0.000000f,1.000000f,0.010000f);
  float_Randomness->Default = 0.000000f; float_Randomness->RightStep = 0.125000f;

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.Label(L"StartSpeed");
  gh.BeginTied();
  sFloatControl *float_StartSpeed_0 = gh.Float(&para->StartSpeed.x,-1024.00f,1024.000f,0.001000f);
  float_StartSpeed_0->Default = 0.000000f; float_StartSpeed_0->RightStep = 0.125000f;
  sFloatControl *float_StartSpeed_1 = gh.Float(&para->StartSpeed.y,-1024.00f,1024.000f,0.001000f);
  float_StartSpeed_1->Default = 0.000000f; float_StartSpeed_1->RightStep = 0.125000f;
  sFloatControl *float_StartSpeed_2 = gh.Float(&para->StartSpeed.z,-1024.00f,1024.000f,0.001000f);
  float_StartSpeed_2->Default = 0.000000f; float_StartSpeed_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Time0");
  sIntControl *int_Time0 = gh.Int(&para->Time0,0,65536,0.125000f);
  int_Time0->Default = 0x00000000; int_Time0->RightStep = 0.125000f;
}

void SphGeneratorDefSphObject(wOp *op)
{
  SphGeneratorParaSphObject sUNUSED *para = (SphGeneratorParaSphObject *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Raster = 1.000000f;
}

void SphGeneratorBindSphObject(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"raster"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"randomness"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"startspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"startspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"startspeed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"time0"),val);
}
void SphGeneratorBind2SphObject(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"shape");
    name[2] = sPoolString(L"center");
    name[3] = sPoolString(L"radius");
    name[4] = sPoolString(L"raster");
    name[5] = sPoolString(L"randomness");
    name[6] = sPoolString(L"color_");
    name[7] = sPoolString(L"startspeed");
    name[8] = sPoolString(L"time0");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[6],ScriptTypeColor,1,cmd->Data+9);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+13);
}
void SphGeneratorBind3SphObject(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import radius : float[3];\n");
  tb.PrintF(L"  import raster : float;\n");
  tb.PrintF(L"  import randomness : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import startspeed : float[3];\n");
  tb.PrintF(L"  import time0 : int;\n");
}
const sChar *SphGeneratorWikiSphObject =
L"= SphGenerator : SphObject\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphObject\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphGenerator\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Shape\n"
L" !i springs\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Shape\n"
L" !i Shape\n"
L" !i box\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sphere\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Raster\n"
L" !i Raster\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Randomness\n"
L" !i Randomness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i StartSpeed\n"
L" !i StartSpeed\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Time0\n"
L" !i Time0\n"
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

sBool SphGeneratorCmdSphSource(wExecutive *exe,wCommand *cmd)
{
  SphGeneratorParaSphSource sUNUSED *para = (SphGeneratorParaSphSource *)(cmd->Data); para;
  SphGenSource *out = (SphGenSource *) cmd->Output;
  if(!out) { out=new SphGenSource; cmd->Output=out; }

  {
#line 185 "fr063_sph_ops.ops"

    out->Para = *para;
    out->Init();
  ;
#line 852 "fr063_sph_ops.cpp"
    return 1;
  }
}

void SphGeneratorGuiSphSource(wGridFrameHelper &gh,wOp *op)
{
  SphGeneratorParaSphSource sUNUSED *para = (SphGeneratorParaSphSource *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Shape");
  gh.Flags(&para->Shape,L"Square|Round",gh.ChangeMsg);

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-1024.00f,1024.000f,0.010000f);
  float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-1024.00f,1024.000f,0.010000f);
  float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
  sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-1024.00f,1024.000f,0.010000f);
  float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Speed");
  gh.BeginTied();
  sFloatControl *float_Speed_0 = gh.Float(&para->Speed.x,-1024.00f,1024.000f,0.001000f);
  float_Speed_0->Default = 0.000000f; float_Speed_0->RightStep = 0.125000f;
  sFloatControl *float_Speed_1 = gh.Float(&para->Speed.y,-1024.00f,1024.000f,0.001000f);
  float_Speed_1->Default = 0.000000f; float_Speed_1->RightStep = 0.125000f;
  sFloatControl *float_Speed_2 = gh.Float(&para->Speed.z,-1024.00f,1024.000f,0.001000f);
  float_Speed_2->Default = 0.000000f; float_Speed_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,-1024.00f,1024.000f,0.010000f);
  float_Radius->Default = 0.000000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Density");
  sFloatControl *float_Density = gh.Float(&para->Density,0.000000f,1024.000f,0.000100f);
  float_Density->Default = 0.000000f; float_Density->RightStep = 0.125000f;

  gh.Label(L"Randomness");
  sFloatControl *float_Randomness = gh.Float(&para->Randomness,0.000000f,1.000000f,0.010000f);
  float_Randomness->Default = 0.000000f; float_Randomness->RightStep = 0.125000f;

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.Label(L"StartTime");
  sIntControl *int_StartTime = gh.Int(&para->StartTime,0,1000000,0.125000f);
  int_StartTime->Default = 0x00000000; int_StartTime->RightStep = 0.125000f;

  gh.Label(L"EndTime");
  sIntControl *int_EndTime = gh.Int(&para->EndTime,0,1000000,0.125000f);
  int_EndTime->Default = 0x00000000; int_EndTime->RightStep = 0.125000f;
}

void SphGeneratorDefSphSource(wOp *op)
{
  SphGeneratorParaSphSource sUNUSED *para = (SphGeneratorParaSphSource *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void SphGeneratorBindSphSource(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"density"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"randomness"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"starttime"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"endtime"),val);
}
void SphGeneratorBind2SphSource(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"shape");
    name[1] = sPoolString(L"center");
    name[2] = sPoolString(L"speed");
    name[3] = sPoolString(L"radius");
    name[4] = sPoolString(L"density");
    name[5] = sPoolString(L"randomness");
    name[6] = sPoolString(L"color_");
    name[7] = sPoolString(L"starttime");
    name[8] = sPoolString(L"endtime");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[6],ScriptTypeColor,1,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+12);
}
void SphGeneratorBind3SphSource(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import speed : float[3];\n");
  tb.PrintF(L"  import radius : float;\n");
  tb.PrintF(L"  import density : float;\n");
  tb.PrintF(L"  import randomness : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import starttime : int;\n");
  tb.PrintF(L"  import endtime : int;\n");
}
const sChar *SphGeneratorWikiSphSource =
L"= SphGenerator : SphSource\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphSource\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphGenerator\n"
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
L" !i Shape\n"
L" !i Shape\n"
L" !i Square\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Round\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Speed\n"
L" !i Speed\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Density\n"
L" !i Density\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Randomness\n"
L" !i Randomness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i StartTime\n"
L" !i StartTime\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i EndTime\n"
L" !i EndTime\n"
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

sBool SphCollisionCmdSphSimpleColl(wExecutive *exe,wCommand *cmd)
{
  SphCollisionParaSphSimpleColl sUNUSED *para = (SphCollisionParaSphSimpleColl *)(cmd->Data); para;
  SphCollSimple *out = (SphCollSimple *) cmd->Output;
  if(!out) { out=new SphCollSimple; cmd->Output=out; }

  {
#line 210 "fr063_sph_ops.ops"

    out->Para = *para;
  ;
#line 1086 "fr063_sph_ops.cpp"
    return 1;
  }
}

void SphCollisionGuiSphSimpleColl(wGridFrameHelper &gh,wOp *op)
{
  SphCollisionParaSphSimpleColl sUNUSED *para = (SphCollisionParaSphSimpleColl *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"contain|kill",gh.ChangeMsg);

  gh.Label(L"Shape");
  gh.Flags(&para->Shape,L"box|sphere",gh.ChangeMsg);

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-1024.00f,1024.000f,0.010000f);
  float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-1024.00f,1024.000f,0.010000f);
  float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
  sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-1024.00f,1024.000f,0.010000f);
  float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Radius");
  gh.BeginTied();
  sFloatControl *float_Radius_0 = gh.Float(&para->Radius.x,0.000000f,1024.000f,0.010000f);
  float_Radius_0->Default = 0.000000f; float_Radius_0->RightStep = 0.125000f;
  sFloatControl *float_Radius_1 = gh.Float(&para->Radius.y,0.000000f,1024.000f,0.010000f);
  float_Radius_1->Default = 0.000000f; float_Radius_1->RightStep = 0.125000f;
  sFloatControl *float_Radius_2 = gh.Float(&para->Radius.z,0.000000f,1024.000f,0.010000f);
  float_Radius_2->Default = 0.000000f; float_Radius_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"StartTime");
  sIntControl *int_StartTime = gh.Int(&para->StartTime,0,100000,0.125000f);
  int_StartTime->Default = 0x00000000; int_StartTime->RightStep = 0.125000f;

  gh.Label(L"EndTime");
  sIntControl *int_EndTime = gh.Int(&para->EndTime,0,100000,0.125000f);
  int_EndTime->Default = 0x00000000; int_EndTime->RightStep = 0.125000f;
}

void SphCollisionDefSphSimpleColl(wOp *op)
{
  SphCollisionParaSphSimpleColl sUNUSED *para = (SphCollisionParaSphSimpleColl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void SphCollisionBindSphSimpleColl(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"starttime"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"endtime"),val);
}
void SphCollisionBind2SphSimpleColl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"shape");
    name[2] = sPoolString(L"center");
    name[3] = sPoolString(L"radius");
    name[4] = sPoolString(L"starttime");
    name[5] = sPoolString(L"endtime");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+9);
}
void SphCollisionBind3SphSimpleColl(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import radius : float[3];\n");
  tb.PrintF(L"  import starttime : int;\n");
  tb.PrintF(L"  import endtime : int;\n");
}
const sChar *SphCollisionWikiSphSimpleColl =
L"= SphCollision : SphSimpleColl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphSimpleColl\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphCollision\n"
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
L" !i contain\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i kill\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Shape\n"
L" !i Shape\n"
L" !i box\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sphere\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i StartTime\n"
L" !i StartTime\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i EndTime\n"
L" !i EndTime\n"
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

sBool SphCollisionCmdSphPlaneColl(wExecutive *exe,wCommand *cmd)
{
  SphCollisionParaSphPlaneColl sUNUSED *para = (SphCollisionParaSphPlaneColl *)(cmd->Data); para;
  SphCollPlane *out = (SphCollPlane *) cmd->Output;
  if(!out) { out=new SphCollPlane; cmd->Output=out; }

  {
#line 230 "fr063_sph_ops.ops"

    out->Para = *para;
  ;
#line 1274 "fr063_sph_ops.cpp"
    return 1;
  }
}

void SphCollisionGuiSphPlaneColl(wGridFrameHelper &gh,wOp *op)
{
  SphCollisionParaSphPlaneColl sUNUSED *para = (SphCollisionParaSphPlaneColl *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"contain|kill",gh.ChangeMsg);

  gh.Label(L"y");
  sFloatControl *float_y = gh.Float(&para->y,-1024.00f,1024.000f,0.010000f);
  float_y->Default = 0.000000f; float_y->RightStep = 0.125000f;

  gh.Label(L"StartTime");
  sIntControl *int_StartTime = gh.Int(&para->StartTime,0,100000,0.125000f);
  int_StartTime->Default = 0x00000000; int_StartTime->RightStep = 0.125000f;

  gh.Label(L"EndTime");
  sIntControl *int_EndTime = gh.Int(&para->EndTime,0,100000,0.125000f);
  int_EndTime->Default = 0x00000000; int_EndTime->RightStep = 0.125000f;
}

void SphCollisionDefSphPlaneColl(wOp *op)
{
  SphCollisionParaSphPlaneColl sUNUSED *para = (SphCollisionParaSphPlaneColl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void SphCollisionBindSphPlaneColl(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"starttime"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"endtime"),val);
}
void SphCollisionBind2SphPlaneColl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"y");
    name[2] = sPoolString(L"starttime");
    name[3] = sPoolString(L"endtime");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
}
void SphCollisionBind3SphPlaneColl(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import y : float;\n");
  tb.PrintF(L"  import starttime : int;\n");
  tb.PrintF(L"  import endtime : int;\n");
}
const sChar *SphCollisionWikiSphPlaneColl =
L"= SphCollision : SphPlaneColl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphPlaneColl\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphCollision\n"
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
L" !i contain\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i kill\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i y\n"
L" !i y\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i StartTime\n"
L" !i StartTime\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i EndTime\n"
L" !i EndTime\n"
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

sBool SphCollisionCmdSphShock(wExecutive *exe,wCommand *cmd)
{
  SphCollisionParaSphShock sUNUSED *para = (SphCollisionParaSphShock *)(cmd->Data); para;
  SphCollShock *out = (SphCollShock *) cmd->Output;
  if(!out) { out=new SphCollShock; cmd->Output=out; }

  {
#line 254 "fr063_sph_ops.ops"

    out->Para = *para;
  ;
#line 1410 "fr063_sph_ops.cpp"
    return 1;
  }
}

void SphCollisionGuiSphShock(wGridFrameHelper &gh,wOp *op)
{
  SphCollisionParaSphShock sUNUSED *para = (SphCollisionParaSphShock *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Time");
  sIntControl *int_Time = gh.Int(&para->Time,0,100000,0.125000f);
  int_Time->Default = 0x00000000; int_Time->RightStep = 0.125000f;

  gh.Group(L"global speed");

  gh.Flags(&para->Flags,L"-|always on",gh.ChangeMsg);

  gh.Label(L"Speed");
  gh.BeginTied();
  sFloatControl *float_Speed_0 = gh.Float(&para->Speed.x,-1024.00f,1024.000f,0.000100f);
  float_Speed_0->Default = 0.000000f; float_Speed_0->RightStep = 0.125000f;
  sFloatControl *float_Speed_1 = gh.Float(&para->Speed.y,-1024.00f,1024.000f,0.000100f);
  float_Speed_1->Default = 0.000000f; float_Speed_1->RightStep = 0.125000f;
  sFloatControl *float_Speed_2 = gh.Float(&para->Speed.z,-1024.00f,1024.000f,0.000100f);
  float_Speed_2->Default = 0.000000f; float_Speed_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"center force");

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-1024.00f,1024.000f,0.001000f);
  float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-1024.00f,1024.000f,0.001000f);
  float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
  sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-1024.00f,1024.000f,0.001000f);
  float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,0.000000f,1024.000f,0.001000f);
  float_Radius->Default = 0.000000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Force");
  sFloatControl *float_Force = gh.Float(&para->Force,-1024.00f,1024.000f,0.001000f);
  float_Force->Default = 0.000000f; float_Force->RightStep = 0.125000f;
}

void SphCollisionDefSphShock(wOp *op)
{
  SphCollisionParaSphShock sUNUSED *para = (SphCollisionParaSphShock *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void SphCollisionBindSphShock(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"time"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"speed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"force"),val);
}
void SphCollisionBind2SphShock(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"time");
    name[1] = sPoolString(L"");
    name[2] = sPoolString(L"flags");
    name[3] = sPoolString(L"speed");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"center");
    name[6] = sPoolString(L"radius");
    name[7] = sPoolString(L"force");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+8);
}
void SphCollisionBind3SphShock(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import time : int;\n");
  tb.PrintF(L"  import speed : float[3];\n");
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import radius : float;\n");
  tb.PrintF(L"  import force : float;\n");
}
const sChar *SphCollisionWikiSphShock =
L"= SphCollision : SphShock\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphShock\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphCollision\n"
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
L" !i Time\n"
L" !i Time\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Flags\n"
L" !i always on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Speed\n"
L" !i Speed\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Force\n"
L" !i Force\n"
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

void Wz4ParticlesAnimSphSimulator::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimSphSimulator::Bind(class ScriptContext *sc,Wz4ParticlesParaSphSimulator *para)
{
};

void SphGeneratorAnimSphObject::Init(class ScriptContext *sc)
{
};

void SphGeneratorAnimSphObject::Bind(class ScriptContext *sc,SphGeneratorParaSphObject *para)
{
};

void SphGeneratorAnimSphSource::Init(class ScriptContext *sc)
{
};

void SphGeneratorAnimSphSource::Bind(class ScriptContext *sc,SphGeneratorParaSphSource *para)
{
};

void SphCollisionAnimSphSimpleColl::Init(class ScriptContext *sc)
{
};

void SphCollisionAnimSphSimpleColl::Bind(class ScriptContext *sc,SphCollisionParaSphSimpleColl *para)
{
};

void SphCollisionAnimSphPlaneColl::Init(class ScriptContext *sc)
{
};

void SphCollisionAnimSphPlaneColl::Bind(class ScriptContext *sc,SphCollisionParaSphPlaneColl *para)
{
};

void SphCollisionAnimSphShock::Init(class ScriptContext *sc)
{
};

void SphCollisionAnimSphShock::Bind(class ScriptContext *sc,SphCollisionParaSphShock *para)
{
};


/****************************************************************************/

void AddTypes_fr063_sph_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(SphGeneratorType = new SphGeneratorType_);
  SphGeneratorType->Secondary = secondary;
  SphGeneratorType->ColumnHeaders[0] = L"system";
  SphGeneratorType->ColumnHeaders[1] = L"generators";
  SphGeneratorType->ColumnHeaders[2] = L"collision";

  Doc->Types.AddTail(SphCollisionType = new SphCollisionType_);
  SphCollisionType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_fr063_sph_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"SphSimulator";
  cl->Label = L"SphSimulator";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = SphGeneratorType;
  cl->Command = Wz4ParticlesCmdSphSimulator;
  cl->MakeGui = Wz4ParticlesGuiSphSimulator;
  cl->SetDefaults = Wz4ParticlesDefSphSimulator;
  cl->BindPara = Wz4ParticlesBindSphSimulator;
  cl->Bind2Para = Wz4ParticlesBind2SphSimulator;
  cl->Bind3Para = Wz4ParticlesBind3SphSimulator;
  cl->WikiText = Wz4ParticlesWikiSphSimulator;
  cl->Actions = Wz4ParticlesActSphSimulator;
  cl->ParaStrings = 1;
  cl->ParaWords = 21;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = AnyTypeType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"Restart",1);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphObject";
  cl->Label = L"SphObject";
  cl->OutputType = SphGeneratorType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphGeneratorCmdSphObject;
  cl->MakeGui = SphGeneratorGuiSphObject;
  cl->SetDefaults = SphGeneratorDefSphObject;
  cl->BindPara = SphGeneratorBindSphObject;
  cl->Bind2Para = SphGeneratorBind2SphObject;
  cl->Bind3Para = SphGeneratorBind3SphObject;
  cl->WikiText = SphGeneratorWikiSphObject;
  cl->ParaWords = 14;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphSource";
  cl->Label = L"SphSource";
  cl->OutputType = SphGeneratorType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphGeneratorCmdSphSource;
  cl->MakeGui = SphGeneratorGuiSphSource;
  cl->SetDefaults = SphGeneratorDefSphSource;
  cl->BindPara = SphGeneratorBindSphSource;
  cl->Bind2Para = SphGeneratorBind2SphSource;
  cl->Bind3Para = SphGeneratorBind3SphSource;
  cl->WikiText = SphGeneratorWikiSphSource;
  cl->ParaWords = 13;
  cl->Column = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphSimpleColl";
  cl->Label = L"SphSimpleColl";
  cl->OutputType = SphCollisionType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphCollisionCmdSphSimpleColl;
  cl->MakeGui = SphCollisionGuiSphSimpleColl;
  cl->SetDefaults = SphCollisionDefSphSimpleColl;
  cl->BindPara = SphCollisionBindSphSimpleColl;
  cl->Bind2Para = SphCollisionBind2SphSimpleColl;
  cl->Bind3Para = SphCollisionBind3SphSimpleColl;
  cl->WikiText = SphCollisionWikiSphSimpleColl;
  cl->ParaWords = 10;
  cl->Column = 2;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphPlaneColl";
  cl->Label = L"SphPlaneColl";
  cl->OutputType = SphCollisionType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphCollisionCmdSphPlaneColl;
  cl->MakeGui = SphCollisionGuiSphPlaneColl;
  cl->SetDefaults = SphCollisionDefSphPlaneColl;
  cl->BindPara = SphCollisionBindSphPlaneColl;
  cl->Bind2Para = SphCollisionBind2SphPlaneColl;
  cl->Bind3Para = SphCollisionBind3SphPlaneColl;
  cl->WikiText = SphCollisionWikiSphPlaneColl;
  cl->ParaWords = 4;
  cl->Column = 2;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphShock";
  cl->Label = L"SphShock";
  cl->OutputType = SphCollisionType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphCollisionCmdSphShock;
  cl->MakeGui = SphCollisionGuiSphShock;
  cl->SetDefaults = SphCollisionDefSphShock;
  cl->BindPara = SphCollisionBindSphShock;
  cl->Bind2Para = SphCollisionBind2SphShock;
  cl->Bind3Para = SphCollisionBind3SphShock;
  cl->WikiText = SphCollisionWikiSphShock;
  cl->ParaWords = 10;
  cl->Column = 2;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fr063_sph_ops,0x110,AddOps_fr063_sph_ops,0);


/****************************************************************************/


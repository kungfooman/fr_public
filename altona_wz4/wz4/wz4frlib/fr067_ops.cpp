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
#include "fr067_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 13 "fr067_ops.ops"

#include "wz4frlib/fr067.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 

#line 30 "fr067_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdFR067_IsoSplash(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR067_IsoSplash sUNUSED *para = (Wz4RenderParaFR067_IsoSplash *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Mtrl sUNUSED *in2 = cmd->GetInput<Wz4Mtrl *>(2); in2;
  Wz4Mtrl sUNUSED *in3 = cmd->GetInput<Wz4Mtrl *>(3); in3;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 69 "fr067_ops.ops"

    RNFR067_IsoSplash *node = new RNFR067_IsoSplash();
    node->ParaBase = node->Para = *para;
    node->Mtrl[0] = in0; in0->AddRef();
    node->Mtrl[1] = in1; if(in1) in1->AddRef();
    node->Mtrl[2] = in2; if(in2) in2->AddRef();
    node->Mtrl[3] = in3; if(in3) in3->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 60 "fr067_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFR067_IsoSplash(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR067_IsoSplash sUNUSED *para = (Wz4RenderParaFR067_IsoSplash *)(op->EditData); para;

  gh.Group(L"Render");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Multithreading");
  gh.Flags(&para->Multithreading,L"-|limited",gh.ChangeMsg);

  gh.Group(L"para");

  gh.Label(L"* IsoValue");
  sFloatControl *float_IsoValue = gh.Float(&para->IsoValue,0.000000f,16.00000f,0.010000f);
  float_IsoValue->Default = 0.500000f; float_IsoValue->RightStep = 0.125000f;

  gh.Label(L"OctreeDivisions");
  gh.Flags(&para->OctreeDivisions,L" 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

  gh.Label(L"GridSize");
  sFloatControl *float_GridSize = gh.Float(&para->GridSize,0.000000f,16.00000f,0.125000f);
  float_GridSize->Default = 4.000000f; float_GridSize->RightStep = 0.125000f;

  gh.Group(L"shape");

  gh.Label(L"* SphereAmp");
  sFloatControl *float_SphereAmp = gh.Float(&para->SphereAmp,-256.000f,256.0000f,0.020000f);
  float_SphereAmp->Default = 0.000000f; float_SphereAmp->RightStep = 0.125000f;

  gh.Label(L"* SphereDirections");
  gh.BeginTied();
  sFloatControl *float_SphereDirections_0 = gh.Float(&para->SphereDirections.x,0.125000f,8.000000f,0.020000f);
  float_SphereDirections_0->Default = 1.000000f; float_SphereDirections_0->RightStep = 0.125000f;
  sFloatControl *float_SphereDirections_1 = gh.Float(&para->SphereDirections.y,0.125000f,8.000000f,0.020000f);
  float_SphereDirections_1->Default = 1.000000f; float_SphereDirections_1->RightStep = 0.125000f;
  sFloatControl *float_SphereDirections_2 = gh.Float(&para->SphereDirections.z,0.125000f,8.000000f,0.020000f);
  float_SphereDirections_2->Default = 1.000000f; float_SphereDirections_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* CubeAmp");
  sFloatControl *float_CubeAmp = gh.Float(&para->CubeAmp,-256.000f,256.0000f,0.020000f);
  float_CubeAmp->Default = 0.000000f; float_CubeAmp->RightStep = 0.125000f;

  gh.Label(L"* CubeDirections");
  gh.BeginTied();
  sFloatControl *float_CubeDirections_0 = gh.Float(&para->CubeDirections.x,0.125000f,8.000000f,0.020000f);
  float_CubeDirections_0->Default = 1.000000f; float_CubeDirections_0->RightStep = 0.125000f;
  sFloatControl *float_CubeDirections_1 = gh.Float(&para->CubeDirections.y,0.125000f,8.000000f,0.020000f);
  float_CubeDirections_1->Default = 1.000000f; float_CubeDirections_1->RightStep = 0.125000f;
  sFloatControl *float_CubeDirections_2 = gh.Float(&para->CubeDirections.z,0.125000f,8.000000f,0.020000f);
  float_CubeDirections_2->Default = 1.000000f; float_CubeDirections_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NoiseAmp1");
  sFloatControl *float_NoiseAmp1 = gh.Float(&para->NoiseAmp1,-1024.00f,1024.000f,0.020000f);
  float_NoiseAmp1->Default = 0.000000f; float_NoiseAmp1->RightStep = 0.125000f;

  gh.Label(L"* NoiseFreq1");
  gh.BeginTied();
  sFloatControl *float_NoiseFreq1_0 = gh.Float(&para->NoiseFreq1.x,0.000000f,1024.000f,0.020000f);
  float_NoiseFreq1_0->Default = 1.000000f; float_NoiseFreq1_0->RightStep = 0.125000f;
  sFloatControl *float_NoiseFreq1_1 = gh.Float(&para->NoiseFreq1.y,0.000000f,1024.000f,0.020000f);
  float_NoiseFreq1_1->Default = 1.000000f; float_NoiseFreq1_1->RightStep = 0.125000f;
  sFloatControl *float_NoiseFreq1_2 = gh.Float(&para->NoiseFreq1.z,0.000000f,1024.000f,0.020000f);
  float_NoiseFreq1_2->Default = 1.000000f; float_NoiseFreq1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NoisePhase1");
  gh.BeginTied();
  sFloatControl *float_NoisePhase1_0 = gh.Float(&para->NoisePhase1.x,-1024.00f,1024.000f,0.020000f);
  float_NoisePhase1_0->Default = 0.000000f; float_NoisePhase1_0->RightStep = 0.125000f;
  sFloatControl *float_NoisePhase1_1 = gh.Float(&para->NoisePhase1.y,-1024.00f,1024.000f,0.020000f);
  float_NoisePhase1_1->Default = 0.000000f; float_NoisePhase1_1->RightStep = 0.125000f;
  sFloatControl *float_NoisePhase1_2 = gh.Float(&para->NoisePhase1.z,-1024.00f,1024.000f,0.020000f);
  float_NoisePhase1_2->Default = 0.000000f; float_NoisePhase1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NoiseSeed1");
  sIntControl *int_NoiseSeed1 = gh.Int(&para->NoiseSeed1,0,255,0.125000f);
  int_NoiseSeed1->Default = 0x00000000; int_NoiseSeed1->RightStep = 0.125000f;

  gh.Group(L"rubber");

  gh.Label(L"* Rot");
  gh.BeginTied();
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rubber");
  gh.BeginTied();
  sFloatControl *float_Rubber_0 = gh.Float(&para->Rubber.x,-16.0000f,16.00000f,0.001000f);
  float_Rubber_0->Default = 0.000000f; float_Rubber_0->RightStep = 0.125000f;
  sFloatControl *float_Rubber_1 = gh.Float(&para->Rubber.y,-16.0000f,16.00000f,0.001000f);
  float_Rubber_1->Default = 0.000000f; float_Rubber_1->RightStep = 0.125000f;
  sFloatControl *float_Rubber_2 = gh.Float(&para->Rubber.z,-16.0000f,16.00000f,0.001000f);
  float_Rubber_2->Default = 0.000000f; float_Rubber_2->RightStep = 0.125000f;
  gh.EndTied();

  if(0x0000)
  {
    gh.Label(L"RubberToNoise");
    gh.Flags(&para->RubberToNoise,L"off|on",gh.ChangeMsg);

  }
  gh.Label(L"* QuickOutSaveGuard");
  sFloatControl *float_QuickOutSaveGuard = gh.Float(&para->QuickOutSaveGuard,0.000000f,16.00000f,0.010000f);
  float_QuickOutSaveGuard->Default = 0.000000f; float_QuickOutSaveGuard->RightStep = 0.125000f;

  gh.Group(L"misc");

  gh.Label(L"* PolarAmp");
  sFloatControl *float_PolarAmp = gh.Float(&para->PolarAmp,-256.000f,256.0000f,0.020000f);
  float_PolarAmp->Default = 0.000000f; float_PolarAmp->RightStep = 0.125000f;

  gh.Label(L"* PolarCenter");
  sFloatControl *float_PolarCenter = gh.Float(&para->PolarCenter,-256.000f,256.0000f,0.020000f);
  float_PolarCenter->Default = 0.000000f; float_PolarCenter->RightStep = 0.125000f;

  gh.Label(L"* PolarY");
  sFloatControl *float_PolarY = gh.Float(&para->PolarY,-256.000f,256.0000f,0.020000f);
  float_PolarY->Default = 0.000000f; float_PolarY->RightStep = 0.125000f;

  gh.Label(L"* PolarXZ");
  sFloatControl *float_PolarXZ = gh.Float(&para->PolarXZ,-256.000f,256.0000f,0.020000f);
  float_PolarXZ->Default = 0.000000f; float_PolarXZ->RightStep = 0.125000f;

  gh.Label(L"* PolarCenterAmount");
  sFloatControl *float_PolarCenterAmount = gh.Float(&para->PolarCenterAmount,-256.000f,256.0000f,0.020000f);
  float_PolarCenterAmount->Default = 0.000000f; float_PolarCenterAmount->RightStep = 0.125000f;

  gh.Label(L"* Shells (per material)");
  gh.BeginTied();
  sIntControl *int_Shells_0 = gh.Int(&para->Shells[0],1,256,0.125000f);
  int_Shells_0->Default = 0x00000001; int_Shells_0->RightStep = 0.125000f;
  sIntControl *int_Shells_1 = gh.Int(&para->Shells[1],1,256,0.125000f);
  int_Shells_1->Default = 0x00000001; int_Shells_1->RightStep = 0.125000f;
  sIntControl *int_Shells_2 = gh.Int(&para->Shells[2],1,256,0.125000f);
  int_Shells_2->Default = 0x00000001; int_Shells_2->RightStep = 0.125000f;
  sIntControl *int_Shells_3 = gh.Int(&para->Shells[3],1,256,0.125000f);
  int_Shells_3->Default = 0x00000001; int_Shells_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NoiseAmp2");
  sFloatControl *float_NoiseAmp2 = gh.Float(&para->NoiseAmp2,-1024.00f,1024.000f,0.020000f);
  float_NoiseAmp2->Default = 0.000000f; float_NoiseAmp2->RightStep = 0.125000f;

  gh.Label(L"* NoiseFreq2");
  gh.BeginTied();
  sFloatControl *float_NoiseFreq2_0 = gh.Float(&para->NoiseFreq2.x,0.000000f,1024.000f,0.020000f);
  float_NoiseFreq2_0->Default = 1.000000f; float_NoiseFreq2_0->RightStep = 0.125000f;
  sFloatControl *float_NoiseFreq2_1 = gh.Float(&para->NoiseFreq2.y,0.000000f,1024.000f,0.020000f);
  float_NoiseFreq2_1->Default = 1.000000f; float_NoiseFreq2_1->RightStep = 0.125000f;
  sFloatControl *float_NoiseFreq2_2 = gh.Float(&para->NoiseFreq2.z,0.000000f,1024.000f,0.020000f);
  float_NoiseFreq2_2->Default = 1.000000f; float_NoiseFreq2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NoisePhase2");
  gh.BeginTied();
  sFloatControl *float_NoisePhase2_0 = gh.Float(&para->NoisePhase2.x,-1024.00f,1024.000f,0.020000f);
  float_NoisePhase2_0->Default = 0.000000f; float_NoisePhase2_0->RightStep = 0.125000f;
  sFloatControl *float_NoisePhase2_1 = gh.Float(&para->NoisePhase2.y,-1024.00f,1024.000f,0.020000f);
  float_NoisePhase2_1->Default = 0.000000f; float_NoisePhase2_1->RightStep = 0.125000f;
  sFloatControl *float_NoisePhase2_2 = gh.Float(&para->NoisePhase2.z,-1024.00f,1024.000f,0.020000f);
  float_NoisePhase2_2->Default = 0.000000f; float_NoisePhase2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* NoiseSeed2");
  sIntControl *int_NoiseSeed2 = gh.Int(&para->NoiseSeed2,0,255,0.125000f);
  int_NoiseSeed2->Default = 0x00000000; int_NoiseSeed2->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFR067_IsoSplash(wOp *op)
{
  Wz4RenderParaFR067_IsoSplash sUNUSED *para = (Wz4RenderParaFR067_IsoSplash *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->IsoValue = 0.500000f;
  para->OctreeDivisions = 0x00000002;
  para->GridSize = 4.000000f;
  para->SphereDirections.x = 1.000000f;
  para->SphereDirections.y = 1.000000f;
  para->SphereDirections.z = 1.000000f;
  para->CubeDirections.x = 1.000000f;
  para->CubeDirections.y = 1.000000f;
  para->CubeDirections.z = 1.000000f;
  para->NoiseFreq1.x = 1.000000f;
  para->NoiseFreq1.y = 1.000000f;
  para->NoiseFreq1.z = 1.000000f;
  para->RubberToNoise = 0x00000001;
  para->Shells[0] = 0x00000001;
  para->Shells[1] = 0x00000001;
  para->Shells[2] = 0x00000001;
  para->Shells[3] = 0x00000001;
  para->NoiseFreq2.x = 1.000000f;
  para->NoiseFreq2.y = 1.000000f;
  para->NoiseFreq2.z = 1.000000f;
}

void Wz4RenderBindFR067_IsoSplash(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"isovalue"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"gridsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"sphereamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"spheredirections"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"spheredirections"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"spheredirections"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"cubeamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"cubedirections"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"cubedirections"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"cubedirections"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"noiseamp1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"noisefreq1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"noisefreq1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"noisefreq1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"noisephase1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"noisephase1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"noisephase1"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"noiseseed1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"rubber"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"rubber"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"rubber"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"quickoutsaveguard"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"polaramp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"polarcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"polary"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"polarxz"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"polarcenteramount"),val);
  val = ctx->MakeValue(ScriptTypeInt,4);
  val->IntPtr = ((sInt *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"shells"),val);
  val = ctx->MakeValue(ScriptTypeInt,4);
  val->IntPtr = ((sInt *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"shells"),val);
  val = ctx->MakeValue(ScriptTypeInt,4);
  val->IntPtr = ((sInt *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"shells"),val);
  val = ctx->MakeValue(ScriptTypeInt,4);
  val->IntPtr = ((sInt *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"shells"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"noiseamp2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"noisefreq2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"noisefreq2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"noisefreq2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+43;
  ctx->BindLocal(ctx->AddSymbol(L"noisephase2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+43;
  ctx->BindLocal(ctx->AddSymbol(L"noisephase2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+43;
  ctx->BindLocal(ctx->AddSymbol(L"noisephase2"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+46;
  ctx->BindLocal(ctx->AddSymbol(L"noiseseed2"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR067_IsoSplash(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[35];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"render");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"renderpass");
    name[3] = sPoolString(L"multithreading");
    name[4] = sPoolString(L"para");
    name[5] = sPoolString(L"isovalue");
    name[6] = sPoolString(L"octreedivisions");
    name[7] = sPoolString(L"gridsize");
    name[8] = sPoolString(L"shape");
    name[9] = sPoolString(L"sphereamp");
    name[10] = sPoolString(L"spheredirections");
    name[11] = sPoolString(L"cubeamp");
    name[12] = sPoolString(L"cubedirections");
    name[13] = sPoolString(L"noiseamp1");
    name[14] = sPoolString(L"noisefreq1");
    name[15] = sPoolString(L"noisephase1");
    name[16] = sPoolString(L"noiseseed1");
    name[17] = sPoolString(L"rubber");
    name[18] = sPoolString(L"rot");
    name[19] = sPoolString(L"rubber");
    name[20] = sPoolString(L"rubbertonoise");
    name[21] = sPoolString(L"quickoutsaveguard");
    name[22] = sPoolString(L"misc");
    name[23] = sPoolString(L"polaramp");
    name[24] = sPoolString(L"polarcenter");
    name[25] = sPoolString(L"polary");
    name[26] = sPoolString(L"polarxz");
    name[27] = sPoolString(L"polarcenteramount");
    name[28] = sPoolString(L"shells");
    name[29] = sPoolString(L"noiseamp2");
    name[30] = sPoolString(L"noisefreq2");
    name[31] = sPoolString(L"noisephase2");
    name[32] = sPoolString(L"noiseseed2");
    name[33] = sPoolString(L"");
    name[34] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[12],ScriptTypeFloat,3,cmd->Data+11);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[14],ScriptTypeFloat,3,cmd->Data+15);
  ctx->AddImport(name[15],ScriptTypeFloat,3,cmd->Data+18);
  ctx->AddImport(name[16],ScriptTypeInt,1,cmd->Data+21);
  ctx->AddImport(name[18],ScriptTypeFloat,3,cmd->Data+22);
  ctx->AddImport(name[19],ScriptTypeFloat,3,cmd->Data+25);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+30);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+31);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+32);
  ctx->AddImport(name[26],ScriptTypeFloat,1,cmd->Data+33);
  ctx->AddImport(name[27],ScriptTypeFloat,1,cmd->Data+34);
  ctx->AddImport(name[28],ScriptTypeInt,4,cmd->Data+35);
  ctx->AddImport(name[29],ScriptTypeFloat,1,cmd->Data+39);
  ctx->AddImport(name[30],ScriptTypeFloat,3,cmd->Data+40);
  ctx->AddImport(name[31],ScriptTypeFloat,3,cmd->Data+43);
  ctx->AddImport(name[32],ScriptTypeInt,1,cmd->Data+46);
  ctx->AddImport(name[34],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR067_IsoSplash(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import isovalue : float;\n");
  tb.PrintF(L"  import gridsize : float;\n");
  tb.PrintF(L"  import sphereamp : float;\n");
  tb.PrintF(L"  import spheredirections : float[3];\n");
  tb.PrintF(L"  import cubeamp : float;\n");
  tb.PrintF(L"  import cubedirections : float[3];\n");
  tb.PrintF(L"  import noiseamp1 : float;\n");
  tb.PrintF(L"  import noisefreq1 : float[3];\n");
  tb.PrintF(L"  import noisephase1 : float[3];\n");
  tb.PrintF(L"  import noiseseed1 : int;\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import rubber : float[3];\n");
  tb.PrintF(L"  import quickoutsaveguard : float;\n");
  tb.PrintF(L"  import polaramp : float;\n");
  tb.PrintF(L"  import polarcenter : float;\n");
  tb.PrintF(L"  import polary : float;\n");
  tb.PrintF(L"  import polarxz : float;\n");
  tb.PrintF(L"  import polarcenteramount : float;\n");
  tb.PrintF(L"  import shells : int[4];\n");
  tb.PrintF(L"  import noiseamp2 : float;\n");
  tb.PrintF(L"  import noisefreq2 : float[3];\n");
  tb.PrintF(L"  import noisephase2 : float[3];\n");
  tb.PrintF(L"  import noiseseed2 : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR067_IsoSplash =
L"= Wz4Render : FR067_IsoSplash\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR067_IsoSplash\n"
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
L" !i Wz4Mtrl\n"
L" !i optional\n"
L" !i *\n"
L"\n"
L" !i Wz4Mtrl\n"
L" !i optional\n"
L" !i *\n"
L"\n"
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
L" !i limited\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i IsoValue\n"
L" !i IsoValue\n"
L" !i float\n"
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
L" !i GridSize\n"
L" !i GridSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SphereAmp\n"
L" !i SphereAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SphereDirections\n"
L" !i SphereDirections\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i CubeAmp\n"
L" !i CubeAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeDirections\n"
L" !i CubeDirections\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i NoiseAmp1\n"
L" !i NoiseAmp1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i NoiseFreq1\n"
L" !i NoiseFreq1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i NoisePhase1\n"
L" !i NoisePhase1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i NoiseSeed1\n"
L" !i NoiseSeed1\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rubber\n"
L" !i Rubber\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i RubberToNoise\n"
L" !i RubberToNoise\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i QuickOutSaveGuard\n"
L" !i QuickOutSaveGuard\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i PolarAmp\n"
L" !i PolarAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i PolarCenter\n"
L" !i PolarCenter\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i PolarY\n"
L" !i PolarY\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i PolarXZ\n"
L" !i PolarXZ\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i PolarCenterAmount\n"
L" !i PolarCenterAmount\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Shells (per material)\n"
L" !i Shells\n"
L" !i int[4]\n"
L" !i *\n"
L"\n"
L" !i NoiseAmp2\n"
L" !i NoiseAmp2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i NoiseFreq2\n"
L" !i NoiseFreq2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i NoisePhase2\n"
L" !i NoisePhase2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i NoiseSeed2\n"
L" !i NoiseSeed2\n"
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

void Wz4RenderAnimFR067_IsoSplash::Init(class ScriptContext *sc)
{
  _IsoValue = sc->AddSymbol(L"isovalue");
  _SphereAmp = sc->AddSymbol(L"sphereamp");
  _SphereDirections = sc->AddSymbol(L"spheredirections");
  _CubeAmp = sc->AddSymbol(L"cubeamp");
  _CubeDirections = sc->AddSymbol(L"cubedirections");
  _NoiseAmp1 = sc->AddSymbol(L"noiseamp1");
  _NoiseFreq1 = sc->AddSymbol(L"noisefreq1");
  _NoisePhase1 = sc->AddSymbol(L"noisephase1");
  _NoiseSeed1 = sc->AddSymbol(L"noiseseed1");
  _Rot = sc->AddSymbol(L"rot");
  _Rubber = sc->AddSymbol(L"rubber");
  _QuickOutSaveGuard = sc->AddSymbol(L"quickoutsaveguard");
  _PolarAmp = sc->AddSymbol(L"polaramp");
  _PolarCenter = sc->AddSymbol(L"polarcenter");
  _PolarY = sc->AddSymbol(L"polary");
  _PolarXZ = sc->AddSymbol(L"polarxz");
  _PolarCenterAmount = sc->AddSymbol(L"polarcenteramount");
  _Shells = sc->AddSymbol(L"shells");
  _NoiseAmp2 = sc->AddSymbol(L"noiseamp2");
  _NoiseFreq2 = sc->AddSymbol(L"noisefreq2");
  _NoisePhase2 = sc->AddSymbol(L"noisephase2");
  _NoiseSeed2 = sc->AddSymbol(L"noiseseed2");
};

void Wz4RenderAnimFR067_IsoSplash::Bind(class ScriptContext *sc,Wz4RenderParaFR067_IsoSplash *para)
{
  sc->BindLocalFloat(_IsoValue,1,&para->IsoValue);
  sc->BindLocalFloat(_SphereAmp,1,&para->SphereAmp);
  sc->BindLocalFloat(_SphereDirections,3,&para->SphereDirections.x);
  sc->BindLocalFloat(_CubeAmp,1,&para->CubeAmp);
  sc->BindLocalFloat(_CubeDirections,3,&para->CubeDirections.x);
  sc->BindLocalFloat(_NoiseAmp1,1,&para->NoiseAmp1);
  sc->BindLocalFloat(_NoiseFreq1,3,&para->NoiseFreq1.x);
  sc->BindLocalFloat(_NoisePhase1,3,&para->NoisePhase1.x);
  sc->BindLocalInt(_NoiseSeed1,1,&para->NoiseSeed1);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Rubber,3,&para->Rubber.x);
  sc->BindLocalFloat(_QuickOutSaveGuard,1,&para->QuickOutSaveGuard);
  sc->BindLocalFloat(_PolarAmp,1,&para->PolarAmp);
  sc->BindLocalFloat(_PolarCenter,1,&para->PolarCenter);
  sc->BindLocalFloat(_PolarY,1,&para->PolarY);
  sc->BindLocalFloat(_PolarXZ,1,&para->PolarXZ);
  sc->BindLocalFloat(_PolarCenterAmount,1,&para->PolarCenterAmount);
  sc->BindLocalInt(_Shells,4,para->Shells);
  sc->BindLocalFloat(_NoiseAmp2,1,&para->NoiseAmp2);
  sc->BindLocalFloat(_NoiseFreq2,3,&para->NoiseFreq2.x);
  sc->BindLocalFloat(_NoisePhase2,3,&para->NoisePhase2.x);
  sc->BindLocalInt(_NoiseSeed2,1,&para->NoiseSeed2);
};


/****************************************************************************/

void AddTypes_fr067_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_fr067_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"FR067_IsoSplash";
  cl->Label = L"FR067_IsoSplash";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR067_IsoSplash;
  cl->MakeGui = Wz4RenderGuiFR067_IsoSplash;
  cl->SetDefaults = Wz4RenderDefFR067_IsoSplash;
  cl->BindPara = Wz4RenderBindFR067_IsoSplash;
  cl->Bind2Para = Wz4RenderBind2FR067_IsoSplash;
  cl->Bind3Para = Wz4RenderBind3FR067_IsoSplash;
  cl->WikiText = Wz4RenderWikiFR067_IsoSplash;
  cl->ParaStrings = 1;
  cl->ParaWords = 47;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(4);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  in[2].Type = Wz4MtrlType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0|wCIF_OPTIONAL;
  in[3].Type = Wz4MtrlType;
  in[3].DefaultClass = 0;
  in[3].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fr067_ops,0x110,AddOps_fr067_ops,0);


/****************************************************************************/


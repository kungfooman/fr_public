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
#include "fr063_tron_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 14 "fr063_tron_ops.ops"

  #include "wz4frlib/adf.hpp"
  #include "wz4frlib/adf_ops.hpp"
  #include "wz4frlib/pdf_ops.hpp"
  #include "wz4frlib/pdf.hpp"  
  #include "fr063_tron_ops.hpp"
  #include "fr063_tron.hpp"
  #include "wz4_demo2_ops.hpp"  

#line 32 "fr063_tron_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdFR063_SpritesADF(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_SpritesADF sUNUSED *para = (Wz4RenderParaFR063_SpritesADF *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4ADF sUNUSED *in1 = cmd->GetInput<Wz4ADF *>(1); in1;
  Texture2D sUNUSED *in2 = cmd->GetInput<Texture2D *>(2); in2;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 92 "fr063_tron_ops.ops"

    RNFR063_Sprites *node = new RNFR063_Sprites();
    node->ParaBase = node->Para = *para;
    node->Source = in0->RootNode; node->Source->AddRef();
    node->SDF         = in1; in1->AddRef();
    node->TextureDiff = in2; in2->AddRef();
    node->Init();

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
    
    if (cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();    
    }    
  ;
#line 67 "fr063_tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndFR063_SpritesADF(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaFR063_SpritesADF sUNUSED *para = (Wz4RenderParaFR063_SpritesADF *)(op->EditData); para;
#line 110 "fr063_tron_ops.ops"
    
    pi.Handle3D(op,1,para->LightPos,wHM_PLANE);
  ;
#line 79 "fr063_tron_ops.cpp"
}

void Wz4RenderGuiFR063_SpritesADF(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_SpritesADF sUNUSED *para = (Wz4RenderParaFR063_SpritesADF *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-4096.00f,4096.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-4096.00f,4096.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-4096.00f,4096.000f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Size");
  sFloatControl *float_Size = gh.Float(&para->Size,0.000000f,4096.000f,0.010000f);
  float_Size->Default = 0.125000f; float_Size->RightStep = 0.125000f;

  gh.Label(L"* Aspect");
  sFloatControl *float_Aspect = gh.Float(&para->Aspect,-16.0000f,16.00000f,0.010000f);
  float_Aspect->Default = 0.000000f; float_Aspect->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*0add|premul alpha|mul|mul2|smooth|alpha (please use pm-alpha):*4zoff|zread|zwrite|zon:*8-|sort:*9atlas anim|atlas multi",gh.LayoutMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*11fade in out|-:*14-|scale by transform",gh.LayoutMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*16dest alpha from shader|dest alpha unchanged|dest alpha = 0|dest alpha blend",gh.LayoutMsg);

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
  sFloatControl *float_SizeRand = gh.Float(&para->SizeRand,0.000000f,10.00000f,0.010000f);
  float_SizeRand->Default = 0.000000f; float_SizeRand->RightStep = 0.125000f;

  gh.Group(L"Particle Size");

  gh.Label(L"GrowMode");
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
  gh.Group(L"Multiple");

  gh.Label(L"GroupCount");
  sIntControl *int_GroupCount = gh.Int(&para->GroupCount,1,256,0.125000f);
  int_GroupCount->Default = 0x00000001; int_GroupCount->RightStep = 0.125000f;

  if(!(para->Mode&0x0800))
  {
    gh.Group(L"Distance fading");

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
  gh.Group(L"SDF Para");

  gh.Label(L"* SDFFadeOffset");
  sFloatControl *float_SDFFadeOffset = gh.Float(&para->SDFFadeOffset,-256.000f,256.0000f,0.000100f);
  float_SDFFadeOffset->Default = 0.000000f; float_SDFFadeOffset->RightStep = 0.125000f;

  gh.Label(L"* SDFFadeMult");
  sFloatControl *float_SDFFadeMult = gh.Float(&para->SDFFadeMult,-256.000f,256.0000f,0.000100f);
  float_SDFFadeMult->Default = 1.000000f; float_SDFFadeMult->RightStep = 0.125000f;

  gh.Group(L"Light");

  gh.Label(L"* LightPos");
  gh.BeginTied();
  sFloatControl *float_LightPos_0 = gh.Float(&para->LightPos.x,-32767.0f,32767.00f,0.001000f);
  float_LightPos_0->Default = 0.000000f; float_LightPos_0->RightStep = 0.125000f;
  sFloatControl *float_LightPos_1 = gh.Float(&para->LightPos.y,-32767.0f,32767.00f,0.001000f);
  float_LightPos_1->Default = 0.000000f; float_LightPos_1->RightStep = 0.125000f;
  sFloatControl *float_LightPos_2 = gh.Float(&para->LightPos.z,-32767.0f,32767.00f,0.001000f);
  float_LightPos_2->Default = 0.000000f; float_LightPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* DiffusePower");
  sFloatControl *float_DiffusePower = gh.Float(&para->DiffusePower,0.000000f,  1000000,0.001000f);
  float_DiffusePower->Default = 1.000000f; float_DiffusePower->RightStep = 0.125000f;

  gh.Label(L"* SpecHardness");
  sFloatControl *float_SpecHardness = gh.Float(&para->SpecHardness,0.000000f,  1000000,0.001000f);
  float_SpecHardness->Default = 1.000000f; float_SpecHardness->RightStep = 0.125000f;

  gh.Label(L"* SpecPower");
  sFloatControl *float_SpecPower = gh.Float(&para->SpecPower,0.000000f,  1000000,0.001000f);
  float_SpecPower->Default = 1.000000f; float_SpecPower->RightStep = 0.125000f;

  gh.Label(L"* InAmbientColor");
  gh.ColorPick(&para->InAmbientColor,L"rgba",0);

  gh.Label(L"* InDiffuseColor");
  gh.ColorPick(&para->InDiffuseColor,L"rgba",0);

  gh.Label(L"* InSpecColor");
  gh.ColorPick(&para->InSpecColor,L"rgba",0);

  gh.Label(L"* OutAmbientColor");
  gh.ColorPick(&para->OutAmbientColor,L"rgba",0);

  gh.Label(L"* OutDiffuseColor");
  gh.ColorPick(&para->OutDiffuseColor,L"rgba",0);

  gh.Label(L"* OutSpecColor");
  gh.ColorPick(&para->OutSpecColor,L"rgba",0);

  gh.Label(L"DropMode");
  gh.Flags(&para->DropMode,L"none|out|in",gh.LayoutMsg);

  gh.Label(L"CollMode");
  gh.Flags(&para->CollMode,L"none|wrapping",gh.LayoutMsg);

  gh.Label(L"* WrapOffset");
  sFloatControl *float_WrapOffset = gh.Float(&para->WrapOffset,-32.0000f,32.00000f,0.000100f);
  float_WrapOffset->Default = 0.000000f; float_WrapOffset->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFR063_SpritesADF(wOp *op)
{
  Wz4RenderParaFR063_SpritesADF sUNUSED *para = (Wz4RenderParaFR063_SpritesADF *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0.125000f;
  para->TexAnimSpeed = 1.000000f;
  para->GroupCount = 0x00000001;
  para->NearFadeDistance = 1.000000f;
  para->FarFadeDistance = 1000.000f;
  para->FarFadeRange = 100.0000f;
  para->SDFFadeMult = 1.000000f;
  para->DiffusePower = 1.000000f;
  para->SpecHardness = 1.000000f;
  para->SpecPower = 1.000000f;
  para->InAmbientColor = 0xff001f00;
  para->InDiffuseColor = 0xff1f0000;
  para->InSpecColor = 0xffffffff;
  para->OutAmbientColor = 0xff00001f;
  para->OutDiffuseColor = 0xff1f0000;
  para->OutSpecColor = 0xffffffff;
}

void Wz4RenderBindFR063_SpritesADF(wCommand *cmd,ScriptContext *ctx)
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
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"rotspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotspread"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"sizerand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"fadein"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"fadeout"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"texanimspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"texanimrand"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"groupcount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"nearfadedistance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"farfadedistance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"farfaderange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"sdffadeoffset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"sdffademult"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"lightpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"lightpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"lightpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"diffusepower"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"spechardness"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"specpower"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"inambientcolor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"indiffusecolor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"inspeccolor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"outambientcolor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"outdiffusecolor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"outspeccolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"wrapoffset"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_SpritesADF(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[45];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"trans");
    name[1] = sPoolString(L"size");
    name[2] = sPoolString(L"aspect");
    name[3] = sPoolString(L"mode");
    name[4] = sPoolString(L"mode");
    name[5] = sPoolString(L"mode");
    name[6] = sPoolString(L"randomization");
    name[7] = sPoolString(L"rotstart");
    name[8] = sPoolString(L"rotspeed");
    name[9] = sPoolString(L"rotrand");
    name[10] = sPoolString(L"rotspread");
    name[11] = sPoolString(L"sizerand");
    name[12] = sPoolString(L"");
    name[13] = sPoolString(L"growmode");
    name[14] = sPoolString(L"fadein");
    name[15] = sPoolString(L"fadeout");
    name[16] = sPoolString(L"renderpass");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"texanimspeed");
    name[19] = sPoolString(L"texanimrand");
    name[20] = sPoolString(L"multiple");
    name[21] = sPoolString(L"groupcount");
    name[22] = sPoolString(L"");
    name[23] = sPoolString(L"nearfadedistance");
    name[24] = sPoolString(L"farfadedistance");
    name[25] = sPoolString(L"farfaderange");
    name[26] = sPoolString(L"");
    name[27] = sPoolString(L"sdffadeoffset");
    name[28] = sPoolString(L"sdffademult");
    name[29] = sPoolString(L"light");
    name[30] = sPoolString(L"lightpos");
    name[31] = sPoolString(L"diffusepower");
    name[32] = sPoolString(L"spechardness");
    name[33] = sPoolString(L"specpower");
    name[34] = sPoolString(L"inambientcolor");
    name[35] = sPoolString(L"indiffusecolor");
    name[36] = sPoolString(L"inspeccolor");
    name[37] = sPoolString(L"outambientcolor");
    name[38] = sPoolString(L"outdiffusecolor");
    name[39] = sPoolString(L"outspeccolor");
    name[40] = sPoolString(L"dropmode");
    name[41] = sPoolString(L"collmode");
    name[42] = sPoolString(L"wrapoffset");
    name[43] = sPoolString(L"");
    name[44] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[16],ScriptTypeInt,1,cmd->Data+15);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[21],ScriptTypeInt,1,cmd->Data+18);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[27],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[28],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[30],ScriptTypeFloat,3,cmd->Data+24);
  ctx->AddImport(name[31],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[32],ScriptTypeFloat,1,cmd->Data+28);
  ctx->AddImport(name[33],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[34],ScriptTypeColor,1,cmd->Data+30);
  ctx->AddImport(name[35],ScriptTypeColor,1,cmd->Data+31);
  ctx->AddImport(name[36],ScriptTypeColor,1,cmd->Data+32);
  ctx->AddImport(name[37],ScriptTypeColor,1,cmd->Data+33);
  ctx->AddImport(name[38],ScriptTypeColor,1,cmd->Data+34);
  ctx->AddImport(name[39],ScriptTypeColor,1,cmd->Data+35);
  ctx->AddImport(name[42],ScriptTypeFloat,1,cmd->Data+38);
  ctx->AddImport(name[44],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_SpritesADF(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import size : float;\n");
  tb.PrintF(L"  import aspect : float;\n");
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
  tb.PrintF(L"  import sdffadeoffset : float;\n");
  tb.PrintF(L"  import sdffademult : float;\n");
  tb.PrintF(L"  import lightpos : float[3];\n");
  tb.PrintF(L"  import diffusepower : float;\n");
  tb.PrintF(L"  import spechardness : float;\n");
  tb.PrintF(L"  import specpower : float;\n");
  tb.PrintF(L"  import inambientcolor : color;\n");
  tb.PrintF(L"  import indiffusecolor : color;\n");
  tb.PrintF(L"  import inspeccolor : color;\n");
  tb.PrintF(L"  import outambientcolor : color;\n");
  tb.PrintF(L"  import outdiffusecolor : color;\n");
  tb.PrintF(L"  import outspeccolor : color;\n");
  tb.PrintF(L"  import wrapoffset : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_SpritesADF =
L"= Wz4Render : FR063_SpritesADF\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_SpritesADF\n"
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
L" !i Wz4ADF\n"
L" !i\n"
L" !i *\n"
L"\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i atlas anim\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i atlas multi\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i fade in out\n"
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
L"!T 4 : 1 1 1 2\n"
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
L" !i GrowMode\n"
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
L" !i SDFFadeOffset\n"
L" !i SDFFadeOffset\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SDFFadeMult\n"
L" !i SDFFadeMult\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LightPos\n"
L" !i LightPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i DiffusePower\n"
L" !i DiffusePower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpecHardness\n"
L" !i SpecHardness\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpecPower\n"
L" !i SpecPower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i InAmbientColor\n"
L" !i InAmbientColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i InDiffuseColor\n"
L" !i InDiffuseColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i InSpecColor\n"
L" !i InSpecColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i OutAmbientColor\n"
L" !i OutAmbientColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i OutDiffuseColor\n"
L" !i OutDiffuseColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i OutSpecColor\n"
L" !i OutSpecColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i DropMode\n"
L" !i DropMode\n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i out\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i in\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CollMode\n"
L" !i CollMode\n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i wrapping\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i WrapOffset\n"
L" !i WrapOffset\n"
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

sBool Wz4RenderCmdFR063_ClothGridSimRender(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_ClothGridSimRender sUNUSED *para = (Wz4RenderParaFR063_ClothGridSimRender *)(cmd->Data); para;
  Wz4ADF sUNUSED *in0 = cmd->GetInput<Wz4ADF *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 162 "fr063_tron_ops.ops"

    RNFR063ClothGridSimRender *node = new RNFR063ClothGridSimRender();
    node->ParaBase = node->Para = *para;
    
    //node->DF = in0;  in0->AddRef();
    node->Mtrl = in1;  in1->AddRef();
    node->Array.Resize(cmd->ArrayCount);
    Wz4RenderArrayFR063_ClothGridSimRender *array= (Wz4RenderArrayFR063_ClothGridSimRender *)cmd->Array;
    for(sInt i=0;i<cmd->ArrayCount;i++)
    {
      node->Array[i].Para = array[i];      
    }
    node->Init(in0),in0->AddRef();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
    
    if (cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();    
    }
  ;
#line 892 "fr063_tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndFR063_ClothGridSimRender(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaFR063_ClothGridSimRender sUNUSED *para = (Wz4RenderParaFR063_ClothGridSimRender *)(op->EditData); para;
#line 185 "fr063_tron_ops.ops"

    RNFR063ClothGridSimRender::Handles(pi,para,op);    
  ;
#line 904 "fr063_tron_ops.cpp"
}

void Wz4RenderArrFR063_ClothGridSimRender(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaFR063_ClothGridSimRender sUNUSED *para = (Wz4RenderParaFR063_ClothGridSimRender *)(op->EditData); para;
  Wz4RenderArrayFR063_ClothGridSimRender *e = (Wz4RenderArrayFR063_ClothGridSimRender *)(mem);
  e->GridX = 0x00000000;
  e->GridY = 0x00000000;
  e->Type = 0x00000001;
  e->DragRadius = 0.000000f;
  e->SplineName = 0;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4RenderArrayFR063_ClothGridSimRender *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4RenderArrayFR063_ClothGridSimRender *)op->ArrayData[pos  ];
    }
    e->DragRadius = f0*p0->DragRadius + f1*p1->DragRadius;
  }
}

void Wz4RenderGuiFR063_ClothGridSimRender(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_ClothGridSimRender sUNUSED *para = (Wz4RenderParaFR063_ClothGridSimRender *)(op->EditData); para;

  gh.Group(L"Grid Creation");

  gh.Label(L"Pos");
  gh.BeginTied();
  sFloatControl *float_Pos_0 = gh.Float(&para->Pos.x,-1024.00f,1024.000f,0.001000f);
  float_Pos_0->Default = -0.750000f; float_Pos_0->RightStep = 0.125000f;
  sFloatControl *float_Pos_1 = gh.Float(&para->Pos.y,-1024.00f,1024.000f,0.001000f);
  float_Pos_1->Default = 1.000000f; float_Pos_1->RightStep = 0.125000f;
  sFloatControl *float_Pos_2 = gh.Float(&para->Pos.z,-1024.00f,1024.000f,0.001000f);
  float_Pos_2->Default = -0.750000f; float_Pos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"AX");
  gh.BeginTied();
  sFloatControl *float_AX_0 = gh.Float(&para->AX.x,-1024.00f,1024.000f,0.001000f);
  float_AX_0->Default = 0.100000f; float_AX_0->RightStep = 0.125000f;
  sFloatControl *float_AX_1 = gh.Float(&para->AX.y,-1024.00f,1024.000f,0.001000f);
  float_AX_1->Default = 0.000000f; float_AX_1->RightStep = 0.125000f;
  sFloatControl *float_AX_2 = gh.Float(&para->AX.z,-1024.00f,1024.000f,0.001000f);
  float_AX_2->Default = 0.000000f; float_AX_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"AY");
  gh.BeginTied();
  sFloatControl *float_AY_0 = gh.Float(&para->AY.x,-1024.00f,1024.000f,0.001000f);
  float_AY_0->Default = 0.000000f; float_AY_0->RightStep = 0.125000f;
  sFloatControl *float_AY_1 = gh.Float(&para->AY.y,-1024.00f,1024.000f,0.001000f);
  float_AY_1->Default = 0.000000f; float_AY_1->RightStep = 0.125000f;
  sFloatControl *float_AY_2 = gh.Float(&para->AY.z,-1024.00f,1024.000f,0.001000f);
  float_AY_2->Default = 0.100000f; float_AY_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"XC");
  sIntControl *int_XC = gh.Int(&para->XC,0,1024,1.000000f);
  int_XC->Default = 0x0000000f; int_XC->RightStep = 0.125000f;

  gh.Label(L"YC");
  sIntControl *int_YC = gh.Int(&para->YC,0,1024,1.000000f);
  int_YC->Default = 0x0000000f; int_YC->RightStep = 0.125000f;

  gh.Label(L"C1");
  sFloatControl *float_C1 = gh.Float(&para->C1,-16384.0f,16384.00f,0.001000f);
  float_C1->Default = 0.500000f; float_C1->RightStep = 0.125000f;

  gh.Label(L"C2");
  sFloatControl *float_C2 = gh.Float(&para->C2,-16384.0f,16384.00f,0.001000f);
  float_C2->Default = 0.500000f; float_C2->RightStep = 0.125000f;

  gh.Label(L"Mass");
  sFloatControl *float_Mass = gh.Float(&para->Mass,0.000000f,1.000000f,0.001000f);
  float_Mass->Default = 1.000000f; float_Mass->RightStep = 0.125000f;

  gh.Group(L"Simulation Parameter");

  gh.Label(L"Gravity");
  gh.BeginTied();
  sFloatControl *float_Gravity_0 = gh.Float(&para->Gravity.x,-1024.00f,1024.000f,0.001000f);
  float_Gravity_0->Default = 0.000000f; float_Gravity_0->RightStep = 0.125000f;
  sFloatControl *float_Gravity_1 = gh.Float(&para->Gravity.y,-1024.00f,1024.000f,0.001000f);
  float_Gravity_1->Default = -1.00000f; float_Gravity_1->RightStep = 0.125000f;
  sFloatControl *float_Gravity_2 = gh.Float(&para->Gravity.z,-1024.00f,1024.000f,0.001000f);
  float_Gravity_2->Default = 0.000000f; float_Gravity_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Force");
  gh.BeginTied();
  sFloatControl *float_Force_0 = gh.Float(&para->Force.x,-1024.00f,1024.000f,0.001000f);
  float_Force_0->Default = 0.000000f; float_Force_0->RightStep = 0.125000f;
  sFloatControl *float_Force_1 = gh.Float(&para->Force.y,-1024.00f,1024.000f,0.001000f);
  float_Force_1->Default = 0.000000f; float_Force_1->RightStep = 0.125000f;
  sFloatControl *float_Force_2 = gh.Float(&para->Force.z,-1024.00f,1024.000f,0.001000f);
  float_Force_2->Default = 0.000000f; float_Force_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Damping");
  sFloatControl *float_Damping = gh.Float(&para->Damping,0.000000f,1024.000f,0.001000f);
  float_Damping->Default = 0.200000f; float_Damping->RightStep = 0.125000f;

  gh.Label(L"CollisionGuard");
  sFloatControl *float_CollisionGuard = gh.Float(&para->CollisionGuard,0.000000f,10.00000f,0.001000f);
  float_CollisionGuard->Default = 0.300000f; float_CollisionGuard->RightStep = 0.125000f;

  gh.Label(L"SlideFactor");
  sFloatControl *float_SlideFactor = gh.Float(&para->SlideFactor,0.000000f,4.000000f,0.001000f);
  float_SlideFactor->Default = 0.000000f; float_SlideFactor->RightStep = 0.125000f;

  gh.Label(L"TimeScale");
  sFloatControl *float_TimeScale = gh.Float(&para->TimeScale,0.100000f,1024.000f,0.001000f);
  float_TimeScale->Default = 1.000000f; float_TimeScale->RightStep = 0.125000f;

  gh.Label(L"TimeOffset");
  sFloatControl *float_TimeOffset = gh.Float(&para->TimeOffset,0.000000f,1024.000f,0.100000f);
  float_TimeOffset->Default = 0.000000f; float_TimeOffset->RightStep = 0.125000f;

  gh.Group(L"Render Parameter");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"DebugDoSim");
  gh.Flags(&para->DebugDoSim,L"Off|On",gh.LayoutMsg);

  gh.Label(L"DebugUseMulticore");
  gh.Flags(&para->DebugUseMulticore,L"Off|On",gh.LayoutMsg);

  gh.Label(L"DebugSubdivide");
  gh.Flags(&para->DebugSubdivide,L"Off|On",gh.LayoutMsg);

  gh.Label(L"DebugFlipEdges");
  gh.Flags(&para->DebugFlipEdges,L"Off|On",gh.LayoutMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
  }
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"GridX",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"GridY",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Type",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"DragRadius",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"SplineName",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArrayFR063_ClothGridSimRender *elem = (Wz4RenderArrayFR063_ClothGridSimRender *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    sIntControl *int_GridX = gh.Int(&elem->GridX,0,1024,0.125000f);
    int_GridX->Default = 0x00000000; int_GridX->RightStep = 0.125000f;

    sIntControl *int_GridY = gh.Int(&elem->GridY,0,1024,0.125000f);
    int_GridY->Default = 0x00000000; int_GridY->RightStep = 0.125000f;

    gh.Flags(&elem->Type,L"Fixing-Total|Fixing-AfterInit|Release-AfterInit",gh.LayoutMsg);

    sFloatControl *float_DragRadius = gh.Float(&elem->DragRadius,0.000000f,256.0000f,0.000100f);
    float_DragRadius->Default = 0.000000f; float_DragRadius->RightStep = 0.125000f;

    gh.String(elem->SplineName);
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

void Wz4RenderDefFR063_ClothGridSimRender(wOp *op)
{
  Wz4RenderParaFR063_ClothGridSimRender sUNUSED *para = (Wz4RenderParaFR063_ClothGridSimRender *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Pos.x = -0.750000f;
  para->Pos.y = 1.000000f;
  para->Pos.z = -0.750000f;
  para->AX.x = 0.100000f;
  para->AY.z = 0.100000f;
  para->XC = 0x0000000f;
  para->YC = 0x0000000f;
  para->C1 = 0.500000f;
  para->C2 = 0.500000f;
  para->Mass = 1.000000f;
  para->Gravity.y = -1.00000f;
  para->Damping = 0.200000f;
  para->CollisionGuard = 0.300000f;
  para->TimeScale = 1.000000f;
  para->DebugDoSim = 0x00000001;
  para->DebugUseMulticore = 0x00000001;
}

void Wz4RenderBindFR063_ClothGridSimRender(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"ax"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"ax"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"ax"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"ay"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"ay"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"ay"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"xc"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"yc"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"c1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"c2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"mass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"force"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"force"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"force"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"damping"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"collisionguard"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"slidefactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"timescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"timeoffset"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_ClothGridSimRender(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[26];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"");
    name[1] = sPoolString(L"pos");
    name[2] = sPoolString(L"ax");
    name[3] = sPoolString(L"ay");
    name[4] = sPoolString(L"xc");
    name[5] = sPoolString(L"yc");
    name[6] = sPoolString(L"c1");
    name[7] = sPoolString(L"c2");
    name[8] = sPoolString(L"mass");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"gravity");
    name[11] = sPoolString(L"force");
    name[12] = sPoolString(L"damping");
    name[13] = sPoolString(L"collisionguard");
    name[14] = sPoolString(L"slidefactor");
    name[15] = sPoolString(L"timescale");
    name[16] = sPoolString(L"timeoffset");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"lightenv");
    name[19] = sPoolString(L"renderpass");
    name[20] = sPoolString(L"debugdosim");
    name[21] = sPoolString(L"debugusemulticore");
    name[22] = sPoolString(L"debugsubdivide");
    name[23] = sPoolString(L"debugflipedges");
    name[24] = sPoolString(L"");
    name[25] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+10);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+14);
  ctx->AddImport(name[11],ScriptTypeFloat,3,cmd->Data+17);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[18],ScriptTypeInt,1,cmd->Data+25);
  ctx->AddImport(name[19],ScriptTypeInt,1,cmd->Data+26);
  ctx->AddImport(name[25],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_ClothGridSimRender(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import pos : float[3];\n");
  tb.PrintF(L"  import ax : float[3];\n");
  tb.PrintF(L"  import ay : float[3];\n");
  tb.PrintF(L"  import xc : int;\n");
  tb.PrintF(L"  import yc : int;\n");
  tb.PrintF(L"  import c1 : float;\n");
  tb.PrintF(L"  import c2 : float;\n");
  tb.PrintF(L"  import mass : float;\n");
  tb.PrintF(L"  import gravity : float[3];\n");
  tb.PrintF(L"  import force : float[3];\n");
  tb.PrintF(L"  import damping : float;\n");
  tb.PrintF(L"  import collisionguard : float;\n");
  tb.PrintF(L"  import slidefactor : float;\n");
  tb.PrintF(L"  import timescale : float;\n");
  tb.PrintF(L"  import timeoffset : float;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_ClothGridSimRender =
L"= Wz4Render : FR063_ClothGridSimRender\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_ClothGridSimRender\n"
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
L" !i Wz4ADF\n"
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
L" !i Pos\n"
L" !i Pos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i AX\n"
L" !i AX\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i AY\n"
L" !i AY\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i XC\n"
L" !i XC\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i YC\n"
L" !i YC\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i C1\n"
L" !i C1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i C2\n"
L" !i C2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Mass\n"
L" !i Mass\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Force\n"
L" !i Force\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Damping\n"
L" !i Damping\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CollisionGuard\n"
L" !i CollisionGuard\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SlideFactor\n"
L" !i SlideFactor\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeScale\n"
L" !i TimeScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeOffset\n"
L" !i TimeOffset\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i DebugDoSim\n"
L" !i DebugDoSim\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugUseMulticore\n"
L" !i DebugUseMulticore\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugSubdivide\n"
L" !i DebugSubdivide\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugFlipEdges\n"
L" !i DebugFlipEdges\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
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
L" !i Pos\n"
L" !i Pos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i AX\n"
L" !i AX\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i AY\n"
L" !i AY\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i XC\n"
L" !i XC\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i YC\n"
L" !i YC\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i C1\n"
L" !i C1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i C2\n"
L" !i C2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Mass\n"
L" !i Mass\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Force\n"
L" !i Force\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Damping\n"
L" !i Damping\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CollisionGuard\n"
L" !i CollisionGuard\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SlideFactor\n"
L" !i SlideFactor\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeScale\n"
L" !i TimeScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeOffset\n"
L" !i TimeOffset\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i DebugDoSim\n"
L" !i DebugDoSim\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugUseMulticore\n"
L" !i DebugUseMulticore\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugSubdivide\n"
L" !i DebugSubdivide\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugFlipEdges\n"
L" !i DebugFlipEdges\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
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

sBool Wz4RenderCmdFR063_MassBallColl(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_MassBallColl sUNUSED *para = (Wz4RenderParaFR063_MassBallColl *)(cmd->Data); para;
  Wz4ADF sUNUSED *in0 = cmd->GetInput<Wz4ADF *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 232 "fr063_tron_ops.ops"

    RNFR063_MassBallColl *node = new RNFR063_MassBallColl();
    node->ParaBase = node->Para = *para;    
    node->SDF      = in0; in0->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 1644 "fr063_tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFR063_MassBallColl(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_MassBallColl sUNUSED *para = (Wz4RenderParaFR063_MassBallColl *)(op->EditData); para;

  gh.Group(L"Generation");

  gh.Label(L"NbOfBalls");
  sIntControl *int_NbOfBalls = gh.Int(&para->NbOfBalls,1,32767,0.125000f);
  int_NbOfBalls->Default = 0x00000100; int_NbOfBalls->RightStep = 0.125000f;

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Label(L"PosStart");
  gh.BeginTied();
  sFloatControl *float_PosStart_0 = gh.Float(&para->PosStart.x,-1024.00f,1024.000f,0.001000f);
  float_PosStart_0->Default = 0.000000f; float_PosStart_0->RightStep = 0.125000f;
  sFloatControl *float_PosStart_1 = gh.Float(&para->PosStart.y,-1024.00f,1024.000f,0.001000f);
  float_PosStart_1->Default = 0.000000f; float_PosStart_1->RightStep = 0.125000f;
  sFloatControl *float_PosStart_2 = gh.Float(&para->PosStart.z,-1024.00f,1024.000f,0.001000f);
  float_PosStart_2->Default = 0.000000f; float_PosStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"PosRand");
  gh.BeginTied();
  sFloatControl *float_PosRand_0 = gh.Float(&para->PosRand.x,0.000000f,1024.000f,0.001000f);
  float_PosRand_0->Default = 0.000000f; float_PosRand_0->RightStep = 0.125000f;
  sFloatControl *float_PosRand_1 = gh.Float(&para->PosRand.y,0.000000f,1024.000f,0.001000f);
  float_PosRand_1->Default = 0.000000f; float_PosRand_1->RightStep = 0.125000f;
  sFloatControl *float_PosRand_2 = gh.Float(&para->PosRand.z,0.000000f,1024.000f,0.001000f);
  float_PosRand_2->Default = 0.000000f; float_PosRand_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"RadiusStart");
  sFloatControl *float_RadiusStart = gh.Float(&para->RadiusStart,0.000000f,8.000000f,0.001000f);
  float_RadiusStart->Default = 0.250000f; float_RadiusStart->RightStep = 0.125000f;

  gh.Label(L"RadiusRand");
  sFloatControl *float_RadiusRand = gh.Float(&para->RadiusRand,0.000000f,8.000000f,0.001000f);
  float_RadiusRand->Default = 0.250000f; float_RadiusRand->RightStep = 0.125000f;

  gh.Label(L"MassStart");
  sFloatControl *float_MassStart = gh.Float(&para->MassStart,-16.0000f,16.00000f,0.001000f);
  float_MassStart->Default = 1.000000f; float_MassStart->RightStep = 0.125000f;

  gh.Label(L"MassScale");
  sFloatControl *float_MassScale = gh.Float(&para->MassScale,-16.0000f,16.00000f,0.001000f);
  float_MassScale->Default = 1.000000f; float_MassScale->RightStep = 0.125000f;

  gh.Group(L"Simulation");

  gh.Label(L"Gravity");
  gh.BeginTied();
  sFloatControl *float_Gravity_0 = gh.Float(&para->Gravity.x,-1024.00f,1024.000f,0.001000f);
  float_Gravity_0->Default = 0.000000f; float_Gravity_0->RightStep = 0.125000f;
  sFloatControl *float_Gravity_1 = gh.Float(&para->Gravity.y,-1024.00f,1024.000f,0.001000f);
  float_Gravity_1->Default = -1.00000f; float_Gravity_1->RightStep = 0.125000f;
  sFloatControl *float_Gravity_2 = gh.Float(&para->Gravity.z,-1024.00f,1024.000f,0.001000f);
  float_Gravity_2->Default = 0.000000f; float_Gravity_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"TimeScale");
  sFloatControl *float_TimeScale = gh.Float(&para->TimeScale,0.000000f,1024.000f,0.001000f);
  float_TimeScale->Default = 1.000000f; float_TimeScale->RightStep = 0.125000f;

  gh.Label(L"TimeOffset");
  sFloatControl *float_TimeOffset = gh.Float(&para->TimeOffset,0.000000f,1024.000f,0.100000f);
  float_TimeOffset->Default = 0.000000f; float_TimeOffset->RightStep = 0.125000f;

  gh.Label(L"SimStep");
  sFloatControl *float_SimStep = gh.Float(&para->SimStep,0.000100f,0.200000f,0.000100f);
  float_SimStep->Default = 0.010000f; float_SimStep->RightStep = 0.125000f;

  gh.Label(L"ReactPower");
  sFloatControl *float_ReactPower = gh.Float(&para->ReactPower,0.000100f,2.000000f,0.000100f);
  float_ReactPower->Default = 0.010000f; float_ReactPower->RightStep = 0.125000f;

  gh.Label(L"ReflPower");
  sFloatControl *float_ReflPower = gh.Float(&para->ReflPower,0.000100f,2.000000f,0.000100f);
  float_ReflPower->Default = 0.010000f; float_ReflPower->RightStep = 0.125000f;

  gh.Label(L"SlidePower");
  sFloatControl *float_SlidePower = gh.Float(&para->SlidePower,0.000100f,2.000000f,0.000100f);
  float_SlidePower->Default = 0.010000f; float_SlidePower->RightStep = 0.125000f;

  gh.Group(L"Light");

  gh.Label(L"* LightPos");
  gh.BeginTied();
  sFloatControl *float_LightPos_0 = gh.Float(&para->LightPos.x,-1024.00f,1024.000f,0.001000f);
  float_LightPos_0->Default = 0.000000f; float_LightPos_0->RightStep = 0.125000f;
  sFloatControl *float_LightPos_1 = gh.Float(&para->LightPos.y,-1024.00f,1024.000f,0.001000f);
  float_LightPos_1->Default = 0.000000f; float_LightPos_1->RightStep = 0.125000f;
  sFloatControl *float_LightPos_2 = gh.Float(&para->LightPos.z,-1024.00f,1024.000f,0.001000f);
  float_LightPos_2->Default = 0.000000f; float_LightPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* AmbientColor");
  gh.ColorPick(&para->AmbientColor,L"rgba",0);

  gh.Label(L"* AmbientPower");
  sFloatControl *float_AmbientPower = gh.Float(&para->AmbientPower,0.000000f,1024.000f,0.001000f);
  float_AmbientPower->Default = 1.000000f; float_AmbientPower->RightStep = 0.125000f;

  gh.Label(L"* DiffuseColor");
  gh.ColorPick(&para->DiffuseColor,L"rgba",0);

  gh.Label(L"* DiffusePower");
  sFloatControl *float_DiffusePower = gh.Float(&para->DiffusePower,0.000000f,1024.000f,0.001000f);
  float_DiffusePower->Default = 1.000000f; float_DiffusePower->RightStep = 0.125000f;

  gh.Label(L"* SpecColor");
  gh.ColorPick(&para->SpecColor,L"rgba",0);

  gh.Label(L"* SpecPower");
  sFloatControl *float_SpecPower = gh.Float(&para->SpecPower,0.000000f,1024.000f,0.001000f);
  float_SpecPower->Default = 1.000000f; float_SpecPower->RightStep = 0.125000f;

  gh.Label(L"* SpecHardness");
  sFloatControl *float_SpecHardness = gh.Float(&para->SpecHardness,0.000000f,1024.000f,0.001000f);
  float_SpecHardness->Default = 1.000000f; float_SpecHardness->RightStep = 0.125000f;

  gh.Group(L"Render");

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

void Wz4RenderDefFR063_MassBallColl(wOp *op)
{
  Wz4RenderParaFR063_MassBallColl sUNUSED *para = (Wz4RenderParaFR063_MassBallColl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->NbOfBalls = 0x00000100;
  para->Seed = 0x00000001;
  para->RadiusStart = 0.250000f;
  para->RadiusRand = 0.250000f;
  para->MassStart = 1.000000f;
  para->MassScale = 1.000000f;
  para->Gravity.y = -1.00000f;
  para->TimeScale = 1.000000f;
  para->SimStep = 0.010000f;
  para->ReactPower = 0.010000f;
  para->ReflPower = 0.010000f;
  para->SlidePower = 0.010000f;
  para->AmbientColor = 0xff001f00;
  para->AmbientPower = 1.000000f;
  para->DiffuseColor = 0xff1f0000;
  para->DiffusePower = 1.000000f;
  para->SpecColor = 0xffffffff;
  para->SpecPower = 1.000000f;
  para->SpecHardness = 1.000000f;
}

void Wz4RenderBindFR063_MassBallColl(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"nbofballs"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"posstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"posstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"posstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"posrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"posrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"posrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"radiusstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"radiusrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"massstart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"massscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"gravity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"timescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"timeoffset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"simstep"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"reactpower"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"reflpower"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"slidepower"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"lightpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"lightpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"lightpos"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"ambientcolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"ambientpower"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"diffusecolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"diffusepower"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"speccolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"specpower"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"spechardness"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+31;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_MassBallColl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[30];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"generation");
    name[1] = sPoolString(L"nbofballs");
    name[2] = sPoolString(L"seed");
    name[3] = sPoolString(L"posstart");
    name[4] = sPoolString(L"posrand");
    name[5] = sPoolString(L"radiusstart");
    name[6] = sPoolString(L"radiusrand");
    name[7] = sPoolString(L"massstart");
    name[8] = sPoolString(L"massscale");
    name[9] = sPoolString(L"simulation");
    name[10] = sPoolString(L"gravity");
    name[11] = sPoolString(L"timescale");
    name[12] = sPoolString(L"timeoffset");
    name[13] = sPoolString(L"simstep");
    name[14] = sPoolString(L"reactpower");
    name[15] = sPoolString(L"reflpower");
    name[16] = sPoolString(L"slidepower");
    name[17] = sPoolString(L"light");
    name[18] = sPoolString(L"lightpos");
    name[19] = sPoolString(L"ambientcolor");
    name[20] = sPoolString(L"ambientpower");
    name[21] = sPoolString(L"diffusecolor");
    name[22] = sPoolString(L"diffusepower");
    name[23] = sPoolString(L"speccolor");
    name[24] = sPoolString(L"specpower");
    name[25] = sPoolString(L"spechardness");
    name[26] = sPoolString(L"render");
    name[27] = sPoolString(L"renderpass");
    name[28] = sPoolString(L"");
    name[29] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[18],ScriptTypeFloat,3,cmd->Data+21);
  ctx->AddImport(name[19],ScriptTypeColor,1,cmd->Data+24);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+25);
  ctx->AddImport(name[21],ScriptTypeColor,1,cmd->Data+26);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[23],ScriptTypeColor,1,cmd->Data+28);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+30);
  ctx->AddImport(name[27],ScriptTypeInt,1,cmd->Data+31);
  ctx->AddImport(name[29],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_MassBallColl(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import nbofballs : int;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import posstart : float[3];\n");
  tb.PrintF(L"  import posrand : float[3];\n");
  tb.PrintF(L"  import radiusstart : float;\n");
  tb.PrintF(L"  import radiusrand : float;\n");
  tb.PrintF(L"  import massstart : float;\n");
  tb.PrintF(L"  import massscale : float;\n");
  tb.PrintF(L"  import gravity : float[3];\n");
  tb.PrintF(L"  import timescale : float;\n");
  tb.PrintF(L"  import timeoffset : float;\n");
  tb.PrintF(L"  import simstep : float;\n");
  tb.PrintF(L"  import reactpower : float;\n");
  tb.PrintF(L"  import reflpower : float;\n");
  tb.PrintF(L"  import slidepower : float;\n");
  tb.PrintF(L"  import lightpos : float[3];\n");
  tb.PrintF(L"  import ambientcolor : color;\n");
  tb.PrintF(L"  import ambientpower : float;\n");
  tb.PrintF(L"  import diffusecolor : color;\n");
  tb.PrintF(L"  import diffusepower : float;\n");
  tb.PrintF(L"  import speccolor : color;\n");
  tb.PrintF(L"  import specpower : float;\n");
  tb.PrintF(L"  import spechardness : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_MassBallColl =
L"= Wz4Render : FR063_MassBallColl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_MassBallColl\n"
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
L" !i Wz4ADF\n"
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
L" !i NbOfBalls\n"
L" !i NbOfBalls\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
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
L" !i RadiusStart\n"
L" !i RadiusStart\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RadiusRand\n"
L" !i RadiusRand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MassStart\n"
L" !i MassStart\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MassScale\n"
L" !i MassScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gravity\n"
L" !i Gravity\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TimeScale\n"
L" !i TimeScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TimeOffset\n"
L" !i TimeOffset\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SimStep\n"
L" !i SimStep\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ReactPower\n"
L" !i ReactPower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ReflPower\n"
L" !i ReflPower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SlidePower\n"
L" !i SlidePower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i LightPos\n"
L" !i LightPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i AmbientColor\n"
L" !i AmbientColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i AmbientPower\n"
L" !i AmbientPower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DiffuseColor\n"
L" !i DiffuseColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i DiffusePower\n"
L" !i DiffusePower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpecColor\n"
L" !i SpecColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i SpecPower\n"
L" !i SpecPower\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SpecHardness\n"
L" !i SpecHardness\n"
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

sBool SphCollisionCmdSphSDFColl(wExecutive *exe,wCommand *cmd)
{
  SphCollisionParaSphSDFColl sUNUSED *para = (SphCollisionParaSphSDFColl *)(cmd->Data); para;
  Wz4ADF sUNUSED *in0 = cmd->GetInput<Wz4ADF *>(0); in0;
  SphCollSDF *out = (SphCollSDF *) cmd->Output;
  if(!out) { out=new SphCollSDF; cmd->Output=out; }

  {
#line 254 "fr063_tron_ops.ops"

    out->Para = *para;
    out->SDF = in0; in0->AddRef();
  ;
#line 2191 "fr063_tron_ops.cpp"
    return 1;
  }
}

void SphCollisionGuiSphSDFColl(wGridFrameHelper &gh,wOp *op)
{
  SphCollisionParaSphSDFColl sUNUSED *para = (SphCollisionParaSphSDFColl *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0contain|kill:*4-|invert",gh.ChangeMsg);
}

void SphCollisionDefSphSDFColl(wOp *op)
{
  SphCollisionParaSphSDFColl sUNUSED *para = (SphCollisionParaSphSDFColl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void SphCollisionBindSphSDFColl(wCommand *cmd,ScriptContext *ctx)
{
}
void SphCollisionBind2SphSDFColl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
  }
}
void SphCollisionBind3SphSDFColl(wOp *op,sTextBuffer &tb)
{
}
const sChar *SphCollisionWikiSphSDFColl =
L"= SphCollision : SphSDFColl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphSDFColl\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphCollision\n"
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
L" !i Wz4ADF\n"
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
L" !i contain\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i kill\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i invert\n"
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

sBool SphCollisionCmdSphSDFMorph(wExecutive *exe,wCommand *cmd)
{
  SphCollisionParaSphSDFMorph sUNUSED *para = (SphCollisionParaSphSDFMorph *)(cmd->Data); para;
  Wz4ADF sUNUSED *in0 = cmd->GetInput<Wz4ADF *>(0); in0;
  SphMorphSDF *out = (SphMorphSDF *) cmd->Output;
  if(!out) { out=new SphMorphSDF; cmd->Output=out; }

  {
#line 273 "fr063_tron_ops.ops"

    out->Para = *para;
    out->SDF = in0; in0->AddRef();
  ;
#line 2303 "fr063_tron_ops.cpp"
    return 1;
  }
}

void SphCollisionGuiSphSDFMorph(wGridFrameHelper &gh,wOp *op)
{
  SphCollisionParaSphSDFMorph sUNUSED *para = (SphCollisionParaSphSDFMorph *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Factor");
  sFloatControl *float_Factor = gh.Float(&para->Factor,-16.0000f,16.00000f,0.000100f);
  float_Factor->Default = 0.001000f; float_Factor->RightStep = 0.125000f;

  gh.Label(L"Time");
  sFloatControl *float_Time = gh.Float(&para->Time,0.000000f,65536.00f,0.000100f);
  float_Time->Default = 0.001000f; float_Time->RightStep = 0.125000f;
}

void SphCollisionDefSphSDFMorph(wOp *op)
{
  SphCollisionParaSphSDFMorph sUNUSED *para = (SphCollisionParaSphSDFMorph *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Factor = 0.001000f;
  para->Time = 0.001000f;
}

void SphCollisionBindSphSDFMorph(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"factor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"time"),val);
}
void SphCollisionBind2SphSDFMorph(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"factor");
    name[1] = sPoolString(L"time");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void SphCollisionBind3SphSDFMorph(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import factor : float;\n");
  tb.PrintF(L"  import time : float;\n");
}
const sChar *SphCollisionWikiSphSDFMorph =
L"= SphCollision : SphSDFMorph\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphSDFMorph\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphCollision\n"
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
L" !i Wz4ADF\n"
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
L" !i Factor\n"
L" !i Factor\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Time\n"
L" !i Time\n"
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

sBool SphCollisionCmdSphPDFColl(wExecutive *exe,wCommand *cmd)
{
  SphCollisionParaSphPDFColl sUNUSED *para = (SphCollisionParaSphPDFColl *)(cmd->Data); para;
  Wz4PDF sUNUSED *in0 = cmd->GetInput<Wz4PDF *>(0); in0;
  SphCollPDF *out = (SphCollPDF *) cmd->Output;
  if(!out) { out=new SphCollPDF; cmd->Output=out; }

  {
#line 292 "fr063_tron_ops.ops"

    out->Para = *para;
    out->PDF = in0; in0->AddRef();
  ;
#line 2426 "fr063_tron_ops.cpp"
    return 1;
  }
}

void SphCollisionGuiSphPDFColl(wGridFrameHelper &gh,wOp *op)
{
  SphCollisionParaSphPDFColl sUNUSED *para = (SphCollisionParaSphPDFColl *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0contain|kill:*4-|invert",gh.ChangeMsg);
}

void SphCollisionDefSphPDFColl(wOp *op)
{
  SphCollisionParaSphPDFColl sUNUSED *para = (SphCollisionParaSphPDFColl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void SphCollisionBindSphPDFColl(wCommand *cmd,ScriptContext *ctx)
{
}
void SphCollisionBind2SphPDFColl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
  }
}
void SphCollisionBind3SphPDFColl(wOp *op,sTextBuffer &tb)
{
}
const sChar *SphCollisionWikiSphPDFColl =
L"= SphCollision : SphPDFColl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphPDFColl\n"
L"\n"
L"  !i Output Type\n"
L"  !i SphCollision\n"
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
L" !i Wz4PDF\n"
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
L" !i contain\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i kill\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i invert\n"
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

sBool Wz4RenderCmdFR063_SpritesExt(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_SpritesExt sUNUSED *para = (Wz4RenderParaFR063_SpritesExt *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 336 "fr063_tron_ops.ops"

    FR063_SpritesExt *node = new FR063_SpritesExt();
    node->ParaBase = node->Para = *para;    
    node->TextureDiff = in0; in0->AddRef();
    if (in1)
    {
      node->TextureFade = in1; 
      in1->AddRef();
    }

    node->Particles.Resize(cmd->ArrayCount);
    Wz4RenderArrayFR063_SpritesExt *array= (Wz4RenderArrayFR063_SpritesExt *)cmd->Array;
    for(sInt i=0;i<cmd->ArrayCount;i++)
    {
      sClear(node->Particles[i]);
      node->Particles[i].Para = array[i];      
    }

    node->Init();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);    
    if (cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();    
    }    
  ;
#line 2562 "fr063_tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndFR063_SpritesExt(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaFR063_SpritesExt sUNUSED *para = (Wz4RenderParaFR063_SpritesExt *)(op->EditData); para;
#line 364 "fr063_tron_ops.ops"

    FR063_SpritesExt::Handles(pi,para,op);    
  ;
#line 2574 "fr063_tron_ops.cpp"
}

void Wz4RenderArrFR063_SpritesExt(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaFR063_SpritesExt sUNUSED *para = (Wz4RenderParaFR063_SpritesExt *)(op->EditData); para;
  Wz4RenderArrayFR063_SpritesExt *e = (Wz4RenderArrayFR063_SpritesExt *)(mem);
  e->Pos.x = 0.000000f;
  e->Pos.y = 0.000000f;
  e->Pos.z = 0.000000f;
  e->Color = 0xffffffff;
  e->Size = 0.000000f;
  e->AlignDir.x = 0.000000f;
  e->AlignDir.y = 0.000000f;
  e->AlignDir.z = 0.000000f;
  e->FixAngle = 0.000000f;
  e->Range = 0.000000f;
  e->Mode = 0x00000000;
  e->Mode = 0x00000000;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4RenderArrayFR063_SpritesExt *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4RenderArrayFR063_SpritesExt *)op->ArrayData[pos  ];
    }
    e->Pos.x = f0*p0->Pos.x + f1*p1->Pos.x;
    e->Pos.y = f0*p0->Pos.y + f1*p1->Pos.y;
    e->Pos.z = f0*p0->Pos.z + f1*p1->Pos.z;
    e->Size = f0*p0->Size + f1*p1->Size;
    e->AlignDir.x = f0*p0->AlignDir.x + f1*p1->AlignDir.x;
    e->AlignDir.y = f0*p0->AlignDir.y + f1*p1->AlignDir.y;
    e->AlignDir.z = f0*p0->AlignDir.z + f1*p1->AlignDir.z;
    e->FixAngle = f0*p0->FixAngle + f1*p1->FixAngle;
    e->Range = f0*p0->Range + f1*p1->Range;
  }
}

void Wz4RenderGuiFR063_SpritesExt(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_SpritesExt sUNUSED *para = (Wz4RenderParaFR063_SpritesExt *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Aspect");
  sFloatControl *float_Aspect = gh.Float(&para->Aspect,-16.0000f,16.00000f,0.010000f);
  float_Aspect->Default = 0.000000f; float_Aspect->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*0add|premul alpha|mul|mul2|smooth|alpha (please use pm-alpha):*4zoff|zread|zwrite|zon:*9atlas anim|atlas multi:*14-|scale by transform:*16old behaviour|-",gh.LayoutMsg);

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
  gh.Group(L"NearFarDistanceFade");

  gh.Label(L"NearFadeDistance");
  sFloatControl *float_NearFadeDistance = gh.Float(&para->NearFadeDistance,0.000000f,  1048576,0.125000f);
  float_NearFadeDistance->Default = 1.000000f; float_NearFadeDistance->RightStep = 0.125000f;

  gh.Label(L"FarFadeDistance");
  sFloatControl *float_FarFadeDistance = gh.Float(&para->FarFadeDistance,0.000000f,  1048576,0.125000f);
  float_FarFadeDistance->Default = 1000.000f; float_FarFadeDistance->RightStep = 0.125000f;

  gh.Label(L"FarFadeRange");
  sFloatControl *float_FarFadeRange = gh.Float(&para->FarFadeRange,0.000000f,  1048576,0.125000f);
  float_FarFadeRange->Default = 100.0000f; float_FarFadeRange->RightStep = 0.125000f;

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
  gh.Grid->AddLabel(L"Pos",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  gh.Grid->AddLabel(L"Color",pos,gh.Line,4,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=4;
  gh.Grid->AddLabel(L"Size",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"AlignDir",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  gh.Grid->AddLabel(L"FixAngle",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Range",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Mode",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Mode",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArrayFR063_SpritesExt *elem = (Wz4RenderArrayFR063_SpritesExt *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&elem->Pos.x,-1024.00f,1024.000f,0.001000f);
    float_Pos_0->Default = 0.000000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&elem->Pos.y,-1024.00f,1024.000f,0.001000f);
    float_Pos_1->Default = 0.000000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&elem->Pos.z,-1024.00f,1024.000f,0.001000f);
    float_Pos_2->Default = 0.000000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Color(&elem->Color,L"rgba");

    sFloatControl *float_Size = gh.Float(&elem->Size,0.000000f,1024.000f,0.000100f);
    float_Size->Default = 0.000000f; float_Size->RightStep = 0.125000f;

    gh.BeginTied();
    sFloatControl *float_AlignDir_0 = gh.Float(&elem->AlignDir.x,-16.0000f,16.00000f,0.001000f);
    float_AlignDir_0->Default = 0.000000f; float_AlignDir_0->RightStep = 0.125000f;
    sFloatControl *float_AlignDir_1 = gh.Float(&elem->AlignDir.y,-16.0000f,16.00000f,0.001000f);
    float_AlignDir_1->Default = 0.000000f; float_AlignDir_1->RightStep = 0.125000f;
    sFloatControl *float_AlignDir_2 = gh.Float(&elem->AlignDir.z,-16.0000f,16.00000f,0.001000f);
    float_AlignDir_2->Default = 0.000000f; float_AlignDir_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_FixAngle = gh.Float(&elem->FixAngle,0.000000f,1.000000f,0.000100f);
    float_FixAngle->Default = 0.000000f; float_FixAngle->RightStep = 0.125000f;

    sFloatControl *float_Range = gh.Float(&elem->Range,0.000000f,1.000000f,0.000100f);
    float_Range->Default = 0.000000f; float_Range->RightStep = 0.125000f;

    gh.Flags(&elem->Mode,L"*16AngleFade Off|AngleOn",gh.ChangeMsg);

    gh.Flags(&elem->Mode,L"*0Lock Off|Lock On",gh.ChangeMsg);
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

void Wz4RenderDefFR063_SpritesExt(wOp *op)
{
  Wz4RenderParaFR063_SpritesExt sUNUSED *para = (Wz4RenderParaFR063_SpritesExt *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->TexAnimSpeed = 1.000000f;
  para->NearFadeDistance = 1.000000f;
  para->FarFadeDistance = 1000.000f;
  para->FarFadeRange = 100.0000f;
}

void Wz4RenderBindFR063_SpritesExt(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"aspect"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"texanimspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"texanimrand"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"nearfadedistance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"farfadedistance"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"farfaderange"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_SpritesExt(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"aspect");
    name[1] = sPoolString(L"mode");
    name[2] = sPoolString(L"renderpass");
    name[3] = sPoolString(L"");
    name[4] = sPoolString(L"texanimspeed");
    name[5] = sPoolString(L"texanimrand");
    name[6] = sPoolString(L"nearfardistancefade");
    name[7] = sPoolString(L"nearfadedistance");
    name[8] = sPoolString(L"farfadedistance");
    name[9] = sPoolString(L"farfaderange");
    name[10] = sPoolString(L"");
    name[11] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[11],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FR063_SpritesExt(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import aspect : float;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import texanimspeed : float;\n");
  tb.PrintF(L"  import texanimrand : float;\n");
  tb.PrintF(L"  import nearfadedistance : float;\n");
  tb.PrintF(L"  import farfadedistance : float;\n");
  tb.PrintF(L"  import farfaderange : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_SpritesExt =
L"= Wz4Render : FR063_SpritesExt\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_SpritesExt\n"
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
L" !i scale by transform\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i old behaviour\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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
L" !i scale by transform\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i old behaviour\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdFR063_AermelKanal(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR063_AermelKanal sUNUSED *para = (Wz4RenderParaFR063_AermelKanal *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Render sUNUSED *in1 = cmd->GetInput<Wz4Render *>(1); in1;
  Wz4ADF sUNUSED *in2 = cmd->GetInput<Wz4ADF *>(2); in2;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 399 "fr063_tron_ops.ops"

  
    RNFR063AermelKanal *node = new RNFR063AermelKanal();
    node->ParaBase = node->Para = *para;    
    if (in2)
    {
      node->DF   = in2; in2->AddRef();
    }
    node->Mtrl = in0; in0->AddRef();           
    node->PathName = cmd->Strings[1] && cmd->Strings[1][0] ? cmd->Strings[1] : L"ak_path_spline";    
    node->MovementName = cmd->Strings[2] && cmd->Strings[2][0] ? cmd->Strings[2] : L"ak_movement_spline";    
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass,1,2);
    if (cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();    
    }    
  ;
#line 3166 "fr063_tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndFR063_AermelKanal(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaFR063_AermelKanal sUNUSED *para = (Wz4RenderParaFR063_AermelKanal *)(op->EditData); para;
#line 420 "fr063_tron_ops.ops"
    
//    pi.Handle3D(op,1,para->LightPos,wHM_PLANE);
  ;
#line 3178 "fr063_tron_ops.cpp"
}

void Wz4RenderGuiFR063_AermelKanal(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR063_AermelKanal sUNUSED *para = (Wz4RenderParaFR063_AermelKanal *)(op->EditData); para;

  gh.Group(L"Kanal");

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,3,256,0.125000f);
  int_Slices->Default = 0x00000020; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Segments");
  sIntControl *int_Segments = gh.Int(&para->Segments,2,4096,0.125000f);
  int_Segments->Default = 0x00000100; int_Segments->RightStep = 0.125000f;

  gh.Label(L"PathSpline");
  gh.String(op->EditString[1]);

  gh.Label(L"RadiusOffset");
  gh.BeginTied();
  sFloatControl *float_RadiusOffset_0 = gh.Float(&para->RadiusOffset[0],0.000000f,4096.000f,0.001000f);
  float_RadiusOffset_0->Default = 1.000000f; float_RadiusOffset_0->RightStep = 0.125000f;
  sFloatControl *float_RadiusOffset_1 = gh.Float(&para->RadiusOffset[1],0.000000f,4096.000f,0.001000f);
  float_RadiusOffset_1->Default = 1.000000f; float_RadiusOffset_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"RadiusScale");
  gh.BeginTied();
  sFloatControl *float_RadiusScale_0 = gh.Float(&para->RadiusScale[0],0.000000f,4096.000f,0.001000f);
  float_RadiusScale_0->Default = 1.000000f; float_RadiusScale_0->RightStep = 0.125000f;
  sFloatControl *float_RadiusScale_1 = gh.Float(&para->RadiusScale[1],0.000000f,4096.000f,0.001000f);
  float_RadiusScale_1->Default = 1.000000f; float_RadiusScale_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"RotationOffset");
  sFloatControl *float_RotationOffset = gh.Float(&para->RotationOffset,-8.00000f,8.000000f,0.010000f);
  float_RotationOffset->Default = 0.000000f; float_RotationOffset->RightStep = 0.125000f;

  gh.Group(L"Movement");

  gh.Label(L"Range");
  sIntControl *int_Range = gh.Int(&para->Range,1,256,0.125000f);
  int_Range->Default = 0x00000004; int_Range->RightStep = 0.125000f;

  gh.Label(L"MovementSpline");
  gh.String(op->EditString[2]);

  gh.Group(L"Render Parameter");

  gh.Label(L"LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Debug");

  gh.Label(L"DebugMode");
  gh.Flags(&para->DebugMode,L"*0-|Edit Spline",gh.LayoutMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[3],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFR063_AermelKanal(wOp *op)
{
  Wz4RenderParaFR063_AermelKanal sUNUSED *para = (Wz4RenderParaFR063_AermelKanal *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Slices = 0x00000020;
  para->Segments = 0x00000100;
  para->RadiusOffset[0] = 1.000000f;
  para->RadiusOffset[1] = 1.000000f;
  para->RadiusScale[0] = 1.000000f;
  para->RadiusScale[1] = 1.000000f;
  para->Range = 0x00000004;
}

void Wz4RenderBindFR063_AermelKanal(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"segments"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pathspline"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"radiusoffset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"radiusoffset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"radiusscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"radiusscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rotationoffset"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"range"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+2;
  ctx->BindLocal(ctx->AddSymbol(L"movementspline"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+3;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FR063_AermelKanal(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[17];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"kanal");
    name[1] = sPoolString(L"slices");
    name[2] = sPoolString(L"segments");
    name[3] = sPoolString(L"pathspline");
    name[4] = sPoolString(L"radiusoffset");
    name[5] = sPoolString(L"radiusscale");
    name[6] = sPoolString(L"rotationoffset");
    name[7] = sPoolString(L"movement");
    name[8] = sPoolString(L"range");
    name[9] = sPoolString(L"movementspline");
    name[10] = sPoolString(L"");
    name[11] = sPoolString(L"lightenv");
    name[12] = sPoolString(L"renderpass");
    name[13] = sPoolString(L"debug");
    name[14] = sPoolString(L"debugmode");
    name[15] = sPoolString(L"");
    name[16] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeString,1,cmd->Strings+2);
  ctx->AddImport(name[11],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[12],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[16],ScriptTypeString,1,cmd->Strings+3);
}
void Wz4RenderBind3FR063_AermelKanal(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import segments : int;\n");
  tb.PrintF(L"  import pathspline : string;\n");
  tb.PrintF(L"  import radiusoffset : float[2];\n");
  tb.PrintF(L"  import radiusscale : float[2];\n");
  tb.PrintF(L"  import rotationoffset : float;\n");
  tb.PrintF(L"  import range : int;\n");
  tb.PrintF(L"  import movementspline : string;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFR063_AermelKanal =
L"= Wz4Render : FR063_AermelKanal\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR063_AermelKanal\n"
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
L" !i Wz4Render\n"
L" !i optional\n"
L" !i *\n"
L"\n"
L" !i Wz4ADF\n"
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
L" !i Slices\n"
L" !i Slices\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Segments\n"
L" !i Segments\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i PathSpline\n"
L" !i PathSpline\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i RadiusOffset\n"
L" !i RadiusOffset\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i RadiusScale\n"
L" !i RadiusScale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i RotationOffset\n"
L" !i RotationOffset\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Range\n"
L" !i Range\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MovementSpline\n"
L" !i MovementSpline\n"
L" !i string\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i DebugMode\n"
L" !i DebugMode\n"
L" !i Edit Spline\n"
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

void Wz4RenderAnimFR063_SpritesADF::Init(class ScriptContext *sc)
{
  _Trans = sc->AddSymbol(L"trans");
  _Size = sc->AddSymbol(L"size");
  _Aspect = sc->AddSymbol(L"aspect");
  _RotStart = sc->AddSymbol(L"rotstart");
  _RotSpeed = sc->AddSymbol(L"rotspeed");
  _RotRand = sc->AddSymbol(L"rotrand");
  _RotSpread = sc->AddSymbol(L"rotspread");
  _FadeIn = sc->AddSymbol(L"fadein");
  _FadeOut = sc->AddSymbol(L"fadeout");
  _TexAnimSpeed = sc->AddSymbol(L"texanimspeed");
  _TexAnimRand = sc->AddSymbol(L"texanimrand");
  _SDFFadeOffset = sc->AddSymbol(L"sdffadeoffset");
  _SDFFadeMult = sc->AddSymbol(L"sdffademult");
  _LightPos = sc->AddSymbol(L"lightpos");
  _DiffusePower = sc->AddSymbol(L"diffusepower");
  _SpecHardness = sc->AddSymbol(L"spechardness");
  _SpecPower = sc->AddSymbol(L"specpower");
  _InAmbientColor = sc->AddSymbol(L"inambientcolor");
  _InDiffuseColor = sc->AddSymbol(L"indiffusecolor");
  _InSpecColor = sc->AddSymbol(L"inspeccolor");
  _OutAmbientColor = sc->AddSymbol(L"outambientcolor");
  _OutDiffuseColor = sc->AddSymbol(L"outdiffusecolor");
  _OutSpecColor = sc->AddSymbol(L"outspeccolor");
  _WrapOffset = sc->AddSymbol(L"wrapoffset");
};

void Wz4RenderAnimFR063_SpritesADF::Bind(class ScriptContext *sc,Wz4RenderParaFR063_SpritesADF *para)
{
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
  sc->BindLocalFloat(_Size,1,&para->Size);
  sc->BindLocalFloat(_Aspect,1,&para->Aspect);
  sc->BindLocalFloat(_RotStart,1,&para->RotStart);
  sc->BindLocalFloat(_RotSpeed,1,&para->RotSpeed);
  sc->BindLocalFloat(_RotRand,1,&para->RotRand);
  sc->BindLocalFloat(_RotSpread,1,&para->RotSpread);
  sc->BindLocalFloat(_FadeIn,1,&para->FadeIn);
  sc->BindLocalFloat(_FadeOut,1,&para->FadeOut);
  sc->BindLocalFloat(_TexAnimSpeed,1,&para->TexAnimSpeed);
  sc->BindLocalFloat(_TexAnimRand,1,&para->TexAnimRand);
  sc->BindLocalFloat(_SDFFadeOffset,1,&para->SDFFadeOffset);
  sc->BindLocalFloat(_SDFFadeMult,1,&para->SDFFadeMult);
  sc->BindLocalFloat(_LightPos,3,&para->LightPos.x);
  sc->BindLocalFloat(_DiffusePower,1,&para->DiffusePower);
  sc->BindLocalFloat(_SpecHardness,1,&para->SpecHardness);
  sc->BindLocalFloat(_SpecPower,1,&para->SpecPower);
  sc->BindLocalColor(_InAmbientColor,&para->InAmbientColor);
  sc->BindLocalColor(_InDiffuseColor,&para->InDiffuseColor);
  sc->BindLocalColor(_InSpecColor,&para->InSpecColor);
  sc->BindLocalColor(_OutAmbientColor,&para->OutAmbientColor);
  sc->BindLocalColor(_OutDiffuseColor,&para->OutDiffuseColor);
  sc->BindLocalColor(_OutSpecColor,&para->OutSpecColor);
  sc->BindLocalFloat(_WrapOffset,1,&para->WrapOffset);
};

void Wz4RenderAnimFR063_ClothGridSimRender::Init(class ScriptContext *sc)
{
  _Force = sc->AddSymbol(L"force");
};

void Wz4RenderAnimFR063_ClothGridSimRender::Bind(class ScriptContext *sc,Wz4RenderParaFR063_ClothGridSimRender *para)
{
  sc->BindLocalFloat(_Force,3,&para->Force.x);
};

void Wz4RenderAnimFR063_MassBallColl::Init(class ScriptContext *sc)
{
  _LightPos = sc->AddSymbol(L"lightpos");
  _AmbientColor = sc->AddSymbol(L"ambientcolor");
  _AmbientPower = sc->AddSymbol(L"ambientpower");
  _DiffuseColor = sc->AddSymbol(L"diffusecolor");
  _DiffusePower = sc->AddSymbol(L"diffusepower");
  _SpecColor = sc->AddSymbol(L"speccolor");
  _SpecPower = sc->AddSymbol(L"specpower");
  _SpecHardness = sc->AddSymbol(L"spechardness");
};

void Wz4RenderAnimFR063_MassBallColl::Bind(class ScriptContext *sc,Wz4RenderParaFR063_MassBallColl *para)
{
  sc->BindLocalFloat(_LightPos,3,&para->LightPos.x);
  sc->BindLocalColor(_AmbientColor,&para->AmbientColor);
  sc->BindLocalFloat(_AmbientPower,1,&para->AmbientPower);
  sc->BindLocalColor(_DiffuseColor,&para->DiffuseColor);
  sc->BindLocalFloat(_DiffusePower,1,&para->DiffusePower);
  sc->BindLocalColor(_SpecColor,&para->SpecColor);
  sc->BindLocalFloat(_SpecPower,1,&para->SpecPower);
  sc->BindLocalFloat(_SpecHardness,1,&para->SpecHardness);
};

void SphCollisionAnimSphSDFColl::Init(class ScriptContext *sc)
{
};

void SphCollisionAnimSphSDFColl::Bind(class ScriptContext *sc,SphCollisionParaSphSDFColl *para)
{
};

void SphCollisionAnimSphSDFMorph::Init(class ScriptContext *sc)
{
};

void SphCollisionAnimSphSDFMorph::Bind(class ScriptContext *sc,SphCollisionParaSphSDFMorph *para)
{
};

void SphCollisionAnimSphPDFColl::Init(class ScriptContext *sc)
{
};

void SphCollisionAnimSphPDFColl::Bind(class ScriptContext *sc,SphCollisionParaSphPDFColl *para)
{
};

void Wz4RenderAnimFR063_SpritesExt::Init(class ScriptContext *sc)
{
  _Aspect = sc->AddSymbol(L"aspect");
  _TexAnimSpeed = sc->AddSymbol(L"texanimspeed");
  _TexAnimRand = sc->AddSymbol(L"texanimrand");
};

void Wz4RenderAnimFR063_SpritesExt::Bind(class ScriptContext *sc,Wz4RenderParaFR063_SpritesExt *para)
{
  sc->BindLocalFloat(_Aspect,1,&para->Aspect);
  sc->BindLocalFloat(_TexAnimSpeed,1,&para->TexAnimSpeed);
  sc->BindLocalFloat(_TexAnimRand,1,&para->TexAnimRand);
};

void Wz4RenderAnimFR063_AermelKanal::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimFR063_AermelKanal::Bind(class ScriptContext *sc,Wz4RenderParaFR063_AermelKanal *para)
{
};


/****************************************************************************/

void AddTypes_fr063_tron_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_fr063_tron_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"FR063_SpritesADF";
  cl->Label = L"FR063_SpritesADF";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_SpritesADF;
  cl->MakeGui = Wz4RenderGuiFR063_SpritesADF;
  cl->SetDefaults = Wz4RenderDefFR063_SpritesADF;
  cl->BindPara = Wz4RenderBindFR063_SpritesADF;
  cl->Bind2Para = Wz4RenderBind2FR063_SpritesADF;
  cl->Bind3Para = Wz4RenderBind3FR063_SpritesADF;
  cl->WikiText = Wz4RenderWikiFR063_SpritesADF;
  cl->Handles = Wz4RenderHndFR063_SpritesADF;
  cl->ParaStrings = 1;
  cl->ParaWords = 39;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(3);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4ADFType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = Texture2DType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_ClothGridSimRender";
  cl->Label = L"FR063_ClothGridSimRender";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_ClothGridSimRender;
  cl->MakeGui = Wz4RenderGuiFR063_ClothGridSimRender;
  cl->SetDefaults = Wz4RenderDefFR063_ClothGridSimRender;
  cl->BindPara = Wz4RenderBindFR063_ClothGridSimRender;
  cl->Bind2Para = Wz4RenderBind2FR063_ClothGridSimRender;
  cl->Bind3Para = Wz4RenderBind3FR063_ClothGridSimRender;
  cl->WikiText = Wz4RenderWikiFR063_ClothGridSimRender;
  cl->Handles = Wz4RenderHndFR063_ClothGridSimRender;
  cl->SetDefaultsArray = Wz4RenderArrFR063_ClothGridSimRender;
  cl->ArrayCount = 20;
  cl->ParaStrings = 1;
  cl->ParaWords = 31;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ADFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_MassBallColl";
  cl->Label = L"FR063_MassBallColl";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_MassBallColl;
  cl->MakeGui = Wz4RenderGuiFR063_MassBallColl;
  cl->SetDefaults = Wz4RenderDefFR063_MassBallColl;
  cl->BindPara = Wz4RenderBindFR063_MassBallColl;
  cl->Bind2Para = Wz4RenderBind2FR063_MassBallColl;
  cl->Bind3Para = Wz4RenderBind3FR063_MassBallColl;
  cl->WikiText = Wz4RenderWikiFR063_MassBallColl;
  cl->ParaStrings = 1;
  cl->ParaWords = 32;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ADFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphSDFColl";
  cl->Label = L"SphSDFColl";
  cl->OutputType = SphCollisionType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphCollisionCmdSphSDFColl;
  cl->MakeGui = SphCollisionGuiSphSDFColl;
  cl->SetDefaults = SphCollisionDefSphSDFColl;
  cl->BindPara = SphCollisionBindSphSDFColl;
  cl->Bind2Para = SphCollisionBind2SphSDFColl;
  cl->Bind3Para = SphCollisionBind3SphSDFColl;
  cl->WikiText = SphCollisionWikiSphSDFColl;
  cl->ParaWords = 1;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ADFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphSDFMorph";
  cl->Label = L"SphSDFMorph";
  cl->OutputType = SphCollisionType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphCollisionCmdSphSDFMorph;
  cl->MakeGui = SphCollisionGuiSphSDFMorph;
  cl->SetDefaults = SphCollisionDefSphSDFMorph;
  cl->BindPara = SphCollisionBindSphSDFMorph;
  cl->Bind2Para = SphCollisionBind2SphSDFMorph;
  cl->Bind3Para = SphCollisionBind3SphSDFMorph;
  cl->WikiText = SphCollisionWikiSphSDFMorph;
  cl->ParaWords = 2;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ADFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphPDFColl";
  cl->Label = L"SphPDFColl";
  cl->OutputType = SphCollisionType;
  cl->TabType = SphGeneratorType;
  cl->Command = SphCollisionCmdSphPDFColl;
  cl->MakeGui = SphCollisionGuiSphPDFColl;
  cl->SetDefaults = SphCollisionDefSphPDFColl;
  cl->BindPara = SphCollisionBindSphPDFColl;
  cl->Bind2Para = SphCollisionBind2SphPDFColl;
  cl->Bind3Para = SphCollisionBind3SphPDFColl;
  cl->WikiText = SphCollisionWikiSphPDFColl;
  cl->ParaWords = 1;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4PDFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_SpritesExt";
  cl->Label = L"FR063_SpritesExt";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_SpritesExt;
  cl->MakeGui = Wz4RenderGuiFR063_SpritesExt;
  cl->SetDefaults = Wz4RenderDefFR063_SpritesExt;
  cl->BindPara = Wz4RenderBindFR063_SpritesExt;
  cl->Bind2Para = Wz4RenderBind2FR063_SpritesExt;
  cl->Bind3Para = Wz4RenderBind3FR063_SpritesExt;
  cl->WikiText = Wz4RenderWikiFR063_SpritesExt;
  cl->Handles = Wz4RenderHndFR063_SpritesExt;
  cl->SetDefaultsArray = Wz4RenderArrFR063_SpritesExt;
  cl->ArrayCount = 11;
  cl->ParaStrings = 1;
  cl->ParaWords = 9;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR063_AermelKanal";
  cl->Label = L"FR063_AermelKanal";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR063_AermelKanal;
  cl->MakeGui = Wz4RenderGuiFR063_AermelKanal;
  cl->SetDefaults = Wz4RenderDefFR063_AermelKanal;
  cl->BindPara = Wz4RenderBindFR063_AermelKanal;
  cl->Bind2Para = Wz4RenderBind2FR063_AermelKanal;
  cl->Bind3Para = Wz4RenderBind3FR063_AermelKanal;
  cl->WikiText = Wz4RenderWikiFR063_AermelKanal;
  cl->Handles = Wz4RenderHndFR063_AermelKanal;
  cl->ParaStrings = 4;
  cl->ParaWords = 11;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(3);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4RenderType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  in[2].Type = Wz4ADFType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fr063_tron_ops,0x110,AddOps_fr063_tron_ops,0);


/****************************************************************************/


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
#include "fr062_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 15 "fr062_ops.ops"


#line 25 "fr062_ops.cpp"

/****************************************************************************/

#line 21 "fr062_ops.ops"

  class MM62_SphereSlicer : public MtrlModule
  {
  public:
    ModShaderParaSphereSlicer Para;
    MtrlModule *Tex;

    MM62_SphereSlicer()
    {
      Phase = MMP_Post;
      Name = L"sphereslicer";
      Shaders = 3;
      Tex = 0;
    }

    void PS(ShaderCreator *sc)
    {
      const sChar *texname = 0;
      if(Tex)
        texname = Tex->Get(sc);

      sc->FragBegin(Name);
      sc->FragModify(L"col_diffuse");
      sc->FragModify(L"alpha");
      sc->InputPS(L"ws_pos",SCT_FLOAT3);
      if(texname)
        sc->FragRead(texname);

      // gather parameters

      sVector30 col;
      col.InitColor(Para.Color);
      sc->TB.PrintF(L"  {\n");
      if(Para.Flags & 4)
      {
        sc->Para(L"Vector0");
        sc->Para(L"Vector1");
        sc->Para(L"Vector2");
        sc->Para(L"Vector3");
        sc->Para(L"Vector4");
        sc->Para(L"Vector5");
        sc->Para(L"Color0");
        sc->TB.PrintF(L"    float3 c0 = Vector0.xyz; float r0 = Vector0.w;\n");
        sc->TB.PrintF(L"    float3 c1 = Vector1.xyz; float r1 = Vector1.w;\n");
        sc->TB.PrintF(L"    float3 c2 = Vector2.xyz; float r2 = Vector2.w;\n");
        sc->TB.PrintF(L"    float3 c3 = Vector3.xyz; float r3 = Vector3.w;\n");
        sc->TB.PrintF(L"    float clipmin=Vector4.x,clipmax=Vector4.x+Vector4.y,colmin=Vector4.z,colmax=Vector4.z+Vector4.w;\n");
        sc->TB.PrintF(L"    float3 col=Color0;\n");
        sc->TB.PrintF(L"    float amp=Vector5.x,bias=Vector5.y,tamp=Vector5.z;\n");
      }
      else
      {
        sc->TB.PrintF(L"    float3 c0 = float3(%f,%f,%f); float r0 = %f;\n",Para.Sphere0.x,Para.Sphere0.y,Para.Sphere0.z,Para.Sphere0.w);
        sc->TB.PrintF(L"    float3 c1 = float3(%f,%f,%f); float r1 = %f;\n",Para.Sphere1.x,Para.Sphere1.y,Para.Sphere1.z,Para.Sphere1.w);
        sc->TB.PrintF(L"    float3 c2 = float3(%f,%f,%f); float r2 = %f;\n",Para.Sphere2.x,Para.Sphere2.y,Para.Sphere2.z,Para.Sphere2.w);
        sc->TB.PrintF(L"    float3 c3 = float3(%f,%f,%f); float r3 = %f;\n",Para.Sphere3.x,Para.Sphere3.y,Para.Sphere3.z,Para.Sphere3.w);
        sc->TB.PrintF(L"    float clipmin=%f,clipmax=%f,colmin=%f,colmax=%f;\n",Para.ClipMin,Para.ClipMax,Para.ColMin,Para.ColMax);
        sc->TB.PrintF(L"    float3 col=float3(%f,%f,%f);\n",col.x,col.y,col.z);
        sc->TB.PrintF(L"    float amp=%f; bias=%f; tamp=%f;\n",Para.Amp,Para.Bias,Para.TexAmp);
      }

      // slice

      sc->TB.PrintF(L"    float pot = r0/length(c0-ws_pos) +  r1/length(c1-ws_pos) +  r2/length(c2-ws_pos) +  r3/length(c3-ws_pos);\n");
      if(Para.Flags & 8)
        sc->TB.PrintF(L"    pot = 1/pot;\n");
      sc->TB.PrintF(L"    pot = pot*amp+bias;\n");
      if(texname)
        sc->TB.PrintF(L"    pot += %s.x*tamp;\n",texname);
      switch(Para.Flags & 3)
      {
      case 0:
        break;
      case 1:
        sc->TB.PrintF(L"    pot = sin(pot*%f);\n",sPI2F);
        break;
      case 2:
        sc->TB.PrintF(L"    pot = frac(pot);\n");
        break;
      case 3:
        sc->TB.PrintF(L"    pot = saturate(sin(pot*%f));\n",sPI2F);
        break;
      }
      if(Para.Flags & 32)
        sc->TB.PrintF(L"    pot = 1-pot;\n",sPI2F);

      if(Para.Flags & 16)
        sc->TB.PrintF(L"    if(!((pot>colmin) && (pot<colmax)))\n");
      else
        sc->TB.PrintF(L"    if((pot>colmin) && (pot<colmax))\n");
      sc->TB.PrintF(L"    {\n");
      sc->TB.PrintF(L"      col_diffuse.xyz = col;\n");
      sc->TB.PrintF(L"      alpha = 1;\n");
      sc->TB.PrintF(L"    }\n");
      sc->TB.PrintF(L"    if((pot<clipmin) || (pot>clipmax))\n");
      sc->TB.PrintF(L"      discard;\n");
      //sc->TB.PrintF(L"    float clipflag = (pot>clipmin) && (pot<clipmax);\n");
      //sc->TB.PrintF(L"    clip(clipflag-0.5);\n");
      sc->TB.PrintF(L"  }\n");

      sc->FragEnd();
    }
  };

#line 134 "fr062_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool ModShaderCmdSphereSlicer(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaSphereSlicer sUNUSED *para = (ModShaderParaSphereSlicer *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 149 "fr062_ops.ops"

    MM62_SphereSlicer *mod = new MM62_SphereSlicer;
    mod->Para = *para;
    if(in0)
      mod->Tex = in0->Modules[0];
    out->Add(in0);
    out->Add(mod)
  ;
#line 158 "fr062_ops.cpp"
    return 1;
  }
}

void ModShaderGuiSphereSlicer(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaSphereSlicer sUNUSED *para = (ModShaderParaSphereSlicer *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Sphere0");
  gh.BeginTied();
  sFloatControl *float_Sphere0_0 = gh.Float(&para->Sphere0.x,-1024.00f,1024.000f,0.010000f);
  float_Sphere0_0->Default = 0.000000f; float_Sphere0_0->RightStep = 0.125000f;
  sFloatControl *float_Sphere0_1 = gh.Float(&para->Sphere0.y,-1024.00f,1024.000f,0.010000f);
  float_Sphere0_1->Default = 0.000000f; float_Sphere0_1->RightStep = 0.125000f;
  sFloatControl *float_Sphere0_2 = gh.Float(&para->Sphere0.z,-1024.00f,1024.000f,0.010000f);
  float_Sphere0_2->Default = 0.000000f; float_Sphere0_2->RightStep = 0.125000f;
  sFloatControl *float_Sphere0_3 = gh.Float(&para->Sphere0.w,-1024.00f,1024.000f,0.010000f);
  float_Sphere0_3->Default = 1.000000f; float_Sphere0_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Sphere1");
  gh.BeginTied();
  sFloatControl *float_Sphere1_0 = gh.Float(&para->Sphere1.x,-1024.00f,1024.000f,0.010000f);
  float_Sphere1_0->Default = 0.000000f; float_Sphere1_0->RightStep = 0.125000f;
  sFloatControl *float_Sphere1_1 = gh.Float(&para->Sphere1.y,-1024.00f,1024.000f,0.010000f);
  float_Sphere1_1->Default = 0.000000f; float_Sphere1_1->RightStep = 0.125000f;
  sFloatControl *float_Sphere1_2 = gh.Float(&para->Sphere1.z,-1024.00f,1024.000f,0.010000f);
  float_Sphere1_2->Default = 0.000000f; float_Sphere1_2->RightStep = 0.125000f;
  sFloatControl *float_Sphere1_3 = gh.Float(&para->Sphere1.w,-1024.00f,1024.000f,0.010000f);
  float_Sphere1_3->Default = 0.000000f; float_Sphere1_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Sphere2");
  gh.BeginTied();
  sFloatControl *float_Sphere2_0 = gh.Float(&para->Sphere2.x,-1024.00f,1024.000f,0.010000f);
  float_Sphere2_0->Default = 0.000000f; float_Sphere2_0->RightStep = 0.125000f;
  sFloatControl *float_Sphere2_1 = gh.Float(&para->Sphere2.y,-1024.00f,1024.000f,0.010000f);
  float_Sphere2_1->Default = 0.000000f; float_Sphere2_1->RightStep = 0.125000f;
  sFloatControl *float_Sphere2_2 = gh.Float(&para->Sphere2.z,-1024.00f,1024.000f,0.010000f);
  float_Sphere2_2->Default = 0.000000f; float_Sphere2_2->RightStep = 0.125000f;
  sFloatControl *float_Sphere2_3 = gh.Float(&para->Sphere2.w,-1024.00f,1024.000f,0.010000f);
  float_Sphere2_3->Default = 0.000000f; float_Sphere2_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Sphere3");
  gh.BeginTied();
  sFloatControl *float_Sphere3_0 = gh.Float(&para->Sphere3.x,-1024.00f,1024.000f,0.010000f);
  float_Sphere3_0->Default = 0.000000f; float_Sphere3_0->RightStep = 0.125000f;
  sFloatControl *float_Sphere3_1 = gh.Float(&para->Sphere3.y,-1024.00f,1024.000f,0.010000f);
  float_Sphere3_1->Default = 0.000000f; float_Sphere3_1->RightStep = 0.125000f;
  sFloatControl *float_Sphere3_2 = gh.Float(&para->Sphere3.z,-1024.00f,1024.000f,0.010000f);
  float_Sphere3_2->Default = 0.000000f; float_Sphere3_2->RightStep = 0.125000f;
  sFloatControl *float_Sphere3_3 = gh.Float(&para->Sphere3.w,-1024.00f,1024.000f,0.010000f);
  float_Sphere3_3->Default = 0.000000f; float_Sphere3_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Amp");
  sFloatControl *float_Amp = gh.Float(&para->Amp,-1024.00f,1024.000f,0.001000f);
  float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|sin|mod|halfsin:*2-|from env:*3 reciproce|linear:*4-|inv color:*5-|inv pot",gh.ChangeMsg);

  gh.Label(L"ClipMin");
  sFloatControl *float_ClipMin = gh.Float(&para->ClipMin,-16.0000f,16.00000f,0.001000f);
  float_ClipMin->Default = 0.000000f; float_ClipMin->RightStep = 0.125000f;

  gh.Label(L"ClipMax");
  sFloatControl *float_ClipMax = gh.Float(&para->ClipMax,-16.0000f,16.00000f,0.001000f);
  float_ClipMax->Default = 0.000000f; float_ClipMax->RightStep = 0.125000f;

  gh.Label(L"ColMin");
  sFloatControl *float_ColMin = gh.Float(&para->ColMin,-16.0000f,16.00000f,0.001000f);
  float_ColMin->Default = 0.000000f; float_ColMin->RightStep = 0.125000f;

  gh.Label(L"ColMax");
  sFloatControl *float_ColMax = gh.Float(&para->ColMax,-16.0000f,16.00000f,0.001000f);
  float_ColMax->Default = 0.000000f; float_ColMax->RightStep = 0.125000f;

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.Label(L"Bias");
  sFloatControl *float_Bias = gh.Float(&para->Bias,-1024.00f,1024.000f,0.001000f);
  float_Bias->Default = 1.000000f; float_Bias->RightStep = 0.125000f;

  gh.Label(L"TexAmp");
  sFloatControl *float_TexAmp = gh.Float(&para->TexAmp,-1024.00f,1024.000f,0.001000f);
  float_TexAmp->Default = 1.000000f; float_TexAmp->RightStep = 0.125000f;
}

void ModShaderDefSphereSlicer(wOp *op)
{
  ModShaderParaSphereSlicer sUNUSED *para = (ModShaderParaSphereSlicer *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Sphere0.w = 1.000000f;
  para->Amp = 1.000000f;
  para->Bias = 1.000000f;
  para->TexAmp = 1.000000f;
}

void ModShaderBindSphereSlicer(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"sphere0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"sphere0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"sphere0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"sphere0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"sphere1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"sphere1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"sphere1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"sphere1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"sphere2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"sphere2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"sphere2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"sphere2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"sphere3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"sphere3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"sphere3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"sphere3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"clipmin"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"clipmax"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"colmin"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"colmax"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"texamp"),val);
}
void ModShaderBind2SphereSlicer(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"sphere0");
    name[1] = sPoolString(L"sphere1");
    name[2] = sPoolString(L"sphere2");
    name[3] = sPoolString(L"sphere3");
    name[4] = sPoolString(L"amp");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"clipmin");
    name[7] = sPoolString(L"clipmax");
    name[8] = sPoolString(L"colmin");
    name[9] = sPoolString(L"colmax");
    name[10] = sPoolString(L"color_");
    name[11] = sPoolString(L"bias");
    name[12] = sPoolString(L"texamp");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,4,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,4,cmd->Data+4);
  ctx->AddImport(name[2],ScriptTypeFloat,4,cmd->Data+8);
  ctx->AddImport(name[3],ScriptTypeFloat,4,cmd->Data+12);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[10],ScriptTypeColor,1,cmd->Data+22);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+24);
}
void ModShaderBind3SphereSlicer(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import sphere0 : float[4];\n");
  tb.PrintF(L"  import sphere1 : float[4];\n");
  tb.PrintF(L"  import sphere2 : float[4];\n");
  tb.PrintF(L"  import sphere3 : float[4];\n");
  tb.PrintF(L"  import amp : float;\n");
  tb.PrintF(L"  import clipmin : float;\n");
  tb.PrintF(L"  import clipmax : float;\n");
  tb.PrintF(L"  import colmin : float;\n");
  tb.PrintF(L"  import colmax : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import bias : float;\n");
  tb.PrintF(L"  import texamp : float;\n");
}
const sChar *ModShaderWikiSphereSlicer =
L"= ModShader : SphereSlicer\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphereSlicer\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
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
L" !i ModShaderSampler\n"
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
L" !i Sphere0\n"
L" !i Sphere0\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Sphere1\n"
L" !i Sphere1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Sphere2\n"
L" !i Sphere2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Sphere3\n"
L" !i Sphere3\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i sin\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mod\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i halfsin\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i from env\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i reciproce\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i inv color\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i inv pot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ClipMin\n"
L" !i ClipMin\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipMax\n"
L" !i ClipMax\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ColMin\n"
L" !i ColMin\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ColMax\n"
L" !i ColMax\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexAmp\n"
L" !i TexAmp\n"
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

sBool Wz4RenderCmdModSlice(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaModSlice sUNUSED *para = (Wz4RenderParaModSlice *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 209 "fr062_ops.ops"

    RNModSlice *node = new RNModSlice;
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 560 "fr062_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiModSlice(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaModSlice sUNUSED *para = (Wz4RenderParaModSlice *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Pos0");
  gh.BeginTied();
  sFloatControl *float_Pos0_0 = gh.Float(&para->Pos0.x, -1000000,  1000000,0.010000f);
  float_Pos0_0->Default = 0.000000f; float_Pos0_0->RightStep = 0.125000f;
  sFloatControl *float_Pos0_1 = gh.Float(&para->Pos0.y, -1000000,  1000000,0.010000f);
  float_Pos0_1->Default = 0.000000f; float_Pos0_1->RightStep = 0.125000f;
  sFloatControl *float_Pos0_2 = gh.Float(&para->Pos0.z, -1000000,  1000000,0.010000f);
  float_Pos0_2->Default = 0.000000f; float_Pos0_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Size0 = gh.Float(&para->Size0,-1000.00f,1000.000f,0.010000f);
  float_Size0->Default = 0.000000f; float_Size0->RightStep = 0.125000f;

  gh.Label(L"* Pos1");
  gh.BeginTied();
  sFloatControl *float_Pos1_0 = gh.Float(&para->Pos1.x, -1000000,  1000000,0.010000f);
  float_Pos1_0->Default = 0.000000f; float_Pos1_0->RightStep = 0.125000f;
  sFloatControl *float_Pos1_1 = gh.Float(&para->Pos1.y, -1000000,  1000000,0.010000f);
  float_Pos1_1->Default = 0.000000f; float_Pos1_1->RightStep = 0.125000f;
  sFloatControl *float_Pos1_2 = gh.Float(&para->Pos1.z, -1000000,  1000000,0.010000f);
  float_Pos1_2->Default = 0.000000f; float_Pos1_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Size1 = gh.Float(&para->Size1,-1000.00f,1000.000f,0.010000f);
  float_Size1->Default = 0.000000f; float_Size1->RightStep = 0.125000f;

  gh.Label(L"* Pos2");
  gh.BeginTied();
  sFloatControl *float_Pos2_0 = gh.Float(&para->Pos2.x, -1000000,  1000000,0.010000f);
  float_Pos2_0->Default = 0.000000f; float_Pos2_0->RightStep = 0.125000f;
  sFloatControl *float_Pos2_1 = gh.Float(&para->Pos2.y, -1000000,  1000000,0.010000f);
  float_Pos2_1->Default = 0.000000f; float_Pos2_1->RightStep = 0.125000f;
  sFloatControl *float_Pos2_2 = gh.Float(&para->Pos2.z, -1000000,  1000000,0.010000f);
  float_Pos2_2->Default = 0.000000f; float_Pos2_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Size2 = gh.Float(&para->Size2,-1000.00f,1000.000f,0.010000f);
  float_Size2->Default = 0.000000f; float_Size2->RightStep = 0.125000f;

  gh.Label(L"* Pos3");
  gh.BeginTied();
  sFloatControl *float_Pos3_0 = gh.Float(&para->Pos3.x, -1000000,  1000000,0.010000f);
  float_Pos3_0->Default = 0.000000f; float_Pos3_0->RightStep = 0.125000f;
  sFloatControl *float_Pos3_1 = gh.Float(&para->Pos3.y, -1000000,  1000000,0.010000f);
  float_Pos3_1->Default = 0.000000f; float_Pos3_1->RightStep = 0.125000f;
  sFloatControl *float_Pos3_2 = gh.Float(&para->Pos3.z, -1000000,  1000000,0.010000f);
  float_Pos3_2->Default = 0.000000f; float_Pos3_2->RightStep = 0.125000f;
  gh.EndTied();

  sFloatControl *float_Size3 = gh.Float(&para->Size3,-1000.00f,1000.000f,0.010000f);
  float_Size3->Default = 0.000000f; float_Size3->RightStep = 0.125000f;

  gh.Label(L"* Amp");
  sFloatControl *float_Amp = gh.Float(&para->Amp,-16.0000f,16.00000f,0.010000f);
  float_Amp->Default = 0.000000f; float_Amp->RightStep = 0.125000f;

  gh.Label(L"* ClipPhase");
  sFloatControl *float_ClipPhase = gh.Float(&para->ClipPhase,-16.0000f,16.00000f,0.010000f);
  float_ClipPhase->Default = 0.000000f; float_ClipPhase->RightStep = 0.125000f;

  gh.Label(L"* ClipSize");
  sFloatControl *float_ClipSize = gh.Float(&para->ClipSize,-16.0000f,16.00000f,0.010000f);
  float_ClipSize->Default = 0.000000f; float_ClipSize->RightStep = 0.125000f;

  gh.Label(L"* ColPhase");
  sFloatControl *float_ColPhase = gh.Float(&para->ColPhase,-16.0000f,16.00000f,0.010000f);
  float_ColPhase->Default = 0.000000f; float_ColPhase->RightStep = 0.125000f;

  gh.Label(L"* ColSize");
  sFloatControl *float_ColSize = gh.Float(&para->ColSize,-16.0000f,16.00000f,0.010000f);
  float_ColSize->Default = 0.000000f; float_ColSize->RightStep = 0.125000f;

  gh.Label(L"* Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.Label(L"* Bias");
  sFloatControl *float_Bias = gh.Float(&para->Bias,-16.0000f,16.00000f,0.010000f);
  float_Bias->Default = 0.000000f; float_Bias->RightStep = 0.125000f;

  gh.Label(L"* TexAmp");
  sFloatControl *float_TexAmp = gh.Float(&para->TexAmp,-1024.00f,1024.000f,0.001000f);
  float_TexAmp->Default = 1.000000f; float_TexAmp->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefModSlice(wOp *op)
{
  Wz4RenderParaModSlice sUNUSED *para = (Wz4RenderParaModSlice *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->TexAmp = 1.000000f;
}

void Wz4RenderBindModSlice(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"size0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"size1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"size2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"size3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"clipphase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"clipsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"colphase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"colsize"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"texamp"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ModSlice(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[20];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"pos0");
    name[3] = sPoolString(L"size0");
    name[4] = sPoolString(L"pos1");
    name[5] = sPoolString(L"size1");
    name[6] = sPoolString(L"pos2");
    name[7] = sPoolString(L"size2");
    name[8] = sPoolString(L"pos3");
    name[9] = sPoolString(L"size3");
    name[10] = sPoolString(L"amp");
    name[11] = sPoolString(L"clipphase");
    name[12] = sPoolString(L"clipsize");
    name[13] = sPoolString(L"colphase");
    name[14] = sPoolString(L"colsize");
    name[15] = sPoolString(L"color_");
    name[16] = sPoolString(L"bias");
    name[17] = sPoolString(L"texamp");
    name[18] = sPoolString(L"");
    name[19] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+14);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[15],ScriptTypeColor,1,cmd->Data+23);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+25);
  ctx->AddImport(name[19],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ModSlice(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import pos0 : float[3];\n");
  tb.PrintF(L"  import size0 : float;\n");
  tb.PrintF(L"  import pos1 : float[3];\n");
  tb.PrintF(L"  import size1 : float;\n");
  tb.PrintF(L"  import pos2 : float[3];\n");
  tb.PrintF(L"  import size2 : float;\n");
  tb.PrintF(L"  import pos3 : float[3];\n");
  tb.PrintF(L"  import size3 : float;\n");
  tb.PrintF(L"  import amp : float;\n");
  tb.PrintF(L"  import clipphase : float;\n");
  tb.PrintF(L"  import clipsize : float;\n");
  tb.PrintF(L"  import colphase : float;\n");
  tb.PrintF(L"  import colsize : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import bias : float;\n");
  tb.PrintF(L"  import texamp : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiModSlice =
L"= Wz4Render : ModSlice\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ModSlice\n"
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
L" !i Index\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Pos0\n"
L" !i Pos0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size0\n"
L" !i Size0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos1\n"
L" !i Pos1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size1\n"
L" !i Size1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos2\n"
L" !i Pos2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size2\n"
L" !i Size2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos3\n"
L" !i Pos3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Size3\n"
L" !i Size3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipPhase\n"
L" !i ClipPhase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ClipSize\n"
L" !i ClipSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ColPhase\n"
L" !i ColPhase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ColSize\n"
L" !i ColSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexAmp\n"
L" !i TexAmp\n"
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

void ModShaderAnimSphereSlicer::Init(class ScriptContext *sc)
{
};

void ModShaderAnimSphereSlicer::Bind(class ScriptContext *sc,ModShaderParaSphereSlicer *para)
{
};

void Wz4RenderAnimModSlice::Init(class ScriptContext *sc)
{
  _Pos0 = sc->AddSymbol(L"pos0");
  _Size0 = sc->AddSymbol(L"size0");
  _Pos1 = sc->AddSymbol(L"pos1");
  _Size1 = sc->AddSymbol(L"size1");
  _Pos2 = sc->AddSymbol(L"pos2");
  _Size2 = sc->AddSymbol(L"size2");
  _Pos3 = sc->AddSymbol(L"pos3");
  _Size3 = sc->AddSymbol(L"size3");
  _Amp = sc->AddSymbol(L"amp");
  _ClipPhase = sc->AddSymbol(L"clipphase");
  _ClipSize = sc->AddSymbol(L"clipsize");
  _ColPhase = sc->AddSymbol(L"colphase");
  _ColSize = sc->AddSymbol(L"colsize");
  _Color = sc->AddSymbol(L"color_");
  _Bias = sc->AddSymbol(L"bias");
  _TexAmp = sc->AddSymbol(L"texamp");
};

void Wz4RenderAnimModSlice::Bind(class ScriptContext *sc,Wz4RenderParaModSlice *para)
{
  sc->BindLocalFloat(_Pos0,3,&para->Pos0.x);
  sc->BindLocalFloat(_Size0,1,&para->Size0);
  sc->BindLocalFloat(_Pos1,3,&para->Pos1.x);
  sc->BindLocalFloat(_Size1,1,&para->Size1);
  sc->BindLocalFloat(_Pos2,3,&para->Pos2.x);
  sc->BindLocalFloat(_Size2,1,&para->Size2);
  sc->BindLocalFloat(_Pos3,3,&para->Pos3.x);
  sc->BindLocalFloat(_Size3,1,&para->Size3);
  sc->BindLocalFloat(_Amp,1,&para->Amp);
  sc->BindLocalFloat(_ClipPhase,1,&para->ClipPhase);
  sc->BindLocalFloat(_ClipSize,1,&para->ClipSize);
  sc->BindLocalFloat(_ColPhase,1,&para->ColPhase);
  sc->BindLocalFloat(_ColSize,1,&para->ColSize);
  sc->BindLocalColor(_Color,&para->Color);
  sc->BindLocalFloat(_Bias,1,&para->Bias);
  sc->BindLocalFloat(_TexAmp,1,&para->TexAmp);
};


/****************************************************************************/

void AddTypes_fr062_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_fr062_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"SphereSlicer";
  cl->Label = L"SphereSlicer";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdSphereSlicer;
  cl->MakeGui = ModShaderGuiSphereSlicer;
  cl->SetDefaults = ModShaderDefSphereSlicer;
  cl->BindPara = ModShaderBindSphereSlicer;
  cl->Bind2Para = ModShaderBind2SphereSlicer;
  cl->Bind3Para = ModShaderBind3SphereSlicer;
  cl->WikiText = ModShaderWikiSphereSlicer;
  cl->ParaWords = 25;
  cl->Column = 7;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ModSlice";
  cl->Label = L"ModSlice";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdModSlice;
  cl->MakeGui = Wz4RenderGuiModSlice;
  cl->SetDefaults = Wz4RenderDefModSlice;
  cl->BindPara = Wz4RenderBindModSlice;
  cl->Bind2Para = Wz4RenderBind2ModSlice;
  cl->Bind3Para = Wz4RenderBind3ModSlice;
  cl->WikiText = Wz4RenderWikiModSlice;
  cl->ParaStrings = 1;
  cl->ParaWords = 26;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(fr062_ops,0x110,AddOps_fr062_ops,0);


/****************************************************************************/


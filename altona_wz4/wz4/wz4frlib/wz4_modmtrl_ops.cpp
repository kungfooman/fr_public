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
#include "wz4_modmtrl_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class ModMtrlType_ *ModMtrlType;
class ModShaderType_ *ModShaderType;
class ModShaderSamplerType_ *ModShaderSamplerType;

/****************************************************************************/


/****************************************************************************/

sBool ModMtrlCmdModMaterial(wExecutive *exe,wCommand *cmd)
{
  ModMtrlParaModMaterial sUNUSED *para = (ModMtrlParaModMaterial *)(cmd->Data); para;
  ModShader sUNUSED *in0 = cmd->GetInput<ModShader *>(0); in0;
  ModMtrl *out = (ModMtrl *) cmd->Output;
  if(!out) { out=new ModMtrl; cmd->Output=out; }

  {
#line 116 "wz4_modmtrl_ops.ops"

    for(sInt i=0;i<cmd->InputCount;i++)
    {
      ModShader *in = cmd->GetInput<ModShader *>(i);
      if(in)
      {
        sAddRefAll(in->Modules);
        out->ModulesUser.Add(in->Modules);
      }
    }
    static sU32 blend[16] = 
    { 0,sMB_PMALPHA,sMB_ADD,sMB_SUB,sMB_MUL,sMB_MUL2,sMB_ADDSMOOTH,sMB_ALPHA,sMBS_F|sMBO_ADD|sMBD_FI };
    sU32 blendc = blend[para->Blend & 15];
    sU32 blenda = sMBS_1|sMBO_ADD|sMBD_0;
    if(para->Blend & 0x30)
    {
      if(blendc==sMB_OFF)
        blendc = sMBS_1|sMBO_ADD|sMBD_0;
      if((para->Blend & 0x30)==0x10)
        blenda = sMBS_0|sMBO_ADD|sMBD_1;
      if((para->Blend & 0x30)==0x20)
        blenda = sMBS_0|sMBO_ADD|sMBD_0;
      if((para->Blend & 0x30)==0x30)
        blenda = sMBS_1|sMBO_ADD|sMBD_SAI;
    }

    out->KillFeatures = para->AllowFeatures;
    out->KillLight = sU8(para->AllowLight);
    out->KillShadow = sU8(para->AllowShadow);
    out->FeatureFlags = para->FeatureFlags;
    out->SetMtrl(para->Flags,blendc,blenda);
    out->SetAlphaTest(para->AlphaTest,para->AlphaRef);

    // for debugging, log where the op is

    if(cmd->Op)
    {
      out->PageName = cmd->Op->Page->Name;
      if(!cmd->Op->Page->IsTree)
      {
        out->PageX = ((wStackOp *)cmd->Op)->PosX;
        out->PageY = ((wStackOp *)cmd->Op)->PosY;
      }
    }

    // ..

    out->Prepare();
    if(out->Error)
      return 0;
    if(cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();
    }
  ;
#line 93 "wz4_modmtrl_ops.cpp"
    return 1;
  }
}

sInt ModMtrlActModMaterial(wOp *op,sInt code,sInt pos)
{
  ModMtrlParaModMaterial sUNUSED *para = (ModMtrlParaModMaterial *)(op->EditData); para;
#line 173 "wz4_modmtrl_ops.ops"

    if(code==1)
    { 
      if(op->RefObj)
      {
        ModMtrl *mtrl = (ModMtrl*) op->RefObj;
        if(mtrl && mtrl->ShaderLog.GetCount())
          App->PopupText(mtrl->ShaderLog.Get());
      }
      return 0;
    }
    if(code==2)
    { 
      return 1;
    }
    if(code==3)
    {
      if(para->AllowLight==0) para->AllowLight=~0;
      else para->AllowLight = 0;
      return 1;
    }
    if(code==4)
    {
      if(para->AllowShadow==0) para->AllowShadow=~0;
      else para->AllowShadow = 0;
      return 1;
    }

    return 0;
  ;
#line 132 "wz4_modmtrl_ops.cpp"
}

void ModMtrlGuiModMaterial(wGridFrameHelper &gh,wOp *op)
{
  ModMtrlParaModMaterial sUNUSED *para = (ModMtrlParaModMaterial *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0zoff|zread|zwrite|zon:*4Doublesided|Singlesided|Inverted",gh.ChangeMsg);

  gh.Label(L"ColorMask");
  gh.Flags(&para->Flags,L"*8-|MaskAlpha:*9-|MaskRed:*10-|MaskGreen:*11-|MaskBlue",gh.ChangeMsg);

  gh.Label(L"Blend");
  gh.Flags(&para->Blend,L"solid|alpha premul|add|sub|mul|mul2|addsmooth|alpha plain|const alpha:*4dest alpha from shader|dest alpha unchanged|dest alpha = 0|dest alpha blend",gh.LayoutMsg);

  gh.Label(L"AlphaTest");
  gh.Flags(&para->AlphaTest,L"|||inverted|on|||off",gh.LayoutMsg);

  if((((para->AlphaTest&0x00ff)!=0x0007)||((para->Blend&0x000f)==0x0008)))
  {
    sIntControl *int_AlphaRef = gh.Int(&para->AlphaRef,0,255,1.000000f);
    int_AlphaRef->Default = 0x00000000; int_AlphaRef->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummy0");
    gh.BeginTied();
    sIntControl *int_dummy0_0 = gh.Int(&para->dummy0[0],0,255,0.125000f);
    int_dummy0_0->Default = 0x00000000; int_dummy0_0->RightStep = 0.125000f;
    sIntControl *int_dummy0_1 = gh.Int(&para->dummy0[1],0,255,0.125000f);
    int_dummy0_1->Default = 0x00000000; int_dummy0_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.ControlWidth = 1;
  gh.Label(L"AllowLight");
  gh.Flags(&para->AllowLight,L"-| 0:*1-| 1:*2-| 2:*3-| 3:*4-| 4:*5-| 5:*6-| 6:*7-| 7",gh.ChangeMsg);
  gh.ControlWidth = 2;

  gh.ControlWidth = 1;
  gh.ActionMsg.Code = 3;
  gh.PushButton(L"All",gh.ActionMsg);
  gh.ControlWidth = 2;

  gh.ControlWidth = 1;
  gh.Label(L"AllowShadow");
  gh.Flags(&para->AllowShadow,L"-| 0:*1-| 1:*2-| 2:*3-| 3:*4-| 4:*5-| 5:*6-| 6:*7-| 7",gh.ChangeMsg);
  gh.ControlWidth = 2;

  gh.ControlWidth = 1;
  gh.ActionMsg.Code = 4;
  gh.PushButton(L"All",gh.ActionMsg);
  gh.ControlWidth = 2;

  gh.Label(L"AllowFeatures");
  gh.Flags(&para->AllowFeatures,L"-|Fog:*1-|GroundFog:*2-|ClipPlanes",gh.ChangeMsg);

  gh.Label(L"FeatureFlags");
  gh.Flags(&para->FeatureFlags,L"-|FogIsBlack:*1CastShadow|-:*2Ambient|-:*3-|swap fogs:*8-|fog alpha",gh.ChangeMsg);

  gh.Label(L"Emissive");
  gh.Flags(&para->FeatureFlags,L"*4Add|Screen:*6-|suppress reflection rim|supress reflection center",gh.ChangeMsg);

  gh.Label(L"Cast Shaodw in LightEnvironment");
  gh.Flags(&para->FeatureFlags,L"*9my own|all",gh.ChangeMsg);

  gh.Label(L"Normals");
  gh.Flags(&para->FeatureFlags,L"*10precise|compact:*11-|double sided",gh.ChangeMsg);

  gh.Group(L"debug");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Shadercode",gh.ActionMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"FlushShaders",gh.ActionMsg);
}

void ModMtrlDefModMaterial(wOp *op)
{
  ModMtrlParaModMaterial sUNUSED *para = (ModMtrlParaModMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000013;
  para->AlphaTest = 0x00000007;
  para->AllowLight = 0xffffffff;
  para->AllowShadow = 0xffffffff;
  para->AllowFeatures = 0xffffffff;
}

void ModMtrlBindModMaterial(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"alpharef"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"dummy0"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"dummy0"),val);
}
void ModMtrlBind2ModMaterial(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[18];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"colormask");
    name[2] = sPoolString(L"blend");
    name[3] = sPoolString(L"alphatest");
    name[4] = sPoolString(L"alpharef");
    name[5] = sPoolString(L"dummy0");
    name[6] = sPoolString(L"allowlight");
    name[7] = sPoolString(L"all");
    name[8] = sPoolString(L"allowshadow");
    name[9] = sPoolString(L"all");
    name[10] = sPoolString(L"allowfeatures");
    name[11] = sPoolString(L"featureflags");
    name[12] = sPoolString(L"emissive");
    name[13] = sPoolString(L"featureflags");
    name[14] = sPoolString(L"normals");
    name[15] = sPoolString(L"debug");
    name[16] = sPoolString(L"shadercode");
    name[17] = sPoolString(L"flushshaders");
  }
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeInt,2,cmd->Data+4);
}
void ModMtrlBind3ModMaterial(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import alpharef : int;\n");
  tb.PrintF(L"  import dummy0 : int[2];\n");
}
const sChar *ModMtrlWikiModMaterial =
L"= ModMtrl : ModMaterial\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ModMaterial\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModMtrl\n"
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
L" !i ModShader\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
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
L" !i Doublesided\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Singlesided\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Inverted\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ColorMask\n"
L" !i Flags\n"
L" !i MaskAlpha\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i MaskRed\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i MaskGreen\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i MaskBlue\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Blend\n"
L" !i Blend\n"
L" !i solid\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha premul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
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
L" !i addsmooth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha plain\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i const alpha\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
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
L" !i AlphaTest\n"
L" !i AlphaTest\n"
L" !i inverted\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i off\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i AlphaRef\n"
L" !i AlphaRef\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i dummy0\n"
L" !i dummy0\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i AllowLight\n"
L" !i AllowLight\n"
L" !i 0\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i All\n"
L" !i All\n"
L" !i action\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i AllowShadow\n"
L" !i AllowShadow\n"
L" !i 0\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i All\n"
L" !i All\n"
L" !i action\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i AllowFeatures\n"
L" !i AllowFeatures\n"
L" !i Fog\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i GroundFog\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i ClipPlanes\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i FeatureFlags\n"
L" !i FeatureFlags\n"
L" !i FogIsBlack\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i CastShadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Ambient\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i swap fogs\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i fog alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Emissive\n"
L" !i FeatureFlags\n"
L" !i Add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Screen\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i suppress reflection rim\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i supress reflection center\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Cast Shaodw in LightEnvironment\n"
L" !i FeatureFlags\n"
L" !i my own\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i all\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Normals\n"
L" !i FeatureFlags\n"
L" !i precise\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i compact\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i double sided\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4RenderCmdModLight(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaModLight sUNUSED *para = (Wz4RenderParaModLight *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 608 "wz4_modmtrl_ops.ops"

    RNModLight *node = new RNModLight;    
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 751 "wz4_modmtrl_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndModLight(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaModLight sUNUSED *para = (Wz4RenderParaModLight *)(op->EditData); para;
#line 660 "wz4_modmtrl_ops.ops"

    sInt mode[8];
    sVector31 *ppos[8];
    sVector30 *pdir[8];

    sInt max = 0;
    mode[max] = para->Mode0; ppos[max] = &para->Pos0; pdir[max] = &para->Dir0; max++;
    mode[max] = para->Mode1; ppos[max] = &para->Pos1; pdir[max] = &para->Dir1; max++;
    mode[max] = para->Mode2; ppos[max] = &para->Pos2; pdir[max] = &para->Dir2; max++;
    mode[max] = para->Mode3; ppos[max] = &para->Pos3; pdir[max] = &para->Dir3; max++;
    mode[max] = para->Mode4; ppos[max] = &para->Pos4; pdir[max] = &para->Dir4; max++;
    mode[max] = para->Mode5; ppos[max] = &para->Pos5; pdir[max] = &para->Dir5; max++;
    mode[max] = para->Mode6; ppos[max] = &para->Pos6; pdir[max] = &para->Dir6; max++;
    mode[max] = para->Mode7; ppos[max] = &para->Pos7; pdir[max] = &para->Dir7; max++;

    for(sInt i=0;i<max;i++)
    {
      if((mode[i]&15)>=2) 
      {
        pi.Handle3D(op,i+1,*ppos[i],wHM_PLANE);
        pi.Line3D(*ppos[i],sVector31(ppos[i]->x,0,ppos[i]->z));
      }
    }
  ;
#line 784 "wz4_modmtrl_ops.cpp"
}

sInt Wz4RenderActModLight(wOp *op,sInt code,sInt pos)
{
  Wz4RenderParaModLight sUNUSED *para = (Wz4RenderParaModLight *)(op->EditData); para;
#line 615 "wz4_modmtrl_ops.ops"

    if(code)
    {
      sU32 am=0;
      sU32 bm=0;
      sU32 cm=0;
      sInt bs=0;
      sInt cs=0;

      switch(code)
      {
      case 1:     // RG
        am = 0x0000ff;
        bm = 0xff0000; bs = 8;
        cm = 0x00ff00; cs = 8;
        break;
      case 2:     // RB
        am = 0x00ff00;
        bm = 0xff0000; bs = 16;
        cm = 0x0000ff; cs = 16;
        break;
      case 3:     // GB
        am = 0xff0000;
        bm = 0x00ff00; bs = 8;
        cm = 0x0000ff; cs = 8;
        break;
      }

      #define SWAPPER(col) col = (col&am) | ((col&bm)>>bs) | ((col&cm)<<cs) 
      SWAPPER(para->Ambient);
      SWAPPER(para->Front0);  SWAPPER(para->Back0);  SWAPPER(para->Middle0);
      SWAPPER(para->Front1);  SWAPPER(para->Back1);  SWAPPER(para->Middle1);
      SWAPPER(para->Front2);  SWAPPER(para->Back2);  SWAPPER(para->Middle2);
      SWAPPER(para->Front3);  SWAPPER(para->Back3);  SWAPPER(para->Middle3);
      SWAPPER(para->Front4);  SWAPPER(para->Back4);  SWAPPER(para->Middle4);
      SWAPPER(para->Front5);  SWAPPER(para->Back5);  SWAPPER(para->Middle5);
      SWAPPER(para->Front6);  SWAPPER(para->Back6);  SWAPPER(para->Middle6);
      SWAPPER(para->Front7);  SWAPPER(para->Back7);  SWAPPER(para->Middle7);
      #undef SWAPPER
      
      return 1;
    }
    return 0;
  ;
#line 835 "wz4_modmtrl_ops.cpp"
}

void Wz4RenderGuiModLight(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaModLight sUNUSED *para = (Wz4RenderParaModLight *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Swap_RG",gh.ActionMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"Swap_RB",gh.ActionMsg);

  gh.ActionMsg.Code = 3;
  gh.PushButton(L"Swap_GB",gh.ActionMsg);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Ambient");
  gh.ColorPick(&para->Ambient,L"rgb",0);

  gh.Group(L"light 0");

  gh.Label(L"Mode0");
  gh.Flags(&para->Mode0,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode0&0x000f))
  {
    gh.Flags(&para->Mode0,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode0&0x000f)&&((para->Mode0&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode0,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode0&0x000f))
  {
    gh.Label(L"* Front0");
    gh.ColorPick(&para->Front0,L"rgb",0);

    sFloatControl *float_FrontAmp0 = gh.Float(&para->FrontAmp0,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp0->Default = 1.000000f; float_FrontAmp0->RightStep = 0.125000f;

    gh.Label(L"* Middle0");
    gh.ColorPick(&para->Middle0,L"rgb",0);

    sFloatControl *float_MiddleAmp0 = gh.Float(&para->MiddleAmp0,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp0->Default = 1.000000f; float_MiddleAmp0->RightStep = 0.125000f;

    gh.Label(L"* Back0");
    gh.ColorPick(&para->Back0,L"rgb",0);

    sFloatControl *float_BackAmp0 = gh.Float(&para->BackAmp0,-1024.00f,1024.000f,0.010000f);
    float_BackAmp0->Default = 1.000000f; float_BackAmp0->RightStep = 0.125000f;

  }
  if(((para->Mode0&0x000f)&&((para->Mode0&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos0");
    gh.BeginTied();
    sFloatControl *float_Pos0_0 = gh.Float(&para->Pos0.x,-10000000, 10000000,0.010000f);
    float_Pos0_0->Default = 0.000000f; float_Pos0_0->RightStep = 0.125000f;
    sFloatControl *float_Pos0_1 = gh.Float(&para->Pos0.y,-10000000, 10000000,0.010000f);
    float_Pos0_1->Default = 0.000000f; float_Pos0_1->RightStep = 0.125000f;
    sFloatControl *float_Pos0_2 = gh.Float(&para->Pos0.z,-10000000, 10000000,0.010000f);
    float_Pos0_2->Default = 0.000000f; float_Pos0_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode0&0x000f)&&((para->Mode0&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir0");
    gh.BeginTied();
    sFloatControl *float_Dir0_0 = gh.Float(&para->Dir0.x,-10000000, 10000000,0.010000f);
    float_Dir0_0->Default = 0.000000f; float_Dir0_0->RightStep = 0.125000f;
    sFloatControl *float_Dir0_1 = gh.Float(&para->Dir0.y,-10000000, 10000000,0.010000f);
    float_Dir0_1->Default = 0.000000f; float_Dir0_1->RightStep = 0.125000f;
    sFloatControl *float_Dir0_2 = gh.Float(&para->Dir0.z,-10000000, 10000000,0.010000f);
    float_Dir0_2->Default = 0.000000f; float_Dir0_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode0&0x000f)&&((para->Mode0&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range0");
    sFloatControl *float_Range0 = gh.Float(&para->Range0,0.000000f, 10000000,0.010000f);
    float_Range0->Default = 16.00000f; float_Range0->RightStep = 0.125000f;

  }
  if((((para->Mode0&0x000f)&&((para->Mode0&0x000f)==0x0003))&&(para->Mode0&0x0020)))
  {
    gh.Label(L"* Inner0");
    sFloatControl *float_Inner0 = gh.Float(&para->Inner0,0.000000f,1.000000f,0.010000f);
    float_Inner0->Default = 0.200000f; float_Inner0->RightStep = 0.125000f;

  }
  if(((para->Mode0&0x000f)&&((para->Mode0&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer0");
    sFloatControl *float_Outer0 = gh.Float(&para->Outer0,0.000000f,1.000000f,0.010000f);
    float_Outer0->Default = 0.500000f; float_Outer0->RightStep = 0.125000f;

  }
  if((((para->Mode0&0x000f)&&((para->Mode0&0x000f)==0x0003))&&(para->Mode0&0x0040)))
  {
    gh.Label(L"* Falloff0");
    sFloatControl *float_Falloff0 = gh.Float(&para->Falloff0,0.000000f,64.00000f,0.010000f);
    float_Falloff0->Default = 1.000000f; float_Falloff0->RightStep = 0.125000f;

  }
  if(((para->Mode0&0x000f)&&(para->Mode0&0x0010)))
  {
    gh.Label(L"* ShadowSize0");
    gh.Flags(&para->ShadowSize0,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter0");
    gh.Flags(&para->ShadowSize0,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias0");
    sFloatControl *float_ShadowBaseBias0 = gh.Float(&para->ShadowBaseBias0,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias0->Default = 0.500000f; float_ShadowBaseBias0->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter0");
    sFloatControl *float_ShadowFilter0 = gh.Float(&para->ShadowFilter0,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter0->Default = 0.500000f; float_ShadowFilter0->RightStep = 0.125000f;

  }
  if((((para->Mode0&0x000f)&&(para->Mode0&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias0");
    sFloatControl *float_ShadowSlopeBias0 = gh.Float(&para->ShadowSlopeBias0,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias0->Default = 0.500000f; float_ShadowSlopeBias0->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya0");
    gh.BeginTied();
    sFloatControl *float_dummya0_0 = gh.Float(&para->dummya0[0],0.000000f,255.0000f,0.125000f);
    float_dummya0_0->Default = 0.000000f; float_dummya0_0->RightStep = 0.125000f;
    sFloatControl *float_dummya0_1 = gh.Float(&para->dummya0[1],0.000000f,255.0000f,0.125000f);
    float_dummya0_1->Default = 0.000000f; float_dummya0_1->RightStep = 0.125000f;
    sFloatControl *float_dummya0_2 = gh.Float(&para->dummya0[2],0.000000f,255.0000f,0.125000f);
    float_dummya0_2->Default = 0.000000f; float_dummya0_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb0");
    gh.BeginTied();
    sFloatControl *float_dummyb0_0 = gh.Float(&para->dummyb0[0],0.000000f,255.0000f,0.125000f);
    float_dummyb0_0->Default = 0.000000f; float_dummyb0_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb0_1 = gh.Float(&para->dummyb0[1],0.000000f,255.0000f,0.125000f);
    float_dummyb0_1->Default = 0.000000f; float_dummyb0_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb0_2 = gh.Float(&para->dummyb0[2],0.000000f,255.0000f,0.125000f);
    float_dummyb0_2->Default = 0.000000f; float_dummyb0_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb0_3 = gh.Float(&para->dummyb0[3],0.000000f,255.0000f,0.125000f);
    float_dummyb0_3->Default = 0.000000f; float_dummyb0_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 1");

  gh.Label(L"Mode1");
  gh.Flags(&para->Mode1,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode1&0x000f))
  {
    gh.Flags(&para->Mode1,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode1&0x000f)&&((para->Mode1&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode1,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode1&0x000f))
  {
    gh.Label(L"* Front1");
    gh.ColorPick(&para->Front1,L"rgb",0);

    sFloatControl *float_FrontAmp1 = gh.Float(&para->FrontAmp1,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp1->Default = 1.000000f; float_FrontAmp1->RightStep = 0.125000f;

    gh.Label(L"* Middle1");
    gh.ColorPick(&para->Middle1,L"rgb",0);

    sFloatControl *float_MiddleAmp1 = gh.Float(&para->MiddleAmp1,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp1->Default = 1.000000f; float_MiddleAmp1->RightStep = 0.125000f;

    gh.Label(L"* Back1");
    gh.ColorPick(&para->Back1,L"rgb",0);

    sFloatControl *float_BackAmp1 = gh.Float(&para->BackAmp1,-1024.00f,1024.000f,0.010000f);
    float_BackAmp1->Default = 1.000000f; float_BackAmp1->RightStep = 0.125000f;

  }
  if(((para->Mode1&0x000f)&&((para->Mode1&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos1");
    gh.BeginTied();
    sFloatControl *float_Pos1_0 = gh.Float(&para->Pos1.x,-10000000, 10000000,0.010000f);
    float_Pos1_0->Default = 0.000000f; float_Pos1_0->RightStep = 0.125000f;
    sFloatControl *float_Pos1_1 = gh.Float(&para->Pos1.y,-10000000, 10000000,0.010000f);
    float_Pos1_1->Default = 0.000000f; float_Pos1_1->RightStep = 0.125000f;
    sFloatControl *float_Pos1_2 = gh.Float(&para->Pos1.z,-10000000, 10000000,0.010000f);
    float_Pos1_2->Default = 0.000000f; float_Pos1_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode1&0x000f)&&((para->Mode1&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir1");
    gh.BeginTied();
    sFloatControl *float_Dir1_0 = gh.Float(&para->Dir1.x,-10000000, 10000000,0.010000f);
    float_Dir1_0->Default = 0.000000f; float_Dir1_0->RightStep = 0.125000f;
    sFloatControl *float_Dir1_1 = gh.Float(&para->Dir1.y,-10000000, 10000000,0.010000f);
    float_Dir1_1->Default = 0.000000f; float_Dir1_1->RightStep = 0.125000f;
    sFloatControl *float_Dir1_2 = gh.Float(&para->Dir1.z,-10000000, 10000000,0.010000f);
    float_Dir1_2->Default = 0.000000f; float_Dir1_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode1&0x000f)&&((para->Mode1&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range1");
    sFloatControl *float_Range1 = gh.Float(&para->Range1,0.000000f, 10000000,0.010000f);
    float_Range1->Default = 16.00000f; float_Range1->RightStep = 0.125000f;

  }
  if((((para->Mode1&0x000f)&&((para->Mode1&0x000f)==0x0003))&&(para->Mode1&0x0020)))
  {
    gh.Label(L"* Inner1");
    sFloatControl *float_Inner1 = gh.Float(&para->Inner1,0.000000f,1.000000f,0.010000f);
    float_Inner1->Default = 0.200000f; float_Inner1->RightStep = 0.125000f;

  }
  if(((para->Mode1&0x000f)&&((para->Mode1&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer1");
    sFloatControl *float_Outer1 = gh.Float(&para->Outer1,0.000000f,1.000000f,0.010000f);
    float_Outer1->Default = 0.500000f; float_Outer1->RightStep = 0.125000f;

  }
  if((((para->Mode1&0x000f)&&((para->Mode1&0x000f)==0x0003))&&(para->Mode1&0x0040)))
  {
    gh.Label(L"* Falloff1");
    sFloatControl *float_Falloff1 = gh.Float(&para->Falloff1,0.000000f,64.00000f,0.010000f);
    float_Falloff1->Default = 1.000000f; float_Falloff1->RightStep = 0.125000f;

  }
  if(((para->Mode1&0x000f)&&(para->Mode1&0x0010)))
  {
    gh.Label(L"* ShadowSize1");
    gh.Flags(&para->ShadowSize1,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter1");
    gh.Flags(&para->ShadowSize1,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias1");
    sFloatControl *float_ShadowBaseBias1 = gh.Float(&para->ShadowBaseBias1,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias1->Default = 0.500000f; float_ShadowBaseBias1->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter1");
    sFloatControl *float_ShadowFilter1 = gh.Float(&para->ShadowFilter1,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter1->Default = 0.500000f; float_ShadowFilter1->RightStep = 0.125000f;

  }
  if((((para->Mode1&0x000f)&&(para->Mode1&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias1");
    sFloatControl *float_ShadowSlopeBias1 = gh.Float(&para->ShadowSlopeBias1,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias1->Default = 0.500000f; float_ShadowSlopeBias1->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya1");
    gh.BeginTied();
    sFloatControl *float_dummya1_0 = gh.Float(&para->dummya1[0],0.000000f,255.0000f,0.125000f);
    float_dummya1_0->Default = 0.000000f; float_dummya1_0->RightStep = 0.125000f;
    sFloatControl *float_dummya1_1 = gh.Float(&para->dummya1[1],0.000000f,255.0000f,0.125000f);
    float_dummya1_1->Default = 0.000000f; float_dummya1_1->RightStep = 0.125000f;
    sFloatControl *float_dummya1_2 = gh.Float(&para->dummya1[2],0.000000f,255.0000f,0.125000f);
    float_dummya1_2->Default = 0.000000f; float_dummya1_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb1");
    gh.BeginTied();
    sFloatControl *float_dummyb1_0 = gh.Float(&para->dummyb1[0],0.000000f,255.0000f,0.125000f);
    float_dummyb1_0->Default = 0.000000f; float_dummyb1_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb1_1 = gh.Float(&para->dummyb1[1],0.000000f,255.0000f,0.125000f);
    float_dummyb1_1->Default = 0.000000f; float_dummyb1_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb1_2 = gh.Float(&para->dummyb1[2],0.000000f,255.0000f,0.125000f);
    float_dummyb1_2->Default = 0.000000f; float_dummyb1_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb1_3 = gh.Float(&para->dummyb1[3],0.000000f,255.0000f,0.125000f);
    float_dummyb1_3->Default = 0.000000f; float_dummyb1_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 2");

  gh.Label(L"Mode2");
  gh.Flags(&para->Mode2,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode2&0x000f))
  {
    gh.Flags(&para->Mode2,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode2&0x000f)&&((para->Mode2&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode2,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode2&0x000f))
  {
    gh.Label(L"* Front2");
    gh.ColorPick(&para->Front2,L"rgb",0);

    sFloatControl *float_FrontAmp2 = gh.Float(&para->FrontAmp2,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp2->Default = 1.000000f; float_FrontAmp2->RightStep = 0.125000f;

    gh.Label(L"* Middle2");
    gh.ColorPick(&para->Middle2,L"rgb",0);

    sFloatControl *float_MiddleAmp2 = gh.Float(&para->MiddleAmp2,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp2->Default = 1.000000f; float_MiddleAmp2->RightStep = 0.125000f;

    gh.Label(L"* Back2");
    gh.ColorPick(&para->Back2,L"rgb",0);

    sFloatControl *float_BackAmp2 = gh.Float(&para->BackAmp2,-1024.00f,1024.000f,0.010000f);
    float_BackAmp2->Default = 1.000000f; float_BackAmp2->RightStep = 0.125000f;

  }
  if(((para->Mode2&0x000f)&&((para->Mode2&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos2");
    gh.BeginTied();
    sFloatControl *float_Pos2_0 = gh.Float(&para->Pos2.x,-10000000, 10000000,0.010000f);
    float_Pos2_0->Default = 0.000000f; float_Pos2_0->RightStep = 0.125000f;
    sFloatControl *float_Pos2_1 = gh.Float(&para->Pos2.y,-10000000, 10000000,0.010000f);
    float_Pos2_1->Default = 0.000000f; float_Pos2_1->RightStep = 0.125000f;
    sFloatControl *float_Pos2_2 = gh.Float(&para->Pos2.z,-10000000, 10000000,0.010000f);
    float_Pos2_2->Default = 0.000000f; float_Pos2_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode2&0x000f)&&((para->Mode2&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir2");
    gh.BeginTied();
    sFloatControl *float_Dir2_0 = gh.Float(&para->Dir2.x,-10000000, 10000000,0.010000f);
    float_Dir2_0->Default = 0.000000f; float_Dir2_0->RightStep = 0.125000f;
    sFloatControl *float_Dir2_1 = gh.Float(&para->Dir2.y,-10000000, 10000000,0.010000f);
    float_Dir2_1->Default = 0.000000f; float_Dir2_1->RightStep = 0.125000f;
    sFloatControl *float_Dir2_2 = gh.Float(&para->Dir2.z,-10000000, 10000000,0.010000f);
    float_Dir2_2->Default = 0.000000f; float_Dir2_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode2&0x000f)&&((para->Mode2&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range2");
    sFloatControl *float_Range2 = gh.Float(&para->Range2,0.000000f, 10000000,0.010000f);
    float_Range2->Default = 16.00000f; float_Range2->RightStep = 0.125000f;

  }
  if((((para->Mode2&0x000f)&&((para->Mode2&0x000f)==0x0003))&&(para->Mode2&0x0020)))
  {
    gh.Label(L"* Inner2");
    sFloatControl *float_Inner2 = gh.Float(&para->Inner2,0.000000f,1.000000f,0.010000f);
    float_Inner2->Default = 0.200000f; float_Inner2->RightStep = 0.125000f;

  }
  if(((para->Mode2&0x000f)&&((para->Mode2&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer2");
    sFloatControl *float_Outer2 = gh.Float(&para->Outer2,0.000000f,1.000000f,0.010000f);
    float_Outer2->Default = 0.500000f; float_Outer2->RightStep = 0.125000f;

  }
  if((((para->Mode2&0x000f)&&((para->Mode2&0x000f)==0x0003))&&(para->Mode2&0x0040)))
  {
    gh.Label(L"* Falloff2");
    sFloatControl *float_Falloff2 = gh.Float(&para->Falloff2,0.000000f,64.00000f,0.010000f);
    float_Falloff2->Default = 1.000000f; float_Falloff2->RightStep = 0.125000f;

  }
  if(((para->Mode2&0x000f)&&(para->Mode2&0x0010)))
  {
    gh.Label(L"* ShadowSize2");
    gh.Flags(&para->ShadowSize2,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter2");
    gh.Flags(&para->ShadowSize2,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias2");
    sFloatControl *float_ShadowBaseBias2 = gh.Float(&para->ShadowBaseBias2,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias2->Default = 0.500000f; float_ShadowBaseBias2->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter2");
    sFloatControl *float_ShadowFilter2 = gh.Float(&para->ShadowFilter2,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter2->Default = 0.500000f; float_ShadowFilter2->RightStep = 0.125000f;

  }
  if((((para->Mode2&0x000f)&&(para->Mode2&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias2");
    sFloatControl *float_ShadowSlopeBias2 = gh.Float(&para->ShadowSlopeBias2,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias2->Default = 0.500000f; float_ShadowSlopeBias2->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya2");
    gh.BeginTied();
    sFloatControl *float_dummya2_0 = gh.Float(&para->dummya2[0],0.000000f,255.0000f,0.125000f);
    float_dummya2_0->Default = 0.000000f; float_dummya2_0->RightStep = 0.125000f;
    sFloatControl *float_dummya2_1 = gh.Float(&para->dummya2[1],0.000000f,255.0000f,0.125000f);
    float_dummya2_1->Default = 0.000000f; float_dummya2_1->RightStep = 0.125000f;
    sFloatControl *float_dummya2_2 = gh.Float(&para->dummya2[2],0.000000f,255.0000f,0.125000f);
    float_dummya2_2->Default = 0.000000f; float_dummya2_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb2");
    gh.BeginTied();
    sFloatControl *float_dummyb2_0 = gh.Float(&para->dummyb2[0],0.000000f,255.0000f,0.125000f);
    float_dummyb2_0->Default = 0.000000f; float_dummyb2_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb2_1 = gh.Float(&para->dummyb2[1],0.000000f,255.0000f,0.125000f);
    float_dummyb2_1->Default = 0.000000f; float_dummyb2_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb2_2 = gh.Float(&para->dummyb2[2],0.000000f,255.0000f,0.125000f);
    float_dummyb2_2->Default = 0.000000f; float_dummyb2_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb2_3 = gh.Float(&para->dummyb2[3],0.000000f,255.0000f,0.125000f);
    float_dummyb2_3->Default = 0.000000f; float_dummyb2_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 3");

  gh.Label(L"Mode3");
  gh.Flags(&para->Mode3,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode3&0x000f))
  {
    gh.Flags(&para->Mode3,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode3&0x000f)&&((para->Mode3&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode3,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode3&0x000f))
  {
    gh.Label(L"* Front3");
    gh.ColorPick(&para->Front3,L"rgb",0);

    sFloatControl *float_FrontAmp3 = gh.Float(&para->FrontAmp3,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp3->Default = 1.000000f; float_FrontAmp3->RightStep = 0.125000f;

    gh.Label(L"* Middle3");
    gh.ColorPick(&para->Middle3,L"rgb",0);

    sFloatControl *float_MiddleAmp3 = gh.Float(&para->MiddleAmp3,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp3->Default = 1.000000f; float_MiddleAmp3->RightStep = 0.125000f;

    gh.Label(L"* Back3");
    gh.ColorPick(&para->Back3,L"rgb",0);

    sFloatControl *float_BackAmp3 = gh.Float(&para->BackAmp3,-1024.00f,1024.000f,0.010000f);
    float_BackAmp3->Default = 1.000000f; float_BackAmp3->RightStep = 0.125000f;

  }
  if(((para->Mode3&0x000f)&&((para->Mode3&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos3");
    gh.BeginTied();
    sFloatControl *float_Pos3_0 = gh.Float(&para->Pos3.x,-10000000, 10000000,0.010000f);
    float_Pos3_0->Default = 0.000000f; float_Pos3_0->RightStep = 0.125000f;
    sFloatControl *float_Pos3_1 = gh.Float(&para->Pos3.y,-10000000, 10000000,0.010000f);
    float_Pos3_1->Default = 0.000000f; float_Pos3_1->RightStep = 0.125000f;
    sFloatControl *float_Pos3_2 = gh.Float(&para->Pos3.z,-10000000, 10000000,0.010000f);
    float_Pos3_2->Default = 0.000000f; float_Pos3_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode3&0x000f)&&((para->Mode3&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir3");
    gh.BeginTied();
    sFloatControl *float_Dir3_0 = gh.Float(&para->Dir3.x,-10000000, 10000000,0.010000f);
    float_Dir3_0->Default = 0.000000f; float_Dir3_0->RightStep = 0.125000f;
    sFloatControl *float_Dir3_1 = gh.Float(&para->Dir3.y,-10000000, 10000000,0.010000f);
    float_Dir3_1->Default = 0.000000f; float_Dir3_1->RightStep = 0.125000f;
    sFloatControl *float_Dir3_2 = gh.Float(&para->Dir3.z,-10000000, 10000000,0.010000f);
    float_Dir3_2->Default = 0.000000f; float_Dir3_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode3&0x000f)&&((para->Mode3&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range3");
    sFloatControl *float_Range3 = gh.Float(&para->Range3,0.000000f, 10000000,0.010000f);
    float_Range3->Default = 16.00000f; float_Range3->RightStep = 0.125000f;

  }
  if((((para->Mode3&0x000f)&&((para->Mode3&0x000f)==0x0003))&&(para->Mode3&0x0020)))
  {
    gh.Label(L"* Inner3");
    sFloatControl *float_Inner3 = gh.Float(&para->Inner3,0.000000f,1.000000f,0.010000f);
    float_Inner3->Default = 0.200000f; float_Inner3->RightStep = 0.125000f;

  }
  if(((para->Mode3&0x000f)&&((para->Mode3&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer3");
    sFloatControl *float_Outer3 = gh.Float(&para->Outer3,0.000000f,1.000000f,0.010000f);
    float_Outer3->Default = 0.500000f; float_Outer3->RightStep = 0.125000f;

  }
  if((((para->Mode3&0x000f)&&((para->Mode3&0x000f)==0x0003))&&(para->Mode3&0x0040)))
  {
    gh.Label(L"* Falloff3");
    sFloatControl *float_Falloff3 = gh.Float(&para->Falloff3,0.000000f,64.00000f,0.010000f);
    float_Falloff3->Default = 1.000000f; float_Falloff3->RightStep = 0.125000f;

  }
  if(((para->Mode3&0x000f)&&(para->Mode3&0x0010)))
  {
    gh.Label(L"* ShadowSize3");
    gh.Flags(&para->ShadowSize3,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter3");
    gh.Flags(&para->ShadowSize3,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias3");
    sFloatControl *float_ShadowBaseBias3 = gh.Float(&para->ShadowBaseBias3,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias3->Default = 0.500000f; float_ShadowBaseBias3->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter3");
    sFloatControl *float_ShadowFilter3 = gh.Float(&para->ShadowFilter3,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter3->Default = 0.500000f; float_ShadowFilter3->RightStep = 0.125000f;

  }
  if((((para->Mode3&0x000f)&&(para->Mode3&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias3");
    sFloatControl *float_ShadowSlopeBias3 = gh.Float(&para->ShadowSlopeBias3,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias3->Default = 0.500000f; float_ShadowSlopeBias3->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya3");
    gh.BeginTied();
    sFloatControl *float_dummya3_0 = gh.Float(&para->dummya3[0],0.000000f,255.0000f,0.125000f);
    float_dummya3_0->Default = 0.000000f; float_dummya3_0->RightStep = 0.125000f;
    sFloatControl *float_dummya3_1 = gh.Float(&para->dummya3[1],0.000000f,255.0000f,0.125000f);
    float_dummya3_1->Default = 0.000000f; float_dummya3_1->RightStep = 0.125000f;
    sFloatControl *float_dummya3_2 = gh.Float(&para->dummya3[2],0.000000f,255.0000f,0.125000f);
    float_dummya3_2->Default = 0.000000f; float_dummya3_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb3");
    gh.BeginTied();
    sFloatControl *float_dummyb3_0 = gh.Float(&para->dummyb3[0],0.000000f,255.0000f,0.125000f);
    float_dummyb3_0->Default = 0.000000f; float_dummyb3_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb3_1 = gh.Float(&para->dummyb3[1],0.000000f,255.0000f,0.125000f);
    float_dummyb3_1->Default = 0.000000f; float_dummyb3_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb3_2 = gh.Float(&para->dummyb3[2],0.000000f,255.0000f,0.125000f);
    float_dummyb3_2->Default = 0.000000f; float_dummyb3_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb3_3 = gh.Float(&para->dummyb3[3],0.000000f,255.0000f,0.125000f);
    float_dummyb3_3->Default = 0.000000f; float_dummyb3_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 4");

  gh.Label(L"Mode4");
  gh.Flags(&para->Mode4,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode4&0x000f))
  {
    gh.Flags(&para->Mode4,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode4&0x000f)&&((para->Mode4&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode4,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode4&0x000f))
  {
    gh.Label(L"* Front4");
    gh.ColorPick(&para->Front4,L"rgb",0);

    sFloatControl *float_FrontAmp4 = gh.Float(&para->FrontAmp4,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp4->Default = 1.000000f; float_FrontAmp4->RightStep = 0.125000f;

    gh.Label(L"* Middle4");
    gh.ColorPick(&para->Middle4,L"rgb",0);

    sFloatControl *float_MiddleAmp4 = gh.Float(&para->MiddleAmp4,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp4->Default = 1.000000f; float_MiddleAmp4->RightStep = 0.125000f;

    gh.Label(L"* Back4");
    gh.ColorPick(&para->Back4,L"rgb",0);

    sFloatControl *float_BackAmp4 = gh.Float(&para->BackAmp4,-1024.00f,1024.000f,0.010000f);
    float_BackAmp4->Default = 1.000000f; float_BackAmp4->RightStep = 0.125000f;

  }
  if(((para->Mode4&0x000f)&&((para->Mode4&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos4");
    gh.BeginTied();
    sFloatControl *float_Pos4_0 = gh.Float(&para->Pos4.x,-10000000, 10000000,0.010000f);
    float_Pos4_0->Default = 0.000000f; float_Pos4_0->RightStep = 0.125000f;
    sFloatControl *float_Pos4_1 = gh.Float(&para->Pos4.y,-10000000, 10000000,0.010000f);
    float_Pos4_1->Default = 0.000000f; float_Pos4_1->RightStep = 0.125000f;
    sFloatControl *float_Pos4_2 = gh.Float(&para->Pos4.z,-10000000, 10000000,0.010000f);
    float_Pos4_2->Default = 0.000000f; float_Pos4_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode4&0x000f)&&((para->Mode4&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir4");
    gh.BeginTied();
    sFloatControl *float_Dir4_0 = gh.Float(&para->Dir4.x,-10000000, 10000000,0.010000f);
    float_Dir4_0->Default = 0.000000f; float_Dir4_0->RightStep = 0.125000f;
    sFloatControl *float_Dir4_1 = gh.Float(&para->Dir4.y,-10000000, 10000000,0.010000f);
    float_Dir4_1->Default = 0.000000f; float_Dir4_1->RightStep = 0.125000f;
    sFloatControl *float_Dir4_2 = gh.Float(&para->Dir4.z,-10000000, 10000000,0.010000f);
    float_Dir4_2->Default = 0.000000f; float_Dir4_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode4&0x000f)&&((para->Mode4&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range4");
    sFloatControl *float_Range4 = gh.Float(&para->Range4,0.000000f, 10000000,0.010000f);
    float_Range4->Default = 16.00000f; float_Range4->RightStep = 0.125000f;

  }
  if((((para->Mode4&0x000f)&&((para->Mode4&0x000f)==0x0003))&&(para->Mode4&0x0020)))
  {
    gh.Label(L"* Inner4");
    sFloatControl *float_Inner4 = gh.Float(&para->Inner4,0.000000f,1.000000f,0.010000f);
    float_Inner4->Default = 0.200000f; float_Inner4->RightStep = 0.125000f;

  }
  if(((para->Mode4&0x000f)&&((para->Mode4&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer4");
    sFloatControl *float_Outer4 = gh.Float(&para->Outer4,0.000000f,1.000000f,0.010000f);
    float_Outer4->Default = 0.500000f; float_Outer4->RightStep = 0.125000f;

  }
  if((((para->Mode4&0x000f)&&((para->Mode4&0x000f)==0x0003))&&(para->Mode4&0x0040)))
  {
    gh.Label(L"* Falloff4");
    sFloatControl *float_Falloff4 = gh.Float(&para->Falloff4,0.000000f,64.00000f,0.010000f);
    float_Falloff4->Default = 1.000000f; float_Falloff4->RightStep = 0.125000f;

  }
  if(((para->Mode4&0x000f)&&(para->Mode4&0x0010)))
  {
    gh.Label(L"* ShadowSize4");
    gh.Flags(&para->ShadowSize4,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter0");
    gh.Flags(&para->ShadowSize4,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias4");
    sFloatControl *float_ShadowBaseBias4 = gh.Float(&para->ShadowBaseBias4,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias4->Default = 0.500000f; float_ShadowBaseBias4->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter4");
    sFloatControl *float_ShadowFilter4 = gh.Float(&para->ShadowFilter4,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter4->Default = 0.500000f; float_ShadowFilter4->RightStep = 0.125000f;

  }
  if((((para->Mode4&0x000f)&&(para->Mode4&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias4");
    sFloatControl *float_ShadowSlopeBias4 = gh.Float(&para->ShadowSlopeBias4,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias4->Default = 0.500000f; float_ShadowSlopeBias4->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya4");
    gh.BeginTied();
    sFloatControl *float_dummya4_0 = gh.Float(&para->dummya4[0],0.000000f,255.0000f,0.125000f);
    float_dummya4_0->Default = 0.000000f; float_dummya4_0->RightStep = 0.125000f;
    sFloatControl *float_dummya4_1 = gh.Float(&para->dummya4[1],0.000000f,255.0000f,0.125000f);
    float_dummya4_1->Default = 0.000000f; float_dummya4_1->RightStep = 0.125000f;
    sFloatControl *float_dummya4_2 = gh.Float(&para->dummya4[2],0.000000f,255.0000f,0.125000f);
    float_dummya4_2->Default = 0.000000f; float_dummya4_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb4");
    gh.BeginTied();
    sFloatControl *float_dummyb4_0 = gh.Float(&para->dummyb4[0],0.000000f,255.0000f,0.125000f);
    float_dummyb4_0->Default = 0.000000f; float_dummyb4_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb4_1 = gh.Float(&para->dummyb4[1],0.000000f,255.0000f,0.125000f);
    float_dummyb4_1->Default = 0.000000f; float_dummyb4_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb4_2 = gh.Float(&para->dummyb4[2],0.000000f,255.0000f,0.125000f);
    float_dummyb4_2->Default = 0.000000f; float_dummyb4_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb4_3 = gh.Float(&para->dummyb4[3],0.000000f,255.0000f,0.125000f);
    float_dummyb4_3->Default = 0.000000f; float_dummyb4_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 5");

  gh.Label(L"Mode5");
  gh.Flags(&para->Mode5,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode5&0x000f))
  {
    gh.Flags(&para->Mode5,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode5&0x000f)&&((para->Mode5&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode5,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode5&0x000f))
  {
    gh.Label(L"* Front5");
    gh.ColorPick(&para->Front5,L"rgb",0);

    sFloatControl *float_FrontAmp5 = gh.Float(&para->FrontAmp5,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp5->Default = 1.000000f; float_FrontAmp5->RightStep = 0.125000f;

    gh.Label(L"* Middle5");
    gh.ColorPick(&para->Middle5,L"rgb",0);

    sFloatControl *float_MiddleAmp5 = gh.Float(&para->MiddleAmp5,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp5->Default = 1.000000f; float_MiddleAmp5->RightStep = 0.125000f;

    gh.Label(L"* Back5");
    gh.ColorPick(&para->Back5,L"rgb",0);

    sFloatControl *float_BackAmp5 = gh.Float(&para->BackAmp5,-1024.00f,1024.000f,0.010000f);
    float_BackAmp5->Default = 1.000000f; float_BackAmp5->RightStep = 0.125000f;

  }
  if(((para->Mode5&0x000f)&&((para->Mode5&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos5");
    gh.BeginTied();
    sFloatControl *float_Pos5_0 = gh.Float(&para->Pos5.x,-10000000, 10000000,0.010000f);
    float_Pos5_0->Default = 0.000000f; float_Pos5_0->RightStep = 0.125000f;
    sFloatControl *float_Pos5_1 = gh.Float(&para->Pos5.y,-10000000, 10000000,0.010000f);
    float_Pos5_1->Default = 0.000000f; float_Pos5_1->RightStep = 0.125000f;
    sFloatControl *float_Pos5_2 = gh.Float(&para->Pos5.z,-10000000, 10000000,0.010000f);
    float_Pos5_2->Default = 0.000000f; float_Pos5_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode5&0x000f)&&((para->Mode5&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir5");
    gh.BeginTied();
    sFloatControl *float_Dir5_0 = gh.Float(&para->Dir5.x,-10000000, 10000000,0.010000f);
    float_Dir5_0->Default = 0.000000f; float_Dir5_0->RightStep = 0.125000f;
    sFloatControl *float_Dir5_1 = gh.Float(&para->Dir5.y,-10000000, 10000000,0.010000f);
    float_Dir5_1->Default = 0.000000f; float_Dir5_1->RightStep = 0.125000f;
    sFloatControl *float_Dir5_2 = gh.Float(&para->Dir5.z,-10000000, 10000000,0.010000f);
    float_Dir5_2->Default = 0.000000f; float_Dir5_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode5&0x000f)&&((para->Mode5&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range5");
    sFloatControl *float_Range5 = gh.Float(&para->Range5,0.000000f, 10000000,0.010000f);
    float_Range5->Default = 16.00000f; float_Range5->RightStep = 0.125000f;

  }
  if((((para->Mode5&0x000f)&&((para->Mode5&0x000f)==0x0003))&&(para->Mode5&0x0020)))
  {
    gh.Label(L"* Inner5");
    sFloatControl *float_Inner5 = gh.Float(&para->Inner5,0.000000f,1.000000f,0.010000f);
    float_Inner5->Default = 0.200000f; float_Inner5->RightStep = 0.125000f;

  }
  if(((para->Mode5&0x000f)&&((para->Mode5&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer5");
    sFloatControl *float_Outer5 = gh.Float(&para->Outer5,0.000000f,1.000000f,0.010000f);
    float_Outer5->Default = 0.500000f; float_Outer5->RightStep = 0.125000f;

  }
  if((((para->Mode5&0x000f)&&((para->Mode5&0x000f)==0x0003))&&(para->Mode5&0x0040)))
  {
    gh.Label(L"* Falloff5");
    sFloatControl *float_Falloff5 = gh.Float(&para->Falloff5,0.000000f,64.00000f,0.010000f);
    float_Falloff5->Default = 1.000000f; float_Falloff5->RightStep = 0.125000f;

  }
  if(((para->Mode5&0x000f)&&(para->Mode5&0x0010)))
  {
    gh.Label(L"* ShadowSize5");
    gh.Flags(&para->ShadowSize5,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter0");
    gh.Flags(&para->ShadowSize5,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias5");
    sFloatControl *float_ShadowBaseBias5 = gh.Float(&para->ShadowBaseBias5,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias5->Default = 0.500000f; float_ShadowBaseBias5->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter5");
    sFloatControl *float_ShadowFilter5 = gh.Float(&para->ShadowFilter5,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter5->Default = 0.500000f; float_ShadowFilter5->RightStep = 0.125000f;

  }
  if((((para->Mode5&0x000f)&&(para->Mode5&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias5");
    sFloatControl *float_ShadowSlopeBias5 = gh.Float(&para->ShadowSlopeBias5,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias5->Default = 0.500000f; float_ShadowSlopeBias5->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya5");
    gh.BeginTied();
    sFloatControl *float_dummya5_0 = gh.Float(&para->dummya5[0],0.000000f,255.0000f,0.125000f);
    float_dummya5_0->Default = 0.000000f; float_dummya5_0->RightStep = 0.125000f;
    sFloatControl *float_dummya5_1 = gh.Float(&para->dummya5[1],0.000000f,255.0000f,0.125000f);
    float_dummya5_1->Default = 0.000000f; float_dummya5_1->RightStep = 0.125000f;
    sFloatControl *float_dummya5_2 = gh.Float(&para->dummya5[2],0.000000f,255.0000f,0.125000f);
    float_dummya5_2->Default = 0.000000f; float_dummya5_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb5");
    gh.BeginTied();
    sFloatControl *float_dummyb5_0 = gh.Float(&para->dummyb5[0],0.000000f,255.0000f,0.125000f);
    float_dummyb5_0->Default = 0.000000f; float_dummyb5_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb5_1 = gh.Float(&para->dummyb5[1],0.000000f,255.0000f,0.125000f);
    float_dummyb5_1->Default = 0.000000f; float_dummyb5_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb5_2 = gh.Float(&para->dummyb5[2],0.000000f,255.0000f,0.125000f);
    float_dummyb5_2->Default = 0.000000f; float_dummyb5_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb5_3 = gh.Float(&para->dummyb5[3],0.000000f,255.0000f,0.125000f);
    float_dummyb5_3->Default = 0.000000f; float_dummyb5_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 6");

  gh.Label(L"Mode6");
  gh.Flags(&para->Mode6,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode6&0x000f))
  {
    gh.Flags(&para->Mode6,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode6&0x000f)&&((para->Mode6&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode6,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode6&0x000f))
  {
    gh.Label(L"* Front6");
    gh.ColorPick(&para->Front6,L"rgb",0);

    sFloatControl *float_FrontAmp6 = gh.Float(&para->FrontAmp6,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp6->Default = 1.000000f; float_FrontAmp6->RightStep = 0.125000f;

    gh.Label(L"* Middle6");
    gh.ColorPick(&para->Middle6,L"rgb",0);

    sFloatControl *float_MiddleAmp6 = gh.Float(&para->MiddleAmp6,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp6->Default = 1.000000f; float_MiddleAmp6->RightStep = 0.125000f;

    gh.Label(L"* Back6");
    gh.ColorPick(&para->Back6,L"rgb",0);

    sFloatControl *float_BackAmp6 = gh.Float(&para->BackAmp6,-1024.00f,1024.000f,0.010000f);
    float_BackAmp6->Default = 1.000000f; float_BackAmp6->RightStep = 0.125000f;

  }
  if(((para->Mode6&0x000f)&&((para->Mode6&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos6");
    gh.BeginTied();
    sFloatControl *float_Pos6_0 = gh.Float(&para->Pos6.x,-10000000, 10000000,0.010000f);
    float_Pos6_0->Default = 0.000000f; float_Pos6_0->RightStep = 0.125000f;
    sFloatControl *float_Pos6_1 = gh.Float(&para->Pos6.y,-10000000, 10000000,0.010000f);
    float_Pos6_1->Default = 0.000000f; float_Pos6_1->RightStep = 0.125000f;
    sFloatControl *float_Pos6_2 = gh.Float(&para->Pos6.z,-10000000, 10000000,0.010000f);
    float_Pos6_2->Default = 0.000000f; float_Pos6_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode6&0x000f)&&((para->Mode6&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir6");
    gh.BeginTied();
    sFloatControl *float_Dir6_0 = gh.Float(&para->Dir6.x,-10000000, 10000000,0.010000f);
    float_Dir6_0->Default = 0.000000f; float_Dir6_0->RightStep = 0.125000f;
    sFloatControl *float_Dir6_1 = gh.Float(&para->Dir6.y,-10000000, 10000000,0.010000f);
    float_Dir6_1->Default = 0.000000f; float_Dir6_1->RightStep = 0.125000f;
    sFloatControl *float_Dir6_2 = gh.Float(&para->Dir6.z,-10000000, 10000000,0.010000f);
    float_Dir6_2->Default = 0.000000f; float_Dir6_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode6&0x000f)&&((para->Mode6&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range6");
    sFloatControl *float_Range6 = gh.Float(&para->Range6,0.000000f, 10000000,0.010000f);
    float_Range6->Default = 16.00000f; float_Range6->RightStep = 0.125000f;

  }
  if((((para->Mode6&0x000f)&&((para->Mode6&0x000f)==0x0003))&&(para->Mode6&0x0020)))
  {
    gh.Label(L"* Inner6");
    sFloatControl *float_Inner6 = gh.Float(&para->Inner6,0.000000f,1.000000f,0.010000f);
    float_Inner6->Default = 0.200000f; float_Inner6->RightStep = 0.125000f;

  }
  if(((para->Mode6&0x000f)&&((para->Mode6&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer6");
    sFloatControl *float_Outer6 = gh.Float(&para->Outer6,0.000000f,1.000000f,0.010000f);
    float_Outer6->Default = 0.500000f; float_Outer6->RightStep = 0.125000f;

  }
  if((((para->Mode6&0x000f)&&((para->Mode6&0x000f)==0x0003))&&(para->Mode6&0x0040)))
  {
    gh.Label(L"* Falloff6");
    sFloatControl *float_Falloff6 = gh.Float(&para->Falloff6,0.000000f,64.00000f,0.010000f);
    float_Falloff6->Default = 1.000000f; float_Falloff6->RightStep = 0.125000f;

  }
  if(((para->Mode6&0x000f)&&(para->Mode6&0x0010)))
  {
    gh.Label(L"* ShadowSize6");
    gh.Flags(&para->ShadowSize6,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter0");
    gh.Flags(&para->ShadowSize6,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias6");
    sFloatControl *float_ShadowBaseBias6 = gh.Float(&para->ShadowBaseBias6,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias6->Default = 0.500000f; float_ShadowBaseBias6->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter6");
    sFloatControl *float_ShadowFilter6 = gh.Float(&para->ShadowFilter6,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter6->Default = 0.500000f; float_ShadowFilter6->RightStep = 0.125000f;

  }
  if((((para->Mode6&0x000f)&&(para->Mode6&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias6");
    sFloatControl *float_ShadowSlopeBias6 = gh.Float(&para->ShadowSlopeBias6,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias6->Default = 0.500000f; float_ShadowSlopeBias6->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya6");
    gh.BeginTied();
    sFloatControl *float_dummya6_0 = gh.Float(&para->dummya6[0],0.000000f,255.0000f,0.125000f);
    float_dummya6_0->Default = 0.000000f; float_dummya6_0->RightStep = 0.125000f;
    sFloatControl *float_dummya6_1 = gh.Float(&para->dummya6[1],0.000000f,255.0000f,0.125000f);
    float_dummya6_1->Default = 0.000000f; float_dummya6_1->RightStep = 0.125000f;
    sFloatControl *float_dummya6_2 = gh.Float(&para->dummya6[2],0.000000f,255.0000f,0.125000f);
    float_dummya6_2->Default = 0.000000f; float_dummya6_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb6");
    gh.BeginTied();
    sFloatControl *float_dummyb6_0 = gh.Float(&para->dummyb6[0],0.000000f,255.0000f,0.125000f);
    float_dummyb6_0->Default = 0.000000f; float_dummyb6_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb6_1 = gh.Float(&para->dummyb6[1],0.000000f,255.0000f,0.125000f);
    float_dummyb6_1->Default = 0.000000f; float_dummyb6_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb6_2 = gh.Float(&para->dummyb6[2],0.000000f,255.0000f,0.125000f);
    float_dummyb6_2->Default = 0.000000f; float_dummyb6_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb6_3 = gh.Float(&para->dummyb6[3],0.000000f,255.0000f,0.125000f);
    float_dummyb6_3->Default = 0.000000f; float_dummyb6_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"light 7");

  gh.Label(L"Mode7");
  gh.Flags(&para->Mode7,L"off|dir|point|spot",gh.LayoutMsg);

  if((para->Mode7&0x000f))
  {
    gh.Flags(&para->Mode7,L"*4-|shadow:*7-|headlight",gh.LayoutMsg);

  }
  if(((para->Mode7&0x000f)&&((para->Mode7&0x000f)==0x0003)))
  {
    gh.Flags(&para->Mode7,L"*5-|inner:*6-|falloff",gh.LayoutMsg);

  }
  if((para->Mode7&0x000f))
  {
    gh.Label(L"* Front7");
    gh.ColorPick(&para->Front7,L"rgb",0);

    sFloatControl *float_FrontAmp7 = gh.Float(&para->FrontAmp7,-1024.00f,1024.000f,0.010000f);
    float_FrontAmp7->Default = 1.000000f; float_FrontAmp7->RightStep = 0.125000f;

    gh.Label(L"* Middle7");
    gh.ColorPick(&para->Middle7,L"rgb",0);

    sFloatControl *float_MiddleAmp7 = gh.Float(&para->MiddleAmp7,-1024.00f,1024.000f,0.010000f);
    float_MiddleAmp7->Default = 1.000000f; float_MiddleAmp7->RightStep = 0.125000f;

    gh.Label(L"* Back7");
    gh.ColorPick(&para->Back7,L"rgb",0);

    sFloatControl *float_BackAmp7 = gh.Float(&para->BackAmp7,-1024.00f,1024.000f,0.010000f);
    float_BackAmp7->Default = 1.000000f; float_BackAmp7->RightStep = 0.125000f;

  }
  if(((para->Mode7&0x000f)&&((para->Mode7&0x000f)>=0x0002)))
  {
    gh.Label(L"* Pos7");
    gh.BeginTied();
    sFloatControl *float_Pos7_0 = gh.Float(&para->Pos7.x,-10000000, 10000000,0.010000f);
    float_Pos7_0->Default = 0.000000f; float_Pos7_0->RightStep = 0.125000f;
    sFloatControl *float_Pos7_1 = gh.Float(&para->Pos7.y,-10000000, 10000000,0.010000f);
    float_Pos7_1->Default = 0.000000f; float_Pos7_1->RightStep = 0.125000f;
    sFloatControl *float_Pos7_2 = gh.Float(&para->Pos7.z,-10000000, 10000000,0.010000f);
    float_Pos7_2->Default = 0.000000f; float_Pos7_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode7&0x000f)&&((para->Mode7&0x000f)!=0x0002)))
  {
    gh.Label(L"* Dir7");
    gh.BeginTied();
    sFloatControl *float_Dir7_0 = gh.Float(&para->Dir7.x,-10000000, 10000000,0.010000f);
    float_Dir7_0->Default = 0.000000f; float_Dir7_0->RightStep = 0.125000f;
    sFloatControl *float_Dir7_1 = gh.Float(&para->Dir7.y,-10000000, 10000000,0.010000f);
    float_Dir7_1->Default = 0.000000f; float_Dir7_1->RightStep = 0.125000f;
    sFloatControl *float_Dir7_2 = gh.Float(&para->Dir7.z,-10000000, 10000000,0.010000f);
    float_Dir7_2->Default = 0.000000f; float_Dir7_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Mode7&0x000f)&&((para->Mode7&0x000f)>=0x0002)))
  {
    gh.Label(L"* Range7");
    sFloatControl *float_Range7 = gh.Float(&para->Range7,0.000000f, 10000000,0.010000f);
    float_Range7->Default = 16.00000f; float_Range7->RightStep = 0.125000f;

  }
  if((((para->Mode7&0x000f)&&((para->Mode7&0x000f)==0x0003))&&(para->Mode7&0x0020)))
  {
    gh.Label(L"* Inner7");
    sFloatControl *float_Inner7 = gh.Float(&para->Inner7,0.000000f,1.000000f,0.010000f);
    float_Inner7->Default = 0.200000f; float_Inner7->RightStep = 0.125000f;

  }
  if(((para->Mode7&0x000f)&&((para->Mode7&0x000f)==0x0003)))
  {
    gh.Label(L"* Outer7");
    sFloatControl *float_Outer7 = gh.Float(&para->Outer7,0.000000f,1.000000f,0.010000f);
    float_Outer7->Default = 0.500000f; float_Outer7->RightStep = 0.125000f;

  }
  if((((para->Mode7&0x000f)&&((para->Mode7&0x000f)==0x0003))&&(para->Mode7&0x0040)))
  {
    gh.Label(L"* Falloff7");
    sFloatControl *float_Falloff7 = gh.Float(&para->Falloff7,0.000000f,64.00000f,0.010000f);
    float_Falloff7->Default = 1.000000f; float_Falloff7->RightStep = 0.125000f;

  }
  if(((para->Mode7&0x000f)&&(para->Mode7&0x0010)))
  {
    gh.Label(L"* ShadowSize7");
    gh.Flags(&para->ShadowSize7,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

    gh.Label(L"ShadowFilter0");
    gh.Flags(&para->ShadowSize7,L"*16point|ordered|random",gh.ChangeMsg);

    gh.Label(L"* ShadowBaseBias7");
    sFloatControl *float_ShadowBaseBias7 = gh.Float(&para->ShadowBaseBias7,-1024.00f,1024.000f,0.000100f);
    float_ShadowBaseBias7->Default = 0.500000f; float_ShadowBaseBias7->RightStep = 0.125000f;

    gh.Label(L"* ShadowFilter7");
    sFloatControl *float_ShadowFilter7 = gh.Float(&para->ShadowFilter7,0.000000f,1024.000f,0.010000f);
    float_ShadowFilter7->Default = 0.500000f; float_ShadowFilter7->RightStep = 0.125000f;

  }
  if((((para->Mode7&0x000f)&&(para->Mode7&0x0010))&&0x0000))
  {
    gh.Label(L"* ShadowSlopeBias7");
    sFloatControl *float_ShadowSlopeBias7 = gh.Float(&para->ShadowSlopeBias7,-1024.00f,1024.000f,0.001000f);
    float_ShadowSlopeBias7->Default = 0.500000f; float_ShadowSlopeBias7->RightStep = 0.125000f;

  }
  if(0x0000)
  {
    gh.Label(L"dummya7");
    gh.BeginTied();
    sFloatControl *float_dummya7_0 = gh.Float(&para->dummya7[0],0.000000f,255.0000f,0.125000f);
    float_dummya7_0->Default = 0.000000f; float_dummya7_0->RightStep = 0.125000f;
    sFloatControl *float_dummya7_1 = gh.Float(&para->dummya7[1],0.000000f,255.0000f,0.125000f);
    float_dummya7_1->Default = 0.000000f; float_dummya7_1->RightStep = 0.125000f;
    sFloatControl *float_dummya7_2 = gh.Float(&para->dummya7[2],0.000000f,255.0000f,0.125000f);
    float_dummya7_2->Default = 0.000000f; float_dummya7_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(0x0000)
  {
    gh.Label(L"dummyb7");
    gh.BeginTied();
    sFloatControl *float_dummyb7_0 = gh.Float(&para->dummyb7[0],0.000000f,255.0000f,0.125000f);
    float_dummyb7_0->Default = 0.000000f; float_dummyb7_0->RightStep = 0.125000f;
    sFloatControl *float_dummyb7_1 = gh.Float(&para->dummyb7[1],0.000000f,255.0000f,0.125000f);
    float_dummyb7_1->Default = 0.000000f; float_dummyb7_1->RightStep = 0.125000f;
    sFloatControl *float_dummyb7_2 = gh.Float(&para->dummyb7[2],0.000000f,255.0000f,0.125000f);
    float_dummyb7_2->Default = 0.000000f; float_dummyb7_2->RightStep = 0.125000f;
    sFloatControl *float_dummyb7_3 = gh.Float(&para->dummyb7[3],0.000000f,255.0000f,0.125000f);
    float_dummyb7_3->Default = 0.000000f; float_dummyb7_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"limit shadows");

  gh.ControlWidth = 1;
  gh.Label(L"LimitShadows");
  gh.Flags(&para->LimitShadows,L"-| 0:*1-| 1:*2-| 2:*3-| 3:*4-| 4:*5-| 5:*6-| 6:*7-| 7",gh.LayoutMsg);
  gh.ControlWidth = 2;

  if(para->LimitShadows)
  {
    gh.Label(L"* LimitCenter");
    gh.BeginTied();
    sFloatControl *float_LimitCenter_0 = gh.Float(&para->LimitCenter.x,-1024.00f,1024.000f,0.125000f);
    float_LimitCenter_0->Default = 0.000000f; float_LimitCenter_0->RightStep = 0.125000f;
    sFloatControl *float_LimitCenter_1 = gh.Float(&para->LimitCenter.y,-1024.00f,1024.000f,0.125000f);
    float_LimitCenter_1->Default = 0.000000f; float_LimitCenter_1->RightStep = 0.125000f;
    sFloatControl *float_LimitCenter_2 = gh.Float(&para->LimitCenter.z,-1024.00f,1024.000f,0.125000f);
    float_LimitCenter_2->Default = 0.000000f; float_LimitCenter_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* LimitRadius");
    gh.BeginTied();
    sFloatControl *float_LimitRadius_0 = gh.Float(&para->LimitRadius.x,0.000000f,1024.000f,0.125000f);
    float_LimitRadius_0->Default = 64.00000f; float_LimitRadius_0->RightStep = 0.125000f;
    sFloatControl *float_LimitRadius_1 = gh.Float(&para->LimitRadius.y,0.000000f,1024.000f,0.125000f);
    float_LimitRadius_1->Default = 64.00000f; float_LimitRadius_1->RightStep = 0.125000f;
    sFloatControl *float_LimitRadius_2 = gh.Float(&para->LimitRadius.z,0.000000f,1024.000f,0.125000f);
    float_LimitRadius_2->Default = 64.00000f; float_LimitRadius_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"Transform");

  gh.Label(L"TransformEnable");
  gh.Flags(&para->TransformEnable,L"-|transformed",gh.LayoutMsg);

  if((para->TransformEnable&0x0001))
  {
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
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
    float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Trans");
    gh.BeginTied();
    sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
    float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
    float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
    sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
    float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
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

void Wz4RenderDefModLight(wOp *op)
{
  Wz4RenderParaModLight sUNUSED *para = (Wz4RenderParaModLight *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Front0 = 0x00ffffff;
  para->FrontAmp0 = 1.000000f;
  para->MiddleAmp0 = 1.000000f;
  para->BackAmp0 = 1.000000f;
  para->Range0 = 16.00000f;
  para->Inner0 = 0.200000f;
  para->Outer0 = 0.500000f;
  para->Falloff0 = 1.000000f;
  para->ShadowSize0 = 0x0000000a;
  para->ShadowBaseBias0 = 0.500000f;
  para->ShadowFilter0 = 0.500000f;
  para->ShadowSlopeBias0 = 0.500000f;
  para->Front1 = 0x00ffffff;
  para->FrontAmp1 = 1.000000f;
  para->MiddleAmp1 = 1.000000f;
  para->BackAmp1 = 1.000000f;
  para->Range1 = 16.00000f;
  para->Inner1 = 0.200000f;
  para->Outer1 = 0.500000f;
  para->Falloff1 = 1.000000f;
  para->ShadowSize1 = 0x0000000a;
  para->ShadowBaseBias1 = 0.500000f;
  para->ShadowFilter1 = 0.500000f;
  para->ShadowSlopeBias1 = 0.500000f;
  para->Front2 = 0x00ffffff;
  para->FrontAmp2 = 1.000000f;
  para->MiddleAmp2 = 1.000000f;
  para->BackAmp2 = 1.000000f;
  para->Range2 = 16.00000f;
  para->Inner2 = 0.200000f;
  para->Outer2 = 0.500000f;
  para->Falloff2 = 1.000000f;
  para->ShadowSize2 = 0x0000000a;
  para->ShadowBaseBias2 = 0.500000f;
  para->ShadowFilter2 = 0.500000f;
  para->ShadowSlopeBias2 = 0.500000f;
  para->Front3 = 0x00ffffff;
  para->FrontAmp3 = 1.000000f;
  para->MiddleAmp3 = 1.000000f;
  para->BackAmp3 = 1.000000f;
  para->Range3 = 16.00000f;
  para->Inner3 = 0.200000f;
  para->Outer3 = 0.500000f;
  para->Falloff3 = 1.000000f;
  para->ShadowSize3 = 0x0000000a;
  para->ShadowBaseBias3 = 0.500000f;
  para->ShadowFilter3 = 0.500000f;
  para->ShadowSlopeBias3 = 0.500000f;
  para->Front4 = 0x00ffffff;
  para->FrontAmp4 = 1.000000f;
  para->MiddleAmp4 = 1.000000f;
  para->BackAmp4 = 1.000000f;
  para->Range4 = 16.00000f;
  para->Inner4 = 0.200000f;
  para->Outer4 = 0.500000f;
  para->Falloff4 = 1.000000f;
  para->ShadowSize4 = 0x0000000a;
  para->ShadowBaseBias4 = 0.500000f;
  para->ShadowFilter4 = 0.500000f;
  para->ShadowSlopeBias4 = 0.500000f;
  para->Front5 = 0x00ffffff;
  para->FrontAmp5 = 1.000000f;
  para->MiddleAmp5 = 1.000000f;
  para->BackAmp5 = 1.000000f;
  para->Range5 = 16.00000f;
  para->Inner5 = 0.200000f;
  para->Outer5 = 0.500000f;
  para->Falloff5 = 1.000000f;
  para->ShadowSize5 = 0x0000000a;
  para->ShadowBaseBias5 = 0.500000f;
  para->ShadowFilter5 = 0.500000f;
  para->ShadowSlopeBias5 = 0.500000f;
  para->Front6 = 0x00ffffff;
  para->FrontAmp6 = 1.000000f;
  para->MiddleAmp6 = 1.000000f;
  para->BackAmp6 = 1.000000f;
  para->Range6 = 16.00000f;
  para->Inner6 = 0.200000f;
  para->Outer6 = 0.500000f;
  para->Falloff6 = 1.000000f;
  para->ShadowSize6 = 0x0000000a;
  para->ShadowBaseBias6 = 0.500000f;
  para->ShadowFilter6 = 0.500000f;
  para->ShadowSlopeBias6 = 0.500000f;
  para->Front7 = 0x00ffffff;
  para->FrontAmp7 = 1.000000f;
  para->MiddleAmp7 = 1.000000f;
  para->BackAmp7 = 1.000000f;
  para->Range7 = 16.00000f;
  para->Inner7 = 0.200000f;
  para->Outer7 = 0.500000f;
  para->Falloff7 = 1.000000f;
  para->ShadowSize7 = 0x0000000a;
  para->ShadowBaseBias7 = 0.500000f;
  para->ShadowFilter7 = 0.500000f;
  para->ShadowSlopeBias7 = 0.500000f;
  para->LimitRadius.x = 64.00000f;
  para->LimitRadius.y = 64.00000f;
  para->LimitRadius.z = 64.00000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4RenderBindModLight(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"ambient"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"front0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"middle0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"back0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"backamp0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"dir0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"dir0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"dir0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"range0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"inner0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"outer0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"falloff0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"dummya0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"dummya0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"dummya0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"front1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"middle1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"back1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"backamp1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+38;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+41;
  ctx->BindLocal(ctx->AddSymbol(L"dir1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+41;
  ctx->BindLocal(ctx->AddSymbol(L"dir1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+41;
  ctx->BindLocal(ctx->AddSymbol(L"dir1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+44;
  ctx->BindLocal(ctx->AddSymbol(L"range1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"inner1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+46;
  ctx->BindLocal(ctx->AddSymbol(L"outer1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+47;
  ctx->BindLocal(ctx->AddSymbol(L"falloff1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+49;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+50;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+52;
  ctx->BindLocal(ctx->AddSymbol(L"dummya1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+52;
  ctx->BindLocal(ctx->AddSymbol(L"dummya1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+52;
  ctx->BindLocal(ctx->AddSymbol(L"dummya1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+55;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+55;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+55;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+55;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+60;
  ctx->BindLocal(ctx->AddSymbol(L"front2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+61;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp2"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+62;
  ctx->BindLocal(ctx->AddSymbol(L"middle2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+63;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp2"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+64;
  ctx->BindLocal(ctx->AddSymbol(L"back2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+65;
  ctx->BindLocal(ctx->AddSymbol(L"backamp2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+66;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+66;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+66;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+69;
  ctx->BindLocal(ctx->AddSymbol(L"dir2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+69;
  ctx->BindLocal(ctx->AddSymbol(L"dir2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+69;
  ctx->BindLocal(ctx->AddSymbol(L"dir2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+72;
  ctx->BindLocal(ctx->AddSymbol(L"range2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+73;
  ctx->BindLocal(ctx->AddSymbol(L"inner2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+74;
  ctx->BindLocal(ctx->AddSymbol(L"outer2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+75;
  ctx->BindLocal(ctx->AddSymbol(L"falloff2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+77;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+78;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+79;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+80;
  ctx->BindLocal(ctx->AddSymbol(L"dummya2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+80;
  ctx->BindLocal(ctx->AddSymbol(L"dummya2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+80;
  ctx->BindLocal(ctx->AddSymbol(L"dummya2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+83;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+83;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+83;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+83;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb2"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+88;
  ctx->BindLocal(ctx->AddSymbol(L"front3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+89;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp3"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+90;
  ctx->BindLocal(ctx->AddSymbol(L"middle3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+91;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp3"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+92;
  ctx->BindLocal(ctx->AddSymbol(L"back3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+93;
  ctx->BindLocal(ctx->AddSymbol(L"backamp3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+94;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+94;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+94;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+97;
  ctx->BindLocal(ctx->AddSymbol(L"dir3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+97;
  ctx->BindLocal(ctx->AddSymbol(L"dir3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+97;
  ctx->BindLocal(ctx->AddSymbol(L"dir3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+100;
  ctx->BindLocal(ctx->AddSymbol(L"range3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+101;
  ctx->BindLocal(ctx->AddSymbol(L"inner3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+102;
  ctx->BindLocal(ctx->AddSymbol(L"outer3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+103;
  ctx->BindLocal(ctx->AddSymbol(L"falloff3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+105;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+106;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+107;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+108;
  ctx->BindLocal(ctx->AddSymbol(L"dummya3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+108;
  ctx->BindLocal(ctx->AddSymbol(L"dummya3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+108;
  ctx->BindLocal(ctx->AddSymbol(L"dummya3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+111;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+111;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+111;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+111;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb3"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+116;
  ctx->BindLocal(ctx->AddSymbol(L"front4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+117;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp4"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+118;
  ctx->BindLocal(ctx->AddSymbol(L"middle4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+119;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp4"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+120;
  ctx->BindLocal(ctx->AddSymbol(L"back4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+121;
  ctx->BindLocal(ctx->AddSymbol(L"backamp4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+122;
  ctx->BindLocal(ctx->AddSymbol(L"pos4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+122;
  ctx->BindLocal(ctx->AddSymbol(L"pos4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+122;
  ctx->BindLocal(ctx->AddSymbol(L"pos4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+125;
  ctx->BindLocal(ctx->AddSymbol(L"dir4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+125;
  ctx->BindLocal(ctx->AddSymbol(L"dir4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+125;
  ctx->BindLocal(ctx->AddSymbol(L"dir4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+128;
  ctx->BindLocal(ctx->AddSymbol(L"range4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+129;
  ctx->BindLocal(ctx->AddSymbol(L"inner4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+130;
  ctx->BindLocal(ctx->AddSymbol(L"outer4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+131;
  ctx->BindLocal(ctx->AddSymbol(L"falloff4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+133;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+134;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+135;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+136;
  ctx->BindLocal(ctx->AddSymbol(L"dummya4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+136;
  ctx->BindLocal(ctx->AddSymbol(L"dummya4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+136;
  ctx->BindLocal(ctx->AddSymbol(L"dummya4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+139;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+139;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+139;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+139;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb4"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+144;
  ctx->BindLocal(ctx->AddSymbol(L"front5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+145;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp5"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+146;
  ctx->BindLocal(ctx->AddSymbol(L"middle5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+147;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp5"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+148;
  ctx->BindLocal(ctx->AddSymbol(L"back5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+149;
  ctx->BindLocal(ctx->AddSymbol(L"backamp5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+150;
  ctx->BindLocal(ctx->AddSymbol(L"pos5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+150;
  ctx->BindLocal(ctx->AddSymbol(L"pos5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+150;
  ctx->BindLocal(ctx->AddSymbol(L"pos5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+153;
  ctx->BindLocal(ctx->AddSymbol(L"dir5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+153;
  ctx->BindLocal(ctx->AddSymbol(L"dir5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+153;
  ctx->BindLocal(ctx->AddSymbol(L"dir5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+156;
  ctx->BindLocal(ctx->AddSymbol(L"range5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+157;
  ctx->BindLocal(ctx->AddSymbol(L"inner5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+158;
  ctx->BindLocal(ctx->AddSymbol(L"outer5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+159;
  ctx->BindLocal(ctx->AddSymbol(L"falloff5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+161;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+162;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+163;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+164;
  ctx->BindLocal(ctx->AddSymbol(L"dummya5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+164;
  ctx->BindLocal(ctx->AddSymbol(L"dummya5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+164;
  ctx->BindLocal(ctx->AddSymbol(L"dummya5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+167;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+167;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+167;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+167;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb5"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+172;
  ctx->BindLocal(ctx->AddSymbol(L"front6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+173;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp6"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+174;
  ctx->BindLocal(ctx->AddSymbol(L"middle6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+175;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp6"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+176;
  ctx->BindLocal(ctx->AddSymbol(L"back6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+177;
  ctx->BindLocal(ctx->AddSymbol(L"backamp6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+178;
  ctx->BindLocal(ctx->AddSymbol(L"pos6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+178;
  ctx->BindLocal(ctx->AddSymbol(L"pos6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+178;
  ctx->BindLocal(ctx->AddSymbol(L"pos6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+181;
  ctx->BindLocal(ctx->AddSymbol(L"dir6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+181;
  ctx->BindLocal(ctx->AddSymbol(L"dir6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+181;
  ctx->BindLocal(ctx->AddSymbol(L"dir6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+184;
  ctx->BindLocal(ctx->AddSymbol(L"range6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+185;
  ctx->BindLocal(ctx->AddSymbol(L"inner6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+186;
  ctx->BindLocal(ctx->AddSymbol(L"outer6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+187;
  ctx->BindLocal(ctx->AddSymbol(L"falloff6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+189;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+190;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+191;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+192;
  ctx->BindLocal(ctx->AddSymbol(L"dummya6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+192;
  ctx->BindLocal(ctx->AddSymbol(L"dummya6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+192;
  ctx->BindLocal(ctx->AddSymbol(L"dummya6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+195;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+195;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+195;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+195;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb6"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+200;
  ctx->BindLocal(ctx->AddSymbol(L"front7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+201;
  ctx->BindLocal(ctx->AddSymbol(L"frontamp7"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+202;
  ctx->BindLocal(ctx->AddSymbol(L"middle7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+203;
  ctx->BindLocal(ctx->AddSymbol(L"middleamp7"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+204;
  ctx->BindLocal(ctx->AddSymbol(L"back7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+205;
  ctx->BindLocal(ctx->AddSymbol(L"backamp7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+206;
  ctx->BindLocal(ctx->AddSymbol(L"pos7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+206;
  ctx->BindLocal(ctx->AddSymbol(L"pos7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+206;
  ctx->BindLocal(ctx->AddSymbol(L"pos7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+209;
  ctx->BindLocal(ctx->AddSymbol(L"dir7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+209;
  ctx->BindLocal(ctx->AddSymbol(L"dir7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+209;
  ctx->BindLocal(ctx->AddSymbol(L"dir7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+212;
  ctx->BindLocal(ctx->AddSymbol(L"range7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+213;
  ctx->BindLocal(ctx->AddSymbol(L"inner7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+214;
  ctx->BindLocal(ctx->AddSymbol(L"outer7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+215;
  ctx->BindLocal(ctx->AddSymbol(L"falloff7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+217;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+218;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+219;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+220;
  ctx->BindLocal(ctx->AddSymbol(L"dummya7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+220;
  ctx->BindLocal(ctx->AddSymbol(L"dummya7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+220;
  ctx->BindLocal(ctx->AddSymbol(L"dummya7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+223;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+223;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+223;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+223;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+228;
  ctx->BindLocal(ctx->AddSymbol(L"limitcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+228;
  ctx->BindLocal(ctx->AddSymbol(L"limitcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+228;
  ctx->BindLocal(ctx->AddSymbol(L"limitcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+231;
  ctx->BindLocal(ctx->AddSymbol(L"limitradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+231;
  ctx->BindLocal(ctx->AddSymbol(L"limitradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+231;
  ctx->BindLocal(ctx->AddSymbol(L"limitradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+235;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+235;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+235;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+238;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+238;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+238;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+241;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+241;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+241;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ModLight(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[201];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"swap_rg");
    name[1] = sPoolString(L"swap_rb");
    name[2] = sPoolString(L"swap_gb");
    name[3] = sPoolString(L"lightenv");
    name[4] = sPoolString(L"renderpass");
    name[5] = sPoolString(L"ambient");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"mode0");
    name[8] = sPoolString(L"mode0");
    name[9] = sPoolString(L"mode0");
    name[10] = sPoolString(L"front0");
    name[11] = sPoolString(L"frontamp0");
    name[12] = sPoolString(L"middle0");
    name[13] = sPoolString(L"middleamp0");
    name[14] = sPoolString(L"back0");
    name[15] = sPoolString(L"backamp0");
    name[16] = sPoolString(L"pos0");
    name[17] = sPoolString(L"dir0");
    name[18] = sPoolString(L"range0");
    name[19] = sPoolString(L"inner0");
    name[20] = sPoolString(L"outer0");
    name[21] = sPoolString(L"falloff0");
    name[22] = sPoolString(L"shadowsize0");
    name[23] = sPoolString(L"shadowfilter0");
    name[24] = sPoolString(L"shadowbasebias0");
    name[25] = sPoolString(L"shadowfilter0");
    name[26] = sPoolString(L"shadowslopebias0");
    name[27] = sPoolString(L"dummya0");
    name[28] = sPoolString(L"dummyb0");
    name[29] = sPoolString(L"");
    name[30] = sPoolString(L"mode1");
    name[31] = sPoolString(L"mode1");
    name[32] = sPoolString(L"mode1");
    name[33] = sPoolString(L"front1");
    name[34] = sPoolString(L"frontamp1");
    name[35] = sPoolString(L"middle1");
    name[36] = sPoolString(L"middleamp1");
    name[37] = sPoolString(L"back1");
    name[38] = sPoolString(L"backamp1");
    name[39] = sPoolString(L"pos1");
    name[40] = sPoolString(L"dir1");
    name[41] = sPoolString(L"range1");
    name[42] = sPoolString(L"inner1");
    name[43] = sPoolString(L"outer1");
    name[44] = sPoolString(L"falloff1");
    name[45] = sPoolString(L"shadowsize1");
    name[46] = sPoolString(L"shadowfilter1");
    name[47] = sPoolString(L"shadowbasebias1");
    name[48] = sPoolString(L"shadowfilter1");
    name[49] = sPoolString(L"shadowslopebias1");
    name[50] = sPoolString(L"dummya1");
    name[51] = sPoolString(L"dummyb1");
    name[52] = sPoolString(L"");
    name[53] = sPoolString(L"mode2");
    name[54] = sPoolString(L"mode2");
    name[55] = sPoolString(L"mode2");
    name[56] = sPoolString(L"front2");
    name[57] = sPoolString(L"frontamp2");
    name[58] = sPoolString(L"middle2");
    name[59] = sPoolString(L"middleamp2");
    name[60] = sPoolString(L"back2");
    name[61] = sPoolString(L"backamp2");
    name[62] = sPoolString(L"pos2");
    name[63] = sPoolString(L"dir2");
    name[64] = sPoolString(L"range2");
    name[65] = sPoolString(L"inner2");
    name[66] = sPoolString(L"outer2");
    name[67] = sPoolString(L"falloff2");
    name[68] = sPoolString(L"shadowsize2");
    name[69] = sPoolString(L"shadowfilter2");
    name[70] = sPoolString(L"shadowbasebias2");
    name[71] = sPoolString(L"shadowfilter2");
    name[72] = sPoolString(L"shadowslopebias2");
    name[73] = sPoolString(L"dummya2");
    name[74] = sPoolString(L"dummyb2");
    name[75] = sPoolString(L"");
    name[76] = sPoolString(L"mode3");
    name[77] = sPoolString(L"mode3");
    name[78] = sPoolString(L"mode3");
    name[79] = sPoolString(L"front3");
    name[80] = sPoolString(L"frontamp3");
    name[81] = sPoolString(L"middle3");
    name[82] = sPoolString(L"middleamp3");
    name[83] = sPoolString(L"back3");
    name[84] = sPoolString(L"backamp3");
    name[85] = sPoolString(L"pos3");
    name[86] = sPoolString(L"dir3");
    name[87] = sPoolString(L"range3");
    name[88] = sPoolString(L"inner3");
    name[89] = sPoolString(L"outer3");
    name[90] = sPoolString(L"falloff3");
    name[91] = sPoolString(L"shadowsize3");
    name[92] = sPoolString(L"shadowfilter3");
    name[93] = sPoolString(L"shadowbasebias3");
    name[94] = sPoolString(L"shadowfilter3");
    name[95] = sPoolString(L"shadowslopebias3");
    name[96] = sPoolString(L"dummya3");
    name[97] = sPoolString(L"dummyb3");
    name[98] = sPoolString(L"");
    name[99] = sPoolString(L"mode4");
    name[100] = sPoolString(L"mode4");
    name[101] = sPoolString(L"mode4");
    name[102] = sPoolString(L"front4");
    name[103] = sPoolString(L"frontamp4");
    name[104] = sPoolString(L"middle4");
    name[105] = sPoolString(L"middleamp4");
    name[106] = sPoolString(L"back4");
    name[107] = sPoolString(L"backamp4");
    name[108] = sPoolString(L"pos4");
    name[109] = sPoolString(L"dir4");
    name[110] = sPoolString(L"range4");
    name[111] = sPoolString(L"inner4");
    name[112] = sPoolString(L"outer4");
    name[113] = sPoolString(L"falloff4");
    name[114] = sPoolString(L"shadowsize4");
    name[115] = sPoolString(L"shadowfilter0");
    name[116] = sPoolString(L"shadowbasebias4");
    name[117] = sPoolString(L"shadowfilter4");
    name[118] = sPoolString(L"shadowslopebias4");
    name[119] = sPoolString(L"dummya4");
    name[120] = sPoolString(L"dummyb4");
    name[121] = sPoolString(L"");
    name[122] = sPoolString(L"mode5");
    name[123] = sPoolString(L"mode5");
    name[124] = sPoolString(L"mode5");
    name[125] = sPoolString(L"front5");
    name[126] = sPoolString(L"frontamp5");
    name[127] = sPoolString(L"middle5");
    name[128] = sPoolString(L"middleamp5");
    name[129] = sPoolString(L"back5");
    name[130] = sPoolString(L"backamp5");
    name[131] = sPoolString(L"pos5");
    name[132] = sPoolString(L"dir5");
    name[133] = sPoolString(L"range5");
    name[134] = sPoolString(L"inner5");
    name[135] = sPoolString(L"outer5");
    name[136] = sPoolString(L"falloff5");
    name[137] = sPoolString(L"shadowsize5");
    name[138] = sPoolString(L"shadowfilter0");
    name[139] = sPoolString(L"shadowbasebias5");
    name[140] = sPoolString(L"shadowfilter5");
    name[141] = sPoolString(L"shadowslopebias5");
    name[142] = sPoolString(L"dummya5");
    name[143] = sPoolString(L"dummyb5");
    name[144] = sPoolString(L"");
    name[145] = sPoolString(L"mode6");
    name[146] = sPoolString(L"mode6");
    name[147] = sPoolString(L"mode6");
    name[148] = sPoolString(L"front6");
    name[149] = sPoolString(L"frontamp6");
    name[150] = sPoolString(L"middle6");
    name[151] = sPoolString(L"middleamp6");
    name[152] = sPoolString(L"back6");
    name[153] = sPoolString(L"backamp6");
    name[154] = sPoolString(L"pos6");
    name[155] = sPoolString(L"dir6");
    name[156] = sPoolString(L"range6");
    name[157] = sPoolString(L"inner6");
    name[158] = sPoolString(L"outer6");
    name[159] = sPoolString(L"falloff6");
    name[160] = sPoolString(L"shadowsize6");
    name[161] = sPoolString(L"shadowfilter0");
    name[162] = sPoolString(L"shadowbasebias6");
    name[163] = sPoolString(L"shadowfilter6");
    name[164] = sPoolString(L"shadowslopebias6");
    name[165] = sPoolString(L"dummya6");
    name[166] = sPoolString(L"dummyb6");
    name[167] = sPoolString(L"");
    name[168] = sPoolString(L"mode7");
    name[169] = sPoolString(L"mode7");
    name[170] = sPoolString(L"mode7");
    name[171] = sPoolString(L"front7");
    name[172] = sPoolString(L"frontamp7");
    name[173] = sPoolString(L"middle7");
    name[174] = sPoolString(L"middleamp7");
    name[175] = sPoolString(L"back7");
    name[176] = sPoolString(L"backamp7");
    name[177] = sPoolString(L"pos7");
    name[178] = sPoolString(L"dir7");
    name[179] = sPoolString(L"range7");
    name[180] = sPoolString(L"inner7");
    name[181] = sPoolString(L"outer7");
    name[182] = sPoolString(L"falloff7");
    name[183] = sPoolString(L"shadowsize7");
    name[184] = sPoolString(L"shadowfilter0");
    name[185] = sPoolString(L"shadowbasebias7");
    name[186] = sPoolString(L"shadowfilter7");
    name[187] = sPoolString(L"shadowslopebias7");
    name[188] = sPoolString(L"dummya7");
    name[189] = sPoolString(L"dummyb7");
    name[190] = sPoolString(L"");
    name[191] = sPoolString(L"limitshadows");
    name[192] = sPoolString(L"limitcenter");
    name[193] = sPoolString(L"limitradius");
    name[194] = sPoolString(L"transform");
    name[195] = sPoolString(L"transformenable");
    name[196] = sPoolString(L"scale");
    name[197] = sPoolString(L"rot");
    name[198] = sPoolString(L"trans");
    name[199] = sPoolString(L"");
    name[200] = sPoolString(L"script");
  }
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[10],ScriptTypeColor,1,cmd->Data+4);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[12],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[14],ScriptTypeColor,1,cmd->Data+8);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[16],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[17],ScriptTypeFloat,3,cmd->Data+13);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[26],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[27],ScriptTypeFloat,3,cmd->Data+24);
  ctx->AddImport(name[28],ScriptTypeFloat,4,cmd->Data+27);
  ctx->AddImport(name[33],ScriptTypeColor,1,cmd->Data+32);
  ctx->AddImport(name[34],ScriptTypeFloat,1,cmd->Data+33);
  ctx->AddImport(name[35],ScriptTypeColor,1,cmd->Data+34);
  ctx->AddImport(name[36],ScriptTypeFloat,1,cmd->Data+35);
  ctx->AddImport(name[37],ScriptTypeColor,1,cmd->Data+36);
  ctx->AddImport(name[38],ScriptTypeFloat,1,cmd->Data+37);
  ctx->AddImport(name[39],ScriptTypeFloat,3,cmd->Data+38);
  ctx->AddImport(name[40],ScriptTypeFloat,3,cmd->Data+41);
  ctx->AddImport(name[41],ScriptTypeFloat,1,cmd->Data+44);
  ctx->AddImport(name[42],ScriptTypeFloat,1,cmd->Data+45);
  ctx->AddImport(name[43],ScriptTypeFloat,1,cmd->Data+46);
  ctx->AddImport(name[44],ScriptTypeFloat,1,cmd->Data+47);
  ctx->AddImport(name[47],ScriptTypeFloat,1,cmd->Data+49);
  ctx->AddImport(name[48],ScriptTypeFloat,1,cmd->Data+50);
  ctx->AddImport(name[49],ScriptTypeFloat,1,cmd->Data+51);
  ctx->AddImport(name[50],ScriptTypeFloat,3,cmd->Data+52);
  ctx->AddImport(name[51],ScriptTypeFloat,4,cmd->Data+55);
  ctx->AddImport(name[56],ScriptTypeColor,1,cmd->Data+60);
  ctx->AddImport(name[57],ScriptTypeFloat,1,cmd->Data+61);
  ctx->AddImport(name[58],ScriptTypeColor,1,cmd->Data+62);
  ctx->AddImport(name[59],ScriptTypeFloat,1,cmd->Data+63);
  ctx->AddImport(name[60],ScriptTypeColor,1,cmd->Data+64);
  ctx->AddImport(name[61],ScriptTypeFloat,1,cmd->Data+65);
  ctx->AddImport(name[62],ScriptTypeFloat,3,cmd->Data+66);
  ctx->AddImport(name[63],ScriptTypeFloat,3,cmd->Data+69);
  ctx->AddImport(name[64],ScriptTypeFloat,1,cmd->Data+72);
  ctx->AddImport(name[65],ScriptTypeFloat,1,cmd->Data+73);
  ctx->AddImport(name[66],ScriptTypeFloat,1,cmd->Data+74);
  ctx->AddImport(name[67],ScriptTypeFloat,1,cmd->Data+75);
  ctx->AddImport(name[70],ScriptTypeFloat,1,cmd->Data+77);
  ctx->AddImport(name[71],ScriptTypeFloat,1,cmd->Data+78);
  ctx->AddImport(name[72],ScriptTypeFloat,1,cmd->Data+79);
  ctx->AddImport(name[73],ScriptTypeFloat,3,cmd->Data+80);
  ctx->AddImport(name[74],ScriptTypeFloat,4,cmd->Data+83);
  ctx->AddImport(name[79],ScriptTypeColor,1,cmd->Data+88);
  ctx->AddImport(name[80],ScriptTypeFloat,1,cmd->Data+89);
  ctx->AddImport(name[81],ScriptTypeColor,1,cmd->Data+90);
  ctx->AddImport(name[82],ScriptTypeFloat,1,cmd->Data+91);
  ctx->AddImport(name[83],ScriptTypeColor,1,cmd->Data+92);
  ctx->AddImport(name[84],ScriptTypeFloat,1,cmd->Data+93);
  ctx->AddImport(name[85],ScriptTypeFloat,3,cmd->Data+94);
  ctx->AddImport(name[86],ScriptTypeFloat,3,cmd->Data+97);
  ctx->AddImport(name[87],ScriptTypeFloat,1,cmd->Data+100);
  ctx->AddImport(name[88],ScriptTypeFloat,1,cmd->Data+101);
  ctx->AddImport(name[89],ScriptTypeFloat,1,cmd->Data+102);
  ctx->AddImport(name[90],ScriptTypeFloat,1,cmd->Data+103);
  ctx->AddImport(name[93],ScriptTypeFloat,1,cmd->Data+105);
  ctx->AddImport(name[94],ScriptTypeFloat,1,cmd->Data+106);
  ctx->AddImport(name[95],ScriptTypeFloat,1,cmd->Data+107);
  ctx->AddImport(name[96],ScriptTypeFloat,3,cmd->Data+108);
  ctx->AddImport(name[97],ScriptTypeFloat,4,cmd->Data+111);
  ctx->AddImport(name[102],ScriptTypeColor,1,cmd->Data+116);
  ctx->AddImport(name[103],ScriptTypeFloat,1,cmd->Data+117);
  ctx->AddImport(name[104],ScriptTypeColor,1,cmd->Data+118);
  ctx->AddImport(name[105],ScriptTypeFloat,1,cmd->Data+119);
  ctx->AddImport(name[106],ScriptTypeColor,1,cmd->Data+120);
  ctx->AddImport(name[107],ScriptTypeFloat,1,cmd->Data+121);
  ctx->AddImport(name[108],ScriptTypeFloat,3,cmd->Data+122);
  ctx->AddImport(name[109],ScriptTypeFloat,3,cmd->Data+125);
  ctx->AddImport(name[110],ScriptTypeFloat,1,cmd->Data+128);
  ctx->AddImport(name[111],ScriptTypeFloat,1,cmd->Data+129);
  ctx->AddImport(name[112],ScriptTypeFloat,1,cmd->Data+130);
  ctx->AddImport(name[113],ScriptTypeFloat,1,cmd->Data+131);
  ctx->AddImport(name[116],ScriptTypeFloat,1,cmd->Data+133);
  ctx->AddImport(name[117],ScriptTypeFloat,1,cmd->Data+134);
  ctx->AddImport(name[118],ScriptTypeFloat,1,cmd->Data+135);
  ctx->AddImport(name[119],ScriptTypeFloat,3,cmd->Data+136);
  ctx->AddImport(name[120],ScriptTypeFloat,4,cmd->Data+139);
  ctx->AddImport(name[125],ScriptTypeColor,1,cmd->Data+144);
  ctx->AddImport(name[126],ScriptTypeFloat,1,cmd->Data+145);
  ctx->AddImport(name[127],ScriptTypeColor,1,cmd->Data+146);
  ctx->AddImport(name[128],ScriptTypeFloat,1,cmd->Data+147);
  ctx->AddImport(name[129],ScriptTypeColor,1,cmd->Data+148);
  ctx->AddImport(name[130],ScriptTypeFloat,1,cmd->Data+149);
  ctx->AddImport(name[131],ScriptTypeFloat,3,cmd->Data+150);
  ctx->AddImport(name[132],ScriptTypeFloat,3,cmd->Data+153);
  ctx->AddImport(name[133],ScriptTypeFloat,1,cmd->Data+156);
  ctx->AddImport(name[134],ScriptTypeFloat,1,cmd->Data+157);
  ctx->AddImport(name[135],ScriptTypeFloat,1,cmd->Data+158);
  ctx->AddImport(name[136],ScriptTypeFloat,1,cmd->Data+159);
  ctx->AddImport(name[139],ScriptTypeFloat,1,cmd->Data+161);
  ctx->AddImport(name[140],ScriptTypeFloat,1,cmd->Data+162);
  ctx->AddImport(name[141],ScriptTypeFloat,1,cmd->Data+163);
  ctx->AddImport(name[142],ScriptTypeFloat,3,cmd->Data+164);
  ctx->AddImport(name[143],ScriptTypeFloat,4,cmd->Data+167);
  ctx->AddImport(name[148],ScriptTypeColor,1,cmd->Data+172);
  ctx->AddImport(name[149],ScriptTypeFloat,1,cmd->Data+173);
  ctx->AddImport(name[150],ScriptTypeColor,1,cmd->Data+174);
  ctx->AddImport(name[151],ScriptTypeFloat,1,cmd->Data+175);
  ctx->AddImport(name[152],ScriptTypeColor,1,cmd->Data+176);
  ctx->AddImport(name[153],ScriptTypeFloat,1,cmd->Data+177);
  ctx->AddImport(name[154],ScriptTypeFloat,3,cmd->Data+178);
  ctx->AddImport(name[155],ScriptTypeFloat,3,cmd->Data+181);
  ctx->AddImport(name[156],ScriptTypeFloat,1,cmd->Data+184);
  ctx->AddImport(name[157],ScriptTypeFloat,1,cmd->Data+185);
  ctx->AddImport(name[158],ScriptTypeFloat,1,cmd->Data+186);
  ctx->AddImport(name[159],ScriptTypeFloat,1,cmd->Data+187);
  ctx->AddImport(name[162],ScriptTypeFloat,1,cmd->Data+189);
  ctx->AddImport(name[163],ScriptTypeFloat,1,cmd->Data+190);
  ctx->AddImport(name[164],ScriptTypeFloat,1,cmd->Data+191);
  ctx->AddImport(name[165],ScriptTypeFloat,3,cmd->Data+192);
  ctx->AddImport(name[166],ScriptTypeFloat,4,cmd->Data+195);
  ctx->AddImport(name[171],ScriptTypeColor,1,cmd->Data+200);
  ctx->AddImport(name[172],ScriptTypeFloat,1,cmd->Data+201);
  ctx->AddImport(name[173],ScriptTypeColor,1,cmd->Data+202);
  ctx->AddImport(name[174],ScriptTypeFloat,1,cmd->Data+203);
  ctx->AddImport(name[175],ScriptTypeColor,1,cmd->Data+204);
  ctx->AddImport(name[176],ScriptTypeFloat,1,cmd->Data+205);
  ctx->AddImport(name[177],ScriptTypeFloat,3,cmd->Data+206);
  ctx->AddImport(name[178],ScriptTypeFloat,3,cmd->Data+209);
  ctx->AddImport(name[179],ScriptTypeFloat,1,cmd->Data+212);
  ctx->AddImport(name[180],ScriptTypeFloat,1,cmd->Data+213);
  ctx->AddImport(name[181],ScriptTypeFloat,1,cmd->Data+214);
  ctx->AddImport(name[182],ScriptTypeFloat,1,cmd->Data+215);
  ctx->AddImport(name[185],ScriptTypeFloat,1,cmd->Data+217);
  ctx->AddImport(name[186],ScriptTypeFloat,1,cmd->Data+218);
  ctx->AddImport(name[187],ScriptTypeFloat,1,cmd->Data+219);
  ctx->AddImport(name[188],ScriptTypeFloat,3,cmd->Data+220);
  ctx->AddImport(name[189],ScriptTypeFloat,4,cmd->Data+223);
  ctx->AddImport(name[192],ScriptTypeFloat,3,cmd->Data+228);
  ctx->AddImport(name[193],ScriptTypeFloat,3,cmd->Data+231);
  ctx->AddImport(name[196],ScriptTypeFloat,3,cmd->Data+235);
  ctx->AddImport(name[197],ScriptTypeFloat,3,cmd->Data+238);
  ctx->AddImport(name[198],ScriptTypeFloat,3,cmd->Data+241);
  ctx->AddImport(name[200],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ModLight(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import ambient : color;\n");
  tb.PrintF(L"  import front0 : color;\n");
  tb.PrintF(L"  import frontamp0 : float;\n");
  tb.PrintF(L"  import middle0 : color;\n");
  tb.PrintF(L"  import middleamp0 : float;\n");
  tb.PrintF(L"  import back0 : color;\n");
  tb.PrintF(L"  import backamp0 : float;\n");
  tb.PrintF(L"  import pos0 : float[3];\n");
  tb.PrintF(L"  import dir0 : float[3];\n");
  tb.PrintF(L"  import range0 : float;\n");
  tb.PrintF(L"  import inner0 : float;\n");
  tb.PrintF(L"  import outer0 : float;\n");
  tb.PrintF(L"  import falloff0 : float;\n");
  tb.PrintF(L"  import shadowbasebias0 : float;\n");
  tb.PrintF(L"  import shadowfilter0 : float;\n");
  tb.PrintF(L"  import shadowslopebias0 : float;\n");
  tb.PrintF(L"  import dummya0 : float[3];\n");
  tb.PrintF(L"  import dummyb0 : float[4];\n");
  tb.PrintF(L"  import front1 : color;\n");
  tb.PrintF(L"  import frontamp1 : float;\n");
  tb.PrintF(L"  import middle1 : color;\n");
  tb.PrintF(L"  import middleamp1 : float;\n");
  tb.PrintF(L"  import back1 : color;\n");
  tb.PrintF(L"  import backamp1 : float;\n");
  tb.PrintF(L"  import pos1 : float[3];\n");
  tb.PrintF(L"  import dir1 : float[3];\n");
  tb.PrintF(L"  import range1 : float;\n");
  tb.PrintF(L"  import inner1 : float;\n");
  tb.PrintF(L"  import outer1 : float;\n");
  tb.PrintF(L"  import falloff1 : float;\n");
  tb.PrintF(L"  import shadowbasebias1 : float;\n");
  tb.PrintF(L"  import shadowfilter1 : float;\n");
  tb.PrintF(L"  import shadowslopebias1 : float;\n");
  tb.PrintF(L"  import dummya1 : float[3];\n");
  tb.PrintF(L"  import dummyb1 : float[4];\n");
  tb.PrintF(L"  import front2 : color;\n");
  tb.PrintF(L"  import frontamp2 : float;\n");
  tb.PrintF(L"  import middle2 : color;\n");
  tb.PrintF(L"  import middleamp2 : float;\n");
  tb.PrintF(L"  import back2 : color;\n");
  tb.PrintF(L"  import backamp2 : float;\n");
  tb.PrintF(L"  import pos2 : float[3];\n");
  tb.PrintF(L"  import dir2 : float[3];\n");
  tb.PrintF(L"  import range2 : float;\n");
  tb.PrintF(L"  import inner2 : float;\n");
  tb.PrintF(L"  import outer2 : float;\n");
  tb.PrintF(L"  import falloff2 : float;\n");
  tb.PrintF(L"  import shadowbasebias2 : float;\n");
  tb.PrintF(L"  import shadowfilter2 : float;\n");
  tb.PrintF(L"  import shadowslopebias2 : float;\n");
  tb.PrintF(L"  import dummya2 : float[3];\n");
  tb.PrintF(L"  import dummyb2 : float[4];\n");
  tb.PrintF(L"  import front3 : color;\n");
  tb.PrintF(L"  import frontamp3 : float;\n");
  tb.PrintF(L"  import middle3 : color;\n");
  tb.PrintF(L"  import middleamp3 : float;\n");
  tb.PrintF(L"  import back3 : color;\n");
  tb.PrintF(L"  import backamp3 : float;\n");
  tb.PrintF(L"  import pos3 : float[3];\n");
  tb.PrintF(L"  import dir3 : float[3];\n");
  tb.PrintF(L"  import range3 : float;\n");
  tb.PrintF(L"  import inner3 : float;\n");
  tb.PrintF(L"  import outer3 : float;\n");
  tb.PrintF(L"  import falloff3 : float;\n");
  tb.PrintF(L"  import shadowbasebias3 : float;\n");
  tb.PrintF(L"  import shadowfilter3 : float;\n");
  tb.PrintF(L"  import shadowslopebias3 : float;\n");
  tb.PrintF(L"  import dummya3 : float[3];\n");
  tb.PrintF(L"  import dummyb3 : float[4];\n");
  tb.PrintF(L"  import front4 : color;\n");
  tb.PrintF(L"  import frontamp4 : float;\n");
  tb.PrintF(L"  import middle4 : color;\n");
  tb.PrintF(L"  import middleamp4 : float;\n");
  tb.PrintF(L"  import back4 : color;\n");
  tb.PrintF(L"  import backamp4 : float;\n");
  tb.PrintF(L"  import pos4 : float[3];\n");
  tb.PrintF(L"  import dir4 : float[3];\n");
  tb.PrintF(L"  import range4 : float;\n");
  tb.PrintF(L"  import inner4 : float;\n");
  tb.PrintF(L"  import outer4 : float;\n");
  tb.PrintF(L"  import falloff4 : float;\n");
  tb.PrintF(L"  import shadowbasebias4 : float;\n");
  tb.PrintF(L"  import shadowfilter4 : float;\n");
  tb.PrintF(L"  import shadowslopebias4 : float;\n");
  tb.PrintF(L"  import dummya4 : float[3];\n");
  tb.PrintF(L"  import dummyb4 : float[4];\n");
  tb.PrintF(L"  import front5 : color;\n");
  tb.PrintF(L"  import frontamp5 : float;\n");
  tb.PrintF(L"  import middle5 : color;\n");
  tb.PrintF(L"  import middleamp5 : float;\n");
  tb.PrintF(L"  import back5 : color;\n");
  tb.PrintF(L"  import backamp5 : float;\n");
  tb.PrintF(L"  import pos5 : float[3];\n");
  tb.PrintF(L"  import dir5 : float[3];\n");
  tb.PrintF(L"  import range5 : float;\n");
  tb.PrintF(L"  import inner5 : float;\n");
  tb.PrintF(L"  import outer5 : float;\n");
  tb.PrintF(L"  import falloff5 : float;\n");
  tb.PrintF(L"  import shadowbasebias5 : float;\n");
  tb.PrintF(L"  import shadowfilter5 : float;\n");
  tb.PrintF(L"  import shadowslopebias5 : float;\n");
  tb.PrintF(L"  import dummya5 : float[3];\n");
  tb.PrintF(L"  import dummyb5 : float[4];\n");
  tb.PrintF(L"  import front6 : color;\n");
  tb.PrintF(L"  import frontamp6 : float;\n");
  tb.PrintF(L"  import middle6 : color;\n");
  tb.PrintF(L"  import middleamp6 : float;\n");
  tb.PrintF(L"  import back6 : color;\n");
  tb.PrintF(L"  import backamp6 : float;\n");
  tb.PrintF(L"  import pos6 : float[3];\n");
  tb.PrintF(L"  import dir6 : float[3];\n");
  tb.PrintF(L"  import range6 : float;\n");
  tb.PrintF(L"  import inner6 : float;\n");
  tb.PrintF(L"  import outer6 : float;\n");
  tb.PrintF(L"  import falloff6 : float;\n");
  tb.PrintF(L"  import shadowbasebias6 : float;\n");
  tb.PrintF(L"  import shadowfilter6 : float;\n");
  tb.PrintF(L"  import shadowslopebias6 : float;\n");
  tb.PrintF(L"  import dummya6 : float[3];\n");
  tb.PrintF(L"  import dummyb6 : float[4];\n");
  tb.PrintF(L"  import front7 : color;\n");
  tb.PrintF(L"  import frontamp7 : float;\n");
  tb.PrintF(L"  import middle7 : color;\n");
  tb.PrintF(L"  import middleamp7 : float;\n");
  tb.PrintF(L"  import back7 : color;\n");
  tb.PrintF(L"  import backamp7 : float;\n");
  tb.PrintF(L"  import pos7 : float[3];\n");
  tb.PrintF(L"  import dir7 : float[3];\n");
  tb.PrintF(L"  import range7 : float;\n");
  tb.PrintF(L"  import inner7 : float;\n");
  tb.PrintF(L"  import outer7 : float;\n");
  tb.PrintF(L"  import falloff7 : float;\n");
  tb.PrintF(L"  import shadowbasebias7 : float;\n");
  tb.PrintF(L"  import shadowfilter7 : float;\n");
  tb.PrintF(L"  import shadowslopebias7 : float;\n");
  tb.PrintF(L"  import dummya7 : float[3];\n");
  tb.PrintF(L"  import dummyb7 : float[4];\n");
  tb.PrintF(L"  import limitcenter : float[3];\n");
  tb.PrintF(L"  import limitradius : float[3];\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiModLight =
L"= Wz4Render : ModLight\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ModLight\n"
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
L" !i Swap_RG\n"
L" !i Swap_RG\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Swap_RB\n"
L" !i Swap_RB\n"
L" !i action\n"
L" !i *\n"
L"\n"
L" !i Swap_GB\n"
L" !i Swap_GB\n"
L" !i action\n"
L" !i *\n"
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
L" !i Ambient\n"
L" !i Ambient\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode0\n"
L" !i Mode0\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode0\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode0\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front0\n"
L" !i Front0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp0\n"
L" !i FrontAmp0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle0\n"
L" !i Middle0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp0\n"
L" !i MiddleAmp0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back0\n"
L" !i Back0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp0\n"
L" !i BackAmp0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos0\n"
L" !i Pos0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir0\n"
L" !i Dir0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range0\n"
L" !i Range0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner0\n"
L" !i Inner0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer0\n"
L" !i Outer0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff0\n"
L" !i Falloff0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize0\n"
L" !i ShadowSize0\n"
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
L" !i ShadowFilter0\n"
L" !i ShadowSize0\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias0\n"
L" !i ShadowBaseBias0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter0\n"
L" !i ShadowFilter0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias0\n"
L" !i ShadowSlopeBias0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya0\n"
L" !i dummya0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb0\n"
L" !i dummyb0\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode1\n"
L" !i Mode1\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode1\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode1\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front1\n"
L" !i Front1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp1\n"
L" !i FrontAmp1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle1\n"
L" !i Middle1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp1\n"
L" !i MiddleAmp1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back1\n"
L" !i Back1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp1\n"
L" !i BackAmp1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos1\n"
L" !i Pos1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir1\n"
L" !i Dir1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range1\n"
L" !i Range1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner1\n"
L" !i Inner1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer1\n"
L" !i Outer1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff1\n"
L" !i Falloff1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize1\n"
L" !i ShadowSize1\n"
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
L" !i ShadowFilter1\n"
L" !i ShadowSize1\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias1\n"
L" !i ShadowBaseBias1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter1\n"
L" !i ShadowFilter1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias1\n"
L" !i ShadowSlopeBias1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya1\n"
L" !i dummya1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb1\n"
L" !i dummyb1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode2\n"
L" !i Mode2\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode2\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode2\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front2\n"
L" !i Front2\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp2\n"
L" !i FrontAmp2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle2\n"
L" !i Middle2\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp2\n"
L" !i MiddleAmp2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back2\n"
L" !i Back2\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp2\n"
L" !i BackAmp2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos2\n"
L" !i Pos2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir2\n"
L" !i Dir2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range2\n"
L" !i Range2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner2\n"
L" !i Inner2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer2\n"
L" !i Outer2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff2\n"
L" !i Falloff2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize2\n"
L" !i ShadowSize2\n"
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
L" !i ShadowFilter2\n"
L" !i ShadowSize2\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias2\n"
L" !i ShadowBaseBias2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter2\n"
L" !i ShadowFilter2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias2\n"
L" !i ShadowSlopeBias2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya2\n"
L" !i dummya2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb2\n"
L" !i dummyb2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode3\n"
L" !i Mode3\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode3\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode3\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front3\n"
L" !i Front3\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp3\n"
L" !i FrontAmp3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle3\n"
L" !i Middle3\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp3\n"
L" !i MiddleAmp3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back3\n"
L" !i Back3\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp3\n"
L" !i BackAmp3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos3\n"
L" !i Pos3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir3\n"
L" !i Dir3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range3\n"
L" !i Range3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner3\n"
L" !i Inner3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer3\n"
L" !i Outer3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff3\n"
L" !i Falloff3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize3\n"
L" !i ShadowSize3\n"
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
L" !i ShadowFilter3\n"
L" !i ShadowSize3\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias3\n"
L" !i ShadowBaseBias3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter3\n"
L" !i ShadowFilter3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias3\n"
L" !i ShadowSlopeBias3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya3\n"
L" !i dummya3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb3\n"
L" !i dummyb3\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode4\n"
L" !i Mode4\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode4\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode4\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front4\n"
L" !i Front4\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp4\n"
L" !i FrontAmp4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle4\n"
L" !i Middle4\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp4\n"
L" !i MiddleAmp4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back4\n"
L" !i Back4\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp4\n"
L" !i BackAmp4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos4\n"
L" !i Pos4\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir4\n"
L" !i Dir4\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range4\n"
L" !i Range4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner4\n"
L" !i Inner4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer4\n"
L" !i Outer4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff4\n"
L" !i Falloff4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize4\n"
L" !i ShadowSize4\n"
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
L" !i ShadowFilter0\n"
L" !i ShadowSize4\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias4\n"
L" !i ShadowBaseBias4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter4\n"
L" !i ShadowFilter4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias4\n"
L" !i ShadowSlopeBias4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya4\n"
L" !i dummya4\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb4\n"
L" !i dummyb4\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode5\n"
L" !i Mode5\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode5\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode5\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front5\n"
L" !i Front5\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp5\n"
L" !i FrontAmp5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle5\n"
L" !i Middle5\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp5\n"
L" !i MiddleAmp5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back5\n"
L" !i Back5\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp5\n"
L" !i BackAmp5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos5\n"
L" !i Pos5\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir5\n"
L" !i Dir5\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range5\n"
L" !i Range5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner5\n"
L" !i Inner5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer5\n"
L" !i Outer5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff5\n"
L" !i Falloff5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize5\n"
L" !i ShadowSize5\n"
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
L" !i ShadowFilter0\n"
L" !i ShadowSize5\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias5\n"
L" !i ShadowBaseBias5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter5\n"
L" !i ShadowFilter5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias5\n"
L" !i ShadowSlopeBias5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya5\n"
L" !i dummya5\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb5\n"
L" !i dummyb5\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode6\n"
L" !i Mode6\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode6\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode6\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front6\n"
L" !i Front6\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp6\n"
L" !i FrontAmp6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle6\n"
L" !i Middle6\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp6\n"
L" !i MiddleAmp6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back6\n"
L" !i Back6\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp6\n"
L" !i BackAmp6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos6\n"
L" !i Pos6\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir6\n"
L" !i Dir6\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range6\n"
L" !i Range6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner6\n"
L" !i Inner6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer6\n"
L" !i Outer6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff6\n"
L" !i Falloff6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize6\n"
L" !i ShadowSize6\n"
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
L" !i ShadowFilter0\n"
L" !i ShadowSize6\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias6\n"
L" !i ShadowBaseBias6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter6\n"
L" !i ShadowFilter6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias6\n"
L" !i ShadowSlopeBias6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya6\n"
L" !i dummya6\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb6\n"
L" !i dummyb6\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode7\n"
L" !i Mode7\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i dir\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i spot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode7\n"
L" !i shadow\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i headlight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Mode7\n"
L" !i inner\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i falloff\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Front7\n"
L" !i Front7\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i FrontAmp7\n"
L" !i FrontAmp7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Middle7\n"
L" !i Middle7\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MiddleAmp7\n"
L" !i MiddleAmp7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Back7\n"
L" !i Back7\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i BackAmp7\n"
L" !i BackAmp7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Pos7\n"
L" !i Pos7\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir7\n"
L" !i Dir7\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range7\n"
L" !i Range7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Inner7\n"
L" !i Inner7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer7\n"
L" !i Outer7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff7\n"
L" !i Falloff7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize7\n"
L" !i ShadowSize7\n"
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
L" !i ShadowFilter0\n"
L" !i ShadowSize7\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias7\n"
L" !i ShadowBaseBias7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter7\n"
L" !i ShadowFilter7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias7\n"
L" !i ShadowSlopeBias7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i dummya7\n"
L" !i dummya7\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i dummyb7\n"
L" !i dummyb7\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i LimitShadows\n"
L" !i LimitShadows\n"
L" !i 0\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i LimitCenter\n"
L" !i LimitCenter\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i LimitRadius\n"
L" !i LimitRadius\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i TransformEnable\n"
L" !i TransformEnable\n"
L" !i transformed\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdModMisc(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaModMisc sUNUSED *para = (Wz4RenderParaModMisc *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 748 "wz4_modmtrl_ops.ops"

    RNModMisc *node = new RNModMisc;
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 5184 "wz4_modmtrl_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiModMisc(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaModMisc sUNUSED *para = (Wz4RenderParaModMisc *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"misc colors");

  gh.Label(L"* Color0");
  gh.ColorPick(&para->Color0,L"rgb",0);

  sFloatControl *float_Amp0 = gh.Float(&para->Amp0,0.000000f,1024.000f,0.010000f);
  float_Amp0->Default = 1.000000f; float_Amp0->RightStep = 0.125000f;

  gh.Label(L"* Color1");
  gh.ColorPick(&para->Color1,L"rgb",0);

  sFloatControl *float_Amp1 = gh.Float(&para->Amp1,0.000000f,1024.000f,0.010000f);
  float_Amp1->Default = 1.000000f; float_Amp1->RightStep = 0.125000f;

  gh.Label(L"* Color2");
  gh.ColorPick(&para->Color2,L"rgb",0);

  sFloatControl *float_Amp2 = gh.Float(&para->Amp2,0.000000f,1024.000f,0.010000f);
  float_Amp2->Default = 1.000000f; float_Amp2->RightStep = 0.125000f;

  gh.Label(L"* Color3");
  gh.ColorPick(&para->Color3,L"rgb",0);

  sFloatControl *float_Amp3 = gh.Float(&para->Amp3,0.000000f,1024.000f,0.010000f);
  float_Amp3->Default = 1.000000f; float_Amp3->RightStep = 0.125000f;

  gh.Label(L"* Color4");
  gh.ColorPick(&para->Color4,L"rgb",0);

  sFloatControl *float_Amp4 = gh.Float(&para->Amp4,0.000000f,1024.000f,0.010000f);
  float_Amp4->Default = 1.000000f; float_Amp4->RightStep = 0.125000f;

  gh.Label(L"* Color5");
  gh.ColorPick(&para->Color5,L"rgb",0);

  sFloatControl *float_Amp5 = gh.Float(&para->Amp5,0.000000f,1024.000f,0.010000f);
  float_Amp5->Default = 1.000000f; float_Amp5->RightStep = 0.125000f;

  gh.Label(L"* Color6");
  gh.ColorPick(&para->Color6,L"rgb",0);

  sFloatControl *float_Amp6 = gh.Float(&para->Amp6,0.000000f,1024.000f,0.010000f);
  float_Amp6->Default = 1.000000f; float_Amp6->RightStep = 0.125000f;

  gh.Label(L"* Color7");
  gh.ColorPick(&para->Color7,L"rgb",0);

  sFloatControl *float_Amp7 = gh.Float(&para->Amp7,0.000000f,1024.000f,0.010000f);
  float_Amp7->Default = 1.000000f; float_Amp7->RightStep = 0.125000f;

  gh.Group(L"misc vectors");

  gh.Label(L"* Vector0");
  gh.BeginTied();
  sFloatControl *float_Vector0_0 = gh.Float(&para->Vector0.x, -1000000,  1000000,0.010000f);
  float_Vector0_0->Default = 0.000000f; float_Vector0_0->RightStep = 0.125000f;
  sFloatControl *float_Vector0_1 = gh.Float(&para->Vector0.y, -1000000,  1000000,0.010000f);
  float_Vector0_1->Default = 0.000000f; float_Vector0_1->RightStep = 0.125000f;
  sFloatControl *float_Vector0_2 = gh.Float(&para->Vector0.z, -1000000,  1000000,0.010000f);
  float_Vector0_2->Default = 0.000000f; float_Vector0_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector1");
  gh.BeginTied();
  sFloatControl *float_Vector1_0 = gh.Float(&para->Vector1.x, -1000000,  1000000,0.010000f);
  float_Vector1_0->Default = 0.000000f; float_Vector1_0->RightStep = 0.125000f;
  sFloatControl *float_Vector1_1 = gh.Float(&para->Vector1.y, -1000000,  1000000,0.010000f);
  float_Vector1_1->Default = 0.000000f; float_Vector1_1->RightStep = 0.125000f;
  sFloatControl *float_Vector1_2 = gh.Float(&para->Vector1.z, -1000000,  1000000,0.010000f);
  float_Vector1_2->Default = 0.000000f; float_Vector1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector2");
  gh.BeginTied();
  sFloatControl *float_Vector2_0 = gh.Float(&para->Vector2.x, -1000000,  1000000,0.010000f);
  float_Vector2_0->Default = 0.000000f; float_Vector2_0->RightStep = 0.125000f;
  sFloatControl *float_Vector2_1 = gh.Float(&para->Vector2.y, -1000000,  1000000,0.010000f);
  float_Vector2_1->Default = 0.000000f; float_Vector2_1->RightStep = 0.125000f;
  sFloatControl *float_Vector2_2 = gh.Float(&para->Vector2.z, -1000000,  1000000,0.010000f);
  float_Vector2_2->Default = 0.000000f; float_Vector2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector3");
  gh.BeginTied();
  sFloatControl *float_Vector3_0 = gh.Float(&para->Vector3.x, -1000000,  1000000,0.010000f);
  float_Vector3_0->Default = 0.000000f; float_Vector3_0->RightStep = 0.125000f;
  sFloatControl *float_Vector3_1 = gh.Float(&para->Vector3.y, -1000000,  1000000,0.010000f);
  float_Vector3_1->Default = 0.000000f; float_Vector3_1->RightStep = 0.125000f;
  sFloatControl *float_Vector3_2 = gh.Float(&para->Vector3.z, -1000000,  1000000,0.010000f);
  float_Vector3_2->Default = 0.000000f; float_Vector3_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector4");
  gh.BeginTied();
  sFloatControl *float_Vector4_0 = gh.Float(&para->Vector4.x, -1000000,  1000000,0.010000f);
  float_Vector4_0->Default = 0.000000f; float_Vector4_0->RightStep = 0.125000f;
  sFloatControl *float_Vector4_1 = gh.Float(&para->Vector4.y, -1000000,  1000000,0.010000f);
  float_Vector4_1->Default = 0.000000f; float_Vector4_1->RightStep = 0.125000f;
  sFloatControl *float_Vector4_2 = gh.Float(&para->Vector4.z, -1000000,  1000000,0.010000f);
  float_Vector4_2->Default = 0.000000f; float_Vector4_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector5");
  gh.BeginTied();
  sFloatControl *float_Vector5_0 = gh.Float(&para->Vector5.x, -1000000,  1000000,0.010000f);
  float_Vector5_0->Default = 0.000000f; float_Vector5_0->RightStep = 0.125000f;
  sFloatControl *float_Vector5_1 = gh.Float(&para->Vector5.y, -1000000,  1000000,0.010000f);
  float_Vector5_1->Default = 0.000000f; float_Vector5_1->RightStep = 0.125000f;
  sFloatControl *float_Vector5_2 = gh.Float(&para->Vector5.z, -1000000,  1000000,0.010000f);
  float_Vector5_2->Default = 0.000000f; float_Vector5_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector6");
  gh.BeginTied();
  sFloatControl *float_Vector6_0 = gh.Float(&para->Vector6.x, -1000000,  1000000,0.010000f);
  float_Vector6_0->Default = 0.000000f; float_Vector6_0->RightStep = 0.125000f;
  sFloatControl *float_Vector6_1 = gh.Float(&para->Vector6.y, -1000000,  1000000,0.010000f);
  float_Vector6_1->Default = 0.000000f; float_Vector6_1->RightStep = 0.125000f;
  sFloatControl *float_Vector6_2 = gh.Float(&para->Vector6.z, -1000000,  1000000,0.010000f);
  float_Vector6_2->Default = 0.000000f; float_Vector6_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Vector7");
  gh.BeginTied();
  sFloatControl *float_Vector7_0 = gh.Float(&para->Vector7.x, -1000000,  1000000,0.010000f);
  float_Vector7_0->Default = 0.000000f; float_Vector7_0->RightStep = 0.125000f;
  sFloatControl *float_Vector7_1 = gh.Float(&para->Vector7.y, -1000000,  1000000,0.010000f);
  float_Vector7_1->Default = 0.000000f; float_Vector7_1->RightStep = 0.125000f;
  sFloatControl *float_Vector7_2 = gh.Float(&para->Vector7.z, -1000000,  1000000,0.010000f);
  float_Vector7_2->Default = 0.000000f; float_Vector7_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"misc matrix 0");

  gh.Label(L"* Scale0");
  gh.BeginTied();
  sFloatControl *float_Scale0_0 = gh.Float(&para->Scale0.x,-1024.00f,1024.000f,0.010000f);
  float_Scale0_0->Default = 1.000000f; float_Scale0_0->RightStep = 0.125000f;
  sFloatControl *float_Scale0_1 = gh.Float(&para->Scale0.y,-1024.00f,1024.000f,0.010000f);
  float_Scale0_1->Default = 1.000000f; float_Scale0_1->RightStep = 0.125000f;
  sFloatControl *float_Scale0_2 = gh.Float(&para->Scale0.z,-1024.00f,1024.000f,0.010000f);
  float_Scale0_2->Default = 1.000000f; float_Scale0_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot0");
  gh.BeginTied();
  sFloatControl *float_Rot0_0 = gh.Float(&para->Rot0.x,-16.0000f,16.00000f,0.001000f);
  float_Rot0_0->Default = 0.000000f; float_Rot0_0->RightStep = 0.125000f;
  sFloatControl *float_Rot0_1 = gh.Float(&para->Rot0.y,-16.0000f,16.00000f,0.001000f);
  float_Rot0_1->Default = 0.000000f; float_Rot0_1->RightStep = 0.125000f;
  sFloatControl *float_Rot0_2 = gh.Float(&para->Rot0.z,-16.0000f,16.00000f,0.001000f);
  float_Rot0_2->Default = 0.000000f; float_Rot0_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans0");
  gh.BeginTied();
  sFloatControl *float_Trans0_0 = gh.Float(&para->Trans0.x,-1024.00f,1024.000f,0.010000f);
  float_Trans0_0->Default = 0.000000f; float_Trans0_0->RightStep = 0.125000f;
  sFloatControl *float_Trans0_1 = gh.Float(&para->Trans0.y,-1024.00f,1024.000f,0.010000f);
  float_Trans0_1->Default = 0.000000f; float_Trans0_1->RightStep = 0.125000f;
  sFloatControl *float_Trans0_2 = gh.Float(&para->Trans0.z,-1024.00f,1024.000f,0.010000f);
  float_Trans0_2->Default = 0.000000f; float_Trans0_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"misc matrix 1");

  gh.Label(L"* Scale1");
  gh.BeginTied();
  sFloatControl *float_Scale1_0 = gh.Float(&para->Scale1.x,-1024.00f,1024.000f,0.010000f);
  float_Scale1_0->Default = 1.000000f; float_Scale1_0->RightStep = 0.125000f;
  sFloatControl *float_Scale1_1 = gh.Float(&para->Scale1.y,-1024.00f,1024.000f,0.010000f);
  float_Scale1_1->Default = 1.000000f; float_Scale1_1->RightStep = 0.125000f;
  sFloatControl *float_Scale1_2 = gh.Float(&para->Scale1.z,-1024.00f,1024.000f,0.010000f);
  float_Scale1_2->Default = 1.000000f; float_Scale1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot1");
  gh.BeginTied();
  sFloatControl *float_Rot1_0 = gh.Float(&para->Rot1.x,-16.0000f,16.00000f,0.001000f);
  float_Rot1_0->Default = 0.000000f; float_Rot1_0->RightStep = 0.125000f;
  sFloatControl *float_Rot1_1 = gh.Float(&para->Rot1.y,-16.0000f,16.00000f,0.001000f);
  float_Rot1_1->Default = 0.000000f; float_Rot1_1->RightStep = 0.125000f;
  sFloatControl *float_Rot1_2 = gh.Float(&para->Rot1.z,-16.0000f,16.00000f,0.001000f);
  float_Rot1_2->Default = 0.000000f; float_Rot1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans1");
  gh.BeginTied();
  sFloatControl *float_Trans1_0 = gh.Float(&para->Trans1.x,-1024.00f,1024.000f,0.010000f);
  float_Trans1_0->Default = 0.000000f; float_Trans1_0->RightStep = 0.125000f;
  sFloatControl *float_Trans1_1 = gh.Float(&para->Trans1.y,-1024.00f,1024.000f,0.010000f);
  float_Trans1_1->Default = 0.000000f; float_Trans1_1->RightStep = 0.125000f;
  sFloatControl *float_Trans1_2 = gh.Float(&para->Trans1.z,-1024.00f,1024.000f,0.010000f);
  float_Trans1_2->Default = 0.000000f; float_Trans1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"misc matrix 2");

  gh.Label(L"* Scale2");
  gh.BeginTied();
  sFloatControl *float_Scale2_0 = gh.Float(&para->Scale2.x,-1024.00f,1024.000f,0.010000f);
  float_Scale2_0->Default = 1.000000f; float_Scale2_0->RightStep = 0.125000f;
  sFloatControl *float_Scale2_1 = gh.Float(&para->Scale2.y,-1024.00f,1024.000f,0.010000f);
  float_Scale2_1->Default = 1.000000f; float_Scale2_1->RightStep = 0.125000f;
  sFloatControl *float_Scale2_2 = gh.Float(&para->Scale2.z,-1024.00f,1024.000f,0.010000f);
  float_Scale2_2->Default = 1.000000f; float_Scale2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot2");
  gh.BeginTied();
  sFloatControl *float_Rot2_0 = gh.Float(&para->Rot2.x,-16.0000f,16.00000f,0.001000f);
  float_Rot2_0->Default = 0.000000f; float_Rot2_0->RightStep = 0.125000f;
  sFloatControl *float_Rot2_1 = gh.Float(&para->Rot2.y,-16.0000f,16.00000f,0.001000f);
  float_Rot2_1->Default = 0.000000f; float_Rot2_1->RightStep = 0.125000f;
  sFloatControl *float_Rot2_2 = gh.Float(&para->Rot2.z,-16.0000f,16.00000f,0.001000f);
  float_Rot2_2->Default = 0.000000f; float_Rot2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans2");
  gh.BeginTied();
  sFloatControl *float_Trans2_0 = gh.Float(&para->Trans2.x,-1024.00f,1024.000f,0.010000f);
  float_Trans2_0->Default = 0.000000f; float_Trans2_0->RightStep = 0.125000f;
  sFloatControl *float_Trans2_1 = gh.Float(&para->Trans2.y,-1024.00f,1024.000f,0.010000f);
  float_Trans2_1->Default = 0.000000f; float_Trans2_1->RightStep = 0.125000f;
  sFloatControl *float_Trans2_2 = gh.Float(&para->Trans2.z,-1024.00f,1024.000f,0.010000f);
  float_Trans2_2->Default = 0.000000f; float_Trans2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"misc matrix 3");

  gh.Label(L"* Scale3");
  gh.BeginTied();
  sFloatControl *float_Scale3_0 = gh.Float(&para->Scale3.x,-1024.00f,1024.000f,0.010000f);
  float_Scale3_0->Default = 1.000000f; float_Scale3_0->RightStep = 0.125000f;
  sFloatControl *float_Scale3_1 = gh.Float(&para->Scale3.y,-1024.00f,1024.000f,0.010000f);
  float_Scale3_1->Default = 1.000000f; float_Scale3_1->RightStep = 0.125000f;
  sFloatControl *float_Scale3_2 = gh.Float(&para->Scale3.z,-1024.00f,1024.000f,0.010000f);
  float_Scale3_2->Default = 1.000000f; float_Scale3_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Rot3");
  gh.BeginTied();
  sFloatControl *float_Rot3_0 = gh.Float(&para->Rot3.x,-16.0000f,16.00000f,0.001000f);
  float_Rot3_0->Default = 0.000000f; float_Rot3_0->RightStep = 0.125000f;
  sFloatControl *float_Rot3_1 = gh.Float(&para->Rot3.y,-16.0000f,16.00000f,0.001000f);
  float_Rot3_1->Default = 0.000000f; float_Rot3_1->RightStep = 0.125000f;
  sFloatControl *float_Rot3_2 = gh.Float(&para->Rot3.z,-16.0000f,16.00000f,0.001000f);
  float_Rot3_2->Default = 0.000000f; float_Rot3_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans3");
  gh.BeginTied();
  sFloatControl *float_Trans3_0 = gh.Float(&para->Trans3.x,-1024.00f,1024.000f,0.010000f);
  float_Trans3_0->Default = 0.000000f; float_Trans3_0->RightStep = 0.125000f;
  sFloatControl *float_Trans3_1 = gh.Float(&para->Trans3.y,-1024.00f,1024.000f,0.010000f);
  float_Trans3_1->Default = 0.000000f; float_Trans3_1->RightStep = 0.125000f;
  sFloatControl *float_Trans3_2 = gh.Float(&para->Trans3.z,-1024.00f,1024.000f,0.010000f);
  float_Trans3_2->Default = 0.000000f; float_Trans3_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefModMisc(wOp *op)
{
  Wz4RenderParaModMisc sUNUSED *para = (Wz4RenderParaModMisc *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Amp0 = 1.000000f;
  para->Amp1 = 1.000000f;
  para->Amp2 = 1.000000f;
  para->Amp3 = 1.000000f;
  para->Amp4 = 1.000000f;
  para->Amp5 = 1.000000f;
  para->Amp6 = 1.000000f;
  para->Amp7 = 1.000000f;
  para->Scale0.x = 1.000000f;
  para->Scale0.y = 1.000000f;
  para->Scale0.z = 1.000000f;
  para->Scale1.x = 1.000000f;
  para->Scale1.y = 1.000000f;
  para->Scale1.z = 1.000000f;
  para->Scale2.x = 1.000000f;
  para->Scale2.y = 1.000000f;
  para->Scale2.z = 1.000000f;
  para->Scale3.x = 1.000000f;
  para->Scale3.y = 1.000000f;
  para->Scale3.z = 1.000000f;
}

void Wz4RenderBindModMisc(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"amp0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"amp1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"color2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"amp2"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"color3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"amp3"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"color4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"amp4"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"color5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"amp5"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"color6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"amp6"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"color7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"amp7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vector0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vector0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"vector0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"vector1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"vector1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"vector1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"vector2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"vector2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"vector2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"vector3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"vector3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"vector3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"vector4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"vector4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"vector4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"vector5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"vector5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"vector5"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"vector6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"vector6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"vector6"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"vector7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"vector7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"vector7"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"scale0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"scale0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"scale0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"rot0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"rot0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"rot0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"trans0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"trans0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"trans0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"rot1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"rot1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"rot1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+57;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+57;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+57;
  ctx->BindLocal(ctx->AddSymbol(L"trans1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+60;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+60;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+60;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+63;
  ctx->BindLocal(ctx->AddSymbol(L"rot2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+63;
  ctx->BindLocal(ctx->AddSymbol(L"rot2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+63;
  ctx->BindLocal(ctx->AddSymbol(L"rot2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+66;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+66;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+66;
  ctx->BindLocal(ctx->AddSymbol(L"trans2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+69;
  ctx->BindLocal(ctx->AddSymbol(L"scale3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+69;
  ctx->BindLocal(ctx->AddSymbol(L"scale3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+69;
  ctx->BindLocal(ctx->AddSymbol(L"scale3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+72;
  ctx->BindLocal(ctx->AddSymbol(L"rot3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+72;
  ctx->BindLocal(ctx->AddSymbol(L"rot3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+72;
  ctx->BindLocal(ctx->AddSymbol(L"rot3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+75;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+75;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+75;
  ctx->BindLocal(ctx->AddSymbol(L"trans3"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ModMisc(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[46];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"color0");
    name[4] = sPoolString(L"amp0");
    name[5] = sPoolString(L"color1");
    name[6] = sPoolString(L"amp1");
    name[7] = sPoolString(L"color2");
    name[8] = sPoolString(L"amp2");
    name[9] = sPoolString(L"color3");
    name[10] = sPoolString(L"amp3");
    name[11] = sPoolString(L"color4");
    name[12] = sPoolString(L"amp4");
    name[13] = sPoolString(L"color5");
    name[14] = sPoolString(L"amp5");
    name[15] = sPoolString(L"color6");
    name[16] = sPoolString(L"amp6");
    name[17] = sPoolString(L"color7");
    name[18] = sPoolString(L"amp7");
    name[19] = sPoolString(L"");
    name[20] = sPoolString(L"vector0");
    name[21] = sPoolString(L"vector1");
    name[22] = sPoolString(L"vector2");
    name[23] = sPoolString(L"vector3");
    name[24] = sPoolString(L"vector4");
    name[25] = sPoolString(L"vector5");
    name[26] = sPoolString(L"vector6");
    name[27] = sPoolString(L"vector7");
    name[28] = sPoolString(L"");
    name[29] = sPoolString(L"scale0");
    name[30] = sPoolString(L"rot0");
    name[31] = sPoolString(L"trans0");
    name[32] = sPoolString(L"");
    name[33] = sPoolString(L"scale1");
    name[34] = sPoolString(L"rot1");
    name[35] = sPoolString(L"trans1");
    name[36] = sPoolString(L"");
    name[37] = sPoolString(L"scale2");
    name[38] = sPoolString(L"rot2");
    name[39] = sPoolString(L"trans2");
    name[40] = sPoolString(L"");
    name[41] = sPoolString(L"scale3");
    name[42] = sPoolString(L"rot3");
    name[43] = sPoolString(L"trans3");
    name[44] = sPoolString(L"");
    name[45] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeColor,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeColor,1,cmd->Data+8);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[11],ScriptTypeColor,1,cmd->Data+10);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[13],ScriptTypeColor,1,cmd->Data+12);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[15],ScriptTypeColor,1,cmd->Data+14);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[17],ScriptTypeColor,1,cmd->Data+16);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[20],ScriptTypeFloat,3,cmd->Data+18);
  ctx->AddImport(name[21],ScriptTypeFloat,3,cmd->Data+21);
  ctx->AddImport(name[22],ScriptTypeFloat,3,cmd->Data+24);
  ctx->AddImport(name[23],ScriptTypeFloat,3,cmd->Data+27);
  ctx->AddImport(name[24],ScriptTypeFloat,3,cmd->Data+30);
  ctx->AddImport(name[25],ScriptTypeFloat,3,cmd->Data+33);
  ctx->AddImport(name[26],ScriptTypeFloat,3,cmd->Data+36);
  ctx->AddImport(name[27],ScriptTypeFloat,3,cmd->Data+39);
  ctx->AddImport(name[29],ScriptTypeFloat,3,cmd->Data+42);
  ctx->AddImport(name[30],ScriptTypeFloat,3,cmd->Data+45);
  ctx->AddImport(name[31],ScriptTypeFloat,3,cmd->Data+48);
  ctx->AddImport(name[33],ScriptTypeFloat,3,cmd->Data+51);
  ctx->AddImport(name[34],ScriptTypeFloat,3,cmd->Data+54);
  ctx->AddImport(name[35],ScriptTypeFloat,3,cmd->Data+57);
  ctx->AddImport(name[37],ScriptTypeFloat,3,cmd->Data+60);
  ctx->AddImport(name[38],ScriptTypeFloat,3,cmd->Data+63);
  ctx->AddImport(name[39],ScriptTypeFloat,3,cmd->Data+66);
  ctx->AddImport(name[41],ScriptTypeFloat,3,cmd->Data+69);
  ctx->AddImport(name[42],ScriptTypeFloat,3,cmd->Data+72);
  ctx->AddImport(name[43],ScriptTypeFloat,3,cmd->Data+75);
  ctx->AddImport(name[45],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ModMisc(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import amp0 : float;\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import amp1 : float;\n");
  tb.PrintF(L"  import color2 : color;\n");
  tb.PrintF(L"  import amp2 : float;\n");
  tb.PrintF(L"  import color3 : color;\n");
  tb.PrintF(L"  import amp3 : float;\n");
  tb.PrintF(L"  import color4 : color;\n");
  tb.PrintF(L"  import amp4 : float;\n");
  tb.PrintF(L"  import color5 : color;\n");
  tb.PrintF(L"  import amp5 : float;\n");
  tb.PrintF(L"  import color6 : color;\n");
  tb.PrintF(L"  import amp6 : float;\n");
  tb.PrintF(L"  import color7 : color;\n");
  tb.PrintF(L"  import amp7 : float;\n");
  tb.PrintF(L"  import vector0 : float[3];\n");
  tb.PrintF(L"  import vector1 : float[3];\n");
  tb.PrintF(L"  import vector2 : float[3];\n");
  tb.PrintF(L"  import vector3 : float[3];\n");
  tb.PrintF(L"  import vector4 : float[3];\n");
  tb.PrintF(L"  import vector5 : float[3];\n");
  tb.PrintF(L"  import vector6 : float[3];\n");
  tb.PrintF(L"  import vector7 : float[3];\n");
  tb.PrintF(L"  import scale0 : float[3];\n");
  tb.PrintF(L"  import rot0 : float[3];\n");
  tb.PrintF(L"  import trans0 : float[3];\n");
  tb.PrintF(L"  import scale1 : float[3];\n");
  tb.PrintF(L"  import rot1 : float[3];\n");
  tb.PrintF(L"  import trans1 : float[3];\n");
  tb.PrintF(L"  import scale2 : float[3];\n");
  tb.PrintF(L"  import rot2 : float[3];\n");
  tb.PrintF(L"  import trans2 : float[3];\n");
  tb.PrintF(L"  import scale3 : float[3];\n");
  tb.PrintF(L"  import rot3 : float[3];\n");
  tb.PrintF(L"  import trans3 : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiModMisc =
L"= Wz4Render : ModMisc\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ModMisc\n"
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
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp0\n"
L" !i Amp0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp1\n"
L" !i Amp1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color2\n"
L" !i Color2\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp2\n"
L" !i Amp2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color3\n"
L" !i Color3\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp3\n"
L" !i Amp3\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color4\n"
L" !i Color4\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp4\n"
L" !i Amp4\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color5\n"
L" !i Color5\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp5\n"
L" !i Amp5\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color6\n"
L" !i Color6\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp6\n"
L" !i Amp6\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color7\n"
L" !i Color7\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp7\n"
L" !i Amp7\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Vector0\n"
L" !i Vector0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector1\n"
L" !i Vector1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector2\n"
L" !i Vector2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector3\n"
L" !i Vector3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector4\n"
L" !i Vector4\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector5\n"
L" !i Vector5\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector6\n"
L" !i Vector6\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Vector7\n"
L" !i Vector7\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Scale0\n"
L" !i Scale0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot0\n"
L" !i Rot0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans0\n"
L" !i Trans0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Scale1\n"
L" !i Scale1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot1\n"
L" !i Rot1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans1\n"
L" !i Trans1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Scale2\n"
L" !i Scale2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot2\n"
L" !i Rot2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans2\n"
L" !i Trans2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Scale3\n"
L" !i Scale3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot3\n"
L" !i Rot3\n"
L" !i float[3]\n"
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

sBool Wz4RenderCmdModLightEnv(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaModLightEnv sUNUSED *para = (Wz4RenderParaModLightEnv *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 826 "wz4_modmtrl_ops.ops"

    RNModLightEnv *node = new RNModLightEnv;
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 6130 "wz4_modmtrl_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiModLightEnv(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaModLightEnv sUNUSED *para = (Wz4RenderParaModLightEnv *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"Features");
  gh.Flags(&para->Features,L"-|Fog:*1-|GroundFog:*2-|Clip Planes",gh.LayoutMsg);

  if((para->Features&0x0001))
  {
    gh.Group(L"Fog");

    gh.Label(L"* FogNear");
    sFloatControl *float_FogNear = gh.Float(&para->FogNear, -1000000,  1000000,0.010000f);
    float_FogNear->Default = 0.000000f; float_FogNear->RightStep = 0.125000f;

    gh.Label(L"* FogFar");
    sFloatControl *float_FogFar = gh.Float(&para->FogFar, -1000000,  1000000,4.000000f);
    float_FogFar->Default = 1000.000f; float_FogFar->RightStep = 0.125000f;

    gh.Label(L"* FogDensity");
    sFloatControl *float_FogDensity = gh.Float(&para->FogDensity,0.000000f,1.000000f,0.002000f);
    float_FogDensity->Default = 1.000000f; float_FogDensity->RightStep = 0.125000f;

    gh.Label(L"* FogColor");
    gh.ColorPick(&para->FogColor,L"rgb",0);

  }
  if(((para->Features&0x0001)&&0x0000))
  {
    gh.Label(L"dummya");
    gh.BeginTied();
    sIntControl *int_dummya_0 = gh.Int(&para->dummya[0],0,255,0.125000f);
    int_dummya_0->Default = 0x00000000; int_dummya_0->RightStep = 0.125000f;
    sIntControl *int_dummya_1 = gh.Int(&para->dummya[1],0,255,0.125000f);
    int_dummya_1->Default = 0x00000000; int_dummya_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Features&0x0002))
  {
    gh.Group(L"Ground Fog");

    gh.Label(L"* GroundFogNear");
    sFloatControl *float_GroundFogNear = gh.Float(&para->GroundFogNear, -1000000,  1000000,0.010000f);
    float_GroundFogNear->Default = 0.000000f; float_GroundFogNear->RightStep = 0.125000f;

    gh.Label(L"* GroundFogFar");
    sFloatControl *float_GroundFogFar = gh.Float(&para->GroundFogFar, -1000000,  1000000,4.000000f);
    float_GroundFogFar->Default = 12.00000f; float_GroundFogFar->RightStep = 0.125000f;

    gh.Label(L"* GroundFogDensity");
    sFloatControl *float_GroundFogDensity = gh.Float(&para->GroundFogDensity,0.000000f,1.000000f,0.002000f);
    float_GroundFogDensity->Default = 1.000000f; float_GroundFogDensity->RightStep = 0.125000f;

    gh.Label(L"* GroundFogColor");
    gh.ColorPick(&para->GroundFogColor,L"rgb",0);

    gh.Label(L"* GroundFogPlane");
    gh.BeginTied();
    sFloatControl *float_GroundFogPlane_0 = gh.Float(&para->GroundFogPlane.x, -1000000,  1000000,0.010000f);
    float_GroundFogPlane_0->Default = 0.000000f; float_GroundFogPlane_0->RightStep = 0.125000f;
    sFloatControl *float_GroundFogPlane_1 = gh.Float(&para->GroundFogPlane.y, -1000000,  1000000,0.010000f);
    float_GroundFogPlane_1->Default = 1.000000f; float_GroundFogPlane_1->RightStep = 0.125000f;
    sFloatControl *float_GroundFogPlane_2 = gh.Float(&para->GroundFogPlane.z, -1000000,  1000000,0.010000f);
    float_GroundFogPlane_2->Default = 0.000000f; float_GroundFogPlane_2->RightStep = 0.125000f;
    sFloatControl *float_GroundFogPlane_3 = gh.Float(&para->GroundFogPlane.w, -1000000,  1000000,0.010000f);
    float_GroundFogPlane_3->Default = 0.000000f; float_GroundFogPlane_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((para->Features&0x0002)&&0x0000))
  {
    gh.Label(L"dummyb");
    gh.BeginTied();
    sIntControl *int_dummyb_0 = gh.Int(&para->dummyb[0],0,255,0.125000f);
    int_dummyb_0->Default = 0x00000000; int_dummyb_0->RightStep = 0.125000f;
    sIntControl *int_dummyb_1 = gh.Int(&para->dummyb[1],0,255,0.125000f);
    int_dummyb_1->Default = 0x00000000; int_dummyb_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Features&0x0004))
  {
    gh.Group(L"Clip Planes");

    gh.Label(L"Clip0");
    gh.Flags(&para->ClipEnable,L"-|on",gh.LayoutMsg);

  }
  if(((para->Features&0x0004)&&(para->ClipEnable&0x0001)))
  {
    gh.BeginTied();
    sFloatControl *float_Clip0_0 = gh.Float(&para->Clip0.x, -1000000,  1000000,0.010000f);
    float_Clip0_0->Default = 1.000000f; float_Clip0_0->RightStep = 0.125000f;
    sFloatControl *float_Clip0_1 = gh.Float(&para->Clip0.y, -1000000,  1000000,0.010000f);
    float_Clip0_1->Default = 0.000000f; float_Clip0_1->RightStep = 0.125000f;
    sFloatControl *float_Clip0_2 = gh.Float(&para->Clip0.z, -1000000,  1000000,0.010000f);
    float_Clip0_2->Default = 0.000000f; float_Clip0_2->RightStep = 0.125000f;
    sFloatControl *float_Clip0_3 = gh.Float(&para->Clip0.w, -1000000,  1000000,0.010000f);
    float_Clip0_3->Default = 0.000000f; float_Clip0_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Features&0x0004))
  {
    gh.Label(L"Clip1");
    gh.Flags(&para->ClipEnable,L"*1-|on",gh.LayoutMsg);

  }
  if(((para->Features&0x0004)&&(para->ClipEnable&0x0002)))
  {
    gh.BeginTied();
    sFloatControl *float_Clip1_0 = gh.Float(&para->Clip1.x, -1000000,  1000000,0.010000f);
    float_Clip1_0->Default = 1.000000f; float_Clip1_0->RightStep = 0.125000f;
    sFloatControl *float_Clip1_1 = gh.Float(&para->Clip1.y, -1000000,  1000000,0.010000f);
    float_Clip1_1->Default = 0.000000f; float_Clip1_1->RightStep = 0.125000f;
    sFloatControl *float_Clip1_2 = gh.Float(&para->Clip1.z, -1000000,  1000000,0.010000f);
    float_Clip1_2->Default = 0.000000f; float_Clip1_2->RightStep = 0.125000f;
    sFloatControl *float_Clip1_3 = gh.Float(&para->Clip1.w, -1000000,  1000000,0.010000f);
    float_Clip1_3->Default = 0.000000f; float_Clip1_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Features&0x0004))
  {
    gh.Label(L"Clip2");
    gh.Flags(&para->ClipEnable,L"*2-|on",gh.LayoutMsg);

  }
  if(((para->Features&0x0004)&&(para->ClipEnable&0x0004)))
  {
    gh.BeginTied();
    sFloatControl *float_Clip2_0 = gh.Float(&para->Clip2.x, -1000000,  1000000,0.010000f);
    float_Clip2_0->Default = 1.000000f; float_Clip2_0->RightStep = 0.125000f;
    sFloatControl *float_Clip2_1 = gh.Float(&para->Clip2.y, -1000000,  1000000,0.010000f);
    float_Clip2_1->Default = 0.000000f; float_Clip2_1->RightStep = 0.125000f;
    sFloatControl *float_Clip2_2 = gh.Float(&para->Clip2.z, -1000000,  1000000,0.010000f);
    float_Clip2_2->Default = 0.000000f; float_Clip2_2->RightStep = 0.125000f;
    sFloatControl *float_Clip2_3 = gh.Float(&para->Clip2.w, -1000000,  1000000,0.010000f);
    float_Clip2_3->Default = 0.000000f; float_Clip2_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Features&0x0004))
  {
    gh.Label(L"Clip3");
    gh.Flags(&para->ClipEnable,L"*3-|on",gh.LayoutMsg);

  }
  if(((para->Features&0x0004)&&(para->ClipEnable&0x0008)))
  {
    gh.BeginTied();
    sFloatControl *float_Clip3_0 = gh.Float(&para->Clip3.x, -1000000,  1000000,0.010000f);
    float_Clip3_0->Default = 1.000000f; float_Clip3_0->RightStep = 0.125000f;
    sFloatControl *float_Clip3_1 = gh.Float(&para->Clip3.y, -1000000,  1000000,0.010000f);
    float_Clip3_1->Default = 0.000000f; float_Clip3_1->RightStep = 0.125000f;
    sFloatControl *float_Clip3_2 = gh.Float(&para->Clip3.z, -1000000,  1000000,0.010000f);
    float_Clip3_2->Default = 0.000000f; float_Clip3_2->RightStep = 0.125000f;
    sFloatControl *float_Clip3_3 = gh.Float(&para->Clip3.w, -1000000,  1000000,0.010000f);
    float_Clip3_3->Default = 0.000000f; float_Clip3_3->RightStep = 0.125000f;
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

void Wz4RenderDefModLightEnv(wOp *op)
{
  Wz4RenderParaModLightEnv sUNUSED *para = (Wz4RenderParaModLightEnv *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->FogFar = 1000.000f;
  para->FogDensity = 1.000000f;
  para->FogColor = 0x00ffffff;
  para->GroundFogFar = 12.00000f;
  para->GroundFogDensity = 1.000000f;
  para->GroundFogColor = 0x00ffffff;
  para->GroundFogPlane.y = 1.000000f;
  para->Clip0.x = 1.000000f;
  para->Clip1.x = 1.000000f;
  para->Clip2.x = 1.000000f;
  para->Clip3.x = 1.000000f;
}

void Wz4RenderBindModLightEnv(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"fognear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"fogfar"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"fogdensity"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"fogcolor"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"dummya"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"dummya"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"groundfognear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogfar"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogdensity"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogcolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogplane"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogplane"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogplane"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"groundfogplane"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"dummyb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ModLightEnv(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[27];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"features");
    name[3] = sPoolString(L"fog");
    name[4] = sPoolString(L"fognear");
    name[5] = sPoolString(L"fogfar");
    name[6] = sPoolString(L"fogdensity");
    name[7] = sPoolString(L"fogcolor");
    name[8] = sPoolString(L"dummya");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"groundfognear");
    name[11] = sPoolString(L"groundfogfar");
    name[12] = sPoolString(L"groundfogdensity");
    name[13] = sPoolString(L"groundfogcolor");
    name[14] = sPoolString(L"groundfogplane");
    name[15] = sPoolString(L"dummyb");
    name[16] = sPoolString(L"");
    name[17] = sPoolString(L"clip0");
    name[18] = sPoolString(L"clip0");
    name[19] = sPoolString(L"clip1");
    name[20] = sPoolString(L"clip1");
    name[21] = sPoolString(L"clip2");
    name[22] = sPoolString(L"clip2");
    name[23] = sPoolString(L"clip3");
    name[24] = sPoolString(L"clip3");
    name[25] = sPoolString(L"");
    name[26] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeInt,2,cmd->Data+7);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[13],ScriptTypeColor,1,cmd->Data+12);
  ctx->AddImport(name[14],ScriptTypeFloat,4,cmd->Data+13);
  ctx->AddImport(name[15],ScriptTypeInt,2,cmd->Data+17);
  ctx->AddImport(name[18],ScriptTypeFloat,4,cmd->Data+20);
  ctx->AddImport(name[20],ScriptTypeFloat,4,cmd->Data+24);
  ctx->AddImport(name[22],ScriptTypeFloat,4,cmd->Data+28);
  ctx->AddImport(name[24],ScriptTypeFloat,4,cmd->Data+32);
  ctx->AddImport(name[26],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ModLightEnv(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import fognear : float;\n");
  tb.PrintF(L"  import fogfar : float;\n");
  tb.PrintF(L"  import fogdensity : float;\n");
  tb.PrintF(L"  import fogcolor : color;\n");
  tb.PrintF(L"  import dummya : int[2];\n");
  tb.PrintF(L"  import groundfognear : float;\n");
  tb.PrintF(L"  import groundfogfar : float;\n");
  tb.PrintF(L"  import groundfogdensity : float;\n");
  tb.PrintF(L"  import groundfogcolor : color;\n");
  tb.PrintF(L"  import groundfogplane : float[4];\n");
  tb.PrintF(L"  import dummyb : int[2];\n");
  tb.PrintF(L"  import clip0 : float[4];\n");
  tb.PrintF(L"  import clip1 : float[4];\n");
  tb.PrintF(L"  import clip2 : float[4];\n");
  tb.PrintF(L"  import clip3 : float[4];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiModLightEnv =
L"= Wz4Render : ModLightEnv\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ModLightEnv\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Features\n"
L" !i Features\n"
L" !i Fog\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i GroundFog\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Clip Planes\n"
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
L" !i FogDensity\n"
L" !i FogDensity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FogColor\n"
L" !i FogColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i dummya\n"
L" !i dummya\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i GroundFogNear\n"
L" !i GroundFogNear\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GroundFogFar\n"
L" !i GroundFogFar\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GroundFogDensity\n"
L" !i GroundFogDensity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GroundFogColor\n"
L" !i GroundFogColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i GroundFogPlane\n"
L" !i GroundFogPlane\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i dummyb\n"
L" !i dummyb\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip0\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip0\n"
L" !i Clip0\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip1\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip1\n"
L" !i Clip1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip2\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip2\n"
L" !i Clip2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip3\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip3\n"
L" !i Clip3\n"
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

sBool Wz4RenderCmdModClipTwister(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaModClipTwister sUNUSED *para = (Wz4RenderParaModClipTwister *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 884 "wz4_modmtrl_ops.ops"

    RNModClipTwister *node = new RNModClipTwister;
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,para->Renderpass);
  ;
#line 6716 "wz4_modmtrl_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiModClipTwister(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaModClipTwister sUNUSED *para = (Wz4RenderParaModClipTwister *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Clip Planes");

  gh.Label(L"Clip0");
  gh.Flags(&para->ClipEnable,L"-|on",gh.LayoutMsg);

  if((para->ClipEnable&0x0001))
  {
    gh.BeginTied();
    sFloatControl *float_Clip0_0 = gh.Float(&para->Clip0.x, -1000000,  1000000,0.010000f);
    float_Clip0_0->Default = 1.000000f; float_Clip0_0->RightStep = 0.125000f;
    sFloatControl *float_Clip0_1 = gh.Float(&para->Clip0.y, -1000000,  1000000,0.010000f);
    float_Clip0_1->Default = 0.000000f; float_Clip0_1->RightStep = 0.125000f;
    sFloatControl *float_Clip0_2 = gh.Float(&para->Clip0.z, -1000000,  1000000,0.010000f);
    float_Clip0_2->Default = 0.000000f; float_Clip0_2->RightStep = 0.125000f;
    sFloatControl *float_Clip0_3 = gh.Float(&para->Clip0.w, -1000000,  1000000,0.010000f);
    float_Clip0_3->Default = 0.000000f; float_Clip0_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Clip1");
  gh.Flags(&para->ClipEnable,L"*1-|on",gh.LayoutMsg);

  if((para->ClipEnable&0x0002))
  {
    gh.BeginTied();
    sFloatControl *float_Clip1_0 = gh.Float(&para->Clip1.x, -1000000,  1000000,0.010000f);
    float_Clip1_0->Default = 1.000000f; float_Clip1_0->RightStep = 0.125000f;
    sFloatControl *float_Clip1_1 = gh.Float(&para->Clip1.y, -1000000,  1000000,0.010000f);
    float_Clip1_1->Default = 0.000000f; float_Clip1_1->RightStep = 0.125000f;
    sFloatControl *float_Clip1_2 = gh.Float(&para->Clip1.z, -1000000,  1000000,0.010000f);
    float_Clip1_2->Default = 0.000000f; float_Clip1_2->RightStep = 0.125000f;
    sFloatControl *float_Clip1_3 = gh.Float(&para->Clip1.w, -1000000,  1000000,0.010000f);
    float_Clip1_3->Default = 0.000000f; float_Clip1_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Clip2");
  gh.Flags(&para->ClipEnable,L"*2-|on",gh.LayoutMsg);

  if((para->ClipEnable&0x0004))
  {
    gh.BeginTied();
    sFloatControl *float_Clip2_0 = gh.Float(&para->Clip2.x, -1000000,  1000000,0.010000f);
    float_Clip2_0->Default = 1.000000f; float_Clip2_0->RightStep = 0.125000f;
    sFloatControl *float_Clip2_1 = gh.Float(&para->Clip2.y, -1000000,  1000000,0.010000f);
    float_Clip2_1->Default = 0.000000f; float_Clip2_1->RightStep = 0.125000f;
    sFloatControl *float_Clip2_2 = gh.Float(&para->Clip2.z, -1000000,  1000000,0.010000f);
    float_Clip2_2->Default = 0.000000f; float_Clip2_2->RightStep = 0.125000f;
    sFloatControl *float_Clip2_3 = gh.Float(&para->Clip2.w, -1000000,  1000000,0.010000f);
    float_Clip2_3->Default = 0.000000f; float_Clip2_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Clip3");
  gh.Flags(&para->ClipEnable,L"*3-|on",gh.LayoutMsg);

  if((para->ClipEnable&0x0008))
  {
    gh.BeginTied();
    sFloatControl *float_Clip3_0 = gh.Float(&para->Clip3.x, -1000000,  1000000,0.010000f);
    float_Clip3_0->Default = 1.000000f; float_Clip3_0->RightStep = 0.125000f;
    sFloatControl *float_Clip3_1 = gh.Float(&para->Clip3.y, -1000000,  1000000,0.010000f);
    float_Clip3_1->Default = 0.000000f; float_Clip3_1->RightStep = 0.125000f;
    sFloatControl *float_Clip3_2 = gh.Float(&para->Clip3.z, -1000000,  1000000,0.010000f);
    float_Clip3_2->Default = 0.000000f; float_Clip3_2->RightStep = 0.125000f;
    sFloatControl *float_Clip3_3 = gh.Float(&para->Clip3.w, -1000000,  1000000,0.010000f);
    float_Clip3_3->Default = 0.000000f; float_Clip3_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"Transform");

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
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefModClipTwister(wOp *op)
{
  Wz4RenderParaModClipTwister sUNUSED *para = (Wz4RenderParaModClipTwister *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Clip0.x = 1.000000f;
  para->Clip1.x = 1.000000f;
  para->Clip2.x = 1.000000f;
  para->Clip3.x = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4RenderBindModClipTwister(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"clip0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"clip1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"clip2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"clip3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
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
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2ModClipTwister(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[17];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"clip0");
    name[4] = sPoolString(L"clip0");
    name[5] = sPoolString(L"clip1");
    name[6] = sPoolString(L"clip1");
    name[7] = sPoolString(L"clip2");
    name[8] = sPoolString(L"clip2");
    name[9] = sPoolString(L"clip3");
    name[10] = sPoolString(L"clip3");
    name[11] = sPoolString(L"transform");
    name[12] = sPoolString(L"scale");
    name[13] = sPoolString(L"rot");
    name[14] = sPoolString(L"trans");
    name[15] = sPoolString(L"");
    name[16] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,4,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeFloat,4,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeFloat,4,cmd->Data+11);
  ctx->AddImport(name[10],ScriptTypeFloat,4,cmd->Data+15);
  ctx->AddImport(name[12],ScriptTypeFloat,3,cmd->Data+19);
  ctx->AddImport(name[13],ScriptTypeFloat,3,cmd->Data+22);
  ctx->AddImport(name[14],ScriptTypeFloat,3,cmd->Data+25);
  ctx->AddImport(name[16],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3ModClipTwister(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import clip0 : float[4];\n");
  tb.PrintF(L"  import clip1 : float[4];\n");
  tb.PrintF(L"  import clip2 : float[4];\n");
  tb.PrintF(L"  import clip3 : float[4];\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiModClipTwister =
L"= Wz4Render : ModClipTwister\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ModClipTwister\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Clip0\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip0\n"
L" !i Clip0\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip1\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip1\n"
L" !i Clip1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip2\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip2\n"
L" !i Clip2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip3\n"
L" !i ClipEnable\n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip3\n"
L" !i Clip3\n"
L" !i float[4]\n"
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

void ModMtrlAnimModMaterial::Init(class ScriptContext *sc)
{
};

void ModMtrlAnimModMaterial::Bind(class ScriptContext *sc,ModMtrlParaModMaterial *para)
{
};

void Wz4RenderAnimModLight::Init(class ScriptContext *sc)
{
  _Front0 = sc->AddSymbol(L"front0");
  _FrontAmp0 = sc->AddSymbol(L"frontamp0");
  _Middle0 = sc->AddSymbol(L"middle0");
  _MiddleAmp0 = sc->AddSymbol(L"middleamp0");
  _Back0 = sc->AddSymbol(L"back0");
  _BackAmp0 = sc->AddSymbol(L"backamp0");
  _Pos0 = sc->AddSymbol(L"pos0");
  _Dir0 = sc->AddSymbol(L"dir0");
  _Range0 = sc->AddSymbol(L"range0");
  _Inner0 = sc->AddSymbol(L"inner0");
  _Outer0 = sc->AddSymbol(L"outer0");
  _Falloff0 = sc->AddSymbol(L"falloff0");
  _ShadowSize0 = sc->AddSymbol(L"shadowsize0");
  _ShadowBaseBias0 = sc->AddSymbol(L"shadowbasebias0");
  _ShadowFilter0 = sc->AddSymbol(L"shadowfilter0");
  _ShadowSlopeBias0 = sc->AddSymbol(L"shadowslopebias0");
  _Front1 = sc->AddSymbol(L"front1");
  _FrontAmp1 = sc->AddSymbol(L"frontamp1");
  _Middle1 = sc->AddSymbol(L"middle1");
  _MiddleAmp1 = sc->AddSymbol(L"middleamp1");
  _Back1 = sc->AddSymbol(L"back1");
  _BackAmp1 = sc->AddSymbol(L"backamp1");
  _Pos1 = sc->AddSymbol(L"pos1");
  _Dir1 = sc->AddSymbol(L"dir1");
  _Range1 = sc->AddSymbol(L"range1");
  _Inner1 = sc->AddSymbol(L"inner1");
  _Outer1 = sc->AddSymbol(L"outer1");
  _Falloff1 = sc->AddSymbol(L"falloff1");
  _ShadowSize1 = sc->AddSymbol(L"shadowsize1");
  _ShadowBaseBias1 = sc->AddSymbol(L"shadowbasebias1");
  _ShadowFilter1 = sc->AddSymbol(L"shadowfilter1");
  _ShadowSlopeBias1 = sc->AddSymbol(L"shadowslopebias1");
  _Front2 = sc->AddSymbol(L"front2");
  _FrontAmp2 = sc->AddSymbol(L"frontamp2");
  _Middle2 = sc->AddSymbol(L"middle2");
  _MiddleAmp2 = sc->AddSymbol(L"middleamp2");
  _Back2 = sc->AddSymbol(L"back2");
  _BackAmp2 = sc->AddSymbol(L"backamp2");
  _Pos2 = sc->AddSymbol(L"pos2");
  _Dir2 = sc->AddSymbol(L"dir2");
  _Range2 = sc->AddSymbol(L"range2");
  _Inner2 = sc->AddSymbol(L"inner2");
  _Outer2 = sc->AddSymbol(L"outer2");
  _Falloff2 = sc->AddSymbol(L"falloff2");
  _ShadowSize2 = sc->AddSymbol(L"shadowsize2");
  _ShadowBaseBias2 = sc->AddSymbol(L"shadowbasebias2");
  _ShadowFilter2 = sc->AddSymbol(L"shadowfilter2");
  _ShadowSlopeBias2 = sc->AddSymbol(L"shadowslopebias2");
  _Front3 = sc->AddSymbol(L"front3");
  _FrontAmp3 = sc->AddSymbol(L"frontamp3");
  _Middle3 = sc->AddSymbol(L"middle3");
  _MiddleAmp3 = sc->AddSymbol(L"middleamp3");
  _Back3 = sc->AddSymbol(L"back3");
  _BackAmp3 = sc->AddSymbol(L"backamp3");
  _Pos3 = sc->AddSymbol(L"pos3");
  _Dir3 = sc->AddSymbol(L"dir3");
  _Range3 = sc->AddSymbol(L"range3");
  _Inner3 = sc->AddSymbol(L"inner3");
  _Outer3 = sc->AddSymbol(L"outer3");
  _Falloff3 = sc->AddSymbol(L"falloff3");
  _ShadowSize3 = sc->AddSymbol(L"shadowsize3");
  _ShadowBaseBias3 = sc->AddSymbol(L"shadowbasebias3");
  _ShadowFilter3 = sc->AddSymbol(L"shadowfilter3");
  _ShadowSlopeBias3 = sc->AddSymbol(L"shadowslopebias3");
  _Front4 = sc->AddSymbol(L"front4");
  _FrontAmp4 = sc->AddSymbol(L"frontamp4");
  _Middle4 = sc->AddSymbol(L"middle4");
  _MiddleAmp4 = sc->AddSymbol(L"middleamp4");
  _Back4 = sc->AddSymbol(L"back4");
  _BackAmp4 = sc->AddSymbol(L"backamp4");
  _Pos4 = sc->AddSymbol(L"pos4");
  _Dir4 = sc->AddSymbol(L"dir4");
  _Range4 = sc->AddSymbol(L"range4");
  _Inner4 = sc->AddSymbol(L"inner4");
  _Outer4 = sc->AddSymbol(L"outer4");
  _Falloff4 = sc->AddSymbol(L"falloff4");
  _ShadowSize4 = sc->AddSymbol(L"shadowsize4");
  _ShadowBaseBias4 = sc->AddSymbol(L"shadowbasebias4");
  _ShadowFilter4 = sc->AddSymbol(L"shadowfilter4");
  _ShadowSlopeBias4 = sc->AddSymbol(L"shadowslopebias4");
  _Front5 = sc->AddSymbol(L"front5");
  _FrontAmp5 = sc->AddSymbol(L"frontamp5");
  _Middle5 = sc->AddSymbol(L"middle5");
  _MiddleAmp5 = sc->AddSymbol(L"middleamp5");
  _Back5 = sc->AddSymbol(L"back5");
  _BackAmp5 = sc->AddSymbol(L"backamp5");
  _Pos5 = sc->AddSymbol(L"pos5");
  _Dir5 = sc->AddSymbol(L"dir5");
  _Range5 = sc->AddSymbol(L"range5");
  _Inner5 = sc->AddSymbol(L"inner5");
  _Outer5 = sc->AddSymbol(L"outer5");
  _Falloff5 = sc->AddSymbol(L"falloff5");
  _ShadowSize5 = sc->AddSymbol(L"shadowsize5");
  _ShadowBaseBias5 = sc->AddSymbol(L"shadowbasebias5");
  _ShadowFilter5 = sc->AddSymbol(L"shadowfilter5");
  _ShadowSlopeBias5 = sc->AddSymbol(L"shadowslopebias5");
  _Front6 = sc->AddSymbol(L"front6");
  _FrontAmp6 = sc->AddSymbol(L"frontamp6");
  _Middle6 = sc->AddSymbol(L"middle6");
  _MiddleAmp6 = sc->AddSymbol(L"middleamp6");
  _Back6 = sc->AddSymbol(L"back6");
  _BackAmp6 = sc->AddSymbol(L"backamp6");
  _Pos6 = sc->AddSymbol(L"pos6");
  _Dir6 = sc->AddSymbol(L"dir6");
  _Range6 = sc->AddSymbol(L"range6");
  _Inner6 = sc->AddSymbol(L"inner6");
  _Outer6 = sc->AddSymbol(L"outer6");
  _Falloff6 = sc->AddSymbol(L"falloff6");
  _ShadowSize6 = sc->AddSymbol(L"shadowsize6");
  _ShadowBaseBias6 = sc->AddSymbol(L"shadowbasebias6");
  _ShadowFilter6 = sc->AddSymbol(L"shadowfilter6");
  _ShadowSlopeBias6 = sc->AddSymbol(L"shadowslopebias6");
  _Front7 = sc->AddSymbol(L"front7");
  _FrontAmp7 = sc->AddSymbol(L"frontamp7");
  _Middle7 = sc->AddSymbol(L"middle7");
  _MiddleAmp7 = sc->AddSymbol(L"middleamp7");
  _Back7 = sc->AddSymbol(L"back7");
  _BackAmp7 = sc->AddSymbol(L"backamp7");
  _Pos7 = sc->AddSymbol(L"pos7");
  _Dir7 = sc->AddSymbol(L"dir7");
  _Range7 = sc->AddSymbol(L"range7");
  _Inner7 = sc->AddSymbol(L"inner7");
  _Outer7 = sc->AddSymbol(L"outer7");
  _Falloff7 = sc->AddSymbol(L"falloff7");
  _ShadowSize7 = sc->AddSymbol(L"shadowsize7");
  _ShadowBaseBias7 = sc->AddSymbol(L"shadowbasebias7");
  _ShadowFilter7 = sc->AddSymbol(L"shadowfilter7");
  _ShadowSlopeBias7 = sc->AddSymbol(L"shadowslopebias7");
  _LimitCenter = sc->AddSymbol(L"limitcenter");
  _LimitRadius = sc->AddSymbol(L"limitradius");
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
};

void Wz4RenderAnimModLight::Bind(class ScriptContext *sc,Wz4RenderParaModLight *para)
{
  sc->BindLocalColor(_Front0,&para->Front0);
  sc->BindLocalFloat(_FrontAmp0,1,&para->FrontAmp0);
  sc->BindLocalColor(_Middle0,&para->Middle0);
  sc->BindLocalFloat(_MiddleAmp0,1,&para->MiddleAmp0);
  sc->BindLocalColor(_Back0,&para->Back0);
  sc->BindLocalFloat(_BackAmp0,1,&para->BackAmp0);
  sc->BindLocalFloat(_Pos0,3,&para->Pos0.x);
  sc->BindLocalFloat(_Dir0,3,&para->Dir0.x);
  sc->BindLocalFloat(_Range0,1,&para->Range0);
  sc->BindLocalFloat(_Inner0,1,&para->Inner0);
  sc->BindLocalFloat(_Outer0,1,&para->Outer0);
  sc->BindLocalFloat(_Falloff0,1,&para->Falloff0);
  sc->BindLocalInt(_ShadowSize0,1,&para->ShadowSize0);
  sc->BindLocalFloat(_ShadowBaseBias0,1,&para->ShadowBaseBias0);
  sc->BindLocalFloat(_ShadowFilter0,1,&para->ShadowFilter0);
  sc->BindLocalFloat(_ShadowSlopeBias0,1,&para->ShadowSlopeBias0);
  sc->BindLocalColor(_Front1,&para->Front1);
  sc->BindLocalFloat(_FrontAmp1,1,&para->FrontAmp1);
  sc->BindLocalColor(_Middle1,&para->Middle1);
  sc->BindLocalFloat(_MiddleAmp1,1,&para->MiddleAmp1);
  sc->BindLocalColor(_Back1,&para->Back1);
  sc->BindLocalFloat(_BackAmp1,1,&para->BackAmp1);
  sc->BindLocalFloat(_Pos1,3,&para->Pos1.x);
  sc->BindLocalFloat(_Dir1,3,&para->Dir1.x);
  sc->BindLocalFloat(_Range1,1,&para->Range1);
  sc->BindLocalFloat(_Inner1,1,&para->Inner1);
  sc->BindLocalFloat(_Outer1,1,&para->Outer1);
  sc->BindLocalFloat(_Falloff1,1,&para->Falloff1);
  sc->BindLocalInt(_ShadowSize1,1,&para->ShadowSize1);
  sc->BindLocalFloat(_ShadowBaseBias1,1,&para->ShadowBaseBias1);
  sc->BindLocalFloat(_ShadowFilter1,1,&para->ShadowFilter1);
  sc->BindLocalFloat(_ShadowSlopeBias1,1,&para->ShadowSlopeBias1);
  sc->BindLocalColor(_Front2,&para->Front2);
  sc->BindLocalFloat(_FrontAmp2,1,&para->FrontAmp2);
  sc->BindLocalColor(_Middle2,&para->Middle2);
  sc->BindLocalFloat(_MiddleAmp2,1,&para->MiddleAmp2);
  sc->BindLocalColor(_Back2,&para->Back2);
  sc->BindLocalFloat(_BackAmp2,1,&para->BackAmp2);
  sc->BindLocalFloat(_Pos2,3,&para->Pos2.x);
  sc->BindLocalFloat(_Dir2,3,&para->Dir2.x);
  sc->BindLocalFloat(_Range2,1,&para->Range2);
  sc->BindLocalFloat(_Inner2,1,&para->Inner2);
  sc->BindLocalFloat(_Outer2,1,&para->Outer2);
  sc->BindLocalFloat(_Falloff2,1,&para->Falloff2);
  sc->BindLocalInt(_ShadowSize2,1,&para->ShadowSize2);
  sc->BindLocalFloat(_ShadowBaseBias2,1,&para->ShadowBaseBias2);
  sc->BindLocalFloat(_ShadowFilter2,1,&para->ShadowFilter2);
  sc->BindLocalFloat(_ShadowSlopeBias2,1,&para->ShadowSlopeBias2);
  sc->BindLocalColor(_Front3,&para->Front3);
  sc->BindLocalFloat(_FrontAmp3,1,&para->FrontAmp3);
  sc->BindLocalColor(_Middle3,&para->Middle3);
  sc->BindLocalFloat(_MiddleAmp3,1,&para->MiddleAmp3);
  sc->BindLocalColor(_Back3,&para->Back3);
  sc->BindLocalFloat(_BackAmp3,1,&para->BackAmp3);
  sc->BindLocalFloat(_Pos3,3,&para->Pos3.x);
  sc->BindLocalFloat(_Dir3,3,&para->Dir3.x);
  sc->BindLocalFloat(_Range3,1,&para->Range3);
  sc->BindLocalFloat(_Inner3,1,&para->Inner3);
  sc->BindLocalFloat(_Outer3,1,&para->Outer3);
  sc->BindLocalFloat(_Falloff3,1,&para->Falloff3);
  sc->BindLocalInt(_ShadowSize3,1,&para->ShadowSize3);
  sc->BindLocalFloat(_ShadowBaseBias3,1,&para->ShadowBaseBias3);
  sc->BindLocalFloat(_ShadowFilter3,1,&para->ShadowFilter3);
  sc->BindLocalFloat(_ShadowSlopeBias3,1,&para->ShadowSlopeBias3);
  sc->BindLocalColor(_Front4,&para->Front4);
  sc->BindLocalFloat(_FrontAmp4,1,&para->FrontAmp4);
  sc->BindLocalColor(_Middle4,&para->Middle4);
  sc->BindLocalFloat(_MiddleAmp4,1,&para->MiddleAmp4);
  sc->BindLocalColor(_Back4,&para->Back4);
  sc->BindLocalFloat(_BackAmp4,1,&para->BackAmp4);
  sc->BindLocalFloat(_Pos4,3,&para->Pos4.x);
  sc->BindLocalFloat(_Dir4,3,&para->Dir4.x);
  sc->BindLocalFloat(_Range4,1,&para->Range4);
  sc->BindLocalFloat(_Inner4,1,&para->Inner4);
  sc->BindLocalFloat(_Outer4,1,&para->Outer4);
  sc->BindLocalFloat(_Falloff4,1,&para->Falloff4);
  sc->BindLocalInt(_ShadowSize4,1,&para->ShadowSize4);
  sc->BindLocalFloat(_ShadowBaseBias4,1,&para->ShadowBaseBias4);
  sc->BindLocalFloat(_ShadowFilter4,1,&para->ShadowFilter4);
  sc->BindLocalFloat(_ShadowSlopeBias4,1,&para->ShadowSlopeBias4);
  sc->BindLocalColor(_Front5,&para->Front5);
  sc->BindLocalFloat(_FrontAmp5,1,&para->FrontAmp5);
  sc->BindLocalColor(_Middle5,&para->Middle5);
  sc->BindLocalFloat(_MiddleAmp5,1,&para->MiddleAmp5);
  sc->BindLocalColor(_Back5,&para->Back5);
  sc->BindLocalFloat(_BackAmp5,1,&para->BackAmp5);
  sc->BindLocalFloat(_Pos5,3,&para->Pos5.x);
  sc->BindLocalFloat(_Dir5,3,&para->Dir5.x);
  sc->BindLocalFloat(_Range5,1,&para->Range5);
  sc->BindLocalFloat(_Inner5,1,&para->Inner5);
  sc->BindLocalFloat(_Outer5,1,&para->Outer5);
  sc->BindLocalFloat(_Falloff5,1,&para->Falloff5);
  sc->BindLocalInt(_ShadowSize5,1,&para->ShadowSize5);
  sc->BindLocalFloat(_ShadowBaseBias5,1,&para->ShadowBaseBias5);
  sc->BindLocalFloat(_ShadowFilter5,1,&para->ShadowFilter5);
  sc->BindLocalFloat(_ShadowSlopeBias5,1,&para->ShadowSlopeBias5);
  sc->BindLocalColor(_Front6,&para->Front6);
  sc->BindLocalFloat(_FrontAmp6,1,&para->FrontAmp6);
  sc->BindLocalColor(_Middle6,&para->Middle6);
  sc->BindLocalFloat(_MiddleAmp6,1,&para->MiddleAmp6);
  sc->BindLocalColor(_Back6,&para->Back6);
  sc->BindLocalFloat(_BackAmp6,1,&para->BackAmp6);
  sc->BindLocalFloat(_Pos6,3,&para->Pos6.x);
  sc->BindLocalFloat(_Dir6,3,&para->Dir6.x);
  sc->BindLocalFloat(_Range6,1,&para->Range6);
  sc->BindLocalFloat(_Inner6,1,&para->Inner6);
  sc->BindLocalFloat(_Outer6,1,&para->Outer6);
  sc->BindLocalFloat(_Falloff6,1,&para->Falloff6);
  sc->BindLocalInt(_ShadowSize6,1,&para->ShadowSize6);
  sc->BindLocalFloat(_ShadowBaseBias6,1,&para->ShadowBaseBias6);
  sc->BindLocalFloat(_ShadowFilter6,1,&para->ShadowFilter6);
  sc->BindLocalFloat(_ShadowSlopeBias6,1,&para->ShadowSlopeBias6);
  sc->BindLocalColor(_Front7,&para->Front7);
  sc->BindLocalFloat(_FrontAmp7,1,&para->FrontAmp7);
  sc->BindLocalColor(_Middle7,&para->Middle7);
  sc->BindLocalFloat(_MiddleAmp7,1,&para->MiddleAmp7);
  sc->BindLocalColor(_Back7,&para->Back7);
  sc->BindLocalFloat(_BackAmp7,1,&para->BackAmp7);
  sc->BindLocalFloat(_Pos7,3,&para->Pos7.x);
  sc->BindLocalFloat(_Dir7,3,&para->Dir7.x);
  sc->BindLocalFloat(_Range7,1,&para->Range7);
  sc->BindLocalFloat(_Inner7,1,&para->Inner7);
  sc->BindLocalFloat(_Outer7,1,&para->Outer7);
  sc->BindLocalFloat(_Falloff7,1,&para->Falloff7);
  sc->BindLocalInt(_ShadowSize7,1,&para->ShadowSize7);
  sc->BindLocalFloat(_ShadowBaseBias7,1,&para->ShadowBaseBias7);
  sc->BindLocalFloat(_ShadowFilter7,1,&para->ShadowFilter7);
  sc->BindLocalFloat(_ShadowSlopeBias7,1,&para->ShadowSlopeBias7);
  sc->BindLocalFloat(_LimitCenter,3,&para->LimitCenter.x);
  sc->BindLocalFloat(_LimitRadius,3,&para->LimitRadius.x);
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
};

void Wz4RenderAnimModMisc::Init(class ScriptContext *sc)
{
  _Color0 = sc->AddSymbol(L"color0");
  _Color1 = sc->AddSymbol(L"color1");
  _Color2 = sc->AddSymbol(L"color2");
  _Color3 = sc->AddSymbol(L"color3");
  _Color4 = sc->AddSymbol(L"color4");
  _Color5 = sc->AddSymbol(L"color5");
  _Color6 = sc->AddSymbol(L"color6");
  _Color7 = sc->AddSymbol(L"color7");
  _Vector0 = sc->AddSymbol(L"vector0");
  _Vector1 = sc->AddSymbol(L"vector1");
  _Vector2 = sc->AddSymbol(L"vector2");
  _Vector3 = sc->AddSymbol(L"vector3");
  _Vector4 = sc->AddSymbol(L"vector4");
  _Vector5 = sc->AddSymbol(L"vector5");
  _Vector6 = sc->AddSymbol(L"vector6");
  _Vector7 = sc->AddSymbol(L"vector7");
  _Scale0 = sc->AddSymbol(L"scale0");
  _Rot0 = sc->AddSymbol(L"rot0");
  _Trans0 = sc->AddSymbol(L"trans0");
  _Scale1 = sc->AddSymbol(L"scale1");
  _Rot1 = sc->AddSymbol(L"rot1");
  _Trans1 = sc->AddSymbol(L"trans1");
  _Scale2 = sc->AddSymbol(L"scale2");
  _Rot2 = sc->AddSymbol(L"rot2");
  _Trans2 = sc->AddSymbol(L"trans2");
  _Scale3 = sc->AddSymbol(L"scale3");
  _Rot3 = sc->AddSymbol(L"rot3");
  _Trans3 = sc->AddSymbol(L"trans3");
};

void Wz4RenderAnimModMisc::Bind(class ScriptContext *sc,Wz4RenderParaModMisc *para)
{
  sc->BindLocalColor(_Color0,&para->Color0);
  sc->BindLocalColor(_Color1,&para->Color1);
  sc->BindLocalColor(_Color2,&para->Color2);
  sc->BindLocalColor(_Color3,&para->Color3);
  sc->BindLocalColor(_Color4,&para->Color4);
  sc->BindLocalColor(_Color5,&para->Color5);
  sc->BindLocalColor(_Color6,&para->Color6);
  sc->BindLocalColor(_Color7,&para->Color7);
  sc->BindLocalFloat(_Vector0,3,&para->Vector0.x);
  sc->BindLocalFloat(_Vector1,3,&para->Vector1.x);
  sc->BindLocalFloat(_Vector2,3,&para->Vector2.x);
  sc->BindLocalFloat(_Vector3,3,&para->Vector3.x);
  sc->BindLocalFloat(_Vector4,3,&para->Vector4.x);
  sc->BindLocalFloat(_Vector5,3,&para->Vector5.x);
  sc->BindLocalFloat(_Vector6,3,&para->Vector6.x);
  sc->BindLocalFloat(_Vector7,3,&para->Vector7.x);
  sc->BindLocalFloat(_Scale0,3,&para->Scale0.x);
  sc->BindLocalFloat(_Rot0,3,&para->Rot0.x);
  sc->BindLocalFloat(_Trans0,3,&para->Trans0.x);
  sc->BindLocalFloat(_Scale1,3,&para->Scale1.x);
  sc->BindLocalFloat(_Rot1,3,&para->Rot1.x);
  sc->BindLocalFloat(_Trans1,3,&para->Trans1.x);
  sc->BindLocalFloat(_Scale2,3,&para->Scale2.x);
  sc->BindLocalFloat(_Rot2,3,&para->Rot2.x);
  sc->BindLocalFloat(_Trans2,3,&para->Trans2.x);
  sc->BindLocalFloat(_Scale3,3,&para->Scale3.x);
  sc->BindLocalFloat(_Rot3,3,&para->Rot3.x);
  sc->BindLocalFloat(_Trans3,3,&para->Trans3.x);
};

void Wz4RenderAnimModLightEnv::Init(class ScriptContext *sc)
{
  _FogNear = sc->AddSymbol(L"fognear");
  _FogFar = sc->AddSymbol(L"fogfar");
  _FogDensity = sc->AddSymbol(L"fogdensity");
  _FogColor = sc->AddSymbol(L"fogcolor");
  _GroundFogNear = sc->AddSymbol(L"groundfognear");
  _GroundFogFar = sc->AddSymbol(L"groundfogfar");
  _GroundFogDensity = sc->AddSymbol(L"groundfogdensity");
  _GroundFogColor = sc->AddSymbol(L"groundfogcolor");
  _GroundFogPlane = sc->AddSymbol(L"groundfogplane");
  _Clip0 = sc->AddSymbol(L"clip0");
  _Clip1 = sc->AddSymbol(L"clip1");
  _Clip2 = sc->AddSymbol(L"clip2");
  _Clip3 = sc->AddSymbol(L"clip3");
};

void Wz4RenderAnimModLightEnv::Bind(class ScriptContext *sc,Wz4RenderParaModLightEnv *para)
{
  sc->BindLocalFloat(_FogNear,1,&para->FogNear);
  sc->BindLocalFloat(_FogFar,1,&para->FogFar);
  sc->BindLocalFloat(_FogDensity,1,&para->FogDensity);
  sc->BindLocalColor(_FogColor,&para->FogColor);
  sc->BindLocalFloat(_GroundFogNear,1,&para->GroundFogNear);
  sc->BindLocalFloat(_GroundFogFar,1,&para->GroundFogFar);
  sc->BindLocalFloat(_GroundFogDensity,1,&para->GroundFogDensity);
  sc->BindLocalColor(_GroundFogColor,&para->GroundFogColor);
  sc->BindLocalFloat(_GroundFogPlane,4,&para->GroundFogPlane.x);
  sc->BindLocalFloat(_Clip0,4,&para->Clip0.x);
  sc->BindLocalFloat(_Clip1,4,&para->Clip1.x);
  sc->BindLocalFloat(_Clip2,4,&para->Clip2.x);
  sc->BindLocalFloat(_Clip3,4,&para->Clip3.x);
};

void Wz4RenderAnimModClipTwister::Init(class ScriptContext *sc)
{
  _Clip0 = sc->AddSymbol(L"clip0");
  _Clip1 = sc->AddSymbol(L"clip1");
  _Clip2 = sc->AddSymbol(L"clip2");
  _Clip3 = sc->AddSymbol(L"clip3");
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
};

void Wz4RenderAnimModClipTwister::Bind(class ScriptContext *sc,Wz4RenderParaModClipTwister *para)
{
  sc->BindLocalFloat(_Clip0,4,&para->Clip0.x);
  sc->BindLocalFloat(_Clip1,4,&para->Clip1.x);
  sc->BindLocalFloat(_Clip2,4,&para->Clip2.x);
  sc->BindLocalFloat(_Clip3,4,&para->Clip3.x);
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
};


/****************************************************************************/

void AddTypes_wz4_modmtrl_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(ModMtrlType = new ModMtrlType_);
  ModMtrlType->Secondary = secondary;

  Doc->Types.AddTail(ModShaderType = new ModShaderType_);
  ModShaderType->Secondary = secondary;

  Doc->Types.AddTail(ModShaderSamplerType = new ModShaderSamplerType_);
  ModShaderSamplerType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_modmtrl_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"ModMaterial";
  cl->Label = L"ModMaterial";
  cl->OutputType = ModMtrlType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModMtrlCmdModMaterial;
  cl->MakeGui = ModMtrlGuiModMaterial;
  cl->SetDefaults = ModMtrlDefModMaterial;
  cl->BindPara = ModMtrlBindModMaterial;
  cl->Bind2Para = ModMtrlBind2ModMaterial;
  cl->Bind3Para = ModMtrlBind3ModMaterial;
  cl->WikiText = ModMtrlWikiModMaterial;
  cl->Actions = ModMtrlActModMaterial;
  cl->ParaWords = 10;
  cl->Shortcut = 'm';
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"All",3);
  cl->ActionIds.AddMany(1)->Init(L"All",4);
  cl->ActionIds.AddMany(1)->Init(L"Shadercode",1);
  cl->ActionIds.AddMany(1)->Init(L"FlushShaders",2);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ModLight";
  cl->Label = L"ModLight";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdModLight;
  cl->MakeGui = Wz4RenderGuiModLight;
  cl->SetDefaults = Wz4RenderDefModLight;
  cl->BindPara = Wz4RenderBindModLight;
  cl->Bind2Para = Wz4RenderBind2ModLight;
  cl->Bind3Para = Wz4RenderBind3ModLight;
  cl->WikiText = Wz4RenderWikiModLight;
  cl->Handles = Wz4RenderHndModLight;
  cl->Actions = Wz4RenderActModLight;
  cl->ParaStrings = 1;
  cl->ParaWords = 244;
  cl->Shortcut = 'L';
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"Swap_RG",1);
  cl->ActionIds.AddMany(1)->Init(L"Swap_RB",2);
  cl->ActionIds.AddMany(1)->Init(L"Swap_GB",3);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ModMisc";
  cl->Label = L"ModMisc";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdModMisc;
  cl->MakeGui = Wz4RenderGuiModMisc;
  cl->SetDefaults = Wz4RenderDefModMisc;
  cl->BindPara = Wz4RenderBindModMisc;
  cl->Bind2Para = Wz4RenderBind2ModMisc;
  cl->Bind3Para = Wz4RenderBind3ModMisc;
  cl->WikiText = Wz4RenderWikiModMisc;
  cl->ParaStrings = 1;
  cl->ParaWords = 78;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ModLightEnv";
  cl->Label = L"ModLightEnv";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdModLightEnv;
  cl->MakeGui = Wz4RenderGuiModLightEnv;
  cl->SetDefaults = Wz4RenderDefModLightEnv;
  cl->BindPara = Wz4RenderBindModLightEnv;
  cl->Bind2Para = Wz4RenderBind2ModLightEnv;
  cl->Bind3Para = Wz4RenderBind3ModLightEnv;
  cl->WikiText = Wz4RenderWikiModLightEnv;
  cl->ParaStrings = 1;
  cl->ParaWords = 36;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ModClipTwister";
  cl->Label = L"ModClipTwister";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdModClipTwister;
  cl->MakeGui = Wz4RenderGuiModClipTwister;
  cl->SetDefaults = Wz4RenderDefModClipTwister;
  cl->BindPara = Wz4RenderBindModClipTwister;
  cl->Bind2Para = Wz4RenderBind2ModClipTwister;
  cl->Bind3Para = Wz4RenderBind3ModClipTwister;
  cl->WikiText = Wz4RenderWikiModClipTwister;
  cl->ParaStrings = 1;
  cl->ParaWords = 28;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_modmtrl_ops,0x110,AddOps_wz4_modmtrl_ops,0);


/****************************************************************************/


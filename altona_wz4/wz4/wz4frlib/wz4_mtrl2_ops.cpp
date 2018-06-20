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
#include "wz4_mtrl2_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4MtrlType_ *Wz4MtrlType;
class SimpleMtrlType_ *SimpleMtrlType;
class CustomMtrlType_ *CustomMtrlType;

/****************************************************************************/


/****************************************************************************/

sBool SimpleMtrlCmdSimpleMaterial(wExecutive *exe,wCommand *cmd)
{
  SimpleMtrlParaSimpleMaterial sUNUSED *para = (SimpleMtrlParaSimpleMaterial *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Texture2D sUNUSED *in2 = cmd->GetInput<Texture2D *>(2); in2;
  SimpleMtrl *out = (SimpleMtrl *) cmd->Output;
  if(!out) { out=new SimpleMtrl; cmd->Output=out; }

  {
#line 152 "wz4_mtrl2_ops.ops"

    static sU32 blend[] = 
    { 0,sMB_PMALPHA,sMB_ADD,sMB_SUB,sMB_MUL,sMB_MUL2,sMB_ADDSMOOTH,sMB_ALPHA };
    sMatrix34 mat;

    sInt extras = para->Extras;
    sInt detail = 0 ;
    switch(para->UVTrans)
    {
    case 0: extras |= 0x00; detail = 0; break;
    case 1: extras |= 0x10; detail = 0; break;
    case 2: extras |= 0x10; detail = 1; break;
    case 3: extras |= 0x10; detail = 2; break;
    case 4: extras |= 0x20; detail = 3; break;
    case 5: extras |= 0x30; detail = 3; break;
    }

    out->SetMtrl(para->Flags,blend[para->Blend],extras);
    out->DetailTexSpace = detail;
    out->SetTex(0,in0,para->Texture0);
    out->SetTex(1,in1,para->Texture1);
    out->SetTex(2,in2,para->Texture2);
    out->SetAlphaTest(para->AlphaTest,para->AlphaRef);
    out->VertexScale = para->VertexScale;

    sInt tflags[3];
    tflags[0] = para->Texture0;
    tflags[1] = para->Texture1;
    tflags[2] = para->Texture2;
    sSRT srt;
    for(sInt j=0;j<3;j++)
    {
      switch(tflags[j]&0x30000)
      {
      case 0x00000:
        mat.Init();
        break;
      case 0x10000:
        mat.Scale(para->SimpleScale);
        break;
      case 0x20000:
        srt.Rotate = para->Rot;
        srt.Translate = para->Trans;
        srt.Scale = para->Scale;
        srt.MakeMatrix(mat);
        break;
      case 0x30000:
        mat.Init();
        out->DetailTexSpace |= 0x100<<j;
        break;
      }
      out->TexTrans[j] = mat;
    }

    out->Prepare();
  ;
#line 95 "wz4_mtrl2_ops.cpp"
    return 1;
  }
}

void SimpleMtrlGuiSimpleMaterial(wGridFrameHelper &gh,wOp *op)
{
  SimpleMtrlParaSimpleMaterial sUNUSED *para = (SimpleMtrlParaSimpleMaterial *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0zoff|zread|zwrite|zon:*4Doublesided|Singlesided|Inverted:*7-|Light",gh.ChangeMsg);

  gh.Label(L"ColorMask");
  gh.Flags(&para->Flags,L"*8-|MaskAlpha:*9-|MaskRed:*10-|MaskGreen:*11-|MaskBlue",gh.ChangeMsg);

  gh.Label(L"VertexColor");
  gh.Flags(&para->Flags,L"*12-|Light:*14-|Material:*24zrender|-",gh.ChangeMsg);

  gh.Label(L"Blend");
  gh.Flags(&para->Blend,L"solid|alpha premul|add|sub|mul|mul2|addsmooth|alpha plain",gh.ChangeMsg);

  if((op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Texture0");
    gh.Flags(&para->Texture0,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white:*16-|scale|matrix|LightEnv",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<1))!=0)
  {
    gh.Label(L"Texture1");
    gh.Flags(&para->Texture1,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white:*16-|scale|matrix|LightEnv",gh.ChangeMsg);

  }
  gh.Label(L"AlphaTest");
  gh.Flags(&para->AlphaTest,L"|||inverted|on|||off",gh.LayoutMsg);

  if((para->AlphaTest!=0x0007))
  {
    sIntControl *int_AlphaRef = gh.Int(&para->AlphaRef,0,255,1.000000f);
    int_AlphaRef->Default = 0x00000000; int_AlphaRef->RightStep = 0.125000f;

  }
  gh.Label(L"Fog");
  gh.Flags(&para->Extras,L"off|on|black|clip3",gh.LayoutMsg);

  gh.Label(L"Clip Planes");
  gh.Flags(&para->Extras,L"*3off|on",gh.ChangeMsg);

  gh.Label(L"Normal Storage");
  gh.Flags(&para->Extras,L"*12precise|compact",gh.ChangeMsg);

  if((op->ConnectionMask & (1<<1))!=0)
  {
    gh.Label(L"Texture Op");
    gh.Flags(&para->Extras,L"*2add|mul",gh.ChangeMsg);

    gh.Flags(&para->UVTrans,L"uv|model|world|camera|envi-sphere|envi-reflect",gh.ChangeMsg);

  }
  gh.Group(L"Transforms");

  gh.Label(L"SimpleScale");
  sFloatControl *float_SimpleScale = gh.Float(&para->SimpleScale,-1024.00f,1024.000f,0.010000f);
  float_SimpleScale->Default = 1.000000f; float_SimpleScale->RightStep = 0.125000f;

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Rot");
  gh.BeginTied();
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Vertex Displacement");

  gh.Label(L"VertexTexture");
  {
    sControl *con=gh.String(op->Links[2].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 2;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 2;
    gh.Box(L"..",msg);
    if(!op->Links[2].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 2;
      gh.Box(L"->",msg);
    }
  }

  if((op->ConnectionMask & (1<<2))!=0)
  {
    gh.Label(L"Texture2");
    gh.Flags(&para->Texture2,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white:*16-|scale|matrix|LightEnv",gh.ChangeMsg);

    gh.Label(L"Mapping");
    gh.Flags(&para->Extras,L"*8uv|model|noise",gh.ChangeMsg);

    gh.Label(L"VertexScale");
    sFloatControl *float_VertexScale = gh.Float(&para->VertexScale,0.000000f,1024.000f,0.010000f);
    float_VertexScale->Default = 1.000000f; float_VertexScale->RightStep = 0.125000f;
  }
}

void SimpleMtrlDefSimpleMaterial(wOp *op)
{
  SimpleMtrlParaSimpleMaterial sUNUSED *para = (SimpleMtrlParaSimpleMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000093;
  para->AlphaTest = 0x00000007;
  para->SimpleScale = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->VertexScale = 1.000000f;
}

void SimpleMtrlBindSimpleMaterial(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"alpharef"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"simplescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"vertexscale"),val);
}
void SimpleMtrlBind2SimpleMaterial(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[23];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"colormask");
    name[2] = sPoolString(L"vertexcolor");
    name[3] = sPoolString(L"blend");
    name[4] = sPoolString(L"texture0");
    name[5] = sPoolString(L"texture1");
    name[6] = sPoolString(L"alphatest");
    name[7] = sPoolString(L"alpharef");
    name[8] = sPoolString(L"fog");
    name[9] = sPoolString(L"extras");
    name[10] = sPoolString(L"extras");
    name[11] = sPoolString(L"extras");
    name[12] = sPoolString(L"uvtrans");
    name[13] = sPoolString(L"transforms");
    name[14] = sPoolString(L"simplescale");
    name[15] = sPoolString(L"scale");
    name[16] = sPoolString(L"rot");
    name[17] = sPoolString(L"trans");
    name[18] = sPoolString(L"");
    name[19] = sPoolString(L"vertextexture");
    name[20] = sPoolString(L"texture2");
    name[21] = sPoolString(L"mapping");
    name[22] = sPoolString(L"vertexscale");
  }
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[15],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[16],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[17],ScriptTypeFloat,3,cmd->Data+15);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+19);
}
void SimpleMtrlBind3SimpleMaterial(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import alpharef : int;\n");
  tb.PrintF(L"  import simplescale : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import vertexscale : float;\n");
}
const sChar *SimpleMtrlWikiSimpleMaterial =
L"= SimpleMtrl : SimpleMaterial\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SimpleMaterial\n"
L"\n"
L"  !i Output Type\n"
L"  !i SimpleMtrl\n"
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
L" !i optional\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link VertexTexture\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Light\n"
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
L" !i VertexColor\n"
L" !i Flags\n"
L" !i Light\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Material\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i zrender\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Texture0\n"
L" !i Texture0\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i matrix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i LightEnv\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Texture1\n"
L" !i Texture1\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i matrix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i LightEnv\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Fog\n"
L" !i Extras\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i black\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clip3\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Clip Planes\n"
L" !i Extras\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Normal Storage\n"
L" !i Extras\n"
L" !i precise\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i compact\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Texture Op\n"
L" !i Extras\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i UVTrans\n"
L" !i uv\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i world\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i camera\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-reflect\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SimpleScale\n"
L" !i SimpleScale\n"
L" !i float\n"
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
L" !i VertexTexture\n"
L" !i VertexTexture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Texture2\n"
L" !i Texture2\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i matrix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i LightEnv\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mapping\n"
L" !i Extras\n"
L" !i uv\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i noise\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i VertexScale\n"
L" !i VertexScale\n"
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

sBool CustomMtrlCmdCustomMaterial2(wExecutive *exe,wCommand *cmd)
{
  CustomMtrlParaCustomMaterial2 sUNUSED *para = (CustomMtrlParaCustomMaterial2 *)(cmd->Data); para;
  TextObject sUNUSED *in0 = cmd->GetInput<TextObject *>(0); in0;
  TextObject sUNUSED *in1 = cmd->GetInput<TextObject *>(1); in1;
  Texture2D sUNUSED *in2 = cmd->GetInput<Texture2D *>(2); in2;
  CustomMtrl *out = (CustomMtrl *) cmd->Output;
  if(!out) { out=new CustomMtrl; cmd->Output=out; }

  {
#line 282 "wz4_mtrl2_ops.ops"

    if(cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();
    }

    // copy vs parameters
    sCopyMem(out->vs_var0, para->vs_var0, sizeof(para->vs_var0));
    sCopyMem(out->vs_var1, para->vs_var1, sizeof(para->vs_var1));
    sCopyMem(out->vs_var2, para->vs_var2, sizeof(para->vs_var2));
    sCopyMem(out->vs_var3, para->vs_var3, sizeof(para->vs_var3));
    sCopyMem(out->vs_var4, para->vs_var4, sizeof(para->vs_var4));

    // copy ps parameters
    sCopyMem(out->ps_var0, para->ps_var0, sizeof(para->ps_var0));
    sCopyMem(out->ps_var1, para->ps_var1, sizeof(para->ps_var1));
    sCopyMem(out->ps_var2, para->ps_var2, sizeof(para->ps_var2));
    sCopyMem(out->ps_var3, para->ps_var3, sizeof(para->ps_var3));
    sCopyMem(out->ps_var4, para->ps_var4, sizeof(para->ps_var4));

    static sU32 blend[] = { 0,sMB_PMALPHA,sMB_ADD,sMB_SUB,sMB_MUL,sMB_MUL2,sMB_ADDSMOOTH,sMB_ALPHA };
    sMatrix34 mat;
    out->SetMtrl(para->Flags,blend[para->Blend]);

    // init textures
    sInt firstInTex = 2;      // first texture input position
    sInt indexTexture = 0;    // current material texture index
    for(sInt i=firstInTex; i<cmd->InputCount && indexTexture<15; i++)
    {
      Texture2D *inTex = cmd->GetInput<Texture2D *>(i);
      if(inTex)
      {
        sInt tmpFilter = sMTF_TILE;
        switch(indexTexture)
        {
          case 0: tmpFilter =  para->TexFilter0 ; break;
          case 1: tmpFilter =  para->TexFilter1 ; break;
          case 2: tmpFilter =  para->TexFilter2 ; break;
          case 3: tmpFilter =  para->TexFilter3 ; break;
          case 4: tmpFilter =  para->TexFilter4 ; break;
          case 5: tmpFilter =  para->TexFilter5 ; break;
          case 6: tmpFilter =  para->TexFilter6 ; break;
          case 7: tmpFilter =  para->TexFilter7 ; break;
          case 8: tmpFilter =  para->TexFilter8 ; break;
          case 9: tmpFilter =  para->TexFilter9 ; break;
          case 10: tmpFilter = para->TexFilter10; break;
          case 11: tmpFilter = para->TexFilter11; break;
          case 12: tmpFilter = para->TexFilter12; break;
          case 13: tmpFilter = para->TexFilter13; break;
          case 14: tmpFilter = para->TexFilter14; break;
          //case 15: tmpFilter = para->TexFilter15; break;
        }
        out->SetTex(indexTexture, inTex, tmpFilter);
        indexTexture++;
      }
    }

    out->SetAlphaTest(para->AlphaTest,para->AlphaRef);
    out->Log.Clear();

    sShader *vs=out->CompileShader(sSTF_VERTEX|sSTF_HLSL23,in0->Text.Get());
    if (!vs)
    {
      cmd->SetError(L"Vertex shader compile failed");
      return 0;
    }

    sShader *ps=out->CompileShader(sSTF_PIXEL|sSTF_HLSL23,in1->Text.Get());
    if (!ps)
    {
      cmd->SetError(L"Pixel shader compile failed");
      return 0;
    }

    out->SetShader(vs,ps);
    out->Prepare();
  ;
#line 906 "wz4_mtrl2_ops.cpp"
    return 1;
  }
}

sInt CustomMtrlActCustomMaterial2(wOp *op,sInt code,sInt pos)
{
  CustomMtrlParaCustomMaterial2 sUNUSED *para = (CustomMtrlParaCustomMaterial2 *)(op->EditData); para;
#line 362 "wz4_mtrl2_ops.ops"

    if(code==1)
    {
      if(op->RefObj)
      {
        CustomMtrl *mtrl = (CustomMtrl*) op->RefObj;
        if(mtrl && mtrl->Log.GetCount())
          App->PopupText(mtrl->Log.Get());
      }
      return 0;
    }
    if(code==2)
    {
      return 1;
    }

    return 0;
  ;
#line 933 "wz4_mtrl2_ops.cpp"
}

void CustomMtrlGuiCustomMaterial2(wGridFrameHelper &gh,wOp *op)
{
  CustomMtrlParaCustomMaterial2 sUNUSED *para = (CustomMtrlParaCustomMaterial2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0zoff|zread|zwrite|zon:*4Doublesided|Singlesided|Inverted:*7-|Light",gh.ChangeMsg);

  gh.Label(L"ColorMask");
  gh.Flags(&para->Flags,L"*8-|MaskAlpha:*9-|MaskRed:*10-|MaskGreen:*11-|MaskBlue",gh.ChangeMsg);

  gh.Label(L"VertexColor");
  gh.Flags(&para->Flags,L"*12-|Light:*14-|Material:*24zrender|-",gh.ChangeMsg);

  gh.Label(L"Blend");
  gh.Flags(&para->Blend,L"solid|alpha premul|add|sub|mul|mul2|addsmooth|alpha plain",gh.ChangeMsg);

  gh.Label(L"AlphaTest");
  gh.Flags(&para->AlphaTest,L"|||inverted|on|||off",gh.LayoutMsg);

  if((para->AlphaTest!=0x0007))
  {
    sIntControl *int_AlphaRef = gh.Int(&para->AlphaRef,0,255,1.000000f);
    int_AlphaRef->Default = 0x00000000; int_AlphaRef->RightStep = 0.125000f;

  }
  gh.Group(L"debug");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Shadercode",gh.ActionMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"FlushShaders",gh.ActionMsg);

  gh.Group(L"Vertex shader variables");

  gh.Label(L"vs_var0");
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

  gh.Label(L"vs_var1");
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

  gh.Label(L"vs_var2");
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

  gh.Label(L"vs_var3");
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

  gh.Label(L"vs_var4");
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

  gh.Label(L"ps_var0");
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

  gh.Label(L"ps_var1");
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

  gh.Label(L"ps_var2");
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

  gh.Label(L"ps_var3");
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

  gh.Label(L"ps_var4");
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

  if((op->ConnectionMask & (1<<2))!=0)
  {
    gh.Label(L"TexFilter0");
    gh.Flags(&para->TexFilter0,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.ChangeMsg);

  }
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
}

void CustomMtrlDefCustomMaterial2(wOp *op)
{
  CustomMtrlParaCustomMaterial2 sUNUSED *para = (CustomMtrlParaCustomMaterial2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000093;
  para->AlphaTest = 0x00000007;
}

void CustomMtrlBindCustomMaterial2(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"alpharef"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"vs_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"ps_var4"),val);
}
void CustomMtrlBind2CustomMaterial2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[37];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"colormask");
    name[2] = sPoolString(L"vertexcolor");
    name[3] = sPoolString(L"blend");
    name[4] = sPoolString(L"alphatest");
    name[5] = sPoolString(L"alpharef");
    name[6] = sPoolString(L"debug");
    name[7] = sPoolString(L"shadercode");
    name[8] = sPoolString(L"flushshaders");
    name[9] = sPoolString(L"");
    name[10] = sPoolString(L"vs_var0");
    name[11] = sPoolString(L"vs_var1");
    name[12] = sPoolString(L"vs_var2");
    name[13] = sPoolString(L"vs_var3");
    name[14] = sPoolString(L"vs_var4");
    name[15] = sPoolString(L"");
    name[16] = sPoolString(L"ps_var0");
    name[17] = sPoolString(L"ps_var1");
    name[18] = sPoolString(L"ps_var2");
    name[19] = sPoolString(L"ps_var3");
    name[20] = sPoolString(L"ps_var4");
    name[21] = sPoolString(L"");
    name[22] = sPoolString(L"texfilter0");
    name[23] = sPoolString(L"texfilter1");
    name[24] = sPoolString(L"texfilter2");
    name[25] = sPoolString(L"texfilter3");
    name[26] = sPoolString(L"texfilter4");
    name[27] = sPoolString(L"texfilter5");
    name[28] = sPoolString(L"texfilter6");
    name[29] = sPoolString(L"texfilter7");
    name[30] = sPoolString(L"texfilter8");
    name[31] = sPoolString(L"texfilter9");
    name[32] = sPoolString(L"texfilter10");
    name[33] = sPoolString(L"texfilter11");
    name[34] = sPoolString(L"texfilter12");
    name[35] = sPoolString(L"texfilter13");
    name[36] = sPoolString(L"texfilter14");
  }
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[10],ScriptTypeFloat,4,cmd->Data+4);
  ctx->AddImport(name[11],ScriptTypeFloat,4,cmd->Data+8);
  ctx->AddImport(name[12],ScriptTypeFloat,4,cmd->Data+12);
  ctx->AddImport(name[13],ScriptTypeFloat,4,cmd->Data+16);
  ctx->AddImport(name[14],ScriptTypeFloat,4,cmd->Data+20);
  ctx->AddImport(name[16],ScriptTypeFloat,4,cmd->Data+24);
  ctx->AddImport(name[17],ScriptTypeFloat,4,cmd->Data+28);
  ctx->AddImport(name[18],ScriptTypeFloat,4,cmd->Data+32);
  ctx->AddImport(name[19],ScriptTypeFloat,4,cmd->Data+36);
  ctx->AddImport(name[20],ScriptTypeFloat,4,cmd->Data+40);
}
void CustomMtrlBind3CustomMaterial2(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import alpharef : int;\n");
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
}
const sChar *CustomMtrlWikiCustomMaterial2 =
L"= CustomMtrl : CustomMaterial2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CustomMaterial2\n"
L"\n"
L"  !i Output Type\n"
L"  !i CustomMtrl\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Light\n"
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
L" !i VertexColor\n"
L" !i Flags\n"
L" !i Light\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Material\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i zrender\n"
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
L" !i TexFilter0\n"
L" !i TexFilter0\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool CustomMtrlCmdCustomMaterial(wExecutive *exe,wCommand *cmd)
{
  CustomMtrlParaCustomMaterial sUNUSED *para = (CustomMtrlParaCustomMaterial *)(cmd->Data); para;
  TextObject sUNUSED *in0 = cmd->GetInput<TextObject *>(0); in0;
  TextObject sUNUSED *in1 = cmd->GetInput<TextObject *>(1); in1;
  CustomMtrl *out = (CustomMtrl *) cmd->Output;
  if(!out) { out=new CustomMtrl; cmd->Output=out; }

  {
#line 412 "wz4_mtrl2_ops.ops"

    if(cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();
    }

    static sU32 blend[] = { 0,sMB_PMALPHA,sMB_ADD,sMB_SUB,sMB_MUL,sMB_MUL2,sMB_ADDSMOOTH,sMB_ALPHA };
    sMatrix34 mat;

    out->SetMtrl(para->Flags,blend[para->Blend]);
//    out->SetTex(0,in0,para->Texture0);
//    tflags[0] = para->Texture0;
    out->SetAlphaTest(para->AlphaTest,para->AlphaRef);
    out->Log.Clear();

    sShader *vs=out->CompileShader(sSTF_VERTEX|sSTF_HLSL23,in0->Text.Get());
    if (!vs)
    {
      cmd->SetError(L"Vertex shader compile failed");
      return 0;
    }

    sShader *ps=out->CompileShader(sSTF_PIXEL|sSTF_HLSL23,in1->Text.Get());
    if (!ps)
    {
      cmd->SetError(L"Pixel shader compile failed");
      return 0;
    }

    out->SetShader(vs,ps);
    out->Prepare();
  ;
#line 2329 "wz4_mtrl2_ops.cpp"
    return 1;
  }
}

sInt CustomMtrlActCustomMaterial(wOp *op,sInt code,sInt pos)
{
  CustomMtrlParaCustomMaterial sUNUSED *para = (CustomMtrlParaCustomMaterial *)(op->EditData); para;
#line 447 "wz4_mtrl2_ops.ops"

    if(code==1)
    { 
      if(op->RefObj)
      {
        CustomMtrl *mtrl = (CustomMtrl*) op->RefObj;
        if(mtrl && mtrl->Log.GetCount())
          App->PopupText(mtrl->Log.Get());
      }
      return 0;
    }
    if(code==2)
    { 
      return 1;
    }

    return 0;
  ;
#line 2356 "wz4_mtrl2_ops.cpp"
}

void CustomMtrlGuiCustomMaterial(wGridFrameHelper &gh,wOp *op)
{
  CustomMtrlParaCustomMaterial sUNUSED *para = (CustomMtrlParaCustomMaterial *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0zoff|zread|zwrite|zon:*4Doublesided|Singlesided|Inverted:*7-|Light",gh.ChangeMsg);

  gh.Label(L"ColorMask");
  gh.Flags(&para->Flags,L"*8-|MaskAlpha:*9-|MaskRed:*10-|MaskGreen:*11-|MaskBlue",gh.ChangeMsg);

  gh.Label(L"VertexColor");
  gh.Flags(&para->Flags,L"*12-|Light:*14-|Material:*24zrender|-",gh.ChangeMsg);

  gh.Label(L"Blend");
  gh.Flags(&para->Blend,L"solid|alpha premul|add|sub|mul|mul2|addsmooth|alpha plain",gh.ChangeMsg);

  gh.Label(L"AlphaTest");
  gh.Flags(&para->AlphaTest,L"|||inverted|on|||off",gh.LayoutMsg);

  if((para->AlphaTest!=0x0007))
  {
    sIntControl *int_AlphaRef = gh.Int(&para->AlphaRef,0,255,1.000000f);
    int_AlphaRef->Default = 0x00000000; int_AlphaRef->RightStep = 0.125000f;

  }
  gh.Label(L"VertexShader");
  gh.Flags(&op->Links[0].Select,L"|link|unused| 1| 2",gh.ConnectLayoutMsg);
  if(op->Links[0].Select==1)
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

  gh.Label(L"PixelShader");
  gh.Flags(&op->Links[1].Select,L"|link|unused| 1| 2",gh.ConnectLayoutMsg);
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

  gh.Group(L"debug");

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"Shadercode",gh.ActionMsg);

  gh.ActionMsg.Code = 2;
  gh.PushButton(L"FlushShaders",gh.ActionMsg);
}

void CustomMtrlDefCustomMaterial(wOp *op)
{
  CustomMtrlParaCustomMaterial sUNUSED *para = (CustomMtrlParaCustomMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000093;
  para->AlphaTest = 0x00000007;
}

void CustomMtrlBindCustomMaterial(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"alpharef"),val);
}
void CustomMtrlBind2CustomMaterial(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"colormask");
    name[2] = sPoolString(L"vertexcolor");
    name[3] = sPoolString(L"blend");
    name[4] = sPoolString(L"alphatest");
    name[5] = sPoolString(L"alpharef");
    name[6] = sPoolString(L"vertexshader");
    name[7] = sPoolString(L"pixelshader");
    name[8] = sPoolString(L"debug");
    name[9] = sPoolString(L"shadercode");
    name[10] = sPoolString(L"flushshaders");
  }
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+3);
}
void CustomMtrlBind3CustomMaterial(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import alpharef : int;\n");
}
const sChar *CustomMtrlWikiCustomMaterial =
L"= CustomMtrl : CustomMaterial\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CustomMaterial\n"
L"\n"
L"  !i Output Type\n"
L"  !i CustomMtrl\n"
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
L" !i TextObject\n"
L" !i link VertexShader\n"
L" !i *\n"
L"\n"
L" !i TextObject\n"
L" !i link PixelShader\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Light\n"
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
L" !i VertexColor\n"
L" !i Flags\n"
L" !i Light\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Material\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i zrender\n"
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
L" !i VertexShader\n"
L" !i VertexShader\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i PixelShader\n"
L" !i PixelShader\n"
L" !i link\n"
L" !i *\n"
L"\n"
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

sBool Wz4RenderCmdSimpleMtrlEnv(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSimpleMtrlEnv sUNUSED *para = (Wz4RenderParaSimpleMtrlEnv *)(cmd->Data); para;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 557 "wz4_mtrl2_ops.ops"

    RNSimpleMtrlEnv *node = new RNSimpleMtrlEnv();
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 2703 "wz4_mtrl2_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSimpleMtrlEnv(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSimpleMtrlEnv sUNUSED *para = (Wz4RenderParaSimpleMtrlEnv *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"light");

  gh.Label(L"* Ambient");
  gh.ColorPick(&para->Ambient,L"rgba",0);

  gh.Label(L"* Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  sFloatControl *float_Color0Amp = gh.Float(&para->Color0Amp,-16.0000f,16.00000f,0.010000f);
  float_Color0Amp->Default = 1.000000f; float_Color0Amp->RightStep = 0.125000f;

  gh.Label(L"* Dir0");
  gh.BeginTied();
  sFloatControl *float_Dir0_0 = gh.Float(&para->Dir0.x,-2.00000f,2.000000f,0.001000f);
  float_Dir0_0->Default = 0.000000f; float_Dir0_0->RightStep = 0.125000f;
  sFloatControl *float_Dir0_1 = gh.Float(&para->Dir0.y,-2.00000f,2.000000f,0.001000f);
  float_Dir0_1->Default = 0.000000f; float_Dir0_1->RightStep = 0.125000f;
  sFloatControl *float_Dir0_2 = gh.Float(&para->Dir0.z,-2.00000f,2.000000f,0.001000f);
  float_Dir0_2->Default = 0.000000f; float_Dir0_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Flags(&para->Headlights,L"-|HeadLight",gh.ChangeMsg);

  gh.Label(L"* Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);

  sFloatControl *float_Color1Amp = gh.Float(&para->Color1Amp,-16.0000f,16.00000f,0.010000f);
  float_Color1Amp->Default = 1.000000f; float_Color1Amp->RightStep = 0.125000f;

  gh.Label(L"* Dir1");
  gh.BeginTied();
  sFloatControl *float_Dir1_0 = gh.Float(&para->Dir1.x,-2.00000f,2.000000f,0.001000f);
  float_Dir1_0->Default = 0.000000f; float_Dir1_0->RightStep = 0.125000f;
  sFloatControl *float_Dir1_1 = gh.Float(&para->Dir1.y,-2.00000f,2.000000f,0.001000f);
  float_Dir1_1->Default = 0.000000f; float_Dir1_1->RightStep = 0.125000f;
  sFloatControl *float_Dir1_2 = gh.Float(&para->Dir1.z,-2.00000f,2.000000f,0.001000f);
  float_Dir1_2->Default = 0.000000f; float_Dir1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Flags(&para->Headlights,L"*4-|HeadLight",gh.ChangeMsg);

  gh.Label(L"* Color2");
  gh.ColorPick(&para->Color2,L"rgba",0);

  sFloatControl *float_Color2Amp = gh.Float(&para->Color2Amp,-16.0000f,16.00000f,0.010000f);
  float_Color2Amp->Default = 1.000000f; float_Color2Amp->RightStep = 0.125000f;

  gh.Label(L"* Dir2");
  gh.BeginTied();
  sFloatControl *float_Dir2_0 = gh.Float(&para->Dir2.x,-2.00000f,2.000000f,0.001000f);
  float_Dir2_0->Default = 0.000000f; float_Dir2_0->RightStep = 0.125000f;
  sFloatControl *float_Dir2_1 = gh.Float(&para->Dir2.y,-2.00000f,2.000000f,0.001000f);
  float_Dir2_1->Default = 0.000000f; float_Dir2_1->RightStep = 0.125000f;
  sFloatControl *float_Dir2_2 = gh.Float(&para->Dir2.z,-2.00000f,2.000000f,0.001000f);
  float_Dir2_2->Default = 0.000000f; float_Dir2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Flags(&para->Headlights,L"*8-|HeadLight",gh.ChangeMsg);

  gh.Label(L"* Color3");
  gh.ColorPick(&para->Color3,L"rgba",0);

  sFloatControl *float_Color3Amp = gh.Float(&para->Color3Amp,-16.0000f,16.00000f,0.010000f);
  float_Color3Amp->Default = 1.000000f; float_Color3Amp->RightStep = 0.125000f;

  gh.Label(L"* Dir3");
  gh.BeginTied();
  sFloatControl *float_Dir3_0 = gh.Float(&para->Dir3.x,-2.00000f,2.000000f,0.001000f);
  float_Dir3_0->Default = 0.000000f; float_Dir3_0->RightStep = 0.125000f;
  sFloatControl *float_Dir3_1 = gh.Float(&para->Dir3.y,-2.00000f,2.000000f,0.001000f);
  float_Dir3_1->Default = 0.000000f; float_Dir3_1->RightStep = 0.125000f;
  sFloatControl *float_Dir3_2 = gh.Float(&para->Dir3.z,-2.00000f,2.000000f,0.001000f);
  float_Dir3_2->Default = 0.000000f; float_Dir3_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Flags(&para->Headlights,L"*12-|HeadLight",gh.ChangeMsg);

  gh.Group(L"fog");

  gh.Label(L"* FogNear");
  sFloatControl *float_FogNear = gh.Float(&para->FogNear,-65536.0f,65536.00f,1.000000f);
  float_FogNear->Default = 10.00000f; float_FogNear->RightStep = 0.125000f;

  gh.Label(L"* FogFar");
  sFloatControl *float_FogFar = gh.Float(&para->FogFar,0.000000f,65536.00f,1.000000f);
  float_FogFar->Default = 1000.000f; float_FogFar->RightStep = 0.125000f;

  gh.Label(L"* FogColor");
  gh.ColorPick(&para->FogColor,L"rgba",0);

  gh.Label(L"FogClip3");
  gh.Flags(&para->ClipPlanes,L"*4-|need",gh.LayoutMsg);

  gh.Group(L"clipplanes");

  gh.Label(L"ClipPlanes");
  gh.Flags(&para->ClipPlanes,L"-| 0:*1-| 1:*2-| 2:*3-| 3",gh.LayoutMsg);

  if((para->ClipPlanes&0x0001))
  {
    gh.Label(L"* Plane 0");
    gh.BeginTied();
    sFloatControl *float_Plane0Dir_0 = gh.Float(&para->Plane0Dir.x,-2.00000f,2.000000f,0.001000f);
    float_Plane0Dir_0->Default = 0.000000f; float_Plane0Dir_0->RightStep = 0.125000f;
    sFloatControl *float_Plane0Dir_1 = gh.Float(&para->Plane0Dir.y,-2.00000f,2.000000f,0.001000f);
    float_Plane0Dir_1->Default = 0.000000f; float_Plane0Dir_1->RightStep = 0.125000f;
    sFloatControl *float_Plane0Dir_2 = gh.Float(&para->Plane0Dir.z,-2.00000f,2.000000f,0.001000f);
    float_Plane0Dir_2->Default = 0.000000f; float_Plane0Dir_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Plane0Dist = gh.Float(&para->Plane0Dist,-65536.0f,65536.00f,0.125000f);
    float_Plane0Dist->Default = 0.000000f; float_Plane0Dist->RightStep = 0.125000f;

  }
  if((para->ClipPlanes&0x0002))
  {
    gh.Label(L"* Plane 1");
    gh.BeginTied();
    sFloatControl *float_Plane1Dir_0 = gh.Float(&para->Plane1Dir.x,-2.00000f,2.000000f,0.001000f);
    float_Plane1Dir_0->Default = 0.000000f; float_Plane1Dir_0->RightStep = 0.125000f;
    sFloatControl *float_Plane1Dir_1 = gh.Float(&para->Plane1Dir.y,-2.00000f,2.000000f,0.001000f);
    float_Plane1Dir_1->Default = 0.000000f; float_Plane1Dir_1->RightStep = 0.125000f;
    sFloatControl *float_Plane1Dir_2 = gh.Float(&para->Plane1Dir.z,-2.00000f,2.000000f,0.001000f);
    float_Plane1Dir_2->Default = 0.000000f; float_Plane1Dir_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Plane1Dist = gh.Float(&para->Plane1Dist,-65536.0f,65536.00f,0.125000f);
    float_Plane1Dist->Default = 0.000000f; float_Plane1Dist->RightStep = 0.125000f;

  }
  if((para->ClipPlanes&0x0004))
  {
    gh.Label(L"* Plane 2");
    gh.BeginTied();
    sFloatControl *float_Plane2Dir_0 = gh.Float(&para->Plane2Dir.x,-2.00000f,2.000000f,0.001000f);
    float_Plane2Dir_0->Default = 0.000000f; float_Plane2Dir_0->RightStep = 0.125000f;
    sFloatControl *float_Plane2Dir_1 = gh.Float(&para->Plane2Dir.y,-2.00000f,2.000000f,0.001000f);
    float_Plane2Dir_1->Default = 0.000000f; float_Plane2Dir_1->RightStep = 0.125000f;
    sFloatControl *float_Plane2Dir_2 = gh.Float(&para->Plane2Dir.z,-2.00000f,2.000000f,0.001000f);
    float_Plane2Dir_2->Default = 0.000000f; float_Plane2Dir_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Plane2Dist = gh.Float(&para->Plane2Dist,-65536.0f,65536.00f,0.125000f);
    float_Plane2Dist->Default = 0.000000f; float_Plane2Dist->RightStep = 0.125000f;

  }
  if((para->ClipPlanes&0x0018))
  {
    gh.Label(L"* Plane 3");
    gh.BeginTied();
    sFloatControl *float_Plane3Dir_0 = gh.Float(&para->Plane3Dir.x,-2.00000f,2.000000f,0.001000f);
    float_Plane3Dir_0->Default = 0.000000f; float_Plane3Dir_0->RightStep = 0.125000f;
    sFloatControl *float_Plane3Dir_1 = gh.Float(&para->Plane3Dir.y,-2.00000f,2.000000f,0.001000f);
    float_Plane3Dir_1->Default = 0.000000f; float_Plane3Dir_1->RightStep = 0.125000f;
    sFloatControl *float_Plane3Dir_2 = gh.Float(&para->Plane3Dir.z,-2.00000f,2.000000f,0.001000f);
    float_Plane3Dir_2->Default = 0.000000f; float_Plane3Dir_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Plane3Dist = gh.Float(&para->Plane3Dist,-65536.0f,65536.00f,0.125000f);
    float_Plane3Dist->Default = 0.000000f; float_Plane3Dist->RightStep = 0.125000f;

  }
  gh.Group(L"optional texture transform");

  gh.Label(L"* TexScale");
  gh.BeginTied();
  sFloatControl *float_TexScale_0 = gh.Float(&para->TexScale.x,-1024.00f,1024.000f,0.001000f);
  float_TexScale_0->Default = 1.000000f; float_TexScale_0->RightStep = 0.125000f;
  sFloatControl *float_TexScale_1 = gh.Float(&para->TexScale.y,-1024.00f,1024.000f,0.001000f);
  float_TexScale_1->Default = 1.000000f; float_TexScale_1->RightStep = 0.125000f;
  sFloatControl *float_TexScale_2 = gh.Float(&para->TexScale.z,-1024.00f,1024.000f,0.001000f);
  float_TexScale_2->Default = 1.000000f; float_TexScale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* TexRot");
  gh.BeginTied();
  sFloatControl *float_TexRot_0 = gh.Float(&para->TexRot.x,-16.0000f,16.00000f,0.010000f);
  float_TexRot_0->Default = 0.000000f; float_TexRot_0->RightStep = 0.125000f;
  sFloatControl *float_TexRot_1 = gh.Float(&para->TexRot.y,-16.0000f,16.00000f,0.010000f);
  float_TexRot_1->Default = 0.000000f; float_TexRot_1->RightStep = 0.125000f;
  sFloatControl *float_TexRot_2 = gh.Float(&para->TexRot.z,-16.0000f,16.00000f,0.010000f);
  float_TexRot_2->Default = 0.000000f; float_TexRot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* TexTrans");
  gh.BeginTied();
  sFloatControl *float_TexTrans_0 = gh.Float(&para->TexTrans.x,-1024.00f,1024.000f,0.010000f);
  float_TexTrans_0->Default = 0.000000f; float_TexTrans_0->RightStep = 0.125000f;
  sFloatControl *float_TexTrans_1 = gh.Float(&para->TexTrans.y,-1024.00f,1024.000f,0.010000f);
  float_TexTrans_1->Default = 0.000000f; float_TexTrans_1->RightStep = 0.125000f;
  sFloatControl *float_TexTrans_2 = gh.Float(&para->TexTrans.z,-1024.00f,1024.000f,0.010000f);
  float_TexTrans_2->Default = 0.000000f; float_TexTrans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefSimpleMtrlEnv(wOp *op)
{
  Wz4RenderParaSimpleMtrlEnv sUNUSED *para = (Wz4RenderParaSimpleMtrlEnv *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Ambient = 0xff404040;
  para->Color0 = 0xffc0c0c0;
  para->Color0Amp = 1.000000f;
  para->Color1 = 0xff000000;
  para->Color1Amp = 1.000000f;
  para->Color2 = 0xff000000;
  para->Color2Amp = 1.000000f;
  para->Color3 = 0xff000000;
  para->Color3Amp = 1.000000f;
  para->FogNear = 10.00000f;
  para->FogFar = 1000.000f;
  para->FogColor = 0x80ffffff;
  para->TexScale.x = 1.000000f;
  para->TexScale.y = 1.000000f;
  para->TexScale.z = 1.000000f;
}

void Wz4RenderBindSimpleMtrlEnv(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"ambient"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+41;
  ctx->BindLocal(ctx->AddSymbol(L"color0amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"dir0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"dir0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"dir0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+42;
  ctx->BindLocal(ctx->AddSymbol(L"color1amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"dir1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"dir1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"dir1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"color2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+43;
  ctx->BindLocal(ctx->AddSymbol(L"color2amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"dir2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"dir2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"dir2"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"color3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+44;
  ctx->BindLocal(ctx->AddSymbol(L"color3amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"dir3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"dir3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"dir3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"fognear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"fogfar"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"fogcolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+33;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+37;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"texscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"texscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+45;
  ctx->BindLocal(ctx->AddSymbol(L"texscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"texrot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"texrot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"texrot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"textrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"textrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"textrans"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2SimpleMtrlEnv(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[41];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"light");
    name[3] = sPoolString(L"ambient");
    name[4] = sPoolString(L"color0");
    name[5] = sPoolString(L"color0amp");
    name[6] = sPoolString(L"dir0");
    name[7] = sPoolString(L"headlights");
    name[8] = sPoolString(L"color1");
    name[9] = sPoolString(L"color1amp");
    name[10] = sPoolString(L"dir1");
    name[11] = sPoolString(L"headlights");
    name[12] = sPoolString(L"color2");
    name[13] = sPoolString(L"color2amp");
    name[14] = sPoolString(L"dir2");
    name[15] = sPoolString(L"headlights");
    name[16] = sPoolString(L"color3");
    name[17] = sPoolString(L"color3amp");
    name[18] = sPoolString(L"dir3");
    name[19] = sPoolString(L"headlights");
    name[20] = sPoolString(L"fog");
    name[21] = sPoolString(L"fognear");
    name[22] = sPoolString(L"fogfar");
    name[23] = sPoolString(L"fogcolor");
    name[24] = sPoolString(L"fogclip3");
    name[25] = sPoolString(L"clipplanes");
    name[26] = sPoolString(L"clipplanes");
    name[27] = sPoolString(L"plane0dir");
    name[28] = sPoolString(L"plane0dist");
    name[29] = sPoolString(L"plane1dir");
    name[30] = sPoolString(L"plane1dist");
    name[31] = sPoolString(L"plane2dir");
    name[32] = sPoolString(L"plane2dist");
    name[33] = sPoolString(L"plane3dir");
    name[34] = sPoolString(L"plane3dist");
    name[35] = sPoolString(L"");
    name[36] = sPoolString(L"texscale");
    name[37] = sPoolString(L"texrot");
    name[38] = sPoolString(L"textrans");
    name[39] = sPoolString(L"");
    name[40] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+23);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+41);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[8],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+42);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[12],ScriptTypeColor,1,cmd->Data+10);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+43);
  ctx->AddImport(name[14],ScriptTypeFloat,3,cmd->Data+11);
  ctx->AddImport(name[16],ScriptTypeColor,1,cmd->Data+14);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+44);
  ctx->AddImport(name[18],ScriptTypeFloat,3,cmd->Data+15);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[23],ScriptTypeColor,1,cmd->Data+20);
  ctx->AddImport(name[27],ScriptTypeFloat,3,cmd->Data+25);
  ctx->AddImport(name[28],ScriptTypeFloat,1,cmd->Data+28);
  ctx->AddImport(name[29],ScriptTypeFloat,3,cmd->Data+29);
  ctx->AddImport(name[30],ScriptTypeFloat,1,cmd->Data+32);
  ctx->AddImport(name[31],ScriptTypeFloat,3,cmd->Data+33);
  ctx->AddImport(name[32],ScriptTypeFloat,1,cmd->Data+36);
  ctx->AddImport(name[33],ScriptTypeFloat,3,cmd->Data+37);
  ctx->AddImport(name[34],ScriptTypeFloat,1,cmd->Data+40);
  ctx->AddImport(name[36],ScriptTypeFloat,3,cmd->Data+45);
  ctx->AddImport(name[37],ScriptTypeFloat,3,cmd->Data+48);
  ctx->AddImport(name[38],ScriptTypeFloat,3,cmd->Data+51);
  ctx->AddImport(name[40],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3SimpleMtrlEnv(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import ambient : color;\n");
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color0amp : float;\n");
  tb.PrintF(L"  import dir0 : float[3];\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import color1amp : float;\n");
  tb.PrintF(L"  import dir1 : float[3];\n");
  tb.PrintF(L"  import color2 : color;\n");
  tb.PrintF(L"  import color2amp : float;\n");
  tb.PrintF(L"  import dir2 : float[3];\n");
  tb.PrintF(L"  import color3 : color;\n");
  tb.PrintF(L"  import color3amp : float;\n");
  tb.PrintF(L"  import dir3 : float[3];\n");
  tb.PrintF(L"  import fognear : float;\n");
  tb.PrintF(L"  import fogfar : float;\n");
  tb.PrintF(L"  import fogcolor : color;\n");
  tb.PrintF(L"  import plane0dir : float[3];\n");
  tb.PrintF(L"  import plane0dist : float;\n");
  tb.PrintF(L"  import plane1dir : float[3];\n");
  tb.PrintF(L"  import plane1dist : float;\n");
  tb.PrintF(L"  import plane2dir : float[3];\n");
  tb.PrintF(L"  import plane2dist : float;\n");
  tb.PrintF(L"  import plane3dir : float[3];\n");
  tb.PrintF(L"  import plane3dist : float;\n");
  tb.PrintF(L"  import texscale : float[3];\n");
  tb.PrintF(L"  import texrot : float[3];\n");
  tb.PrintF(L"  import textrans : float[3];\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSimpleMtrlEnv =
L"= Wz4Render : SimpleMtrlEnv\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SimpleMtrlEnv\n"
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
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color0Amp\n"
L" !i Color0Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Dir0\n"
L" !i Dir0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Headlights\n"
L" !i HeadLight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color1\n"
L" !i Color1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1Amp\n"
L" !i Color1Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Dir1\n"
L" !i Dir1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Headlights\n"
L" !i HeadLight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color2\n"
L" !i Color2\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color2Amp\n"
L" !i Color2Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Dir2\n"
L" !i Dir2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Headlights\n"
L" !i HeadLight\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color3\n"
L" !i Color3\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color3Amp\n"
L" !i Color3Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Dir3\n"
L" !i Dir3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Headlights\n"
L" !i HeadLight\n"
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
L" !i FogColor\n"
L" !i FogColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i FogClip3\n"
L" !i ClipPlanes\n"
L" !i need\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L"!T 4 : 1 1 1 2\n"
L" !i ClipPlanes\n"
L" !i ClipPlanes\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Plane 0\n"
L" !i Plane0Dir\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Plane0Dist\n"
L" !i Plane0Dist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Plane 1\n"
L" !i Plane1Dir\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Plane1Dist\n"
L" !i Plane1Dist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Plane 2\n"
L" !i Plane2Dir\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Plane2Dist\n"
L" !i Plane2Dist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Plane 3\n"
L" !i Plane3Dir\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Plane3Dist\n"
L" !i Plane3Dist\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i TexScale\n"
L" !i TexScale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TexRot\n"
L" !i TexRot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TexTrans\n"
L" !i TexTrans\n"
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

void SimpleMtrlAnimSimpleMaterial::Init(class ScriptContext *sc)
{
};

void SimpleMtrlAnimSimpleMaterial::Bind(class ScriptContext *sc,SimpleMtrlParaSimpleMaterial *para)
{
};

void CustomMtrlAnimCustomMaterial2::Init(class ScriptContext *sc)
{
};

void CustomMtrlAnimCustomMaterial2::Bind(class ScriptContext *sc,CustomMtrlParaCustomMaterial2 *para)
{
};

void CustomMtrlAnimCustomMaterial::Init(class ScriptContext *sc)
{
};

void CustomMtrlAnimCustomMaterial::Bind(class ScriptContext *sc,CustomMtrlParaCustomMaterial *para)
{
};

void Wz4RenderAnimSimpleMtrlEnv::Init(class ScriptContext *sc)
{
  _Ambient = sc->AddSymbol(L"ambient");
  _Color0 = sc->AddSymbol(L"color0");
  _Color0Amp = sc->AddSymbol(L"color0amp");
  _Dir0 = sc->AddSymbol(L"dir0");
  _Color1 = sc->AddSymbol(L"color1");
  _Color1Amp = sc->AddSymbol(L"color1amp");
  _Dir1 = sc->AddSymbol(L"dir1");
  _Color2 = sc->AddSymbol(L"color2");
  _Color2Amp = sc->AddSymbol(L"color2amp");
  _Dir2 = sc->AddSymbol(L"dir2");
  _Color3 = sc->AddSymbol(L"color3");
  _Color3Amp = sc->AddSymbol(L"color3amp");
  _Dir3 = sc->AddSymbol(L"dir3");
  _FogNear = sc->AddSymbol(L"fognear");
  _FogFar = sc->AddSymbol(L"fogfar");
  _FogColor = sc->AddSymbol(L"fogcolor");
  _Plane0Dir = sc->AddSymbol(L"plane0dir");
  _Plane0Dist = sc->AddSymbol(L"plane0dist");
  _Plane1Dir = sc->AddSymbol(L"plane1dir");
  _Plane1Dist = sc->AddSymbol(L"plane1dist");
  _Plane2Dir = sc->AddSymbol(L"plane2dir");
  _Plane2Dist = sc->AddSymbol(L"plane2dist");
  _Plane3Dir = sc->AddSymbol(L"plane3dir");
  _Plane3Dist = sc->AddSymbol(L"plane3dist");
  _TexScale = sc->AddSymbol(L"texscale");
  _TexRot = sc->AddSymbol(L"texrot");
  _TexTrans = sc->AddSymbol(L"textrans");
};

void Wz4RenderAnimSimpleMtrlEnv::Bind(class ScriptContext *sc,Wz4RenderParaSimpleMtrlEnv *para)
{
  sc->BindLocalColor(_Ambient,&para->Ambient);
  sc->BindLocalColor(_Color0,&para->Color0);
  sc->BindLocalFloat(_Color0Amp,1,&para->Color0Amp);
  sc->BindLocalFloat(_Dir0,3,&para->Dir0.x);
  sc->BindLocalColor(_Color1,&para->Color1);
  sc->BindLocalFloat(_Color1Amp,1,&para->Color1Amp);
  sc->BindLocalFloat(_Dir1,3,&para->Dir1.x);
  sc->BindLocalColor(_Color2,&para->Color2);
  sc->BindLocalFloat(_Color2Amp,1,&para->Color2Amp);
  sc->BindLocalFloat(_Dir2,3,&para->Dir2.x);
  sc->BindLocalColor(_Color3,&para->Color3);
  sc->BindLocalFloat(_Color3Amp,1,&para->Color3Amp);
  sc->BindLocalFloat(_Dir3,3,&para->Dir3.x);
  sc->BindLocalFloat(_FogNear,1,&para->FogNear);
  sc->BindLocalFloat(_FogFar,1,&para->FogFar);
  sc->BindLocalColor(_FogColor,&para->FogColor);
  sc->BindLocalFloat(_Plane0Dir,3,&para->Plane0Dir.x);
  sc->BindLocalFloat(_Plane0Dist,1,&para->Plane0Dist);
  sc->BindLocalFloat(_Plane1Dir,3,&para->Plane1Dir.x);
  sc->BindLocalFloat(_Plane1Dist,1,&para->Plane1Dist);
  sc->BindLocalFloat(_Plane2Dir,3,&para->Plane2Dir.x);
  sc->BindLocalFloat(_Plane2Dist,1,&para->Plane2Dist);
  sc->BindLocalFloat(_Plane3Dir,3,&para->Plane3Dir.x);
  sc->BindLocalFloat(_Plane3Dist,1,&para->Plane3Dist);
  sc->BindLocalFloat(_TexScale,3,&para->TexScale.x);
  sc->BindLocalFloat(_TexRot,3,&para->TexRot.x);
  sc->BindLocalFloat(_TexTrans,3,&para->TexTrans.x);
};


/****************************************************************************/

void AddTypes_wz4_mtrl2_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4MtrlType = new Wz4MtrlType_);
  Wz4MtrlType->Secondary = secondary;
  Wz4MtrlType->ColumnHeaders[0] = L"Material";
  Wz4MtrlType->ColumnHeaders[1] = L"Environment";
  Wz4MtrlType->ColumnHeaders[4] = L"Mod Shader";
  Wz4MtrlType->ColumnHeaders[5] = L"Mod Texture";
  Wz4MtrlType->ColumnHeaders[6] = L"Mod Mapping";
  Wz4MtrlType->ColumnHeaders[7] = L"Mod FX";

  Doc->Types.AddTail(SimpleMtrlType = new SimpleMtrlType_);
  SimpleMtrlType->Secondary = secondary;

  Doc->Types.AddTail(CustomMtrlType = new CustomMtrlType_);
  CustomMtrlType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_mtrl2_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"SimpleMaterial";
  cl->Label = L"SimpleMaterial";
  cl->OutputType = SimpleMtrlType;
  cl->TabType = Wz4MtrlType;
  cl->Command = SimpleMtrlCmdSimpleMaterial;
  cl->MakeGui = SimpleMtrlGuiSimpleMaterial;
  cl->SetDefaults = SimpleMtrlDefSimpleMaterial;
  cl->BindPara = SimpleMtrlBindSimpleMaterial;
  cl->Bind2Para = SimpleMtrlBind2SimpleMaterial;
  cl->Bind3Para = SimpleMtrlBind3SimpleMaterial;
  cl->WikiText = SimpleMtrlWikiSimpleMaterial;
  cl->ParaWords = 20;
  cl->Shortcut = 'M';
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(3);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  in[2].Type = Texture2DType;
  in[2].DefaultClass = 0;
  in[2].Name = L"VertexTexture";
  in[2].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"CustomMaterial2";
  cl->Label = L"CustomMaterial";
  cl->OutputType = CustomMtrlType;
  cl->TabType = Wz4MtrlType;
  cl->Command = CustomMtrlCmdCustomMaterial2;
  cl->MakeGui = CustomMtrlGuiCustomMaterial2;
  cl->SetDefaults = CustomMtrlDefCustomMaterial2;
  cl->BindPara = CustomMtrlBindCustomMaterial2;
  cl->Bind2Para = CustomMtrlBind2CustomMaterial2;
  cl->Bind3Para = CustomMtrlBind3CustomMaterial2;
  cl->WikiText = CustomMtrlWikiCustomMaterial2;
  cl->Actions = CustomMtrlActCustomMaterial2;
  cl->ParaWords = 59;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(3);
  in[0].Type = TextObjectType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = TextObjectType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = Texture2DType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0|wCIF_OPTIONAL;
  cl->ActionIds.AddMany(1)->Init(L"Shadercode",1);
  cl->ActionIds.AddMany(1)->Init(L"FlushShaders",2);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"CustomMaterial";
  cl->Label = L"CustomMaterial (old)";
  cl->OutputType = CustomMtrlType;
  cl->TabType = Wz4MtrlType;
  cl->Command = CustomMtrlCmdCustomMaterial;
  cl->MakeGui = CustomMtrlGuiCustomMaterial;
  cl->SetDefaults = CustomMtrlDefCustomMaterial;
  cl->BindPara = CustomMtrlBindCustomMaterial;
  cl->Bind2Para = CustomMtrlBind2CustomMaterial;
  cl->Bind3Para = CustomMtrlBind3CustomMaterial;
  cl->WikiText = CustomMtrlWikiCustomMaterial;
  cl->Actions = CustomMtrlActCustomMaterial;
  cl->ParaWords = 4;
  cl->Flags = 0x8040;
  in = cl->Inputs.AddMany(2);
  in[0].Type = TextObjectType;
  in[0].DefaultClass = 0;
  in[0].Name = L"VertexShader";
  in[0].Flags = 0|wCIF_METHODCHOOSE;
  in[1].Type = TextObjectType;
  in[1].DefaultClass = 0;
  in[1].Name = L"PixelShader";
  in[1].Flags = 0|wCIF_METHODCHOOSE;
  cl->ActionIds.AddMany(1)->Init(L"Shadercode",1);
  cl->ActionIds.AddMany(1)->Init(L"FlushShaders",2);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SimpleMtrlEnv";
  cl->Label = L"SimpleMtrlEnv";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdSimpleMtrlEnv;
  cl->MakeGui = Wz4RenderGuiSimpleMtrlEnv;
  cl->SetDefaults = Wz4RenderDefSimpleMtrlEnv;
  cl->BindPara = Wz4RenderBindSimpleMtrlEnv;
  cl->Bind2Para = Wz4RenderBind2SimpleMtrlEnv;
  cl->Bind3Para = Wz4RenderBind3SimpleMtrlEnv;
  cl->WikiText = Wz4RenderWikiSimpleMtrlEnv;
  cl->ParaStrings = 1;
  cl->ParaWords = 54;
  cl->Column = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_mtrl2_ops,0x110,AddOps_wz4_mtrl2_ops,0);


/****************************************************************************/


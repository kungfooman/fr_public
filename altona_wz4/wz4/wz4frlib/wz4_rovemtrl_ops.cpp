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
#include "wz4_rovemtrl_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class RoveMtrlType_ *RoveMtrlType;

/****************************************************************************/


/****************************************************************************/

sBool RoveMtrlCmdRoveMaterial(wExecutive *exe,wCommand *cmd)
{
  RoveMtrlParaRoveMaterial sUNUSED *para = (RoveMtrlParaRoveMaterial *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  RoveMtrl *out = (RoveMtrl *) cmd->Output;
  if(!out) { out=new RoveMtrl; cmd->Output=out; }

  {
#line 75 "wz4_rovemtrl_ops.ops"

    sInt extras = para->Extras;
    sInt detail = 0;
    switch(para->UVTrans)
    {
    case 0: extras |= 0x00; detail = 0; break;
    case 1: extras |= 0x10; detail = 0; break;
    case 2: extras |= 0x10; detail = 1; break;
    case 3: extras |= 0x10; detail = 2; break;
    case 4: extras |= 0x20; detail = 3; break;
    case 5: extras |= 0x30; detail = 3; break;
    case 6: extras |= 0x00; detail = 4; break;
    }

    out->SetMtrl(para->Flags,extras);
    out->DetailTexSpace = detail;
    out->SetTex(0,in0,para->Texture0);
    out->SetTex(1,in1,para->Texture1);

    sMatrix34 mat;
    sInt tflags[2] = { para->Texture0,para->Texture1 };
    for(sInt j=0;j<2;j++)
    {
      if(tflags[j]&0x10000)
      {
        mat.Scale(para->SimpleScale);
      }
      else if(tflags[j]&0x20000)
      {
        sSRT srt;
        srt.Rotate = para->Rot;
        srt.Translate = para->Trans;
        srt.Scale = para->Scale;
        srt.MakeMatrix(mat);
      }
      else
      {
        mat.Init();
      }
      out->TexTrans[j] = mat;
    }

    out->Prepare();
  ;
#line 80 "wz4_rovemtrl_ops.cpp"
    return 1;
  }
}

void RoveMtrlGuiRoveMaterial(wGridFrameHelper &gh,wOp *op)
{
  RoveMtrlParaRoveMaterial sUNUSED *para = (RoveMtrlParaRoveMaterial *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0zoff|zread|zwrite|zon:*4Doublesided|Singlesided|Inverted",gh.ChangeMsg);

  if((op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Texture0");
    gh.Flags(&para->Texture0,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white:*16-|scale|matrix",gh.ChangeMsg);

  }
  if((op->ConnectionMask & (1<<1))!=0)
  {
    gh.Label(L"Texture1");
    gh.Flags(&para->Texture1,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white:*16-|scale|matrix",gh.ChangeMsg);

  }
  gh.Label(L"Fog");
  gh.Flags(&para->Extras,L"off|on|black|clip3",gh.LayoutMsg);

  gh.Label(L"Clip Planes");
  gh.Flags(&para->Extras,L"*3off|on",gh.ChangeMsg);

  if((op->ConnectionMask & (1<<1))!=0)
  {
    gh.Label(L"Texture Op");
    gh.Flags(&para->Extras,L"*2add|mul",gh.ChangeMsg);

    gh.Flags(&para->UVTrans,L"uv|model|world|camera|envi-sphere|envi-reflect|from LightEnv",gh.ChangeMsg);

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
}

void RoveMtrlDefRoveMaterial(wOp *op)
{
  RoveMtrlParaRoveMaterial sUNUSED *para = (RoveMtrlParaRoveMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000013;
  para->SimpleScale = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void RoveMtrlBindRoveMaterial(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"simplescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
}
void RoveMtrlBind2RoveMaterial(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"texture0");
    name[2] = sPoolString(L"texture1");
    name[3] = sPoolString(L"fog");
    name[4] = sPoolString(L"extras");
    name[5] = sPoolString(L"extras");
    name[6] = sPoolString(L"uvtrans");
    name[7] = sPoolString(L"transforms");
    name[8] = sPoolString(L"simplescale");
    name[9] = sPoolString(L"scale");
    name[10] = sPoolString(L"rot");
    name[11] = sPoolString(L"trans");
  }
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[11],ScriptTypeFloat,3,cmd->Data+12);
}
void RoveMtrlBind3RoveMaterial(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import simplescale : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *RoveMtrlWikiRoveMaterial =
L"= RoveMtrl : RoveMaterial\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i RoveMaterial\n"
L"\n"
L"  !i Output Type\n"
L"  !i RoveMtrl\n"
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
L" !i \n"
L" !i \n"
L" !i from LightEnv\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4RenderCmdRoveMtrlEnv(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaRoveMtrlEnv sUNUSED *para = (Wz4RenderParaRoveMtrlEnv *)(cmd->Data); para;
  TextureCube sUNUSED *in0 = cmd->GetInput<TextureCube *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 215 "wz4_rovemtrl_ops.ops"

    RNRoveMtrlEnv *node = new RNRoveMtrlEnv;
    node->ParaBase = *para;
    node->LightCube = in0; if(in0) in0->AddRef();
    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 527 "wz4_rovemtrl_ops.cpp"
    return 1;
  }
}

void Wz4RenderHndRoveMtrlEnv(wPaintInfo &pi,wOp *op)
{
  Wz4RenderParaRoveMtrlEnv sUNUSED *para = (Wz4RenderParaRoveMtrlEnv *)(op->EditData); para;
#line 223 "wz4_rovemtrl_ops.ops"

    if((para->Color0 & 0xffffff) && para->Color0Amp) pi.Handle3D(op,0,para->Pos0,wHM_PLANE);
    if((para->Color1 & 0xffffff) && para->Color1Amp) pi.Handle3D(op,1,para->Pos1,wHM_PLANE);
    if((para->Color2 & 0xffffff) && para->Color2Amp) pi.Handle3D(op,2,para->Pos2,wHM_PLANE);
    if((para->Color3 & 0xffffff) && para->Color3Amp) pi.Handle3D(op,3,para->Pos3,wHM_PLANE);
  ;
#line 542 "wz4_rovemtrl_ops.cpp"
}

void Wz4RenderGuiRoveMtrlEnv(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaRoveMtrlEnv sUNUSED *para = (Wz4RenderParaRoveMtrlEnv *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"LightEnv");
  sIntControl *int_Index = gh.Int(&para->Index,0,15,0.125000f);
  int_Index->Default = 0x00000000; int_Index->RightStep = 0.125000f;

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Group(L"Lights");

  gh.Label(L"LightCubemap");
  gh.Flags(&op->Links[0].Select,L"input|link",gh.ConnectLayoutMsg);
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

  gh.Label(L"* Ambient");
  gh.ColorPick(&para->Ambient,L"rgba",0);

  gh.Label(L"* Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  sFloatControl *float_Color0Amp = gh.Float(&para->Color0Amp,-16.0000f,16.00000f,0.010000f);
  float_Color0Amp->Default = 1.000000f; float_Color0Amp->RightStep = 0.125000f;

  gh.Label(L"* Pos0");
  gh.BeginTied();
  sFloatControl *float_Pos0_0 = gh.Float(&para->Pos0.x,-65536.0f,65536.00f,0.001000f);
  float_Pos0_0->Default = 0.000000f; float_Pos0_0->RightStep = 0.125000f;
  sFloatControl *float_Pos0_1 = gh.Float(&para->Pos0.y,-65536.0f,65536.00f,0.001000f);
  float_Pos0_1->Default = 0.000000f; float_Pos0_1->RightStep = 0.125000f;
  sFloatControl *float_Pos0_2 = gh.Float(&para->Pos0.z,-65536.0f,65536.00f,0.001000f);
  float_Pos0_2->Default = 0.000000f; float_Pos0_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Range0");
  sFloatControl *float_Range0 = gh.Float(&para->Range0,0.000000f,65536.00f,0.001000f);
  float_Range0->Default = 0.000000f; float_Range0->RightStep = 0.125000f;

  gh.Flags(&para->LightType,L"-|Shadows",gh.ChangeMsg);

  gh.Label(L"* Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);

  sFloatControl *float_Color1Amp = gh.Float(&para->Color1Amp,-16.0000f,16.00000f,0.010000f);
  float_Color1Amp->Default = 1.000000f; float_Color1Amp->RightStep = 0.125000f;

  gh.Label(L"* Pos1");
  gh.BeginTied();
  sFloatControl *float_Pos1_0 = gh.Float(&para->Pos1.x,-65536.0f,65536.00f,0.001000f);
  float_Pos1_0->Default = 0.000000f; float_Pos1_0->RightStep = 0.125000f;
  sFloatControl *float_Pos1_1 = gh.Float(&para->Pos1.y,-65536.0f,65536.00f,0.001000f);
  float_Pos1_1->Default = 0.000000f; float_Pos1_1->RightStep = 0.125000f;
  sFloatControl *float_Pos1_2 = gh.Float(&para->Pos1.z,-65536.0f,65536.00f,0.001000f);
  float_Pos1_2->Default = 0.000000f; float_Pos1_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Range1");
  sFloatControl *float_Range1 = gh.Float(&para->Range1,0.000000f,65536.00f,0.001000f);
  float_Range1->Default = 0.000000f; float_Range1->RightStep = 0.125000f;

  gh.Label(L"* Color2");
  gh.ColorPick(&para->Color2,L"rgba",0);

  sFloatControl *float_Color2Amp = gh.Float(&para->Color2Amp,-16.0000f,16.00000f,0.010000f);
  float_Color2Amp->Default = 1.000000f; float_Color2Amp->RightStep = 0.125000f;

  gh.Label(L"* Pos2");
  gh.BeginTied();
  sFloatControl *float_Pos2_0 = gh.Float(&para->Pos2.x,-65536.0f,65536.00f,0.001000f);
  float_Pos2_0->Default = 0.000000f; float_Pos2_0->RightStep = 0.125000f;
  sFloatControl *float_Pos2_1 = gh.Float(&para->Pos2.y,-65536.0f,65536.00f,0.001000f);
  float_Pos2_1->Default = 0.000000f; float_Pos2_1->RightStep = 0.125000f;
  sFloatControl *float_Pos2_2 = gh.Float(&para->Pos2.z,-65536.0f,65536.00f,0.001000f);
  float_Pos2_2->Default = 0.000000f; float_Pos2_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Range2");
  sFloatControl *float_Range2 = gh.Float(&para->Range2,0.000000f,65536.00f,0.001000f);
  float_Range2->Default = 0.000000f; float_Range2->RightStep = 0.125000f;

  gh.Label(L"* Color3");
  gh.ColorPick(&para->Color3,L"rgba",0);

  sFloatControl *float_Color3Amp = gh.Float(&para->Color3Amp,-16.0000f,16.00000f,0.010000f);
  float_Color3Amp->Default = 1.000000f; float_Color3Amp->RightStep = 0.125000f;

  gh.Label(L"* Pos3");
  gh.BeginTied();
  sFloatControl *float_Pos3_0 = gh.Float(&para->Pos3.x,-65536.0f,65536.00f,0.001000f);
  float_Pos3_0->Default = 0.000000f; float_Pos3_0->RightStep = 0.125000f;
  sFloatControl *float_Pos3_1 = gh.Float(&para->Pos3.y,-65536.0f,65536.00f,0.001000f);
  float_Pos3_1->Default = 0.000000f; float_Pos3_1->RightStep = 0.125000f;
  sFloatControl *float_Pos3_2 = gh.Float(&para->Pos3.z,-65536.0f,65536.00f,0.001000f);
  float_Pos3_2->Default = 0.000000f; float_Pos3_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Range3");
  sFloatControl *float_Range3 = gh.Float(&para->Range3,0.000000f,65536.00f,0.001000f);
  float_Range3->Default = 0.000000f; float_Range3->RightStep = 0.125000f;

  gh.Group(L"Fog");

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

  gh.Group(L"Clip planes");

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
  gh.Group(L"Optional texture transform");

  gh.Label(L"* TexScale");
  gh.BeginTied();
  sFloatControl *float_TexScale_0 = gh.Float(&para->TexScale.x,-1024.00f,1024.000f,0.010000f);
  float_TexScale_0->Default = 1.000000f; float_TexScale_0->RightStep = 0.125000f;
  sFloatControl *float_TexScale_1 = gh.Float(&para->TexScale.y,-1024.00f,1024.000f,0.010000f);
  float_TexScale_1->Default = 1.000000f; float_TexScale_1->RightStep = 0.125000f;
  sFloatControl *float_TexScale_2 = gh.Float(&para->TexScale.z,-1024.00f,1024.000f,0.010000f);
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

void Wz4RenderDefRoveMtrlEnv(wOp *op)
{
  Wz4RenderParaRoveMtrlEnv sUNUSED *para = (Wz4RenderParaRoveMtrlEnv *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Ambient = 0xff000000;
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

void Wz4RenderBindRoveMtrlEnv(wCommand *cmd,ScriptContext *ctx)
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
  val->ColorPtr = ((sU32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"color0amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"pos0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"range0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"color1amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"pos1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"range1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"color2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"color2amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"pos2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"range2"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"color3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"color3amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"pos3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+27;
  ctx->BindLocal(ctx->AddSymbol(L"range3"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"fognear"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+29;
  ctx->BindLocal(ctx->AddSymbol(L"fogfar"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"fogcolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+32;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+35;
  ctx->BindLocal(ctx->AddSymbol(L"plane0dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+36;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+39;
  ctx->BindLocal(ctx->AddSymbol(L"plane1dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+40;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+43;
  ctx->BindLocal(ctx->AddSymbol(L"plane2dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+44;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+44;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+44;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+47;
  ctx->BindLocal(ctx->AddSymbol(L"plane3dist"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"texscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"texscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+48;
  ctx->BindLocal(ctx->AddSymbol(L"texscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"texrot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"texrot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+51;
  ctx->BindLocal(ctx->AddSymbol(L"texrot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"textrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"textrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+54;
  ctx->BindLocal(ctx->AddSymbol(L"textrans"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2RoveMtrlEnv(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[43];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightenv");
    name[1] = sPoolString(L"renderpass");
    name[2] = sPoolString(L"lights");
    name[3] = sPoolString(L"lightcubemap");
    name[4] = sPoolString(L"ambient");
    name[5] = sPoolString(L"color0");
    name[6] = sPoolString(L"color0amp");
    name[7] = sPoolString(L"pos0");
    name[8] = sPoolString(L"range0");
    name[9] = sPoolString(L"lighttype");
    name[10] = sPoolString(L"color1");
    name[11] = sPoolString(L"color1amp");
    name[12] = sPoolString(L"pos1");
    name[13] = sPoolString(L"range1");
    name[14] = sPoolString(L"color2");
    name[15] = sPoolString(L"color2amp");
    name[16] = sPoolString(L"pos2");
    name[17] = sPoolString(L"range2");
    name[18] = sPoolString(L"color3");
    name[19] = sPoolString(L"color3amp");
    name[20] = sPoolString(L"pos3");
    name[21] = sPoolString(L"range3");
    name[22] = sPoolString(L"fog");
    name[23] = sPoolString(L"fognear");
    name[24] = sPoolString(L"fogfar");
    name[25] = sPoolString(L"fogcolor");
    name[26] = sPoolString(L"fogclip3");
    name[27] = sPoolString(L"");
    name[28] = sPoolString(L"clipplanes");
    name[29] = sPoolString(L"plane0dir");
    name[30] = sPoolString(L"plane0dist");
    name[31] = sPoolString(L"plane1dir");
    name[32] = sPoolString(L"plane1dist");
    name[33] = sPoolString(L"plane2dir");
    name[34] = sPoolString(L"plane2dist");
    name[35] = sPoolString(L"plane3dir");
    name[36] = sPoolString(L"plane3dist");
    name[37] = sPoolString(L"");
    name[38] = sPoolString(L"texscale");
    name[39] = sPoolString(L"texrot");
    name[40] = sPoolString(L"textrans");
    name[41] = sPoolString(L"");
    name[42] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[5],ScriptTypeColor,1,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[10],ScriptTypeColor,1,cmd->Data+10);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[12],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[14],ScriptTypeColor,1,cmd->Data+16);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[16],ScriptTypeFloat,3,cmd->Data+18);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[18],ScriptTypeColor,1,cmd->Data+22);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+23);
  ctx->AddImport(name[20],ScriptTypeFloat,3,cmd->Data+24);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+27);
  ctx->AddImport(name[23],ScriptTypeFloat,1,cmd->Data+28);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+29);
  ctx->AddImport(name[25],ScriptTypeColor,1,cmd->Data+30);
  ctx->AddImport(name[29],ScriptTypeFloat,3,cmd->Data+32);
  ctx->AddImport(name[30],ScriptTypeFloat,1,cmd->Data+35);
  ctx->AddImport(name[31],ScriptTypeFloat,3,cmd->Data+36);
  ctx->AddImport(name[32],ScriptTypeFloat,1,cmd->Data+39);
  ctx->AddImport(name[33],ScriptTypeFloat,3,cmd->Data+40);
  ctx->AddImport(name[34],ScriptTypeFloat,1,cmd->Data+43);
  ctx->AddImport(name[35],ScriptTypeFloat,3,cmd->Data+44);
  ctx->AddImport(name[36],ScriptTypeFloat,1,cmd->Data+47);
  ctx->AddImport(name[38],ScriptTypeFloat,3,cmd->Data+48);
  ctx->AddImport(name[39],ScriptTypeFloat,3,cmd->Data+51);
  ctx->AddImport(name[40],ScriptTypeFloat,3,cmd->Data+54);
  ctx->AddImport(name[42],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3RoveMtrlEnv(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import ambient : color;\n");
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color0amp : float;\n");
  tb.PrintF(L"  import pos0 : float[3];\n");
  tb.PrintF(L"  import range0 : float;\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import color1amp : float;\n");
  tb.PrintF(L"  import pos1 : float[3];\n");
  tb.PrintF(L"  import range1 : float;\n");
  tb.PrintF(L"  import color2 : color;\n");
  tb.PrintF(L"  import color2amp : float;\n");
  tb.PrintF(L"  import pos2 : float[3];\n");
  tb.PrintF(L"  import range2 : float;\n");
  tb.PrintF(L"  import color3 : color;\n");
  tb.PrintF(L"  import color3amp : float;\n");
  tb.PrintF(L"  import pos3 : float[3];\n");
  tb.PrintF(L"  import range3 : float;\n");
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
const sChar *Wz4RenderWikiRoveMtrlEnv =
L"= Wz4Render : RoveMtrlEnv\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i RoveMtrlEnv\n"
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
L" !i TextureCube\n"
L" !i optional link LightCubemap\n"
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
L" !i LightCubemap\n"
L" !i LightCubemap\n"
L" !i link\n"
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
L" !i Pos0\n"
L" !i Pos0\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range0\n"
L" !i Range0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i LightType\n"
L" !i Shadows\n"
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
L" !i Pos1\n"
L" !i Pos1\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range1\n"
L" !i Range1\n"
L" !i float\n"
L" !i *\n"
L"\n"
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
L" !i Pos2\n"
L" !i Pos2\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range2\n"
L" !i Range2\n"
L" !i float\n"
L" !i *\n"
L"\n"
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
L" !i Pos3\n"
L" !i Pos3\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Range3\n"
L" !i Range3\n"
L" !i float\n"
L" !i *\n"
L"\n"
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

void RoveMtrlAnimRoveMaterial::Init(class ScriptContext *sc)
{
};

void RoveMtrlAnimRoveMaterial::Bind(class ScriptContext *sc,RoveMtrlParaRoveMaterial *para)
{
};

void Wz4RenderAnimRoveMtrlEnv::Init(class ScriptContext *sc)
{
  _Ambient = sc->AddSymbol(L"ambient");
  _Color0 = sc->AddSymbol(L"color0");
  _Color0Amp = sc->AddSymbol(L"color0amp");
  _Pos0 = sc->AddSymbol(L"pos0");
  _Range0 = sc->AddSymbol(L"range0");
  _Color1 = sc->AddSymbol(L"color1");
  _Color1Amp = sc->AddSymbol(L"color1amp");
  _Pos1 = sc->AddSymbol(L"pos1");
  _Range1 = sc->AddSymbol(L"range1");
  _Color2 = sc->AddSymbol(L"color2");
  _Color2Amp = sc->AddSymbol(L"color2amp");
  _Pos2 = sc->AddSymbol(L"pos2");
  _Range2 = sc->AddSymbol(L"range2");
  _Color3 = sc->AddSymbol(L"color3");
  _Color3Amp = sc->AddSymbol(L"color3amp");
  _Pos3 = sc->AddSymbol(L"pos3");
  _Range3 = sc->AddSymbol(L"range3");
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

void Wz4RenderAnimRoveMtrlEnv::Bind(class ScriptContext *sc,Wz4RenderParaRoveMtrlEnv *para)
{
  sc->BindLocalColor(_Ambient,&para->Ambient);
  sc->BindLocalColor(_Color0,&para->Color0);
  sc->BindLocalFloat(_Color0Amp,1,&para->Color0Amp);
  sc->BindLocalFloat(_Pos0,3,&para->Pos0.x);
  sc->BindLocalFloat(_Range0,1,&para->Range0);
  sc->BindLocalColor(_Color1,&para->Color1);
  sc->BindLocalFloat(_Color1Amp,1,&para->Color1Amp);
  sc->BindLocalFloat(_Pos1,3,&para->Pos1.x);
  sc->BindLocalFloat(_Range1,1,&para->Range1);
  sc->BindLocalColor(_Color2,&para->Color2);
  sc->BindLocalFloat(_Color2Amp,1,&para->Color2Amp);
  sc->BindLocalFloat(_Pos2,3,&para->Pos2.x);
  sc->BindLocalFloat(_Range2,1,&para->Range2);
  sc->BindLocalColor(_Color3,&para->Color3);
  sc->BindLocalFloat(_Color3Amp,1,&para->Color3Amp);
  sc->BindLocalFloat(_Pos3,3,&para->Pos3.x);
  sc->BindLocalFloat(_Range3,1,&para->Range3);
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

void AddTypes_wz4_rovemtrl_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(RoveMtrlType = new RoveMtrlType_);
  RoveMtrlType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_rovemtrl_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"RoveMaterial";
  cl->Label = L"RoveMaterial";
  cl->OutputType = RoveMtrlType;
  cl->TabType = Wz4MtrlType;
  cl->Command = RoveMtrlCmdRoveMaterial;
  cl->MakeGui = RoveMtrlGuiRoveMaterial;
  cl->SetDefaults = RoveMtrlDefRoveMaterial;
  cl->BindPara = RoveMtrlBindRoveMaterial;
  cl->Bind2Para = RoveMtrlBind2RoveMaterial;
  cl->Bind3Para = RoveMtrlBind3RoveMaterial;
  cl->WikiText = RoveMtrlWikiRoveMaterial;
  cl->ParaWords = 15;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"RoveMtrlEnv";
  cl->Label = L"RoveMtrlEnv";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = Wz4RenderCmdRoveMtrlEnv;
  cl->MakeGui = Wz4RenderGuiRoveMtrlEnv;
  cl->SetDefaults = Wz4RenderDefRoveMtrlEnv;
  cl->BindPara = Wz4RenderBindRoveMtrlEnv;
  cl->Bind2Para = Wz4RenderBind2RoveMtrlEnv;
  cl->Bind3Para = Wz4RenderBind3RoveMtrlEnv;
  cl->WikiText = Wz4RenderWikiRoveMtrlEnv;
  cl->Handles = Wz4RenderHndRoveMtrlEnv;
  cl->ParaStrings = 1;
  cl->ParaWords = 57;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = TextureCubeType;
  in[0].DefaultClass = 0;
  in[0].Name = L"LightCubemap";
  in[0].Flags = 0|wCIF_OPTIONAL|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_rovemtrl_ops,0x110,AddOps_wz4_rovemtrl_ops,0);


/****************************************************************************/


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
#include "easter_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 13 "easter_ops.ops"

#include "wz4frlib/easter.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4lib/script.hpp" 

#line 30 "easter_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4RenderCmdCubeTrees(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaCubeTrees sUNUSED *para = (Wz4RenderParaCubeTrees *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 64 "easter_ops.ops"

    RNCubeTrees *node = new RNCubeTrees();
    node->ParaBase = node->Para = *para;
    node->TreeMtrl = in0; sAddRef(in0);
    node->CubeMtrl = in1; sAddRef(in1);

    node->Array.Resize(cmd->ArrayCount);
    Wz4RenderArrayCubeTrees *array= (Wz4RenderArrayCubeTrees *)cmd->Array;
    for(sInt i=0;i<cmd->ArrayCount;i++)
      node->Array[i] = array[i];

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 61 "easter_ops.cpp"
    return 1;
  }
}

void Wz4RenderArrCubeTrees(wOp *op,sInt pos,void *mem)
{
  Wz4RenderParaCubeTrees sUNUSED *para = (Wz4RenderParaCubeTrees *)(op->EditData); para;
  Wz4RenderArrayCubeTrees *e = (Wz4RenderArrayCubeTrees *)(mem);
  e->Pos.x = 0.000000f;
  e->Pos.y = 0.000000f;
  e->Pos.z = 0.000000f;
  e->Rot = 0.000000f;
  e->Seed = 0x00000000;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4RenderArrayCubeTrees *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4RenderArrayCubeTrees *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4RenderArrayCubeTrees *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4RenderArrayCubeTrees *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4RenderArrayCubeTrees *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4RenderArrayCubeTrees *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4RenderArrayCubeTrees *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4RenderArrayCubeTrees *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4RenderArrayCubeTrees *)op->ArrayData[pos  ];
    }
    e->Pos.x = f0*p0->Pos.x + f1*p1->Pos.x;
    e->Pos.y = f0*p0->Pos.y + f1*p1->Pos.y;
    e->Pos.z = f0*p0->Pos.z + f1*p1->Pos.z;
    e->Rot = f0*p0->Rot + f1*p1->Rot;
  }
}

void Wz4RenderGuiCubeTrees(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaCubeTrees sUNUSED *para = (Wz4RenderParaCubeTrees *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* LightEnv");
  sIntControl *int_LightEnv = gh.Int(&para->LightEnv,0,15,0.125000f);
  int_LightEnv->Default = 0x00000000; int_LightEnv->RightStep = 0.125000f;

  gh.Group(L"Materials");

  gh.Label(L"TreeMaterial");
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

  gh.Label(L"CubeMaterial");
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

  gh.Group(L"Tree");

  gh.Label(L"* StartWidth");
  sFloatControl *float_StartWidth = gh.Float(&para->StartWidth,0.010000f,1.000000f,0.010000f);
  float_StartWidth->Default = 0.200000f; float_StartWidth->RightStep = 0.125000f;

  gh.Label(L"* GrowSpeed");
  sFloatControl *float_GrowSpeed = gh.Float(&para->GrowSpeed,0.100000f,10.00000f,0.010000f);
  float_GrowSpeed->Default = 1.000000f; float_GrowSpeed->RightStep = 0.125000f;

  gh.Label(L"* SegmentLength");
  sFloatControl *float_SegmentLength = gh.Float(&para->SegmentLength,0.010000f,2.000000f,0.010000f);
  float_SegmentLength->Default = 0.300000f; float_SegmentLength->RightStep = 0.125000f;

  gh.Label(L"* WidthDecay");
  sFloatControl *float_WidthDecay = gh.Float(&para->WidthDecay,0.100000f,1.000000f,0.010000f);
  float_WidthDecay->Default = 0.500000f; float_WidthDecay->RightStep = 0.125000f;

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Label(L"* MinWidth");
  sFloatControl *float_MinWidth = gh.Float(&para->MinWidth,0.010000f,1.000000f,0.010000f);
  float_MinWidth->Default = 0.020000f; float_MinWidth->RightStep = 0.125000f;

  gh.Label(L"* Bend");
  sFloatControl *float_Bend = gh.Float(&para->Bend,0.010000f,5.000000f,0.010000f);
  float_Bend->Default = 0.100000f; float_Bend->RightStep = 0.125000f;

  gh.Group(L"Cubes");

  gh.Label(L"* CubeSize");
  sFloatControl *float_CubeSize = gh.Float(&para->CubeSize,0.010000f,1.000000f,0.010000f);
  float_CubeSize->Default = 0.200000f; float_CubeSize->RightStep = 0.125000f;

  gh.Label(L"* CubeGrowTime");
  sFloatControl *float_CubeGrowTime = gh.Float(&para->CubeGrowTime,0.010000f,100.0000f,0.010000f);
  float_CubeGrowTime->Default = 1.000000f; float_CubeGrowTime->RightStep = 0.125000f;

  gh.Label(L"* CubeWobbleTime");
  sFloatControl *float_CubeWobbleTime = gh.Float(&para->CubeWobbleTime,0.010000f,10.00000f,0.010000f);
  float_CubeWobbleTime->Default = 3.000000f; float_CubeWobbleTime->RightStep = 0.125000f;

  gh.Label(L"* CubeRot");
  gh.BeginTied();
  sFloatControl *float_CubeRot_0 = gh.Float(&para->CubeRot.x,-1.00000f,1.000000f,0.010000f);
  float_CubeRot_0->Default = -0.090000f; float_CubeRot_0->RightStep = 0.125000f;
  sFloatControl *float_CubeRot_1 = gh.Float(&para->CubeRot.y,-1.00000f,1.000000f,0.010000f);
  float_CubeRot_1->Default = 0.210000f; float_CubeRot_1->RightStep = 0.125000f;
  sFloatControl *float_CubeRot_2 = gh.Float(&para->CubeRot.z,-1.00000f,1.000000f,0.010000f);
  float_CubeRot_2->Default = 0.270000f; float_CubeRot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Multiple");

  gh.Label(L"* SpawnDelay");
  sFloatControl *float_SpawnDelay = gh.Float(&para->SpawnDelay,0.000000f,1000.000f,0.100000f);
  float_SpawnDelay->Default = 1.000000f; float_SpawnDelay->RightStep = 0.125000f;

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
  gh.Grid->AddLabel(L"Rot",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Seed",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4RenderArrayCubeTrees *elem = (Wz4RenderArrayCubeTrees *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&elem->Pos.x,0.000000f,255.0000f,0.125000f);
    float_Pos_0->Default = 0.000000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&elem->Pos.y,0.000000f,255.0000f,0.125000f);
    float_Pos_1->Default = 0.000000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&elem->Pos.z,0.000000f,255.0000f,0.125000f);
    float_Pos_2->Default = 0.000000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Rot = gh.Float(&elem->Rot,-0.500000f,0.500000f,0.010000f);
    float_Rot->Default = 0.000000f; float_Rot->RightStep = 0.125000f;

    sIntControl *int_Seed = gh.Int(&elem->Seed,0,255,0.125000f);
    int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;
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

void Wz4RenderDefCubeTrees(wOp *op)
{
  Wz4RenderParaCubeTrees sUNUSED *para = (Wz4RenderParaCubeTrees *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->StartWidth = 0.200000f;
  para->GrowSpeed = 1.000000f;
  para->SegmentLength = 0.300000f;
  para->WidthDecay = 0.500000f;
  para->Seed = 0x00000001;
  para->MinWidth = 0.020000f;
  para->Bend = 0.100000f;
  para->CubeSize = 0.200000f;
  para->CubeGrowTime = 1.000000f;
  para->CubeWobbleTime = 3.000000f;
  para->CubeRot.x = -0.090000f;
  para->CubeRot.y = 0.210000f;
  para->CubeRot.z = 0.270000f;
  para->SpawnDelay = 1.000000f;
}

void Wz4RenderBindCubeTrees(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"lightenv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"startwidth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"growspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"segmentlength"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"widthdecay"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"minwidth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"bend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"cubesize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"cubegrowtime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"cubewobbletime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"cuberot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"cuberot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"cuberot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"spawndelay"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2CubeTrees(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[22];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"lightenv");
    name[2] = sPoolString(L"materials");
    name[3] = sPoolString(L"treematerial");
    name[4] = sPoolString(L"cubematerial");
    name[5] = sPoolString(L"tree");
    name[6] = sPoolString(L"startwidth");
    name[7] = sPoolString(L"growspeed");
    name[8] = sPoolString(L"segmentlength");
    name[9] = sPoolString(L"widthdecay");
    name[10] = sPoolString(L"seed");
    name[11] = sPoolString(L"minwidth");
    name[12] = sPoolString(L"bend");
    name[13] = sPoolString(L"cubes");
    name[14] = sPoolString(L"cubesize");
    name[15] = sPoolString(L"cubegrowtime");
    name[16] = sPoolString(L"cubewobbletime");
    name[17] = sPoolString(L"cuberot");
    name[18] = sPoolString(L"multiple");
    name[19] = sPoolString(L"spawndelay");
    name[20] = sPoolString(L"");
    name[21] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[10],ScriptTypeInt,1,cmd->Data+6);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[17],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[21],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3CubeTrees(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import lightenv : int;\n");
  tb.PrintF(L"  import startwidth : float;\n");
  tb.PrintF(L"  import growspeed : float;\n");
  tb.PrintF(L"  import segmentlength : float;\n");
  tb.PrintF(L"  import widthdecay : float;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import minwidth : float;\n");
  tb.PrintF(L"  import bend : float;\n");
  tb.PrintF(L"  import cubesize : float;\n");
  tb.PrintF(L"  import cubegrowtime : float;\n");
  tb.PrintF(L"  import cubewobbletime : float;\n");
  tb.PrintF(L"  import cuberot : float[3];\n");
  tb.PrintF(L"  import spawndelay : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiCubeTrees =
L"= Wz4Render : CubeTrees\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CubeTrees\n"
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
L" !i link TreeMaterial\n"
L" !i *\n"
L"\n"
L" !i Wz4Mtrl\n"
L" !i optional link CubeMaterial\n"
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
L" !i TreeMaterial\n"
L" !i TreeMaterial\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i CubeMaterial\n"
L" !i CubeMaterial\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i StartWidth\n"
L" !i StartWidth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GrowSpeed\n"
L" !i GrowSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SegmentLength\n"
L" !i SegmentLength\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WidthDecay\n"
L" !i WidthDecay\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MinWidth\n"
L" !i MinWidth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Bend\n"
L" !i Bend\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeSize\n"
L" !i CubeSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeGrowTime\n"
L" !i CubeGrowTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeWobbleTime\n"
L" !i CubeWobbleTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeRot\n"
L" !i CubeRot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i SpawnDelay\n"
L" !i SpawnDelay\n"
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
L" !i TreeMaterial\n"
L" !i TreeMaterial\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i CubeMaterial\n"
L" !i CubeMaterial\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i StartWidth\n"
L" !i StartWidth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GrowSpeed\n"
L" !i GrowSpeed\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i SegmentLength\n"
L" !i SegmentLength\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WidthDecay\n"
L" !i WidthDecay\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MinWidth\n"
L" !i MinWidth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Bend\n"
L" !i Bend\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeSize\n"
L" !i CubeSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeGrowTime\n"
L" !i CubeGrowTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeWobbleTime\n"
L" !i CubeWobbleTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CubeRot\n"
L" !i CubeRot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i SpawnDelay\n"
L" !i SpawnDelay\n"
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

sBool Wz4RenderCmdTVNoise(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaTVNoise sUNUSED *para = (Wz4RenderParaTVNoise *)(cmd->Data); para;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 99 "easter_ops.ops"

    RNTVNoise *node = new RNTVNoise();
    node->ParaBase = node->Para = *para;

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);
  ;
#line 667 "easter_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiTVNoise(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaTVNoise sUNUSED *para = (Wz4RenderParaTVNoise *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* Alpha");
  sFloatControl *float_Alpha = gh.Float(&para->Alpha,0.000000f,1.000000f,0.010000f);
  float_Alpha->Default = 1.000000f; float_Alpha->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefTVNoise(wOp *op)
{
  Wz4RenderParaTVNoise sUNUSED *para = (Wz4RenderParaTVNoise *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Alpha = 1.000000f;
}

void Wz4RenderBindTVNoise(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"alpha"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2TVNoise(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"alpha");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3TVNoise(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import alpha : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiTVNoise =
L"= Wz4Render : TVNoise\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TVNoise\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Alpha\n"
L" !i Alpha\n"
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

sBool Wz4RenderCmdJulia4D(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaJulia4D sUNUSED *para = (Wz4RenderParaJulia4D *)(cmd->Data); para;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 128 "easter_ops.ops"

    RNJulia4D *node = new RNJulia4D;
    node->ParaBase = node->Para = *para;

    out->RootNode = node;
    out->AddCode(cmd,para->Renderpass);    
  ;
#line 800 "easter_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiJulia4D(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaJulia4D sUNUSED *para = (Wz4RenderParaJulia4D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Renderpass");
  sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
  int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  gh.Label(L"* C");
  gh.BeginTied();
  sFloatControl *float_C_0 = gh.Float(&para->C.x,-2.00000f,2.000000f,0.010000f);
  float_C_0->Default = 0.000000f; float_C_0->RightStep = 0.125000f;
  sFloatControl *float_C_1 = gh.Float(&para->C.y,-2.00000f,2.000000f,0.010000f);
  float_C_1->Default = 0.000000f; float_C_1->RightStep = 0.125000f;
  sFloatControl *float_C_2 = gh.Float(&para->C.z,-2.00000f,2.000000f,0.010000f);
  float_C_2->Default = 0.000000f; float_C_2->RightStep = 0.125000f;
  sFloatControl *float_C_3 = gh.Float(&para->C.w,-2.00000f,2.000000f,0.010000f);
  float_C_3->Default = 0.000000f; float_C_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.Flags(&para->Flags,L"-|x2",gh.ChangeMsg);

  gh.Label(L"Specular");
  gh.ColorPick(&para->Specular,L"rgb",0);

  sFloatControl *float_Power = gh.Float(&para->Power,1.000000f,100.0000f,0.100000f);
  float_Power->Default = 8.000000f; float_Power->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefJulia4D(wOp *op)
{
  Wz4RenderParaJulia4D sUNUSED *para = (Wz4RenderParaJulia4D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0x00ffffff;
  para->Specular = 0x00ffffff;
  para->Power = 8.000000f;
}

void Wz4RenderBindJulia4D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"c"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"c"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"c"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"c"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"specular"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"power"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Julia4D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"c");
    name[2] = sPoolString(L"color_");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"specular");
    name[5] = sPoolString(L"power");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,4,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[7],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Julia4D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import c : float[4];\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import specular : color;\n");
  tb.PrintF(L"  import power : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiJulia4D =
L"= Wz4Render : Julia4D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Julia4D\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i C\n"
L" !i C\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Flags\n"
L" !i x2\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Specular\n"
L" !i Specular\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Power\n"
L" !i Power\n"
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

void Wz4RenderAnimCubeTrees::Init(class ScriptContext *sc)
{
  _LightEnv = sc->AddSymbol(L"lightenv");
  _StartWidth = sc->AddSymbol(L"startwidth");
  _GrowSpeed = sc->AddSymbol(L"growspeed");
  _SegmentLength = sc->AddSymbol(L"segmentlength");
  _WidthDecay = sc->AddSymbol(L"widthdecay");
  _MinWidth = sc->AddSymbol(L"minwidth");
  _Bend = sc->AddSymbol(L"bend");
  _CubeSize = sc->AddSymbol(L"cubesize");
  _CubeGrowTime = sc->AddSymbol(L"cubegrowtime");
  _CubeWobbleTime = sc->AddSymbol(L"cubewobbletime");
  _CubeRot = sc->AddSymbol(L"cuberot");
  _SpawnDelay = sc->AddSymbol(L"spawndelay");
};

void Wz4RenderAnimCubeTrees::Bind(class ScriptContext *sc,Wz4RenderParaCubeTrees *para)
{
  sc->BindLocalInt(_LightEnv,1,&para->LightEnv);
  sc->BindLocalFloat(_StartWidth,1,&para->StartWidth);
  sc->BindLocalFloat(_GrowSpeed,1,&para->GrowSpeed);
  sc->BindLocalFloat(_SegmentLength,1,&para->SegmentLength);
  sc->BindLocalFloat(_WidthDecay,1,&para->WidthDecay);
  sc->BindLocalFloat(_MinWidth,1,&para->MinWidth);
  sc->BindLocalFloat(_Bend,1,&para->Bend);
  sc->BindLocalFloat(_CubeSize,1,&para->CubeSize);
  sc->BindLocalFloat(_CubeGrowTime,1,&para->CubeGrowTime);
  sc->BindLocalFloat(_CubeWobbleTime,1,&para->CubeWobbleTime);
  sc->BindLocalFloat(_CubeRot,3,&para->CubeRot.x);
  sc->BindLocalFloat(_SpawnDelay,1,&para->SpawnDelay);
};

void Wz4RenderAnimTVNoise::Init(class ScriptContext *sc)
{
  _Alpha = sc->AddSymbol(L"alpha");
};

void Wz4RenderAnimTVNoise::Bind(class ScriptContext *sc,Wz4RenderParaTVNoise *para)
{
  sc->BindLocalFloat(_Alpha,1,&para->Alpha);
};

void Wz4RenderAnimJulia4D::Init(class ScriptContext *sc)
{
  _C = sc->AddSymbol(L"c");
};

void Wz4RenderAnimJulia4D::Bind(class ScriptContext *sc,Wz4RenderParaJulia4D *para)
{
  sc->BindLocalFloat(_C,4,&para->C.x);
};


/****************************************************************************/

void AddTypes_easter_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_easter_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"CubeTrees";
  cl->Label = L"Easter_CubeTrees";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdCubeTrees;
  cl->MakeGui = Wz4RenderGuiCubeTrees;
  cl->SetDefaults = Wz4RenderDefCubeTrees;
  cl->BindPara = Wz4RenderBindCubeTrees;
  cl->Bind2Para = Wz4RenderBind2CubeTrees;
  cl->Bind3Para = Wz4RenderBind3CubeTrees;
  cl->WikiText = Wz4RenderWikiCubeTrees;
  cl->SetDefaultsArray = Wz4RenderArrCubeTrees;
  cl->ArrayCount = 5;
  cl->ParaStrings = 1;
  cl->ParaWords = 16;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Name = L"TreeMaterial";
  in[0].Flags = 0|wCIF_METHODBOTH;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Name = L"CubeMaterial";
  in[1].Flags = 0|wCIF_OPTIONAL|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TVNoise";
  cl->Label = L"Easter_TVNoise";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdTVNoise;
  cl->MakeGui = Wz4RenderGuiTVNoise;
  cl->SetDefaults = Wz4RenderDefTVNoise;
  cl->BindPara = Wz4RenderBindTVNoise;
  cl->Bind2Para = Wz4RenderBind2TVNoise;
  cl->Bind3Para = Wz4RenderBind3TVNoise;
  cl->WikiText = Wz4RenderWikiTVNoise;
  cl->ParaStrings = 1;
  cl->ParaWords = 2;
  cl->Column = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Julia4D";
  cl->Label = L"Easter_Julia4D";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdJulia4D;
  cl->MakeGui = Wz4RenderGuiJulia4D;
  cl->SetDefaults = Wz4RenderDefJulia4D;
  cl->BindPara = Wz4RenderBindJulia4D;
  cl->Bind2Para = Wz4RenderBind2Julia4D;
  cl->Bind3Para = Wz4RenderBind3Julia4D;
  cl->WikiText = Wz4RenderWikiJulia4D;
  cl->ParaStrings = 1;
  cl->ParaWords = 9;
  cl->Column = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(easter_ops,0x110,AddOps_easter_ops,0);


/****************************************************************************/


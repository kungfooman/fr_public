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
#include "wz4_anim_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4ChannelType_ *Wz4ChannelType;
class Wz4SkeletonType_ *Wz4SkeletonType;

/****************************************************************************/

#line 26 "wz4_anim_ops.ops"
void Wz4SkeletonType_::BeginEngine(wPaintInfo &pi,sBool clear)
{
#line 27 "wz4_anim_ops.ops"

    sSetTarget(sTargetPara(clear ? sST_CLEARALL : 0,pi.BackColor,pi.Spec));
    pi.View->SetTargetCurrent();
    pi.View->SetZoom(pi.Zoom3D);
    pi.View->Prepare();
  ;
#line 34 "wz4_anim_ops.cpp"
}
#line 34 "wz4_anim_ops.ops"
void Wz4SkeletonType_::Wireframe(wObject *obj,wPaintInfo &pi,sMatrix34 &mat_)
{
#line 35 "wz4_anim_ops.ops"

    sVertexBasic *vp;
    sVector30 a,b,c;
    Wz4Skeleton *skel = (Wz4Skeleton *)obj;

    sInt count = skel->Joints.GetCount();
    if(count>0)
    {
      sF32 time = (sGetTime()%10000)/10000.0f;
      sMatrix34 *mat = sALLOCSTACK(sMatrix34,count);
      skel->Evaluate(time,mat);

      sCBuffer<sSimpleMaterialPara> cb;
      cb.Data->Set(*pi.View);
      pi.FlatMtrl->Set(&cb);
      pi.LineGeo->BeginLoadVB(count*8,sGD_STREAM,(void **)&vp);
      for(sInt i=0;i<count;i++)
      {
        sInt j=skel->Joints[i].Parent;
        if(j==-1) j=i;

        a = mat[i].i * 0.125f;
        b = mat[i].j * 0.125f;
        c = mat[i].k * 0.125f;

        vp[0].Init(mat[i].l+a,~0);
        vp[1].Init(mat[i].l-a,~0);
        vp[2].Init(mat[i].l+b,~0);
        vp[3].Init(mat[i].l-b,~0);
        vp[4].Init(mat[i].l+c,~0);
        vp[5].Init(mat[i].l-c,~0);
        vp[6].Init(mat[i].l,0xffffff00);
        vp[7].Init(mat[j].l,0xffffff00);
        vp+=8;
      }
      pi.LineGeo->EndLoadVB();
      pi.LineGeo->Draw();
    }
  ;
#line 79 "wz4_anim_ops.cpp"
}

/****************************************************************************/

sBool Wz4SkeletonCmdBoneChain(wExecutive *exe,wCommand *cmd)
{
  Wz4SkeletonParaBoneChain sUNUSED *para = (Wz4SkeletonParaBoneChain *)(cmd->Data); para;
  Wz4Skeleton *out = (Wz4Skeleton *) cmd->Output;
  if(!out) { out=new Wz4Skeleton; cmd->Output=out; }

  {
#line 86 "wz4_anim_ops.ops"

    Wz4AnimJoint *j;
    Wz4ChannelConstant *ch;
    out->Joints.AddMany(para->Count);
    sFORALL(out->Joints,j)
    {
      sF32 f = sF32(_i)/(para->Count-1);
      ch = new Wz4ChannelConstant;
      ch->Start.Trans.Fade(f,para->Start,para->End);

      j->Init();
      j->Channel = ch;
    }
    return 1;
  ;
#line 107 "wz4_anim_ops.cpp"
    return 1;
  }
}

void Wz4SkeletonGuiBoneChain(wGridFrameHelper &gh,wOp *op)
{
  Wz4SkeletonParaBoneChain sUNUSED *para = (Wz4SkeletonParaBoneChain *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Start");
  gh.BeginTied();
  sFloatControl *float_Start_0 = gh.Float(&para->Start.x,-1024.00f,1024.000f,0.010000f);
  float_Start_0->Default = 0.000000f; float_Start_0->RightStep = 0.125000f;
  sFloatControl *float_Start_1 = gh.Float(&para->Start.y,-1024.00f,1024.000f,0.010000f);
  float_Start_1->Default = 0.000000f; float_Start_1->RightStep = 0.125000f;
  sFloatControl *float_Start_2 = gh.Float(&para->Start.z,-1024.00f,1024.000f,0.010000f);
  float_Start_2->Default = 0.000000f; float_Start_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"End");
  gh.BeginTied();
  sFloatControl *float_End_0 = gh.Float(&para->End.x,-1024.00f,1024.000f,0.010000f);
  float_End_0->Default = 0.000000f; float_End_0->RightStep = 0.125000f;
  sFloatControl *float_End_1 = gh.Float(&para->End.y,-1024.00f,1024.000f,0.010000f);
  float_End_1->Default = 0.000000f; float_End_1->RightStep = 0.125000f;
  sFloatControl *float_End_2 = gh.Float(&para->End.z,-1024.00f,1024.000f,0.010000f);
  float_End_2->Default = 0.000000f; float_End_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,2,16,0.125000f);
  int_Count->Default = 0x00000005; int_Count->RightStep = 0.125000f;
}

void Wz4SkeletonDefBoneChain(wOp *op)
{
  Wz4SkeletonParaBoneChain sUNUSED *para = (Wz4SkeletonParaBoneChain *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000005;
}

void Wz4SkeletonBindBoneChain(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"end"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"end"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"end"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
}
void Wz4SkeletonBind2BoneChain(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"start");
    name[1] = sPoolString(L"end");
    name[2] = sPoolString(L"count");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+6);
}
void Wz4SkeletonBind3BoneChain(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import start : float[3];\n");
  tb.PrintF(L"  import end : float[3];\n");
  tb.PrintF(L"  import count : int;\n");
}
const sChar *Wz4SkeletonWikiBoneChain =
L"= Wz4Skeleton : BoneChain\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BoneChain\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Skeleton\n"
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
L" !i Start\n"
L" !i Start\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i End\n"
L" !i End\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
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

void Wz4SkeletonAnimBoneChain::Init(class ScriptContext *sc)
{
};

void Wz4SkeletonAnimBoneChain::Bind(class ScriptContext *sc,Wz4SkeletonParaBoneChain *para)
{
};


/****************************************************************************/

void AddTypes_wz4_anim_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4ChannelType = new Wz4ChannelType_);
  Wz4ChannelType->Secondary = secondary;

  Doc->Types.AddTail(Wz4SkeletonType = new Wz4SkeletonType_);
  Wz4SkeletonType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_anim_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"BoneChain";
  cl->Label = L"BoneChain";
  cl->OutputType = Wz4SkeletonType;
  cl->TabType = Wz4SkeletonType;
  cl->Command = Wz4SkeletonCmdBoneChain;
  cl->MakeGui = Wz4SkeletonGuiBoneChain;
  cl->SetDefaults = Wz4SkeletonDefBoneChain;
  cl->BindPara = Wz4SkeletonBindBoneChain;
  cl->Bind2Para = Wz4SkeletonBind2BoneChain;
  cl->Bind3Para = Wz4SkeletonBind3BoneChain;
  cl->WikiText = Wz4SkeletonWikiBoneChain;
  cl->ParaWords = 7;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_anim_ops,0x110,AddOps_wz4_anim_ops,0);


/****************************************************************************/


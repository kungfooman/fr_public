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
#include "wz4_mtrl_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4MaterialType_ *Wz4MaterialType;

/****************************************************************************/

#line 17 "wz4_mtrl_ops.ops"

#include "wz4frlib/chaosmesh_ops.hpp"

#line 27 "wz4_mtrl_ops.cpp"

/****************************************************************************/

#line 35 "wz4_mtrl_ops.ops"
void Wz4MaterialType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 36 "wz4_mtrl_ops.ops"

    Wz4Material *mtrl;
  
    sSetTarget(sTargetPara(sCLEAR_ALL,pi.BackColor,pi.Spec));
    pi.View->SetTargetCurrent();
    pi.View->SetZoom(pi.Zoom3D);
    pi.View->Prepare();

    if(obj && obj->Type==Wz4MaterialType)
    {
      mtrl = (Wz4Material *) obj;

      sCBuffer<Wz4ShaderCamera> cb_cam;
      sCBuffer<Wz4ShaderUV> cb_uv;
      mtrl->Material->SetCam(cb_cam.Data,pi.View);
      mtrl->Material->SetUV(cb_uv.Data,pi.View);
      mtrl->Material->Set(&cb_cam,&cb_uv);

      sInt ty = 24;
      sInt tx = 24;
      sF32 ro = 2;
      sF32 ri = 0.5;
      sF32 u,v,fx,fy;
      sU16 *ip;

      sGeometry *Geo = new sGeometry;
      Geo->Init(sGF_TRILIST|sGF_INDEX16,sVertexFormatTSpace4);

  
      sVertexTSpace4 *vp;
      Geo->BeginLoadVB(tx*ty,sGD_STREAM,(void **)&vp);

      for(sInt y=0;y<ty;y++)
      {
        for(sInt x=0;x<tx;x++)
        {
          u = sF32(x)/tx; fx = u*sPI2F;
          v = sF32(y)/ty; fy = v*sPI2F;
          vp->px = -sFCos(fy)*(ro+sFSin(fx)*ri);
          vp->py = -sFCos(fx)*ri;
          vp->pz = sFSin(fy)*(ro+sFSin(fx)*ri);
          vp->nx = -sFCos(fy)*sFSin(fx);
          vp->ny = -sFCos(fx);
          vp->nz = sFSin(fy)*sFSin(fx);
          vp->tx = sFSin(fy);
          vp->ty = 0;
          vp->tz = sFCos(fy);
          vp->tsign = 1;
          vp->c0 = 0;
          vp->u0 = u;
          vp->v0 = v;
          vp->u1 = u;
          vp->v1 = v;
          vp++;
        }
      }
      Geo->EndLoadVB();
      
      Geo->BeginLoadIB(tx*ty*6,sGD_STREAM,(void **)&ip);
      for(sInt y=0;y<ty;y++)
      {
        for(sInt x=0;x<tx;x++)
        {
          sQuad(ip,0,
            (y+0)%ty*tx+(x+0)%tx,
            (y+1)%ty*tx+(x+0)%tx,
            (y+1)%ty*tx+(x+1)%tx,
            (y+0)%ty*tx+(x+1)%tx);
        }
      }
      Geo->EndLoadIB();

      Geo->Draw();

      delete Geo;
    }
  ;
#line 112 "wz4_mtrl_ops.cpp"
}

/****************************************************************************/

sBool Wz4MaterialCmdMaterial(wExecutive *exe,wCommand *cmd)
{
  Wz4MaterialParaMaterial sUNUSED *para = (Wz4MaterialParaMaterial *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Texture2D sUNUSED *in2 = cmd->GetInput<Texture2D *>(2); in2;
  TextureCube sUNUSED *in3 = cmd->GetInput<TextureCube *>(3); in3;
  TextureCube sUNUSED *in4 = cmd->GetInput<TextureCube *>(4); in4;
  Texture2D sUNUSED *in5 = cmd->GetInput<Texture2D *>(5); in5;
  Wz4Material *out = (Wz4Material *) cmd->Output;
  if(!out) { out=new Wz4Material; cmd->Output=out; }

  {
#line 208 "wz4_mtrl_ops.ops"

    static sU32 blend[8] =
    {
      sMB_OFF,sMB_ADD,sMB_MUL,sMB_MUL2,sMB_ADDSMOOTH,sMB_ALPHA
    };
    out->Material = new Wz4Shader;
    out->Material->Flags = para->Flags;
    out->Material->BlendColor = blend[para->Blend&7];

    out->Material->DetailMode = 0;
    if(in2)
    {
      out->Material->DetailMode = para->DetailMode;
      if((out->Material->DetailMode&0x0f)==3 && in0==0)
        out->Material->DetailMode = 0;
      if((out->Material->DetailMode&0x0f)==4 && in3==0)
        out->Material->DetailMode = 0;
    }
    out->Material->DetailMode |= para->DetailMode&0xff00;

    if(in0)
    {
      out->Tex[0] = in0; in0->AddRef();
      out->Material->Texture[0] = in0->Texture;
      out->Material->TFlags[0] = (para->TFlags0 ^ 2)&0xff;
      out->Material->MakeMatrix(0,para->TFlags0,para->Scale0,&para->Mat0Scale[0],&para->Mat1Scale.x);
    }

    if(in1)
    {
      out->Tex[1] = in1; in1->AddRef();
      out->Material->Texture[1] = in1->Texture;
      out->Material->TFlags[1] = (para->TFlags1 ^ 2)&0xff;
      out->Material->MakeMatrix(1,para->TFlags1,para->Scale1,&para->Mat0Scale[0],&para->Mat1Scale.x);
    }

    if(out->Material->DetailMode & 0x0f)
    {
      sVERIFY(in2);
      out->Tex[2] = in2; in2->AddRef();
      out->Material->Texture[2] = in2->Texture;
      out->Material->TFlags[2] = (para->TFlags2 ^ 2)&0xff;
      out->Material->MakeMatrix(2,para->TFlags2,para->Scale2,&para->Mat0Scale[0],&para->Mat1Scale.x);
    }

    if(in3)
    {
      out->Tex[3] = in3; in3->AddRef();
      out->Material->Texture[3] = in3->Texture;
      out->Material->TFlags[3] = ((para->TFlags3 ^ 2)&0x0f)|sMTF_CLAMP;
    }

    if(in4)
    {
      out->Tex[4] = in4; in4->AddRef();
      out->Material->Texture[4] = in4->Texture;
      out->Material->TFlags[4] = ((para->TFlags4 ^ 2)&0x0f)|sMTF_CLAMP;
    }

    if(in5)
    {
      out->Tex[5] = in5; in5->AddRef();
      out->Material->Texture[5] = in5->Texture;
      out->Material->TFlags[5] = ((para->TFlags5 ^ 2)&0x0f)|sMTF_CLAMP;
    }

    // build vertex format

    sU32 desc[16];
    sInt di = 0;

    sInt det = out->Material->DetailMode&0xf0;

    desc[di++] = sVF_POSITION;
    if(para->VertexMode)
    {
      desc[di++] = sVF_BONEINDEX|sVF_I4;
      desc[di++] = sVF_BONEWEIGHT|sVF_C4;
    }
    if(out->Material->Texture[0] || out->Material->Texture[3] || out->Material->Texture[4] || det==0x40 || det==0x50)
      desc[di++] = sVF_NORMAL;
    if(out->Material->Texture[0])
      desc[di++] = sVF_TANGENT|sVF_F4;
    desc[di++] = sVF_UV0;
    if(det==0x10)
      desc[di++] = sVF_UV1;
    desc[di++] = 0;

    out->Format = sCreateVertexFormat(desc);
    out->Material->Prepare(out->Format);

    return 1;
  ;
#line 224 "wz4_mtrl_ops.cpp"
    return 1;
  }
}

void Wz4MaterialGuiMaterial(wGridFrameHelper &gh,wOp *op)
{
  Wz4MaterialParaMaterial sUNUSED *para = (Wz4MaterialParaMaterial *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"zoff|zread|zwrite|zon:*4culloff|cullon|cullinv:*7-|light",gh.ChangeMsg);

  gh.Label(L"Write Mask");
  gh.Flags(&para->Flags,L"*8-|no A:*9-|no R:*10-|no G:*11-|no B",gh.ChangeMsg);

  gh.Label(L"Blend");
  gh.Flags(&para->Blend,L"opaque|add|mul|mul2|smooth|alpha",gh.ChangeMsg);

  gh.Group(L"Bump");

  gh.Label(L"Texture");
  gh.Flags(&op->Links[0].Select,L"|link|unused| 1| 2| 3| 4| 5| 6",gh.ConnectLayoutMsg);
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

  if((op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"Modes");

    gh.Flags(&para->TFlags0,L"point|linear|trilinear|aniso:*4tile|clamp|mirror",gh.ChangeMsg);

    gh.Label(L"Scale");
    gh.Flags(&para->TFlags0,L"*14-|scale|mat0|mat1",gh.LayoutMsg);

  }
  if(((op->ConnectionMask & (1<<0))!=0&&((para->TFlags0&0xc000)==0x4000)))
  {
    sFloatControl *float_Scale0 = gh.Float(&para->Scale0,-1024.00f,1024.000f,0.010000f);
    float_Scale0->Default = 1.000000f; float_Scale0->RightStep = 0.125000f;

  }
  gh.Group(L"Diffuse");

  gh.Label(L"Texture");
  gh.Flags(&op->Links[1].Select,L"|link|unused| 1| 2| 3| 4| 5| 6",gh.ConnectLayoutMsg);
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

  if((op->ConnectionMask & (1<<1))!=0)
  {
    gh.Label(L"Modes");

    gh.Flags(&para->TFlags1,L"point|linear|trilinear|aniso:*4tile|clamp|mirror",gh.ChangeMsg);

    gh.Label(L"Scale");
    gh.Flags(&para->TFlags1,L"*14-|scale|mat0|mat1",gh.LayoutMsg);

  }
  if(((op->ConnectionMask & (1<<1))!=0&&((para->TFlags1&0xc000)==0x4000)))
  {
    sFloatControl *float_Scale1 = gh.Float(&para->Scale1,-1024.00f,1024.000f,0.010000f);
    float_Scale1->Default = 1.000000f; float_Scale1->RightStep = 0.125000f;

  }
  gh.Group(L"Detail");

  gh.Label(L"Texture");
  gh.Flags(&op->Links[2].Select,L"|link|unused| 1| 2| 3| 4| 5| 6",gh.ConnectLayoutMsg);
  if(op->Links[2].Select==1)
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
    gh.Label(L"Modes");

    gh.Flags(&para->TFlags2,L"point|linear|trilinear|aniso:*4tile|clamp|mirror",gh.ChangeMsg);

    gh.Label(L"DetailMode");
    gh.Flags(&para->DetailMode,L"off|mul|add|bump|specmul:*4uv0|uv1|model|world|sphere|reflect",gh.ChangeMsg);

    gh.Label(L"Scale");
    gh.Flags(&para->TFlags2,L"*14-|scale|mat0|mat1",gh.LayoutMsg);

  }
  if(((op->ConnectionMask & (1<<2))!=0&&((para->TFlags2&0xc000)==0x4000)))
  {
    sFloatControl *float_Scale2 = gh.Float(&para->Scale2,-1024.00f,1024.000f,0.010000f);
    float_Scale2->Default = 1.000000f; float_Scale2->RightStep = 0.125000f;

  }
  gh.Group(L"Specular Cube");

  gh.Label(L"Texture");
  gh.Flags(&op->Links[3].Select,L"|link|unused| 1| 2| 3| 4| 5| 6",gh.ConnectLayoutMsg);
  if(op->Links[3].Select==1)
  {
    sControl *con=gh.String(op->Links[3].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 3;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 3;
    gh.Box(L"..",msg);
    if(!op->Links[3].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 3;
      gh.Box(L"->",msg);
    }
  }

  if((op->ConnectionMask & (1<<3))!=0)
  {
    gh.Label(L"Modes");

    gh.Flags(&para->TFlags3,L"point|linear|trilinear|aniso",gh.ChangeMsg);

  }
  gh.Group(L"Diffuse Cube");

  gh.Label(L"Texture");
  gh.Flags(&op->Links[4].Select,L"|link|unused| 1| 2| 3| 4| 5| 6",gh.ConnectLayoutMsg);
  if(op->Links[4].Select==1)
  {
    sControl *con=gh.String(op->Links[4].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 4;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 4;
    gh.Box(L"..",msg);
    if(!op->Links[4].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 4;
      gh.Box(L"->",msg);
    }
  }

  if((op->ConnectionMask & (1<<4))!=0)
  {
    gh.Label(L"Modes");

    gh.Flags(&para->TFlags4,L"point|linear|trilinear|aniso",gh.ChangeMsg);

  }
  gh.Group(L"Envi");

  gh.Label(L"Texture");
  gh.Flags(&op->Links[5].Select,L"|link|unused| 1| 2| 3| 4| 5| 6",gh.ConnectLayoutMsg);
  if(op->Links[5].Select==1)
  {
    sControl *con=gh.String(op->Links[5].LinkName,gh.LabelWidth+gh.WideWidth-gh.Left);
    con->ChangeMsg = gh.ConnectMsg;
    con->DoneMsg = gh.ConnectLayoutMsg;
    sMessage msg = gh.LinkBrowserMsg; msg.Code = 5;
    gh.Box(L"...",msg);
    msg = gh.LinkPopupMsg; msg.Code = 5;
    gh.Box(L"..",msg);
    if(!op->Links[5].LinkName.IsEmpty())
    {
      msg = gh.LinkGotoMsg; msg.Code = 5;
      gh.Box(L"->",msg);
    }
  }

  if((op->ConnectionMask & (1<<5))!=0)
  {
    gh.Label(L"Modes");

    gh.Flags(&para->TFlags5,L"point|linear|trilinear|aniso",gh.ChangeMsg);

  }
  if(((((para->TFlags0&0xc000)==0x8000)||((para->TFlags1&0xc000)==0x8000))||((para->TFlags2&0xc000)==0x8000)))
  {
    gh.Group(L"Matrix 0");

    gh.Label(L"Mat0Scale");
    gh.BeginTied();
    sFloatControl *float_Mat0Scale_0 = gh.Float(&para->Mat0Scale[0],-64.0000f,64.00000f,0.010000f);
    float_Mat0Scale_0->Default = 1.000000f; float_Mat0Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Mat0Scale_1 = gh.Float(&para->Mat0Scale[1],-64.0000f,64.00000f,0.010000f);
    float_Mat0Scale_1->Default = 1.000000f; float_Mat0Scale_1->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Mat0Rot");
    sFloatControl *float_Mat0Rot = gh.Float(&para->Mat0Rot,-64.0000f,64.00000f,0.010000f);
    float_Mat0Rot->Default = 0.000000f; float_Mat0Rot->RightStep = 0.125000f;

    gh.Label(L"Mat0Trans");
    gh.BeginTied();
    sFloatControl *float_Mat0Trans_0 = gh.Float(&para->Mat0Trans[0],-64.0000f,64.00000f,0.010000f);
    float_Mat0Trans_0->Default = 0.000000f; float_Mat0Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Mat0Trans_1 = gh.Float(&para->Mat0Trans[1],-64.0000f,64.00000f,0.010000f);
    float_Mat0Trans_1->Default = 0.000000f; float_Mat0Trans_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  if(((((para->TFlags0&0xc000)==0xc000)||((para->TFlags1&0xc000)==0xc000))||((para->TFlags2&0xc000)==0xc000)))
  {
    gh.Group(L"Matrix 1");

    gh.Label(L"Mat1Scale");
    gh.BeginTied();
    sFloatControl *float_Mat1Scale_0 = gh.Float(&para->Mat1Scale.x,-64.0000f,64.00000f,0.010000f);
    float_Mat1Scale_0->Default = 1.000000f; float_Mat1Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Mat1Scale_1 = gh.Float(&para->Mat1Scale.y,-64.0000f,64.00000f,0.010000f);
    float_Mat1Scale_1->Default = 1.000000f; float_Mat1Scale_1->RightStep = 0.125000f;
    sFloatControl *float_Mat1Scale_2 = gh.Float(&para->Mat1Scale.z,-64.0000f,64.00000f,0.010000f);
    float_Mat1Scale_2->Default = 1.000000f; float_Mat1Scale_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Mat1Rot");
    gh.BeginTied();
    sFloatControl *float_Mat1Rot_0 = gh.Float(&para->Mat1Rot.x,-64.0000f,64.00000f,0.010000f);
    float_Mat1Rot_0->Default = 0.000000f; float_Mat1Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Mat1Rot_1 = gh.Float(&para->Mat1Rot.y,-64.0000f,64.00000f,0.010000f);
    float_Mat1Rot_1->Default = 0.000000f; float_Mat1Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Mat1Rot_2 = gh.Float(&para->Mat1Rot.z,-64.0000f,64.00000f,0.010000f);
    float_Mat1Rot_2->Default = 0.000000f; float_Mat1Rot_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Mat1Trans");
    gh.BeginTied();
    sFloatControl *float_Mat1Trans_0 = gh.Float(&para->Mat1Trans.x,-64.0000f,64.00000f,0.010000f);
    float_Mat1Trans_0->Default = 0.000000f; float_Mat1Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Mat1Trans_1 = gh.Float(&para->Mat1Trans.y,-64.0000f,64.00000f,0.010000f);
    float_Mat1Trans_1->Default = 0.000000f; float_Mat1Trans_1->RightStep = 0.125000f;
    sFloatControl *float_Mat1Trans_2 = gh.Float(&para->Mat1Trans.z,-64.0000f,64.00000f,0.010000f);
    float_Mat1Trans_2->Default = 0.000000f; float_Mat1Trans_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Group(L"Misc");

  gh.Label(L"VertexMode");
  gh.Flags(&para->VertexMode,L"-|anim",gh.ChangeMsg);

  gh.Label(L"Alpha");
  gh.Flags(&para->DetailMode,L"*8one|distance|||diffuse",gh.ChangeMsg);
}

void Wz4MaterialDefMaterial(wOp *op)
{
  Wz4MaterialParaMaterial sUNUSED *para = (Wz4MaterialParaMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000093;
  para->TFlags0 = 0x00000002;
  para->Scale0 = 1.000000f;
  para->TFlags1 = 0x00000002;
  para->Scale1 = 1.000000f;
  para->TFlags2 = 0x00000002;
  para->DetailMode = 0x00000001;
  para->Scale2 = 1.000000f;
  para->TFlags3 = 0x00000002;
  para->TFlags4 = 0x00000002;
  para->TFlags5 = 0x00000002;
  para->Mat0Scale[0] = 1.000000f;
  para->Mat0Scale[1] = 1.000000f;
  para->Mat1Scale.x = 1.000000f;
  para->Mat1Scale.y = 1.000000f;
  para->Mat1Scale.z = 1.000000f;
}

void Wz4MaterialBindMaterial(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale0"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scale1"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"scale2"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"mat0scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"mat0scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"mat0rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"mat0trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"mat0trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"mat1scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"mat1scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"mat1scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"mat1rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"mat1rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"mat1rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"mat1trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"mat1trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"mat1trans"),val);
}
void Wz4MaterialBind2Material(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[45];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"blend");
    name[3] = sPoolString(L"bump");
    name[4] = sPoolString(L"texture");
    name[5] = sPoolString(L"modes");
    name[6] = sPoolString(L"tflags0");
    name[7] = sPoolString(L"scale");
    name[8] = sPoolString(L"scale0");
    name[9] = sPoolString(L"diffuse");
    name[10] = sPoolString(L"texture");
    name[11] = sPoolString(L"modes");
    name[12] = sPoolString(L"tflags1");
    name[13] = sPoolString(L"scale");
    name[14] = sPoolString(L"scale1");
    name[15] = sPoolString(L"detail");
    name[16] = sPoolString(L"texture");
    name[17] = sPoolString(L"modes");
    name[18] = sPoolString(L"tflags2");
    name[19] = sPoolString(L"detailmode");
    name[20] = sPoolString(L"scale");
    name[21] = sPoolString(L"scale2");
    name[22] = sPoolString(L"");
    name[23] = sPoolString(L"texture");
    name[24] = sPoolString(L"modes");
    name[25] = sPoolString(L"tflags3");
    name[26] = sPoolString(L"");
    name[27] = sPoolString(L"texture");
    name[28] = sPoolString(L"modes");
    name[29] = sPoolString(L"tflags4");
    name[30] = sPoolString(L"envi");
    name[31] = sPoolString(L"texture");
    name[32] = sPoolString(L"modes");
    name[33] = sPoolString(L"tflags5");
    name[34] = sPoolString(L"");
    name[35] = sPoolString(L"mat0scale");
    name[36] = sPoolString(L"mat0rot");
    name[37] = sPoolString(L"mat0trans");
    name[38] = sPoolString(L"");
    name[39] = sPoolString(L"mat1scale");
    name[40] = sPoolString(L"mat1rot");
    name[41] = sPoolString(L"mat1trans");
    name[42] = sPoolString(L"misc");
    name[43] = sPoolString(L"vertexmode");
    name[44] = sPoolString(L"alpha");
  }
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[14],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[35],ScriptTypeFloat,2,cmd->Data+12);
  ctx->AddImport(name[36],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[37],ScriptTypeFloat,2,cmd->Data+15);
  ctx->AddImport(name[39],ScriptTypeFloat,3,cmd->Data+17);
  ctx->AddImport(name[40],ScriptTypeFloat,3,cmd->Data+20);
  ctx->AddImport(name[41],ScriptTypeFloat,3,cmd->Data+23);
}
void Wz4MaterialBind3Material(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale0 : float;\n");
  tb.PrintF(L"  import scale1 : float;\n");
  tb.PrintF(L"  import scale2 : float;\n");
  tb.PrintF(L"  import mat0scale : float[2];\n");
  tb.PrintF(L"  import mat0rot : float;\n");
  tb.PrintF(L"  import mat0trans : float[2];\n");
  tb.PrintF(L"  import mat1scale : float[3];\n");
  tb.PrintF(L"  import mat1rot : float[3];\n");
  tb.PrintF(L"  import mat1trans : float[3];\n");
}
const sChar *Wz4MaterialWikiMaterial =
L"= Wz4Material : Material\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Material\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Material\n"
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
L" !i optional link Texture\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link Texture\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link Texture\n"
L" !i *\n"
L"\n"
L" !i TextureCube\n"
L" !i optional link Texture\n"
L" !i *\n"
L"\n"
L" !i TextureCube\n"
L" !i optional link Texture\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link Texture\n"
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
L" !i culloff\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i cullon\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i cullinv\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i light\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Write Mask\n"
L" !i Flags\n"
L" !i no A\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i no R\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i no G\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i no B\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Blend\n"
L" !i Blend\n"
L" !i opaque\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
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
L" !i alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Texture\n"
L" !i Texture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Modes\n"
L" !i TFlags0\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Scale\n"
L" !i TFlags0\n"
L" !i scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mat0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mat1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale0\n"
L" !i Scale0\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Texture\n"
L" !i Texture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Modes\n"
L" !i TFlags1\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Scale\n"
L" !i TFlags1\n"
L" !i scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mat0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mat1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale1\n"
L" !i Scale1\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Texture\n"
L" !i Texture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Modes\n"
L" !i TFlags2\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i DetailMode\n"
L" !i DetailMode\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bump\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i specmul\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i uv0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uv1\n"
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
L" !i sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i reflect\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale\n"
L" !i TFlags2\n"
L" !i scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mat0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mat1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale2\n"
L" !i Scale2\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Texture\n"
L" !i Texture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Modes\n"
L" !i TFlags3\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Texture\n"
L" !i Texture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Modes\n"
L" !i TFlags4\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Texture\n"
L" !i Texture\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Modes\n"
L" !i TFlags5\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mat0Scale\n"
L" !i Mat0Scale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Mat0Rot\n"
L" !i Mat0Rot\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Mat0Trans\n"
L" !i Mat0Trans\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Mat1Scale\n"
L" !i Mat1Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Mat1Rot\n"
L" !i Mat1Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Mat1Trans\n"
L" !i Mat1Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i VertexMode\n"
L" !i VertexMode\n"
L" !i anim\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Alpha\n"
L" !i DetailMode\n"
L" !i one\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i distance\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i diffuse\n"
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

void Wz4MaterialAnimMaterial::Init(class ScriptContext *sc)
{
};

void Wz4MaterialAnimMaterial::Bind(class ScriptContext *sc,Wz4MaterialParaMaterial *para)
{
};


/****************************************************************************/

void AddTypes_wz4_mtrl_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4MaterialType = new Wz4MaterialType_);
  Wz4MaterialType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_mtrl_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Material";
  cl->Label = L"Material";
  cl->OutputType = Wz4MaterialType;
  cl->TabType = Wz4MaterialType;
  cl->Command = Wz4MaterialCmdMaterial;
  cl->MakeGui = Wz4MaterialGuiMaterial;
  cl->SetDefaults = Wz4MaterialDefMaterial;
  cl->BindPara = Wz4MaterialBindMaterial;
  cl->Bind2Para = Wz4MaterialBind2Material;
  cl->Bind3Para = Wz4MaterialBind3Material;
  cl->WikiText = Wz4MaterialWikiMaterial;
  cl->ParaWords = 27;
  cl->Shortcut = 'm';
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(6);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Name = L"Texture";
  in[0].Flags = 0|wCIF_OPTIONAL|wCIF_METHODCHOOSE;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Name = L"Texture";
  in[1].Flags = 0|wCIF_OPTIONAL|wCIF_METHODCHOOSE;
  in[2].Type = Texture2DType;
  in[2].DefaultClass = 0;
  in[2].Name = L"Texture";
  in[2].Flags = 0|wCIF_OPTIONAL|wCIF_METHODCHOOSE;
  in[3].Type = TextureCubeType;
  in[3].DefaultClass = 0;
  in[3].Name = L"Texture";
  in[3].Flags = 0|wCIF_OPTIONAL|wCIF_METHODCHOOSE;
  in[4].Type = TextureCubeType;
  in[4].DefaultClass = 0;
  in[4].Name = L"Texture";
  in[4].Flags = 0|wCIF_OPTIONAL|wCIF_METHODCHOOSE;
  in[5].Type = Texture2DType;
  in[5].DefaultClass = 0;
  in[5].Name = L"Texture";
  in[5].Flags = 0|wCIF_OPTIONAL|wCIF_METHODCHOOSE;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_mtrl_ops,0x110,AddOps_wz4_mtrl_ops,0);


/****************************************************************************/


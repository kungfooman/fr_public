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
#include "pdf_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4PDFType_ *Wz4PDFType;

/****************************************************************************/

#line 14 "pdf_ops.ops"
  
  #include "wz4frlib/pdf.hpp"
  #include "wz4frlib/adf_ops.hpp"

#line 28 "pdf_ops.cpp"

/****************************************************************************/

#line 34 "pdf_ops.ops"
void Wz4PDFType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 35 "pdf_ops.ops"

    if(obj && obj->IsType(Wz4PDFType))
    {
      static const sInt downsample = 1;
      sInt tgtSizeX = sMin(pi.Client.SizeX()/downsample,256);
      sInt tgtSizeY = sMin(pi.Client.SizeY()/downsample,256);

      if(tgtSizeX != img->SizeX || tgtSizeY != img->SizeY)
      {
        delete img;
        img = new sImage(tgtSizeX,tgtSizeY);
      }

      Wz4PDF *pdf = (Wz4PDF *) obj;
    
      img->Fill(pi.BackColor);
      Wz4PDFObj_Render(img, pdf, pi);
      
      sRect srcRect(0,0,img->SizeX,img->SizeY);
      sStretch2D(img->Data,img->SizeX,srcRect,pi.Client);
    }
    
  ;
#line 59 "pdf_ops.cpp"
}
#line 59 "pdf_ops.ops"
void Wz4PDFType_::Init()
{
#line 60 "pdf_ops.ops"

    img = new sImage(1,1);
  ;
#line 68 "pdf_ops.cpp"
}
#line 64 "pdf_ops.ops"
void Wz4PDFType_::Exit()
{
#line 65 "pdf_ops.ops"

    sDelete(img);
  ;
#line 77 "pdf_ops.cpp"
}

/****************************************************************************/

sBool Wz4PDFCmdCube(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaCube sUNUSED *para = (Wz4PDFParaCube *)(cmd->Data); para;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 78 "pdf_ops.ops"

    out->SetObj(new Wz4PDFCube());
  ;
#line 93 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiCube(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaCube sUNUSED *para = (Wz4PDFParaCube *)(op->EditData); para;
}

void Wz4PDFDefCube(wOp *op)
{
  Wz4PDFParaCube sUNUSED *para = (Wz4PDFParaCube *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4PDFBindCube(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind2Cube(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind3Cube(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4PDFWikiCube =
L"= Wz4PDF : Cube\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Cube\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
L" !i\n"
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

sBool Wz4PDFCmdSphere(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaSphere sUNUSED *para = (Wz4PDFParaSphere *)(cmd->Data); para;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 91 "pdf_ops.ops"
    
    out->SetObj(new Wz4PDFSphere());
  ;
#line 152 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiSphere(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaSphere sUNUSED *para = (Wz4PDFParaSphere *)(op->EditData); para;
}

void Wz4PDFDefSphere(wOp *op)
{
  Wz4PDFParaSphere sUNUSED *para = (Wz4PDFParaSphere *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4PDFBindSphere(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind2Sphere(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind3Sphere(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4PDFWikiSphere =
L"= Wz4PDF : Sphere\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sphere\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
L" !i\n"
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

sBool Wz4PDFCmdFromADF(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaFromADF sUNUSED *para = (Wz4PDFParaFromADF *)(cmd->Data); para;
  Wz4ADF sUNUSED *in0 = cmd->GetInput<Wz4ADF *>(0); in0;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 104 "pdf_ops.ops"

    Wz4PDFFromADF *obj = new Wz4PDFFromADF(in0);    
    out->SetObj(obj);
  ;
#line 213 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiFromADF(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaFromADF sUNUSED *para = (Wz4PDFParaFromADF *)(op->EditData); para;
}

void Wz4PDFDefFromADF(wOp *op)
{
  Wz4PDFParaFromADF sUNUSED *para = (Wz4PDFParaFromADF *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4PDFBindFromADF(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind2FromADF(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind3FromADF(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4PDFWikiFromADF =
L"= Wz4PDF : FromADF\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FromADF\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4PDFCmdAdd(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaAdd sUNUSED *para = (Wz4PDFParaAdd *)(cmd->Data); para;
  Wz4PDF sUNUSED *in0 = cmd->GetInput<Wz4PDF *>(0); in0;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 120 "pdf_ops.ops"

    Wz4PDFAdd *obj = new Wz4PDFAdd();    
    out->SetObj(obj);
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      Wz4PDF *in = cmd->GetInput<Wz4PDF *>(i);
      if(in)
      {                
        obj->AddObj(in->GetObj());
        in->GetObj()->AddRef();
      }
    }
  ;
#line 295 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiAdd(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaAdd sUNUSED *para = (Wz4PDFParaAdd *)(op->EditData); para;
}

void Wz4PDFDefAdd(wOp *op)
{
  Wz4PDFParaAdd sUNUSED *para = (Wz4PDFParaAdd *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4PDFBindAdd(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind2Add(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4PDFBind3Add(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4PDFWikiAdd =
L"= Wz4PDF : Add\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Add\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
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
L" !i multiple optional\n"
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

sBool Wz4PDFCmdMultiply(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaMultiply sUNUSED *para = (Wz4PDFParaMultiply *)(cmd->Data); para;
  Wz4PDF sUNUSED *in0 = cmd->GetInput<Wz4PDF *>(0); in0;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 147 "pdf_ops.ops"

    sMatrix34 mat,mat0,mat1,matInvT;
    Wz4PDFAdd *obj = new Wz4PDFAdd();
    sSRT srt;

    srt.Scale.Init(1.0f,1.0f,1.0f);
    srt.Rotate.Init(0.0f,0.0f,0.0f);
    srt.Translate.Init(0.0f,0.0f,0.0f);

    out->SetObj(obj);

    for(sInt i=0;i<para->Count;i++)
    {      
      Wz4PDFTransform *t = new Wz4PDFTransform();
      t->Init(in0->GetObj(), srt.Scale, srt.Rotate, srt.Translate);     
      obj->AddObj(t);      
      in0->GetObj()->AddRef();
      srt.Translate = srt.Translate + (sVector30)para->Trans;
      srt.Rotate    = srt.Rotate + para->Rot;
      srt.Scale     = srt.Scale * para->Scale;
    }
  ;
#line 386 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiMultiply(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaMultiply sUNUSED *para = (Wz4PDFParaMultiply *)(op->EditData); para;
  gh.Group(op->Class->Label);

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
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-65536.0f,65536.00f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-65536.0f,65536.00f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-65536.0f,65536.00f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,1024,0.125000f);
  int_Count->Default = 0x00000002; int_Count->RightStep = 0.125000f;
}

void Wz4PDFDefMultiply(wOp *op)
{
  Wz4PDFParaMultiply sUNUSED *para = (Wz4PDFParaMultiply *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Count = 0x00000002;
}

void Wz4PDFBindMultiply(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
}
void Wz4PDFBind2Multiply(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"count");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+9);
}
void Wz4PDFBind3Multiply(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import count : int;\n");
}
const sChar *Wz4PDFWikiMultiply =
L"= Wz4PDF : Multiply\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Multiply\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
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

sBool Wz4PDFCmdTransform(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaTransform sUNUSED *para = (Wz4PDFParaTransform *)(cmd->Data); para;
  Wz4PDF sUNUSED *in0 = cmd->GetInput<Wz4PDF *>(0); in0;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 182 "pdf_ops.ops"

    Wz4PDFTransform *obj = new Wz4PDFTransform();    
    obj->Init(in0->GetObj(), para->Scale, para->Rot, para->Trans);
    in0->GetObj()->AddRef();
    out->SetObj(obj);
  ;
#line 579 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiTransform(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaTransform sUNUSED *para = (Wz4PDFParaTransform *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,0.010000f,1024.000f,0.001000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,0.010000f,1024.000f,0.001000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,0.010000f,1024.000f,0.001000f);
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
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-65536.0f,65536.00f,0.001000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-65536.0f,65536.00f,0.001000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-65536.0f,65536.00f,0.001000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4PDFDefTransform(wOp *op)
{
  Wz4PDFParaTransform sUNUSED *para = (Wz4PDFParaTransform *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4PDFBindTransform(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
}
void Wz4PDFBind2Transform(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
}
void Wz4PDFBind3Transform(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *Wz4PDFWikiTransform =
L"= Wz4PDF : Transform\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Transform\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
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

sBool Wz4PDFCmdTwirl(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaTwirl sUNUSED *para = (Wz4PDFParaTwirl *)(cmd->Data); para;
  Wz4PDF sUNUSED *in0 = cmd->GetInput<Wz4PDF *>(0); in0;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 200 "pdf_ops.ops"

    Wz4PDFTwirl *obj = new Wz4PDFTwirl();
    obj->Init(in0->GetObj(), para->Scale, para->Bias);
    in0->AddRef();
    out->SetObj(obj);
  ;
#line 756 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiTwirl(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaTwirl sUNUSED *para = (Wz4PDFParaTwirl *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.001000f);
  float_Scale_0->Default = 0.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.001000f);
  float_Scale_1->Default = 0.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.001000f);
  float_Scale_2->Default = 0.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Bias");
  gh.BeginTied();
  sFloatControl *float_Bias_0 = gh.Float(&para->Bias.x,-1024.00f,1024.000f,0.001000f);
  float_Bias_0->Default = 0.000000f; float_Bias_0->RightStep = 0.125000f;
  sFloatControl *float_Bias_1 = gh.Float(&para->Bias.y,-1024.00f,1024.000f,0.001000f);
  float_Bias_1->Default = 0.000000f; float_Bias_1->RightStep = 0.125000f;
  sFloatControl *float_Bias_2 = gh.Float(&para->Bias.z,-1024.00f,1024.000f,0.001000f);
  float_Bias_2->Default = 0.000000f; float_Bias_2->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4PDFDefTwirl(wOp *op)
{
  Wz4PDFParaTwirl sUNUSED *para = (Wz4PDFParaTwirl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4PDFBindTwirl(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
}
void Wz4PDFBind2Twirl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"bias");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
}
void Wz4PDFBind3Twirl(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import bias : float[3];\n");
}
const sChar *Wz4PDFWikiTwirl =
L"= Wz4PDF : Twirl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Twirl\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
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
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
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

sBool Wz4PDFCmdMerge(wExecutive *exe,wCommand *cmd)
{
  Wz4PDFParaMerge sUNUSED *para = (Wz4PDFParaMerge *)(cmd->Data); para;
  Wz4PDF sUNUSED *in0 = cmd->GetInput<Wz4PDF *>(0); in0;
  Wz4PDF sUNUSED *in1 = cmd->GetInput<Wz4PDF *>(1); in1;
  Wz4PDF *out = (Wz4PDF *) cmd->Output;
  if(!out) { out=new Wz4PDF; cmd->Output=out; }

  {
#line 218 "pdf_ops.ops"

    Wz4PDFMerge *obj = new Wz4PDFMerge();  
    obj->Init(in0->GetObj(),in1->GetObj(),para->MergeType, para->Factor);
    in0->GetObj()->AddRef();
    in1->GetObj()->AddRef();
    out->SetObj(obj);
  ;
#line 905 "pdf_ops.cpp"
    return 1;
  }
}

void Wz4PDFGuiMerge(wGridFrameHelper &gh,wOp *op)
{
  Wz4PDFParaMerge sUNUSED *para = (Wz4PDFParaMerge *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"MergeType");
  gh.Flags(&para->MergeType,L"A|B|C|D|E|F",gh.LayoutMsg);

  gh.Label(L"Factor");
  sFloatControl *float_Factor = gh.Float(&para->Factor,0.000000f,1.000000f,0.000100f);
  float_Factor->Default = 0.000000f; float_Factor->RightStep = 0.125000f;
}

void Wz4PDFDefMerge(wOp *op)
{
  Wz4PDFParaMerge sUNUSED *para = (Wz4PDFParaMerge *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4PDFBindMerge(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"factor"),val);
}
void Wz4PDFBind2Merge(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mergetype");
    name[1] = sPoolString(L"factor");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void Wz4PDFBind3Merge(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import factor : float;\n");
}
const sChar *Wz4PDFWikiMerge =
L"= Wz4PDF : Merge\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Merge\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4PDF\n"
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
L" !i MergeType\n"
L" !i MergeType\n"
L" !i A\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i B\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i C\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i D\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i E\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i F\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Factor\n"
L" !i Factor\n"
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

void Wz4PDFAnimCube::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimCube::Bind(class ScriptContext *sc,Wz4PDFParaCube *para)
{
};

void Wz4PDFAnimSphere::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimSphere::Bind(class ScriptContext *sc,Wz4PDFParaSphere *para)
{
};

void Wz4PDFAnimFromADF::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimFromADF::Bind(class ScriptContext *sc,Wz4PDFParaFromADF *para)
{
};

void Wz4PDFAnimAdd::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimAdd::Bind(class ScriptContext *sc,Wz4PDFParaAdd *para)
{
};

void Wz4PDFAnimMultiply::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimMultiply::Bind(class ScriptContext *sc,Wz4PDFParaMultiply *para)
{
};

void Wz4PDFAnimTransform::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimTransform::Bind(class ScriptContext *sc,Wz4PDFParaTransform *para)
{
};

void Wz4PDFAnimTwirl::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimTwirl::Bind(class ScriptContext *sc,Wz4PDFParaTwirl *para)
{
};

void Wz4PDFAnimMerge::Init(class ScriptContext *sc)
{
};

void Wz4PDFAnimMerge::Bind(class ScriptContext *sc,Wz4PDFParaMerge *para)
{
};


/****************************************************************************/

void AddTypes_pdf_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4PDFType = new Wz4PDFType_);
  Wz4PDFType->Secondary = secondary;
  Wz4PDFType->ColumnHeaders[0] = L"Generator";
  Wz4PDFType->ColumnHeaders[1] = L"Manipulator";

}

/****************************************************************************/

void AddOps_pdf_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Cube";
  cl->Label = L"Cube";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdCube;
  cl->MakeGui = Wz4PDFGuiCube;
  cl->SetDefaults = Wz4PDFDefCube;
  cl->BindPara = Wz4PDFBindCube;
  cl->Bind2Para = Wz4PDFBind2Cube;
  cl->Bind3Para = Wz4PDFBind3Cube;
  cl->WikiText = Wz4PDFWikiCube;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sphere";
  cl->Label = L"Sphere";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdSphere;
  cl->MakeGui = Wz4PDFGuiSphere;
  cl->SetDefaults = Wz4PDFDefSphere;
  cl->BindPara = Wz4PDFBindSphere;
  cl->Bind2Para = Wz4PDFBind2Sphere;
  cl->Bind3Para = Wz4PDFBind3Sphere;
  cl->WikiText = Wz4PDFWikiSphere;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FromADF";
  cl->Label = L"FromADF";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdFromADF;
  cl->MakeGui = Wz4PDFGuiFromADF;
  cl->SetDefaults = Wz4PDFDefFromADF;
  cl->BindPara = Wz4PDFBindFromADF;
  cl->Bind2Para = Wz4PDFBind2FromADF;
  cl->Bind3Para = Wz4PDFBind3FromADF;
  cl->WikiText = Wz4PDFWikiFromADF;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ADFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Add";
  cl->Label = L"Add";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdAdd;
  cl->MakeGui = Wz4PDFGuiAdd;
  cl->SetDefaults = Wz4PDFDefAdd;
  cl->BindPara = Wz4PDFBindAdd;
  cl->Bind2Para = Wz4PDFBind2Add;
  cl->Bind3Para = Wz4PDFBind3Add;
  cl->WikiText = Wz4PDFWikiAdd;
  cl->Column = 1;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4PDFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Multiply";
  cl->Label = L"Multiply";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdMultiply;
  cl->MakeGui = Wz4PDFGuiMultiply;
  cl->SetDefaults = Wz4PDFDefMultiply;
  cl->BindPara = Wz4PDFBindMultiply;
  cl->Bind2Para = Wz4PDFBind2Multiply;
  cl->Bind3Para = Wz4PDFBind3Multiply;
  cl->WikiText = Wz4PDFWikiMultiply;
  cl->ParaWords = 10;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4PDFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Transform";
  cl->Label = L"Transform";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdTransform;
  cl->MakeGui = Wz4PDFGuiTransform;
  cl->SetDefaults = Wz4PDFDefTransform;
  cl->BindPara = Wz4PDFBindTransform;
  cl->Bind2Para = Wz4PDFBind2Transform;
  cl->Bind3Para = Wz4PDFBind3Transform;
  cl->WikiText = Wz4PDFWikiTransform;
  cl->ParaWords = 9;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4PDFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Twirl";
  cl->Label = L"Twirl";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdTwirl;
  cl->MakeGui = Wz4PDFGuiTwirl;
  cl->SetDefaults = Wz4PDFDefTwirl;
  cl->BindPara = Wz4PDFBindTwirl;
  cl->Bind2Para = Wz4PDFBind2Twirl;
  cl->Bind3Para = Wz4PDFBind3Twirl;
  cl->WikiText = Wz4PDFWikiTwirl;
  cl->ParaWords = 6;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4PDFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Merge";
  cl->Label = L"Merge";
  cl->OutputType = Wz4PDFType;
  cl->TabType = Wz4PDFType;
  cl->Command = Wz4PDFCmdMerge;
  cl->MakeGui = Wz4PDFGuiMerge;
  cl->SetDefaults = Wz4PDFDefMerge;
  cl->BindPara = Wz4PDFBindMerge;
  cl->Bind2Para = Wz4PDFBind2Merge;
  cl->Bind3Para = Wz4PDFBind3Merge;
  cl->WikiText = Wz4PDFWikiMerge;
  cl->ParaWords = 2;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4PDFType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4PDFType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(pdf_ops,0x110,AddOps_pdf_ops,0);


/****************************************************************************/


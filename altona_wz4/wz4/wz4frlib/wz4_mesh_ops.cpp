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
#include "wz4_mesh_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4MeshType_ *Wz4MeshType;

/****************************************************************************/

#line 424 "wz4_mesh_ops.ops"

  static sBool logic(sInt selflag,sF32 select)
  {
    switch(selflag)
    {
    default:
      return 1;
    case 1:
      return 0;
    case 2:
      return select>=0.5f;
    case 3:
      return select<=0.5f;
    }
  }

  static sF32 logicF(sInt selflag,sF32 select)
  {
    if (!(selflag&0x04)) return logic(selflag, select)?1.0f:0.0f;

    switch(selflag&0x03)
    {
    default:
      return 1;
    case 1:
      return 0;
    case 2:
      return select;
    case 3:
      return 1.0f-select;
    }
  }


#line 58 "wz4_mesh_ops.cpp"

/****************************************************************************/

#line 38 "wz4_mesh_ops.ops"
void Wz4MeshType_::Init()
{
#line 39 "wz4_mesh_ops.ops"

    DefaultMtrl = new SimpleMtrl;
    DefaultMtrl->SetMtrl();
    DefaultMtrl->Prepare();
  ;
#line 71 "wz4_mesh_ops.cpp"
}
#line 45 "wz4_mesh_ops.ops"
void Wz4MeshType_::Exit()
{
#line 46 "wz4_mesh_ops.ops"

    delete DefaultMtrl;
  ;
#line 80 "wz4_mesh_ops.cpp"
}
#line 50 "wz4_mesh_ops.ops"
void Wz4MeshType_::BeginEngine(wPaintInfo &pi,sBool clear)
{
#line 51 "wz4_mesh_ops.ops"

    sSetTarget(sTargetPara((clear ? sST_CLEARALL : 0)|sST_SCISSOR,pi.BackColor,pi.Spec));
    pi.View->SetTargetCurrent();
    pi.View->SetZoom(pi.Zoom3D);
    pi.View->Prepare();
  ;
#line 92 "wz4_mesh_ops.cpp"
}
#line 58 "wz4_mesh_ops.ops"
void Wz4MeshType_::Paint(wObject *obj,wPaintInfo &pi,sMatrix34 *mat,sInt matcount)
{
#line 59 "wz4_mesh_ops.ops"

    if(obj && obj->IsType(Wz4MeshType))
    {
      Wz4MtrlType->PrepareView(*pi.View);
      sFrustum fr; fr.Init(pi.View->ModelScreen);
      Wz4Mesh *mesh = (Wz4Mesh *) obj;
      for(sInt i=0;i<matcount;i++)
      {
        mesh->Render(sRF_TARGET_MAIN,0,&sMatrix34CM(mat[i]),0,fr);
      }
    }
  ;
#line 110 "wz4_mesh_ops.cpp"
}
#line 72 "wz4_mesh_ops.ops"
void Wz4MeshType_::Hit(wObject *obj,const sRay &ray,wHitInfo &info)
{
#line 73 "wz4_mesh_ops.ops"

    sClear(info);
  ;
#line 119 "wz4_mesh_ops.cpp"
}
#line 77 "wz4_mesh_ops.ops"
void Wz4MeshType_::Wireframe(wObject *obj,wPaintInfo &pi,sMatrix34 &mat)
{
#line 78 "wz4_mesh_ops.ops"

    if(obj && obj->IsType(Wz4MeshType))
    {
      Wz4MtrlType->PrepareView(*pi.View);
      sFrustum fr; fr.Init(pi.View->ModelScreen);
      Wz4Mesh *mesh = (Wz4Mesh *) obj;
      mesh->Render(sRF_TARGET_WIRE,0,&sMatrix34CM(mat),0,fr);
    }
  ;
#line 134 "wz4_mesh_ops.cpp"
}

/****************************************************************************/

sBool Wz4MeshCmdConvertFromChaosMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaConvertFromChaosMesh sUNUSED *para = (Wz4MeshParaConvertFromChaosMesh *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 99 "wz4_mesh_ops.ops"

    out->ConvertFrom(in0);
  ;
#line 151 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiConvertFromChaosMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaConvertFromChaosMesh sUNUSED *para = (Wz4MeshParaConvertFromChaosMesh *)(op->EditData); para;
}

void Wz4MeshDefConvertFromChaosMesh(wOp *op)
{
  Wz4MeshParaConvertFromChaosMesh sUNUSED *para = (Wz4MeshParaConvertFromChaosMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindConvertFromChaosMesh(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2ConvertFromChaosMesh(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind3ConvertFromChaosMesh(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiConvertFromChaosMesh =
L"= Wz4Mesh : ConvertFromChaosMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ConvertFromChaosMesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i ChaosMesh\n"
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

sBool Wz4MeshCmdExport(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaExport sUNUSED *para = (Wz4MeshParaExport *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 123 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);
    out->SaveFlags = para->Flags;    
    if (para->FormatType==0)
      sSaveObject(cmd->Strings[0],out);
    else
      out->SaveOBJ(cmd->Strings[0]);
    
    return 1;
  ;
#line 230 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiExport(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaExport sUNUSED *para = (Wz4MeshParaExport *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Filename");
  {
    sControl *con = gh.String(op->EditString[0]);
    con->DoneMsg = con->ChangeMsg;
    con->ChangeMsg = sMessage();
    gh.FileSaveDialogMsg.Code = 0;
    gh.Box(L"...",gh.FileSaveDialogMsg);
  }

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0materials|-",gh.ChangeMsg);

  gh.Label(L"Vertex");
  gh.Flags(&para->Flags,L"*8tangents|-:*9uv0|-:*10uv1|-:*11vertex colors|-:*12bones|-",gh.ChangeMsg);

  gh.Label(L"Format");
  gh.Flags(&para->FormatType,L"wz4|obj",gh.ChangeMsg);
}

void Wz4MeshDefExport(wOp *op)
{
  Wz4MeshParaExport sUNUSED *para = (Wz4MeshParaExport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindExport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void Wz4MeshBind2Export(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"filename");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"vertex");
    name[3] = sPoolString(L"format");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4MeshBind3Export(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *Wz4MeshWikiExport =
L"= Wz4Mesh : Export\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Export\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Filename\n"
L" !i Filename\n"
L" !i save file\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i materials\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Vertex\n"
L" !i Flags\n"
L" !i tangents\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i uv1\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i vertex colors\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i bones\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Format\n"
L" !i FormatType\n"
L" !i wz4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i obj\n"
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

sBool Wz4MeshCmdImport(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaImport sUNUSED *para = (Wz4MeshParaImport *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 151 "wz4_mesh_ops.ops"

    sBool result = 0;
    const sChar *name = cmd->Strings[0];
    const sChar *ext = sFindFileExtension(name);
    if(sCmpStringI(ext,L"wz4mesh")==0)
    {
      result = sLoadObject(name,out);
    }
    else if(sCmpStringI(ext,L"xsi")==0)
    {
      result = out->LoadXSI(name,para->Flags&1,para->Flags&2);
    }
    else if(sCmpStringI(ext,L"lwo")==0)
    {
      result = out->LoadLWO(name);
    }
    else if(sCmpStringI(ext,L"obj")==0)
    {
      result = out->LoadOBJ(name);
    }
    else if(sCmpStringI(ext,L"wz3minmesh")==0)
    {
      result = out->LoadWz3MinMesh(name);
    }
    else
    {
      cmd->SetError(L"unrecognized file extension");
      result = sFALSE;
    }

    return result;
  ;
#line 435 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiImport(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaImport sUNUSED *para = (Wz4MeshParaImport *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Filename");
  {
    sControl *con = gh.String(op->EditString[0]);
    con->DoneMsg = con->ChangeMsg;
    con->ChangeMsg = sMessage();
    gh.FileLoadDialogMsg.Code = 0;
    gh.Box(L"...",gh.FileLoadDialogMsg);
    gh.Box(L"reload",gh.FileReloadMsg);
  }

  gh.Label(L"XSI Flags");
  gh.Flags(&para->Flags,L"*0-|force animated:*1-|force rgb",gh.ChangeMsg);
}

void Wz4MeshDefImport(wOp *op)
{
  Wz4MeshParaImport sUNUSED *para = (Wz4MeshParaImport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindImport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void Wz4MeshBind2Import(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"filename");
    name[1] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4MeshBind3Import(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *Wz4MeshWikiImport =
L"= Wz4Mesh : Import\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Import\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Filename\n"
L" !i Filename\n"
L" !i load file\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i XSI Flags\n"
L" !i Flags\n"
L" !i force animated\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i force rgb\n"
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

sBool Wz4MeshCmdTorus(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTorus sUNUSED *para = (Wz4MeshParaTorus *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 200 "wz4_mesh_ops.ops"

    out->MakeTorus(para->Slices,para->Segments,para->InnerRadius,para->OuterRadius,para->Phase,para->Arc);
    out->CalcNormalAndTangents();
  ;
#line 552 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTorus(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTorus sUNUSED *para = (Wz4MeshParaTorus *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,3,4096,0.125000f);
  int_Slices->Default = 0x0000000c; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Segments");
  sIntControl *int_Segments = gh.Int(&para->Segments,3,4096,0.125000f);
  int_Segments->Default = 0x00000008; int_Segments->RightStep = 0.125000f;

  gh.Label(L"InnerRadius");
  sFloatControl *float_InnerRadius = gh.Float(&para->InnerRadius,0.000000f,1024.000f,-0.010000f);
  float_InnerRadius->Default = 0.250000f; float_InnerRadius->RightStep = 0.125000f;

  gh.Label(L"OuterRadius");
  sFloatControl *float_OuterRadius = gh.Float(&para->OuterRadius,0.000000f,1024.000f,-0.010000f);
  float_OuterRadius->Default = 1.000000f; float_OuterRadius->RightStep = 0.125000f;

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,-4.00000f,4.000000f,0.001000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;

  gh.Label(L"Arc");
  sFloatControl *float_Arc = gh.Float(&para->Arc,0.000000f,1.000000f,0.001000f);
  float_Arc->Default = 1.000000f; float_Arc->RightStep = 0.125000f;
}

void Wz4MeshDefTorus(wOp *op)
{
  Wz4MeshParaTorus sUNUSED *para = (Wz4MeshParaTorus *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Slices = 0x0000000c;
  para->Segments = 0x00000008;
  para->InnerRadius = 0.250000f;
  para->OuterRadius = 1.000000f;
  para->Arc = 1.000000f;
}

void Wz4MeshBindTorus(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"segments"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"innerradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"outerradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"arc"),val);
}
void Wz4MeshBind2Torus(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"slices");
    name[1] = sPoolString(L"segments");
    name[2] = sPoolString(L"innerradius");
    name[3] = sPoolString(L"outerradius");
    name[4] = sPoolString(L"phase");
    name[5] = sPoolString(L"arc");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
}
void Wz4MeshBind3Torus(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import segments : int;\n");
  tb.PrintF(L"  import innerradius : float;\n");
  tb.PrintF(L"  import outerradius : float;\n");
  tb.PrintF(L"  import phase : float;\n");
  tb.PrintF(L"  import arc : float;\n");
}
const sChar *Wz4MeshWikiTorus =
L"= Wz4Mesh : Torus\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Torus\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i InnerRadius\n"
L" !i InnerRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i OuterRadius\n"
L" !i OuterRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Phase\n"
L" !i Phase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Arc\n"
L" !i Arc\n"
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

sBool Wz4MeshCmdGrid(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaGrid sUNUSED *para = (Wz4MeshParaGrid *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 219 "wz4_mesh_ops.ops"

    // create one grid

    out->MakeGrid(para->Tesselate[0],para->Tesselate[1]);

    // double grid

    if(para->Sides==2)
    {
      Wz4Mesh *m2 = new Wz4Mesh;
      m2->CopyFrom(out);
      sMatrix34 mat;
      mat.i.x = -1;
      mat.j.y = -1;
      mat.l.x = sF32(para->Tesselate[0]);
      m2->Transform(mat);
      out->Add(m2);
      delete m2;
    }

    // scale and position grid

    sMatrix34 mat;
    sF32 sx = para->Size/(para->Tesselate[0]);
    sF32 sz = para->Size/(para->Tesselate[1]);
    sF32 sy = 1;
    sF32 tx = -para->Size*0.5f;
    sF32 tz = -para->Size*0.5f;
    if(para->Sides==1) 
    {
      sy = -sy;
      sz = -sz;
      tz = -tz;
    }
    mat.i.Init(sx,0,0);
    mat.j.Init(0,sy,0);
    mat.k.Init(0,0,sz);
    mat.l.Init(tx,0,tz);
    out->Transform(mat);

    // flip uv

    Wz4MeshVertex *mv;
    sFORALL(out->Vertices,mv)
      mv->V0 = 1-mv->V0;

  //  out->CalcNormalAndTangents();
  ;
#line 769 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiGrid(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaGrid sUNUSED *para = (Wz4MeshParaGrid *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Tesselate");
  gh.BeginTied();
  sIntControl *int_Tesselate_0 = gh.Int(&para->Tesselate[0],1,4096,0.125000f);
  int_Tesselate_0->Default = 0x00000001; int_Tesselate_0->RightStep = 0.125000f;
  sIntControl *int_Tesselate_1 = gh.Int(&para->Tesselate[1],1,4096,0.125000f);
  int_Tesselate_1->Default = 0x00000001; int_Tesselate_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Sides");
  gh.Flags(&para->Sides,L"-|invert|double",gh.ChangeMsg);

  gh.Label(L"Size");
  sFloatControl *float_Size = gh.Float(&para->Size,0.000000f,1024.000f,0.010000f);
  float_Size->Default = 1.000000f; float_Size->RightStep = 0.125000f;
}

void Wz4MeshDefGrid(wOp *op)
{
  Wz4MeshParaGrid sUNUSED *para = (Wz4MeshParaGrid *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Tesselate[0] = 0x00000001;
  para->Tesselate[1] = 0x00000001;
  para->Size = 1.000000f;
}

void Wz4MeshBindGrid(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tesselate"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tesselate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
}
void Wz4MeshBind2Grid(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"tesselate");
    name[1] = sPoolString(L"sides");
    name[2] = sPoolString(L"size");
  }
  ctx->AddImport(name[0],ScriptTypeInt,2,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
}
void Wz4MeshBind3Grid(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import tesselate : int[2];\n");
  tb.PrintF(L"  import size : float;\n");
}
const sChar *Wz4MeshWikiGrid =
L"= Wz4Mesh : Grid\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Grid\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Tesselate\n"
L" !i Tesselate\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Sides\n"
L" !i Sides\n"
L" !i invert\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i double\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Size\n"
L" !i Size\n"
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

sBool Wz4MeshCmdDisc(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaDisc sUNUSED *para = (Wz4MeshParaDisc *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 282 "wz4_mesh_ops.ops"

    out->MakeDisc(para->Slices,para->Radius,para->Phase,para->Flags);
    out->CalcNormalAndTangents();
  ;
#line 901 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiDisc(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaDisc sUNUSED *para = (Wz4MeshParaDisc *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,3,4096,0.125000f);
  int_Slices->Default = 0x00000008; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,0.000000f,1024.000f,-0.010000f);
  float_Radius->Default = 0.250000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,-4.00000f,4.000000f,0.001000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|doublesided",gh.ChangeMsg);
}

void Wz4MeshDefDisc(wOp *op)
{
  Wz4MeshParaDisc sUNUSED *para = (Wz4MeshParaDisc *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Slices = 0x00000008;
  para->Radius = 0.250000f;
}

void Wz4MeshBindDisc(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
}
void Wz4MeshBind2Disc(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"slices");
    name[1] = sPoolString(L"radius");
    name[2] = sPoolString(L"phase");
    name[3] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4MeshBind3Disc(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import radius : float;\n");
  tb.PrintF(L"  import phase : float;\n");
}
const sChar *Wz4MeshWikiDisc =
L"= Wz4Mesh : Disc\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Disc\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Slices\n"
L" !i Slices\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Phase\n"
L" !i Phase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i doublesided\n"
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

sBool Wz4MeshCmdSphere(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSphere sUNUSED *para = (Wz4MeshParaSphere *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 301 "wz4_mesh_ops.ops"

    out->MakeSphere(para->Slices,para->Segments);
    sMatrix34 mat;
    mat.i.x = para->Diameter.x;
    mat.j.y = para->Diameter.y;
    mat.k.z = para->Diameter.z;
    out->Transform(mat);
    out->CalcNormalAndTangents();
  ;
#line 1040 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiSphere(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSphere sUNUSED *para = (Wz4MeshParaSphere *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,3,256,0.125000f);
  int_Slices->Default = 0x0000000c; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Segments");
  sIntControl *int_Segments = gh.Int(&para->Segments,2,256,0.125000f);
  int_Segments->Default = 0x00000008; int_Segments->RightStep = 0.125000f;

  gh.Label(L"Diameter");
  gh.BeginTied();
  sFloatControl *float_Diameter_0 = gh.Float(&para->Diameter.x,0.000000f,1024.000f,-0.010000f);
  float_Diameter_0->Default = 1.000000f; float_Diameter_0->RightStep = 0.125000f;
  sFloatControl *float_Diameter_1 = gh.Float(&para->Diameter.y,0.000000f,1024.000f,-0.010000f);
  float_Diameter_1->Default = 1.000000f; float_Diameter_1->RightStep = 0.125000f;
  sFloatControl *float_Diameter_2 = gh.Float(&para->Diameter.z,0.000000f,1024.000f,-0.010000f);
  float_Diameter_2->Default = 1.000000f; float_Diameter_2->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4MeshDefSphere(wOp *op)
{
  Wz4MeshParaSphere sUNUSED *para = (Wz4MeshParaSphere *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Slices = 0x0000000c;
  para->Segments = 0x00000008;
  para->Diameter.x = 1.000000f;
  para->Diameter.y = 1.000000f;
  para->Diameter.z = 1.000000f;
}

void Wz4MeshBindSphere(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"segments"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"diameter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"diameter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"diameter"),val);
}
void Wz4MeshBind2Sphere(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"slices");
    name[1] = sPoolString(L"segments");
    name[2] = sPoolString(L"diameter");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
}
void Wz4MeshBind3Sphere(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import segments : int;\n");
  tb.PrintF(L"  import diameter : float[3];\n");
}
const sChar *Wz4MeshWikiSphere =
L"= Wz4Mesh : Sphere\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sphere\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Diameter\n"
L" !i Diameter\n"
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

sBool Wz4MeshCmdCube(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaCube sUNUSED *para = (Wz4MeshParaCube *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 325 "wz4_mesh_ops.ops"

    out->MakeCube(para->Tesselate[0],para->Tesselate[1],para->Tesselate[2]);
    sMatrix34 mat;
    sF32 sx = para->Scale.x;
    sF32 sy = para->Scale.y;
    sF32 sz = para->Scale.z;
    mat.i.Init(sx/para->Tesselate[0],0,0);
    mat.j.Init(0,sy/para->Tesselate[1],0);
    mat.k.Init(0,0,sz/para->Tesselate[2]);
    mat.l.Init(-sx*0.5f,-sy*0.5f,-sz*0.5f);
    out->Transform(mat);

    Wz4MeshVertex *vp;
    sFORALL(out->Vertices,vp)
    {
      vp->Normal.Unit();
      vp->Tangent.Unit();
    }
    out->CalcNormalAndTangents();
  ;
#line 1196 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiCube(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaCube sUNUSED *para = (Wz4MeshParaCube *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Tesselate");
  gh.BeginTied();
  sIntControl *int_Tesselate_0 = gh.Int(&para->Tesselate[0],1,4096,0.125000f);
  int_Tesselate_0->Default = 0x00000001; int_Tesselate_0->RightStep = 0.125000f;
  sIntControl *int_Tesselate_1 = gh.Int(&para->Tesselate[1],1,4096,0.125000f);
  int_Tesselate_1->Default = 0x00000001; int_Tesselate_1->RightStep = 0.125000f;
  sIntControl *int_Tesselate_2 = gh.Int(&para->Tesselate[2],1,4096,0.125000f);
  int_Tesselate_2->Default = 0x00000001; int_Tesselate_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.125000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.125000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.125000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4MeshDefCube(wOp *op)
{
  Wz4MeshParaCube sUNUSED *para = (Wz4MeshParaCube *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Tesselate[0] = 0x00000001;
  para->Tesselate[1] = 0x00000001;
  para->Tesselate[2] = 0x00000001;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4MeshBindCube(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tesselate"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tesselate"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"tesselate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
}
void Wz4MeshBind2Cube(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"tesselate");
    name[1] = sPoolString(L"scale");
  }
  ctx->AddImport(name[0],ScriptTypeInt,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
}
void Wz4MeshBind3Cube(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import tesselate : int[3];\n");
  tb.PrintF(L"  import scale : float[3];\n");
}
const sChar *Wz4MeshWikiCube =
L"= Wz4Mesh : Cube\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Cube\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Tesselate\n"
L" !i Tesselate\n"
L" !i int[3]\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
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

sBool Wz4MeshCmdCylinder(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaCylinder sUNUSED *para = (Wz4MeshParaCylinder *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 365 "wz4_mesh_ops.ops"

    out->MakeCylinder(para->Slices,para->Segments,para->Top,para->Flags);
    sMatrix34 mat;
    mat.i.Init(para->Radius,0,0);
    mat.j.Init(0,para->Height,0);
    mat.k.Init(0,0,para->Radius);
    mat.l.Init(0,(para->Flags & 1)?0:-para->Height*0.5f,0);
    out->Transform(mat);
    out->CalcNormalAndTangents();
  ;
#line 1340 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiCylinder(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaCylinder sUNUSED *para = (Wz4MeshParaCylinder *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,3,4096,0.125000f);
  int_Slices->Default = 0x0000000c; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Segments");
  sIntControl *int_Segments = gh.Int(&para->Segments,1,4096,0.125000f);
  int_Segments->Default = 0x00000001; int_Segments->RightStep = 0.125000f;

  gh.Label(L"Top");
  sIntControl *int_Top = gh.Int(&para->Top,0,256,0.125000f);
  int_Top->Default = 0x00000000; int_Top->RightStep = 0.125000f;

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,0.000000f,1024.000f,0.010000f);
  float_Radius->Default = 0.500000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Height");
  sFloatControl *float_Height = gh.Float(&para->Height,0.000000f,1024.000f,0.010000f);
  float_Height->Default = 1.000000f; float_Height->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"centered|upright:*1top|-:*2bottom|-",gh.ChangeMsg);
}

void Wz4MeshDefCylinder(wOp *op)
{
  Wz4MeshParaCylinder sUNUSED *para = (Wz4MeshParaCylinder *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Slices = 0x0000000c;
  para->Segments = 0x00000001;
  para->Radius = 0.500000f;
  para->Height = 1.000000f;
}

void Wz4MeshBindCylinder(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"segments"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"top"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"height"),val);
}
void Wz4MeshBind2Cylinder(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"slices");
    name[1] = sPoolString(L"segments");
    name[2] = sPoolString(L"top");
    name[3] = sPoolString(L"radius");
    name[4] = sPoolString(L"height");
    name[5] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
}
void Wz4MeshBind3Cylinder(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import segments : int;\n");
  tb.PrintF(L"  import top : int;\n");
  tb.PrintF(L"  import radius : float;\n");
  tb.PrintF(L"  import height : float;\n");
}
const sChar *Wz4MeshWikiCylinder =
L"= Wz4Mesh : Cylinder\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Cylinder\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Top\n"
L" !i Top\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Height\n"
L" !i Height\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i centered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upright\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i top\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i bottom\n"
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

sBool Wz4MeshCmdText3D(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaText3D sUNUSED *para = (Wz4MeshParaText3D *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 393 "wz4_mesh_ops.ops"

    out->MakeText(cmd->Strings[0],cmd->Strings[1],para->Height,para->Extrude,para->MaxError,para->Flags);
    out->CalcNormalAndTangents();
  ;
#line 1528 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiText3D(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaText3D sUNUSED *para = (Wz4MeshParaText3D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Text");
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Right-gh.Left);
    tw->SetFont(sGui->FixedFont);
  }

  gh.Label(L"Font");
  gh.String(op->EditString[1]);

  gh.Label(L"Height");
  sFloatControl *float_Height = gh.Float(&para->Height,0.000000f,65536.00f,0.001000f);
  float_Height->Default = 0.500000f; float_Height->RightStep = 0.125000f;

  gh.Label(L"Extrude");
  sFloatControl *float_Extrude = gh.Float(&para->Extrude,0.000000f,65536.00f,0.001000f);
  float_Extrude->Default = 0.100000f; float_Extrude->RightStep = 0.125000f;

  gh.Label(L"MaxError");
  sFloatControl *float_MaxError = gh.Float(&para->MaxError,0.000000f,1.000000f,0.001000f);
  float_MaxError->Default = 0.050000f; float_MaxError->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|sharp edges:*1-|make chunks:*4X|Z",gh.ChangeMsg);

  gh.Label(L"Style");
  gh.Flags(&para->Flags,L"*2-|bold:*3-|italics",gh.ChangeMsg);
}

void Wz4MeshDefText3D(wOp *op)
{
  Wz4MeshParaText3D sUNUSED *para = (Wz4MeshParaText3D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  *op->EditString[0] = L"hund.";
  *op->EditString[1] = L"Arial";
  para->Height = 0.500000f;
  para->Extrude = 0.100000f;
  para->MaxError = 0.050000f;
}

void Wz4MeshBindText3D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"text"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"font"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"height"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"extrude"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"maxerror"),val);
}
void Wz4MeshBind2Text3D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"text");
    name[1] = sPoolString(L"font");
    name[2] = sPoolString(L"height");
    name[3] = sPoolString(L"extrude");
    name[4] = sPoolString(L"maxerror");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"style");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4MeshBind3Text3D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import text : string;\n");
  tb.PrintF(L"  import font : string;\n");
  tb.PrintF(L"  import height : float;\n");
  tb.PrintF(L"  import extrude : float;\n");
  tb.PrintF(L"  import maxerror : float;\n");
}
const sChar *Wz4MeshWikiText3D =
L"= Wz4Mesh : Text3D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Text3D\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Text\n"
L" !i Text\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Font\n"
L" !i Font\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Height\n"
L" !i Height\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Extrude\n"
L" !i Extrude\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaxError\n"
L" !i MaxError\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i sharp edges\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i make chunks\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i X\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Z\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Style\n"
L" !i Flags\n"
L" !i bold\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i italics\n"
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

sBool Wz4MeshCmdPath3D(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaPath3D sUNUSED *para = (Wz4MeshParaPath3D *)(cmd->Data); para;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 411 "wz4_mesh_ops.ops"

    out->MakePath(cmd->Strings[0],para->Extrude,para->MaxError,para->WeldThreshold,para->Flags);
    out->CalcNormalAndTangents();
  ;
#line 1736 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiPath3D(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaPath3D sUNUSED *para = (Wz4MeshParaPath3D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Path");
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Right-gh.Left);
    tw->SetFont(sGui->FixedFont);
  }

  gh.Label(L"Extrude");
  sFloatControl *float_Extrude = gh.Float(&para->Extrude,-65536.0f,65536.00f,0.001000f);
  float_Extrude->Default = 0.100000f; float_Extrude->RightStep = 0.125000f;

  gh.Label(L"MaxError");
  sFloatControl *float_MaxError = gh.Float(&para->MaxError,0.000000f,1.000000f,0.000100f);
  float_MaxError->Default = 0.005000f; float_MaxError->RightStep = 0.125000f;

  gh.Label(L"WeldThreshold");
  sFloatControl *float_WeldThreshold = gh.Float(&para->WeldThreshold,0.000000f,1.000000f,0.000001f);
  float_WeldThreshold->Default = 0.000010f; float_WeldThreshold->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|sharp edges",gh.ChangeMsg);
}

void Wz4MeshDefPath3D(wOp *op)
{
  Wz4MeshParaPath3D sUNUSED *para = (Wz4MeshParaPath3D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Extrude = 0.100000f;
  para->MaxError = 0.005000f;
  para->WeldThreshold = 0.000010f;
}

void Wz4MeshBindPath3D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"path"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"extrude"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"maxerror"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"weldthreshold"),val);
}
void Wz4MeshBind2Path3D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"path");
    name[1] = sPoolString(L"extrude");
    name[2] = sPoolString(L"maxerror");
    name[3] = sPoolString(L"weldthreshold");
    name[4] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4MeshBind3Path3D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import path : string;\n");
  tb.PrintF(L"  import extrude : float;\n");
  tb.PrintF(L"  import maxerror : float;\n");
  tb.PrintF(L"  import weldthreshold : float;\n");
}
const sChar *Wz4MeshWikiPath3D =
L"= Wz4Mesh : Path3D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Path3D\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Path\n"
L" !i Path\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Extrude\n"
L" !i Extrude\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaxError\n"
L" !i MaxError\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WeldThreshold\n"
L" !i WeldThreshold\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i sharp edges\n"
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

sBool Wz4MeshCmdNormalize(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaNormalize sUNUSED *para = (Wz4MeshParaNormalize *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 469 "wz4_mesh_ops.ops"

    if(para->Flags)
    {
			sInt *map = (para->Flags & 4) ? out->BasePos():out->BaseNormal();
      sBool byselection = (para->Flags&8);
			if(para->Flags & 1) out->CalcNormals(map,byselection);
			if(para->Flags & 2) out->CalcTangents(map,byselection);
			delete[] map; 
      if(para->Flags & 5) out->MergeVertices();
    }
  ;
#line 1896 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiNormalize(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaNormalize sUNUSED *para = (Wz4MeshParaNormalize *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|normals:*1-|tangents:*2-|smooth:*3-|by selection",gh.ChangeMsg);
}

void Wz4MeshDefNormalize(wOp *op)
{
  Wz4MeshParaNormalize sUNUSED *para = (Wz4MeshParaNormalize *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000003;
}

void Wz4MeshBindNormalize(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Normalize(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
  }
}
void Wz4MeshBind3Normalize(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiNormalize =
L"= Wz4Mesh : Normalize\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Normalize\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i normals\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i tangents\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i smooth\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i by selection\n"
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

sBool Wz4MeshCmdRandomize(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaRandomize sUNUSED *para = (Wz4MeshParaRandomize *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 495 "wz4_mesh_ops.ops"

    Wz4MeshVertex *vp;
    sRandom rnd;

    rnd.Seed(para->Seed);
    sF32 a2 = para->Amount*2;
    sF32 a = para->Amount;
    sInt *map = out->BasePos();

    sFORALL(out->Vertices,vp)
    {
      if(map[_i]==-1)
      {
        if(logic(para->Selection,vp->Select))
        {
          if(para->Mode==1)
          {
            sF32 f = rnd.Float(a2)-a;
            vp->Pos += vp->Normal * f;
          }
          else
          {
            vp->Pos.x += rnd.Float(a2)-a;
            vp->Pos.y += rnd.Float(a2)-a;
            vp->Pos.z += rnd.Float(a2)-a;
          }
        }
      }
      else
      {
        vp->Pos = out->Vertices[map[_i]].Pos;
      }
    }
    out->Flush();
    out->CalcNormalAndTangents();
    delete[] map;
  ;
#line 2056 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiRandomize(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaRandomize sUNUSED *para = (Wz4MeshParaRandomize *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"Amount");
  sFloatControl *float_Amount = gh.Float(&para->Amount,0.000000f,1024.000f,-0.010000f);
  float_Amount->Default = 0.125000f; float_Amount->RightStep = 0.125000f;

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L" 3d|by normal",gh.ChangeMsg);
}

void Wz4MeshDefRandomize(wOp *op)
{
  Wz4MeshParaRandomize sUNUSED *para = (Wz4MeshParaRandomize *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Amount = 0.125000f;
}

void Wz4MeshBindRandomize(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
}
void Wz4MeshBind2Randomize(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"seed");
    name[1] = sPoolString(L"amount");
    name[2] = sPoolString(L"selection");
    name[3] = sPoolString(L"mode");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void Wz4MeshBind3Randomize(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import amount : float;\n");
}
const sChar *Wz4MeshWikiRandomize =
L"= Wz4Mesh : Randomize\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Randomize\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Amount\n"
L" !i Amount\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i 3d\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i by normal\n"
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

sBool Wz4MeshCmdNoise(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaNoise sUNUSED *para = (Wz4MeshParaNoise *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 550 "wz4_mesh_ops.ops"

    Wz4MeshVertex *vp;

    sInt *map = out->BasePos();
    sVector30 p;
    sVector30 a;

    sFORALL(out->Vertices,vp)
    {
      if(map[_i]==-1)
      {
        if(logic(para->Selection&3,vp->Select))
        {
          sInt x = sInt(vp->Pos.x*para->Freq[0]*0x10000);
          sInt y = sInt(vp->Pos.y*para->Freq[1]*0x10000);
          sInt z = sInt(vp->Pos.z*para->Freq[2]*0x10000);
          a.x = para->Amplify[0];
          a.y = para->Amplify[1];
          a.z = para->Amplify[2];
          p.Init(0,0,0);
          for(sInt i=0;i<para->Octaves;i++)
          {
            p.x += a.x * sPerlin3D(x,y,z,255,para->Seed+0);
            p.y += a.y * sPerlin3D(x,y,z,255,para->Seed+1);
            p.z += a.z * sPerlin3D(x,y,z,255,para->Seed+2);
            x *= 2;
            y *= 2;
            z *= 2; 
            a *= para->Falloff;
          }
          if(para->Selection & 4)
          {
            p.y = sFAbs(p.y);
          }
          vp->Pos += p;
        }
      }
      else
      {
        vp->Pos = out->Vertices[map[_i]].Pos;
      }
    }
    out->Flush();
    out->CalcNormalAndTangents();
    delete[] map;
  ;
#line 2254 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiNoise(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaNoise sUNUSED *para = (Wz4MeshParaNoise *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"Freq");
  gh.BeginTied();
  sFloatControl *float_Freq_0 = gh.Float(&para->Freq[0],0.000000f,1024.000f,-0.010000f);
  float_Freq_0->Default = 1.000000f; float_Freq_0->RightStep = 0.125000f;
  sFloatControl *float_Freq_1 = gh.Float(&para->Freq[1],0.000000f,1024.000f,-0.010000f);
  float_Freq_1->Default = 1.000000f; float_Freq_1->RightStep = 0.125000f;
  sFloatControl *float_Freq_2 = gh.Float(&para->Freq[2],0.000000f,1024.000f,-0.010000f);
  float_Freq_2->Default = 1.000000f; float_Freq_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Amplify");
  gh.BeginTied();
  sFloatControl *float_Amplify_0 = gh.Float(&para->Amplify[0],0.000000f,1024.000f,-0.010000f);
  float_Amplify_0->Default = 0.125000f; float_Amplify_0->RightStep = 0.125000f;
  sFloatControl *float_Amplify_1 = gh.Float(&para->Amplify[1],0.000000f,1024.000f,-0.010000f);
  float_Amplify_1->Default = 0.125000f; float_Amplify_1->RightStep = 0.125000f;
  sFloatControl *float_Amplify_2 = gh.Float(&para->Amplify[2],0.000000f,1024.000f,-0.010000f);
  float_Amplify_2->Default = 0.125000f; float_Amplify_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Octaves");
  sIntControl *int_Octaves = gh.Int(&para->Octaves,1,16,0.125000f);
  int_Octaves->Default = 0x00000001; int_Octaves->RightStep = 0.125000f;

  gh.Label(L"Falloff");
  sFloatControl *float_Falloff = gh.Float(&para->Falloff,0.000000f,16.00000f,0.010000f);
  float_Falloff->Default = 1.000000f; float_Falloff->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Selection,L"*2-|abs y",gh.ChangeMsg);
}

void Wz4MeshDefNoise(wOp *op)
{
  Wz4MeshParaNoise sUNUSED *para = (Wz4MeshParaNoise *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Freq[0] = 1.000000f;
  para->Freq[1] = 1.000000f;
  para->Freq[2] = 1.000000f;
  para->Amplify[0] = 0.125000f;
  para->Amplify[1] = 0.125000f;
  para->Amplify[2] = 0.125000f;
  para->Octaves = 0x00000001;
  para->Falloff = 1.000000f;
}

void Wz4MeshBindNoise(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"octaves"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"falloff"),val);
}
void Wz4MeshBind2Noise(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"seed");
    name[1] = sPoolString(L"freq");
    name[2] = sPoolString(L"amplify");
    name[3] = sPoolString(L"selection");
    name[4] = sPoolString(L"octaves");
    name[5] = sPoolString(L"falloff");
    name[6] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+9);
}
void Wz4MeshBind3Noise(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import freq : float[3];\n");
  tb.PrintF(L"  import amplify : float[3];\n");
  tb.PrintF(L"  import octaves : int;\n");
  tb.PrintF(L"  import falloff : float;\n");
}
const sChar *Wz4MeshWikiNoise =
L"= Wz4Mesh : Noise\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Noise\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Freq\n"
L" !i Freq\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Octaves\n"
L" !i Octaves\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Falloff\n"
L" !i Falloff\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Selection\n"
L" !i abs y\n"
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

sBool Wz4MeshCmdInvert(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaInvert sUNUSED *para = (Wz4MeshParaInvert *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 610 "wz4_mesh_ops.ops"

    Wz4MeshFace *fp;    
    sFORALL(out->Faces,fp)
    {
      if(logic(para->Selection,fp->Select))
        fp->Invert();
    }
    Wz4MeshVertex *mv;
    sFORALL(out->Vertices,mv)
      if(logic(para->Selection,mv->Select))
        mv->Normal.Neg();
    out->Flush();
  ;
#line 2492 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiInvert(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaInvert sUNUSED *para = (Wz4MeshParaInvert *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefInvert(wOp *op)
{
  Wz4MeshParaInvert sUNUSED *para = (Wz4MeshParaInvert *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindInvert(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Invert(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
  }
}
void Wz4MeshBind3Invert(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiInvert =
L"= Wz4Mesh : Invert\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Invert\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

sBool Wz4MeshCmdTriangulate(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTriangulate sUNUSED *para = (Wz4MeshParaTriangulate *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 636 "wz4_mesh_ops.ops"

    Wz4MeshFace *fp;
    Wz4MeshFace *nfp;
    sArray<Wz4MeshFace> newfaces;

    sInt fc = 0;
    sFORALL(out->Faces,fp)
    {
      if(!logic(para->Selection,fp->Select) || fp->Count==3)
        fc += 1;
      else
        fc += 2;
    }
    nfp = newfaces.AddMany(fc);
    sFORALL(out->Faces,fp)
    {
      if(!logic(para->Selection,fp->Select) || fp->Count==3)
      {
        *nfp++ = *fp;
      }
      else
      {
        nfp->Init(3);
        nfp->Select = fp->Select;
        nfp->Selected = fp->Selected;
        nfp->Cluster = fp->Cluster;
        nfp->Vertex[0] = fp->Vertex[0];
        nfp->Vertex[1] = fp->Vertex[1];
        nfp->Vertex[2] = fp->Vertex[2];
        nfp++;
        nfp->Init(3);
        nfp->Select = fp->Select;
        nfp->Selected = fp->Selected;
        nfp->Cluster = fp->Cluster;
        nfp->Vertex[0] = fp->Vertex[0];
        nfp->Vertex[1] = fp->Vertex[2];
        nfp->Vertex[2] = fp->Vertex[3];
        nfp++;
      }
    }

    out->Faces = newfaces;
    out->Flush();
  ;
#line 2643 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTriangulate(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTriangulate sUNUSED *para = (Wz4MeshParaTriangulate *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefTriangulate(wOp *op)
{
  Wz4MeshParaTriangulate sUNUSED *para = (Wz4MeshParaTriangulate *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindTriangulate(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Triangulate(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
  }
}
void Wz4MeshBind3Triangulate(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiTriangulate =
L"= Wz4Mesh : Triangulate\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Triangulate\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

sBool Wz4MeshCmdDeleteFace(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaDeleteFace sUNUSED *para = (Wz4MeshParaDeleteFace *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 696 "wz4_mesh_ops.ops"

    Wz4MeshFace *fp;
    Wz4MeshFace *nfp;
    sArray<Wz4MeshFace> newfaces;

    sInt fc = 0;
    sFORALL(out->Faces,fp)
    {
      if(!logic(para->Selection,fp->Select))
        fc += 1;
    }
    nfp = newfaces.AddMany(fc);
    sFORALL(out->Faces,fp)
    {
      if(!logic(para->Selection,fp->Select))
      {
        *nfp++ = *fp;
      }
    }

    out->Faces = newfaces;

    // delete vertices without faces ?
    if(para->DeleteUnusedVertices)
    {
      sInt vc = 0;
      sFORALL(out->Faces,fp)
        vc += fp->Count;

      Wz4MeshVertex *nv = new Wz4MeshVertex[vc];

      sInt nc = 0;
      sFORALL(out->Faces,fp)
      {
        for(sInt i=0;i<fp->Count;i++)
        {
          nv[nc] = out->Vertices[fp->Vertex[i]];
          fp->Vertex[i] = nc;
          nc++;
        }
      }
      sVERIFY(nc==vc);

      out->Vertices.Resize(nc);
      sCopyMem(out->Vertices.GetData(),nv,sizeof(Wz4MeshVertex)*nc);
      delete[] nv;
    }

    out->Flush();
  ;
#line 2800 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiDeleteFace(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaDeleteFace sUNUSED *para = (Wz4MeshParaDeleteFace *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Vertices");
  gh.Flags(&para->DeleteUnusedVertices,L"keep|delete",gh.ChangeMsg);
}

void Wz4MeshDefDeleteFace(wOp *op)
{
  Wz4MeshParaDeleteFace sUNUSED *para = (Wz4MeshParaDeleteFace *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Selection = 0x00000002;
}

void Wz4MeshBindDeleteFace(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2DeleteFace(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
    name[1] = sPoolString(L"vertices");
  }
}
void Wz4MeshBind3DeleteFace(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiDeleteFace =
L"= Wz4Mesh : DeleteFace\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DeleteFace\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Vertices\n"
L" !i DeleteUnusedVertices\n"
L" !i keep\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i delete\n"
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

sBool Wz4MeshCmdSetMaterial(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSetMaterial sUNUSED *para = (Wz4MeshParaSetMaterial *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mtrl sUNUSED *in1 = cmd->GetInput<Wz4Mtrl *>(1); in1;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 763 "wz4_mesh_ops.ops"

    if(para->Selection==4)
    {
      sInt cli = para->Cluster;
      if(cli>=0 && cli<out->Clusters.GetCount())
      {
        out->Clusters[cli]->Mtrl->Release();
        out->Clusters[cli]->Mtrl = in1;
        in1->AddRef();
      }
    }
    else
    {
      if(para->Selection==0)
        sDeleteAll(out->Clusters);
     
      Wz4MeshCluster *cl;
      sInt cli = -1;
      sFORALL(out->Clusters,cl)
        if(cl->Mtrl==in1)
          cli = _i;
      if(cli==-1)
      {
        cl = new Wz4MeshCluster;
        cl->Mtrl = in1; in1->AddRef();
        cli = out->Clusters.GetCount();
        out->Clusters.AddTail(cl);
      }

      Wz4MeshFace *mf;
      sFORALL(out->Faces,mf)
        if(logic(para->Selection,mf->Select))
          mf->Cluster = cli;

      if(out->Skeleton) out->SplitClustersAnim(74);
      if(out->Chunks.GetCount()) out->SplitClustersChunked(74);

    }
    out->Flush();
  ;
#line 2962 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiSetMaterial(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSetMaterial sUNUSED *para = (Wz4MeshParaSetMaterial *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Material");
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

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected|cluster",gh.LayoutMsg);

  if((para->Selection==0x0004))
  {
    gh.Label(L"Cluster");
    sIntControl *int_Cluster = gh.Int(&para->Cluster,0,65536,0.125000f);
    int_Cluster->Default = 0x00000000; int_Cluster->RightStep = 0.125000f;
  }
}

void Wz4MeshDefSetMaterial(wOp *op)
{
  Wz4MeshParaSetMaterial sUNUSED *para = (Wz4MeshParaSetMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindSetMaterial(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"cluster"),val);
}
void Wz4MeshBind2SetMaterial(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"material");
    name[1] = sPoolString(L"selection");
    name[2] = sPoolString(L"cluster");
  }
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
}
void Wz4MeshBind3SetMaterial(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import cluster : int;\n");
}
const sChar *Wz4MeshWikiSetMaterial =
L"= Wz4Mesh : SetMaterial\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SetMaterial\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Wz4Mtrl\n"
L" !i link Material\n"
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
L" !i Material\n"
L" !i Material\n"
L" !i link\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i cluster\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Cluster\n"
L" !i Cluster\n"
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

sBool Wz4MeshCmdTransform(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTransform sUNUSED *para = (Wz4MeshParaTransform *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 820 "wz4_mesh_ops.ops"

    sMatrix34 mat,matInvT;
    sSRT srt;
    sBool flipped = sFALSE;
    Wz4MeshVertex *mv;

    srt.Scale = para->Scale;
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.MakeMatrix(mat);

    matInvT = mat;
    matInvT.Invert3();
    matInvT.Trans3();

    sFORALL(out->Vertices,mv)
      if(logic(para->Selection,mv->Select))
        mv->Transform(mat,matInvT);

    Wz4ChunkPhysics *phys;
    sFORALL(out->Chunks,phys)
      phys->Transform(mat);

    if(para->Scale.x * para->Scale.y * para->Scale.z < 0.0f)
    {
      Wz4MeshFace *f;
      sFORALL(out->Faces,f)
        f->Invert();

      flipped = sTRUE;
    }

    if(flipped || para->Selection>=2)
      out->CalcNormalAndTangents();

    out->Flush();
  ;
#line 3158 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTransform(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTransform sUNUSED *para = (Wz4MeshParaTransform *)(op->EditData); para;
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

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefTransform(wOp *op)
{
  Wz4MeshParaTransform sUNUSED *para = (Wz4MeshParaTransform *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4MeshBindTransform(wCommand *cmd,ScriptContext *ctx)
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
void Wz4MeshBind2Transform(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
}
void Wz4MeshBind3Transform(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *Wz4MeshWikiTransform =
L"= Wz4Mesh : Transform\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Transform\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

sBool Wz4MeshCmdTransformRange(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTransformRange sUNUSED *para = (Wz4MeshParaTransformRange *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 883 "wz4_mesh_ops.ops"

    out->TransformRange(para->RangeMode,para->Mode,para->Selection,para->Direction,para->AxialRange,
                        para->ScaleStart,para->RotateStart,para->TranslateStart,
                        para->ScaleEnd, para->RotateEnd, para->TranslateEnd);
  ;
#line 3355 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshHndTransformRange(wPaintInfo &pi,wOp *op)
{
  Wz4MeshParaTransformRange sUNUSED *para = (Wz4MeshParaTransformRange *)(op->EditData); para;
#line 889 "wz4_mesh_ops.ops"

    sMatrix34 mat;
    sSRT srt;
    srt.Rotate = sVector30(-para->Direction.x, 0, -para->Direction.y);
    srt.MakeMatrix(mat);

    sVector31 v[7],p;
    bool zoff = true;
    sF32 s = 0.2f;
    sF32 o = para->AxialRange.y;

    // pyramid
    p.Init( 0,o-s, 0); v[0] = p*mat;
    p.Init(-s, o,-s); v[1] = p*mat;
    p.Init( s, o,-s); v[2] = p*mat;
    p.Init( s, o, s); v[3] = p*mat;
    p.Init(-s, o, s); v[4] = p*mat;
    pi.Line3D(v[0],v[1],0,zoff);
    pi.Line3D(v[0],v[2],0,zoff);
    pi.Line3D(v[0],v[3],0,zoff);
    pi.Line3D(v[0],v[4],0,zoff);
    pi.Line3D(v[1],v[2],0,zoff);
    pi.Line3D(v[2],v[3],0,zoff);
    pi.Line3D(v[3],v[4],0,zoff);
    pi.Line3D(v[4],v[1],0,zoff);

    // axial range
    p.Init( 0, para->AxialRange.x, 0); v[5] = p*mat;
    p.Init( 0, para->AxialRange.y-s, 0); v[6] = p*mat;
    pi.Line3D(v[5],v[6],0,zoff);
  ;
#line 3395 "wz4_mesh_ops.cpp"
}

void Wz4MeshGuiTransformRange(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTransformRange sUNUSED *para = (Wz4MeshParaTransformRange *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"linear|smooth|tent|tent smooth",gh.ChangeMsg);

  gh.Label(L"Direction");
  gh.BeginTied();
  sFloatControl *float_Direction_0 = gh.Float(&para->Direction.x,-1024.00f,1024.000f,0.010000f);
  float_Direction_0->Default = 0.000000f; float_Direction_0->RightStep = 0.125000f;
  sFloatControl *float_Direction_1 = gh.Float(&para->Direction.y,-1024.00f,1024.000f,0.010000f);
  float_Direction_1->Default = 0.000000f; float_Direction_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"AxialRange");
  gh.BeginTied();
  sFloatControl *float_AxialRange_0 = gh.Float(&para->AxialRange.x,-1024.00f,1024.000f,0.010000f);
  float_AxialRange_0->Default = 1.000000f; float_AxialRange_0->RightStep = 0.125000f;
  sFloatControl *float_AxialRange_1 = gh.Float(&para->AxialRange.y,-1024.00f,1024.000f,0.010000f);
  float_AxialRange_1->Default = -1.00000f; float_AxialRange_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"RangeMode");
  gh.Flags(&para->RangeMode,L"auto|manual",gh.ChangeMsg);

  gh.Group(L"Start");

  gh.Label(L"ScaleStart");
  gh.BeginTied();
  sFloatControl *float_ScaleStart_0 = gh.Float(&para->ScaleStart.x,0.000000f,1024.000f,0.010000f);
  float_ScaleStart_0->Default = 1.000000f; float_ScaleStart_0->RightStep = 0.125000f;
  sFloatControl *float_ScaleStart_1 = gh.Float(&para->ScaleStart.y,0.000000f,1024.000f,0.010000f);
  float_ScaleStart_1->Default = 1.000000f; float_ScaleStart_1->RightStep = 0.125000f;
  sFloatControl *float_ScaleStart_2 = gh.Float(&para->ScaleStart.z,0.000000f,1024.000f,0.010000f);
  float_ScaleStart_2->Default = 1.000000f; float_ScaleStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"RotateStart");
  gh.BeginTied();
  sFloatControl *float_RotateStart_0 = gh.Float(&para->RotateStart.x,-1024.00f,1024.000f,0.001000f);
  float_RotateStart_0->Default = 0.000000f; float_RotateStart_0->RightStep = 0.125000f;
  sFloatControl *float_RotateStart_1 = gh.Float(&para->RotateStart.y,-1024.00f,1024.000f,0.001000f);
  float_RotateStart_1->Default = 0.000000f; float_RotateStart_1->RightStep = 0.125000f;
  sFloatControl *float_RotateStart_2 = gh.Float(&para->RotateStart.z,-1024.00f,1024.000f,0.001000f);
  float_RotateStart_2->Default = 0.000000f; float_RotateStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"TranslateStart");
  gh.BeginTied();
  sFloatControl *float_TranslateStart_0 = gh.Float(&para->TranslateStart.x,-1024.00f,1024.000f,0.010000f);
  float_TranslateStart_0->Default = 0.000000f; float_TranslateStart_0->RightStep = 0.125000f;
  sFloatControl *float_TranslateStart_1 = gh.Float(&para->TranslateStart.y,-1024.00f,1024.000f,0.010000f);
  float_TranslateStart_1->Default = 0.000000f; float_TranslateStart_1->RightStep = 0.125000f;
  sFloatControl *float_TranslateStart_2 = gh.Float(&para->TranslateStart.z,-1024.00f,1024.000f,0.010000f);
  float_TranslateStart_2->Default = 0.000000f; float_TranslateStart_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"End");

  gh.Label(L"ScaleEnd");
  gh.BeginTied();
  sFloatControl *float_ScaleEnd_0 = gh.Float(&para->ScaleEnd.x,0.000000f,1024.000f,0.010000f);
  float_ScaleEnd_0->Default = 1.000000f; float_ScaleEnd_0->RightStep = 0.125000f;
  sFloatControl *float_ScaleEnd_1 = gh.Float(&para->ScaleEnd.y,0.000000f,1024.000f,0.010000f);
  float_ScaleEnd_1->Default = 1.000000f; float_ScaleEnd_1->RightStep = 0.125000f;
  sFloatControl *float_ScaleEnd_2 = gh.Float(&para->ScaleEnd.z,0.000000f,1024.000f,0.010000f);
  float_ScaleEnd_2->Default = 1.000000f; float_ScaleEnd_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"RotateEnd");
  gh.BeginTied();
  sFloatControl *float_RotateEnd_0 = gh.Float(&para->RotateEnd.x,-1024.00f,1024.000f,0.001000f);
  float_RotateEnd_0->Default = 0.000000f; float_RotateEnd_0->RightStep = 0.125000f;
  sFloatControl *float_RotateEnd_1 = gh.Float(&para->RotateEnd.y,-1024.00f,1024.000f,0.001000f);
  float_RotateEnd_1->Default = 0.000000f; float_RotateEnd_1->RightStep = 0.125000f;
  sFloatControl *float_RotateEnd_2 = gh.Float(&para->RotateEnd.z,-1024.00f,1024.000f,0.001000f);
  float_RotateEnd_2->Default = 0.000000f; float_RotateEnd_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"TranslateEnd");
  gh.BeginTied();
  sFloatControl *float_TranslateEnd_0 = gh.Float(&para->TranslateEnd.x,-1024.00f,1024.000f,0.010000f);
  float_TranslateEnd_0->Default = 0.000000f; float_TranslateEnd_0->RightStep = 0.125000f;
  sFloatControl *float_TranslateEnd_1 = gh.Float(&para->TranslateEnd.y,-1024.00f,1024.000f,0.010000f);
  float_TranslateEnd_1->Default = 0.000000f; float_TranslateEnd_1->RightStep = 0.125000f;
  sFloatControl *float_TranslateEnd_2 = gh.Float(&para->TranslateEnd.z,-1024.00f,1024.000f,0.010000f);
  float_TranslateEnd_2->Default = 0.000000f; float_TranslateEnd_2->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4MeshDefTransformRange(wOp *op)
{
  Wz4MeshParaTransformRange sUNUSED *para = (Wz4MeshParaTransformRange *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->AxialRange.x = 1.000000f;
  para->AxialRange.y = -1.00000f;
  para->ScaleStart.x = 1.000000f;
  para->ScaleStart.y = 1.000000f;
  para->ScaleStart.z = 1.000000f;
  para->ScaleEnd.x = 1.000000f;
  para->ScaleEnd.y = 1.000000f;
  para->ScaleEnd.z = 1.000000f;
}

void Wz4MeshBindTransformRange(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"direction"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"direction"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"axialrange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"axialrange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scalestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scalestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"scalestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotatestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotatestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"rotatestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"translatestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"translatestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"translatestart"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"scaleend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"scaleend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"scaleend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"rotateend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"rotateend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"rotateend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"translateend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"translateend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"translateend"),val);
}
void Wz4MeshBind2TransformRange(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
    name[1] = sPoolString(L"mode");
    name[2] = sPoolString(L"direction");
    name[3] = sPoolString(L"axialrange");
    name[4] = sPoolString(L"rangemode");
    name[5] = sPoolString(L"start");
    name[6] = sPoolString(L"scalestart");
    name[7] = sPoolString(L"rotatestart");
    name[8] = sPoolString(L"translatestart");
    name[9] = sPoolString(L"end");
    name[10] = sPoolString(L"scaleend");
    name[11] = sPoolString(L"rotateend");
    name[12] = sPoolString(L"translateend");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+10);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+13);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+16);
  ctx->AddImport(name[11],ScriptTypeFloat,3,cmd->Data+19);
  ctx->AddImport(name[12],ScriptTypeFloat,3,cmd->Data+22);
}
void Wz4MeshBind3TransformRange(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import direction : float[2];\n");
  tb.PrintF(L"  import axialrange : float[2];\n");
  tb.PrintF(L"  import scalestart : float[3];\n");
  tb.PrintF(L"  import rotatestart : float[3];\n");
  tb.PrintF(L"  import translatestart : float[3];\n");
  tb.PrintF(L"  import scaleend : float[3];\n");
  tb.PrintF(L"  import rotateend : float[3];\n");
  tb.PrintF(L"  import translateend : float[3];\n");
}
const sChar *Wz4MeshWikiTransformRange =
L"= Wz4Mesh : TransformRange\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TransformRange\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i smooth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tent\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tent smooth\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Direction\n"
L" !i Direction\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i AxialRange\n"
L" !i AxialRange\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i RangeMode\n"
L" !i RangeMode\n"
L" !i auto\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i manual\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ScaleStart\n"
L" !i ScaleStart\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i RotateStart\n"
L" !i RotateStart\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TranslateStart\n"
L" !i TranslateStart\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i ScaleEnd\n"
L" !i ScaleEnd\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i RotateEnd\n"
L" !i RotateEnd\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i TranslateEnd\n"
L" !i TranslateEnd\n"
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

sBool Wz4MeshCmdMirror(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaMirror sUNUSED *para = (Wz4MeshParaMirror *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 938 "wz4_mesh_ops.ops"

    out->Mirror(para->MirrorX, para->MirrorY, para->MirrorZ, para->Selection, para->Mode);    
  ;
#line 3760 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiMirror(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaMirror sUNUSED *para = (Wz4MeshParaMirror *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"MirrorX");
  gh.Flags(&para->MirrorX,L"off|on",gh.ChangeMsg);

  gh.Label(L"MirrorY");
  gh.Flags(&para->MirrorY,L"off|on",gh.ChangeMsg);

  gh.Label(L"MirrorZ");
  gh.Flags(&para->MirrorZ,L"off|on",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"*0-|recalc normal:*2-|recalc tangents",gh.ChangeMsg);
}

void Wz4MeshDefMirror(wOp *op)
{
  Wz4MeshParaMirror sUNUSED *para = (Wz4MeshParaMirror *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindMirror(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Mirror(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mirrorx");
    name[1] = sPoolString(L"mirrory");
    name[2] = sPoolString(L"mirrorz");
    name[3] = sPoolString(L"selection");
    name[4] = sPoolString(L"mode");
  }
}
void Wz4MeshBind3Mirror(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiMirror =
L"= Wz4Mesh : Mirror\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Mirror\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i MirrorX\n"
L" !i MirrorX\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MirrorY\n"
L" !i MirrorY\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MirrorZ\n"
L" !i MirrorZ\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i recalc normal\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i recalc tangents\n"
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

sBool Wz4MeshCmdCenter(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaCenter sUNUSED *para = (Wz4MeshParaCenter *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 950 "wz4_mesh_ops.ops"

    Wz4MeshVertex *mv;

    sAABBox bounds;
    sFORALL(out->Vertices,mv)
      bounds.Add(mv->Pos);

    sVector30 d = (sVector30(bounds.Max)+sVector30(bounds.Min))*-0.5f;
    sFORALL(out->Vertices,mv)
      mv->Pos += d;

    out->Flush();
  ;
#line 3937 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiCenter(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaCenter sUNUSED *para = (Wz4MeshParaCenter *)(op->EditData); para;
}

void Wz4MeshDefCenter(wOp *op)
{
  Wz4MeshParaCenter sUNUSED *para = (Wz4MeshParaCenter *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindCenter(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Center(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind3Center(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiCenter =
L"= Wz4Mesh : Center\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Center\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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

sBool Wz4MeshCmdSelectGrow(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSelectGrow sUNUSED *para = (Wz4MeshParaSelectGrow *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 980 "wz4_mesh_ops.ops"

    Wz4MeshFaceConnect *adj = out->Adjacency();
    sF32 bias = sClamp(para->Amount*para->Range*para->Bias, 0.0f, 1.0f);

    if(para->Input)
      out->SelVerticesToFaces(true, false, bias);
    else
      out->SelFacesToVertices(true, false, bias, false);

    while(para->Amount--)
      out->SelectGrow(adj, para->Amount, para->Power, para->Range);

    out->Flush();

    delete[]adj;
  ;
#line 4022 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiSelectGrow(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSelectGrow sUNUSED *para = (Wz4MeshParaSelectGrow *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Input");
  gh.Flags(&para->Input,L"face|vertices",gh.ChangeMsg);

  gh.Label(L"Amount");
  sIntControl *int_Amount = gh.Int(&para->Amount,0,1024,0.125000f);
  int_Amount->Default = 0x00000000; int_Amount->RightStep = 0.125000f;

  gh.Label(L"Range");
  sFloatControl *float_Range = gh.Float(&para->Range,0.000000f,1.000000f,0.001000f);
  float_Range->Default = 0.000000f; float_Range->RightStep = 0.125000f;

  gh.Label(L"Power");
  sIntControl *int_Power = gh.Int(&para->Power,0,256,0.125000f);
  int_Power->Default = 0x00000001; int_Power->RightStep = 0.125000f;

  gh.Label(L"Bias");
  sFloatControl *float_Bias = gh.Float(&para->Bias,0.000000f,16.00000f,0.010000f);
  float_Bias->Default = 1.000000f; float_Bias->RightStep = 0.125000f;
}

void Wz4MeshDefSelectGrow(wOp *op)
{
  Wz4MeshParaSelectGrow sUNUSED *para = (Wz4MeshParaSelectGrow *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Power = 0x00000001;
  para->Bias = 1.000000f;
}

void Wz4MeshBindSelectGrow(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"range"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"power"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
}
void Wz4MeshBind2SelectGrow(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"input");
    name[1] = sPoolString(L"amount");
    name[2] = sPoolString(L"range");
    name[3] = sPoolString(L"power");
    name[4] = sPoolString(L"bias");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
}
void Wz4MeshBind3SelectGrow(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import amount : int;\n");
  tb.PrintF(L"  import range : float;\n");
  tb.PrintF(L"  import power : int;\n");
  tb.PrintF(L"  import bias : float;\n");
}
const sChar *Wz4MeshWikiSelectGrow =
L"= Wz4Mesh : SelectGrow\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SelectGrow\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Input\n"
L" !i Input\n"
L" !i face\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i vertices\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Amount\n"
L" !i Amount\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Range\n"
L" !i Range\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Power\n"
L" !i Power\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
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

sBool Wz4MeshCmdMultiply(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaMultiply sUNUSED *para = (Wz4MeshParaMultiply *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1013 "wz4_mesh_ops.ops"

    sMatrix34 mat,mat0,mat1,matInvT;
    sSRT srt;
    Wz4MeshVertex *mv;

    srt.Scale = para->Scale;
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.MakeMatrix(mat1);


    for(sInt i=0;i<para->Count;i++)
      out->Add(in0);

    sInt vc = in0->Vertices.GetCount();
    mv = out->Vertices.GetData();
    mat.Init();
    mv += vc;
    for(sInt i=1;i<para->Count;i++)
    {
//      mat = mat * mat1;
      mat = mat1 * mat;         // seems to be the same... strange...
      matInvT = mat;
      matInvT.Invert3();
      matInvT.Trans3();
      for(sInt j=0;j<vc;j++)
      {
        mv->Transform(mat,matInvT);
        mv++;
      }

    }

    if(para->Flags & 1)
    {
      mat.Init();
      mat.l = sVector31(sVector30(para->Trans) * (-sF32(para->Count-1)*0.5f));
      out->Transform(mat);
    }

    out->Flush();
  ;
#line 4227 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiMultiply(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaMultiply sUNUSED *para = (Wz4MeshParaMultiply *)(op->EditData); para;
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

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Center",gh.ChangeMsg);
}

void Wz4MeshDefMultiply(wOp *op)
{
  Wz4MeshParaMultiply sUNUSED *para = (Wz4MeshParaMultiply *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Count = 0x00000002;
}

void Wz4MeshBindMultiply(wCommand *cmd,ScriptContext *ctx)
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
void Wz4MeshBind2Multiply(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"count");
    name[4] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+9);
}
void Wz4MeshBind3Multiply(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import count : int;\n");
}
const sChar *Wz4MeshWikiMultiply =
L"= Wz4Mesh : Multiply\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Multiply\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Center\n"
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

sBool Wz4MeshCmdMultiplyNew(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaMultiplyNew sUNUSED *para = (Wz4MeshParaMultiplyNew *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1078 "wz4_mesh_ops.ops"

    sMatrix34 PreMat;
    sMatrix34 MulMat;
    sMatrix34 accu;
    sMatrix34 mat0,mati;
    sSRT srt;
    Wz4MeshVertex *mv;

    srt.Scale = para->Scale;
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.MakeMatrix(MulMat);

    srt.Scale = para->PreScale;
    srt.Rotate = para->PreRot;
    srt.Translate = para->PreTrans;
    srt.MakeMatrix(PreMat);

    if((para->Flags & 1) && para->Count>1)
      accu.l = sVector31(sVector30(para->Trans) * (-sF32(para->Count-1)*0.5f));

    for(sInt i=0;i<para->Count;i++)
      out->Add(in0);

    sInt vc = in0->Vertices.GetCount();
    mv = out->Vertices.GetData();
    for(sInt i=0;i<para->Count;i++)
    {
      mat0 = PreMat*accu;
      mati = mat0;
      mati.Invert3();
      mati.Trans3();
      for(sInt j=0;j<vc;j++)
      {
        mv->Transform(mat0,mati);
        mv++;
      }
      accu = accu * MulMat;
    }

    out->Flush();
  ;
#line 4465 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiMultiplyNew(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaMultiplyNew sUNUSED *para = (Wz4MeshParaMultiplyNew *)(op->EditData); para;
  gh.Group(op->Class->Label);

  if(0x0000)
  {
    gh.Label(L"Renderpass");
    sIntControl *int_Renderpass = gh.Int(&para->Renderpass,-127,127,0.125000f);
    int_Renderpass->Default = 0x00000000; int_Renderpass->RightStep = 0.125000f;

  }
  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Center",gh.ChangeMsg);

  gh.Group(L"Pre-Transform");

  gh.Label(L"* PreScale");
  gh.BeginTied();
  sFloatControl *float_PreScale_0 = gh.Float(&para->PreScale.x,-1024.00f,1024.000f,0.010000f);
  float_PreScale_0->Default = 1.000000f; float_PreScale_0->RightStep = 0.125000f;
  sFloatControl *float_PreScale_1 = gh.Float(&para->PreScale.y,-1024.00f,1024.000f,0.010000f);
  float_PreScale_1->Default = 1.000000f; float_PreScale_1->RightStep = 0.125000f;
  sFloatControl *float_PreScale_2 = gh.Float(&para->PreScale.z,-1024.00f,1024.000f,0.010000f);
  float_PreScale_2->Default = 1.000000f; float_PreScale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* PreRot");
  gh.BeginTied();
  sFloatControl *float_PreRot_0 = gh.Float(&para->PreRot.x,-16.0000f,16.00000f,0.010000f);
  float_PreRot_0->Default = 0.000000f; float_PreRot_0->RightStep = 0.125000f;
  sFloatControl *float_PreRot_1 = gh.Float(&para->PreRot.y,-16.0000f,16.00000f,0.010000f);
  float_PreRot_1->Default = 0.000000f; float_PreRot_1->RightStep = 0.125000f;
  sFloatControl *float_PreRot_2 = gh.Float(&para->PreRot.z,-16.0000f,16.00000f,0.010000f);
  float_PreRot_2->Default = 0.000000f; float_PreRot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* PreTrans");
  gh.BeginTied();
  sFloatControl *float_PreTrans_0 = gh.Float(&para->PreTrans.x,-65536.0f,65536.00f,0.010000f);
  float_PreTrans_0->Default = 0.000000f; float_PreTrans_0->RightStep = 0.125000f;
  sFloatControl *float_PreTrans_1 = gh.Float(&para->PreTrans.y,-65536.0f,65536.00f,0.010000f);
  float_PreTrans_1->Default = 0.000000f; float_PreTrans_1->RightStep = 0.125000f;
  sFloatControl *float_PreTrans_2 = gh.Float(&para->PreTrans.z,-65536.0f,65536.00f,0.010000f);
  float_PreTrans_2->Default = 0.000000f; float_PreTrans_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Multiply Transform");

  gh.Label(L"* Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,1024,0.125000f);
  int_Count->Default = 0x00000002; int_Count->RightStep = 0.125000f;

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
  sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.010000f);
  float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
  sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.010000f);
  float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
  sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.010000f);
  float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Trans");
  gh.BeginTied();
  sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-65536.0f,65536.00f,0.010000f);
  float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
  sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-65536.0f,65536.00f,0.010000f);
  float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
  sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-65536.0f,65536.00f,0.010000f);
  float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4MeshDefMultiplyNew(wOp *op)
{
  Wz4MeshParaMultiplyNew sUNUSED *para = (Wz4MeshParaMultiplyNew *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->PreScale.x = 1.000000f;
  para->PreScale.y = 1.000000f;
  para->PreScale.z = 1.000000f;
  para->Count = 0x00000002;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void Wz4MeshBindMultiplyNew(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"renderpass"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"prescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"prescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"prescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"prerot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"prerot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"prerot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"pretrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"pretrans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"pretrans"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
}
void Wz4MeshBind2MultiplyNew(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"renderpass");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"");
    name[3] = sPoolString(L"prescale");
    name[4] = sPoolString(L"prerot");
    name[5] = sPoolString(L"pretrans");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"count");
    name[8] = sPoolString(L"scale");
    name[9] = sPoolString(L"rot");
    name[10] = sPoolString(L"trans");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+12);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+15);
  ctx->AddImport(name[10],ScriptTypeFloat,3,cmd->Data+18);
}
void Wz4MeshBind3MultiplyNew(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import renderpass : int;\n");
  tb.PrintF(L"  import prescale : float[3];\n");
  tb.PrintF(L"  import prerot : float[3];\n");
  tb.PrintF(L"  import pretrans : float[3];\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *Wz4MeshWikiMultiplyNew =
L"= Wz4Mesh : MultiplyNew\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MultiplyNew\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Renderpass\n"
L" !i Renderpass\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Center\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i PreScale\n"
L" !i PreScale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i PreRot\n"
L" !i PreRot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i PreTrans\n"
L" !i PreTrans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
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

sBool Wz4MeshCmdTransformEx(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTransformEx sUNUSED *para = (Wz4MeshParaTransformEx *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1144 "wz4_mesh_ops.ops"

    sMatrix34 mat;
    sSRT srt;
    Wz4MeshVertex *mv;

    srt.Scale = para->Scale;
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.MakeMatrix(mat);

    sVector4 v;
    sFORALL(out->Vertices,mv)
    {
      sF32 sel = logicF(para->Selection,mv->Select);
      if(sel>0)
      {
        switch(para->Flags & 15)
        {
          case 0:  v = mv->Pos; break;
          case 1:  v = mv->Normal; break;
          case 2:  v = mv->Tangent; break;
          case 3:  v.Init(mv->U0,mv->V0,0,1); break;
          case 4:  v.Init(mv->U1,mv->V1,0,1); break;
#if !WZ4MESH_LOWMEM
          case 5:  v.InitColor(mv->Color0);
          case 6:  v.InitColor(mv->Color1);
#endif
        }

        v = sFade(sel,v,v*mat);

        switch((para->Flags>>4) & 15)
        {
          case 0:  mv->Pos = sVector31(v); break;
          case 1:  mv->Normal = sVector30(v); break;
          case 2:  mv->Tangent = sVector30(v); break;
          case 3:  mv->U0 = v.x; mv->V0 = v.y; break;
          case 4:  mv->U1 = v.x; mv->V1 = v.y; break;
#if !WZ4MESH_LOWMEM
          case 5:  mv->Color0 = v.GetColor(); break;
          case 6:  mv->Color1 = v.GetColor(); break;
#endif
        }
      }
    }
    out->Flush();
  ;
#line 4817 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTransformEx(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTransformEx sUNUSED *para = (Wz4MeshParaTransformEx *)(op->EditData); para;
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

  gh.Label(L"Input");
  gh.Flags(&para->Flags,L"pos|normal|tangent|uv0|uv1|color0|color1",gh.ChangeMsg);

  gh.Label(L"Output");
  gh.Flags(&para->Flags,L"*4pos|normal|tangent|uv0|uv1|color0|color1",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.LayoutMsg);

  if((para->Selection&0x0002))
  {
    gh.Flags(&para->Selection,L"*2-|soft",gh.ChangeMsg);
  }
}

void Wz4MeshDefTransformEx(wOp *op)
{
  Wz4MeshParaTransformEx sUNUSED *para = (Wz4MeshParaTransformEx *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Flags = 0x00000033;
}

void Wz4MeshBindTransformEx(wCommand *cmd,ScriptContext *ctx)
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
void Wz4MeshBind2TransformEx(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"input");
    name[4] = sPoolString(L"output");
    name[5] = sPoolString(L"selection");
    name[6] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
}
void Wz4MeshBind3TransformEx(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *Wz4MeshWikiTransformEx =
L"= Wz4Mesh : TransformEx\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TransformEx\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Input\n"
L" !i Flags\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
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
L" !i color0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Output\n"
L" !i Flags\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
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
L" !i color0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Selection\n"
L" !i soft\n"
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

sBool Wz4MeshCmdTransformMatrix(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTransformMatrix sUNUSED *para = (Wz4MeshParaTransformMatrix *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1214 "wz4_mesh_ops.ops"

    sMatrix34 mat;
    Wz4MeshVertex *mv;

    mat.i.Init(para->x[0],para->y[0],para->z[0]);
    mat.j.Init(para->x[1],para->y[1],para->z[1]);
    mat.k.Init(para->x[2],para->y[2],para->z[2]);
    mat.l.Init(para->x[3],para->y[3],para->z[3]);

    sVector4 v;
    sFORALL(out->Vertices,mv)
    {
      sF32 sel = logicF(para->Selection,mv->Select);
      if(sel>0)
      {
        switch(para->Flags & 15)
        {
          case 0:  v = mv->Pos; break;
          case 1:  v = mv->Normal; break;
          case 2:  v = mv->Tangent; break;
          case 3:  v.Init(mv->U0,mv->V0,0,1); break;
          case 4:  v.Init(mv->U1,mv->V1,0,1); break;
#if !WZ4MESH_LOWMEM
          case 5:  v.InitColor(mv->Color0);
          case 6:  v.InitColor(mv->Color1);
#endif
        }

        v = sFade(sel,v,v*mat);

        switch((para->Flags>>4) & 15)
        {
          case 0:  mv->Pos = sVector31(v); break;
          case 1:  mv->Normal = sVector30(v); break;
          case 2:  mv->Tangent = sVector30(v); break;
          case 3:  mv->U0 = v.x; mv->V0 = v.y; break;
          case 4:  mv->U1 = v.x; mv->V1 = v.y; break;
#if !WZ4MESH_LOWMEM
          case 5:  mv->Color0 = v.GetColor(); break;
          case 6:  mv->Color1 = v.GetColor(); break;
#endif
        }
      }
    }
    out->Flush();
  ;
#line 5133 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTransformMatrix(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTransformMatrix sUNUSED *para = (Wz4MeshParaTransformMatrix *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"x =");
  gh.BeginTied();
  sFloatControl *float_x_0 = gh.Float(&para->x[0],-1024.00f,1024.000f,0.010000f);
  float_x_0->Default = 1.000000f; float_x_0->RightStep = 0.125000f;
  sFloatControl *float_x_1 = gh.Float(&para->x[1],-1024.00f,1024.000f,0.010000f);
  float_x_1->Default = 0.000000f; float_x_1->RightStep = 0.125000f;
  sFloatControl *float_x_2 = gh.Float(&para->x[2],-1024.00f,1024.000f,0.010000f);
  float_x_2->Default = 0.000000f; float_x_2->RightStep = 0.125000f;
  sFloatControl *float_x_3 = gh.Float(&para->x[3],-1024.00f,1024.000f,0.010000f);
  float_x_3->Default = 0.000000f; float_x_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"y =");
  gh.BeginTied();
  sFloatControl *float_y_0 = gh.Float(&para->y[0],-1024.00f,1024.000f,0.010000f);
  float_y_0->Default = 0.000000f; float_y_0->RightStep = 0.125000f;
  sFloatControl *float_y_1 = gh.Float(&para->y[1],-1024.00f,1024.000f,0.010000f);
  float_y_1->Default = 1.000000f; float_y_1->RightStep = 0.125000f;
  sFloatControl *float_y_2 = gh.Float(&para->y[2],-1024.00f,1024.000f,0.010000f);
  float_y_2->Default = 0.000000f; float_y_2->RightStep = 0.125000f;
  sFloatControl *float_y_3 = gh.Float(&para->y[3],-1024.00f,1024.000f,0.010000f);
  float_y_3->Default = 0.000000f; float_y_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"z =");
  gh.BeginTied();
  sFloatControl *float_z_0 = gh.Float(&para->z[0],-1024.00f,1024.000f,0.010000f);
  float_z_0->Default = 0.000000f; float_z_0->RightStep = 0.125000f;
  sFloatControl *float_z_1 = gh.Float(&para->z[1],-1024.00f,1024.000f,0.010000f);
  float_z_1->Default = 0.000000f; float_z_1->RightStep = 0.125000f;
  sFloatControl *float_z_2 = gh.Float(&para->z[2],-1024.00f,1024.000f,0.010000f);
  float_z_2->Default = 1.000000f; float_z_2->RightStep = 0.125000f;
  sFloatControl *float_z_3 = gh.Float(&para->z[3],-1024.00f,1024.000f,0.010000f);
  float_z_3->Default = 0.000000f; float_z_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Input");
  gh.Flags(&para->Flags,L"pos|normal|tangent|uv0|uv1|color0|color1",gh.ChangeMsg);

  gh.Label(L"Output");
  gh.Flags(&para->Flags,L"*4pos|normal|tangent|uv0|uv1|color0|color1",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.LayoutMsg);

  if((para->Selection&0x0002))
  {
    gh.Flags(&para->Selection,L"*2-|soft",gh.ChangeMsg);
  }
}

void Wz4MeshDefTransformMatrix(wOp *op)
{
  Wz4MeshParaTransformMatrix sUNUSED *para = (Wz4MeshParaTransformMatrix *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->x[0] = 1.000000f;
  para->y[1] = 1.000000f;
  para->z[2] = 1.000000f;
}

void Wz4MeshBindTransformMatrix(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
}
void Wz4MeshBind2TransformMatrix(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"x");
    name[1] = sPoolString(L"y");
    name[2] = sPoolString(L"z");
    name[3] = sPoolString(L"input");
    name[4] = sPoolString(L"output");
    name[5] = sPoolString(L"selection");
    name[6] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,4,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,4,cmd->Data+4);
  ctx->AddImport(name[2],ScriptTypeFloat,4,cmd->Data+8);
}
void Wz4MeshBind3TransformMatrix(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import x : float[4];\n");
  tb.PrintF(L"  import y : float[4];\n");
  tb.PrintF(L"  import z : float[4];\n");
}
const sChar *Wz4MeshWikiTransformMatrix =
L"= Wz4Mesh : TransformMatrix\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TransformMatrix\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i x =\n"
L" !i x\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i y =\n"
L" !i y\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i z =\n"
L" !i z\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Input\n"
L" !i Flags\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
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
L" !i color0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Output\n"
L" !i Flags\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
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
L" !i color0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Selection\n"
L" !i soft\n"
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

sBool Wz4MeshCmdTransformNonLinear(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTransformNonLinear sUNUSED *para = (Wz4MeshParaTransformNonLinear *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1292 "wz4_mesh_ops.ops"

    sMatrix34 mat;
    Wz4MeshVertex *mv;

    sVector4 v,vv;
    sFORALL(out->Vertices,mv)
    {
      sF32 sel = logicF(para->Selection,mv->Select);
      if(sel>0)
      {
        switch(para->Flags & 15)
        {
          case 0:  v = mv->Pos; break;
          case 1:  v = mv->Normal; break;
          case 2:  v = mv->Tangent; break;
          case 3:  v.Init(mv->U0,mv->V0,0,1); break;
          case 4:  v.Init(mv->U1,mv->V1,0,1); break;
#if !WZ4MESH_LOWMEM
          case 5:  v.InitColor(mv->Color0);
          case 6:  v.InitColor(mv->Color1);
#endif
        }

        vv.x = (para->x1^v) * (para->x2^(v*v)) / (para->xr^v);
        vv.y = (para->y1^v) * (para->y2^(v*v)) / (para->yr^v);
        vv.z = (para->z1^v) * (para->z2^(v*v)) / (para->zr^v);
        v = sFade(sel,v,vv);

        switch((para->Flags>>4) & 15)
        {
          case 0:  mv->Pos = sVector31(v); break;
          case 1:  mv->Normal = sVector30(v); break;
          case 2:  mv->Tangent = sVector30(v); break;
          case 3:  mv->U0 = v.x; mv->V0 = v.y; break;
          case 4:  mv->U1 = v.x; mv->V1 = v.y; break;
#if !WZ4MESH_LOWMEM
          case 5:  mv->Color0 = v.GetColor(); break;
          case 6:  mv->Color1 = v.GetColor(); break;
#endif
        }
      }
    }
    out->Flush();
  ;
#line 5461 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTransformNonLinear(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTransformNonLinear sUNUSED *para = (Wz4MeshParaTransformNonLinear *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Input");
  gh.Flags(&para->Flags,L"pos|normal|tangent|uv0|uv1|color0|color1",gh.ChangeMsg);

  gh.Label(L"Output");
  gh.Flags(&para->Flags,L"*4pos|normal|tangent|uv0|uv1|color0|color1",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.LayoutMsg);

  if((para->Selection&0x0002))
  {
    gh.Flags(&para->Selection,L"*2-|soft",gh.ChangeMsg);

  }
  gh.Group(L"X^1");

  gh.Label(L"x");
  gh.BeginTied();
  sFloatControl *float_x1_0 = gh.Float(&para->x1.x,-1024.00f,1024.000f,0.010000f);
  float_x1_0->Default = 1.000000f; float_x1_0->RightStep = 0.125000f;
  sFloatControl *float_x1_1 = gh.Float(&para->x1.y,-1024.00f,1024.000f,0.010000f);
  float_x1_1->Default = 0.000000f; float_x1_1->RightStep = 0.125000f;
  sFloatControl *float_x1_2 = gh.Float(&para->x1.z,-1024.00f,1024.000f,0.010000f);
  float_x1_2->Default = 0.000000f; float_x1_2->RightStep = 0.125000f;
  sFloatControl *float_x1_3 = gh.Float(&para->x1.w,-1024.00f,1024.000f,0.010000f);
  float_x1_3->Default = 0.000000f; float_x1_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"y");
  gh.BeginTied();
  sFloatControl *float_y1_0 = gh.Float(&para->y1.x,-1024.00f,1024.000f,0.010000f);
  float_y1_0->Default = 0.000000f; float_y1_0->RightStep = 0.125000f;
  sFloatControl *float_y1_1 = gh.Float(&para->y1.y,-1024.00f,1024.000f,0.010000f);
  float_y1_1->Default = 1.000000f; float_y1_1->RightStep = 0.125000f;
  sFloatControl *float_y1_2 = gh.Float(&para->y1.z,-1024.00f,1024.000f,0.010000f);
  float_y1_2->Default = 0.000000f; float_y1_2->RightStep = 0.125000f;
  sFloatControl *float_y1_3 = gh.Float(&para->y1.w,-1024.00f,1024.000f,0.010000f);
  float_y1_3->Default = 0.000000f; float_y1_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"z");
  gh.BeginTied();
  sFloatControl *float_z1_0 = gh.Float(&para->z1.x,-1024.00f,1024.000f,0.010000f);
  float_z1_0->Default = 0.000000f; float_z1_0->RightStep = 0.125000f;
  sFloatControl *float_z1_1 = gh.Float(&para->z1.y,-1024.00f,1024.000f,0.010000f);
  float_z1_1->Default = 0.000000f; float_z1_1->RightStep = 0.125000f;
  sFloatControl *float_z1_2 = gh.Float(&para->z1.z,-1024.00f,1024.000f,0.010000f);
  float_z1_2->Default = 1.000000f; float_z1_2->RightStep = 0.125000f;
  sFloatControl *float_z1_3 = gh.Float(&para->z1.w,-1024.00f,1024.000f,0.010000f);
  float_z1_3->Default = 0.000000f; float_z1_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"X^2");

  gh.Label(L"x");
  gh.BeginTied();
  sFloatControl *float_x2_0 = gh.Float(&para->x2.x,-1024.00f,1024.000f,0.010000f);
  float_x2_0->Default = 0.000000f; float_x2_0->RightStep = 0.125000f;
  sFloatControl *float_x2_1 = gh.Float(&para->x2.y,-1024.00f,1024.000f,0.010000f);
  float_x2_1->Default = 0.000000f; float_x2_1->RightStep = 0.125000f;
  sFloatControl *float_x2_2 = gh.Float(&para->x2.z,-1024.00f,1024.000f,0.010000f);
  float_x2_2->Default = 0.000000f; float_x2_2->RightStep = 0.125000f;
  sFloatControl *float_x2_3 = gh.Float(&para->x2.w,-1024.00f,1024.000f,0.010000f);
  float_x2_3->Default = 1.000000f; float_x2_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"y");
  gh.BeginTied();
  sFloatControl *float_y2_0 = gh.Float(&para->y2.x,-1024.00f,1024.000f,0.010000f);
  float_y2_0->Default = 0.000000f; float_y2_0->RightStep = 0.125000f;
  sFloatControl *float_y2_1 = gh.Float(&para->y2.y,-1024.00f,1024.000f,0.010000f);
  float_y2_1->Default = 0.000000f; float_y2_1->RightStep = 0.125000f;
  sFloatControl *float_y2_2 = gh.Float(&para->y2.z,-1024.00f,1024.000f,0.010000f);
  float_y2_2->Default = 0.000000f; float_y2_2->RightStep = 0.125000f;
  sFloatControl *float_y2_3 = gh.Float(&para->y2.w,-1024.00f,1024.000f,0.010000f);
  float_y2_3->Default = 1.000000f; float_y2_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"z");
  gh.BeginTied();
  sFloatControl *float_z2_0 = gh.Float(&para->z2.x,-1024.00f,1024.000f,0.010000f);
  float_z2_0->Default = 0.000000f; float_z2_0->RightStep = 0.125000f;
  sFloatControl *float_z2_1 = gh.Float(&para->z2.y,-1024.00f,1024.000f,0.010000f);
  float_z2_1->Default = 0.000000f; float_z2_1->RightStep = 0.125000f;
  sFloatControl *float_z2_2 = gh.Float(&para->z2.z,-1024.00f,1024.000f,0.010000f);
  float_z2_2->Default = 0.000000f; float_z2_2->RightStep = 0.125000f;
  sFloatControl *float_z2_3 = gh.Float(&para->z2.w,-1024.00f,1024.000f,0.010000f);
  float_z2_3->Default = 1.000000f; float_z2_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"X^-1");

  gh.Label(L"x");
  gh.BeginTied();
  sFloatControl *float_xr_0 = gh.Float(&para->xr.x,-1024.00f,1024.000f,0.010000f);
  float_xr_0->Default = 0.000000f; float_xr_0->RightStep = 0.125000f;
  sFloatControl *float_xr_1 = gh.Float(&para->xr.y,-1024.00f,1024.000f,0.010000f);
  float_xr_1->Default = 0.000000f; float_xr_1->RightStep = 0.125000f;
  sFloatControl *float_xr_2 = gh.Float(&para->xr.z,-1024.00f,1024.000f,0.010000f);
  float_xr_2->Default = 0.000000f; float_xr_2->RightStep = 0.125000f;
  sFloatControl *float_xr_3 = gh.Float(&para->xr.w,-1024.00f,1024.000f,0.010000f);
  float_xr_3->Default = 1.000000f; float_xr_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"y");
  gh.BeginTied();
  sFloatControl *float_yr_0 = gh.Float(&para->yr.x,-1024.00f,1024.000f,0.010000f);
  float_yr_0->Default = 0.000000f; float_yr_0->RightStep = 0.125000f;
  sFloatControl *float_yr_1 = gh.Float(&para->yr.y,-1024.00f,1024.000f,0.010000f);
  float_yr_1->Default = 0.000000f; float_yr_1->RightStep = 0.125000f;
  sFloatControl *float_yr_2 = gh.Float(&para->yr.z,-1024.00f,1024.000f,0.010000f);
  float_yr_2->Default = 0.000000f; float_yr_2->RightStep = 0.125000f;
  sFloatControl *float_yr_3 = gh.Float(&para->yr.w,-1024.00f,1024.000f,0.010000f);
  float_yr_3->Default = 1.000000f; float_yr_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"z");
  gh.BeginTied();
  sFloatControl *float_zr_0 = gh.Float(&para->zr.x,-1024.00f,1024.000f,0.010000f);
  float_zr_0->Default = 0.000000f; float_zr_0->RightStep = 0.125000f;
  sFloatControl *float_zr_1 = gh.Float(&para->zr.y,-1024.00f,1024.000f,0.010000f);
  float_zr_1->Default = 0.000000f; float_zr_1->RightStep = 0.125000f;
  sFloatControl *float_zr_2 = gh.Float(&para->zr.z,-1024.00f,1024.000f,0.010000f);
  float_zr_2->Default = 0.000000f; float_zr_2->RightStep = 0.125000f;
  sFloatControl *float_zr_3 = gh.Float(&para->zr.w,-1024.00f,1024.000f,0.010000f);
  float_zr_3->Default = 1.000000f; float_zr_3->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4MeshDefTransformNonLinear(wOp *op)
{
  Wz4MeshParaTransformNonLinear sUNUSED *para = (Wz4MeshParaTransformNonLinear *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->x1.x = 1.000000f;
  para->y1.y = 1.000000f;
  para->z1.z = 1.000000f;
  para->x2.w = 1.000000f;
  para->y2.w = 1.000000f;
  para->z2.w = 1.000000f;
  para->xr.w = 1.000000f;
  para->yr.w = 1.000000f;
  para->zr.w = 1.000000f;
}

void Wz4MeshBindTransformNonLinear(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"x"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+30;
  ctx->BindLocal(ctx->AddSymbol(L"y"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+34;
  ctx->BindLocal(ctx->AddSymbol(L"z"),val);
}
void Wz4MeshBind2TransformNonLinear(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[16];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"input");
    name[1] = sPoolString(L"output");
    name[2] = sPoolString(L"selection");
    name[3] = sPoolString(L"selection");
    name[4] = sPoolString(L"");
    name[5] = sPoolString(L"x");
    name[6] = sPoolString(L"y");
    name[7] = sPoolString(L"z");
    name[8] = sPoolString(L"");
    name[9] = sPoolString(L"x");
    name[10] = sPoolString(L"y");
    name[11] = sPoolString(L"z");
    name[12] = sPoolString(L"");
    name[13] = sPoolString(L"x");
    name[14] = sPoolString(L"y");
    name[15] = sPoolString(L"z");
  }
  ctx->AddImport(name[5],ScriptTypeFloat,4,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeFloat,4,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeFloat,4,cmd->Data+10);
  ctx->AddImport(name[9],ScriptTypeFloat,4,cmd->Data+14);
  ctx->AddImport(name[10],ScriptTypeFloat,4,cmd->Data+18);
  ctx->AddImport(name[11],ScriptTypeFloat,4,cmd->Data+22);
  ctx->AddImport(name[13],ScriptTypeFloat,4,cmd->Data+26);
  ctx->AddImport(name[14],ScriptTypeFloat,4,cmd->Data+30);
  ctx->AddImport(name[15],ScriptTypeFloat,4,cmd->Data+34);
}
void Wz4MeshBind3TransformNonLinear(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import x : float[4];\n");
  tb.PrintF(L"  import y : float[4];\n");
  tb.PrintF(L"  import z : float[4];\n");
  tb.PrintF(L"  import x : float[4];\n");
  tb.PrintF(L"  import y : float[4];\n");
  tb.PrintF(L"  import z : float[4];\n");
  tb.PrintF(L"  import x : float[4];\n");
  tb.PrintF(L"  import y : float[4];\n");
  tb.PrintF(L"  import z : float[4];\n");
}
const sChar *Wz4MeshWikiTransformNonLinear =
L"= Wz4Mesh : TransformNonLinear\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TransformNonLinear\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Input\n"
L" !i Flags\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
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
L" !i color0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Output\n"
L" !i Flags\n"
L" !i pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
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
L" !i color0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i color1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i <NULL>\n"
L" !i Selection\n"
L" !i soft\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i x\n"
L" !i x1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i y\n"
L" !i y1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i z\n"
L" !i z1\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i x\n"
L" !i x2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i y\n"
L" !i y2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i z\n"
L" !i z2\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i x\n"
L" !i xr\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i y\n"
L" !i yr\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i z\n"
L" !i zr\n"
L" !i float[4]\n"
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

sBool Wz4MeshCmdExtrudeNormal(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaExtrudeNormal sUNUSED *para = (Wz4MeshParaExtrudeNormal *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1350 "wz4_mesh_ops.ops"

    out->ExtrudeNormal(para->Selection,para->Amount);
    out->Flush();
  ;
#line 5957 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiExtrudeNormal(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaExtrudeNormal sUNUSED *para = (Wz4MeshParaExtrudeNormal *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Amount");
  sFloatControl *float_Amount = gh.Float(&para->Amount,-1024.00f,1024.000f,0.001000f);
  float_Amount->Default = 0.250000f; float_Amount->RightStep = 0.125000f;

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefExtrudeNormal(wOp *op)
{
  Wz4MeshParaExtrudeNormal sUNUSED *para = (Wz4MeshParaExtrudeNormal *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Amount = 0.250000f;
}

void Wz4MeshBindExtrudeNormal(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
}
void Wz4MeshBind2ExtrudeNormal(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"amount");
    name[1] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void Wz4MeshBind3ExtrudeNormal(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import amount : float;\n");
}
const sChar *Wz4MeshWikiExtrudeNormal =
L"= Wz4Mesh : ExtrudeNormal\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ExtrudeNormal\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Amount\n"
L" !i Amount\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

struct Wz4MeshHelperBend
{
#line 1419 "wz4_mesh_ops.ops"
  sVector31 hup;
#line 1420 "wz4_mesh_ops.ops"
  sVector31 haxis;
#line 6079 "wz4_mesh_ops.cpp"
};
sBool Wz4MeshCmdBend(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaBend sUNUSED *para = (Wz4MeshParaBend *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1373 "wz4_mesh_ops.ops"

    sVector4 plane; 
    Wz4MeshVertex *mv;
    sMatrix34 mat;
    sVector30 d0;

    sVector30 dir = para->Up;
    sVector30 axis = para->Axis;
    dir.Unit();
    axis.Unit();
    d0.Cross(dir,axis);
    d0 *= para->Radius;

    plane.InitPlane(para->Start,dir);

    sFORALL(out->Vertices,mv)
    {
      sF32 sel = logicF(para->Selection,mv->Select);
      if(sel>0)
      {
        sF32 d = plane ^ mv->Pos;
        sF32 angle,move;
        if(para->Flags)
        {
          angle = sClamp<sF32>(d/para->Radius,0,para->Angle*6);
          move = angle*para->Radius;
          angle = angle * (sPI2F/6);
        }
        else
        {
          angle = sClamp<sF32>(d/para->Radius,0,para->Angle*sPI2F);
          move = angle*para->Radius;
        }

        if(angle>=0)
        {
          mat.RotateAxis(axis,-angle);
          mat.l = para->Start-d0 - sVector30(para->Start+move*dir-d0)*mat;
          mv->Transform(mat,mat);
        }
      }
    }
    out->Flush();
  ;
#line 6133 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshHndBend(wPaintInfo &pi,wOp *op)
{
  Wz4MeshParaBend sUNUSED *para = (Wz4MeshParaBend *)(op->EditData); para;
  Wz4MeshHelperBend *helper = (Wz4MeshHelperBend *)(op->HelperData);
#line 1423 "wz4_mesh_ops.ops"

    if(pi.IsSelected(op,2))
      para->Up = helper->hup-para->Start;

    if(pi.IsSelected(op,3))
      para->Axis = helper->haxis-para->Start;

    helper->hup = para->Start + para->Up;
    helper->haxis = para->Start + para->Axis;
    pi.Handle3D(op,1,para->Start,wHM_PLANE);
    pi.Handle3D(op,2,helper->hup,wHM_PLANE);
    pi.Handle3D(op,3,helper->haxis,wHM_PLANE);
    pi.Line3D(para->Start,helper->hup);
    pi.Line3D(para->Start,helper->haxis);
  ;
#line 6158 "wz4_mesh_ops.cpp"
}

void Wz4MeshGuiBend(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaBend sUNUSED *para = (Wz4MeshParaBend *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Start");
  gh.BeginTied();
  sFloatControl *float_Start_0 = gh.Float(&para->Start.x,-1024.00f,1024.000f,0.001000f);
  float_Start_0->Default = 0.000000f; float_Start_0->RightStep = 0.125000f;
  sFloatControl *float_Start_1 = gh.Float(&para->Start.y,-1024.00f,1024.000f,0.001000f);
  float_Start_1->Default = 0.000000f; float_Start_1->RightStep = 0.125000f;
  sFloatControl *float_Start_2 = gh.Float(&para->Start.z,-1024.00f,1024.000f,0.001000f);
  float_Start_2->Default = 0.000000f; float_Start_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Up");
  gh.BeginTied();
  sFloatControl *float_Up_0 = gh.Float(&para->Up.x,-1024.00f,1024.000f,0.001000f);
  float_Up_0->Default = 0.000000f; float_Up_0->RightStep = 0.125000f;
  sFloatControl *float_Up_1 = gh.Float(&para->Up.y,-1024.00f,1024.000f,0.001000f);
  float_Up_1->Default = 1.000000f; float_Up_1->RightStep = 0.125000f;
  sFloatControl *float_Up_2 = gh.Float(&para->Up.z,-1024.00f,1024.000f,0.001000f);
  float_Up_2->Default = 0.000000f; float_Up_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Axis");
  gh.BeginTied();
  sFloatControl *float_Axis_0 = gh.Float(&para->Axis.x,-1024.00f,1024.000f,0.001000f);
  float_Axis_0->Default = 0.000000f; float_Axis_0->RightStep = 0.125000f;
  sFloatControl *float_Axis_1 = gh.Float(&para->Axis.y,-1024.00f,1024.000f,0.001000f);
  float_Axis_1->Default = 0.000000f; float_Axis_1->RightStep = 0.125000f;
  sFloatControl *float_Axis_2 = gh.Float(&para->Axis.z,-1024.00f,1024.000f,0.001000f);
  float_Axis_2->Default = -1.00000f; float_Axis_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Angle");
  sFloatControl *float_Angle = gh.Float(&para->Angle,-4.00000f,4.000000f,0.001000f);
  float_Angle->Default = 0.250000f; float_Angle->RightStep = 0.125000f;

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,-1024.00f,1024.000f,0.001000f);
  float_Radius->Default = 1.000000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|pi=3",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefBend(wOp *op)
{
  Wz4MeshParaBend sUNUSED *para = (Wz4MeshParaBend *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Up.y = 1.000000f;
  para->Axis.z = -1.00000f;
  para->Angle = 0.250000f;
  para->Radius = 1.000000f;
}

void Wz4MeshBindBend(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"up"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"up"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"up"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"axis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"axis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"axis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"angle"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
}
void Wz4MeshBind2Bend(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"start");
    name[1] = sPoolString(L"up");
    name[2] = sPoolString(L"axis");
    name[3] = sPoolString(L"angle");
    name[4] = sPoolString(L"radius");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+10);
}
void Wz4MeshBind3Bend(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import start : float[3];\n");
  tb.PrintF(L"  import up : float[3];\n");
  tb.PrintF(L"  import axis : float[3];\n");
  tb.PrintF(L"  import angle : float;\n");
  tb.PrintF(L"  import radius : float;\n");
}
const sChar *Wz4MeshWikiBend =
L"= Wz4Mesh : Bend\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bend\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Start\n"
L" !i Start\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Up\n"
L" !i Up\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Axis\n"
L" !i Axis\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Angle\n"
L" !i Angle\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i pi=3\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

sBool Wz4MeshCmdSubdivide(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSubdivide sUNUSED *para = (Wz4MeshParaSubdivide *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1454 "wz4_mesh_ops.ops"

    Wz4MeshFace *f;
    sFORALL(out->Faces,f)
      f->Select = logic(para->Selection,f->Select)?1:0;

    out->Flush();
    for(sInt i=0;i<para->Levels;i++)
      out->Subdivide(para->Smooth);

    out->CalcNormalAndTangents();
  ;
#line 6399 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiSubdivide(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSubdivide sUNUSED *para = (Wz4MeshParaSubdivide *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"Levels");
  gh.Flags(&para->Levels,L"| 1| 2| 3| 4| 5| 6",gh.ChangeMsg);

  gh.Label(L"Smooth");
  sFloatControl *float_Smooth = gh.Float(&para->Smooth,-16.0000f,16.00000f,0.010000f);
  float_Smooth->Default = 1.000000f; float_Smooth->RightStep = 0.125000f;
}

void Wz4MeshDefSubdivide(wOp *op)
{
  Wz4MeshParaSubdivide sUNUSED *para = (Wz4MeshParaSubdivide *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Levels = 0x00000001;
  para->Smooth = 1.000000f;
}

void Wz4MeshBindSubdivide(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"smooth"),val);
}
void Wz4MeshBind2Subdivide(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
    name[1] = sPoolString(L"levels");
    name[2] = sPoolString(L"smooth");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4MeshBind3Subdivide(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import smooth : float;\n");
}
const sChar *Wz4MeshWikiSubdivide =
L"= Wz4Mesh : Subdivide\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Subdivide\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Levels\n"
L" !i Levels\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Smooth\n"
L" !i Smooth\n"
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

sBool Wz4MeshCmdExtrude(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaExtrude sUNUSED *para = (Wz4MeshParaExtrude *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1485 "wz4_mesh_ops.ops"

    out->Extrude(para->Steps,para->Amount,para->Flags,para->Center,para->LocalScale,para->SelectUpdateFlag,para->UVOffset);
  ;
#line 6557 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiExtrude(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaExtrude sUNUSED *para = (Wz4MeshParaExtrude *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Steps");
  sIntControl *int_Steps = gh.Int(&para->Steps,1,1024,0.125000f);
  int_Steps->Default = 0x00000001; int_Steps->RightStep = 0.125000f;

  gh.Label(L"Amount");
  sFloatControl *float_Amount = gh.Float(&para->Amount,-1024.00f,1024.000f,0.010000f);
  float_Amount->Default = 1.000000f; float_Amount->RightStep = 0.125000f;

  gh.Label(L"Faces");
  gh.Flags(&para->Flags,L"group|single",gh.ChangeMsg);

  gh.Label(L"Direction");
  gh.Flags(&para->Flags,L"*1group|normal|center",gh.LayoutMsg);

  if(((para->Flags&0x0006)==0x0004))
  {
    gh.Label(L"Center");
    gh.BeginTied();
    sFloatControl *float_Center_0 = gh.Float(&para->Center.x,-1024.00f,1024.000f,0.125000f);
    float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
    sFloatControl *float_Center_1 = gh.Float(&para->Center.y,-1024.00f,1024.000f,0.125000f);
    float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
    sFloatControl *float_Center_2 = gh.Float(&para->Center.z,-1024.00f,1024.000f,0.125000f);
    float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"LocalScale");
  sFloatControl *float_LocalScale = gh.Float(&para->LocalScale,0.000000f,16.00000f,0.010000f);
  float_LocalScale->Default = 1.000000f; float_LocalScale->RightStep = 0.125000f;

  gh.Label(L"Selection");
  gh.Flags(&para->SelectUpdateFlag,L"newest faces|original faces",gh.ChangeMsg);

  gh.Label(L"UV offset");
  gh.BeginTied();
  sFloatControl *float_UVOffset_0 = gh.Float(&para->UVOffset.x,-1024.00f,1024.000f,0.010000f);
  float_UVOffset_0->Default = 0.000000f; float_UVOffset_0->RightStep = 0.125000f;
  sFloatControl *float_UVOffset_1 = gh.Float(&para->UVOffset.y,-1024.00f,1024.000f,0.010000f);
  float_UVOffset_1->Default = 0.000000f; float_UVOffset_1->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4MeshDefExtrude(wOp *op)
{
  Wz4MeshParaExtrude sUNUSED *para = (Wz4MeshParaExtrude *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Steps = 0x00000001;
  para->Amount = 1.000000f;
  para->LocalScale = 1.000000f;
}

void Wz4MeshBindExtrude(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"steps"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"localscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"uvoffset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"uvoffset"),val);
}
void Wz4MeshBind2Extrude(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"steps");
    name[1] = sPoolString(L"amount");
    name[2] = sPoolString(L"faces");
    name[3] = sPoolString(L"direction");
    name[4] = sPoolString(L"center");
    name[5] = sPoolString(L"localscale");
    name[6] = sPoolString(L"selection");
    name[7] = sPoolString(L"uvoffset");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeFloat,2,cmd->Data+8);
}
void Wz4MeshBind3Extrude(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import steps : int;\n");
  tb.PrintF(L"  import amount : float;\n");
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import localscale : float;\n");
  tb.PrintF(L"  import uvoffset : float[2];\n");
}
const sChar *Wz4MeshWikiExtrude =
L"= Wz4Mesh : Extrude\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Extrude\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Steps\n"
L" !i Steps\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Amount\n"
L" !i Amount\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Faces\n"
L" !i Flags\n"
L" !i group\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i single\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Direction\n"
L" !i Flags\n"
L" !i group\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i center\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i LocalScale\n"
L" !i LocalScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i SelectUpdateFlag\n"
L" !i newest faces\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i original faces\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UV offset\n"
L" !i UVOffset\n"
L" !i float[2]\n"
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

sBool Wz4MeshCmdAdd(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaAdd sUNUSED *para = (Wz4MeshParaAdd *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1501 "wz4_mesh_ops.ops"

    // first pass: count how many faces and vertices to allocate
    sInt fcount = 0;
    sInt vcount = 0;
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      Wz4Mesh *in = cmd->GetInput<Wz4Mesh *>(i);
      if(in)
      {
        fcount += in->Faces.GetCount();
        vcount += in->Vertices.GetCount();
      }
    }

    out->Faces.HintSize(fcount);
    out->Vertices.HintSize(vcount);

    // second pass: actual add
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      Wz4Mesh *in = cmd->GetInput<Wz4Mesh *>(i);
      if(in)
        out->Add(in);
    }
  ;
#line 6814 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiAdd(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaAdd sUNUSED *para = (Wz4MeshParaAdd *)(op->EditData); para;
}

void Wz4MeshDefAdd(wOp *op)
{
  Wz4MeshParaAdd sUNUSED *para = (Wz4MeshParaAdd *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindAdd(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Add(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind3Add(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiAdd =
L"= Wz4Mesh : Add\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Add\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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

sBool Wz4MeshCmdSelect(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSelect sUNUSED *para = (Wz4MeshParaSelect *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  GenBitmap sUNUSED *in1 = cmd->GetInput<GenBitmap *>(1); in1;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1575 "wz4_mesh_ops.ops"

    sSRT srt;
    sMatrix34 mat;
    sMatrix34 inv;
    Wz4MeshVertex *vp;
    Wz4MeshFace *face;
    sVector31 v;
    sRandom rnd;
   
    rnd.Seed(para->RandomSeed);

    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.Scale = para->Scale;
    srt.MakeMatrix(mat);
    srt.MakeMatrixInv(inv);

    sInt pc = out->Vertices.GetCount();
    
    sInt refR = 0x80*((para->RefColor>>16)&0xff);
    sInt refG = 0x80*((para->RefColor>>8)&0xff);
    sInt refB = 0x80*((para->RefColor>>0)&0xff);
    sInt refInner = 0x80*para->RefColorErr;
    sInt refOuter = 0x80*(para->RefColorErr+para->RefColorSpread);
    sF32 refScale = 1.0f/(0x80*para->RefColorSpread);

    sInt flagsInput = para->Flags & 0x1c0;
    sInt flagsOutput = (para->Flags >> 4) & 3;
    sBool selectVerts = flagsOutput==0 || flagsOutput==3;

    sF32 *fsel = new sF32[pc];
    if(flagsInput==0x0c0)
    {
      for(sInt i=0;i<pc;i++)
        fsel[i] = 0.0f;
      sFORALL(out->Faces,face)
      {
        if(face->Select>0.0f)
        {
          for(sInt i=0;i<face->Count;i++)
            fsel[face->Vertex[i]]=face->Select;
        }
      }
    }
    if(flagsInput==0x180)
    {
      for(sInt i=0;i<pc;i++)
        fsel[i] = 0.0f;
      sFORALL(out->Faces,face)
      {
        if(face->Cluster==para->Cluster)
          for(sInt i=0;i<face->Count;i++)
            fsel[face->Vertex[i]]= 1;
      }
    }
    sFORALL(out->Vertices,vp)
    {
      v = vp->Pos * inv;
      sF32 inside = 0.0f;
      switch(flagsInput)
      {
      case 0x00:
        inside = (v.x>=-1&&v.x<=1 && v.y>=-1&&v.y<=1 && v.z>=-1&&v.z<=1)?1.0f:0.0f;
        break;
      case 0x40:
        inside = ((v.x*v.x+v.y*v.y+v.z*v.z)<=1)?1.0f:0.0f;
        break;
      case 0x80:
        inside = vp->Select;
        break;
      case 0x0c0:
      case 0x180:
        inside = fsel[_i];
        break;
      case 0x100:
        inside = 1.0f;
        break;
      case 0x140:
        {
          GenBitmap *bmp = cmd->GetInput<GenBitmap *>(1);
          if (!bmp) break;

          sF32 baseu, basev;
          if (para->TextureUV&1)
          {
            baseu=vp->U1;
            basev=vp->V1;
          }
          else
          {
            baseu=vp->U0;
            basev=vp->V0;
          }

          if (para->TextureUV&2)
          {
            baseu=sFMod(baseu,1); if (baseu<0) baseu+=1;
            basev=sFMod(basev,1); if (basev<0) basev+=1;
          }
          else
          {
            baseu=sClamp(baseu,0.0f,0.9999f);
            basev=sClamp(basev,0.0f,0.9999f);
          }

          sInt u=(sInt)(bmp->XSize*baseu);
          sInt v=(sInt)(bmp->YSize*basev);
          sU64 pixel=bmp->Data[bmp->XSize*v+u];
          sInt b=(pixel&0xffff);
          sInt g=((pixel>>16)&0xffff);
          sInt r=((pixel>>32)&0xffff);
          sInt err=sMax(sMax(sAbs(r-refR),sAbs(g-refG)),sAbs(b-refB));
          if (err<refInner)
            inside = 1.0f;
          else if (err<refOuter)
            inside = (refOuter-err)*refScale;
          else
            inside= 0.0f;
        }
        break;
      }

      if(para->Flags & 1)
        inside=1.0f-inside;
      
      fsel[_i] = inside;
    }

    if(selectVerts)
    {
      if (flagsOutput==0)
      {
        for(sInt i=0;i<pc;i++)
          if (rnd.Float(1)>para->Random)
            fsel[i] = 0;
      }
      else
      {
        // smear
        sInt *base = out->BasePos(1);
        for (sInt i=0;i<pc;i++)
          fsel[base[i]] = sMax(fsel[base[i]],fsel[i]);

        for (sInt i=0;i<pc;i++)
        {
          if (rnd.Float(1)>para->Random)
            fsel[i] = 0;
          fsel[i] = fsel[base[i]];
        }
        delete[] base;
      }
      sFORALL(out->Vertices,vp)
      {
        sF32 inside = fsel[_i];
        switch(para->Flags & 12)
        {
        case 0:
          vp->Select=sMax(vp->Select-inside,0.0f);
          break;
        case 4:
          vp->Select=sMin(vp->Select+inside,1.0f);
          break;
        case 8:
          vp->Select = inside;
          break;
        }
      }
    }
    else
    {
      sFORALL(out->Faces,face)
      {
        sInt n = 0;
        for(sInt i=0;i<face->Count;i++)
          n += (fsel[face->Vertex[i]]>=0.5f)?1:0;
        sBool action = 0;
        switch(flagsOutput)
        {
        case 1:
          action = (n>0);
          break;
        case 2:
          action = (n==face->Count);
          break;
        }
        if(rnd.Float(1)>para->Random)
          action = 0;
        switch(para->Flags & 12)
        {
        case 0:
          if(action)
            face->Select = 0;
          break;
        case 4:
          if(action)
            face->Select = 1;
          break;
        case 8:
          face->Select = action?1:0;
          break;
        }
      }
    }

    // face or vertex ?
    sInt type = 0;
    if(((para->Flags&0x1c0)!=0x1c0))
      type = (selectVerts)?wMST_VERTEX:wMST_FACE;
    if(((para->Flags&0x1c0)==0x1c0))
      type = ((para->Flags >> 4) & 1)?wMST_FACE:wMST_VERTEX;

    // load slot
    if(((para->Flags&0x1c0)==0x1c0))
      out->SelStoreLoad(wMSM_LOAD,type,para->InputSlot);

    // store slot
    if(((para->Flags&0x1c0)!=0x1c0) && para->OutputSlot>0)
      out->SelStoreLoad(wMSM_STORE,type,para->OutputSlot-1);


    delete[] fsel;
  ;
#line 7106 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshHndSelect(wPaintInfo &pi,wOp *op)
{
  Wz4MeshParaSelect sUNUSED *para = (Wz4MeshParaSelect *)(op->EditData); para;
#line 1799 "wz4_mesh_ops.ops"

    sSRT srt;
    sMatrix34 mat;
    sVector31 v[8],p;

    if(((para->Flags&0x1c0)!=0x1c0))  // no handles when input == slot
    {
      srt.Rotate = para->Rot;
      srt.Translate = para->Trans;
      srt.Scale = para->Scale;
      srt.MakeMatrix(mat);

      sF32 s = 1;
      p.Init(-s,-s,-s); v[0] = p*mat;
      p.Init(-s,-s, s); v[1] = p*mat;
      p.Init(-s, s, s); v[2] = p*mat;
      p.Init(-s, s,-s); v[3] = p*mat;
      p.Init( s,-s,-s); v[4] = p*mat;
      p.Init( s,-s, s); v[5] = p*mat;
      p.Init( s, s, s); v[6] = p*mat;
      p.Init( s, s,-s); v[7] = p*mat;

      pi.Line3D(v[0],v[1]);
      pi.Line3D(v[1],v[2]);
      pi.Line3D(v[2],v[3]);
      pi.Line3D(v[3],v[0]);
      pi.Line3D(v[4],v[5]);
      pi.Line3D(v[5],v[6]);
      pi.Line3D(v[6],v[7]);
      pi.Line3D(v[7],v[4]);
      pi.Line3D(v[0],v[4]);
      pi.Line3D(v[1],v[5]);
      pi.Line3D(v[2],v[6]);
      pi.Line3D(v[3],v[7]);
    }
  ;
#line 7151 "wz4_mesh_ops.cpp"
}

void Wz4MeshGuiSelect(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSelect sUNUSED *para = (Wz4MeshParaSelect *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Input");
  gh.Flags(&para->Flags,L"*6cube|sphere|vertex select|face select|all|by texture|cluster|slot",gh.LayoutMsg);

  if(((para->Flags&0x01c0)!=0x01c0))
  {
    gh.Label(L"Logic");
    gh.Flags(&para->Flags,L"-|invert:*2clear|set|assign",gh.ChangeMsg);

  }
  if(((para->Flags&0x01c0)!=0x01c0))
  {
    gh.Label(L"Output");
    gh.Flags(&para->Flags,L"*4inner vertex|touched face|enclosed face|full vertex",gh.ChangeMsg);

  }
  if(((para->Flags&0x01c0)==0x01c0))
  {
    gh.Label(L"Channel");
    gh.Flags(&para->Flags,L"*4vertex|face",gh.ChangeMsg);

  }
  if((((para->Flags&0x01c0)==0x0000)||((para->Flags&0x01c0)==0x0040)))
  {
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
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-64.0000f,64.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-64.0000f,64.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-64.0000f,64.00000f,0.001000f);
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

  }
  if(((para->Flags&0x01c0)!=0x01c0))
  {
    gh.Label(L"Random");
    sFloatControl *float_Random = gh.Float(&para->Random,0.000000f,1.000000f,0.020000f);
    float_Random->Default = 1.000000f; float_Random->RightStep = 0.125000f;

    gh.Label(L"RandomSeed");
    sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
    int_RandomSeed->Default = 0x00000000; int_RandomSeed->RightStep = 0.125000f;

  }
  if(((para->Flags&0x01c0)==0x0140))
  {
    gh.Label(L"Reference");
    gh.ColorPick(&para->RefColor,L"rgb",0);

    gh.Label(L"Radius");
    sIntControl *int_RefColorErr = gh.Int(&para->RefColorErr,0,255,0.125000f);
    int_RefColorErr->Default = 0x00000002; int_RefColorErr->RightStep = 0.125000f;

    gh.Label(L"Spread");
    sIntControl *int_RefColorSpread = gh.Int(&para->RefColorSpread,0,255,0.125000f);
    int_RefColorSpread->Default = 0x000000fd; int_RefColorSpread->RightStep = 0.125000f;

    gh.Label(L"UV Set");
    gh.Flags(&para->TextureUV,L"UV0|UV1",gh.ChangeMsg);

    gh.Label(L"UV Mode");
    gh.Flags(&para->TextureUV,L"*1clamp|wrap",gh.ChangeMsg);

  }
  if(((para->Flags&0x01c0)==0x0180))
  {
    gh.Label(L"Cluster");
    sIntControl *int_Cluster = gh.Int(&para->Cluster,0,1024,0.125000f);
    int_Cluster->Default = 0x00000000; int_Cluster->RightStep = 0.125000f;

  }
  if(((para->Flags&0x01c0)==0x01c0))
  {
    gh.Label(L"Slot");
    gh.Radio(&para->InputSlot,L" 1| 2| 3| 4| 5| 6| 7| 8",1);

  }
  if(((para->Flags&0x01c0)!=0x01c0))
  {
    gh.Label(L"Slot");
    gh.Radio(&para->OutputSlot,L"none| 1| 2| 3| 4| 5| 6| 7| 8",1);
  }
}

void Wz4MeshDefSelect(wOp *op)
{
  Wz4MeshParaSelect sUNUSED *para = (Wz4MeshParaSelect *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000008;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Random = 1.000000f;
  para->RefColor = 0x00ffffff;
  para->RefColorErr = 0x00000002;
  para->RefColorSpread = 0x000000fd;
}

void Wz4MeshBindSelect(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"randomseed"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"reference"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"spread"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"cluster"),val);
}
void Wz4MeshBind2Select(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[17];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"input");
    name[1] = sPoolString(L"logic");
    name[2] = sPoolString(L"output");
    name[3] = sPoolString(L"channel");
    name[4] = sPoolString(L"scale");
    name[5] = sPoolString(L"rot");
    name[6] = sPoolString(L"trans");
    name[7] = sPoolString(L"random");
    name[8] = sPoolString(L"randomseed");
    name[9] = sPoolString(L"reference");
    name[10] = sPoolString(L"radius");
    name[11] = sPoolString(L"spread");
    name[12] = sPoolString(L"textureuv");
    name[13] = sPoolString(L"textureuv");
    name[14] = sPoolString(L"cluster");
    name[15] = sPoolString(L"slot");
    name[16] = sPoolString(L"slot");
  }
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+11);
  ctx->AddImport(name[9],ScriptTypeColor,1,cmd->Data+12);
  ctx->AddImport(name[10],ScriptTypeInt,1,cmd->Data+13);
  ctx->AddImport(name[11],ScriptTypeInt,1,cmd->Data+14);
  ctx->AddImport(name[14],ScriptTypeInt,1,cmd->Data+16);
}
void Wz4MeshBind3Select(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import random : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
  tb.PrintF(L"  import reference : color;\n");
  tb.PrintF(L"  import radius : int;\n");
  tb.PrintF(L"  import spread : int;\n");
  tb.PrintF(L"  import cluster : int;\n");
}
const sChar *Wz4MeshWikiSelect =
L"= Wz4Mesh : Select\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Select\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i GenBitmap\n"
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
L" !i Input\n"
L" !i Flags\n"
L" !i cube\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i vertex select\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i face select\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i by texture\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i cluster\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i slot\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Logic\n"
L" !i Flags\n"
L" !i invert\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i clear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i assign\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Output\n"
L" !i Flags\n"
L" !i inner vertex\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i touched face\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i enclosed face\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i full vertex\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Channel\n"
L" !i Flags\n"
L" !i vertex\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i face\n"
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
L" !i Random\n"
L" !i Random\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomSeed\n"
L" !i RandomSeed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Reference\n"
L" !i RefColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i RefColorErr\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Spread\n"
L" !i RefColorSpread\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i UV Set\n"
L" !i TextureUV\n"
L" !i UV0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i UV1\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UV Mode\n"
L" !i TextureUV\n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i wrap\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Cluster\n"
L" !i Cluster\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Slot\n"
L" !i InputSlot\n"
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
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Slot\n"
L" !i OutputSlot\n"
L" !i none\n"
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
L" !i \n"
L" !i \n"
L" !i 8\n"
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

sBool Wz4MeshCmdSplitAlongPlane(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSplitAlongPlane sUNUSED *para = (Wz4MeshParaSplitAlongPlane *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1848 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);
    for(int i=0; i<para->Count; i++)
    {
      out->SplitAlongPlane(para->Plane);
      para->Plane.w += para->Distance;
    }
  ;
#line 7656 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiSplitAlongPlane(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSplitAlongPlane sUNUSED *para = (Wz4MeshParaSplitAlongPlane *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Plane");
  gh.BeginTied();
  sFloatControl *float_Plane_0 = gh.Float(&para->Plane.x,-256.000f,256.0000f,0.001000f);
  float_Plane_0->Default = 0.000000f; float_Plane_0->RightStep = 0.125000f;
  sFloatControl *float_Plane_1 = gh.Float(&para->Plane.y,-256.000f,256.0000f,0.001000f);
  float_Plane_1->Default = 1.000000f; float_Plane_1->RightStep = 0.125000f;
  sFloatControl *float_Plane_2 = gh.Float(&para->Plane.z,-256.000f,256.0000f,0.001000f);
  float_Plane_2->Default = 0.000000f; float_Plane_2->RightStep = 0.125000f;
  sFloatControl *float_Plane_3 = gh.Float(&para->Plane.w,-256.000f,256.0000f,0.001000f);
  float_Plane_3->Default = 0.500000f; float_Plane_3->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,256,0.125000f);
  int_Count->Default = 0x00000001; int_Count->RightStep = 0.125000f;

  gh.Label(L"Distance");
  sFloatControl *float_Distance = gh.Float(&para->Distance,-1024.00f,1024.000f,0.001000f);
  float_Distance->Default = 0.000000f; float_Distance->RightStep = 0.125000f;
}

void Wz4MeshDefSplitAlongPlane(wOp *op)
{
  Wz4MeshParaSplitAlongPlane sUNUSED *para = (Wz4MeshParaSplitAlongPlane *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Plane.y = 1.000000f;
  para->Plane.w = 0.500000f;
  para->Count = 0x00000001;
}

void Wz4MeshBindSplitAlongPlane(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"plane"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"plane"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"plane"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"plane"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"distance"),val);
}
void Wz4MeshBind2SplitAlongPlane(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"plane");
    name[1] = sPoolString(L"count");
    name[2] = sPoolString(L"distance");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,4,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+5);
}
void Wz4MeshBind3SplitAlongPlane(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import plane : float[4];\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import distance : float;\n");
}
const sChar *Wz4MeshWikiSplitAlongPlane =
L"= Wz4Mesh : SplitAlongPlane\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SplitAlongPlane\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Plane\n"
L" !i Plane\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Distance\n"
L" !i Distance\n"
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

sBool Wz4MeshCmdBakeAnim(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaBakeAnim sUNUSED *para = (Wz4MeshParaBakeAnim *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1866 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);
    out->BakeAnim(para->Time);
  ;
#line 7812 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiBakeAnim(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaBakeAnim sUNUSED *para = (Wz4MeshParaBakeAnim *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Time");
  sFloatControl *float_Time = gh.Float(&para->Time,0.000000f,1024.000f,0.010000f);
  float_Time->Default = 0.000000f; float_Time->RightStep = 0.125000f;
}

void Wz4MeshDefBakeAnim(wOp *op)
{
  Wz4MeshParaBakeAnim sUNUSED *para = (Wz4MeshParaBakeAnim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindBakeAnim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"time"),val);
}
void Wz4MeshBind2BakeAnim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"time");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void Wz4MeshBind3BakeAnim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import time : float;\n");
}
const sChar *Wz4MeshWikiBakeAnim =
L"= Wz4Mesh : BakeAnim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BakeAnim\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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

sBool Wz4MeshCmdFacette(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaFacette sUNUSED *para = (Wz4MeshParaFacette *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1881 "wz4_mesh_ops.ops"

    out->Facette(para->Smoothness);
  ;
#line 7917 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiFacette(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaFacette sUNUSED *para = (Wz4MeshParaFacette *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Smoothness");
  sFloatControl *float_Smoothness = gh.Float(&para->Smoothness,0.000000f,1.000000f,0.010000f);
  float_Smoothness->Default = 0.000000f; float_Smoothness->RightStep = 0.125000f;
}

void Wz4MeshDefFacette(wOp *op)
{
  Wz4MeshParaFacette sUNUSED *para = (Wz4MeshParaFacette *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindFacette(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"smoothness"),val);
}
void Wz4MeshBind2Facette(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"smoothness");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void Wz4MeshBind3Facette(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import smoothness : float;\n");
}
const sChar *Wz4MeshWikiFacette =
L"= Wz4Mesh : Facette\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Facette\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Smoothness\n"
L" !i Smoothness\n"
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

sBool Wz4MeshCmdCrease(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaCrease sUNUSED *para = (Wz4MeshParaCrease *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1891 "wz4_mesh_ops.ops"

    out->Crease();
  ;
#line 8022 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiCrease(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaCrease sUNUSED *para = (Wz4MeshParaCrease *)(op->EditData); para;
}

void Wz4MeshDefCrease(wOp *op)
{
  Wz4MeshParaCrease sUNUSED *para = (Wz4MeshParaCrease *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindCrease(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Crease(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind3Crease(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiCrease =
L"= Wz4Mesh : Crease\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Crease\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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

sBool Wz4MeshCmdUnCrease(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaUnCrease sUNUSED *para = (Wz4MeshParaUnCrease *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1905 "wz4_mesh_ops.ops"

    out->Uncrease(para->Selection);
  ;
#line 8094 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiUnCrease(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaUnCrease sUNUSED *para = (Wz4MeshParaUnCrease *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefUnCrease(wOp *op)
{
  Wz4MeshParaUnCrease sUNUSED *para = (Wz4MeshParaUnCrease *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindUnCrease(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2UnCrease(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"selection");
  }
}
void Wz4MeshBind3UnCrease(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiUnCrease =
L"= Wz4Mesh : UnCrease\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i UnCrease\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

sBool Wz4MeshCmdDisplace(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaDisplace sUNUSED *para = (Wz4MeshParaDisplace *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  BitmapBase sUNUSED *in1 = cmd->GetInput<BitmapBase *>(1); in1;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1924 "wz4_mesh_ops.ops"

    sSRT srt;
    sMatrix34 mat;
    sImageI16 img;
   
    srt.Rotate = para->Rot;
    srt.Translate = para->Trans;
    srt.Scale = para->Scale;
    srt.MakeMatrix(mat);

    in1->CopyTo(&img);

    out->CopyFrom(in0);
    out->Displace(mat,&img,para->Amount,para->Bias,para->Flags,para->Selection);
    out->CalcNormalAndTangents();
  ;
#line 8218 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiDisplace(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaDisplace sUNUSED *para = (Wz4MeshParaDisplace *)(op->EditData); para;
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

  gh.Label(L"Amount");
  sFloatControl *float_Amount = gh.Float(&para->Amount,-1024.00f,1024.000f,0.010000f);
  float_Amount->Default = 1.000000f; float_Amount->RightStep = 0.125000f;

  gh.Label(L"Bias");
  sFloatControl *float_Bias = gh.Float(&para->Bias,0.000000f,1.000000f,0.010000f);
  float_Bias->Default = 0.500000f; float_Bias->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Center:*1-|uv:*2-|by normal",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);
}

void Wz4MeshDefDisplace(wOp *op)
{
  Wz4MeshParaDisplace sUNUSED *para = (Wz4MeshParaDisplace *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Amount = 1.000000f;
  para->Bias = 0.500000f;
}

void Wz4MeshBindDisplace(wCommand *cmd,ScriptContext *ctx)
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
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"bias"),val);
}
void Wz4MeshBind2Displace(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rot");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"amount");
    name[4] = sPoolString(L"bias");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+10);
}
void Wz4MeshBind3Displace(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import amount : float;\n");
  tb.PrintF(L"  import bias : float;\n");
}
const sChar *Wz4MeshWikiDisplace =
L"= Wz4Mesh : Displace\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Displace\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i BitmapBase\n"
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
L" !i Amount\n"
L" !i Amount\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Bias\n"
L" !i Bias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i Center\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i uv\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i by normal\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
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

sBool Wz4MeshCmdSplitter(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaSplitter sUNUSED *para = (Wz4MeshParaSplitter *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1951 "wz4_mesh_ops.ops"

    out->Splitter(in0,para->Depth,para->Scale);
  ;
#line 8476 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiSplitter(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaSplitter sUNUSED *para = (Wz4MeshParaSplitter *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Depth");
  sFloatControl *float_Depth = gh.Float(&para->Depth,-16.0000f,16.00000f,0.001000f);
  float_Depth->Default = -0.125000f; float_Depth->RightStep = 0.125000f;

  gh.Label(L"Scale");
  sFloatControl *float_Scale = gh.Float(&para->Scale,-16.0000f,16.00000f,0.001000f);
  float_Scale->Default = 0.875000f; float_Scale->RightStep = 0.125000f;
}

void Wz4MeshDefSplitter(wOp *op)
{
  Wz4MeshParaSplitter sUNUSED *para = (Wz4MeshParaSplitter *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Depth = -0.125000f;
  para->Scale = 0.875000f;
}

void Wz4MeshBindSplitter(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"depth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
}
void Wz4MeshBind2Splitter(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"depth");
    name[1] = sPoolString(L"scale");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void Wz4MeshBind3Splitter(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import depth : float;\n");
  tb.PrintF(L"  import scale : float;\n");
}
const sChar *Wz4MeshWikiSplitter =
L"= Wz4Mesh : Splitter\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Splitter\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Depth\n"
L" !i Depth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
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

sBool Wz4MeshCmdDual(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaDual sUNUSED *para = (Wz4MeshParaDual *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 1964 "wz4_mesh_ops.ops"

    out->Dual(in0,para->Random);
  ;
#line 8598 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiDual(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaDual sUNUSED *para = (Wz4MeshParaDual *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Random");
  sFloatControl *float_Random = gh.Float(&para->Random,0.000000f,2.000000f,0.001000f);
  float_Random->Default = 0.000000f; float_Random->RightStep = 0.125000f;
}

void Wz4MeshDefDual(wOp *op)
{
  Wz4MeshParaDual sUNUSED *para = (Wz4MeshParaDual *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindDual(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
}
void Wz4MeshBind2Dual(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"random");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void Wz4MeshBind3Dual(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import random : float;\n");
}
const sChar *Wz4MeshWikiDual =
L"= Wz4Mesh : Dual\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Dual\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Random\n"
L" !i Random\n"
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

sBool Wz4MeshCmdHeal(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaHeal sUNUSED *para = (Wz4MeshParaHeal *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1984 "wz4_mesh_ops.ops"

    out->Heal(in1,para->Flags,para->PosThreshold,para->NormThreshold);
  ;
#line 8704 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiHeal(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaHeal sUNUSED *para = (Wz4MeshParaHeal *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|Normals:*1-|Tangents:*2-|UVs",gh.ChangeMsg);

  gh.Label(L"Reference");
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

  gh.Label(L"PosThreshold");
  sFloatControl *float_PosThreshold = gh.Float(&para->PosThreshold,0.000000f,100.0000f,0.001000f);
  float_PosThreshold->Default = 0.001000f; float_PosThreshold->RightStep = 0.125000f;

  gh.Label(L"NormThreshold");
  sFloatControl *float_NormThreshold = gh.Float(&para->NormThreshold,-1.00000f,1.000000f,0.001000f);
  float_NormThreshold->Default = 0.900000f; float_NormThreshold->RightStep = 0.125000f;
}

void Wz4MeshDefHeal(wOp *op)
{
  Wz4MeshParaHeal sUNUSED *para = (Wz4MeshParaHeal *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000007;
  para->PosThreshold = 0.001000f;
  para->NormThreshold = 0.900000f;
}

void Wz4MeshBindHeal(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"posthreshold"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"normthreshold"),val);
}
void Wz4MeshBind2Heal(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"reference");
    name[2] = sPoolString(L"posthreshold");
    name[3] = sPoolString(L"normthreshold");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4MeshBind3Heal(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import posthreshold : float;\n");
  tb.PrintF(L"  import normthreshold : float;\n");
}
const sChar *Wz4MeshWikiHeal =
L"= Wz4Mesh : Heal\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Heal\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Wz4Mesh\n"
L" !i link Reference\n"
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
L" !i Normals\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Tangents\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i UVs\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Reference\n"
L" !i Reference\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i PosThreshold\n"
L" !i PosThreshold\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i NormThreshold\n"
L" !i NormThreshold\n"
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

sBool Wz4MeshCmdDeform(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaDeform sUNUSED *para = (Wz4MeshParaDeform *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 2012 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);
    if(!(para->Flags & 1))
    {
      out->Deform(para->Count,para->Start,para->End,
        cmd->ArrayCount,(const Wz4MeshArrayDeform *)cmd->Array,
        para->Selection,para->UpVectorUse,para->UpVector);
      if(!(para->Flags & 2))
        out->BakeAnim(0);
      out->CalcNormalAndTangents();
    }
  ;
#line 8892 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshHndDeform(wPaintInfo &pi,wOp *op)
{
  Wz4MeshParaDeform sUNUSED *para = (Wz4MeshParaDeform *)(op->EditData); para;
#line 2045 "wz4_mesh_ops.ops"

    void *ap;
    sVector31 *key;
    sInt n=1;
    if(para->Flags & 1)
    {
      pi.Handle3D(op,n++,para->Start,wHM_PLANE);
      pi.Handle3D(op,n++,para->End,wHM_PLANE);
    }
    else
    {
      if(pi.DeleteSelectedHandles)
      {
        // have to delete in reverse to not corrupt indices
        for (sInt i=op->ArrayData.GetCount()-1;i>=0;i--)
          if(pi.IsSelected(op,i+n))
            op->RemArray(i);
        Doc->Change(op);
      }
      sFORALL(op->ArrayData,ap)
      {
        key = (sVector31 *)ap;
        pi.Handle3D(op,n++,*key,wHM_PLANE,_i);
      }
    }
  ;
#line 8927 "wz4_mesh_ops.cpp"
}

void Wz4MeshArrDeform(wOp *op,sInt pos,void *mem)
{
  Wz4MeshParaDeform sUNUSED *para = (Wz4MeshParaDeform *)(op->EditData); para;
  Wz4MeshArrayDeform *e = (Wz4MeshArrayDeform *)(mem);
  e->Pos.x = 0.000000f;
  e->Pos.y = 0.000000f;
  e->Pos.z = 0.000000f;
  e->Twist = 0.000000f;
  e->Scale = 1.000000f;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    Wz4MeshArrayDeform *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (Wz4MeshArrayDeform *)op->ArrayData[0];
      f1 =  0; p1 = (Wz4MeshArrayDeform *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (Wz4MeshArrayDeform *)op->ArrayData[0];
      f1 = -1; p1 = (Wz4MeshArrayDeform *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (Wz4MeshArrayDeform *)op->ArrayData[max-1];
      f1 = -1; p1 = (Wz4MeshArrayDeform *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (Wz4MeshArrayDeform *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (Wz4MeshArrayDeform *)op->ArrayData[pos  ];
    }
    e->Pos.x = f0*p0->Pos.x + f1*p1->Pos.x;
    e->Pos.y = f0*p0->Pos.y + f1*p1->Pos.y;
    e->Pos.z = f0*p0->Pos.z + f1*p1->Pos.z;
    e->Twist = f0*p0->Twist + f1*p1->Twist;
    e->Scale = f0*p0->Scale + f1*p1->Scale;
  }
}

sInt Wz4MeshActDeform(wOp *op,sInt code,sInt pos)
{
  Wz4MeshParaDeform sUNUSED *para = (Wz4MeshParaDeform *)(op->EditData); para;
#line 2026 "wz4_mesh_ops.ops"

    if(code==1)
    {
      op->ArrayData.Clear();
      for(sInt i=0;i<para->Count;i++)
      {
        sVector31 *p = (sVector31 *)op->AddArray(-1);
        p->Fade(sF32(i)/(para->Count-1),para->Start,para->End);
      }
      Doc->Change(op);
      return 1;
    }
    else
    {
      return 0;
    }
  ;
#line 8993 "wz4_mesh_ops.cpp"
}

void Wz4MeshGuiDeform(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaDeform sUNUSED *para = (Wz4MeshParaDeform *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,4,256,0.125000f);
  int_Count->Default = 0x00000004; int_Count->RightStep = 0.125000f;

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

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|disable:*1-|keep bones",gh.ChangeMsg);

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|none|selected|unselected",gh.ChangeMsg);

  gh.Label(L"UpVectorUse");
  gh.Flags(&para->UpVectorUse,L"free|fixed|shear:*4-|straight out:*8-|old mode",gh.ChangeMsg);

  gh.Label(L"UpVector");
  gh.BeginTied();
  sFloatControl *float_UpVector_0 = gh.Float(&para->UpVector.x,-4.00000f,4.000000f,0.001000f);
  float_UpVector_0->Default = 0.000000f; float_UpVector_0->RightStep = 0.125000f;
  sFloatControl *float_UpVector_1 = gh.Float(&para->UpVector.y,-4.00000f,4.000000f,0.001000f);
  float_UpVector_1->Default = 1.000000f; float_UpVector_1->RightStep = 0.125000f;
  sFloatControl *float_UpVector_2 = gh.Float(&para->UpVector.z,-4.00000f,4.000000f,0.001000f);
  float_UpVector_2->Default = 0.000000f; float_UpVector_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.ActionMsg.Code = 1;
  gh.PushButton(L"ResetKeys",gh.ActionMsg);
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Pos",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  gh.Grid->AddLabel(L"Twist",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Scale",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      Wz4MeshArrayDeform *elem = (Wz4MeshArrayDeform *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&elem->Pos.x,-1024.00f,1024.000f,0.010000f);
    float_Pos_0->Default = 0.000000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&elem->Pos.y,-1024.00f,1024.000f,0.010000f);
    float_Pos_1->Default = 0.000000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&elem->Pos.z,-1024.00f,1024.000f,0.010000f);
    float_Pos_2->Default = 0.000000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

    sFloatControl *float_Twist = gh.Float(&elem->Twist,-16.0000f,16.00000f,0.002000f);
    float_Twist->Default = 0.000000f; float_Twist->RightStep = 0.125000f;

    sFloatControl *float_Scale = gh.Float(&elem->Scale,-1024.00f,1024.000f,0.010000f);
    float_Scale->Default = 1.000000f; float_Scale->RightStep = 0.125000f;
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

void Wz4MeshDefDeform(wOp *op)
{
  Wz4MeshParaDeform sUNUSED *para = (Wz4MeshParaDeform *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Count = 0x00000004;
  para->UpVector.y = 1.000000f;
}

void Wz4MeshBindDeform(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"start"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"end"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"end"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"end"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"upvector"),val);
}
void Wz4MeshBind2Deform(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"count");
    name[1] = sPoolString(L"start");
    name[2] = sPoolString(L"end");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"selection");
    name[5] = sPoolString(L"upvectoruse");
    name[6] = sPoolString(L"upvector");
    name[7] = sPoolString(L"resetkeys");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+10);
}
void Wz4MeshBind3Deform(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import start : float[3];\n");
  tb.PrintF(L"  import end : float[3];\n");
  tb.PrintF(L"  import upvector : float[3];\n");
}
const sChar *Wz4MeshWikiDeform =
L"= Wz4Mesh : Deform\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Deform\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i disable\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i keep bones\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UpVectorUse\n"
L" !i UpVectorUse\n"
L" !i free\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fixed\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i straight out\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i old mode\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UpVector\n"
L" !i UpVector\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i ResetKeys\n"
L" !i ResetKeys\n"
L" !i action\n"
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
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i disable\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i keep bones\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Selection\n"
L" !i Selection\n"
L" !i all\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i none\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i unselected\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UpVectorUse\n"
L" !i UpVectorUse\n"
L" !i free\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i fixed\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i straight out\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i old mode\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UpVector\n"
L" !i UpVector\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i ResetKeys\n"
L" !i ResetKeys\n"
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

sBool Wz4MeshCmdChunks(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaChunks sUNUSED *para = (Wz4MeshParaChunks *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 2087 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);  
    return out->DivideInChunks(para->Flags,para->Normal,para->Rotation);
  ;
#line 9418 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiChunks(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaChunks sUNUSED *para = (Wz4MeshParaChunks *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Normal");
  gh.BeginTied();
  sFloatControl *float_Normal_0 = gh.Float(&para->Normal.x,-16.0000f,16.00000f,0.010000f);
  float_Normal_0->Default = 0.000000f; float_Normal_0->RightStep = 0.125000f;
  sFloatControl *float_Normal_1 = gh.Float(&para->Normal.y,-16.0000f,16.00000f,0.010000f);
  float_Normal_1->Default = 1.000000f; float_Normal_1->RightStep = 0.125000f;
  sFloatControl *float_Normal_2 = gh.Float(&para->Normal.z,-16.0000f,16.00000f,0.010000f);
  float_Normal_2->Default = 0.000000f; float_Normal_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"fixed|random",gh.LayoutMsg);

  if(((para->Flags&0x0001)==0x0000))
  {
    gh.Label(L"Rotation");
    gh.BeginTied();
    sFloatControl *float_Rotation_0 = gh.Float(&para->Rotation.x,-16.0000f,16.00000f,0.010000f);
    float_Rotation_0->Default = 1.000000f; float_Rotation_0->RightStep = 0.125000f;
    sFloatControl *float_Rotation_1 = gh.Float(&para->Rotation.y,-16.0000f,16.00000f,0.010000f);
    float_Rotation_1->Default = 0.000000f; float_Rotation_1->RightStep = 0.125000f;
    sFloatControl *float_Rotation_2 = gh.Float(&para->Rotation.z,-16.0000f,16.00000f,0.010000f);
    float_Rotation_2->Default = 0.000000f; float_Rotation_2->RightStep = 0.125000f;
    gh.EndTied();
  }
}

void Wz4MeshDefChunks(wOp *op)
{
  Wz4MeshParaChunks sUNUSED *para = (Wz4MeshParaChunks *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Normal.y = 1.000000f;
  para->Flags = 0x00000001;
  para->Rotation.x = 1.000000f;
}

void Wz4MeshBindChunks(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"normal"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"normal"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"normal"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
}
void Wz4MeshBind2Chunks(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"normal");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"rotation");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
}
void Wz4MeshBind3Chunks(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import normal : float[3];\n");
  tb.PrintF(L"  import rotation : float[3];\n");
}
const sChar *Wz4MeshWikiChunks =
L"= Wz4Mesh : Chunks\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Chunks\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Normal\n"
L" !i Normal\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i fixed\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Rotation\n"
L" !i Rotation\n"
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

sBool Wz4MeshCmdRandomizeChunks(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaRandomizeChunks sUNUSED *para = (Wz4MeshParaRandomizeChunks *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 2105 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);
    sInt n = out->Chunks.GetCount();
    if(n>=0)
    {
      sVector30 *dis = new sVector30[n];
      sRandom rnd;
      rnd.Seed(para->Seed);

      for(sInt i=0;i<n;i++)
      {
        switch(para->Flags)
        {
        case 0:
          dis[i].x = (rnd.Float(1)*2-1);
          dis[i].y = (rnd.Float(1)*2-1);
          dis[i].z = (rnd.Float(1)*2-1);
          break;
        case 1:
          dis[i].InitRandom(rnd);
          break;
        case 2:
          dis[i].InitRandom(rnd);
          dis[i].Unit();
          break;
        }
        dis[i] = dis[i]*0.5*para->Random;
      }

      Wz4ChunkPhysics *ch;
      Wz4MeshVertex *mv;
      sFORALL(out->Vertices,mv)
        mv->Temp = -1;
      sInt n = out->Vertices.GetCount()-1;
      sFORALLREVERSE(out->Chunks,ch)
      {
        ch->COM += dis[_i];
        while(n>=ch->FirstVert)
          out->Vertices[n--].Temp = _i;
      }
      sFORALL(out->Vertices,mv)
        if(mv->Temp>=0)
          mv->Pos += dis[mv->Temp];

      delete[] dis;
    }
  ;
#line 9626 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiRandomizeChunks(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaRandomizeChunks sUNUSED *para = (Wz4MeshParaRandomizeChunks *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Random");
  gh.BeginTied();
  sFloatControl *float_Random_0 = gh.Float(&para->Random.x,-1024.00f,1024.000f,0.010000f);
  float_Random_0->Default = 0.000000f; float_Random_0->RightStep = 0.125000f;
  sFloatControl *float_Random_1 = gh.Float(&para->Random.y,-1024.00f,1024.000f,0.010000f);
  float_Random_1->Default = 0.000000f; float_Random_1->RightStep = 0.125000f;
  sFloatControl *float_Random_2 = gh.Float(&para->Random.z,-1024.00f,1024.000f,0.010000f);
  float_Random_2->Default = 0.000000f; float_Random_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"box|sphere|bouble",gh.ChangeMsg);

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;
}

void Wz4MeshDefRandomizeChunks(wOp *op)
{
  Wz4MeshParaRandomizeChunks sUNUSED *para = (Wz4MeshParaRandomizeChunks *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindRandomizeChunks(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"random"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
}
void Wz4MeshBind2RandomizeChunks(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"random");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"seed");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+4);
}
void Wz4MeshBind3RandomizeChunks(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import random : float[3];\n");
  tb.PrintF(L"  import seed : int;\n");
}
const sChar *Wz4MeshWikiRandomizeChunks =
L"= Wz4Mesh : RandomizeChunks\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i RandomizeChunks\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Random\n"
L" !i Random\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i box\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bouble\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Seed\n"
L" !i Seed\n"
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

sBool Wz4MeshCmdBevel(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaBevel sUNUSED *para = (Wz4MeshParaBevel *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 2165 "wz4_mesh_ops.ops"

    out->CopyFrom(in0);  
    out->Bevel(para->Amount);
  ;
#line 9777 "wz4_mesh_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiBevel(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaBevel sUNUSED *para = (Wz4MeshParaBevel *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Amount");
  sFloatControl *float_Amount = gh.Float(&para->Amount,0.000000f,  1000000,0.001000f);
  float_Amount->Default = 0.125000f; float_Amount->RightStep = 0.125000f;
}

void Wz4MeshDefBevel(wOp *op)
{
  Wz4MeshParaBevel sUNUSED *para = (Wz4MeshParaBevel *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Amount = 0.125000f;
}

void Wz4MeshBindBevel(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
}
void Wz4MeshBind2Bevel(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"amount");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void Wz4MeshBind3Bevel(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import amount : float;\n");
}
const sChar *Wz4MeshWikiBevel =
L"= Wz4Mesh : Bevel\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bevel\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Mesh\n"
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
L" !i Wz4Mesh\n"
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
L" !i Amount\n"
L" !i Amount\n"
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

void Wz4MeshAnimConvertFromChaosMesh::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimConvertFromChaosMesh::Bind(class ScriptContext *sc,Wz4MeshParaConvertFromChaosMesh *para)
{
};

void Wz4MeshAnimExport::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimExport::Bind(class ScriptContext *sc,Wz4MeshParaExport *para)
{
};

void Wz4MeshAnimImport::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimImport::Bind(class ScriptContext *sc,Wz4MeshParaImport *para)
{
};

void Wz4MeshAnimTorus::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTorus::Bind(class ScriptContext *sc,Wz4MeshParaTorus *para)
{
};

void Wz4MeshAnimGrid::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimGrid::Bind(class ScriptContext *sc,Wz4MeshParaGrid *para)
{
};

void Wz4MeshAnimDisc::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimDisc::Bind(class ScriptContext *sc,Wz4MeshParaDisc *para)
{
};

void Wz4MeshAnimSphere::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSphere::Bind(class ScriptContext *sc,Wz4MeshParaSphere *para)
{
};

void Wz4MeshAnimCube::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimCube::Bind(class ScriptContext *sc,Wz4MeshParaCube *para)
{
};

void Wz4MeshAnimCylinder::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimCylinder::Bind(class ScriptContext *sc,Wz4MeshParaCylinder *para)
{
};

void Wz4MeshAnimText3D::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimText3D::Bind(class ScriptContext *sc,Wz4MeshParaText3D *para)
{
};

void Wz4MeshAnimPath3D::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimPath3D::Bind(class ScriptContext *sc,Wz4MeshParaPath3D *para)
{
};

void Wz4MeshAnimNormalize::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimNormalize::Bind(class ScriptContext *sc,Wz4MeshParaNormalize *para)
{
};

void Wz4MeshAnimRandomize::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimRandomize::Bind(class ScriptContext *sc,Wz4MeshParaRandomize *para)
{
};

void Wz4MeshAnimNoise::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimNoise::Bind(class ScriptContext *sc,Wz4MeshParaNoise *para)
{
};

void Wz4MeshAnimInvert::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimInvert::Bind(class ScriptContext *sc,Wz4MeshParaInvert *para)
{
};

void Wz4MeshAnimTriangulate::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTriangulate::Bind(class ScriptContext *sc,Wz4MeshParaTriangulate *para)
{
};

void Wz4MeshAnimDeleteFace::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimDeleteFace::Bind(class ScriptContext *sc,Wz4MeshParaDeleteFace *para)
{
};

void Wz4MeshAnimSetMaterial::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSetMaterial::Bind(class ScriptContext *sc,Wz4MeshParaSetMaterial *para)
{
};

void Wz4MeshAnimTransform::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTransform::Bind(class ScriptContext *sc,Wz4MeshParaTransform *para)
{
};

void Wz4MeshAnimTransformRange::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTransformRange::Bind(class ScriptContext *sc,Wz4MeshParaTransformRange *para)
{
};

void Wz4MeshAnimMirror::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimMirror::Bind(class ScriptContext *sc,Wz4MeshParaMirror *para)
{
};

void Wz4MeshAnimCenter::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimCenter::Bind(class ScriptContext *sc,Wz4MeshParaCenter *para)
{
};

void Wz4MeshAnimSelectGrow::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSelectGrow::Bind(class ScriptContext *sc,Wz4MeshParaSelectGrow *para)
{
};

void Wz4MeshAnimMultiply::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimMultiply::Bind(class ScriptContext *sc,Wz4MeshParaMultiply *para)
{
};

void Wz4MeshAnimMultiplyNew::Init(class ScriptContext *sc)
{
  _PreScale = sc->AddSymbol(L"prescale");
  _PreRot = sc->AddSymbol(L"prerot");
  _PreTrans = sc->AddSymbol(L"pretrans");
  _Count = sc->AddSymbol(L"count");
  _Scale = sc->AddSymbol(L"scale");
  _Rot = sc->AddSymbol(L"rot");
  _Trans = sc->AddSymbol(L"trans");
};

void Wz4MeshAnimMultiplyNew::Bind(class ScriptContext *sc,Wz4MeshParaMultiplyNew *para)
{
  sc->BindLocalFloat(_PreScale,3,&para->PreScale.x);
  sc->BindLocalFloat(_PreRot,3,&para->PreRot.x);
  sc->BindLocalFloat(_PreTrans,3,&para->PreTrans.x);
  sc->BindLocalInt(_Count,1,&para->Count);
  sc->BindLocalFloat(_Scale,3,&para->Scale.x);
  sc->BindLocalFloat(_Rot,3,&para->Rot.x);
  sc->BindLocalFloat(_Trans,3,&para->Trans.x);
};

void Wz4MeshAnimTransformEx::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTransformEx::Bind(class ScriptContext *sc,Wz4MeshParaTransformEx *para)
{
};

void Wz4MeshAnimTransformMatrix::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTransformMatrix::Bind(class ScriptContext *sc,Wz4MeshParaTransformMatrix *para)
{
};

void Wz4MeshAnimTransformNonLinear::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTransformNonLinear::Bind(class ScriptContext *sc,Wz4MeshParaTransformNonLinear *para)
{
};

void Wz4MeshAnimExtrudeNormal::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimExtrudeNormal::Bind(class ScriptContext *sc,Wz4MeshParaExtrudeNormal *para)
{
};

void Wz4MeshAnimBend::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimBend::Bind(class ScriptContext *sc,Wz4MeshParaBend *para)
{
};

void Wz4MeshAnimSubdivide::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSubdivide::Bind(class ScriptContext *sc,Wz4MeshParaSubdivide *para)
{
};

void Wz4MeshAnimExtrude::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimExtrude::Bind(class ScriptContext *sc,Wz4MeshParaExtrude *para)
{
};

void Wz4MeshAnimAdd::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimAdd::Bind(class ScriptContext *sc,Wz4MeshParaAdd *para)
{
};

void Wz4MeshAnimSelect::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSelect::Bind(class ScriptContext *sc,Wz4MeshParaSelect *para)
{
};

void Wz4MeshAnimSplitAlongPlane::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSplitAlongPlane::Bind(class ScriptContext *sc,Wz4MeshParaSplitAlongPlane *para)
{
};

void Wz4MeshAnimBakeAnim::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimBakeAnim::Bind(class ScriptContext *sc,Wz4MeshParaBakeAnim *para)
{
};

void Wz4MeshAnimFacette::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimFacette::Bind(class ScriptContext *sc,Wz4MeshParaFacette *para)
{
};

void Wz4MeshAnimCrease::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimCrease::Bind(class ScriptContext *sc,Wz4MeshParaCrease *para)
{
};

void Wz4MeshAnimUnCrease::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimUnCrease::Bind(class ScriptContext *sc,Wz4MeshParaUnCrease *para)
{
};

void Wz4MeshAnimDisplace::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimDisplace::Bind(class ScriptContext *sc,Wz4MeshParaDisplace *para)
{
};

void Wz4MeshAnimSplitter::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimSplitter::Bind(class ScriptContext *sc,Wz4MeshParaSplitter *para)
{
};

void Wz4MeshAnimDual::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimDual::Bind(class ScriptContext *sc,Wz4MeshParaDual *para)
{
};

void Wz4MeshAnimHeal::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimHeal::Bind(class ScriptContext *sc,Wz4MeshParaHeal *para)
{
};

void Wz4MeshAnimDeform::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimDeform::Bind(class ScriptContext *sc,Wz4MeshParaDeform *para)
{
};

void Wz4MeshAnimChunks::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimChunks::Bind(class ScriptContext *sc,Wz4MeshParaChunks *para)
{
};

void Wz4MeshAnimRandomizeChunks::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimRandomizeChunks::Bind(class ScriptContext *sc,Wz4MeshParaRandomizeChunks *para)
{
};

void Wz4MeshAnimBevel::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimBevel::Bind(class ScriptContext *sc,Wz4MeshParaBevel *para)
{
};


/****************************************************************************/

void AddTypes_wz4_mesh_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4MeshType = new Wz4MeshType_);
  Wz4MeshType->Secondary = secondary;
  Wz4MeshType->ColumnHeaders[0] = L"Primitives";
  Wz4MeshType->ColumnHeaders[1] = L"Vertex";
  Wz4MeshType->ColumnHeaders[2] = L"Topology";
  Wz4MeshType->ColumnHeaders[3] = L"Special";

}

/****************************************************************************/

void AddOps_wz4_mesh_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"ConvertFromChaosMesh";
  cl->Label = L"ConvertFromChaosMesh";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdConvertFromChaosMesh;
  cl->MakeGui = Wz4MeshGuiConvertFromChaosMesh;
  cl->SetDefaults = Wz4MeshDefConvertFromChaosMesh;
  cl->BindPara = Wz4MeshBindConvertFromChaosMesh;
  cl->Bind2Para = Wz4MeshBind2ConvertFromChaosMesh;
  cl->Bind3Para = Wz4MeshBind3ConvertFromChaosMesh;
  cl->WikiText = Wz4MeshWikiConvertFromChaosMesh;
  cl->Column = 3;
  cl->Flags = 0x00c0;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Export";
  cl->Label = L"Export";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdExport;
  cl->MakeGui = Wz4MeshGuiExport;
  cl->SetDefaults = Wz4MeshDefExport;
  cl->BindPara = Wz4MeshBindExport;
  cl->Bind2Para = Wz4MeshBind2Export;
  cl->Bind3Para = Wz4MeshBind3Export;
  cl->WikiText = Wz4MeshWikiExport;
  cl->ParaStrings = 1;
  cl->ParaWords = 2;
  cl->FileOutMask = 1;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Import";
  cl->Label = L"Import";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdImport;
  cl->MakeGui = Wz4MeshGuiImport;
  cl->SetDefaults = Wz4MeshDefImport;
  cl->BindPara = Wz4MeshBindImport;
  cl->Bind2Para = Wz4MeshBind2Import;
  cl->Bind3Para = Wz4MeshBind3Import;
  cl->WikiText = Wz4MeshWikiImport;
  cl->ParaStrings = 1;
  cl->ParaWords = 1;
  cl->FileInMask = 1;
  cl->FileInFilter = L"xsi|wz4mesh|wz3minmesh|lwo|obj";
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Torus";
  cl->Label = L"Torus";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTorus;
  cl->MakeGui = Wz4MeshGuiTorus;
  cl->SetDefaults = Wz4MeshDefTorus;
  cl->BindPara = Wz4MeshBindTorus;
  cl->Bind2Para = Wz4MeshBind2Torus;
  cl->Bind3Para = Wz4MeshBind3Torus;
  cl->WikiText = Wz4MeshWikiTorus;
  cl->ParaWords = 6;
  cl->Shortcut = 'o';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Grid";
  cl->Label = L"Grid";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdGrid;
  cl->MakeGui = Wz4MeshGuiGrid;
  cl->SetDefaults = Wz4MeshDefGrid;
  cl->BindPara = Wz4MeshBindGrid;
  cl->Bind2Para = Wz4MeshBind2Grid;
  cl->Bind3Para = Wz4MeshBind3Grid;
  cl->WikiText = Wz4MeshWikiGrid;
  cl->ParaWords = 4;
  cl->Shortcut = 'g';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Disc";
  cl->Label = L"Disc";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdDisc;
  cl->MakeGui = Wz4MeshGuiDisc;
  cl->SetDefaults = Wz4MeshDefDisc;
  cl->BindPara = Wz4MeshBindDisc;
  cl->Bind2Para = Wz4MeshBind2Disc;
  cl->Bind3Para = Wz4MeshBind3Disc;
  cl->WikiText = Wz4MeshWikiDisc;
  cl->ParaWords = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sphere";
  cl->Label = L"Sphere";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSphere;
  cl->MakeGui = Wz4MeshGuiSphere;
  cl->SetDefaults = Wz4MeshDefSphere;
  cl->BindPara = Wz4MeshBindSphere;
  cl->Bind2Para = Wz4MeshBind2Sphere;
  cl->Bind3Para = Wz4MeshBind3Sphere;
  cl->WikiText = Wz4MeshWikiSphere;
  cl->ParaWords = 5;
  cl->Shortcut = 'h';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Cube";
  cl->Label = L"Cube";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdCube;
  cl->MakeGui = Wz4MeshGuiCube;
  cl->SetDefaults = Wz4MeshDefCube;
  cl->BindPara = Wz4MeshBindCube;
  cl->Bind2Para = Wz4MeshBind2Cube;
  cl->Bind3Para = Wz4MeshBind3Cube;
  cl->WikiText = Wz4MeshWikiCube;
  cl->ParaWords = 6;
  cl->Shortcut = 'q';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Cylinder";
  cl->Label = L"Cylinder";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdCylinder;
  cl->MakeGui = Wz4MeshGuiCylinder;
  cl->SetDefaults = Wz4MeshDefCylinder;
  cl->BindPara = Wz4MeshBindCylinder;
  cl->Bind2Para = Wz4MeshBind2Cylinder;
  cl->Bind3Para = Wz4MeshBind3Cylinder;
  cl->WikiText = Wz4MeshWikiCylinder;
  cl->ParaWords = 6;
  cl->Shortcut = 'c';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Text3D";
  cl->Label = L"Text3D";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdText3D;
  cl->MakeGui = Wz4MeshGuiText3D;
  cl->SetDefaults = Wz4MeshDefText3D;
  cl->BindPara = Wz4MeshBindText3D;
  cl->Bind2Para = Wz4MeshBind2Text3D;
  cl->Bind3Para = Wz4MeshBind3Text3D;
  cl->WikiText = Wz4MeshWikiText3D;
  cl->ParaStrings = 2;
  cl->ParaWords = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Path3D";
  cl->Label = L"Path3D";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdPath3D;
  cl->MakeGui = Wz4MeshGuiPath3D;
  cl->SetDefaults = Wz4MeshDefPath3D;
  cl->BindPara = Wz4MeshBindPath3D;
  cl->Bind2Para = Wz4MeshBind2Path3D;
  cl->Bind3Para = Wz4MeshBind3Path3D;
  cl->WikiText = Wz4MeshWikiPath3D;
  cl->ParaStrings = 1;
  cl->ParaWords = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Normalize";
  cl->Label = L"Normalize";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdNormalize;
  cl->MakeGui = Wz4MeshGuiNormalize;
  cl->SetDefaults = Wz4MeshDefNormalize;
  cl->BindPara = Wz4MeshBindNormalize;
  cl->Bind2Para = Wz4MeshBind2Normalize;
  cl->Bind3Para = Wz4MeshBind3Normalize;
  cl->WikiText = Wz4MeshWikiNormalize;
  cl->ParaWords = 1;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Randomize";
  cl->Label = L"Randomize";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdRandomize;
  cl->MakeGui = Wz4MeshGuiRandomize;
  cl->SetDefaults = Wz4MeshDefRandomize;
  cl->BindPara = Wz4MeshBindRandomize;
  cl->Bind2Para = Wz4MeshBind2Randomize;
  cl->Bind3Para = Wz4MeshBind3Randomize;
  cl->WikiText = Wz4MeshWikiRandomize;
  cl->ParaWords = 4;
  cl->Shortcut = 'r';
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Noise";
  cl->Label = L"Noise";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdNoise;
  cl->MakeGui = Wz4MeshGuiNoise;
  cl->SetDefaults = Wz4MeshDefNoise;
  cl->BindPara = Wz4MeshBindNoise;
  cl->Bind2Para = Wz4MeshBind2Noise;
  cl->Bind3Para = Wz4MeshBind3Noise;
  cl->WikiText = Wz4MeshWikiNoise;
  cl->ParaWords = 10;
  cl->Shortcut = 'p';
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Invert";
  cl->Label = L"Invert";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdInvert;
  cl->MakeGui = Wz4MeshGuiInvert;
  cl->SetDefaults = Wz4MeshDefInvert;
  cl->BindPara = Wz4MeshBindInvert;
  cl->Bind2Para = Wz4MeshBind2Invert;
  cl->Bind3Para = Wz4MeshBind3Invert;
  cl->WikiText = Wz4MeshWikiInvert;
  cl->ParaWords = 1;
  cl->Shortcut = 'i';
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Triangulate";
  cl->Label = L"Triangulate";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTriangulate;
  cl->MakeGui = Wz4MeshGuiTriangulate;
  cl->SetDefaults = Wz4MeshDefTriangulate;
  cl->BindPara = Wz4MeshBindTriangulate;
  cl->Bind2Para = Wz4MeshBind2Triangulate;
  cl->Bind3Para = Wz4MeshBind3Triangulate;
  cl->WikiText = Wz4MeshWikiTriangulate;
  cl->ParaWords = 1;
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DeleteFace";
  cl->Label = L"DeleteFace";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdDeleteFace;
  cl->MakeGui = Wz4MeshGuiDeleteFace;
  cl->SetDefaults = Wz4MeshDefDeleteFace;
  cl->BindPara = Wz4MeshBindDeleteFace;
  cl->Bind2Para = Wz4MeshBind2DeleteFace;
  cl->Bind3Para = Wz4MeshBind3DeleteFace;
  cl->WikiText = Wz4MeshWikiDeleteFace;
  cl->ParaWords = 2;
  cl->Shortcut = 'd';
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SetMaterial";
  cl->Label = L"SetMaterial";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSetMaterial;
  cl->MakeGui = Wz4MeshGuiSetMaterial;
  cl->SetDefaults = Wz4MeshDefSetMaterial;
  cl->BindPara = Wz4MeshBindSetMaterial;
  cl->Bind2Para = Wz4MeshBind2SetMaterial;
  cl->Bind3Para = Wz4MeshBind3SetMaterial;
  cl->WikiText = Wz4MeshWikiSetMaterial;
  cl->ParaWords = 2;
  cl->Shortcut = 'M';
  cl->Column = 3;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MtrlType;
  in[1].DefaultClass = 0;
  in[1].Name = L"Material";
  in[1].Flags = 0|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Transform";
  cl->Label = L"Transform";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTransform;
  cl->MakeGui = Wz4MeshGuiTransform;
  cl->SetDefaults = Wz4MeshDefTransform;
  cl->BindPara = Wz4MeshBindTransform;
  cl->Bind2Para = Wz4MeshBind2Transform;
  cl->Bind3Para = Wz4MeshBind3Transform;
  cl->WikiText = Wz4MeshWikiTransform;
  cl->ParaWords = 10;
  cl->Shortcut = 't';
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TransformRange";
  cl->Label = L"TransformRange";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTransformRange;
  cl->MakeGui = Wz4MeshGuiTransformRange;
  cl->SetDefaults = Wz4MeshDefTransformRange;
  cl->BindPara = Wz4MeshBindTransformRange;
  cl->Bind2Para = Wz4MeshBind2TransformRange;
  cl->Bind3Para = Wz4MeshBind3TransformRange;
  cl->WikiText = Wz4MeshWikiTransformRange;
  cl->Handles = Wz4MeshHndTransformRange;
  cl->ParaWords = 25;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Mirror";
  cl->Label = L"Mirror";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdMirror;
  cl->MakeGui = Wz4MeshGuiMirror;
  cl->SetDefaults = Wz4MeshDefMirror;
  cl->BindPara = Wz4MeshBindMirror;
  cl->Bind2Para = Wz4MeshBind2Mirror;
  cl->Bind3Para = Wz4MeshBind3Mirror;
  cl->WikiText = Wz4MeshWikiMirror;
  cl->ParaWords = 5;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Center";
  cl->Label = L"Center";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdCenter;
  cl->MakeGui = Wz4MeshGuiCenter;
  cl->SetDefaults = Wz4MeshDefCenter;
  cl->BindPara = Wz4MeshBindCenter;
  cl->Bind2Para = Wz4MeshBind2Center;
  cl->Bind3Para = Wz4MeshBind3Center;
  cl->WikiText = Wz4MeshWikiCenter;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SelectGrow";
  cl->Label = L"SelectGrow";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSelectGrow;
  cl->MakeGui = Wz4MeshGuiSelectGrow;
  cl->SetDefaults = Wz4MeshDefSelectGrow;
  cl->BindPara = Wz4MeshBindSelectGrow;
  cl->Bind2Para = Wz4MeshBind2SelectGrow;
  cl->Bind3Para = Wz4MeshBind3SelectGrow;
  cl->WikiText = Wz4MeshWikiSelectGrow;
  cl->ParaWords = 5;
  cl->Column = 3;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Multiply";
  cl->Label = L"Multiply (old)";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdMultiply;
  cl->MakeGui = Wz4MeshGuiMultiply;
  cl->SetDefaults = Wz4MeshDefMultiply;
  cl->BindPara = Wz4MeshBindMultiply;
  cl->Bind2Para = Wz4MeshBind2Multiply;
  cl->Bind3Para = Wz4MeshBind3Multiply;
  cl->WikiText = Wz4MeshWikiMultiply;
  cl->ParaWords = 11;
  cl->Column = 3;
  cl->Flags = 0x0040;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MultiplyNew";
  cl->Label = L"Multiply";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdMultiplyNew;
  cl->MakeGui = Wz4MeshGuiMultiplyNew;
  cl->SetDefaults = Wz4MeshDefMultiplyNew;
  cl->BindPara = Wz4MeshBindMultiplyNew;
  cl->Bind2Para = Wz4MeshBind2MultiplyNew;
  cl->Bind3Para = Wz4MeshBind3MultiplyNew;
  cl->WikiText = Wz4MeshWikiMultiplyNew;
  cl->ParaWords = 21;
  cl->Shortcut = 'm';
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TransformEx";
  cl->Label = L"TransformEx";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTransformEx;
  cl->MakeGui = Wz4MeshGuiTransformEx;
  cl->SetDefaults = Wz4MeshDefTransformEx;
  cl->BindPara = Wz4MeshBindTransformEx;
  cl->Bind2Para = Wz4MeshBind2TransformEx;
  cl->Bind3Para = Wz4MeshBind3TransformEx;
  cl->WikiText = Wz4MeshWikiTransformEx;
  cl->ParaWords = 11;
  cl->Shortcut = 'T';
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TransformMatrix";
  cl->Label = L"TransformMatrix";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTransformMatrix;
  cl->MakeGui = Wz4MeshGuiTransformMatrix;
  cl->SetDefaults = Wz4MeshDefTransformMatrix;
  cl->BindPara = Wz4MeshBindTransformMatrix;
  cl->Bind2Para = Wz4MeshBind2TransformMatrix;
  cl->Bind3Para = Wz4MeshBind3TransformMatrix;
  cl->WikiText = Wz4MeshWikiTransformMatrix;
  cl->ParaWords = 14;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TransformNonLinear";
  cl->Label = L"TransformNonLinear";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTransformNonLinear;
  cl->MakeGui = Wz4MeshGuiTransformNonLinear;
  cl->SetDefaults = Wz4MeshDefTransformNonLinear;
  cl->BindPara = Wz4MeshBindTransformNonLinear;
  cl->Bind2Para = Wz4MeshBind2TransformNonLinear;
  cl->Bind3Para = Wz4MeshBind3TransformNonLinear;
  cl->WikiText = Wz4MeshWikiTransformNonLinear;
  cl->ParaWords = 38;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ExtrudeNormal";
  cl->Label = L"ExtrudeNormal";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdExtrudeNormal;
  cl->MakeGui = Wz4MeshGuiExtrudeNormal;
  cl->SetDefaults = Wz4MeshDefExtrudeNormal;
  cl->BindPara = Wz4MeshBindExtrudeNormal;
  cl->Bind2Para = Wz4MeshBind2ExtrudeNormal;
  cl->Bind3Para = Wz4MeshBind3ExtrudeNormal;
  cl->WikiText = Wz4MeshWikiExtrudeNormal;
  cl->ParaWords = 2;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bend";
  cl->Label = L"Bend";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdBend;
  cl->MakeGui = Wz4MeshGuiBend;
  cl->SetDefaults = Wz4MeshDefBend;
  cl->BindPara = Wz4MeshBindBend;
  cl->Bind2Para = Wz4MeshBind2Bend;
  cl->Bind3Para = Wz4MeshBind3Bend;
  cl->WikiText = Wz4MeshWikiBend;
  cl->Handles = Wz4MeshHndBend;
  cl->ParaWords = 13;
  cl->HelperWords = (sizeof(Wz4MeshHelperBend)+3)/4;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Subdivide";
  cl->Label = L"Subdivide";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSubdivide;
  cl->MakeGui = Wz4MeshGuiSubdivide;
  cl->SetDefaults = Wz4MeshDefSubdivide;
  cl->BindPara = Wz4MeshBindSubdivide;
  cl->Bind2Para = Wz4MeshBind2Subdivide;
  cl->Bind3Para = Wz4MeshBind3Subdivide;
  cl->WikiText = Wz4MeshWikiSubdivide;
  cl->ParaWords = 3;
  cl->Shortcut = 'u';
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Extrude";
  cl->Label = L"Extrude";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdExtrude;
  cl->MakeGui = Wz4MeshGuiExtrude;
  cl->SetDefaults = Wz4MeshDefExtrude;
  cl->BindPara = Wz4MeshBindExtrude;
  cl->Bind2Para = Wz4MeshBind2Extrude;
  cl->Bind3Para = Wz4MeshBind3Extrude;
  cl->WikiText = Wz4MeshWikiExtrude;
  cl->ParaWords = 10;
  cl->Shortcut = 'e';
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Add";
  cl->Label = L"Add";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdAdd;
  cl->MakeGui = Wz4MeshGuiAdd;
  cl->SetDefaults = Wz4MeshDefAdd;
  cl->BindPara = Wz4MeshBindAdd;
  cl->Bind2Para = Wz4MeshBind2Add;
  cl->Bind3Para = Wz4MeshBind3Add;
  cl->WikiText = Wz4MeshWikiAdd;
  cl->Shortcut = 'a';
  cl->Column = 3;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Select";
  cl->Label = L"Select";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSelect;
  cl->MakeGui = Wz4MeshGuiSelect;
  cl->SetDefaults = Wz4MeshDefSelect;
  cl->BindPara = Wz4MeshBindSelect;
  cl->Bind2Para = Wz4MeshBind2Select;
  cl->Bind3Para = Wz4MeshBind3Select;
  cl->WikiText = Wz4MeshWikiSelect;
  cl->Handles = Wz4MeshHndSelect;
  cl->ParaWords = 19;
  cl->Shortcut = 'S';
  cl->Column = 3;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = GenBitmapType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SplitAlongPlane";
  cl->Label = L"SplitAlongPlane";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSplitAlongPlane;
  cl->MakeGui = Wz4MeshGuiSplitAlongPlane;
  cl->SetDefaults = Wz4MeshDefSplitAlongPlane;
  cl->BindPara = Wz4MeshBindSplitAlongPlane;
  cl->Bind2Para = Wz4MeshBind2SplitAlongPlane;
  cl->Bind3Para = Wz4MeshBind3SplitAlongPlane;
  cl->WikiText = Wz4MeshWikiSplitAlongPlane;
  cl->ParaWords = 6;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BakeAnim";
  cl->Label = L"BakeAnim";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdBakeAnim;
  cl->MakeGui = Wz4MeshGuiBakeAnim;
  cl->SetDefaults = Wz4MeshDefBakeAnim;
  cl->BindPara = Wz4MeshBindBakeAnim;
  cl->Bind2Para = Wz4MeshBind2BakeAnim;
  cl->Bind3Para = Wz4MeshBind3BakeAnim;
  cl->WikiText = Wz4MeshWikiBakeAnim;
  cl->ParaWords = 1;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Facette";
  cl->Label = L"Facette";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdFacette;
  cl->MakeGui = Wz4MeshGuiFacette;
  cl->SetDefaults = Wz4MeshDefFacette;
  cl->BindPara = Wz4MeshBindFacette;
  cl->Bind2Para = Wz4MeshBind2Facette;
  cl->Bind3Para = Wz4MeshBind3Facette;
  cl->WikiText = Wz4MeshWikiFacette;
  cl->ParaWords = 1;
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Crease";
  cl->Label = L"Crease";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdCrease;
  cl->MakeGui = Wz4MeshGuiCrease;
  cl->SetDefaults = Wz4MeshDefCrease;
  cl->BindPara = Wz4MeshBindCrease;
  cl->Bind2Para = Wz4MeshBind2Crease;
  cl->Bind3Para = Wz4MeshBind3Crease;
  cl->WikiText = Wz4MeshWikiCrease;
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"UnCrease";
  cl->Label = L"UnCrease";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdUnCrease;
  cl->MakeGui = Wz4MeshGuiUnCrease;
  cl->SetDefaults = Wz4MeshDefUnCrease;
  cl->BindPara = Wz4MeshBindUnCrease;
  cl->Bind2Para = Wz4MeshBind2UnCrease;
  cl->Bind3Para = Wz4MeshBind3UnCrease;
  cl->WikiText = Wz4MeshWikiUnCrease;
  cl->ParaWords = 1;
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Displace";
  cl->Label = L"Displace";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdDisplace;
  cl->MakeGui = Wz4MeshGuiDisplace;
  cl->SetDefaults = Wz4MeshDefDisplace;
  cl->BindPara = Wz4MeshBindDisplace;
  cl->Bind2Para = Wz4MeshBind2Displace;
  cl->Bind3Para = Wz4MeshBind3Displace;
  cl->WikiText = Wz4MeshWikiDisplace;
  cl->ParaWords = 13;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = BitmapBaseType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Splitter";
  cl->Label = L"Splitter";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdSplitter;
  cl->MakeGui = Wz4MeshGuiSplitter;
  cl->SetDefaults = Wz4MeshDefSplitter;
  cl->BindPara = Wz4MeshBindSplitter;
  cl->Bind2Para = Wz4MeshBind2Splitter;
  cl->Bind3Para = Wz4MeshBind3Splitter;
  cl->WikiText = Wz4MeshWikiSplitter;
  cl->ParaWords = 2;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Dual";
  cl->Label = L"Dual";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdDual;
  cl->MakeGui = Wz4MeshGuiDual;
  cl->SetDefaults = Wz4MeshDefDual;
  cl->BindPara = Wz4MeshBindDual;
  cl->Bind2Para = Wz4MeshBind2Dual;
  cl->Bind3Para = Wz4MeshBind3Dual;
  cl->WikiText = Wz4MeshWikiDual;
  cl->ParaWords = 1;
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Heal";
  cl->Label = L"Heal";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdHeal;
  cl->MakeGui = Wz4MeshGuiHeal;
  cl->SetDefaults = Wz4MeshDefHeal;
  cl->BindPara = Wz4MeshBindHeal;
  cl->Bind2Para = Wz4MeshBind2Heal;
  cl->Bind3Para = Wz4MeshBind3Heal;
  cl->WikiText = Wz4MeshWikiHeal;
  cl->ParaWords = 3;
  cl->Column = 3;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Name = L"Reference";
  in[1].Flags = 0|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Deform";
  cl->Label = L"Deform";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdDeform;
  cl->MakeGui = Wz4MeshGuiDeform;
  cl->SetDefaults = Wz4MeshDefDeform;
  cl->BindPara = Wz4MeshBindDeform;
  cl->Bind2Para = Wz4MeshBind2Deform;
  cl->Bind3Para = Wz4MeshBind3Deform;
  cl->WikiText = Wz4MeshWikiDeform;
  cl->Handles = Wz4MeshHndDeform;
  cl->SetDefaultsArray = Wz4MeshArrDeform;
  cl->Actions = Wz4MeshActDeform;
  cl->ArrayCount = 5;
  cl->ParaWords = 13;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  cl->ActionIds.AddMany(1)->Init(L"ResetKeys",1);
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Chunks";
  cl->Label = L"Chunks";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdChunks;
  cl->MakeGui = Wz4MeshGuiChunks;
  cl->SetDefaults = Wz4MeshDefChunks;
  cl->BindPara = Wz4MeshBindChunks;
  cl->Bind2Para = Wz4MeshBind2Chunks;
  cl->Bind3Para = Wz4MeshBind3Chunks;
  cl->WikiText = Wz4MeshWikiChunks;
  cl->ParaWords = 7;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"RandomizeChunks";
  cl->Label = L"RandomizeChunks";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdRandomizeChunks;
  cl->MakeGui = Wz4MeshGuiRandomizeChunks;
  cl->SetDefaults = Wz4MeshDefRandomizeChunks;
  cl->BindPara = Wz4MeshBindRandomizeChunks;
  cl->Bind2Para = Wz4MeshBind2RandomizeChunks;
  cl->Bind3Para = Wz4MeshBind3RandomizeChunks;
  cl->WikiText = Wz4MeshWikiRandomizeChunks;
  cl->ParaWords = 5;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bevel";
  cl->Label = L"Bevel";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdBevel;
  cl->MakeGui = Wz4MeshGuiBevel;
  cl->SetDefaults = Wz4MeshDefBevel;
  cl->BindPara = Wz4MeshBindBevel;
  cl->Bind2Para = Wz4MeshBind2Bevel;
  cl->Bind3Para = Wz4MeshBind3Bevel;
  cl->WikiText = Wz4MeshWikiBevel;
  cl->ParaWords = 1;
  cl->Shortcut = 'b';
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_mesh_ops,0x110,AddOps_wz4_mesh_ops,0);


/****************************************************************************/


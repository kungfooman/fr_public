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
#include "chaosmesh_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class ChaosMeshType_ *ChaosMeshType;

/****************************************************************************/

#line 40 "chaosmesh_ops.ops"
void ChaosMeshType_::Init()
{
#line 41 "chaosmesh_ops.ops"

    WireGeo = new sGeometry;
    WireGeo->Init(sGF_LINELIST|sGF_INDEX32,sVertexFormatSingle);
    FlatGeo = new sGeometry;
    FlatGeo->Init(sGF_TRILIST|sGF_INDEX32,sVertexFormatBasic);
    QuadGeo = new sGeometry;
    QuadGeo->Init(sGF_QUADLIST,sVertexFormatBasic);
  ;
#line 35 "chaosmesh_ops.cpp"
}
#line 50 "chaosmesh_ops.ops"
void ChaosMeshType_::Exit()
{
#line 51 "chaosmesh_ops.ops"

    sDelete(WireGeo);
    sDelete(FlatGeo);
    sDelete(QuadGeo);
  ;
#line 46 "chaosmesh_ops.cpp"
}
#line 57 "chaosmesh_ops.ops"
void ChaosMeshType_::BeginEngine(wPaintInfo &pi,sBool clear)
{
#line 58 "chaosmesh_ops.ops"

    sSetTarget(sTargetPara(clear ? sST_CLEARALL : 0,pi.BackColor,pi.Spec));
    pi.View->SetTargetCurrent();
    pi.View->SetZoom(pi.Zoom3D);
    pi.View->Prepare();
  ;
#line 58 "chaosmesh_ops.cpp"
}
#line 65 "chaosmesh_ops.ops"
void ChaosMeshType_::Paint(wObject *obj,wPaintInfo &pi,sMatrix34 *mat,sInt matcount)
{
#line 66 "chaosmesh_ops.ops"

    if(obj && obj->IsType(ChaosMeshType))
    {
      SceneInstance si;
      si.Init();
      ChaosMesh *mesh = (ChaosMesh *) obj;
      si.Time = 0;
      if(mesh->Skeleton && mesh->Skeleton->TotalTime>0)
        si.Time = sMod(pi.TimeMS / (mesh->Skeleton->TotalTime*1000),1);
      for(sInt i=0;i<matcount;i++)
      {
        pi.View->UpdateModelMatrix(mat[i]);
        mesh->Paint(pi.View,&si);
      }
    }
  ;
#line 80 "chaosmesh_ops.cpp"
}
#line 83 "chaosmesh_ops.ops"
void ChaosMeshType_::Hit(wObject *obj,const sRay &ray,wHitInfo &info)
{
#line 84 "chaosmesh_ops.ops"

    sClear(info);
//    if(obj->IsType(PocMeshType))
//      ((PocMesh *)obj)->Hit(ray,info);
  ;
#line 91 "chaosmesh_ops.cpp"
}
#line 90 "chaosmesh_ops.ops"
void ChaosMeshType_::Wireframe(wObject *obj,wPaintInfo &pi,sMatrix34 &mat)
{
#line 91 "chaosmesh_ops.ops"

    if(obj && obj->IsType(ChaosMeshType))
    {
      ChaosMesh *mesh = (ChaosMesh *) obj;

      pi.View->UpdateModelMatrix(mat);
      sCBuffer<sSimpleMaterialPara> cb;
      cb.Modify();
      cb.Data->Set(*pi.View);

      pi.FlatMtrl->Set(&cb);
      sF32 time = 0;
      if(mesh->Skeleton && mesh->Skeleton->TotalTime>0)
        time = sMod(pi.TimeMS / (mesh->Skeleton->TotalTime*1000),1);
      mesh->PaintWire(WireGeo,time);
      mesh->PaintSelection(FlatGeo,QuadGeo,1/pi.View->ZoomX*0.012f,time,pi.View);
    }
  ;
#line 115 "chaosmesh_ops.cpp"
}
#line 109 "chaosmesh_ops.ops"
void ChaosMeshType_::ListExtractions(wObject *obj,void (* cb)(const sChar *name,wType *type),const sChar *storename)
{
#line 110 "chaosmesh_ops.ops"

    ChaosMeshModel *model;
    ChaosMesh *mesh;
    wDocName buffer;
    sArray<Texture2D *> tex2da;
    sArray<TextureCube *> texcubea;
    Texture2D *tex2d;
    TextureCube *texcube;

    sVERIFY(obj->Type==ChaosMeshType);
    mesh = (ChaosMesh *) obj;
    sFORALL(mesh->Models,model)
    {
      sSPrintF(buffer,L"%s:mesh.%s",storename,model->Name);
      (*cb)(buffer,ChaosMeshType);
    }
    if(mesh->Skeleton)
    {
      sSPrintF(buffer,L"%s:skeleton",storename);
      (*cb)(buffer,Wz4SkeletonType);
    }

    mesh->ListTextures(tex2da);
    sFORALL(tex2da,tex2d)
    {
      sSPrintF(buffer,L"%s:tex.%d",storename,_i);
      (*cb)(buffer,Texture2DType);
    }
    mesh->ListTextures(texcubea);
    sFORALL(texcubea,texcube)
    {
      sSPrintF(buffer,L"%s:cube.%d",storename,_i);
      (*cb)(buffer,TextureCubeType);
    }
  ;
#line 156 "chaosmesh_ops.cpp"
}

/****************************************************************************/

sBool ChaosMeshCmdExtract_ChaosMesh_ChaosMesh(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaExtract_ChaosMesh_ChaosMesh sUNUSED *para = (ChaosMeshParaExtract_ChaosMesh_ChaosMesh *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 162 "chaosmesh_ops.ops"

    ChaosMeshModel *model;

    const sChar *name = cmd->Strings[0];
    if(sCmpStringLen(name,L"mesh.",5)==0)
    {
      name += 5;
      sFORALL(in0->Models,model)
      {
        if(sCmpString(model->Name,name)==0)
        {
          out->CopyFrom(model);

          return 1;
        }
      }
    }
    return 0;
  ;
#line 189 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiExtract_ChaosMesh_ChaosMesh(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaExtract_ChaosMesh_ChaosMesh sUNUSED *para = (ChaosMeshParaExtract_ChaosMesh_ChaosMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);
}

void ChaosMeshDefExtract_ChaosMesh_ChaosMesh(wOp *op)
{
  ChaosMeshParaExtract_ChaosMesh_ChaosMesh sUNUSED *para = (ChaosMeshParaExtract_ChaosMesh_ChaosMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindExtract_ChaosMesh_ChaosMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
}
void ChaosMeshBind2Extract_ChaosMesh_ChaosMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"name");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void ChaosMeshBind3Extract_ChaosMesh_ChaosMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
}
const sChar *ChaosMeshWikiExtract_ChaosMesh_ChaosMesh =
L"= ChaosMesh : Extract_ChaosMesh_ChaosMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Extract_ChaosMesh_ChaosMesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Name\n"
L" !i Name\n"
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

sBool Texture2DCmdExtract_ChaosMesh_Texture2D(wExecutive *exe,wCommand *cmd)
{
  Texture2DParaExtract_ChaosMesh_Texture2D sUNUSED *para = (Texture2DParaExtract_ChaosMesh_Texture2D *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  Texture2D *out = (Texture2D *) cmd->Output;
  if(!out) { out=new Texture2D; cmd->Output=out; }

  {
#line 194 "chaosmesh_ops.ops"

    sArray<Texture2D *> textures;
    Texture2D *tex;

    const sChar *name = cmd->Strings[0];
    if(sCmpStringLen(name,L"tex.",4)==0)
    {
      name += 4;

      in0->ListTextures(textures);
      sFORALL(textures,tex)
      {
        sString<8> buffer;
        const sChar *tname = tex->Name;
        if(tname[0]==0)
        {
          sSPrintF(buffer,L"%d",_i);
          tname = buffer;
        }

        if(sCmpString(tname,name)==0)
        {
          cmd->Output->Release();
          cmd->Output = tex;
          cmd->Output->AddRef();

          return 1;
        }
      }
    }
    return 0;
  ;
#line 322 "chaosmesh_ops.cpp"
    return 1;
  }
}

void Texture2DGuiExtract_ChaosMesh_Texture2D(wGridFrameHelper &gh,wOp *op)
{
  Texture2DParaExtract_ChaosMesh_Texture2D sUNUSED *para = (Texture2DParaExtract_ChaosMesh_Texture2D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);
}

void Texture2DDefExtract_ChaosMesh_Texture2D(wOp *op)
{
  Texture2DParaExtract_ChaosMesh_Texture2D sUNUSED *para = (Texture2DParaExtract_ChaosMesh_Texture2D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Texture2DBindExtract_ChaosMesh_Texture2D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
}
void Texture2DBind2Extract_ChaosMesh_Texture2D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"name");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void Texture2DBind3Extract_ChaosMesh_Texture2D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
}
const sChar *Texture2DWikiExtract_ChaosMesh_Texture2D =
L"= Texture2D : Extract_ChaosMesh_Texture2D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Extract_ChaosMesh_Texture2D\n"
L"\n"
L"  !i Output Type\n"
L"  !i Texture2D\n"
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
L" !i Name\n"
L" !i Name\n"
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

sBool TextureCubeCmdExtract_ChaosMesh_TextureCube(wExecutive *exe,wCommand *cmd)
{
  TextureCubeParaExtract_ChaosMesh_TextureCube sUNUSED *para = (TextureCubeParaExtract_ChaosMesh_TextureCube *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  TextureCube *out = (TextureCube *) cmd->Output;
  if(!out) { out=new TextureCube; cmd->Output=out; }

  {
#line 239 "chaosmesh_ops.ops"

    sArray<TextureCube *> textures;
    TextureCube *tex;

    const sChar *name = cmd->Strings[0];
    if(sCmpStringLen(name,L"cube.",5)==0)
    {
      name += 5;

      in0->ListTextures(textures);
      sFORALL(textures,tex)
      {
        sString<8> buffer;
        const sChar *tname;// = tex->Name;
//        if(tname[0]==0)
        {
          sSPrintF(buffer,L"%d",_i);
          tname = buffer;
        }

        if(sCmpString(tname,name)==0)
        {
          cmd->Output->Release();
          cmd->Output = tex;
          cmd->Output->AddRef();

          return 1;
        }
      }
    }
    return 0;
  ;
#line 455 "chaosmesh_ops.cpp"
    return 1;
  }
}

void TextureCubeGuiExtract_ChaosMesh_TextureCube(wGridFrameHelper &gh,wOp *op)
{
  TextureCubeParaExtract_ChaosMesh_TextureCube sUNUSED *para = (TextureCubeParaExtract_ChaosMesh_TextureCube *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);
}

void TextureCubeDefExtract_ChaosMesh_TextureCube(wOp *op)
{
  TextureCubeParaExtract_ChaosMesh_TextureCube sUNUSED *para = (TextureCubeParaExtract_ChaosMesh_TextureCube *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void TextureCubeBindExtract_ChaosMesh_TextureCube(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
}
void TextureCubeBind2Extract_ChaosMesh_TextureCube(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"name");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void TextureCubeBind3Extract_ChaosMesh_TextureCube(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
}
const sChar *TextureCubeWikiExtract_ChaosMesh_TextureCube =
L"= TextureCube : Extract_ChaosMesh_TextureCube\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Extract_ChaosMesh_TextureCube\n"
L"\n"
L"  !i Output Type\n"
L"  !i TextureCube\n"
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
L" !i Name\n"
L" !i Name\n"
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

sBool Wz4SkeletonCmdExtract_ChaosMesh_Wz4Skeleton(wExecutive *exe,wCommand *cmd)
{
  Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton sUNUSED *para = (Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  Wz4Skeleton *out = (Wz4Skeleton *) cmd->Output;
  if(!out) { out=new Wz4Skeleton; cmd->Output=out; }

  {
#line 284 "chaosmesh_ops.ops"

    const sChar *name = cmd->Strings[0];
    if(sCmpString(name,L"skeleton")==0 && in0->Skeleton)
    {
      cmd->Output->Release();
      cmd->Output = in0->Skeleton;
      cmd->Output->AddRef();
    }
    return 1;
  ;
#line 566 "chaosmesh_ops.cpp"
    return 1;
  }
}

void Wz4SkeletonGuiExtract_ChaosMesh_Wz4Skeleton(wGridFrameHelper &gh,wOp *op)
{
  Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton sUNUSED *para = (Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);
}

void Wz4SkeletonDefExtract_ChaosMesh_Wz4Skeleton(wOp *op)
{
  Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton sUNUSED *para = (Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4SkeletonBindExtract_ChaosMesh_Wz4Skeleton(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
}
void Wz4SkeletonBind2Extract_ChaosMesh_Wz4Skeleton(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"name");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4SkeletonBind3Extract_ChaosMesh_Wz4Skeleton(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
}
const sChar *Wz4SkeletonWikiExtract_ChaosMesh_Wz4Skeleton =
L"= Wz4Skeleton : Extract_ChaosMesh_Wz4Skeleton\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Extract_ChaosMesh_Wz4Skeleton\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Skeleton\n"
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
L" !i Name\n"
L" !i Name\n"
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

sBool ChaosMeshCmdExport(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaExport sUNUSED *para = (ChaosMeshParaExport *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 312 "chaosmesh_ops.ops"

    out->CopyFrom(in0);

    sSaveObject(cmd->Strings[0],out);

    return 1;
  ;
#line 674 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiExport(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaExport sUNUSED *para = (ChaosMeshParaExport *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Filename");
  {
    sControl *con = gh.String(op->EditString[0]);
    con->DoneMsg = con->ChangeMsg;
    con->ChangeMsg = sMessage();
    gh.FileSaveDialogMsg.Code = 0;
    gh.Box(L"...",gh.FileSaveDialogMsg);
  }
}

void ChaosMeshDefExport(wOp *op)
{
  ChaosMeshParaExport sUNUSED *para = (ChaosMeshParaExport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindExport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void ChaosMeshBind2Export(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"filename");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void ChaosMeshBind3Export(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *ChaosMeshWikiExport =
L"= ChaosMesh : Export\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Export\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ChaosMeshCmdExportXSI(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaExportXSI sUNUSED *para = (ChaosMeshParaExportXSI *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 332 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    out->ExportXSI(cmd->Strings[0]);
    return 1;
  ;
#line 786 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiExportXSI(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaExportXSI sUNUSED *para = (ChaosMeshParaExportXSI *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Filename");
  {
    sControl *con = gh.String(op->EditString[0]);
    con->DoneMsg = con->ChangeMsg;
    con->ChangeMsg = sMessage();
    gh.FileSaveDialogMsg.Code = 0;
    gh.Box(L"...",gh.FileSaveDialogMsg);
  }
}

void ChaosMeshDefExportXSI(wOp *op)
{
  ChaosMeshParaExportXSI sUNUSED *para = (ChaosMeshParaExportXSI *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindExportXSI(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void ChaosMeshBind2ExportXSI(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"filename");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void ChaosMeshBind3ExportXSI(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *ChaosMeshWikiExportXSI =
L"= ChaosMesh : ExportXSI\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ExportXSI\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ChaosMeshCmdImport(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaImport sUNUSED *para = (ChaosMeshParaImport *)(cmd->Data); para;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 354 "chaosmesh_ops.ops"

    sBool result = 0;
    const sChar *name = cmd->Strings[0];
    const sChar *ext = sFindFileExtension(name);
    if(sCmpStringI(ext,L"cm")==0)
    {
      result = sLoadObject(name,out);
    }
    else if(sCmpStringI(ext,L"xsi")==0)
    {
      result = LoadXSI(out,name,para->Flags&1,para->Flags&2);
      if(result) 
        out->SplitForMatrices();
    }

    return result;
  ;
#line 909 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiImport(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaImport sUNUSED *para = (ChaosMeshParaImport *)(op->EditData); para;
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

void ChaosMeshDefImport(wOp *op)
{
  ChaosMeshParaImport sUNUSED *para = (ChaosMeshParaImport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindImport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void ChaosMeshBind2Import(wCommand *cmd,ScriptContext *ctx)
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
void ChaosMeshBind3Import(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *ChaosMeshWikiImport =
L"= ChaosMesh : Import\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Import\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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

sBool ChaosMeshCmdtorus(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParatorus sUNUSED *para = (ChaosMeshParatorus *)(cmd->Data); para;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 394 "chaosmesh_ops.ops"

    sF32 ro,ri;
    sInt ty = para->Sections;
    sInt tx = para->Slices;
    if(para->Flags & 1)
    {
      ri = (para->Outer-para->Inner)/2;
      ro = (para->Outer+para->Inner)/2;
    }
    else
    {
      ro = para->Outer;
      ri = para->Inner;
    }

    sMatrix34 mat;
    if(para->Flags & 2)
      mat.l.y = ri;

    out->AddCluster(0);
    out->AddTorus(mat,tx,ty,ri,ro,para->Phase,para->Arc);
    return 1;
  ;
#line 1045 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuitorus(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParatorus sUNUSED *para = (ChaosMeshParatorus *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Inner");
  sFloatControl *float_Inner = gh.Float(&para->Inner,0.000000f,1024.000f,0.010000f);
  float_Inner->Default = 0.250000f; float_Inner->RightStep = 0.125000f;

  gh.Label(L"Outer");
  sFloatControl *float_Outer = gh.Float(&para->Outer,0.000000f,1024.000f,0.010000f);
  float_Outer->Default = 1.000000f; float_Outer->RightStep = 0.125000f;

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,-64.0000f,64.00000f,0.010000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;

  gh.Label(L"Sections");
  sIntControl *int_Sections = gh.Int(&para->Sections,3,64,0.125000f);
  int_Sections->Default = 0x00000004; int_Sections->RightStep = 0.125000f;

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,3,64,0.125000f);
  int_Slices->Default = 0x00000004; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Radius Mode");
  gh.Flags(&para->Flags,L"relative|absolute",gh.ChangeMsg);

  gh.Label(L"Origin");
  gh.Flags(&para->Flags,L"*1center|bottom",gh.ChangeMsg);

  gh.Label(L"Arc");
  sFloatControl *float_Arc = gh.Float(&para->Arc,-64.0000f,64.00000f,0.010000f);
  float_Arc->Default = 1.000000f; float_Arc->RightStep = 0.125000f;
}

void ChaosMeshDeftorus(wOp *op)
{
  ChaosMeshParatorus sUNUSED *para = (ChaosMeshParatorus *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Inner = 0.250000f;
  para->Outer = 1.000000f;
  para->Sections = 0x00000004;
  para->Slices = 0x00000004;
  para->Arc = 1.000000f;
}

void ChaosMeshBindtorus(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"inner"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"outer"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"sections"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"arc"),val);
}
void ChaosMeshBind2torus(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"inner");
    name[1] = sPoolString(L"outer");
    name[2] = sPoolString(L"phase");
    name[3] = sPoolString(L"sections");
    name[4] = sPoolString(L"slices");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"origin");
    name[7] = sPoolString(L"arc");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+6);
}
void ChaosMeshBind3torus(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import inner : float;\n");
  tb.PrintF(L"  import outer : float;\n");
  tb.PrintF(L"  import phase : float;\n");
  tb.PrintF(L"  import sections : int;\n");
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import arc : float;\n");
}
const sChar *ChaosMeshWikitorus =
L"= ChaosMesh : torus\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i torus\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Inner\n"
L" !i Inner\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Outer\n"
L" !i Outer\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Phase\n"
L" !i Phase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Sections\n"
L" !i Sections\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Slices\n"
L" !i Slices\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Radius Mode\n"
L" !i Flags\n"
L" !i relative\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i absolute\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Origin\n"
L" !i Flags\n"
L" !i center\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bottom\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool ChaosMeshCmdgrid(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParagrid sUNUSED *para = (ChaosMeshParagrid *)(cmd->Data); para;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 430 "chaosmesh_ops.ops"

    sMatrix34 mat;
    mat.i.Init(-1,0,0);
    mat.j.Init(0,0,1);
    out->AddCluster(0);
    out->AddGrid(mat,para->Tesselation[0],para->Tesselation[1],para->Mode&1);
  ;
#line 1248 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuigrid(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParagrid sUNUSED *para = (ChaosMeshParagrid *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"inverted|doublesided|singlesided",gh.ChangeMsg);

  gh.Label(L"Tesselation");
  gh.BeginTied();
  sIntControl *int_Tesselation_0 = gh.Int(&para->Tesselation[0],1,255,0.125000f);
  int_Tesselation_0->Default = 0x00000001; int_Tesselation_0->RightStep = 0.125000f;
  sIntControl *int_Tesselation_1 = gh.Int(&para->Tesselation[1],1,255,0.125000f);
  int_Tesselation_1->Default = 0x00000001; int_Tesselation_1->RightStep = 0.125000f;
  gh.EndTied();
}

void ChaosMeshDefgrid(wOp *op)
{
  ChaosMeshParagrid sUNUSED *para = (ChaosMeshParagrid *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Mode = 0x00000002;
  para->Tesselation[0] = 0x00000001;
  para->Tesselation[1] = 0x00000001;
}

void ChaosMeshBindgrid(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"tesselation"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"tesselation"),val);
}
void ChaosMeshBind2grid(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"tesselation");
  }
  ctx->AddImport(name[1],ScriptTypeInt,2,cmd->Data+1);
}
void ChaosMeshBind3grid(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import tesselation : int[2];\n");
}
const sChar *ChaosMeshWikigrid =
L"= ChaosMesh : grid\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i grid\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i inverted\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i doublesided\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i singlesided\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Tesselation\n"
L" !i Tesselation\n"
L" !i int[2]\n"
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

sBool ChaosMeshCmdcube(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParacube sUNUSED *para = (ChaosMeshParacube *)(cmd->Data); para;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 453 "chaosmesh_ops.ops"

    sSRT srt;
    sMatrix34 mat;
    
    srt.Rotate = para->Rotate;
    srt.Translate = para->Trans;
    srt.Scale = para->Scale;
    srt.MakeMatrix(mat);

    if(para->Flags & 2)
      mat.l = mat.l + 0.5f*mat.j;

    out->AddCluster(0);
    if(para->Flags & 4)
      out->AddCube(mat,para->Tess[0],para->Tess[1],para->Tess[2],(para->Flags & 1)!=0,para->Scale[0],para->Scale[1],para->Scale[2]);
    else
      out->AddCube(mat,para->Tess[0],para->Tess[1],para->Tess[2],(para->Flags & 1)!=0);
  ;
#line 1383 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuicube(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParacube sUNUSED *para = (ChaosMeshParacube *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Tesselate");
  gh.BeginTied();
  sIntControl *int_Tess_0 = gh.Int(&para->Tess[0],1,255,0.125000f);
  int_Tess_0->Default = 0x00000001; int_Tess_0->RightStep = 0.125000f;
  sIntControl *int_Tess_1 = gh.Int(&para->Tess[1],1,255,0.125000f);
  int_Tess_1->Default = 0x00000001; int_Tess_1->RightStep = 0.125000f;
  sIntControl *int_Tess_2 = gh.Int(&para->Tess[2],1,255,0.125000f);
  int_Tess_2->Default = 0x00000001; int_Tess_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|wrap uv:*1center|bottom:*2-|scale UV",gh.ChangeMsg);

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
  float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Rotate");
  gh.BeginTied();
  sFloatControl *float_Rotate_0 = gh.Float(&para->Rotate.x,-64.0000f,64.00000f,0.001000f);
  float_Rotate_0->Default = 0.000000f; float_Rotate_0->RightStep = 0.125000f;
  sFloatControl *float_Rotate_1 = gh.Float(&para->Rotate.y,-64.0000f,64.00000f,0.001000f);
  float_Rotate_1->Default = 0.000000f; float_Rotate_1->RightStep = 0.125000f;
  sFloatControl *float_Rotate_2 = gh.Float(&para->Rotate.z,-64.0000f,64.00000f,0.001000f);
  float_Rotate_2->Default = 0.000000f; float_Rotate_2->RightStep = 0.125000f;
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

void ChaosMeshDefcube(wOp *op)
{
  ChaosMeshParacube sUNUSED *para = (ChaosMeshParacube *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Tess[0] = 0x00000001;
  para->Tess[1] = 0x00000001;
  para->Tess[2] = 0x00000001;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void ChaosMeshBindcube(wCommand *cmd,ScriptContext *ctx)
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
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
}
void ChaosMeshBind2cube(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"tesselate");
    name[1] = sPoolString(L"flags");
    name[2] = sPoolString(L"scale");
    name[3] = sPoolString(L"rotate");
    name[4] = sPoolString(L"trans");
  }
  ctx->AddImport(name[0],ScriptTypeInt,3,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+10);
}
void ChaosMeshBind3cube(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import tesselate : int[3];\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rotate : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *ChaosMeshWikicube =
L"= ChaosMesh : cube\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i cube\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Tess\n"
L" !i int[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i wrap uv\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i center\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bottom\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i scale UV\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rotate\n"
L" !i Rotate\n"
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

sBool ChaosMeshCmdSphere(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaSphere sUNUSED *para = (ChaosMeshParaSphere *)(cmd->Data); para;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 489 "chaosmesh_ops.ops"

    sMatrix34 mat;
    mat.i.x = para->Diameter;
    mat.j.y = para->Diameter;
    mat.k.z = para->Diameter;

    out->AddCluster(0);
    out->AddSphere(mat,para->Facets,para->Slices);
    return 1;
  ;
#line 1613 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiSphere(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaSphere sUNUSED *para = (ChaosMeshParaSphere *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Facets");
  sIntControl *int_Facets = gh.Int(&para->Facets,3,64,0.125000f);
  int_Facets->Default = 0x00000008; int_Facets->RightStep = 0.125000f;

  gh.Label(L"Slices");
  sIntControl *int_Slices = gh.Int(&para->Slices,1,64,0.125000f);
  int_Slices->Default = 0x00000004; int_Slices->RightStep = 0.125000f;

  gh.Label(L"Diameter");
  sFloatControl *float_Diameter = gh.Float(&para->Diameter,-1024.00f,1024.000f,0.010000f);
  float_Diameter->Default = 1.000000f; float_Diameter->RightStep = 0.125000f;
}

void ChaosMeshDefSphere(wOp *op)
{
  ChaosMeshParaSphere sUNUSED *para = (ChaosMeshParaSphere *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Facets = 0x00000008;
  para->Slices = 0x00000004;
  para->Diameter = 1.000000f;
}

void ChaosMeshBindSphere(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"facets"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"slices"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"diameter"),val);
}
void ChaosMeshBind2Sphere(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"facets");
    name[1] = sPoolString(L"slices");
    name[2] = sPoolString(L"diameter");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void ChaosMeshBind3Sphere(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import facets : int;\n");
  tb.PrintF(L"  import slices : int;\n");
  tb.PrintF(L"  import diameter : float;\n");
}
const sChar *ChaosMeshWikiSphere =
L"= ChaosMesh : Sphere\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sphere\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Facets\n"
L" !i Facets\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Slices\n"
L" !i Slices\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Diameter\n"
L" !i Diameter\n"
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

sBool ChaosMeshCmdSelectCube(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaSelectCube sUNUSED *para = (ChaosMeshParaSelectCube *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 525 "chaosmesh_ops.ops"

    sSRT srt;
    sMatrix34 mat;
    sMatrix34 inv;
    ChaosMeshVertexPosition *vp;
    ChaosMeshFace *face;
    sVector31 v;
    sRandom rnd;
   
    rnd.Seed(para->RandomSeed);

    srt.Rotate = para->Rotate;
    srt.Translate = para->Trans;
    srt.Scale = para->Scale;
    srt.MakeMatrix(mat);
    srt.MakeMatrixInv(inv);

    out->CopyFrom(in0);
    sInt pc = out->Positions.GetCount();
    sU8 *fsel = sALLOCSTACK(sU8,pc);
    if(para->Flags & 0x1c0)
    {
      for(sInt i=0;i<pc;i++)
        fsel[i] = 0;
      sFORALL(out->Faces,face)
      {
        if(face->Select)
        {
          for(sInt i=0;i<face->Count;i++)
            fsel[face->Positions[i]] = 1;
        }
      }
    }
    sFORALL(out->Positions,vp)
    {
      v = vp->Position * inv;
      sBool inside = 0;
      switch(para->Flags & 0x1c0)
      {
      case 0x00:
        inside = v.x>=-1&&v.x<=1 && v.y>=-1&&v.y<=1 && v.z>=-1&&v.z<=1;
        break;
      case 0x40:
        inside = (v.x*v.x+v.y*v.y+v.z*v.z)<=1;
        break;
      case 0x80:
        inside = vp->Select;
        break;
      case 0x0c0:
        inside = fsel[_i];
        break;
      case 0x100:
        inside = 1;
        break;
      }
      sBool action = inside;
      if(para->Flags & 1)
        action = !inside;
      
      fsel[_i] = sU8(action);

      if((para->Flags & 48)==0)
      {
        if(rnd.Float(1)>para->Random)
          action = 0;
        if(action)
        {
          if(para->Flags & 4)
            vp->Select = 1;
          else
            vp->Select = 0;
        }
      }
    }
    if(para->Flags&48)
    {
      sFORALL(out->Faces,face)
      {
        sInt n = 0;
        for(sInt i=0;i<face->Count;i++)
          n += fsel[face->Positions[i]];
        sBool action = 0;
        switch(para->Flags&48)
        {
        case 16:
          action = (n>0);
          break;
        case 32:
          action = (n==face->Count);
          break;
        }
        if(rnd.Float(1)>para->Random)
          action = 0;
        if(action)
        {
          if(para->Flags & 4)
            face->Select = 1;
          else
            face->Select = 0;
        }
      }
    }
  ;
#line 1839 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshHndSelectCube(wPaintInfo &pi,wOp *op)
{
  ChaosMeshParaSelectCube sUNUSED *para = (ChaosMeshParaSelectCube *)(op->EditData); para;
#line 630 "chaosmesh_ops.ops"

    sSRT srt;
    sMatrix34 mat;
    sVector31 v[8],p;
   
    srt.Rotate = para->Rotate;
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
  ;
#line 1881 "chaosmesh_ops.cpp"
}

void ChaosMeshGuiSelectCube(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaSelectCube sUNUSED *para = (ChaosMeshParaSelectCube *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Input");
  gh.Flags(&para->Flags,L"*6cube|sphere|vertex select|face select|all",gh.LayoutMsg);

  gh.Label(L"Logic");
  gh.Flags(&para->Flags,L"-|invert:*2clear|set:*4vertex|touched face|enclosed face",gh.ChangeMsg);

  gh.Label(L"Output");
  gh.Flags(&para->Flags,L"*4vertex|touched face|enclosed face",gh.ChangeMsg);

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

    gh.Label(L"Rotate");
    gh.BeginTied();
    sFloatControl *float_Rotate_0 = gh.Float(&para->Rotate.x,-64.0000f,64.00000f,0.001000f);
    float_Rotate_0->Default = 0.000000f; float_Rotate_0->RightStep = 0.125000f;
    sFloatControl *float_Rotate_1 = gh.Float(&para->Rotate.y,-64.0000f,64.00000f,0.001000f);
    float_Rotate_1->Default = 0.000000f; float_Rotate_1->RightStep = 0.125000f;
    sFloatControl *float_Rotate_2 = gh.Float(&para->Rotate.z,-64.0000f,64.00000f,0.001000f);
    float_Rotate_2->Default = 0.000000f; float_Rotate_2->RightStep = 0.125000f;
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
  gh.Label(L"Random");
  sFloatControl *float_Random = gh.Float(&para->Random,0.000000f,1.000000f,0.020000f);
  float_Random->Default = 1.000000f; float_Random->RightStep = 0.125000f;

  gh.Label(L"RandomSeed");
  sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
  int_RandomSeed->Default = 0x00000000; int_RandomSeed->RightStep = 0.125000f;
}

void ChaosMeshDefSelectCube(wOp *op)
{
  ChaosMeshParaSelectCube sUNUSED *para = (ChaosMeshParaSelectCube *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000004;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->Random = 1.000000f;
}

void ChaosMeshBindSelectCube(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
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
}
void ChaosMeshBind2SelectCube(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"input");
    name[1] = sPoolString(L"logic");
    name[2] = sPoolString(L"output");
    name[3] = sPoolString(L"scale");
    name[4] = sPoolString(L"rotate");
    name[5] = sPoolString(L"trans");
    name[6] = sPoolString(L"random");
    name[7] = sPoolString(L"randomseed");
  }
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+7);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+11);
}
void ChaosMeshBind3SelectCube(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rotate : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import random : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
}
const sChar *ChaosMeshWikiSelectCube =
L"= ChaosMesh : SelectCube\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SelectCube\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i vertex\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i touched face\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i enclosed face\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Output\n"
L" !i Flags\n"
L" !i vertex\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i touched face\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i enclosed face\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rotate\n"
L" !i Rotate\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ChaosMeshCmdDeleteFaces(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaDeleteFaces sUNUSED *para = (ChaosMeshParaDeleteFaces *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 679 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    if(para->Flags & 1)
      sRemTrue(out->Faces,&ChaosMeshFace::Select);
    else
      sRemFalse(out->Faces,&ChaosMeshFace::Select);
    out->Cleanup();
  ;
#line 2175 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiDeleteFaces(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaDeleteFaces sUNUSED *para = (ChaosMeshParaDeleteFaces *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"unselected|selected",gh.ChangeMsg);
}

void ChaosMeshDefDeleteFaces(wOp *op)
{
  ChaosMeshParaDeleteFaces sUNUSED *para = (ChaosMeshParaDeleteFaces *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000001;
}

void ChaosMeshBindDeleteFaces(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2DeleteFaces(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
  }
}
void ChaosMeshBind3DeleteFaces(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiDeleteFaces =
L"= ChaosMesh : DeleteFaces\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DeleteFaces\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i unselected\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i selected\n"
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

sBool ChaosMeshCmdtransform(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParatransform sUNUSED *para = (ChaosMeshParatransform *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 708 "chaosmesh_ops.ops"

    ChaosMeshVertexPosition *vp;
    ChaosMeshVertexNormal *vn;
    ChaosMeshVertexTangent *vt;
    sSRT srt;
    sMatrix34 matp;
    sMatrix34 matn;
    
    srt.Rotate = para->Rotate;
    srt.MakeMatrix(matn);
    srt.Translate = para->Trans;
    srt.Scale = para->Scale;
    srt.MakeMatrix(matp);
    
    out->CopyFrom(in0);
    if(para->Selection==0)
    {
      sFORALL(out->Positions,vp)
        vp->Position = vp->Position * matp;
      sFORALL(out->Normals,vn)
        vn->Normal = vn->Normal * matn;
      sFORALL(out->Tangents,vt)
        vt->Tangent = vt->Tangent * matn;
    }
    else
    {
      sInt sel = (para->Selection == 1);
      sFORALL(out->Positions,vp)
      {
        if(vp->Select == sel)
          vp->Position = vp->Position * matp;
      }
      out->CalcNormals();
      out->CalcTangents();
    }
    
    return 1;
  ;
#line 2313 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuitransform(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParatransform sUNUSED *para = (ChaosMeshParatransform *)(op->EditData); para;
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

  gh.Label(L"Rotate");
  gh.BeginTied();
  sFloatControl *float_Rotate_0 = gh.Float(&para->Rotate.x,-64.0000f,64.00000f,0.001000f);
  float_Rotate_0->Default = 0.000000f; float_Rotate_0->RightStep = 0.125000f;
  sFloatControl *float_Rotate_1 = gh.Float(&para->Rotate.y,-64.0000f,64.00000f,0.001000f);
  float_Rotate_1->Default = 0.000000f; float_Rotate_1->RightStep = 0.125000f;
  sFloatControl *float_Rotate_2 = gh.Float(&para->Rotate.z,-64.0000f,64.00000f,0.001000f);
  float_Rotate_2->Default = 0.000000f; float_Rotate_2->RightStep = 0.125000f;
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

  gh.Label(L"Selection");
  gh.Flags(&para->Selection,L"all|selected|unselected",gh.ChangeMsg);
}

void ChaosMeshDeftransform(wOp *op)
{
  ChaosMeshParatransform sUNUSED *para = (ChaosMeshParatransform *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void ChaosMeshBindtransform(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
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
void ChaosMeshBind2transform(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rotate");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"selection");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
}
void ChaosMeshBind3transform(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rotate : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *ChaosMeshWikitransform =
L"= ChaosMesh : transform\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i transform\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Rotate\n"
L" !i Rotate\n"
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

sBool ChaosMeshCmdrandomize(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshPararandomize sUNUSED *para = (ChaosMeshPararandomize *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 760 "chaosmesh_ops.ops"

    ChaosMeshVertexPosition *vp;
    sVector30 v;
    sRandom rnd;

    rnd.Seed(para->Seed);

    out->CopyFrom(in0);

    switch(para->Flags)
    {
    case 0:
      sFORALL(out->Positions,vp)
      {
        v.x = rnd.Float(2)-1;
        v.y = rnd.Float(2)-1;
        v.z = rnd.Float(2)-1;
        vp->Position += v * para->Amount;
      }
      break;

    case 1:
      sFORALL(out->Positions,vp)
      {
        do
        {
          v.x = rnd.Float(2)-1;
          v.y = rnd.Float(2)-1;
          v.z = rnd.Float(2)-1;
        }
        while((v^v)<1);

        vp->Position += v * para->Amount;
      }
      break;
    }

    out->CalcNormals();
    out->CalcTangents();

    return 1;
  ;
#line 2543 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuirandomize(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshPararandomize sUNUSED *para = (ChaosMeshPararandomize *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Amount");
  gh.BeginTied();
  sFloatControl *float_Amount_0 = gh.Float(&para->Amount.x,-1024.00f,1024.000f,0.010000f);
  float_Amount_0->Default = 0.000000f; float_Amount_0->RightStep = 0.125000f;
  sFloatControl *float_Amount_1 = gh.Float(&para->Amount.y,-1024.00f,1024.000f,0.010000f);
  float_Amount_1->Default = 0.000000f; float_Amount_1->RightStep = 0.125000f;
  sFloatControl *float_Amount_2 = gh.Float(&para->Amount.z,-1024.00f,1024.000f,0.010000f);
  float_Amount_2->Default = 0.000000f; float_Amount_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"box|sphere",gh.ChangeMsg);
}

void ChaosMeshDefrandomize(wOp *op)
{
  ChaosMeshPararandomize sUNUSED *para = (ChaosMeshPararandomize *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindrandomize(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
}
void ChaosMeshBind2randomize(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"amount");
    name[1] = sPoolString(L"seed");
    name[2] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+3);
}
void ChaosMeshBind3randomize(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import amount : float[3];\n");
  tb.PrintF(L"  import seed : int;\n");
}
const sChar *ChaosMeshWikirandomize =
L"= ChaosMesh : randomize\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i randomize\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ChaosMeshCmdadd(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaadd sUNUSED *para = (ChaosMeshParaadd *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 812 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    for(sInt i=1;i<cmd->InputCount;i++)
      out->Add(cmd->GetInput<ChaosMesh *>(i));
    return 1;
  ;
#line 2691 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiadd(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaadd sUNUSED *para = (ChaosMeshParaadd *)(op->EditData); para;
}

void ChaosMeshDefadd(wOp *op)
{
  ChaosMeshParaadd sUNUSED *para = (ChaosMeshParaadd *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindadd(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2add(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind3add(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiadd =
L"= ChaosMesh : add\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i add\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i multiple\n"
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

sBool ChaosMeshCmdSetMtrl(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaSetMtrl sUNUSED *para = (ChaosMeshParaSetMtrl *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  Wz4Material sUNUSED *in1 = cmd->GetInput<Wz4Material *>(1); in1;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 832 "chaosmesh_ops.ops"

    ChaosMeshCluster *cl;
    out->CopyFrom(in0);
    sFORALL(out->Clusters,cl)
    {
      sRelease(cl->Material);
      cl->Material = in1;
      in1->AddRef();
    }

    return 1;
  ;
#line 2773 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiSetMtrl(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaSetMtrl sUNUSED *para = (ChaosMeshParaSetMtrl *)(op->EditData); para;
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
}

void ChaosMeshDefSetMtrl(wOp *op)
{
  ChaosMeshParaSetMtrl sUNUSED *para = (ChaosMeshParaSetMtrl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindSetMtrl(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2SetMtrl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"material");
  }
}
void ChaosMeshBind3SetMtrl(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiSetMtrl =
L"= ChaosMesh : SetMtrl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SetMtrl\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Wz4Material\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ChaosMeshCmdChangeTexture(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaChangeTexture sUNUSED *para = (ChaosMeshParaChangeTexture *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Texture2D sUNUSED *in2 = cmd->GetInput<Texture2D *>(2); in2;
  Texture2D sUNUSED *in3 = cmd->GetInput<Texture2D *>(3); in3;
  TextureCube sUNUSED *in4 = cmd->GetInput<TextureCube *>(4); in4;
  TextureCube sUNUSED *in5 = cmd->GetInput<TextureCube *>(5); in5;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 884 "chaosmesh_ops.ops"

    static sU32 blend[8] =
    {
      sMB_OFF,sMB_ADD,sMB_MUL,sMB_MUL2,sMB_ADDSMOOTH,sMB_ALPHA
    };

    ChaosMeshCluster *cl;
    Wz4Material *cm;
    out->CopyFrom(in0,SEPARATE_VERTEX|SEPARATE_FACE|SEPARATE_MATERIAL);


    // modify all

    sFORALL(out->Clusters,cl)
    {
      cm = cl->Material;
      cm->TempPtr = cm;

      for(sInt i=0;i<3;i++)
      {
        if(para->Exchange & (1<<i))
        {
          cm->Tex[i]->Release();
          cm->Tex[i] = 0;
          cm->Material->Texture[i] = 0;
          Texture2D *tex = cmd->GetInput<Texture2D *>(i+1);
          if(tex)
          {
            cm->Tex[i] = tex; tex->AddRef();
            cm->Material->Texture[i] = tex->Texture;
          }
        }
      }
      for(sInt i=3;i<5;i++)
      {
        if(para->Exchange & (1<<i))
        {
          cm->Tex[i]->Release();
          cm->Tex[i] = 0;
          cm->Material->Texture[i] = 0;
          TextureCube *tex = cmd->GetInput<TextureCube *>(i+1);
          if(tex)
          {
            cm->Tex[i] = tex; tex->AddRef();
            cm->Material->Texture[i] = tex->Texture;
          }
        }
      }
      if(para->Exchange & (1<<8))
      {
        cm->Material->DetailMode = para->DetailMode;
      }
      if(para->Exchange & (1<<9))
      {
        cm->Material->BlendColor = blend[para->BlendMode&7];
      }
    }

    // prepare all 

    sFORALL(out->Clusters,cl)
    {
      cm = cl->Material;
      if(cm->TempPtr)
      {
        cm->TempPtr = 0;
        cm->Material->Prepare(cm->Format);
      }
    }
  
    return 1;
  ;
#line 2964 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiChangeTexture(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaChangeTexture sUNUSED *para = (ChaosMeshParaChangeTexture *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Exchange");
  gh.Flags(&para->Exchange,L"-|Bump:*1-|Diffuse:*2-|Detail",gh.LayoutMsg);

  gh.Label(L"Exchange");
  gh.Flags(&para->Exchange,L"*3-|SpecCube:*4-|LightCube",gh.LayoutMsg);

  gh.Label(L"Exchange");
  gh.Flags(&para->Exchange,L"*8-|DetailMode:*9-|BlendMode",gh.LayoutMsg);

  gh.Group(L"Flags");

  if(((para->Exchange&0x0100)==0x0100))
  {
    gh.Label(L"DetailMode");
    gh.Flags(&para->DetailMode,L"off|mul|add|bump|specmul:*4uv0|uv1|model|world|sphere|reflect:*8-|AlphaDepth",gh.ChangeMsg);

  }
  if(((para->Exchange&0x0200)==0x0200))
  {
    gh.Label(L"BlendMode");
    gh.Flags(&para->BlendMode,L"opaque|add|mul|mul2|smooth|alpha",gh.ChangeMsg);

  }
  gh.Group(L"Textures");

  if(((para->Exchange&0x0001)==0x0001))
  {
    gh.Label(L"Bump");
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

  }
  if(((para->Exchange&0x0002)==0x0002))
  {
    gh.Label(L"Diffuse");
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

  }
  if(((para->Exchange&0x0004)==0x0004))
  {
    gh.Label(L"Detail");
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

  }
  if(((para->Exchange&0x0008)==0x0008))
  {
    gh.Label(L"SpecCube");
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

  }
  if(((para->Exchange&0x0010)==0x0010))
  {
    gh.Label(L"LightCube");
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
  }
}

void ChaosMeshDefChangeTexture(wOp *op)
{
  ChaosMeshParaChangeTexture sUNUSED *para = (ChaosMeshParaChangeTexture *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->DetailMode = 0x00000001;
}

void ChaosMeshBindChangeTexture(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2ChangeTexture(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"exchange");
    name[1] = sPoolString(L"exchange");
    name[2] = sPoolString(L"exchange");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"detailmode");
    name[5] = sPoolString(L"blendmode");
    name[6] = sPoolString(L"textures");
    name[7] = sPoolString(L"bump");
    name[8] = sPoolString(L"diffuse");
    name[9] = sPoolString(L"detail");
    name[10] = sPoolString(L"speccube");
    name[11] = sPoolString(L"lightcube");
  }
}
void ChaosMeshBind3ChangeTexture(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiChangeTexture =
L"= ChaosMesh : ChangeTexture\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ChangeTexture\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Texture2D\n"
L" !i optional link Bump\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link Diffuse\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i optional link Detail\n"
L" !i *\n"
L"\n"
L" !i TextureCube\n"
L" !i optional link SpecCube\n"
L" !i *\n"
L"\n"
L" !i TextureCube\n"
L" !i optional link LightCube\n"
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
L" !i Exchange\n"
L" !i Exchange\n"
L" !i Bump\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Diffuse\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Detail\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Exchange\n"
L" !i Exchange\n"
L" !i SpecCube\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i LightCube\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Exchange\n"
L" !i Exchange\n"
L" !i DetailMode\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i BlendMode\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i AlphaDepth\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i BlendMode\n"
L" !i BlendMode\n"
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
L" !i Bump\n"
L" !i Bump\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i Diffuse\n"
L" !i Diffuse\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i Detail\n"
L" !i Detail\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i SpecCube\n"
L" !i SpecCube\n"
L" !i link\n"
L" !i *\n"
L"\n"
L" !i LightCube\n"
L" !i LightCube\n"
L" !i link\n"
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

sBool ChaosMeshCmdChangeMaterial(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaChangeMaterial sUNUSED *para = (ChaosMeshParaChangeMaterial *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  Wz4Material sUNUSED *in1 = cmd->GetInput<Wz4Material *>(1); in1;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 969 "chaosmesh_ops.ops"

    ChaosMeshCluster *cl;
    out->CopyFrom(in0);

    // modify all

    sFORALL(out->Clusters,cl)
    {
      cl->Material->Release();
      cl->Material = in1;
      in1->AddRef();
    }  

    return 1;
  ;
#line 3381 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiChangeMaterial(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaChangeMaterial sUNUSED *para = (ChaosMeshParaChangeMaterial *)(op->EditData); para;
}

void ChaosMeshDefChangeMaterial(wOp *op)
{
  ChaosMeshParaChangeMaterial sUNUSED *para = (ChaosMeshParaChangeMaterial *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindChangeMaterial(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2ChangeMaterial(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind3ChangeMaterial(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiChangeMaterial =
L"= ChaosMesh : ChangeMaterial\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ChangeMaterial\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Wz4Material\n"
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

sBool ChaosMeshCmdBurnAnim(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaBurnAnim sUNUSED *para = (ChaosMeshParaBurnAnim *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 996 "chaosmesh_ops.ops"

    ChaosMeshVertexPosition *pos;
    ChaosMeshCluster *cl;
    out->CopyFrom(in0,SEPARATE_VERTEX);

    if(out->Skeleton)
    {
      sVector31 v;
      sMatrix34 *mat,*bmat;

      mat = sALLOCSTACK(sMatrix34,out->Skeleton->Joints.GetCount());
      bmat = sALLOCSTACK(sMatrix34,out->Skeleton->Joints.GetCount());
      out->Skeleton->Evaluate(para->Phase,mat,bmat);

      sFORALL(out->Positions,pos)
      {
        if(pos->MatrixIndex[0]!=-1)
        {
          v.Init(0,0,0);
          for(sInt i=0;i<4;i++)
          {
            if(pos->MatrixIndex[i]==-1)
              break;
            v = v + sVector30(pos->Position * bmat[pos->MatrixIndex[i]])*pos->MatrixWeight[i];
          }
          pos->Position = v;
          pos->ClearWeights();
        }
      }
      sRelease(out->Skeleton);

      sFORALL(out->Clusters,cl)
      {
        cl->Material->Format = sVertexFormatTSpace4;
        cl->Material->Material->Prepare(sVertexFormatTSpace4);
      }
    }

    return 1;
  ;
#line 3494 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiBurnAnim(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaBurnAnim sUNUSED *para = (ChaosMeshParaBurnAnim *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,0.000000f,1.000000f,0.001000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;
}

void ChaosMeshDefBurnAnim(wOp *op)
{
  ChaosMeshParaBurnAnim sUNUSED *para = (ChaosMeshParaBurnAnim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindBurnAnim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
}
void ChaosMeshBind2BurnAnim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"phase");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void ChaosMeshBind3BurnAnim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import phase : float;\n");
}
const sChar *ChaosMeshWikiBurnAnim =
L"= ChaosMesh : BurnAnim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BurnAnim\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Phase\n"
L" !i Phase\n"
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

sBool ChaosMeshCmdDeleteSkeleton(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaDeleteSkeleton sUNUSED *para = (ChaosMeshParaDeleteSkeleton *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1045 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    sRelease(out->Skeleton);
    return 1;
  ;
#line 3601 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiDeleteSkeleton(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaDeleteSkeleton sUNUSED *para = (ChaosMeshParaDeleteSkeleton *)(op->EditData); para;
}

void ChaosMeshDefDeleteSkeleton(wOp *op)
{
  ChaosMeshParaDeleteSkeleton sUNUSED *para = (ChaosMeshParaDeleteSkeleton *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindDeleteSkeleton(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2DeleteSkeleton(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind3DeleteSkeleton(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiDeleteSkeleton =
L"= ChaosMesh : DeleteSkeleton\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DeleteSkeleton\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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

sBool ChaosMeshCmdBakeMorph(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaBakeMorph sUNUSED *para = (ChaosMeshParaBakeMorph *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh sUNUSED *in1 = cmd->GetInput<ChaosMesh *>(1); in1;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1064 "chaosmesh_ops.ops"

    sF32 fade = para->Phase;
    ChaosMeshVertexPosition *pos0,*pos1;

    out->CopyFrom(in0);
    if(out->Positions.GetCount()==in1->Positions.GetCount() &&
       out->Normals.GetCount()==in1->Normals.GetCount() &&
       out->Tangents.GetCount()==in1->Tangents.GetCount() && 
       out->Skeleton && in1->Skeleton)
    {
      sVector31 v,v0,v1;
      sMatrix34 *out_mat,*out_bmat;
      sMatrix34 *shp_mat,*shp_bmat;

      out_mat = sALLOCSTACK(sMatrix34,out->Skeleton->Joints.GetCount());
      out_bmat = sALLOCSTACK(sMatrix34,out->Skeleton->Joints.GetCount());
      out->Skeleton->Evaluate(para->Anim,out_mat,out_bmat);

      shp_mat = sALLOCSTACK(sMatrix34,in1->Skeleton->Joints.GetCount());
      shp_bmat = sALLOCSTACK(sMatrix34,in1->Skeleton->Joints.GetCount());
      in1->Skeleton->Evaluate(para->Anim,shp_mat,shp_bmat);

      sFORALL(out->Positions,pos0)
      {
        if(pos0->MatrixIndex[0]!=-1)
        {
          v.Init(0,0,0);
          for(sInt i=0;i<4;i++)
          {
            if(pos0->MatrixIndex[i]==-1)
              break;
            v = v + sVector30(pos0->Position * out_bmat[pos0->MatrixIndex[i]])*pos0->MatrixWeight[i];
          }
          v0 = v;
          pos0->ClearWeights();
        }

        pos1 = &in1->Positions[_i];
        if(pos1->MatrixIndex[0]!=-1)
        {
          v.Init(0,0,0);
          for(sInt i=0;i<4;i++)
          {
            if(pos1->MatrixIndex[i]==-1)
              break;
            v = v + sVector30(pos1->Position * shp_bmat[pos1->MatrixIndex[i]])*pos1->MatrixWeight[i];
          }
          v1 = v;
        }

        pos0->Position.Fade(fade,v0,v1);
      }

      ChaosMeshCluster *cl;
      sFORALL(out->Clusters,cl)
      {
        cl->Material->Format = sVertexFormatTSpace4;
        cl->Material->Material->Prepare(sVertexFormatTSpace4);
      }

    }

    return 1;
  ;
#line 3735 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiBakeMorph(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaBakeMorph sUNUSED *para = (ChaosMeshParaBakeMorph *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,0.000000f,1.000000f,0.001000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;

  gh.Label(L"Anim");
  sFloatControl *float_Anim = gh.Float(&para->Anim,0.000000f,1.000000f,0.001000f);
  float_Anim->Default = 0.000000f; float_Anim->RightStep = 0.125000f;
}

void ChaosMeshDefBakeMorph(wOp *op)
{
  ChaosMeshParaBakeMorph sUNUSED *para = (ChaosMeshParaBakeMorph *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindBakeMorph(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"anim"),val);
}
void ChaosMeshBind2BakeMorph(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"phase");
    name[1] = sPoolString(L"anim");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void ChaosMeshBind3BakeMorph(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import phase : float;\n");
  tb.PrintF(L"  import anim : float;\n");
}
const sChar *ChaosMeshWikiBakeMorph =
L"= ChaosMesh : BakeMorph\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BakeMorph\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i ChaosMesh\n"
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
L" !i Phase\n"
L" !i Phase\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Anim\n"
L" !i Anim\n"
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

sBool ChaosMeshCmdMergeShape(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaMergeShape sUNUSED *para = (ChaosMeshParaMergeShape *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh sUNUSED *in1 = cmd->GetInput<ChaosMesh *>(1); in1;
  ChaosMesh sUNUSED *in2 = cmd->GetInput<ChaosMesh *>(2); in2;
  ChaosMesh sUNUSED *in3 = cmd->GetInput<ChaosMesh *>(3); in3;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1141 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    return out->MergeShape(in1,in2,para->Phase,in3);
  ;
#line 3863 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiMergeShape(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaMergeShape sUNUSED *para = (ChaosMeshParaMergeShape *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,0.000000f,1.000000f,0.000010f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;
}

void ChaosMeshDefMergeShape(wOp *op)
{
  ChaosMeshParaMergeShape sUNUSED *para = (ChaosMeshParaMergeShape *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindMergeShape(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
}
void ChaosMeshBind2MergeShape(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"phase");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void ChaosMeshBind3MergeShape(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import phase : float;\n");
}
const sChar *ChaosMeshWikiMergeShape =
L"= ChaosMesh : MergeShape\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MergeShape\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i ChaosMesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i ChaosMesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i ChaosMesh\n"
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
L" !i Phase\n"
L" !i Phase\n"
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

sBool ChaosMeshCmdMergeAnim(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaMergeAnim sUNUSED *para = (ChaosMeshParaMergeAnim *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1158 "chaosmesh_ops.ops"

    static sInt AnimMask[128] = 
    {
      1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
      1,0,0,1,1,0,1,1,0,0,1,1,0,0,1,0,
      0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,
      1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };


    Wz4AnimJoint *joint,*joint2;
    ChaosMeshAnimClip *clip;
    ChaosMesh *in;

    out->CopyFrom(in0,SEPARATE_SKELETON);
    
    out->AnimClips.Clear();
    for(sInt input=1;input<cmd->InputCount;input++)
    {
      in = cmd->GetInput<ChaosMesh *>(input);
      if(out->Skeleton && in->Skeleton)
      {
        sInt time0 = 0;
        sInt time1 = 0;

        sFORALL(out->Skeleton->Joints,joint)
        {
          Wz4ChannelPerFrame *pf = (Wz4ChannelPerFrame *) joint->Channel;
          if(pf && pf->Keys>0)
          {
            if(time0==0)
              time0 = pf->Keys;
            else
              sVERIFY(time0 == pf->Keys);
          }
        }
        sFORALL(in->Skeleton->Joints,joint)
        {
          Wz4ChannelPerFrame *pf = (Wz4ChannelPerFrame *) joint->Channel;
          if(pf && pf->Keys>0)
          {
            if(time1==0)
              time1 = pf->Keys;
            else
              sVERIFY(time1 == pf->Keys);
          }
        }

        if(para->UseAnimMask)
          if(AnimMask[input]==0)
            time1 = 0;
        
        sVERIFY(time0+time1>0);
        
        if(input==1)
        {
          clip = out->AnimClips.AddMany(1);
          clip->Start = 0;
          clip->End = sF32(time0);
          clip->Speed = 0;
          clip->Id = 0;
        }
        sVERIFY(time0==out->AnimClips[input-1].End);
        clip = out->AnimClips.AddMany(1);
        clip->Start = sF32(time0);
        clip->End = sF32(time0+time1);
        clip->Speed = 0;
        clip->Id = 0;

        sFORALL(out->Skeleton->Joints,joint)
        {
          Wz4ChannelPerFrame *pf0 = (Wz4ChannelPerFrame *) joint->Channel;

          // find add-channel

          Wz4ChannelPerFrame *pf1 = 0;
          sFORALL(in->Skeleton->Joints,joint2)
          {
            if(sCmpStringI(joint->Name,joint2->Name)==0)
            {
              pf1 = (Wz4ChannelPerFrame *) joint2->Channel;
              break;
            }
          }
          if(pf1 && pf1->Keys==0)
            pf1 = 0;

          // entend backwards

          if((pf0->Scale && pf0->Keys>0) || (pf1 && pf1->Scale))
          {
            sVector31 *n = new sVector31[time0+time1];
            for(sInt i=0;i<time0+time1;i++)
              n[i] = pf0->Start.Scale;
            if(pf0->Scale)
              sCopyMem(n,pf0->Scale,sizeof(*n)*time0);
            if(pf1 && !pf1->Scale)
              for(sInt i=time0;i<time0+time1;i++)
                n[i] = pf1->Start.Scale;
            if(pf1 && pf1->Scale)
              sCopyMem(n+time0,pf1->Scale,sizeof(*n)*time1);
            delete[] pf0->Scale;
            pf0->Scale = n;
          }
          if((pf0->Rot && pf0->Keys>0) || (pf1 && pf1->Rot))
          {
            sQuaternion *n = new sQuaternion[time0+time1];
            for(sInt i=0;i<time0+time1;i++)
              n[i] = pf0->Start.Rot;
            if(pf0->Rot)
              sCopyMem(n,pf0->Rot,sizeof(*n)*time0);
            if(pf1 && !pf1->Rot)
              for(sInt i=time0;i<time0+time1;i++)
                n[i] = pf1->Start.Rot;
            if(pf1 && pf1->Rot)
              sCopyMem(n+time0,pf1->Rot,sizeof(*n)*time1);
            delete[] pf0->Rot;
            pf0->Rot = n;
          }
          if((pf0->Trans && pf0->Keys>0) || (pf1 && pf1->Trans))
          {
            sVector31 *n = new sVector31[time0+time1];
            for(sInt i=0;i<time0+time1;i++)
              n[i] = pf0->Start.Trans;
            if(pf0->Trans)
              sCopyMem(n,pf0->Trans,sizeof(*n)*time0);
            if(pf1 && !pf1->Trans)
              for(sInt i=time0;i<time0+time1;i++)
                n[i] = pf1->Start.Trans;
            if(pf1 && pf1->Trans)
              sCopyMem(n+time0,pf1->Trans,sizeof(*n)*time1);
            delete[] pf0->Trans;
            pf0->Trans = n;
          }
          sVERIFY(pf0->User==0);
          pf0->Keys = time0+time1;
        }
      }
    }
    
    sInt count = out->AnimClips.GetCount();
    if(count>0)
    {
      sF32 max = out->AnimClips[count-1].End;
      sF32 imax = 1.0f/max;
      sFORALL(out->AnimClips,clip)
      {
        clip->Start *= imax;
        clip->End *= imax;
        clip->Speed = 60*imax;
      }
    }

    return 1;
  ;
#line 4136 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiMergeAnim(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaMergeAnim sUNUSED *para = (ChaosMeshParaMergeAnim *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"UseAnimMask");
  gh.Flags(&para->UseAnimMask,L"off|detuned",gh.ChangeMsg);
}

void ChaosMeshDefMergeAnim(wOp *op)
{
  ChaosMeshParaMergeAnim sUNUSED *para = (ChaosMeshParaMergeAnim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindMergeAnim(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2MergeAnim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"useanimmask");
  }
}
void ChaosMeshBind3MergeAnim(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiMergeAnim =
L"= ChaosMesh : MergeAnim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MergeAnim\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i multiple\n"
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
L" !i UseAnimMask\n"
L" !i UseAnimMask\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i detuned\n"
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

sBool ChaosMeshCmdFakeBone(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaFakeBone sUNUSED *para = (ChaosMeshParaFakeBone *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1334 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    if(in0->Skeleton && para->BoneIndex>=0 && para->BoneIndex<in0->Skeleton->Joints.GetCount() && para->What!=0)
    {
      out->Skeleton->Release();
      out->Skeleton = new Wz4Skeleton;
      out->Skeleton->CopyFrom(in0->Skeleton);

      Wz4AnimJoint *j = &out->Skeleton->Joints[para->BoneIndex];
      if(j->Channel->Kind==Wz4ChannelKindPerFrame)
      {
        Wz4ChannelPerFrame *ch = (Wz4ChannelPerFrame *) j->Channel;
        if(para->What&1)
        {
          sDeleteArray(ch->Scale);
          ch->Start.Scale = para->Scale;
        }
        if(para->What&2)
        {
          sDeleteArray(ch->Rot);
          sMatrix34 mat;
          mat.EulerXYZ(para->Rotate.x*sPI2F,para->Rotate.y*sPI2F,para->Rotate.z*sPI2F);
          ch->Start.Rot.Init(mat);
        }
        if(para->What&4)
        {
          sDeleteArray(ch->Trans);
          ch->Start.Trans = para->Trans;
        }
      }
    }
  ;
#line 4267 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiFakeBone(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaFakeBone sUNUSED *para = (ChaosMeshParaFakeBone *)(op->EditData); para;
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

  gh.Label(L"Rotate");
  gh.BeginTied();
  sFloatControl *float_Rotate_0 = gh.Float(&para->Rotate.x,-64.0000f,64.00000f,0.001000f);
  float_Rotate_0->Default = 0.000000f; float_Rotate_0->RightStep = 0.125000f;
  sFloatControl *float_Rotate_1 = gh.Float(&para->Rotate.y,-64.0000f,64.00000f,0.001000f);
  float_Rotate_1->Default = 0.000000f; float_Rotate_1->RightStep = 0.125000f;
  sFloatControl *float_Rotate_2 = gh.Float(&para->Rotate.z,-64.0000f,64.00000f,0.001000f);
  float_Rotate_2->Default = 0.000000f; float_Rotate_2->RightStep = 0.125000f;
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

  gh.Label(L"BoneIndex");
  sIntControl *int_BoneIndex = gh.Int(&para->BoneIndex,0,255,0.125000f);
  int_BoneIndex->Default = 0x00000000; int_BoneIndex->RightStep = 0.125000f;

  gh.Label(L"What");
  gh.Flags(&para->What,L"*0-|s:*1-|r:*2-|t",gh.ChangeMsg);
}

void ChaosMeshDefFakeBone(wOp *op)
{
  ChaosMeshParaFakeBone sUNUSED *para = (ChaosMeshParaFakeBone *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void ChaosMeshBindFakeBone(wCommand *cmd,ScriptContext *ctx)
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
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"rotate"),val);
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
  ctx->BindLocal(ctx->AddSymbol(L"boneindex"),val);
}
void ChaosMeshBind2FakeBone(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"scale");
    name[1] = sPoolString(L"rotate");
    name[2] = sPoolString(L"trans");
    name[3] = sPoolString(L"boneindex");
    name[4] = sPoolString(L"what");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+9);
}
void ChaosMeshBind3FakeBone(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rotate : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import boneindex : int;\n");
}
const sChar *ChaosMeshWikiFakeBone =
L"= ChaosMesh : FakeBone\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FakeBone\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Rotate\n"
L" !i Rotate\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i BoneIndex\n"
L" !i BoneIndex\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i What\n"
L" !i What\n"
L" !i s\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i r\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i t\n"
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

sBool ChaosMeshCmdCompressAnim(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaCompressAnim sUNUSED *para = (ChaosMeshParaCompressAnim *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1382 "chaosmesh_ops.ops"

    out->CopyFrom(in0);
    if(in0->Skeleton)
    {
      out->Skeleton->Release();
      out->Skeleton = new Wz4Skeleton;
      out->Skeleton->CopyFrom(in0->Skeleton);
      
      sInt total = 0, compressed = 0;
      sInt totalRotKeys = 0, totalTransKeys = 0;
      sF32 accuracy = sFPow(10.0f,para->LogRelativeAccuracy);
      
      Wz4AnimJoint *j;
      sFORALL(out->Skeleton->Joints,j)
      {
        if(j->Channel->Kind==Wz4ChannelKindPerFrame)
        {
          Wz4ChannelPerFrame *oldch = (Wz4ChannelPerFrame *) j->Channel;
          Wz4ChannelSpline *splinech = new Wz4ChannelSpline;
          total++;
          
          if(splinech->Approximate(*oldch,accuracy) || !(para->Flags & 1))
          {
            totalRotKeys += splinech->Rot.GetNumControlPoints();
            totalTransKeys += splinech->Trans.GetNumControlPoints();
            compressed++;
            oldch->Release();
            j->Channel = splinech;
          }
        }
      }
      
      sDPrintF(L"%d/%d curves compresssed successfully.\n",compressed,total);
      sDPrintF(L"%d rotation keys total, %d translation\n",totalRotKeys,totalTransKeys);
    }
  ;
#line 4516 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiCompressAnim(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaCompressAnim sUNUSED *para = (ChaosMeshParaCompressAnim *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Max error (sig. digits)");
  sFloatControl *float_LogRelativeAccuracy = gh.Float(&para->LogRelativeAccuracy,-5.00000f,2.000000f,0.001000f);
  float_LogRelativeAccuracy->Default = -3.00000f; float_LogRelativeAccuracy->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0-|guaranteed precision",gh.ChangeMsg);
}

void ChaosMeshDefCompressAnim(wOp *op)
{
  ChaosMeshParaCompressAnim sUNUSED *para = (ChaosMeshParaCompressAnim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->LogRelativeAccuracy = -3.00000f;
}

void ChaosMeshBindCompressAnim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"logrelativeaccuracy"),val);
}
void ChaosMeshBind2CompressAnim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"logrelativeaccuracy");
    name[1] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void ChaosMeshBind3CompressAnim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import logrelativeaccuracy : float;\n");
}
const sChar *ChaosMeshWikiCompressAnim =
L"= ChaosMesh : CompressAnim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i CompressAnim\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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
L" !i Max error (sig. digits)\n"
L" !i LogRelativeAccuracy\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i guaranteed precision\n"
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

sBool ChaosMeshCmdSliceAndDice(wExecutive *exe,wCommand *cmd)
{
  ChaosMeshParaSliceAndDice sUNUSED *para = (ChaosMeshParaSliceAndDice *)(cmd->Data); para;
  ChaosMesh sUNUSED *in0 = cmd->GetInput<ChaosMesh *>(0); in0;
  ChaosMesh *out = (ChaosMesh *) cmd->Output;
  if(!out) { out=new ChaosMesh; cmd->Output=out; }

  {
#line 1424 "chaosmesh_ops.ops"

    // burn annimation for base mesh
    ChaosMeshVertexPosition *pos;
    ChaosMeshCluster *cl;
    out->CopyFrom(in0,SEPARATE_VERTEX);

    if(out->Skeleton)
    {
      sVector31 v;
      sMatrix34 *mat,*bmat;

      mat = sALLOCSTACK(sMatrix34,out->Skeleton->Joints.GetCount());
      bmat = sALLOCSTACK(sMatrix34,out->Skeleton->Joints.GetCount());
      out->Skeleton->Evaluate(0.0f,mat,bmat);

      sFORALL(out->Positions,pos)
      {
        if(pos->MatrixIndex[0]!=-1)
        {
          v.Init(0,0,0);
          for(sInt i=0;i<4;i++)
          {
            if(pos->MatrixIndex[i]==-1)
              break;
            v = v + sVector30(pos->Position * bmat[pos->MatrixIndex[i]])*pos->MatrixWeight[i];
          }
          pos->Position = v;
          pos->ClearWeights();
        }
      }
      sRelease(out->Skeleton);

      sFORALL(out->Clusters,cl)
      {
        cl->Material->Format = sVertexFormatTSpace4;
        cl->Material->Material->Prepare(sVertexFormatTSpace4);
      }
    }
    
    // cut 'em up!
    ChaosMeshFX_SliceAndDice(out);
  ;
#line 4670 "chaosmesh_ops.cpp"
    return 1;
  }
}

void ChaosMeshGuiSliceAndDice(wGridFrameHelper &gh,wOp *op)
{
  ChaosMeshParaSliceAndDice sUNUSED *para = (ChaosMeshParaSliceAndDice *)(op->EditData); para;
}

void ChaosMeshDefSliceAndDice(wOp *op)
{
  ChaosMeshParaSliceAndDice sUNUSED *para = (ChaosMeshParaSliceAndDice *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ChaosMeshBindSliceAndDice(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind2SliceAndDice(wCommand *cmd,ScriptContext *ctx)
{
}
void ChaosMeshBind3SliceAndDice(wOp *op,sTextBuffer &tb)
{
}
const sChar *ChaosMeshWikiSliceAndDice =
L"= ChaosMesh : SliceAndDice\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SliceAndDice\n"
L"\n"
L"  !i Output Type\n"
L"  !i ChaosMesh\n"
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

void ChaosMeshAnimExtract_ChaosMesh_ChaosMesh::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimExtract_ChaosMesh_ChaosMesh::Bind(class ScriptContext *sc,ChaosMeshParaExtract_ChaosMesh_ChaosMesh *para)
{
};

void Texture2DAnimExtract_ChaosMesh_Texture2D::Init(class ScriptContext *sc)
{
};

void Texture2DAnimExtract_ChaosMesh_Texture2D::Bind(class ScriptContext *sc,Texture2DParaExtract_ChaosMesh_Texture2D *para)
{
};

void TextureCubeAnimExtract_ChaosMesh_TextureCube::Init(class ScriptContext *sc)
{
};

void TextureCubeAnimExtract_ChaosMesh_TextureCube::Bind(class ScriptContext *sc,TextureCubeParaExtract_ChaosMesh_TextureCube *para)
{
};

void Wz4SkeletonAnimExtract_ChaosMesh_Wz4Skeleton::Init(class ScriptContext *sc)
{
};

void Wz4SkeletonAnimExtract_ChaosMesh_Wz4Skeleton::Bind(class ScriptContext *sc,Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton *para)
{
};

void ChaosMeshAnimExport::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimExport::Bind(class ScriptContext *sc,ChaosMeshParaExport *para)
{
};

void ChaosMeshAnimExportXSI::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimExportXSI::Bind(class ScriptContext *sc,ChaosMeshParaExportXSI *para)
{
};

void ChaosMeshAnimImport::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimImport::Bind(class ScriptContext *sc,ChaosMeshParaImport *para)
{
};

void ChaosMeshAnimtorus::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimtorus::Bind(class ScriptContext *sc,ChaosMeshParatorus *para)
{
};

void ChaosMeshAnimgrid::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimgrid::Bind(class ScriptContext *sc,ChaosMeshParagrid *para)
{
};

void ChaosMeshAnimcube::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimcube::Bind(class ScriptContext *sc,ChaosMeshParacube *para)
{
};

void ChaosMeshAnimSphere::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimSphere::Bind(class ScriptContext *sc,ChaosMeshParaSphere *para)
{
};

void ChaosMeshAnimSelectCube::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimSelectCube::Bind(class ScriptContext *sc,ChaosMeshParaSelectCube *para)
{
};

void ChaosMeshAnimDeleteFaces::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimDeleteFaces::Bind(class ScriptContext *sc,ChaosMeshParaDeleteFaces *para)
{
};

void ChaosMeshAnimtransform::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimtransform::Bind(class ScriptContext *sc,ChaosMeshParatransform *para)
{
};

void ChaosMeshAnimrandomize::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimrandomize::Bind(class ScriptContext *sc,ChaosMeshPararandomize *para)
{
};

void ChaosMeshAnimadd::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimadd::Bind(class ScriptContext *sc,ChaosMeshParaadd *para)
{
};

void ChaosMeshAnimSetMtrl::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimSetMtrl::Bind(class ScriptContext *sc,ChaosMeshParaSetMtrl *para)
{
};

void ChaosMeshAnimChangeTexture::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimChangeTexture::Bind(class ScriptContext *sc,ChaosMeshParaChangeTexture *para)
{
};

void ChaosMeshAnimChangeMaterial::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimChangeMaterial::Bind(class ScriptContext *sc,ChaosMeshParaChangeMaterial *para)
{
};

void ChaosMeshAnimBurnAnim::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimBurnAnim::Bind(class ScriptContext *sc,ChaosMeshParaBurnAnim *para)
{
};

void ChaosMeshAnimDeleteSkeleton::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimDeleteSkeleton::Bind(class ScriptContext *sc,ChaosMeshParaDeleteSkeleton *para)
{
};

void ChaosMeshAnimBakeMorph::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimBakeMorph::Bind(class ScriptContext *sc,ChaosMeshParaBakeMorph *para)
{
};

void ChaosMeshAnimMergeShape::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimMergeShape::Bind(class ScriptContext *sc,ChaosMeshParaMergeShape *para)
{
};

void ChaosMeshAnimMergeAnim::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimMergeAnim::Bind(class ScriptContext *sc,ChaosMeshParaMergeAnim *para)
{
};

void ChaosMeshAnimFakeBone::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimFakeBone::Bind(class ScriptContext *sc,ChaosMeshParaFakeBone *para)
{
};

void ChaosMeshAnimCompressAnim::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimCompressAnim::Bind(class ScriptContext *sc,ChaosMeshParaCompressAnim *para)
{
};

void ChaosMeshAnimSliceAndDice::Init(class ScriptContext *sc)
{
};

void ChaosMeshAnimSliceAndDice::Bind(class ScriptContext *sc,ChaosMeshParaSliceAndDice *para)
{
};


/****************************************************************************/

void AddTypes_chaosmesh_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(ChaosMeshType = new ChaosMeshType_);
  ChaosMeshType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_chaosmesh_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Extract_ChaosMesh_ChaosMesh";
  cl->Label = L"Extract_ChaosMesh_ChaosMesh";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdExtract_ChaosMesh_ChaosMesh;
  cl->MakeGui = ChaosMeshGuiExtract_ChaosMesh_ChaosMesh;
  cl->SetDefaults = ChaosMeshDefExtract_ChaosMesh_ChaosMesh;
  cl->BindPara = ChaosMeshBindExtract_ChaosMesh_ChaosMesh;
  cl->Bind2Para = ChaosMeshBind2Extract_ChaosMesh_ChaosMesh;
  cl->Bind3Para = ChaosMeshBind3Extract_ChaosMesh_ChaosMesh;
  cl->WikiText = ChaosMeshWikiExtract_ChaosMesh_ChaosMesh;
  cl->ParaStrings = 1;
  cl->Column = 1;
  cl->Flags = 0x8040;
  cl->Extract = L"mesh";
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Extract_ChaosMesh_Texture2D";
  cl->Label = L"Extract_ChaosMesh_Texture2D";
  cl->OutputType = Texture2DType;
  cl->TabType = Texture2DType;
  cl->Command = Texture2DCmdExtract_ChaosMesh_Texture2D;
  cl->MakeGui = Texture2DGuiExtract_ChaosMesh_Texture2D;
  cl->SetDefaults = Texture2DDefExtract_ChaosMesh_Texture2D;
  cl->BindPara = Texture2DBindExtract_ChaosMesh_Texture2D;
  cl->Bind2Para = Texture2DBind2Extract_ChaosMesh_Texture2D;
  cl->Bind3Para = Texture2DBind3Extract_ChaosMesh_Texture2D;
  cl->WikiText = Texture2DWikiExtract_ChaosMesh_Texture2D;
  cl->ParaStrings = 1;
  cl->Column = 3;
  cl->Flags = 0x8040;
  cl->Extract = L"tex";
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Extract_ChaosMesh_TextureCube";
  cl->Label = L"Extract_ChaosMesh_TextureCube";
  cl->OutputType = TextureCubeType;
  cl->TabType = TextureCubeType;
  cl->Command = TextureCubeCmdExtract_ChaosMesh_TextureCube;
  cl->MakeGui = TextureCubeGuiExtract_ChaosMesh_TextureCube;
  cl->SetDefaults = TextureCubeDefExtract_ChaosMesh_TextureCube;
  cl->BindPara = TextureCubeBindExtract_ChaosMesh_TextureCube;
  cl->Bind2Para = TextureCubeBind2Extract_ChaosMesh_TextureCube;
  cl->Bind3Para = TextureCubeBind3Extract_ChaosMesh_TextureCube;
  cl->WikiText = TextureCubeWikiExtract_ChaosMesh_TextureCube;
  cl->ParaStrings = 1;
  cl->Column = 3;
  cl->Flags = 0x8040;
  cl->Extract = L"cube";
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Extract_ChaosMesh_Wz4Skeleton";
  cl->Label = L"Extract_ChaosMesh_Wz4Skeleton";
  cl->OutputType = Wz4SkeletonType;
  cl->TabType = Wz4SkeletonType;
  cl->Command = Wz4SkeletonCmdExtract_ChaosMesh_Wz4Skeleton;
  cl->MakeGui = Wz4SkeletonGuiExtract_ChaosMesh_Wz4Skeleton;
  cl->SetDefaults = Wz4SkeletonDefExtract_ChaosMesh_Wz4Skeleton;
  cl->BindPara = Wz4SkeletonBindExtract_ChaosMesh_Wz4Skeleton;
  cl->Bind2Para = Wz4SkeletonBind2Extract_ChaosMesh_Wz4Skeleton;
  cl->Bind3Para = Wz4SkeletonBind3Extract_ChaosMesh_Wz4Skeleton;
  cl->WikiText = Wz4SkeletonWikiExtract_ChaosMesh_Wz4Skeleton;
  cl->ParaStrings = 1;
  cl->Column = 3;
  cl->Flags = 0x8040;
  cl->Extract = L"skeleton";
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Export";
  cl->Label = L"Export";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdExport;
  cl->MakeGui = ChaosMeshGuiExport;
  cl->SetDefaults = ChaosMeshDefExport;
  cl->BindPara = ChaosMeshBindExport;
  cl->Bind2Para = ChaosMeshBind2Export;
  cl->Bind3Para = ChaosMeshBind3Export;
  cl->WikiText = ChaosMeshWikiExport;
  cl->ParaStrings = 1;
  cl->FileOutMask = 1;
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ExportXSI";
  cl->Label = L"ExportXSI";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdExportXSI;
  cl->MakeGui = ChaosMeshGuiExportXSI;
  cl->SetDefaults = ChaosMeshDefExportXSI;
  cl->BindPara = ChaosMeshBindExportXSI;
  cl->Bind2Para = ChaosMeshBind2ExportXSI;
  cl->Bind3Para = ChaosMeshBind3ExportXSI;
  cl->WikiText = ChaosMeshWikiExportXSI;
  cl->ParaStrings = 1;
  cl->FileOutMask = 1;
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Import";
  cl->Label = L"Import";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdImport;
  cl->MakeGui = ChaosMeshGuiImport;
  cl->SetDefaults = ChaosMeshDefImport;
  cl->BindPara = ChaosMeshBindImport;
  cl->Bind2Para = ChaosMeshBind2Import;
  cl->Bind3Para = ChaosMeshBind3Import;
  cl->WikiText = ChaosMeshWikiImport;
  cl->ParaStrings = 1;
  cl->ParaWords = 1;
  cl->FileInMask = 1;
  cl->FileInFilter = L"xsi|cm";
  cl->Flags = 0x8000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"torus";
  cl->Label = L"torus";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdtorus;
  cl->MakeGui = ChaosMeshGuitorus;
  cl->SetDefaults = ChaosMeshDeftorus;
  cl->BindPara = ChaosMeshBindtorus;
  cl->Bind2Para = ChaosMeshBind2torus;
  cl->Bind3Para = ChaosMeshBind3torus;
  cl->WikiText = ChaosMeshWikitorus;
  cl->ParaWords = 7;
  cl->Shortcut = 'o';
  cl->Flags = 0x8000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"grid";
  cl->Label = L"grid";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdgrid;
  cl->MakeGui = ChaosMeshGuigrid;
  cl->SetDefaults = ChaosMeshDefgrid;
  cl->BindPara = ChaosMeshBindgrid;
  cl->Bind2Para = ChaosMeshBind2grid;
  cl->Bind3Para = ChaosMeshBind3grid;
  cl->WikiText = ChaosMeshWikigrid;
  cl->ParaWords = 3;
  cl->Flags = 0x8000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"cube";
  cl->Label = L"cube";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdcube;
  cl->MakeGui = ChaosMeshGuicube;
  cl->SetDefaults = ChaosMeshDefcube;
  cl->BindPara = ChaosMeshBindcube;
  cl->Bind2Para = ChaosMeshBind2cube;
  cl->Bind3Para = ChaosMeshBind3cube;
  cl->WikiText = ChaosMeshWikicube;
  cl->ParaWords = 13;
  cl->Flags = 0x8000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sphere";
  cl->Label = L"Sphere";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdSphere;
  cl->MakeGui = ChaosMeshGuiSphere;
  cl->SetDefaults = ChaosMeshDefSphere;
  cl->BindPara = ChaosMeshBindSphere;
  cl->Bind2Para = ChaosMeshBind2Sphere;
  cl->Bind3Para = ChaosMeshBind3Sphere;
  cl->WikiText = ChaosMeshWikiSphere;
  cl->ParaWords = 3;
  cl->Shortcut = 'h';
  cl->Flags = 0x8000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SelectCube";
  cl->Label = L"SelectCube";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdSelectCube;
  cl->MakeGui = ChaosMeshGuiSelectCube;
  cl->SetDefaults = ChaosMeshDefSelectCube;
  cl->BindPara = ChaosMeshBindSelectCube;
  cl->Bind2Para = ChaosMeshBind2SelectCube;
  cl->Bind3Para = ChaosMeshBind3SelectCube;
  cl->WikiText = ChaosMeshWikiSelectCube;
  cl->Handles = ChaosMeshHndSelectCube;
  cl->ParaWords = 12;
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DeleteFaces";
  cl->Label = L"DeleteFaces";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdDeleteFaces;
  cl->MakeGui = ChaosMeshGuiDeleteFaces;
  cl->SetDefaults = ChaosMeshDefDeleteFaces;
  cl->BindPara = ChaosMeshBindDeleteFaces;
  cl->Bind2Para = ChaosMeshBind2DeleteFaces;
  cl->Bind3Para = ChaosMeshBind3DeleteFaces;
  cl->WikiText = ChaosMeshWikiDeleteFaces;
  cl->ParaWords = 1;
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"transform";
  cl->Label = L"transform";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdtransform;
  cl->MakeGui = ChaosMeshGuitransform;
  cl->SetDefaults = ChaosMeshDeftransform;
  cl->BindPara = ChaosMeshBindtransform;
  cl->Bind2Para = ChaosMeshBind2transform;
  cl->Bind3Para = ChaosMeshBind3transform;
  cl->WikiText = ChaosMeshWikitransform;
  cl->ParaWords = 10;
  cl->Shortcut = 't';
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"randomize";
  cl->Label = L"randomize";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdrandomize;
  cl->MakeGui = ChaosMeshGuirandomize;
  cl->SetDefaults = ChaosMeshDefrandomize;
  cl->BindPara = ChaosMeshBindrandomize;
  cl->Bind2Para = ChaosMeshBind2randomize;
  cl->Bind3Para = ChaosMeshBind3randomize;
  cl->WikiText = ChaosMeshWikirandomize;
  cl->ParaWords = 5;
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"add";
  cl->Label = L"add";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdadd;
  cl->MakeGui = ChaosMeshGuiadd;
  cl->SetDefaults = ChaosMeshDefadd;
  cl->BindPara = ChaosMeshBindadd;
  cl->Bind2Para = ChaosMeshBind2add;
  cl->Bind3Para = ChaosMeshBind3add;
  cl->WikiText = ChaosMeshWikiadd;
  cl->Shortcut = 'a';
  cl->Column = 2;
  cl->Flags = 0x8001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SetMtrl";
  cl->Label = L"SetMtrl";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdSetMtrl;
  cl->MakeGui = ChaosMeshGuiSetMtrl;
  cl->SetDefaults = ChaosMeshDefSetMtrl;
  cl->BindPara = ChaosMeshBindSetMtrl;
  cl->Bind2Para = ChaosMeshBind2SetMtrl;
  cl->Bind3Para = ChaosMeshBind3SetMtrl;
  cl->WikiText = ChaosMeshWikiSetMtrl;
  cl->Shortcut = 'm';
  cl->Column = 2;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MaterialType;
  in[1].DefaultClass = 0;
  in[1].Name = L"Material";
  in[1].Flags = 0|wCIF_METHODBOTH;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ChangeTexture";
  cl->Label = L"ChangeTexture";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdChangeTexture;
  cl->MakeGui = ChaosMeshGuiChangeTexture;
  cl->SetDefaults = ChaosMeshDefChangeTexture;
  cl->BindPara = ChaosMeshBindChangeTexture;
  cl->Bind2Para = ChaosMeshBind2ChangeTexture;
  cl->Bind3Para = ChaosMeshBind3ChangeTexture;
  cl->WikiText = ChaosMeshWikiChangeTexture;
  cl->ParaWords = 3;
  cl->Shortcut = 'm';
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(6);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Name = L"Bump";
  in[1].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  in[2].Type = Texture2DType;
  in[2].DefaultClass = 0;
  in[2].Name = L"Diffuse";
  in[2].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  in[3].Type = Texture2DType;
  in[3].DefaultClass = 0;
  in[3].Name = L"Detail";
  in[3].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  in[4].Type = TextureCubeType;
  in[4].DefaultClass = 0;
  in[4].Name = L"SpecCube";
  in[4].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  in[5].Type = TextureCubeType;
  in[5].DefaultClass = 0;
  in[5].Name = L"LightCube";
  in[5].Flags = 0|wCIF_OPTIONAL|wCIF_METHODLINK;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ChangeMaterial";
  cl->Label = L"ChangeMaterial";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdChangeMaterial;
  cl->MakeGui = ChaosMeshGuiChangeMaterial;
  cl->SetDefaults = ChaosMeshDefChangeMaterial;
  cl->BindPara = ChaosMeshBindChangeMaterial;
  cl->Bind2Para = ChaosMeshBind2ChangeMaterial;
  cl->Bind3Para = ChaosMeshBind3ChangeMaterial;
  cl->WikiText = ChaosMeshWikiChangeMaterial;
  cl->Shortcut = 'm';
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MaterialType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BurnAnim";
  cl->Label = L"BurnAnim";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdBurnAnim;
  cl->MakeGui = ChaosMeshGuiBurnAnim;
  cl->SetDefaults = ChaosMeshDefBurnAnim;
  cl->BindPara = ChaosMeshBindBurnAnim;
  cl->Bind2Para = ChaosMeshBind2BurnAnim;
  cl->Bind3Para = ChaosMeshBind3BurnAnim;
  cl->WikiText = ChaosMeshWikiBurnAnim;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DeleteSkeleton";
  cl->Label = L"DeleteSkeleton";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdDeleteSkeleton;
  cl->MakeGui = ChaosMeshGuiDeleteSkeleton;
  cl->SetDefaults = ChaosMeshDefDeleteSkeleton;
  cl->BindPara = ChaosMeshBindDeleteSkeleton;
  cl->Bind2Para = ChaosMeshBind2DeleteSkeleton;
  cl->Bind3Para = ChaosMeshBind3DeleteSkeleton;
  cl->WikiText = ChaosMeshWikiDeleteSkeleton;
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BakeMorph";
  cl->Label = L"BakeMorph";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdBakeMorph;
  cl->MakeGui = ChaosMeshGuiBakeMorph;
  cl->SetDefaults = ChaosMeshDefBakeMorph;
  cl->BindPara = ChaosMeshBindBakeMorph;
  cl->Bind2Para = ChaosMeshBind2BakeMorph;
  cl->Bind3Para = ChaosMeshBind3BakeMorph;
  cl->WikiText = ChaosMeshWikiBakeMorph;
  cl->ParaWords = 2;
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = ChaosMeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MergeShape";
  cl->Label = L"MergeShape";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdMergeShape;
  cl->MakeGui = ChaosMeshGuiMergeShape;
  cl->SetDefaults = ChaosMeshDefMergeShape;
  cl->BindPara = ChaosMeshBindMergeShape;
  cl->Bind2Para = ChaosMeshBind2MergeShape;
  cl->Bind3Para = ChaosMeshBind3MergeShape;
  cl->WikiText = ChaosMeshWikiMergeShape;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(4);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = ChaosMeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = ChaosMeshType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0;
  in[3].Type = ChaosMeshType;
  in[3].DefaultClass = 0;
  in[3].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MergeAnim";
  cl->Label = L"MergeAnim";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdMergeAnim;
  cl->MakeGui = ChaosMeshGuiMergeAnim;
  cl->SetDefaults = ChaosMeshDefMergeAnim;
  cl->BindPara = ChaosMeshBindMergeAnim;
  cl->Bind2Para = ChaosMeshBind2MergeAnim;
  cl->Bind3Para = ChaosMeshBind3MergeAnim;
  cl->WikiText = ChaosMeshWikiMergeAnim;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x8001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FakeBone";
  cl->Label = L"FakeBone";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdFakeBone;
  cl->MakeGui = ChaosMeshGuiFakeBone;
  cl->SetDefaults = ChaosMeshDefFakeBone;
  cl->BindPara = ChaosMeshBindFakeBone;
  cl->Bind2Para = ChaosMeshBind2FakeBone;
  cl->Bind3Para = ChaosMeshBind3FakeBone;
  cl->WikiText = ChaosMeshWikiFakeBone;
  cl->ParaWords = 11;
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"CompressAnim";
  cl->Label = L"CompressAnim";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdCompressAnim;
  cl->MakeGui = ChaosMeshGuiCompressAnim;
  cl->SetDefaults = ChaosMeshDefCompressAnim;
  cl->BindPara = ChaosMeshBindCompressAnim;
  cl->Bind2Para = ChaosMeshBind2CompressAnim;
  cl->Bind3Para = ChaosMeshBind3CompressAnim;
  cl->WikiText = ChaosMeshWikiCompressAnim;
  cl->ParaWords = 2;
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SliceAndDice";
  cl->Label = L"SliceAndDice";
  cl->OutputType = ChaosMeshType;
  cl->TabType = ChaosMeshType;
  cl->Command = ChaosMeshCmdSliceAndDice;
  cl->MakeGui = ChaosMeshGuiSliceAndDice;
  cl->SetDefaults = ChaosMeshDefSliceAndDice;
  cl->BindPara = ChaosMeshBindSliceAndDice;
  cl->Bind2Para = ChaosMeshBind2SliceAndDice;
  cl->Bind3Para = ChaosMeshBind3SliceAndDice;
  cl->WikiText = ChaosMeshWikiSliceAndDice;
  cl->Column = 1;
  cl->Flags = 0x8000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ChaosMeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(chaosmesh_ops,0x111,AddOps_chaosmesh_ops,0);


/****************************************************************************/


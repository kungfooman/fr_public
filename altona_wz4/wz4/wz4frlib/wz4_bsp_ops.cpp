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
#include "wz4_bsp_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4BSPType_ *Wz4BSPType;

/****************************************************************************/

#line 30 "wz4_bsp_ops.ops"
void Wz4BSPType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 31 "wz4_bsp_ops.ops"

    if(obj && obj->IsType(Wz4BSPType))
    {
      static const sInt downsample = 1;
      sInt tgtSizeX = sMin(pi.Client.SizeX()/downsample,512);
      sInt tgtSizeY = sMin(pi.Client.SizeY()/downsample,384);

      if(tgtSizeX != img->SizeX || tgtSizeY != img->SizeY)
      {
        delete img;
        img = new sImage(tgtSizeX,tgtSizeY);
      }

      Wz4BSP *bsp = (Wz4BSP *) obj;
      img->Fill(pi.BackColor);

      sU32 *ptr = img->Data;
      sRay ray;
      sVector30 normal, dir;

      dir = pi.View->Camera.k;

      for(sInt y=0;y<img->SizeY;y++)
      {
        for(sInt x=0;x<img->SizeX;x++)
        {
          pi.View->MakeRay(2.0f*x/img->SizeX-1.0f,1.0f-2.0f*y/img->SizeY,ray);

          /*ray.Start.Init(0.0f,0.0f,-5.0f);
          ray.Dir.Init(4.0f/3.0f*(2.0f*x/img->SizeX-1.0f),1.0f-2.0f*y/img->SizeY,1.0f);
          ray.Dir.Unit();*/
          
          sF32 t;
          if(bsp->TraceRay(ray,0.0f,1e+20f,t,normal))
          {
            //sVector31 hit = ray.Start + t * ray.Dir;

            //hit = sVector31(hit * 1.5f);
            //sInt colR = sClamp<sInt>(hit.x * 127.5f + 127.5f,0,255);
            //sInt colG = sClamp<sInt>(hit.y * 127.5f + 127.5f,0,255);
            //sInt colB = sClamp<sInt>(hit.z * 127.5f + 127.5f,0,255);
            //*ptr = (colR<<16) + (colG<<8) + (colB<<0) + 0xff000000;

            sInt col = sClamp<sInt>(sInt(-(normal^dir)*255),0,255);
            *ptr = col*0x010101 | 0xff000000;
          }

          ptr++;
        }
      }

      sRect srcRect(0,0,img->SizeX,img->SizeY);
      sStretch2D(img->Data,img->SizeX,srcRect,pi.Client);
    }
  ;
#line 82 "wz4_bsp_ops.cpp"
}
#line 87 "wz4_bsp_ops.ops"
void Wz4BSPType_::Init()
{
#line 88 "wz4_bsp_ops.ops"

    img = new sImage(1,1);
  ;
#line 91 "wz4_bsp_ops.cpp"
}
#line 92 "wz4_bsp_ops.ops"
void Wz4BSPType_::Exit()
{
#line 93 "wz4_bsp_ops.ops"

    sDelete(img);
  ;
#line 100 "wz4_bsp_ops.cpp"
}

/****************************************************************************/

sBool Wz4BSPCmdPolyhedron(wExecutive *exe,wCommand *cmd)
{
  Wz4BSPParaPolyhedron sUNUSED *para = (Wz4BSPParaPolyhedron *)(cmd->Data); para;
  Wz4BSP *out = (Wz4BSP *) cmd->Output;
  if(!out) { out=new Wz4BSP; cmd->Output=out; }

  {
#line 112 "wz4_bsp_ops.ops"

    out->MakePolyhedron(para->Faces,para->nIter,para->Power,para->Flags&1,para->RandomSeed);
  ;
#line 116 "wz4_bsp_ops.cpp"
    return 1;
  }
}

void Wz4BSPGuiPolyhedron(wGridFrameHelper &gh,wOp *op)
{
  Wz4BSPParaPolyhedron sUNUSED *para = (Wz4BSPParaPolyhedron *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Faces");
  sIntControl *int_Faces = gh.Int(&para->Faces,4,256,0.125000f);
  int_Faces->Default = 0x00000004; int_Faces->RightStep = 0.125000f;

  gh.Label(L"nIter");
  sIntControl *int_nIter = gh.Int(&para->nIter,1,200,0.125000f);
  int_nIter->Default = 0x00000020; int_nIter->RightStep = 0.125000f;

  gh.Label(L"Power");
  sFloatControl *float_Power = gh.Float(&para->Power,0.000000f,10.00000f,0.001000f);
  float_Power->Default = 0.500000f; float_Power->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"-|dualize",gh.ChangeMsg);

  gh.Label(L"RandomSeed");
  sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
  int_RandomSeed->Default = 0x00000000; int_RandomSeed->RightStep = 0.125000f;
}

void Wz4BSPDefPolyhedron(wOp *op)
{
  Wz4BSPParaPolyhedron sUNUSED *para = (Wz4BSPParaPolyhedron *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Faces = 0x00000004;
  para->nIter = 0x00000020;
  para->Power = 0.500000f;
}

void Wz4BSPBindPolyhedron(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"faces"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"niter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"power"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"randomseed"),val);
}
void Wz4BSPBind2Polyhedron(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"faces");
    name[1] = sPoolString(L"niter");
    name[2] = sPoolString(L"power");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"randomseed");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
}
void Wz4BSPBind3Polyhedron(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import faces : int;\n");
  tb.PrintF(L"  import niter : int;\n");
  tb.PrintF(L"  import power : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
}
const sChar *Wz4BSPWikiPolyhedron =
L"= Wz4BSP : Polyhedron\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Polyhedron\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4BSP\n"
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
L" !i Faces\n"
L" !i Faces\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i nIter\n"
L" !i nIter\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Power\n"
L" !i Power\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i dualize\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4BSPCmdFromMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4BSPParaFromMesh sUNUSED *para = (Wz4BSPParaFromMesh *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4BSP *out = (Wz4BSP *) cmd->Output;
  if(!out) { out=new Wz4BSP; cmd->Output=out; }

  {
#line 125 "wz4_bsp_ops.ops"

    static const sF32 thick[9] =
    {
      1e-10f,
      3e-7f,
      1e-6f,
      2e-5f,
      1e-4f,
      1e-2f,
      2.0f,
      100.0f,
    };

    Wz4BSPError err = out->FromMesh(in0,thick[sClamp<sInt>(para->PlaneThickness,0,6)]);
    if(err != WZ4BSP_OK)
    {
      cmd->SetError(Wz4BSPGetErrorString(err));
      return 0;
    }
  ;
#line 284 "wz4_bsp_ops.cpp"
    return 1;
  }
}

void Wz4BSPGuiFromMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4BSPParaFromMesh sUNUSED *para = (Wz4BSPParaFromMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Plane thickness (epsilon)");
  gh.Flags(&para->PlaneThickness,L"Molecular|Tiny|Small|Normal|Large|Huge|San Andreas Gap|Ridiculous",gh.ChangeMsg);
}

void Wz4BSPDefFromMesh(wOp *op)
{
  Wz4BSPParaFromMesh sUNUSED *para = (Wz4BSPParaFromMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->PlaneThickness = 0x00000003;
}

void Wz4BSPBindFromMesh(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4BSPBind2FromMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"planethickness");
  }
}
void Wz4BSPBind3FromMesh(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4BSPWikiFromMesh =
L"= Wz4BSP : FromMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FromMesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4BSP\n"
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
L" !i Plane thickness (epsilon)\n"
L" !i PlaneThickness\n"
L" !i Molecular\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Tiny\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Small\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Large\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Huge\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i San Andreas Gap\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Ridiculous\n"
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

sBool Wz4BSPCmdSliceAndDice(wExecutive *exe,wCommand *cmd)
{
  Wz4BSPParaSliceAndDice sUNUSED *para = (Wz4BSPParaSliceAndDice *)(cmd->Data); para;
  Wz4BSP sUNUSED *in0 = cmd->GetInput<Wz4BSP *>(0); in0;
  Wz4BSP *out = (Wz4BSP *) cmd->Output;
  if(!out) { out=new Wz4BSP; cmd->Output=out; }

  {
#line 159 "wz4_bsp_ops.ops"

    out->CopyFrom(in0);
    out->MakeRandomSplits(para->RandomPlanesAtMin,sMin(para->MinSize,para->MaxSize),
      para->MaxSize,para->RandomSeed,para->MaxSplits);
  ;
#line 413 "wz4_bsp_ops.cpp"
    return 1;
  }
}

void Wz4BSPGuiSliceAndDice(wGridFrameHelper &gh,wOp *op)
{
  Wz4BSPParaSliceAndDice sUNUSED *para = (Wz4BSPParaSliceAndDice *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"MinSize");
  sFloatControl *float_MinSize = gh.Float(&para->MinSize,0.000000f,256.0000f,0.001000f);
  float_MinSize->Default = 0.000000f; float_MinSize->RightStep = 0.125000f;

  gh.Label(L"MaxSize");
  sFloatControl *float_MaxSize = gh.Float(&para->MaxSize,0.010000f,256.0000f,0.001000f);
  float_MaxSize->Default = 0.100000f; float_MaxSize->RightStep = 0.125000f;

  gh.Label(L"RandomPlanesAtMin");
  sFloatControl *float_RandomPlanesAtMin = gh.Float(&para->RandomPlanesAtMin,0.000000f,1.000000f,0.001000f);
  float_RandomPlanesAtMin->Default = 0.100000f; float_RandomPlanesAtMin->RightStep = 0.125000f;

  gh.Label(L"RandomSeed");
  sIntControl *int_RandomSeed = gh.Int(&para->RandomSeed,0,255,0.125000f);
  int_RandomSeed->Default = 0x00000001; int_RandomSeed->RightStep = 0.125000f;

  gh.Label(L"MaxSplits");
  sIntControl *int_MaxSplits = gh.Int(&para->MaxSplits,1,1000000,1.000000f);
  int_MaxSplits->Default = 0x00002710; int_MaxSplits->RightStep = 0.125000f;
}

void Wz4BSPDefSliceAndDice(wOp *op)
{
  Wz4BSPParaSliceAndDice sUNUSED *para = (Wz4BSPParaSliceAndDice *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->MaxSize = 0.100000f;
  para->RandomPlanesAtMin = 0.100000f;
  para->RandomSeed = 0x00000001;
  para->MaxSplits = 0x00002710;
}

void Wz4BSPBindSliceAndDice(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"minsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"maxsize"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"randomplanesatmin"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"randomseed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"maxsplits"),val);
}
void Wz4BSPBind2SliceAndDice(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"minsize");
    name[1] = sPoolString(L"maxsize");
    name[2] = sPoolString(L"randomplanesatmin");
    name[3] = sPoolString(L"randomseed");
    name[4] = sPoolString(L"maxsplits");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
}
void Wz4BSPBind3SliceAndDice(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import minsize : float;\n");
  tb.PrintF(L"  import maxsize : float;\n");
  tb.PrintF(L"  import randomplanesatmin : float;\n");
  tb.PrintF(L"  import randomseed : int;\n");
  tb.PrintF(L"  import maxsplits : int;\n");
}
const sChar *Wz4BSPWikiSliceAndDice =
L"= Wz4BSP : SliceAndDice\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SliceAndDice\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4BSP\n"
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
L" !i Wz4BSP\n"
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
L" !i MinSize\n"
L" !i MinSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaxSize\n"
L" !i MaxSize\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomPlanesAtMin\n"
L" !i RandomPlanesAtMin\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i RandomSeed\n"
L" !i RandomSeed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MaxSplits\n"
L" !i MaxSplits\n"
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

sBool Wz4MeshCmdBSPToMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaBSPToMesh sUNUSED *para = (Wz4MeshParaBSPToMesh *)(cmd->Data); para;
  Wz4BSP sUNUSED *in0 = cmd->GetInput<Wz4BSP *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 174 "wz4_bsp_ops.ops"

    Wz4BSPError err = in0->GeneratePolyhedrons(out,para->Explode);
    out->DontClearVertices = 1;
    if(err != WZ4BSP_OK)
    {
      cmd->SetError(Wz4BSPGetErrorString(err));
      return 0;
    }
  ;
#line 588 "wz4_bsp_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiBSPToMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaBSPToMesh sUNUSED *para = (Wz4MeshParaBSPToMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Explode");
  sFloatControl *float_Explode = gh.Float(&para->Explode,0.000000f,16.00000f,0.001000f);
  float_Explode->Default = 0.000000f; float_Explode->RightStep = 0.125000f;
}

void Wz4MeshDefBSPToMesh(wOp *op)
{
  Wz4MeshParaBSPToMesh sUNUSED *para = (Wz4MeshParaBSPToMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindBSPToMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"explode"),val);
}
void Wz4MeshBind2BSPToMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"explode");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void Wz4MeshBind3BSPToMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import explode : float;\n");
}
const sChar *Wz4MeshWikiBSPToMesh =
L"= Wz4Mesh : BSPToMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BSPToMesh\n"
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
L" !i Wz4BSP\n"
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
L" !i Explode\n"
L" !i Explode\n"
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

void Wz4BSPAnimPolyhedron::Init(class ScriptContext *sc)
{
};

void Wz4BSPAnimPolyhedron::Bind(class ScriptContext *sc,Wz4BSPParaPolyhedron *para)
{
};

void Wz4BSPAnimFromMesh::Init(class ScriptContext *sc)
{
};

void Wz4BSPAnimFromMesh::Bind(class ScriptContext *sc,Wz4BSPParaFromMesh *para)
{
};

void Wz4BSPAnimSliceAndDice::Init(class ScriptContext *sc)
{
};

void Wz4BSPAnimSliceAndDice::Bind(class ScriptContext *sc,Wz4BSPParaSliceAndDice *para)
{
};

void Wz4MeshAnimBSPToMesh::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimBSPToMesh::Bind(class ScriptContext *sc,Wz4MeshParaBSPToMesh *para)
{
};


/****************************************************************************/

void AddTypes_wz4_bsp_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4BSPType = new Wz4BSPType_);
  Wz4BSPType->Secondary = secondary;

}

/****************************************************************************/

void AddOps_wz4_bsp_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Polyhedron";
  cl->Label = L"Polyhedron";
  cl->OutputType = Wz4BSPType;
  cl->TabType = Wz4BSPType;
  cl->Command = Wz4BSPCmdPolyhedron;
  cl->MakeGui = Wz4BSPGuiPolyhedron;
  cl->SetDefaults = Wz4BSPDefPolyhedron;
  cl->BindPara = Wz4BSPBindPolyhedron;
  cl->Bind2Para = Wz4BSPBind2Polyhedron;
  cl->Bind3Para = Wz4BSPBind3Polyhedron;
  cl->WikiText = Wz4BSPWikiPolyhedron;
  cl->ParaWords = 5;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FromMesh";
  cl->Label = L"FromMesh";
  cl->OutputType = Wz4BSPType;
  cl->TabType = Wz4BSPType;
  cl->Command = Wz4BSPCmdFromMesh;
  cl->MakeGui = Wz4BSPGuiFromMesh;
  cl->SetDefaults = Wz4BSPDefFromMesh;
  cl->BindPara = Wz4BSPBindFromMesh;
  cl->Bind2Para = Wz4BSPBind2FromMesh;
  cl->Bind3Para = Wz4BSPBind3FromMesh;
  cl->WikiText = Wz4BSPWikiFromMesh;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SliceAndDice";
  cl->Label = L"SliceAndDice";
  cl->OutputType = Wz4BSPType;
  cl->TabType = Wz4BSPType;
  cl->Command = Wz4BSPCmdSliceAndDice;
  cl->MakeGui = Wz4BSPGuiSliceAndDice;
  cl->SetDefaults = Wz4BSPDefSliceAndDice;
  cl->BindPara = Wz4BSPBindSliceAndDice;
  cl->Bind2Para = Wz4BSPBind2SliceAndDice;
  cl->Bind3Para = Wz4BSPBind3SliceAndDice;
  cl->WikiText = Wz4BSPWikiSliceAndDice;
  cl->ParaWords = 5;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4BSPType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BSPToMesh";
  cl->Label = L"BSPToMesh";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdBSPToMesh;
  cl->MakeGui = Wz4MeshGuiBSPToMesh;
  cl->SetDefaults = Wz4MeshDefBSPToMesh;
  cl->BindPara = Wz4MeshBindBSPToMesh;
  cl->Bind2Para = Wz4MeshBind2BSPToMesh;
  cl->Bind3Para = Wz4MeshBind3BSPToMesh;
  cl->WikiText = Wz4MeshWikiBSPToMesh;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4BSPType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_bsp_ops,0x110,AddOps_wz4_bsp_ops,0);


/****************************************************************************/


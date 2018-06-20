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
#include "tron_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 16 "tron_ops.ops"

#include "wz4frlib/tron.hpp"
#include "wz4frlib/tron_ops.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4frlib/wz4_ipp.hpp"

#line 31 "tron_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool Wz4ParticlesCmdPlaceOnMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaPlaceOnMesh sUNUSED *para = (Wz4ParticlesParaPlaceOnMesh *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 39 "tron_ops.ops"

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
    
    TronPOM *node = new TronPOM();
    out->RootNode = node;   
    node->ParaBase = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    node->Mesh = in1; in1->AddRef();    
    Wz4BSPError err = node->Init(thick[sClamp<sInt>(para->PlaneThickness,0,6)]);

    if(err != WZ4BSP_OK)
    {
      cmd->SetError(Wz4BSPGetErrorString(err));
      return 0;
    }
    
    out->AddCode(cmd);    
    
    if (cmd->Op)
    {
      cmd->Op->RefObj->Release();
      cmd->Op->RefObj = out; out->AddRef();    
    }    
  ;
#line 82 "tron_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesHndPlaceOnMesh(wPaintInfo &pi,wOp *op)
{
  Wz4ParticlesParaPlaceOnMesh sUNUSED *para = (Wz4ParticlesParaPlaceOnMesh *)(op->EditData); para;
#line 75 "tron_ops.ops"

    TronPOM::Handles(pi,para,op);    
  ;
#line 94 "tron_ops.cpp"
}

void Wz4ParticlesGuiPlaceOnMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaPlaceOnMesh sUNUSED *para = (Wz4ParticlesParaPlaceOnMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Plane thickness (epsilon)");
  gh.Flags(&para->PlaneThickness,L"Molecular|Tiny|Small|Normal|Large|Huge|San Andreas Gap|Ridiculous",gh.ChangeMsg);

  gh.Label(L"Length");
  sFloatControl *float_Length = gh.Float(&para->Length,0.010000f,1024.000f,0.001000f);
  float_Length->Default = 1.000000f; float_Length->RightStep = 0.125000f;

  gh.Label(L"Direction");
  gh.BeginTied();
  sFloatControl *float_Direction_0 = gh.Float(&para->Direction.x,-1024.00f,1024.000f,0.001000f);
  float_Direction_0->Default = 0.000000f; float_Direction_0->RightStep = 0.125000f;
  sFloatControl *float_Direction_1 = gh.Float(&para->Direction.y,-1024.00f,1024.000f,0.001000f);
  float_Direction_1->Default = 0.000000f; float_Direction_1->RightStep = 0.125000f;
  sFloatControl *float_Direction_2 = gh.Float(&para->Direction.z,-1024.00f,1024.000f,0.001000f);
  float_Direction_2->Default = 0.000000f; float_Direction_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"Static|Dynamic",gh.ChangeMsg);
}

void Wz4ParticlesDefPlaceOnMesh(wOp *op)
{
  Wz4ParticlesParaPlaceOnMesh sUNUSED *para = (Wz4ParticlesParaPlaceOnMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->PlaneThickness = 0x00000003;
  para->Length = 1.000000f;
}

void Wz4ParticlesBindPlaceOnMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"length"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"direction"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"direction"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"direction"),val);
}
void Wz4ParticlesBind2PlaceOnMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"planethickness");
    name[1] = sPoolString(L"length");
    name[2] = sPoolString(L"direction");
    name[3] = sPoolString(L"mode");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
}
void Wz4ParticlesBind3PlaceOnMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import length : float;\n");
  tb.PrintF(L"  import direction : float[3];\n");
}
const sChar *Wz4ParticlesWikiPlaceOnMesh =
L"= Wz4Particles : PlaceOnMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i PlaceOnMesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
L" !i\n"
L" !i *\n"
L"\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Length\n"
L" !i Length\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Direction\n"
L" !i Direction\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i Static\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Dynamic\n"
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

sBool Wz4ParticlesCmdSingleForceField(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaSingleForceField sUNUSED *para = (Wz4ParticlesParaSingleForceField *)(cmd->Data); para;
  Wz4Particles sUNUSED *in0 = cmd->GetInput<Wz4Particles *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 108 "tron_ops.ops"

    TronSFF *node = new TronSFF();
    node->ParaBase = *para;
    node->Source = in0->RootNode; in0->RootNode->AddRef();
    node->Init();
    out->RootNode = node;
    out->AddCode(cmd);    
  ;
#line 286 "tron_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesHndSingleForceField(wPaintInfo &pi,wOp *op)
{
  Wz4ParticlesParaSingleForceField sUNUSED *para = (Wz4ParticlesParaSingleForceField *)(op->EditData); para;
#line 118 "tron_ops.ops"

    sVector31 p0,p1,p2,p3,p4,p5,p6,p7;

    if (para->FieldType==0)
    {
      p0 = p1 = p2 = p3 = p4 = p5 = para->Position;
      p0.x += para->Size.x;
      p1.x -= para->Size.x;
      p2.y += para->Size.y;
      p3.y -= para->Size.y;
      p4.z += para->Size.z;
      p5.z -= para->Size.z;

      pi.Line3D(p0,p1);
      pi.Line3D(p2,p3);
      pi.Line3D(p4,p5);
    }
    else
    {
      p0 = p1 = p2 = p3 = p4 = p5 = p6 = p7 = para->Position;
      p0.x += 0.1f;
      p1.x -= 0.1f;
      p2.y += 0.1f;
      p3.y -= 0.1f;
      p4.z += 0.1f;
      p5.z -= 0.1f;
      
      sVector30 pn;
      sMatrix34 mat;
      mat.EulerXYZ(para->Rotation.x, para->Rotation.y, para->Rotation.z);
      pn.Init(0.0f,1.0f,0.0f);  
      pn = pn * mat;
      
      p7 = p7 + pn * para->Distance;

      pi.Line3D(p0,p1);
      pi.Line3D(p2,p3);
      pi.Line3D(p4,p5);
      pi.Line3D(p6,p7);
    }
  ;
#line 336 "tron_ops.cpp"
}

void Wz4ParticlesGuiSingleForceField(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaSingleForceField sUNUSED *para = (Wz4ParticlesParaSingleForceField *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"FieldType");
  gh.Flags(&para->FieldType,L"Ellipsoid|Plane",gh.LayoutMsg);

  gh.Label(L"ForceType");
  gh.Flags(&para->ForceType,L"x|sinx|recx|recquadx",gh.LayoutMsg);

  gh.Label(L"* Position");
  gh.BeginTied();
  sFloatControl *float_Position_0 = gh.Float(&para->Position.x,-1024.00f,1024.000f,0.001000f);
  float_Position_0->Default = 0.000000f; float_Position_0->RightStep = 0.125000f;
  sFloatControl *float_Position_1 = gh.Float(&para->Position.y,-1024.00f,1024.000f,0.001000f);
  float_Position_1->Default = 0.000000f; float_Position_1->RightStep = 0.125000f;
  sFloatControl *float_Position_2 = gh.Float(&para->Position.z,-1024.00f,1024.000f,0.001000f);
  float_Position_2->Default = 0.000000f; float_Position_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* Scale");
  sFloatControl *float_Scale = gh.Float(&para->Scale,-1024.00f,1024.000f,0.001000f);
  float_Scale->Default = 1.000000f; float_Scale->RightStep = 0.125000f;

  if((para->FieldType==0x0000))
  {
    gh.Label(L"* Size");
    gh.BeginTied();
    sFloatControl *float_Size_0 = gh.Float(&para->Size.x,-1024.00f,1024.000f,0.001000f);
    float_Size_0->Default = 1.000000f; float_Size_0->RightStep = 0.125000f;
    sFloatControl *float_Size_1 = gh.Float(&para->Size.y,-1024.00f,1024.000f,0.001000f);
    float_Size_1->Default = 1.000000f; float_Size_1->RightStep = 0.125000f;
    sFloatControl *float_Size_2 = gh.Float(&para->Size.z,-1024.00f,1024.000f,0.001000f);
    float_Size_2->Default = 1.000000f; float_Size_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->FieldType==0x0001))
  {
    gh.Label(L"* Rotation");
    gh.BeginTied();
    sFloatControl *float_Rotation_0 = gh.Float(&para->Rotation.x,-1024.00f,1024.000f,0.001000f);
    float_Rotation_0->Default = 0.000000f; float_Rotation_0->RightStep = 0.125000f;
    sFloatControl *float_Rotation_1 = gh.Float(&para->Rotation.y,-1024.00f,1024.000f,0.001000f);
    float_Rotation_1->Default = 0.000000f; float_Rotation_1->RightStep = 0.125000f;
    sFloatControl *float_Rotation_2 = gh.Float(&para->Rotation.z,-1024.00f,1024.000f,0.001000f);
    float_Rotation_2->Default = 0.000000f; float_Rotation_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* Distance");
    sFloatControl *float_Distance = gh.Float(&para->Distance,-1024.00f,1024.000f,0.001000f);
    float_Distance->Default = 1.000000f; float_Distance->RightStep = 0.125000f;

  }
  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4ParticlesDefSingleForceField(wOp *op)
{
  Wz4ParticlesParaSingleForceField sUNUSED *para = (Wz4ParticlesParaSingleForceField *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale = 1.000000f;
  para->Size.x = 1.000000f;
  para->Size.y = 1.000000f;
  para->Size.z = 1.000000f;
  para->Distance = 1.000000f;
}

void Wz4ParticlesBindSingleForceField(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rotation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"distance"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4ParticlesBind2SingleForceField(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"fieldtype");
    name[1] = sPoolString(L"forcetype");
    name[2] = sPoolString(L"position");
    name[3] = sPoolString(L"scale");
    name[4] = sPoolString(L"size");
    name[5] = sPoolString(L"rotation");
    name[6] = sPoolString(L"distance");
    name[7] = sPoolString(L"");
    name[8] = sPoolString(L"script");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[8],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4ParticlesBind3SingleForceField(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import position : float[3];\n");
  tb.PrintF(L"  import scale : float;\n");
  tb.PrintF(L"  import size : float[3];\n");
  tb.PrintF(L"  import rotation : float[3];\n");
  tb.PrintF(L"  import distance : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4ParticlesWikiSingleForceField =
L"= Wz4Particles : SingleForceField\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SingleForceField\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i Wz4Particles\n"
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
L" !i FieldType\n"
L" !i FieldType\n"
L" !i Ellipsoid\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Plane\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ForceType\n"
L" !i ForceType\n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sinx\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i recx\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i recquadx\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Position\n"
L" !i Position\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rotation\n"
L" !i Rotation\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Distance\n"
L" !i Distance\n"
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

sBool Wz4MeshCmdRetexturizer(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaRetexturizer sUNUSED *para = (Wz4MeshParaRetexturizer *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 171 "tron_ops.ops"
        
    TronRTR(out, in0, in1);
  ;
#line 603 "tron_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiRetexturizer(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaRetexturizer sUNUSED *para = (Wz4MeshParaRetexturizer *)(op->EditData); para;
}

void Wz4MeshDefRetexturizer(wOp *op)
{
  Wz4MeshParaRetexturizer sUNUSED *para = (Wz4MeshParaRetexturizer *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4MeshBindRetexturizer(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind2Retexturizer(wCommand *cmd,ScriptContext *ctx)
{
}
void Wz4MeshBind3Retexturizer(wOp *op,sTextBuffer &tb)
{
}
const sChar *Wz4MeshWikiRetexturizer =
L"= Wz4Mesh : Retexturizer\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Retexturizer\n"
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

sBool Wz4ParticlesCmdFR033_MeteorShowerSim(wExecutive *exe,wCommand *cmd)
{
  Wz4ParticlesParaFR033_MeteorShowerSim sUNUSED *para = (Wz4ParticlesParaFR033_MeteorShowerSim *)(cmd->Data); para;
  GroupType sUNUSED *in0 = cmd->GetInput<GroupType *>(0); in0;
  Wz4Particles *out = (Wz4Particles *) cmd->Output;
  if(!out) { out=new Wz4Particles; cmd->Output=out; }

  {
#line 198 "tron_ops.ops"
			
    FR033_MeteorShowerSim *node = new FR033_MeteorShowerSim();
    node->ParaBase = *para;
    in0->AddRef();
    node->GroupLogos = in0;
    out->RootNode = node;
    out->AddCode(cmd); 
    node->Init();  
  ;
#line 685 "tron_ops.cpp"
    return 1;
  }
}

void Wz4ParticlesGuiFR033_MeteorShowerSim(wGridFrameHelper &gh,wOp *op)
{
  Wz4ParticlesParaFR033_MeteorShowerSim sUNUSED *para = (Wz4ParticlesParaFR033_MeteorShowerSim *)(op->EditData); para;

  gh.Group(L"Meteor Field");

  gh.Label(L"MF_Seed");
  sIntControl *int_MF_Seed = gh.Int(&para->MF_Seed,10,1000,1.000000f);
  int_MF_Seed->Default = 0x00000064; int_MF_Seed->RightStep = 0.125000f;

  gh.Label(L"MF_Count");
  sIntControl *int_MF_Count = gh.Int(&para->MF_Count,1,1000,1.000000f);
  int_MF_Count->Default = 0x00000064; int_MF_Count->RightStep = 0.125000f;

  gh.Label(L"MF_StartPos");
  gh.BeginTied();
  sFloatControl *float_MF_StartPos_0 = gh.Float(&para->MF_StartPos.x,-1024.00f,1024.000f,0.001000f);
  float_MF_StartPos_0->Default = 0.000000f; float_MF_StartPos_0->RightStep = 0.125000f;
  sFloatControl *float_MF_StartPos_1 = gh.Float(&para->MF_StartPos.y,-1024.00f,1024.000f,0.001000f);
  float_MF_StartPos_1->Default = 0.000000f; float_MF_StartPos_1->RightStep = 0.125000f;
  sFloatControl *float_MF_StartPos_2 = gh.Float(&para->MF_StartPos.z,-1024.00f,1024.000f,0.001000f);
  float_MF_StartPos_2->Default = 0.000000f; float_MF_StartPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"MF_RandPos");
  gh.BeginTied();
  sFloatControl *float_MF_RandPos_0 = gh.Float(&para->MF_RandPos.x,-1024.00f,1024.000f,0.001000f);
  float_MF_RandPos_0->Default = 0.000000f; float_MF_RandPos_0->RightStep = 0.125000f;
  sFloatControl *float_MF_RandPos_1 = gh.Float(&para->MF_RandPos.y,-1024.00f,1024.000f,0.001000f);
  float_MF_RandPos_1->Default = 0.000000f; float_MF_RandPos_1->RightStep = 0.125000f;
  sFloatControl *float_MF_RandPos_2 = gh.Float(&para->MF_RandPos.z,-1024.00f,1024.000f,0.001000f);
  float_MF_RandPos_2->Default = 0.000000f; float_MF_RandPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"MF_StartSpeed");
  gh.BeginTied();
  sFloatControl *float_MF_StartSpeed_0 = gh.Float(&para->MF_StartSpeed.x,-1024.00f,1024.000f,0.001000f);
  float_MF_StartSpeed_0->Default = 0.000000f; float_MF_StartSpeed_0->RightStep = 0.125000f;
  sFloatControl *float_MF_StartSpeed_1 = gh.Float(&para->MF_StartSpeed.y,-1024.00f,1024.000f,0.001000f);
  float_MF_StartSpeed_1->Default = 0.000000f; float_MF_StartSpeed_1->RightStep = 0.125000f;
  sFloatControl *float_MF_StartSpeed_2 = gh.Float(&para->MF_StartSpeed.z,-1024.00f,1024.000f,0.001000f);
  float_MF_StartSpeed_2->Default = 0.000000f; float_MF_StartSpeed_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"MF_RandSpeed");
  gh.BeginTied();
  sFloatControl *float_MF_RandSpeed_0 = gh.Float(&para->MF_RandSpeed.x,-1024.00f,1024.000f,0.001000f);
  float_MF_RandSpeed_0->Default = 0.000000f; float_MF_RandSpeed_0->RightStep = 0.125000f;
  sFloatControl *float_MF_RandSpeed_1 = gh.Float(&para->MF_RandSpeed.y,-1024.00f,1024.000f,0.001000f);
  float_MF_RandSpeed_1->Default = 0.000000f; float_MF_RandSpeed_1->RightStep = 0.125000f;
  sFloatControl *float_MF_RandSpeed_2 = gh.Float(&para->MF_RandSpeed.z,-1024.00f,1024.000f,0.001000f);
  float_MF_RandSpeed_2->Default = 0.000000f; float_MF_RandSpeed_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"MF_StartTime");
  sFloatControl *float_MF_StartTime = gh.Float(&para->MF_StartTime,0.000000f,1024.000f,0.000100f);
  float_MF_StartTime->Default = 0.000000f; float_MF_StartTime->RightStep = 0.125000f;

  gh.Label(L"MF_RandTime");
  sFloatControl *float_MF_RandTime = gh.Float(&para->MF_RandTime,0.000000f,1024.000f,0.000100f);
  float_MF_RandTime->Default = 0.000000f; float_MF_RandTime->RightStep = 0.125000f;

  gh.Label(L"MF_OnTime");
  sFloatControl *float_MF_OnTime = gh.Float(&para->MF_OnTime,0.000000f,1024.000f,0.010000f);
  float_MF_OnTime->Default = 0.100000f; float_MF_OnTime->RightStep = 0.125000f;

  gh.Label(L"MF_OffTime");
  sFloatControl *float_MF_OffTime = gh.Float(&para->MF_OffTime,0.000000f,1024.000f,0.010000f);
  float_MF_OffTime->Default = 0.100000f; float_MF_OffTime->RightStep = 0.125000f;
}

void Wz4ParticlesDefFR033_MeteorShowerSim(wOp *op)
{
  Wz4ParticlesParaFR033_MeteorShowerSim sUNUSED *para = (Wz4ParticlesParaFR033_MeteorShowerSim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->MF_Seed = 0x00000064;
  para->MF_Count = 0x00000064;
  para->MF_OnTime = 0.100000f;
  para->MF_OffTime = 0.100000f;
}

void Wz4ParticlesBindFR033_MeteorShowerSim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"mf_seed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"mf_count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"mf_startpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"mf_startpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"mf_startpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"mf_startspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"mf_startspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"mf_startspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randspeed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"mf_starttime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"mf_randtime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"mf_ontime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"mf_offtime"),val);
}
void Wz4ParticlesBind2FR033_MeteorShowerSim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[11];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"");
    name[1] = sPoolString(L"mf_seed");
    name[2] = sPoolString(L"mf_count");
    name[3] = sPoolString(L"mf_startpos");
    name[4] = sPoolString(L"mf_randpos");
    name[5] = sPoolString(L"mf_startspeed");
    name[6] = sPoolString(L"mf_randspeed");
    name[7] = sPoolString(L"mf_starttime");
    name[8] = sPoolString(L"mf_randtime");
    name[9] = sPoolString(L"mf_ontime");
    name[10] = sPoolString(L"mf_offtime");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+11);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+17);
}
void Wz4ParticlesBind3FR033_MeteorShowerSim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import mf_seed : int;\n");
  tb.PrintF(L"  import mf_count : int;\n");
  tb.PrintF(L"  import mf_startpos : float[3];\n");
  tb.PrintF(L"  import mf_randpos : float[3];\n");
  tb.PrintF(L"  import mf_startspeed : float[3];\n");
  tb.PrintF(L"  import mf_randspeed : float[3];\n");
  tb.PrintF(L"  import mf_starttime : float;\n");
  tb.PrintF(L"  import mf_randtime : float;\n");
  tb.PrintF(L"  import mf_ontime : float;\n");
  tb.PrintF(L"  import mf_offtime : float;\n");
}
const sChar *Wz4ParticlesWikiFR033_MeteorShowerSim =
L"= Wz4Particles : FR033_MeteorShowerSim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR033_MeteorShowerSim\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4Particles\n"
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
L" !i GroupType\n"
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
L" !i MF_Seed\n"
L" !i MF_Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MF_Count\n"
L" !i MF_Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MF_StartPos\n"
L" !i MF_StartPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i MF_RandPos\n"
L" !i MF_RandPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i MF_StartSpeed\n"
L" !i MF_StartSpeed\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i MF_RandSpeed\n"
L" !i MF_RandSpeed\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i MF_StartTime\n"
L" !i MF_StartTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MF_RandTime\n"
L" !i MF_RandTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MF_OnTime\n"
L" !i MF_OnTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MF_OffTime\n"
L" !i MF_OffTime\n"
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

sBool Wz4RenderCmdFR033_WaterSimRender(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFR033_WaterSimRender sUNUSED *para = (Wz4RenderParaFR033_WaterSimRender *)(cmd->Data); para;
  Wz4Mtrl sUNUSED *in0 = cmd->GetInput<Wz4Mtrl *>(0); in0;
  Texture2D sUNUSED *in1 = cmd->GetInput<Texture2D *>(1); in1;
  Wz4Particles sUNUSED *in2 = cmd->GetInput<Wz4Particles *>(2); in2;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 240 "tron_ops.ops"
			
    FR033_WaterSimRender *node = new FR033_WaterSimRender();
    node->ParaBase = *para;
    in0->AddRef();    
    in1->AddRef();
    in2->AddRef();
    node->WaterMtrl = in0;
    node->Dancer = in1;
    node->MeteorSim = in2;

    node->Init();  

    out->RootNode = node;
    out->AddCode(cmd,0); 
  ;
#line 993 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFR033_WaterSimRender(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFR033_WaterSimRender sUNUSED *para = (Wz4RenderParaFR033_WaterSimRender *)(op->EditData); para;

  gh.Group(L"Water Grid");

  gh.Label(L"WG_VertXZ");
  gh.BeginTied();
  sIntControl *int_WG_VertXZ_0 = gh.Int(&para->WG_VertXZ[0],10,1000,1.000000f);
  int_WG_VertXZ_0->Default = 0x00000064; int_WG_VertXZ_0->RightStep = 0.125000f;
  sIntControl *int_WG_VertXZ_1 = gh.Int(&para->WG_VertXZ[1],10,1000,1.000000f);
  int_WG_VertXZ_1->Default = 0x00000064; int_WG_VertXZ_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"WG_Pos");
  gh.BeginTied();
  sFloatControl *float_WG_Pos_0 = gh.Float(&para->WG_Pos.x,-1024.00f,1024.000f,0.001000f);
  float_WG_Pos_0->Default = 0.000000f; float_WG_Pos_0->RightStep = 0.125000f;
  sFloatControl *float_WG_Pos_1 = gh.Float(&para->WG_Pos.y,-1024.00f,1024.000f,0.001000f);
  float_WG_Pos_1->Default = 0.000000f; float_WG_Pos_1->RightStep = 0.125000f;
  sFloatControl *float_WG_Pos_2 = gh.Float(&para->WG_Pos.z,-1024.00f,1024.000f,0.001000f);
  float_WG_Pos_2->Default = 0.000000f; float_WG_Pos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"WG_SizeXZ");
  gh.BeginTied();
  sFloatControl *float_WG_SizeXZ_0 = gh.Float(&para->WG_SizeXZ[0],0.001000f,1024.000f,0.001000f);
  float_WG_SizeXZ_0->Default = 1.000000f; float_WG_SizeXZ_0->RightStep = 0.125000f;
  sFloatControl *float_WG_SizeXZ_1 = gh.Float(&para->WG_SizeXZ[1],0.001000f,1024.000f,0.001000f);
  float_WG_SizeXZ_1->Default = 1.000000f; float_WG_SizeXZ_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"WG_ScaleUV");
  gh.BeginTied();
  sFloatControl *float_WG_ScaleUV_0 = gh.Float(&para->WG_ScaleUV[0],-1024.00f,1024.000f,0.001000f);
  float_WG_ScaleUV_0->Default = 1.000000f; float_WG_ScaleUV_0->RightStep = 0.125000f;
  sFloatControl *float_WG_ScaleUV_1 = gh.Float(&para->WG_ScaleUV[1],-1024.00f,1024.000f,0.001000f);
  float_WG_ScaleUV_1->Default = 1.000000f; float_WG_ScaleUV_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"WG_OffsetUV");
  gh.BeginTied();
  sFloatControl *float_WG_OffsetUV_0 = gh.Float(&para->WG_OffsetUV[0],-1024.00f,1024.000f,0.000100f);
  float_WG_OffsetUV_0->Default = 0.000000f; float_WG_OffsetUV_0->RightStep = 0.125000f;
  sFloatControl *float_WG_OffsetUV_1 = gh.Float(&para->WG_OffsetUV[1],-1024.00f,1024.000f,0.000100f);
  float_WG_OffsetUV_1->Default = 0.000000f; float_WG_OffsetUV_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Water Sim");

  gh.Label(L"WS_Amplitude");
  sFloatControl *float_WS_Amplitude = gh.Float(&para->WS_Amplitude,0.001000f,1024.000f,0.001000f);
  float_WS_Amplitude->Default = 1.000000f; float_WS_Amplitude->RightStep = 0.125000f;

  gh.Label(L"WS_DampingTime");
  sFloatControl *float_WS_DampingTime = gh.Float(&para->WS_DampingTime,0.001000f,1024.000f,0.001000f);
  float_WS_DampingTime->Default = 1.000000f; float_WS_DampingTime->RightStep = 0.125000f;

  gh.Label(L"WS_DampingExpansion");
  sFloatControl *float_WS_DampingExpansion = gh.Float(&para->WS_DampingExpansion,0.001000f,1024.000f,0.001000f);
  float_WS_DampingExpansion->Default = 1.000000f; float_WS_DampingExpansion->RightStep = 0.125000f;

  gh.Label(L"WS_Freq");
  sFloatControl *float_WS_Freq = gh.Float(&para->WS_Freq,0.001000f,1024.000f,0.001000f);
  float_WS_Freq->Default = 1.000000f; float_WS_Freq->RightStep = 0.125000f;

  gh.Label(L"WS_FreqTime");
  sFloatControl *float_WS_FreqTime = gh.Float(&para->WS_FreqTime,0.001000f,1024.000f,0.001000f);
  float_WS_FreqTime->Default = 1.000000f; float_WS_FreqTime->RightStep = 0.125000f;

  gh.Label(L"WS_FreqExpansion");
  sFloatControl *float_WS_FreqExpansion = gh.Float(&para->WS_FreqExpansion,0.001000f,1024.000f,0.001000f);
  float_WS_FreqExpansion->Default = 1.000000f; float_WS_FreqExpansion->RightStep = 0.125000f;

  gh.Group(L"Dancer Para");

  gh.Label(L"DP_Seed");
  sIntControl *int_DP_Seed = gh.Int(&para->DP_Seed,10,1000,1.000000f);
  int_DP_Seed->Default = 0x00000064; int_DP_Seed->RightStep = 0.125000f;

  gh.Label(L"DP_Count");
  sIntControl *int_DP_Count = gh.Int(&para->DP_Count,1,10000,1.000000f);
  int_DP_Count->Default = 0x00000064; int_DP_Count->RightStep = 0.125000f;

  gh.Label(L"DP_Scale");
  gh.BeginTied();
  sFloatControl *float_DP_Scale_0 = gh.Float(&para->DP_Scale[0],0.001000f,1024.000f,0.001000f);
  float_DP_Scale_0->Default = 1.000000f; float_DP_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_DP_Scale_1 = gh.Float(&para->DP_Scale[1],0.001000f,1024.000f,0.001000f);
  float_DP_Scale_1->Default = 1.000000f; float_DP_Scale_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"DP_RandScale");
  gh.BeginTied();
  sFloatControl *float_DP_RandScale_0 = gh.Float(&para->DP_RandScale[0],0.001000f,1024.000f,0.001000f);
  float_DP_RandScale_0->Default = 0.000000f; float_DP_RandScale_0->RightStep = 0.125000f;
  sFloatControl *float_DP_RandScale_1 = gh.Float(&para->DP_RandScale[1],0.001000f,1024.000f,0.001000f);
  float_DP_RandScale_1->Default = 0.000000f; float_DP_RandScale_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"DP_StartPos");
  gh.BeginTied();
  sFloatControl *float_DP_StartPos_0 = gh.Float(&para->DP_StartPos[0],0.001000f,1024.000f,0.001000f);
  float_DP_StartPos_0->Default = 0.000000f; float_DP_StartPos_0->RightStep = 0.125000f;
  sFloatControl *float_DP_StartPos_1 = gh.Float(&para->DP_StartPos[1],0.001000f,1024.000f,0.001000f);
  float_DP_StartPos_1->Default = 0.000000f; float_DP_StartPos_1->RightStep = 0.125000f;
  sFloatControl *float_DP_StartPos_2 = gh.Float(&para->DP_StartPos[2],0.001000f,1024.000f,0.001000f);
  float_DP_StartPos_2->Default = 0.000000f; float_DP_StartPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"DP_DimXZ");
  gh.BeginTied();
  sFloatControl *float_DP_DimXZ_0 = gh.Float(&para->DP_DimXZ[0],0.001000f,1024.000f,0.001000f);
  float_DP_DimXZ_0->Default = 1.000000f; float_DP_DimXZ_0->RightStep = 0.125000f;
  sFloatControl *float_DP_DimXZ_1 = gh.Float(&para->DP_DimXZ[1],0.001000f,1024.000f,0.001000f);
  float_DP_DimXZ_1->Default = 1.000000f; float_DP_DimXZ_1->RightStep = 0.125000f;
  gh.EndTied();
}

void Wz4RenderDefFR033_WaterSimRender(wOp *op)
{
  Wz4RenderParaFR033_WaterSimRender sUNUSED *para = (Wz4RenderParaFR033_WaterSimRender *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->WG_VertXZ[0] = 0x00000064;
  para->WG_VertXZ[1] = 0x00000064;
  para->WG_SizeXZ[0] = 1.000000f;
  para->WG_SizeXZ[1] = 1.000000f;
  para->WG_ScaleUV[0] = 1.000000f;
  para->WG_ScaleUV[1] = 1.000000f;
  para->WS_Amplitude = 1.000000f;
  para->WS_DampingTime = 1.000000f;
  para->WS_DampingExpansion = 1.000000f;
  para->WS_Freq = 1.000000f;
  para->WS_FreqTime = 1.000000f;
  para->WS_FreqExpansion = 1.000000f;
  para->DP_Seed = 0x00000064;
  para->DP_Count = 0x00000064;
  para->DP_Scale[0] = 1.000000f;
  para->DP_Scale[1] = 1.000000f;
  para->DP_DimXZ[0] = 1.000000f;
  para->DP_DimXZ[1] = 1.000000f;
}

void Wz4RenderBindFR033_WaterSimRender(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"wg_vertxz"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"wg_vertxz"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"wg_pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"wg_pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"wg_pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"wg_sizexz"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"wg_sizexz"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"wg_scaleuv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"wg_scaleuv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"wg_offsetuv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"wg_offsetuv"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"ws_amplitude"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"ws_dampingtime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"ws_dampingexpansion"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"ws_freq"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+15;
  ctx->BindLocal(ctx->AddSymbol(L"ws_freqtime"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"ws_freqexpansion"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"dp_seed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"dp_count"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"dp_scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"dp_scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"dp_randscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"dp_randscale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"dp_startpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"dp_startpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"dp_startpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"dp_dimxz"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"dp_dimxz"),val);
}
void Wz4RenderBind2FR033_WaterSimRender(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[20];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"");
    name[1] = sPoolString(L"wg_vertxz");
    name[2] = sPoolString(L"wg_pos");
    name[3] = sPoolString(L"wg_sizexz");
    name[4] = sPoolString(L"wg_scaleuv");
    name[5] = sPoolString(L"wg_offsetuv");
    name[6] = sPoolString(L"");
    name[7] = sPoolString(L"ws_amplitude");
    name[8] = sPoolString(L"ws_dampingtime");
    name[9] = sPoolString(L"ws_dampingexpansion");
    name[10] = sPoolString(L"ws_freq");
    name[11] = sPoolString(L"ws_freqtime");
    name[12] = sPoolString(L"ws_freqexpansion");
    name[13] = sPoolString(L"");
    name[14] = sPoolString(L"dp_seed");
    name[15] = sPoolString(L"dp_count");
    name[16] = sPoolString(L"dp_scale");
    name[17] = sPoolString(L"dp_randscale");
    name[18] = sPoolString(L"dp_startpos");
    name[19] = sPoolString(L"dp_dimxz");
  }
  ctx->AddImport(name[1],ScriptTypeInt,2,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,2,cmd->Data+5);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,2,cmd->Data+9);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+13);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+14);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+15);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+16);
  ctx->AddImport(name[14],ScriptTypeInt,1,cmd->Data+17);
  ctx->AddImport(name[15],ScriptTypeInt,1,cmd->Data+18);
  ctx->AddImport(name[16],ScriptTypeFloat,2,cmd->Data+19);
  ctx->AddImport(name[17],ScriptTypeFloat,2,cmd->Data+21);
  ctx->AddImport(name[18],ScriptTypeFloat,3,cmd->Data+23);
  ctx->AddImport(name[19],ScriptTypeFloat,2,cmd->Data+26);
}
void Wz4RenderBind3FR033_WaterSimRender(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import wg_vertxz : int[2];\n");
  tb.PrintF(L"  import wg_pos : float[3];\n");
  tb.PrintF(L"  import wg_sizexz : float[2];\n");
  tb.PrintF(L"  import wg_scaleuv : float[2];\n");
  tb.PrintF(L"  import wg_offsetuv : float[2];\n");
  tb.PrintF(L"  import ws_amplitude : float;\n");
  tb.PrintF(L"  import ws_dampingtime : float;\n");
  tb.PrintF(L"  import ws_dampingexpansion : float;\n");
  tb.PrintF(L"  import ws_freq : float;\n");
  tb.PrintF(L"  import ws_freqtime : float;\n");
  tb.PrintF(L"  import ws_freqexpansion : float;\n");
  tb.PrintF(L"  import dp_seed : int;\n");
  tb.PrintF(L"  import dp_count : int;\n");
  tb.PrintF(L"  import dp_scale : float[2];\n");
  tb.PrintF(L"  import dp_randscale : float[2];\n");
  tb.PrintF(L"  import dp_startpos : float[3];\n");
  tb.PrintF(L"  import dp_dimxz : float[2];\n");
}
const sChar *Wz4RenderWikiFR033_WaterSimRender =
L"= Wz4Render : FR033_WaterSimRender\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FR033_WaterSimRender\n"
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
L" !i\n"
L" !i *\n"
L"\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i Wz4Particles\n"
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
L" !i WG_VertXZ\n"
L" !i WG_VertXZ\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i WG_Pos\n"
L" !i WG_Pos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i WG_SizeXZ\n"
L" !i WG_SizeXZ\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i WG_ScaleUV\n"
L" !i WG_ScaleUV\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i WG_OffsetUV\n"
L" !i WG_OffsetUV\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i WS_Amplitude\n"
L" !i WS_Amplitude\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WS_DampingTime\n"
L" !i WS_DampingTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WS_DampingExpansion\n"
L" !i WS_DampingExpansion\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WS_Freq\n"
L" !i WS_Freq\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WS_FreqTime\n"
L" !i WS_FreqTime\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i WS_FreqExpansion\n"
L" !i WS_FreqExpansion\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i DP_Seed\n"
L" !i DP_Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i DP_Count\n"
L" !i DP_Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i DP_Scale\n"
L" !i DP_Scale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i DP_RandScale\n"
L" !i DP_RandScale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i DP_StartPos\n"
L" !i DP_StartPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i DP_DimXZ\n"
L" !i DP_DimXZ\n"
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

sBool Wz4RenderCmdSharpen(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSharpen sUNUSED *para = (Wz4RenderParaSharpen *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 270 "tron_ops.ops"

    RNSharpen *node = new RNSharpen();
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 1448 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSharpen(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSharpen sUNUSED *para = (Wz4RenderParaSharpen *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Strength");
  sFloatControl *float_Strength = gh.Float(&para->Strength,0.000000f,9.990000f,0.100000f);
  float_Strength->Default = 2.000000f; float_Strength->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefSharpen(wOp *op)
{
  Wz4RenderParaSharpen sUNUSED *para = (Wz4RenderParaSharpen *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Strength = 2.000000f;
}

void Wz4RenderBindSharpen(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"strength"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Sharpen(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"strength");
    name[1] = sPoolString(L"");
    name[2] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Sharpen(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import strength : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiSharpen =
L"= Wz4Render : Sharpen\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sharpen\n"
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
L" !i Strength\n"
L" !i Strength\n"
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

sBool Wz4RenderCmdSBlur(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaSBlur sUNUSED *para = (Wz4RenderParaSBlur *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 291 "tron_ops.ops"

    RNSBlur *node = new RNSBlur();
    node->ParaBase = *para;
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 1578 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiSBlur(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaSBlur sUNUSED *para = (Wz4RenderParaSBlur *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,1.000000f,4096.000f,0.010000f);
  float_Radius->Default = 1.000000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Amp");
  sFloatControl *float_Amp = gh.Float(&para->Amp,0.000000f,256.0000f,0.010000f);
  float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;

  gh.Label(L"Intensity");
  sFloatControl *float_Intensity = gh.Float(&para->Intensity,0.000000f,999.9901f,0.100000f);
  float_Intensity->Default = 3.000000f; float_Intensity->RightStep = 0.125000f;
}

void Wz4RenderDefSBlur(wOp *op)
{
  Wz4RenderParaSBlur sUNUSED *para = (Wz4RenderParaSBlur *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Radius = 1.000000f;
  para->Amp = 1.000000f;
  para->Intensity = 3.000000f;
}

void Wz4RenderBindSBlur(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"intensity"),val);
}
void Wz4RenderBind2SBlur(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"radius");
    name[1] = sPoolString(L"amp");
    name[2] = sPoolString(L"intensity");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void Wz4RenderBind3SBlur(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import radius : float;\n");
  tb.PrintF(L"  import amp : float;\n");
  tb.PrintF(L"  import intensity : float;\n");
}
const sChar *Wz4RenderWikiSBlur =
L"= Wz4Render : SBlur\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SBlur\n"
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
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Intensity\n"
L" !i Intensity\n"
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

sBool Wz4RenderCmdBloom(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaBloom sUNUSED *para = (Wz4RenderParaBloom *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 370 "tron_ops.ops"

    RNBloom *node = new RNBloom();
    node->ParaBase = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 1720 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiBloom(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaBloom sUNUSED *para = (Wz4RenderParaBloom *)(op->EditData); para;

  gh.Group(L"GrayMask");

  gh.Label(L"screen size");
  gh.Flags(&para->CalcMaskFromScreen,L"*2half|full|quarter",gh.ChangeMsg);

  gh.Label(L"CalcMaskFromScreen");
  gh.Flags(&para->CalcMaskFromScreen,L"Off|On",gh.LayoutMsg);

  if((para->CalcMaskFromScreen&0x0001))
  {
    gh.Label(L"Signed MaskCol");
    gh.Flags(&para->CalcMaskFromScreen,L"*1off|on",gh.ChangeMsg);

    gh.Label(L"* HighlightCol");
    gh.ColorPick(&para->HighlightCol,L"rgba",0);

    gh.Label(L"* MaskCol");
    gh.ColorPick(&para->MaskCol,L"rgba",0);

    gh.Label(L"* MaskAmp");
    sFloatControl *float_MaskAmp = gh.Float(&para->MaskAmp,-1024.00f,1024.000f,0.001000f);
    float_MaskAmp->Default = 1.000000f; float_MaskAmp->RightStep = 0.125000f;

    gh.Label(L"* MaskBias");
    sFloatControl *float_MaskBias = gh.Float(&para->MaskBias,-1024.00f,1024.000f,0.001000f);
    float_MaskBias->Default = 0.000000f; float_MaskBias->RightStep = 0.125000f;

  }
  gh.Label(L"UseAlpha");
  gh.Flags(&para->UseAlpha,L"Off|On",gh.LayoutMsg);

  if((para->UseAlpha==0x0001))
  {
    gh.Label(L"* AlphaAmp");
    sFloatControl *float_AlphaAmp = gh.Float(&para->AlphaAmp,-1024.00f,1024.000f,0.001000f);
    float_AlphaAmp->Default = 1.000000f; float_AlphaAmp->RightStep = 0.125000f;

    gh.Label(L"* AlphaBias");
    sFloatControl *float_AlphaBias = gh.Float(&para->AlphaBias,-1024.00f,1024.000f,0.001000f);
    float_AlphaBias->Default = 0.000000f; float_AlphaBias->RightStep = 0.125000f;

  }
  gh.Label(L"UseZBuf");
  gh.Flags(&para->UseZBuf,L"Off|On",gh.LayoutMsg);

  if((para->UseZBuf==0x0001))
  {
    gh.Label(L"* ZBufAmp");
    sFloatControl *float_ZBufAmp = gh.Float(&para->ZBufAmp,-1024.00f,1024.000f,0.001000f);
    float_ZBufAmp->Default = 1.000000f; float_ZBufAmp->RightStep = 0.125000f;

    gh.Label(L"* ZBufBias");
    sFloatControl *float_ZBufBias = gh.Float(&para->ZBufBias,-1024.00f,1024.000f,0.001000f);
    float_ZBufBias->Default = 0.000000f; float_ZBufBias->RightStep = 0.125000f;

  }
  gh.Label(L"MultiplyScreenCol");
  gh.Flags(&para->MultiplyScreenCol,L"Off|On",gh.LayoutMsg);

  if((para->MultiplyScreenCol==0x0001))
  {
    gh.Label(L"* BlendFactor");
    gh.BeginTied();
    sFloatControl *float_BlendFactor_0 = gh.Float(&para->BlendFactor.x,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_0->Default = 0.500000f; float_BlendFactor_0->RightStep = 0.125000f;
    sFloatControl *float_BlendFactor_1 = gh.Float(&para->BlendFactor.y,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_1->Default = 0.500000f; float_BlendFactor_1->RightStep = 0.125000f;
    sFloatControl *float_BlendFactor_2 = gh.Float(&para->BlendFactor.z,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_2->Default = 0.500000f; float_BlendFactor_2->RightStep = 0.125000f;
    sFloatControl *float_BlendFactor_3 = gh.Float(&para->BlendFactor.w,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_3->Default = 0.500000f; float_BlendFactor_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"* GrayMaskCol");
  gh.ColorPick(&para->GrayMaskCol,L"rgba",0);

  gh.Label(L"* GrayMaskAmp");
  sFloatControl *float_GrayMaskAmp = gh.Float(&para->GrayMaskAmp,-1024.00f,1024.000f,0.001000f);
  float_GrayMaskAmp->Default = 1.000000f; float_GrayMaskAmp->RightStep = 0.125000f;

  gh.Label(L"* GrayMaskBias");
  sFloatControl *float_GrayMaskBias = gh.Float(&para->GrayMaskBias,-1024.00f,1024.000f,0.001000f);
  float_GrayMaskBias->Default = 0.000000f; float_GrayMaskBias->RightStep = 0.125000f;

  gh.Group(L"Blur");

  gh.Label(L"* BlurRadius");
  sFloatControl *float_BlurRadius = gh.Float(&para->BlurRadius,1.000000f,4096.000f,0.010000f);
  float_BlurRadius->Default = 50.00000f; float_BlurRadius->RightStep = 0.125000f;

  gh.Label(L"* BlurAmp");
  sFloatControl *float_BlurAmp = gh.Float(&para->BlurAmp,0.000000f,256.0000f,0.001000f);
  float_BlurAmp->Default = 1.000000f; float_BlurAmp->RightStep = 0.125000f;

  gh.Group(L"Composition");

  gh.Label(L"* CompBloomCol");
  gh.ColorPick(&para->CompBloomCol,L"rgba",0);

  gh.Label(L"* CompBloomAmp");
  sFloatControl *float_CompBloomAmp = gh.Float(&para->CompBloomAmp,-1024.00f,1024.000f,0.001000f);
  float_CompBloomAmp->Default = 0.000000f; float_CompBloomAmp->RightStep = 0.125000f;

  gh.Label(L"* CompScreenCol");
  gh.ColorPick(&para->CompScreenCol,L"rgba",0);

  gh.Label(L"* CompScreenAmp");
  sFloatControl *float_CompScreenAmp = gh.Float(&para->CompScreenAmp,-1024.00f,1024.000f,0.001000f);
  float_CompScreenAmp->Default = 1.000000f; float_CompScreenAmp->RightStep = 0.125000f;

  gh.Label(L"CompFormula");
  gh.Flags(&para->CompFormula,L"Add|Screen|Mul",gh.LayoutMsg);

  gh.Group(L"Debug:");

  gh.Label(L"DebugShow");
  gh.Flags(&para->DebugShow,L"Result|Mask|Blur",gh.LayoutMsg);

  gh.Group(L"Pre HighlightCol Blur");

  gh.Label(L"PreBlurMode");
  gh.Flags(&para->PreBlurMode,L"off| 5 Tap| 9 Tap",gh.ChangeMsg);

  gh.Label(L"* PreBlurSize");
  sFloatControl *float_PreBlurSize = gh.Float(&para->PreBlurSize,0.000000f,16.00000f,0.010000f);
  float_PreBlurSize->Default = 2.000000f; float_PreBlurSize->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefBloom(wOp *op)
{
  Wz4RenderParaBloom sUNUSED *para = (Wz4RenderParaBloom *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->MaskCol = 0xffffffff;
  para->MaskAmp = 1.000000f;
  para->AlphaAmp = 1.000000f;
  para->ZBufAmp = 1.000000f;
  para->BlendFactor.x = 0.500000f;
  para->BlendFactor.y = 0.500000f;
  para->BlendFactor.z = 0.500000f;
  para->BlendFactor.w = 0.500000f;
  para->GrayMaskCol = 0xffffffff;
  para->GrayMaskAmp = 1.000000f;
  para->BlurRadius = 50.00000f;
  para->BlurAmp = 1.000000f;
  para->CompBloomCol = 0xffffffff;
  para->CompScreenCol = 0xffffffff;
  para->CompScreenAmp = 1.000000f;
  para->PreBlurSize = 2.000000f;
}

void Wz4RenderBindBloom(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"highlightcol"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"maskcol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"maskamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"maskbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"alphaamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"alphabias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"zbufamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"zbufbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"graymaskcol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"graymaskamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"graymaskbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"blurradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"bluramp"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"compbloomcol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"compbloomamp"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"compscreencol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"compscreenamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+28;
  ctx->BindLocal(ctx->AddSymbol(L"preblursize"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Bloom(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[35];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"graymask");
    name[1] = sPoolString(L"calcmaskfromscreen");
    name[2] = sPoolString(L"calcmaskfromscreen");
    name[3] = sPoolString(L"calcmaskfromscreen");
    name[4] = sPoolString(L"highlightcol");
    name[5] = sPoolString(L"maskcol");
    name[6] = sPoolString(L"maskamp");
    name[7] = sPoolString(L"maskbias");
    name[8] = sPoolString(L"usealpha");
    name[9] = sPoolString(L"alphaamp");
    name[10] = sPoolString(L"alphabias");
    name[11] = sPoolString(L"usezbuf");
    name[12] = sPoolString(L"zbufamp");
    name[13] = sPoolString(L"zbufbias");
    name[14] = sPoolString(L"multiplyscreencol");
    name[15] = sPoolString(L"blendfactor");
    name[16] = sPoolString(L"graymaskcol");
    name[17] = sPoolString(L"graymaskamp");
    name[18] = sPoolString(L"graymaskbias");
    name[19] = sPoolString(L"blur");
    name[20] = sPoolString(L"blurradius");
    name[21] = sPoolString(L"bluramp");
    name[22] = sPoolString(L"composition");
    name[23] = sPoolString(L"compbloomcol");
    name[24] = sPoolString(L"compbloomamp");
    name[25] = sPoolString(L"compscreencol");
    name[26] = sPoolString(L"compscreenamp");
    name[27] = sPoolString(L"compformula");
    name[28] = sPoolString(L"");
    name[29] = sPoolString(L"debugshow");
    name[30] = sPoolString(L"");
    name[31] = sPoolString(L"preblurmode");
    name[32] = sPoolString(L"preblursize");
    name[33] = sPoolString(L"");
    name[34] = sPoolString(L"script");
  }
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[5],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[13],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[15],ScriptTypeFloat,4,cmd->Data+12);
  ctx->AddImport(name[16],ScriptTypeColor,1,cmd->Data+16);
  ctx->AddImport(name[17],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[20],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[23],ScriptTypeColor,1,cmd->Data+21);
  ctx->AddImport(name[24],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[25],ScriptTypeColor,1,cmd->Data+23);
  ctx->AddImport(name[26],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[32],ScriptTypeFloat,1,cmd->Data+28);
  ctx->AddImport(name[34],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Bloom(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import highlightcol : color;\n");
  tb.PrintF(L"  import maskcol : color;\n");
  tb.PrintF(L"  import maskamp : float;\n");
  tb.PrintF(L"  import maskbias : float;\n");
  tb.PrintF(L"  import alphaamp : float;\n");
  tb.PrintF(L"  import alphabias : float;\n");
  tb.PrintF(L"  import zbufamp : float;\n");
  tb.PrintF(L"  import zbufbias : float;\n");
  tb.PrintF(L"  import blendfactor : float[4];\n");
  tb.PrintF(L"  import graymaskcol : color;\n");
  tb.PrintF(L"  import graymaskamp : float;\n");
  tb.PrintF(L"  import graymaskbias : float;\n");
  tb.PrintF(L"  import blurradius : float;\n");
  tb.PrintF(L"  import bluramp : float;\n");
  tb.PrintF(L"  import compbloomcol : color;\n");
  tb.PrintF(L"  import compbloomamp : float;\n");
  tb.PrintF(L"  import compscreencol : color;\n");
  tb.PrintF(L"  import compscreenamp : float;\n");
  tb.PrintF(L"  import preblursize : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiBloom =
L"= Wz4Render : Bloom\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bloom\n"
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
L" !i screen size\n"
L" !i CalcMaskFromScreen\n"
L" !i half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i full\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i quarter\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CalcMaskFromScreen\n"
L" !i CalcMaskFromScreen\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Signed MaskCol\n"
L" !i CalcMaskFromScreen\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i on\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i HighlightCol\n"
L" !i HighlightCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MaskCol\n"
L" !i MaskCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MaskAmp\n"
L" !i MaskAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaskBias\n"
L" !i MaskBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i UseAlpha\n"
L" !i UseAlpha\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i AlphaAmp\n"
L" !i AlphaAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AlphaBias\n"
L" !i AlphaBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i UseZBuf\n"
L" !i UseZBuf\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ZBufAmp\n"
L" !i ZBufAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ZBufBias\n"
L" !i ZBufBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i MultiplyScreenCol\n"
L" !i MultiplyScreenCol\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i BlendFactor\n"
L" !i BlendFactor\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i GrayMaskCol\n"
L" !i GrayMaskCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i GrayMaskAmp\n"
L" !i GrayMaskAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GrayMaskBias\n"
L" !i GrayMaskBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurRadius\n"
L" !i BlurRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurAmp\n"
L" !i BlurAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CompBloomCol\n"
L" !i CompBloomCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i CompBloomAmp\n"
L" !i CompBloomAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CompScreenCol\n"
L" !i CompScreenCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i CompScreenAmp\n"
L" !i CompScreenAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i CompFormula\n"
L" !i CompFormula\n"
L" !i Add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Mul\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugShow\n"
L" !i DebugShow\n"
L" !i Result\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Mask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Blur\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L"!T 4 : 1 1 1 2\n"
L" !i PreBlurMode\n"
L" !i PreBlurMode\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5 Tap\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 9 Tap\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i PreBlurSize\n"
L" !i PreBlurSize\n"
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

sBool Wz4RenderCmdPromist(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaPromist sUNUSED *para = (Wz4RenderParaPromist *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 444 "tron_ops.ops"

    RNPromist *node = new RNPromist();
    node->ParaBase = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 2314 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiPromist(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaPromist sUNUSED *para = (Wz4RenderParaPromist *)(op->EditData); para;

  gh.Group(L"GrayMask");

  gh.Label(L"CalcMaskFromScreen");
  gh.Flags(&para->CalcMaskFromScreen,L"Off|On",gh.LayoutMsg);

  if((para->CalcMaskFromScreen==0x0001))
  {
    gh.Label(L"* HighlightCol");
    gh.ColorPick(&para->HighlightCol,L"rgba",0);

    gh.Label(L"* MaskCol");
    gh.ColorPick(&para->MaskCol,L"rgba",0);

    gh.Label(L"* MaskAmp");
    sFloatControl *float_MaskAmp = gh.Float(&para->MaskAmp,-1024.00f,1024.000f,0.001000f);
    float_MaskAmp->Default = 1.000000f; float_MaskAmp->RightStep = 0.125000f;

    gh.Label(L"* MaskBias");
    sFloatControl *float_MaskBias = gh.Float(&para->MaskBias,-1024.00f,1024.000f,0.001000f);
    float_MaskBias->Default = 0.000000f; float_MaskBias->RightStep = 0.125000f;

  }
  gh.Label(L"UseAlpha");
  gh.Flags(&para->UseAlpha,L"Off|On",gh.LayoutMsg);

  if((para->UseAlpha==0x0001))
  {
    gh.Label(L"* AlphaAmp");
    sFloatControl *float_AlphaAmp = gh.Float(&para->AlphaAmp,-1024.00f,1024.000f,0.001000f);
    float_AlphaAmp->Default = 1.000000f; float_AlphaAmp->RightStep = 0.125000f;

    gh.Label(L"* AlphaBias");
    sFloatControl *float_AlphaBias = gh.Float(&para->AlphaBias,-1024.00f,1024.000f,0.001000f);
    float_AlphaBias->Default = 0.000000f; float_AlphaBias->RightStep = 0.125000f;

  }
  gh.Label(L"UseZBuf");
  gh.Flags(&para->UseZBuf,L"Off|On",gh.LayoutMsg);

  if((para->UseZBuf==0x0001))
  {
    gh.Label(L"* ZBufAmp");
    sFloatControl *float_ZBufAmp = gh.Float(&para->ZBufAmp,-1024.00f,1024.000f,0.001000f);
    float_ZBufAmp->Default = 1.000000f; float_ZBufAmp->RightStep = 0.125000f;

    gh.Label(L"* ZBufBias");
    sFloatControl *float_ZBufBias = gh.Float(&para->ZBufBias,-1024.00f,1024.000f,0.001000f);
    float_ZBufBias->Default = 0.000000f; float_ZBufBias->RightStep = 0.125000f;

  }
  gh.Label(L"MultiplyScreenCol");
  gh.Flags(&para->MultiplyScreenCol,L"Off|On",gh.LayoutMsg);

  if((para->MultiplyScreenCol==0x0001))
  {
    gh.Label(L"* BlendFactor");
    gh.BeginTied();
    sFloatControl *float_BlendFactor_0 = gh.Float(&para->BlendFactor.x,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_0->Default = 0.500000f; float_BlendFactor_0->RightStep = 0.125000f;
    sFloatControl *float_BlendFactor_1 = gh.Float(&para->BlendFactor.y,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_1->Default = 0.500000f; float_BlendFactor_1->RightStep = 0.125000f;
    sFloatControl *float_BlendFactor_2 = gh.Float(&para->BlendFactor.z,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_2->Default = 0.500000f; float_BlendFactor_2->RightStep = 0.125000f;
    sFloatControl *float_BlendFactor_3 = gh.Float(&para->BlendFactor.w,0.000000f,1.000000f,0.001000f);
    float_BlendFactor_3->Default = 0.500000f; float_BlendFactor_3->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"* GrayMaskCol");
  gh.ColorPick(&para->GrayMaskCol,L"rgba",0);

  gh.Label(L"* GrayMaskAmp");
  sFloatControl *float_GrayMaskAmp = gh.Float(&para->GrayMaskAmp,-1024.00f,1024.000f,0.001000f);
  float_GrayMaskAmp->Default = 1.000000f; float_GrayMaskAmp->RightStep = 0.125000f;

  gh.Label(L"* GrayMaskBias");
  sFloatControl *float_GrayMaskBias = gh.Float(&para->GrayMaskBias,-1024.00f,1024.000f,0.001000f);
  float_GrayMaskBias->Default = 0.000000f; float_GrayMaskBias->RightStep = 0.125000f;

  gh.Group(L"Gray MaskBlur");

  gh.Label(L"* BlurRadius");
  sFloatControl *float_BlurRadius = gh.Float(&para->BlurRadius,1.000000f,4096.000f,0.010000f);
  float_BlurRadius->Default = 50.00000f; float_BlurRadius->RightStep = 0.125000f;

  gh.Label(L"* BlurAmp");
  sFloatControl *float_BlurAmp = gh.Float(&para->BlurAmp,0.000000f,256.0000f,0.001000f);
  float_BlurAmp->Default = 1.000000f; float_BlurAmp->RightStep = 0.125000f;

  gh.Group(L"Screen Blur");

  gh.Label(L"* BlurScreenRadius");
  sFloatControl *float_BlurScreenRadius = gh.Float(&para->BlurScreenRadius,1.000000f,4096.000f,0.010000f);
  float_BlurScreenRadius->Default = 50.00000f; float_BlurScreenRadius->RightStep = 0.125000f;

  gh.Label(L"* BlurScreenAmp");
  sFloatControl *float_BlurScreenAmp = gh.Float(&para->BlurScreenAmp,-1024.00f,1024.000f,0.001000f);
  float_BlurScreenAmp->Default = 1.000000f; float_BlurScreenAmp->RightStep = 0.125000f;

  gh.Group(L"Composition");

  gh.Label(L"* CompBloomCol");
  gh.ColorPick(&para->CompBloomCol,L"rgba",0);

  gh.Label(L"* CompBloomAmp");
  sFloatControl *float_CompBloomAmp = gh.Float(&para->CompBloomAmp,-1024.00f,1024.000f,0.001000f);
  float_CompBloomAmp->Default = 0.000000f; float_CompBloomAmp->RightStep = 0.125000f;

  gh.Label(L"* CompScreenCol");
  gh.ColorPick(&para->CompScreenCol,L"rgba",0);

  gh.Label(L"* CompScreenAmp");
  sFloatControl *float_CompScreenAmp = gh.Float(&para->CompScreenAmp,-1024.00f,1024.000f,0.001000f);
  float_CompScreenAmp->Default = 1.000000f; float_CompScreenAmp->RightStep = 0.125000f;

  gh.Group(L"Debug:");

  gh.Label(L"DebugShow");
  gh.Flags(&para->DebugShow,L"Result|Mask|BlurMask|BlurScreen",gh.LayoutMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefPromist(wOp *op)
{
  Wz4RenderParaPromist sUNUSED *para = (Wz4RenderParaPromist *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->MaskCol = 0xffffffff;
  para->MaskAmp = 1.000000f;
  para->AlphaAmp = 1.000000f;
  para->ZBufAmp = 1.000000f;
  para->BlendFactor.x = 0.500000f;
  para->BlendFactor.y = 0.500000f;
  para->BlendFactor.z = 0.500000f;
  para->BlendFactor.w = 0.500000f;
  para->GrayMaskCol = 0xffffffff;
  para->GrayMaskAmp = 1.000000f;
  para->BlurRadius = 50.00000f;
  para->BlurAmp = 1.000000f;
  para->BlurScreenRadius = 50.00000f;
  para->BlurScreenAmp = 1.000000f;
  para->CompBloomCol = 0xffffffff;
  para->CompScreenCol = 0xffffffff;
  para->CompScreenAmp = 1.000000f;
}

void Wz4RenderBindPromist(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"highlightcol"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"maskcol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"maskamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"maskbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"alphaamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"alphabias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"zbufamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"zbufbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,4);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"blendfactor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+16;
  ctx->BindLocal(ctx->AddSymbol(L"graymaskcol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+17;
  ctx->BindLocal(ctx->AddSymbol(L"graymaskamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+18;
  ctx->BindLocal(ctx->AddSymbol(L"graymaskbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+19;
  ctx->BindLocal(ctx->AddSymbol(L"blurradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+20;
  ctx->BindLocal(ctx->AddSymbol(L"bluramp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+21;
  ctx->BindLocal(ctx->AddSymbol(L"blurscreenradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+22;
  ctx->BindLocal(ctx->AddSymbol(L"blurscreenamp"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+23;
  ctx->BindLocal(ctx->AddSymbol(L"compbloomcol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+24;
  ctx->BindLocal(ctx->AddSymbol(L"compbloomamp"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+25;
  ctx->BindLocal(ctx->AddSymbol(L"compscreencol"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+26;
  ctx->BindLocal(ctx->AddSymbol(L"compscreenamp"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Promist(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[32];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"graymask");
    name[1] = sPoolString(L"calcmaskfromscreen");
    name[2] = sPoolString(L"highlightcol");
    name[3] = sPoolString(L"maskcol");
    name[4] = sPoolString(L"maskamp");
    name[5] = sPoolString(L"maskbias");
    name[6] = sPoolString(L"usealpha");
    name[7] = sPoolString(L"alphaamp");
    name[8] = sPoolString(L"alphabias");
    name[9] = sPoolString(L"usezbuf");
    name[10] = sPoolString(L"zbufamp");
    name[11] = sPoolString(L"zbufbias");
    name[12] = sPoolString(L"multiplyscreencol");
    name[13] = sPoolString(L"blendfactor");
    name[14] = sPoolString(L"graymaskcol");
    name[15] = sPoolString(L"graymaskamp");
    name[16] = sPoolString(L"graymaskbias");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"blurradius");
    name[19] = sPoolString(L"bluramp");
    name[20] = sPoolString(L"");
    name[21] = sPoolString(L"blurscreenradius");
    name[22] = sPoolString(L"blurscreenamp");
    name[23] = sPoolString(L"composition");
    name[24] = sPoolString(L"compbloomcol");
    name[25] = sPoolString(L"compbloomamp");
    name[26] = sPoolString(L"compscreencol");
    name[27] = sPoolString(L"compscreenamp");
    name[28] = sPoolString(L"");
    name[29] = sPoolString(L"debugshow");
    name[30] = sPoolString(L"");
    name[31] = sPoolString(L"script");
  }
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[13],ScriptTypeFloat,4,cmd->Data+12);
  ctx->AddImport(name[14],ScriptTypeColor,1,cmd->Data+16);
  ctx->AddImport(name[15],ScriptTypeFloat,1,cmd->Data+17);
  ctx->AddImport(name[16],ScriptTypeFloat,1,cmd->Data+18);
  ctx->AddImport(name[18],ScriptTypeFloat,1,cmd->Data+19);
  ctx->AddImport(name[19],ScriptTypeFloat,1,cmd->Data+20);
  ctx->AddImport(name[21],ScriptTypeFloat,1,cmd->Data+21);
  ctx->AddImport(name[22],ScriptTypeFloat,1,cmd->Data+22);
  ctx->AddImport(name[24],ScriptTypeColor,1,cmd->Data+23);
  ctx->AddImport(name[25],ScriptTypeFloat,1,cmd->Data+24);
  ctx->AddImport(name[26],ScriptTypeColor,1,cmd->Data+25);
  ctx->AddImport(name[27],ScriptTypeFloat,1,cmd->Data+26);
  ctx->AddImport(name[31],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Promist(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import highlightcol : color;\n");
  tb.PrintF(L"  import maskcol : color;\n");
  tb.PrintF(L"  import maskamp : float;\n");
  tb.PrintF(L"  import maskbias : float;\n");
  tb.PrintF(L"  import alphaamp : float;\n");
  tb.PrintF(L"  import alphabias : float;\n");
  tb.PrintF(L"  import zbufamp : float;\n");
  tb.PrintF(L"  import zbufbias : float;\n");
  tb.PrintF(L"  import blendfactor : float[4];\n");
  tb.PrintF(L"  import graymaskcol : color;\n");
  tb.PrintF(L"  import graymaskamp : float;\n");
  tb.PrintF(L"  import graymaskbias : float;\n");
  tb.PrintF(L"  import blurradius : float;\n");
  tb.PrintF(L"  import bluramp : float;\n");
  tb.PrintF(L"  import blurscreenradius : float;\n");
  tb.PrintF(L"  import blurscreenamp : float;\n");
  tb.PrintF(L"  import compbloomcol : color;\n");
  tb.PrintF(L"  import compbloomamp : float;\n");
  tb.PrintF(L"  import compscreencol : color;\n");
  tb.PrintF(L"  import compscreenamp : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiPromist =
L"= Wz4Render : Promist\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Promist\n"
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
L" !i CalcMaskFromScreen\n"
L" !i CalcMaskFromScreen\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i HighlightCol\n"
L" !i HighlightCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MaskCol\n"
L" !i MaskCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i MaskAmp\n"
L" !i MaskAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaskBias\n"
L" !i MaskBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i UseAlpha\n"
L" !i UseAlpha\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i AlphaAmp\n"
L" !i AlphaAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i AlphaBias\n"
L" !i AlphaBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i UseZBuf\n"
L" !i UseZBuf\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ZBufAmp\n"
L" !i ZBufAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ZBufBias\n"
L" !i ZBufBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i MultiplyScreenCol\n"
L" !i MultiplyScreenCol\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i BlendFactor\n"
L" !i BlendFactor\n"
L" !i float[4]\n"
L" !i *\n"
L"\n"
L" !i GrayMaskCol\n"
L" !i GrayMaskCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i GrayMaskAmp\n"
L" !i GrayMaskAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GrayMaskBias\n"
L" !i GrayMaskBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurRadius\n"
L" !i BlurRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurAmp\n"
L" !i BlurAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurScreenRadius\n"
L" !i BlurScreenRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurScreenAmp\n"
L" !i BlurScreenAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CompBloomCol\n"
L" !i CompBloomCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i CompBloomAmp\n"
L" !i CompBloomAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CompScreenCol\n"
L" !i CompScreenCol\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i CompScreenAmp\n"
L" !i CompScreenAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugShow\n"
L" !i DebugShow\n"
L" !i Result\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Mask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i BlurMask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i BlurScreen\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdDepthOfField3(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaDepthOfField3 sUNUSED *para = (Wz4RenderParaDepthOfField3 *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 485 "tron_ops.ops"

    RNDoF3 *node = new RNDoF3();
    node->ParaBase = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 2862 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiDepthOfField3(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaDepthOfField3 sUNUSED *para = (Wz4RenderParaDepthOfField3 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* FocalDepth");
  sFloatControl *float_FocalDepth = gh.Float(&para->FocalDepth,0.000000f,16384.00f,0.001000f);
  float_FocalDepth->Default = 1.000000f; float_FocalDepth->RightStep = 0.125000f;

  gh.Label(L"* FocusRange");
  sFloatControl *float_FocusRange = gh.Float(&para->FocusRange,-16384.0f,16384.00f,0.001000f);
  float_FocusRange->Default = 0.000000f; float_FocusRange->RightStep = 0.125000f;

  gh.Label(L"* UnfocusRangeBefore");
  sFloatControl *float_UnfocusRangeBefore = gh.Float(&para->UnfocusRangeBefore,0.000000f,16384.00f,0.001000f);
  float_UnfocusRangeBefore->Default = 1.000000f; float_UnfocusRangeBefore->RightStep = 0.125000f;

  gh.Label(L"* UnfocusRangeAfter");
  sFloatControl *float_UnfocusRangeAfter = gh.Float(&para->UnfocusRangeAfter,0.000000f,16384.00f,0.001000f);
  float_UnfocusRangeAfter->Default = 1.000000f; float_UnfocusRangeAfter->RightStep = 0.125000f;

  gh.Label(L"* BlurMaskRadius");
  sFloatControl *float_BlurMaskRadius = gh.Float(&para->BlurMaskRadius,2.000000f,4096.000f,0.010000f);
  float_BlurMaskRadius->Default = 10.00000f; float_BlurMaskRadius->RightStep = 0.125000f;

  gh.Label(L"* BlurMaskAmb");
  sFloatControl *float_BlurMaskAmb = gh.Float(&para->BlurMaskAmb,-4096.00f,4096.000f,0.010000f);
  float_BlurMaskAmb->Default = 1.000000f; float_BlurMaskAmb->RightStep = 0.125000f;

  gh.Group(L"Advanced");

  gh.Label(L"Advanced");
  gh.Flags(&para->Advanced,L"Off|On",gh.LayoutMsg);

  if((para->Advanced==0x0001))
  {
    gh.Label(L"* BlurScreenRadius");
    sFloatControl *float_BlurScreenRadius = gh.Float(&para->BlurScreenRadius,2.000000f,4096.000f,0.010000f);
    float_BlurScreenRadius->Default = 1.000000f; float_BlurScreenRadius->RightStep = 0.125000f;

    gh.Label(L"* BlurScreenAmb");
    sFloatControl *float_BlurScreenAmb = gh.Float(&para->BlurScreenAmb,-4096.00f,4096.000f,0.010000f);
    float_BlurScreenAmb->Default = 1.000000f; float_BlurScreenAmb->RightStep = 0.125000f;

    gh.Label(L"* CompScreenAmb");
    sFloatControl *float_CompScreenAmb = gh.Float(&para->CompScreenAmb,-4096.00f,4096.000f,0.010000f);
    float_CompScreenAmb->Default = 1.000000f; float_CompScreenAmb->RightStep = 0.125000f;

    gh.Label(L"* CompMaskAmb");
    sFloatControl *float_CompMaskAmb = gh.Float(&para->CompMaskAmb,-4096.00f,4096.000f,0.010000f);
    float_CompMaskAmb->Default = 1.000000f; float_CompMaskAmb->RightStep = 0.125000f;

  }
  gh.Group(L"Debug");

  gh.Label(L"DebugShow");
  gh.Flags(&para->DebugShow,L"Result|ZMask|ZBlurMask|BlurScreen",gh.LayoutMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefDepthOfField3(wOp *op)
{
  Wz4RenderParaDepthOfField3 sUNUSED *para = (Wz4RenderParaDepthOfField3 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->FocalDepth = 1.000000f;
  para->UnfocusRangeBefore = 1.000000f;
  para->UnfocusRangeAfter = 1.000000f;
  para->BlurMaskRadius = 10.00000f;
  para->BlurMaskAmb = 1.000000f;
  para->BlurScreenRadius = 1.000000f;
  para->BlurScreenAmb = 1.000000f;
  para->CompScreenAmb = 1.000000f;
  para->CompMaskAmb = 1.000000f;
}

void Wz4RenderBindDepthOfField3(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"focaldepth"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"focusrange"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"unfocusrangebefore"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"unfocusrangeafter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"blurmaskradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"blurmaskamb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"blurscreenradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"blurscreenamb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"compscreenamb"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"compmaskamb"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2DepthOfField3(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[16];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"focaldepth");
    name[1] = sPoolString(L"focusrange");
    name[2] = sPoolString(L"unfocusrangebefore");
    name[3] = sPoolString(L"unfocusrangeafter");
    name[4] = sPoolString(L"blurmaskradius");
    name[5] = sPoolString(L"blurmaskamb");
    name[6] = sPoolString(L"advanced");
    name[7] = sPoolString(L"advanced");
    name[8] = sPoolString(L"blurscreenradius");
    name[9] = sPoolString(L"blurscreenamb");
    name[10] = sPoolString(L"compscreenamb");
    name[11] = sPoolString(L"compmaskamb");
    name[12] = sPoolString(L"debug");
    name[13] = sPoolString(L"debugshow");
    name[14] = sPoolString(L"");
    name[15] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[15],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3DepthOfField3(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import focaldepth : float;\n");
  tb.PrintF(L"  import focusrange : float;\n");
  tb.PrintF(L"  import unfocusrangebefore : float;\n");
  tb.PrintF(L"  import unfocusrangeafter : float;\n");
  tb.PrintF(L"  import blurmaskradius : float;\n");
  tb.PrintF(L"  import blurmaskamb : float;\n");
  tb.PrintF(L"  import blurscreenradius : float;\n");
  tb.PrintF(L"  import blurscreenamb : float;\n");
  tb.PrintF(L"  import compscreenamb : float;\n");
  tb.PrintF(L"  import compmaskamb : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiDepthOfField3 =
L"= Wz4Render : DepthOfField3\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DepthOfField3\n"
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
L" !i FocalDepth\n"
L" !i FocalDepth\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FocusRange\n"
L" !i FocusRange\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i UnfocusRangeBefore\n"
L" !i UnfocusRangeBefore\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i UnfocusRangeAfter\n"
L" !i UnfocusRangeAfter\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurMaskRadius\n"
L" !i BlurMaskRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurMaskAmb\n"
L" !i BlurMaskAmb\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Advanced\n"
L" !i Advanced\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i BlurScreenRadius\n"
L" !i BlurScreenRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurScreenAmb\n"
L" !i BlurScreenAmb\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CompScreenAmb\n"
L" !i CompScreenAmb\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i CompMaskAmb\n"
L" !i CompMaskAmb\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugShow\n"
L" !i DebugShow\n"
L" !i Result\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ZMask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ZBlurMask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i BlurScreen\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdGlow(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaGlow sUNUSED *para = (Wz4RenderParaGlow *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 527 "tron_ops.ops"

    RNGlow *node = new RNGlow();
    node->ParaBase = *para;
    node->Init();
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 3181 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiGlow(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaGlow sUNUSED *para = (Wz4RenderParaGlow *)(op->EditData); para;

  gh.Group(L"Gradient");

  gh.Label(L"* GradInColor");
  gh.ColorPick(&para->GradInColor,L"rgba",0);

  gh.Label(L"* GradOutColor");
  gh.ColorPick(&para->GradOutColor,L"rgba",0);

  gh.Label(L"* GradShift");
  sFloatControl *float_GradShift = gh.Float(&para->GradShift,0.000000f,128.0000f,0.001000f);
  float_GradShift->Default = 1.000000f; float_GradShift->RightStep = 0.125000f;

  gh.Label(L"* GradIntensity");
  sFloatControl *float_GradIntensity = gh.Float(&para->GradIntensity,0.000000f,999.9901f,0.010000f);
  float_GradIntensity->Default = 10.00000f; float_GradIntensity->RightStep = 0.125000f;

  gh.Label(L"* GradOffset");
  sFloatControl *float_GradOffset = gh.Float(&para->GradOffset,-10.0000f,10.00000f,0.001000f);
  float_GradOffset->Default = 1.000000f; float_GradOffset->RightStep = 0.125000f;

  gh.Group(L"Mask");

  gh.Label(L"MaskEdgeGlow");
  gh.Flags(&para->MaskEdgeGlow,L"Off|On",gh.LayoutMsg);

  gh.Label(L"* MaskThres");
  sFloatControl *float_MaskThres = gh.Float(&para->MaskThres,0.000000f,1.000000f,0.001000f);
  float_MaskThres->Default = 0.500000f; float_MaskThres->RightStep = 0.125000f;

  gh.Label(L"* MaskSoftenThres");
  sFloatControl *float_MaskSoftenThres = gh.Float(&para->MaskSoftenThres,0.001000f,1.000000f,0.001000f);
  float_MaskSoftenThres->Default = 0.001000f; float_MaskSoftenThres->RightStep = 0.125000f;

  gh.Group(L"BlurMask");

  gh.Label(L"* BlurMaskRadius");
  sFloatControl *float_BlurMaskRadius = gh.Float(&para->BlurMaskRadius,0.000000f,4096.000f,0.010000f);
  float_BlurMaskRadius->Default = 1.000000f; float_BlurMaskRadius->RightStep = 0.125000f;

  gh.Label(L"* BlurMaskAmp");
  sFloatControl *float_BlurMaskAmp = gh.Float(&para->BlurMaskAmp,0.000000f,256.0000f,0.010000f);
  float_BlurMaskAmp->Default = 1.000000f; float_BlurMaskAmp->RightStep = 0.125000f;

  gh.Group(L"Combine");

  gh.Label(L"CombineMode");
  gh.Flags(&para->CombineMode,L"Add|Blend|Multiply|Sub",gh.LayoutMsg);

  gh.Group(L"Debug");

  gh.Label(L"DebugShow");
  gh.Flags(&para->DebugShow,L"Result|BlurMask|Mask|Gradient",gh.LayoutMsg);

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefGlow(wOp *op)
{
  Wz4RenderParaGlow sUNUSED *para = (Wz4RenderParaGlow *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->GradInColor = 0xffffffff;
  para->GradOutColor = 0xffffffff;
  para->GradShift = 1.000000f;
  para->GradIntensity = 10.00000f;
  para->GradOffset = 1.000000f;
  para->MaskThres = 0.500000f;
  para->MaskSoftenThres = 0.001000f;
  para->BlurMaskRadius = 1.000000f;
  para->BlurMaskAmp = 1.000000f;
}

void Wz4RenderBindGlow(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"gradincolor"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"gradoutcolor"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"gradshift"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"gradintensity"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"gradoffset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"maskthres"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"masksoftenthres"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"blurmaskradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"blurmaskamp"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2Glow(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[19];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"gradient");
    name[1] = sPoolString(L"gradincolor");
    name[2] = sPoolString(L"gradoutcolor");
    name[3] = sPoolString(L"gradshift");
    name[4] = sPoolString(L"gradintensity");
    name[5] = sPoolString(L"gradoffset");
    name[6] = sPoolString(L"mask");
    name[7] = sPoolString(L"maskedgeglow");
    name[8] = sPoolString(L"maskthres");
    name[9] = sPoolString(L"masksoftenthres");
    name[10] = sPoolString(L"blurmask");
    name[11] = sPoolString(L"blurmaskradius");
    name[12] = sPoolString(L"blurmaskamp");
    name[13] = sPoolString(L"combine");
    name[14] = sPoolString(L"combinemode");
    name[15] = sPoolString(L"debug");
    name[16] = sPoolString(L"debugshow");
    name[17] = sPoolString(L"");
    name[18] = sPoolString(L"script");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+0);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[9],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[12],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[18],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3Glow(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import gradincolor : color;\n");
  tb.PrintF(L"  import gradoutcolor : color;\n");
  tb.PrintF(L"  import gradshift : float;\n");
  tb.PrintF(L"  import gradintensity : float;\n");
  tb.PrintF(L"  import gradoffset : float;\n");
  tb.PrintF(L"  import maskthres : float;\n");
  tb.PrintF(L"  import masksoftenthres : float;\n");
  tb.PrintF(L"  import blurmaskradius : float;\n");
  tb.PrintF(L"  import blurmaskamp : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiGlow =
L"= Wz4Render : Glow\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Glow\n"
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
L" !i GradInColor\n"
L" !i GradInColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i GradOutColor\n"
L" !i GradOutColor\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i GradShift\n"
L" !i GradShift\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GradIntensity\n"
L" !i GradIntensity\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i GradOffset\n"
L" !i GradOffset\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i MaskEdgeGlow\n"
L" !i MaskEdgeGlow\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i MaskThres\n"
L" !i MaskThres\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i MaskSoftenThres\n"
L" !i MaskSoftenThres\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurMaskRadius\n"
L" !i BlurMaskRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurMaskAmp\n"
L" !i BlurMaskAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i CombineMode\n"
L" !i CombineMode\n"
L" !i Add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Blend\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Multiply\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Sub\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L"!T 4 : 1 1 1 2\n"
L" !i DebugShow\n"
L" !i DebugShow\n"
L" !i Result\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i BlurMask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Mask\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Gradient\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
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

sBool Wz4RenderCmdFocusBlur(wExecutive *exe,wCommand *cmd)
{
  Wz4RenderParaFocusBlur sUNUSED *para = (Wz4RenderParaFocusBlur *)(cmd->Data); para;
  Wz4Render sUNUSED *in0 = cmd->GetInput<Wz4Render *>(0); in0;
  Wz4Render *out = (Wz4Render *) cmd->Output;
  if(!out) { out=new Wz4Render; cmd->Output=out; }

  {
#line 554 "tron_ops.ops"

    RNFocusBlur *node = new RNFocusBlur();
    node->ParaBase = node->Para = *para;    
    out->RootNode = node;
    out->AddChilds(cmd,0);
  ;
#line 3509 "tron_ops.cpp"
    return 1;
  }
}

void Wz4RenderGuiFocusBlur(wGridFrameHelper &gh,wOp *op)
{
  Wz4RenderParaFocusBlur sUNUSED *para = (Wz4RenderParaFocusBlur *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* FocusPoint");
  gh.BeginTied();
  sFloatControl *float_FocusPoint_0 = gh.Float(&para->FocusPoint[0],-100.000f,200.0000f,0.010000f);
  float_FocusPoint_0->Default = 50.00000f; float_FocusPoint_0->RightStep = 0.125000f;
  sFloatControl *float_FocusPoint_1 = gh.Float(&para->FocusPoint[1],-100.000f,200.0000f,0.010000f);
  float_FocusPoint_1->Default = 50.00000f; float_FocusPoint_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* FocusAmp");
  sFloatControl *float_FocusAmp = gh.Float(&para->FocusAmp,-16.0000f,16.00000f,0.000100f);
  float_FocusAmp->Default = 1.000000f; float_FocusAmp->RightStep = 0.125000f;

  gh.Label(L"* FocusBias");
  sFloatControl *float_FocusBias = gh.Float(&para->FocusBias,-16.0000f,16.00000f,0.000100f);
  float_FocusBias->Default = 0.000000f; float_FocusBias->RightStep = 0.125000f;

  gh.Label(L"* BlurScreenRadius");
  sFloatControl *float_BlurScreenRadius = gh.Float(&para->BlurScreenRadius,0.000000f,256.0000f,0.001000f);
  float_BlurScreenRadius->Default = 1.000000f; float_BlurScreenRadius->RightStep = 0.125000f;

  gh.Label(L"* BlurScreenAmp");
  sFloatControl *float_BlurScreenAmp = gh.Float(&para->BlurScreenAmp,0.000000f,256.0000f,0.001000f);
  float_BlurScreenAmp->Default = 1.000000f; float_BlurScreenAmp->RightStep = 0.125000f;

  gh.Group(L"Animation Script");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[0],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
    tw->EditFlags |= sTEF_LINENUMBER;
  }
}

void Wz4RenderDefFocusBlur(wOp *op)
{
  Wz4RenderParaFocusBlur sUNUSED *para = (Wz4RenderParaFocusBlur *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->FocusPoint[0] = 50.00000f;
  para->FocusPoint[1] = 50.00000f;
  para->FocusAmp = 1.000000f;
  para->BlurScreenRadius = 1.000000f;
  para->BlurScreenAmp = 1.000000f;
}

void Wz4RenderBindFocusBlur(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"focuspoint"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"focuspoint"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"focusamp"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"focusbias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"blurscreenradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"blurscreenamp"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"script"),val);
}
void Wz4RenderBind2FocusBlur(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"focuspoint");
    name[1] = sPoolString(L"focusamp");
    name[2] = sPoolString(L"focusbias");
    name[3] = sPoolString(L"blurscreenradius");
    name[4] = sPoolString(L"blurscreenamp");
    name[5] = sPoolString(L"");
    name[6] = sPoolString(L"script");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,2,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeString,1,cmd->Strings+0);
}
void Wz4RenderBind3FocusBlur(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import focuspoint : float[2];\n");
  tb.PrintF(L"  import focusamp : float;\n");
  tb.PrintF(L"  import focusbias : float;\n");
  tb.PrintF(L"  import blurscreenradius : float;\n");
  tb.PrintF(L"  import blurscreenamp : float;\n");
  tb.PrintF(L"  import script : string;\n");
}
const sChar *Wz4RenderWikiFocusBlur =
L"= Wz4Render : FocusBlur\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FocusBlur\n"
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
L" !i FocusPoint\n"
L" !i FocusPoint\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i FocusAmp\n"
L" !i FocusAmp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i FocusBias\n"
L" !i FocusBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurScreenRadius\n"
L" !i BlurScreenRadius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i BlurScreenAmp\n"
L" !i BlurScreenAmp\n"
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

sBool GenBitmapCmdTronFont(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaTronFont sUNUSED *para = (GenBitmapParaTronFont *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 581 "tron_ops.ops"

    TronInitFont(out, cmd->Strings[0], cmd->Strings[1],1<<(para->Size&0xff),1<<((para->Size>>8)&0xff), para->Width, para->Height, para->Style, para->Safety, para->SpacePreCellPost[0], para->SpacePreCellPost[1], para->SpacePreCellPost[2], (sU32)(para->Col));
  ;
#line 3706 "tron_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiTronFont(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaTronFont sUNUSED *para = (GenBitmapParaTronFont *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Name");
  gh.String(op->EditString[0]);

  gh.Label(L"Letters");
  gh.String(op->EditString[1]);

  gh.Label(L"Height");
  sIntControl *int_Height = gh.Int(&para->Height,1,1024,0.125000f);
  int_Height->Default = 0x0000000e; int_Height->RightStep = 0.125000f;

  gh.Label(L"Width");
  sIntControl *int_Width = gh.Int(&para->Width,0,1024,0.125000f);
  int_Width->Default = 0x00000000; int_Width->RightStep = 0.125000f;

  gh.Label(L"Style");
  gh.Flags(&para->Style,L"*0-|Bold:*1-|Italics:*2-|Underline:*3-|Strikeout:*4-|symbols",gh.ChangeMsg);

  gh.Label(L"Safety");
  sIntControl *int_Safety = gh.Int(&para->Safety,0,1024,0.125000f);
  int_Safety->Default = 0x00000001; int_Safety->RightStep = 0.125000f;

  gh.Label(L"SpacePreCellPost");
  gh.BeginTied();
  sIntControl *int_SpacePreCellPost_0 = gh.Int(&para->SpacePreCellPost[0],-1024,1024,0.125000f);
  int_SpacePreCellPost_0->Default = 0x00000000; int_SpacePreCellPost_0->RightStep = 0.125000f;
  sIntControl *int_SpacePreCellPost_1 = gh.Int(&para->SpacePreCellPost[1],-1024,1024,0.125000f);
  int_SpacePreCellPost_1->Default = 0x00000000; int_SpacePreCellPost_1->RightStep = 0.125000f;
  sIntControl *int_SpacePreCellPost_2 = gh.Int(&para->SpacePreCellPost[2],-1024,1024,0.125000f);
  int_SpacePreCellPost_2->Default = 0x00000000; int_SpacePreCellPost_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Col");
  gh.ColorPick(&para->Col,L"rgba",0);
}

void GenBitmapDefTronFont(wOp *op)
{
  GenBitmapParaTronFont sUNUSED *para = (GenBitmapParaTronFont *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Height = 0x0000000e;
  para->Safety = 0x00000001;
  para->Col = 0xffffffff;
}

void GenBitmapBindTronFont(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"name"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"letters"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"height"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"safety"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"spaceprecellpost"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"spaceprecellpost"),val);
  val = ctx->MakeValue(ScriptTypeInt,3);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"spaceprecellpost"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"col"),val);
}
void GenBitmapBind2TronFont(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"name");
    name[2] = sPoolString(L"letters");
    name[3] = sPoolString(L"height");
    name[4] = sPoolString(L"width");
    name[5] = sPoolString(L"style");
    name[6] = sPoolString(L"safety");
    name[7] = sPoolString(L"spaceprecellpost");
    name[8] = sPoolString(L"col");
  }
  ctx->AddImport(name[1],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[2],ScriptTypeString,1,cmd->Strings+1);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[7],ScriptTypeInt,3,cmd->Data+5);
  ctx->AddImport(name[8],ScriptTypeColor,1,cmd->Data+8);
}
void GenBitmapBind3TronFont(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import name : string;\n");
  tb.PrintF(L"  import letters : string;\n");
  tb.PrintF(L"  import height : int;\n");
  tb.PrintF(L"  import width : int;\n");
  tb.PrintF(L"  import safety : int;\n");
  tb.PrintF(L"  import spaceprecellpost : int[3];\n");
  tb.PrintF(L"  import col : color;\n");
}
const sChar *GenBitmapWikiTronFont =
L"= GenBitmap : TronFont\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TronFont\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Size\n"
L" !i Size\n"
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
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
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
L" !i Name\n"
L" !i Name\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Letters\n"
L" !i Letters\n"
L" !i string\n"
L" !i *\n"
L"\n"
L" !i Height\n"
L" !i Height\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Width\n"
L" !i Width\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Style\n"
L" !i Style\n"
L" !i Bold\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Italics\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Underline\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Strikeout\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i symbols\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Safety\n"
L" !i Safety\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i SpacePreCellPost\n"
L" !i SpacePreCellPost\n"
L" !i int[3]\n"
L" !i *\n"
L"\n"
L" !i Col\n"
L" !i Col\n"
L" !i color\n"
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

sBool Wz4MeshCmdTronPrint(wExecutive *exe,wCommand *cmd)
{
  Wz4MeshParaTronPrint sUNUSED *para = (Wz4MeshParaTronPrint *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  Wz4Mesh *out = (Wz4Mesh *) cmd->Output;
  if(!out) { out=new Wz4Mesh; cmd->Output=out; }

  {
#line 600 "tron_ops.ops"

    sInt nb=0;
    static GenBitmap *input[256];
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      GenBitmap *in = cmd->GetInput<GenBitmap *>(i);
      if(in)
      {
        input[nb++]=in;
      }
    }

    TronPrint(out, input, nb, cmd->Strings[1],para->Zoom,para->Width,para->Space[0],para->Space[1]);
  ;
#line 4082 "tron_ops.cpp"
    return 1;
  }
}

void Wz4MeshGuiTronPrint(wGridFrameHelper &gh,wOp *op)
{
  Wz4MeshParaTronPrint sUNUSED *para = (Wz4MeshParaTronPrint *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Label(L"Zoom");
  sFloatControl *float_Zoom = gh.Float(&para->Zoom,0.000000f,16.00000f,0.000100f);
  float_Zoom->Default = 1.000000f; float_Zoom->RightStep = 0.125000f;

  gh.Label(L"Width");
  sIntControl *int_Width = gh.Int(&para->Width,1,8192,0.125000f);
  int_Width->Default = 0x00000400; int_Width->RightStep = 0.125000f;

  gh.Label(L"Space");
  gh.BeginTied();
  sFloatControl *float_Space_0 = gh.Float(&para->Space[0],-1024.00f,1024.000f,0.100000f);
  float_Space_0->Default = 0.000000f; float_Space_0->RightStep = 0.125000f;
  sFloatControl *float_Space_1 = gh.Float(&para->Space[1],-1024.00f,1024.000f,0.100000f);
  float_Space_1->Default = 0.000000f; float_Space_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Group(L"Text");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[1],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
  }
}

void Wz4MeshDefTronPrint(wOp *op)
{
  Wz4MeshParaTronPrint sUNUSED *para = (Wz4MeshParaTronPrint *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0xffffffff;
  para->Zoom = 1.000000f;
  para->Width = 0x00000400;
  *op->EditString[1] = L"hund.";
}

void Wz4MeshBindTronPrint(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"zoom"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"space"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"space"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"text"),val);
}
void Wz4MeshBind2TronPrint(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"color_");
    name[1] = sPoolString(L"zoom");
    name[2] = sPoolString(L"width");
    name[3] = sPoolString(L"space");
    name[4] = sPoolString(L"text");
    name[5] = sPoolString(L"text");
  }
  ctx->AddImport(name[0],ScriptTypeColor,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,2,cmd->Data+3);
  ctx->AddImport(name[5],ScriptTypeString,1,cmd->Strings+1);
}
void Wz4MeshBind3TronPrint(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import zoom : float;\n");
  tb.PrintF(L"  import width : int;\n");
  tb.PrintF(L"  import space : float[2];\n");
  tb.PrintF(L"  import text : string;\n");
}
const sChar *Wz4MeshWikiTronPrint =
L"= Wz4Mesh : TronPrint\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TronPrint\n"
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
L" !i GenBitmap\n"
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
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Zoom\n"
L" !i Zoom\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Width\n"
L" !i Width\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Space\n"
L" !i Space\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Text\n"
L" !i Text\n"
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

void Wz4ParticlesAnimPlaceOnMesh::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimPlaceOnMesh::Bind(class ScriptContext *sc,Wz4ParticlesParaPlaceOnMesh *para)
{
};

void Wz4ParticlesAnimSingleForceField::Init(class ScriptContext *sc)
{
  _Position = sc->AddSymbol(L"position");
  _Scale = sc->AddSymbol(L"scale");
  _Size = sc->AddSymbol(L"size");
  _Rotation = sc->AddSymbol(L"rotation");
  _Distance = sc->AddSymbol(L"distance");
};

void Wz4ParticlesAnimSingleForceField::Bind(class ScriptContext *sc,Wz4ParticlesParaSingleForceField *para)
{
  sc->BindLocalFloat(_Position,3,&para->Position.x);
  sc->BindLocalFloat(_Scale,1,&para->Scale);
  sc->BindLocalFloat(_Size,3,&para->Size.x);
  sc->BindLocalFloat(_Rotation,3,&para->Rotation.x);
  sc->BindLocalFloat(_Distance,1,&para->Distance);
};

void Wz4MeshAnimRetexturizer::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimRetexturizer::Bind(class ScriptContext *sc,Wz4MeshParaRetexturizer *para)
{
};

void Wz4ParticlesAnimFR033_MeteorShowerSim::Init(class ScriptContext *sc)
{
};

void Wz4ParticlesAnimFR033_MeteorShowerSim::Bind(class ScriptContext *sc,Wz4ParticlesParaFR033_MeteorShowerSim *para)
{
};

void Wz4RenderAnimFR033_WaterSimRender::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimFR033_WaterSimRender::Bind(class ScriptContext *sc,Wz4RenderParaFR033_WaterSimRender *para)
{
};

void Wz4RenderAnimSharpen::Init(class ScriptContext *sc)
{
  _Strength = sc->AddSymbol(L"strength");
};

void Wz4RenderAnimSharpen::Bind(class ScriptContext *sc,Wz4RenderParaSharpen *para)
{
  sc->BindLocalFloat(_Strength,1,&para->Strength);
};

void Wz4RenderAnimSBlur::Init(class ScriptContext *sc)
{
};

void Wz4RenderAnimSBlur::Bind(class ScriptContext *sc,Wz4RenderParaSBlur *para)
{
};

void Wz4RenderAnimBloom::Init(class ScriptContext *sc)
{
  _HighlightCol = sc->AddSymbol(L"highlightcol");
  _MaskCol = sc->AddSymbol(L"maskcol");
  _MaskAmp = sc->AddSymbol(L"maskamp");
  _MaskBias = sc->AddSymbol(L"maskbias");
  _AlphaAmp = sc->AddSymbol(L"alphaamp");
  _AlphaBias = sc->AddSymbol(L"alphabias");
  _ZBufAmp = sc->AddSymbol(L"zbufamp");
  _ZBufBias = sc->AddSymbol(L"zbufbias");
  _BlendFactor = sc->AddSymbol(L"blendfactor");
  _GrayMaskCol = sc->AddSymbol(L"graymaskcol");
  _GrayMaskAmp = sc->AddSymbol(L"graymaskamp");
  _GrayMaskBias = sc->AddSymbol(L"graymaskbias");
  _BlurRadius = sc->AddSymbol(L"blurradius");
  _BlurAmp = sc->AddSymbol(L"bluramp");
  _CompBloomCol = sc->AddSymbol(L"compbloomcol");
  _CompBloomAmp = sc->AddSymbol(L"compbloomamp");
  _CompScreenCol = sc->AddSymbol(L"compscreencol");
  _CompScreenAmp = sc->AddSymbol(L"compscreenamp");
  _PreBlurSize = sc->AddSymbol(L"preblursize");
};

void Wz4RenderAnimBloom::Bind(class ScriptContext *sc,Wz4RenderParaBloom *para)
{
  sc->BindLocalColor(_HighlightCol,&para->HighlightCol);
  sc->BindLocalColor(_MaskCol,&para->MaskCol);
  sc->BindLocalFloat(_MaskAmp,1,&para->MaskAmp);
  sc->BindLocalFloat(_MaskBias,1,&para->MaskBias);
  sc->BindLocalFloat(_AlphaAmp,1,&para->AlphaAmp);
  sc->BindLocalFloat(_AlphaBias,1,&para->AlphaBias);
  sc->BindLocalFloat(_ZBufAmp,1,&para->ZBufAmp);
  sc->BindLocalFloat(_ZBufBias,1,&para->ZBufBias);
  sc->BindLocalFloat(_BlendFactor,4,&para->BlendFactor.x);
  sc->BindLocalColor(_GrayMaskCol,&para->GrayMaskCol);
  sc->BindLocalFloat(_GrayMaskAmp,1,&para->GrayMaskAmp);
  sc->BindLocalFloat(_GrayMaskBias,1,&para->GrayMaskBias);
  sc->BindLocalFloat(_BlurRadius,1,&para->BlurRadius);
  sc->BindLocalFloat(_BlurAmp,1,&para->BlurAmp);
  sc->BindLocalColor(_CompBloomCol,&para->CompBloomCol);
  sc->BindLocalFloat(_CompBloomAmp,1,&para->CompBloomAmp);
  sc->BindLocalColor(_CompScreenCol,&para->CompScreenCol);
  sc->BindLocalFloat(_CompScreenAmp,1,&para->CompScreenAmp);
  sc->BindLocalFloat(_PreBlurSize,1,&para->PreBlurSize);
};

void Wz4RenderAnimPromist::Init(class ScriptContext *sc)
{
  _HighlightCol = sc->AddSymbol(L"highlightcol");
  _MaskCol = sc->AddSymbol(L"maskcol");
  _MaskAmp = sc->AddSymbol(L"maskamp");
  _MaskBias = sc->AddSymbol(L"maskbias");
  _AlphaAmp = sc->AddSymbol(L"alphaamp");
  _AlphaBias = sc->AddSymbol(L"alphabias");
  _ZBufAmp = sc->AddSymbol(L"zbufamp");
  _ZBufBias = sc->AddSymbol(L"zbufbias");
  _BlendFactor = sc->AddSymbol(L"blendfactor");
  _GrayMaskCol = sc->AddSymbol(L"graymaskcol");
  _GrayMaskAmp = sc->AddSymbol(L"graymaskamp");
  _GrayMaskBias = sc->AddSymbol(L"graymaskbias");
  _BlurRadius = sc->AddSymbol(L"blurradius");
  _BlurAmp = sc->AddSymbol(L"bluramp");
  _BlurScreenRadius = sc->AddSymbol(L"blurscreenradius");
  _BlurScreenAmp = sc->AddSymbol(L"blurscreenamp");
  _CompBloomCol = sc->AddSymbol(L"compbloomcol");
  _CompBloomAmp = sc->AddSymbol(L"compbloomamp");
  _CompScreenCol = sc->AddSymbol(L"compscreencol");
  _CompScreenAmp = sc->AddSymbol(L"compscreenamp");
};

void Wz4RenderAnimPromist::Bind(class ScriptContext *sc,Wz4RenderParaPromist *para)
{
  sc->BindLocalColor(_HighlightCol,&para->HighlightCol);
  sc->BindLocalColor(_MaskCol,&para->MaskCol);
  sc->BindLocalFloat(_MaskAmp,1,&para->MaskAmp);
  sc->BindLocalFloat(_MaskBias,1,&para->MaskBias);
  sc->BindLocalFloat(_AlphaAmp,1,&para->AlphaAmp);
  sc->BindLocalFloat(_AlphaBias,1,&para->AlphaBias);
  sc->BindLocalFloat(_ZBufAmp,1,&para->ZBufAmp);
  sc->BindLocalFloat(_ZBufBias,1,&para->ZBufBias);
  sc->BindLocalFloat(_BlendFactor,4,&para->BlendFactor.x);
  sc->BindLocalColor(_GrayMaskCol,&para->GrayMaskCol);
  sc->BindLocalFloat(_GrayMaskAmp,1,&para->GrayMaskAmp);
  sc->BindLocalFloat(_GrayMaskBias,1,&para->GrayMaskBias);
  sc->BindLocalFloat(_BlurRadius,1,&para->BlurRadius);
  sc->BindLocalFloat(_BlurAmp,1,&para->BlurAmp);
  sc->BindLocalFloat(_BlurScreenRadius,1,&para->BlurScreenRadius);
  sc->BindLocalFloat(_BlurScreenAmp,1,&para->BlurScreenAmp);
  sc->BindLocalColor(_CompBloomCol,&para->CompBloomCol);
  sc->BindLocalFloat(_CompBloomAmp,1,&para->CompBloomAmp);
  sc->BindLocalColor(_CompScreenCol,&para->CompScreenCol);
  sc->BindLocalFloat(_CompScreenAmp,1,&para->CompScreenAmp);
};

void Wz4RenderAnimDepthOfField3::Init(class ScriptContext *sc)
{
  _FocalDepth = sc->AddSymbol(L"focaldepth");
  _FocusRange = sc->AddSymbol(L"focusrange");
  _UnfocusRangeBefore = sc->AddSymbol(L"unfocusrangebefore");
  _UnfocusRangeAfter = sc->AddSymbol(L"unfocusrangeafter");
  _BlurMaskRadius = sc->AddSymbol(L"blurmaskradius");
  _BlurMaskAmb = sc->AddSymbol(L"blurmaskamb");
  _BlurScreenRadius = sc->AddSymbol(L"blurscreenradius");
  _BlurScreenAmb = sc->AddSymbol(L"blurscreenamb");
  _CompScreenAmb = sc->AddSymbol(L"compscreenamb");
  _CompMaskAmb = sc->AddSymbol(L"compmaskamb");
};

void Wz4RenderAnimDepthOfField3::Bind(class ScriptContext *sc,Wz4RenderParaDepthOfField3 *para)
{
  sc->BindLocalFloat(_FocalDepth,1,&para->FocalDepth);
  sc->BindLocalFloat(_FocusRange,1,&para->FocusRange);
  sc->BindLocalFloat(_UnfocusRangeBefore,1,&para->UnfocusRangeBefore);
  sc->BindLocalFloat(_UnfocusRangeAfter,1,&para->UnfocusRangeAfter);
  sc->BindLocalFloat(_BlurMaskRadius,1,&para->BlurMaskRadius);
  sc->BindLocalFloat(_BlurMaskAmb,1,&para->BlurMaskAmb);
  sc->BindLocalFloat(_BlurScreenRadius,1,&para->BlurScreenRadius);
  sc->BindLocalFloat(_BlurScreenAmb,1,&para->BlurScreenAmb);
  sc->BindLocalFloat(_CompScreenAmb,1,&para->CompScreenAmb);
  sc->BindLocalFloat(_CompMaskAmb,1,&para->CompMaskAmb);
};

void Wz4RenderAnimGlow::Init(class ScriptContext *sc)
{
  _GradInColor = sc->AddSymbol(L"gradincolor");
  _GradOutColor = sc->AddSymbol(L"gradoutcolor");
  _GradShift = sc->AddSymbol(L"gradshift");
  _GradIntensity = sc->AddSymbol(L"gradintensity");
  _GradOffset = sc->AddSymbol(L"gradoffset");
  _MaskThres = sc->AddSymbol(L"maskthres");
  _MaskSoftenThres = sc->AddSymbol(L"masksoftenthres");
  _BlurMaskRadius = sc->AddSymbol(L"blurmaskradius");
  _BlurMaskAmp = sc->AddSymbol(L"blurmaskamp");
};

void Wz4RenderAnimGlow::Bind(class ScriptContext *sc,Wz4RenderParaGlow *para)
{
  sc->BindLocalColor(_GradInColor,&para->GradInColor);
  sc->BindLocalColor(_GradOutColor,&para->GradOutColor);
  sc->BindLocalFloat(_GradShift,1,&para->GradShift);
  sc->BindLocalFloat(_GradIntensity,1,&para->GradIntensity);
  sc->BindLocalFloat(_GradOffset,1,&para->GradOffset);
  sc->BindLocalFloat(_MaskThres,1,&para->MaskThres);
  sc->BindLocalFloat(_MaskSoftenThres,1,&para->MaskSoftenThres);
  sc->BindLocalFloat(_BlurMaskRadius,1,&para->BlurMaskRadius);
  sc->BindLocalFloat(_BlurMaskAmp,1,&para->BlurMaskAmp);
};

void Wz4RenderAnimFocusBlur::Init(class ScriptContext *sc)
{
  _FocusPoint = sc->AddSymbol(L"focuspoint");
  _FocusAmp = sc->AddSymbol(L"focusamp");
  _FocusBias = sc->AddSymbol(L"focusbias");
  _BlurScreenRadius = sc->AddSymbol(L"blurscreenradius");
  _BlurScreenAmp = sc->AddSymbol(L"blurscreenamp");
};

void Wz4RenderAnimFocusBlur::Bind(class ScriptContext *sc,Wz4RenderParaFocusBlur *para)
{
  sc->BindLocalFloat(_FocusPoint,2,para->FocusPoint);
  sc->BindLocalFloat(_FocusAmp,1,&para->FocusAmp);
  sc->BindLocalFloat(_FocusBias,1,&para->FocusBias);
  sc->BindLocalFloat(_BlurScreenRadius,1,&para->BlurScreenRadius);
  sc->BindLocalFloat(_BlurScreenAmp,1,&para->BlurScreenAmp);
};

void GenBitmapAnimTronFont::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimTronFont::Bind(class ScriptContext *sc,GenBitmapParaTronFont *para)
{
};

void Wz4MeshAnimTronPrint::Init(class ScriptContext *sc)
{
};

void Wz4MeshAnimTronPrint::Bind(class ScriptContext *sc,Wz4MeshParaTronPrint *para)
{
};


/****************************************************************************/

void AddTypes_tron_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_tron_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"PlaceOnMesh";
  cl->Label = L"PlaceOnMesh";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdPlaceOnMesh;
  cl->MakeGui = Wz4ParticlesGuiPlaceOnMesh;
  cl->SetDefaults = Wz4ParticlesDefPlaceOnMesh;
  cl->BindPara = Wz4ParticlesBindPlaceOnMesh;
  cl->Bind2Para = Wz4ParticlesBind2PlaceOnMesh;
  cl->Bind3Para = Wz4ParticlesBind3PlaceOnMesh;
  cl->WikiText = Wz4ParticlesWikiPlaceOnMesh;
  cl->Handles = Wz4ParticlesHndPlaceOnMesh;
  cl->ParaWords = 6;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SingleForceField";
  cl->Label = L"SingleForceField";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdSingleForceField;
  cl->MakeGui = Wz4ParticlesGuiSingleForceField;
  cl->SetDefaults = Wz4ParticlesDefSingleForceField;
  cl->BindPara = Wz4ParticlesBindSingleForceField;
  cl->Bind2Para = Wz4ParticlesBind2SingleForceField;
  cl->Bind3Para = Wz4ParticlesBind3SingleForceField;
  cl->WikiText = Wz4ParticlesWikiSingleForceField;
  cl->Handles = Wz4ParticlesHndSingleForceField;
  cl->ParaStrings = 1;
  cl->ParaWords = 13;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4ParticlesType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Retexturizer";
  cl->Label = L"Retexturizer";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdRetexturizer;
  cl->MakeGui = Wz4MeshGuiRetexturizer;
  cl->SetDefaults = Wz4MeshDefRetexturizer;
  cl->BindPara = Wz4MeshBindRetexturizer;
  cl->Bind2Para = Wz4MeshBind2Retexturizer;
  cl->Bind3Para = Wz4MeshBind3Retexturizer;
  cl->WikiText = Wz4MeshWikiRetexturizer;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR033_MeteorShowerSim";
  cl->Label = L"FR033_MeteorShowerSim";
  cl->OutputType = Wz4ParticlesType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4ParticlesCmdFR033_MeteorShowerSim;
  cl->MakeGui = Wz4ParticlesGuiFR033_MeteorShowerSim;
  cl->SetDefaults = Wz4ParticlesDefFR033_MeteorShowerSim;
  cl->BindPara = Wz4ParticlesBindFR033_MeteorShowerSim;
  cl->Bind2Para = Wz4ParticlesBind2FR033_MeteorShowerSim;
  cl->Bind3Para = Wz4ParticlesBind3FR033_MeteorShowerSim;
  cl->WikiText = Wz4ParticlesWikiFR033_MeteorShowerSim;
  cl->ParaWords = 18;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GroupTypeType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FR033_WaterSimRender";
  cl->Label = L"FR033_WaterSimRender";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFR033_WaterSimRender;
  cl->MakeGui = Wz4RenderGuiFR033_WaterSimRender;
  cl->SetDefaults = Wz4RenderDefFR033_WaterSimRender;
  cl->BindPara = Wz4RenderBindFR033_WaterSimRender;
  cl->Bind2Para = Wz4RenderBind2FR033_WaterSimRender;
  cl->Bind3Para = Wz4RenderBind3FR033_WaterSimRender;
  cl->WikiText = Wz4RenderWikiFR033_WaterSimRender;
  cl->ParaWords = 28;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(3);
  in[0].Type = Wz4MtrlType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Texture2DType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = Wz4ParticlesType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sharpen";
  cl->Label = L"Sharpen";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSharpen;
  cl->MakeGui = Wz4RenderGuiSharpen;
  cl->SetDefaults = Wz4RenderDefSharpen;
  cl->BindPara = Wz4RenderBindSharpen;
  cl->Bind2Para = Wz4RenderBind2Sharpen;
  cl->Bind3Para = Wz4RenderBind3Sharpen;
  cl->WikiText = Wz4RenderWikiSharpen;
  cl->ParaStrings = 1;
  cl->ParaWords = 1;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SBlur";
  cl->Label = L"SBlur";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdSBlur;
  cl->MakeGui = Wz4RenderGuiSBlur;
  cl->SetDefaults = Wz4RenderDefSBlur;
  cl->BindPara = Wz4RenderBindSBlur;
  cl->Bind2Para = Wz4RenderBind2SBlur;
  cl->Bind3Para = Wz4RenderBind3SBlur;
  cl->WikiText = Wz4RenderWikiSBlur;
  cl->ParaWords = 3;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bloom";
  cl->Label = L"Bloom";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdBloom;
  cl->MakeGui = Wz4RenderGuiBloom;
  cl->SetDefaults = Wz4RenderDefBloom;
  cl->BindPara = Wz4RenderBindBloom;
  cl->Bind2Para = Wz4RenderBind2Bloom;
  cl->Bind3Para = Wz4RenderBind3Bloom;
  cl->WikiText = Wz4RenderWikiBloom;
  cl->ParaStrings = 1;
  cl->ParaWords = 29;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Promist";
  cl->Label = L"Promist";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdPromist;
  cl->MakeGui = Wz4RenderGuiPromist;
  cl->SetDefaults = Wz4RenderDefPromist;
  cl->BindPara = Wz4RenderBindPromist;
  cl->Bind2Para = Wz4RenderBind2Promist;
  cl->Bind3Para = Wz4RenderBind3Promist;
  cl->WikiText = Wz4RenderWikiPromist;
  cl->ParaStrings = 1;
  cl->ParaWords = 28;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DepthOfField3";
  cl->Label = L"DepthOfField3";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdDepthOfField3;
  cl->MakeGui = Wz4RenderGuiDepthOfField3;
  cl->SetDefaults = Wz4RenderDefDepthOfField3;
  cl->BindPara = Wz4RenderBindDepthOfField3;
  cl->Bind2Para = Wz4RenderBind2DepthOfField3;
  cl->Bind3Para = Wz4RenderBind3DepthOfField3;
  cl->WikiText = Wz4RenderWikiDepthOfField3;
  cl->ParaStrings = 1;
  cl->ParaWords = 12;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Glow";
  cl->Label = L"Glow";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdGlow;
  cl->MakeGui = Wz4RenderGuiGlow;
  cl->SetDefaults = Wz4RenderDefGlow;
  cl->BindPara = Wz4RenderBindGlow;
  cl->Bind2Para = Wz4RenderBind2Glow;
  cl->Bind3Para = Wz4RenderBind3Glow;
  cl->WikiText = Wz4RenderWikiGlow;
  cl->ParaStrings = 1;
  cl->ParaWords = 12;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FocusBlur";
  cl->Label = L"FocusBlur";
  cl->OutputType = Wz4RenderType;
  cl->TabType = Wz4RenderType;
  cl->Command = Wz4RenderCmdFocusBlur;
  cl->MakeGui = Wz4RenderGuiFocusBlur;
  cl->SetDefaults = Wz4RenderDefFocusBlur;
  cl->BindPara = Wz4RenderBindFocusBlur;
  cl->Bind2Para = Wz4RenderBind2FocusBlur;
  cl->Bind3Para = Wz4RenderBind3FocusBlur;
  cl->WikiText = Wz4RenderWikiFocusBlur;
  cl->ParaStrings = 1;
  cl->ParaWords = 6;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4RenderType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TronFont";
  cl->Label = L"TronFont";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdTronFont;
  cl->MakeGui = GenBitmapGuiTronFont;
  cl->SetDefaults = GenBitmapDefTronFont;
  cl->BindPara = GenBitmapBindTronFont;
  cl->Bind2Para = GenBitmapBind2TronFont;
  cl->Bind3Para = GenBitmapBind3TronFont;
  cl->WikiText = GenBitmapWikiTronFont;
  cl->ParaStrings = 2;
  cl->ParaWords = 9;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TronPrint";
  cl->Label = L"TronPrint";
  cl->OutputType = Wz4MeshType;
  cl->TabType = Wz4MeshType;
  cl->Command = Wz4MeshCmdTronPrint;
  cl->MakeGui = Wz4MeshGuiTronPrint;
  cl->SetDefaults = Wz4MeshDefTronPrint;
  cl->BindPara = Wz4MeshBindTronPrint;
  cl->Bind2Para = Wz4MeshBind2TronPrint;
  cl->Bind3Para = Wz4MeshBind3TronPrint;
  cl->WikiText = Wz4MeshWikiTronPrint;
  cl->ParaStrings = 2;
  cl->ParaWords = 5;
  cl->Column = 1;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(tron_ops,0x110,AddOps_tron_ops,0);


/****************************************************************************/


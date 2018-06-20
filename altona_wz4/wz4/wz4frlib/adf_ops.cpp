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
#include "adf_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class Wz4ADFType_ *Wz4ADFType;

/****************************************************************************/

#line 14 "adf_ops.ops"

#include "wz4frlib/adf.hpp"
#include "wz4frlib/adf_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"

#line 29 "adf_ops.cpp"

/****************************************************************************/

#line 34 "adf_ops.ops"
void Wz4ADFType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 35 "adf_ops.ops"

    if(obj && obj->IsType(Wz4ADFType))
    {     
    
      static const sInt downsample = 1;
      sInt tgtSizeX = sMin(pi.Client.SizeX()/downsample,512);
      sInt tgtSizeY = sMin(pi.Client.SizeY()/downsample,512);

      if(tgtSizeX != img->SizeX || tgtSizeY != img->SizeY)
      {
        delete img;
        img = new sImage(tgtSizeX,tgtSizeY);      
        Wz4ADF_Init(tgtSizeX,tgtSizeY);        
      }

      Wz4ADF *adf = (Wz4ADF *) obj;
      //img->Fill(pi.BackColor);
      
      Wz4ADF_Render(img, adf, pi);

      sRect srcRect(0,0,img->SizeX,img->SizeY);
      sStretch2D(img->Data,img->SizeX,srcRect,pi.Client);                       
    }    
  ;
#line 61 "adf_ops.cpp"
}
#line 60 "adf_ops.ops"
void Wz4ADFType_::Init()
{
#line 61 "adf_ops.ops"

    img = new sImage(128,128);
    Wz4ADF_Init(128,128);
  ;
#line 71 "adf_ops.cpp"
}
#line 66 "adf_ops.ops"
void Wz4ADFType_::Exit()
{
#line 67 "adf_ops.ops"

    sDelete(img);
    Wz4ADF_Exit();
  ;
#line 81 "adf_ops.cpp"
}

/****************************************************************************/

sBool Wz4ADFCmdImport(wExecutive *exe,wCommand *cmd)
{
  Wz4ADFParaImport sUNUSED *para = (Wz4ADFParaImport *)(cmd->Data); para;
  Wz4ADF *out = (Wz4ADF *) cmd->Output;
  if(!out) { out=new Wz4ADF; cmd->Output=out; }

  {
#line 84 "adf_ops.ops"
   
    const sChar *name = cmd->Strings[0];
    const sChar *ext = sFindFileExtension(name);
//    if(sCmpStringI(ext,L"sdf")==0)
    if (sCmpStringI(name,L"")!=0)
    {
       out->FromFile((sChar *)name);
    }   
  ;
#line 103 "adf_ops.cpp"
    return 1;
  }
}

void Wz4ADFGuiImport(wGridFrameHelper &gh,wOp *op)
{
  Wz4ADFParaImport sUNUSED *para = (Wz4ADFParaImport *)(op->EditData); para;
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
}

void Wz4ADFDefImport(wOp *op)
{
  Wz4ADFParaImport sUNUSED *para = (Wz4ADFParaImport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Wz4ADFBindImport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void Wz4ADFBind2Import(wCommand *cmd,ScriptContext *ctx)
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
void Wz4ADFBind3Import(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *Wz4ADFWikiImport =
L"= Wz4ADF : Import\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Import\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4ADF\n"
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
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool Wz4ADFCmdFromMesh(wExecutive *exe,wCommand *cmd)
{
  Wz4ADFParaFromMesh sUNUSED *para = (Wz4ADFParaFromMesh *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  Wz4Mesh sUNUSED *in1 = cmd->GetInput<Wz4Mesh *>(1); in1;
  Wz4ADF *out = (Wz4ADF *) cmd->Output;
  if(!out) { out=new Wz4ADF; cmd->Output=out; }

  {
#line 113 "adf_ops.ops"
     
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

    sVector31 bp=para->BoxPos; 
    sVector30 bdh=para->BoxDimH;        
    if(para->UserBox && in1)
    {
      sAABBox box;
      in1->CalcBBox(box);           
      bdh=(box.Max-box.Min)*0.5f;
      bp=box.Min+bdh;
    }
    Wz4BSPError err = out->FromMesh(in0, thick[sClamp<sInt>(para->PlaneThickness,0,6)], para->Depth, para->GuardBand, para->ForceCubeSampling, para->UserBox,bp,bdh,para->BruteForce);    
    if(err != WZ4BSP_OK)
    {
      cmd->SetError(Wz4BSPGetErrorString(err));
      return 0;
    }    
  ;
#line 229 "adf_ops.cpp"
    return 1;
  }
}

void Wz4ADFGuiFromMesh(wGridFrameHelper &gh,wOp *op)
{
  Wz4ADFParaFromMesh sUNUSED *para = (Wz4ADFParaFromMesh *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Depth");
  gh.Flags(&para->Depth,L"|||| 4| 5| 6| 7| 8| 9| 10| 11",gh.ChangeMsg);

  gh.Label(L"GuardBand");
  sFloatControl *float_GuardBand = gh.Float(&para->GuardBand,-64.0000f,64.00000f,0.001000f);
  float_GuardBand->Default = 0.000000f; float_GuardBand->RightStep = 0.125000f;

  gh.Label(L"ForceCubeSampling");
  gh.Flags(&para->ForceCubeSampling,L"Off|On",gh.LayoutMsg);

  gh.Label(L"UserBox");
  gh.Flags(&para->UserBox,L"Off|On",gh.LayoutMsg);

  gh.Label(L"BoxPos");
  gh.BeginTied();
  sFloatControl *float_BoxPos_0 = gh.Float(&para->BoxPos.x,-1024.00f,1024.000f,0.000100f);
  float_BoxPos_0->Default = 0.000000f; float_BoxPos_0->RightStep = 0.125000f;
  sFloatControl *float_BoxPos_1 = gh.Float(&para->BoxPos.y,-1024.00f,1024.000f,0.000100f);
  float_BoxPos_1->Default = 0.000000f; float_BoxPos_1->RightStep = 0.125000f;
  sFloatControl *float_BoxPos_2 = gh.Float(&para->BoxPos.z,-1024.00f,1024.000f,0.000100f);
  float_BoxPos_2->Default = 0.000000f; float_BoxPos_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"BoxDimH");
  gh.BeginTied();
  sFloatControl *float_BoxDimH_0 = gh.Float(&para->BoxDimH.x,0.000100f,1024.000f,0.000100f);
  float_BoxDimH_0->Default = 0.000000f; float_BoxDimH_0->RightStep = 0.125000f;
  sFloatControl *float_BoxDimH_1 = gh.Float(&para->BoxDimH.y,0.000100f,1024.000f,0.000100f);
  float_BoxDimH_1->Default = 0.000000f; float_BoxDimH_1->RightStep = 0.125000f;
  sFloatControl *float_BoxDimH_2 = gh.Float(&para->BoxDimH.z,0.000100f,1024.000f,0.000100f);
  float_BoxDimH_2->Default = 0.000000f; float_BoxDimH_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"BruteForce");
  gh.Flags(&para->BruteForce,L"Off|On",gh.LayoutMsg);

  gh.Label(L"Plane thickness (epsilon)");
  gh.Flags(&para->PlaneThickness,L"Molecular|Tiny|Small|Normal|Large|Huge|San Andreas Gap|Ridiculous",gh.ChangeMsg);
}

void Wz4ADFDefFromMesh(wOp *op)
{
  Wz4ADFParaFromMesh sUNUSED *para = (Wz4ADFParaFromMesh *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Depth = 0x00000004;
  para->PlaneThickness = 0x00000003;
}

void Wz4ADFBindFromMesh(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"guardband"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"boxpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"boxpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"boxpos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"boxdimh"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"boxdimh"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"boxdimh"),val);
}
void Wz4ADFBind2FromMesh(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"depth");
    name[1] = sPoolString(L"guardband");
    name[2] = sPoolString(L"forcecubesampling");
    name[3] = sPoolString(L"userbox");
    name[4] = sPoolString(L"boxpos");
    name[5] = sPoolString(L"boxdimh");
    name[6] = sPoolString(L"bruteforce");
    name[7] = sPoolString(L"planethickness");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[4],ScriptTypeFloat,3,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+7);
}
void Wz4ADFBind3FromMesh(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import guardband : float;\n");
  tb.PrintF(L"  import boxpos : float[3];\n");
  tb.PrintF(L"  import boxdimh : float[3];\n");
}
const sChar *Wz4ADFWikiFromMesh =
L"= Wz4ADF : FromMesh\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i FromMesh\n"
L"\n"
L"  !i Output Type\n"
L"  !i Wz4ADF\n"
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
L" !i Depth\n"
L" !i Depth\n"
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
L" !i \n"
L" !i \n"
L" !i 9\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 10\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 11\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i GuardBand\n"
L" !i GuardBand\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ForceCubeSampling\n"
L" !i ForceCubeSampling\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UserBox\n"
L" !i UserBox\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i BoxPos\n"
L" !i BoxPos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i BoxDimH\n"
L" !i BoxDimH\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i BruteForce\n"
L" !i BruteForce\n"
L" !i Off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i On\n"
L" !i *\n"
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

void Wz4ADFAnimImport::Init(class ScriptContext *sc)
{
};

void Wz4ADFAnimImport::Bind(class ScriptContext *sc,Wz4ADFParaImport *para)
{
};

void Wz4ADFAnimFromMesh::Init(class ScriptContext *sc)
{
};

void Wz4ADFAnimFromMesh::Bind(class ScriptContext *sc,Wz4ADFParaFromMesh *para)
{
};


/****************************************************************************/

void AddTypes_adf_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(Wz4ADFType = new Wz4ADFType_);
  Wz4ADFType->Secondary = secondary;
  Wz4ADFType->ColumnHeaders[0] = L"Generator";
  Wz4ADFType->ColumnHeaders[1] = L"Filter";

}

/****************************************************************************/

void AddOps_adf_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Import";
  cl->Label = L"Import";
  cl->OutputType = Wz4ADFType;
  cl->TabType = Wz4ADFType;
  cl->Command = Wz4ADFCmdImport;
  cl->MakeGui = Wz4ADFGuiImport;
  cl->SetDefaults = Wz4ADFDefImport;
  cl->BindPara = Wz4ADFBindImport;
  cl->Bind2Para = Wz4ADFBind2Import;
  cl->Bind3Para = Wz4ADFBind3Import;
  cl->WikiText = Wz4ADFWikiImport;
  cl->ParaStrings = 1;
  cl->FileInMask = 1;
  cl->FileInFilter = L"sdf";
  cl->Shortcut = 'i';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"FromMesh";
  cl->Label = L"FromMesh";
  cl->OutputType = Wz4ADFType;
  cl->TabType = Wz4ADFType;
  cl->Command = Wz4ADFCmdFromMesh;
  cl->MakeGui = Wz4ADFGuiFromMesh;
  cl->SetDefaults = Wz4ADFDefFromMesh;
  cl->BindPara = Wz4ADFBindFromMesh;
  cl->Bind2Para = Wz4ADFBind2FromMesh;
  cl->Bind3Para = Wz4ADFBind3FromMesh;
  cl->WikiText = Wz4ADFWikiFromMesh;
  cl->ParaWords = 12;
  cl->Shortcut = 'm';
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = Wz4MeshType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(adf_ops,0x110,AddOps_adf_ops,0);


/****************************************************************************/


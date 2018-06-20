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
#include "wz3_bitmap_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/

class GenBitmapType_ *GenBitmapType;

/****************************************************************************/

#line 9 "wz3_bitmap_ops.ops"

  #include "wz4frlib/wz3_bitmap_code.hpp"
  #include "wz4lib/poc_ops.hpp"
  void xInitPerlin();

#line 29 "wz3_bitmap_ops.cpp"

/****************************************************************************/

#line 37 "wz3_bitmap_ops.ops"
void GenBitmapType_::Init()
{
#line 38 "wz3_bitmap_ops.ops"

    xInitPerlin();
  ;
#line 40 "wz3_bitmap_ops.cpp"
}
#line 42 "wz3_bitmap_ops.ops"
void GenBitmapType_::Show(wObject *obj,wPaintInfo &pi)
{
#line 43 "wz3_bitmap_ops.ops"

    ((GenBitmap *)obj)->CopyTo(pi.Image);

    pi.SetSizeTex2D(pi.Image->SizeX,pi.Image->SizeY);
    pi.PaintTex2D(pi.Image);
    pi.PaintHandles();
  ;
#line 53 "wz3_bitmap_ops.cpp"
}

/****************************************************************************/

sBool GenBitmapCmdMakeWz3Bitmap(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaMakeWz3Bitmap sUNUSED *para = (GenBitmapParaMakeWz3Bitmap *)(cmd->Data); para;
  BitmapBase sUNUSED *in0 = cmd->GetInput<BitmapBase *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 58 "wz3_bitmap_ops.ops"

    sImage img;
    in0->CopyTo(&img);
    out->Init(&img);
  ;
#line 72 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiMakeWz3Bitmap(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaMakeWz3Bitmap sUNUSED *para = (GenBitmapParaMakeWz3Bitmap *)(op->EditData); para;
}

void GenBitmapDefMakeWz3Bitmap(wOp *op)
{
  GenBitmapParaMakeWz3Bitmap sUNUSED *para = (GenBitmapParaMakeWz3Bitmap *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindMakeWz3Bitmap(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2MakeWz3Bitmap(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind3MakeWz3Bitmap(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiMakeWz3Bitmap =
L"= GenBitmap : MakeWz3Bitmap\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MakeWz3Bitmap\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i BitmapBase\n"
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

sBool Texture2DCmdMakeTexture2(wExecutive *exe,wCommand *cmd)
{
  Texture2DParaMakeTexture2 sUNUSED *para = (Texture2DParaMakeTexture2 *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  Texture2D *out = (Texture2D *) cmd->Output;
  if(!out) { out=new Texture2D; cmd->Output=out; }

  {
#line 76 "wz3_bitmap_ops.ops"

    static sInt modes[] = 
    { 
      0,sTEX_ARGB8888,sTEX_A8,sTEX_I8,sTEX_DXT1,sTEX_DXT1A,sTEX_DXT3,sTEX_DXT5,sTEX_R16F,sTEX_R32F,sTEX_ARGB16F,sTEX_ARGB32F
    };

    sInt format = modes[para->Format];
    sImage *img;
    switch(format)
    {
    case sTEX_R16F:
      {
        sImageData *id = new sImageData;
        id->Init2(format|sTEX_2D,1,in0->XSize,in0->YSize,1);
        sU64 *s = (sU64 *)in0->Data;
        sU16 *d = (sU16 *)id->Data;
        for(sInt i=0;i<in0->XSize*in0->YSize;i++)
        {
          sU64 v = s[i]; 
          d[i] = sFloatToHalf(((v>>32)&0x7fff)/sF32(0x7fff));
        }
        out->ConvertFrom(id);
      }
      break;
    case sTEX_ARGB16F:
      {        
        sImageData *id = new sImageData;
        id->Init2(format|sTEX_2D,1,in0->XSize,in0->YSize,1);
        sU64 *s = (sU64 *)in0->Data;
        sU16 *d = (sU16 *)id->Data;
        for(sInt i=0;i<in0->XSize*in0->YSize;i++)
        {
          sU64 v = s[i]; 
          d[i*4+0] = sFloatToHalf(((v>>32)&0x7fff)/sF32(0x7fff));
          d[i*4+1] = sFloatToHalf(((v>> 8)&0x7fff)/sF32(0x7fff));
          d[i*4+2] = sFloatToHalf(((v>> 0)&0x7fff)/sF32(0x7fff));
          d[i*4+3] = sFloatToHalf(((v>>48)&0x7fff)/sF32(0x7fff));
        }
        out->ConvertFrom(id);
      }
      break;
    case sTEX_R32F:
      {
        sImageData *id = new sImageData;
        id->Init2(format|sTEX_2D,1,in0->XSize,in0->YSize,1);
        sU64 *s = (sU64 *)in0->Data;
        sF32 *d = (sF32 *)id->Data;
        for(sInt i=0;i<in0->XSize*in0->YSize;i++)
        {
          sU64 v = s[i]; 
          d[i] = (((v>>32)&0x7fff)/sF32(0x7fff));
        }
        out->ConvertFrom(id);
      }
      break;
    case sTEX_ARGB32F:
      {
        sImageData *id = new sImageData;
        id->Init2(format|sTEX_2D,1,in0->XSize,in0->YSize,1);
        sU64 *s = (sU64 *)in0->Data;
        sF32 *d = (sF32 *)id->Data;
        for(sInt i=0;i<in0->XSize*in0->YSize;i++)
        {
          sU64 v = s[i]; 
          d[i*4+0] = (((v>>32)&0x7fff)/sF32(0x7fff));
          d[i*4+1] = (((v>> 8)&0x7fff)/sF32(0x7fff));
          d[i*4+2] = (((v>> 0)&0x7fff)/sF32(0x7fff));
          d[i*4+3] = (((v>>48)&0x7fff)/sF32(0x7fff));
        }
        out->ConvertFrom(id);
      }
      break;
    default:
      img = new sImage;
      in0->CopyTo(img);
      if(format==0)
      {
        if(Doc->DocOptions.TextureQuality>0)
        {
          if(img->HasAlpha())
            format = sTEX_DXT5;
          else
            format = sTEX_DXT1;
        }
        else
          format = sTEX_ARGB8888;
        if(Doc->DocOptions.TextureQuality>1)
        {
          sImage *x = img->Half();
          delete img;
          img = x;
        }
      }

      out->ConvertFrom(img,format|sTEX_2D);
      delete img;
    }
    out->Atlas=in0->Atlas;
    return 1;
  ;
#line 241 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void Texture2DGuiMakeTexture2(wGridFrameHelper &gh,wOp *op)
{
  Texture2DParaMakeTexture2 sUNUSED *para = (Texture2DParaMakeTexture2 *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Format");
  gh.Flags(&para->Format,L"default|argb8888|a8|i8|DXT1|DXT1A|DXT3|DXT5|R16F|R32F|ARGB16F|ARGB32F",gh.ChangeMsg);
}

void Texture2DDefMakeTexture2(wOp *op)
{
  Texture2DParaMakeTexture2 sUNUSED *para = (Texture2DParaMakeTexture2 *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void Texture2DBindMakeTexture2(wCommand *cmd,ScriptContext *ctx)
{
}
void Texture2DBind2MakeTexture2(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"format");
  }
}
void Texture2DBind3MakeTexture2(wOp *op,sTextBuffer &tb)
{
}
const sChar *Texture2DWikiMakeTexture2 =
L"= Texture2D : MakeTexture2\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i MakeTexture2\n"
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
L" !i GenBitmap\n"
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
L" !i Format\n"
L" !i Format\n"
L" !i default\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i argb8888\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i i8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i DXT1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i DXT1A\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i DXT3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i DXT5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i R16F\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i R32F\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ARGB16F\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ARGB32F\n"
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

sBool UnitTestCmdUnitTestBitmap(wExecutive *exe,wCommand *cmd)
{
  UnitTestParaUnitTestBitmap sUNUSED *para = (UnitTestParaUnitTestBitmap *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  UnitTest *out = (UnitTest *) cmd->Output;
  if(!out) { out=new UnitTest; cmd->Output=out; }

  {
#line 190 "wz3_bitmap_ops.ops"

    sImage img;
    in0->CopyTo(&img);
    return out->Test(img,cmd->Strings[0],para->Flags);
  ;
#line 385 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void UnitTestGuiUnitTestBitmap(wGridFrameHelper &gh,wOp *op)
{
  UnitTestParaUnitTestBitmap sUNUSED *para = (UnitTestParaUnitTestBitmap *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"TestName");
  {
    sControl *con = gh.String(op->EditString[0]);
    con->DoneMsg = con->ChangeMsg;
    con->ChangeMsg = sMessage();
    gh.FileSaveDialogMsg.Code = 0;
    gh.Box(L"...",gh.FileSaveDialogMsg);
  }

  gh.Label(L"Always Pass");
  gh.Flags(&para->Flags,L"-|compare:*1-|cross compare",gh.ChangeMsg);
}

void UnitTestDefUnitTestBitmap(wOp *op)
{
  UnitTestParaUnitTestBitmap sUNUSED *para = (UnitTestParaUnitTestBitmap *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void UnitTestBindUnitTestBitmap(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"testname"),val);
}
void UnitTestBind2UnitTestBitmap(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"testname");
    name[1] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeString,1,cmd->Strings+0);
}
void UnitTestBind3UnitTestBitmap(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import testname : string;\n");
}
const sChar *UnitTestWikiUnitTestBitmap =
L"= UnitTest : UnitTestBitmap\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i UnitTestBitmap\n"
L"\n"
L"  !i Output Type\n"
L"  !i UnitTest\n"
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
L" !i TestName\n"
L" !i TestName\n"
L" !i save file\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Always Pass\n"
L" !i Flags\n"
L" !i compare\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i cross compare\n"
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

sBool GenBitmapCmdFlat(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaFlat sUNUSED *para = (GenBitmapParaFlat *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 215 "wz3_bitmap_ops.ops"

    out->Init(1<<(para->Size&0xff),1<<((para->Size>>8)&0xff));
    out->Flat(para->Color);
  ;
#line 513 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiFlat(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaFlat sUNUSED *para = (GenBitmapParaFlat *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);
}

void GenBitmapDefFlat(wOp *op)
{
  GenBitmapParaFlat sUNUSED *para = (GenBitmapParaFlat *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Color = 0xff000000;
}

void GenBitmapBindFlat(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
}
void GenBitmapBind2Flat(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"color_");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
}
void GenBitmapBind3Flat(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
}
const sChar *GenBitmapWikiFlat =
L"= GenBitmap : Flat\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Flat\n"
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
L" !i Color\n"
L" !i Color\n"
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

sBool GenBitmapCmdPerlin(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaPerlin sUNUSED *para = (GenBitmapParaPerlin *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 244 "wz3_bitmap_ops.ops"

    out->Init(1<<(para->Size&0xff),1<<((para->Size>>8)&0xff));
    out->Perlin(para->Frequency,para->Octaves,para->FadeOff,para->Seed,para->Mode,para->Amplify,para->Gamma,para->Color0,para->Color1);
  ;
#line 730 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiPerlin(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaPerlin sUNUSED *para = (GenBitmapParaPerlin *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Frequency");
  sIntControl *int_Frequency = gh.Int(&para->Frequency,0,16,0.125000f);
  int_Frequency->Default = 0x00000001; int_Frequency->RightStep = 0.125000f;

  gh.Label(L"Octaves");
  sIntControl *int_Octaves = gh.Int(&para->Octaves,0,16,0.125000f);
  int_Octaves->Default = 0x00000002; int_Octaves->RightStep = 0.125000f;

  gh.Label(L"FadeOff");
  sFloatControl *float_FadeOff = gh.Float(&para->FadeOff,-8.00000f,8.000000f,0.010000f);
  float_FadeOff->Default = 1.000000f; float_FadeOff->RightStep = 0.125000f;

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"-|abs:*1-|sin",gh.ChangeMsg);

  gh.Label(L"Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,0.000000f,16.00000f,0.010000f);
  float_Amplify->Default = 1.000000f; float_Amplify->RightStep = 0.125000f;

  gh.Label(L"Gamma");
  sFloatControl *float_Gamma = gh.Float(&para->Gamma,0.000000f,16.00000f,0.010000f);
  float_Gamma->Default = 1.000000f; float_Gamma->RightStep = 0.125000f;

  gh.Label(L"Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  gh.Label(L"Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);
}

void GenBitmapDefPerlin(wOp *op)
{
  GenBitmapParaPerlin sUNUSED *para = (GenBitmapParaPerlin *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Frequency = 0x00000001;
  para->Octaves = 0x00000002;
  para->FadeOff = 1.000000f;
  para->Seed = 0x00000001;
  para->Amplify = 1.000000f;
  para->Gamma = 1.000000f;
  para->Color0 = 0xff000000;
  para->Color1 = 0xffffffff;
}

void GenBitmapBindPerlin(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"frequency"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"octaves"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"fadeoff"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
}
void GenBitmapBind2Perlin(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"frequency");
    name[2] = sPoolString(L"octaves");
    name[3] = sPoolString(L"fadeoff");
    name[4] = sPoolString(L"seed");
    name[5] = sPoolString(L"mode");
    name[6] = sPoolString(L"amplify");
    name[7] = sPoolString(L"gamma");
    name[8] = sPoolString(L"color0");
    name[9] = sPoolString(L"color1");
  }
  ctx->AddImport(name[1],ScriptTypeInt,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeInt,1,cmd->Data+4);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeColor,1,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeColor,1,cmd->Data+9);
}
void GenBitmapBind3Perlin(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import frequency : int;\n");
  tb.PrintF(L"  import octaves : int;\n");
  tb.PrintF(L"  import fadeoff : float;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import amplify : float;\n");
  tb.PrintF(L"  import gamma : float;\n");
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color1 : color;\n");
}
const sChar *GenBitmapWikiPerlin =
L"= GenBitmap : Perlin\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Perlin\n"
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
L" !i Frequency\n"
L" !i Frequency\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Octaves\n"
L" !i Octaves\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i FadeOff\n"
L" !i FadeOff\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i abs\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i sin\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Amplify\n"
L" !i Amplify\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gamma\n"
L" !i Gamma\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
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

sBool GenBitmapCmdCell(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaCell sUNUSED *para = (GenBitmapParaCell *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 274 "wz3_bitmap_ops.ops"

    out->Init(1<<(para->Size&0xff),1<<((para->Size>>8)&0xff));
    out->Cell(para->Color0,para->Color1,para->Color2,para->Max,para->Seed,
              para->Amplify,para->Gamma,para->Mode,para->MinDistance,para->Percentage,para->Aspect);
  ;
#line 1078 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiCell(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaCell sUNUSED *para = (GenBitmapParaCell *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  gh.Label(L"Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);

  gh.Label(L"Max");
  sIntControl *int_Max = gh.Int(&para->Max,2,255,0.250000f);
  int_Max->Default = 0x000000ff; int_Max->RightStep = 0.125000f;

  gh.Label(L"MinDistance");
  sFloatControl *float_MinDistance = gh.Float(&para->MinDistance,0.000000f,1.000000f,0.001000f);
  float_MinDistance->Default = 0.125000f; float_MinDistance->RightStep = 0.125000f;

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;

  gh.Label(L"Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,0.000000f,16.00000f,0.001000f);
  float_Amplify->Default = 1.000000f; float_Amplify->RightStep = 0.125000f;

  gh.Label(L"Gamma");
  sFloatControl *float_Gamma = gh.Float(&para->Gamma,0.000000f,16.00000f,0.001000f);
  float_Gamma->Default = 0.500000f; float_Gamma->RightStep = 0.125000f;

  gh.Label(L"Aspect");
  sFloatControl *float_Aspect = gh.Float(&para->Aspect,-8.00000f,8.000000f,0.010000f);
  float_Aspect->Default = 0.000000f; float_Aspect->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"inner|outer:*1-|cell-color:*2-|invert",gh.ChangeMsg);

  gh.Group(L"Cell-Color-Mode");

  gh.Label(L"Color2");
  gh.ColorPick(&para->Color2,L"rgba",0);

  gh.Label(L"Percentage");
  sIntControl *int_Percentage = gh.Int(&para->Percentage,0,255,0.125000f);
  int_Percentage->Default = 0x00000000; int_Percentage->RightStep = 0.125000f;
}

void GenBitmapDefCell(wOp *op)
{
  GenBitmapParaCell sUNUSED *para = (GenBitmapParaCell *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Color0 = 0xffff0000;
  para->Color1 = 0xffffff00;
  para->Max = 0x000000ff;
  para->MinDistance = 0.125000f;
  para->Seed = 0x00000001;
  para->Amplify = 1.000000f;
  para->Gamma = 0.500000f;
  para->Mode = 0x00000007;
  para->Color2 = 0xff000000;
}

void GenBitmapBindCell(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"max"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"mindistance"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"aspect"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"color2"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"percentage"),val);
}
void GenBitmapBind2Cell(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[13];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"color0");
    name[2] = sPoolString(L"color1");
    name[3] = sPoolString(L"max");
    name[4] = sPoolString(L"mindistance");
    name[5] = sPoolString(L"seed");
    name[6] = sPoolString(L"amplify");
    name[7] = sPoolString(L"gamma");
    name[8] = sPoolString(L"aspect");
    name[9] = sPoolString(L"mode");
    name[10] = sPoolString(L"");
    name[11] = sPoolString(L"color2");
    name[12] = sPoolString(L"percentage");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeInt,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[11],ScriptTypeColor,1,cmd->Data+10);
  ctx->AddImport(name[12],ScriptTypeInt,1,cmd->Data+11);
}
void GenBitmapBind3Cell(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import max : int;\n");
  tb.PrintF(L"  import mindistance : float;\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import amplify : float;\n");
  tb.PrintF(L"  import gamma : float;\n");
  tb.PrintF(L"  import aspect : float;\n");
  tb.PrintF(L"  import color2 : color;\n");
  tb.PrintF(L"  import percentage : int;\n");
}
const sChar *GenBitmapWikiCell =
L"= GenBitmap : Cell\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Cell\n"
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
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Max\n"
L" !i Max\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i MinDistance\n"
L" !i MinDistance\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Gamma\n"
L" !i Gamma\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Aspect\n"
L" !i Aspect\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i inner\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i outer\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i cell-color\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i invert\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color2\n"
L" !i Color2\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Percentage\n"
L" !i Percentage\n"
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

sBool GenBitmapCmdGradient(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaGradient sUNUSED *para = (GenBitmapParaGradient *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 299 "wz3_bitmap_ops.ops"

    out->Init(1<<(para->Size&0xff),1<<((para->Size>>8)&0xff));

    GenBitmapGradientPoint *g = new GenBitmapGradientPoint[cmd->ArrayCount];
    GenBitmapArrayGradient *a = (GenBitmapArrayGradient *) cmd->Array;
    for(sInt i=0;i<cmd->ArrayCount;i++)
    {
      g[i].Pos = a[i].Pos;
      g[i].Color.InitColor(a[i].Color);
    }
    out->Gradient(g,cmd->ArrayCount,para->Flags);
    delete[] g;
  ;
#line 1480 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapArrGradient(wOp *op,sInt pos,void *mem)
{
  GenBitmapParaGradient sUNUSED *para = (GenBitmapParaGradient *)(op->EditData); para;
  GenBitmapArrayGradient *e = (GenBitmapArrayGradient *)(mem);
  e->Pos = 0.000000f;
  e->Color = 0x00000000;
  sInt max = op->ArrayData.GetCount();
  if(max>=1)
  {
    GenBitmapArrayGradient *p0,*p1;
    sF32 f0,f1;
    if(max==1)
    {
      f0 =  1; p0 = (GenBitmapArrayGradient *)op->ArrayData[0];
      f1 =  0; p1 = (GenBitmapArrayGradient *)op->ArrayData[0];
    }
    else if(pos==0)
    {
      f0 =  2; p0 = (GenBitmapArrayGradient *)op->ArrayData[0];
      f1 = -1; p1 = (GenBitmapArrayGradient *)op->ArrayData[1];
    }
    else if(pos==max)
    {
      f0 =  2; p0 = (GenBitmapArrayGradient *)op->ArrayData[max-1];
      f1 = -1; p1 = (GenBitmapArrayGradient *)op->ArrayData[max-2];
    }
    else
    {
      f0 =0.5f; p0 = (GenBitmapArrayGradient *)op->ArrayData[pos-1];
      f1 =0.5f; p1 = (GenBitmapArrayGradient *)op->ArrayData[pos  ];
    }
    e->Pos = f0*p0->Pos + f1*p1->Pos;
  }
}

void GenBitmapGuiGradient(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaGradient sUNUSED *para = (GenBitmapParaGradient *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"step|linear|hermite|smoothstep:*4-|premul alpha",gh.ChangeMsg);
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"Pos",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"Color",pos,gh.Line,4,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=4;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      GenBitmapArrayGradient *elem = (GenBitmapArrayGradient *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    sFloatControl *float_Pos = gh.Float(&elem->Pos,0.000000f,1.000000f,0.010000f);
    float_Pos->Default = 0.000000f; float_Pos->RightStep = 0.125000f;

    gh.Color(&elem->Color,L"rgba");
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

void GenBitmapDefGradient(wOp *op)
{
  GenBitmapParaGradient sUNUSED *para = (GenBitmapParaGradient *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000408;
  para->Flags = 0x00000012;
}

void GenBitmapBindGradient(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2Gradient(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"flags");
  }
}
void GenBitmapBind3Gradient(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiGradient =
L"= GenBitmap : Gradient\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Gradient\n"
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
L" !i Flags\n"
L" !i Flags\n"
L" !i step\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i hermite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i smoothstep\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i premul alpha\n"
L" !i *\n"
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
L" !i Flags\n"
L" !i Flags\n"
L" !i step\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i hermite\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i smoothstep\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i premul alpha\n"
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

sBool GenBitmapCmdImport(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaImport sUNUSED *para = (GenBitmapParaImport *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 324 "wz3_bitmap_ops.ops"

    sImage img;

    if(img.Load(cmd->Strings[0]))
    {
      if(sIsPower2(img.SizeX) && sIsPower2(img.SizeY))
      {
        out->Init(&img);
        return 1;
      }
      else
        cmd->SetError(L"Image dimensions not power of two");
    }
    cmd->SetError(L"couldn't load image");
    return 0;
  ;
#line 1957 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiImport(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaImport sUNUSED *para = (GenBitmapParaImport *)(op->EditData); para;
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

void GenBitmapDefImport(wOp *op)
{
  GenBitmapParaImport sUNUSED *para = (GenBitmapParaImport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindImport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void GenBitmapBind2Import(wCommand *cmd,ScriptContext *ctx)
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
void GenBitmapBind3Import(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *GenBitmapWikiImport =
L"= GenBitmap : Import\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Import\n"
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

sBool GenBitmapCmdImportAnim(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaImportAnim sUNUSED *para = (GenBitmapParaImportAnim *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 352 "wz3_bitmap_ops.ops"

    if (LoadAtlas(cmd->Strings[0], out)==0)
    {
      return 1;
    }
    else
    {
      cmd->SetError(L"couldn't load image");
    }
    return 0;
  ;
#line 2063 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiImportAnim(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaImportAnim sUNUSED *para = (GenBitmapParaImportAnim *)(op->EditData); para;
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

void GenBitmapDefImportAnim(wOp *op)
{
  GenBitmapParaImportAnim sUNUSED *para = (GenBitmapParaImportAnim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindImportAnim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void GenBitmapBind2ImportAnim(wCommand *cmd,ScriptContext *ctx)
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
void GenBitmapBind3ImportAnim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *GenBitmapWikiImportAnim =
L"= GenBitmap : ImportAnim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ImportAnim\n"
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

struct GenBitmapHelperGlowRect
{
#line 392 "wz3_bitmap_ops.ops"
  sF32 x1;
#line 393 "wz3_bitmap_ops.ops"
  sF32 y1;
#line 394 "wz3_bitmap_ops.ops"
  sF32 x2;
#line 395 "wz3_bitmap_ops.ops"
  sF32 y2;
#line 396 "wz3_bitmap_ops.ops"
  sF32 cx;
#line 397 "wz3_bitmap_ops.ops"
  sF32 cy;
#line 398 "wz3_bitmap_ops.ops"
  sF32 a1;
#line 399 "wz3_bitmap_ops.ops"
  sF32 a2;
#line 2169 "wz3_bitmap_ops.cpp"
};
sBool GenBitmapCmdGlowRect(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaGlowRect sUNUSED *para = (GenBitmapParaGlowRect *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 385 "wz3_bitmap_ops.ops"

    out->GlowRect(para->Center[0],para->Center[1],para->Radius[0],para->Radius[1],para->Size[0],para->Size[1],
                  para->Color,para->Blend,para->Power,para->Wrap,para->Flags);
  ;
#line 2183 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndGlowRect(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaGlowRect sUNUSED *para = (GenBitmapParaGlowRect *)(op->EditData); para;
  GenBitmapHelperGlowRect *helper = (GenBitmapHelperGlowRect *)(op->HelperData);
#line 403 "wz3_bitmap_ops.ops"

    if(!pi.Dragging)
    {
      if(sAbs(para->Size[0])>0.00001 && sAbs(para->Size[1])>0.00001)
        helper->a1 = para->Size[0]/para->Size[1];
      else
        helper->a1 = 1;
      if(sAbs(para->Radius[0])>0.00001 && sAbs(para->Radius[1])>0.00001)
        helper->a2 = para->Radius[0]/para->Radius[1];
      else
        helper->a2 = 1;
    }
    else
    {
      if(pi.IsSelected(op,2))
      {
        para->Size[0] = sAbs(helper->x1-para->Center[0]);
        para->Size[1] = sAbs(helper->y1-para->Center[1]);
      }

      if(pi.IsSelected(op,3))
        para->Size[0] = sAbs(helper->x1-para->Center[0]);

      if(pi.IsSelected(op,4))
        para->Size[1] = sAbs(helper->y1-para->Center[1]);

      if(pi.IsSelected(op,5))
      {
        para->Radius[0] = sAbs(helper->x2-helper->x1);
        para->Radius[1] = sAbs(helper->y2-helper->y1);
      }

      if(pi.IsSelected(op,6))
        para->Radius[0] = sAbs(helper->x2-helper->x1);

      if(pi.IsSelected(op,7))
        para->Radius[1] = sAbs(helper->y2-helper->y1);
    }

    helper->x1 = para->Size[0]+para->Center[0];
    helper->y1 = para->Size[1]+para->Center[1];

    helper->x2 = para->Size[0]+para->Center[0]+para->Radius[0];
    helper->y2 = para->Size[1]+para->Center[1]+para->Radius[1];

    helper->cx = para->Center[0];
    helper->cy = para->Center[1];


    pi.HandleTex2D(op,2,helper->x1,helper->y1);
    pi.HandleTex2D(op,3,helper->x1,helper->cy);
    pi.HandleTex2D(op,4,helper->cx,helper->y1);

    pi.HandleTex2D(op,5,helper->x2,helper->y2);
    pi.HandleTex2D(op,6,helper->x2,helper->cy);
    pi.HandleTex2D(op,7,helper->cx,helper->y2);

        pi.HandleTex2D(op,1,para->Center[0],para->Center[1]);

    pi.LineTex2D(para->Center[0],para->Center[1],helper->x1,helper->y1);
    pi.LineTex2D(para->Center[0],helper->y1,helper->x1,helper->y1);
    pi.LineTex2D(helper->x1,para->Center[1],helper->x1,helper->y1);

    pi.LineTex2D(helper->x1,helper->y1,helper->x2,helper->y2);
    pi.LineTex2D(helper->x1,helper->y2,helper->x2,helper->y2);
    pi.LineTex2D(helper->x2,helper->y1,helper->x2,helper->y2);
  ;
#line 2260 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiGlowRect(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaGlowRect sUNUSED *para = (GenBitmapParaGlowRect *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center[0],-4.00000f,4.000000f,0.001000f);
  float_Center_0->Default = 0.500000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center[1],-4.00000f,4.000000f,0.001000f);
  float_Center_1->Default = 0.500000f; float_Center_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Radius");
  gh.BeginTied();
  sFloatControl *float_Radius_0 = gh.Float(&para->Radius[0],0.000000f,4.000000f,0.001000f);
  float_Radius_0->Default = 0.500000f; float_Radius_0->RightStep = 0.125000f;
  sFloatControl *float_Radius_1 = gh.Float(&para->Radius[1],0.000000f,4.000000f,0.001000f);
  float_Radius_1->Default = 0.500000f; float_Radius_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Size");
  gh.BeginTied();
  sFloatControl *float_Size_0 = gh.Float(&para->Size[0],0.000000f,4.000000f,0.001000f);
  float_Size_0->Default = 0.000000f; float_Size_0->RightStep = 0.125000f;
  sFloatControl *float_Size_1 = gh.Float(&para->Size[1],0.000000f,4.000000f,0.001000f);
  float_Size_1->Default = 0.000000f; float_Size_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Label(L"Blend");
  sFloatControl *float_Blend = gh.Float(&para->Blend,0.000000f,1.000000f,0.010000f);
  float_Blend->Default = 1.000000f; float_Blend->RightStep = 0.125000f;

  gh.Label(L"Power (hardness)");
  sFloatControl *float_Power = gh.Float(&para->Power,0.000000f,16.00000f,0.001000f);
  float_Power->Default = 0.500000f; float_Power->RightStep = 0.125000f;

  gh.Label(L"Wrap");
  gh.Flags(&para->Wrap,L"-|wrap",gh.ChangeMsg);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0-|alt power:*1ellipse|rectangle",gh.ChangeMsg);
}

void GenBitmapDefGlowRect(wOp *op)
{
  GenBitmapParaGlowRect sUNUSED *para = (GenBitmapParaGlowRect *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Center[0] = 0.500000f;
  para->Center[1] = 0.500000f;
  para->Radius[0] = 0.500000f;
  para->Radius[1] = 0.500000f;
  para->Color = 0xffffffff;
  para->Blend = 1.000000f;
  para->Power = 0.500000f;
}

void GenBitmapBindGlowRect(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"size"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"blend"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"power"),val);
}
void GenBitmapBind2GlowRect(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"center");
    name[1] = sPoolString(L"radius");
    name[2] = sPoolString(L"size");
    name[3] = sPoolString(L"color_");
    name[4] = sPoolString(L"blend");
    name[5] = sPoolString(L"power");
    name[6] = sPoolString(L"wrap");
    name[7] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,2,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+2);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
}
void GenBitmapBind3GlowRect(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[2];\n");
  tb.PrintF(L"  import radius : float[2];\n");
  tb.PrintF(L"  import size : float[2];\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import blend : float;\n");
  tb.PrintF(L"  import power : float;\n");
}
const sChar *GenBitmapWikiGlowRect =
L"= GenBitmap : GlowRect\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i GlowRect\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i defaults to: Flat\n"
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
L" !i Center\n"
L" !i Center\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Size\n"
L" !i Size\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Blend\n"
L" !i Blend\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Power (hardness)\n"
L" !i Power\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Wrap\n"
L" !i Wrap\n"
L" !i wrap\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i alt power\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i ellipse\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i rectangle\n"
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

sBool GenBitmapCmdDots(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaDots sUNUSED *para = (GenBitmapParaDots *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 487 "wz3_bitmap_ops.ops"

    out->Dots(para->Color0,para->Color1,para->Count,para->Seed);
  ;
#line 2496 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiDots(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaDots sUNUSED *para = (GenBitmapParaDots *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  gh.Label(L"Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,0,65536,0.125000f);
  int_Count->Default = 0x00000010; int_Count->RightStep = 0.125000f;

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000001; int_Seed->RightStep = 0.125000f;
}

void GenBitmapDefDots(wOp *op)
{
  GenBitmapParaDots sUNUSED *para = (GenBitmapParaDots *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color0 = 0xff000000;
  para->Color1 = 0xffffffff;
  para->Count = 0x00000010;
  para->Seed = 0x00000001;
}

void GenBitmapBindDots(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
}
void GenBitmapBind2Dots(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"color0");
    name[1] = sPoolString(L"color1");
    name[2] = sPoolString(L"count");
    name[3] = sPoolString(L"seed");
  }
  ctx->AddImport(name[0],ScriptTypeColor,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeInt,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeInt,1,cmd->Data+3);
}
void GenBitmapBind3Dots(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import seed : int;\n");
}
const sChar *GenBitmapWikiDots =
L"= GenBitmap : Dots\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Dots\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i defaults to: Flat\n"
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
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
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

sBool GenBitmapCmdAtlas(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaAtlas sUNUSED *para = (GenBitmapParaAtlas *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 503 "wz3_bitmap_ops.ops"

    sInt x = 0;
    sInt y = 0;
    sInt ymax = 0;
    sInt xs = 1<<(para->Size&0xff);
    sInt ys = 1<<((para->Size>>8)&0xff);

    out->Init(xs,ys);
    out->Flat(para->Color);

    out->Atlas.Entries.Clear();
    out->Atlas.Entries.HintSize(cmd->InputCount);
    
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      GenBitmap *bm = cmd->GetInput<GenBitmap *>(i);
      if(bm)
      {
        out->Blit(x,y,bm);
        ymax = sMax(ymax,bm->YSize);
        
        if (bm->Atlas.Entries.IsEmpty())
        {
          BitmapAtlasEntry *ae=out->Atlas.Entries.AddMany(1);
          ae->Pixels.Init(x,y,x+bm->XSize,y+bm->YSize);
          ae->UVs.x0 = sF32(ae->Pixels.x0)/out->XSize;
          ae->UVs.y0 = sF32(ae->Pixels.y0)/out->YSize;
          ae->UVs.x1 = sF32(ae->Pixels.x1)/out->XSize;
          ae->UVs.y1 = sF32(ae->Pixels.y1)/out->YSize;
        }
        else
        {
          BitmapAtlasEntry *ain, *ae=out->Atlas.Entries.AddMany(bm->Atlas.Entries.GetCount());
          sFORALL(bm->Atlas.Entries,ain)
          {
            ae->Pixels.Init(x+ain->Pixels.x0,y+ain->Pixels.y0,x+ain->Pixels.x1,y+ain->Pixels.y1);
            ae->UVs.x0 = sF32(ae->Pixels.x0)/out->XSize;
            ae->UVs.y0 = sF32(ae->Pixels.y0)/out->YSize;
            ae->UVs.x1 = sF32(ae->Pixels.x1)/out->XSize;
            ae->UVs.y1 = sF32(ae->Pixels.y1)/out->YSize;
            ae++;        
          }
        }
        
        x+= bm->XSize;
        if(x>=xs)
        {
          x = 0;
          y += ymax;
          ymax = 0;
        }
      }
    }
  ;
#line 2699 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiAtlas(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaAtlas sUNUSED *para = (GenBitmapParaAtlas *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);
}

void GenBitmapDefAtlas(wOp *op)
{
  GenBitmapParaAtlas sUNUSED *para = (GenBitmapParaAtlas *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Color = 0xffff00ff;
}

void GenBitmapBindAtlas(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
}
void GenBitmapBind2Atlas(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"color_");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
}
void GenBitmapBind3Atlas(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
}
const sChar *GenBitmapWikiAtlas =
L"= GenBitmap : Atlas\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Atlas\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Color\n"
L" !i Color\n"
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

sBool GenBitmapCmdColor(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaColor sUNUSED *para = (GenBitmapParaColor *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 576 "wz3_bitmap_ops.ops"

    sU64 col = GenBitmap::GetColor64(para->Color);
    out->InitSize(in0);
    out->Loop(para->Mode+BI_MULCOL,&col,in0);
  ;
#line 2930 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiColor(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaColor sUNUSED *para = (GenBitmapParaColor *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"mul|add|sub|gray|invert|scale",gh.ChangeMsg);

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);
}

void GenBitmapDefColor(wOp *op)
{
  GenBitmapParaColor sUNUSED *para = (GenBitmapParaColor *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0xff000000;
}

void GenBitmapBindColor(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
}
void GenBitmapBind2Color(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"color_");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
}
void GenBitmapBind3Color(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
}
const sChar *GenBitmapWikiColor =
L"= GenBitmap : Color\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Color\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i gray\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i invert\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i scale\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color\n"
L" !i Color\n"
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

sBool GenBitmapCmdRange(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaRange sUNUSED *para = (GenBitmapParaRange *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 596 "wz3_bitmap_ops.ops"

    sU64 cx[2];

    cx[0] = GenBitmap::GetColor64(para->Color0);
    cx[1] = GenBitmap::GetColor64(para->Color1);

    out->InitSize(in0);
    GenBitmap *in = in0;

    if(para->Mode&1)
    {
      out->Loop(BI_GRAY,cx,in);
      in = out;
    }
    if(para->Mode&2)
    {
      out->Loop(BI_INVERT,cx,in);
      in = out;
    }
    out->Loop(BI_RANGE,cx,in);
  ;
#line 3083 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiRange(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaRange sUNUSED *para = (GenBitmapParaRange *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"adjust|range:*1normal|invert",gh.ChangeMsg);

  gh.Label(L"Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  gh.Label(L"Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);
}

void GenBitmapDefRange(wOp *op)
{
  GenBitmapParaRange sUNUSED *para = (GenBitmapParaRange *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color0 = 0xff000000;
  para->Color1 = 0xffffffff;
}

void GenBitmapBindRange(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
}
void GenBitmapBind2Range(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"color0");
    name[2] = sPoolString(L"color1");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+2);
}
void GenBitmapBind3Range(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color1 : color;\n");
}
const sChar *GenBitmapWikiRange =
L"= GenBitmap : Range\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Range\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i adjust\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i range\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i invert\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
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

sBool GenBitmapCmdHSCB(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaHSCB sUNUSED *para = (GenBitmapParaHSCB *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 634 "wz3_bitmap_ops.ops"

    out->HSCB(para->Hue,para->Saturation,para->Contrast,para->Brightness);
  ;
#line 3230 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiHSCB(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaHSCB sUNUSED *para = (GenBitmapParaHSCB *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Hue");
  sFloatControl *float_Hue = gh.Float(&para->Hue,-4.00000f,4.000000f,0.001000f);
  float_Hue->Default = 0.000000f; float_Hue->RightStep = 0.125000f;

  gh.Label(L"Saturation");
  sFloatControl *float_Saturation = gh.Float(&para->Saturation,-16.0000f,16.00000f,0.001000f);
  float_Saturation->Default = 1.000000f; float_Saturation->RightStep = 0.125000f;

  gh.Label(L"Contrast");
  sFloatControl *float_Contrast = gh.Float(&para->Contrast,0.000000f,16.00000f,0.001000f);
  float_Contrast->Default = 1.000000f; float_Contrast->RightStep = 0.125000f;

  gh.Label(L"Brightness");
  sFloatControl *float_Brightness = gh.Float(&para->Brightness,0.000000f,16.00000f,0.001000f);
  float_Brightness->Default = 1.000000f; float_Brightness->RightStep = 0.125000f;
}

void GenBitmapDefHSCB(wOp *op)
{
  GenBitmapParaHSCB sUNUSED *para = (GenBitmapParaHSCB *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Saturation = 1.000000f;
  para->Contrast = 1.000000f;
  para->Brightness = 1.000000f;
}

void GenBitmapBindHSCB(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"hue"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"saturation"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"contrast"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"brightness"),val);
}
void GenBitmapBind2HSCB(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"hue");
    name[1] = sPoolString(L"saturation");
    name[2] = sPoolString(L"contrast");
    name[3] = sPoolString(L"brightness");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+3);
}
void GenBitmapBind3HSCB(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import hue : float;\n");
  tb.PrintF(L"  import saturation : float;\n");
  tb.PrintF(L"  import contrast : float;\n");
  tb.PrintF(L"  import brightness : float;\n");
}
const sChar *GenBitmapWikiHSCB =
L"= GenBitmap : HSCB\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i HSCB\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Hue\n"
L" !i Hue\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Saturation\n"
L" !i Saturation\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Contrast\n"
L" !i Contrast\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Brightness\n"
L" !i Brightness\n"
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

sBool GenBitmapCmdBitcrusher(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaBitcrusher sUNUSED *para = (GenBitmapParaBitcrusher *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 651 "wz3_bitmap_ops.ops"

    sU16 *p = (sU16 *) out->Data;
    sInt s = sInt(para->Steps*128);
    sInt h = sInt(para->Phase*0x7fff*128);
    sInt is = sInt(0x7fff/sRoundUp(para->Steps));
    for(sInt i=0;i<out->Size;i++)
    {
      p[0] = sU16(sClamp((p[0]*s+h)>>22,0,s-1)*is);
      p[1] = sU16(sClamp((p[1]*s+h)>>22,0,s-1)*is);
      p[2] = sU16(sClamp((p[2]*s+h)>>22,0,s-1)*is);
      p+=4;
    }
  ;
#line 3393 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiBitcrusher(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaBitcrusher sUNUSED *para = (GenBitmapParaBitcrusher *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Steps");
  sFloatControl *float_Steps = gh.Float(&para->Steps,1.000000f,128.0000f,0.100000f);
  float_Steps->Default = 2.000000f; float_Steps->RightStep = 0.125000f;

  gh.Label(L"Phase");
  sFloatControl *float_Phase = gh.Float(&para->Phase,-1.00000f,1.000000f,0.010000f);
  float_Phase->Default = 0.000000f; float_Phase->RightStep = 0.125000f;
}

void GenBitmapDefBitcrusher(wOp *op)
{
  GenBitmapParaBitcrusher sUNUSED *para = (GenBitmapParaBitcrusher *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Steps = 2.000000f;
}

void GenBitmapBindBitcrusher(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"steps"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"phase"),val);
}
void GenBitmapBind2Bitcrusher(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"steps");
    name[1] = sPoolString(L"phase");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void GenBitmapBind3Bitcrusher(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import steps : float;\n");
  tb.PrintF(L"  import phase : float;\n");
}
const sChar *GenBitmapWikiBitcrusher =
L"= GenBitmap : Bitcrusher\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bitcrusher\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i float\n"
L" !i *\n"
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

sBool GenBitmapCmdMerge(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaMerge sUNUSED *para = (GenBitmapParaMerge *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 677 "wz3_bitmap_ops.ops"

    GenBitmap *in;
    static sU8 modes[] = 
    {
      BI_ADD,BI_SUB,BI_MUL,BI_DIFF,BI_ALPHA,
      BI_BRIGHTNESS,
      BI_HARDLIGHT,BI_OVER,BI_ADDSMOOTH,
      BI_MIN,BI_MAX,
      BI_ALPHA,
    };
    sInt mode = modes[para->Mode];

    for(sInt i=1;i<cmd->InputCount;i++)
    {
      in = cmd->GetInput<GenBitmap *>(i);

      if(in0->XSize!=in->XSize || in0->YSize!=in->YSize)
        return 0;
    }

    out->CopyFrom(in0);
    for(sInt i=1;i<cmd->InputCount;i++)
    {
      in = cmd->GetInput<GenBitmap *>(i);

      out->Loop(mode,in,out);
    }
    if(para->Mode==11)
      out->PreMulAlpha();
  ;
#line 3541 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiMerge(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaMerge sUNUSED *para = (GenBitmapParaMerge *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"add|sub|mul|diff|alpha|brightness|hardlight|over|addsmooth|min|max|premul alpha",gh.ChangeMsg);
}

void GenBitmapDefMerge(wOp *op)
{
  GenBitmapParaMerge sUNUSED *para = (GenBitmapParaMerge *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindMerge(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2Merge(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
  }
}
void GenBitmapBind3Merge(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiMerge =
L"= GenBitmap : Merge\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Merge\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i diff\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i brightness\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i hardlight\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i over\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i addsmooth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i min\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i max\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i premul alpha\n"
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

sBool GenBitmapCmdPreMulAlpha(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaPreMulAlpha sUNUSED *para = (GenBitmapParaPreMulAlpha *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 716 "wz3_bitmap_ops.ops"

    out->PreMulAlpha();
  ;
#line 3683 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiPreMulAlpha(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaPreMulAlpha sUNUSED *para = (GenBitmapParaPreMulAlpha *)(op->EditData); para;
}

void GenBitmapDefPreMulAlpha(wOp *op)
{
  GenBitmapParaPreMulAlpha sUNUSED *para = (GenBitmapParaPreMulAlpha *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindPreMulAlpha(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2PreMulAlpha(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind3PreMulAlpha(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiPreMulAlpha =
L"= GenBitmap : PreMulAlpha\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i PreMulAlpha\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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

sBool GenBitmapCmdMask(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaMask sUNUSED *para = (GenBitmapParaMask *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap sUNUSED *in1 = cmd->GetInput<GenBitmap *>(1); in1;
  GenBitmap sUNUSED *in2 = cmd->GetInput<GenBitmap *>(2); in2;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 732 "wz3_bitmap_ops.ops"

    if(in0->XSize!= in1->XSize || in0->XSize!=in2->XSize) return 0;
    if(in0->YSize!= in1->YSize || in0->YSize!=in2->YSize) return 0;
    out->InitSize(in0);
    out->Loop(BI_GRAY,in0,in0);
    switch(para->Mode)
    {
    case 0:
      out->Loop(BI_MERGE,in1,in2);
      break;
    case 1:
      out->Loop(BI_MUL,in1,out);
      out->Loop(BI_ADD,in2,out);
      break;
    case 2:
      out->Loop(BI_MUL,in1,out);
      out->Loop(BI_SUBR,in2,out);
      break;
    case 3:
      out->Loop(BI_MULMERGE,in1,in2);
      break;
    }
  ;
#line 3777 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiMask(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaMask sUNUSED *para = (GenBitmapParaMask *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"mix|add|sub|mul",gh.ChangeMsg);
}

void GenBitmapDefMask(wOp *op)
{
  GenBitmapParaMask sUNUSED *para = (GenBitmapParaMask *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindMask(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2Mask(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
  }
}
void GenBitmapBind3Mask(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiMask =
L"= GenBitmap : Mask\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Mask\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i\n"
L" !i *\n"
L"\n"
L" !i GenBitmap\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i mix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
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

sBool GenBitmapCmdColorBalance(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaColorBalance sUNUSED *para = (GenBitmapParaColorBalance *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 770 "wz3_bitmap_ops.ops"

    out->ColorBalance(para->Shadows,para->Midtones,para->Highlights);
  ;
#line 3895 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiColorBalance(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaColorBalance sUNUSED *para = (GenBitmapParaColorBalance *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Shadows");
  gh.BeginTied();
  sFloatControl *float_Shadows_0 = gh.Float(&para->Shadows.x,-1.00000f,1.000000f,0.001000f);
  float_Shadows_0->Default = 0.000000f; float_Shadows_0->RightStep = 0.125000f;
  sFloatControl *float_Shadows_1 = gh.Float(&para->Shadows.y,-1.00000f,1.000000f,0.001000f);
  float_Shadows_1->Default = 0.000000f; float_Shadows_1->RightStep = 0.125000f;
  sFloatControl *float_Shadows_2 = gh.Float(&para->Shadows.z,-1.00000f,1.000000f,0.001000f);
  float_Shadows_2->Default = 0.000000f; float_Shadows_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Midtones");
  gh.BeginTied();
  sFloatControl *float_Midtones_0 = gh.Float(&para->Midtones.x,-1.00000f,1.000000f,0.001000f);
  float_Midtones_0->Default = 0.000000f; float_Midtones_0->RightStep = 0.125000f;
  sFloatControl *float_Midtones_1 = gh.Float(&para->Midtones.y,-1.00000f,1.000000f,0.001000f);
  float_Midtones_1->Default = 0.000000f; float_Midtones_1->RightStep = 0.125000f;
  sFloatControl *float_Midtones_2 = gh.Float(&para->Midtones.z,-1.00000f,1.000000f,0.001000f);
  float_Midtones_2->Default = 0.000000f; float_Midtones_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Highlights");
  gh.BeginTied();
  sFloatControl *float_Highlights_0 = gh.Float(&para->Highlights.x,-1.00000f,1.000000f,0.001000f);
  float_Highlights_0->Default = 0.000000f; float_Highlights_0->RightStep = 0.125000f;
  sFloatControl *float_Highlights_1 = gh.Float(&para->Highlights.y,-1.00000f,1.000000f,0.001000f);
  float_Highlights_1->Default = 0.000000f; float_Highlights_1->RightStep = 0.125000f;
  sFloatControl *float_Highlights_2 = gh.Float(&para->Highlights.z,-1.00000f,1.000000f,0.001000f);
  float_Highlights_2->Default = 0.000000f; float_Highlights_2->RightStep = 0.125000f;
  gh.EndTied();
}

void GenBitmapDefColorBalance(wOp *op)
{
  GenBitmapParaColorBalance sUNUSED *para = (GenBitmapParaColorBalance *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindColorBalance(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"shadows"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"shadows"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"shadows"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"midtones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"midtones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"midtones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"highlights"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"highlights"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"highlights"),val);
}
void GenBitmapBind2ColorBalance(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"shadows");
    name[1] = sPoolString(L"midtones");
    name[2] = sPoolString(L"highlights");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[2],ScriptTypeFloat,3,cmd->Data+6);
}
void GenBitmapBind3ColorBalance(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import shadows : float[3];\n");
  tb.PrintF(L"  import midtones : float[3];\n");
  tb.PrintF(L"  import highlights : float[3];\n");
}
const sChar *GenBitmapWikiColorBalance =
L"= GenBitmap : ColorBalance\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ColorBalance\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Shadows\n"
L" !i Shadows\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Midtones\n"
L" !i Midtones\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Highlights\n"
L" !i Highlights\n"
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

sBool GenBitmapCmdBlur(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaBlur sUNUSED *para = (GenBitmapParaBlur *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 788 "wz3_bitmap_ops.ops"

    out->CopyFrom(in0);
    out->Blur(para->Passes,para->Blur[0],para->Blur[1],para->Amplify);
  ;
#line 4067 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiBlur(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaBlur sUNUSED *para = (GenBitmapParaBlur *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Passes");
  gh.Flags(&para->Passes,L" 0| 1| 2| 3| 4| 5",gh.ChangeMsg);

  gh.Label(L"Blur");
  gh.BeginTied();
  sFloatControl *float_Blur_0 = gh.Float(&para->Blur[0],0.000000f,1.000000f,0.000100f);
  float_Blur_0->Default = 0.015000f; float_Blur_0->RightStep = 0.125000f;
  sFloatControl *float_Blur_1 = gh.Float(&para->Blur[1],0.000000f,1.000000f,0.000100f);
  float_Blur_1->Default = 0.015000f; float_Blur_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,0.000000f,16.00000f,0.010000f);
  float_Amplify->Default = 1.000000f; float_Amplify->RightStep = 0.125000f;
}

void GenBitmapDefBlur(wOp *op)
{
  GenBitmapParaBlur sUNUSED *para = (GenBitmapParaBlur *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Passes = 0x00000002;
  para->Blur[0] = 0.015000f;
  para->Blur[1] = 0.015000f;
  para->Amplify = 1.000000f;
}

void GenBitmapBindBlur(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
}
void GenBitmapBind2Blur(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"passes");
    name[1] = sPoolString(L"blur");
    name[2] = sPoolString(L"amplify");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
}
void GenBitmapBind3Blur(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import blur : float[2];\n");
  tb.PrintF(L"  import amplify : float;\n");
}
const sChar *GenBitmapWikiBlur =
L"= GenBitmap : Blur\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Blur\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Passes\n"
L" !i Passes\n"
L" !i 0\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Blur\n"
L" !i Blur\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
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

sBool GenBitmapCmdSharpen(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaSharpen sUNUSED *para = (GenBitmapParaSharpen *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 805 "wz3_bitmap_ops.ops"

    out->InitSize(in0);
    out->Sharpen(in0,para->Passes,para->Blur[0],para->Blur[1],para->Amplify);
  ;
#line 4229 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiSharpen(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaSharpen sUNUSED *para = (GenBitmapParaSharpen *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Passes");
  gh.Flags(&para->Passes,L" 0| 1| 2| 3| 4| 5",gh.ChangeMsg);

  gh.Label(L"Blur");
  gh.BeginTied();
  sFloatControl *float_Blur_0 = gh.Float(&para->Blur[0],0.000000f,1.000000f,0.000100f);
  float_Blur_0->Default = 0.015000f; float_Blur_0->RightStep = 0.125000f;
  sFloatControl *float_Blur_1 = gh.Float(&para->Blur[1],0.000000f,1.000000f,0.000100f);
  float_Blur_1->Default = 0.015000f; float_Blur_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,0.000000f,16.00000f,0.010000f);
  float_Amplify->Default = 1.000000f; float_Amplify->RightStep = 0.125000f;
}

void GenBitmapDefSharpen(wOp *op)
{
  GenBitmapParaSharpen sUNUSED *para = (GenBitmapParaSharpen *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Passes = 0x00000002;
  para->Blur[0] = 0.015000f;
  para->Blur[1] = 0.015000f;
  para->Amplify = 1.000000f;
}

void GenBitmapBindSharpen(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"blur"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
}
void GenBitmapBind2Sharpen(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"passes");
    name[1] = sPoolString(L"blur");
    name[2] = sPoolString(L"amplify");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
}
void GenBitmapBind3Sharpen(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import blur : float[2];\n");
  tb.PrintF(L"  import amplify : float;\n");
}
const sChar *GenBitmapWikiSharpen =
L"= GenBitmap : Sharpen\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sharpen\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Passes\n"
L" !i Passes\n"
L" !i 0\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Blur\n"
L" !i Blur\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
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

struct GenBitmapHelperRotate
{
#line 846 "wz3_bitmap_ops.ops"
  sF32 dx;
#line 847 "wz3_bitmap_ops.ops"
  sF32 dy;
#line 848 "wz3_bitmap_ops.ops"
  sF32 sxx;
#line 849 "wz3_bitmap_ops.ops"
  sF32 sxy;
#line 850 "wz3_bitmap_ops.ops"
  sF32 syx;
#line 851 "wz3_bitmap_ops.ops"
  sF32 syy;
#line 4393 "wz3_bitmap_ops.cpp"
};
sBool GenBitmapCmdRotate(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaRotate sUNUSED *para = (GenBitmapParaRotate *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 833 "wz3_bitmap_ops.ops"

    sInt sx = para->Size&0xff;
    sInt sy = (para->Size>>8)&0xff;
    
    sx = sx ? 1<<(sx-1) : in0->XSize;
    sy = sy ? 1<<(sy-1) : in0->YSize;

    out->Init(sx,sy);
    out->Rotate(in0,para->Center[0],para->Center[1],para->Angle,para->Scale[0],para->Scale[1],para->Offset[0],para->Offset[1],para->Flags);
  ;
#line 4413 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndRotate(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaRotate sUNUSED *para = (GenBitmapParaRotate *)(op->EditData); para;
  GenBitmapHelperRotate *helper = (GenBitmapHelperRotate *)(op->HelperData);
#line 855 "wz3_bitmap_ops.ops"

    if(pi.Dragging && pi.IsSelected(op,2))
    {
      para->Angle = sFATan2(para->Center[0]-helper->dx , para->Center[1]-helper->dy)/sPI2F;
    }
    
    if(pi.Dragging && pi.IsSelected(op,3))
    {
      sF32 x = helper->sxx - para->Center[0];
      sF32 y = helper->sxy - para->Center[1];
      para->Scale[0] = 
      para->Scale[1] = sFSqrt(x*x+y*y);
    }
    /*
    if(pi.Dragging && pi.IsSelected(op,4))
    {
      sF32 x = helper->syx - para->Center[0];
      sF32 y = helper->syy - para->Center[1];
      para->Scale[0] = sFSqrt(x*x+y*y);
    }
    */

    sF32 s = sFSin(para->Angle*sPI2F);
    sF32 c = sFCos(para->Angle*sPI2F);
    helper->dx = para->Center[0] - 0.25f*s;
    helper->dy = para->Center[1] - 0.25f*c;
    helper->sxx = para->Center[0] + para->Scale[1]*s;
    helper->sxy = para->Center[1] + para->Scale[1]*c;
    helper->syx = para->Center[0] + para->Scale[0]*c;
    helper->syy = para->Center[1] - para->Scale[0]*s;

    pi.HandleTex2D(op,1,para->Center[0],para->Center[1]);
    pi.HandleTex2D(op,2,helper->dx,helper->dy);
    pi.HandleTex2D(op,3,helper->sxx,helper->sxy);
//    pi.HandleTex2D(op,4,helper->syx,helper->syy);
    pi.LineTex2D(para->Center[0],para->Center[1],helper->dx,helper->dy);
    pi.LineTex2D(para->Center[0],para->Center[1],helper->sxx,helper->sxy);
//    pi.LineTex2D(para->Center[0],para->Center[1],helper->syx,helper->syy);
  ;
#line 4462 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiRotate(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaRotate sUNUSED *para = (GenBitmapParaRotate *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L"current| 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8current| 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center[0],-4.00000f,4.000000f,0.001000f);
  float_Center_0->Default = 0.500000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center[1],-4.00000f,4.000000f,0.001000f);
  float_Center_1->Default = 0.500000f; float_Center_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Angle");
  sFloatControl *float_Angle = gh.Float(&para->Angle,-4.00000f,4.000000f,0.000100f);
  float_Angle->Default = 0.000000f; float_Angle->RightStep = 0.125000f;

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale[0],-16.0000f,16.00000f,0.001000f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale[1],-16.0000f,16.00000f,0.001000f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Offset");
  gh.BeginTied();
  sFloatControl *float_Offset_0 = gh.Float(&para->Offset[0],-4.00000f,4.000000f,0.001000f);
  float_Offset_0->Default = 0.500000f; float_Offset_0->RightStep = 0.125000f;
  sFloatControl *float_Offset_1 = gh.Float(&para->Offset[1],-4.00000f,4.000000f,0.001000f);
  float_Offset_1->Default = 0.500000f; float_Offset_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Border Clamp");
  gh.Flags(&para->Flags,L"off|x|y|both",gh.ChangeMsg);

  gh.Label(L"Filter");
  gh.Flags(&para->Flags,L"*2bilinear|nearest",gh.ChangeMsg);
}

void GenBitmapDefRotate(wOp *op)
{
  GenBitmapParaRotate sUNUSED *para = (GenBitmapParaRotate *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Center[0] = 0.500000f;
  para->Center[1] = 0.500000f;
  para->Scale[0] = 1.000000f;
  para->Scale[1] = 1.000000f;
  para->Offset[0] = 0.500000f;
  para->Offset[1] = 0.500000f;
}

void GenBitmapBindRotate(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"angle"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
}
void GenBitmapBind2Rotate(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[7];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"center");
    name[2] = sPoolString(L"angle");
    name[3] = sPoolString(L"scale");
    name[4] = sPoolString(L"offset");
    name[5] = sPoolString(L"flags");
    name[6] = sPoolString(L"filter");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+6);
}
void GenBitmapBind3Rotate(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[2];\n");
  tb.PrintF(L"  import angle : float;\n");
  tb.PrintF(L"  import scale : float[2];\n");
  tb.PrintF(L"  import offset : float[2];\n");
}
const sChar *GenBitmapWikiRotate =
L"= GenBitmap : Rotate\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Rotate\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Size\n"
L" !i Size\n"
L" !i current\n"
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
L" !i current\n"
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
L" !i Center\n"
L" !i Center\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Angle\n"
L" !i Angle\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Offset\n"
L" !i Offset\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Border Clamp\n"
L" !i Flags\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i both\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Filter\n"
L" !i Flags\n"
L" !i bilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i nearest\n"
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

sBool GenBitmapCmdRotateMul(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaRotateMul sUNUSED *para = (GenBitmapParaRotateMul *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 916 "wz3_bitmap_ops.ops"

    out->CopyFrom(in0);
    out->RotateMul(0.5f,0.5f,para->Angle,para->Scale[0],para->Scale[1],para->Offset[0],para->Offset[1],
                   para->Flags,para->PreAdjust,para->Mode,para->Count,para->Fade);
  ;
#line 4804 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndRotateMul(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaRotateMul sUNUSED *para = (GenBitmapParaRotateMul *)(op->EditData); para;
#line 922 "wz3_bitmap_ops.ops"

    pi.HandleTex2D(op,1,para->Offset[0],para->Offset[1]);
  ;
#line 4816 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiRotateMul(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaRotateMul sUNUSED *para = (GenBitmapParaRotateMul *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Angle");
  sFloatControl *float_Angle = gh.Float(&para->Angle,-4.00000f,4.000000f,0.000100f);
  float_Angle->Default = 0.000000f; float_Angle->RightStep = 0.125000f;

  gh.Label(L"Scale");
  gh.BeginTied();
  sFloatControl *float_Scale_0 = gh.Float(&para->Scale[0],-16.0000f,16.00000f,0.000100f);
  float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
  sFloatControl *float_Scale_1 = gh.Float(&para->Scale[1],-16.0000f,16.00000f,0.000100f);
  float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Offset");
  gh.BeginTied();
  sFloatControl *float_Offset_0 = gh.Float(&para->Offset[0],-4.00000f,4.000000f,0.001000f);
  float_Offset_0->Default = 0.500000f; float_Offset_0->RightStep = 0.125000f;
  sFloatControl *float_Offset_1 = gh.Float(&para->Offset[1],-4.00000f,4.000000f,0.001000f);
  float_Offset_1->Default = 0.500000f; float_Offset_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Border Clamp");
  gh.Flags(&para->Flags,L"off|x|y|both",gh.ChangeMsg);

  gh.Label(L"Filter");
  gh.Flags(&para->Flags,L"*2bilinear|nearest",gh.ChangeMsg);

  gh.Group(L"multiply");

  gh.Label(L"PreAdjust");
  gh.ColorPick(&para->PreAdjust,L"rgba",0);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"add|sub|mul|diff|alpha:*4linear|recursive",gh.ChangeMsg);

  gh.Label(L"Count");
  sIntControl *int_Count = gh.Int(&para->Count,1,255,0.125000f);
  int_Count->Default = 0x00000002; int_Count->RightStep = 0.125000f;

  gh.Label(L"Fade");
  gh.ColorPick(&para->Fade,L"rgba",0);
}

void GenBitmapDefRotateMul(wOp *op)
{
  GenBitmapParaRotateMul sUNUSED *para = (GenBitmapParaRotateMul *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Scale[0] = 1.000000f;
  para->Scale[1] = 1.000000f;
  para->Offset[0] = 0.500000f;
  para->Offset[1] = 0.500000f;
  para->PreAdjust = 0xffffffff;
  para->Count = 0x00000002;
  para->Fade = 0xffffffff;
}

void GenBitmapBindRotateMul(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"angle"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"offset"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"preadjust"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"fade"),val);
}
void GenBitmapBind2RotateMul(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"angle");
    name[1] = sPoolString(L"scale");
    name[2] = sPoolString(L"offset");
    name[3] = sPoolString(L"flags");
    name[4] = sPoolString(L"filter");
    name[5] = sPoolString(L"multiply");
    name[6] = sPoolString(L"preadjust");
    name[7] = sPoolString(L"mode");
    name[8] = sPoolString(L"count");
    name[9] = sPoolString(L"fade");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,2,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+3);
  ctx->AddImport(name[6],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeColor,1,cmd->Data+9);
}
void GenBitmapBind3RotateMul(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import angle : float;\n");
  tb.PrintF(L"  import scale : float[2];\n");
  tb.PrintF(L"  import offset : float[2];\n");
  tb.PrintF(L"  import preadjust : color;\n");
  tb.PrintF(L"  import count : int;\n");
  tb.PrintF(L"  import fade : color;\n");
}
const sChar *GenBitmapWikiRotateMul =
L"= GenBitmap : RotateMul\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i RotateMul\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Angle\n"
L" !i Angle\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Offset\n"
L" !i Offset\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Border Clamp\n"
L" !i Flags\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i both\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Filter\n"
L" !i Flags\n"
L" !i bilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i nearest\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i PreAdjust\n"
L" !i PreAdjust\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i diff\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i recursive\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Count\n"
L" !i Count\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i Fade\n"
L" !i Fade\n"
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

struct GenBitmapHelperTwirl
{
#line 949 "wz3_bitmap_ops.ops"
  sF32 x1;
#line 950 "wz3_bitmap_ops.ops"
  sF32 y1;
#line 951 "wz3_bitmap_ops.ops"
  sF32 cx;
#line 952 "wz3_bitmap_ops.ops"
  sF32 cy;
#line 953 "wz3_bitmap_ops.ops"
  sF32 a1;
#line 5091 "wz3_bitmap_ops.cpp"
};
sBool GenBitmapCmdTwirl(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaTwirl sUNUSED *para = (GenBitmapParaTwirl *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 941 "wz3_bitmap_ops.ops"

    out->InitSize(in0);
    out->Twirl(in0,para->Strength,para->Gamma,para->Radius[0],para->Radius[1],para->Center[0],para->Center[1],para->Flags);
  ;
#line 5105 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndTwirl(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaTwirl sUNUSED *para = (GenBitmapParaTwirl *)(op->EditData); para;
  GenBitmapHelperTwirl *helper = (GenBitmapHelperTwirl *)(op->HelperData);
#line 957 "wz3_bitmap_ops.ops"

    if(!pi.Dragging)
    {

      if(sAbs(para->Radius[0])>0.00001 && sAbs(para->Radius[1])>0.00001)
        helper->a1 = para->Radius[0]/para->Radius[1];
      else
        helper->a1 = 1;
    }
    else
    {
      if(pi.IsSelected(op,2))
      {
        para->Radius[0] = sAbs(helper->x1-para->Center[0]);
        para->Radius[1] = sAbs(helper->y1-para->Center[1]);
      }

      if(pi.IsSelected(op,3))
        para->Radius[0] = sAbs(helper->x1-para->Center[0]);

      if(pi.IsSelected(op,4))
        para->Radius[1] = sAbs(helper->y1-para->Center[1]);
    }

    helper->x1 = para->Radius[0]+para->Center[0];
    helper->y1 = para->Radius[1]+para->Center[1];

    helper->cx = para->Center[0];
    helper->cy = para->Center[1];

    pi.HandleTex2D(op,1,para->Center[0],para->Center[1]);

    pi.HandleTex2D(op,2,helper->x1,helper->y1);
    pi.HandleTex2D(op,3,helper->x1,helper->cy);
    pi.HandleTex2D(op,4,helper->cx,helper->y1);

    pi.LineTex2D(para->Center[0],para->Center[1],helper->x1,helper->y1);
    pi.LineTex2D(para->Center[0],helper->y1,helper->x1,helper->y1);
    pi.LineTex2D(helper->x1,para->Center[1],helper->x1,helper->y1);
  ;
#line 5155 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiTwirl(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaTwirl sUNUSED *para = (GenBitmapParaTwirl *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Strength");
  sFloatControl *float_Strength = gh.Float(&para->Strength,-64.0000f,64.00000f,0.001000f);
  float_Strength->Default = 0.500000f; float_Strength->RightStep = 0.125000f;

  gh.Label(L"Gamma");
  sFloatControl *float_Gamma = gh.Float(&para->Gamma,0.000000f,64.00000f,0.010000f);
  float_Gamma->Default = 2.000000f; float_Gamma->RightStep = 0.125000f;

  gh.Label(L"Radius");
  gh.BeginTied();
  sFloatControl *float_Radius_0 = gh.Float(&para->Radius[0],0.000000f,4.000000f,0.001000f);
  float_Radius_0->Default = 0.250000f; float_Radius_0->RightStep = 0.125000f;
  sFloatControl *float_Radius_1 = gh.Float(&para->Radius[1],0.000000f,4.000000f,0.001000f);
  float_Radius_1->Default = 0.250000f; float_Radius_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center[0],-4.00000f,4.000000f,0.001000f);
  float_Center_0->Default = 0.500000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center[1],-4.00000f,4.000000f,0.001000f);
  float_Center_1->Default = 0.500000f; float_Center_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Border Clamp");
  gh.Flags(&para->Flags,L"off|x|y|both",gh.ChangeMsg);
}

void GenBitmapDefTwirl(wOp *op)
{
  GenBitmapParaTwirl sUNUSED *para = (GenBitmapParaTwirl *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Strength = 0.500000f;
  para->Gamma = 2.000000f;
  para->Radius[0] = 0.250000f;
  para->Radius[1] = 0.250000f;
  para->Center[0] = 0.500000f;
  para->Center[1] = 0.500000f;
}

void GenBitmapBindTwirl(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"strength"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"gamma"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
}
void GenBitmapBind2Twirl(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"strength");
    name[1] = sPoolString(L"gamma");
    name[2] = sPoolString(L"radius");
    name[3] = sPoolString(L"center");
    name[4] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeFloat,2,cmd->Data+4);
}
void GenBitmapBind3Twirl(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import strength : float;\n");
  tb.PrintF(L"  import gamma : float;\n");
  tb.PrintF(L"  import radius : float[2];\n");
  tb.PrintF(L"  import center : float[2];\n");
}
const sChar *GenBitmapWikiTwirl =
L"= GenBitmap : Twirl\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Twirl\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Gamma\n"
L" !i Gamma\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Border Clamp\n"
L" !i Flags\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i both\n"
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

sBool GenBitmapCmdDistort(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaDistort sUNUSED *para = (GenBitmapParaDistort *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap sUNUSED *in1 = cmd->GetInput<GenBitmap *>(1); in1;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1011 "wz3_bitmap_ops.ops"

    if(in0->XSize!=in1->XSize || in0->YSize!=in1->YSize) return 0;
    out->InitSize(in0);
    out->Distort(in0,in1,para->Strength,para->Flags);
  ;
#line 5347 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiDistort(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaDistort sUNUSED *para = (GenBitmapParaDistort *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Strength");
  sFloatControl *float_Strength = gh.Float(&para->Strength,-64.0000f,64.00000f,0.001000f);
  float_Strength->Default = 0.500000f; float_Strength->RightStep = 0.125000f;

  gh.Label(L"Border Clamp");
  gh.Flags(&para->Flags,L"off|x|y|both",gh.ChangeMsg);
}

void GenBitmapDefDistort(wOp *op)
{
  GenBitmapParaDistort sUNUSED *para = (GenBitmapParaDistort *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Strength = 0.500000f;
}

void GenBitmapBindDistort(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"strength"),val);
}
void GenBitmapBind2Distort(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"strength");
    name[1] = sPoolString(L"flags");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void GenBitmapBind3Distort(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import strength : float;\n");
}
const sChar *GenBitmapWikiDistort =
L"= GenBitmap : Distort\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Distort\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i\n"
L" !i *\n"
L"\n"
L" !i GenBitmap\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Border Clamp\n"
L" !i Flags\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i both\n"
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

sBool GenBitmapCmdNormals(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaNormals sUNUSED *para = (GenBitmapParaNormals *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1030 "wz3_bitmap_ops.ops"

    out->InitSize(in0);
    out->Normals(in0,para->Strength,para->Mode);
  ;
#line 5479 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiNormals(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaNormals sUNUSED *para = (GenBitmapParaNormals *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Strength");
  sFloatControl *float_Strength = gh.Float(&para->Strength,-64.0000f,64.00000f,0.001000f);
  float_Strength->Default = 0.500000f; float_Strength->RightStep = 0.125000f;

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L" 2d| 3d|tangent 2d|tangent 3d:*2normal|extra sharp",gh.ChangeMsg);
}

void GenBitmapDefNormals(wOp *op)
{
  GenBitmapParaNormals sUNUSED *para = (GenBitmapParaNormals *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Strength = 0.500000f;
}

void GenBitmapBindNormals(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"strength"),val);
}
void GenBitmapBind2Normals(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"strength");
    name[1] = sPoolString(L"mode");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void GenBitmapBind3Normals(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import strength : float;\n");
}
const sChar *GenBitmapWikiNormals =
L"= GenBitmap : Normals\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Normals\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i 2d\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3d\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent 2d\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent 3d\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i extra sharp\n"
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

struct GenBitmapHelperLight
{
#line 1069 "wz3_bitmap_ops.ops"
  sF32 x;
#line 1070 "wz3_bitmap_ops.ops"
  sF32 y;
#line 5614 "wz3_bitmap_ops.cpp"
};
sBool GenBitmapCmdLight(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaLight sUNUSED *para = (GenBitmapParaLight *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1061 "wz3_bitmap_ops.ops"

    out->Bump(0,para->Mode,
              para->Pos.x,para->Pos.y,para->Pos.z,para->Dir[0],para->Dir[1],
              para->Diffuse,para->Ambient,para->Outer,para->Falloff,para->Amplify,
              para->Ambient,0,0);
  ;
#line 5630 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndLight(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaLight sUNUSED *para = (GenBitmapParaLight *)(op->EditData); para;
  GenBitmapHelperLight *helper = (GenBitmapHelperLight *)(op->HelperData);
#line 1073 "wz3_bitmap_ops.ops"

    sF32 dx,dy,dist;
    if(pi.IsSelected(op,2))
    {
      dx = helper->x - para->Pos.x;
      dy = helper->y - para->Pos.y;
      dist = sClamp<sF32>(sSqrt(dx*dx+dy*dy)*2,-1,1);
      para->Dir[1] = sACos(dist)/sPIF;
      para->Dir[0] = sATan2(dx,dy)/sPI2F;
    }

    dist = (sCos(para->Dir[1]*sPIF))*0.5f;
    dx = sSin(para->Dir[0]*sPI2F)*dist;
    dy = sCos(para->Dir[0]*sPI2F)*dist;
    helper->x = para->Pos.x + dx;
    helper->y = para->Pos.y + dy;

    pi.HandleTex2D(op,1,para->Pos.x,para->Pos.y);
    if(para->Mode!=1)
    {
      pi.HandleTex2D(op,2,helper->x,helper->y);
      pi.LineTex2D(para->Pos.x,para->Pos.y,helper->x,helper->y);
    }
  ;
#line 5664 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiLight(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaLight sUNUSED *para = (GenBitmapParaLight *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"spot|point|directional",gh.LayoutMsg);

  if((para->Mode!=0x0002))
  {
    gh.Label(L"Pos");
    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&para->Pos.x,-16.0000f,16.00000f,0.020000f);
    float_Pos_0->Default = 0.500000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&para->Pos.y,-16.0000f,16.00000f,0.020000f);
    float_Pos_1->Default = 0.500000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&para->Pos.z,-16.0000f,16.00000f,0.020000f);
    float_Pos_2->Default = 0.500000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Mode!=0x0001))
  {
    gh.Label(L"Dir");
    gh.BeginTied();
    sFloatControl *float_Dir_0 = gh.Float(&para->Dir[0],-4.00000f,4.000000f,0.001000f);
    float_Dir_0->Default = 0.125000f; float_Dir_0->RightStep = 0.125000f;
    sFloatControl *float_Dir_1 = gh.Float(&para->Dir[1],-4.00000f,4.000000f,0.001000f);
    float_Dir_1->Default = 0.250000f; float_Dir_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Diffuse");
  gh.ColorPick(&para->Diffuse,L"rgba",0);

  gh.Label(L"Ambient");
  gh.ColorPick(&para->Ambient,L"rgba",0);

  gh.Label(L"Outer");
  sFloatControl *float_Outer = gh.Float(&para->Outer,0.000000f,1.000000f,0.001000f);
  float_Outer->Default = 0.750000f; float_Outer->RightStep = 0.125000f;

  gh.Label(L"Falloff");
  sFloatControl *float_Falloff = gh.Float(&para->Falloff,0.000000f,17.00000f,0.001000f);
  float_Falloff->Default = 1.000000f; float_Falloff->RightStep = 0.125000f;

  gh.Label(L"Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,-4.00000f,4.000000f,0.001000f);
  float_Amplify->Default = 0.500000f; float_Amplify->RightStep = 0.125000f;
}

void GenBitmapDefLight(wOp *op)
{
  GenBitmapParaLight sUNUSED *para = (GenBitmapParaLight *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Pos.x = 0.500000f;
  para->Pos.y = 0.500000f;
  para->Pos.z = 0.500000f;
  para->Dir[0] = 0.125000f;
  para->Dir[1] = 0.250000f;
  para->Diffuse = 0xffffffff;
  para->Ambient = 0xffffffff;
  para->Outer = 0.750000f;
  para->Falloff = 1.000000f;
  para->Amplify = 0.500000f;
}

void GenBitmapBindLight(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"diffuse"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"ambient"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"outer"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"falloff"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
}
void GenBitmapBind2Light(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"pos");
    name[2] = sPoolString(L"dir");
    name[3] = sPoolString(L"diffuse");
    name[4] = sPoolString(L"ambient");
    name[5] = sPoolString(L"outer");
    name[6] = sPoolString(L"falloff");
    name[7] = sPoolString(L"amplify");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+10);
}
void GenBitmapBind3Light(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import pos : float[3];\n");
  tb.PrintF(L"  import dir : float[2];\n");
  tb.PrintF(L"  import diffuse : color;\n");
  tb.PrintF(L"  import ambient : color;\n");
  tb.PrintF(L"  import outer : float;\n");
  tb.PrintF(L"  import falloff : float;\n");
  tb.PrintF(L"  import amplify : float;\n");
}
const sChar *GenBitmapWikiLight =
L"= GenBitmap : Light\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Light\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i spot\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i directional\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Pos\n"
L" !i Pos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir\n"
L" !i Dir\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Diffuse\n"
L" !i Diffuse\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Ambient\n"
L" !i Ambient\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Outer\n"
L" !i Outer\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff\n"
L" !i Falloff\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
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

struct GenBitmapHelperBump
{
#line 1137 "wz3_bitmap_ops.ops"
  sF32 x;
#line 1138 "wz3_bitmap_ops.ops"
  sF32 y;
#line 5903 "wz3_bitmap_ops.cpp"
};
sBool GenBitmapCmdBump(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaBump sUNUSED *para = (GenBitmapParaBump *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap sUNUSED *in1 = cmd->GetInput<GenBitmap *>(1); in1;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1126 "wz3_bitmap_ops.ops"

    if(out->Incompatible(in1)) return 0;

    out->Bump(in1,para->Mode,
              para->Pos.x,para->Pos.y,para->Pos.z,para->Dir[0],para->Dir[1],
              para->Diffuse,para->Ambient,para->Outer,para->Falloff,para->Amplify,
              para->Specular,para->Power,para->SpecAmp);
  ;
#line 5922 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndBump(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaBump sUNUSED *para = (GenBitmapParaBump *)(op->EditData); para;
  GenBitmapHelperBump *helper = (GenBitmapHelperBump *)(op->HelperData);
#line 1141 "wz3_bitmap_ops.ops"

    sF32 dx,dy,dist;
    if(pi.IsSelected(op,2))
    {
      dx = helper->x - para->Pos.x;
      dy = helper->y - para->Pos.y;
      dist = sClamp<sF32>(sSqrt(dx*dx+dy*dy)*2,-1,1);
      para->Dir[1] = sACos(dist)/sPIF;
      para->Dir[0] = sATan2(dx,dy)/sPI2F;
    }

    dist = (sCos(para->Dir[1]*sPIF))*0.5f;
    dx = sSin(para->Dir[0]*sPI2F)*dist;
    dy = sCos(para->Dir[0]*sPI2F)*dist;
    helper->x = para->Pos.x + dx;
    helper->y = para->Pos.y + dy;

    pi.HandleTex2D(op,1,para->Pos.x,para->Pos.y);
    if(para->Mode!=1)
    {
      pi.HandleTex2D(op,2,helper->x,helper->y);
      pi.LineTex2D(para->Pos.x,para->Pos.y,helper->x,helper->y);
    }
  ;
#line 5956 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiBump(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaBump sUNUSED *para = (GenBitmapParaBump *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"spot|point|directional",gh.LayoutMsg);

  if((para->Mode!=0x0002))
  {
    gh.Label(L"Pos");
    gh.BeginTied();
    sFloatControl *float_Pos_0 = gh.Float(&para->Pos.x,-16.0000f,16.00000f,0.020000f);
    float_Pos_0->Default = 0.500000f; float_Pos_0->RightStep = 0.125000f;
    sFloatControl *float_Pos_1 = gh.Float(&para->Pos.y,-16.0000f,16.00000f,0.020000f);
    float_Pos_1->Default = 0.500000f; float_Pos_1->RightStep = 0.125000f;
    sFloatControl *float_Pos_2 = gh.Float(&para->Pos.z,-16.0000f,16.00000f,0.020000f);
    float_Pos_2->Default = 0.500000f; float_Pos_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->Mode!=0x0001))
  {
    gh.Label(L"Dir");
    gh.BeginTied();
    sFloatControl *float_Dir_0 = gh.Float(&para->Dir[0],-4.00000f,4.000000f,0.001000f);
    float_Dir_0->Default = 0.125000f; float_Dir_0->RightStep = 0.125000f;
    sFloatControl *float_Dir_1 = gh.Float(&para->Dir[1],-4.00000f,4.000000f,0.001000f);
    float_Dir_1->Default = 0.250000f; float_Dir_1->RightStep = 0.125000f;
    gh.EndTied();

  }
  gh.Label(L"Diffuse");
  gh.ColorPick(&para->Diffuse,L"rgba",0);

  gh.Label(L"Ambient");
  gh.ColorPick(&para->Ambient,L"rgba",0);

  gh.Label(L"Outer");
  sFloatControl *float_Outer = gh.Float(&para->Outer,0.000000f,1.000000f,0.001000f);
  float_Outer->Default = 0.750000f; float_Outer->RightStep = 0.125000f;

  gh.Label(L"Falloff");
  sFloatControl *float_Falloff = gh.Float(&para->Falloff,0.000000f,17.00000f,0.001000f);
  float_Falloff->Default = 1.000000f; float_Falloff->RightStep = 0.125000f;

  gh.Label(L"Amplify");
  sFloatControl *float_Amplify = gh.Float(&para->Amplify,-4.00000f,4.000000f,0.001000f);
  float_Amplify->Default = 0.500000f; float_Amplify->RightStep = 0.125000f;

  gh.Group(L"specular");

  gh.Label(L"Specular");
  gh.ColorPick(&para->Specular,L"rgba",0);

  gh.Label(L"Power (hardness)");
  sFloatControl *float_Power = gh.Float(&para->Power,0.000000f,256.0000f,0.020000f);
  float_Power->Default = 16.00000f; float_Power->RightStep = 0.125000f;

  gh.Label(L"Amplify");
  sFloatControl *float_SpecAmp = gh.Float(&para->SpecAmp,0.000000f,4.000000f,0.001000f);
  float_SpecAmp->Default = 1.000000f; float_SpecAmp->RightStep = 0.125000f;
}

void GenBitmapDefBump(wOp *op)
{
  GenBitmapParaBump sUNUSED *para = (GenBitmapParaBump *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Pos.x = 0.500000f;
  para->Pos.y = 0.500000f;
  para->Pos.z = 0.500000f;
  para->Dir[0] = 0.125000f;
  para->Dir[1] = 0.250000f;
  para->Diffuse = 0xffffffff;
  para->Ambient = 0xffffffff;
  para->Outer = 0.750000f;
  para->Falloff = 1.000000f;
  para->Amplify = 0.500000f;
  para->Specular = 0xffffffff;
  para->Power = 16.00000f;
  para->SpecAmp = 1.000000f;
}

void GenBitmapBindBump(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"pos"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"diffuse"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"ambient"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"outer"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"falloff"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+10;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"specular"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"power"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+13;
  ctx->BindLocal(ctx->AddSymbol(L"amplify"),val);
}
void GenBitmapBind2Bump(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"pos");
    name[2] = sPoolString(L"dir");
    name[3] = sPoolString(L"diffuse");
    name[4] = sPoolString(L"ambient");
    name[5] = sPoolString(L"outer");
    name[6] = sPoolString(L"falloff");
    name[7] = sPoolString(L"amplify");
    name[8] = sPoolString(L"specular");
    name[9] = sPoolString(L"specular");
    name[10] = sPoolString(L"power");
    name[11] = sPoolString(L"amplify");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,3,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+6);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+7);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+8);
  ctx->AddImport(name[6],ScriptTypeFloat,1,cmd->Data+9);
  ctx->AddImport(name[7],ScriptTypeFloat,1,cmd->Data+10);
  ctx->AddImport(name[9],ScriptTypeColor,1,cmd->Data+11);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+12);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+13);
}
void GenBitmapBind3Bump(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import pos : float[3];\n");
  tb.PrintF(L"  import dir : float[2];\n");
  tb.PrintF(L"  import diffuse : color;\n");
  tb.PrintF(L"  import ambient : color;\n");
  tb.PrintF(L"  import outer : float;\n");
  tb.PrintF(L"  import falloff : float;\n");
  tb.PrintF(L"  import amplify : float;\n");
  tb.PrintF(L"  import specular : color;\n");
  tb.PrintF(L"  import power : float;\n");
  tb.PrintF(L"  import amplify : float;\n");
}
const sChar *GenBitmapWikiBump =
L"= GenBitmap : Bump\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bump\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i\n"
L" !i *\n"
L"\n"
L" !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i spot\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i directional\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Pos\n"
L" !i Pos\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Dir\n"
L" !i Dir\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Diffuse\n"
L" !i Diffuse\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Ambient\n"
L" !i Ambient\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Outer\n"
L" !i Outer\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Falloff\n"
L" !i Falloff\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i Amplify\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Specular\n"
L" !i Specular\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Power (hardness)\n"
L" !i Power\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Amplify\n"
L" !i SpecAmp\n"
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

sBool GenBitmapCmdDownsample(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaDownsample sUNUSED *para = (GenBitmapParaDownsample *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1179 "wz3_bitmap_ops.ops"

    sInt sx = para->Size&0xff;
    sInt sy = (para->Size>>8)&0xff;
    
    sx = sx ? 1<<(sx-1) : in0->XSize;
    sy = sy ? 1<<(sy-1) : in0->YSize;

    out->Init(sx,sy);
    out->Downsample(in0,para->Flags);
  ;
#line 6261 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiDownsample(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaDownsample sUNUSED *para = (GenBitmapParaDownsample *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L"current| 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8current| 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Mode");
  gh.Flags(&para->Flags,L"point|box",gh.ChangeMsg);
}

void GenBitmapDefDownsample(wOp *op)
{
  GenBitmapParaDownsample sUNUSED *para = (GenBitmapParaDownsample *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindDownsample(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2Downsample(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"mode");
  }
}
void GenBitmapBind3Downsample(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiDownsample =
L"= GenBitmap : Downsample\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Downsample\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Size\n"
L" !i Size\n"
L" !i current\n"
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
L" !i current\n"
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
L" !i Mode\n"
L" !i Flags\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i box\n"
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

sBool GenBitmapCmdText(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaText sUNUSED *para = (GenBitmapParaText *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; out->CopyFrom(in0); cmd->Output=out; }

  {
#line 1212 "wz3_bitmap_ops.ops"

    out->Text(para->Position[0],para->Position[1],para->Stretch,para->Height,para->Color,para->Flags,
              para->Leading,cmd->Strings[1],cmd->Strings[0])
  ;
#line 6494 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndText(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaText sUNUSED *para = (GenBitmapParaText *)(op->EditData); para;
#line 1217 "wz3_bitmap_ops.ops"

    pi.HandleTex2D(op,1,para->Position[0],para->Position[1]);
  ;
#line 6506 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiText(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaText sUNUSED *para = (GenBitmapParaText *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Position");
  gh.BeginTied();
  sFloatControl *float_Position_0 = gh.Float(&para->Position[0],-4.00000f,4.000000f,0.001000f);
  float_Position_0->Default = 0.000000f; float_Position_0->RightStep = 0.125000f;
  sFloatControl *float_Position_1 = gh.Float(&para->Position[1],-4.00000f,4.000000f,0.001000f);
  float_Position_1->Default = 0.000000f; float_Position_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Height");
  sFloatControl *float_Height = gh.Float(&para->Height,-16.0000f,16.00000f,0.001000f);
  float_Height->Default = 0.125000f; float_Height->RightStep = 0.125000f;

  gh.Label(L"Leading");
  sFloatControl *float_Leading = gh.Float(&para->Leading,-16.0000f,16.00000f,0.001000f);
  float_Leading->Default = 1.000000f; float_Leading->RightStep = 0.125000f;

  gh.Label(L"Stretch");
  sFloatControl *float_Stretch = gh.Float(&para->Stretch,0.000000f,16.00000f,0.001000f);
  float_Stretch->Default = 0.000000f; float_Stretch->RightStep = 0.125000f;

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Label(L"Center");
  gh.Flags(&para->Flags,L"-|x:*1-|y",gh.ChangeMsg);

  gh.Label(L"Style");
  gh.Flags(&para->Flags,L"*8-|italics:*9-|bold:*10-|symbols",gh.ChangeMsg);

  gh.Label(L"Font");
  gh.String(op->EditString[0]);

  gh.Group(L"Text");

  gh.Left = 0;
  {
    sTextWindow *tw = gh.Text(op->EditString[1],5,gh.Grid->Columns-gh.Left);
    tw->SetFont(sGui->FixedFont);
  }
}

void GenBitmapDefText(wOp *op)
{
  GenBitmapParaText sUNUSED *para = (GenBitmapParaText *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Height = 0.125000f;
  para->Leading = 1.000000f;
  para->Color = 0xffffffff;
  *op->EditString[0] = L"arial";
  *op->EditString[1] = L"hund.";
}

void GenBitmapBindText(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"position"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"height"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"leading"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"stretch"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"font"),val);
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+1;
  ctx->BindLocal(ctx->AddSymbol(L"text"),val);
}
void GenBitmapBind2Text(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"position");
    name[1] = sPoolString(L"height");
    name[2] = sPoolString(L"leading");
    name[3] = sPoolString(L"stretch");
    name[4] = sPoolString(L"color_");
    name[5] = sPoolString(L"center");
    name[6] = sPoolString(L"style");
    name[7] = sPoolString(L"font");
    name[8] = sPoolString(L"text");
    name[9] = sPoolString(L"text");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,2,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+3);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeColor,1,cmd->Data+5);
  ctx->AddImport(name[7],ScriptTypeString,1,cmd->Strings+0);
  ctx->AddImport(name[9],ScriptTypeString,1,cmd->Strings+1);
}
void GenBitmapBind3Text(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import position : float[2];\n");
  tb.PrintF(L"  import height : float;\n");
  tb.PrintF(L"  import leading : float;\n");
  tb.PrintF(L"  import stretch : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import font : string;\n");
  tb.PrintF(L"  import text : string;\n");
}
const sChar *GenBitmapWikiText =
L"= GenBitmap : Text\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Text\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i defaults to: Flat\n"
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
L" !i Position\n"
L" !i Position\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Height\n"
L" !i Height\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Leading\n"
L" !i Leading\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Stretch\n"
L" !i Stretch\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Center\n"
L" !i Flags\n"
L" !i x\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Style\n"
L" !i Flags\n"
L" !i italics\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i bold\n"
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
L" !i Font\n"
L" !i Font\n"
L" !i string\n"
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

sBool GenBitmapCmdExport(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaExport sUNUSED *para = (GenBitmapParaExport *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1231 "wz3_bitmap_ops.ops"

    sImage img;
    out->CopyFrom(in0);
    out->CopyTo(&img);
    return img.Save(cmd->Strings[0]);
  ;
#line 6763 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiExport(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaExport sUNUSED *para = (GenBitmapParaExport *)(op->EditData); para;
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

void GenBitmapDefExport(wOp *op)
{
  GenBitmapParaExport sUNUSED *para = (GenBitmapParaExport *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindExport(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeString,1);
  val->StringPtr = ((sPoolString *)cmd->Strings)+0;
  ctx->BindLocal(ctx->AddSymbol(L"filename"),val);
}
void GenBitmapBind2Export(wCommand *cmd,ScriptContext *ctx)
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
void GenBitmapBind3Export(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import filename : string;\n");
}
const sChar *GenBitmapWikiExport =
L"= GenBitmap : Export\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Export\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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

sBool GenBitmapCmdUnwrap(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaUnwrap sUNUSED *para = (GenBitmapParaUnwrap *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1247 "wz3_bitmap_ops.ops"

    out->Unwrap(in0,para->Mode);
  ;
#line 6873 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiUnwrap(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaUnwrap sUNUSED *para = (GenBitmapParaUnwrap *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"polar2normal|normal2polar|rect2normal",gh.ChangeMsg);

  gh.Label(L"Border Clamp");
  gh.Flags(&para->Mode,L"*4off|x|y|both",gh.ChangeMsg);
}

void GenBitmapDefUnwrap(wOp *op)
{
  GenBitmapParaUnwrap sUNUSED *para = (GenBitmapParaUnwrap *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindUnwrap(wCommand *cmd,ScriptContext *ctx)
{
}
void GenBitmapBind2Unwrap(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
    name[1] = sPoolString(L"mode");
  }
}
void GenBitmapBind3Unwrap(wOp *op,sTextBuffer &tb)
{
}
const sChar *GenBitmapWikiUnwrap =
L"= GenBitmap : Unwrap\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Unwrap\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i Mode\n"
L" !i Mode\n"
L" !i polar2normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i normal2polar\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i rect2normal\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Border Clamp\n"
L" !i Mode\n"
L" !i off\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i x\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i y\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i both\n"
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

sBool GenBitmapCmdBulge(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaBulge sUNUSED *para = (GenBitmapParaBulge *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1259 "wz3_bitmap_ops.ops"

    out->Bulge(in0,para->Amount);
  ;
#line 7000 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiBulge(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaBulge sUNUSED *para = (GenBitmapParaBulge *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Amount");
  sFloatControl *float_Amount = gh.Float(&para->Amount,-0.500000f,16.00000f,0.001000f);
  float_Amount->Default = 0.000000f; float_Amount->RightStep = 0.125000f;
}

void GenBitmapDefBulge(wOp *op)
{
  GenBitmapParaBulge sUNUSED *para = (GenBitmapParaBulge *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void GenBitmapBindBulge(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"amount"),val);
}
void GenBitmapBind2Bulge(wCommand *cmd,ScriptContext *ctx)
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
void GenBitmapBind3Bulge(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import amount : float;\n");
}
const sChar *GenBitmapWikiBulge =
L"= GenBitmap : Bulge\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bulge\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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

sBool GenBitmapCmdBricks(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaBricks sUNUSED *para = (GenBitmapParaBricks *)(cmd->Data); para;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1284 "wz3_bitmap_ops.ops"

    out->Bricks(
      1<<(para->Size&0xff),1<<((para->Size&0xff00)>>8),
      para->Color0,para->Color1,para->Joints,
      para->SizeJoints[0],para->SizeJoints[1],para->Count[0],para->Count[1],
      para->Seed,para->SingleWidthStones,para->Flags,
      para->Side,para->ColorBalance)
  ;
#line 7109 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapGuiBricks(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaBricks sUNUSED *para = (GenBitmapParaBricks *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Size");
  gh.Flags(&para->Size,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192:*8 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"Color0");
  gh.ColorPick(&para->Color0,L"rgba",0);

  gh.Label(L"Color1");
  gh.ColorPick(&para->Color1,L"rgba",0);

  gh.Label(L"Joints");
  gh.ColorPick(&para->Joints,L"rgba",0);

  gh.Label(L"SizeJoints");
  gh.BeginTied();
  sFloatControl *float_SizeJoints_0 = gh.Float(&para->SizeJoints[0],0.000000f,1.000000f,0.001000f);
  float_SizeJoints_0->Default = 0.180000f; float_SizeJoints_0->RightStep = 0.125000f;
  sFloatControl *float_SizeJoints_1 = gh.Float(&para->SizeJoints[1],0.000000f,1.000000f,0.001000f);
  float_SizeJoints_1->Default = 0.280000f; float_SizeJoints_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Count");
  gh.BeginTied();
  sIntControl *int_Count_0 = gh.Int(&para->Count[0],1,256,0.250000f);
  int_Count_0->Default = 0x00000012; int_Count_0->RightStep = 0.125000f;
  sIntControl *int_Count_1 = gh.Int(&para->Count[1],1,256,0.250000f);
  int_Count_1->Default = 0x0000001c; int_Count_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Seed");
  sIntControl *int_Seed = gh.Int(&para->Seed,0,255,0.125000f);
  int_Seed->Default = 0x00000000; int_Seed->RightStep = 0.125000f;

  gh.Label(L"SingleWidthStones");
  sIntControl *int_SingleWidthStones = gh.Int(&para->SingleWidthStones,0,255,0.125000f);
  int_SingleWidthStones->Default = 0x00000050; int_SingleWidthStones->RightStep = 0.125000f;

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*2-|no adjacent singles:*3-|joints color",gh.ChangeMsg);

  gh.Label(L"Multiply");
  gh.Flags(&para->Flags,L"*4 1| 2| 4| 8| 16| 32| 64| 128",gh.ChangeMsg);

  gh.Label(L"Side");
  sFloatControl *float_Side = gh.Float(&para->Side,0.000000f,1.000000f,0.010000f);
  float_Side->Default = 0.250000f; float_Side->RightStep = 0.125000f;

  gh.Label(L"ColorBalance");
  sFloatControl *float_ColorBalance = gh.Float(&para->ColorBalance,0.000000f,16.00000f,0.010000f);
  float_ColorBalance->Default = 1.000000f; float_ColorBalance->RightStep = 0.125000f;
}

void GenBitmapDefBricks(wOp *op)
{
  GenBitmapParaBricks sUNUSED *para = (GenBitmapParaBricks *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Size = 0x00000808;
  para->Color0 = 0xffff0000;
  para->Color1 = 0xffffff00;
  para->Joints = 0xff000000;
  para->SizeJoints[0] = 0.180000f;
  para->SizeJoints[1] = 0.280000f;
  para->Count[0] = 0x00000012;
  para->Count[1] = 0x0000001c;
  para->SingleWidthStones = 0x00000050;
  para->Side = 0.250000f;
  para->ColorBalance = 1.000000f;
}

void GenBitmapBindBricks(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color0"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color1"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"joints"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"sizejoints"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"sizejoints"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeInt,2);
  val->IntPtr = ((sInt *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"count"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"seed"),val);
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"singlewidthstones"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"side"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"colorbalance"),val);
}
void GenBitmapBind2Bricks(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[12];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"size");
    name[1] = sPoolString(L"color0");
    name[2] = sPoolString(L"color1");
    name[3] = sPoolString(L"joints");
    name[4] = sPoolString(L"sizejoints");
    name[5] = sPoolString(L"count");
    name[6] = sPoolString(L"seed");
    name[7] = sPoolString(L"singlewidthstones");
    name[8] = sPoolString(L"flags");
    name[9] = sPoolString(L"multiply");
    name[10] = sPoolString(L"side");
    name[11] = sPoolString(L"colorbalance");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+2);
  ctx->AddImport(name[3],ScriptTypeColor,1,cmd->Data+3);
  ctx->AddImport(name[4],ScriptTypeFloat,2,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeInt,2,cmd->Data+6);
  ctx->AddImport(name[6],ScriptTypeInt,1,cmd->Data+8);
  ctx->AddImport(name[7],ScriptTypeInt,1,cmd->Data+9);
  ctx->AddImport(name[10],ScriptTypeFloat,1,cmd->Data+11);
  ctx->AddImport(name[11],ScriptTypeFloat,1,cmd->Data+12);
}
void GenBitmapBind3Bricks(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color0 : color;\n");
  tb.PrintF(L"  import color1 : color;\n");
  tb.PrintF(L"  import joints : color;\n");
  tb.PrintF(L"  import sizejoints : float[2];\n");
  tb.PrintF(L"  import count : int[2];\n");
  tb.PrintF(L"  import seed : int;\n");
  tb.PrintF(L"  import singlewidthstones : int;\n");
  tb.PrintF(L"  import side : float;\n");
  tb.PrintF(L"  import colorbalance : float;\n");
}
const sChar *GenBitmapWikiBricks =
L"= GenBitmap : Bricks\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Bricks\n"
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
L" !i Color0\n"
L" !i Color0\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Color1\n"
L" !i Color1\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Joints\n"
L" !i Joints\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i SizeJoints\n"
L" !i SizeJoints\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L" !i Count\n"
L" !i Count\n"
L" !i int[2]\n"
L" !i *\n"
L"\n"
L" !i Seed\n"
L" !i Seed\n"
L" !i int\n"
L" !i *\n"
L"\n"
L" !i SingleWidthStones\n"
L" !i SingleWidthStones\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i no adjacent singles\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i joints color\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Multiply\n"
L" !i Flags\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Side\n"
L" !i Side\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ColorBalance\n"
L" !i ColorBalance\n"
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

sBool GenBitmapCmdVector(wExecutive *exe,wCommand *cmd)
{
  GenBitmapParaVector sUNUSED *para = (GenBitmapParaVector *)(cmd->Data); para;
  GenBitmap sUNUSED *in0 = cmd->GetInput<GenBitmap *>(0); in0;
  GenBitmap *out = (GenBitmap *) cmd->Output;
  if(!out) { out=new GenBitmap; cmd->Output=out; }

  {
#line 1308 "wz3_bitmap_ops.ops"

    out->CopyFrom(in0);
    out->Vector(para->Color,(GenBitmapArrayVector *)cmd->Array,cmd->ArrayCount);
  ;
#line 7524 "wz3_bitmap_ops.cpp"
    return 1;
  }
}

void GenBitmapHndVector(wPaintInfo &pi,wOp *op)
{
  GenBitmapParaVector sUNUSED *para = (GenBitmapParaVector *)(op->EditData); para;
#line 1313 "wz3_bitmap_ops.ops"

    sInt max = op->GetArrayCount();
    GenBitmapArrayVector *e = new GenBitmapArrayVector[max];
    for(sInt i=0;i<max;i++)
      e[i] = *op->GetArray<GenBitmapArrayVector>(i);

    sArray<GenBitmapVectorLoop> l;
    CalcGenBitmapVectorLoop(e,max,l);

    GenBitmapVectorLoop *le;
    sFORALL(l,le)
    {
      if((le->mode&7)==1)
      {
        for(sInt i=le->start;i<le->end;i++)
        {
          GenBitmapArrayVector *p0 = op->GetArray<GenBitmapArrayVector>(i);
          pi.HandleTex2D(op,i+1,p0->x,p0->y,i);
        }
      }
      else if((le->mode&7)==2)
      {
        for(sInt i=le->start;i<le->end;i+=3)
        {
          sInt ie = i+3; 
          if(ie==le->end)
            ie = le->start;
          GenBitmapArrayVector *p0 = op->GetArray<GenBitmapArrayVector>(i+0);
          GenBitmapArrayVector *p1 = op->GetArray<GenBitmapArrayVector>(i+1);
          GenBitmapArrayVector *p2 = op->GetArray<GenBitmapArrayVector>(i+2);
          GenBitmapArrayVector *p3 = op->GetArray<GenBitmapArrayVector>(ie );
          pi.HandleTex2D(op,i+1,p0->x,p0->y,i+0);
          pi.HandleTex2D(op,i+2,p1->x,p1->y,i+1);
          pi.HandleTex2D(op,i+3,p2->x,p2->y,i+2);
          pi.LineTex2D(p0->x,p0->y,p1->x,p1->y);
          pi.LineTex2D(p2->x,p2->y,p3->x,p3->y);
        }
      }
    }

    delete[] e;
  ;
#line 7575 "wz3_bitmap_ops.cpp"
}

void GenBitmapArrVector(wOp *op,sInt pos,void *mem)
{
  GenBitmapParaVector sUNUSED *para = (GenBitmapParaVector *)(op->EditData); para;
  GenBitmapArrayVector *e = (GenBitmapArrayVector *)(mem);
#line 1356 "wz3_bitmap_ops.ops"

    GenBitmapArrayVector *k0,*k1;
    sInt max = op->ArrayData.GetCount();

    if(max==0)
    {
      e->restart = 1;
      e->col = 0xffffffff;
      e->x = 0.5f;
      e->y = 0.5f;
    }
    else if(max==1)
    {
      e->restart = 0;
      e->col = 0xffffffff;
      e->x = 0.4f;
      e->y = 0.5f;
    }
    else 
    {
      if(pos==0)
      {
        k0 = (GenBitmapArrayVector *) op->ArrayData[0];
        k1 = (GenBitmapArrayVector *) op->ArrayData[1];
        e->restart = 0;
        e->col = k0->col;
        e->x = k0->x - (k1->x - k0->x);
        e->y = k0->y - (k1->y - k0->y);
      }
      else if(pos==max)
      {
        k0 = (GenBitmapArrayVector *) op->ArrayData[max-1];
        k1 = (GenBitmapArrayVector *) op->ArrayData[max-2];
        e->restart = 0;
        e->col = k0->col;
        e->x = k0->x - (k1->x - k0->x);
        e->y = k0->y - (k1->y - k0->y);
      }
      else
      {
        k0 = (GenBitmapArrayVector *) op->ArrayData[pos-1];
        k1 = (GenBitmapArrayVector *) op->ArrayData[pos];

        e->restart = 0;
        e->col = k0->col;
        e->x = (k1->x + k0->x)/2;
        e->y = (k1->y + k0->y)/2;
      }
    }
  ;
#line 7633 "wz3_bitmap_ops.cpp"
}

void GenBitmapGuiVector(wGridFrameHelper &gh,wOp *op)
{
  GenBitmapParaVector sUNUSED *para = (GenBitmapParaVector *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);
  void *ap;
  sInt pos = 0;
  gh.LabelWidth = 0;
  gh.Group(L"Elements");
  gh.Flags(&op->ArrayGroupMode,L"auto|all|hide",gh.LayoutMsg);
  gh.PushButton(L"clear all",gh.ArrayClearAllMsg);
  gh.ControlWidth = 1;
  gh.NextLine();
  gh.Grid->AddLabel(L"x",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"y",pos,gh.Line,1,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=1;
  gh.Grid->AddLabel(L"col",pos,gh.Line,4,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=4;
  gh.Grid->AddLabel(L"mode",pos,gh.Line,3,1,sGFLF_GROUP|sGFLF_NARROWGROUP); pos+=3;
  sBool hideall = (op->ArrayGroupMode==2);
  sBool hidesome = (op->ArrayGroupMode==3);
  if(op->ArrayGroupMode==0 && op->ArrayData.GetCount()>20) hideall=1;
  if(!hideall)
  {
    gh.EmptyLine = 0;
    gh.NextLine();
    sFORALL(op->ArrayData,ap)
    {
      GenBitmapArrayVector *elem = (GenBitmapArrayVector *)ap;
      if(hidesome && *((sU32 *)elem)==0) continue;

    sFloatControl *float_x = gh.Float(&elem->x,-4.00000f,4.000000f,0.010000f);
    float_x->Default = 0.000000f; float_x->RightStep = 0.125000f;

    sFloatControl *float_y = gh.Float(&elem->y,-4.00000f,4.000000f,0.010000f);
    float_y->Default = 0.000000f; float_y->RightStep = 0.125000f;

    gh.Color(&elem->col,L"rgba");

    gh.Flags(&elem->restart,L"-|line|spline:*3-|hole:*4-|evenodd",gh.ChangeMsg);
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

void GenBitmapDefVector(wOp *op)
{
  GenBitmapParaVector sUNUSED *para = (GenBitmapParaVector *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0xffffffff;
}

void GenBitmapBindVector(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
}
void GenBitmapBind2Vector(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"color_");
  }
  ctx->AddImport(name[0],ScriptTypeColor,1,cmd->Data+0);
}
void GenBitmapBind3Vector(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
}
const sChar *GenBitmapWikiVector =
L"= GenBitmap : Vector\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Vector\n"
L"\n"
L"  !i Output Type\n"
L"  !i GenBitmap\n"
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
L" !i defaults to: Flat\n"
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
L" !i Color\n"
L" !i Color\n"
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

void GenBitmapAnimMakeWz3Bitmap::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimMakeWz3Bitmap::Bind(class ScriptContext *sc,GenBitmapParaMakeWz3Bitmap *para)
{
};

void Texture2DAnimMakeTexture2::Init(class ScriptContext *sc)
{
};

void Texture2DAnimMakeTexture2::Bind(class ScriptContext *sc,Texture2DParaMakeTexture2 *para)
{
};

void UnitTestAnimUnitTestBitmap::Init(class ScriptContext *sc)
{
};

void UnitTestAnimUnitTestBitmap::Bind(class ScriptContext *sc,UnitTestParaUnitTestBitmap *para)
{
};

void GenBitmapAnimFlat::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimFlat::Bind(class ScriptContext *sc,GenBitmapParaFlat *para)
{
};

void GenBitmapAnimPerlin::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimPerlin::Bind(class ScriptContext *sc,GenBitmapParaPerlin *para)
{
};

void GenBitmapAnimCell::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimCell::Bind(class ScriptContext *sc,GenBitmapParaCell *para)
{
};

void GenBitmapAnimGradient::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimGradient::Bind(class ScriptContext *sc,GenBitmapParaGradient *para)
{
};

void GenBitmapAnimImport::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimImport::Bind(class ScriptContext *sc,GenBitmapParaImport *para)
{
};

void GenBitmapAnimImportAnim::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimImportAnim::Bind(class ScriptContext *sc,GenBitmapParaImportAnim *para)
{
};

void GenBitmapAnimGlowRect::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimGlowRect::Bind(class ScriptContext *sc,GenBitmapParaGlowRect *para)
{
};

void GenBitmapAnimDots::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimDots::Bind(class ScriptContext *sc,GenBitmapParaDots *para)
{
};

void GenBitmapAnimAtlas::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimAtlas::Bind(class ScriptContext *sc,GenBitmapParaAtlas *para)
{
};

void GenBitmapAnimColor::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimColor::Bind(class ScriptContext *sc,GenBitmapParaColor *para)
{
};

void GenBitmapAnimRange::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimRange::Bind(class ScriptContext *sc,GenBitmapParaRange *para)
{
};

void GenBitmapAnimHSCB::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimHSCB::Bind(class ScriptContext *sc,GenBitmapParaHSCB *para)
{
};

void GenBitmapAnimBitcrusher::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimBitcrusher::Bind(class ScriptContext *sc,GenBitmapParaBitcrusher *para)
{
};

void GenBitmapAnimMerge::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimMerge::Bind(class ScriptContext *sc,GenBitmapParaMerge *para)
{
};

void GenBitmapAnimPreMulAlpha::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimPreMulAlpha::Bind(class ScriptContext *sc,GenBitmapParaPreMulAlpha *para)
{
};

void GenBitmapAnimMask::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimMask::Bind(class ScriptContext *sc,GenBitmapParaMask *para)
{
};

void GenBitmapAnimColorBalance::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimColorBalance::Bind(class ScriptContext *sc,GenBitmapParaColorBalance *para)
{
};

void GenBitmapAnimBlur::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimBlur::Bind(class ScriptContext *sc,GenBitmapParaBlur *para)
{
};

void GenBitmapAnimSharpen::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimSharpen::Bind(class ScriptContext *sc,GenBitmapParaSharpen *para)
{
};

void GenBitmapAnimRotate::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimRotate::Bind(class ScriptContext *sc,GenBitmapParaRotate *para)
{
};

void GenBitmapAnimRotateMul::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimRotateMul::Bind(class ScriptContext *sc,GenBitmapParaRotateMul *para)
{
};

void GenBitmapAnimTwirl::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimTwirl::Bind(class ScriptContext *sc,GenBitmapParaTwirl *para)
{
};

void GenBitmapAnimDistort::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimDistort::Bind(class ScriptContext *sc,GenBitmapParaDistort *para)
{
};

void GenBitmapAnimNormals::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimNormals::Bind(class ScriptContext *sc,GenBitmapParaNormals *para)
{
};

void GenBitmapAnimLight::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimLight::Bind(class ScriptContext *sc,GenBitmapParaLight *para)
{
};

void GenBitmapAnimBump::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimBump::Bind(class ScriptContext *sc,GenBitmapParaBump *para)
{
};

void GenBitmapAnimDownsample::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimDownsample::Bind(class ScriptContext *sc,GenBitmapParaDownsample *para)
{
};

void GenBitmapAnimText::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimText::Bind(class ScriptContext *sc,GenBitmapParaText *para)
{
};

void GenBitmapAnimExport::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimExport::Bind(class ScriptContext *sc,GenBitmapParaExport *para)
{
};

void GenBitmapAnimUnwrap::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimUnwrap::Bind(class ScriptContext *sc,GenBitmapParaUnwrap *para)
{
};

void GenBitmapAnimBulge::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimBulge::Bind(class ScriptContext *sc,GenBitmapParaBulge *para)
{
};

void GenBitmapAnimBricks::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimBricks::Bind(class ScriptContext *sc,GenBitmapParaBricks *para)
{
};

void GenBitmapAnimVector::Init(class ScriptContext *sc)
{
};

void GenBitmapAnimVector::Bind(class ScriptContext *sc,GenBitmapParaVector *para)
{
};


/****************************************************************************/

void AddTypes_wz3_bitmap_ops(sBool secondary)
{
  sVERIFY(Doc);

  Doc->Types.AddTail(GenBitmapType = new GenBitmapType_);
  GenBitmapType->Secondary = secondary;
  GenBitmapType->ColumnHeaders[0] = L"generator";
  GenBitmapType->ColumnHeaders[1] = L"filters";
  GenBitmapType->ColumnHeaders[2] = L"special";
  GenBitmapType->ColumnHeaders[3] = L"samplers";

}

/****************************************************************************/

void AddOps_wz3_bitmap_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"MakeWz3Bitmap";
  cl->Label = L"MakeWz3Bitmap";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdMakeWz3Bitmap;
  cl->MakeGui = GenBitmapGuiMakeWz3Bitmap;
  cl->SetDefaults = GenBitmapDefMakeWz3Bitmap;
  cl->BindPara = GenBitmapBindMakeWz3Bitmap;
  cl->Bind2Para = GenBitmapBind2MakeWz3Bitmap;
  cl->Bind3Para = GenBitmapBind3MakeWz3Bitmap;
  cl->WikiText = GenBitmapWikiMakeWz3Bitmap;
  cl->Column = 3;
  cl->Flags = 0x00c0;
  in = cl->Inputs.AddMany(1);
  in[0].Type = BitmapBaseType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"MakeTexture2";
  cl->Label = L"MakeTexture2";
  cl->OutputType = Texture2DType;
  cl->TabType = GenBitmapType;
  cl->Command = Texture2DCmdMakeTexture2;
  cl->MakeGui = Texture2DGuiMakeTexture2;
  cl->SetDefaults = Texture2DDefMakeTexture2;
  cl->BindPara = Texture2DBindMakeTexture2;
  cl->Bind2Para = Texture2DBind2MakeTexture2;
  cl->Bind3Para = Texture2DBind3MakeTexture2;
  cl->WikiText = Texture2DWikiMakeTexture2;
  cl->ParaWords = 1;
  cl->Column = 3;
  cl->Flags = 0x0080;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"UnitTestBitmap";
  cl->Label = L"UnitTestBitmap";
  cl->OutputType = UnitTestType;
  cl->TabType = GenBitmapType;
  cl->Command = UnitTestCmdUnitTestBitmap;
  cl->MakeGui = UnitTestGuiUnitTestBitmap;
  cl->SetDefaults = UnitTestDefUnitTestBitmap;
  cl->BindPara = UnitTestBindUnitTestBitmap;
  cl->Bind2Para = UnitTestBind2UnitTestBitmap;
  cl->Bind3Para = UnitTestBind3UnitTestBitmap;
  cl->WikiText = UnitTestWikiUnitTestBitmap;
  cl->ParaStrings = 1;
  cl->ParaWords = 1;
  cl->FileOutMask = 1;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Flat";
  cl->Label = L"Flat";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdFlat;
  cl->MakeGui = GenBitmapGuiFlat;
  cl->SetDefaults = GenBitmapDefFlat;
  cl->BindPara = GenBitmapBindFlat;
  cl->Bind2Para = GenBitmapBind2Flat;
  cl->Bind3Para = GenBitmapBind3Flat;
  cl->WikiText = GenBitmapWikiFlat;
  cl->ParaWords = 2;
  cl->Shortcut = 'f';
  cl->Flags = 0x1000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Perlin";
  cl->Label = L"Perlin";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdPerlin;
  cl->MakeGui = GenBitmapGuiPerlin;
  cl->SetDefaults = GenBitmapDefPerlin;
  cl->BindPara = GenBitmapBindPerlin;
  cl->Bind2Para = GenBitmapBind2Perlin;
  cl->Bind3Para = GenBitmapBind3Perlin;
  cl->WikiText = GenBitmapWikiPerlin;
  cl->ParaWords = 10;
  cl->Shortcut = 'p';
  cl->Flags = 0x1000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Cell";
  cl->Label = L"Cell";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdCell;
  cl->MakeGui = GenBitmapGuiCell;
  cl->SetDefaults = GenBitmapDefCell;
  cl->BindPara = GenBitmapBindCell;
  cl->Bind2Para = GenBitmapBind2Cell;
  cl->Bind3Para = GenBitmapBind3Cell;
  cl->WikiText = GenBitmapWikiCell;
  cl->ParaWords = 12;
  cl->Shortcut = 'c';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Gradient";
  cl->Label = L"Gradient";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdGradient;
  cl->MakeGui = GenBitmapGuiGradient;
  cl->SetDefaults = GenBitmapDefGradient;
  cl->BindPara = GenBitmapBindGradient;
  cl->Bind2Para = GenBitmapBind2Gradient;
  cl->Bind3Para = GenBitmapBind3Gradient;
  cl->WikiText = GenBitmapWikiGradient;
  cl->SetDefaultsArray = GenBitmapArrGradient;
  cl->ArrayCount = 2;
  cl->ParaWords = 2;
  cl->Shortcut = 'G';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Import";
  cl->Label = L"Import";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdImport;
  cl->MakeGui = GenBitmapGuiImport;
  cl->SetDefaults = GenBitmapDefImport;
  cl->BindPara = GenBitmapBindImport;
  cl->Bind2Para = GenBitmapBind2Import;
  cl->Bind3Para = GenBitmapBind3Import;
  cl->WikiText = GenBitmapWikiImport;
  cl->ParaStrings = 1;
  cl->FileInMask = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ImportAnim";
  cl->Label = L"ImportAnim";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdImportAnim;
  cl->MakeGui = GenBitmapGuiImportAnim;
  cl->SetDefaults = GenBitmapDefImportAnim;
  cl->BindPara = GenBitmapBindImportAnim;
  cl->Bind2Para = GenBitmapBind2ImportAnim;
  cl->Bind3Para = GenBitmapBind3ImportAnim;
  cl->WikiText = GenBitmapWikiImportAnim;
  cl->ParaStrings = 1;
  cl->FileInMask = 1;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"GlowRect";
  cl->Label = L"GlowRect";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdGlowRect;
  cl->MakeGui = GenBitmapGuiGlowRect;
  cl->SetDefaults = GenBitmapDefGlowRect;
  cl->BindPara = GenBitmapBindGlowRect;
  cl->Bind2Para = GenBitmapBind2GlowRect;
  cl->Bind3Para = GenBitmapBind3GlowRect;
  cl->WikiText = GenBitmapWikiGlowRect;
  cl->Handles = GenBitmapHndGlowRect;
  cl->ParaWords = 11;
  cl->HelperWords = (sizeof(GenBitmapHelperGlowRect)+3)/4;
  cl->Shortcut = 'g';
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = Doc->FindClass(L"Flat",L"GenBitmap");
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Dots";
  cl->Label = L"Dots";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdDots;
  cl->MakeGui = GenBitmapGuiDots;
  cl->SetDefaults = GenBitmapDefDots;
  cl->BindPara = GenBitmapBindDots;
  cl->Bind2Para = GenBitmapBind2Dots;
  cl->Bind3Para = GenBitmapBind3Dots;
  cl->WikiText = GenBitmapWikiDots;
  cl->ParaWords = 4;
  cl->Shortcut = 'w';
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = Doc->FindClass(L"Flat",L"GenBitmap");
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Atlas";
  cl->Label = L"Atlas";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdAtlas;
  cl->MakeGui = GenBitmapGuiAtlas;
  cl->SetDefaults = GenBitmapDefAtlas;
  cl->BindPara = GenBitmapBindAtlas;
  cl->Bind2Para = GenBitmapBind2Atlas;
  cl->Bind3Para = GenBitmapBind3Atlas;
  cl->WikiText = GenBitmapWikiAtlas;
  cl->ParaWords = 2;
  cl->Column = 2;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Color";
  cl->Label = L"Color";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdColor;
  cl->MakeGui = GenBitmapGuiColor;
  cl->SetDefaults = GenBitmapDefColor;
  cl->BindPara = GenBitmapBindColor;
  cl->Bind2Para = GenBitmapBind2Color;
  cl->Bind3Para = GenBitmapBind3Color;
  cl->WikiText = GenBitmapWikiColor;
  cl->ParaWords = 2;
  cl->Shortcut = 'C';
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Range";
  cl->Label = L"Range";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdRange;
  cl->MakeGui = GenBitmapGuiRange;
  cl->SetDefaults = GenBitmapDefRange;
  cl->BindPara = GenBitmapBindRange;
  cl->Bind2Para = GenBitmapBind2Range;
  cl->Bind3Para = GenBitmapBind3Range;
  cl->WikiText = GenBitmapWikiRange;
  cl->ParaWords = 3;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"HSCB";
  cl->Label = L"HSCB";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdHSCB;
  cl->MakeGui = GenBitmapGuiHSCB;
  cl->SetDefaults = GenBitmapDefHSCB;
  cl->BindPara = GenBitmapBindHSCB;
  cl->Bind2Para = GenBitmapBind2HSCB;
  cl->Bind3Para = GenBitmapBind3HSCB;
  cl->WikiText = GenBitmapWikiHSCB;
  cl->ParaWords = 4;
  cl->Shortcut = 'h';
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bitcrusher";
  cl->Label = L"Bitcrusher";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdBitcrusher;
  cl->MakeGui = GenBitmapGuiBitcrusher;
  cl->SetDefaults = GenBitmapDefBitcrusher;
  cl->BindPara = GenBitmapBindBitcrusher;
  cl->Bind2Para = GenBitmapBind2Bitcrusher;
  cl->Bind3Para = GenBitmapBind3Bitcrusher;
  cl->WikiText = GenBitmapWikiBitcrusher;
  cl->ParaWords = 2;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Merge";
  cl->Label = L"Merge";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdMerge;
  cl->MakeGui = GenBitmapGuiMerge;
  cl->SetDefaults = GenBitmapDefMerge;
  cl->BindPara = GenBitmapBindMerge;
  cl->Bind2Para = GenBitmapBind2Merge;
  cl->Bind3Para = GenBitmapBind3Merge;
  cl->WikiText = GenBitmapWikiMerge;
  cl->ParaWords = 1;
  cl->Shortcut = 'a';
  cl->Column = 2;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"PreMulAlpha";
  cl->Label = L"PreMulAlpha";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdPreMulAlpha;
  cl->MakeGui = GenBitmapGuiPreMulAlpha;
  cl->SetDefaults = GenBitmapDefPreMulAlpha;
  cl->BindPara = GenBitmapBindPreMulAlpha;
  cl->Bind2Para = GenBitmapBind2PreMulAlpha;
  cl->Bind3Para = GenBitmapBind3PreMulAlpha;
  cl->WikiText = GenBitmapWikiPreMulAlpha;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Mask";
  cl->Label = L"Mask";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdMask;
  cl->MakeGui = GenBitmapGuiMask;
  cl->SetDefaults = GenBitmapDefMask;
  cl->BindPara = GenBitmapBindMask;
  cl->Bind2Para = GenBitmapBind2Mask;
  cl->Bind3Para = GenBitmapBind3Mask;
  cl->WikiText = GenBitmapWikiMask;
  cl->ParaWords = 1;
  cl->Shortcut = 'm';
  cl->Column = 2;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(3);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = GenBitmapType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  in[2].Type = GenBitmapType;
  in[2].DefaultClass = 0;
  in[2].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ColorBalance";
  cl->Label = L"ColorBalance";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdColorBalance;
  cl->MakeGui = GenBitmapGuiColorBalance;
  cl->SetDefaults = GenBitmapDefColorBalance;
  cl->BindPara = GenBitmapBindColorBalance;
  cl->Bind2Para = GenBitmapBind2ColorBalance;
  cl->Bind3Para = GenBitmapBind3ColorBalance;
  cl->WikiText = GenBitmapWikiColorBalance;
  cl->ParaWords = 9;
  cl->Column = 1;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Blur";
  cl->Label = L"Blur";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdBlur;
  cl->MakeGui = GenBitmapGuiBlur;
  cl->SetDefaults = GenBitmapDefBlur;
  cl->BindPara = GenBitmapBindBlur;
  cl->Bind2Para = GenBitmapBind2Blur;
  cl->Bind3Para = GenBitmapBind3Blur;
  cl->WikiText = GenBitmapWikiBlur;
  cl->ParaWords = 4;
  cl->Shortcut = 'b';
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sharpen";
  cl->Label = L"Sharpen";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdSharpen;
  cl->MakeGui = GenBitmapGuiSharpen;
  cl->SetDefaults = GenBitmapDefSharpen;
  cl->BindPara = GenBitmapBindSharpen;
  cl->Bind2Para = GenBitmapBind2Sharpen;
  cl->Bind3Para = GenBitmapBind3Sharpen;
  cl->WikiText = GenBitmapWikiSharpen;
  cl->ParaWords = 4;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Rotate";
  cl->Label = L"Rotate";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdRotate;
  cl->MakeGui = GenBitmapGuiRotate;
  cl->SetDefaults = GenBitmapDefRotate;
  cl->BindPara = GenBitmapBindRotate;
  cl->Bind2Para = GenBitmapBind2Rotate;
  cl->Bind3Para = GenBitmapBind3Rotate;
  cl->WikiText = GenBitmapWikiRotate;
  cl->Handles = GenBitmapHndRotate;
  cl->ParaWords = 9;
  cl->HelperWords = (sizeof(GenBitmapHelperRotate)+3)/4;
  cl->Shortcut = 'r';
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"RotateMul";
  cl->Label = L"RotateMul";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdRotateMul;
  cl->MakeGui = GenBitmapGuiRotateMul;
  cl->SetDefaults = GenBitmapDefRotateMul;
  cl->BindPara = GenBitmapBindRotateMul;
  cl->Bind2Para = GenBitmapBind2RotateMul;
  cl->Bind3Para = GenBitmapBind3RotateMul;
  cl->WikiText = GenBitmapWikiRotateMul;
  cl->Handles = GenBitmapHndRotateMul;
  cl->ParaWords = 10;
  cl->Shortcut = 'R';
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Twirl";
  cl->Label = L"Twirl";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdTwirl;
  cl->MakeGui = GenBitmapGuiTwirl;
  cl->SetDefaults = GenBitmapDefTwirl;
  cl->BindPara = GenBitmapBindTwirl;
  cl->Bind2Para = GenBitmapBind2Twirl;
  cl->Bind3Para = GenBitmapBind3Twirl;
  cl->WikiText = GenBitmapWikiTwirl;
  cl->Handles = GenBitmapHndTwirl;
  cl->ParaWords = 7;
  cl->HelperWords = (sizeof(GenBitmapHelperTwirl)+3)/4;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Distort";
  cl->Label = L"Distort";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdDistort;
  cl->MakeGui = GenBitmapGuiDistort;
  cl->SetDefaults = GenBitmapDefDistort;
  cl->BindPara = GenBitmapBindDistort;
  cl->Bind2Para = GenBitmapBind2Distort;
  cl->Bind3Para = GenBitmapBind3Distort;
  cl->WikiText = GenBitmapWikiDistort;
  cl->ParaWords = 2;
  cl->Shortcut = 'd';
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = GenBitmapType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Normals";
  cl->Label = L"Normals";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdNormals;
  cl->MakeGui = GenBitmapGuiNormals;
  cl->SetDefaults = GenBitmapDefNormals;
  cl->BindPara = GenBitmapBindNormals;
  cl->Bind2Para = GenBitmapBind2Normals;
  cl->Bind3Para = GenBitmapBind3Normals;
  cl->WikiText = GenBitmapWikiNormals;
  cl->ParaWords = 2;
  cl->Shortcut = 'n';
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Light";
  cl->Label = L"Light";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdLight;
  cl->MakeGui = GenBitmapGuiLight;
  cl->SetDefaults = GenBitmapDefLight;
  cl->BindPara = GenBitmapBindLight;
  cl->Bind2Para = GenBitmapBind2Light;
  cl->Bind3Para = GenBitmapBind3Light;
  cl->WikiText = GenBitmapWikiLight;
  cl->Handles = GenBitmapHndLight;
  cl->ParaWords = 11;
  cl->HelperWords = (sizeof(GenBitmapHelperLight)+3)/4;
  cl->Shortcut = 'L';
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bump";
  cl->Label = L"Bump";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdBump;
  cl->MakeGui = GenBitmapGuiBump;
  cl->SetDefaults = GenBitmapDefBump;
  cl->BindPara = GenBitmapBindBump;
  cl->Bind2Para = GenBitmapBind2Bump;
  cl->Bind3Para = GenBitmapBind3Bump;
  cl->WikiText = GenBitmapWikiBump;
  cl->Handles = GenBitmapHndBump;
  cl->ParaWords = 14;
  cl->HelperWords = (sizeof(GenBitmapHelperBump)+3)/4;
  cl->Shortcut = 'B';
  cl->Column = 2;
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(2);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = GenBitmapType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Downsample";
  cl->Label = L"Downsample";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdDownsample;
  cl->MakeGui = GenBitmapGuiDownsample;
  cl->SetDefaults = GenBitmapDefDownsample;
  cl->BindPara = GenBitmapBindDownsample;
  cl->Bind2Para = GenBitmapBind2Downsample;
  cl->Bind3Para = GenBitmapBind3Downsample;
  cl->WikiText = GenBitmapWikiDownsample;
  cl->ParaWords = 2;
  cl->Column = 3;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Text";
  cl->Label = L"Text";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdText;
  cl->MakeGui = GenBitmapGuiText;
  cl->SetDefaults = GenBitmapDefText;
  cl->BindPara = GenBitmapBindText;
  cl->Bind2Para = GenBitmapBind2Text;
  cl->Bind3Para = GenBitmapBind3Text;
  cl->WikiText = GenBitmapWikiText;
  cl->Handles = GenBitmapHndText;
  cl->ParaStrings = 2;
  cl->ParaWords = 7;
  cl->Shortcut = 't';
  cl->Flags = 0x1800;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = Doc->FindClass(L"Flat",L"GenBitmap");
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Export";
  cl->Label = L"Export";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdExport;
  cl->MakeGui = GenBitmapGuiExport;
  cl->SetDefaults = GenBitmapDefExport;
  cl->BindPara = GenBitmapBindExport;
  cl->Bind2Para = GenBitmapBind2Export;
  cl->Bind3Para = GenBitmapBind3Export;
  cl->WikiText = GenBitmapWikiExport;
  cl->ParaStrings = 1;
  cl->FileOutMask = 1;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Unwrap";
  cl->Label = L"Unwrap";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdUnwrap;
  cl->MakeGui = GenBitmapGuiUnwrap;
  cl->SetDefaults = GenBitmapDefUnwrap;
  cl->BindPara = GenBitmapBindUnwrap;
  cl->Bind2Para = GenBitmapBind2Unwrap;
  cl->Bind3Para = GenBitmapBind3Unwrap;
  cl->WikiText = GenBitmapWikiUnwrap;
  cl->ParaWords = 1;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bulge";
  cl->Label = L"Bulge";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdBulge;
  cl->MakeGui = GenBitmapGuiBulge;
  cl->SetDefaults = GenBitmapDefBulge;
  cl->BindPara = GenBitmapBindBulge;
  cl->Bind2Para = GenBitmapBind2Bulge;
  cl->Bind3Para = GenBitmapBind3Bulge;
  cl->WikiText = GenBitmapWikiBulge;
  cl->ParaWords = 1;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Bricks";
  cl->Label = L"Bricks";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdBricks;
  cl->MakeGui = GenBitmapGuiBricks;
  cl->SetDefaults = GenBitmapDefBricks;
  cl->BindPara = GenBitmapBindBricks;
  cl->Bind2Para = GenBitmapBind2Bricks;
  cl->Bind3Para = GenBitmapBind3Bricks;
  cl->WikiText = GenBitmapWikiBricks;
  cl->ParaWords = 13;
  cl->Shortcut = 'q';
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Vector";
  cl->Label = L"Vector";
  cl->OutputType = GenBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = GenBitmapCmdVector;
  cl->MakeGui = GenBitmapGuiVector;
  cl->SetDefaults = GenBitmapDefVector;
  cl->BindPara = GenBitmapBindVector;
  cl->Bind2Para = GenBitmapBind2Vector;
  cl->Bind3Para = GenBitmapBind3Vector;
  cl->WikiText = GenBitmapWikiVector;
  cl->Handles = GenBitmapHndVector;
  cl->SetDefaultsArray = GenBitmapArrVector;
  cl->ArrayCount = 4;
  cl->ParaWords = 1;
  cl->Column = 1;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = GenBitmapType;
  in[0].DefaultClass = Doc->FindClass(L"Flat",L"GenBitmap");
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz3_bitmap_ops,0x110,AddOps_wz3_bitmap_ops,0);


/****************************************************************************/


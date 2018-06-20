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
#include "wz4_audio_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/


/****************************************************************************/

sBool PocBitmapCmdAudioRMS(wExecutive *exe,wCommand *cmd)
{
  PocBitmapParaAudioRMS sUNUSED *para = (PocBitmapParaAudioRMS *)(cmd->Data); para;
  PocBitmap *out = (PocBitmap *) cmd->Output;
  if(!out) { out=new PocBitmap; cmd->Output=out; }

  {
#line 30 "wz4_audio_ops.ops"

    if(!Wz4Audiolyzer::AudioAvailable())
    {
      cmd->SetError(L"No audio input signal available");
      return 0;
    }

    Wz4Audiolyzer::RMSImage(out->Image,1<<(para->Width+3),1<<(para->Height+3),1<<(para->ChunkSize+6));
  ;
#line 42 "wz4_audio_ops.cpp"
    return 1;
  }
}

void PocBitmapGuiAudioRMS(wGridFrameHelper &gh,wOp *op)
{
  PocBitmapParaAudioRMS sUNUSED *para = (PocBitmapParaAudioRMS *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Width");
  gh.Flags(&para->Width,L" 8| 16| 32| 64| 128| 256| 512| 1024| 2048",gh.ChangeMsg);

  gh.Label(L"Height");
  gh.Flags(&para->Height,L" 8| 16| 32| 64| 128| 256| 512| 1024| 2048",gh.ChangeMsg);

  gh.Label(L"ChunkSize");
  gh.Flags(&para->ChunkSize,L" 64| 128| 256| 512| 1024| 2048| 4096| 8192| 16384| 32768",gh.ChangeMsg);
}

void PocBitmapDefAudioRMS(wOp *op)
{
  PocBitmapParaAudioRMS sUNUSED *para = (PocBitmapParaAudioRMS *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Width = 0x00000007;
  para->Height = 0x00000001;
  para->ChunkSize = 0x00000004;
}

void PocBitmapBindAudioRMS(wCommand *cmd,ScriptContext *ctx)
{
}
void PocBitmapBind2AudioRMS(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"width");
    name[1] = sPoolString(L"height");
    name[2] = sPoolString(L"chunksize");
  }
}
void PocBitmapBind3AudioRMS(wOp *op,sTextBuffer &tb)
{
}
const sChar *PocBitmapWikiAudioRMS =
L"= PocBitmap : AudioRMS\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i AudioRMS\n"
L"\n"
L"  !i Output Type\n"
L"  !i PocBitmap\n"
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
L" !i Width\n"
L" !i Width\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i Height\n"
L" !i Height\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i ChunkSize\n"
L" !i ChunkSize\n"
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
L" !i \n"
L" !i \n"
L" !i 16384\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32768\n"
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

sBool PocBitmapCmdAudioSpectogram(wExecutive *exe,wCommand *cmd)
{
  PocBitmapParaAudioSpectogram sUNUSED *para = (PocBitmapParaAudioSpectogram *)(cmd->Data); para;
  PocBitmap *out = (PocBitmap *) cmd->Output;
  if(!out) { out=new PocBitmap; cmd->Output=out; }

  {
#line 52 "wz4_audio_ops.ops"

    if(!Wz4Audiolyzer::AudioAvailable())
    {
      cmd->SetError(L"No audio input signal available");
      return 0;
    }

    Wz4Audiolyzer::Spectogram(out->Image,1<<(para->Width+3),1<<(para->FFTSize+6));
  ;
#line 254 "wz4_audio_ops.cpp"
    return 1;
  }
}

void PocBitmapGuiAudioSpectogram(wGridFrameHelper &gh,wOp *op)
{
  PocBitmapParaAudioSpectogram sUNUSED *para = (PocBitmapParaAudioSpectogram *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Width");
  gh.Flags(&para->Width,L" 8| 16| 32| 64| 128| 256| 512| 1024| 2048",gh.ChangeMsg);

  gh.Label(L"FFTSize");
  gh.Flags(&para->FFTSize,L" 64| 128| 256| 512| 1024| 2048| 4096| 8192| 16384| 32768",gh.ChangeMsg);
}

void PocBitmapDefAudioSpectogram(wOp *op)
{
  PocBitmapParaAudioSpectogram sUNUSED *para = (PocBitmapParaAudioSpectogram *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Width = 0x00000007;
  para->FFTSize = 0x00000004;
}

void PocBitmapBindAudioSpectogram(wCommand *cmd,ScriptContext *ctx)
{
}
void PocBitmapBind2AudioSpectogram(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"width");
    name[1] = sPoolString(L"fftsize");
  }
}
void PocBitmapBind3AudioSpectogram(wOp *op,sTextBuffer &tb)
{
}
const sChar *PocBitmapWikiAudioSpectogram =
L"= PocBitmap : AudioSpectogram\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i AudioSpectogram\n"
L"\n"
L"  !i Output Type\n"
L"  !i PocBitmap\n"
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
L" !i Width\n"
L" !i Width\n"
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
L"!T 4 : 1 1 1 2\n"
L" !i FFTSize\n"
L" !i FFTSize\n"
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
L" !i \n"
L" !i \n"
L" !i 16384\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32768\n"
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

void PocBitmapAnimAudioRMS::Init(class ScriptContext *sc)
{
};

void PocBitmapAnimAudioRMS::Bind(class ScriptContext *sc,PocBitmapParaAudioRMS *para)
{
};

void PocBitmapAnimAudioSpectogram::Init(class ScriptContext *sc)
{
};

void PocBitmapAnimAudioSpectogram::Bind(class ScriptContext *sc,PocBitmapParaAudioSpectogram *para)
{
};


/****************************************************************************/

void AddTypes_wz4_audio_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_wz4_audio_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"AudioRMS";
  cl->Label = L"AudioRMS";
  cl->OutputType = PocBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = PocBitmapCmdAudioRMS;
  cl->MakeGui = PocBitmapGuiAudioRMS;
  cl->SetDefaults = PocBitmapDefAudioRMS;
  cl->BindPara = PocBitmapBindAudioRMS;
  cl->Bind2Para = PocBitmapBind2AudioRMS;
  cl->Bind3Para = PocBitmapBind3AudioRMS;
  cl->WikiText = PocBitmapWikiAudioRMS;
  cl->ParaWords = 3;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"AudioSpectogram";
  cl->Label = L"AudioSpectogram";
  cl->OutputType = PocBitmapType;
  cl->TabType = GenBitmapType;
  cl->Command = PocBitmapCmdAudioSpectogram;
  cl->MakeGui = PocBitmapGuiAudioSpectogram;
  cl->SetDefaults = PocBitmapDefAudioSpectogram;
  cl->BindPara = PocBitmapBindAudioSpectogram;
  cl->Bind2Para = PocBitmapBind2AudioSpectogram;
  cl->Bind3Para = PocBitmapBind3AudioSpectogram;
  cl->WikiText = PocBitmapWikiAudioSpectogram;
  cl->ParaWords = 2;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_audio_ops,0x110,AddOps_wz4_audio_ops,0);


/****************************************************************************/


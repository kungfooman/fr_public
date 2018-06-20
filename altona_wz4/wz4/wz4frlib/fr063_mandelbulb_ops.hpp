/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fr063_mandelbulb_ops
#define HEADER_WZ4OPS_fr063_mandelbulb_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class MandelbulbIsoDataType_ *MandelbulbIsoDataType;

/****************************************************************************/

#line 9 "fr063_mandelbulb_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 22 "fr063_mandelbulb_ops.hpp"
class MandelbulbIsoDataType_ : public AnyTypeType_
{
public:
  MandelbulbIsoDataType_() { Parent = AnyTypeType; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"MandelbulbIsoData"; Label = L"MandelbulbIsoData";  Init(); }
  ~MandelbulbIsoDataType_() { Exit(); }
#line 75 "fr063_mandelbulb_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 31 "fr063_mandelbulb_ops.hpp"
};

struct Wz4RenderParaFR063_Mandelbulb
{
  sF32 LodSplit;
  sF32 LodDraw;
  sF32 LodDrop;
  sF32 LodAll;
  sF32 IsoValue;
  sInt Iterations;
  sF32 Scale;
  sInt LightEnv;
  sInt Renderpass;
  sInt ShadowLevel;
  sInt Multithreading;
  sInt NodesPerFrame;
  sInt GeoBufferCount;
};

struct MandelbulbIsoDataParaFR063_MandelbulbIsoData
{
  sInt Iterations;
  sInt OctreeDivisions;
  sInt Multithreading;
};

struct Wz4RenderParaFR063_MandelbulbIso
{
  sF32 IsoValue;
  sInt Iterations_;
  sF32 Scale_;
  sInt OctreeDivisions_;
  sInt LightEnv;
  sInt Renderpass;
  sInt Flags;
  sInt Multithreading;
};


/****************************************************************************/

struct Wz4RenderAnimFR063_Mandelbulb
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_Mandelbulb *para);

};

struct MandelbulbIsoDataAnimFR063_MandelbulbIsoData
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,MandelbulbIsoDataParaFR063_MandelbulbIsoData *para);

};

struct Wz4RenderAnimFR063_MandelbulbIso
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_MandelbulbIso *para);

  struct ScriptSymbol *_IsoValue;
  struct ScriptSymbol *_Iterations_;
  struct ScriptSymbol *_Scale_;
};


/****************************************************************************/

void AddTypes_fr063_mandelbulb_ops(sBool secondary=0);
void AddOps_fr063_mandelbulb_ops(sBool secondary=0);

/****************************************************************************/

#endif

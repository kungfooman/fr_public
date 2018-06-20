/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_adf_ops
#define HEADER_WZ4OPS_adf_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4ADFType_ *Wz4ADFType;

/****************************************************************************/

#line 9 "adf_ops.ops"

#include "wz4lib/basic_ops.hpp"

#line 22 "adf_ops.hpp"
class Wz4ADFType_ : public AnyTypeType_
{
public:
  Wz4ADFType_() { Parent = AnyTypeType; Color= 0xff3080f0; Flags = 0x0000; GuiSets = 0x0002; Symbol = L"Wz4ADF"; Label = L"Wz4 ADF";  Init(); }
  ~Wz4ADFType_() { Exit(); }
#line 30 "adf_ops.ops"

    sImage *img;
  
#line 32 "adf_ops.hpp"
#line 34 "adf_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 60 "adf_ops.ops"
  void Init();
#line 66 "adf_ops.ops"
  void Exit();
#line 40 "adf_ops.hpp"
};

struct Wz4ADFParaImport
{
};

struct Wz4ADFParaFromMesh
{
  sInt Depth;
  sF32 GuardBand;
  sInt ForceCubeSampling;
  sInt UserBox;
  sVector31 BoxPos;
  sVector30 BoxDimH;
  sInt BruteForce;
  sInt PlaneThickness;
};


/****************************************************************************/

struct Wz4ADFAnimImport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ADFParaImport *para);

};

struct Wz4ADFAnimFromMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ADFParaFromMesh *para);

};


/****************************************************************************/

void AddTypes_adf_ops(sBool secondary=0);
void AddOps_adf_ops(sBool secondary=0);

/****************************************************************************/

#endif

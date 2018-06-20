/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_pdf_ops
#define HEADER_WZ4OPS_pdf_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4PDFType_ *Wz4PDFType;

/****************************************************************************/

#line 9 "pdf_ops.ops"

#include "wz4lib/basic_ops.hpp"

#line 22 "pdf_ops.hpp"
class Wz4PDFType_ : public AnyTypeType_
{
public:
  Wz4PDFType_() { Parent = AnyTypeType; Color= 0xff30f080; Flags = 0x0000; GuiSets = 0x0002; Symbol = L"Wz4PDF"; Label = L"Wz4 PDF";  Init(); }
  ~Wz4PDFType_() { Exit(); }
#line 30 "pdf_ops.ops"

    sImage *img;
  
#line 32 "pdf_ops.hpp"
#line 34 "pdf_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 59 "pdf_ops.ops"
  void Init();
#line 64 "pdf_ops.ops"
  void Exit();
#line 40 "pdf_ops.hpp"
};

struct Wz4PDFParaCube
{
};

struct Wz4PDFParaSphere
{
};

struct Wz4PDFParaFromADF
{
};

struct Wz4PDFParaAdd
{
};

struct Wz4PDFParaMultiply
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Count;
};

struct Wz4PDFParaTransform
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct Wz4PDFParaTwirl
{
  sVector30 Scale;
  sVector30 Bias;
};

struct Wz4PDFParaMerge
{
  sInt MergeType;
  sF32 Factor;
};


/****************************************************************************/

struct Wz4PDFAnimCube
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaCube *para);

};

struct Wz4PDFAnimSphere
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaSphere *para);

};

struct Wz4PDFAnimFromADF
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaFromADF *para);

};

struct Wz4PDFAnimAdd
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaAdd *para);

};

struct Wz4PDFAnimMultiply
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaMultiply *para);

};

struct Wz4PDFAnimTransform
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaTransform *para);

};

struct Wz4PDFAnimTwirl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaTwirl *para);

};

struct Wz4PDFAnimMerge
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4PDFParaMerge *para);

};


/****************************************************************************/

void AddTypes_pdf_ops(sBool secondary=0);
void AddOps_pdf_ops(sBool secondary=0);

/****************************************************************************/

#endif

/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_mtrl_ops
#define HEADER_WZ4OPS_wz4_mtrl_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4MaterialType_ *Wz4MaterialType;

/****************************************************************************/

#line 9 "wz4_mtrl_ops.ops"

#include "wz4lib/poc_ops.hpp"
#include "util/image.hpp"
#include "base/graphics.hpp"
#include "util/shaders.hpp"
#include "wz4frlib/wz4_mtrl.hpp"

#line 26 "wz4_mtrl_ops.hpp"
class Wz4MaterialType_ : public AnyTypeType_
{
public:
  Wz4MaterialType_() { Parent = AnyTypeType; Color= 0xff60a060; Flags = 0x0003; GuiSets = 0x0000; Symbol = L"Wz4Material"; Label = L"Obsolete Wz4 Material";  Init(); }
  ~Wz4MaterialType_() { Exit(); }
#line 35 "wz4_mtrl_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 35 "wz4_mtrl_ops.hpp"
};

struct Wz4MaterialParaMaterial
{
  sInt Flags;
  sInt Blend;
  sInt TFlags0;
  sF32 Scale0;
  sInt TFlags1;
  sF32 Scale1;
  sInt TFlags2;
  sInt DetailMode;
  sF32 Scale2;
  sInt TFlags3;
  sInt TFlags4;
  sInt TFlags5;
  sF32 Mat0Scale[2];
  sF32 Mat0Rot;
  sF32 Mat0Trans[2];
  sVector31 Mat1Scale;
  sVector31 Mat1Rot;
  sVector31 Mat1Trans;
  sInt VertexMode;
};


/****************************************************************************/

struct Wz4MaterialAnimMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MaterialParaMaterial *para);

};


/****************************************************************************/

void AddTypes_wz4_mtrl_ops(sBool secondary=0);
void AddOps_wz4_mtrl_ops(sBool secondary=0);

/****************************************************************************/

#endif

/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_bsp_ops
#define HEADER_WZ4OPS_wz4_bsp_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4BSPType_ *Wz4BSPType;

/****************************************************************************/

#line 9 "wz4_bsp_ops.ops"

#include "wz4lib/poc_ops.hpp"
#include "wz4frlib/wz4_bsp.hpp"
#include "wz4frlib/wz4_mesh.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"

#line 25 "wz4_bsp_ops.hpp"
class Wz4BSPType_ : public AnyTypeType_
{
public:
  Wz4BSPType_() { Parent = AnyTypeType; Color= 0xff7070f0; Flags = 0x0000; GuiSets = 0x0002; Symbol = L"Wz4BSP"; Label = L"Wz4 BSP";  Init(); }
  ~Wz4BSPType_() { Exit(); }
#line 26 "wz4_bsp_ops.ops"

    sImage *img;
  
#line 35 "wz4_bsp_ops.hpp"
#line 30 "wz4_bsp_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 87 "wz4_bsp_ops.ops"
  void Init();
#line 92 "wz4_bsp_ops.ops"
  void Exit();
#line 43 "wz4_bsp_ops.hpp"
};

struct Wz4BSPParaPolyhedron
{
  sInt Faces;
  sInt nIter;
  sF32 Power;
  sInt Flags;
  sInt RandomSeed;
};

struct Wz4BSPParaFromMesh
{
  sInt PlaneThickness;
};

struct Wz4BSPParaSliceAndDice
{
  sF32 MinSize;
  sF32 MaxSize;
  sF32 RandomPlanesAtMin;
  sInt RandomSeed;
  sInt MaxSplits;
};

struct Wz4MeshParaBSPToMesh
{
  sF32 Explode;
};


/****************************************************************************/

struct Wz4BSPAnimPolyhedron
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4BSPParaPolyhedron *para);

};

struct Wz4BSPAnimFromMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4BSPParaFromMesh *para);

};

struct Wz4BSPAnimSliceAndDice
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4BSPParaSliceAndDice *para);

};

struct Wz4MeshAnimBSPToMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaBSPToMesh *para);

};


/****************************************************************************/

void AddTypes_wz4_bsp_ops(sBool secondary=0);
void AddOps_wz4_bsp_ops(sBool secondary=0);

/****************************************************************************/

#endif

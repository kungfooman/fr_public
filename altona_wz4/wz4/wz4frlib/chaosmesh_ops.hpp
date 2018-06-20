/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_chaosmesh_ops
#define HEADER_WZ4OPS_chaosmesh_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class ChaosMeshType_ *ChaosMeshType;

/****************************************************************************/

#line 9 "chaosmesh_ops.ops"

#include "wz4lib/poc_ops.hpp"
#include "wz4frlib/wz4_anim_ops.hpp"
#include "chaosmesh_code.hpp"
#include "chaosmesh_xsi.hpp"
#include "chaosmesh_fx.hpp"
#include "wz4_mtrl_ops.hpp"

#line 27 "chaosmesh_ops.hpp"
class ChaosMeshType_ : public MeshBaseType_
{
public:
  ChaosMeshType_() { Parent = MeshBaseType; Color= 0xff60a0a0; Flags = 0x0006; GuiSets = 0x0002; Symbol = L"ChaosMesh"; Label = L"Chaos Mesh";  Init(); }
  ~ChaosMeshType_() { Exit(); }
#line 34 "chaosmesh_ops.ops"

    sGeometry *WireGeo;
    sGeometry *FlatGeo;
    sGeometry *QuadGeo;
  
#line 39 "chaosmesh_ops.hpp"
#line 40 "chaosmesh_ops.ops"
  void Init();
#line 50 "chaosmesh_ops.ops"
  void Exit();
#line 57 "chaosmesh_ops.ops"
  void BeginEngine(wPaintInfo &pi,sBool clear);
#line 65 "chaosmesh_ops.ops"
  void Paint(wObject *obj,wPaintInfo &pi,sMatrix34 *mat,sInt matcount);
#line 83 "chaosmesh_ops.ops"
  void Hit(wObject *obj,const sRay &ray,wHitInfo &info);
#line 90 "chaosmesh_ops.ops"
  void Wireframe(wObject *obj,wPaintInfo &pi,sMatrix34 &mat);
#line 109 "chaosmesh_ops.ops"
  void ListExtractions(wObject *obj,void (* cb)(const sChar *name,wType *type),const sChar *storename);
#line 55 "chaosmesh_ops.hpp"
};

struct ChaosMeshParaExtract_ChaosMesh_ChaosMesh
{
};

struct Texture2DParaExtract_ChaosMesh_Texture2D
{
};

struct TextureCubeParaExtract_ChaosMesh_TextureCube
{
};

struct Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton
{
};

struct ChaosMeshParaExport
{
};

struct ChaosMeshParaExportXSI
{
};

struct ChaosMeshParaImport
{
  sInt Flags;
};

struct ChaosMeshParatorus
{
  sF32 Inner;
  sF32 Outer;
  sF32 Phase;
  sInt Sections;
  sInt Slices;
  sInt Flags;
  sF32 Arc;
};

struct ChaosMeshParagrid
{
  sInt Mode;
  sInt Tesselation[2];
};

struct ChaosMeshParacube
{
  sInt Tess[3];
  sInt Flags;
  sVector31 Scale;
  sVector30 Rotate;
  sVector31 Trans;
};

struct ChaosMeshParaSphere
{
  sInt Facets;
  sInt Slices;
  sF32 Diameter;
};

struct ChaosMeshParaSelectCube
{
  sInt Flags;
  sVector31 Scale;
  sVector30 Rotate;
  sVector31 Trans;
  sF32 Random;
  sInt RandomSeed;
};

struct ChaosMeshParaDeleteFaces
{
  sInt Flags;
};

struct ChaosMeshParatransform
{
  sVector31 Scale;
  sVector30 Rotate;
  sVector31 Trans;
  sInt Selection;
};

struct ChaosMeshPararandomize
{
  sVector30 Amount;
  sInt Seed;
  sInt Flags;
};

struct ChaosMeshParaadd
{
};

struct ChaosMeshParaSetMtrl
{
};

struct ChaosMeshParaChangeTexture
{
  sInt Exchange;
  sInt DetailMode;
  sInt BlendMode;
};

struct ChaosMeshParaChangeMaterial
{
};

struct ChaosMeshParaBurnAnim
{
  sF32 Phase;
};

struct ChaosMeshParaDeleteSkeleton
{
};

struct ChaosMeshParaBakeMorph
{
  sF32 Phase;
  sF32 Anim;
};

struct ChaosMeshParaMergeShape
{
  sF32 Phase;
};

struct ChaosMeshParaMergeAnim
{
  sInt UseAnimMask;
};

struct ChaosMeshParaFakeBone
{
  sVector31 Scale;
  sVector30 Rotate;
  sVector31 Trans;
  sInt BoneIndex;
  sInt What;
};

struct ChaosMeshParaCompressAnim
{
  sF32 LogRelativeAccuracy;
  sInt Flags;
};

struct ChaosMeshParaSliceAndDice
{
};


/****************************************************************************/

struct ChaosMeshAnimExtract_ChaosMesh_ChaosMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaExtract_ChaosMesh_ChaosMesh *para);

};

struct Texture2DAnimExtract_ChaosMesh_Texture2D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Texture2DParaExtract_ChaosMesh_Texture2D *para);

};

struct TextureCubeAnimExtract_ChaosMesh_TextureCube
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,TextureCubeParaExtract_ChaosMesh_TextureCube *para);

};

struct Wz4SkeletonAnimExtract_ChaosMesh_Wz4Skeleton
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4SkeletonParaExtract_ChaosMesh_Wz4Skeleton *para);

};

struct ChaosMeshAnimExport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaExport *para);

};

struct ChaosMeshAnimExportXSI
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaExportXSI *para);

};

struct ChaosMeshAnimImport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaImport *para);

};

struct ChaosMeshAnimtorus
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParatorus *para);

};

struct ChaosMeshAnimgrid
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParagrid *para);

};

struct ChaosMeshAnimcube
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParacube *para);

};

struct ChaosMeshAnimSphere
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaSphere *para);

};

struct ChaosMeshAnimSelectCube
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaSelectCube *para);

};

struct ChaosMeshAnimDeleteFaces
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaDeleteFaces *para);

};

struct ChaosMeshAnimtransform
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParatransform *para);

};

struct ChaosMeshAnimrandomize
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshPararandomize *para);

};

struct ChaosMeshAnimadd
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaadd *para);

};

struct ChaosMeshAnimSetMtrl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaSetMtrl *para);

};

struct ChaosMeshAnimChangeTexture
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaChangeTexture *para);

};

struct ChaosMeshAnimChangeMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaChangeMaterial *para);

};

struct ChaosMeshAnimBurnAnim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaBurnAnim *para);

};

struct ChaosMeshAnimDeleteSkeleton
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaDeleteSkeleton *para);

};

struct ChaosMeshAnimBakeMorph
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaBakeMorph *para);

};

struct ChaosMeshAnimMergeShape
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaMergeShape *para);

};

struct ChaosMeshAnimMergeAnim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaMergeAnim *para);

};

struct ChaosMeshAnimFakeBone
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaFakeBone *para);

};

struct ChaosMeshAnimCompressAnim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaCompressAnim *para);

};

struct ChaosMeshAnimSliceAndDice
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosMeshParaSliceAndDice *para);

};


/****************************************************************************/

void AddTypes_chaosmesh_ops(sBool secondary=0);
void AddOps_chaosmesh_ops(sBool secondary=0);

/****************************************************************************/

#endif

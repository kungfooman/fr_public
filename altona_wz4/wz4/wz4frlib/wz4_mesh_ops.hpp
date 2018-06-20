/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_mesh_ops
#define HEADER_WZ4OPS_wz4_mesh_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4MeshType_ *Wz4MeshType;

/****************************************************************************/

#line 9 "wz4_mesh_ops.ops"

#include "wz4lib/poc_ops.hpp"
#include "wz4frlib/chaosmesh_ops.hpp"
#include "wz4frlib/wz4_anim_ops.hpp"
#include "wz4frlib/wz4_mtrl2_ops.hpp"
#include "wz4frlib/wz4_mtrl2.hpp"
#include "wz4frlib/wz4_mesh.hpp"
#include "wz4frlib/wz3_bitmap_ops.hpp"
#include "wz4frlib/wz3_bitmap_code.hpp"

#line 29 "wz4_mesh_ops.hpp"
class Wz4MeshType_ : public MeshBaseType_
{
public:
  Wz4MeshType_() { Parent = MeshBaseType; Color= 0xff608080; Flags = 0x0006; GuiSets = 0x0002; Symbol = L"Wz4Mesh"; Label = L"wz4 Mesh";  Init(); }
  ~Wz4MeshType_() { Exit(); }
#line 34 "wz4_mesh_ops.ops"

    SimpleMtrl *DefaultMtrl;
  
#line 39 "wz4_mesh_ops.hpp"
#line 38 "wz4_mesh_ops.ops"
  void Init();
#line 45 "wz4_mesh_ops.ops"
  void Exit();
#line 50 "wz4_mesh_ops.ops"
  void BeginEngine(wPaintInfo &pi,sBool clear);
#line 58 "wz4_mesh_ops.ops"
  void Paint(wObject *obj,wPaintInfo &pi,sMatrix34 *mat,sInt matcount);
#line 72 "wz4_mesh_ops.ops"
  void Hit(wObject *obj,const sRay &ray,wHitInfo &info);
#line 77 "wz4_mesh_ops.ops"
  void Wireframe(wObject *obj,wPaintInfo &pi,sMatrix34 &mat);
#line 53 "wz4_mesh_ops.hpp"
};

struct Wz4MeshParaConvertFromChaosMesh
{
};

struct Wz4MeshParaExport
{
  sInt Flags;
  sInt FormatType;
};

struct Wz4MeshParaImport
{
  sInt Flags;
};

struct Wz4MeshParaTorus
{
  sInt Slices;
  sInt Segments;
  sF32 InnerRadius;
  sF32 OuterRadius;
  sF32 Phase;
  sF32 Arc;
};

struct Wz4MeshParaGrid
{
  sInt Tesselate[2];
  sInt Sides;
  sF32 Size;
};

struct Wz4MeshParaDisc
{
  sInt Slices;
  sF32 Radius;
  sF32 Phase;
  sInt Flags;
};

struct Wz4MeshParaSphere
{
  sInt Slices;
  sInt Segments;
  sVector30 Diameter;
};

struct Wz4MeshParaCube
{
  sInt Tesselate[3];
  sVector30 Scale;
};

struct Wz4MeshParaCylinder
{
  sInt Slices;
  sInt Segments;
  sInt Top;
  sF32 Radius;
  sF32 Height;
  sInt Flags;
};

struct Wz4MeshParaText3D
{
  sF32 Height;
  sF32 Extrude;
  sF32 MaxError;
  sInt Flags;
};

struct Wz4MeshParaPath3D
{
  sF32 Extrude;
  sF32 MaxError;
  sF32 WeldThreshold;
  sInt Flags;
};

struct Wz4MeshParaNormalize
{
  sInt Flags;
};

struct Wz4MeshParaRandomize
{
  sInt Seed;
  sF32 Amount;
  sInt Selection;
  sInt Mode;
};

struct Wz4MeshParaNoise
{
  sInt Seed;
  sF32 Freq[3];
  sF32 Amplify[3];
  sInt Selection;
  sInt Octaves;
  sF32 Falloff;
};

struct Wz4MeshParaInvert
{
  sInt Selection;
};

struct Wz4MeshParaTriangulate
{
  sInt Selection;
};

struct Wz4MeshParaDeleteFace
{
  sInt Selection;
  sInt DeleteUnusedVertices;
};

struct Wz4MeshParaSetMaterial
{
  sInt Selection;
  sInt Cluster;
};

struct Wz4MeshParaTransform
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Selection;
};

struct Wz4MeshParaTransformRange
{
  sInt Selection;
  sInt Mode;
  sVector2 Direction;
  sVector2 AxialRange;
  sInt RangeMode;
  sVector31 ScaleStart;
  sVector30 RotateStart;
  sVector31 TranslateStart;
  sVector31 ScaleEnd;
  sVector30 RotateEnd;
  sVector31 TranslateEnd;
};

struct Wz4MeshParaMirror
{
  sInt MirrorX;
  sInt MirrorY;
  sInt MirrorZ;
  sInt Selection;
  sInt Mode;
};

struct Wz4MeshParaCenter
{
};

struct Wz4MeshParaSelectGrow
{
  sInt Amount;
  sInt Input;
  sF32 Range;
  sInt Power;
  sF32 Bias;
};

struct Wz4MeshParaMultiply
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Count;
  sInt Flags;
};

struct Wz4MeshParaMultiplyNew
{
  sInt Renderpass;
  sInt Flags;
  sVector31 PreScale;
  sVector30 PreRot;
  sVector31 PreTrans;
  sInt Count;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct Wz4MeshParaTransformEx
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Flags;
  sInt Selection;
};

struct Wz4MeshParaTransformMatrix
{
  sF32 x[4];
  sF32 y[4];
  sF32 z[4];
  sInt Flags;
  sInt Selection;
};

struct Wz4MeshParaTransformNonLinear
{
  sInt Flags;
  sInt Selection;
  sVector4 x1;
  sVector4 y1;
  sVector4 z1;
  sVector4 x2;
  sVector4 y2;
  sVector4 z2;
  sVector4 xr;
  sVector4 yr;
  sVector4 zr;
};

struct Wz4MeshParaExtrudeNormal
{
  sF32 Amount;
  sInt Selection;
};

struct Wz4MeshParaBend
{
  sVector31 Start;
  sVector30 Up;
  sVector30 Axis;
  sF32 Angle;
  sF32 Radius;
  sInt Flags;
  sInt Selection;
};

struct Wz4MeshParaSubdivide
{
  sInt Selection;
  sInt Levels;
  sF32 Smooth;
};

struct Wz4MeshParaExtrude
{
  sInt Steps;
  sF32 Amount;
  sInt Flags;
  sVector31 Center;
  sF32 LocalScale;
  sInt SelectUpdateFlag;
  sVector2 UVOffset;
};

struct Wz4MeshParaAdd
{
};

struct Wz4MeshParaSelect
{
  sInt Flags;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sF32 Random;
  sInt RandomSeed;
  sU32 RefColor;
  sInt RefColorErr;
  sInt RefColorSpread;
  sInt TextureUV;
  sInt Cluster;
  sInt InputSlot;
  sInt OutputSlot;
};

struct Wz4MeshParaSplitAlongPlane
{
  sVector4 Plane;
  sInt Count;
  sF32 Distance;
};

struct Wz4MeshParaBakeAnim
{
  sF32 Time;
};

struct Wz4MeshParaFacette
{
  sF32 Smoothness;
};

struct Wz4MeshParaCrease
{
};

struct Wz4MeshParaUnCrease
{
  sInt Selection;
};

struct Wz4MeshParaDisplace
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sF32 Amount;
  sF32 Bias;
  sInt Flags;
  sInt Selection;
};

struct Wz4MeshParaSplitter
{
  sF32 Depth;
  sF32 Scale;
};

struct Wz4MeshParaDual
{
  sF32 Random;
};

struct Wz4MeshParaHeal
{
  sInt Flags;
  sF32 PosThreshold;
  sF32 NormThreshold;
};

struct Wz4MeshParaDeform
{
  sInt Count;
  sVector31 Start;
  sVector31 End;
  sInt Flags;
  sInt Selection;
  sInt UpVectorUse;
  sVector30 UpVector;
};

struct Wz4MeshArrayDeform
{
  sVector31 Pos;
  sF32 Twist;
  sF32 Scale;
};

struct Wz4MeshParaChunks
{
  sVector30 Normal;
  sInt Flags;
  sVector30 Rotation;
};

struct Wz4MeshParaRandomizeChunks
{
  sVector30 Random;
  sInt Flags;
  sInt Seed;
};

struct Wz4MeshParaBevel
{
  sF32 Amount;
};


/****************************************************************************/

struct Wz4MeshAnimConvertFromChaosMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaConvertFromChaosMesh *para);

};

struct Wz4MeshAnimExport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaExport *para);

};

struct Wz4MeshAnimImport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaImport *para);

};

struct Wz4MeshAnimTorus
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTorus *para);

};

struct Wz4MeshAnimGrid
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaGrid *para);

};

struct Wz4MeshAnimDisc
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaDisc *para);

};

struct Wz4MeshAnimSphere
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSphere *para);

};

struct Wz4MeshAnimCube
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaCube *para);

};

struct Wz4MeshAnimCylinder
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaCylinder *para);

};

struct Wz4MeshAnimText3D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaText3D *para);

};

struct Wz4MeshAnimPath3D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaPath3D *para);

};

struct Wz4MeshAnimNormalize
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaNormalize *para);

};

struct Wz4MeshAnimRandomize
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaRandomize *para);

};

struct Wz4MeshAnimNoise
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaNoise *para);

};

struct Wz4MeshAnimInvert
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaInvert *para);

};

struct Wz4MeshAnimTriangulate
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTriangulate *para);

};

struct Wz4MeshAnimDeleteFace
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaDeleteFace *para);

};

struct Wz4MeshAnimSetMaterial
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSetMaterial *para);

};

struct Wz4MeshAnimTransform
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTransform *para);

};

struct Wz4MeshAnimTransformRange
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTransformRange *para);

};

struct Wz4MeshAnimMirror
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaMirror *para);

};

struct Wz4MeshAnimCenter
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaCenter *para);

};

struct Wz4MeshAnimSelectGrow
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSelectGrow *para);

};

struct Wz4MeshAnimMultiply
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaMultiply *para);

};

struct Wz4MeshAnimMultiplyNew
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaMultiplyNew *para);

  struct ScriptSymbol *_PreScale;
  struct ScriptSymbol *_PreRot;
  struct ScriptSymbol *_PreTrans;
  struct ScriptSymbol *_Count;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
};

struct Wz4MeshAnimTransformEx
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTransformEx *para);

};

struct Wz4MeshAnimTransformMatrix
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTransformMatrix *para);

};

struct Wz4MeshAnimTransformNonLinear
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaTransformNonLinear *para);

};

struct Wz4MeshAnimExtrudeNormal
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaExtrudeNormal *para);

};

struct Wz4MeshAnimBend
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaBend *para);

};

struct Wz4MeshAnimSubdivide
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSubdivide *para);

};

struct Wz4MeshAnimExtrude
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaExtrude *para);

};

struct Wz4MeshAnimAdd
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaAdd *para);

};

struct Wz4MeshAnimSelect
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSelect *para);

};

struct Wz4MeshAnimSplitAlongPlane
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSplitAlongPlane *para);

};

struct Wz4MeshAnimBakeAnim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaBakeAnim *para);

};

struct Wz4MeshAnimFacette
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaFacette *para);

};

struct Wz4MeshAnimCrease
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaCrease *para);

};

struct Wz4MeshAnimUnCrease
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaUnCrease *para);

};

struct Wz4MeshAnimDisplace
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaDisplace *para);

};

struct Wz4MeshAnimSplitter
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaSplitter *para);

};

struct Wz4MeshAnimDual
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaDual *para);

};

struct Wz4MeshAnimHeal
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaHeal *para);

};

struct Wz4MeshAnimDeform
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaDeform *para);

};

struct Wz4MeshAnimChunks
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaChunks *para);

};

struct Wz4MeshAnimRandomizeChunks
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaRandomizeChunks *para);

};

struct Wz4MeshAnimBevel
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4MeshParaBevel *para);

};


/****************************************************************************/

void AddTypes_wz4_mesh_ops(sBool secondary=0);
void AddOps_wz4_mesh_ops(sBool secondary=0);

/****************************************************************************/

#endif

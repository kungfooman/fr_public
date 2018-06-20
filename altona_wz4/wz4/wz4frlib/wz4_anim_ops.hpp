/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_anim_ops
#define HEADER_WZ4OPS_wz4_anim_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4ChannelType_ *Wz4ChannelType;
extern class Wz4SkeletonType_ *Wz4SkeletonType;

/****************************************************************************/

#line 9 "wz4_anim_ops.ops"

#include "wz4lib/basic_ops.hpp"
#include "wz4_anim.hpp"

#line 24 "wz4_anim_ops.hpp"
class Wz4ChannelType_ : public AnyTypeType_
{
public:
  Wz4ChannelType_() { Parent = AnyTypeType; Flags = 0x0001; GuiSets = 0x0000; Symbol = L"Wz4Channel"; Label = L"Channel";  Init(); }
  ~Wz4ChannelType_() { Exit(); }
#line 31 "wz4_anim_ops.hpp"
};

class Wz4SkeletonType_ : public MeshBaseType_
{
public:
  Wz4SkeletonType_() { Parent = MeshBaseType; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"Wz4Skeleton"; Label = L"Skeleton";  Init(); }
  ~Wz4SkeletonType_() { Exit(); }
#line 26 "wz4_anim_ops.ops"
  void BeginEngine(wPaintInfo &pi,sBool clear);
#line 34 "wz4_anim_ops.ops"
  void Wireframe(wObject *obj,wPaintInfo &pi,sMatrix34 &mat_);
#line 43 "wz4_anim_ops.hpp"
};

struct Wz4SkeletonParaBoneChain
{
  sVector31 Start;
  sVector31 End;
  sInt Count;
};


/****************************************************************************/

struct Wz4SkeletonAnimBoneChain
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4SkeletonParaBoneChain *para);

};


/****************************************************************************/

void AddTypes_wz4_anim_ops(sBool secondary=0);
void AddOps_wz4_anim_ops(sBool secondary=0);

/****************************************************************************/

#endif

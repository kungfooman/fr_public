/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fr063_sph_ops
#define HEADER_WZ4OPS_fr063_sph_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class SphGeneratorType_ *SphGeneratorType;
extern class SphCollisionType_ *SphCollisionType;

/****************************************************************************/

#line 15 "fr063_sph_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 23 "fr063_sph_ops.hpp"
class SphGeneratorType_ : public AnyTypeType_
{
public:
  SphGeneratorType_() { Parent = AnyTypeType; Flags = 0x0002; GuiSets = 0x0002; Symbol = L"SphGenerator"; Label = L"Smooth Particle Hydrodynamics";  Init(); }
  ~SphGeneratorType_() { Exit(); }
#line 37 "fr063_sph_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 32 "fr063_sph_ops.hpp"
};

class SphCollisionType_ : public AnyTypeType_
{
public:
  SphCollisionType_() { Parent = AnyTypeType; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"SphCollision"; Label = L"SphCollision";  Init(); }
  ~SphCollisionType_() { Exit(); }
#line 47 "fr063_sph_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 42 "fr063_sph_ops.hpp"
};

struct Wz4ParticlesParaSphSimulator
{
  sInt TimeStep_Old;
  sF32 Gravity;
  sF32 CentralGravity;
  sF32 OuterForce;
  sF32 InnerForce;
  sF32 InteractRadius;
  sF32 Friction;
  sF32 BasePressure;
  sF32 Viscosity;
  sInt MaxPart;
  sInt StartSteps;
  sInt Flags;
  sInt TicksPerFrame;
  sF32 TimeStep;
  sInt MaxSteps;
  sF32 ColorSmooth;
  sF32 SpringForce;
  sF32 SpringBreakForce;
  sInt PhysicsCycles;
  sF32 SpringBreakForceDot;
  sInt Multithreading;
};

struct SphGeneratorParaSphObject
{
  sInt Shape;
  sVector31 Center;
  sVector30 Radius;
  sF32 Raster;
  sF32 Randomness;
  sU32 Color;
  sVector30 StartSpeed;
  sInt Time0;
};

struct SphGeneratorParaSphSource
{
  sInt Shape;
  sVector31 Center;
  sVector30 Speed;
  sF32 Radius;
  sF32 Density;
  sF32 Randomness;
  sU32 Color;
  sInt StartTime;
  sInt EndTime;
};

struct SphCollisionParaSphSimpleColl
{
  sInt Flags;
  sInt Shape;
  sVector31 Center;
  sVector30 Radius;
  sInt StartTime;
  sInt EndTime;
};

struct SphCollisionParaSphPlaneColl
{
  sInt Flags;
  sF32 y;
  sInt StartTime;
  sInt EndTime;
};

struct SphCollisionParaSphShock
{
  sInt Time;
  sVector30 Speed;
  sVector31 Center;
  sF32 Radius;
  sF32 Force;
  sInt Flags;
};


/****************************************************************************/

struct Wz4ParticlesAnimSphSimulator
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4ParticlesParaSphSimulator *para);

};

struct SphGeneratorAnimSphObject
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphGeneratorParaSphObject *para);

};

struct SphGeneratorAnimSphSource
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphGeneratorParaSphSource *para);

};

struct SphCollisionAnimSphSimpleColl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphCollisionParaSphSimpleColl *para);

};

struct SphCollisionAnimSphPlaneColl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphCollisionParaSphPlaneColl *para);

};

struct SphCollisionAnimSphShock
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,SphCollisionParaSphShock *para);

};


/****************************************************************************/

void AddTypes_fr063_sph_ops(sBool secondary=0);
void AddOps_fr063_sph_ops(sBool secondary=0);

/****************************************************************************/

#endif

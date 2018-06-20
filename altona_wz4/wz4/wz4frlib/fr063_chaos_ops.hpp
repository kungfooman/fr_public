/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fr063_chaos_ops
#define HEADER_WZ4OPS_fr063_chaos_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "fr063_chaos_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 21 "fr063_chaos_ops.hpp"
struct Wz4RenderParaFR063_Water
{
  sInt BowlCount;
  sF32 BowlSize;
  sInt DropCount;
  sF32 DropSize;
  sF32 Gravity;
  sF32 OuterForce;
  sF32 InnerForce;
  sF32 InteractRadius;
  sF32 Friction;
  sInt LightEnv;
  sInt Renderpass;
};

struct Wz4RenderParaFR063_MultiProgress
{
  sInt Cores;
  sF32 Animate;
  sInt Renderpass;
};


/****************************************************************************/

struct Wz4RenderAnimFR063_Water
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_Water *para);

};

struct Wz4RenderAnimFR063_MultiProgress
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFR063_MultiProgress *para);

  struct ScriptSymbol *_Animate;
};


/****************************************************************************/

void AddTypes_fr063_chaos_ops(sBool secondary=0);
void AddOps_fr063_chaos_ops(sBool secondary=0);

/****************************************************************************/

#endif

/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_screens4_ops
#define HEADER_WZ4OPS_screens4_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "screens4_ops.ops"

#include "wz4lib/poc_ops.hpp"

#line 21 "screens4_ops.hpp"
struct Wz4RenderParaSiegmeister
{
  sInt Renderpass;
  sInt LightEnv;
  sF32 BlinkSpeed;
  sInt AspNum;
  sInt AspDen;
};

struct Wz4RenderParaCustom2DFS
{
  sInt Renderpass;
  sU32 Color;
  sInt Flags;
};


/****************************************************************************/

struct Wz4RenderAnimSiegmeister
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSiegmeister *para);

  struct ScriptSymbol *_BlinkSpeed;
};

struct Wz4RenderAnimCustom2DFS
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCustom2DFS *para);

  struct ScriptSymbol *_Color;
};


/****************************************************************************/

void AddTypes_screens4_ops(sBool secondary=0);
void AddOps_screens4_ops(sBool secondary=0);

/****************************************************************************/

#endif

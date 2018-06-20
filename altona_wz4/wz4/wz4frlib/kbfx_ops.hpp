/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_kbfx_ops
#define HEADER_WZ4OPS_kbfx_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "kbfx_ops.ops"

#include "wz4frlib/wz4_demo2.hpp"
#include "wz4frlib/wz4_demo2_ops.hpp"

#line 22 "kbfx_ops.hpp"
struct Wz4RenderParaVideoDistort
{
  sInt Renderpass;
  sF32 KeyFrameInterval;
  sF32 Chance;
};

struct Wz4RenderParaBlockTransition
{
  sInt Renderpass;
  sInt BlockSize;
  sInt StreakSize;
  sInt StreakDeviate;
  sInt SrcDeviate;
  sInt Seed;
  sF32 Chance;
};

struct Wz4RenderParaGlitch2D
{
  sInt Renderpass;
  sInt Seed;
  sInt LineSize;
  sF32 Chance;
  sF32 ShiftX;
  sF32 ShiftY;
  sF32 ShiftRGB;
};


/****************************************************************************/

struct Wz4RenderAnimVideoDistort
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaVideoDistort *para);

};

struct Wz4RenderAnimBlockTransition
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBlockTransition *para);

  struct ScriptSymbol *_BlockSize;
  struct ScriptSymbol *_StreakSize;
  struct ScriptSymbol *_StreakDeviate;
  struct ScriptSymbol *_SrcDeviate;
  struct ScriptSymbol *_Seed;
  struct ScriptSymbol *_Chance;
};

struct Wz4RenderAnimGlitch2D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaGlitch2D *para);

  struct ScriptSymbol *_Seed;
  struct ScriptSymbol *_LineSize;
  struct ScriptSymbol *_Chance;
  struct ScriptSymbol *_ShiftX;
  struct ScriptSymbol *_ShiftY;
  struct ScriptSymbol *_ShiftRGB;
};


/****************************************************************************/

void AddTypes_kbfx_ops(sBool secondary=0);
void AddOps_kbfx_ops(sBool secondary=0);

/****************************************************************************/

#endif

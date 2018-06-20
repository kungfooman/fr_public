/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_fr062_ops
#define HEADER_WZ4OPS_fr062_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "fr062_ops.ops"

#include "wz4frlib/wz4_modmtrl.hpp"
#include "wz4frlib/wz4_modmtrl_ops.hpp"
#include "wz4frlib/fr062_ops.hpp"

#line 23 "fr062_ops.hpp"
struct ModShaderParaSphereSlicer
{
  sVector4 Sphere0;
  sVector4 Sphere1;
  sVector4 Sphere2;
  sVector4 Sphere3;
  sF32 Amp;
  sInt Flags;
  sF32 ClipMin;
  sF32 ClipMax;
  sF32 ColMin;
  sF32 ColMax;
  sU32 Color;
  sF32 Bias;
  sF32 TexAmp;
};

struct Wz4RenderParaModSlice
{
  sInt Index;
  sInt Renderpass;
  sVector30 Pos0;
  sF32 Size0;
  sVector30 Pos1;
  sF32 Size1;
  sVector30 Pos2;
  sF32 Size2;
  sVector30 Pos3;
  sF32 Size3;
  sF32 Amp;
  sF32 ClipPhase;
  sF32 ClipSize;
  sF32 ColPhase;
  sF32 ColSize;
  sU32 Color;
  sF32 Bias;
  sF32 TexAmp;
};


/****************************************************************************/

struct ModShaderAnimSphereSlicer
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaSphereSlicer *para);

};

struct Wz4RenderAnimModSlice
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaModSlice *para);

  struct ScriptSymbol *_Pos0;
  struct ScriptSymbol *_Size0;
  struct ScriptSymbol *_Pos1;
  struct ScriptSymbol *_Size1;
  struct ScriptSymbol *_Pos2;
  struct ScriptSymbol *_Size2;
  struct ScriptSymbol *_Pos3;
  struct ScriptSymbol *_Size3;
  struct ScriptSymbol *_Amp;
  struct ScriptSymbol *_ClipPhase;
  struct ScriptSymbol *_ClipSize;
  struct ScriptSymbol *_ColPhase;
  struct ScriptSymbol *_ColSize;
  struct ScriptSymbol *_Color;
  struct ScriptSymbol *_Bias;
  struct ScriptSymbol *_TexAmp;
};


/****************************************************************************/

void AddTypes_fr062_ops(sBool secondary=0);
void AddOps_fr062_ops(sBool secondary=0);

/****************************************************************************/

#line 162 "fr062_ops.ops"

  class RNModSlice : public Wz4RenderNode
  {
  public:
    Wz4RenderParaModSlice Para,ParaBase;
    Wz4RenderAnimModSlice Anim;

    RNModSlice();
    ~RNModSlice();

    void Simulate(Wz4RenderContext *);
    void Render(Wz4RenderContext *);
  };

#line 119 "fr062_ops.hpp"

/****************************************************************************/

#endif

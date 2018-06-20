/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_modmtrlmod_ops
#define HEADER_WZ4OPS_wz4_modmtrlmod_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/


/****************************************************************************/

#line 9 "wz4_modmtrlmod_ops.ops"

#include "wz4frlib/wz4_modmtrl.hpp"
#include "wz4frlib/wz4_modmtrl_ops.hpp"

#line 22 "wz4_modmtrlmod_ops.hpp"
struct ModShaderParaFlat
{
  sU32 Color;
};

struct ModShaderParaLambert
{
  sInt Light;
};

struct ModShaderParaPhong
{
  sF32 Specular;
  sInt Light;
  sInt SpecularityMap;
  sInt UseTexture;
  sInt TransparencyMap;
  sF32 Transparency;
};

struct ModShaderParaRim
{
  sInt Flags;
  sF32 Width;
  sU32 Color;
  sInt Shadow;
};

struct ModShaderParaComic
{
  sInt Mode;
};

struct ModShaderParaBlinnPhong
{
  sF32 Specular;
  sInt Light;
  sInt SpecularityMap;
};

struct ModShaderSamplerParaTex2D
{
  sInt Flags;
  sInt UV;
  sInt Transform;
  sInt Aux;
  sF32 SimpleScale;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct ModShaderSamplerParaTex2DAnim
{
  sInt Flags;
  sInt UV;
  sInt Transform;
  sInt Aux;
  sInt AtlasAnim;
  sF32 SimpleScale;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct ModShaderSamplerParaTex2DSurround
{
  sInt Aux;
  sInt Transform;
  sF32 SimpleScale;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Flags;
  sInt CoordinateSystem;
  sVector30 MajorAxis;
};

struct ModShaderParaTex2DSurroundNormal
{
  sInt Aux;
  sInt Transform;
  sF32 SimpleScale;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Flags;
  sInt CoordinateSystem;
  sVector30 MajorAxis;
};

struct ModShaderSamplerParaConst
{
  sInt Source;
  sU32 Color;
  sF32 Amp;
};

struct ModShaderSamplerParaTrickLight
{
  sInt Light;
  sInt Enable;
};

struct ModShaderSamplerParaMul
{
};

struct ModShaderSamplerParaAdd
{
};

struct ModShaderSamplerParaSub
{
};

struct ModShaderParaDiffuse
{
  sInt Op;
  sInt Aux;
};

struct ModShaderParaGloss
{
  sInt Op;
  sInt Aux;
};

struct ModShaderParaEmissive
{
  sInt Op;
  sInt Aux;
};

struct ModShaderParaSpecular
{
  sInt Op;
  sInt Aux;
};

struct ModShaderParaAux
{
  sInt Op;
};

struct ModShaderParaAlpha
{
  sInt Op;
  sInt Channel;
};

struct ModShaderParaKill
{
  sF32 Thresh[2];
  sInt Invert;
  sInt Channel;
};

struct ModShaderParaDisplace
{
  sInt Channel;
  sF32 Scale;
};

struct ModShaderParaExtrudeNormal
{
  sInt Source;
  sF32 Value;
};

struct ModShaderParaNormalMap
{
};

struct ModShaderParaDoubleNormalMap
{
  sInt Mode;
};

struct ModShaderSamplerParaBakedShadow
{
  sVector30 Dir;
  sInt ShadowSize;
  sF32 ShadowBaseBias;
  sF32 ShadowFilter;
  sF32 ShadowSlopeBias;
  sU32 Color;
  sVector31 LimitCenter;
  sVector30 LimitRadius;
};

struct ModShaderSamplerParaShadowGrab
{
  sInt Lightsource;
};

struct ModShaderParaTint
{
  sInt Select;
  sU32 Color;
  sF32 Amp;
};

struct ModShaderParaDebug
{
  sInt Debug;
  sInt Light;
  sF32 Bright;
};

struct ModShaderParaSphereFog
{
  sVector31 Center;
  sF32 Radius;
  sInt Animate;
  sInt LightEnvVector;
};


/****************************************************************************/

struct ModShaderAnimFlat
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaFlat *para);

};

struct ModShaderAnimLambert
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaLambert *para);

};

struct ModShaderAnimPhong
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaPhong *para);

};

struct ModShaderAnimRim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaRim *para);

};

struct ModShaderAnimComic
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaComic *para);

};

struct ModShaderAnimBlinnPhong
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaBlinnPhong *para);

};

struct ModShaderSamplerAnimTex2D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaTex2D *para);

};

struct ModShaderSamplerAnimTex2DAnim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaTex2DAnim *para);

};

struct ModShaderSamplerAnimTex2DSurround
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaTex2DSurround *para);

};

struct ModShaderAnimTex2DSurroundNormal
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaTex2DSurroundNormal *para);

};

struct ModShaderSamplerAnimConst
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaConst *para);

};

struct ModShaderSamplerAnimTrickLight
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaTrickLight *para);

};

struct ModShaderSamplerAnimMul
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaMul *para);

};

struct ModShaderSamplerAnimAdd
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaAdd *para);

};

struct ModShaderSamplerAnimSub
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaSub *para);

};

struct ModShaderAnimDiffuse
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaDiffuse *para);

};

struct ModShaderAnimGloss
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaGloss *para);

};

struct ModShaderAnimEmissive
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaEmissive *para);

};

struct ModShaderAnimSpecular
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaSpecular *para);

};

struct ModShaderAnimAux
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaAux *para);

};

struct ModShaderAnimAlpha
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaAlpha *para);

};

struct ModShaderAnimKill
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaKill *para);

};

struct ModShaderAnimDisplace
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaDisplace *para);

};

struct ModShaderAnimExtrudeNormal
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaExtrudeNormal *para);

};

struct ModShaderAnimNormalMap
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaNormalMap *para);

};

struct ModShaderAnimDoubleNormalMap
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaDoubleNormalMap *para);

};

struct ModShaderSamplerAnimBakedShadow
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaBakedShadow *para);

  struct ScriptSymbol *_Dir;
  struct ScriptSymbol *_ShadowSize;
  struct ScriptSymbol *_ShadowBaseBias;
  struct ScriptSymbol *_ShadowFilter;
  struct ScriptSymbol *_ShadowSlopeBias;
  struct ScriptSymbol *_LimitCenter;
  struct ScriptSymbol *_LimitRadius;
};

struct ModShaderSamplerAnimShadowGrab
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderSamplerParaShadowGrab *para);

};

struct ModShaderAnimTint
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaTint *para);

};

struct ModShaderAnimDebug
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaDebug *para);

};

struct ModShaderAnimSphereFog
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ModShaderParaSphereFog *para);

};


/****************************************************************************/

void AddTypes_wz4_modmtrlmod_ops(sBool secondary=0);
void AddOps_wz4_modmtrlmod_ops(sBool secondary=0);

/****************************************************************************/

#endif

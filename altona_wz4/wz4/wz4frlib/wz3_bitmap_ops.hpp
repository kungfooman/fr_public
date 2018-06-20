/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz3_bitmap_ops
#define HEADER_WZ4OPS_wz3_bitmap_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class GenBitmapType_ *GenBitmapType;

/****************************************************************************/

#line 15 "wz3_bitmap_ops.ops"

  #include "wz4lib/basic_ops.hpp"
  #include "wz4lib/basic.hpp"

#line 23 "wz3_bitmap_ops.hpp"
class GenBitmapType_ : public BitmapBaseType_
{
public:
  GenBitmapType_() { Parent = BitmapBaseType; Color= 0xffc040c0; Flags = 0x0004; GuiSets = 0x0001; Symbol = L"GenBitmap"; Label = L"wz3 Bitmap";  Init(); }
  ~GenBitmapType_() { Exit(); }
#line 37 "wz3_bitmap_ops.ops"
  void Init();
#line 42 "wz3_bitmap_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 34 "wz3_bitmap_ops.hpp"
};

struct GenBitmapParaMakeWz3Bitmap
{
};

struct Texture2DParaMakeTexture2
{
  sInt Format;
};

struct UnitTestParaUnitTestBitmap
{
  sInt Flags;
};

struct GenBitmapParaFlat
{
  sInt Size;
  sU32 Color;
};

struct GenBitmapParaPerlin
{
  sInt Size;
  sInt Frequency;
  sInt Octaves;
  sF32 FadeOff;
  sInt Seed;
  sInt Mode;
  sF32 Amplify;
  sF32 Gamma;
  sU32 Color0;
  sU32 Color1;
};

struct GenBitmapParaCell
{
  sInt Size;
  sU32 Color0;
  sU32 Color1;
  sInt Max;
  sF32 MinDistance;
  sInt Seed;
  sF32 Amplify;
  sF32 Gamma;
  sF32 Aspect;
  sInt Mode;
  sU32 Color2;
  sInt Percentage;
};

struct GenBitmapParaGradient
{
  sInt Size;
  sInt Flags;
};

struct GenBitmapArrayGradient
{
  sF32 Pos;
  sU32 Color;
};

struct GenBitmapParaImport
{
};

struct GenBitmapParaImportAnim
{
};

struct GenBitmapParaGlowRect
{
  sF32 Center[2];
  sF32 Radius[2];
  sF32 Size[2];
  sU32 Color;
  sF32 Blend;
  sF32 Power;
  sInt Wrap;
  sInt Flags;
};

struct GenBitmapParaDots
{
  sU32 Color0;
  sU32 Color1;
  sInt Count;
  sInt Seed;
};

struct GenBitmapParaAtlas
{
  sInt Size;
  sU32 Color;
};

struct GenBitmapParaColor
{
  sInt Mode;
  sU32 Color;
};

struct GenBitmapParaRange
{
  sInt Mode;
  sU32 Color0;
  sU32 Color1;
};

struct GenBitmapParaHSCB
{
  sF32 Hue;
  sF32 Saturation;
  sF32 Contrast;
  sF32 Brightness;
};

struct GenBitmapParaBitcrusher
{
  sF32 Steps;
  sF32 Phase;
};

struct GenBitmapParaMerge
{
  sInt Mode;
};

struct GenBitmapParaPreMulAlpha
{
};

struct GenBitmapParaMask
{
  sInt Mode;
};

struct GenBitmapParaColorBalance
{
  sVector30 Shadows;
  sVector30 Midtones;
  sVector30 Highlights;
};

struct GenBitmapParaBlur
{
  sInt Passes;
  sF32 Blur[2];
  sF32 Amplify;
};

struct GenBitmapParaSharpen
{
  sInt Passes;
  sF32 Blur[2];
  sF32 Amplify;
};

struct GenBitmapParaRotate
{
  sInt Size;
  sF32 Center[2];
  sF32 Angle;
  sF32 Scale[2];
  sF32 Offset[2];
  sInt Flags;
};

struct GenBitmapParaRotateMul
{
  sF32 Angle;
  sF32 Scale[2];
  sF32 Offset[2];
  sInt Flags;
  sU32 PreAdjust;
  sInt Mode;
  sInt Count;
  sU32 Fade;
};

struct GenBitmapParaTwirl
{
  sF32 Strength;
  sF32 Gamma;
  sF32 Radius[2];
  sF32 Center[2];
  sInt Flags;
};

struct GenBitmapParaDistort
{
  sF32 Strength;
  sInt Flags;
};

struct GenBitmapParaNormals
{
  sF32 Strength;
  sInt Mode;
};

struct GenBitmapParaLight
{
  sInt Mode;
  sVector31 Pos;
  sF32 Dir[2];
  sU32 Diffuse;
  sU32 Ambient;
  sF32 Outer;
  sF32 Falloff;
  sF32 Amplify;
};

struct GenBitmapParaBump
{
  sInt Mode;
  sVector31 Pos;
  sF32 Dir[2];
  sU32 Diffuse;
  sU32 Ambient;
  sF32 Outer;
  sF32 Falloff;
  sF32 Amplify;
  sU32 Specular;
  sF32 Power;
  sF32 SpecAmp;
};

struct GenBitmapParaDownsample
{
  sInt Size;
  sInt Flags;
};

struct GenBitmapParaText
{
  sF32 Position[2];
  sF32 Height;
  sF32 Leading;
  sF32 Stretch;
  sU32 Color;
  sInt Flags;
};

struct GenBitmapParaExport
{
};

struct GenBitmapParaUnwrap
{
  sInt Mode;
};

struct GenBitmapParaBulge
{
  sF32 Amount;
};

struct GenBitmapParaBricks
{
  sInt Size;
  sU32 Color0;
  sU32 Color1;
  sU32 Joints;
  sF32 SizeJoints[2];
  sInt Count[2];
  sInt Seed;
  sInt SingleWidthStones;
  sInt Flags;
  sF32 Side;
  sF32 ColorBalance;
};

struct GenBitmapParaVector
{
  sU32 Color;
};

struct GenBitmapArrayVector
{
  sF32 x;
  sF32 y;
  sU32 col;
  sInt restart;
};


/****************************************************************************/

struct GenBitmapAnimMakeWz3Bitmap
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaMakeWz3Bitmap *para);

};

struct Texture2DAnimMakeTexture2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Texture2DParaMakeTexture2 *para);

};

struct UnitTestAnimUnitTestBitmap
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,UnitTestParaUnitTestBitmap *para);

};

struct GenBitmapAnimFlat
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaFlat *para);

};

struct GenBitmapAnimPerlin
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaPerlin *para);

};

struct GenBitmapAnimCell
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaCell *para);

};

struct GenBitmapAnimGradient
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaGradient *para);

};

struct GenBitmapAnimImport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaImport *para);

};

struct GenBitmapAnimImportAnim
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaImportAnim *para);

};

struct GenBitmapAnimGlowRect
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaGlowRect *para);

};

struct GenBitmapAnimDots
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaDots *para);

};

struct GenBitmapAnimAtlas
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaAtlas *para);

};

struct GenBitmapAnimColor
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaColor *para);

};

struct GenBitmapAnimRange
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaRange *para);

};

struct GenBitmapAnimHSCB
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaHSCB *para);

};

struct GenBitmapAnimBitcrusher
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaBitcrusher *para);

};

struct GenBitmapAnimMerge
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaMerge *para);

};

struct GenBitmapAnimPreMulAlpha
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaPreMulAlpha *para);

};

struct GenBitmapAnimMask
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaMask *para);

};

struct GenBitmapAnimColorBalance
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaColorBalance *para);

};

struct GenBitmapAnimBlur
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaBlur *para);

};

struct GenBitmapAnimSharpen
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaSharpen *para);

};

struct GenBitmapAnimRotate
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaRotate *para);

};

struct GenBitmapAnimRotateMul
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaRotateMul *para);

};

struct GenBitmapAnimTwirl
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaTwirl *para);

};

struct GenBitmapAnimDistort
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaDistort *para);

};

struct GenBitmapAnimNormals
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaNormals *para);

};

struct GenBitmapAnimLight
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaLight *para);

};

struct GenBitmapAnimBump
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaBump *para);

};

struct GenBitmapAnimDownsample
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaDownsample *para);

};

struct GenBitmapAnimText
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaText *para);

};

struct GenBitmapAnimExport
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaExport *para);

};

struct GenBitmapAnimUnwrap
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaUnwrap *para);

};

struct GenBitmapAnimBulge
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaBulge *para);

};

struct GenBitmapAnimBricks
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaBricks *para);

};

struct GenBitmapAnimVector
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaVector *para);

};


/****************************************************************************/

void AddTypes_wz3_bitmap_ops(sBool secondary=0);
void AddOps_wz3_bitmap_ops(sBool secondary=0);

/****************************************************************************/

#endif

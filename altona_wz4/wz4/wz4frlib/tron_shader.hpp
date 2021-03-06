/****************************************************************************/
/***                                                                      ***/
/***   header file generated by ASC 1.63 - altona shader compiler.        ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4FRLIB_TRON_SHADER_ASC
#define HEADER_WZ4FRLIB_TRON_SHADER_ASC

#include "base/graphics.hpp"

/****************************************************************************/

enum tBloomMaskPSPerm
{
  tBloomMaskPSPermMask_GRAY                 = 0x0001,
  tBloomMaskPSPermMask_MSC                  = 0x0002,
  tBloomMaskPSPermMask_ZBUF                 = 0x0004,
  tBloomMaskPSPermMask_ABUF                 = 0x0008,
  tBloomMaskPSPerm_TAP0                     = 0x0000,
  tBloomMaskPSPerm_TAP5                     = 0x0010,
  tBloomMaskPSPerm_TAP9                     = 0x0020,
  tBloomMaskPSPermMask_TAP                  = 0x0030,
};
enum tBloomCompPSPerm
{
  tBloomCompPSPerm_Add                      = 0x0000,
  tBloomCompPSPerm_Screen                   = 0x0001,
  tBloomCompPSPerm_Mul                      = 0x0002,
  tBloomCompPSPermMask_Blend                = 0x0003,
};
enum tGlowMaskMatPSPerm
{
  tGlowMaskMatPSPermMask_EDGE               = 0x0001,
};
enum tGlowCombMatPSPerm
{
  tGlowCombMatPSPermMask_ADD                = 0x0001,
  tGlowCombMatPSPermMask_BLEND              = 0x0002,
  tGlowCombMatPSPermMask_MULTIPLY           = 0x0004,
  tGlowCombMatPSPermMask_SUB                = 0x0008,
};

/****************************************************************************/

struct tSharpen4MaterialVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 54 "tron_shader.hpp"
};

struct tSharpen4MaterialPSPara
{
public:
  sVector4 rw;
  sVector4 rh;
  sVector4 factors[16];
  static const sInt RegStart = 0;
  static const sInt RegCount = 18;
  static const sInt Slot = sCBUFFER_PS|0;
#line 66 "tron_shader.hpp"
};

struct tLTSMaterialVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 76 "tron_shader.hpp"
};

struct tLTSMaterialPSPara
{
public:
  sVector4 scale;
  static const sInt RegStart = 0;
  static const sInt RegCount = 1;
  static const sInt Slot = sCBUFFER_PS|0;
#line 86 "tron_shader.hpp"
};

struct tSTLMaterialVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 96 "tron_shader.hpp"
};

struct tSTLMaterialPSPara
{
public:
  sVector4 ivexpo;
  static const sInt RegStart = 0;
  static const sInt RegCount = 1;
  static const sInt Slot = sCBUFFER_PS|0;
#line 106 "tron_shader.hpp"
};

struct tBloomMaskVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 116 "tron_shader.hpp"
};

struct tBloomMaskPSPara
{
public:
  sVector4 HighlightCol;
  sVector4 MaskCol;
  sVector4 MaskScaleBias;
  sVector4 ZBufScaleBias;
  sVector4 AlphaScaleBias;
  sVector4 GrayCol;
  sVector4 BlendFactor;
  sVector4 Misc;
  static const sInt RegStart = 0;
  static const sInt RegCount = 8;
  static const sInt Slot = sCBUFFER_PS|0;
#line 133 "tron_shader.hpp"
};

struct tBloomCompVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 143 "tron_shader.hpp"
};

struct tBloomCompPSPara
{
public:
  sVector4 ScreenCol;
  sVector4 BloomCol;
  static const sInt RegStart = 0;
  static const sInt RegCount = 2;
  static const sInt Slot = sCBUFFER_PS|0;
#line 154 "tron_shader.hpp"
};

struct tPromistCompVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 164 "tron_shader.hpp"
};

struct tPromistCompPSPara
{
public:
  sVector4 ScreenNormalCol;
  sVector4 ScreenBlurredCol;
  static const sInt RegStart = 0;
  static const sInt RegCount = 2;
  static const sInt Slot = sCBUFFER_PS|0;
#line 175 "tron_shader.hpp"
};

struct tCopyVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 185 "tron_shader.hpp"
};

struct tCopyPSPara
{
public:
  sVector4 unused;
  static const sInt RegStart = 0;
  static const sInt RegCount = 1;
  static const sInt Slot = sCBUFFER_PS|0;
#line 195 "tron_shader.hpp"
};

struct tDoF3MaskVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 205 "tron_shader.hpp"
};

struct tDoF3MaskPSPara
{
public:
  sVector4 Params;
  static const sInt RegStart = 0;
  static const sInt RegCount = 1;
  static const sInt Slot = sCBUFFER_PS|0;
#line 215 "tron_shader.hpp"
};

struct tDoF3CompVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 225 "tron_shader.hpp"
};

struct tDoF3CompPSPara
{
public:
  sVector4 ScreenNormalCol;
  sVector4 ScreenBlurredCol;
  static const sInt RegStart = 0;
  static const sInt RegCount = 2;
  static const sInt Slot = sCBUFFER_PS|0;
#line 236 "tron_shader.hpp"
};

struct tGlowGradientMatVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 246 "tron_shader.hpp"
};

struct tGlowGradientMatPSPara
{
public:
  sVector4 in_color;
  sVector4 out_color;
  sVector4 factors;
  static const sInt RegStart = 0;
  static const sInt RegCount = 3;
  static const sInt Slot = sCBUFFER_PS|0;
#line 258 "tron_shader.hpp"
};

struct tGlowMaskMatVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 268 "tron_shader.hpp"
};

struct tGlowMaskMatPSPara
{
public:
  sVector4 textpar;
  sVector4 maskpar;
  static const sInt RegStart = 0;
  static const sInt RegCount = 2;
  static const sInt Slot = sCBUFFER_PS|0;
#line 279 "tron_shader.hpp"
};

struct tGlowCombMatVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 289 "tron_shader.hpp"
};

struct tGlowCombMatPSPara
{
public:
  sVector4 textpar;
  static const sInt RegStart = 0;
  static const sInt RegCount = 1;
  static const sInt Slot = sCBUFFER_PS|0;
#line 299 "tron_shader.hpp"
};

struct tFocusBlurMatVSPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 309 "tron_shader.hpp"
};

struct tFocusBlurMatPSPara
{
public:
  sVector4 focuspoint;
  static const sInt RegStart = 0;
  static const sInt RegCount = 1;
  static const sInt Slot = sCBUFFER_PS|0;
#line 319 "tron_shader.hpp"
};


/****************************************************************************/

class tSharpen4Material : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tLTSMaterial : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tSTLMaterial : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tBloomMaskMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS(sInt);
public:
  tBloomMaskMat();
  void SelectShaders(sVertexFormatHandle *);
#line 349 "tron_shader.asc"

    enum ExtraBits
    {
      EXTRA_GRAY    = 0x02,
      EXTRA_MSC     = 0x04,
      EXTRA_ZBUF    = 0x08,
      EXTRA_ABUF    = 0x10,
      EXTRA_PRETAP0 = 0x00,
      EXTRA_PRETAP5 = 0x40,
      EXTRA_PRETAP9 = 0x80,
    };
    sInt Extra;
  
#line 367 "tron_shader.cpp"
};
class tBloomCompMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS(sInt);
public:
  tBloomCompMat();
  void SelectShaders(sVertexFormatHandle *);
#line 500 "tron_shader.asc"

    enum ExtraBits
    {
      EXTRA_ADD  = 0,
      EXTRA_SCREEN   = 1,
      EXTRA_MUL   = 2,
    };
    sInt Extra;
  
#line 386 "tron_shader.cpp"
};
class tPromistCompMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tCopyMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tDoF3MaskMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tDoF3CompMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tGlowGradientMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class tGlowMaskMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS(sInt);
public:
  tGlowMaskMat();
  void SelectShaders(sVertexFormatHandle *);
#line 981 "tron_shader.asc"

    enum ExtraBits
    {
      EXTRA_EDGE  = 1<<1,
    };
    sInt Extra;
  
#line 438 "tron_shader.cpp"
};
class tGlowCombMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS(sInt);
public:
  tGlowCombMat();
  void SelectShaders(sVertexFormatHandle *);
#line 1106 "tron_shader.asc"

    enum ExtraBits
    {
      EXTRA_ADD      = 1<<1,
      EXTRA_BLEND    = 1<<2,
      EXTRA_MULTIPLY = 1<<3,
      EXTRA_SUB      = 1<<4
    };
    sInt Extra;
  
#line 458 "tron_shader.cpp"
};
class tFocusBlurMat : public sMaterial
{
  static sShader *VS();
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};

/****************************************************************************/

#endif


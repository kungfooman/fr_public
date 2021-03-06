/****************************************************************************/
/***                                                                      ***/
/***   header file generated by ASC 1.63 - altona shader compiler.        ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4FRLIB_WZ4_MTRL2_SHADER_ASC
#define HEADER_WZ4FRLIB_WZ4_MTRL2_SHADER_ASC

#include "base/graphics.hpp"

/****************************************************************************/

enum Wz4MtrlWireframePerm
{
  Wz4MtrlWireframePermMask_Inst             = 0x0001,
};
enum Wz4MtrlZOnlyPerm
{
  Wz4MtrlZOnlyPermMask_Inst                 = 0x0001,
  Wz4MtrlZOnlyPermMask_Skin                 = 0x0002,
  Wz4MtrlZOnlyPerm_ZNormal                  = 0x0000,
  Wz4MtrlZOnlyPerm_ZW                       = 0x0004,
  Wz4MtrlZOnlyPerm_ZDist                    = 0x0008,
  Wz4MtrlZOnlyPermMask_ZMode                = 0x000c,
  Wz4MtrlZOnlyPermMask_NormalI4             = 0x0010,
};
enum Wz4MtrlZOnlyPSPerm
{
  Wz4MtrlZOnlyPSPerm_ZNormal                = 0x0000,
  Wz4MtrlZOnlyPSPerm_ZW                     = 0x0001,
  Wz4MtrlZOnlyPSPerm_ZDist                  = 0x0002,
  Wz4MtrlZOnlyPSPermMask_ZMode              = 0x0003,
};
enum Wz4MtrlErrorPerm
{
  Wz4MtrlErrorPermMask_Inst                 = 0x0001,
  Wz4MtrlErrorPermMask_Skin                 = 0x0002,
};
enum SimpleShaderVPerm
{
  SimpleShaderVPermMask_Light               = 0x0001,
  SimpleShaderVPerm_TexOff                  = 0x0000,
  SimpleShaderVPerm_Tex1                    = 0x0002,
  SimpleShaderVPerm_Tex2                    = 0x0004,
  SimpleShaderVPermMask_Tex                 = 0x0006,
  SimpleShaderVPerm_DetailUV                = 0x0000,
  SimpleShaderVPerm_DetailPos               = 0x0008,
  SimpleShaderVPerm_DetailNorm              = 0x0010,
  SimpleShaderVPerm_DetailRefl              = 0x0018,
  SimpleShaderVPermMask_Detail              = 0x0038,
  SimpleShaderVPermMask_MatrixSkin          = 0x0040,
  SimpleShaderVPermMask_MatrixInst          = 0x0080,
  SimpleShaderVPermMask_PosOut              = 0x0100,
  SimpleShaderVPerm_VTexOff                 = 0x0000,
  SimpleShaderVPerm_VTexUV                  = 0x0200,
  SimpleShaderVPerm_VTexPos                 = 0x0400,
  SimpleShaderVPerm_VTexNoise               = 0x0600,
  SimpleShaderVPermMask_VTex                = 0x0e00,
  SimpleShaderVPermMask_NormalI4            = 0x1000,
};
enum SimpleShaderPPerm
{
  SimpleShaderPPermMask_Tex1                = 0x0001,
  SimpleShaderPPerm_Tex2Off                 = 0x0000,
  SimpleShaderPPerm_Tex2Add                 = 0x0002,
  SimpleShaderPPerm_Tex2Mul                 = 0x0004,
  SimpleShaderPPermMask_Tex2                = 0x0006,
  SimpleShaderPPerm_FogOff                  = 0x0000,
  SimpleShaderPPerm_FogOn                   = 0x0008,
  SimpleShaderPPerm_FogBlack                = 0x0010,
  SimpleShaderPPerm_FogClip3                = 0x0018,
  SimpleShaderPPermMask_Fog                 = 0x0038,
  SimpleShaderPPermMask_Clip                = 0x0040,
};

/****************************************************************************/

struct Wz4MtrlModelPara
{
public:
  sVector4 m[3];
  static const sInt RegStart = 28;
  static const sInt RegCount = 3;
  static const sInt Slot = sCBUFFER_VS|1;
#line 87 "wz4_mtrl2_shader.hpp"
};

struct Wz4MtrlSkinPara
{
public:
  sVector4 Skinning[3];
  static const sInt RegStart = 32;
  static const sInt RegCount = 3;
  static const sInt Slot = sCBUFFER_VS|3;
#line 97 "wz4_mtrl2_shader.hpp"
};

struct CustomShaderVEnv
{
public:
  sMatrix44 mvp;
  sMatrix44 mv;
  sVector4 EyePos;
  sVector4 vs_var0;
  sVector4 vs_var1;
  sVector4 vs_var2;
  sVector4 vs_var3;
  sVector4 vs_var4;
  static const sInt RegStart = 0;
  static const sInt RegCount = 14;
  static const sInt Slot = sCBUFFER_VS|0;
#line 114 "wz4_mtrl2_shader.hpp"
};

struct CustomShaderPEnv
{
public:
  sMatrix44 mvp;
  sMatrix44 mv;
  sVector4 EyePos;
  sVector4 ps_var0;
  sVector4 ps_var1;
  sVector4 ps_var2;
  sVector4 ps_var3;
  sVector4 ps_var4;
  static const sInt RegStart = 0;
  static const sInt RegCount = 14;
  static const sInt Slot = sCBUFFER_PS|0;
#line 131 "wz4_mtrl2_shader.hpp"
};

struct Wz4MtrlWireframePara
{
public:
  sMatrix44 MVP;
  sVector4 scale;
  static const sInt RegStart = 0;
  static const sInt RegCount = 5;
  static const sInt Slot = sCBUFFER_VS|0;
#line 142 "wz4_mtrl2_shader.hpp"
};

struct Wz4MtrlZOnlyPara
{
public:
  sMatrix44 mvp;
  sMatrix44 mv;
  sVector4 proj;
  sVector4 center;
  static const sInt RegStart = 0;
  static const sInt RegCount = 10;
  static const sInt Slot = sCBUFFER_VS|0;
#line 155 "wz4_mtrl2_shader.hpp"
};

struct Wz4MtrlErrorPara
{
public:
  sMatrix44 mvp;
  static const sInt RegStart = 0;
  static const sInt RegCount = 4;
  static const sInt Slot = sCBUFFER_VS|0;
#line 165 "wz4_mtrl2_shader.hpp"
};

struct SimpleShaderVEnv
{
public:
  sMatrix44 mvp;
  sMatrix44 mv;
  sVector4 lc[4];
  sVector4 la;
  sVector4 ld[3];
  sVector4 EyePos;
  static const sInt RegStart = 0;
  static const sInt RegCount = 17;
  static const sInt Slot = sCBUFFER_VS|0;
#line 180 "wz4_mtrl2_shader.hpp"
};

struct SimpleShaderVPara
{
public:
  sVector4 texmat[7];
  sVector4 vextra;
  static const sInt RegStart = 20;
  static const sInt RegCount = 8;
  static const sInt Slot = sCBUFFER_VS|2;
#line 191 "wz4_mtrl2_shader.hpp"
};

struct SimpleShaderPEnv
{
public:
  sVector4 FogPara;
  sVector4 FogColor;
  sVector4 ClipPlane[4];
  static const sInt RegStart = 0;
  static const sInt RegCount = 6;
  static const sInt Slot = sCBUFFER_PS|0;
#line 203 "wz4_mtrl2_shader.hpp"
};


/****************************************************************************/

class Wz4MtrlWireframe : public sMaterial
{
  static sShader *VS(sInt);
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class Wz4MtrlZOnly : public sMaterial
{
  static sShader *VS(sInt);
  static sShader *PS(sInt);
public:
  Wz4MtrlZOnly();
  void SelectShaders(sVertexFormatHandle *);
#line 221 "wz4_mtrl2_shader.asc"

    sInt SimpleZ;
  
#line 227 "wz4_mtrl2_shader.cpp"
};
class Wz4MtrlError : public sMaterial
{
  static sShader *VS(sInt);
  static sShader *PS();
public:
  void SelectShaders(sVertexFormatHandle *);
};
class SimpleShader : public sMaterial
{
  static sShader *VS(sInt);
  static sShader *PS(sInt);
public:
  SimpleShader();
  void SelectShaders(sVertexFormatHandle *);
#line 625 "wz4_mtrl2_shader.asc"

    enum ExtraBits
    {
      Extra_Fog           = 0x0001,
      Extra_FogBlack      = 0x0002,
      Extra_TexMul        = 0x0004,
      Extra_Clip          = 0x0008,
      Extra_NormalI4      = 0x1000,

      ExtraDetailMask     = 0x00f0,
      ExtraDetailUV       = 0x0000,
      ExtraDetailPos      = 0x0010,
      ExtraDetailNorm     = 0x0020,
      ExtraDetailRefl     = 0x0030,

      ExtraVTexMask       = 0x0300,
      ExtraVTexUV         = 0x0000,
      ExtraVTexPos        = 0x0100,
      ExtraVTexNoise      = 0x0200,
    };
    sInt Extra;
  
#line 266 "wz4_mtrl2_shader.cpp"
};

/****************************************************************************/

#endif


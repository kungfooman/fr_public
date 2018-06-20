/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_wz4_demo2_ops
#define HEADER_WZ4OPS_wz4_demo2_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class Wz4RenderType_ *Wz4RenderType;
extern class Wz4ParticlesType_ *Wz4ParticlesType;
extern class Rendertarget2DType_ *Rendertarget2DType;

/****************************************************************************/

#line 9 "wz4_demo2_ops.ops"

#include "wz4lib/poc_ops.hpp"
//#include "wz4frlib/chaosmesh_ops.hpp"
#include "wz4frlib/wz4_mesh_ops.hpp"

#line 26 "wz4_demo2_ops.hpp"
class Wz4RenderType_ : public AnyTypeType_
{
public:
  Wz4RenderType_() { Parent = AnyTypeType; Color= 0xfffbda66; Flags = 0x0002; GuiSets = 0x0002; Symbol = L"Wz4Render"; Label = L"wz4 RenderTree";  Init(); }
  ~Wz4RenderType_() { Exit(); }
#line 39 "wz4_demo2_ops.ops"

    class ScriptContext *Script;
    struct ScriptSymbol *_Time;
    struct ScriptSymbol *_BaseTime;
    struct ScriptSymbol *_LocalTime;
    struct ScriptSymbol *_LowQuality;
//    struct ScriptSymbol *_Fader;
//    struct ScriptSymbol *_Rotor;
    class IppHelper2 *IppHelper;
    sU8 MidiHigh[16];
    sF32 MidiFloat[16];

    void Init();
    void Exit();
    void BeginShow(wPaintInfo &pi);
    void Show(wObject *obj,wPaintInfo &pi);

    void Midi();
  
#line 52 "wz4_demo2_ops.hpp"
#line 54 "wz4_demo2_ops.hpp"
};

class Wz4ParticlesType_ : public AnyTypeType_
{
public:
  Wz4ParticlesType_() { Parent = AnyTypeType; Color= 0xffa0a060; Flags = 0x0003; GuiSets = 0x0002; Symbol = L"Wz4Particles"; Label = L"wz4 Particles";  Init(); }
  ~Wz4ParticlesType_() { Exit(); }
#line 68 "wz4_demo2_ops.ops"

    void Show(wObject *obj,wPaintInfo &pi);
  
#line 65 "wz4_demo2_ops.hpp"
#line 67 "wz4_demo2_ops.hpp"
};

class Rendertarget2DType_ : public Texture2DType_
{
public:
  Rendertarget2DType_() { Parent = Texture2DType; Flags = 0x0003; GuiSets = 0x0001; Symbol = L"Rendertarget2D"; Label = L"Rendertarget2D";  Init(); }
  ~Rendertarget2DType_() { Exit(); }
#line 79 "wz4_demo2_ops.ops"

  public:
    sArray<Rendertarget2D *> Targets;
  
#line 79 "wz4_demo2_ops.hpp"
#line 83 "wz4_demo2_ops.ops"
  void EndShow(wPaintInfo &pi);
#line 83 "wz4_demo2_ops.hpp"
};

struct Rendertarget2DParaRendertarget2
{
  sInt Flags;
  sInt Size2;
  sInt Divider[2];
  sInt Size[2];
  sInt Mode;
  sInt AtlasCount;
};

struct Wz4RenderParaRender
{
};

struct Wz4RenderParaRenderNull
{
};

struct Wz4RenderParaCamera
{
  sVector31 Target;
  sVector31 Position;
  sF32 Tilt;
  sF32 Zoom;
  sF32 ClipNear;
  sF32 ClipFar;
  sF32 Distance;
  sU32 ClearColor;
  sInt Renderpass;
  sInt Mode;
  sVector31 Rot;
  sInt Clear;
  sF32 SplineTime;
};

struct Wz4RenderParaBillboardCamera
{
  sInt Renderpass;
  sU32 ClearColor;
  sInt Flags;
  sF32 Distance;
  sF32 Zoom;
  sF32 ClipNear;
  sF32 ClipFar;
  sInt AtlasId;
};

struct GenBitmapParaRender
{
  sInt Flags;
  sInt Size2;
  sInt Divider[2];
  sInt Size[2];
  sF32 Time;
  sF32 BaseTime;
};

struct Wz4RenderParaRenderMesh
{
  sInt LightEnv;
  sF32 BoneTime;
  sInt Renderpass;
  sInt Instances;
};

struct Wz4RenderParaMultiplyMesh
{
  sInt Flags;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Count1;
  sVector31 Scale1;
  sVector30 Rot1;
  sVector31 Trans1;
  sInt Count2;
  sVector31 Scale2;
  sVector30 Rot2;
  sVector31 Trans2;
  sInt Count3;
  sVector31 Scale3;
  sVector30 Rot3;
  sVector31 Trans3;
  sInt LightEnv;
  sInt Renderpass;
};

struct Wz4RenderParaScript
{
  sInt Renderpass;
};

struct Wz4RenderParaTransform
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Renderpass;
};

struct Wz4RenderParaTransformPivot
{
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
  sInt Renderpass;
  sVector31 Pivot;
};

struct Wz4RenderParaSplinedObject
{
  sF32 Tick;
  sF32 TimeDelta;
  sInt Mode;
  sInt Renderpass;
  sF32 RotateAmount;
};

struct Wz4RenderParaLookAt
{
  sVector31 Pos;
  sVector31 Target;
  sVector30 UpVector;
  sF32 Tilt;
  sInt Renderpass;
};

struct Wz4RenderParaSkyCube
{
  sInt Renderpass;
};

struct Wz4RenderParaShaker
{
  sInt Mode;
  sF32 Animate;
  sVector31 Center;
  sF32 Amp;
  sF32 TimeRange[2];
  sVector31 TranslateAmp;
  sVector30 TranslateFreq;
  sVector31 RotateAmp;
  sVector30 RotateFreq;
  sInt Renderpass;
};

struct Wz4RenderParaMultiply
{
  sInt Renderpass;
  sInt Flags;
  sVector31 PreScale;
  sVector30 PreRot;
  sVector31 PreTrans;
  sInt Count;
  sVector31 Scale;
  sVector30 Rot;
  sVector31 Trans;
};

struct Wz4RenderParaClip
{
  sF32 StartTime;
  sF32 Length;
  sInt Line;
  sInt Flags;
  sInt Renderpass;
  sF32 Time0;
  sF32 Time1;
  sInt Enable;
  sF32 LocalOffset;
  sInt Color;
};

struct Wz4RenderParaClipRandomizer
{
  sF32 StartTime;
  sF32 Length;
  sInt Line;
  sInt _pad3;
  sInt Renderpass;
  sInt _pad5[2];
  sInt Enable;
  sF32 DefaultClipLength;
};

struct Wz4RenderParaClipRandDuration
{
  sInt _pad0;
  sF32 Length;
};

struct Wz4RenderParaMultiClip
{
  sInt Flags;
  sInt Renderpass;
  sInt Line;
  sInt MasterEnable;
};

struct Wz4RenderArrayMultiClip
{
  sF32 Start;
  sF32 Length;
  sF32 Time0;
  sF32 Time1;
  sInt Enable;
  sInt Color;
};

struct Wz4RenderParaFader
{
  sInt Renderpass;
  sVector4 FaderA;
  sVector4 FaderB;
  sVector4 RotorA;
  sVector4 RotorB;
};

struct Wz4RenderParaFader2
{
  sInt Renderpass;
  sVector4 FaderA;
  sVector4 FaderB;
  sVector4 RotorA;
  sVector4 RotorB;
};

struct Wz4RenderParaVariable
{
  sInt Renderpass;
  sInt Count;
  sVector4 Value;
};

struct Wz4RenderParaSpline
{
  sInt Dimensions;
  sInt Spline;
  sF32 MaxTime;
  sInt Flags;
  sInt GrabCamMode;
};

struct Wz4RenderArraySpline
{
  sF32 Time;
  sInt Use;
  sF32 Value;
  sInt Select;
};

struct Wz4RenderParaLayer2D
{
  sInt Renderpass;
  sF32 Center[2];
  sF32 Size[2];
  sF32 ScaleUV[2];
  sF32 ScrollUV[2];
  sU32 Color;
  sInt Aspect;
  sInt Blend;
  sInt Align;
  sInt Filter;
  sInt Mix;
  sF32 ScaleUV2[2];
  sF32 ScrollUV2[2];
};

struct Wz4RenderParaBeat
{
  sF32 Level0;
  sF32 Att0;
  sF32 Rel0;
  sF32 Level1;
  sF32 Att1;
  sF32 Rel1;
  sF32 Level2;
  sF32 Att2;
  sF32 Rel2;
  sF32 Level3;
  sF32 Att3;
  sF32 Rel3;
  sF32 Level4;
  sF32 Att4;
  sF32 Rel4;
  sF32 Level5;
  sF32 Att5;
  sF32 Rel5;
  sF32 Level6;
  sF32 Att6;
  sF32 Rel6;
  sF32 Level7;
  sF32 Att7;
  sF32 Rel7;
  sF32 Level8;
  sF32 Att8;
  sF32 Rel8;
  sF32 Level9;
  sF32 Att9;
  sF32 Rel9;
  sF32 Level10;
  sF32 Att10;
  sF32 Rel10;
  sF32 Level11;
  sF32 Att11;
  sF32 Rel11;
  sF32 Level12;
  sF32 Att12;
  sF32 Rel12;
  sF32 Level13;
  sF32 Att13;
  sF32 Rel13;
  sF32 Level14;
  sF32 Att14;
  sF32 Rel14;
  sF32 Level15;
  sF32 Att15;
  sF32 Rel15;
  sInt Tempo;
  sInt _pad49;
  sInt Mode;
  sF32 Attack;
  sF32 Release;
  sF32 Amp;
  sF32 Bias;
  sF32 Timeshift;
  sInt SplineFlags;
  sInt _pad57[2];
  sInt Levels;
};

struct Wz4RenderArrayBeat
{
  sInt Hex[4];
};

struct Wz4RenderParaBoneTrain
{
  sInt Renderpass;
  sInt LightEnv;
  sF32 Start;
  sF32 Length;
  sInt Flags;
  sVector30 UpVector;
  sF32 Twist;
  sF32 Twirl;
};

struct UnitTestParaUnitTestWz4
{
  sInt Size;
  sInt Flags;
};


/****************************************************************************/

struct Rendertarget2DAnimRendertarget2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Rendertarget2DParaRendertarget2 *para);

};

struct Wz4RenderAnimRender
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaRender *para);

};

struct Wz4RenderAnimRenderNull
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaRenderNull *para);

};

struct Wz4RenderAnimCamera
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaCamera *para);

  struct ScriptSymbol *_SplineTime;
  struct ScriptSymbol *_Position;
  struct ScriptSymbol *_Target;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Distance;
  struct ScriptSymbol *_Tilt;
  struct ScriptSymbol *_Zoom;
  struct ScriptSymbol *_ClipNear;
  struct ScriptSymbol *_ClipFar;
  struct ScriptSymbol *_ClearColor;
};

struct Wz4RenderAnimBillboardCamera
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBillboardCamera *para);

  struct ScriptSymbol *_ClearColor;
  struct ScriptSymbol *_Distance;
  struct ScriptSymbol *_Zoom;
  struct ScriptSymbol *_ClipNear;
  struct ScriptSymbol *_ClipFar;
};

struct GenBitmapAnimRender
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,GenBitmapParaRender *para);

};

struct Wz4RenderAnimRenderMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaRenderMesh *para);

  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_BoneTime;
};

struct Wz4RenderAnimMultiplyMesh
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaMultiplyMesh *para);

  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Count1;
  struct ScriptSymbol *_Scale1;
  struct ScriptSymbol *_Rot1;
  struct ScriptSymbol *_Trans1;
  struct ScriptSymbol *_Count2;
  struct ScriptSymbol *_Scale2;
  struct ScriptSymbol *_Rot2;
  struct ScriptSymbol *_Trans2;
  struct ScriptSymbol *_Count3;
  struct ScriptSymbol *_Scale3;
  struct ScriptSymbol *_Rot3;
  struct ScriptSymbol *_Trans3;
};

struct Wz4RenderAnimScript
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaScript *para);

};

struct Wz4RenderAnimTransform
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaTransform *para);

  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
};

struct Wz4RenderAnimTransformPivot
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaTransformPivot *para);

  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
  struct ScriptSymbol *_Pivot;
};

struct Wz4RenderAnimSplinedObject
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSplinedObject *para);

  struct ScriptSymbol *_Tick;
  struct ScriptSymbol *_TimeDelta;
};

struct Wz4RenderAnimLookAt
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaLookAt *para);

  struct ScriptSymbol *_Pos;
  struct ScriptSymbol *_Target;
  struct ScriptSymbol *_UpVector;
  struct ScriptSymbol *_Tilt;
};

struct Wz4RenderAnimSkyCube
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSkyCube *para);

};

struct Wz4RenderAnimShaker
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaShaker *para);

  struct ScriptSymbol *_Animate;
  struct ScriptSymbol *_Center;
  struct ScriptSymbol *_Amp;
  struct ScriptSymbol *_TimeRange;
  struct ScriptSymbol *_TranslateAmp;
  struct ScriptSymbol *_TranslateFreq;
  struct ScriptSymbol *_RotateAmp;
  struct ScriptSymbol *_RotateFreq;
};

struct Wz4RenderAnimMultiply
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaMultiply *para);

  struct ScriptSymbol *_PreScale;
  struct ScriptSymbol *_PreRot;
  struct ScriptSymbol *_PreTrans;
  struct ScriptSymbol *_Count;
  struct ScriptSymbol *_Scale;
  struct ScriptSymbol *_Rot;
  struct ScriptSymbol *_Trans;
};

struct Wz4RenderAnimClip
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaClip *para);

  struct ScriptSymbol *_Enable;
};

struct Wz4RenderAnimClipRandomizer
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaClipRandomizer *para);

  struct ScriptSymbol *_Enable;
};

struct Wz4RenderAnimClipRandDuration
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaClipRandDuration *para);

};

struct Wz4RenderAnimMultiClip
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaMultiClip *para);

  struct ScriptSymbol *_MasterEnable;
};

struct Wz4RenderAnimFader
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFader *para);

  struct ScriptSymbol *_FaderA;
  struct ScriptSymbol *_FaderB;
  struct ScriptSymbol *_RotorA;
  struct ScriptSymbol *_RotorB;
};

struct Wz4RenderAnimFader2
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaFader2 *para);

  struct ScriptSymbol *_FaderA;
  struct ScriptSymbol *_FaderB;
  struct ScriptSymbol *_RotorA;
  struct ScriptSymbol *_RotorB;
};

struct Wz4RenderAnimVariable
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaVariable *para);

};

struct Wz4RenderAnimSpline
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaSpline *para);

};

struct Wz4RenderAnimLayer2D
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaLayer2D *para);

  struct ScriptSymbol *_Center;
  struct ScriptSymbol *_Size;
  struct ScriptSymbol *_ScaleUV;
  struct ScriptSymbol *_ScrollUV;
  struct ScriptSymbol *_Color;
  struct ScriptSymbol *_ScaleUV2;
  struct ScriptSymbol *_ScrollUV2;
};

struct Wz4RenderAnimBeat
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBeat *para);

};

struct Wz4RenderAnimBoneTrain
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,Wz4RenderParaBoneTrain *para);

  struct ScriptSymbol *_LightEnv;
  struct ScriptSymbol *_Start;
  struct ScriptSymbol *_Length;
  struct ScriptSymbol *_UpVector;
  struct ScriptSymbol *_Twist;
  struct ScriptSymbol *_Twirl;
};

struct UnitTestAnimUnitTestWz4
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,UnitTestParaUnitTestWz4 *para);

};


/****************************************************************************/

void AddTypes_wz4_demo2_ops(sBool secondary=0);
void AddOps_wz4_demo2_ops(sBool secondary=0);

/****************************************************************************/

#endif

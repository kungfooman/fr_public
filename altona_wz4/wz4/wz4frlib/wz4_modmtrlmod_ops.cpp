/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#define sPEDANTIC_OBSOLETE 1
#define sPEDANTIC_WARN 1
#include "gui/gui.hpp"
#include "gui/textwindow.hpp"
#include "wz4lib/script.hpp"
#include "wz4_modmtrlmod_ops.hpp"

#pragma warning(disable:4189) // unused variables - happens in generated code


/****************************************************************************/


/****************************************************************************/

#line 15 "wz4_modmtrlmod_ops.ops"

#include "wz4frlib/wz4_modmtrlmod.hpp"

#line 26 "wz4_modmtrlmod_ops.cpp"

/****************************************************************************/

#line 772 "wz4_modmtrlmod_ops.ops"

  class MM_ShadowGrab : public MtrlModule
  {
  public:
    sInt Light;
	const sChar *VarName;
  
    MM_ShadowGrab()
    {
      Phase = MMP_TexLD;
      Name = L"ShadowGrab";
      Light = 0;
      VarName = 0;
    }

	void Start(ShaderCreator *sc)
	{
	  VarName = 0;
	}

	sPoolString Get(ShaderCreator *sc)
	{
	  if(VarName==0)
	  {
		VarName = sc->GetTemp();
		sc->FragBegin(Name);
		sc->FragFirst(VarName);
		sc->FragRead(L"lightshadow");
		sc->TB.PrintF(L"  float4 %s = lightshadow[%d];\n",VarName,Light);
		sc->FragEnd();
	  }
	  return sPoolString(VarName);
	}
  };

#line 66 "wz4_modmtrlmod_ops.cpp"

/****************************************************************************/

#line 833 "wz4_modmtrlmod_ops.ops"

  class MM_Tint : public MtrlModule
  {
  public:
    sInt Select;
    sVector30 Color;

    MM_Tint()
    {
      Phase = MMP_Post;
      Name = L"tint";
      Select = 0;
      Shaders = 2;
    }

    void PS(ShaderCreator *sc)
    {
      sc->FragBegin(Name);
      if(Select==0)
      {
        sc->TB.PrintF(L"o_color.xyz *= float3(%f,%f,%f);\n",Color.x,Color.y,Color.z);
      }
      else
      {
        sc->Para(sPoolF(L"Color%d",Select-1));
        sc->TB.PrintF(L"o_color.xyz *= Color%d;\n",Select-1);
      }
      sc->FragModify(L"o_color");
      sc->FragEnd();
    }
  };

#line 103 "wz4_modmtrlmod_ops.cpp"

/****************************************************************************/

#line 892 "wz4_modmtrlmod_ops.ops"

  class MM_Debug : public MtrlModule
  {
  public:
    sInt Debug;
    sInt Light;
    sF32 Bright;
    MM_Debug()
    {
      Phase = MMP_Shader;
      Name = L"debug";
      Debug = 0;
      Bright = 1;
      Shaders = 2;
    }

    void PS(ShaderCreator *sc)
    {
      if(Debug)
      {
        sc->FragBegin(Name);
        const sChar *bias = L"";
        if(Debug & 16)
          bias = L"*0.5+0.5";

        switch(Debug&15)
        {
        case 0:
          break;
        case 1: 
          sc->TB.PrintF(L"  o_color.xyz = ws_normal%s;\n",bias);
          sc->InputPS(L"ws_normal",SCT_FLOAT3);
          sc->FragModify(L"o_color");
          break;
        case 2: 
          sc->TB.PrintF(L"  o_color.xyz = ms_tangent%s;\n",bias);
          sc->InputPS(L"ms_tangent",SCT_FLOAT3);
          sc->FragModify(L"o_color");
          break;
        case 3: 
          sc->TB.PrintF(L"  o_color.xyz = ws_bitangent%s;\n",bias);
          sc->InputPS(L"ws_bitangent",SCT_FLOAT3);
          sc->FragModify(L"o_color");
          break;
        case 4:
          {
            sInt slot = sc->Texture(ModMtrlType->DummyTex2D,sMTF_LEVEL0|sMTF_TILE);
            sc->UpdateTex[slot].Enable = 1;
            sc->UpdateTex[slot].Light = Light;
            sc->UpdateTex[slot].Mode = MMRTM_DirShadow;
            sc->InputPS(L"uv0",SCT_FLOAT2);
//            sc->TB.PrintF(L"  o_color.xyz = %f*tex2D(tex%d,uv0).x;\n",Bright,slot);
            sc->TB.PrintF(L"  o_color.xyz = %f*%s;\n",Bright,Tex2D(slot,L"uv0",L"x",0));

            sc->FragModify(L"o_color");
          }
          break;        
        case 5:
          {
            sInt slot = sc->Texture(ModMtrlType->DummyTexCube,sMTF_LEVEL0|sMTF_TILE);
            sc->UpdateTex[slot].Enable = 1;
            sc->UpdateTex[slot].Light = Light;
            sc->UpdateTex[slot].Mode = MMRTM_PointShadow;
            sc->InputPS(L"ms_pos",SCT_FLOAT3);
            sc->TB.PrintF(L"  o_color.xyz = 1-(%f*(1/texCUBE(tex%d,ms_pos).x));\n",Bright,slot);

            sc->FragModify(L"o_color");
          }
          break;
        case 6: 
          sc->TB.PrintF(L"  o_color.xyz = ms_pos%s;\n",bias);
          sc->InputPS(L"ms_pos",SCT_FLOAT3);
          sc->FragModify(L"o_color");
          break;          
        case 7:
          sc->TB.PrintF(L"  o_color.xyz = float4(1,1,1,1,1);  // error on purpose\n");
          sc->FragModify(L"o_color");
          break;
        }
        sc->FragEnd();
      }
    }
  };

#line 192 "wz4_modmtrlmod_ops.cpp"

/****************************************************************************/

#line 1008 "wz4_modmtrlmod_ops.ops"

  class MM_SphereFog : public MtrlModule
  {
  public:
    sVector31 Center;
    sF32 Radius;
    sInt Flags;
    sInt VectorId;

    MM_SphereFog()
    {
      Phase = MMP_Post;
      Name = L"tint";
      Shaders = 2;

      Center.Init(0,0,0);
      Radius = 10;
      Flags = 0;
      VectorId = 0;
    }

    void PS(ShaderCreator *sc)
    {
      sc->FragBegin(Name);
      sc->FragModify(L"col_fog");
      sc->FragModify(L"fogfactor");
//            sc->FragModify(L"o_color");
      sc->InputPS(L"ws_pos",SCT_FLOAT3);
      sc->InputPS(L"ws_campos",SCT_FLOAT3);
      sc->Para(L"GroundFogAdd");        // FogAdd = -mindist
      sc->Para(L"GroundFogMul");        // FogMul = 1/maxdist
      sc->Para(L"GroundFogDensity");
      sc->Para(L"GroundFogColor");

      sc->TB.PrintF(L"  {\n");
      if((Flags&15)>=1)
      {
        sc->Para(sPoolF(L"Vector%d",VectorId&7));
        sc->TB.PrintF(L"    float radius = Vector%d.x;\n",VectorId&7);
      }
      else
      {
        sc->TB.PrintF(L"    float radius = %f;\n",Radius);
      }
      if((Flags&15)>=2)
      {
        sc->Para(sPoolF(L"Vector%d",(VectorId>>4)&7));
        sc->TB.PrintF(L"    float3 center = Vector%d.xyz;\n",(VectorId>>4)&7);
      }
      else
      {
        sc->TB.PrintF(L"    float3 center = float3(%f,%f,%f);\n",Center.x,Center.y,Center.z);
      }

      sc->TB.PrintF(L"    float3 d = ws_pos-ws_campos;\n");
      sc->TB.PrintF(L"    float a = dot(d,d);\n");
      sc->TB.PrintF(L"    float b = 2*dot(d,ws_campos-center);\n");
      sc->TB.PrintF(L"    float c = dot(center,center)+dot(ws_campos,ws_campos)\n");
      sc->TB.PrintF(L"            - 2*dot(center,ws_campos)-radius*radius;\n");
      sc->TB.PrintF(L"    float dis = b*b-4*a*c;\n");

      sc->TB.PrintF(L"    if(dis>0)\n");
      sc->TB.PrintF(L"    {\n");

      sc->TB.PrintF(L"      float fog1 = saturate((-b+sqrt(dis))/(2*a));\n");
      sc->TB.PrintF(L"      float fog0 = saturate((-b-sqrt(dis))/(2*a));\n");
      sc->TB.PrintF(L"      float fog = (fog1-fog0)*length(d);\n");
      sc->TB.PrintF(L"      \n");

      sc->TB.PrintF(L"      fog = saturate((fog+GroundFogAdd)*GroundFogMul);\n");
      sc->TB.PrintF(L"      fog = 3*fog*fog-2*fog*fog*fog;\n");
      sc->TB.PrintF(L"      fog = fog*GroundFogDensity;\n");
      sc->TB.PrintF(L"      fogfactor += fog;\n");
      sc->TB.PrintF(L"      col_fog += fog*GroundFogColor;\n");

      sc->TB.PrintF(L"    }\n");
      sc->TB.PrintF(L"  }\n");
      sc->FragEnd();
    }
  };

#line 278 "wz4_modmtrlmod_ops.cpp"

/****************************************************************************/


/****************************************************************************/

sBool ModShaderCmdFlat(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaFlat sUNUSED *para = (ModShaderParaFlat *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 42 "wz4_modmtrlmod_ops.ops"

    MM_Flat *mod = new MM_Flat;
    mod->Color.InitColor(para->Color);
    out->Add(mod);
  ;
#line 298 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiFlat(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaFlat sUNUSED *para = (ModShaderParaFlat *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgb",0);
}

void ModShaderDefFlat(wOp *op)
{
  ModShaderParaFlat sUNUSED *para = (ModShaderParaFlat *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0x00ffffff;
}

void ModShaderBindFlat(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
}
void ModShaderBind2Flat(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"color_");
  }
  ctx->AddImport(name[0],ScriptTypeColor,1,cmd->Data+0);
}
void ModShaderBind3Flat(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
}
const sChar *ModShaderWikiFlat =
L"= ModShader : Flat\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Flat\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdLambert(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaLambert sUNUSED *para = (ModShaderParaLambert *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 62 "wz4_modmtrlmod_ops.ops"

    MM_Lambert *mod = new MM_Lambert;
    mod->LightFlags = para->Light;
    out->Add(mod);
  ;
#line 392 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiLambert(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaLambert sUNUSED *para = (ModShaderParaLambert *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Light");
  gh.Flags(&para->Light,L"-|Front:*1-|Middle:*2-|Back",gh.ChangeMsg);
}

void ModShaderDefLambert(wOp *op)
{
  ModShaderParaLambert sUNUSED *para = (ModShaderParaLambert *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Light = 0x00000007;
}

void ModShaderBindLambert(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Lambert(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"light");
  }
}
void ModShaderBind3Lambert(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiLambert =
L"= ModShader : Lambert\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Lambert\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Light\n"
L" !i Light\n"
L" !i Front\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Middle\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Back\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdPhong(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaPhong sUNUSED *para = (ModShaderParaPhong *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 92 "wz4_modmtrlmod_ops.ops"

    MM_Phong *mod = new MM_Phong;
    mod->Specular = para->Specular;
    mod->Transpar = para->Transparency;
    mod->LightFlags = para->Light;
    mod->TextureFlags = para->UseTexture;
    mod->SpecularityMap = para->SpecularityMap;
    mod->TransparencyMap = para->TransparencyMap;
    if(in0)
      mod->Tex = in0->Modules[0];
    out->Add(in0);
    out->Add(mod);
  ;
#line 507 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiPhong(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaPhong sUNUSED *para = (ModShaderParaPhong *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Specular");
  sFloatControl *float_Specular = gh.Float(&para->Specular,0.000000f,128.0000f,0.010000f);
  float_Specular->Default = 32.00000f; float_Specular->RightStep = 0.125000f;

  gh.Label(L"Transparency");
  sFloatControl *float_Transparency = gh.Float(&para->Transparency,0.000000f,1.000000f,0.005000f);
  float_Transparency->Default = 1.000000f; float_Transparency->RightStep = 0.125000f;

  gh.Label(L"Light");
  gh.Flags(&para->Light,L"-|Front:*1-|Middle:*2-|Back:*3-|Specular",gh.ChangeMsg);

  if((op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"UseTexture");
    gh.Flags(&para->UseTexture,L"*0-|Specularity:*1-|Transparency:*2-|Color (rgb)",gh.LayoutMsg);

  }
  if(((op->ConnectionMask & (1<<0))!=0&&(para->UseTexture&0x0001)))
  {
    gh.Label(L"SpecularityMap");
    gh.Flags(&para->SpecularityMap,L"r|g|b|a",gh.ChangeMsg);

  }
  if(((op->ConnectionMask & (1<<0))!=0&&(para->UseTexture&0x0002)))
  {
    gh.Label(L"TransparencyMap");
    gh.Flags(&para->TransparencyMap,L"r|g|b|a",gh.ChangeMsg);
  }
}

void ModShaderDefPhong(wOp *op)
{
  ModShaderParaPhong sUNUSED *para = (ModShaderParaPhong *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Specular = 32.00000f;
  para->Transparency = 1.000000f;
  para->Light = 0x0000000f;
  para->UseTexture = 0x00000001;
  para->SpecularityMap = 0x00000003;
  para->TransparencyMap = 0x00000003;
}

void ModShaderBindPhong(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"specular"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"transparency"),val);
}
void ModShaderBind2Phong(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[6];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"specular");
    name[1] = sPoolString(L"transparency");
    name[2] = sPoolString(L"light");
    name[3] = sPoolString(L"usetexture");
    name[4] = sPoolString(L"specularitymap");
    name[5] = sPoolString(L"transparencymap");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+5);
}
void ModShaderBind3Phong(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import specular : float;\n");
  tb.PrintF(L"  import transparency : float;\n");
}
const sChar *ModShaderWikiPhong =
L"= ModShader : Phong\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Phong\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i optional\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Specular\n"
L" !i Specular\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Transparency\n"
L" !i Transparency\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Light\n"
L" !i Light\n"
L" !i Front\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Middle\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Back\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Specular\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UseTexture\n"
L" !i UseTexture\n"
L" !i Specularity\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Transparency\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Color (rgb)\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SpecularityMap\n"
L" !i SpecularityMap\n"
L" !i r\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i g\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i b\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i TransparencyMap\n"
L" !i TransparencyMap\n"
L" !i r\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i g\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i b\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdRim(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaRim sUNUSED *para = (ModShaderParaRim *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 122 "wz4_modmtrlmod_ops.ops"

    MM_Rim *mod = new MM_Rim;
    mod->Flags = para->Flags;
    mod->Width = para->Width;
    mod->Color.InitColor(para->Color);
    mod->Shadow = para->Shadow;
    out->Add(mod);
  ;
#line 751 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiRim(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaRim sUNUSED *para = (ModShaderParaRim *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"linear|smoothstep:*1emissive|diffuse",gh.ChangeMsg);

  gh.Label(L"Width");
  sFloatControl *float_Width = gh.Float(&para->Width,0.000000f,1.000000f,0.010000f);
  float_Width->Default = 0.500000f; float_Width->RightStep = 0.125000f;

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgb",0);

  gh.ControlWidth = 1;
  gh.Label(L"React to Shadow");
  gh.Flags(&para->Shadow,L"*0 -| 0:*1 -| 1:*2 -| 2:*3 -| 3:*4 -| 4:*5 -| 5:*6 -| 6:*7 -| 7",gh.ChangeMsg);
  gh.ControlWidth = 2;
}

void ModShaderDefRim(wOp *op)
{
  ModShaderParaRim sUNUSED *para = (ModShaderParaRim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x00000001;
  para->Width = 0.500000f;
  para->Color = 0x00ffffff;
}

void ModShaderBindRim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"width"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
}
void ModShaderBind2Rim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"width");
    name[2] = sPoolString(L"color_");
    name[3] = sPoolString(L"shadow");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeColor,1,cmd->Data+2);
}
void ModShaderBind3Rim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import width : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
}
const sChar *ModShaderWikiRim =
L"= ModShader : Rim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Rim\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i linear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i smoothstep\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i emissive\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i diffuse\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Width\n"
L" !i Width\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i React to Shadow\n"
L" !i Shadow\n"
L" !i 0\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdComic(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaComic sUNUSED *para = (ModShaderParaComic *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 144 "wz4_modmtrlmod_ops.ops"

    MM_Comic *mod = new MM_Comic;
    mod->Mode = para->Mode;
    mod->Tex = in0;  in0->AddRef();
    out->Add(mod);
  ;
#line 965 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiComic(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaComic sUNUSED *para = (ModShaderParaComic *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"-|Phong",gh.ChangeMsg);
}

void ModShaderDefComic(wOp *op)
{
  ModShaderParaComic sUNUSED *para = (ModShaderParaComic *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Mode = 0x00000001;
}

void ModShaderBindComic(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Comic(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
  }
}
void ModShaderBind3Comic(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiComic =
L"= ModShader : Comic\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Comic\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i Phong\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdBlinnPhong(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaBlinnPhong sUNUSED *para = (ModShaderParaBlinnPhong *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 167 "wz4_modmtrlmod_ops.ops"

    MM_BlinnPhong *mod = new MM_BlinnPhong;
    mod->Specular = para->Specular;
    mod->LightFlags = para->Light;
    mod->SpecularityMap = para->SpecularityMap;
    if(in0)
      mod->Tex = in0->Modules[0];
    out->Add(in0);
    out->Add(mod);
  ;
#line 1071 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiBlinnPhong(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaBlinnPhong sUNUSED *para = (ModShaderParaBlinnPhong *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Specular");
  sFloatControl *float_Specular = gh.Float(&para->Specular,0.000000f,128.0000f,0.010000f);
  float_Specular->Default = 32.00000f; float_Specular->RightStep = 0.125000f;

  gh.Label(L"Light");
  gh.Flags(&para->Light,L"-|Front:*1-|Middle:*2-|Back:*3-|Specular",gh.ChangeMsg);

  if((op->ConnectionMask & (1<<0))!=0)
  {
    gh.Label(L"SpecularityMap");
    gh.Flags(&para->SpecularityMap,L"r|g|b|a",gh.ChangeMsg);
  }
}

void ModShaderDefBlinnPhong(wOp *op)
{
  ModShaderParaBlinnPhong sUNUSED *para = (ModShaderParaBlinnPhong *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Specular = 32.00000f;
  para->Light = 0x0000000f;
  para->SpecularityMap = 0x00000003;
}

void ModShaderBindBlinnPhong(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"specular"),val);
}
void ModShaderBind2BlinnPhong(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"specular");
    name[1] = sPoolString(L"light");
    name[2] = sPoolString(L"specularitymap");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,1,cmd->Data+0);
}
void ModShaderBind3BlinnPhong(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import specular : float;\n");
}
const sChar *ModShaderWikiBlinnPhong =
L"= ModShader : BlinnPhong\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BlinnPhong\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i optional\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Specular\n"
L" !i Specular\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Light\n"
L" !i Light\n"
L" !i Front\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Middle\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Back\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Specular\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SpecularityMap\n"
L" !i SpecularityMap\n"
L" !i r\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i g\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i b\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdTex2D(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaTex2D sUNUSED *para = (ModShaderSamplerParaTex2D *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 207 "wz4_modmtrlmod_ops.ops"

    MM_Tex2D *mod = new MM_Tex2D;
    mod->Flags = sConvertOldUvFlags(para->Flags&~0x40000000);
    mod->UV = para->UV;
    mod->Transform = para->Transform;
    mod->Aux = para->Aux;
    mod->SimpleScale = para->SimpleScale;
    mod->Scale = para->Scale;
    mod->Rot = para->Rot;
    mod->Trans = para->Trans;    
    mod->Texture = in0; in0->AddRef();    
    if(para->Flags & 0x40000000)
      mod->Rot *= 1.0f/sPI2F;
    out->Add(mod);
  ;
#line 1251 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiTex2D(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaTex2D sUNUSED *para = (ModShaderSamplerParaTex2D *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white:*30old buggy rotation|-",gh.LayoutMsg);

  gh.Label(L"UV");
  gh.Flags(&para->UV,L"uv0|uv1|model|world|camera|envi-sphere|envi-reflect|envi-sphere (per pixel)|envi-reflect (per pixel)",gh.LayoutMsg);

  gh.Label(L"Transform");
  gh.Flags(&para->Transform,L"-|Scale|Matrix| 0 LightEnv Matrix 0| 1 LightEnv Matrix 1| 2 LightEnv Matrix 2| 3 LightEnv Matrix 3",gh.LayoutMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.LayoutMsg);

  if((para->Transform==0x0001))
  {
    gh.Label(L"SimpleScale");
    sFloatControl *float_SimpleScale = gh.Float(&para->SimpleScale,-1024.00f,1024.000f,0.010000f);
    float_SimpleScale->Default = 1.000000f; float_SimpleScale->RightStep = 0.125000f;

  }
  if((para->Transform==0x0002))
  {
    gh.Label(L"Scale");
    gh.BeginTied();
    sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
    float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
    float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
    sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
    float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Rot");
    gh.BeginTied();
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
    float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Trans");
    gh.BeginTied();
    sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
    float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
    float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
    sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
    float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
    gh.EndTied();
  }
}

void ModShaderSamplerDefTex2D(wOp *op)
{
  ModShaderSamplerParaTex2D sUNUSED *para = (ModShaderSamplerParaTex2D *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Flags = 0x40000000;
  para->SimpleScale = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void ModShaderSamplerBindTex2D(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"simplescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
}
void ModShaderSamplerBind2Tex2D(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[8];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"uv");
    name[2] = sPoolString(L"transform");
    name[3] = sPoolString(L"aux");
    name[4] = sPoolString(L"simplescale");
    name[5] = sPoolString(L"scale");
    name[6] = sPoolString(L"rot");
    name[7] = sPoolString(L"trans");
  }
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[5],ScriptTypeFloat,3,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+11);
}
void ModShaderSamplerBind3Tex2D(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import simplescale : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *ModShaderSamplerWikiTex2D =
L"= ModShaderSampler : Tex2D\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Tex2D\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bilinear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mirror\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_black\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_white\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i old buggy rotation\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UV\n"
L" !i UV\n"
L" !i uv0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uv1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i world\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i camera\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-reflect\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-sphere (per pixel)\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-reflect (per pixel)\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Transform\n"
L" !i Transform\n"
L" !i Scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Matrix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 0 LightEnv Matrix 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1 LightEnv Matrix 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2 LightEnv Matrix 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3 LightEnv Matrix 3\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SimpleScale\n"
L" !i SimpleScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdTex2DAnim(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaTex2DAnim sUNUSED *para = (ModShaderSamplerParaTex2DAnim *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 249 "wz4_modmtrlmod_ops.ops"

    MM_Tex2DAnim *mod = new MM_Tex2DAnim;
    mod->Flags = para->Flags;
    mod->UV = para->UV;
    mod->Transform = para->Transform;
    mod->Aux = para->Aux;
    mod->SimpleScale = para->SimpleScale;
    mod->Scale = para->Scale;
    mod->Rot = para->Rot;
    mod->Trans = para->Trans;
    mod->AtlasAnim = para->AtlasAnim;
    mod->Texture = in0; in0->AddRef();
    out->Add(mod);
  ;
#line 1606 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiTex2DAnim(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaTex2DAnim sUNUSED *para = (ModShaderSamplerParaTex2DAnim *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0trilinear|aniso|point|bilinear",gh.LayoutMsg);

  gh.Label(L"UV");
  gh.Flags(&para->UV,L"uv0|uv1|model|world|camera|envi-sphere|envi-reflect|envi-sphere (per pixel)|envi-reflect (per pixel)",gh.LayoutMsg);

  gh.Label(L"Transform");
  gh.Flags(&para->Transform,L"-|Scale|Matrix| 0 LightEnv Matrix 0| 1 LightEnv Matrix 1| 2 LightEnv Matrix 2| 3 LightEnv Matrix 3",gh.LayoutMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.LayoutMsg);

  gh.Label(L"AtlasAnim");
  gh.Flags(&para->AtlasAnim,L"Vector0|Vector1|Vector2|Vector3|Vector4|Vector5|Vector6|Vector7",gh.ChangeMsg);

  if((para->Transform==0x0001))
  {
    gh.Label(L"SimpleScale");
    sFloatControl *float_SimpleScale = gh.Float(&para->SimpleScale,-1024.00f,1024.000f,0.010000f);
    float_SimpleScale->Default = 1.000000f; float_SimpleScale->RightStep = 0.125000f;

  }
  if((para->Transform==0x0002))
  {
    gh.Label(L"Scale");
    gh.BeginTied();
    sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
    float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
    float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
    sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
    float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Rot");
    gh.BeginTied();
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
    float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Trans");
    gh.BeginTied();
    sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
    float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
    float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
    sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
    float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
    gh.EndTied();
  }
}

void ModShaderSamplerDefTex2DAnim(wOp *op)
{
  ModShaderSamplerParaTex2DAnim sUNUSED *para = (ModShaderSamplerParaTex2DAnim *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->SimpleScale = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
}

void ModShaderSamplerBindTex2DAnim(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"simplescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+12;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
}
void ModShaderSamplerBind2Tex2DAnim(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[9];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"uv");
    name[2] = sPoolString(L"transform");
    name[3] = sPoolString(L"aux");
    name[4] = sPoolString(L"atlasanim");
    name[5] = sPoolString(L"simplescale");
    name[6] = sPoolString(L"scale");
    name[7] = sPoolString(L"rot");
    name[8] = sPoolString(L"trans");
  }
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+12);
}
void ModShaderSamplerBind3Tex2DAnim(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import simplescale : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
}
const sChar *ModShaderSamplerWikiTex2DAnim =
L"= ModShaderSampler : Tex2DAnim\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Tex2DAnim\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bilinear\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i UV\n"
L" !i UV\n"
L" !i uv0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i uv1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i world\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i camera\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-sphere\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-reflect\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-sphere (per pixel)\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i envi-reflect (per pixel)\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Transform\n"
L" !i Transform\n"
L" !i Scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Matrix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 0 LightEnv Matrix 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1 LightEnv Matrix 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2 LightEnv Matrix 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3 LightEnv Matrix 3\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i AtlasAnim\n"
L" !i AtlasAnim\n"
L" !i Vector0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SimpleScale\n"
L" !i SimpleScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdTex2DSurround(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaTex2DSurround sUNUSED *para = (ModShaderSamplerParaTex2DSurround *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 295 "wz4_modmtrlmod_ops.ops"

    MM_Tex2DSurround *mod = new MM_Tex2DSurround;
    mod->Flags = sConvertOldUvFlags(para->Flags);
    mod->Aux = para->Aux;
    mod->Space = para->CoordinateSystem;
    mod->SimpleScale = para->SimpleScale;
    mod->Scale = para->Scale;
    mod->Rot = para->Rot;
    mod->Trans = para->Trans;
    mod->Transform = para->Transform;
    mod->MajorAxis = para->MajorAxis;
    mod->Texture = in0; in0->AddRef();
    out->Add(mod);
  ;
#line 1963 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiTex2DSurround(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaTex2DSurround sUNUSED *para = (ModShaderSamplerParaTex2DSurround *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.LayoutMsg);

  gh.Label(L"CoordinateSystem");
  gh.Flags(&para->CoordinateSystem,L"world|model post skin|model pre skin",gh.LayoutMsg);

  gh.Label(L"Flags");
  gh.Flags(&para->CoordinateSystem,L"*4-|Major Axis",gh.LayoutMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.LayoutMsg);

  gh.Label(L"Transform");
  gh.Flags(&para->Transform,L"-|Scale|Matrix| 0 LightEnv Matrix 0| 1 LightEnv Matrix 1| 2 LightEnv Matrix 2| 3 LightEnv Matrix 3",gh.LayoutMsg);

  if((para->Transform==0x0001))
  {
    gh.Label(L"SimpleScale");
    sFloatControl *float_SimpleScale = gh.Float(&para->SimpleScale,-1024.00f,1024.000f,0.010000f);
    float_SimpleScale->Default = 1.000000f; float_SimpleScale->RightStep = 0.125000f;

  }
  if((para->Transform==0x0002))
  {
    gh.Label(L"Scale");
    gh.BeginTied();
    sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
    float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
    float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
    sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
    float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Rot");
    gh.BeginTied();
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
    float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Trans");
    gh.BeginTied();
    sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
    float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
    float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
    sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
    float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->CoordinateSystem&0x0010))
  {
    gh.Label(L"MajorAxis");
    gh.BeginTied();
    sFloatControl *float_MajorAxis_0 = gh.Float(&para->MajorAxis.x,-1024.00f,1024.000f,0.125000f);
    float_MajorAxis_0->Default = 1.000000f; float_MajorAxis_0->RightStep = 0.125000f;
    sFloatControl *float_MajorAxis_1 = gh.Float(&para->MajorAxis.y,-1024.00f,1024.000f,0.125000f);
    float_MajorAxis_1->Default = 1.000000f; float_MajorAxis_1->RightStep = 0.125000f;
    sFloatControl *float_MajorAxis_2 = gh.Float(&para->MajorAxis.z,-1024.00f,1024.000f,0.125000f);
    float_MajorAxis_2->Default = 1.000000f; float_MajorAxis_2->RightStep = 0.125000f;
    gh.EndTied();
  }
}

void ModShaderSamplerDefTex2DSurround(wOp *op)
{
  ModShaderSamplerParaTex2DSurround sUNUSED *para = (ModShaderSamplerParaTex2DSurround *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->CoordinateSystem = 0x00000002;
  para->SimpleScale = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->MajorAxis.x = 1.000000f;
  para->MajorAxis.y = 1.000000f;
  para->MajorAxis.z = 1.000000f;
}

void ModShaderSamplerBindTex2DSurround(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"simplescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"majoraxis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"majoraxis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"majoraxis"),val);
}
void ModShaderSamplerBind2Tex2DSurround(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"coordinatesystem");
    name[2] = sPoolString(L"flags");
    name[3] = sPoolString(L"aux");
    name[4] = sPoolString(L"transform");
    name[5] = sPoolString(L"simplescale");
    name[6] = sPoolString(L"scale");
    name[7] = sPoolString(L"rot");
    name[8] = sPoolString(L"trans");
    name[9] = sPoolString(L"majoraxis");
  }
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+14);
}
void ModShaderSamplerBind3Tex2DSurround(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import simplescale : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import majoraxis : float[3];\n");
}
const sChar *ModShaderSamplerWikiTex2DSurround =
L"= ModShaderSampler : Tex2DSurround\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Tex2DSurround\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bilinear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mirror\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_black\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_white\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CoordinateSystem\n"
L" !i CoordinateSystem\n"
L" !i world\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model post skin\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model pre skin\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i CoordinateSystem\n"
L" !i Major Axis\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Transform\n"
L" !i Transform\n"
L" !i Scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Matrix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 0 LightEnv Matrix 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1 LightEnv Matrix 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2 LightEnv Matrix 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3 LightEnv Matrix 3\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SimpleScale\n"
L" !i SimpleScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i MajorAxis\n"
L" !i MajorAxis\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdTex2DSurroundNormal(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaTex2DSurroundNormal sUNUSED *para = (ModShaderParaTex2DSurroundNormal *)(cmd->Data); para;
  Texture2D sUNUSED *in0 = cmd->GetInput<Texture2D *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 340 "wz4_modmtrlmod_ops.ops"

    MM_Tex2DSurroundNormal *mod = new MM_Tex2DSurroundNormal;
    mod->Flags = sConvertOldUvFlags(para->Flags);
    mod->Space = para->CoordinateSystem;
    mod->SimpleScale = para->SimpleScale;
    mod->Scale = para->Scale;
    mod->Rot = para->Rot;
    mod->Trans = para->Trans;
    mod->Transform = para->Transform;
    mod->MajorAxis = para->MajorAxis;
    mod->Texture = in0; in0->AddRef();
    out->Add(mod);
  ;
#line 2326 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiTex2DSurroundNormal(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaTex2DSurroundNormal sUNUSED *para = (ModShaderParaTex2DSurroundNormal *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Flags");
  gh.Flags(&para->Flags,L"*0trilinear|aniso|point|bilinear:*4tile|clamp|mirror|border_black|border_white",gh.LayoutMsg);

  gh.Label(L"CoordinateSystem");
  gh.Flags(&para->CoordinateSystem,L"world|model post skin|model pre skin",gh.LayoutMsg);

  gh.Label(L"Flags");
  gh.Flags(&para->CoordinateSystem,L"*4-|Major Axis",gh.LayoutMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.LayoutMsg);

  gh.Label(L"Transform");
  gh.Flags(&para->Transform,L"-|Scale|Matrix",gh.LayoutMsg);

  if((para->Transform==0x0001))
  {
    gh.Label(L"SimpleScale");
    sFloatControl *float_SimpleScale = gh.Float(&para->SimpleScale,-1024.00f,1024.000f,0.010000f);
    float_SimpleScale->Default = 1.000000f; float_SimpleScale->RightStep = 0.125000f;

  }
  if((para->Transform==0x0002))
  {
    gh.Label(L"Scale");
    gh.BeginTied();
    sFloatControl *float_Scale_0 = gh.Float(&para->Scale.x,-1024.00f,1024.000f,0.010000f);
    float_Scale_0->Default = 1.000000f; float_Scale_0->RightStep = 0.125000f;
    sFloatControl *float_Scale_1 = gh.Float(&para->Scale.y,-1024.00f,1024.000f,0.010000f);
    float_Scale_1->Default = 1.000000f; float_Scale_1->RightStep = 0.125000f;
    sFloatControl *float_Scale_2 = gh.Float(&para->Scale.z,-1024.00f,1024.000f,0.010000f);
    float_Scale_2->Default = 1.000000f; float_Scale_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Rot");
    gh.BeginTied();
    sFloatControl *float_Rot_0 = gh.Float(&para->Rot.x,-16.0000f,16.00000f,0.001000f);
    float_Rot_0->Default = 0.000000f; float_Rot_0->RightStep = 0.125000f;
    sFloatControl *float_Rot_1 = gh.Float(&para->Rot.y,-16.0000f,16.00000f,0.001000f);
    float_Rot_1->Default = 0.000000f; float_Rot_1->RightStep = 0.125000f;
    sFloatControl *float_Rot_2 = gh.Float(&para->Rot.z,-16.0000f,16.00000f,0.001000f);
    float_Rot_2->Default = 0.000000f; float_Rot_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"Trans");
    gh.BeginTied();
    sFloatControl *float_Trans_0 = gh.Float(&para->Trans.x,-1024.00f,1024.000f,0.010000f);
    float_Trans_0->Default = 0.000000f; float_Trans_0->RightStep = 0.125000f;
    sFloatControl *float_Trans_1 = gh.Float(&para->Trans.y,-1024.00f,1024.000f,0.010000f);
    float_Trans_1->Default = 0.000000f; float_Trans_1->RightStep = 0.125000f;
    sFloatControl *float_Trans_2 = gh.Float(&para->Trans.z,-1024.00f,1024.000f,0.010000f);
    float_Trans_2->Default = 0.000000f; float_Trans_2->RightStep = 0.125000f;
    gh.EndTied();

  }
  if((para->CoordinateSystem&0x0010))
  {
    gh.Label(L"MajorAxis");
    gh.BeginTied();
    sFloatControl *float_MajorAxis_0 = gh.Float(&para->MajorAxis.x,-1024.00f,1024.000f,0.125000f);
    float_MajorAxis_0->Default = 1.000000f; float_MajorAxis_0->RightStep = 0.125000f;
    sFloatControl *float_MajorAxis_1 = gh.Float(&para->MajorAxis.y,-1024.00f,1024.000f,0.125000f);
    float_MajorAxis_1->Default = 1.000000f; float_MajorAxis_1->RightStep = 0.125000f;
    sFloatControl *float_MajorAxis_2 = gh.Float(&para->MajorAxis.z,-1024.00f,1024.000f,0.125000f);
    float_MajorAxis_2->Default = 1.000000f; float_MajorAxis_2->RightStep = 0.125000f;
    gh.EndTied();
  }
}

void ModShaderDefTex2DSurroundNormal(wOp *op)
{
  ModShaderParaTex2DSurroundNormal sUNUSED *para = (ModShaderParaTex2DSurroundNormal *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->CoordinateSystem = 0x00000002;
  para->Transform = 0x00000001;
  para->SimpleScale = 1.000000f;
  para->Scale.x = 1.000000f;
  para->Scale.y = 1.000000f;
  para->Scale.z = 1.000000f;
  para->MajorAxis.x = 1.000000f;
  para->MajorAxis.y = 1.000000f;
  para->MajorAxis.z = 1.000000f;
}

void ModShaderBindTex2DSurroundNormal(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"simplescale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"rot"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+9;
  ctx->BindLocal(ctx->AddSymbol(L"trans"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"majoraxis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"majoraxis"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+14;
  ctx->BindLocal(ctx->AddSymbol(L"majoraxis"),val);
}
void ModShaderBind2Tex2DSurroundNormal(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"flags");
    name[1] = sPoolString(L"coordinatesystem");
    name[2] = sPoolString(L"flags");
    name[3] = sPoolString(L"aux");
    name[4] = sPoolString(L"transform");
    name[5] = sPoolString(L"simplescale");
    name[6] = sPoolString(L"scale");
    name[7] = sPoolString(L"rot");
    name[8] = sPoolString(L"trans");
    name[9] = sPoolString(L"majoraxis");
  }
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+2);
  ctx->AddImport(name[6],ScriptTypeFloat,3,cmd->Data+3);
  ctx->AddImport(name[7],ScriptTypeFloat,3,cmd->Data+6);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+9);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+14);
}
void ModShaderBind3Tex2DSurroundNormal(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import simplescale : float;\n");
  tb.PrintF(L"  import scale : float[3];\n");
  tb.PrintF(L"  import rot : float[3];\n");
  tb.PrintF(L"  import trans : float[3];\n");
  tb.PrintF(L"  import majoraxis : float[3];\n");
}
const sChar *ModShaderWikiTex2DSurroundNormal =
L"= ModShader : Tex2DSurroundNormal\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Tex2DSurroundNormal\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Texture2D\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i Flags\n"
L" !i trilinear\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i aniso\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bilinear\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i tile\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i clamp\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mirror\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_black\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i border_white\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CoordinateSystem\n"
L" !i CoordinateSystem\n"
L" !i world\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model post skin\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i model pre skin\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Flags\n"
L" !i CoordinateSystem\n"
L" !i Major Axis\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Transform\n"
L" !i Transform\n"
L" !i Scale\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Matrix\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i SimpleScale\n"
L" !i SimpleScale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Rot\n"
L" !i Rot\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Trans\n"
L" !i Trans\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i MajorAxis\n"
L" !i MajorAxis\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdConst(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaConst sUNUSED *para = (ModShaderSamplerParaConst *)(cmd->Data); para;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 373 "wz4_modmtrlmod_ops.ops"

    MM_Const *mod = new MM_Const;
    mod->Source = para->Source;
    mod->Color.InitColor(para->Color,para->Amp);
    out->Add(mod);
  ;
#line 2666 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiConst(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaConst sUNUSED *para = (ModShaderSamplerParaConst *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Source");
  gh.Flags(&para->Source,L"here|env 0|env 1|env 2|env 3|env 4|env 5|env 6|env 7|vertex0|vertex1|instance|depth|shellextrude",gh.LayoutMsg);

  if((para->Source==0x0000))
  {
    gh.Label(L"Color");
    gh.ColorPick(&para->Color,L"rgba",0);

    sFloatControl *float_Amp = gh.Float(&para->Amp,-1024.00f,1024.000f,0.010000f);
    float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;
  }
}

void ModShaderSamplerDefConst(wOp *op)
{
  ModShaderSamplerParaConst sUNUSED *para = (ModShaderSamplerParaConst *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Amp = 1.000000f;
}

void ModShaderSamplerBindConst(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
}
void ModShaderSamplerBind2Const(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"source");
    name[1] = sPoolString(L"color_");
    name[2] = sPoolString(L"amp");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void ModShaderSamplerBind3Const(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import amp : float;\n");
}
const sChar *ModShaderSamplerWikiConst =
L"= ModShaderSampler : Const\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Const\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Source\n"
L" !i Source\n"
L" !i here\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i env 7\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i vertex0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i vertex1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i instance\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i depth\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shellextrude\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdTrickLight(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaTrickLight sUNUSED *para = (ModShaderSamplerParaTrickLight *)(cmd->Data); para;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 394 "wz4_modmtrlmod_ops.ops"

    MM_TrickLight *mod = new MM_TrickLight;
    mod->LightFlags = para->Light;
    mod->LightEnable = para->Enable;
    out->Add(mod);
  ;
#line 2840 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiTrickLight(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaTrickLight sUNUSED *para = (ModShaderSamplerParaTrickLight *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Light");
  gh.Flags(&para->Light,L"-|Front:*1-|Middle:*2-|Back",gh.ChangeMsg);

  gh.ControlWidth = 1;
  gh.Label(L"Enable");
  gh.Flags(&para->Enable,L"-| 0:*1-| 1:*2-| 2:*3-| 3:*4-| 4:*5-| 5:*6-| 6:*7-| 7",gh.ChangeMsg);
  gh.ControlWidth = 2;
}

void ModShaderSamplerDefTrickLight(wOp *op)
{
  ModShaderSamplerParaTrickLight sUNUSED *para = (ModShaderSamplerParaTrickLight *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Light = 0x00000007;
}

void ModShaderSamplerBindTrickLight(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind2TrickLight(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"light");
    name[1] = sPoolString(L"enable");
  }
}
void ModShaderSamplerBind3TrickLight(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderSamplerWikiTrickLight =
L"= ModShaderSampler : TrickLight\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i TrickLight\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Light\n"
L" !i Light\n"
L" !i Front\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Middle\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i Back\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Enable\n"
L" !i Enable\n"
L" !i 0\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdMul(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaMul sUNUSED *para = (ModShaderSamplerParaMul *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 410 "wz4_modmtrlmod_ops.ops"

    MM_Math *mod = new MM_Math;
    mod->Mode = 0;
    out->Add(mod);
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      ModShaderSampler *in = cmd->GetInput<ModShaderSampler*>(i);
      mod->Inputs.AddTail(in->Modules[0]);
      out->Add(in);
    }
  ;
#line 3027 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiMul(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaMul sUNUSED *para = (ModShaderSamplerParaMul *)(op->EditData); para;
}

void ModShaderSamplerDefMul(wOp *op)
{
  ModShaderSamplerParaMul sUNUSED *para = (ModShaderSamplerParaMul *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderSamplerBindMul(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind2Mul(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind3Mul(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderSamplerWikiMul =
L"= ModShaderSampler : Mul\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Mul\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i multiple\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdAdd(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaAdd sUNUSED *para = (ModShaderSamplerParaAdd *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 429 "wz4_modmtrlmod_ops.ops"

    MM_Math *mod = new MM_Math;
    mod->Mode = 1;
    out->Add(mod);
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      ModShaderSampler *in = cmd->GetInput<ModShaderSampler*>(i);
      mod->Inputs.AddTail(in->Modules[0]);
      out->Add(in);
    }
  ;
#line 3107 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiAdd(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaAdd sUNUSED *para = (ModShaderSamplerParaAdd *)(op->EditData); para;
}

void ModShaderSamplerDefAdd(wOp *op)
{
  ModShaderSamplerParaAdd sUNUSED *para = (ModShaderSamplerParaAdd *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderSamplerBindAdd(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind2Add(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind3Add(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderSamplerWikiAdd =
L"= ModShaderSampler : Add\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Add\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i multiple\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdSub(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaSub sUNUSED *para = (ModShaderSamplerParaSub *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 448 "wz4_modmtrlmod_ops.ops"

    MM_Math *mod = new MM_Math;
    mod->Mode = 2;
    out->Add(mod);
    for(sInt i=0;i<cmd->InputCount;i++)
    {
      ModShaderSampler *in = cmd->GetInput<ModShaderSampler*>(i);
      mod->Inputs.AddTail(in->Modules[0]);
      out->Add(in);
    }
  ;
#line 3187 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiSub(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaSub sUNUSED *para = (ModShaderSamplerParaSub *)(op->EditData); para;
}

void ModShaderSamplerDefSub(wOp *op)
{
  ModShaderSamplerParaSub sUNUSED *para = (ModShaderSamplerParaSub *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderSamplerBindSub(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind2Sub(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderSamplerBind3Sub(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderSamplerWikiSub =
L"= ModShaderSampler : Sub\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Sub\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i multiple\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdDiffuse(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaDiffuse sUNUSED *para = (ModShaderParaDiffuse *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 476 "wz4_modmtrlmod_ops.ops"

    MM_ApplyTexture *mod = new MM_ApplyTexture;
    mod->Tex = in0->Modules[0];
    mod->Dest = L"col_diffuse";
    mod->Op = (para->Op&15);
    mod->Aux = para->Aux;
    mod->Swizzle = (para->Op&16)?L"w":L"xyz";
    out->Add(mod);
    out->Add(in0);
  ;
#line 3266 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiDiffuse(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaDiffuse sUNUSED *para = (ModShaderParaDiffuse *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Op");
  gh.Flags(&para->Op,L"add|mul|sub|mul2|mul4|screen|set:*4rgb|alpha",gh.ChangeMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.ChangeMsg);
}

void ModShaderDefDiffuse(wOp *op)
{
  ModShaderParaDiffuse sUNUSED *para = (ModShaderParaDiffuse *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Op = 0x00000001;
}

void ModShaderBindDiffuse(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Diffuse(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"op");
    name[1] = sPoolString(L"aux");
  }
}
void ModShaderBind3Diffuse(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiDiffuse =
L"= ModShader : Diffuse\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Diffuse\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Op\n"
L" !i Op\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i rgb\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdGloss(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaGloss sUNUSED *para = (ModShaderParaGloss *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 499 "wz4_modmtrlmod_ops.ops"

    MM_ApplyTexture *mod = new MM_ApplyTexture;
    mod->Tex = in0->Modules[0];
    mod->Dest = L"col_gloss";
    mod->Op = (para->Op&15);
    mod->Aux = para->Aux;
    mod->Swizzle = (para->Op&16)?L"w":L"xyz";
    out->Add(mod);
    out->Add(in0);
  ;
#line 3430 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiGloss(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaGloss sUNUSED *para = (ModShaderParaGloss *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Op");
  gh.Flags(&para->Op,L"add|mul|sub|mul2|mul4|screen|set:*4rgb|alpha",gh.ChangeMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.ChangeMsg);
}

void ModShaderDefGloss(wOp *op)
{
  ModShaderParaGloss sUNUSED *para = (ModShaderParaGloss *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Op = 0x00000001;
}

void ModShaderBindGloss(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Gloss(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"op");
    name[1] = sPoolString(L"aux");
  }
}
void ModShaderBind3Gloss(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiGloss =
L"= ModShader : Gloss\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Gloss\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Op\n"
L" !i Op\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i rgb\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdEmissive(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaEmissive sUNUSED *para = (ModShaderParaEmissive *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 522 "wz4_modmtrlmod_ops.ops"

    MM_ApplyTexture *mod = new MM_ApplyTexture;
    mod->Tex = in0->Modules[0];
    mod->Dest = L"col_emissive";
    mod->Op = (para->Op&15);
    mod->Aux = para->Aux;
    mod->Swizzle = (para->Op&16)?L"w":L"xyz";
    out->Add(mod);
    out->Add(in0);
  ;
#line 3594 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiEmissive(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaEmissive sUNUSED *para = (ModShaderParaEmissive *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Op");
  gh.Flags(&para->Op,L"add|mul|sub|mul2|mul4|screen|set:*4rgb|alpha",gh.ChangeMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.ChangeMsg);
}

void ModShaderDefEmissive(wOp *op)
{
  ModShaderParaEmissive sUNUSED *para = (ModShaderParaEmissive *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderBindEmissive(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Emissive(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"op");
    name[1] = sPoolString(L"aux");
  }
}
void ModShaderBind3Emissive(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiEmissive =
L"= ModShader : Emissive\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Emissive\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Op\n"
L" !i Op\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i rgb\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdSpecular(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaSpecular sUNUSED *para = (ModShaderParaSpecular *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 545 "wz4_modmtrlmod_ops.ops"

    MM_ApplyTexture *mod = new MM_ApplyTexture;
    mod->Tex = in0->Modules[0];
    mod->Dest = L"col_specular";
    mod->Op = (para->Op&15);
    mod->Aux = para->Aux;
    mod->Swizzle = (para->Op&16)?L"w":L"xyz";
    out->Add(mod);
    out->Add(in0);
  ;
#line 3757 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiSpecular(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaSpecular sUNUSED *para = (ModShaderParaSpecular *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Op");
  gh.Flags(&para->Op,L"add|mul|sub|mul2|mul4|screen|set:*4rgb|alpha",gh.ChangeMsg);

  gh.Label(L"Aux");
  gh.Flags(&para->Aux,L"-|aux| 1-aux|upper half|lower half",gh.ChangeMsg);
}

void ModShaderDefSpecular(wOp *op)
{
  ModShaderParaSpecular sUNUSED *para = (ModShaderParaSpecular *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Op = 0x00000001;
}

void ModShaderBindSpecular(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Specular(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"op");
    name[1] = sPoolString(L"aux");
  }
}
void ModShaderBind3Specular(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiSpecular =
L"= ModShader : Specular\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Specular\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Op\n"
L" !i Op\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i rgb\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Aux\n"
L" !i Aux\n"
L" !i aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1-aux\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i upper half\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i lower half\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdAux(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaAux sUNUSED *para = (ModShaderParaAux *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 567 "wz4_modmtrlmod_ops.ops"

    MM_ApplyTexture *mod = new MM_ApplyTexture;
    mod->Tex = in0->Modules[0];
    mod->Dest = L"col_aux";
    mod->Op = (para->Op&15);
    mod->Swizzle = (para->Op&16)?L"w":L"xyz";
    mod->Phase = MMP_Pre;
    out->Add(mod);
    out->Add(in0);
  ;
#line 3921 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiAux(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaAux sUNUSED *para = (ModShaderParaAux *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Op");
  gh.Flags(&para->Op,L"add|mul|sub|mul2|mul4|screen|set:*4rgb|alpha",gh.ChangeMsg);
}

void ModShaderDefAux(wOp *op)
{
  ModShaderParaAux sUNUSED *para = (ModShaderParaAux *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Op = 0x00000011;
}

void ModShaderBindAux(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Aux(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"op");
  }
}
void ModShaderBind3Aux(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiAux =
L"= ModShader : Aux\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Aux\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Op\n"
L" !i Op\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i rgb\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i alpha\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdAlpha(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaAlpha sUNUSED *para = (ModShaderParaAlpha *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 590 "wz4_modmtrlmod_ops.ops"

    MM_ApplyTexture *mod = new MM_ApplyTexture;
    mod->Tex = in0->Modules[0];
    mod->Dest = L"alpha";
    mod->Op = (para->Op&15);
    switch(para->Channel)
    {
    default:
    case 0: mod->Swizzle = L"r"; break;
    case 1: mod->Swizzle = L"g"; break;
    case 2: mod->Swizzle = L"b"; break;
    case 3: mod->Swizzle = L"a"; break;
    }
    out->Add(mod);
    out->Add(in0);
  ;
#line 4070 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiAlpha(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaAlpha sUNUSED *para = (ModShaderParaAlpha *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Op");
  gh.Flags(&para->Op,L"add|mul|sub|mul2|mul4|screen|set",gh.ChangeMsg);

  gh.Label(L"Channel");
  gh.Flags(&para->Channel,L"r|g|b|a",gh.ChangeMsg);
}

void ModShaderDefAlpha(wOp *op)
{
  ModShaderParaAlpha sUNUSED *para = (ModShaderParaAlpha *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Op = 0x00000001;
  para->Channel = 0x00000003;
}

void ModShaderBindAlpha(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2Alpha(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"op");
    name[1] = sPoolString(L"channel");
  }
}
void ModShaderBind3Alpha(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiAlpha =
L"= ModShader : Alpha\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Alpha\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Op\n"
L" !i Op\n"
L" !i add\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i sub\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i mul4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i screen\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i set\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Channel\n"
L" !i Channel\n"
L" !i r\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i g\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i b\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdKill(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaKill sUNUSED *para = (ModShaderParaKill *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 620 "wz4_modmtrlmod_ops.ops"

    MM_Kill *mod = new MM_Kill;
    mod->Tex = in0->Modules[0];
    mod->ThreshLo = para->Thresh[0];
    mod->ThreshHi = para->Thresh[1];
    mod->Invert = para->Invert;
    mod->Channel = para->Channel;
    out->Add(mod);
    out->Add(in0);
  ;
#line 4222 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiKill(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaKill sUNUSED *para = (ModShaderParaKill *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Low / High");
  gh.BeginTied();
  sFloatControl *float_Thresh_0 = gh.Float(&para->Thresh[0],-16.0000f,16.00000f,0.010000f);
  float_Thresh_0->Default = 0.250000f; float_Thresh_0->RightStep = 0.125000f;
  sFloatControl *float_Thresh_1 = gh.Float(&para->Thresh[1],-16.0000f,16.00000f,0.010000f);
  float_Thresh_1->Default = 0.750000f; float_Thresh_1->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Invert");
  gh.Flags(&para->Invert,L"-|Invert",gh.ChangeMsg);

  gh.Label(L"Channel");
  gh.Flags(&para->Channel,L"r|g|b|a",gh.ChangeMsg);
}

void ModShaderDefKill(wOp *op)
{
  ModShaderParaKill sUNUSED *para = (ModShaderParaKill *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Thresh[0] = 0.250000f;
  para->Thresh[1] = 0.750000f;
  para->Channel = 0x00000003;
}

void ModShaderBindKill(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"thresh"),val);
  val = ctx->MakeValue(ScriptTypeFloat,2);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"thresh"),val);
}
void ModShaderBind2Kill(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"thresh");
    name[1] = sPoolString(L"invert");
    name[2] = sPoolString(L"channel");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,2,cmd->Data+0);
}
void ModShaderBind3Kill(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import thresh : float[2];\n");
}
const sChar *ModShaderWikiKill =
L"= ModShader : Kill\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Kill\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Low / High\n"
L" !i Thresh\n"
L" !i float[2]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Invert\n"
L" !i Invert\n"
L" !i Invert\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Channel\n"
L" !i Channel\n"
L" !i r\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i g\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i b\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdDisplace(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaDisplace sUNUSED *para = (ModShaderParaDisplace *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 647 "wz4_modmtrlmod_ops.ops"

    MM_Displace *mod = new MM_Displace;
    mod->Tex = in0->Modules[0];
    switch(para->Channel&15)
    {
    default:
    case 0: mod->Swizzle = L"r"; break;
    case 1: mod->Swizzle = L"g"; break;
    case 2: mod->Swizzle = L"b"; break;
    case 3: mod->Swizzle = L"a"; break;
    }
    mod->Bias = (para->Channel&16) ? -0.5f : 0;
    mod->Source = (para->Channel&0xf00)>>8;
    mod->Scale = para->Scale;
    out->Add(mod);
    out->Add(in0);
  ;
#line 4381 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiDisplace(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaDisplace sUNUSED *para = (ModShaderParaDisplace *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Channel");
  gh.Flags(&para->Channel,L"r|g|b|a",gh.ChangeMsg);

  gh.Label(L"Bias");
  gh.Flags(&para->Channel,L"*4-|bias",gh.ChangeMsg);

  gh.Label(L"Source");
  gh.Flags(&para->Channel,L"*8here|Vector0|Vector1|Vector2|Vector3|Vector4|Vector5|Vector6|Vector7",gh.ChangeMsg);

  gh.Label(L"Scale");
  sFloatControl *float_Scale = gh.Float(&para->Scale,-1024.00f,1024.000f,0.010000f);
  float_Scale->Default = 1.000000f; float_Scale->RightStep = 0.125000f;
}

void ModShaderDefDisplace(wOp *op)
{
  ModShaderParaDisplace sUNUSED *para = (ModShaderParaDisplace *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Channel = 0x00000010;
  para->Scale = 1.000000f;
}

void ModShaderBindDisplace(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"scale"),val);
}
void ModShaderBind2Displace(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[4];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"channel");
    name[1] = sPoolString(L"bias");
    name[2] = sPoolString(L"source");
    name[3] = sPoolString(L"scale");
  }
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+1);
}
void ModShaderBind3Displace(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import scale : float;\n");
}
const sChar *ModShaderWikiDisplace =
L"= ModShader : Displace\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Displace\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Channel\n"
L" !i Channel\n"
L" !i r\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i g\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i b\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i a\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Bias\n"
L" !i Channel\n"
L" !i bias\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Source\n"
L" !i Channel\n"
L" !i here\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Scale\n"
L" !i Scale\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdExtrudeNormal(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaExtrudeNormal sUNUSED *para = (ModShaderParaExtrudeNormal *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 679 "wz4_modmtrlmod_ops.ops"

    MM_ExtrudeNormal *mod = new MM_ExtrudeNormal;
    mod->Source = para->Source;
    mod->Value = para->Value;
    out->Add(mod);
  ;
#line 4562 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiExtrudeNormal(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaExtrudeNormal sUNUSED *para = (ModShaderParaExtrudeNormal *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Source");
  gh.Flags(&para->Source,L"const|shell|Vector0|Vector1|Vector2|Vector3|Vector4|Vector5|Vector6|Vector7",gh.LayoutMsg);

  gh.Label(L"Value");
  sFloatControl *float_Value = gh.Float(&para->Value,-1024.00f,1024.000f,0.001000f);
  float_Value->Default = 0.000000f; float_Value->RightStep = 0.125000f;
}

void ModShaderDefExtrudeNormal(wOp *op)
{
  ModShaderParaExtrudeNormal sUNUSED *para = (ModShaderParaExtrudeNormal *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderBindExtrudeNormal(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"value"),val);
}
void ModShaderBind2ExtrudeNormal(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[2];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"source");
    name[1] = sPoolString(L"value");
  }
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+1);
}
void ModShaderBind3ExtrudeNormal(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import value : float;\n");
}
const sChar *ModShaderWikiExtrudeNormal =
L"= ModShader : ExtrudeNormal\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ExtrudeNormal\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Source\n"
L" !i Source\n"
L" !i const\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shell\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i Vector7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Value\n"
L" !i Value\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdNormalMap(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaNormalMap sUNUSED *para = (ModShaderParaNormalMap *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 697 "wz4_modmtrlmod_ops.ops"

    MM_NormalMap *mod = new MM_NormalMap;
    mod->Tex = in0->Modules[0];
    out->Add(mod);
    out->Add(in0);
  ;
#line 4704 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiNormalMap(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaNormalMap sUNUSED *para = (ModShaderParaNormalMap *)(op->EditData); para;
}

void ModShaderDefNormalMap(wOp *op)
{
  ModShaderParaNormalMap sUNUSED *para = (ModShaderParaNormalMap *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderBindNormalMap(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2NormalMap(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind3NormalMap(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiNormalMap =
L"= ModShader : NormalMap\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i NormalMap\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdDoubleNormalMap(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaDoubleNormalMap sUNUSED *para = (ModShaderParaDoubleNormalMap *)(cmd->Data); para;
  ModShaderSampler sUNUSED *in0 = cmd->GetInput<ModShaderSampler *>(0); in0;
  ModShaderSampler sUNUSED *in1 = cmd->GetInput<ModShaderSampler *>(1); in1;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 717 "wz4_modmtrlmod_ops.ops"

    MM_DoubleNormalMap *mod = new MM_DoubleNormalMap;
    mod->Tex0 = in0->Modules[0];
    mod->Tex1 = in1->Modules[0];
    mod->Flags = para->Mode;
    out->Add(mod);
    out->Add(in0);
    out->Add(in1);
  ;
#line 4783 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiDoubleNormalMap(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaDoubleNormalMap sUNUSED *para = (ModShaderParaDoubleNormalMap *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Mode");
  gh.Flags(&para->Mode,L"mix|blend by aux",gh.ChangeMsg);
}

void ModShaderDefDoubleNormalMap(wOp *op)
{
  ModShaderParaDoubleNormalMap sUNUSED *para = (ModShaderParaDoubleNormalMap *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderBindDoubleNormalMap(wCommand *cmd,ScriptContext *ctx)
{
}
void ModShaderBind2DoubleNormalMap(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"mode");
  }
}
void ModShaderBind3DoubleNormalMap(wOp *op,sTextBuffer &tb)
{
}
const sChar *ModShaderWikiDoubleNormalMap =
L"= ModShader : DoubleNormalMap\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i DoubleNormalMap\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L" !i ModShaderSampler\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Mode\n"
L" !i Mode\n"
L" !i mix\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i blend by aux\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdBakedShadow(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaBakedShadow sUNUSED *para = (ModShaderSamplerParaBakedShadow *)(cmd->Data); para;
  Wz4Mesh sUNUSED *in0 = cmd->GetInput<Wz4Mesh *>(0); in0;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 752 "wz4_modmtrlmod_ops.ops"

    MM_BakedShadow *mod = new MM_BakedShadow;
    mod->Dir = -para->Dir;
    mod->Dir.Unit();
    mod->ShadowSize = para->ShadowSize;
    mod->ShadowBaseBias = para->ShadowBaseBias;
    mod->ShadowFilter = para->ShadowFilter/(1<<(para->ShadowSize&15));
    mod->ShadowSlopeBias = para->ShadowSlopeBias;
    mod->LimitCenter = para->LimitCenter;
    mod->LimitRadius = para->LimitRadius;
    mod->Color.InitColor(para->Color);
    mod->Render(in0);
    out->Add(mod);
  ;
#line 4900 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiBakedShadow(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaBakedShadow sUNUSED *para = (ModShaderSamplerParaBakedShadow *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"* Dir");
  gh.BeginTied();
  sFloatControl *float_Dir_0 = gh.Float(&para->Dir.x,-10000000, 10000000,0.010000f);
  float_Dir_0->Default = 0.000000f; float_Dir_0->RightStep = 0.125000f;
  sFloatControl *float_Dir_1 = gh.Float(&para->Dir.y,-10000000, 10000000,0.010000f);
  float_Dir_1->Default = 0.000000f; float_Dir_1->RightStep = 0.125000f;
  sFloatControl *float_Dir_2 = gh.Float(&para->Dir.z,-10000000, 10000000,0.010000f);
  float_Dir_2->Default = 0.000000f; float_Dir_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"* ShadowSize");
  gh.Flags(&para->ShadowSize,L" 1| 2| 4| 8| 16| 32| 64| 128| 256| 512| 1024| 2048| 4096| 8192",gh.ChangeMsg);

  gh.Label(L"ShadowFilter0");
  gh.Flags(&para->ShadowSize,L"*16point|ordered|random:*20-|PCF",gh.ChangeMsg);

  gh.Label(L"* ShadowBaseBias");
  sFloatControl *float_ShadowBaseBias = gh.Float(&para->ShadowBaseBias,0.000000f,1024.000f,0.001000f);
  float_ShadowBaseBias->Default = 0.500000f; float_ShadowBaseBias->RightStep = 0.125000f;

  gh.Label(L"* ShadowFilter");
  sFloatControl *float_ShadowFilter = gh.Float(&para->ShadowFilter,0.000000f,1024.000f,0.001000f);
  float_ShadowFilter->Default = 0.500000f; float_ShadowFilter->RightStep = 0.125000f;

  gh.Label(L"* ShadowSlopeBias");
  sFloatControl *float_ShadowSlopeBias = gh.Float(&para->ShadowSlopeBias,-1024.00f,1024.000f,0.001000f);
  float_ShadowSlopeBias->Default = 0.500000f; float_ShadowSlopeBias->RightStep = 0.125000f;

  gh.Label(L"Color");
  gh.ColorPick(&para->Color,L"rgba",0);

  gh.Label(L"Limit Shadows");
  gh.Flags(&para->ShadowSize,L"*21-|limit",gh.LayoutMsg);

  if((para->ShadowSize&0x200000))
  {
    gh.Label(L"* LimitCenter");
    gh.BeginTied();
    sFloatControl *float_LimitCenter_0 = gh.Float(&para->LimitCenter.x,-1024.00f,1024.000f,0.125000f);
    float_LimitCenter_0->Default = 0.000000f; float_LimitCenter_0->RightStep = 0.125000f;
    sFloatControl *float_LimitCenter_1 = gh.Float(&para->LimitCenter.y,-1024.00f,1024.000f,0.125000f);
    float_LimitCenter_1->Default = 0.000000f; float_LimitCenter_1->RightStep = 0.125000f;
    sFloatControl *float_LimitCenter_2 = gh.Float(&para->LimitCenter.z,-1024.00f,1024.000f,0.125000f);
    float_LimitCenter_2->Default = 0.000000f; float_LimitCenter_2->RightStep = 0.125000f;
    gh.EndTied();

    gh.Label(L"* LimitRadius");
    gh.BeginTied();
    sFloatControl *float_LimitRadius_0 = gh.Float(&para->LimitRadius.x,0.000000f,1024.000f,0.125000f);
    float_LimitRadius_0->Default = 64.00000f; float_LimitRadius_0->RightStep = 0.125000f;
    sFloatControl *float_LimitRadius_1 = gh.Float(&para->LimitRadius.y,0.000000f,1024.000f,0.125000f);
    float_LimitRadius_1->Default = 64.00000f; float_LimitRadius_1->RightStep = 0.125000f;
    sFloatControl *float_LimitRadius_2 = gh.Float(&para->LimitRadius.z,0.000000f,1024.000f,0.125000f);
    float_LimitRadius_2->Default = 64.00000f; float_LimitRadius_2->RightStep = 0.125000f;
    gh.EndTied();
  }
}

void ModShaderSamplerDefBakedShadow(wOp *op)
{
  ModShaderSamplerParaBakedShadow sUNUSED *para = (ModShaderSamplerParaBakedShadow *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->ShadowSize = 0x0000000a;
  para->ShadowBaseBias = 0.500000f;
  para->ShadowFilter = 0.500000f;
  para->ShadowSlopeBias = 0.500000f;
  para->Color = 0x00808080;
  para->LimitRadius.x = 64.00000f;
  para->LimitRadius.y = 64.00000f;
  para->LimitRadius.z = 64.00000f;
}

void ModShaderSamplerBindBakedShadow(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"dir"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+4;
  ctx->BindLocal(ctx->AddSymbol(L"shadowbasebias"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+5;
  ctx->BindLocal(ctx->AddSymbol(L"shadowfilter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+6;
  ctx->BindLocal(ctx->AddSymbol(L"shadowslopebias"),val);
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+7;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"limitcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"limitcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+8;
  ctx->BindLocal(ctx->AddSymbol(L"limitcenter"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"limitradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"limitradius"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+11;
  ctx->BindLocal(ctx->AddSymbol(L"limitradius"),val);
}
void ModShaderSamplerBind2BakedShadow(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[10];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"dir");
    name[1] = sPoolString(L"shadowsize");
    name[2] = sPoolString(L"shadowfilter0");
    name[3] = sPoolString(L"shadowbasebias");
    name[4] = sPoolString(L"shadowfilter");
    name[5] = sPoolString(L"shadowslopebias");
    name[6] = sPoolString(L"color_");
    name[7] = sPoolString(L"shadowsize");
    name[8] = sPoolString(L"limitcenter");
    name[9] = sPoolString(L"limitradius");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[3],ScriptTypeFloat,1,cmd->Data+4);
  ctx->AddImport(name[4],ScriptTypeFloat,1,cmd->Data+5);
  ctx->AddImport(name[5],ScriptTypeFloat,1,cmd->Data+6);
  ctx->AddImport(name[6],ScriptTypeColor,1,cmd->Data+7);
  ctx->AddImport(name[8],ScriptTypeFloat,3,cmd->Data+8);
  ctx->AddImport(name[9],ScriptTypeFloat,3,cmd->Data+11);
}
void ModShaderSamplerBind3BakedShadow(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import dir : float[3];\n");
  tb.PrintF(L"  import shadowbasebias : float;\n");
  tb.PrintF(L"  import shadowfilter : float;\n");
  tb.PrintF(L"  import shadowslopebias : float;\n");
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import limitcenter : float[3];\n");
  tb.PrintF(L"  import limitradius : float[3];\n");
}
const sChar *ModShaderSamplerWikiBakedShadow =
L"= ModShaderSampler : BakedShadow\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i BakedShadow\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Inputs\n"
L"\n"
L"!T 3 : 1 1 3\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Type\n"
L"  !i Flags\n"
L"  !i Comment\n"
L" !i Wz4Mesh\n"
L" !i\n"
L" !i *\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Dir\n"
L" !i Dir\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowSize\n"
L" !i ShadowSize\n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 16\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 32\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 64\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 128\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 256\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 512\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1024\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2048\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4096\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 8192\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowFilter0\n"
L" !i ShadowSize\n"
L" !i point\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ordered\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i random\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i PCF\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i ShadowBaseBias\n"
L" !i ShadowBaseBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowFilter\n"
L" !i ShadowFilter\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i ShadowSlopeBias\n"
L" !i ShadowSlopeBias\n"
L" !i float\n"
L" !i *\n"
L"\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Limit Shadows\n"
L" !i ShadowSize\n"
L" !i limit\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i LimitCenter\n"
L" !i LimitCenter\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i LimitRadius\n"
L" !i LimitRadius\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderSamplerCmdShadowGrab(wExecutive *exe,wCommand *cmd)
{
  ModShaderSamplerParaShadowGrab sUNUSED *para = (ModShaderSamplerParaShadowGrab *)(cmd->Data); para;
  ModShaderSampler *out = (ModShaderSampler *) cmd->Output;
  if(!out) { out=new ModShaderSampler; cmd->Output=out; }

  {
#line 819 "wz4_modmtrlmod_ops.ops"

    MM_ShadowGrab *mod = new MM_ShadowGrab;
    mod->Light = para->Lightsource;
    out->Add(mod);
  ;
#line 5240 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderSamplerGuiShadowGrab(wGridFrameHelper &gh,wOp *op)
{
  ModShaderSamplerParaShadowGrab sUNUSED *para = (ModShaderSamplerParaShadowGrab *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Lightsource");
  sIntControl *int_Lightsource = gh.Int(&para->Lightsource,0,7,0.125000f);
  int_Lightsource->Default = 0x00000000; int_Lightsource->RightStep = 0.125000f;
}

void ModShaderSamplerDefShadowGrab(wOp *op)
{
  ModShaderSamplerParaShadowGrab sUNUSED *para = (ModShaderSamplerParaShadowGrab *)(op->EditData); para;
  op->ArrayGroupMode = 0;
}

void ModShaderSamplerBindShadowGrab(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeInt,1);
  val->IntPtr = ((sInt *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"lightsource"),val);
}
void ModShaderSamplerBind2ShadowGrab(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[1];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"lightsource");
  }
  ctx->AddImport(name[0],ScriptTypeInt,1,cmd->Data+0);
}
void ModShaderSamplerBind3ShadowGrab(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import lightsource : int;\n");
}
const sChar *ModShaderSamplerWikiShadowGrab =
L"= ModShaderSampler : ShadowGrab\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i ShadowGrab\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShaderSampler\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Lightsource\n"
L" !i Lightsource\n"
L" !i int\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdTint(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaTint sUNUSED *para = (ModShaderParaTint *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 881 "wz4_modmtrlmod_ops.ops"

    MM_Tint *mod = new MM_Tint;
    mod->Select = para->Select;
    mod->Color.InitColor(para->Color,para->Amp);
    out->Add(mod)
  ;
#line 5335 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiTint(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaTint sUNUSED *para = (ModShaderParaTint *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Select");
  gh.Flags(&para->Select,L"here| 0| 1| 2| 3| 4| 5| 6| 7",gh.LayoutMsg);

  if((para->Select==0x0000))
  {
    gh.Label(L"Color");
    gh.ColorPick(&para->Color,L"rgb",0);

    gh.Label(L"Amp");
    sFloatControl *float_Amp = gh.Float(&para->Amp,0.000000f,1024.000f,0.010000f);
    float_Amp->Default = 1.000000f; float_Amp->RightStep = 0.125000f;
  }
}

void ModShaderDefTint(wOp *op)
{
  ModShaderParaTint sUNUSED *para = (ModShaderParaTint *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Color = 0xffffffff;
  para->Amp = 1.000000f;
}

void ModShaderBindTint(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeColor,1);
  val->ColorPtr = ((sU32 *)cmd->Data)+1;
  ctx->BindLocal(ctx->AddSymbol(L"color_"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"amp"),val);
}
void ModShaderBind2Tint(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"select");
    name[1] = sPoolString(L"color_");
    name[2] = sPoolString(L"amp");
  }
  ctx->AddImport(name[1],ScriptTypeColor,1,cmd->Data+1);
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void ModShaderBind3Tint(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import color_ : color;\n");
  tb.PrintF(L"  import amp : float;\n");
}
const sChar *ModShaderWikiTint =
L"= ModShader : Tint\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Tint\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Select\n"
L" !i Select\n"
L" !i here\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Color\n"
L" !i Color\n"
L" !i color\n"
L" !i *\n"
L"\n"
L" !i Amp\n"
L" !i Amp\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdDebug(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaDebug sUNUSED *para = (ModShaderParaDebug *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 992 "wz4_modmtrlmod_ops.ops"

    MM_Debug *mod = new MM_Debug;
    mod->Debug = para->Debug;
    mod->Light = para->Light;
    mod->Bright = para->Bright;
    out->Add(mod);
  ;
#line 5492 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiDebug(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaDebug sUNUSED *para = (ModShaderParaDebug *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Debug");
  gh.Flags(&para->Debug,L"-|normal|tangent|bitangent|shadow2d|shadowCube|ms_pos|error:*4-|bias",gh.LayoutMsg);

  if((((para->Debug&0x000f)==0x0004)||((para->Debug&0x000f)==0x0005)))
  {
    gh.Label(L"Light");
    gh.Flags(&para->Light,L" 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

    gh.Label(L"Bright");
    sFloatControl *float_Bright = gh.Float(&para->Bright,0.000000f,256.0000f,0.010000f);
    float_Bright->Default = 1.000000f; float_Bright->RightStep = 0.125000f;
  }
}

void ModShaderDefDebug(wOp *op)
{
  ModShaderParaDebug sUNUSED *para = (ModShaderParaDebug *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Bright = 1.000000f;
}

void ModShaderBindDebug(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+2;
  ctx->BindLocal(ctx->AddSymbol(L"bright"),val);
}
void ModShaderBind2Debug(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[3];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"debug");
    name[1] = sPoolString(L"light");
    name[2] = sPoolString(L"bright");
  }
  ctx->AddImport(name[2],ScriptTypeFloat,1,cmd->Data+2);
}
void ModShaderBind3Debug(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import bright : float;\n");
}
const sChar *ModShaderWikiDebug =
L"= ModShader : Debug\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i Debug\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Debug\n"
L" !i Debug\n"
L" !i normal\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i tangent\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i bitangent\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shadow2d\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i shadowCube\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i ms_pos\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i error\n"
L" !i *\n"
L" !i\n"
L" !i\n"
L" !i\n"
L" !i\n"
L"\n"
L" !i \n"
L" !i \n"
L" !i bias\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Light\n"
L" !i Light\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i Bright\n"
L" !i Bright\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

sBool ModShaderCmdSphereFog(wExecutive *exe,wCommand *cmd)
{
  ModShaderParaSphereFog sUNUSED *para = (ModShaderParaSphereFog *)(cmd->Data); para;
  ModShader *out = (ModShader *) cmd->Output;
  if(!out) { out=new ModShader; cmd->Output=out; }

  {
#line 1106 "wz4_modmtrlmod_ops.ops"

    MM_SphereFog *mod = new MM_SphereFog;
    mod->Center = para->Center;
    mod->Radius = para->Radius;
    mod->Flags = para->Animate;
    mod->VectorId = para->LightEnvVector;
    out->Add(mod)
  ;
#line 5673 "wz4_modmtrlmod_ops.cpp"
    return 1;
  }
}

void ModShaderGuiSphereFog(wGridFrameHelper &gh,wOp *op)
{
  ModShaderParaSphereFog sUNUSED *para = (ModShaderParaSphereFog *)(op->EditData); para;
  gh.Group(op->Class->Label);

  gh.Label(L"Center");
  gh.BeginTied();
  sFloatControl *float_Center_0 = gh.Float(&para->Center.x, -1000000,  1000000,0.010000f);
  float_Center_0->Default = 0.000000f; float_Center_0->RightStep = 0.125000f;
  sFloatControl *float_Center_1 = gh.Float(&para->Center.y, -1000000,  1000000,0.010000f);
  float_Center_1->Default = 0.000000f; float_Center_1->RightStep = 0.125000f;
  sFloatControl *float_Center_2 = gh.Float(&para->Center.z, -1000000,  1000000,0.010000f);
  float_Center_2->Default = 0.000000f; float_Center_2->RightStep = 0.125000f;
  gh.EndTied();

  gh.Label(L"Radius");
  sFloatControl *float_Radius = gh.Float(&para->Radius,0.000000f,  1000000,0.010000f);
  float_Radius->Default = 1.000000f; float_Radius->RightStep = 0.125000f;

  gh.Label(L"Animate");
  gh.Flags(&para->Animate,L"all static|radius from lightenv|all from lightenv",gh.ChangeMsg);

  if((para->Animate>=0x0001))
  {
    gh.Label(L"RadiusVector");
    gh.Flags(&para->LightEnvVector,L" 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);

  }
  if((para->Animate>=0x0002))
  {
    gh.Label(L"CenterVector");
    gh.Flags(&para->LightEnvVector,L"*4 0| 1| 2| 3| 4| 5| 6| 7",gh.ChangeMsg);
  }
}

void ModShaderDefSphereFog(wOp *op)
{
  ModShaderParaSphereFog sUNUSED *para = (ModShaderParaSphereFog *)(op->EditData); para;
  op->ArrayGroupMode = 0;
  para->Radius = 1.000000f;
}

void ModShaderBindSphereFog(wCommand *cmd,ScriptContext *ctx)
{
  ScriptValue *val;
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,3);
  val->FloatPtr = ((sF32 *)cmd->Data)+0;
  ctx->BindLocal(ctx->AddSymbol(L"center"),val);
  val = ctx->MakeValue(ScriptTypeFloat,1);
  val->FloatPtr = ((sF32 *)cmd->Data)+3;
  ctx->BindLocal(ctx->AddSymbol(L"radius"),val);
}
void ModShaderBind2SphereFog(wCommand *cmd,ScriptContext *ctx)
{
  static sInt initdone = 0;
  static sPoolString name[5];
  if(!initdone)
  {
    initdone = 1; 
    name[0] = sPoolString(L"center");
    name[1] = sPoolString(L"radius");
    name[2] = sPoolString(L"animate");
    name[3] = sPoolString(L"radiusvector");
    name[4] = sPoolString(L"centervector");
  }
  ctx->AddImport(name[0],ScriptTypeFloat,3,cmd->Data+0);
  ctx->AddImport(name[1],ScriptTypeFloat,1,cmd->Data+3);
}
void ModShaderBind3SphereFog(wOp *op,sTextBuffer &tb)
{
  tb.PrintF(L"  import center : float[3];\n");
  tb.PrintF(L"  import radius : float;\n");
}
const sChar *ModShaderWikiSphereFog =
L"= ModShader : SphereFog\n"
L"\n"
L"!t 2 : 2 3\n"
L" !T 2\n"
L"  !i Name\n"
L"  !i SphereFog\n"
L"\n"
L"  !i Output Type\n"
L"  !i ModShader\n"
L" !i\n"
L"\n"
L"== Parameters\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !\n"
L"  ! bc #c0c0c0\n"
L"  !i Screen Name\n"
L"  !i Script Name\n"
L"  !i Type\n"
L"  !i Comment\n"
L"\n"
L" !i Center\n"
L" !i Center\n"
L" !i float[3]\n"
L" !i *\n"
L"\n"
L" !i Radius\n"
L" !i Radius\n"
L" !i float\n"
L" !i *\n"
L"\n"
L"!T 4 : 1 1 1 2\n"
L" !i Animate\n"
L" !i Animate\n"
L" !i all static\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i radius from lightenv\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i all from lightenv\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i RadiusVector\n"
L" !i LightEnvVector\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"!T 4 : 1 1 1 2\n"
L" !i CenterVector\n"
L" !i LightEnvVector\n"
L" !i 0\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 1\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 2\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 3\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 4\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 5\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 6\n"
L" !i *\n"
L" !i \n"
L" !i \n"
L" !i 7\n"
L" !i *\n"
L"== Comments\n"
L"\n"
L"*\n"
L"\n"
L"== See Also\n"
L"\n"
L"\n"
;

/****************************************************************************/

void ModShaderAnimFlat::Init(class ScriptContext *sc)
{
};

void ModShaderAnimFlat::Bind(class ScriptContext *sc,ModShaderParaFlat *para)
{
};

void ModShaderAnimLambert::Init(class ScriptContext *sc)
{
};

void ModShaderAnimLambert::Bind(class ScriptContext *sc,ModShaderParaLambert *para)
{
};

void ModShaderAnimPhong::Init(class ScriptContext *sc)
{
};

void ModShaderAnimPhong::Bind(class ScriptContext *sc,ModShaderParaPhong *para)
{
};

void ModShaderAnimRim::Init(class ScriptContext *sc)
{
};

void ModShaderAnimRim::Bind(class ScriptContext *sc,ModShaderParaRim *para)
{
};

void ModShaderAnimComic::Init(class ScriptContext *sc)
{
};

void ModShaderAnimComic::Bind(class ScriptContext *sc,ModShaderParaComic *para)
{
};

void ModShaderAnimBlinnPhong::Init(class ScriptContext *sc)
{
};

void ModShaderAnimBlinnPhong::Bind(class ScriptContext *sc,ModShaderParaBlinnPhong *para)
{
};

void ModShaderSamplerAnimTex2D::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimTex2D::Bind(class ScriptContext *sc,ModShaderSamplerParaTex2D *para)
{
};

void ModShaderSamplerAnimTex2DAnim::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimTex2DAnim::Bind(class ScriptContext *sc,ModShaderSamplerParaTex2DAnim *para)
{
};

void ModShaderSamplerAnimTex2DSurround::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimTex2DSurround::Bind(class ScriptContext *sc,ModShaderSamplerParaTex2DSurround *para)
{
};

void ModShaderAnimTex2DSurroundNormal::Init(class ScriptContext *sc)
{
};

void ModShaderAnimTex2DSurroundNormal::Bind(class ScriptContext *sc,ModShaderParaTex2DSurroundNormal *para)
{
};

void ModShaderSamplerAnimConst::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimConst::Bind(class ScriptContext *sc,ModShaderSamplerParaConst *para)
{
};

void ModShaderSamplerAnimTrickLight::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimTrickLight::Bind(class ScriptContext *sc,ModShaderSamplerParaTrickLight *para)
{
};

void ModShaderSamplerAnimMul::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimMul::Bind(class ScriptContext *sc,ModShaderSamplerParaMul *para)
{
};

void ModShaderSamplerAnimAdd::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimAdd::Bind(class ScriptContext *sc,ModShaderSamplerParaAdd *para)
{
};

void ModShaderSamplerAnimSub::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimSub::Bind(class ScriptContext *sc,ModShaderSamplerParaSub *para)
{
};

void ModShaderAnimDiffuse::Init(class ScriptContext *sc)
{
};

void ModShaderAnimDiffuse::Bind(class ScriptContext *sc,ModShaderParaDiffuse *para)
{
};

void ModShaderAnimGloss::Init(class ScriptContext *sc)
{
};

void ModShaderAnimGloss::Bind(class ScriptContext *sc,ModShaderParaGloss *para)
{
};

void ModShaderAnimEmissive::Init(class ScriptContext *sc)
{
};

void ModShaderAnimEmissive::Bind(class ScriptContext *sc,ModShaderParaEmissive *para)
{
};

void ModShaderAnimSpecular::Init(class ScriptContext *sc)
{
};

void ModShaderAnimSpecular::Bind(class ScriptContext *sc,ModShaderParaSpecular *para)
{
};

void ModShaderAnimAux::Init(class ScriptContext *sc)
{
};

void ModShaderAnimAux::Bind(class ScriptContext *sc,ModShaderParaAux *para)
{
};

void ModShaderAnimAlpha::Init(class ScriptContext *sc)
{
};

void ModShaderAnimAlpha::Bind(class ScriptContext *sc,ModShaderParaAlpha *para)
{
};

void ModShaderAnimKill::Init(class ScriptContext *sc)
{
};

void ModShaderAnimKill::Bind(class ScriptContext *sc,ModShaderParaKill *para)
{
};

void ModShaderAnimDisplace::Init(class ScriptContext *sc)
{
};

void ModShaderAnimDisplace::Bind(class ScriptContext *sc,ModShaderParaDisplace *para)
{
};

void ModShaderAnimExtrudeNormal::Init(class ScriptContext *sc)
{
};

void ModShaderAnimExtrudeNormal::Bind(class ScriptContext *sc,ModShaderParaExtrudeNormal *para)
{
};

void ModShaderAnimNormalMap::Init(class ScriptContext *sc)
{
};

void ModShaderAnimNormalMap::Bind(class ScriptContext *sc,ModShaderParaNormalMap *para)
{
};

void ModShaderAnimDoubleNormalMap::Init(class ScriptContext *sc)
{
};

void ModShaderAnimDoubleNormalMap::Bind(class ScriptContext *sc,ModShaderParaDoubleNormalMap *para)
{
};

void ModShaderSamplerAnimBakedShadow::Init(class ScriptContext *sc)
{
  _Dir = sc->AddSymbol(L"dir");
  _ShadowSize = sc->AddSymbol(L"shadowsize");
  _ShadowBaseBias = sc->AddSymbol(L"shadowbasebias");
  _ShadowFilter = sc->AddSymbol(L"shadowfilter");
  _ShadowSlopeBias = sc->AddSymbol(L"shadowslopebias");
  _LimitCenter = sc->AddSymbol(L"limitcenter");
  _LimitRadius = sc->AddSymbol(L"limitradius");
};

void ModShaderSamplerAnimBakedShadow::Bind(class ScriptContext *sc,ModShaderSamplerParaBakedShadow *para)
{
  sc->BindLocalFloat(_Dir,3,&para->Dir.x);
  sc->BindLocalInt(_ShadowSize,1,&para->ShadowSize);
  sc->BindLocalFloat(_ShadowBaseBias,1,&para->ShadowBaseBias);
  sc->BindLocalFloat(_ShadowFilter,1,&para->ShadowFilter);
  sc->BindLocalFloat(_ShadowSlopeBias,1,&para->ShadowSlopeBias);
  sc->BindLocalFloat(_LimitCenter,3,&para->LimitCenter.x);
  sc->BindLocalFloat(_LimitRadius,3,&para->LimitRadius.x);
};

void ModShaderSamplerAnimShadowGrab::Init(class ScriptContext *sc)
{
};

void ModShaderSamplerAnimShadowGrab::Bind(class ScriptContext *sc,ModShaderSamplerParaShadowGrab *para)
{
};

void ModShaderAnimTint::Init(class ScriptContext *sc)
{
};

void ModShaderAnimTint::Bind(class ScriptContext *sc,ModShaderParaTint *para)
{
};

void ModShaderAnimDebug::Init(class ScriptContext *sc)
{
};

void ModShaderAnimDebug::Bind(class ScriptContext *sc,ModShaderParaDebug *para)
{
};

void ModShaderAnimSphereFog::Init(class ScriptContext *sc)
{
};

void ModShaderAnimSphereFog::Bind(class ScriptContext *sc,ModShaderParaSphereFog *para)
{
};


/****************************************************************************/

void AddTypes_wz4_modmtrlmod_ops(sBool secondary)
{
  sVERIFY(Doc);

}

/****************************************************************************/

void AddOps_wz4_modmtrlmod_ops(sBool secondary)
{
  sVERIFY(Doc);

  wClass sUNUSED *cl=0; cl;
  wClassInputInfo sUNUSED *in=0; in;



  cl= new wClass;
  cl->Name = L"Flat";
  cl->Label = L"Flat";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdFlat;
  cl->MakeGui = ModShaderGuiFlat;
  cl->SetDefaults = ModShaderDefFlat;
  cl->BindPara = ModShaderBindFlat;
  cl->Bind2Para = ModShaderBind2Flat;
  cl->Bind3Para = ModShaderBind3Flat;
  cl->WikiText = ModShaderWikiFlat;
  cl->ParaWords = 1;
  cl->Shortcut = 'f';
  cl->Column = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Lambert";
  cl->Label = L"Lambert";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdLambert;
  cl->MakeGui = ModShaderGuiLambert;
  cl->SetDefaults = ModShaderDefLambert;
  cl->BindPara = ModShaderBindLambert;
  cl->Bind2Para = ModShaderBind2Lambert;
  cl->Bind3Para = ModShaderBind3Lambert;
  cl->WikiText = ModShaderWikiLambert;
  cl->ParaWords = 1;
  cl->Shortcut = 'b';
  cl->Column = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Phong";
  cl->Label = L"Phong";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdPhong;
  cl->MakeGui = ModShaderGuiPhong;
  cl->SetDefaults = ModShaderDefPhong;
  cl->BindPara = ModShaderBindPhong;
  cl->Bind2Para = ModShaderBind2Phong;
  cl->Bind3Para = ModShaderBind3Phong;
  cl->WikiText = ModShaderWikiPhong;
  cl->ParaWords = 6;
  cl->Shortcut = 'p';
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Rim";
  cl->Label = L"Rim";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdRim;
  cl->MakeGui = ModShaderGuiRim;
  cl->SetDefaults = ModShaderDefRim;
  cl->BindPara = ModShaderBindRim;
  cl->Bind2Para = ModShaderBind2Rim;
  cl->Bind3Para = ModShaderBind3Rim;
  cl->WikiText = ModShaderWikiRim;
  cl->ParaWords = 4;
  cl->Column = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Comic";
  cl->Label = L"Comic";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdComic;
  cl->MakeGui = ModShaderGuiComic;
  cl->SetDefaults = ModShaderDefComic;
  cl->BindPara = ModShaderBindComic;
  cl->Bind2Para = ModShaderBind2Comic;
  cl->Bind3Para = ModShaderBind3Comic;
  cl->WikiText = ModShaderWikiComic;
  cl->ParaWords = 1;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BlinnPhong";
  cl->Label = L"BlinnPhong";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdBlinnPhong;
  cl->MakeGui = ModShaderGuiBlinnPhong;
  cl->SetDefaults = ModShaderDefBlinnPhong;
  cl->BindPara = ModShaderBindBlinnPhong;
  cl->Bind2Para = ModShaderBind2BlinnPhong;
  cl->Bind3Para = ModShaderBind3BlinnPhong;
  cl->WikiText = ModShaderWikiBlinnPhong;
  cl->ParaWords = 3;
  cl->Column = 4;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0|wCIF_OPTIONAL;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Tex2D";
  cl->Label = L"Tex2D";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdTex2D;
  cl->MakeGui = ModShaderSamplerGuiTex2D;
  cl->SetDefaults = ModShaderSamplerDefTex2D;
  cl->BindPara = ModShaderSamplerBindTex2D;
  cl->Bind2Para = ModShaderSamplerBind2Tex2D;
  cl->Bind3Para = ModShaderSamplerBind3Tex2D;
  cl->WikiText = ModShaderSamplerWikiTex2D;
  cl->ParaWords = 14;
  cl->Shortcut = 't';
  cl->Column = 6;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Tex2DAnim";
  cl->Label = L"Tex2DAnim";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdTex2DAnim;
  cl->MakeGui = ModShaderSamplerGuiTex2DAnim;
  cl->SetDefaults = ModShaderSamplerDefTex2DAnim;
  cl->BindPara = ModShaderSamplerBindTex2DAnim;
  cl->Bind2Para = ModShaderSamplerBind2Tex2DAnim;
  cl->Bind3Para = ModShaderSamplerBind3Tex2DAnim;
  cl->WikiText = ModShaderSamplerWikiTex2DAnim;
  cl->ParaWords = 15;
  cl->Column = 6;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Tex2DSurround";
  cl->Label = L"Tex2DSurround";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdTex2DSurround;
  cl->MakeGui = ModShaderSamplerGuiTex2DSurround;
  cl->SetDefaults = ModShaderSamplerDefTex2DSurround;
  cl->BindPara = ModShaderSamplerBindTex2DSurround;
  cl->Bind2Para = ModShaderSamplerBind2Tex2DSurround;
  cl->Bind3Para = ModShaderSamplerBind3Tex2DSurround;
  cl->WikiText = ModShaderSamplerWikiTex2DSurround;
  cl->ParaWords = 17;
  cl->Shortcut = 'T';
  cl->Column = 6;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Tex2DSurroundNormal";
  cl->Label = L"Tex2DSurroundNormal";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdTex2DSurroundNormal;
  cl->MakeGui = ModShaderGuiTex2DSurroundNormal;
  cl->SetDefaults = ModShaderDefTex2DSurroundNormal;
  cl->BindPara = ModShaderBindTex2DSurroundNormal;
  cl->Bind2Para = ModShaderBind2Tex2DSurroundNormal;
  cl->Bind3Para = ModShaderBind3Tex2DSurroundNormal;
  cl->WikiText = ModShaderWikiTex2DSurroundNormal;
  cl->ParaWords = 17;
  cl->Column = 6;
  cl->Flags = 0x0040;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Texture2DType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Const";
  cl->Label = L"Const";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdConst;
  cl->MakeGui = ModShaderSamplerGuiConst;
  cl->SetDefaults = ModShaderSamplerDefConst;
  cl->BindPara = ModShaderSamplerBindConst;
  cl->Bind2Para = ModShaderSamplerBind2Const;
  cl->Bind3Para = ModShaderSamplerBind3Const;
  cl->WikiText = ModShaderSamplerWikiConst;
  cl->ParaWords = 3;
  cl->Shortcut = 'c';
  cl->Column = 6;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"TrickLight";
  cl->Label = L"TrickLight";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdTrickLight;
  cl->MakeGui = ModShaderSamplerGuiTrickLight;
  cl->SetDefaults = ModShaderSamplerDefTrickLight;
  cl->BindPara = ModShaderSamplerBindTrickLight;
  cl->Bind2Para = ModShaderSamplerBind2TrickLight;
  cl->Bind3Para = ModShaderSamplerBind3TrickLight;
  cl->WikiText = ModShaderSamplerWikiTrickLight;
  cl->ParaWords = 2;
  cl->Column = 6;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Mul";
  cl->Label = L"Mul";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdMul;
  cl->MakeGui = ModShaderSamplerGuiMul;
  cl->SetDefaults = ModShaderSamplerDefMul;
  cl->BindPara = ModShaderSamplerBindMul;
  cl->Bind2Para = ModShaderSamplerBind2Mul;
  cl->Bind3Para = ModShaderSamplerBind3Mul;
  cl->WikiText = ModShaderSamplerWikiMul;
  cl->Column = 6;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Add";
  cl->Label = L"Add";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdAdd;
  cl->MakeGui = ModShaderSamplerGuiAdd;
  cl->SetDefaults = ModShaderSamplerDefAdd;
  cl->BindPara = ModShaderSamplerBindAdd;
  cl->Bind2Para = ModShaderSamplerBind2Add;
  cl->Bind3Para = ModShaderSamplerBind3Add;
  cl->WikiText = ModShaderSamplerWikiAdd;
  cl->Column = 6;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Sub";
  cl->Label = L"Sub";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdSub;
  cl->MakeGui = ModShaderSamplerGuiSub;
  cl->SetDefaults = ModShaderSamplerDefSub;
  cl->BindPara = ModShaderSamplerBindSub;
  cl->Bind2Para = ModShaderSamplerBind2Sub;
  cl->Bind3Para = ModShaderSamplerBind3Sub;
  cl->WikiText = ModShaderSamplerWikiSub;
  cl->Column = 6;
  cl->Flags = 0x0001;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Diffuse";
  cl->Label = L"Diffuse";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdDiffuse;
  cl->MakeGui = ModShaderGuiDiffuse;
  cl->SetDefaults = ModShaderDefDiffuse;
  cl->BindPara = ModShaderBindDiffuse;
  cl->Bind2Para = ModShaderBind2Diffuse;
  cl->Bind3Para = ModShaderBind3Diffuse;
  cl->WikiText = ModShaderWikiDiffuse;
  cl->ParaWords = 2;
  cl->Shortcut = 'd';
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Gloss";
  cl->Label = L"Gloss";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdGloss;
  cl->MakeGui = ModShaderGuiGloss;
  cl->SetDefaults = ModShaderDefGloss;
  cl->BindPara = ModShaderBindGloss;
  cl->Bind2Para = ModShaderBind2Gloss;
  cl->Bind3Para = ModShaderBind3Gloss;
  cl->WikiText = ModShaderWikiGloss;
  cl->ParaWords = 2;
  cl->Shortcut = 'g';
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Emissive";
  cl->Label = L"Emissive";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdEmissive;
  cl->MakeGui = ModShaderGuiEmissive;
  cl->SetDefaults = ModShaderDefEmissive;
  cl->BindPara = ModShaderBindEmissive;
  cl->Bind2Para = ModShaderBind2Emissive;
  cl->Bind3Para = ModShaderBind3Emissive;
  cl->WikiText = ModShaderWikiEmissive;
  cl->ParaWords = 2;
  cl->Shortcut = 'e';
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Specular";
  cl->Label = L"Specular";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdSpecular;
  cl->MakeGui = ModShaderGuiSpecular;
  cl->SetDefaults = ModShaderDefSpecular;
  cl->BindPara = ModShaderBindSpecular;
  cl->Bind2Para = ModShaderBind2Specular;
  cl->Bind3Para = ModShaderBind3Specular;
  cl->WikiText = ModShaderWikiSpecular;
  cl->ParaWords = 2;
  cl->Shortcut = 'u';
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Aux";
  cl->Label = L"Aux";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdAux;
  cl->MakeGui = ModShaderGuiAux;
  cl->SetDefaults = ModShaderDefAux;
  cl->BindPara = ModShaderBindAux;
  cl->Bind2Para = ModShaderBind2Aux;
  cl->Bind3Para = ModShaderBind3Aux;
  cl->WikiText = ModShaderWikiAux;
  cl->ParaWords = 1;
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Alpha";
  cl->Label = L"Alpha";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdAlpha;
  cl->MakeGui = ModShaderGuiAlpha;
  cl->SetDefaults = ModShaderDefAlpha;
  cl->BindPara = ModShaderBindAlpha;
  cl->Bind2Para = ModShaderBind2Alpha;
  cl->Bind3Para = ModShaderBind3Alpha;
  cl->WikiText = ModShaderWikiAlpha;
  cl->ParaWords = 2;
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Kill";
  cl->Label = L"Kill";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdKill;
  cl->MakeGui = ModShaderGuiKill;
  cl->SetDefaults = ModShaderDefKill;
  cl->BindPara = ModShaderBindKill;
  cl->Bind2Para = ModShaderBind2Kill;
  cl->Bind3Para = ModShaderBind3Kill;
  cl->WikiText = ModShaderWikiKill;
  cl->ParaWords = 4;
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Displace";
  cl->Label = L"Displace";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdDisplace;
  cl->MakeGui = ModShaderGuiDisplace;
  cl->SetDefaults = ModShaderDefDisplace;
  cl->BindPara = ModShaderBindDisplace;
  cl->Bind2Para = ModShaderBind2Displace;
  cl->Bind3Para = ModShaderBind3Displace;
  cl->WikiText = ModShaderWikiDisplace;
  cl->ParaWords = 2;
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ExtrudeNormal";
  cl->Label = L"ExtrudeNormal";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdExtrudeNormal;
  cl->MakeGui = ModShaderGuiExtrudeNormal;
  cl->SetDefaults = ModShaderDefExtrudeNormal;
  cl->BindPara = ModShaderBindExtrudeNormal;
  cl->Bind2Para = ModShaderBind2ExtrudeNormal;
  cl->Bind3Para = ModShaderBind3ExtrudeNormal;
  cl->WikiText = ModShaderWikiExtrudeNormal;
  cl->ParaWords = 2;
  cl->Column = 4;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"NormalMap";
  cl->Label = L"NormalMap";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdNormalMap;
  cl->MakeGui = ModShaderGuiNormalMap;
  cl->SetDefaults = ModShaderDefNormalMap;
  cl->BindPara = ModShaderBindNormalMap;
  cl->Bind2Para = ModShaderBind2NormalMap;
  cl->Bind3Para = ModShaderBind3NormalMap;
  cl->WikiText = ModShaderWikiNormalMap;
  cl->Shortcut = 'n';
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"DoubleNormalMap";
  cl->Label = L"DoubleNormalMap";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdDoubleNormalMap;
  cl->MakeGui = ModShaderGuiDoubleNormalMap;
  cl->SetDefaults = ModShaderDefDoubleNormalMap;
  cl->BindPara = ModShaderBindDoubleNormalMap;
  cl->Bind2Para = ModShaderBind2DoubleNormalMap;
  cl->Bind3Para = ModShaderBind3DoubleNormalMap;
  cl->WikiText = ModShaderWikiDoubleNormalMap;
  cl->ParaWords = 1;
  cl->Column = 5;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(2);
  in[0].Type = ModShaderSamplerType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  in[1].Type = ModShaderSamplerType;
  in[1].DefaultClass = 0;
  in[1].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"BakedShadow";
  cl->Label = L"BakedShadow";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdBakedShadow;
  cl->MakeGui = ModShaderSamplerGuiBakedShadow;
  cl->SetDefaults = ModShaderSamplerDefBakedShadow;
  cl->BindPara = ModShaderSamplerBindBakedShadow;
  cl->Bind2Para = ModShaderSamplerBind2BakedShadow;
  cl->Bind3Para = ModShaderSamplerBind3BakedShadow;
  cl->WikiText = ModShaderSamplerWikiBakedShadow;
  cl->ParaWords = 14;
  cl->Column = 6;
  cl->Flags = 0x0000;
  in = cl->Inputs.AddMany(1);
  in[0].Type = Wz4MeshType;
  in[0].DefaultClass = 0;
  in[0].Flags = 0;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"ShadowGrab";
  cl->Label = L"ShadowGrab";
  cl->OutputType = ModShaderSamplerType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderSamplerCmdShadowGrab;
  cl->MakeGui = ModShaderSamplerGuiShadowGrab;
  cl->SetDefaults = ModShaderSamplerDefShadowGrab;
  cl->BindPara = ModShaderSamplerBindShadowGrab;
  cl->Bind2Para = ModShaderSamplerBind2ShadowGrab;
  cl->Bind3Para = ModShaderSamplerBind3ShadowGrab;
  cl->WikiText = ModShaderSamplerWikiShadowGrab;
  cl->ParaWords = 1;
  cl->Column = 6;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Tint";
  cl->Label = L"Tint";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdTint;
  cl->MakeGui = ModShaderGuiTint;
  cl->SetDefaults = ModShaderDefTint;
  cl->BindPara = ModShaderBindTint;
  cl->Bind2Para = ModShaderBind2Tint;
  cl->Bind3Para = ModShaderBind3Tint;
  cl->WikiText = ModShaderWikiTint;
  cl->ParaWords = 3;
  cl->Column = 7;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"Debug";
  cl->Label = L"Debug";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdDebug;
  cl->MakeGui = ModShaderGuiDebug;
  cl->SetDefaults = ModShaderDefDebug;
  cl->BindPara = ModShaderBindDebug;
  cl->Bind2Para = ModShaderBind2Debug;
  cl->Bind3Para = ModShaderBind3Debug;
  cl->WikiText = ModShaderWikiDebug;
  cl->ParaWords = 3;
  cl->Column = 7;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

  cl= new wClass;
  cl->Name = L"SphereFog";
  cl->Label = L"SphereFog";
  cl->OutputType = ModShaderType;
  cl->TabType = Wz4MtrlType;
  cl->Command = ModShaderCmdSphereFog;
  cl->MakeGui = ModShaderGuiSphereFog;
  cl->SetDefaults = ModShaderDefSphereFog;
  cl->BindPara = ModShaderBindSphereFog;
  cl->Bind2Para = ModShaderBind2SphereFog;
  cl->Bind3Para = ModShaderBind3SphereFog;
  cl->WikiText = ModShaderWikiSphereFog;
  cl->ParaWords = 6;
  cl->Column = 7;
  cl->Flags = 0x0000;
  Doc->Classes.AddTail(cl);

}

// sADDSUBSYSTEM(wz4_modmtrlmod_ops,0x110,AddOps_wz4_modmtrlmod_ops,0);


/****************************************************************************/


/****************************************************************************/
/***                                                                      ***/
/***   Computer generated code - do not modify                            ***/
/***                                                                      ***/
/****************************************************************************/

#ifndef HEADER_WZ4OPS_chaos_font_ops
#define HEADER_WZ4OPS_chaos_font_ops

#include "wz4lib/doc.hpp"

/****************************************************************************/

extern class ChaosFontType_ *ChaosFontType;

/****************************************************************************/

#line 9 "chaos_font_ops.ops"

  #include "wz4lib/basic_ops.hpp"
  #include "wz4lib/basic.hpp"
  #include "wz4frlib/wz4_demo2_ops.hpp"
  #include "wz4frlib/wz4_demo2.hpp"

#line 25 "chaos_font_ops.hpp"
class ChaosFontType_ : public BitmapBaseType_
{
public:
  ChaosFontType_() { Parent = BitmapBaseType; Flags = 0x0001; GuiSets = 0x0001; Symbol = L"ChaosFont"; Label = L"Chaos Font";  Init(); }
  ~ChaosFontType_() { Exit(); }
#line 28 "chaos_font_ops.ops"
  void Show(wObject *obj,wPaintInfo &pi);
#line 34 "chaos_font_ops.hpp"
};

struct ChaosFontParaFont
{
  sInt Size;
  sInt Height;
  sInt Width;
  sInt Style;
  sInt Safety;
  sInt Outline;
  sInt LineFeed;
};

struct ChaosFontParaMergeFont
{
};

struct ChaosFontParaAddSymbol
{
  sInt Start[2];
  sInt Size[2];
  sInt Char;
  sInt Count;
  sInt OffsetX;
  sInt AdjustY;
};


/****************************************************************************/

struct ChaosFontAnimFont
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosFontParaFont *para);

};

struct ChaosFontAnimMergeFont
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosFontParaMergeFont *para);

};

struct ChaosFontAnimAddSymbol
{
  void Init(class ScriptContext *sc);
  void Bind(class ScriptContext *sc,ChaosFontParaAddSymbol *para);

};


/****************************************************************************/

void AddTypes_chaos_font_ops(sBool secondary=0);
void AddOps_chaos_font_ops(sBool secondary=0);

/****************************************************************************/

#endif

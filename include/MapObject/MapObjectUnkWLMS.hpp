#pragma once

#include "MapObject/MapObject.hpp"
#include "MapObject/MapObjectProfile.hpp"
#include "MapObject/MapObjectUnkSTAT.hpp"
#include "Player/TouchControl.hpp"
#include "Render/ModelRender.hpp"
#include "Unknown/Common.hpp"
#include "Unknown/UnkStruct_ov000_020b1c10.hpp"
#include "Unknown/UnkStruct_ov094_02177ff8.hpp"
#include "global.h"
#include "types.h"

class UnkStruct_ov063_02163910 : public MapObject_UnkStruct1 {
public:
    UnkStruct_ov063_02163910(void *param1);

    /* 00 */ virtual void vfunc2_00() override;
    /* 04 */ virtual void vfunc2_04() override;
};

class MapObjectUnkWLMS : public UnkStruct_ov094_02177ff8 {
public:
    /* 000 (base) */
    /* 070 */ ModelRender mUnk_070;
    /* 0D0 */ UnkStruct_ov000_020b1c10 mUnk_0D0;
    /* 0F4 */ unk32 mUnk_0F4;
    /* 0F8 */ STRUCT_PAD(0x0F8, 0x2F4);
    /* 2F4 */ TouchControl mUnk_2F4;
    /* 316 */ unk16 mUnk_316;
    /* 318 */ unk16 mUnk_318;
    /* 31A */ unk16 mUnk_31A;
    /* 31C */ unk16 mUnk_31C;
    /* 31E */ unk8 mUnk_31E;
    /* 31F */ STRUCT_PAD(0x31F, 0x320);
    /* 320 */ UnkStruct_ov063_02163910 mUnk_320;

    MapObjectUnkWLMS();

    /* 38 */ virtual void vfunc_38(void) override;

    void func_ov063_0215fe74(void);
    void func_ov063_0215fe88(void);
    void func_ov063_0215feb0(void);
    void func_ov063_0215fff8(void);
    void func_ov063_02160030(void);
    void func_ov063_02160254(void);
    void func_ov063_02160548(void);
    void func_ov063_02160580(void);
    void func_ov063_02160688(void);
    void func_ov063_021606b4(void);
    void func_ov063_02160780(void);
    void func_ov063_02160880(void);
    void func_ov063_021608a8(void);
    void func_ov063_02160918(void);
    void func_ov063_02160938(void);
    void func_ov063_0216095c(void);
};

class MapObjectProfileUnkWLMS : public MapObjectProfileUnkSTAT_Base {
public:
    /* 00 (base) */

    MapObjectProfileUnkWLMS();

    /* 0C */ virtual MapObject *Create();

    static MapObjectProfileUnkWLMS *GetProfile();
};

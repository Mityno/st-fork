#include "MapObject/MapObjectUnkWLMS.hpp"
#include "Animation/CellAnimObject.hpp"
#include "LinkList.hpp"
#include "MapObject/MapObject.hpp"
#include "Player/TouchControl.hpp"
#include "Unknown/UnkStruct_0204a088.hpp"
#include "Unknown/UnkStruct_027e09bc.hpp"
#include "Unknown/UnkStruct_ov031_02118fa4.hpp"
#include "flags.h"
#include "global.h"
#include "nitro/math.h"
#include "nitro/mi.h"
#include "nns/g3d/g3d.h"
#include "profile.hpp"

struct UnkStruct_data_ov063_021638c8 {
    /* 00 */ unk32 mUnk_00;
    /* 04 */ unk16 mUnk_04;
    /* 06 */ unk16 mUnk_06;
    /* 08 */ unk32 mUnk_08;
    /* 0C */ unk32 mUnk_0C;
    /* 10 */ unk32 mUnk_10;
    /* 14 */ unk32 mUnk_14;
    /* 18 */ unk32 mUnk_18;
    /* 1C */ unk32 mUnk_1C;
};
extern UnkStruct_data_ov063_021638c8 data_ov063_021638c8;

extern MapObject_10 data_ov063_021646d8;
extern CellAnimObject data_ov063_02164514;
extern CellAnimObject data_ov063_0216458c;

// Overlay 9
extern "C" void func_ov009_020b669c(UnkStruct_ov031_02118fa4 *param1, unk32 param2, unk32 param3);

DECL_PROFILE(MapObjectProfileUnkWLMS);

MapObject *MapObjectProfileUnkWLMS::Create() {
    return new(HeapIndex_ITCM) MapObjectUnkWLMS();
}

MapObjectProfileUnkWLMS::MapObjectProfileUnkWLMS() :
    MapObjectProfileUnkSTAT_Base(MapObjectId_WLMS, MapObjectId_WLMS) {
    mUnk_D4.mUnk_08 = 0x2bc07006;
    VecFx32_Init(0, 0, 0, &mUnk_D4.mUnk_0C);
    mUnk_D4.mUnk_18.x = 0x800;
    mUnk_D4.mUnk_18.y = 0x1000;
    UNSET_FLAG2(mUnk_D4.mUnk_04, 1);
    mUnk_14 = 0x574c4d50;
    mUnk_0C = 0x1B33;
    mUnk_06 = -1;
    SET_FLAG2(mUnk_1E, 0);
}

UnkStruct_ov063_02163910::UnkStruct_ov063_02163910(void *param1) {
    mUnk_04 = (uintptr_t) param1;
}

struct UnkStruct_ov063_02163910_04 {
    /* 00 */ STRUCT_PAD(0x0, 0x40);
    /* 40 */ unk32 mUnk_40;
    /* 44 */ LinkListNode mUnk_44;
};
void UnkStruct_ov063_02163910::vfunc2_00() {

    void *ptr = mUnk_04p;
    if (ptr != NULL) {
        ptr = &((UnkStruct_ov063_02163910_04 *) mUnk_04p)->mUnk_40;
    }

    data_0204a088->func_ov000_020611dc(ptr, 7);
}

void UnkStruct_ov063_02163910::vfunc2_04() {
    LinkListImpl::Detach(&((UnkStruct_ov063_02163910_04 *) mUnk_04p)->mUnk_44);
}

MapObjectUnkWLMS::MapObjectUnkWLMS() :
    mUnk_070(G3d_GetModelPtr(GET_PROFILE(MapObjectProfileUnkWLMS)->mUnk_20.mUnk_50)),
    mUnk_0D0(&mUnk_0F4, 0x80),
    mUnk_2F4(),
    mUnk_31C(0),
    mUnk_31E(0),
    mUnk_320(this) {
    mUnk_10          = &data_ov063_021646d8;
    mUnk_0D0.mUnk_1C = 0x2000;
    mUnk_316         = -1;
    mUnk_318         = -1;
    mUnk_31A         = -1;

    MI_CpuFillFast(&mUnk_0F4, 0, 0x200);

    data_ov063_02164514.func_ov000_0206082c(0x2e, 1);
    data_ov063_02164514.func_ov000_02060bac();
    data_ov063_0216458c.func_ov000_0206082c(0x2e, 1);
    data_ov063_0216458c.func_ov000_02060bac();
}

bool MapObjectUnkWLMS::vfunc_00() {
    mUnk_18[0] = 0x14;
    if (mUnk_20.mParams[1] == 1) {
        mPos.x += 0x800;
    }
    this->func_ov063_02160580(0, 1);
    return true;
}

void MapObjectUnkWLMS::vfunc_38(void) {}

void MapObjectUnkWLMS::func_ov063_02160254(void) {}

void MapObjectUnkWLMS::func_ov063_02160548(void) {
    mUnk_0D0.mUnk_10.mUnk_04 = mUnk_0D0.mUnk_10.mUnk_00;
    mUnk_31A                 = mUnk_316;
    mUnk_316                 = -1;
    data_ov063_02164514.func_ov000_0206082c(0x2e, 1);
}

void MapObjectUnkWLMS::func_ov063_02160580(unk32 param1, unk32 param2) {}

unk32 MapObjectUnkWLMS::vfunc_28(unk32 param1, unk32 param2, unk32 param3) {
    if (!mState) {
        this->func_ov063_02160580(1, 0);
        return 0;
    }
    return -1;
}

void MapObjectUnkWLMS::vfunc_14() {}
void MapObjectUnkWLMS::vfunc_18(s8 *param1, s8 param2) {}

void MapObjectUnkWLMS::vfunc_60(void) {
    if (!data_ov031_02118fa4) {
        return;
    }
    func_ov009_020b669c(data_ov031_02118fa4, 1, 0);
}

void MapObjectUnkWLMS::vfunc_64(unk32 param1, unk32 param2) {

    if (mState == 1 && param2 == 1) {
        UnkStruct_data_ov063_021638c8 stackVar = data_ov063_021638c8;
        stackVar.mUnk_06                       = mAngle;
        data_027e09bc->mUnk_0C->func_ov000_0207834c(&mPos, &stackVar, 0);
    }
}

void MapObjectUnkWLMS::vfunc_68(void) {}
void MapObjectUnkWLMS::vfunc_6C(void) {}
void MapObjectUnkWLMS::vfunc_70(void) {}

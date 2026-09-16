#include "MapObject/MapObjectUnkWLMS.hpp"
#include "Actor/ActorUnkE3GL.hpp"
#include "Animation/CellAnimObject.hpp"
#include "FileSelect/FileSelectUnkDraw.hpp"
#include "LinkList.hpp"
#include "MapObject/MapObject.hpp"
#include "Player/TouchControl.hpp"
#include "Unknown/UnkStruct_0204a088.hpp"
#include "Unknown/UnkStruct_0204af1c.hpp"
#include "Unknown/UnkStruct_027e0954.hpp"
#include "Unknown/UnkStruct_027e09b8.hpp"
#include "Unknown/UnkStruct_027e09bc.hpp"
#include "Unknown/UnkStruct_ov031_02118fa4.hpp"
#include "flags.h"
#include "global.h"
#include "math.hpp"
#include "nitro/fx.h"
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
extern unk16 data_ov063_021638c0;
extern unk16 data_ov063_021638c2;
extern UnkStruct_data_ov063_021638c8 data_ov063_021638c8;
unk16 data_ov063_021638e8 = data_ov063_021638c8.mUnk_10;

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

    data_0204a088->func_ov000_020611dc((FileSelectManager_UnkDrawBase *) ptr, 7);
}

void UnkStruct_ov063_02163910::vfunc2_04() {
    LinkListImpl::Detach(&((UnkStruct_ov063_02163910_04 *) mUnk_04p)->mUnk_44);
}

MapObjectUnkWLMS::MapObjectUnkWLMS() :
    mUnk_70(G3d_GetModelPtr(GET_PROFILE(MapObjectProfileUnkWLMS)->mUnk_20.mUnk_50)),
    mUnk_D0(&mUnk_F4, 0x80),
    mUnk_2F4(),
    mUnk_31C(0),
    mUnk_31E(0),
    mUnk_320(this) {
    mUnk_10         = &data_ov063_021646d8;
    mUnk_D0.mUnk_1C = 0x2000;
    mUnk_316        = -1;
    mUnk_318        = -1;
    mUnk_31A        = -1;

    MI_CpuFillFast(&mUnk_F4, 0, 0x200);

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
    mUnk_D0.mUnk_10.mUnk_04 = mUnk_D0.mUnk_10.mUnk_00;
    mUnk_31A                = mUnk_316;
    mUnk_316                = -1;
    data_ov063_02164514.func_ov000_0206082c(0x2e, 1);
}

unk32 MapObjectUnkWLMS::func_ov063_02160580(unk32 param1, MapObjState param2) {
    mState = param2;
    switch (mState) {
        case 0:
            if (this->func_ov000_0209d29c(0)) {
                UNSET_FLAG(mFlags, 9);
            } else {
                SET_FLAG(mFlags, 9);
            }
            break;
        case 1: {
            UNSET_FLAG(mFlags, 9);
            stack_ov000_02073578 stack;
            GET_PROFILE(ActorProfileUnkE3GL)->GetProfile();
            break;
        }
        case 2:
            break;
        case 3:
            ActorUnkE3GL();
            break;
        case 4:
            mUnk_D0.mUnk_10.mUnk_04 = mUnk_D0.mUnk_10.mUnk_00;
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
    }
    return 1;
}

unk32 MapObjectUnkWLMS::vfunc_28(unk32 param1, unk32 param2, unk32 param3) {
    if (!mState) {
        this->func_ov063_02160580(1, 0);
        return 0;
    }
    return -1;
}

void MapObjectUnkWLMS::vfunc_14() {
    VecFx32 vec;
    VecFx32_Init(mPos.x, mPos.y + 0xb33, mPos.z + -0x733, &vec);
    mUnk_4C.vfunc_18(&vec);
    mUnk_70.vfunc_18(&vec);

    if (1 < (u16) (s16) (mState - 4)) {
        return;
    }

    if (mUnk_D0.mUnk_10.mUnk_04 - mUnk_D0.mUnk_10.mUnk_00 != 0) {
        UnkStruct_ov000_020b1c10 *ptr = &mUnk_D0;
        LinkListNode *node;
        if (ptr != NULL) {
            node = &ptr->mUnk_04;
        } else {
            node = (LinkListNode *) ptr;
        }
        data_027e0954->mUnk_00[1].mUnk_04.Prepend(node);
    }
}

void MapObjectUnkWLMS::vfunc_18(s8 *param1, s8 param2) {
    if (param1[0] != 0 && param1[1] != 0) {
        return;
    }

    unk16 *start = &mUnk_316;
    if (start < &mUnk_31C) {
        unk16 *ptr = start;
        do {
            unk16 val = *ptr;
            if (val >= 0) {
                u16 temp_x   = (&data_ov063_021638e8)[val * 2] + (&data_ov063_021638c0)[0];
                u16 temp_y   = (&data_ov063_021638e8 + 1)[val * 2] + (&data_ov063_021638c0)[1];
                u16 stack[2] = {temp_x, temp_y};

                if (ptr == start || ptr == &mUnk_31A) {
                    data_0204af1c.func_0201aad0(&data_ov063_02164514, &stack, 1, NULL);
                } else {
                    data_0204af1c.func_0201aad0(&data_ov063_0216458c, &stack, 1, NULL);
                }
            }
            ptr++;
        } while (ptr < &mUnk_31C);
    }
}

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
        data_027e09bc->mUnk_04[2]->func_ov000_0207834c(&mPos, &stackVar, 0);
    }
}

void MapObjectUnkWLMS::vfunc_68(void) {
    if (mState == 1) {
        this->func_ov063_02160580(2, 0);
    }
}

void MapObjectUnkWLMS::vfunc_6C(unk32 param1) {
    if (param1 == 2 && mUnk_318 < 0) {
        this->func_ov063_02160548();
    }
}

void MapObjectUnkWLMS::vfunc_70(unk32 param1, unk32 param2) {
    if (param1 == 1 && mState == 7 && param2 == 1) {
        data_027e09bc->mUnk_04[2]->func_ov000_02078230(0);

        if (mUnk_31E != 0) {
            this->func_ov000_0209d2c4(0, true);
        }

        this->func_ov063_02160580(0, 0);
    }
}

#include "Actor/ActorUnkKOTA.hpp"
#include "Actor/Actor.hpp"
#include "Actor/ActorId.hpp"
#include "Actor/ActorManager.hpp"
#include "CommonFuncs.hpp"
#include "RefStruct.hpp"
#include "Save/SaveFile.hpp"
#include "Save/SaveManager.hpp"
#include "System/Random.hpp"
#include "Unknown/UnkStruct_027e0cd8.hpp"
#include "nitro/fx.h"
#include "nitro/math.h"
#include "nitro/types.h"
#include <cstddef>

DECL_PROFILE(ActorProfileUnkKOTA);

Actor *ActorProfileUnkKOTA::Create() {
    return new(HeapIndex_2) ActorUnkKOTA();
}

ActorProfileUnkKOTA::ActorProfileUnkKOTA() :
    ActorProfile(ActorId_KOTA) {
    mUnk_24 = ActorId_KOAT;
}

ActorUnkKOTA::ActorUnkKOTA() :
    mUnk_D4((ActorUnkKOTA_D4 *) &mUnk_94),
    mUnk_D8(0),
    mUnk_DA(0) {}

bool ActorUnkKOTA::Init(unk32 param1) {
#pragma unused(param1)
    return true;
}

void ActorUnkKOTA::Setup(void) {
    for (unk32 i = 0; i < this->func_ov094_0216ed94(); i++) {
        this->func_ov094_0216e4f0();
        mUnk_D8++;
    }
    mUnk_DA = mUnk_D8;
}

void ActorUnkKOTA::vfunc_24(void) {
    this->Update();
}

void ActorUnkKOTA::Update(void) {
    for (unk32 i = mUnk_D8; i < this->func_ov094_0216ed94(); i++) {
        this->func_ov094_0216e4f0();
        mUnk_D8++;
    }
    mUnk_DA = mUnk_D8;
}

void ActorUnkKOTA::func_ov094_0216e4f0(void) {
    ActorParams params;
    params.mUnk_28.Reset();
    params.func_ov000_020975f8();
    this->func_ov094_0216e5a4(&params);

    RefStruct pOutRef;
    this->func_ov000_020973f4(&pOutRef, &data_ov000_020b539c_eur, ActorId_Cucco, &params, 0);

    Actor *actor = gpActorManager->func_01fff3b4(pOutRef);
    if (actor == NULL) {
        return;
    }

    if ((uintptr_t) ((unk32 *) GetUnkD4() - (unk32 *) &mUnk_94) >= 0x10) {
        return;
    }

    if (mUnk_D4 != NULL) {
        mUnk_D4->mUnk_00 = actor;
    }

    mUnk_D4++;
}

void ActorUnkKOTA::func_ov094_0216e5a4(ActorParams *param1) {}

// non-matching (a preview of hell itself, matching by parts) -> ~76%
void ActorUnkKOTA::func_ov094_0216e9fc(VecFx32 *param1, VecFx32 *param2, fx32 param3) {
    VecFx32_Copy(param2, param1);
    param1->y = data_027e0cd8->mUnk_0C->vfunc_28(param1, 1, 0);
    u16 below = 0, above = 0;
    for (fx32 *ptr = &mUnk_94; ptr != (fx32 *) mUnk_D4; ptr++) {
        if (*ptr != 0) {
            if (func_01ff9258(param2->x - *(ptr + 1), param2->z - *(ptr + 3)) > param3 / 2) {
                above++;
            } else {
                below++;
            }
        }
    }
    if ((u32) above > (u32) below) {
        s32 random_val = gRandom.Next32(param3 / 4);
        s16 angle      = (mUnk_D8 - mUnk_DA) * (0xFFFF / (this->func_ov094_0216ed94() - mUnk_DA));
        fx16 sin_val   = SIN(angle);
        fx16 cos_val   = COS(angle);
        param1->x += FX_Mul(sin_val, random_val);
        param1->z += FX_Mul(cos_val, random_val);
    } else if (above == below) {
        s32 random_val = gRandom.Next32(param3 - param3 / 4);
        s16 angle      = (mUnk_D8 - mUnk_DA) * (0xFFFF / (this->func_ov094_0216ed94() - mUnk_DA));
        fx16 sin_val   = SIN(angle);
        fx16 cos_val   = COS(angle);
        param1->x += FX_Mul(sin_val, random_val);
        param1->z += FX_Mul(cos_val, random_val);
    } else {
        s32 random_val = gRandom.Next32(param3 - param3 / 2);
        s16 angle      = (mUnk_D8 - mUnk_DA) * (0xFFFF / (this->func_ov094_0216ed94() - mUnk_DA));
        fx16 sin_val   = SIN(angle);
        fx16 cos_val   = COS(angle);
        param1->x += FX_Mul(sin_val, random_val);
        param1->z += FX_Mul(cos_val, random_val);
    }
}

// non-matching (load offset pattern)
unk32 ActorUnkKOTA::func_ov094_0216ed94(void) {
    u16 uVar2;
    u16 *array = &gSaveManager.GetUnk000()->unk_B78.unk_08;
    if (mUnk_5C.mParams[0] == 0) {
        uVar2 = array[1];
    } else {
        uVar2 = array[4];
    }

    if (mUnk_5C.mParams[2] != 0 && uVar2 > mUnk_5C.mParams[2]) {
        uVar2 = mUnk_5C.mParams[2];
    }
    return uVar2;
}

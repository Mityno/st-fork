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
#include "math.hpp"
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
    mUnk_D4(mUnk_94),
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

    if ((GetUnkD4() - (volatile Actor **) &mUnk_94) >= ARRAY_LEN_U(mUnk_94)) {
        return;
    }

    if (mUnk_D4 != NULL) {
        *mUnk_D4 = actor;
    }

    mUnk_D4++;
}

// non-matching (stack layout, grandom stuff)
void ActorUnkKOTA::func_ov094_0216e5a4(ActorParams *param1) {
    UnkStruct_027e0cd8_0C_Base_148_00 *ret = NULL;
    if (mUnk_5C.mParams[1] != 0) {
        ret = data_027e0cd8->mUnk_0C->func_ov000_02080620(mUnk_5C.mParams[1]);
    }

    if (ret == NULL) {
        this->func_ov094_0216e9fc(&param1->mInitialPos, &mPos, FX_F32_TO_FX32(5.f));
        return;
    }

    if (ret->vfunc_04() == 0) {
        VecFx32 vecBase = ret->mUnk_14.unk_00;
        VecFx32_Add(&vecBase, &ret->mUnk_14.unk_0C, &vecBase);
        func_01ff93c0(&vecBase, FX_F32_TO_FX32(0.5f));
        vecBase.y = data_027e0cd8->mUnk_0C->vfunc_28(&vecBase, 1, 0);

        VecFx32 vecRet;
        u16 arrayCmp[4] = {0, 0, 0, 0};
        for (Actor **ptr = mUnk_94; ptr != mUnk_D4; ptr++) {
            if (*ptr != NULL) {
                func_01ffb714(&(*ptr)->mPos, &vecBase, &vecRet);

                if (vecRet.x <= 0) {
                    if (vecRet.z <= 0) {
                        arrayCmp[0]++;
                    } else {
                        arrayCmp[1]++;
                    }
                } else {
                    if (vecRet.z <= 0) {
                        arrayCmp[2]++;
                    } else {
                        arrayCmp[3]++;
                    }
                }
            }
        }

        u32 var1 = 0, var2 = 0;
        while (var2 < 3) {
            if (arrayCmp[var1] > arrayCmp[var2] ||
                (arrayCmp[var1] == arrayCmp[var2] && (gRandom.Next32(0) & 0x80000000) != 0)) {
                var1 = var2;
            }
            var2++;
        }

        Vec2bCpp sp12(0, 0), sp14(0, 0);
        switch (var1) {
            case 0: {
                Vec2bCpp vec2b1, vec2b2;
                func_01ffedac(&vec2b1, &ret->mUnk_14.unk_00);
                sp14.data[0] = vec2b1.data[0];

                func_01ffedac(&vec2b2, &vecBase);
                sp12.data[0] = vec2b2.data[0];
                break;
            }
            case 1: {
                Vec2bCpp vec2b1, vec2b2;
                VecFx32 vec1, vec2;
                VecFx32_Init(ret->mUnk_14.unk_00.x, 0, vecBase.z, &vec1);
                func_01ffedac(&vec2b1, &vec1);
                sp14.data[0] = vec2b1.data[0];

                VecFx32_Init(vecBase.x, 0, ret->mUnk_14.unk_0C.z, &vec2);
                func_01ffedac(&vec2b2, &vec2);
                sp12.data[0] = vec2b2.data[0];
                break;
            }
            case 2: {
                Vec2bCpp vec2b1, vec2b2;
                VecFx32 vec1, vec2;
                VecFx32_Init(vecBase.x, 0, ret->mUnk_14.unk_00.z, &vec1);
                func_01ffedac(&vec2b1, &vec1);
                sp14.data[0] = vec2b1.data[0];

                VecFx32_Init(ret->mUnk_14.unk_00.x, 0, vecBase.z, &vec2);
                func_01ffedac(&vec2b2, &vec2);
                sp12.data[0] = vec2b2.data[0];
                break;
            }
            case 3: {
                Vec2bCpp vec2b1, vec2b2;
                VecFx32 vec1;
                VecFx32_Init(vecBase.x, 0, vecBase.z, &vec1);
                func_01ffedac(&vec2b1, &vec1);
                sp14.data[0] = vec2b1.data[0];

                func_01ffedac(&vec2b2, &ret->mUnk_14.unk_0C);
                sp12.data[0] = vec2b2.data[0];
                break;
            }
        }

        Vec2bCpp random_val, tmp;
        tmp.x              = gRandom.Next32((sp12.x - sp14.x) + 1);
        tmp.y              = gRandom.Next32((sp12.y - sp14.y) + 1);
        random_val.data[0] = tmp.data[0];
        func_ov000_0205ad90(random_val.GetDataU32(), &param1->mInitialPos);
        func_01ffb714(&vecBase, &param1->mInitialPos, &vecRet);
        func_01ff9770(&vecRet, 0xC00);
        VecFx32_Add(&param1->mInitialPos, &vecRet, &param1->mInitialPos);
        return;
    }

    if (ret->vfunc_04() == 1) {
        this->func_ov094_0216e9fc(&param1->mInitialPos, &ret->mUnk_14.unk_00, ret->mUnk_14.unk_0C.x);
    } else {
        this->func_ov094_0216e9fc(&param1->mInitialPos, &mPos, FX_F32_TO_FX32(5.f));
    }
}

// non-matching (a preview of hell itself, some parts match) -> ~76%
void ActorUnkKOTA::func_ov094_0216e9fc(VecFx32 *param1, VecFx32 *param2, fx32 param3) {
    VecFx32_Copy(param2, param1);
    param1->y = data_027e0cd8->mUnk_0C->vfunc_28(param1, 1, 0);
    u16 below = 0, above = 0;
    for (Actor **ptr = mUnk_94; ptr != mUnk_D4; ptr++) {
        if (*ptr != NULL) {
            if (func_01ff9258(param2->x - (*ptr)->mPos.x, param2->z - (*ptr)->mPos.z) > param3 / 2) {
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

unk32 ActorUnkKOTA::func_ov094_0216ed94(void) {
    u16 uVar2;
    SaveManager_00 *saveManager = gSaveManager.GetUnk000();
    if (mUnk_5C.mParams[0] == 0) {
        uVar2 = saveManager->unk_B78.unk_0A;
    } else {
        uVar2 = saveManager->unk_B78.unk_10;
    }

    if (mUnk_5C.mParams[2] != 0 && uVar2 > mUnk_5C.mParams[2]) {
        uVar2 = mUnk_5C.mParams[2];
    }
    return uVar2;
}

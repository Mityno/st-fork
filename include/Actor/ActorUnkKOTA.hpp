#pragma once

#include "Actor/Actor.hpp"
#include "Actor/ActorProfile.hpp"
#include "global.h"
#include "nitro/types.h"
#include "types.h"

class ActorUnkKOTA_C4 : public Actor_C4 {
public:
    ActorUnkKOTA_C4(Actor *param1);

    /* 00 */ virtual bool vfunc_00(RefStruct ref, unk32 param2) override;
    /* 04 */ virtual bool vfunc_04() override;
    /* 08 */ virtual void vfunc_08() override;
    /* 0C */ virtual void vfunc_0C(unk32 param1) override;
};

struct ActorUnkKOTA_D4 {
    /* 00 */ Actor *mUnk_00;

    ActorUnkKOTA_D4(Actor *param1) :
        mUnk_00(param1) {}
};

class ActorUnkKOTA : public Actor {
public:
    /* 00 (base) */
    /* 94 */ unk32 mUnk_94;
    /* 98 */ PAD(0x98, 0xD4);
    /* D4 */ ActorUnkKOTA_D4 *mUnk_D4;
    /* D8 */ u16 mUnk_D8;
    /* DA */ u16 mUnk_DA;
    /* DC */

    ActorUnkKOTA();

    /* 18 */ virtual bool Init(unk32 param1);
    /* 1C */ virtual void Setup();
    /* 20 */ virtual void Update();
    /* 24 */ virtual void vfunc_24();

    void func_ov094_0216e4f0(void);
    void func_ov094_0216e5a4(ActorParams *param1);
    void func_ov094_0216e9fc(VecFx32 *param1, VecFx32 *param2, fx32 param3);
    unk32 func_ov094_0216ed94(void);

    volatile ActorUnkKOTA_D4 *GetUnkD4() const {
        return mUnk_D4;
    }
};

class ActorProfileUnkKOTA : public ActorProfile {
public:
    /* 00 (base) */

    ActorProfileUnkKOTA();

    /* 0C */ virtual Actor *Create();

    static ActorProfileUnkKOTA *GetProfile();
};

#ifndef CADDIE_SCENE_UI_TIMER_DATA_H
#define CADDIE_SCENE_UI_TIMER_DATA_H

#include <caddie/ui/caddieTextBox.h>

#include "types_caddie.h"

#include <nw4r/math.h>
#include <nw4r/ut.h>

namespace caddie {

    class TimerData {
    public:
        static const u32 mAbsMaxTimesSaved = 20;

        TimerData();
        ~TimerData();

        void EnterTime(u32 timeValue);

        void ResetData();

        u32 GetBestTime() const;
        u32 GetWorstTime() const;
        u32 GetAverageTime() const;

        virtual void Calc();
        virtual void Draw();

    private:
        u32 mCurrMaxTimesSaved;
        u32 mCurrTimesSaved;
        u32 mNextIndex;

        u32 mSavedTimeValues[mAbsMaxTimesSaved];

        TextBox mTextBox;

    // default timer data position on screen
    static const nw4r::math::VEC2 sTimerDataPos;

    };

}

#endif // CADDIE_SCENE_UI_TIMER_DATA_H
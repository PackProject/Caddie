#include "caddie/ui/timer/caddieTimerData.h"
#include "caddie/ui/caddieTextBox.h"

#include <cstdio>
#include <cstring>

#include <nw4r/math.h>

namespace caddie {

    TimerData::TimerData()
        : mCurrMaxTimesSaved(10),
        mCurrTimesSaved(0),
        mNextIndex(0),
        mTextBox() {}

    const nw4r::math::VEC2 TimerData::sTimerDataPos(25.0f, 375.0f);

    TimerData::~TimerData() {}

    void TimerData::EnterTime(u32 timeValue) {
        mSavedTimeValues[mNextIndex] = timeValue;

        mNextIndex++;

        if (mNextIndex >= mCurrMaxTimesSaved) {
            mNextIndex = 0;
        }

        if (mCurrTimesSaved < mCurrMaxTimesSaved) {
            mCurrTimesSaved++;
        }
    }

    void TimerData::ResetData() {
        mCurrTimesSaved = 0;
        mNextIndex = 0;
        for(u32 i = 0; i < mAbsMaxTimesSaved; i++) {
            mSavedTimeValues[i] = 0;
        }
    }

    u32 TimerData::GetBestTime() const {
        if (mCurrMaxTimesSaved == 0) return 0;

        u32 bestTime = mSavedTimeValues[0];
        for (u32 i = 1; i < mCurrTimesSaved; i++) {
            if(mSavedTimeValues[i] < bestTime) {
                bestTime = mSavedTimeValues[i];
            }
        }
        return bestTime;
    }

    u32 TimerData::GetWorstTime() const {
        if (mCurrMaxTimesSaved == 0) return 0;

        u32 worstTime = mSavedTimeValues[0];
        for (u32 i = 1; i < mCurrTimesSaved; i++) {
            if(mSavedTimeValues[i] > worstTime) {
                worstTime = mSavedTimeValues[i];
            }
        }
        return worstTime;
    }

    u32 TimerData::GetAverageTime() const {
        if (mCurrMaxTimesSaved == 0) return 0;

        u32 totalTime = 0;
        for (u32 i = 0; i < mCurrTimesSaved; i++) {
            totalTime += mSavedTimeValues[i];
        }
        u32 averageTime = totalTime / mCurrTimesSaved;
        return averageTime;
    }

    u32 TimerData::GetLatestTime() const {
        if (mCurrMaxTimesSaved == 0) return 0;

        u32 latestTime;

        if(mNextIndex == 0) {
            latestTime = mSavedTimeValues[mCurrTimesSaved - 1];
        } else {
            latestTime = mSavedTimeValues[mNextIndex - 1];
        }

        return latestTime;
    }

    void TimerData::Calc() {
        mTextBox.SetPosition(sTimerDataPos);
        float bestTime = GetBestTime() / 60.0f;
        float worstTime = GetWorstTime() / 60.0f;
        float averageTime = GetAverageTime() / 60.0f;
        float latestTime = GetLatestTime() / 60.0f;
        float latestTimeDiff = latestTime - averageTime;
        const char* latestTimeNotation = (latestTimeDiff < 0) ? "-" : "+";
        mTextBox.SetTextFmt(
            "Latest: %.2f (%s%.2f)\nBest: %.2f\nWorst: %.2f\nAverage: %.2f\n", 
            latestTime, latestTimeNotation, latestTimeDiff, bestTime, worstTime, averageTime
        );
        mTextBox.SetStroke(TextBox::STROKE_OUTLINE);
    }

    void TimerData::Draw() {
        mTextBox.Draw();
    }

}
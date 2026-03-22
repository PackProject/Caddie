#include "caddieSceneHookMgr.h"

#include <RP/RPSystem.h>

namespace caddie {
namespace {

/**
 * @brief Get current scene's ID
 */
s32 GetCurrentSceneID() {
    return RPSysSceneMgr::getInstance().getCurrentSceneID();
}

/**
 * @brief Get current scene
 */
RPSysScene* GetCurrentScene() {
    return static_cast<RPSysScene*>(
        RPSysSceneMgr::getInstance().getCurrentScene());
}

} // namespace

/**
 * @brief Dispatch scene hook Configure callback
 */
void SceneHookMgr::DoConfigure() {
    const s32 scene = GetCurrentSceneID();
    const SceneHookMgr& hookMgr = SceneHookMgr::GetInstance();

    if (hookMgr.mSceneHooks[scene].onConfigure != NULL) {
        hookMgr.mSceneHooks[scene].onConfigure(GetCurrentScene());
    }

    if (hookMgr.mGlobalSceneHook.onConfigure != NULL) {
        hookMgr.mGlobalSceneHook.onConfigure(GetCurrentScene());
    }
}
CADDIE_LOCALIZE(kmBranch(0x801c389c, SceneHookMgr::DoConfigure), // NTSC_U
                kmBranch(0x801c389c, SceneHookMgr::DoConfigure), // PAL
                kmBranch(0x801c389c, SceneHookMgr::DoConfigure), // NTSC_J
                CADDIE_NOTIMPLEMENTED                            // KOR
);

/**
 * @brief Dispatch scene hook Calculate callback
 */
void SceneHookMgr::DoCalculate() {
    const s32 scene = GetCurrentSceneID();
    const SceneHookMgr& hookMgr = SceneHookMgr::GetInstance();

    if (hookMgr.mSceneHooks[scene].onCalculate != NULL) {
        hookMgr.mSceneHooks[scene].onCalculate(GetCurrentScene());
    }

    if (hookMgr.mGlobalSceneHook.onCalculate != NULL) {
        hookMgr.mGlobalSceneHook.onCalculate(GetCurrentScene());
    }
}
CADDIE_LOCALIZE(kmBranch(0x8022f8f8, SceneHookMgr::DoCalculate), // NTSC_U
                kmBranch(0x80232c64, SceneHookMgr::DoCalculate), // PAL
                kmBranch(0x8022f8f8, SceneHookMgr::DoCalculate), // NTSC_J
                CADDIE_NOTIMPLEMENTED                            // KOR
);

/**
 * @brief Dispatch scene hook UserDraw callback
 */
void SceneHookMgr::DoUserDraw() {
    const s32 scene = GetCurrentSceneID();
    const SceneHookMgr& hookMgr = SceneHookMgr::GetInstance();

    if (hookMgr.mSceneHooks[scene].onUserDraw != NULL) {
        hookMgr.mSceneHooks[scene].onUserDraw(GetCurrentScene());
    }

    if (hookMgr.mGlobalSceneHook.onUserDraw != NULL) {
        hookMgr.mGlobalSceneHook.onUserDraw(GetCurrentScene());
    }
}
CADDIE_LOCALIZE(kmBranch(0x802542a8, SceneHookMgr::DoUserDraw), // NTSC_U
                kmBranch(0x802545c8, SceneHookMgr::DoUserDraw), // PAL
                kmBranch(0x802541f8, SceneHookMgr::DoUserDraw), // NTSC_J
                CADDIE_NOTIMPLEMENTED                           // KOR
);

/**
 * @brief Dispatch scene hook Exit callback
 */
void SceneHookMgr::DoExit() {
    const s32 scene = GetCurrentSceneID();
    const SceneHookMgr& hookMgr = SceneHookMgr::GetInstance();

    if (hookMgr.mSceneHooks[scene].onExit != NULL) {
        hookMgr.mSceneHooks[scene].onExit(GetCurrentScene());
    }

    if (hookMgr.mGlobalSceneHook.onExit != NULL) {
        hookMgr.mGlobalSceneHook.onExit(GetCurrentScene());
    }
}
CADDIE_LOCALIZE(kmBranch(0x8022f6f4, SceneHookMgr::DoExit), // NTSC_U
                kmBranch(0x8022f96c, SceneHookMgr::DoExit), // PAL
                kmBranch(0x8022f6f4, SceneHookMgr::DoExit), // NTSC_J
                CADDIE_NOTIMPLEMENTED                       // KOR
);

/**
 * @brief Update pause manager
 */
void SceneHookMgr::DoUpdatePause() {
    const s32 scene = GetCurrentSceneID();
    const SceneHookMgr& hookMgr = SceneHookMgr::GetInstance();

    if (hookMgr.mPauseSetting[scene]) {
        RPSysPauseMgr::getInstance().update();
    }
}
CADDIE_LOCALIZE(kmCall(0x80232984, SceneHookMgr::DoUpdatePause), // NTSC_U
                kmCall(0x80232c50, SceneHookMgr::DoUpdatePause), // PAL
                kmCall(0x80232938, SceneHookMgr::DoUpdatePause), // NTSC_J
                CADDIE_NOTIMPLEMENTED                            // KOR
);

} // namespace caddie

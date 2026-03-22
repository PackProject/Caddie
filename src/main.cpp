#include "caddieCmnGlobalSceneHook.h"
#include "caddieGlfSceneHook.h"
#include "caddieMapFile.h"
#include "caddieRuntime.h"
#include "caddieSceneHookMgr.h"

#include <RP/RPSystem.h>
#include <egg/core.h>
#include <egg/util.h>

namespace caddie {

static const char* MAPFILE_PATH =
    "modules/main_" CADDIE_LOCALIZE("NTSC_U", "PAL", "NTSC_J", "KOR") ".map";

/**
 * @brief Mod entrypoint
 */
void main() {
    // Initialize heap
    MemManager::Initialize();

#if !defined(NDEBUG)
    // Always show exception handler
    static const u16 scEmptyCombo[] = {0};
    EGG::Exception::setUserCallback(scEmptyCombo);

    MapFile::GetInstance().LoadFromDVD(MAPFILE_PATH, MapFile::LINK_DYNAMIC);
#endif

    // Skip MotionPlus video
    RPSysProjectLocal::getInstance().setMPlusVideoSeen(true);

    // Global scene hook
    SceneHookMgr::GetInstance().SetHook(
        RPSysSceneCreator::SCENE_ALL,
        (SceneHook){GlobalSceneHook::OnConfigure, GlobalSceneHook::OnCalculate,
                    GlobalSceneHook::OnUserDraw, GlobalSceneHook::OnExit});

    // Golf scene hook
    SceneHookMgr::GetInstance().SetHook(
        RPSysSceneCreator::SCENE_GLF,
        (SceneHook){GlfSceneHook::OnConfigure, GlfSceneHook::OnCalculate,
                    GlfSceneHook::OnUserDraw, GlfSceneHook::OnExit});
    // Disable pausing in the Golf scene
    SceneHookMgr::GetInstance().AllowPause(RPSysSceneCreator::SCENE_GLF, false);

    SceneHookMgr::GetInstance().SetHook(
        RPSysSceneCreator::SCENE_DGL,
        (SceneHook){GlfSceneHook::OnConfigure, GlfSceneHook::OnCalculate,
                    GlfSceneHook::OnUserDraw, GlfSceneHook::OnExit});

    SceneHookMgr::GetInstance().AllowPause(RPSysSceneCreator::SCENE_DGL, false);
}
CADDIE_LOCALIZE(kmBranch(0x80230b60, main), // NTSC_U
                kmBranch(0x80230e2c, main), // PAL
                kmBranch(0x80230b14, main), // NTSC_J
                CADDIE_NOTIMPLEMENTED       // KOR
);

} // namespace caddie

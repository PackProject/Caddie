#include "types_caddie.h"

namespace caddie {
namespace {

/**
 * @brief Remove AB check
 */
bool IsABCheckAll() { return true; }
CADDIE_LOCALIZE(kmBranch(0x8026a298, IsABCheckAll), // NTSC_U
                kmBranch(0x8026a5b8, IsABCheckAll), // PAL
                kmBranch(0x8026a1e8, IsABCheckAll), // NTSC_J
                CADDIE_NOTIMPLEMENTED               // KOR
);

} // namespace
} // namespace caddie

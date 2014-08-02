/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2014 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MENU_COMMON_BACKEND_H
#define _MENU_COMMON_BACKEND_H

#include "../menu_common.h"

#ifndef GFX_MAX_PARAMETERS
#define GFX_MAX_PARAMETERS 64
#endif

#ifndef MAX_COUNTERS
#define MAX_COUNTERS 64
#endif

typedef enum
{
   // Shader stuff
   MENU_SETTINGS_GENERAL_OPTIONS = MENU_START_SCREEN + 1,
   MENU_SETTINGS_VIDEO_OPTIONS,
   MENU_SETTINGS_VIDEO_OPTIONS_FIRST,
   MENU_SETTINGS_VIDEO_HW_SHARED_CONTEXT,
   MENU_SETTINGS_VIDEO_RESOLUTION,
   MENU_SETTINGS_VIDEO_PAL60,
   MENU_SETTINGS_VIDEO_FILTER,
   MENU_SETTINGS_VIDEO_SOFT_FILTER,
   MENU_SETTINGS_FLICKER_FILTER,
   MENU_SETTINGS_SOFT_DISPLAY_FILTER,
   MENU_SETTINGS_VIDEO_GAMMA,
   MENU_SETTINGS_VIDEO_INTEGER_SCALE,
   MENU_SETTINGS_VIDEO_ASPECT_RATIO,
   MENU_SETTINGS_CUSTOM_VIEWPORT,
   MENU_SETTINGS_CUSTOM_VIEWPORT_2,
   MENU_SETTINGS_TOGGLE_FULLSCREEN,
   MENU_SETTINGS_VIDEO_THREADED,
   MENU_SETTINGS_VIDEO_ROTATION,
   MENU_SETTINGS_VIDEO_VSYNC,
   MENU_SETTINGS_VIDEO_HARD_SYNC,
   MENU_SETTINGS_VIDEO_HARD_SYNC_FRAMES,
   MENU_SETTINGS_VIDEO_BLACK_FRAME_INSERTION,
   MENU_SETTINGS_VIDEO_SWAP_INTERVAL,
   MENU_SETTINGS_VIDEO_WINDOW_SCALE_X,
   MENU_SETTINGS_VIDEO_WINDOW_SCALE_Y,
   MENU_SETTINGS_VIDEO_CROP_OVERSCAN,
   MENU_SETTINGS_VIDEO_REFRESH_RATE,
   MENU_SETTINGS_VIDEO_REFRESH_RATE_AUTO,
   MENU_SETTINGS_VIDEO_MONITOR_INDEX,
   MENU_SETTINGS_VIDEO_SOFTFILTER,
   MENU_SETTINGS_VIDEO_OPTIONS_LAST,
   MENU_SETTINGS_FONT_OPTIONS,
   MENU_SETTINGS_FONT_ENABLE,
   MENU_SETTINGS_FONT_SIZE,
   MENU_SETTINGS_SLOWMOTION_RATIO,
   MENU_SETTINGS_FASTFORWARD_RATIO,
   MENU_SETTINGS_LOAD_DUMMY_ON_CORE_SHUTDOWN,
   MENU_SETTINGS_SHADER_OPTIONS,
   MENU_SETTINGS_SHADER_FILTER,
   MENU_SETTINGS_SHADER_PRESET,
   MENU_SETTINGS_SHADER_APPLY,
   MENU_SETTINGS_SHADER_PARAMETERS, // Modifies current shader directly. Will not get saved to CGP.
   MENU_SETTINGS_SHADER_PRESET_PARAMETERS, // Modifies shader preset currently in menu.
   MENU_SETTINGS_SHADER_PASSES,
   MENU_SETTINGS_SHADER_PARAMETER_0,
   MENU_SETTINGS_SHADER_PARAMETER_LAST = MENU_SETTINGS_SHADER_PARAMETER_0 + (GFX_MAX_PARAMETERS - 1),
   MENU_SETTINGS_SHADER_0,
   MENU_SETTINGS_SHADER_0_FILTER,
   MENU_SETTINGS_SHADER_0_SCALE,
   MENU_SETTINGS_SHADER_LAST = MENU_SETTINGS_SHADER_0_SCALE + (3 * (GFX_MAX_SHADERS - 1)),
   MENU_SETTINGS_SHADER_PRESET_SAVE,

   // settings options are done here too
   MENU_SETTINGS_OPEN_FILEBROWSER,
   MENU_SETTINGS_OPEN_FILEBROWSER_DEFERRED_CORE,
   MENU_SETTINGS_OPEN_HISTORY,
   MENU_SETTINGS_CORE,
   MENU_SETTINGS_CORE_INFO,
   MENU_SETTINGS_DEFERRED_CORE,
   MENU_SETTINGS_CONFIG,
   MENU_SETTINGS_SAVE_CONFIG,
   MENU_SETTINGS_CORE_OPTIONS,
   MENU_SETTINGS_AUDIO_OPTIONS,
   MENU_SETTINGS_INPUT_OPTIONS,
   MENU_SETTINGS_PATH_OPTIONS,
   MENU_SETTINGS_OVERLAY_OPTIONS,
   MENU_SETTINGS_USER_OPTIONS,
   MENU_SETTINGS_NETPLAY_OPTIONS,
   MENU_SETTINGS_PRIVACY_OPTIONS,
   MENU_SETTINGS_OPTIONS,
   MENU_SETTINGS_DRIVERS,
   MENU_SETTINGS_PERFORMANCE_COUNTERS,
   MENU_SETTINGS_PERFORMANCE_COUNTERS_LIBRETRO,
   MENU_SETTINGS_PERFORMANCE_COUNTERS_FRONTEND,
   MENU_SETTINGS_REWIND_ENABLE,
   MENU_SETTINGS_LIBRETRO_LOG_LEVEL,
   MENU_SETTINGS_LOGGING_VERBOSITY,
   MENU_SETTINGS_PERFORMANCE_COUNTERS_ENABLE,
   MENU_SETTINGS_REWIND_GRANULARITY,
   MENU_SETTINGS_CONFIG_SAVE_ON_EXIT,
   MENU_SETTINGS_PER_CORE_CONFIG,
   MENU_SETTINGS_SRAM_AUTOSAVE,
   MENU_SETTINGS_SAVESTATE_SAVE,
   MENU_SETTINGS_SAVESTATE_LOAD,
   MENU_SETTINGS_DISK_OPTIONS,
   MENU_SETTINGS_DISK_INDEX,
   MENU_SETTINGS_DISK_APPEND,
   MENU_SETTINGS_DRIVER_VIDEO,
   MENU_SETTINGS_DRIVER_AUDIO,
   MENU_SETTINGS_DRIVER_AUDIO_DEVICE,
   MENU_SETTINGS_DRIVER_AUDIO_RESAMPLER,
   MENU_SETTINGS_DRIVER_INPUT,
   MENU_SETTINGS_DRIVER_CAMERA,
   MENU_SETTINGS_DRIVER_LOCATION,
   MENU_SETTINGS_DRIVER_MENU,
   MENU_SETTINGS_SCREENSHOT,
   MENU_SETTINGS_GPU_SCREENSHOT,
   MENU_SETTINGS_SAVESTATE_AUTO_SAVE,
   MENU_SETTINGS_SAVESTATE_AUTO_LOAD,
   MENU_SETTINGS_BLOCK_SRAM_OVERWRITE,
   MENU_SETTINGS_WINDOW_COMPOSITING_ENABLE,
   MENU_SETTINGS_PAUSE_IF_WINDOW_FOCUS_LOST,
   MENU_CONTENT_HISTORY_SIZE,
   MENU_SCREENSHOT_DIR_PATH,
   MENU_BROWSER_DIR_PATH,
   MENU_CONTENT_HISTORY_PATH,
   MENU_CONTENT_DIR_PATH,
   MENU_ASSETS_DIR_PATH,
   MENU_FILTER_DIR_PATH,
   MENU_DSP_FILTER_DIR_PATH,
   MENU_SHADER_DIR_PATH,
   MENU_SAVESTATE_DIR_PATH,
   MENU_SAVEFILE_DIR_PATH,
   MENU_LIBRETRO_DIR_PATH,
   MENU_LIBRETRO_INFO_DIR_PATH,
   MENU_CONFIG_DIR_PATH,
   MENU_OVERLAY_DIR_PATH,
   MENU_SYSTEM_DIR_PATH,
   MENU_AUTOCONFIG_DIR_PATH,
   MENU_EXTRACTION_DIR_PATH,
   MENU_SETTINGS_RESTART_GAME,
   MENU_SETTINGS_AUDIO_DSP_FILTER,
   MENU_SETTINGS_AUDIO_ENABLE,
   MENU_SETTINGS_AUDIO_MUTE,
   MENU_SETTINGS_AUDIO_LATENCY,
   MENU_SETTINGS_AUDIO_SYNC,
   MENU_SETTINGS_AUDIO_CONTROL_RATE_DELTA,
   MENU_SETTINGS_AUDIO_VOLUME,
   MENU_SETTINGS_CUSTOM_BGM_CONTROL_ENABLE,
   MENU_SETTINGS_ZIP_EXTRACT,
   MENU_SETTINGS_DEBUG_TEXT,
   MENU_SETTINGS_RESTART_EMULATOR,
   MENU_SETTINGS_RESUME_GAME,
   MENU_SETTINGS_QUIT_RARCH,

   MENU_SETTINGS_NETPLAY_ENABLE,
   MENU_SETTINGS_NETPLAY_MODE,
   MENU_SETTINGS_NETPLAY_SPECTATOR_MODE_ENABLE,
   MENU_SETTINGS_NETPLAY_HOST_IP_ADDRESS,
   MENU_SETTINGS_NETPLAY_TCP_UDP_PORT,
   MENU_SETTINGS_NETPLAY_DELAY_FRAMES,
   MENU_SETTINGS_NETPLAY_NICKNAME,
   MENU_SETTINGS_USER_LANGUAGE,

   MENU_SETTINGS_PRIVACY_CAMERA_ALLOW,
   MENU_SETTINGS_PRIVACY_LOCATION_ALLOW,

   MENU_SETTINGS_OVERLAY_PRESET,
   MENU_SETTINGS_OVERLAY_OPACITY,
   MENU_SETTINGS_OVERLAY_SCALE,
   MENU_SETTINGS_BIND_PLAYER,
   MENU_SETTINGS_BIND_DEVICE,
   MENU_SETTINGS_BIND_DEVICE_TYPE,
   MENU_SETTINGS_BIND_ANALOG_MODE,
   MENU_SETTINGS_INPUT_AXIS_THRESHOLD,
   MENU_SETTINGS_DEVICE_AUTODETECT_ENABLE,

   // Match up with libretro order for simplicity.
   MENU_SETTINGS_BIND_BEGIN,
   MENU_SETTINGS_BIND_LAST = MENU_SETTINGS_BIND_BEGIN + RARCH_ANALOG_RIGHT_Y_MINUS,
   MENU_SETTINGS_BIND_ALL_LAST = MENU_SETTINGS_BIND_BEGIN + RARCH_MENU_TOGGLE,

   MENU_SETTINGS_CUSTOM_BIND_MODE,
   MENU_SETTINGS_CUSTOM_BIND,
   MENU_SETTINGS_CUSTOM_BIND_KEYBOARD,
   MENU_SETTINGS_CUSTOM_BIND_ALL,
   MENU_SETTINGS_CUSTOM_BIND_DEFAULT_ALL,
   MENU_SETTINGS_ONSCREEN_KEYBOARD_ENABLE,
   MENU_SETTINGS_LIBRETRO_PERF_COUNTERS_BEGIN,
   MENU_SETTINGS_LIBRETRO_PERF_COUNTERS_END = MENU_SETTINGS_LIBRETRO_PERF_COUNTERS_BEGIN + (MAX_COUNTERS - 1),
   MENU_SETTINGS_PERF_COUNTERS_BEGIN,
   MENU_SETTINGS_PERF_COUNTERS_END = MENU_SETTINGS_PERF_COUNTERS_BEGIN + (MAX_COUNTERS - 1)
} menu_settings_t;

#ifdef GEKKO
enum
{
   GX_RESOLUTIONS_512_192 = 0,
   GX_RESOLUTIONS_598_200,
   GX_RESOLUTIONS_640_200,
   GX_RESOLUTIONS_384_224,
   GX_RESOLUTIONS_448_224,
   GX_RESOLUTIONS_480_224,
   GX_RESOLUTIONS_512_224,
   GX_RESOLUTIONS_576_224,
   GX_RESOLUTIONS_608_224,
   GX_RESOLUTIONS_640_224,
   GX_RESOLUTIONS_340_232,
   GX_RESOLUTIONS_512_232,
   GX_RESOLUTIONS_512_236,
   GX_RESOLUTIONS_336_240,
   GX_RESOLUTIONS_352_240,
   GX_RESOLUTIONS_384_240,
   GX_RESOLUTIONS_512_240,
   GX_RESOLUTIONS_530_240,
   GX_RESOLUTIONS_640_240,
   GX_RESOLUTIONS_512_384,
   GX_RESOLUTIONS_598_400,
   GX_RESOLUTIONS_640_400,
   GX_RESOLUTIONS_384_448,
   GX_RESOLUTIONS_448_448,
   GX_RESOLUTIONS_480_448,
   GX_RESOLUTIONS_512_448,
   GX_RESOLUTIONS_576_448,
   GX_RESOLUTIONS_608_448,
   GX_RESOLUTIONS_640_448,
   GX_RESOLUTIONS_340_464,
   GX_RESOLUTIONS_512_464,
   GX_RESOLUTIONS_512_472,
   GX_RESOLUTIONS_352_480,
   GX_RESOLUTIONS_384_480,
   GX_RESOLUTIONS_512_480,
   GX_RESOLUTIONS_530_480,
   GX_RESOLUTIONS_608_480,
   GX_RESOLUTIONS_640_480,
   GX_RESOLUTIONS_LAST,
};
#endif

#endif

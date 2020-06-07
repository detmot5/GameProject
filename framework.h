// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <cstdlib>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

#include "Paths.h"

#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       640
#define DEFAULT_BLOCK_SIZE  32
#define MAX_CHUNKS_COUNT	1000

#define WORLD_BORDER		((MAX_CHUNKS_COUNT * DEFAULT_BLOCK_SIZE) * (SCREEN_WIDTH / DEFAULT_BLOCK_SIZE))



#define DEBUG_MODE true
#define GAME_GENERATOR_DEBUG true
#define GAME_SAVER_DEBUG false





// if windows
#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <wchar.h>
#define MAX_PATH PATH_MAX
#define WCHAR wchar_t
#define FOURCC uint32_t
#define mmioFOURCC(ch0, ch1, ch2, ch3) \
    ((uint32_t)(uint8_t)(ch0) | ((uint32_t)(uint8_t)(ch1) << 8) | \
    ((uint32_t)(uint8_t)(ch2) << 16) | ((uint32_t)(uint8_t)(ch3) << 24))

#ifdef __cplusplus
extern "C" {
#endif
    void OutputDebugStringW(const WCHAR * fmt, ...);
#ifdef __cplusplus
}
# endif
#endif

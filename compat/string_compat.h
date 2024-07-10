#ifndef __STRING_COMPAT_H__
#define __STRING_COMPAT_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

#ifndef _MSC_VER
#include <strings.h>

#ifndef _stricmp
#define _stricmp strcasecmp
#endif

#ifndef _strnicmp
#define _strnicmp strncasecmp
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STRING_COMPAT_H__ */

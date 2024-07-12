#pragma once

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

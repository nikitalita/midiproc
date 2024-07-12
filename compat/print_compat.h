#include <stdio.h>
#ifndef sprintf_s
#define sprintf_s snprintf
#endif
#ifndef swprintf_s
#include <wchar.h>
#define swprintf_s swprintf
#endif

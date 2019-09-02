#ifndef _CORE_DEBUG_H
#define _CORE_DEBUG_H
#ifdef CORE_DEBUG
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#endif /* CORE_DEBUG */
#include "uart.h"
#ifdef __cplusplus
extern "C"
{
#endif
  /** Output a debug message
 *
 * @param format printf-style format string, followed by variables
 * Note: By using the printf function of the library C this inflates the size of
 * the code, use a lot of stack. An alternative, will be to implement a tiny
 * and limited functionality implementation of printf.
 */
void core_debug(const char *format, ...);


#ifdef __cplusplus
}
#endif

#endif /* _CORE_DEBUG_H */

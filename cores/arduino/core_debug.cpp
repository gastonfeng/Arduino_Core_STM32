#ifdef CORE_DEBUG
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "uart.h"
#include <Arduino.h>
#endif /* CORE_DEBUG */
extern "C"
{
  void core_debug(const char *format, ...)
  {
#ifdef CORE_DEBUG
    char buf[128];
    va_list args;
    va_start(args, format);
    vsprintf(buf, format, args);
    SERIAL_PORT_MONITOR.print(buf);
    va_end(args);
#else
    (void)(format);
#endif /* CORE_DEBUG */
  }
}
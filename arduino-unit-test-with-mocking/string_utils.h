//---

#pragma once

#include <string.h>
#include <inttypes.h>

//---

#ifndef pgm_read_byte
#define pgm_read_byte *
#endif

#ifndef PROGMEM
#define PROGMEM
#endif

//---

template <size_t size>
char* strlcpy_P(char (&p_destination)[size], const char* p_source)
{
    const char *s = reinterpret_cast<const char *>(p_source);
    char* d = p_destination;
    size_t n = 0;

    if(size > 0)
    {
        while (1)
        {
            uint8_t c = pgm_read_byte(s++);
            *d++ = c;
            n++;

            if (c == 0) break;
            if (n >= (size - 1)) break;
        }

        p_destination[size - 1] = '\0';
    }

    return p_destination;
}

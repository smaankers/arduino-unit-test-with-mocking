//---

#include "string_utils.h"

//---

const char startup_progmem[] PROGMEM = "Starting up...";
const char running_progmem[] PROGMEM = "Running";

//---

void setup()
{
    Serial.begin(115200);

    char text_string[20] = {0};
    strlcpy_P(text_string, startup_progmem);
    Serial.println(text_string);
}

//---

void loop()
{
    char text_string[20] = {0};
    strlcpy_P(text_string, running_progmem);
    Serial.println(text_string);

    delay(1000);
}

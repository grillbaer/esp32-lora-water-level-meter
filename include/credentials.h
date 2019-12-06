#pragma once

#if __has_include("secret_credentials.h")
// keep secret credentials in an external file that is never committed:
#include "secret_credentials.h"
#endif

#ifndef _SECRET_CREDENTIALS
// use dummy credentials to make it compilable without secrets
const char *devEui = "0000000000000000";
const char *appEui = "0000000000000000";
const char *appKey = "00000000000000000000000000000000";
#endif

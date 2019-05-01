// StreamUtils - github.com/bblanchon/ArduinoStreamUtils
// Copyright Benoit Blanchon 2019
// MIT License

#pragma once

#ifndef STREAMUTILS_CLIENT_CONNECT_TAKE_CONST_REF
#ifdef ARDUINO_ARCH_ESP8266
#define STREAMUTILS_CLIENT_CONNECT_TAKE_CONST_REF 1
#else
#define STREAMUTILS_CLIENT_CONNECT_TAKE_CONST_REF 0
#endif
#endif

#ifndef STREAMUTILS_CLIENT_FLUSH_TAKES_TIMEOUT
#ifdef ARDUINO_ARCH_ESP8266
#define STREAMUTILS_CLIENT_FLUSH_TAKES_TIMEOUT 1
#else
#define STREAMUTILS_CLIENT_FLUSH_TAKES_TIMEOUT 0
#endif
#endif

#ifndef STREAMUTILS_CLIENT_STOP_TAKES_TIMEOUT
#ifdef ARDUINO_ARCH_ESP8266
#define STREAMUTILS_CLIENT_STOP_TAKES_TIMEOUT 1
#else
#define STREAMUTILS_CLIENT_STOP_TAKES_TIMEOUT 0
#endif
#endif

#ifndef STREAMUTILS_CLIENT_STOP_RETURN_BOOL
#ifdef ARDUINO_ARCH_ESP8266
#define STREAMUTILS_CLIENT_STOP_RETURN_BOOL 1
#else
#define STREAMUTILS_CLIENT_STOP_RETURN_BOOL 0
#endif
#endif

#ifndef STREAMUTILS_PRINT_FLUSH_EXISTS
#ifdef ARDUINO_ARCH_ESP8266
#define STREAMUTILS_PRINT_FLUSH_EXISTS 1
#else
#define STREAMUTILS_PRINT_FLUSH_EXISTS 0
#endif
#endif

#ifndef STREAMUTILS_STREAM_READBYTES_IS_VIRTUAL
#ifdef ARDUINO_ARCH_ESP8266
#define STREAMUTILS_STREAM_READBYTES_IS_VIRTUAL 1
#else
#define STREAMUTILS_STREAM_READBYTES_IS_VIRTUAL 0
#endif
#endif
// StreamUtils - github.com/bblanchon/ArduinoStreamUtils
// Copyright Benoit Blanchon 2019
// MIT License

#pragma once

#include <Stream.h>
#include "../Configuration.hpp"

namespace StreamUtils {

class WriteLoggingPolicy {
 public:
  WriteLoggingPolicy(Print &log) : _log(log) {}

  size_t write(Print &target, const uint8_t *buffer, size_t size) {
    size_t result = target.write(buffer, size);
    _log.write(buffer, result);
    return result;
  }

  size_t write(Print &target, uint8_t c) {
    size_t result = target.write(c);
    _log.write(c);
    return result;
  }

  void flush(Stream &target) {
    target.flush();
  }

#if STREAMUTILS_CLIENT_FLUSH_TAKES_TIMEOUT
  bool flush(Client &target, unsigned timeout) {
    return target.flush(timeout);
  }
#endif

  void flush(Print &) {}
  void detach(Print &) {}

 private:
  Print &_log;
};

}  // namespace StreamUtils
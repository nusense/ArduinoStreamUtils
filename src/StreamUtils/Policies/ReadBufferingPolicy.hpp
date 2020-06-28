// StreamUtils - github.com/bblanchon/ArduinoStreamUtils
// Copyright Benoit Blanchon 2019-2020
// MIT License

#pragma once

#include <Stream.h>

#include "../Buffers/LinearBuffer.hpp"
#include "../Helpers.hpp"

namespace StreamUtils {

template <typename TAllocator>
struct ReadBufferingPolicy {
  ReadBufferingPolicy(size_t capacity, TAllocator allocator = TAllocator())
      : _buffer(capacity, allocator) {}

  ReadBufferingPolicy(const ReadBufferingPolicy &other)
      : _buffer(other._buffer) {}

  int available(Stream &stream) {
    return stream.available() + _buffer.available();
  }

  template <typename TTarget>  // Stream or Client
  int read(TTarget &target) {
    if (!_buffer)
      return target.read();

    if (_buffer.available() > 0)
      return _buffer.read();

    size_t avail = static_cast<size_t>(target.available());
    if (avail <= 1)
      return target.read();

    _buffer.reloadFrom(target, avail);
    return _buffer.read();
  }

  int peek(Stream &stream) {
    return isEmpty() ? stream.peek() : _buffer.peek();
  }

  template <typename TTarget>  // Stream or Client
  size_t readBytes(TTarget &target, char *buffer, size_t size) {
    if (!_buffer)
      return optimizedRead(target, buffer, size);

    size_t result = 0;

    // can we read from buffer?
    if (_buffer.available() > 0) {
      size_t bytesRead = _buffer.readBytes(buffer, size);
      result += bytesRead;
      buffer += bytesRead;
      size -= bytesRead;
    }

    // still something to read?
    if (size > 0) {
      // (at this point, the buffer is empty)

      size_t avail = static_cast<size_t>(target.available());

      // should we use the buffer?
      if (avail > size && size < _buffer.capacity()) {
        _buffer.reloadFrom(target, avail);
        size_t bytesRead = _buffer.readBytes(buffer, size);
        result += bytesRead;
      } else {
        // we can bypass the buffer
        result += optimizedRead(target, buffer, size);
      }
    }

    return result;
  }

  int read(Client &client, uint8_t *buffer, size_t size) {
    return readBytes(client, reinterpret_cast<char *>(buffer), size);
  }

 private:
  bool isEmpty() const {
    return _buffer.available() == 0;
  }

  LinearBuffer<TAllocator> _buffer;
};  // namespace StreamUtils

}  // namespace StreamUtils
#ifndef RAY_COMMON_BUFFER_H
#define RAY_COMMON_BUFFER_H

#include <cstdint>
#include <cstdio>

namespace ray {

/// The interface that represents a buffer of bytes.
class Buffer {
 public:
  /// Pointer to the data.
  virtual uint8_t *Data() const = 0;

  /// Size of this buffer.
  virtual size_t Size() const = 0;

  virtual ~Buffer() {}

  bool operator==(const Buffer &rhs) const {
    return this->Data() == rhs.Data() && this->Size() == rhs.Size();
  }
};

/// Represents a byte buffer in local memory.
class LocalMemoryBuffer : public Buffer {
 public:
  LocalMemoryBuffer(uint8_t *data, size_t size) : data_(data), size_(size) {}

  uint8_t *Data() const override { return data_; }

  size_t Size() const override { return size_; }

  ~LocalMemoryBuffer() {}

 private:
  /// Pointer to the data.
  uint8_t *data_;
  /// Size of the buffer.
  size_t size_;
};

}  // namespace ray

#endif  // RAY_COMMON_BUFFER_H

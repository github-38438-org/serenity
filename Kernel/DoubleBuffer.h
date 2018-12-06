#pragma once

#include <AK/Types.h>
#include <AK/Vector.h>

class DoubleBuffer {
public:
    DoubleBuffer()
        : m_write_buffer(&m_buffer1)
        , m_read_buffer(&m_buffer2)
    {
    }

    ssize_t write(const byte*, size_t);
    ssize_t read(byte*, size_t);

    bool is_empty() const { return m_read_buffer_index >= m_read_buffer->size() && m_write_buffer->isEmpty(); }

private:
    void flip();

    Vector<byte>* m_write_buffer { nullptr };
    Vector<byte>* m_read_buffer { nullptr };
    Vector<byte> m_buffer1;
    Vector<byte> m_buffer2;
    size_t m_read_buffer_index { 0 };
};
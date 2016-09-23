#include "Buffer.h"

namespace fhl
{

Buffer::Buffer(GLuint _target, GLuint _usage)
   : m_moved(false),
	 target(_target),
     usage(_usage),
     size(0)
{
   glGenBuffers(1, &m_id);
}

Buffer::Buffer(Buffer && _other)
	: m_id(_other.m_id),
	  m_moved(false),
	  target(_other.target),
	  usage(_other.usage),
	  size(_other.size)
{
	_other.m_moved = true;
}

Buffer::~Buffer()
{
   if(!m_moved)
	glDeleteBuffers(1, &m_id);
}

void Buffer::bind()
{
   glBindBuffer(target, m_id);
}

void Buffer::unbind()
{
   glBindBuffer(target, 0);
}

void Buffer::setData(GLuint _size, const void* _data)
{
   size = _size;
   glBufferData(target, _size, _data, usage);
}

void Buffer::updateData(GLuint _offset, GLuint _size, const void* _data)
{
   glBufferSubData(target, _offset, _size, _data);
}

}

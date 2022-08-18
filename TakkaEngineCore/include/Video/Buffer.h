#pragma once

#include <glad/glad.h>
#include "Array.h"
#include "../Logger.h"

namespace Takka
{
	class Buffer
	{
	public:

		Buffer(const Buffer& buffer) noexcept;
		Buffer(Buffer&& buffer) noexcept;

		Buffer& operator=(const Buffer& buffer) noexcept;
		Buffer& operator=(Buffer&& buffer) noexcept;

		Buffer(GLenum bufferType) noexcept;
		
		~Buffer() noexcept;

		void Bind();
		void UnBind();
		GLuint GetID();

		template<typename T>
		void LoadData(Array<T>& data, GLenum renderType)
		{
			Bind();
			glBufferData(type, data.GetSizeOfData(), data.GetData(), renderType);
			sizeOfData = data.GetSizeOfData();
			UnBind();
		}

		template<typename T>
		void LoadSubData(size_t offset, Array<T>& data)
		{
			Bind();
			glBufferSubData(type, offset, data.GetSizeOfData(), data.GetData());
			UnBind();
		}

		void LoadData(const void* data, size_t size, GLenum renderType = GL_STATIC_DRAW);
		void LoadSubData(size_t offset, const void* data, size_t size);

		void BindBase(GLuint point);
		void BindRange(GLuint point, size_t size, size_t offset);

		static void BufferCopyData(const Buffer& readBuffer, Buffer& writeBuffer);
		static void Swap(Buffer& l, Buffer& r) noexcept;

	private:
		GLuint id = 0;
		GLenum type = 0;
		GLuint sizeOfData = 0;
	};
}
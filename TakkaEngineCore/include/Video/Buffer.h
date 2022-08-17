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
		void LoadSubData(Array<T>& data)
		{
			Bind();
			glBufferSubData(type, sizeOfData, data.GetSizeOfData(), data.GetData());
			sizeOfData += data.GetSizeOfData();
			UnBind();
		}

		static void BufferCopyData(const Buffer& readBuffer, Buffer& writeBuffer);
		static void Swap(Buffer& l, Buffer& r) noexcept;

	private:
		GLuint id = 0;
		GLenum type = 0;
		GLuint sizeOfData = 0;
	};
}
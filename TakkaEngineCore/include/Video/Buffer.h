#pragma once

#include <glad/glad.h>
#include <Utils.h>
#include <Video/Array.h>

namespace Takka
{
	class Buffer
	{
	public:
		Buffer(GLenum bufferType);
		Buffer(Buffer& buffer);
		Buffer& operator=(Buffer& buffer);
		~Buffer();

		void Bind();
		void UnBind();
		GLuint GetID();

		template<typename T>
		void LoadData(Array<T>& data, GLenum renderType)
		{
			Bind();
			glBufferData(type, data.getSizeOfData(), data.getData(), renderType);
			sizeOfData = data.getSizeOfData();
			UnBind();
		}

		template<typename T>
		void LoadSubData(Array<T>& data)
		{
			Bind();
			glBufferSubData(type, sizeOfData, data.getSizeOfData(), data.getData());
			sizeOfData += data.getSizeOfData();
			UnBind();
		}

		static void BufferCopyData(Buffer& readBuffer, Buffer& writeBuffer);

	private:
		GLuint id;
		GLenum type;
		GLuint sizeOfData = 0;
	};
}
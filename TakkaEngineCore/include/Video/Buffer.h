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

		static void BufferCopyData(Buffer& readBuffer, Buffer& writeBuffer);

	private:
		GLuint id;
		GLenum type;
		GLuint sizeOfData = 0;
	};
}
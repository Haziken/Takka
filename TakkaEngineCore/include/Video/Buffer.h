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
		Buffer(GLuint id, GLenum type);
		~Buffer();

		Buffer(const Buffer& buffer);
		Buffer(Buffer& buffer);

		Buffer& operator=(const Buffer& buffer);
		Buffer& operator=(Buffer& buffer);

		void Bind();
		void UnBind();
		GLuint GetID();

		void Delete();

		template<typename T>
		void LoadData(Array<T>& data, GLenum renderType)
		{
			Bind();
			glBufferData(type, data.getSizeOfData(), data.getData(), renderType);
			UnBind();
		}

	private:
		GLuint id;
		GLenum type;
	};
}
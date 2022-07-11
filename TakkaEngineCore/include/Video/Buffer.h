#pragma once

#include <glad/glad.h>
#include <Utils.h>
#include <Video/Array.h>

namespace Takka
{
	class Buffer
	{
	public:
		DELCPY(Buffer);

		Buffer(GLenum bufferType);
		~Buffer();

		void Bind();
		void UnBind();
		GLuint GetID();

		template<typename T>
		void LoadData(Array<T>& data, GLenum renderType)
		{
			Bind();
			glBufferData(id, data.getSizeOfData(), data.getData(), renderType);
			UnBind();
		}

	private:
		GLuint id;
		GLenum type;
	};
}
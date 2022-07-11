#pragma once
#include <glad/glad.h>
#include <vector>
#include <Utils.h>

namespace Takka
{
	template<typename T>
	class Array
	{
	public:
		DELCPY(Array);
		Array(std::vector<T> data);
		Array(T* data, size_t size);

		~Array();

		std::vector<T>& getVector() const;
		T* getData();
		size_t getSizeOfVector();
		size_t getSizeOfData();
	private:
		std::vector<T> data;
	};

	template<typename T>
	inline Array<T>::Array(std::vector<T> data) : data(data) {}

	template<typename T>
	inline Array<T>::Array(T* data, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
			this->data.push_back(data[i]);
	}

	template<typename T>
	inline Array<T>::~Array() {}

	template<typename T>
	inline std::vector<T>& Array<T>::getVector() const
	{
		return data;
	}

	template<typename T>
	inline T* Array<T>::getData()
	{
		return data.data();
	}

	template<typename T>
	inline size_t Array<T>::getSizeOfVector()
	{
		return data.size();
	}

	template<typename T>
	inline size_t Array<T>::getSizeOfData()
	{
		return sizeof(T) * data.size();
	}
}
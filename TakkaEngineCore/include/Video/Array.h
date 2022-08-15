#pragma once
#include <glad/glad.h>
#include <vector>

namespace Takka
{
	template<typename T>
	class Array
	{
	public:
		Array();
		Array(std::vector<T> data);
		Array(T* data, size_t size);
		Array(const Array<T>& arr);

		Array& operator=(const Array<T>& arr);
		Array& operator=(const Array<T>&& arr);

		~Array();

		std::vector<T>& GetVector();
		T* GetData();
		size_t GetSizeOfVector();
		size_t GetSizeOfData();	

		Array& operator+=(Array&& arr);
		Array& operator+(Array&& arr);

		Array& operator+=(T&& val);
		Array& operator+(T&& val);

		Array& operator+=(Array& arr);
		Array& operator+(Array& arr);

		Array& operator+=(T& val);
		Array& operator+(T& val);

		void Add(Array& arr);
		void Add(T& val);

		void Add(Array&& arr);
		void Add(T&& val);

	private:
		std::vector<T> data;
	};

	template<typename T>
	inline Array<T>::Array() {}

	template<typename T>
	inline Array<T>::Array(std::vector<T> data) : data(data) {}

	template<typename T>
	inline Array<T>::Array(T* data, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
			this->data.push_back(data[i]);
	}

	template<typename T>
	inline Array<T>::Array(const Array<T>& arr)
	{
		this->data = arr.data;
	}

	template<typename T>
	inline Array<T>& Array<T>::operator=(const Array<T>& arr)
	{
		this->data = arr.data;
		return *this;
	}

	template<typename T>
	inline Array<T>& Array<T>::operator=(const Array<T>&& arr)
	{
		data = arr.data;
		return *this;
	}

	template<typename T>
	inline Array<T>::~Array() {}

	template<typename T>
	inline std::vector<T>& Array<T>::GetVector()
	{
		return data;
	}

	template<typename T>
	inline T* Array<T>::GetData()
	{
		return data.data();
	}

	template<typename T>
	inline size_t Array<T>::GetSizeOfVector()
	{
		return data.size();
	}

	template<typename T>
	inline size_t Array<T>::GetSizeOfData()
	{
		return sizeof(T) * data.size();
	}

	template<typename T>
	inline Array<T>& Array<T>::operator+=(Array&& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(Array&& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+=(T&& val)
	{
		data.push_back(val);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(T&& val)
	{
		data.push_back(val);
		return *this;
	}

	template<typename T>
	inline Array<T>& Array<T>::operator+=(Array& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(Array& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+=(T& val)
	{
		data.push_back(val);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(T& val)
	{
		data.push_back(val);
		return *this;
	}

	template<typename T>
	inline void Array<T>::Add(Array& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
	}
	template<typename T>
	inline void Array<T>::Add(T& val)
	{
		data.push_back(val);
	}
	template<typename T>

	inline void Array<T>::Add(Array&& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
	}
	template<typename T>
	inline void Array<T>::Add(T&& val)
	{
		data.push_back(val);
	}
}
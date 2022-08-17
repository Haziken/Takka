#pragma once
#include <glad/glad.h>
#include <vector>

namespace Takka
{
	template<typename T>
	class Array
	{
	public:
		Array() noexcept;
		Array(const std::vector<T> data) noexcept;
		Array(T* data, size_t size) noexcept;

		Array(const Array<T>& arr) noexcept;
		Array(Array<T>&& arr) noexcept;

		Array& operator=(const Array<T>& arr) noexcept;
		Array& operator=(Array<T>&& arr) noexcept;

		~Array() noexcept;

		std::vector<T>& GetVector();
		T* GetData();
		size_t GetSizeOfVector();
		size_t GetSizeOfData();	

		Array& operator+=(Array&& arr);
		Array& operator+=(Array& arr);
		Array& operator+=(T&& val);
		Array& operator+=(T& val);

		Array& operator+(Array&& arr);
		Array& operator+(Array& arr);
		Array& operator+(T&& val);
		Array& operator+(T& val);

		void Add(Array&& arr);
		void Add(Array& arr);

		void Add(T&& val);
		void Add(T& val);

	private:
		std::vector<T> data;
	};

	template<typename T>
	inline Array<T>::Array() noexcept {}

	template<typename T>
	inline Array<T>::Array(std::vector<T> data) noexcept : data(data) {}

	template<typename T>
	inline Array<T>::Array(T* data, size_t size) noexcept
	{
		for (size_t i = 0; i < size; ++i)
			this->data.push_back(data[i]);
	}

	template<typename T>
	inline Array<T>::Array(const Array<T>& arr) noexcept
	{
		this->data = arr.data;
	}

	template<typename T>
	inline Array<T>::Array(Array<T>&& arr) noexcept
	{
		std::swap(this->data, arr.data);
	}

	template<typename T>
	inline Array<T>& Array<T>::operator=(const Array<T>& arr) noexcept
	{
		this->data = arr.data;
		return *this;
	}

	template<typename T>
	inline Array<T>& Array<T>::operator=(Array<T>&& arr) noexcept
	{
		std::swap(this->data, arr.data);
		return *this;
	}

	template<typename T>
	inline Array<T>::~Array() noexcept {}

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
		Add(arr);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+=(Array& arr)
	{
		Add(arr);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+=(T&& val)
	{
		Add(val);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+=(T& val)
	{
		Add(val);
		return *this;
	}
	
	template<typename T>
	inline Array<T>& Array<T>::operator+(Array&& arr)
	{
		Add(arr);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(Array& arr)
	{
		Add(arr);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(T&& val)
	{
		Add(val);
		return *this;
	}
	template<typename T>
	inline Array<T>& Array<T>::operator+(T& val)
	{
		Add(val);
		return *this;
	}

	template<typename T>
	inline void Array<T>::Add(Array&& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
	}
	template<typename T>
	inline void Array<T>::Add(Array& arr)
	{
		data.insert(data.end(), arr.GetVector().begin(), arr.GetVector().end());
	}
	
	template<typename T>
	inline void Array<T>::Add(T&& val)
	{
		data.push_back(val);
	}
	template<typename T>
	inline void Array<T>::Add(T& val)
	{
		data.push_back(val);
	}
}
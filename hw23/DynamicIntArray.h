#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>

template<class T>
class DynamicIntArray
{
public:
	DynamicIntArray();
	DynamicIntArray(std::size_t size);
    DynamicIntArray(const DynamicIntArray& other);
    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other);
	T& operator[](std::size_t index);
	    
    std::size_t getSize() const;
	std::size_t getCapacity() const;

	void setSize(std::size_t newSize);
    void clear();
    void push_back(const T element);

	void reserve(std::size_t reservedSpace);
	void shrinkToFit();

	void pop_back();
	T back() const;
	bool operator==(const DynamicIntArray<T>& other) const;

private:
	void copy(T* destination, const T* source, size_t count);

	T* m_array;
	size_t  m_capacity;
	size_t  m_size;
	const size_t  m_capacitySize = 10;
};

template<class T>
DynamicIntArray<T>::DynamicIntArray()
{
	m_size = 0;
	m_capacity = m_capacitySize;
	m_array = new T[m_capacity];
	
}

template<class T>
DynamicIntArray<T>::DynamicIntArray(std::size_t size)
{
	m_size = (size >= 0) ? size : 0;
	m_capacity = m_size + m_capacitySize;
	m_array = new T[m_capacity];
}

template<class T>
DynamicIntArray<T>::DynamicIntArray(const DynamicIntArray& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_array = new T[m_size];
	copy(m_array, other.m_array, m_size);
}

template<class T>
DynamicIntArray<T>::~DynamicIntArray()
{
	delete[] m_array;
}

template<class T>
DynamicIntArray<T>& DynamicIntArray<T>::operator=(const DynamicIntArray& other)
{
	if (&other == this)
		return *this;

	m_size = other.m_size;
	m_capacity = other.m_capacity;
	delete[] m_array;

	m_array = new T[m_capacity];

	copy(m_array, other.m_array, m_size);

	return *this;
}

template<class T>
T& DynamicIntArray<T>::operator[](std::size_t index)
{
	if (index >= m_size)
	{
		std::cerr << "operator[] index: " << index << " is out of range!";
	}

	return m_array[index];
}

template <typename T>
void DynamicIntArray<T>::shrinkToFit()
{
	m_capacity = m_size;
	T* tempArray = new T[m_capacity];
	
	copy(tempArray, m_array, m_size);

	delete[] m_array;
	m_array = tempArray;
}

template <typename T>
void DynamicIntArray<T>::reserve(std::size_t capacity)
{
	if (m_capacity >= capacity)
		return;

	m_capacity = capacity;
	T* tempArray = new T[m_capacity];
	
	copy(tempArray, m_array, m_size);

	delete[] m_array;
	m_array = tempArray;
}

template<class T>
void DynamicIntArray<T>::setSize(std::size_t newSize)
{
	if (newSize > 0)
	{
		m_capacity = newSize + m_capacitySize;
		T* tempArray = new T[m_capacity];
		
		copy(tempArray, m_array, newSize);

		delete[] m_array;

		if (m_size < newSize)
		{
			for (size_t i = m_size; i < newSize; i++)
			{
				tempArray[i] = 0;
			}
		}

		m_size = newSize;		
		m_array = tempArray;
	}
}

template<class T>
std::size_t DynamicIntArray<T>::getSize() const
{
	return m_size;
}

template<class T>
std::size_t DynamicIntArray<T>::getCapacity() const
{
	return m_capacity;
}

template<class T>
void DynamicIntArray<T>::clear()
{	
	delete[] m_array;
	m_size = 0;
	m_capacity = m_capacitySize;
	m_array = new T[m_capacity];
}

template<class T>
void DynamicIntArray<T>::push_back(const T element)
{	
	if (m_size == m_capacity)
	{
		m_capacity = m_size + m_capacitySize;
		setSize(m_size + 1);
		m_array[m_size - 1] = element;
	}
	else 
	{		
		m_array[m_size] = element;
		m_size++;
	}
}

template <class T>
void DynamicIntArray<T>::pop_back()
{	
	if (m_size == 0)
	{
		return;
	}
		
	T* tempArray = new T[--m_size];
	copy(tempArray, m_array, m_size);
	
	delete[] m_array;	
	m_array = tempArray;	
}

template <class T>
T DynamicIntArray<T>::back() const
{
	return m_array[m_size - 1];
}

template <class T>
bool DynamicIntArray<T>::operator==(const DynamicIntArray<T>& other) const
{
	if (m_size != other.m_size)
	{
		return false;
	}
		
	return std::equal(m_array, m_array + m_size, other.m_array);
}

template<class T>
void DynamicIntArray<T>::copy(T* to, const T* from, const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		to[i] = from[i];
	}
}
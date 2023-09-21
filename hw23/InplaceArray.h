#pragma once
#include <cstdlib>

template <typename T, int size>
class InplaceArray
{
public:
    InplaceArray() : m_stackSize{ size }, m_heapData{ nullptr }, m_heapSize{ 0 }, m_capacity{ 0 } {};
    InplaceArray(std::size_t size_arg);
    InplaceArray(const InplaceArray& other);
    
    ~InplaceArray() { delete[] m_heapData; };

    InplaceArray& operator=(const InplaceArray& other);

    T& operator[](std::size_t index);
    bool operator==(const InplaceArray& other) const;   
    std::size_t getSize() const { return m_stackSize + m_heapSize; };
    std::size_t getCapacity() const { return m_capacity; };
    T back() const;

    void push_back(const T& element);
    void pop_back();
    
    void setSize(std::size_t newSize);
    void reserve(std::size_t reservedSpace);
    void clear() 
    { 
        m_stackSize = 0; 
        m_heapSize = 0; 
    }
    
    void shrinkToFit();
private:
    void copy(T* destination, const T* source, size_t count);
    void changeSize(size_t size_arg);

    T m_stackData[size];
    size_t m_stackSize{};
    T* m_heapData;
    size_t m_heapSize;
    size_t m_capacity;
    const float m_capacityModificator = 0.5f;
};

template<typename T, int size>
InplaceArray<T, size>::InplaceArray(std::size_t size_arg)     
{        
    if (size_arg >= size)
    {
        std::fill(m_stackData, m_stackData + size, T{});
        m_stackSize = size;
    }

    if (size_arg > size)
    {
        m_heapSize = size_arg - size;
        m_capacity = m_heapSize + m_heapSize * m_capacityModificator;
        m_heapData = new T[m_capacity];
        std::fill(m_heapData, m_heapData + m_capacity, T{});
    }
}

template<typename T, int size>
InplaceArray<T, size>::InplaceArray(const InplaceArray& other) :
    m_stackSize{ other.m_stackSize },
    m_heapData{ new T[other.m_heapSize] },
    m_capacity{ other.m_capacity },    
    m_heapSize{ other.m_heapSize }
{    
    copy(m_heapData, other.m_heapData, m_heapSize);
    copy(m_stackData, other.m_stackData, m_stackSize);    
}

template<typename T, int size>
InplaceArray<T, size>& InplaceArray<T, size>::operator=(const InplaceArray& other)
{
    if (&other == this)
		return *this;

    m_stackSize = other.m_stackSize;
	m_capacity = other.m_capacity;
	delete[] m_heapData;

    m_heapData = new T[m_capacity];
    	
    copy(m_heapData, other.m_heapData, m_heapSize);
    copy(m_stackData, other.m_stackData, m_stackSize);

	return *this;    
}

template<typename T, int size>
T& InplaceArray<T, size>::operator[](std::size_t index)
{
    if (index < m_stackSize)
        return m_stackData[index];

    return m_heapData[index - m_stackSize];
}

template<typename T, int size>
bool InplaceArray<T, size>::operator==(const InplaceArray& other) const
{
    if (m_stackSize != other.m_stackSize ||
        m_heapSize != other.m_heapSize)
        return false;

    return std::equal(m_heapData, m_heapData + m_heapSize, other.m_heapData, other.m_heapData + other.m_heapSize) &&
        std::equal(m_stackData, m_stackData + m_stackSize, other.m_stackData, other.m_stackData + other.m_stackSize);
}

template<class T, int size>
void InplaceArray<T, size>::push_back(const T& element)
{
    if (m_stackSize < size)
    {        
        m_stackData[m_stackSize] = element;
        m_stackSize++;
        return;
    }
        
    if (m_capacity == m_heapSize)
    {
        size_t newSize = (m_heapSize == 0) ? size + size * m_capacityModificator
            : m_heapSize + m_heapSize * m_capacityModificator;
        changeSize(newSize);
    }
        
    m_heapData[m_heapSize] = element;
    m_heapSize++;
}

template<typename T, int size>
void InplaceArray<T, size>::changeSize(std::size_t size_arg)
{
    if (size_arg == m_heapSize)
    {
        return;
    }        

    if (m_heapData == nullptr)
    {
        m_capacity = size + size * m_capacityModificator;
        m_heapData = new T[m_capacity];
        std::fill(m_heapData, m_heapData + m_capacity, T{});
        return;
    }

    const size_t elementsCount = (size_arg > m_heapSize) ? size_arg : m_heapSize;
    T* tempArray = new T[size_arg];
    copy(tempArray, m_heapData, elementsCount);
    
    if (size_arg > elementsCount)
    {
        std::fill(tempArray + elementsCount, tempArray + size_arg, T{});
    }    

    delete[] m_heapData;
    m_heapData = tempArray;
    m_capacity = size_arg;
}

template<typename T, int size>
void InplaceArray<T, size>::setSize(std::size_t newSize)
{
    if (newSize <= size)
        m_stackSize = newSize;
    else
    {
        if (m_stackSize < size)
        {
            std::fill(&m_stackData[m_stackSize], m_stackData + size, T{});
            m_stackSize = size;
        }

        changeSize(newSize - size);
    }
}

template<typename T, int size>
void InplaceArray<T, size>::copy(T* to, const T* from, const size_t size_arg)
{
    if (std::is_trivially_copyable_v<T>)
        memcpy(to, from, size_arg * sizeof(T));
    else
        std::uninitialized_copy(from, from + size_arg, to);
}

template <typename T, int size>
T InplaceArray<T, size>::back() const
{
    if (m_heapSize != 0)
        return m_heapData[m_heapSize - 1];

    
    return m_stackData[m_stackSize - 1];    
}

template <typename T, int size>
void InplaceArray<T, size>::pop_back()
{
    if (m_heapSize)
    {
        --m_heapSize;
        return;
    }

    --m_stackSize;
    return;
}

template<typename T, int size>
void InplaceArray<T, size>::reserve(size_t capacity)
{
    if (m_capacity >= capacity)
        return;

    T* tempArray = new T[capacity];

    copy(tempArray, m_heapData, m_heapSize);

    delete[] m_heapData;

    m_heapData = tempArray;
    m_capacity = capacity;
}

template<typename T, int size>
void InplaceArray<T, size>::shrinkToFit()
{
    if (m_capacity > m_heapSize)
    {
        T* tempArray = new T[m_heapSize];
        copy(tempArray, m_heapData, m_heapSize);
        delete[] m_heapData;
        m_heapData = tempArray;
        m_capacity = m_heapSize;
    }
}
#include <iostream>
#include "DynamicIntArray.h"
#include "InplaceArray.h"

int main()
{
	InplaceArray<int, 5> array1(10);

	std::cout << "Size: " << array1.getSize() << std::endl;
	std::cout << "getCapacity: " << array1.getCapacity() << std::endl;
	
	array1.shrinkToFit();

	std::cout << "Size: " << array1.getSize() << std::endl;
	std::cout << "getCapacity: " << array1.getCapacity() << std::endl;
}

enum class SortingDirection
{
	ascending = 1,
	descending = 0
};

void linearSearch(const int arr[][5], int rows, int cols, int elem);
bool isSorted(const int* arr, int size, SortingDirection direction);
void arrayTraversal(const int arr[][5], int rows, int cols);
void arrayTraversalSecondVersion(const int arr[][5], int rows, int cols);
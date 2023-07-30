enum class SortingDirection
{
	ascending = 1,
	descending = 0
};

const int SIZE = 5;

bool linearSearch(const int arr[][SIZE], int rows, int cols, int elem);
bool isSorted(const int* arr, int size, SortingDirection direction);
void arrayTraversal(const int arr[][SIZE], int rows, int cols);
void arrayTraversalSecondVersion(const int arr[][SIZE], int rows, int cols);
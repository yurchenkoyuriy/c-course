#include <iostream>

constexpr int COLUMNS = 6;
constexpr int ROWS = 5;
enum class SortingDirection 
{
    ByRows, 
    byColumn
};

void swap(int* x, int* y);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(const int* arr, int size);
void print2dArray(const int arr[][COLUMNS], int rows, int columns);
void bubleSort(int arr[], int size); // Task 1
void sort(int arr[][COLUMNS], int rows, SortingDirection); // Task 2

int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {4, 8, 2, 3, 9, 1, 7, 0, 6, 5};
    int arr_2d[][COLUMNS] = {
        {24, 21, 4, 22, 10, 30},
        {20, 16, 2, 3, 17, 27}, 
        {14, 5, 1, 13, 9, 29}, 
        {12, 8, 7, 18, 23, 26}, 
        {11, 19, 25, 15, 6, 28}, 
    };

    // Task 1
    std::cout << "Unsorted array: " << std::endl;
    
    printArray(arr, SIZE);
    
    std::cout << std::endl << "Buble sorted array: " << std::endl;
    
    bubleSort(arr, SIZE);
    printArray(arr, SIZE);

    // Task 2
    std::cout << std::endl << "Unsorted array: " << std::endl;

    print2dArray(arr_2d, ROWS, COLUMNS);

    std::cout << std::endl << "Quick Sorted array by Column: " << std::endl;
    
    sort(arr_2d, ROWS, SortingDirection::byColumn);    
    print2dArray(arr_2d, ROWS, COLUMNS);

    std::cout << std::endl << "Quick Sorted array by Rows: " << std::endl;

    sort(arr_2d, COLUMNS, SortingDirection::ByRows);
    print2dArray(arr_2d, ROWS, COLUMNS);
}

void bubleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = size - 1; j > i; j--)
        {         
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

void sort(int arr[][COLUMNS], int rows, SortingDirection direction)
{    
    int* temp_arr = new int[rows];

    if (direction == SortingDirection::byColumn)
    {     
        for (int i = 0; i < COLUMNS; i++)
        {
            for (int j = 0; j < ROWS; j++)
            {
                temp_arr[j] = arr[j][i];
            }

            quickSort(temp_arr, 0, ROWS - 1);

            for (size_t j{}; j < ROWS; j++)
            {
                arr[j][i] = temp_arr[j];
            }                            
        }
    } 
    else 
    {     
        for (int i = 0; i < ROWS; i++)
        {            
            quickSort(arr[i], 0, COLUMNS - 1);
        }        
    }

    delete[] temp_arr;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void print2dArray(const int arr[][COLUMNS], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
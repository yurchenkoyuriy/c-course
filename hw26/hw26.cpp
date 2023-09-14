#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

int sumVector(const std::vector<int>& vec) 
{
    auto start = std::chrono::high_resolution_clock::now();

    int sum = std::accumulate(vec.begin(), vec.end(), 0);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << " seconds. ";

    return sum;
}


int sumVectorMultiThread(const std::vector<int>& vec, const int numThreads) 
{
    auto start = std::chrono::high_resolution_clock::now();

    int vecSize = vec.size();
    int chunkSize = vecSize / numThreads;

    std::vector<std::thread> threads(numThreads);
    std::vector<int> partialSums(numThreads, 0);

    for (int i = 0; i < numThreads; ++i) 
    {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? vecSize : (i + 1) * chunkSize;
        threads[i] = std::thread([start, end, &vec, &partialSums, i]() {
            partialSums[i] = std::accumulate(vec.begin() + start, vec.begin() + end, 0);
        });
    }

    for (int i = 0; i < numThreads; ++i) 
    {        
        threads[i].join();
    }

    int totalSum = 0;
    for (int partialSum : partialSums) 
    {
        totalSum += partialSum;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << numThreads << " time: " << duration.count() << " seconds. ";

    return totalSum;    
}

void generateRandomVector(std::vector<int>& vec, const int size, const int min = 1, const int max = 9)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    std::generate(vec.begin(), vec.end(), [&]() {
        return distribution(gen);
    });
}


int main()
{
    const int vectorSize = 10000000;
    const int processorCores = std::thread::hardware_concurrency();
    std::vector<int> myVector(vectorSize);
    generateRandomVector(myVector, vectorSize, 10000, 99999);
            
    std::cout << "Vector sum: " << sumVector(myVector) << std::endl;
    std::cout << "Vector sum: " << sumVectorMultiThread(myVector, 2) << std::endl;
    std::cout << "Vector sum: " << sumVectorMultiThread(myVector, processorCores) << std::endl;
    std::cout << "Vector sum: " << sumVectorMultiThread(myVector, 2 * processorCores) << std::endl;    

    return 0;
}

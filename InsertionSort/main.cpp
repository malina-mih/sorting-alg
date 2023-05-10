#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
void insertionSort(int arr[], int n)
{
for (int i = 1; i < n; ++i)
{
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
int main() {
const int SIZE = 500000;
int arr[SIZE];
for (int i = 0; i < SIZE; i++)
    {
arr[i] = rand() % 1000000;
}
clock_t start = clock();
insertionSort(arr, SIZE-1);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
int minutes=int(duration) / 60;
int seconds=int(duration) %60;
int milliseconds=int((duration-int(duration))*1000);
cout << "Execution time: " <<minutes<<" minutes,"<<seconds<<" seconds,"<<milliseconds<<" milliseconds";
return 0;
}

#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}
if (minIndex != i) {
swap(arr[i], arr[minIndex]);
}
}
}
int main() {
const int SIZE = 500000;
int arr[SIZE];
for (int i = 0; i < SIZE; i++) {
arr[i] = rand() % 1000000;
}
clock_t start = clock();
selectionSort(arr, SIZE-1);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
int minutes=int(duration) / 60;
int seconds=int(duration) %60;
int milliseconds=int((duration-int(duration))*1000);
cout << "Execution time: " <<minutes<<" minutes,"<<seconds<<" seconds,"<<milliseconds<<" milliseconds";
return 0;
}

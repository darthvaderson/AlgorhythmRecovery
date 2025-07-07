#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdint>
using namespace std;


int hoare(uint16_t* array, int left, int right);
void quickSort(uint16_t* array, int left, int right);
void mergeSort(int* array, int left, int right, int* temp);
void print(int* array, int left, int right);
void swap(int& x, int& y);

int main() {


	int size;
	cin >> size;


	return 0;
}
void swap(uint16_t& x, uint16_t& y)
{
	uint16_t temp = y;
	y = x;
	x = temp;
}
void print(uint16_t* array, int left, int right)
{
	for(int i = left ; i <= right ; i ++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int hoare(uint16_t* array, int left, int right)
{
    int pIndex = left + rand() % (right - left + 1);
    // int pIndex = (left + right)/2;
    uint16_t pValue = array[pIndex];
    int i = left;
    int j = right;

    while(true)
    {
        while(array[i] < pValue){
            i++;
        }
        while(array[j] > pValue){
            j--;
        }
        if(i >= j) return j;

        uint16_t temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        i++; j--;
    }

}
void quickSort(uint16_t* array, int left, int right)
{
	if(left>=right) return;

	int partitionBoundary = hoare(array, left, right);

	quickSort(array, left, partitionBoundary);

	quickSort(array, partitionBoundary+1, right);

	return;
}
void mergeSort(int* array, int left, int right, int* temp)
{
	if(left >= right) return;

	int mid = (left+right)/2;
	mergeSort(array, left, mid, temp);
	mergeSort(array, mid+1, right, temp);

	int i = left;
	int j = mid+1;
	int k = left;

	while(i <= mid && j <= right)
	{
		if(array[i] <= array[j] )
		{
			temp[k++] = array[i++];
		} else
		{
			temp[k++] = array[j++];
		}
	}

	while(i <= mid) {
		temp[k++] = array[i++];
	}

	while(j <= right) {
		temp[k++] = array[j++];
	}

	for(int h = left ; h <= right ; h++)
	{
		array[h] = temp[h];
	}

	return;
}

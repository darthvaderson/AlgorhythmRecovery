#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


int hoare(int* array, int left, int right);
int lomuto(int* array, int left, int right);
void quickSort(int* array, int left, int right, int size);
void print(int* array, int left, int right);
int binarySearch(int* array, int left, int right, int input);

int main(){
    
    
    int size;
    cin >> size;
    cin.ignore();
    int* array = new int[size];
    
    int num;
    string s;
    stringstream stream;
    
    getline(cin,s);
    stream.str(s);
    int idx = 0;
    
  while(stream >> num){
      array[idx++] = num;
  }
    
    //print(array, 0, size-1);
    
    quickSort(array,0,size-1, size-1);
    
    //print(array, 0, size-1);
    
    int size_2;
    cin >> size_2;
    cin.ignore();
    int* array_2 = new int[size_2];
    
    stream.str(""); 
    stream.clear(); 
    
    getline(cin,s);
    stream.str(s);
    idx = 0;
    
    while(stream >> num){
      array_2[idx++] = num;
  }
   
  //print(array_2, 0, size_2-1);
   
    stream.str(""); 
    stream.clear();
    
    for(int i = 0 ; i < size_2 ; i++)
    {
        int result = binarySearch(array, 0, size-1, array_2[i]) >= 0 ? 1 : 0;
        stream << result << "\n";
    }
    
    cout << stream.str();
    
    return 0;
}
int hoare(int* array, int left, int right)
{
    int l = left;
    int r = right;
    int pValue = array[(l + r)/2];
    
    while(true){
        while(array[l] < pValue)
        {
          l++;    
        }
        while ( array[r] > pValue )
        {
          r--;  
        } 
        
        if(l >= r) break;
        int temp = array[l];
        array[l] = array[r];
        array[r] = temp;
        l++; r--;
        // print(array, left, right);
    }
    
    return r;
}
int lomuto(int* array, int left, int right)
{
    //pivot 값은 배열의 첫번째 원소로 고정한다.
    int pValue = array[left];
    int pIndex = left;
    
    //pIndex 기준 우측 값은 pValue 보다 크다. pIndex는 pivot 값의 최종 위치.
    for(int i = left+1 ; i <= right ; i++)
    {
        if(array[i] < pValue)
        {
            pIndex ++;
            int temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
        }
    }
    int temp = array[pIndex];
    array[pIndex] = array[left];
    array[left] = array[pIndex];
    
    return pIndex;
}
void quickSort(int* array, int left, int right, int size)
{
    // if(left < right)
    // {
    //     int pIndex = lomuto(array, left, right);
    //     quickSort(int* array, left, pIndex-1);
    //     quickSort(int* array, pIndex+1, right);
    // }
    if(left < right)
    {
        int pIndex = hoare(array, left, right);
        //print(array, size);
        quickSort(array, left, pIndex, size);
        quickSort(array, pIndex+1, right, size);
    }
    
}
int binarySearch(int* array, int left, int right, int input){
    int result;
    int mid = (left+right) / 2 ;
    if(left > right) 
    { 
        result = -1; 
    }
    else if(array[mid] == input) 
    {
        result = mid;
    }
    else if(array[mid] < input )
    {
        result = binarySearch(array, mid+1, right, input);
    }else if(array[mid] > input)
    {
        result = binarySearch(array, left, mid-1, input);
    }
    return result;
}
void print(int* array, int left, int right)
{
 for(int i = left ; i <= right ; i ++)
 {
     cout << array[i] << " ";
 }
 cout << endl;
}
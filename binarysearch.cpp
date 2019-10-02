#include<iostream>
#include<ctime>

#define size 1000000

using namespace std;

bool binarySearch(int arr[], int l, int r, int val) 
{ 
  if (r >= l) { 
    int mid = l + (r - l) / 2; 
    if (arr[mid] == val) 
      return true;
    if (arr[mid] > val) {
      return binarySearch(arr, l, mid - 1, val);
    } 
    return binarySearch(arr, mid + 1, r, val);
  } 
  return false; 
}

void mediaryFunction(int val){
  int array[size];
  for(int i = 0; i < size; ++i){
    array[i] = i;
  }
  time_t startTime, endTime;
  double avgTime = 0;
  for(int i = 0; i < 3; ++i){
    startTime = clock();
    bool elementFound = binarySearch(array, 0, size - 1, val); 
    endTime = clock();
    double timeDiff = (endTime - startTime);
    timeDiff /= 1000;
    cout<<"Run#"<<i+1<<":\t"<<timeDiff<<"ms\n";
    avgTime += timeDiff;
  }
  cout<<"Average:\t"<<avgTime / 3<<"ms\n\n";
}

int main(){
  cout<<"\nBinary search : Compiled and executed by Harsh Yadav.\n 44614803117\n";
  cout<<"Best Case :\n";
  mediaryFunction(499999);
  cout<<"Average Case :\n";
  mediaryFunction(975);
  cout<<"Worst Case :\n";
  mediaryFunction(999999);
  return 0;
}
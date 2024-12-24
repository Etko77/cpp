#include <iostream>
using namespace std;

void printArray(int arr [],int s);
int* meshArrays(int arr1[],int size1,int arr2[],int size2);


int main(){
    int arr1[] {1,2,3,4,5};
    int arr2[]{10,20,30};
    printArray(arr1,5);
    int* arrPtr = meshArrays(arr1,5,arr2,3);
    printArray(arrPtr, 5*3);
    return 0;
}
void printArray(int arr [],int s){
    cout<<"[";
    for (int i  = 0; i < s;i++){
        cout<< arr[i]<<" ";
    }
    cout<<"]"<<endl;
}
int* meshArrays(int arr1[],int size1,int arr2[],int size2){
    int newSize = size1*size2;
    int* newArr = new int[newSize];

    int counter = 0;

    for (int i = 0; i < size2;i++){
        for(int j = 0; j < size1;j++){
            newArr[counter] = arr1[j]*arr2[i];
            counter++;
        }
    }
    return newArr;

}
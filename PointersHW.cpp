#include <iostream>

void reverseArray(int* arr, int size);
int main(){

    /*(1)Create an array of 5 integer element. Create pointer ptr1 that point to the 3rd element of the
array. Modify the value pointed by ptr1 by multiply it by 10. Show the array value.*/

    int arr1[] = {1,2,3,4,5};
    int *ptr1 = &arr1[2];

    *ptr1= *ptr1* 10;

    std::cout<<"(1)Modified Array\n ";
    for (int i:arr1){
        std::cout<< i<<" ";
    }
    std::cout<<"\n*************************************\n" <<std::endl;

    /*(2)Write a program that finds the sum of all elements in an integer array using pointers*/
    int arr2[] = {2,4,6,8,10};
    int size = sizeof(arr2)/sizeof(arr2[0]);
    int *ptr2 = &arr2[0];

    int sum;

    for (int i = 0; i < size ; i++){
        sum += *ptr2;
        ptr2++;
    }
    std::cout<<"(2)sum of all elements: " <<sum<<std::endl;
    std::cout<<"\n*************************************\n" <<std::endl;

    /*(3)Write a program that reverses the elements of an array using pointers*/
    int arr3[] = {3,6,9,12,15};
    int *ptr3;
    ptr3 = arr3;
    int size1 = sizeof(arr3)/sizeof(arr3[0]);

    reverseArray(ptr3, size1);
    std::cout<<"(3)Reverse Array\n" ;
    for(int i: arr3){
        std::cout<< i <<" ";
    }
    std::cout<<std::endl;
    std::cout<<"\n*************************************\n" <<std::endl;

    /*(4)Write a program that multiplies each element of an array by 2 using pointers*/
    int arr4[] = {1,2,3,4,5,6};
    int size2 = sizeof(arr4)/sizeof(arr4[0]);
    int *ptr4 = &arr4[0];
    int **ptr4nd = &ptr4;
    int multiply = 1;

    for (int i = 0 ; i<size2; i++){
        multiply *= *(*ptr4nd+i);

    }
    std::cout<<"(4)multiply each elements in the array: "<<multiply<<std::endl;
    std::cout<<"\n*************************************\n" <<std::endl;

    /*(5)Create an array of 5 integer elements. Use 2 pointers to propagate from left to right and right
    to left. If the value is odd pointer jump by one. Otherwise, if the value is even, pointer jump by
    two.
         Show the array and address of each element
         When pointers point to the same value, print the value
         Otherwise, when pointers pass by each other, print the values and address both pointer
            pointed to*/
    
    int arr5[] = {5,3,7,9,4,2,1,23,11,16,65,85,44,90};
    int size3 = sizeof(arr5)/sizeof(arr5[0]);
    int *ptrleft = &arr5[0];
    int *ptrright = &arr5[size3-1];
    int i=1;
    std::cout<<"(5)Use 2 pointers to propagate from left to right\n";

    while(ptrleft<ptrright){

        std::cout<< "Step: "<<i<<std::endl;
        std::cout<<" value: "<< *ptrleft<< " address: "<< ptrleft<<std::endl;
        std::cout<<" value: "<< *ptrright<< " address: "<< ptrright<<std::endl;
        std::cout<<"--------------------------"<<"\n";

        if(*ptrleft%2!=0){
            ptrleft++;
        }
        else{ptrleft+=2;}
        
        if(*ptrright%2!=0){
            ptrright--;
        }
        else{ptrright-=2;}

        i++;
    }
    std::cout<< "Step: "<<i++<< ", Finish loop"<<std::endl;
    std::cout<<" value: "<< *ptrleft<< " address: "<< ptrleft<<std::endl;
    std::cout<<" value: "<< *ptrright<< " address: "<< ptrright<<std::endl;
    std::cout<<"\n*************************************\n" <<std::endl;

    return 0;
}

void reverseArray(int* arr, int size){
    int *left = arr;
    int *right = arr + (size-1);

    while ( left<right){

    int temp = *left;
    *left = *right;
    *right = temp;

    left++; right--;
    
    }

    return;
}


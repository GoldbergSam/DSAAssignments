#include <bits/stdc++.h>

using namespace std;

int sumTo(int x);
int RecursiveSumTo(int x);

int Fibbonacci(int x);
int RecursiveFib(int x);

int maxArr(int arr[], int size);
int RecMaxArr(int arr[], int size);
int RecMaxArrHelper(int arr[], int size, int i);

void reverseArr(int arr[], int size);
void RecReverseArr(int arr[], int size);
void RecReverseArrHelper(int arr[],int* left, int* right);

void palindrome(const string &word, int size);
void RecPalindrome(const string &word, int size);
void RecPalindromeHelper(const string &word, int left, int right);

int count(int arr[], int size, int key);
int countRec(int arr[], int curr, int key);

int countDigits(int num);
int countDigitsRec(int num);

int to_Binary(int num);
int to_BinaryRec(int num);

int pow(int num, int n);
int powRec(int num, int n);

void printarr(int arr[], int size){
cout<<"[ ";
    for (int i=0; i<size; i+=1) {
        cout << arr[i] << " ";
    }
    cout<<"]"<<endl;
}

int main(){
    //Exe 1: Write a program that asks the user for an integer number and find the sum of all natural numbers up to that input number
    cout << "1.\n";
    cout << "Sum up to 20 : "<< sumTo(5)<<endl;
    cout << "Sum up to 20 Recursively : " << RecursiveSumTo(5)<<endl;

    //Calculate Fibonacci
    cout << "2.\n";
    cout<< "Fibbonacci n=10: "<<Fibbonacci(10)<<endl;
    cout << "Fibbonacci n=10 Recursively: "<<RecursiveFib(10)<<endl;

    //Exe 3: Find max value in a given in array
    int arr1[] = {1,2,3,4,5,6,4,3,2,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    cout <<"3. \n";
    cout <<"Find max value : "<<maxArr(arr1,size1)<<endl;
    cout <<"Find max value Recursively :  "<<RecMaxArr(arr1,size1)<<endl;
    //Exe 4: Reverse array
    int arr2[] = {1,2,3,4,5,6,7,8};
    int size2 = sizeof(arr2)/ sizeof(arr2[0]);
    int arr3[] = {1,2,3,4,5,6,7,8};
    int size3= sizeof(arr3)/ sizeof(arr3[0]);
    cout << "4. \n";
    cout << "Reversed Array \n"; reverseArr(arr2,size2);
    printarr(arr2,size2);
    cout<< "Reversed Array recursively \n"; RecReverseArr(arr3,size3);
    printarr(arr3,size3);
    cout<<endl;

    //Exe 5: Check if a given string is a palindrome
    cout << "5. \n";
    string word = "rotator";
    cout << "the word rotator"<<endl;
    palindrome(word,word.size());
    cout << "Recursive function; the word rotator "<<endl;
    RecPalindrome(word,word.size());
    cout<<endl;

    //Exe 6: Count the number of occurrences of a specific element in an array of integers
    cout << "6. \n";
    int arr4[] = {2,4,5,6,4,3,5,8,89,5,4};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
    cout << "How many 4s occured in array: "<<count(arr4,size4,4)<<endl;
    cout << "Count 5s in array Recursively: "<<countRec(arr4,size4-1,5)<<endl;

    //Exe 7: Count the number of digits of a given number
    cout << "7. \n";
    int num1 = 12413;
    cout<<"Number of digits : "<<countDigits(num1)<<endl;
    cout<<"Number of digits Recursively "<<countDigitsRec(num1)<<endl;
    
    //Exe 8: Convert decimal number to binary
    cout << "8. \n";
    int num2 = 223,num3=223;
    cout<<"convert 223 to Binary : "<<to_Binary(num2)<<endl;
    cout<<"convert 223 to Binary using recursive: "<<to_BinaryRec(num3)<<endl;

    //Exe 9: Calculate power of number
    cout << "9. \n";
    cout<<"Have 5^3 : "<<pow(5,3)<<endl;
    cout<<"Have 3^5 recursively : "<<powRec(3,5)<<endl;

    return 0;
}

int sumTo(int x){
    int sum=0;
    for (int i=1; i<=x;i++){
        sum+=i;
    }
        return sum;
}

int RecursiveSumTo(int x){
    if (x==0 ){return 0;}
    else if (x>0){
    return x+RecursiveSumTo(x-1);}
    else{return -1;}
}

int Fibbonacci(int x){
    int a=0,b=1,c;
    if (x<=1){return x;}
    for (int i=2;i<=x;i++){
        c=a+b;
        a=b;
        b=c;
    } return c;
}

int RecursiveFib(int x){
    if (x<=1){return x;}
    return RecursiveFib(x-1) + RecursiveFib(x-2);
}

int maxArr(int arr[],int size){
    int max=arr[0];
    for (int i=1; i <size;i++ ){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int RecMaxArr(int arr[], int size){
    return RecMaxArrHelper(arr,size,0);
}

int RecMaxArrHelper(int arr[], int size,int i){
    if (i == size-1)return arr[i];
    int max = RecMaxArrHelper(arr,size,i+1);
    return arr[i]>max ? arr[i] : max;
}

void reverseArr(int arr[], int size){
    int *left = arr;
    int *right = arr+(size-1);
    while(left<right){
        int temp = *left;
        *left = *right;
        *right = temp;

        left++; right--;
    }
}
void RecReverseArr(int arr[], int size){
    RecReverseArrHelper(arr,&arr[0],(&arr[size-1]));
}
void RecReverseArrHelper(int arr[],int* left, int* right){
    if(left>=right){
        return;
    }
    int temp = *left;
    *left = *right;
    *right = temp;
    RecReverseArrHelper(arr, left+1, right-1);
}

void palindrome(const string &word, int size){
    int left = 0;
    int right = size-1;

    while(left<right){

        if(word[left]!=word[right]){
            cout<<"String is NOT palindrome\n"<<endl; return;
        }
        left++;right--;
    }
    cout<<"String IS palindrome\n"<<endl; return;
}

void RecPalindrome(const string &word, int size){
    return RecPalindromeHelper(word,0,size-1);
}
void RecPalindromeHelper(const string &word, int left, int right){
    if (left >= right){
        cout<<"String IS palindrome"<<endl; return;
    }
    if (word[left]!=word[right]){
        cout<<"String is NOT palindrome"<<endl; return;
    }
    RecPalindromeHelper(word, left+1, right-1);
}
int count(int arr[], int size, int key){
    int counts=0;
    for (int i = 0;i<size;i++){
        if(arr[i]==key){counts++;}
    }
    return counts;
}
int countRec(int arr[], int curr, int key){
    if (curr<0) return 0;
    if(arr[curr]==key){return 1+countRec(arr,curr-1,key);}
    else return countRec(arr,curr-1,key);
}

int countDigits(int num){
    int count=0;
    while(num!= 0){
        num = num/10;
        count++;
    }
    return count;
}
int countDigitsRec(int num){
    if (num/10==0){return 1;}
    return 1+countDigitsRec(num/10);
}

int to_Binary(int num){
    int binary=0, steps=1;
    while(num!=0){
        binary+=(num%2)*steps;
        num = num /2;
        steps *=10;
    }
    return binary;
}

int to_BinaryRec(int num){
    if (num<=0) return 0;
    
    return (num%2) + 10*to_BinaryRec(num/2);
}

int pow(int num, int n){
    int prod=1;
    for (int i=0; i<n;i++){
        prod*=num;
    } return prod;
}
int powRec(int num, int n){
    if (n==0) return 1;
    return num * powRec(num,n-1);
}

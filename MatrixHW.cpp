#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void show_diagonol(const int matrix[4][4]);
void sum_rows(const int matrix[4][4]);
void sum_columns(const int matrix[4][4]);
int maxMatrix(int matrix[4][4]);
int sumD_by3n7(int matrix[4][4]);
void mirror(int matrix[4][4]);

int main(){
    //Create a Matrix of 4 rows and 4 column
    int matrix[4][4];
    int size = 4;
    // /Initialize the Matrix with random value from 0 to 99
    srand(time(0));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrix[i][j] = rand()%100;
        }
    }
    cout<<"Show Matrix: \n";
    for(int j=0;j<4;j++){
        for(int i:matrix[j]){
            cout<<setw(3)<<i<<" ";
        }
        cout<<endl;
    }
    //Write a function to show values in diagonal of the matrix
    cout << "Showing Diagonol: "<<endl;
    show_diagonol(matrix);

    //Write a function to sum all values of each row
    cout<< "Sum of all values in each row: "<<endl;
    sum_rows(matrix);

    //Write a function to sum all value of each column
    cout<< "Sum of all values in each column: "<<endl;
    sum_columns(matrix);

    //Write a function to find highest value in the Matrix
    cout<< "Find the highest value: ";
    cout<< maxMatrix(matrix)<<endl;

    //Write a function to sum all items of the matrix which value is divisible by 3 or 7
    cout<< "Write a function to sum all items of the matrix which value is divisible by 3 or 7: "<<endl;
    cout<<"Sum = "<<sumD_by3n7(matrix)<<endl;

    //Write a function to mirror the matrix
    cout<<"Fucntion to mirror matrix: "<< endl;
    mirror(matrix);
    cout<<"Show Mirrored Matrix: \n";
    for(int j=0;j<4;j++){
        for(int i:matrix[j]){
            cout<<setw(3)<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
void show_diagonol(const int matrix[4][4]){
    for (int i=0; i<4;i++){
        for(int j=0;j<i;j++){cout<<"  ";}
        cout<<setw(3)<< matrix[i][i]<<"\n";
    }
    cout<<endl;

}
void sum_rows(const int matrix[4][4]){

    for(int i=0; i<4;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=matrix[i][j];
        }
        cout<<"Row: "<<i<<": "<<sum<<endl;
    }

}
void sum_columns(const int matrix[4][4]){
    
    for(int j=0;j<4;j++){
        int sum=0;
        for(int i=0;i<4;i++){
            sum+=matrix[i][j];
        }
        cout<<"Column: "<<j<<": "<<sum<<endl;
    }
}
int maxMatrix(int matrix[4][4]){

    int max= matrix[0][0];
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            if(matrix[i][j]>max){
                max = matrix[i][j];
            }
        }
    }
    return max;
}
int sumD_by3n7(int matrix[4][4]){
    int sum=0;
    for(int i=0; i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]%3==0 || matrix[i][j]%7==0){
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
void mirror(int matrix[4][4]){
    for(int i=0; i<4; i++){
        for(int j=0;j<4/2;j++){
            int temp = matrix [i][j];
            matrix[i][j] = matrix[i][3-j];
            matrix[i][3-j] = temp;
        }
    }
}

#include <iostream>
#include <cstdlib>
#include <ctime>

int (*convolution(int matrix[28][28], int kernel[3][3], int stride)) [26];
int (*MaxPool2D(int matrix[26][26], int size_w, int stride)) [24];

int main() {
    int matrix[28][28];
    srand(time(0));

    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    int kernel[3][3] = {{1, 0, 1},
                        {0, 1, 0},
                        {1, 0, 1}};

    int stride = 1;

    for (int i = 0; i < 28; i++) {
        for (int j : matrix[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Output: " << std::endl;
    int (*output)[26] = convolution(matrix, kernel, 1);

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Max pooling Output : "<<std::endl;
    int (*MaxPool)[24] = MaxPool2D(output,3,1);
        for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            std::cout << MaxPool[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

int (*convolution(int matrix[28][28], int kernel[3][3], int stride))[26] {
    int size_i = 28;
    int size_k = 3;
    int size_output = (size_i - (size_k / stride)) + 1;

    static int output[26][26];                                     
                                                                                                 
    for (int s = 0; s < size_output; s++) {
        for (int i = 0; i < size_output; i++) {
            output[s][i] = 0; 

            for (int j = 0; j < size_k; j++) {
                for (int k = 0; k < size_k; k++) {
                    output[s][i] += matrix[s * stride + j][i * stride + k] * kernel[j][k];
                }
            }
        }
    }

    return output;
}

int (*MaxPool2D(int matrix[26][26], int size_w, int stride))[24]{
    int size_i = 26;
    int size_output = (size_i-size_w)/stride +1;

    static int pool[24][24];

    for(int c=0; c<size_output; c++){
        for(int r=0; r<size_output; r++){
            int max = matrix[c][r];

            for(int i=0; i<size_w; i++){
                for(int j=0; j<size_w; j++){

                    if (matrix[c*stride+i][r*stride+j] > max){
                        max = matrix[c*stride+i][r*stride+j];

                    }
                }
            }
            pool[c][r] = max;
        }
    }
    return pool;
}
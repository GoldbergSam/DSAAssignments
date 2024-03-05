#include <iostream>
#include <cstdlib>
#include <ctime>

int** convolution(int matrix[28][28], int kernel[3][3], int stride, int output_size);
int** MaxPool2D(int matrix[26][26], int size_w, int stride, int output_size);

void multiply_sum(int s, int i, int matrix[28][28], int kernel[3][3], int stride, int* output);
int fmax(int c, int r, int matrix[26][26], int size, int stride);

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
  std::cout<<"Matrix: "<<std::endl;
    for (int i = 0; i < 28; i++) {
        for (int j : matrix[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    int** output = convolution(matrix, kernel, stride, 26);

    std::cout << "Output: " << std::endl;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int temp_output[26][26];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            temp_output[i][j] = output[i][j];
    }
    }
    int poolsize = 3;
    int** MaxPool = MaxPool2D(temp_output,poolsize, stride, 24);

    std::cout << "Max pooling Output : " << std::endl;
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            std::cout << MaxPool[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


int** convolution(int matrix[28][28], int kernel[3][3], int stride, int output_size) {

  int** output = new int* [output_size];
  for (int i = 0; i < output_size; i++) {
    output[i] = new int[output_size];
  }

  int size = (28 - 3/stride) + 1;

  for (int s = 0; s < size; s++) {
    for (int i = 0; i < size; i++) {
      multiply_sum(s, i, matrix, kernel, stride, &output[s][i]);
    }
  }

  return output;
}

void multiply_sum(int s, int i, int matrix[28][28], int kernel[3][3], int stride, int* output) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            sum += matrix[s * stride + j][i * stride + k] * kernel[j][k];
        }
    }
    *output = sum;
}

int** MaxPool2D(int matrix[26][26], int size_w, int stride, int output_size) {

  int** Pool = new int* [output_size];
  for (int i = 0; i < output_size; i++) {
    Pool[i] = new int[output_size];
  }
  int size = (26 - size_w + stride) / stride;

  for (int c = 0; c < size; c++) {
    for (int r = 0; r < size; r++) {
      Pool[c][r] = fmax(c, r, matrix, size_w, stride);
    }
  }

  return Pool;
}


int fmax(int c, int r, int matrix[26][26], int size, int stride){
    int max = matrix[c * stride][r * stride];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::max(max, matrix[c * stride + i][r * stride + j]);
            }
        }
    return max;
}


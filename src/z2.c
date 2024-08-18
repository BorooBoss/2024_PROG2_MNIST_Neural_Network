#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h" // ReLU funkcia a pomocne funkcie
#include "data.h" // Makra, vahy a bias hodnoty

double* funkc2(double *pixels, double* result){
    double temp = 0;
    for (int neuron = 0; neuron < 10; neuron++){
        for (int i = 0; i < IMAGE_SIZE; i++) {
            temp += (weights[(neuron*IMAGE_SIZE)+i] * (pixels[i]));
        }
        temp += bias[neuron];
        result[neuron] = relu(temp);
        temp = 0;
        //printf("%5.2lf\n", result[neuron]);

    }
    return result;

}
double* funkc3(double *result, double *result_softmax){
    double sum_softmax = 0;
    double max = result[0];

    for (int i = 0; i < 10; i++) {
        if (result[i] > max) {
            max = result[i];
        }
    }
    for (int j = 0; j < 10; j++) {
        sum_softmax += exp(result[j] - max);
        //printf("%4.2lf\n", sum_softmax);
    }
    for (int i = 0; i < 10; i++){
        result_softmax[i] = exp(result[i] - max) / sum_softmax;
        //printf("%4.2lf ", result_softmax[i]);
    }
    return result_softmax;
}
int funkc4(double *result_softmax){
    double find_max_max = result_softmax[0];
    int find_max_index = 0;
    for (int j = 0; j < 10; j++){
        if (result_softmax[j] > find_max_max){
            find_max_max = result_softmax[j];
            find_max_index = j;
        }
    }
    printf("%i", find_max_index);
    return find_max_index;
}
int main(void) {
    int mode;
    int neuron_index;
    scanf("%i", &mode);
    if (mode == 1) {
        scanf("%i", &neuron_index);
        for (int i = 0; i < IMAGE_SIZE; i++) {
            printf("%8.2lf", weights[(neuron_index*IMAGE_SIZE)+i]);
            if ((i + 1) % 10 == 0) {
                printf("\n"); }
        };
    } else if (mode == 2) {
        double obrazok[IMAGE_SIZE];
        double result = 0;
        scanf("%i", &neuron_index);
        for (int i = 0; i < IMAGE_SIZE; i++) {
            scanf("%lf", &obrazok[i]); // Read values into the array
            result += (weights[(neuron_index*IMAGE_SIZE)+i] * (obrazok[i]));}

        result += bias[neuron_index];
        printf("%5.2lf", result);
    } else if (mode == 3){
        double relu_number;
        double relu_result;
        scanf("%lf", &relu_number);
        relu_result = relu(relu_number);
        printf("%4.2lf", relu_result);

    } else if (mode == 4) {
        double z[10];
        double sum_softmax = 0;
        double result_softmax[10];
        for (int i = 0; i < 10; i++) {
            scanf("%lf", &z[i]);
        }
        double max = z[0];

        for (int i = 0; i < 10; i++) {
            if (z[i] > max) {
                max = z[i];
            }
        }
        for (int j = 0; j < 10; j++) {
            sum_softmax += exp(z[j] - max);
            //printf("%4.2lf\n", sum_softmax);
        }
        for (int i = 0; i < 10; i++) {
            result_softmax[i] = exp(z[i] - max) / sum_softmax;
            printf("%0.2lf ", result_softmax[i]);
        }
    } else if (mode == 5){
        double max_array[10];
        for (int i = 0; i < 10; i++) {
            scanf("%lf", &max_array[i]);
        }
        double find_max_max = max_array[0];
        int find_max_index = 0;
        for (int j = 0; j < 10; j++){
            if (max_array[j] > find_max_max){
                find_max_max = max_array[j];
                find_max_index = j;
            }
        }
        printf("%i", find_max_index);

    } else if (mode == 6){
        double draw[IMAGE_SIZE];
        for (int i = 0; i < IMAGE_SIZE; i++){
            scanf("%lf", &draw[i]);
        }
        print_image(draw, IMAGE_WIDTH, IMAGE_HEIGHT);
    } else if (mode == 7) {
        double pixels[IMAGE_SIZE];
        int neurons_amount = 10;
        double result[neurons_amount];
        double result_softmax[neurons_amount];
        load_data(pixels, IMAGE_SIZE);
        funkc2(pixels, result);
        //for (int i = 0; i < 10; i++){
//printf("%5.2lf\n", result[i]);
        // }
        funkc3(result, result_softmax);
        //for (int i = 0; i < 10; i++) {
            //printf("%5.2lf\n", result_softmax[i]);
        //}
        funkc4(result_softmax);
        return 0;
    }
}
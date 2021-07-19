#include <iostream>

// Conta o número de 1's em um frame
int one_freq(int frame[], int inicio, int fim){
    int freq = 0;
    for (int i = inicio; i < fim; i++){
        if (frame[i] == 1)
            freq++;
    }
    return freq;
}
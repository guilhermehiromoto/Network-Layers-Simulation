#include <iostream>
#include <cstring>
#include "communication.h"
#include "utils.h"

using namespace std;

void MeioDeComunicacao (int fluxoBrutoDeBits[]){
    int porcentagemDeErros;
    int fluxoBrutoDeBitsPontoA[MESSAGE_SIZE + CRC], fluxoBrutoDeBitsPontoB[MESSAGE_SIZE + CRC];

    porcentagemDeErros = 50; // 0%, 10%, 20% ... 100%

    for (int i = 0; i < MESSAGE_SIZE + CRC; i++)
        fluxoBrutoDeBitsPontoA[i] = fluxoBrutoDeBits[i];
    
    memset(fluxoBrutoDeBitsPontoB, 0, sizeof(fluxoBrutoDeBitsPontoB));

    for (int i = 0; i < MESSAGE_SIZE + CRC; i++){
        if (rand()%100 >= porcentagemDeErros) 
            fluxoBrutoDeBitsPontoB[i] += fluxoBrutoDeBitsPontoA[i];
        else{ 

            fluxoBrutoDeBitsPontoB[i] == 0 ?
            fluxoBrutoDeBitsPontoA[i] = ++fluxoBrutoDeBitsPontoB[i]:
            fluxoBrutoDeBitsPontoA[i] = --fluxoBrutoDeBitsPontoB[i];
        }
    }

    for (int i = 0; i < MESSAGE_SIZE + CRC; i++)
        fluxoBrutoDeBits[i] = fluxoBrutoDeBitsPontoA[i];
}
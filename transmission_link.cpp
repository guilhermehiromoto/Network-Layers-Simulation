#include <iostream>
#include "transmission_link.h"
#include "utils.h"

using namespace std;

//Função que seta o controle de erro de CRC
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(int frame[]){
    int frame_copy[MESSAGE_SIZE+CRC];

    for (int i = 0; i < MESSAGE_SIZE+CRC; i++)
        frame_copy[i] = frame[i];

    for (int i = 0; i < MESSAGE_SIZE; i++){
        if (frame_copy[i] == 0) 
            continue;
        
   
        for (int j = 0; j < CRC; j++){
            if (frame_copy[i+j] == crc32[j])
                frame_copy[i+j] = 0;
            else
                frame_copy[i+j] = 1;
        }
    }

    for (int i = MESSAGE_SIZE; i < MESSAGE_SIZE+CRC; i++)
        frame[i] = frame_copy[i];
    
}

// Função que seta o controle de erro de paridade par
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (int frame[]){
    if (one_freq(frame, 0, MESSAGE_SIZE+CRC) % 2 == 0)
        frame[MESSAGE_SIZE+1] = 0;
    else 
        frame[MESSAGE_SIZE+1] = 1;
}

// Função que seta o controle de erro de paridade par
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar (int frame[]){
    if (one_freq(frame, 0, MESSAGE_SIZE+CRC) % 2 != 0)
        frame[MESSAGE_SIZE+1] = 0;
    else 
        frame[MESSAGE_SIZE+1] = 1;
}

// Função auxiliar para o controle de erro
void CamadaEnlaceDadosTransmissoraControleDeErro (int frame[], int error_control){
    switch (error_control){ 
    case 0: // paridade par
        CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(frame);
        break;
    case 1: // paridade impar
        CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(frame);
        break;
    case 2: // CRC
        CamadaEnlaceDadosTransmissoraControleDeErroCRC(frame);
        break;
    default:
        break;
    }
}

// Função para setar o controle de erro
void CamadaEnlaceDadosTransmissora(int frame[], int error_control){
    CamadaEnlaceDadosTransmissoraControleDeErro(frame, error_control);
}
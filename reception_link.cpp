#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#include "reception_link.h"
#include "utils.h"

using namespace std;

//Função que checka o controle de erro de CRC
// Retorna true caso tenha erro e false caso esteja tudo certo
bool CamadaEnlaceDadosReceptoraControleDeErroCRC(int frame[]){

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

    for (int i = MESSAGE_SIZE; i < MESSAGE_SIZE+CRC; i++){
        if (frame_copy[i] == 1){
            cout << "Erro" << endl;
            return true; 
        }
    }
    cout << endl << "|CAMADA DE ENLACE (Recepção)| Mensagem válida" << endl;
    return false;
}


// Funcao que checka o erro de paridade impar
// Retorna true caso tenha erro e false caso esteja tudo certo
bool CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar (int frame[]){

    if (one_freq(frame, 0, MESSAGE_SIZE+CRC) % 2 == 0){ 
        cout << "Erro" << endl;
        return true;
    }
    cout << endl << "|CAMADA DE ENLACE (Recepção)| Mensagem válida" << endl;
    return false;
}

// Funcao que checka o erro de paridade par
// Retorna true caso tenha erro e false caso esteja tudo certo
bool CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar (int frame[]){

    if (one_freq(frame, 0, MESSAGE_SIZE+CRC) % 2 == 0){ 
        cout << endl << "|CAMADA DE ENLACE (Recepção)| Mensagem válida" << endl;
        return false;
    }
    cout << "Erro" << endl;
    return true;
}


// Função auxiliar para o controle de erro
bool CamadaEnlaceDadosReceptoraControleDeErro (int frame[], int error_control){
    switch (error_control){ 
    case 0: // paridade par
        return CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(frame);
    case 1: // paridade impar
        return CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(frame);
    case 2: // CRC
        return CamadaEnlaceDadosReceptoraControleDeErroCRC(frame);
    default:
        break;
    }

    return false;
}

// Função para executar o controle de erro
// Retorna true caso tenha erro e false caso esteja tudo certo
bool CamadaEnlaceDadosReceptora(int frame[], int error_control){
    return CamadaEnlaceDadosReceptoraControleDeErro(frame, error_control);

}
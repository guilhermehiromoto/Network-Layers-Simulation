#include <iostream>
#include <bits/stdc++.h>
#include "utils.h"
#include "transmission_app.h"
#include "transmission_link.h"
#include "communication.h"
#include "reception_link.h"
#include "reception_app.h"

int main (){

    string message;
    
    int frame[MESSAGE_SIZE+CRC];
    int error_control = 2;
    memset(frame, 0, sizeof(frame));

    // Camada de Aplicação da transmissão
    AplicacaoTransmissora(message, frame);

    // Camada de Enlace da transmissão
    CamadaEnlaceDadosTransmissora(frame, error_control);

    // Camada física da transmissão + Meio de Comunicação + Camada física da recepção 
    MeioDeComunicacao (frame);

    // Camada de Enlace da recepção
    if (!CamadaEnlaceDadosReceptora(frame, error_control)){
        
        // Camada de Aplicação da recepção
        CamadaDeAplicacaoReceptora(frame, message.length());
    }


    return 0;
}
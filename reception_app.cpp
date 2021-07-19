#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include "utils.h"
#include "reception_app.h"

using namespace std;

void AplicacaoReceptora(char message[], int messageSize){
    cout << endl << "|CAMADA DE APLICAÇÃO (Recepção)| Mensagem recebida: ";
    for (int i = 0; i < messageSize; i++){
        cout << message[i];
    }
    cout << endl << endl;
}

void CamadaDeAplicacaoReceptora(int frame[], int messageSize){
    char message[MESSAGE_SIZE];
    for (int i = 0; i < messageSize; i++){
        ostringstream os;
        for (int j = 0; j<8; j++) {
            os << frame[8*i+j];
        }

        string charBitString(os.str());

        char c1 = static_cast<char>(stoi(charBitString,0,2));
        message[i] = c1;
    }

    AplicacaoReceptora(message, messageSize);
}




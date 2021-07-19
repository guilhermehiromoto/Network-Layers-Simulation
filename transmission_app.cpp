#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#include "transmission_app.h"
#include "utils.h"

using namespace std;

void AplicacaoTransmissora(string& message, int frame[]){
    cout << "Digite uma mensagem: " << endl;
    cin >> message;
    CamadaDeAplicacaoTransmissora(message, frame);
}

void CamadaDeAplicacaoTransmissora(string message, int frame[]){

    string binary_string = "";

    for (char& _char : message) {
        binary_string +=bitset<8>(_char).to_string();
    }

    cout << endl <<"|CAMADA DE APLICAÇÃO (Transmissão)| Mensagem em bits: ";

    for (int i = 0, j = 0; j <= binary_string.size()-1; i++, j++){
        frame[i] = int(binary_string[j]) - '0';
        cout << frame[i];
    }
    cout << endl;

}


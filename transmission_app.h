#include <string>

using namespace std;

#define MESSAGE_SIZE 8*30
#define CRC 32

void AplicacaoTransmissora(string& message, int frame[]);

void CamadaDeAplicacaoTransmissora(string message, int frame[]);
#include "pacienteESP.h"


string
pacienteESP::getNome(){
    return paciente::getNome() + "\t Esse paciente é especial";
}

ostream&
operator<<(ostream& output,pacienteESP &entrada){
    
    output << (entrada).getNome() << "\n";
    return output;

}

pacienteESP::pacienteESP(string n): paciente(n)
{
    setNome(n);
}
#include <iostream>
#include <exception>

using namespace std;

class erroInserir : public exception {

    public:

        erroInserir()
        : exception() {}
        virtual const char * what() const throw() {
            return "Paciente já existente";
        }
};

class erroBuscar : public exception {

    public:

        erroBuscar() 
        : exception() {}

        virtual const char * what() const throw() {
            return "Paciente Não achado";
        }
};
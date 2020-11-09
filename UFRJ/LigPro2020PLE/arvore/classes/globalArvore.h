#ifndef GLOBAL_H
#define GLOBAL_H

#include "arvore.h"

bool 
operator==(filme,filme);

bool 
operator<(filme,filme);

bool
operator>(filme,filme);


istream & operator>>(istream &input, filme &saida);
ostream & operator<<(ostream &output, const filme A);
ostream & operator<<(ostream &output, const catalogo A);


#endif

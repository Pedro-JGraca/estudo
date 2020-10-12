#include "grafo.h"
#include "aresta.h"
#include <vector>

using namespace std;

grafo::grafo(string entrada)
{
    for (unsigned i=0, a=0 ; i<entrada.size() ;i++){
        //linha
        if (
            (entrada[i] == '.') or
            (entrada[i] == ',') or
            (entrada[i] == ';')
        )
        {
            if (entrada.substr(a,i-a)[0] == ' '){
                linha.push_back(entrada.substr(a+1,i - a -1));
            }
            else {
                linha.push_back(entrada.substr(a, i - a ));
            }
            a = i+1;
        }
        
    }

    for (unsigned index= 0; index<linha.size();index++){
        setCaminho(linha[index]);
    }

 

}


string
grafo::getMaior(){
    //string saida;
    unsigned maior=0;
    unsigned indice = 0;
    for (unsigned i = 0; i< vertices.size();i++){
        if (maior < vertices[i].getChamadas()){
            maior = vertices[i].getChamadas();
            indice = i;
        }
    }

    return vertices[indice].getNome();


}

string
grafo::getSequencia(unsigned uni){
    
    if ((uni <2) or (uni > 5))
        return "N nao aceito. So são aceitos de 2 a 5";

    vector <string> respostas;
    vector <unsigned> menor;
    string resposta;
    

    for (unsigned aux = 0; aux < vertices.size();aux++){
        vertice * a = &vertices[aux];
        vector <string> saida;
        vector <vector <string>> nova;

        for (unsigned i = 0; i<uni ;i++){
            if (a->getAponta(0)){
                saida.push_back(a->getNome());
                if(a ->getApontaSize()>1){
                    nova.push_back(saida);
                }
                a =encontraVertice(a->getAponta(0)->getPonta());
            }
            else{
                if (saida.size()){
                    if(a->getNome()!= saida[saida.size()-1]){
                        saida.push_back(a->getNome());
                    }
                }
            }            
        }
        for ( unsigned i = 0;i<nova.size();i++){
            a = encontraVertice(nova[i][nova[i].size()-1]);
            unsigned temp = a->getApontaSize();
            if (nova[i].size()<uni){
                for (unsigned aux = 1;aux<temp;aux++){
                    a = encontraVertice(a->getAponta(aux)->getPonta());
                    nova[i].push_back(a->getNome());
                }
                while (nova[i].size()<uni) {
                    a = encontraVertice(a->getAponta(0)->getPonta());
                    nova[i].push_back(a->getNome());
                }
            }
            respostas.push_back("");
            menor.push_back(0);
            for (unsigned aux = 0;aux<nova[i].size();aux++){
                respostas[respostas.size()-1] += encontraVertice(nova[i][aux])->getNome()+"->";
                if ((encontraVertice(nova[i][aux])->getApontaSize()>0) and ((aux+1)!=uni)){
                    unsigned aa = (encontraVertice(nova[i][aux])->getAponta(0)->getSit());
                    if ((aa < menor[menor.size()-1]) or (menor[menor.size()-1]==0))
                        menor[menor.size()-1] = aa;
                }
            }
            
        }
        menor.push_back(0);
        respostas.push_back("");
        for (unsigned i = 0; i<uni ;i++){
            if (saida.size()==uni){
                respostas[respostas.size()-1] += (encontraVertice(saida[i])->getNome() + "->");
                if ((encontraVertice(saida[i])->getApontaSize()>0) and ((i+1)!=uni)){
                    unsigned aa = (encontraVertice(saida[i])->getAponta(0)->getSit());
                    if ((aa <menor[menor.size()-1]) or (menor[menor.size()-1] ==0))
                        menor[menor.size()-1] =aa; 
                }
                
            }
        }
    }
    unsigned menos= menor[0];
    resposta = respostas[0];
    for (unsigned i = 0; i<respostas.size() ; i++){
        if(respostas[i]!="")
            if (menos <menor[i]){
                resposta= respostas[i];
                menos = menor[i];
            }
                
    }


    return resposta;

}

void
grafo::getLinha(){
    for (unsigned char i= 0; i<linha.size();i++){
        cout << linha[i] << endl;
    }
}

void
grafo::setCaminho (string line){
    vector <string> vertice;
    
    for (unsigned p = 0, a = 0; p < line.size(); p ++){
        if ((line[p] == ' ') or ((p+1) == line.size())){
            vertice.push_back(line.substr(a,p - a +1));
            a = p +1;
        }
    }//pega a linha e separa as palavras, criando uma lista de vertices temporarios

    for (unsigned i = 0; (i) < vertice.size(); i++){
        setVertice(strip(vertice[i]));
    }//constroi os vertices

    for (unsigned i = 0; (i+1) < vertice.size(); i++){
        setAresta(strip(vertice[i]), strip(vertice[i+1]));
    }//constroi as arestas

}

void
grafo::setAresta (string A, string B) {

    bool encontrei = false;
    vertice * ptr = encontraVertice(A);
    for (unsigned i =0;i<ptr->getApontaSize();i++){
        if (ptr->getAponta(i)->getPonta()==B){ //encontrei aresta igual
            ptr->getAponta(i)->setSit(1);
            encontrei=true;
        }
    }
    if (!encontrei){
        aresta *ARESTA = new aresta(A,B); //precisa dar del
        ptr->setApontaAresta(ARESTA);
        encontraVertice(B)->setRecebeAresta(ARESTA);
    }
}

vertice *
grafo::encontraVertice(string A){
   for (unsigned i = 0;  i<vertices.size(); i++){
       if (vertices[i].getNome()==A){
           return &vertices[i];
       }
   }
   return NULL;
}

void
grafo::setVertice(string A){
    if (!verificaVertice(A)){//se nao tem vertice
        vertices.push_back(vertice(A));
    }
    else {
        encontraVertice(A)->setChamadas();
    }
}


bool
grafo::verificaVertice (string A){
    for (unsigned i = 0;i < vertices.size();i++){
        if (A==vertices[i].getNome()){
            return true;
        }
    }
    return false;
}

string
grafo::strip (string A){
    if (A[0]== ' '){
        A = A.substr(1,A.size());
    }
    if (A[A.size()-1]== ' '){
        A = A.substr(0,A.size()-1);
    }
    return A;
}
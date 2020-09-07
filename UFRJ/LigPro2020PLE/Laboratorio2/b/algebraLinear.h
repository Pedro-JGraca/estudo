class Ponto
{
private:
    int coordenada[3];
public:
    Ponto();//construtor
    void
    setX(int); //coordenada[0]
    void
    setY(int); //coordenada[1]
    void
    setZ(int); //coordenada[1]
    
    int
    getX();
    int
    getY();
    int
    getZ();

    int*
    getCoordenadas();
    
    void
    printCoordenadas();
};


class Linha
{
private:
    Ponto p1;
    Ponto p2;
public:
    Linha(Ponto,Ponto);
    void
    setPontoUm(int,int,int);
    void
    setPontoDois(int,int,int);
    
    int *
    getPontoUm();
    int *
    getPontoDois();

    double
    getComprimento();
};



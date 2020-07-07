package aula02;

import static java.lang.System.out;

public class Caneta {
    String modelo;
    String cor;
    float ponta;
    int carga;
    boolean tampada;
    void rabiscar(){
        if (this.tampada != true){
            out.println("Nao se escreve sem tampa");
        } else {
            out.println("RABISCAR");
        }
    }
    void tampar(){
        this.tampada=true;
    }
    void destampar() {
        this.tampada = false;
    }

    void status(){
        out.println("O Modelo eh "+ this.modelo);
        out.printf("Uma caneta %s%n", this.cor);
        out.println("Ponta: " + this.ponta);
        out.println("Carga:" + this.carga + "%");
        out.println("Está tampada? " + this.tampada);

    }
}

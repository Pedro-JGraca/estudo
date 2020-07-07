package app.canino;

public class Lobo extends Mamifero {

    @Override
    public void emitirSom() {
        System.out.println("Au!!!!!!!");
    }
    public void reagir (boolean perto){
        if (true){
            System.out.println("Atacar");
        }
        else {
            System.out.println("Rosnar");            
        }
    }
    
}
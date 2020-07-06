package app.canino;

public class Cachorro extends Lobo {


    @Override
    public void emitirSom() {
        System.out.println("Au!Au!");
    }

    public void reagir (String frase){
        if (frase.equals("Tome Biscoito")|| frase.equals("Olá")) {
            System.out.println("Abanar");
        }
        else {
            System.out.println("Rosnar");
        }
    }
    public void reagir (boolean dono){
        if (dono){
            System.out.println("Abanar");

        }
        else {
            System.out.println("rosnar");

        }
    }
    public void reagir (int hora, int minuto){
        if (hora < 12) {
            System.out.println("Abanar");
        }
        else if (hora >= 18) {
            System.out.println("ignorar");
        }
        else {
            System.out.println("Abanar e Latir");
        }
    }
    public void reagir (int idade, float peso) {
        if (idade <10){
            if (peso < 10) {
                System.out.println("Abanar");            
            } else {
                System.out.println("Latir!");
            }
        }
        else {
            if (peso<10) {
                System.out.println("Rosnar");                
            } else {
                System.out.println("Ignorar");
            
            }
        }
    }

    
}
package app;

import app.canino.*;

public class App {
    public static void main(String[] args) throws Exception {
        Lobo x = new Lobo();
        x.emitirSom();
        Cachorro a = new Cachorro();
        a.emitirSom();

        a.reagir("Vai apanhar");
        a.reagir("Olá");
        a.reagir(11,45);
        a.reagir(true);
        x.reagir(true);
    
    }
}
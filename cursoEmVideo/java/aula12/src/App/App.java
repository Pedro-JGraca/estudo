package App;

import mae.filho.*;

public class App {
    public static void main(String[] args) throws Exception {
        //animal a = new animal();
        mamifero m = new mamifero();
        reptil r = new reptil();
        ave a = new ave();
        peixe p = new peixe(); //12:20M

        
        m.setPeso(35.3f);
        m.setCorPelo("Marrom");

        m.alimentar();
        m.locomover();
        m.emitirSom();

        a.locomover();

        p.locomover();


    }
}
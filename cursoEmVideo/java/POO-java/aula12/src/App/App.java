package App;

import mae.filho.*;
import mae.filho.neto.Arara;
import mae.filho.neto.Cobra;
import mae.filho.neto.Conguru;
import mae.filho.neto.GoldFish;
import mae.filho.neto.Tartaruga;

public class App {
    public static void main(String[] args) throws Exception {
        //animal a = new animal();
        mamifero m = new mamifero();
        reptil r = new reptil();
        ave a = new ave();
        peixe p = new peixe(); //12:20M

        Conguru C = new Conguru();
        Cobra J = new Cobra();
        Tartaruga T = new Tartaruga(); 
        GoldFish G = new GoldFish();
        Arara E = new Arara();

        C.locomover();

        m.setPeso(35.3f);
        m.setCorPelo("Marrom");

        m.alimentar();
        m.locomover();
        m.emitirSom();

        a.locomover();

        p.locomover();

        r.locomover();


    }
}
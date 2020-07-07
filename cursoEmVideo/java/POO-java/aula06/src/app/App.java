package app;

import app.classe.*;

public class App {
    public static void main (String[] args) {
        ControleRemoto c1 = new ControleRemoto();
        c1.ligar();
        c1.maisVolume();
        c1.ligarMudo();
        c1.abrirMenu();

    }
}

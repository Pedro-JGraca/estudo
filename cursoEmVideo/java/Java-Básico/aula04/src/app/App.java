package app;

import java.awt.*;
import java.util.*;



public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello Java");
        Date data = new Date();
        Locale idioma = Locale.getDefault();
        Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
        System.out.println("Data: " + data.toString());
        System.out.println("Lingua Sistema: " + idioma.getDisplayLanguage());
        System.out.println("Reolução da Tela: " + d.width + "x" + d.height );
    }
}
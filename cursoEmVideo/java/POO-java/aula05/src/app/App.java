package app;

import app.classes.*;

public class App {

    public static void main(String[] args) {
        Pessoa joao = new Pessoa("joao", 400f, 200f);
        Pessoa maria = new Pessoa("maria", 500f, 150f);

        System.out.println(maria.toString());
        System.out.println(joao.toString());

        Banco bjoao = new Banco(joao);
        Banco bmaria = new Banco(maria);

        System.out.println(bjoao.toString());
        System.out.println(bmaria.toString());

        bjoao.abrirConta("cc");
        bmaria.abrirConta("cp");

        System.out.println(bjoao.toString());
        System.out.println(bmaria.toString());

        bjoao.pagarMensal();
        bmaria.pagarMensal();

        System.out.println(bjoao.toString());
        System.out.println(bmaria.toString());
    }
}



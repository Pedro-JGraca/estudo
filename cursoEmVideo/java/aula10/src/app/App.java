package app;

import app.pacote.*;

public class App {
    public static void main (String[] args) {
			Pessoa p0= new Pessoa("Pedro",32,'M');
			Aluno p1 = new Aluno("Maria",22,'F',1, "informática");
			Professor p2 = new Professor("Cláudio",49, 'M', "Informática", 2500.75f);
			Funcionario p3 = new Funcionario("Fabiana",12, 'F', "Estroque", true);

			System.out.println(p0.toString());
			System.out.println(p1.toString());
			System.out.println(p2.toString());
			System.out.println(p3.toString());


		}
}

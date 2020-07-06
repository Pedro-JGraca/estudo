package aula11;

import aula11.classeRaiz.ClassesFilhas.*;
import aula11.ClassesFilhas.ClassesNetas.*;

public class Principal {

	public static void main(String[] args) {
		Visitante v1 = new Visitante();
		System.out.println(v1.toString());
		Aluno a1 = new Aluno();

		a1.setNome("Claudio");
		a1.setMatricula(1111);
		a1.setCurso("informática");
		a1.setIdade(16);
		a1.setSexo('M');
		System.out.println(a1.toString());
		
		Bolsista b1 = new Bolsista();
		b1.setNome("Jubileu");
		b1.setMatricula(1112);
		b1.setCurso("informática");
		b1.setIdade(15);
		b1.setSexo('M');
		b1.setBolsa(100);
		System.out.println(b1.toString());
		
		a1.pagarMensalidade();
		b1.pagarMensalidade();
	}

}

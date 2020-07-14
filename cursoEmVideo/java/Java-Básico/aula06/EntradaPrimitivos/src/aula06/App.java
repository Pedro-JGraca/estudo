package aula06;

import java.util.Scanner;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner teclado = new Scanner(System.in);
		System.out.print("Digite o nome do Aluno:");
		String nome = teclado.nextLine();
		System.out.print("Digite a nota:");
		float nota = teclado.nextFloat();
		System.out.printf("A nota de %s e %.1f \n", nome,nota);
		
	}

}

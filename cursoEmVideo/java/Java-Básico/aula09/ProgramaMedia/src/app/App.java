package app;

import java.util.Scanner;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner teclado =new Scanner(System.in);
		System.out.print("Nota1: ");
		float n1 = teclado.nextFloat();
		System.out.print("Nota2: ");
		float n2 = teclado.nextFloat();
		float m = (n1+n2)/2;
		if (m>=9) {
			System.out.println("parabêns");
		}
		System.out.println("Sua media foi "+ m);
		
		teclado.close();

	}

}

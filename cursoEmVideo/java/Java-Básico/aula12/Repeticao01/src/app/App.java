package app;

import java.util.Scanner;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int cc=0;
		
		do {
			System.out.println( ++cc + ". cambalhota");
		}while (cc<4);
		
		int n, s=0;
		String resp;
		Scanner teclado = new Scanner(System.in);
		do {
			System.out.print("Digite um numero");
			n = teclado.nextInt();
			s+=n;
			System.out.println("Quer Continuar? [S/N]");
			resp = teclado.next();
		}while ( resp.equals("s") || resp.equals("S") );
		
		
		System.out.print("A soma é: " + s);
		
		
		teclado.close();
		

	}

}

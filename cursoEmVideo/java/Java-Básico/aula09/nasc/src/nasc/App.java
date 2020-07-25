package nasc;

import java.util.Calendar;
import java.util.Scanner;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner teclado =new Scanner(System.in);
		Calendar cal = Calendar.getInstance();
		
		System.out.print("Ano de nascimento:");
		int nasc = teclado.nextInt();
		int ida = cal.get(Calendar.YEAR) - nasc;
		if (ida >= 18) {
			System.out.println("de Maior");
		}
		else {
			System.out.println("de Menor ");
		}
		teclado.close();
		
		

	}

}

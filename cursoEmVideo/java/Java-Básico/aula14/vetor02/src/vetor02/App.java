package vetor02;

import java.util.Arrays;
import java.util.Calendar;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] mes = {"Jan","Fev","Mar","Abr","Mai","Jun",
				"Jul","Ago","Set","Out","Nov","Dez"};
		
		int[] tot = {31,28,31,30,31,30,
				31,31,30,31,30,31};
		Calendar cal = Calendar.getInstance();
		
		if (cal.get(Calendar.YEAR)%4==0) {
			tot[1]=29;
		};
		

		for (int i=0;i<mes.length;i++) {
			System.out.println("O mes de " + mes[i] + " tem "
					+tot[i] + " dias ao todo");
		}

		int i = 0;
		System.out.println("");
		for (String mesi: mes) {
		
			System.out.println("O mes de " + mesi + " tem "
					+tot[i] + " dias ao todo");
			i++;
		}
		
		int[] ord = {3,5,1,8,4};
		
		System.out.println("\n\n Vetor sem ordem");
		for (int valor:ord) {
			System.out.print(valor+ " ");
		}
		
		System.out.println("\n\n Vetor com ordem");
		Arrays.sort(ord);
		for (int valor:ord) {
			System.out.print(valor+ " ");
		}
		
		System.out.println("\n\n Vetor limpo");

		Arrays.fill(ord, 0);
		for (int valor:ord) {
			System.out.print(valor+ " ");
		}

	}

}

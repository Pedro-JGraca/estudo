package contador01;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int cc = 0;
		
		while (cc <20) {
			cc++;
			if (cc == 5 || cc == 7) {
				continue;
			}
			if (cc == 9) {
				break;
			}
			System.out.println(cc +".\tCambalhota");
		}
		

	}

}

package classes;

import javax.swing.JOptionPane;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//JOptionPane.showMessageDialog(null, "Ola mundo", "Titulo", JOptionPane.WARNING_MESSAGE);
		int n, t =-1, p=0,Acima=0,M=0;
		//3,6,5,200,150,120,5,9
		do {
			n = Integer.parseInt(JOptionPane.showInputDialog(null,
					"<html>informe um numero<br><em>(valor 0 interrompe)</em></html>"));
			t++;
			if (n%2==0) {
				p++;
			}
			if (n>100) {
				Acima++;
			}
			
			M+=n;
		}while (n!=0);
		M/=t;

		JOptionPane.showMessageDialog(null,
				"<html>Total de valores: "+ t + "<br>" +
				"<html>Total de Pares: "+ p + "<br>" +	
				"<html>Total de Impares: "+ (t-p) + "<br>" +
				"<html>Acima de 100: "+ Acima + "<br>" +
				"<html>Media Aritmética: "+ M + "<br>" +
				"</html>"
				);
	}
}

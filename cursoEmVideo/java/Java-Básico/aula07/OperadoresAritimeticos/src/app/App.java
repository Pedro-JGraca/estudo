package app;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n1 =3;
		int n2 = 5;
		float m = (n1+n2)/2;
		System.out.printf("A média de %d e %d é %.1f\n",n1,n2, m);
		
		int numero = 5;
		int valor = 5 + numero++;
		System.out.printf("Pós : %s\n", valor);
		numero=5;
		valor = 5 + ++numero;
		System.out.printf("Pré : %s\n", valor);

		
		numero = 4;
		numero *=2;
		System.out.print(numero+ "\n");
		
		float v = 8.5f;
		int ar = (int) Math.floor(v);
		System.out.printf("O arredondamendo floor de %.1f é %d\n",v,ar);
		
		ar = (int) Math.round(v);
		System.out.printf("O arredondamendo round de %.1f é %d\n",v,ar);
		
		double ale = Math.random();
		int sup=11; //nao inclui o superior (vai de 5,...1 até 10,...9 ~ 5 a 10)
		int sub=5;
		ale = sub + ale*((sup--)-sub);
		System.out.printf("Valor aleatorio entre %d e %d é %d\n",sub,sup,(int)ale);
		
		System.out.println();	
	}

}

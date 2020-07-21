package app;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String nome1 = "Gustavo";
		String nome2 = "Gustavo";
		String nome3 = new String("Gustavo");
		String res;
		res = (nome1==nome2)?"iguais":"diferentes";
		System.out.println("Strings são " + res);
		res = (nome1== nome3)?"iguais":"diferentes";
		System.out.println("String e Objeto são " + res);
		res = (nome1.equals(nome3))?"iguais":"diferentes";
		System.out.println("Mas o conteudo deles sao " + res);
	}

}

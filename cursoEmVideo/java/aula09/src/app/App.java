package app;

import app.pacote.*;

public class App 
{
	public static void main (String[] args)
		{
			Pessoa[] p = new Pessoa[2];
			Livro[] l= new Livro[3];

			p[0] = new Pessoa("Pedro",22,'M');
			p[1] = new Pessoa("maria", 25, 'F');
			l[0] = new Livro("Aprendendo Java", "Jose da silva", 300, p[0]);
			l[1] = new Livro("POO para iniciantes", "Pedro Paulo", 400, p[1]);
			l[2] = new Livro("Java avançado", "Maria", 800, p[0]);


			l[0].abrir();
			l[0].folhear(200);
			l[0].avancarPagina();
			
			System.out.println(l[0].detalhes());
		}
}

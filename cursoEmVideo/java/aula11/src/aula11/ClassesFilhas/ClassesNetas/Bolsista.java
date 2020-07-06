package aula11.ClassesFilhas.ClassesNetas;

import aula11.classeRaiz.ClassesFilhas.Aluno;

public class Bolsista extends Aluno{
	private float bolsa;
	
	public void renovarBolsa() {
		System.out.println("Renovando bolsa de " + this.getNome());
	}

	public float getBolsa() {
		return bolsa;
	}

	public void setBolsa(float bolsa) {
		this.bolsa = bolsa;
	}
	
	@Override
	public void pagarMensalidade() {
		System.out.println(this.getNome() + " é Bolsista! Pagamento facilidato.");
	}
	
	
 
}

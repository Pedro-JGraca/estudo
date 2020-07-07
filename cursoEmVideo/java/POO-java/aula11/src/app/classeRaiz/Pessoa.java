package app.classeRaiz;

public abstract class Pessoa {
	private String nome;
	private int idade;
	private char sexo;
	
	@Override
	public String toString() {
		return "Dados: {nome=" + nome + ", idade=" + idade + ", sexo=" + sexo + "}";
	}
	
	//get and set
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getIdade() {
		return idade;
	}
	public void setIdade(int idade) {
		this.idade = idade;
	}
	public char getSexo() {
		return sexo;
	}
	public void setSexo(char c) {
		this.sexo = c;
	}//get and set
	
	// internal method
	
	public void fazerAniversario() {
		this.setIdade(this.getIdade()+1);
	}
	
	// internal method
	
	
}

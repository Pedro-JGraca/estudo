package aula09.pacote;

public class Pessoa{
    private String nome;
    private int Idade;
    private Character sexo;

    // construtor
    public Pessoa(String nome, int idade, Character sexo) 
    {
        this.setNome(nome);
        this.setIdade(idade);
        this.setSexo(sexo);
    }// contrutor

    // get and sets
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return Idade;
    }

    public void setIdade(int idade) {
        Idade = idade;
    }

    public Character getSexo() {
        return sexo;
    }

    public void setSexo(Character sexo) {
        this.sexo = sexo;
    }
    // gets and sets

    //public methods   
    //public methods
   
    //private methods
    public void fazerAniversario() {
        this.setIdade(this.getIdade()+1);
    }//private methods

 
}

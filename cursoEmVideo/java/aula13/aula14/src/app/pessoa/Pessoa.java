package app.pessoa;

public abstract class Pessoa {
    protected String nome;
    protected int idade;
    protected char sexo;
    protected int exp;

    protected abstract void ganharExp();


    public Pessoa(String nome, int idade, char sexo) {
        this.setNome(nome);
        this.setIdade(idade);
        this.setSexo(sexo);
        this.setExp(0);
    }

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

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public int getExp() {
        return exp;
    }

    public void setExp(int exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        return "Pessoa [exp=" + exp + ", idade=" + idade + ", nome=" + nome + ", sexo=" + sexo + "]";
    }

    
    

    
}
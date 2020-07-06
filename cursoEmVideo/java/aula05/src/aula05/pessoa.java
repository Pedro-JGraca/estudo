package aula05;

public class pessoa {
    public String nome;
    private float dinheiro;
    private float salario;

    public pessoa(String nome,float dinheiro, float salario) {
        this.nome = nome;
        this.dinheiro = dinheiro;
        this.salario= salario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getDinheiro() {
        return dinheiro;
    }

    public void setDinheiro(float dinheiro) {
        this.dinheiro = dinheiro;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public void virouMes(){
        this.dinheiro= this.dinheiro+this.salario;
    }

    @Override
    public String toString() {
        return "pessoa{" +
                "nome='" + nome + '\'' +
                ", dinheiro=" + dinheiro +
                '}';
    }
}

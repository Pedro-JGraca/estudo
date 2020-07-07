package app.pacote;

public class Funcionario extends Pessoa{
    private String setor;
    private boolean trabalhando;

    //construtor
    public Funcionario(String nome, int idade, char sexo, String setor, boolean trabalhando) {
        super(nome, idade, sexo);
        this.setSetor(setor);
        this.setTrabalhando(trabalhando);
    }// construtor

    //get and set
    public String getSetor() {
        return setor;
    }

    public void setSetor(String setor) {
        this.setor = setor;
    }

    public boolean isTrabalhando() {
        return trabalhando;
    }

    public void setTrabalhando(boolean trabalhando) {
        this.trabalhando = trabalhando;
    }//get and set

    //method internal
    public void mudarTrabalho() {
        this.setTrabalhando(!this.isTrabalhando());
    }//method internal

    
    

}
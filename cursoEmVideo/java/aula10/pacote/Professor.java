package aula10.pacote;

public class Professor extends Pessoa {
    private String especialidade;
    private float salario;
    
    //contrutor
    public Professor(String nome, int idade, char sexo,String especialidade, float salario) {
        super(nome, idade, sexo);
        this.setEspecialidade(especialidade);
        this.setSalario(salario);
    }//contrutor

    //set and get
    public String getEspecialidade() {
        return especialidade;
    }

    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }//set and get

    //internal methods
    public void receberAumento (float m){
        this.setSalario(this.getSalario()+m);
    }    
}
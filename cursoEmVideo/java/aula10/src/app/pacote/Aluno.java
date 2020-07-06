package app.pacote;

public class Aluno extends Pessoa {
    private int mat;
    private String curso;

    //contrutor
    public Aluno(String nome, int idade, char sexo, int mat, String curso) {
        super(nome, idade, sexo);
        this.setMat(mat);
        this.setCurso(curso);
    }//contrutor

    //get and set
    public int getMat() {
        return mat;
    }

    public void setMat(int mat) {
        this.mat = mat;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }//get and set

    //internal methods
    public void cancelarMatr(){
        System.out.print("cancelar matricula");
    }//internal methods
}
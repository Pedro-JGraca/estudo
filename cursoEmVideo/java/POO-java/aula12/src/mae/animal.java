package mae;

public abstract class animal {
    protected float peso;
    protected int idade;
    protected int membros;

    public abstract void locomover();
    public abstract void alimentar();
    public abstract void emitirSom();

    /**
     * @return the peso
     */
    public float getPeso() {
        return peso;
    }

    /**
     * @param peso the peso to set
     */
    public void setPeso(float peso) {
        this.peso = peso;
    }

    /**
     * @return the idade
     */
    public int getIdade() {
        return idade;
    }

    /**
     * @param idade the idade to set
     */
    public void setIdade(int idade) {
        this.idade = idade;
    }

    /**
     * @return the membros
     */
    public int getMembros() {
        return membros;
    }

    /**
     * @param membros the membros to set
     */
    public void setMembros(int membros) {
        this.membros = membros;
    }
    
    
}
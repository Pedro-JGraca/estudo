package mae.filho;

import mae.animal;

public class peixe extends animal {
    private String corEscama;

    @Override
    public void locomover() {
        System.out.println("nadando");

    }

    @Override
    public void alimentar() {
        System.out.println("Comendo Substancias");

    }

    @Override
    public void emitirSom() {
        System.out.println("Peixe nao faz som");
    }

    public void soltarBolha() {
        System.out.println("Soltando Bolha");
    }
    

    /**
     * @return String return the corEscama
     */
    public String getCorEscama() {
        return corEscama;
    }

    /**
     * @param corEscama the corEscama to set
     */
    public void setCorEscama(String corEscama) {
        this.corEscama = corEscama;
    }

}
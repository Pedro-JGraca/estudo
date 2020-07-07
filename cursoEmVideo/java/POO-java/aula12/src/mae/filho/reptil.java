package mae.filho;

import mae.animal;

public class reptil extends animal {
    private String corEscana;

    @Override
    public void locomover() {
        System.out.println("Rastejando");

    }

    @Override
    public void alimentar() {
        System.out.println("Comendo Vegetais");

    }

    @Override
    public void emitirSom() {
        System.out.println("Som de Reptil");

    }

    /**
     * @return String return the corEscana
     */
    public String getCorEscana() {
        return corEscana;
    }

    /**
     * @param corEscana the corEscana to set
     */
    public void setCorEscana(String corEscana) {
        this.corEscana = corEscana;
    }

}
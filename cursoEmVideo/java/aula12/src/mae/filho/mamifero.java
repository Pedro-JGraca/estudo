package mae.filho;

import mae.animal;

public class mamifero extends animal {
    private String corPelo;
    
    @Override
    public void locomover() {
        System.out.println("Correndo");
    }

    @Override
    public void alimentar() {
        System.out.println("Mamando");
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de Mamifero");
    }

    /**
     * @return the corPelo
     */
    public String getCorPelo() {
        return corPelo;
    }

    /**
     * @param corPelo the corPelo to set
     */
    public void setCorPelo(String corPelo) {
        this.corPelo = corPelo;
    }

    
}
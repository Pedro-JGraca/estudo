package mae.filho;

import mae.animal;

public class ave extends animal{
    private String corPena;


    @Override
    public void locomover() {
        System.out.println("Voando");

    }

    @Override
    public void alimentar() {
        System.out.println("Comendo Frutas");

    }

    @Override
    public void emitirSom() {
        System.out.println("Som de ave");

    }

    public void fazerNinhi() {
        System.out.println("Construineo um ninho");        
    }


    /**
     * @return String return the corPena
     */
    public String getCorPena() {
        return corPena;
    }

    /**
     * @param corPena the corPena to set
     */
    public void setCorPena(String corPena) {
        this.corPena = corPena;
    }

}
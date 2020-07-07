package app;

import app.pessoa.Gafanhoto;
import app.video.Video;

public class visualizacao {

    private Gafanhoto espectador;
    private Video filme;

    public visualizacao(Gafanhoto espectador, Video filme) {
        this.espectador = espectador;
        this.filme = filme;
        this.espectador.ViuMaisUm();
        this.filme.setViews(this.filme.getViews()+1);
    }
    
    public void avaliar() {
        filme.setAvaliacao(5);
    }

    public void avaliar(int nota) {
        filme.setAvaliacao(filme.getAvaliacao()+nota);
    }

    public void avaliar(float porc) {
        int tot;
        if (porc <= 20f){
            tot=3;
        }
        else if (porc <= 50){
            tot=5;
        }
        else if (porc <= 90) {
            tot=8;
        }
        else {
            tot=10;
        }
        filme.setAvaliacao(tot);
    }

  
    
    /**
     * @return Gafanhoto return the espectador
     */
    public Gafanhoto getEspectador() {
        return espectador;
    }

    /**
     * @param espectador the espectador to set
     */
    public void setEspectador(Gafanhoto espectador) {
        this.espectador = espectador;
    }

    /**
     * @return Video return the filme
     */
    public Video getFilme() {
        return filme;
    }

    /**
     * @param filme the filme to set
     */
    public void setFilme(Video filme) {
        this.filme = filme;
    }

    @Override
    public String toString() {
        return "visualizacao [espectador=" + espectador + ", filme=" + filme + "]";
    }

}
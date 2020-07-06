package app.video;

public class Video implements AcoesVideo{
    private String titulo;
    private int avaliacao;
    private int views;
    private boolean reproduzindo;

    /**
     * @return String return the titulo
     */
    public String getTitulo() {
        return titulo;
    }

    /**
     * @param titulo the titulo to set
     */
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    /**
     * @return int return the avaliacao
     */
    public int getAvaliacao() {
        return avaliacao;
    }

    /**
     * @param avaliacao the avaliacao to set
     */
    public void setAvaliacao(int avaliacao) {
        this.avaliacao = avaliacao;
    }

    /**
     * @return int return the views
     */
    public int getViews() {
        return views;
    }

    /**
     * @param views the views to set
     */
    public void setViews(int views) {
        this.views = views;
    }

    /**
     * @return boolean return the reproduzindo
     */
    public boolean isReproduzindo() {
        return reproduzindo;
    }

    /**
     * @param reproduzindo the reproduzindo to set
     */
    public void setReproduzindo(boolean reproduzindo) {
        this.reproduzindo = reproduzindo;
    }

    public Video(String titulo) {
        this.titulo = titulo;
        this.avaliacao = 0;
        this.views = 0;
        this.reproduzindo = false;
    }

    @Override
    public void play() {
        if(isReproduzindo()){
            System.out.println("Precisa estar pausado para dar play");
        }
        else {
            System.out.println("Play!");
            this.setReproduzindo(true);
        }
    }

    @Override
    public void pause() {
        if(isReproduzindo()){
            this.setReproduzindo(false);
            System.out.println("Pause!");
        }
        else {
            System.out.println("Precisa estar rodando para dar pause");
        }

    }

    @Override
    public void like() {
        this.setAvaliacao(this.getAvaliacao()+1);

    }

}
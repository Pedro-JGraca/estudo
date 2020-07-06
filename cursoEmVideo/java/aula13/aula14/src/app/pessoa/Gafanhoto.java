package app.pessoa;

public class Gafanhoto extends Pessoa {

    private String login;
    private int totAssistido;

    

    @Override
    protected void ganharExp() {

    }

    

    /**
     * @return String return the login
     */
    public String getLogin() {
        return login;
    }

    /**
     * @param login the login to set
     */
    public void setLogin(String login) {
        this.login = login;
    }

    /**
     * @return int return the totAssistido
     */
    public int getTotAssistido() {
        return totAssistido;
    }

    /**
     * @param totAssistido the totAssistido to set
     */
    public void setTotAssistido(int totAssistido) {
        this.totAssistido = totAssistido;
    }

    public Gafanhoto(String nome, int idade, char sexo, String login) {
        super(nome, idade, sexo);
        this.setLogin(login);
        this.setTotAssistido(0);
    }

    

}
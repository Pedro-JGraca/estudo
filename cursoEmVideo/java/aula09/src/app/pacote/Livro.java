package app.pacote;

public class Livro implements Publicacao {
    private String titulo, autor;
    private int totPaginas, pagAtual;
    private boolean aberto;
    private Pessoa leitor;

    // construtor
    public Livro(String titulo,String autor,int totPaginas,Pessoa leitor)
    {
		this.setTitulo(titulo);
        this.setAutor(autor);
        this.setTotPaginas(totPaginas);
        this.setPagAtual(0);
        this.setAberto(false);
        this.setLeitor(leitor);
    }// contrutor

    // get and sets
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getTotPaginas() {
        return totPaginas;
    }

    public void setTotPaginas(int totPaginas) {
        this.totPaginas = totPaginas;
    }

    public int getPagAtual() {
        return pagAtual;
    }

    public void setPagAtual(int pagAtual) {
        this.pagAtual = pagAtual;
    }

    public boolean isAberto() {
        return aberto;
    }

    public void setAberto(boolean aberto) {
        this.aberto = aberto;
    }

    public Pessoa getLeitor() {
        return leitor;
    }

    public void setLeitor(Pessoa leitor) {
        this.leitor = leitor;
    }// gets and sets 
    
    //public methods
    @Override
    public void abrir() {
        setAberto(true);
    }

    @Override
    public void avancarPagina() {
        this.setPagAtual(this.getPagAtual()+1);

    }

    @Override
    public void fechar() {
        this.setAberto(false);
    }

    @Override
    public void folhear(int p) {
        if (p<=this.getTotPaginas()){
            this.setPagAtual(p);
        }
    }

    @Override
	public void voltarPagina() {
		this.setPagAtual(this.getPagAtual()-1);
	}// public methods


    // private methods
    public String detalhes() {
        return "Livro\n{ \n\taberto=" + aberto + ",\n\tautor=" + autor + ",\n\tleitor=" + leitor.getNome() + ",\n\tpagAtual=" + pagAtual
        + ",\n\ttitulo=" + titulo + ",\n\ttotPaginas=" + totPaginas+ ",\n}";

    }// private methods
    
}
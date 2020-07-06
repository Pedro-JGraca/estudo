package aula07.luta;

public class Lutador implements AcessoLutador{
    private String nome, nacionalidade,categoria ;
    private float altura, peso;
    private int vitorias,idade,derrotas,empates;

    public Lutador(String nome,
                   String nacionalidade,
                   int idade,
                   float altura,
                   float peso,
                   int vitorias,
                   int derrotas,
                   int empates) {
        this.setNome(nome);
        this.setNacionalidade(nacionalidade);
        this.setIdade(idade);
        this.setAltura(altura);
        this.setPeso(peso);
        this.setVitorias(vitorias);
        this.setDerrotas(derrotas);
        this.setEmpates(empates);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
        this.setCategoria();
    }

    public String getCategoria() {
        return categoria;
    }

    private void setCategoria()
    {
        if (this.peso<52.2f)
        {
            this.categoria = "invalido";
        }

        else if (this.peso<=70.3)
        {
            this.categoria = "leve";
        }

        else if (this.peso<=83.9)
        {
            this.categoria = "medio";
        }
        else if (this.peso<=120.2)
        {
            this.categoria = "pesado";
        }
        else {
            this.categoria = "invalido";
        }



    }

    public int getVitorias() {
        return vitorias;
    }

    public void setVitorias(int vitorias) {
        this.vitorias = vitorias;
    }

    public int getDerrotas() {
        return derrotas;
    }

    public void setDerrotas(int derrotas) {
        this.derrotas = derrotas;
    }

    public int getEmpates() {
        return empates;
    }

    public void setEmpates(int empates) {
        this.empates = empates;
    }

    @Override
    public void apresentar() {
        System.out.println(
                "nome=" + nome + "\n" +
                "nacionalidade=" + nacionalidade + '\n' +
                "idade=" + idade + "\n" +
                "altura=" + altura + "\n" +
                "peso=" + peso + "\n" +
                "categoria=" + categoria + '\n' +
                "vitorias=" + vitorias + "\n" +
                "derrotas=" + derrotas + "\n" +
                "empates=" + empates + "\n"
        );
    }

    @Override
    public void status() {
        System.out.println(
                "O " + getNome() + " é um peso " + getCategoria()+ " com:\n" +
                        getVitorias() + " vitorias;\n" +
                        getDerrotas() + " derrotas;\n" +
                        getEmpates()  + " empates.\n"
        );
    }

    @Override
    public void ganharLuta() {
        this.setVitorias(this.getVitorias()+1);
    }

    @Override
    public void perderLuta() {
        this.setDerrotas(this.getDerrotas()+1);
    }

    @Override
    public void empatarLuta() {
        this.setEmpates(this.getEmpates()+1);
    }


}

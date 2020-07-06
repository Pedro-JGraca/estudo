package aula03;

public class Caneta {
    public String modelo;
    public String cor;
    private float ponta;
    protected int carga;
    private boolean tampada;
    public void status () {
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Cor: " + this.cor);
        System.out.println("Ponta: " + this.ponta);
        System.out.println("Carga: " + this.carga);
        System.out.println("Tampada: " + this.tampada);
    }
    public void rabiscar () {
        if (this.tampada){
            System.out.println("Erro! Com tampa nao se pode rabiscar");
        } else {
            System.out.println("RABISCANDO");
        }
    }

    public void tampar () {
        tampada = true;
    }

    public void destampar () {
        tampada = false;
    }
}

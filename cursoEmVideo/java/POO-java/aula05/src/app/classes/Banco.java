package app.classes;

public class Banco {
    public int numConta;
    protected String tipo;
    private Pessoa dono;
    private float saldo;
    private boolean status;

    public Banco(Pessoa dono) {
        this.setStatus(false);
        this.setNumConta(1);
        this.setSaldo(0f);
        this.setDono(dono);
    }

    public int getNumConta() {
        return numConta;
    }

    public String getTipo() {
        return tipo;
    }

    public Pessoa getDono() {
        return dono;
    }

    public float getSaldo() {
        return saldo;
    }

    public boolean getStatus() {
        return status;
    }

    public void setNumConta(int numConta) {
        this.numConta = numConta;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setDono(Pessoa dono) {
        this.dono = dono;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public void abrirConta(String tipo){
        if (dono.getSalario()>20f) {
            this.setTipo(tipo);
            this.setStatus(true);
            if (this.tipo.equals("cc")) {
                this.setSaldo(50f);
            }
            if (this.tipo.equals("cp")) {
                this.setSaldo(150f);
            }
        } else {
            System.out.println("Seu Salario eh muito baixo para nosso banco");
        }

    }

    public void fecharConta(){
        if (saldo==0f){
            if (getStatus()){
                this.setStatus(false);
                System.out.println("Sua conta fechou");
            } else {
                System.out.println("Sua conta não fechou, pois já estava fechada");
            }
        } else {
            System.out.println("Para fechar sua conta, zere seu saldo");
        }
    }
    public void depositar (float v){
        if (this.status){
            this.setSaldo(this.getSaldo() + v);
            dono.setDinheiro(dono.getDinheiro()-v);
            System.out.println(dono.getNome() + " depositou R$" + v);
        }else {
            System.out.println("Não é possivel depositar com a conta fechada");
        }
    }
    public void sacar (float t) {
        if(status){
            if (t<=this.saldo) {
                this.setSaldo(this.getSaldo()-t);
                dono.setDinheiro(dono.getDinheiro() + t);
                System.out.println("Vc savou R$" + t);
            }else {
                System.out.println("Vc não tem R$" +t + "no banco");
            }
        } else {
            System.out.println("não é possivel sacar com a conta fechada");
        }
    }
    public void pagarMensal ()
    {
        float M=0f;
        if (this.tipo.equals("cc")){
            M=12f;
        }
        if (this.tipo.equals("cp")){
            M=20f;
        }

        if(status){
            dono.virouMes();
            this.depositar(dono.getSalario());
            this.setSaldo(this.getSaldo()-M);
        }else {
            System.out.println("Não é possivel pagar mensalidade com a conta fechada");
        }
    }

    @Override
    public String toString() {
        return "banco{" +
                "numConta=" + numConta +
                ", tipo='" + tipo + '\'' +
                ", dono=" + dono +
                ", saldo=" + saldo +
                ", status=" + status +
                '}';
    }
}


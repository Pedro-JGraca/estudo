package aula07.luta;

import java.util.Random;


public class Luta implements AcessoLuta {
    private Lutador desafiado;
    private Lutador desafiante;
    private int rounds;
    private boolean aprovada;

    public Luta(int rounds)
    {
        this.setAprovada(false); 
        this.setRounds(rounds);
    }

    
    @Override
    public void marcarLuta(Lutador atacador,Lutador defensor) 
    {
        if(
            atacador.getCategoria().equals(defensor.getCategoria()) 
            && 
            !atacador.equals(defensor)
        )
        {
            this.setAprovada(true);
            this.setDesafiado(atacador);
            this.setdesafiante(defensor);
        }
        else 
        {
            this.setAprovada(false);
            this.setDesafiado(null);
            this.setdesafiante(null);
        }
    }

    @Override
    public void lutar() {
        if(this.getAprovada())
        {
            this.desafiado.apresentar();
            this.desafiante.apresentar();
            Random aleatorio = new Random();
            switch(aleatorio.nextInt(3))
            {
                case (0):
                { //Empate
                    System.out.print("EMPATE\n");
                    desafiante.empatarLuta();
                    desafiado.empatarLuta();
                    break;
                }
                case (1):
                { //Ganhou Defensor
                    System.out.println("Ganhou "+ this.desafiado.getNome()+ "\n");
                    desafiante.perderLuta();
                    desafiado.ganharLuta();
                    break;
                }
                case (2): 
                {//Ganhou Atacante
                    System.out.println("Ganhou "+ this.desafiante.getNome()+ "\n");
                    desafiante.ganharLuta();
                    desafiado.perderLuta();
                    break;
                }
                default:
                {
                    break;
                }

            }
        }
        else
        {
            System.out.println("Luta não aprovada");
        }
    }
    public Lutador getDesafiado() {
        return desafiado;
    }

    public void setDesafiado(Lutador desafiado) {
        this.desafiado = desafiado;
    }

    public int getRounds() {
       return rounds; 
    }

    public void setRounds(int rounds) {
        this.rounds = rounds;
    }

    public Lutador getdesafiante() {
        return desafiante;
    }

    public void setdesafiante(Lutador desafiante) {
        this.desafiante = desafiante;
    }

    public boolean getAprovada() {
        return aprovada;
    }

    public void setAprovada(boolean aprovada) {
        this.aprovada = aprovada;
    }
}

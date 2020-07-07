package app.canino;

public abstract class Mamifero extends Animal {
    protected String corPelo;

    @Override
    public void emitirSom() {
        System.out.println("som de mamifero");
    }

    
}
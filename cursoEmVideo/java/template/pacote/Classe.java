package template.pacote;


public class Classe implements AcessoClasse {
    private int atributo;

    public Classe(int a)
    {
        this.setAtributo(a);
    }//contrutor

    public int getAtributo() {
        return this.atributo;
    }//get

    public void setAtributo(int a) {
        this.atributo = a;
    }//set
    
    @Override
    public void metodo() 
    {
			System.out.println("oi");
			//implemetar metodo
		}

}

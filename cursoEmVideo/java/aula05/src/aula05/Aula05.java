package aula05;

public class Aula05 {
    public static void main( String[] args){
        pessoa joao = new pessoa("joao",400f,200f);
        pessoa maria = new pessoa("maria",500f,150f);


        System.out.println(maria.toString());
        System.out.println(joao.toString());

        banco bjoao = new banco (joao);
        banco bmaria = new banco (maria);

        System.out.println(bjoao.toString());
        System.out.println(bmaria.toString());

        bjoao.abrirConta("cc");
        bmaria.abrirConta("cp");

        System.out.println(bjoao.toString());
        System.out.println(bmaria.toString());

        bjoao.pagarMensal();
        bmaria.pagarMensal();

        System.out.println(bjoao.toString());
        System.out.println(bmaria.toString());
    }
}



package aula04;
public class Aula04 {
    public static void main(String[] args){
        Caneta c1 = new Caneta("NIC",0.4f);
        System.out.println(c1.toString());
        c1.setModelo("BIC");
        c1.setPonta(0.5f);
        System.out.println(c1.toString());

    }
}

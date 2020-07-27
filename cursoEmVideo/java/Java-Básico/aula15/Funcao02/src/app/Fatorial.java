package app;

public class Fatorial {
	
	private int num = 0;
	private int fat = 1;
	
	private String formula = "";

	public void setValor(int n) {
		this.setNum(n);
		int f = 1;
		String S = "";
		for (int c = this.getNum();c>1;c--) {
			f *=c;
			S+= c + " x ";
		}
		S += "1 = ";
		this.setFat(f);
		this.setFormula(S);
	}
	
	public int getFatorial() {
		return getFat();
	}
	
	public int getNum() {
		return num;
	}

	private void setNum(int num) {
		this.num = num;
	}

	public int getFat() {
		return fat;
	}

	private void setFat(int fat) {
		this.fat = fat;
	}

	public String getFormula() {
		return formula;
	}

	private void setFormula(String formula) {
		this.formula = formula;
	}
	
	
	

}

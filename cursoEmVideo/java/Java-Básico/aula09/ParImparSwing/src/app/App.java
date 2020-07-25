package app;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JFormattedTextField;
import javax.swing.JButton;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class App extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					App frame = new App();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	  private static boolean isNumberZ(String str) {
	      boolean integer = str.matches("[0-9]*");
	      boolean empyt = str.isEmpty();
	      if (integer && (!(empyt))) {
	        return true;
	      }
	      else {
	        return false;
	      }
	  }
	  private static String removeZeros(String str) {

	    if (str.isEmpty()) {
	      return str;
	    }
	    else {
	      String saida=str;
	      for (int i=0;i<str.length();i++) {
	        if (str.charAt(i) == '0') {
	          saida =  (String) str.subSequence(i+1,str.length());
	        }
	        else {
	          i=str.length();
	        }
	      }
	      if (saida.isEmpty()) {
	        saida="0";
	      }
	      return saida;
	    }
	  }

	public App() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 215, 300);
		getContentPane().setLayout(null);
		
		JLabel lblValor = new JLabel("Valor");
		lblValor.setBounds(26, 41, 70, 15);
		getContentPane().add(lblValor);
		
		JFormattedTextField txtValor = new JFormattedTextField();
		txtValor.setHorizontalAlignment(SwingConstants.TRAILING);
		txtValor.setBounds(98, 39, 85, 19);
		getContentPane().add(txtValor);
		
		JButton btnVerificar = new JButton("Verificar");
	
		btnVerificar.setBounds(43, 89, 117, 25);
		getContentPane().add(btnVerificar);
		
		JLabel lblResultado = new JLabel("Indefinido");
		lblResultado.setBounds(70, 154, 90, 15);
		getContentPane().add(lblResultado);
		
		btnVerificar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				String str = removeZeros(txtValor.getText());
				txtValor.setText(str);
				if (!isNumberZ(str)) {
					lblResultado.setText("Nao Numero");
				}
				else {

					if (Integer.parseInt(str)%2==0) {
						lblResultado.setText("Par");
					}
					else {
						lblResultado.setText("Impar");
					}
				}

			}
		});
		
	}
}

package app;

import java.awt.BorderLayout;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.Calendar;
import java.awt.event.ActionEvent;

public class App extends JFrame {

	private JPanel contentPane;
	private JTextField txtNascimentp;

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
	
	private static boolean isNumber(String str) {
		if (str.matches("[0-9]*") && (!(str.isEmpty()))) {
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
	
	private static boolean isStrLimite(String str, int limite) {
		
		if (str.length()>limite) {
			return false;
		}
		else {
			return true;
		}
	}

	public App() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 254, 160);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNascimento = new JLabel("Nascimento");
		lblNascimento.setBounds(12, 12, 98, 15);
		contentPane.add(lblNascimento);
		
		txtNascimentp = new JTextField();
		txtNascimentp.setBounds(126, 12, 114, 19);
		contentPane.add(txtNascimentp);
		txtNascimentp.setColumns(10);
		
		JButton btnCalcular = new JButton("Calcular");

		btnCalcular.setBounds(68, 57, 117, 25);
		contentPane.add(btnCalcular);
		
		JLabel lblResultado = new JLabel("");
		lblResultado.setBounds(12, 108, 117, 15);
		
		Calendar cal = Calendar.getInstance();
		
		contentPane.add(lblResultado);
		
		JLabel lblIdade = new JLabel("");
		lblIdade.setBounds(172, 108, 70, 15);
		contentPane.add(lblIdade);
		btnCalcular.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!isStrLimite(txtNascimentp.getText(),4)) {
					lblResultado.setText("limite de "+ 4 +" elementos");
					txtNascimentp.setText("");
					lblIdade.setText("");
				}
				else if (!isNumber(txtNascimentp.getText())) {
					lblResultado.setText("Nao e numero");
					txtNascimentp.setText("");
					lblIdade.setText("");
				}
				
				else {
					txtNascimentp.setText(removeZeros(txtNascimentp.getText()));
					int id = cal.get(Calendar.YEAR) - Integer.parseInt(txtNascimentp.getText());

					if (id < 16) {
						lblResultado.setText("Nao pode votar");
						lblIdade.setText(Integer.toString(id));
					} else if (( id <18) || (id > 70)) {
						lblResultado.setText("Pode votar");
						lblIdade.setText(Integer.toString(id));
					}
					else {
						lblResultado.setText("Tem que votar");
						lblIdade.setText(Integer.toString(id));
					}
				}
			}
		});
	}
}

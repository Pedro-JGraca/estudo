package TelaIdade;

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
import javax.swing.SwingConstants;
import javax.swing.JCheckBox;

public class TelaIdade extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtAno;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaIdade frame = new TelaIdade();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	private static boolean isNumberZ(String str) {
	    boolean integer = str.matches("[0-9]*");
	    boolean empyt = str.isEmpty();
	    if (integer && (!(empyt))) {
	    	return false;
	    }
	    else {
		    return true;
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
	
	
	

	/**
	 * Create the frame.
	 */
	public TelaIdade() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 280, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Ano de Nascimento");
		lblNewLabel.setBounds(22, 12, 156, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblIdadeFixo = new JLabel("Idade");
		lblIdadeFixo.setBounds(22, 162, 57, 15);
		contentPane.add(lblIdadeFixo);
		
		JLabel lblSituacaoFixo = new JLabel("Situação:");
		lblSituacaoFixo.setBounds(22, 219, 88, 15);
		contentPane.add(lblSituacaoFixo);
		
		txtAno = new JTextField();
		txtAno.setBounds(172, 10, 66, 19);
		contentPane.add(txtAno);
		txtAno.setColumns(10);
		
		JButton btnCalc = new JButton("Calcular Idade");

		btnCalc.setBounds(69, 111, 135, 25);
		contentPane.add(btnCalc);
		
		JLabel lblIdade = new JLabel("0");
		lblIdade.setHorizontalAlignment(SwingConstants.TRAILING);
		lblIdade.setBounds(91, 162, 177, 15);
		contentPane.add(lblIdade);
		
		JLabel lblSituacao = new JLabel("");
		lblSituacao.setHorizontalAlignment(SwingConstants.TRAILING);
		lblSituacao.setBounds(122, 219, 146, 15);
		contentPane.add(lblSituacao);
		
		JCheckBox chckbxAniversario = new JCheckBox("Fez aniversário?");
		chckbxAniversario.setBounds(32, 62, 146, 23);
		contentPane.add(chckbxAniversario);
		Calendar cal = Calendar.getInstance();
		
		btnCalc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				txtAno.setText(removeZeros(txtAno.getText()));

				if (txtAno.getText().length()> 4 ) {
					lblIdade.setText("Limite de " + 4 + " caracteres"); //verifica se numero e grande
			        txtAno.setText("");
			        lblSituacao.setText("");
				}
				else if (isNumberZ(txtAno.getText())) {
					lblIdade.setText("Precisa ser Numero"); //verifica se está vazio ou se e palavra
			        txtAno.setText("");
			        lblSituacao.setText("");
			    }
			    else {
					int idade = cal.get(Calendar.YEAR) - Integer.parseInt(txtAno.getText());

					if (!chckbxAniversario.isSelected()) {
						idade -=1;
					}

					if (idade<0) {
						lblIdade.setText("Ainda nao aconteceu"); //verifica se esta falando de uma data futura
						txtAno.setText("");
						lblSituacao.setText("");    
					}
					else if (idade>150) {
						lblIdade.setText("Passou de " + 150 + " anos!"); //verifica se esta falando de uma data futura
						txtAno.setText("");
						lblSituacao.setText("");   
					}
					else {
						lblIdade.setText(Integer.toString(idade));
						String sit = ((idade>=16 && idade <18)|| (idade>70))?"Votar é opcional":((idade<16)?"Votar é proibido":"votar é obrigatório");
						lblSituacao.setText(sit);
					}		
			    }
			}
		});
	}
}

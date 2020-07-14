package soma;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;

public class TelaSoma extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtN1;
	private JTextField txtN2;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaSoma frame = new TelaSoma();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	private static boolean isInteger(String str) {
		return str != null && str.matches("[0-9]*");
	}

	/**
	 * Create the frame.
	 */
	public TelaSoma() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 123);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		txtN1 = new JTextField();
		txtN1.setBounds(122, 36, 56, 19);
		contentPane.add(txtN1);
		txtN1.setColumns(10);
		
		txtN2 = new JTextField();
		txtN2.setBounds(36, 36, 56, 19);
		contentPane.add(txtN2);
		txtN2.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("+");
		lblNewLabel.setBounds(104, 38, 18, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblSoma = new JLabel("0");
		lblSoma.setVerticalAlignment(SwingConstants.TOP);
		lblSoma.setBounds(252, 38, 186, 68);
		contentPane.add(lblSoma);
		
		JButton btnSoma = new JButton("=");
		btnSoma.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.print("É palavra? "+!(isInteger(txtN1.getText()) && isInteger(txtN2.getText()))+" ");
				System.out.println("\tEstá vazia? "+((txtN1.getText().isEmpty()) || (txtN2.getText().isEmpty())));
				if ( (!(isInteger(txtN1.getText()) && isInteger(txtN2.getText()))) || ((txtN1.getText().isEmpty()) || (txtN2.getText().isEmpty()))){
					lblSoma.setText("Precisam ser Numeros"); //verifica se está fazia ou se sao nulos
					txtN1.setText("");
					txtN2.setText("");
				}
				else {
					int n1 = Integer.parseInt(txtN1.getText());
					int n2 = Integer.parseInt(txtN2.getText());
					lblSoma.setText(Integer.toString(n1+n2));
					txtN1.setText("");
					txtN2.setText("");
				}
			}
		});
		btnSoma.setBounds(190, 33, 44, 25);
		contentPane.add(btnSoma);
	}
}

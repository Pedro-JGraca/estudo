package genio;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Color;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.Random;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;
import java.awt.Font;

public class App extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

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
	public App() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 320, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblEscolhaUmNumero = new JLabel("Escolha Um Numero");
		lblEscolhaUmNumero.setFont(new Font("Dialog", Font.PLAIN, 12));
		lblEscolhaUmNumero.setVerticalAlignment(SwingConstants.TOP);
		lblEscolhaUmNumero.setHorizontalAlignment(SwingConstants.CENTER);
		lblEscolhaUmNumero.setForeground(Color.RED);
		lblEscolhaUmNumero.setBounds(83, 61, 149, 79);
		contentPane.add(lblEscolhaUmNumero);
		
		JLabel lblAdivinhaNumeroEntr = new JLabel("Adivinha! Numero entre 1 e 5");
		lblAdivinhaNumeroEntr.setBounds(58, 12, 211, 15);
		contentPane.add(lblAdivinhaNumeroEntr);
		
		JSpinner spinner = new JSpinner();
		spinner.setModel(new SpinnerNumberModel(1, 1, 5, 1));
		spinner.setBounds(145, 120, 29, 20);
		contentPane.add(spinner);
		
		
		

		
		JButton btnChute = new JButton("Chute!");
		btnChute.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				Random gerador = new Random();
				
				int random=gerador.nextInt(5)+1;
				
				int chute= (int) spinner.getValue();
				
				if (random == chute){
					lblEscolhaUmNumero.setText("Acertou!");
				}
				else {
					lblEscolhaUmNumero.setText("<html>Errou!<br>" + " Pensei no <strong>" + Integer.toString(random) + "</strong> </html>");
				}
			}
		});
		btnChute.setBounds(95, 175, 117, 25);
		contentPane.add(btnChute);
	}
}

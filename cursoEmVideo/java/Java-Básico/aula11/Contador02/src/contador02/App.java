package contador02;


import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

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
		setBounds(100, 100, 450, 160);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Contagem");
		lblNewLabel.setBounds(12, 41, 97, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblContar = new JLabel("");
		lblContar.setFont(new Font("Dialog", Font.BOLD, 18));
		lblContar.setBounds(107, 29, 331, 37);
		contentPane.add(lblContar);
		
		JButton btnContar = new JButton("Contar");

		btnContar.setBounds(43, 90, 117, 25);
		contentPane.add(btnContar);
		
		btnContar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int cc = 1;
				String contagem = "";
				while (cc < 11) {
					contagem += cc + " ";
					cc++;
					lblContar.setText(contagem);
				}

			}
		});
	}
}

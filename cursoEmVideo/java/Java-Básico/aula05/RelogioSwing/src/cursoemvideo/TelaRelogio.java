package cursoemvideo;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.io.IOException;
import java.util.Date;

import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TelaRelogio extends JFrame {

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
					TelaRelogio frame = new TelaRelogio();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public TelaRelogio() throws IOException {
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 638, 413);
		System.out.println();
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
	
		contentPane.setLayout(null);
		
		JLabel lblNewLabel_1 = new JLabel("Data e Hora Atuais");
		lblNewLabel_1.setBounds(305, 42, 166, 30);
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(lblNewLabel_1);
		
		JLabel label = new JLabel("");
		label.setIcon(new ImageIcon(TelaRelogio.class.getResource("/imagens/cronometro.png")));
		label.setBounds(12, 42, 330, 260);
		contentPane.add(label);
		
		JButton btnAtualizar = new JButton("Atualizar");
		
		btnAtualizar.setBounds(339, 231, 117, 25);
		contentPane.add(btnAtualizar);
		
		JLabel lblMostra = new JLabel("Clique em Atualizar");
		lblMostra.setFont(new Font("FreeSans", Font.BOLD | Font.ITALIC, 22));
		lblMostra.setHorizontalAlignment(SwingConstants.LEFT);
		lblMostra.setBounds(305, 114, 321, 62);
		contentPane.add(lblMostra);
		btnAtualizar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Date data = new Date();
				lblMostra.setText(data.toString());;
				
			}
		});
	}
}

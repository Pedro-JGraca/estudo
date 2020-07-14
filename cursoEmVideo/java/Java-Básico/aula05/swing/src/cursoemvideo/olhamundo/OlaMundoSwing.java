package cursoemvideo.olhamundo;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.awt.event.ActionEvent;

public class OlaMundoSwing extends JFrame {

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
					OlaMundoSwing frame = new OlaMundoSwing();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 * @throws IOException 
	 */
	public OlaMundoSwing() throws IOException {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 612, 410);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		new File("*").getCanonicalPath();
		
		
		System.out.println(new File("").getCanonicalPath());
		
		JLabel lbMensagem = new JLabel("Aqui vai a mensagem");
		lbMensagem.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(lbMensagem, BorderLayout.CENTER);
		
		JButton btnClick = new JButton("Clica aqui");
		
		btnClick.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				if (lbMensagem.getText().equals("Aqui vai a mensagem")) {
					lbMensagem.setText("Olá, Mundo!");
				}
				else if (lbMensagem.getText().equals("Olá, Mundo!")) {
					lbMensagem.setText("Aqui vai a mensagem");
				}
			}
		});
		contentPane.add(btnClick, BorderLayout.SOUTH);
	}

}

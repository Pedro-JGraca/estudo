package app;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import java.awt.Font;
import java.awt.Color;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.Locale;
import java.awt.event.ActionEvent;

public class Idioma extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Idioma frame = new Idioma();
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
	public Idioma() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 573, 433);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel label = new JLabel("");
		label.setIcon(new ImageIcon(Idioma.class.getResource("/images/pandemic.png")));
		label.setBounds(12, 80, 301, 280);
		contentPane.add(label);
		
		JLabel lblALinguaDo = new JLabel("The language of this system is:");
		lblALinguaDo.setHorizontalAlignment(SwingConstants.CENTER);
		lblALinguaDo.setFont(new Font("Khmer OS", Font.BOLD, 18));
		lblALinguaDo.setBounds(290, 95, 257, 37);
		contentPane.add(lblALinguaDo);
		
		JLabel lblAtualize = new JLabel("Update");
		lblAtualize.setHorizontalAlignment(SwingConstants.CENTER);
		lblAtualize.setForeground(Color.GRAY);
		lblAtualize.setFont(new Font("Waree", Font.BOLD | Font.ITALIC, 24));
		lblAtualize.setBounds(291, 156, 246, 52);
		contentPane.add(lblAtualize);
		Locale idioma = Locale.getDefault();
		
		JButton btnAtualize = new JButton("update");
		btnAtualize.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				lblAtualize.setText(idioma.getDisplayLanguage());
			}
		});
		btnAtualize.setBounds(358, 304, 117, 25);
		contentPane.add(btnAtualize);
	}
}

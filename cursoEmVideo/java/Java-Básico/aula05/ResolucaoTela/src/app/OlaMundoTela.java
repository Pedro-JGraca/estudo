package app;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.Color;

import java.awt.Dimension;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import java.awt.*;
import java.util.*;


public class OlaMundoTela extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					OlaMundoTela frame = new OlaMundoTela();
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
	public OlaMundoTela() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 881, 430);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setIcon(new ImageIcon(OlaMundoTela.class.getResource("/images/computador.png")));
		lblNewLabel.setBounds(12, 12, 565, 393);
		contentPane.add(lblNewLabel);
		
		JButton btnAtualizar = new JButton("Atualizar");
	
		btnAtualizar.setBounds(645, 281, 117, 25);
		contentPane.add(btnAtualizar);
		
		JLabel lblSuaResoluo = new JLabel("Sua Resolução");
		lblSuaResoluo.setForeground(Color.GRAY);
		lblSuaResoluo.setHorizontalAlignment(SwingConstants.CENTER);
		lblSuaResoluo.setFont(new Font("DialogInput", Font.BOLD | Font.ITALIC, 22));
		lblSuaResoluo.setBounds(572, 95, 252, 82);
		contentPane.add(lblSuaResoluo);
		
		Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
		
		btnAtualizar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				lblSuaResoluo.setText(d.width + "x" + d.height);
			}
		});
	}
}

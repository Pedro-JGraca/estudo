package classes;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JSpinner;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.Color;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.util.*;
import java.awt.event.ActionEvent;
import javax.swing.SpinnerNumberModel;


public class TelaIdadade extends JFrame {

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
					TelaIdadade frame = new TelaIdadade();
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
	public TelaIdadade() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 407, 205);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Ano de Nascimento");
		lblNewLabel.setBounds(12, 32, 136, 18);
		contentPane.add(lblNewLabel);
		Date data = new Date();
		int year = data.getYear() + 1900;
		
		JSpinner txtAN = new JSpinner();
		txtAN.setModel(new SpinnerNumberModel(1500, 1500, year, 1));
		txtAN.setBounds(167, 32, 78, 20);
		contentPane.add(txtAN);
		
		JButton btnCalc = new JButton("Calcular");
		
		btnCalc.setBounds(78, 94, 127, 42);
		btnCalc.setHorizontalAlignment(SwingConstants.LEADING);
		btnCalc.setIcon(new ImageIcon("/home/pedro-graca/Downloads/calculadora.png"));
		contentPane.add(btnCalc);
		
		JLabel lblNewLabel_1 = new JLabel("Idade");
		lblNewLabel_1.setBounds(25, 153, 70, 15);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblIdade = new JLabel("0");
		lblIdade.setBounds(107, 148, 70, 25);
		lblIdade.setForeground(Color.RED);
		lblIdade.setFont(new Font("Dialog", Font.BOLD, 18));
		contentPane.add(lblIdade);
		
		JLabel label = new JLabel("");
		label.setBounds(295, 32, 85, 87);
		label.setIcon(new ImageIcon(TelaIdadade.class.getResource("/imagens/do-utilizador.png")));
		label.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(label);
		
		JLabel lblAnoAtual = new JLabel("Ano Atual:");
		lblAnoAtual.setBounds(12, 5, 95, 15);
		contentPane.add(lblAnoAtual);
		
		
		JLabel lblAA = new JLabel(Integer.toString(year));
		lblAA.setBounds(107, 5, 70, 15);
		contentPane.add(lblAA);
		btnCalc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int ano = (int) txtAN.getValue();
				int id = 2020 - ano;
				lblIdade.setText(Integer.toString(id));
				
			}
		});
	}
}

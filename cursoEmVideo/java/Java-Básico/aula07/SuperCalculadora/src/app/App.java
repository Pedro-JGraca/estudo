package app;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JSpinner;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;
import javax.swing.border.BevelBorder;

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
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 369);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JSpinner spinner = new JSpinner();
		spinner.setBounds(200, 62, 61, 20);
		contentPane.add(spinner);
		
		JLabel lblNewLabel = new JLabel("Super Calculadora");
		lblNewLabel.setFont(new Font("Dialog", Font.BOLD, 18));
		lblNewLabel.setBounds(123, 0, 207, 15);
		contentPane.add(lblNewLabel);
		
		JButton btnNewButton = new JButton("Calcular");

		btnNewButton.setHorizontalAlignment(SwingConstants.LEFT);
		btnNewButton.setIcon(new ImageIcon(App.class.getResource("/images/calculadora.png")));
		btnNewButton.setBounds(273, 27, 165, 74);
		contentPane.add(btnNewButton);
		
		JLabel lblNewLabel_1 = new JLabel("Informe um valor:");
		lblNewLabel_1.setBounds(51, 64, 131, 15);
		contentPane.add(lblNewLabel_1);
		
		JPanel pan = new JPanel();
		pan.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		pan.setBounds(28, 113, 346, 214);
		contentPane.add(pan);
		pan.setLayout(null);
		pan.setVisible(false);
		
		JLabel lblTextoElC = new JLabel("Elevado ao cubo");
		lblTextoElC.setBounds(15, 67, 115, 15);
		pan.add(lblTextoElC);
		
		JLabel lblTextoRD2 = new JLabel("Resto da divisao por 2");
		lblTextoRD2.setBounds(15, 29, 157, 15);
		pan.add(lblTextoRD2);
		
		JLabel lblTextoRC = new JLabel("Raiz Cubica");
		lblTextoRC.setBounds(15, 148, 81, 15);
		pan.add(lblTextoRC);
		
		JLabel lblTextoVA = new JLabel("Valor Absoluto");
		lblTextoVA.setBounds(15, 186, 104, 15);
		pan.add(lblTextoVA);
		
		JLabel lblValRD2 = new JLabel("0");
		lblValRD2.setBounds(183, 28, 151, 17);
		pan.add(lblValRD2);
		lblValRD2.setFont(new Font("Dialog", Font.BOLD, 14));
		lblValRD2.setForeground(new Color(0, 0, 255));
		lblValRD2.setHorizontalAlignment(SwingConstants.TRAILING);
		
		JLabel lblValElC = new JLabel("0");
		lblValElC.setBounds(183, 66, 151, 17);
		pan.add(lblValElC);
		lblValElC.setHorizontalAlignment(SwingConstants.TRAILING);
		lblValElC.setForeground(Color.BLUE);
		lblValElC.setFont(new Font("Dialog", Font.BOLD, 14));
		
		JLabel lblTextoRQ = new JLabel("Raiz Quadrada");
		lblTextoRQ.setBounds(15, 106, 104, 15);
		pan.add(lblTextoRQ);
		
		JLabel lblValRQ = new JLabel("0");
		lblValRQ.setBounds(193, 105, 141, 17);
		pan.add(lblValRQ);
		lblValRQ.setHorizontalAlignment(SwingConstants.TRAILING);
		lblValRQ.setForeground(Color.BLUE);
		lblValRQ.setFont(new Font("Dialog", Font.BOLD, 14));
		
		JLabel lblValRC = new JLabel("0");
		lblValRC.setBounds(183, 147, 151, 17);
		pan.add(lblValRC);
		lblValRC.setHorizontalAlignment(SwingConstants.TRAILING);
		lblValRC.setForeground(Color.BLUE);
		lblValRC.setFont(new Font("Dialog", Font.BOLD, 14));
		
		JLabel lblValVA = new JLabel("0");
		lblValVA.setBounds(183, 185, 151, 17);
		pan.add(lblValVA);
		lblValVA.setHorizontalAlignment(SwingConstants.TRAILING);
		lblValVA.setForeground(Color.BLUE);
		lblValVA.setFont(new Font("Dialog", Font.BOLD, 14));
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				int valor = (int) spinner.getValue();
				lblValRD2.setText(String.format("%d,00",valor%2)); //resto divisao por 2
				lblValElC.setText(String.format("%.2f",Math.pow(valor, 3))); // elevado ao cubo
				lblValRQ.setText(String.format("%.2f",Math.sqrt(valor))); // raiz quadrada
				lblValRC.setText(String.format("%.2f",Math.cbrt(valor))); // raiz cubica
				lblValVA.setText(String.format("%d,00", Math.abs(valor))); //valor absoluto	
				
				pan.setVisible(true);
			}
		});
	}
}

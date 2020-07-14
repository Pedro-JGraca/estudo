package classes;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;

public class TelaValores extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtNum;
	private JTextField txtDen;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaValores frame = new TelaValores();
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
	public TelaValores() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 295, 375);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		txtNum = new JTextField();
		txtNum.setBounds(150, 54, 114, 19);
		contentPane.add(txtNum);
		txtNum.setColumns(10);
		
		txtDen = new JTextField();
		txtDen.setBounds(150, 97, 114, 19);
		contentPane.add(txtDen);
		txtDen.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Numerador");
		lblNewLabel.setBounds(38, 56, 79, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Denominador");
		lblNewLabel_1.setBounds(38, 99, 95, 15);
		contentPane.add(lblNewLabel_1);
		
		JButton btnDividir = new JButton("Calcular");
		
		btnDividir.setBounds(72, 144, 117, 25);
		contentPane.add(btnDividir);
		
		JLabel lblNewLabel_2 = new JLabel("Divisao");
		lblNewLabel_2.setBounds(38, 218, 70, 15);
		contentPane.add(lblNewLabel_2);
		
		JLabel lblDiv = new JLabel("0");
		lblDiv.setForeground(Color.RED);
		lblDiv.setHorizontalAlignment(SwingConstants.TRAILING);
		lblDiv.setBounds(171, 218, 70, 15);
		contentPane.add(lblDiv);
		
		JLabel lblNewLabel_4 = new JLabel("Resto");
		lblNewLabel_4.setBounds(38, 260, 70, 15);
		contentPane.add(lblNewLabel_4);
		
		JLabel lblRest = new JLabel("0");
		lblRest.setForeground(Color.RED);
		lblRest.setHorizontalAlignment(SwingConstants.TRAILING);
		lblRest.setBounds(171, 260, 70, 15);
		contentPane.add(lblRest);
		
		JLabel lblNewLabel_4_1 = new JLabel("Raiz");
		lblNewLabel_4_1.setBounds(38, 301, 70, 15);
		contentPane.add(lblNewLabel_4_1);
		
		JLabel lblRaiz = new JLabel("0");
		lblRaiz.setHorizontalAlignment(SwingConstants.TRAILING);
		lblRaiz.setForeground(new Color(255, 0, 0));
		lblRaiz.setBounds(171, 301, 70, 15);
		contentPane.add(lblRaiz);
		
		btnDividir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int num = Integer.parseInt(txtNum.getText());
				int dev = Integer.parseInt(txtDen.getText());
				String div = Integer.toString(num/dev);
				String resto = Integer.toString(num%dev);
				lblDiv.setText(div);
				lblRest.setText(resto);
				String raiz= Double.toString(Math.pow((double)num,1.0D/((double)dev)));
				lblRaiz.setText(raiz);
				
				
			}
		});
	}
}

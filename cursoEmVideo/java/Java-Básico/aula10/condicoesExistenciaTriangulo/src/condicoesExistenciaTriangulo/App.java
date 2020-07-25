package condicoesExistenciaTriangulo;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JSlider;
import javax.swing.JButton;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import java.awt.Font;
import java.awt.Color;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.ImageIcon;

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
	public int abs (int n) {
		if (n<0)
		{
			return n*(-1);
		}
		else {
			return n;
		}
	}
	
	public boolean isTriangulo(int a, int b, int c) {

		if (((abs(b-c)<a) && (a<(b+c))) && ((abs(a-c)<b) && (b<(a+c))) && ((abs(a-b)<c) && (c<(a+b))))
		{
			return true;
		}
		else {
			return false;
		}
	}
	
	public String TipoTriangulo(int a, int b, int c) {
		
		if ((a==b)&&(b==c)) {
			return "equilatero";
		}
		else if ((a==b)||(a==c)||(b==c)) {
			return "isoceles";
		}
		else if ((a!=b)&&(b!=c)&&(c!=a)) {
			return "escaleno";
		}
		else {
			return "nao sei";
		}
	}
	
	public App() {
		int div =5;
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 509, 311);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblSegmentoA = new JLabel("Segmento a");
		lblSegmentoA.setBounds(12, 30, 99, 15);
		contentPane.add(lblSegmentoA);
		
		JLabel lblSegmentoB = new JLabel("Segmento b");
		lblSegmentoB.setBounds(12, 68, 99, 15);
		contentPane.add(lblSegmentoB);
		
		JLabel lblSegmentoC = new JLabel("Segmento c");
		lblSegmentoC.setBounds(12, 116, 99, 15);
		contentPane.add(lblSegmentoC);
		
		JSlider sliderA = new JSlider();

		sliderA.setBounds(112, 29, 200, 16);
		contentPane.add(sliderA);
		
		JSlider sliderB = new JSlider();
		sliderB.setBounds(112, 67, 200, 16);
		contentPane.add(sliderB);
		
		JSlider sliderC = new JSlider();
		sliderC.setBounds(112, 116, 200, 16);
		contentPane.add(sliderC);
		
		JLabel lblSliderA = new JLabel(Integer.toString(sliderA.getValue()/div));
		lblSliderA.setBounds(318, 30, 27, 15);
		contentPane.add(lblSliderA);
		
		JLabel lblSliderB = new JLabel(Integer.toString(sliderB.getValue()/div));
		lblSliderB.setBounds(318, 68, 27, 15);
		contentPane.add(lblSliderB);
		
		JLabel lblSliderC = new JLabel(Integer.toString(sliderC.getValue()/div));
		lblSliderC.setBounds(318, 116, 27, 15);
		contentPane.add(lblSliderC);
		
		JButton btnVerifica = new JButton("Verificar");

		btnVerifica.setBounds(84, 165, 117, 25);
		contentPane.add(btnVerifica);
		
		JLabel lblTriangulo = new JLabel("");
		lblTriangulo.setHorizontalAlignment(SwingConstants.CENTER);
		lblTriangulo.setForeground(Color.BLUE);
		lblTriangulo.setFont(new Font("Dialog", Font.BOLD, 18));
		lblTriangulo.setBounds(94, 212, 328, 38);
		contentPane.add(lblTriangulo);
		
		JLabel lblTipo = new JLabel("");
		lblTipo.setFont(new Font("Dialog", Font.BOLD, 16));
		lblTipo.setForeground(Color.RED);
		lblTipo.setHorizontalAlignment(SwingConstants.CENTER);
		lblTipo.setBounds(181, 244, 142, 33);
		contentPane.add(lblTipo);
		
		JLabel lblImagem = new JLabel("");
		lblImagem.setIcon(new ImageIcon(App.class.getResource("/imagens/Triangulo.png")));
		lblImagem.setBounds(392, 42, 99, 100);
		contentPane.add(lblImagem);
		
		sliderA.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblSliderA.setText(Integer.toString(sliderA.getValue()/div));
			}
		});
		sliderB.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblSliderB.setText(Integer.toString(sliderB.getValue()/div));
			}
		});
		sliderC.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblSliderC.setText(Integer.toString(sliderC.getValue()/div));
			}
		});
		
		btnVerifica.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				int a = sliderA.getValue()/div;
				int b = sliderB.getValue()/div;
				int c = sliderC.getValue()/div;
				
				if (!isTriangulo(a,b,c)){
					lblTriangulo.setText("Não forma um Triangulo");
					lblTipo.setText("");
				}
				else {
					String tipo = TipoTriangulo(a,b,c); 
					lblTriangulo.setText("Forma um Triangulo");
					if (tipo.equals("escaleno")) {
						lblTipo.setText(tipo);
					}
					else if (tipo.equals("isoceles")) {
						lblTipo.setText(tipo);
					}
					else if (tipo.equals("equilatero")) {
						lblTipo.setText(tipo);
					}
					else {
						lblTipo.setText(tipo);

					}
				}
				
				

			}
		});
	}
}

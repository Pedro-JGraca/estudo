package app;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JComboBox;
import javax.swing.JSpinner;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.Color;
import javax.swing.SpinnerNumberModel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;

public class App extends JFrame {

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
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JSpinner spinnerX2 = new JSpinner();

		spinnerX2.setModel(new SpinnerNumberModel(0, -150, 150, 1));
		spinnerX2.setBounds(49, 36, 42, 20);
		contentPane.add(spinnerX2);
		
		JSpinner spinnerX = new JSpinner();

		spinnerX.setModel(new SpinnerNumberModel(0, -150, 150, 1));
		spinnerX.setBounds(142, 36, 42, 20);
		contentPane.add(spinnerX);
		
		JSpinner spinnerC = new JSpinner();
		spinnerC.setModel(new SpinnerNumberModel(0, -150, 150, 1));
		spinnerC.setBounds(235, 36, 42, 20);
		contentPane.add(spinnerC);
		
		JLabel lblNewLabel = new JLabel("X²  +");
		lblNewLabel.setFont(new Font("FreeSans", Font.BOLD, 18));
		lblNewLabel.setBounds(98, 28, 42, 33);
		contentPane.add(lblNewLabel);
		
		JLabel lblX = new JLabel("X  +");
		lblX.setFont(new Font("FreeSans", Font.BOLD, 18));
		lblX.setBounds(188, 28, 42, 33);
		contentPane.add(lblX);
		
		JLabel lblX_1 = new JLabel("= 0");
		lblX_1.setFont(new Font("FreeSans", Font.BOLD, 18));
		lblX_1.setBounds(280, 28, 66, 33);
		contentPane.add(lblX_1);
		
		JButton btnCalcular = new JButton("Calcular");

		btnCalcular.setBounds(160, 133, 117, 25);
		contentPane.add(btnCalcular);
		
		JLabel lblNewLabel_1 = new JLabel("D=        ² - 4.        .            =");
		lblNewLabel_1.setFont(new Font("Dialog", Font.BOLD, 18));
		lblNewLabel_1.setBounds(51, 83, 271, 38);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblA = new JLabel("A");
		lblA.setHorizontalAlignment(SwingConstants.CENTER);
		lblA.setForeground(Color.RED);
		lblA.setFont(new Font("Dialog", Font.BOLD, 18));
		lblA.setBounds(188, 83, 41, 38);
		contentPane.add(lblA);
		
		JLabel lblB = new JLabel("B");
		lblB.setHorizontalAlignment(SwingConstants.CENTER);
		lblB.setForeground(Color.RED);
		lblB.setFont(new Font("Dialog", Font.BOLD, 18));
		lblB.setBounds(83, 83, 54, 38);
		contentPane.add(lblB);
		
		JLabel lblC = new JLabel("C");
		lblC.setHorizontalAlignment(SwingConstants.CENTER);
		lblC.setForeground(Color.RED);
		lblC.setFont(new Font("Dialog", Font.BOLD, 18));
		lblC.setBounds(235, 83, 76, 38);
		contentPane.add(lblC);
		
		JLabel lblDelta = new JLabel("0");
		lblDelta.setFont(new Font("Dialog", Font.BOLD, 18));
		lblDelta.setBounds(323, 84, 48, 38);
		contentPane.add(lblDelta);
		
		JLabel lblX1 = new JLabel("X1=");
		lblX1.setBounds(68, 188, 70, 15);
		contentPane.add(lblX1);
		
		JLabel lblX2 = new JLabel("X2=");
		lblX2.setBounds(70, 229, 70, 15);
		contentPane.add(lblX2);
		
		JLabel labelXR1 = new JLabel("");
		labelXR1.setHorizontalAlignment(SwingConstants.LEFT);
		labelXR1.setBounds(142, 188, 180, 15);
		contentPane.add(labelXR1);
		
		JLabel labelXR2 = new JLabel("");
		labelXR2.setHorizontalAlignment(SwingConstants.LEFT);
		labelXR2.setBounds(142, 229, 180, 15);
		contentPane.add(labelXR2);
		spinnerX2.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblA.setText(spinnerX2.getValue().toString());
			}
		});
		spinnerX.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblB.setText(spinnerX.getValue().toString());
			}
		});
		spinnerC.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblC.setText(spinnerC.getValue().toString());
			}
		});
		
		btnCalcular.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				labelXR1.setText("");
				labelXR2.setText("");
				int A = (int) spinnerX2.getValue();
				int B = (int) spinnerX.getValue();
				//

				//
				int C = (int) spinnerC.getValue();
				//

				//
				int Delta = (int) B*B - 4*A*C;
				lblDelta.setText(Integer.toString(Delta));
				if (!(A==0)) {
					if (Delta>0) {
						double xr1 = (-B+ Math.pow(Delta,(0.5f)))/((double) (2*A));
						double xr2 = (-B- Math.pow(Delta,(0.5f)))/((double) (2*A));
						

						labelXR1.setText(String.format("%.2f", xr1));
						labelXR2.setText(String.format("%.2f", xr2));
					}

					else if (Delta == 0) {
						double xr = (-B/((double) (2*A)));
						labelXR1.setText(String.format("%.2f", xr));
						labelXR2.setText(String.format("%.2f", xr));
					}
					else {
						labelXR1.setText("complexo");
						labelXR2.setText("complexo");
					}

				}
				else {
					labelXR1.setText("A nao pode ser zero");
					labelXR2.setText("A não pode ser zero");
				}


			}
		});
	}
}

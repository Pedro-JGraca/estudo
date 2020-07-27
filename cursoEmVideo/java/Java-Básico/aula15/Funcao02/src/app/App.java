package app;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

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
		setBounds(100, 100, 450, 147);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblFormula = new JLabel("");
		lblFormula.setBounds(12, 54, 269, 15);
		contentPane.add(lblFormula);
		
		JLabel lblResultado = new JLabel("");
		lblResultado.setBounds(51, 81, 243, 15);
		contentPane.add(lblResultado);
		
		JButton btnNewButton = new JButton("!");

		btnNewButton.setHorizontalAlignment(SwingConstants.LEFT);
		btnNewButton.setBounds(91, 12, 39, 25);
		contentPane.add(btnNewButton);
		
		JSpinner spinner = new JSpinner();
		spinner.setModel(new SpinnerNumberModel(0, 0, 12, 1));
		spinner.setBounds(41, 15, 39, 20);
		contentPane.add(spinner);
		
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			int n = (int) spinner.getValue();
			Fatorial f = new Fatorial();
			f.setValor(n);
			lblFormula.setText(f.getFormula());
			lblResultado.setText(Integer.toString(f.getFatorial()));
			}
		});
	}
}

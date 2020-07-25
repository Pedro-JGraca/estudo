package app;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JSpinner;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.SpinnerNumberModel;
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
		setBounds(100, 100, 160, 120);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JSpinner spinner = new JSpinner();

		spinner.setModel(new SpinnerNumberModel(1, 1, 10, 1));
		spinner.setBounds(106, 12, 29, 20);
		contentPane.add(spinner);
		
		JLabel lblNewLabel = new JLabel("Pernas");
		lblNewLabel.setBounds(22, 14, 70, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblTipo = new JLabel("");
		lblTipo.setHorizontalAlignment(SwingConstants.CENTER);
		lblTipo.setBounds(22, 56, 113, 15);
		contentPane.add(lblTipo);
		spinner.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				int pernas= (int) spinner.getValue();
				switch (pernas) {
				case 1:
					lblTipo.setText("Saci");
					break;
				case 2:
					lblTipo.setText("Bípede");
					break;
				case 4:
					lblTipo.setText("Quadrupede");
					break;
				case 6:
					lblTipo.setText("Insetos");
					break;
				default:
					lblTipo.setText("ET");
				}
				
			}
		});
	}
}

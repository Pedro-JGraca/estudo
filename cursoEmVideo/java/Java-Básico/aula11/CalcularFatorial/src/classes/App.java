package classes;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import javax.swing.JSpinner;
import java.awt.Font;
import javax.swing.SpinnerNumberModel;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import javax.swing.UIManager;

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
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 611, 461);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setIcon(new ImageIcon(App.class.getResource("/imagens/alerta.png")));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(466, 12, 133, 382);
		contentPane.add(lblNewLabel);
		
		JSpinner spinner = new JSpinner();

		spinner.setModel(new SpinnerNumberModel(1, 1, 12, 1));
		spinner.setFont(new Font("Dialog", Font.BOLD, 48));
		spinner.setBounds(32, 156, 99, 76);
		contentPane.add(spinner);
		
		JLabel lblNewLabel_1 = new JLabel("! = ");
		lblNewLabel_1.setFont(new Font("Dialog", Font.BOLD, 48));
		lblNewLabel_1.setBounds(140, 156, 99, 76);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblResposta = new JLabel("1");
		lblResposta.setForeground(UIManager.getColor("OptionPane.errorDialog.border.background"));
		lblResposta.setHorizontalAlignment(SwingConstants.LEFT);
		lblResposta.setFont(new Font("Dialog", Font.BOLD, 36));
		lblResposta.setBounds(223, 159, 231, 76);
		contentPane.add(lblResposta);
		
		JLabel lblResposta_1 = new JLabel("1");
		lblResposta_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblResposta_1.setForeground(UIManager.getColor("OptionPane.warningDialog.titlePane.foreground"));
		lblResposta_1.setFont(new Font("Dialog", Font.BOLD, 28));
		lblResposta_1.setBounds(12, 288, 481, 76);
		contentPane.add(lblResposta_1);
		
		spinner.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				int n=(int)spinner.getValue();
				int r=1;
				String contador = "" + n;
				while (n > 1) {
					r*=n;
					n--;
					contador += "*" + n;
				}
				lblResposta_1.setText(contador);
				String resposta = "<html>" + r + "</html>";
				lblResposta.setText(resposta);
			}
		});
	}
}

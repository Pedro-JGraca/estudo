package contadorEspecial;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JSlider;
import javax.swing.JButton;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.DefaultListModel;
import javax.swing.ListSelectionModel;
import javax.swing.border.BevelBorder;
import javax.swing.JTree;
import javax.swing.JSeparator;
import javax.swing.JEditorPane;

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
		setBounds(100, 100, 511, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Inicio");
		lblNewLabel.setBounds(28, 28, 70, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblNew = new JLabel("Fim");
		lblNew.setBounds(28, 61, 70, 15);
		contentPane.add(lblNew);
		
		JLabel lblNewLabel_1_1 = new JLabel("Passo");
		lblNewLabel_1_1.setBounds(28, 97, 70, 15);
		contentPane.add(lblNewLabel_1_1);
		
		
		JSlider sliderInicio = new JSlider();
		sliderInicio.setValue(3);
		sliderInicio.setMaximum(6);

		sliderInicio.setBounds(68, 28, 200, 16);
		contentPane.add(sliderInicio);
		
		JSlider sliderFim = new JSlider();
		sliderFim.setMinimum(1);
		sliderFim.setValue(10);
		sliderFim.setMaximum(20);

		sliderFim.setBounds(68, 60, 200, 16);
		contentPane.add(sliderFim);
		
		JSlider sliderPasso = new JSlider();
		sliderPasso.setMinimum(1);
		sliderPasso.setValue(3);
		sliderPasso.setMaximum(6);

		sliderPasso.setBounds(68, 96, 200, 16);
		contentPane.add(sliderPasso);
		
		JLabel lblInicio = new JLabel("2");
		lblInicio.setBounds(268, 28, 29, 15);
		contentPane.add(lblInicio);
		
		JLabel lblFim = new JLabel(Integer.toString(sliderFim.getValue()));
		lblFim.setBounds(268, 61, 29, 15);
		contentPane.add(lblFim);
		
		JLabel lblPasso = new JLabel("2");
		lblPasso.setBounds(268, 97, 29, 15);
		contentPane.add(lblPasso);
		
		JButton btnContar = new JButton("Contar");

		btnContar.setBounds(109, 148, 117, 25);
		contentPane.add(btnContar);
		
		JList<Integer> listA = new JList<Integer>();
		listA.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		listA.setBounds(337, 12, 137, 227);
		contentPane.add(listA);
		sliderInicio.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {

				lblInicio.setText(Integer.toString(sliderInicio.getValue()));
				if (Integer.parseInt(lblFim.getText()) <= Integer.parseInt(lblInicio.getText())) {
					lblFim.setText(Integer.toString(sliderInicio.getValue()+1));
					sliderFim.setValue((sliderInicio.getValue()+1));
				}
			}
		});
		sliderFim.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				if (sliderFim.getValue()>sliderInicio.getValue()) {
					lblFim.setText(Integer.toString(sliderFim.getValue()));
				}
				else {
					sliderInicio.setValue(sliderFim.getValue()-1);
					lblFim.setText(Integer.toString(sliderFim.getValue()));
				}

			}
		});
		
		sliderPasso.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblPasso.setText(Integer.toString(sliderPasso.getValue()));
			}
		});
		
		btnContar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int inicio= Integer.parseInt(lblInicio.getText());
				int fim= Integer.parseInt(lblFim.getText());
				int passo= Integer.parseInt(lblPasso.getText());
				
				DefaultListModel<Integer> lista = new DefaultListModel<Integer>();
				
				for (int i=inicio;i<=fim;i+=passo) {
					lista.addElement(i);
				}
						
				listA.setModel(lista);
			}
		});
	}
}

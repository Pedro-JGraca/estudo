package projetoVetor;


import java.awt.EventQueue;
import java.util.Arrays;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JSpinner;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JScrollPane;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

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
	public void rotina1( int local, int valor, int[] vector){
		if (local <0) local=0;
		vector[local] = valor;
	}
	public void rotina (int [] vector ,DefaultListModel<String> lista, JSpinner spinner, JLabel lblVector ) {
		lista.removeAllElements();
		for (int i = 0; i<vector.length;i++) {
			lista.addElement("vector["+i+"]= "+ vector[i]);
		}
		spinner.setValue(0);
		lblVector.setText("["+0+"]");
	}
	
	public App() {
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 310);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JSpinner spinner = new JSpinner();
		spinner.setBounds(26, 36, 56, 20);
		contentPane.add(spinner);
		
		JButton btnAdd = new JButton("Add");

		btnAdd.setBounds(99, 33, 117, 25);
		contentPane.add(btnAdd);
		
		JButton btnRemover = new JButton("Remover");

		btnRemover.setBounds(99, 70, 117, 25);
		contentPane.add(btnRemover);
		
		JButton btnOrdenar = new JButton("Ordenar");

		btnOrdenar.setBounds(99, 107, 117, 25);
		contentPane.add(btnOrdenar);
		
		JLabel lblNewLabel = new JLabel("Vetor");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(319, 12, 51, 20);
		contentPane.add(lblNewLabel);
		
		JLabel lblVector = new JLabel("[0]");
		lblVector.setBounds(380, 15, 28, 15);
		contentPane.add(lblVector);
		
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(292, 36, 132, 228);
		contentPane.add(scrollPane);

		JList<String> lstVetor = new JList<String>();

		scrollPane.setViewportView(lstVetor);
		
		int[] vector = new int [10];;
		
		Arrays.fill(vector, 0);
		
		DefaultListModel<String> lista = new DefaultListModel<String>();
		


		for (int i = 0; i<vector.length;i++) {
			lista.addElement("vector["+i+"]= "+ vector[i]);
		}
		
		lstVetor.setModel(lista); //atrela a lista visual a lista
		
		lstVetor.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				int local = lstVetor.getSelectedIndex();
				if (local <0) local=0;
				lblVector.setText("["+local+"]");
				
			}
		});
		





		btnAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rotina1(lstVetor.getSelectedIndex(),(int)spinner.getValue(),vector);				
				rotina (vector,lista,spinner,lblVector);

			}
		});

		btnRemover.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rotina1(lstVetor.getSelectedIndex(),0,vector);
				rotina (vector,lista,spinner,lblVector);
			}
		});

		btnOrdenar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Arrays.sort(vector);
				rotina (vector,lista,spinner,lblVector);
			}
		});


	}
}

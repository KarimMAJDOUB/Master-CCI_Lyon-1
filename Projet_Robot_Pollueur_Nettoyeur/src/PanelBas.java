import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class PanelBas {
	Monde M = new Monde();
	JPanel bas = new JPanel();
	JButton bNombre = new JButton("Nombre de cases polluees " );
	
	public PanelBas(Monde M){
		seTPanelBas();
		NomPapiersGras(M);
		
	}
	public void seTPanelBas(){
		bas.setLayout(new GridBagLayout()); 
		GridBagConstraints gc = new GridBagConstraints(); 
		gc.fill = GridBagConstraints.BOTH; 
		gc.insets = new Insets(1, 1, 1, 1); 
		
	
		gc.ipady = gc.anchor = GridBagConstraints.CENTER;
		gc.weightx = 1; 
		gc.weighty = 1; 
		
		gc.gridx = 0;
		gc.gridy = 0;
		bas.add(bNombre, gc); 
		
		Fenetre.fenetre.add(bas, BorderLayout.SOUTH ); 
	}

	public void NomPapiersGras(Monde m){
		}

}

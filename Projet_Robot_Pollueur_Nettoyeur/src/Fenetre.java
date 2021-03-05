import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class Fenetre {
	static JFrame fenetre = new JFrame();
	
	
	public Fenetre(Monde M1){
		fenetre.setTitle("Projet ROBOT");
		fenetre.setSize(1500, 1000);
		fenetre.setLocationRelativeTo(null);
		fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fenetre.setVisible(true);
		
		new PanelCentre(M1);
		new PanelBas(M1);
		new PanelHaut(M1);
		new PanelDroit(M1);
		new PanelGauche(M1);
	}
}

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class PanelHaut {
	
	JPanel haut = new JPanel();
	JButton bNettoyer = new JButton("Nettoyer Tout");
	JButton bPolluerTout = new JButton("Polluer Tout");
	JButton bRAZ = new JButton("Réinitilisation");
	JButton bQuitter = new JButton("Quitter");
	
	
	public PanelHaut(Monde M1){
		seTPanelHaut();
		PolluerTout(M1);
		NettoyerTout(M1);
		Quitter();
		RAZ(M1);
	}
	public void seTPanelHaut(){
		haut.setLayout(new GridBagLayout()); 
		GridBagConstraints gc = new GridBagConstraints(); 
		gc.fill = GridBagConstraints.BOTH;
		gc.insets = new Insets(1, 1, 1, 1); 
		
		
		gc.ipady = gc.anchor = GridBagConstraints.CENTER;
		gc.weightx = 4; 
		gc.weighty = 1; 
		
		gc.gridx = 0;
		gc.gridy = 0;
		haut.add(bNettoyer, gc);
		
		gc.gridx = 1;
		gc.gridy = 0;
		haut.add(bPolluerTout, gc); 
		
		gc.gridx = 2;
		gc.gridy = 0;
		haut.add(bRAZ, gc);
		
		gc.gridx = 3;
		gc.gridy = 0;
		haut.add(bQuitter, gc); 
		
	
		
		Fenetre.fenetre.add(haut, BorderLayout.NORTH );
	}
	public void PolluerTout(Monde m){
		bPolluerTout.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent Polluer){
				try {
					new Pollueurs(m); 
				} catch (ajoutPapierException e) {
					e.printStackTrace();
				}
				MAS(m);
				haut.repaint();
				haut.revalidate();
			}});
	}
	public void NettoyerTout(Monde m){
		bNettoyer.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent Nettoyer){
				try {
					new Nettoyeurs(m);
				} catch (ajoutPapierException e) {
					e.printStackTrace();
				}
				MAS(m);
				haut.repaint();
				haut.revalidate();
			}});
	}
	public void RAZ (Monde m){
		bRAZ.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent Nettoyer){
				try {
					new Nettoyeurs(m);
				} catch (ajoutPapierException e) {
					e.printStackTrace();
				}
				MAS(m);
				haut.repaint();
				haut.revalidate();
			}});
	}
	public void Quitter(){
		bQuitter.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent Nettoyer){
				System.exit(0); 
			}});
	}
	public void MAS(Monde m){
		PanelCentre PC = new PanelCentre(m); 
		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++){
				if(m.Mat[i][j])
					PC.tabCentre[i][j].setBackground(Color.red);
				else
					PC.tabCentre[i][j].setBackground(Color.blue);
			}
	}
}

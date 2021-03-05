import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


import javax.swing.*;

public class PanelDroit {
	
	JPanel droit = new JPanel();
 	JButton bNettoyeurColonne = new JButton("Nettoyeur Colonne");
	static JButton bNettoyeurSmart = new JButton("Nettoyeur Smart");
	JButton bNettoyeurLibre = new JButton("Nettoyeur Libre");
	JButton bNettoyeurSauteur = new JButton("Nettoyeur Sauteur");
	JButton bNettoyeurPlus = new JButton("Nettoyeur Plus");
	int i, j;
	int colonne;
	int ligne;
	public PanelDroit(Monde M){
	
		setPanelDroit();
		NettoyeurColonne(M);
		NettoyeurSmart(M);
		NettoyeurLibre(M);
		NettoyeurSauteur(M);
		NettoyeurPlus(M);
		
	}
	public void setPanelDroit(){
		droit.setLayout(new GridBagLayout()); 
		GridBagConstraints gc = new GridBagConstraints(); 
		gc.fill = GridBagConstraints.BOTH; 
		gc.insets = new Insets(1, 1, 1, 1); 
		gc.ipady = gc.anchor = GridBagConstraints.CENTER;
		
		gc.weightx = 1; 
		gc.weighty = 5; 
	
		
		gc.gridx = 0;
		gc.gridy = 0;
		droit.add(bNettoyeurColonne, gc);
		
		gc.gridx = 0;
		gc.gridy = 1;
		droit.add(bNettoyeurSmart, gc);
		
		gc.gridx = 0;
		gc.gridy = 2;
		droit.add(bNettoyeurLibre, gc);
		
		gc.gridx = 0;
		gc.gridy = 3;
		droit.add(bNettoyeurSauteur, gc);

		gc.gridx = 0;
		gc.gridy = 4;
		droit.add(bNettoyeurPlus, gc);
				
		Fenetre.fenetre.add(droit, BorderLayout.EAST ); 
	}
	public void NettoyeurColonne(Monde m){
		bNettoyeurColonne.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurTouutDroit){
				try {
					int colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					while(colonne > 9)
						colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					new Nettoyeurs(colonne,m);
				} catch (ajoutPapierException e) {
					e.printStackTrace();
				}
				MAS(m);
				droit.repaint();
				droit.revalidate();
			}});
	}

		public void NettoyeurSmart(Monde m){
		bNettoyeurSmart.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurTouutDroit){
				
					try {
						ligne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
						while(ligne > 9)
							ligne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
						colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la ligne :"));
						while(colonne > 9)
							colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la ligne :"));
						new Nettoyeurs(ligne,colonne,m);
						
					} catch (ajoutPapierException e) {
					e.printStackTrace();
					}
			
				
				MAS(m);
				droit.repaint();
				droit.revalidate();
			}});
	}


	public void NettoyeurLibre(Monde m){
		bNettoyeurLibre.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurAleatoire){
				try {
					new Nettoyeurs(m, 1);  
				} catch (ajoutPapierException e) {
					e.printStackTrace();
				}
				MAS(m);
				droit.repaint();
				droit.revalidate();
			}});
	}
	public void NettoyeurSauteur(Monde m){
		bNettoyeurSauteur.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurSauteur){
				try 
				{
				
					int CDebut = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					while(CDebut > 9)
						CDebut = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					int pas = Integer.parseInt(JOptionPane.showInputDialog("Le pas ="));
					while(pas > 9)
						pas = Integer.parseInt(JOptionPane.showInputDialog("Le pas ="));
					new Nettoyeurs(m, pas, CDebut);
				} 
				catch (ajoutPapierException e)
				 {
					e.printStackTrace();
				}
				MAS(m);
				droit.repaint();
				droit.revalidate();
			}});
	}


	public void NettoyeurPlus(Monde m){
		bNettoyeurPlus.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurSauteur){
				try 
				{
					int NC = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					int NL = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la ligne :"));
					int CENTR = Integer.parseInt(JOptionPane.showInputDialog("Le centre ="));		
					new Nettoyeurs(m, NC, NL, CENTR);
				} 
				catch (ajoutPapierException e)
				 {
					e.printStackTrace();
				}
				MAS(m);
				droit.repaint();
				droit.revalidate();
			}});
	}


	public void MAS(Monde m){
		Fonction F = new Fonction(m); 
		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++){
				if(m.Mat[i][j])
					F.tabCentre[i][j].setBackground(Color.red);
				else
					F.tabCentre[i][j].setBackground(Color.blue);
			}
	}
}

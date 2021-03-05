import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


import javax.swing.*;

public class PanelGauche {
	
	JPanel gauche = new JPanel();
 	JButton bPollueurColonne = new JButton("Pollueur Colonne");
	static JButton bPollueurSmart = new JButton("Pollueur Smart");
	JButton bPollueurLibre = new JButton("Pollueur Libre");
	JButton bPollueurSauteur = new JButton("Pollueur Sauteur");
	JButton bPollueurPlus = new JButton("Pollueur Plus");
	int i, j;
	int colonne;
	int ligne;
	public PanelGauche(Monde M){
	
		setPanelGauche();
		PollueurColonne(M);
		PollueurSmart(M);
		PollueurLibre(M);
		PollueurSauteur(M);
		PollueurPlus(M);
	}
	public void setPanelGauche(){
		gauche.setLayout(new GridBagLayout()); 
		GridBagConstraints gc = new GridBagConstraints(); 
		gc.fill = GridBagConstraints.BOTH; 
		gc.insets = new Insets(1, 1, 1, 1); 
		gc.ipady = gc.anchor = GridBagConstraints.CENTER;
		
		gc.weightx = 1; 
		gc.weighty = 5; 
	
		
		gc.gridx = 0;
		gc.gridy = 0;
		gauche.add(bPollueurColonne, gc);
		
		gc.gridx = 0;
		gc.gridy = 1;
		gauche.add(bPollueurSmart, gc);
		
		gc.gridx = 0;
		gc.gridy = 2;
		gauche.add(bPollueurLibre, gc);
		
		gc.gridx = 0;
		gc.gridy = 3;
		gauche.add(bPollueurSauteur, gc);

		gc.gridx = 0;
		gc.gridy = 4;
		gauche.add(bPollueurPlus, gc);
				
		Fenetre.fenetre.add(gauche, BorderLayout.WEST ); 
	}
	public void PollueurColonne(Monde m){
		bPollueurColonne.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurTouutDroit){
				
					try {
						colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la Colonne :"));
						while(colonne > 9)
							colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la Colonne :"));
						new Pollueurs(colonne,m);
						
					} catch (ajoutPapierException e) {
					e.printStackTrace();
					}
			
				
				MAS(m);
				gauche.repaint();
				gauche.revalidate();
			}});
	}

	public void PollueurSmart(Monde m){
		bPollueurSmart.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurTouutDroit){
				
					try {
						ligne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
						while(ligne > 9)
							ligne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
						colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la ligne :"));
						while(colonne > 9)
							colonne = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la ligne :"));
						new Pollueurs(ligne,colonne,m);
						
					} catch (ajoutPapierException e) {
					e.printStackTrace();
					}
			
				
				MAS(m);
				gauche.repaint();
				gauche.revalidate();
			}});
	}
	public void PollueurLibre(Monde m){
		bPollueurLibre.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurAleatoire){
				try {
					new Pollueurs(m, 1);  /*Robot pollueur aléatoire */
				} catch (ajoutPapierException e) {
					e.printStackTrace();
				}
				MAS(m);
				gauche.repaint();
				gauche.revalidate();
			}});
	}
	public void PollueurSauteur(Monde m){
		bPollueurSauteur.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurSauteur){
				try 
				{
					
					int CDebut = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne:"));
					while(CDebut > 9)
						CDebut = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					int pas = Integer.parseInt(JOptionPane.showInputDialog("Le pas ="));
					while(pas > 9)
						pas = Integer.parseInt(JOptionPane.showInputDialog("Le pas = "));
					new Pollueurs(m, pas, CDebut);
				} 
				catch (ajoutPapierException e)
				 {
					e.printStackTrace();
				}
				MAS(m);
				gauche.repaint();
				gauche.revalidate();
			}});
	}

		public void PollueurPlus(Monde m){
		bPollueurPlus.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurSauteur){
				try 
				{
					int NC = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la colonne :"));
					int NL = Integer.parseInt(JOptionPane.showInputDialog("Donner le numero de la ligne :"));
					int CENTR = Integer.parseInt(JOptionPane.showInputDialog("CENTER :"));		
					new Pollueurs(m, NC, NL, CENTR);
				} 
				catch (ajoutPapierException e)
				 {
					e.printStackTrace();
				}
				MAS(m);
				gauche.repaint();
				gauche.revalidate();
			}});
	}

	public void MAS(Monde m){
		Fonction PC = new Fonction(m); 
		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++){
				if(m.Mat[i][j])
					PC.tabCentre[i][j].setBackground(Color.red);
				else
					PC.tabCentre[i][j].setBackground(Color.blue);
			}
	}
}

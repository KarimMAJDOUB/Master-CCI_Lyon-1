import java.awt.*;
import javax.swing.*;

public class PanelCentre {

	JPanel tabCentre[][] = new JPanel[10][10];
	JPanel centre = new JPanel();
	public PanelCentre(Monde M1){
		centre.setLayout(new GridLayout(10,10));
		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++){
				tabCentre[i][j] = new JPanel();
				if(M1.Mat[i][j])
					tabCentre[i][j].setBackground(Color.red);
				else
					tabCentre[i][j].setBackground(Color.blue);
				centre.add(tabCentre[i][j]);
				tabCentre[i][j].setBorder(BorderFactory.createLineBorder(Color.white));
			}
		Fenetre.fenetre.add(centre, BorderLayout.CENTER );
	}
}

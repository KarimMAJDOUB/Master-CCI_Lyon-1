
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.*;
import javax.swing.*;

public class Fonction extends JPanel implements ActionListener{
	
		Monde M;
		JFrame frame = new JFrame();
		JFrame fenetre = new JFrame();
		ImageIcon Anima;
		int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w;
		final JButton bPollueurSmart = PanelGauche.bPollueurSmart;
		JLabel holder = new JLabel();
		Timer clock = new Timer(1000, this);
		JPanel tabCentre[][] = new JPanel[10][10];
		JPanel centreS = new JPanel();
		JPanel nord = new JPanel();
		static boolean mode = false;
		int jeton1, jeton2;
		
	public Fonction(Monde M1)
	{
		M = M1;
		
		centreS.setLayout(new GridLayout(10,10));
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				tabCentre[i][j] = new JPanel();
				if(M.Mat[i][j] )
					tabCentre[i][j].setBackground(Color.red);
				else
					tabCentre[i][j].setBackground(Color.blue);
				centreS.add(tabCentre[i][j]);
				tabCentre[i][j].setBorder(BorderFactory.createLineBorder(Color.white));
			}
		}
		Fenetre.fenetre.add(centreS, BorderLayout.CENTER );
	}
	
	public void PollueurSmart()
	{
		bPollueurSmart.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent PollueurAleatoire){
				clock.start();
				
			}});
		
	}
	@Override
	public void actionPerformed(ActionEvent e) {
			if(j<3 && i == 0){
				tabCentre[0][j].setBackground(Color.red);
				j++;
			}
			if(i<5 && j>=3){
				tabCentre[i][1].setBackground(Color.red);
				i++;
			}
			o = (int)(Math.random()*10);
            p = (int)(Math.random()*10);
            tabCentre[o][p].setBackground(Color.red);
			revalidate();
			repaint();
	}
}

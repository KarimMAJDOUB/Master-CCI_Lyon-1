
public class RobotNettoyeur extends Robot {
	public RobotNettoyeur(Monde m1) throws ajoutPapierException{
		super(0,0, m1);
		parcourir();
	}
	public void parcourir(){
		for(int i=0; i<m.nbL; i++)
			for(int j=0; j<m.nbC; j++)
				m.Mat[i][j] = false;
	}
	public void affiche(){
		super.affiche();
	}
}

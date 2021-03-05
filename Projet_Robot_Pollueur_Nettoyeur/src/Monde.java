public class Monde
{
    int nbL;
    int nbC;
    boolean Mat[][];
    
    public Monde()
    {
        nbL = 10;
        nbC = 10;
        Mat = new boolean[nbL][nbC];
    }
    public void ajoutPapier(int nL, int nC)
        throws ajoutPapierException
        {
            if(nL > nbL || nC > nbC)
                throw new ajoutPapierException();
            else
                Mat[nL][nC] = true;
        }
    public int comptePapierGras(){
        int compteur=0;
        for(int i=0; i<Mat.length; i++)
            for(int j=0; j<Mat.length; j++)
                if(Mat[i][j] == true)
                    compteur++;
        
        return compteur;
        
    }
}
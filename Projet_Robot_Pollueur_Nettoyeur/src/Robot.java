public abstract class Robot{
    int posx;
    int posy;
    Monde m;
    
    public Robot(int x, int y, Monde m1) 
        throws ajoutPapierException{
        posx = x;
        posy = y;
        m = m1;
    }
    public Robot(Monde m1) throws ajoutPapierException{
        posx = (int)(Math.random()*10);
        posy = (int)(Math.random()*10);
        m = m1;
    }
    public void deplacer(int x, int y)
        throws ajoutPapierException
        {
            if(x > m.nbL || y > m.nbC )
                throw new ajoutPapierException();
            else
            {
                posx = x;
                posy = y;
                m.ajoutPapier(posx, posy);
            }
        }
    public abstract void parcourir() throws ajoutPapierException;
    
    public void affiche(){
    	for(int i=0; i<m.nbL; i++){
    		for(int j=0; j<m.nbC; j++)
    			System.out.print(m.Mat[i][j] + " ");
    				System.out.print("\n");
    	}
    		
    			
    }
    
}
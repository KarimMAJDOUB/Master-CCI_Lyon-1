public class Pollueurs extends Robot{
    int  numRobot;
    int numColonne;
    
    
    public Pollueurs(Monde M) throws ajoutPapierException{  
 	    	super(0,0,M);
 	    	for(int i=0; i<m.nbL; i++)
 				for(int j=0; j<m.nbC; j++)
 					m.Mat[i][j] = true;
    }
    public Pollueurs(int nC, Monde M1) throws ajoutPapierException{ 
        	super(0,nC,M1);
        	numColonne = nC;
        	for(int i=0; i<m.nbL; i++)
    			m.Mat[i][numColonne] = true;
    }

    public Pollueurs(int nC, int nl,  Monde M2) throws ajoutPapierException{ 
            super(M2);
            for(int i=0; i<m.nbL; i++)
                for(int j =0; j<m.nbC; j++)
                m.Mat[nl][nC] = true;
    }
    public Pollueurs(Monde M3, int unused) throws ajoutPapierException{ 
    	super(M3);
    	m.Mat[posx][posy] = true;    				
    }
    public Pollueurs(Monde M4, int pas, int CDebut) throws ajoutPapierException{ 
    	super(M4);
    	
				for(int i=0; i<m.nbC; i=i+pas)
					m.Mat[i][CDebut] = true;    				
    }
    public Pollueurs(Monde M5, int c, int nl, int cen) throws ajoutPapierException{ 
        super(M5);
        m.Mat[cen][cen] = true;
            for (int i =0; i<10; i++) 
                m.Mat[i][c] = true;  
            for(int j=0; j<10; j++)
                m.Mat[nl][j] = true;
                                       
    }
    public void parcourir(){} 
}
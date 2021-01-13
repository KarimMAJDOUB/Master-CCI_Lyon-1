 class Matrice{
	double tableau[][];
	
	public Matrice (double tab [][]) {
		tableau = new double[tab.length][];
		for(int i = 0; i < tab.length; i++){
			tableau[i]= new double[tab[i].length];
			for(int j = 0; j < tab[i].length; j++){
				tableau[i][j]=tab[i][j];
			}
		}
    }
    
    public void afficheMatrice() {
		for(int i = 0; i < tableau.length; i++){
			for(int j = 0; j < tableau[i].length; j++){
				System.out.println(tableau[i][j]);
			}
		}
		
    }
    
    public double sommeligne (int i)
    {
		double som=0;
		for(int j = 0; j < tableau[i].length; j++){
			som=som + tableau[i][j];
		}
		return som;
			
	}
	
	public double comptetableau ()
    {
		double compte=0;
		for(int i = 0; i < tableau.length; i++){
			for(int j = 0; j < tableau[i].length; j++){
				compte++;
			}
		}
		return compte;
			
	}
	
	public double sommetouttableau(){
	     double som=0;
	     for(int i = 0; i < tableau.length; i++){
				som = som + sommeligne(i);
		  }
		  return som;
		  
	}
		
	public double moyennetableau(){
	    
		  return sommetouttableau()/comptetableau ();
		  
	}
		
	public double maxmatrice() {
		double max= tableau[0][0];
		for(int i = 0; i < tableau.length; i++){
			for(int j = 0; j < tableau[i].length; j++){
				if (max<tableau[i][j]){
					max=tableau[i][j];
			    }
			}
		}
		return max;
    }
    
    
	public boolean verifierelement(double x) {
	
		for(int i = 0; i < tableau.length; i++){
			for(int j = 0; j < tableau[i].length; j++){
				if (x == tableau[i][j])
					return true;
			}

    }
    return false;
    }
    
     
	//main
	public static void main(String args[]){
		double [][] tab = {{7,3,15},{1,2},{55},{4,8,9}};
        Matrice A = new Matrice (tab);
        A.afficheMatrice ();
        
        double k = A.sommeligne(2);
        System.out.println("la somme de " + k);
        double s = A.sommetouttableau();
        System.out.println("la somme de toute la matrice " + s);
        double m = A.moyennetableau();
        System.out.println("la moyenne de la matrice " + m);
        double max = A.maxmatrice();
        System.out.println("le maximum de la matrice " + max);
        
        
        System.out.println(A.verifierelement(55));
	}
	
} 

class Complexe {
	private double x;
	private double y;
	
	public Complexe (double x1,double y1)
	{
		x=x1;
		y=y1;	
	}
	
	public Complexe ()
	{
		x=Math.random()*(100-1)+1;
		y=Math.random()*(100-1)+1;	
	}
	
	public Complexe (boolean t)   
	{
		this.x=3;
		this.y=5;	
	}
	
	public void affichealgebrique()
	{
		System.out.println(x + " " + "+" + " " + "i" + y);
		
	}
	
	public Complexe conjugue()
	{
		Complexe z = new Complexe(x,y);
		z.y = -1*z.y;
		return z;
	}

    public void sommecomplexe(Complexe z)
	{
		this.x += z.x;
		this.y += z.y;
	
	}

    public boolean comparecomplexe(Complexe z)
	{   
		if (this.x == z.x & this.y == z.y)
		{
			return true; 
		}
		return false;
	
	}
    
    public double getX()
	{
		return this.x;
	}
	
	public double getY()
	{
		return this.y;
	}

//main
	public static void main(String args[]){
		
		Complexe C = new Complexe(2,6);
		C.affichealgebrique();
		Complexe CZ = new Complexe();
		CZ.affichealgebrique();
		
		Complexe Z=C.conjugue();
		Z.affichealgebrique();
		
		C.sommecomplexe(Z);
		C.affichealgebrique();
		
		System.out.println(C.comparecomplexe(Z));
	}
	
} 


class TableauComplexe {
	Complexe t[];
	
	public TableauComplexe (int l) 
	{
		t= new Complexe[l];
		for(int i = 0; i < l; i++){
			t[i]=new Complexe();
		}
    }
    
    public void affichetableaucomplexe() {
	
		for(int i = 0; i < t.length; i++){
			t[i].affichealgebrique();
		}
    }

    public boolean verifiercomplexetab(Complexe C) {
	
		for(int i = 0; i < t.length; i++){
			if ( t[i].getX() == C.getX() & t[i].getY() == C.getY())
		    {
			return true; 
		    }
		}
		return false;
    }


    public void echangecomplexe(int n, int m) {
		Complexe C;
		for(int i = 0; i < t.length; i++){
			if (i==n )
			{
				C=this.t[n];
				this.t[n]=this.t[m];
				this.t[m]=C;
			}
		}
    }

    public void supprimercomplexe(int n) {
		int l=this.t.length;
		for(int i = 0; i < t.length; i++)
		{
			if (i==n )
			{
				for(int j=i+1; j<t.length; j++)
				{
				t[j-1]=t[j];
			    }
			    
			}
			//diminue le length
			
		}	
    }
    
    public void ajoutercomplexe(Complexe C) {
		int l= this.t.length;
		Complexe tab[] = new Complexe[l+1];
		for(int i = 0; i < t.length; i++)
		{
				tab[i]=this.t[i];   	
		}	
		tab[this.t.length]=C;
    }
    
	//main
	public static void main(String args[]){
        TableauComplexe A = new TableauComplexe (10);
        Complexe C =  new Complexe(2,6);
        
        A.affichetableaucomplexe();
        A.ajoutercomplexe(C);
        System.out.println("ajouter");
        A.affichetableaucomplexe();
        A.supprimercomplexe(4);
        System.out.println("ajouter");
        A.affichetableaucomplexe();
	}
	
} 
class Recette
{
	public String nom;
	public int numero;
	public String [] ingredients;
	public int [] proportions;
	static int nbrecettes=0;
	
	public Recette (String nomrecette, String[] tabingredients, int [] tabproportions)
	{
		this.nom=nomrecette;
		this.ingredients=tabingredients;
		this.proportions=tabproportions;
		this.nbrecettes++;
		this.numero=this.nbrecettes;
	
    }
    
    public void afficherecette()
    {
		 System.out.println("Recette" +" " +nom +" " + "numero" +" " +numero);
		 for(int i = 0; i < nbrecettes; i++)
		 {
			System.out.println(ingredients[i] + " " + proportions[i]);
		 }
    }
    
	public void ajouterecette(String nomingredient, int proportioningrediant)
    {
		
		String tab1[] = new String[nbrecettes+1];
		int tab2[] = new int[nbrecettes+1];
		for(int i = 0; i < nbrecettes; i++)
		{
				tab1[i]=this.ingredients[i];   	
				tab2[i]=this.proportions[i];  
		}	
		tab1[nbrecettes]=nomingredient;
		tab2[nbrecettes]=proportioningrediant;
		
		String ingredients[] = new String[tab1.length];
		int proportions[] = new int[tab2.length];
		for(int i = 0; i < tab1.length; i++)
		{
				ingredients[i]=tab1[i];   	
				proportions[i]=tab2[i];  
		}
    }
    
    ajoutPlat(r1);
}
    
	main
	public static void main(String args[])
	{
       
	}
	
} 

class Etudiant
{
	/** Attributs */
	String nom;
	String prenom;
	int numero; // numero de l’etudiant
	static int nbretucrees=0; // nombre d’etudiants crees
	String [] courssuivis; // tableau contenant les cours suivis
	int notes[]; // tableau des notes pour chaque cours suivis.
	
	
	
	public Etudiant (String nom, String prenom, String [] cours)
	{
			this.nom=nom;
			this.prenom=prenom;
			this.courssuivis = cours;
			
			this.numero=nbretucrees+1;
			this.nbretucrees=nbretucrees+1;
			
			notes = new int [courssuivis.length];
			for (int i=0; i<courssuivis.length;i++)
			{
				this.notes[i]=0;
			}	
	}
	public Etudiant (Etudiant Etu)
	{
			
		this.nom=Etu.nom;
		this.prenom=Etu.prenom;
			
		courssuivis = new String [Etu.courssuivis.length];
		for (int i=0; i<courssuivis.length;i++)
		{
			this.courssuivis[i]=Etu.courssuivis[i];
		}
			
		this.numero=Etu.numero;
			
		notes = new int [courssuivis.length];
		for (int i=0; i<courssuivis.length;i++)
		{
			this.notes[i]=Etu.notes[i];
		}
					
	}
			
	public boolean compare (Etudiant Etu)
	{
		if (this.nom == Etu.nom && this.prenom == Etu.prenom)
		{
			return true;
		}
		return false;
	}
			
			
	public void affiche()
	{
			
		System.out.println("Etudiant N°: " +numero);
		System.out.println("Nom: " +nom);
    	System.out.println("Prénom: " +prenom);
			
		for(int i=0;i<courssuivis.length;i++)
		{	
		 System.out.println("Module: " +courssuivis[i] +" " +"et la Note: " +notes[i]);
		}		
	}
			
		public static void main(String args[])
		
        {
			
			String modules[] = {"UML","JAVA","C"}; 
			
			Etudiant etu = new Etudiant ("MAJDOUB", "Abdelkarim",modules);
			etu.affiche();
			
			Etudiant etu1 = new Etudiant ("Deheuvels", "Marine",modules);
			etu1.affiche();
			
			System.out.println("les deux étudiants  sont identiques ? " +etu1.compare(etu));
			
			
			Etudiant copie = new Etudiant(etu1);
			copie.affiche();
			
			System.out.println("l'étudiant est identique a sa copie ? " +copie.compare(etu1));
			
		}
			
			
			
}


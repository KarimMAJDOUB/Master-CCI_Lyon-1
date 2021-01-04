/* #################################################################################################################################################################################
                                                                          TP 01 : Classes et M´ethodes
####################################################################################################################################################################################*/
class bonjour  {
	public void affiche(String name){
		System.out.println("bonjour" + name);
	}
	public static void main(String args[]) {
		bonjour x=new bonjour();
		x.affiche("MAJDOUB");
	}
}

class Point {
	double x, y;
	public Point (double x, double y)
	{
		this.x=x;
		this.y=y;
	}
	/*
	public void initialise(double ptx, double pty)
	{
		x=ptx;
		y=pty;
	}
	*/
	public void deplace(double dx, double dy)
	{
		x=dx;
		y=dy;
	}
	public void affiche (Point pt)
	{
		System.out.println("x = " + pt.x + " et y = " + pt.y);
	}
}


class TestPoint{
	public static void main (String[] args) {
		Point pt=new Point(0,0);
		Point2 pt2=new Point2();
		pt.affiche(pt);
		pt2.affiche();
		Point2 pt3=new Point2(pt);
		pt3.affiche();
		pt3.translation(5,10);
		pt3.affiche();
		pt3.set_abscisse(0);
		pt3.get_ordonnee();
		pt3.affiche();
		//pt.deplace(0.7,1.4);
		//pt.affiche(pt);
	}
}

class Point2 {
	double x, y;
	public Point2 (double x, double y)
	{
		this.x=x;
		this.y=y;
	}
	public Point2 (Point pt)
	{
		this.x=pt.x;
		this.y=pt.y;
	}
	public Point2 ()
	{
		x=1;
		y=2;
	}
	public void affiche ()
	{
		System.out.println("x = " + x + " et y = " + y);
	}
	public void translation(double dx, double dy)
	{
		x+=dx;
		y+=dy;
	}
	public void set_abscisse(double x)
	{
		this.x=x;
	}
	public double get_ordonnee()
	{
		return (y);
	}
}

class CalcTableau {
	double tableau[];
	CalcTableau(int n) {
		tableau = new double [n];
		for (int i=0; i<tableau.length ; i++)
		{
			tableau[i] = i;
		}
	}
	public double somme()
	{
		double s=0;
		for (int i=0 ; i<tableau.length ; i++)
			s+=tableau[i];
		return s;
	}
	public void increment(double n)
	{
		for (int i=0 ; i<tableau.length ; i++)
			tableau[i]+=n;
	}
	public void affichage()
	{
		for (int i=0 ; i<tableau.length ; i++)
			System.out.print(tableau[i] + " ");
		System.out.print("\n");
	}
}


class TstCalcTableau {
	public static void main (String[] args) {
	CalcTableau T = new CalcTableau(10); 
	T.affichage();
	System.out.println(T.somme());
	T.increment(10);
	T.affichage();
	}
}

class Moyenne {
	double t[];
	
	Moyenne (String mytab[])
	{
		t=new double [mytab.length];
		for (int i=0 ; i<t.length ; i++)
		{
			t[i] = Double.parseDouble(mytab[i]);
		}
	}
	public void affichage ()
	{
		for (int i=0 ; i<t.length ; i++)
		{
			System.out.print(t[i] + "\t");
		}
		System.out.print("\n");
	}
	public double somme ()
	{
		
		double somme=0;
		for (int i=0 ; i<t.length ; i++)
		{
			somme+=t[i];
		}
		return somme;
	}
	public double moyenne ()
	{
		return (somme()/t.length);
	}
	
	public static void main (String[] args) 
	{
		String mytab[] = {"0","1","2","3","4","5","6","7","8","9"};
		Moyenne M = new Moyenne(mytab);
		M.affichage();
		System.out.println(M.somme());
		System.out.println(M.moyenne());
		
	}
}





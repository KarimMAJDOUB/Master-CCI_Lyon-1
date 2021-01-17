class Voiture
{
	public String marque;
	public int nbchevaux;
	public String [] options;

	public Voiture(String marque, int nbchevaux, String[] options) 
    {
		this.marque = marque;
		this.nbchevaux = nbchevaux;
		this.options = options;
	}
	
	public void affiche()
	{
		System.out.println("Marque : " + this.marque + ", Nobre de chevaux: " + this.nbchevaux);
		for(int i = 0; i < this.options.length; i++)
		{
			System.out.println(this.options[i] + " ");
		}
		System.out.println("\n");

	}
	
	public void demarrer()
	{
		System.out.println("Demarrage OK");
	}
	
}

class VoiturCourse extends Voiture
{
	public boolean aileron;

	public VoiturCourse(String marque, String[] options, boolean aileron) 
    {
		super(marque,250,options);
		this.aileron = aileron;
	}
	
	public void affiche()
	{

		super.affiche();
		if (this.aileron)
		System.out.println("Je suis une voiture de course avec aileron");
		else
		System.out.println("Je suis une voiture de course sans aileron");

	}
	
	public void demarrer()
	{
		super.demarrer();
		System.out.println("Verouuum");
	}
	
}

class Concession 
{
	public Voiture[] stock;
	
	public Concession (Voiture voiture0)
	{
        this.stock= new Voiture[1];
		this.stock[0]=voiture0;
	}

	public void ajouteVoiture (Voiture V)
	{
			
		Voiture temp[] = new Voiture[stock.length+1];
			
			for (int i=0;i<stock.length;i++)
			{
				temp[i] = this.stock[i];
			}
			temp[stock.length]= V;
					
			this.stock = new Voiture[temp.length];
				
			for (int i=0;i<temp.length;i++)
			{
						
				this.stock[i] = temp[i];
			}
	}
			
			
	public void affiche() 
	{
		System.out.println("le stock");
		for (int i=0;i<stock.length;i++)
		{
			System.out.println("La voiture num" + " " +i);
			this.stock[i].affiche();
		}
	}
  public void rechercheoption (String option_recherch)
{
  for(int i=0; i<this.stock.length; i++)
     {
       for (int j=0;j<this.stock[i].options.length;j++)
	   {
         if (stock[i].options[j] == option_recherch)
            {
                  this.stock[i].affiche();
            }
       }
	 }

}

public static void main(String[] args)
{
String[] op1={"ABS", "GPS"};
String[] op2={"ABS", "autoradio", "jantes alu"};
String[] op3={"GPS", "sieges cuir"};
Voiture v1=new Voiture("Audi", 120, op1);
Voiture v2=new Voiture("Peugeot", 80, op2);
VoiturCourse v3=new VoiturCourse("BMW", op3, true);
v1.demarrer();
v3.demarrer();
Concession c=new Concession(v1);
c.ajouteVoiture(v2);
c.ajouteVoiture(v3);
c.affiche();
c.rechercheoption("GPS");
}
}



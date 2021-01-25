import java.util.List;
import java.util.Collections;
import java.util.ArrayList;

class Document 
{

	// CONSTANTE
	final static double PRIX_DE_BASE_PAR_PAGE = 0.20 ; // prix en EUR

	// ATTRIBUT DE CLASSE
	static int dernierNumeroDordre = 1000; // J'ai décidé de commencer à partir de 1000 parce que j'en avais envie :-)

	// ATTRIBUTS D'INSTANCE
	int numeroDordre;
	int nombreDePage;
	String titre ;
	char prefixe = '_'; // L, V ou M (avec pour valeur par défaut "_")
	boolean empruntable = true ; // par defaut un document est empruntable


	Document(String titre, int nombreDePage) 
	{
		this.dernierNumeroDordre++;
		this.numeroDordre = dernierNumeroDordre;
		this.titre = titre;
		this.nombreDePage = nombreDePage;
	}
	
	public String numOrdre() 
	{
		return String.valueOf(numeroDordre);
	}

	public double valeur() 
	{
		switch(this.prefixe)
		{
			case 'L': return PRIX_DE_BASE_PAR_PAGE * nombreDePage;
			case 'V': return PRIX_DE_BASE_PAR_PAGE * 2 * nombreDePage;
			case 'M': return PRIX_DE_BASE_PAR_PAGE * 0.5 * nombreDePage;
			default:  return PRIX_DE_BASE_PAR_PAGE * nombreDePage;
		}
	}

	public boolean estEmpruntable()
	{
		return empruntable;
	}

	public void setPrefixe(char prefixe) 
	{
		this.prefixe = prefixe;
	}

	public String toString()  // renvoi l'identifiant 
	{ 
		return prefixe + numOrdre();
	}
}

// === LIVRE =================================================================

class Livre extends Document 
{

	String auteur;

	Livre(String titre, String auteur, int nombreDePage) 
	{
		super(titre, nombreDePage);
		this.setPrefixe('L');
		this.auteur = auteur;
	}

	public String toString() 
	{
		return super.toString() + " - " + this.titre + " - par " + this.auteur + " - " + this.nombreDePage;
	}

	public static void main(String [] args) 
	{

		Livre l1 = new Livre("Programmer en Java", "Delannoy", 799);
		System.out.println(l1 + " (" +  l1.valeur()+ " EUR)" );
	}
}

// === VIEUX LIVRE =================================================================

class VieuxLivre extends Livre 
{
	
	int annee;

	VieuxLivre(String titre, String auteur, int nombreDePage, int annee) 
	{
		super(titre, auteur, nombreDePage);
		this.annee = annee;
		this.setPrefixe('V');
	}
	
	public String toString() 
	{
		return super.toString() + " - " + this.titre + " - par " + this.auteur + " - " + this.nombreDePage + " - " + annee;
	}

	public static void main(String [] args) 
	{

		VieuxLivre v1 = new VieuxLivre("La voie royale", "Lenoir", 314, 1862);
		System.out.println(v1 + " (" +  v1.valeur()+ " EUR)" );
	}
}

// === MAGAZINE =================================================================

class Magazine extends Document
 {

	int numero;

	Magazine(String titre, int nombreDePage, int numero) 
	{
		super(titre, nombreDePage);
		this.numero = numero;
		this.setPrefixe('M');
	}
	
	public String toString() 
	{
		return super.toString() + " - " + this.titre + " - " + this.nombreDePage + " pages - No " + numero ;
	}

	public static void main(String [] args)
	{

		Magazine m1 = new Magazine("Pif", 34, 190);
		System.out.println(m1 + " (" +  m1.valeur()+ " EUR)" );
	}

}


// ==================================================================================
// === BIBLIOTHEQUE =================================================================
// ==================================================================================

class Bibliotheque {

	static List<Document> documents;

	public static void affiche() { // Affiche le contenu de la bibliothèque
		for(Document doc : documents) {
			System.out.println(doc);
		}
	}

	public static Document rechercher(int numeroDordre) {

		for(Document doc : documents) {
			if(doc.numeroDordre == numeroDordre) 
				return doc;
		}
		return null;		
	}

	public static void ajouterLivre(String titre, String auteur, int nombreDePages) {
		documents.add(new Livre(titre, auteur, nombreDePages));
	}

	public static void ajouterVieuxLivre() {
		// TODO
	}
	
	public static void ajouterMagazine() {
		// TODO
	}

	public static void main(String [] args) {
	
		documents = new ArrayList<Document>();

		documents.add(new Livre("Programmer en Java", "Delannoy", 799));
		documents.add(new VieuxLivre("La voie royale", "Lenoir", 314, 1862));		
		documents.add(new Magazine("Pif", 34, 190));

		ajouterLivre("Rich Dad, Poor Dad","Kiyosaki", 542);

		affiche();

		Document doc = rechercher(1001);
		if (doc != null) {
			System.out.println(doc);
		} else {
			System.out.println("Document introuvable.");
		}
	}
}







//Exo 1 
/*
public class Bonjour {
	public void affiche(){
		System.out.println("bonjour");
	}
} il manque le main !!
*/


public class Point {
	float x,y;
	
	public void initialise (float x1, float y1) {
		x=x1;
		y=y1;
	} 
	public void deplace (float dx, float dy){
		x=x+dx;
		y=y+dy;
	}
	public void affiche(){
		System.out.println("les coordonnées de point est " + x + y);
		
	}	
	
	
	
	
	public static void main(String args[]){
		Point obj=new Point();
		
		Point p1=new Point();
        Point p2=new Point();
		
		obj.affiche();
		
		
		
		obj.deplace(1,5);
		obj.affiche();
			
			
		obj.deplace(11,10);
		obj.affiche();
			
	}
} 



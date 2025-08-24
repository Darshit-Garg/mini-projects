import java.lang.*;
import java.util.Scanner;

class Cuboid{
	double width;
	double height;
	double breadth;
	
	Cuboid(double width,double height,double breadth){
		this.width = width;
		this.height = height;
		this.breadth = breadth;
	}
	
	double volume(){
		return width*height*breadth;
	}
	
	double TSA(){
		return 2*(width*height + height*breadth + width*breadth);
	}
}

class Area{
	public static void main(String args[]){
		Scanner sn = new Scanner(System.in);
		System.out.print("Enter height: ");
		double height = sn.nextDouble();
		System.out.print("Enter width: ");
		double width = sn.nextDouble();
		System.out.print("Enter breadth: ");
		double breadth = sn.nextDouble();
		Cuboid c = new Cuboid(width,height,breadth);
		System.out.println("Area "+c.TSA());
		System.out.println("Volume "+c.volume());
	}
}
		
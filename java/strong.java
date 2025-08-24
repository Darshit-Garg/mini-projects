import java.util.Scanner;

class strong{
	public static int getfact(int n){
		if( n==0 || n==1 ){
			return 1;
		}
		else{
			return(n*getfact(n-1));
		}
	}
	
	public static void main(String args[]){
		System.out.print("Enter the number: ");
		Scanner sn = new Scanner(System.in);
		int n = sn.nextInt();
		int sum = 0;
		int temp = n;
		int r;
		while(n!=0){
			r=n%10;
			n/=10;
			int fact = getfact(r);
			sum+=fact;
		}
		if(sum==temp){
			System.out.println("Strong number");
		}
		else{
			System.out.println("Not Strong number");
		}
	}
}
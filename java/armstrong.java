import java.util.Scanner;

class armstrong
{
	public static void main(String args[])
	{
		System.out.print("Enter the number: ");
		Scanner sn = new Scanner(System.in);
		int num = sn.nextInt();
		int length = 1;
		int sum = 0;
		int r;
		int temp = num;
		while(temp/10!=0){
			temp = temp/10;
			length++;
		}
		temp = num;
		for(int i = 0; i<length; i++){
			r = num%10;
			num = num/10;
			sum = sum + (int)Math.pow(r,length);
		}
		if(sum==temp){
			System.out.println("Armstrong number");
		}
		else{
			System.out.println("Not Armstrong number");
		}
	}
}
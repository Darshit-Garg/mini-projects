import java.util.*;

class Bank
{
	private double balance;
	private int i = 0;
	private int j = 0;
	double[] Final_Balance;
	double[] count;
	
	Bank(int N, double balance)
	{
		this.balance = balance;
		double[] Final_Balance = new double[N];
		double[] count = new double[N];
	}

	public void read()
	{
		System.out.println(this.balance);
		return;
	}
	public void credit(double n)
	{
		balance+=n;
		count[j++] = n;
		return;
	}
	public void debit(double n)
	{
		balance-=n;
		count[j++] = 0-n;
		return;
	}
	public void abort(int x)
	{
		double temp = count[x-1];
		balance-=temp;
		return;
	}
	public void rollback(int x)
	{
		balance = Final_Balance[x-1];
		return;
	}
	public void commit()
	{
		Final_Balance[i++] = balance;
	}
}

public class Customer
{
	public static void main(String[] args)
	{
		double balance;
		int N;
		String operation;
		
		Scanner sc = new Scanner(System.in);
		balance = sc.nextDouble();
		N = sc.nextInt();
		
		Bank obj = new Bank(N,balance);
				
		for(int i = 0; i < N; i++ )
		{
			operation = sc.nextLine();
			sc.next();
			String[] operations = operation.split(" ");
			
			if(operations[0]=="credit")
			{
				double x = Double.parseDouble(operations[1]);
				obj.credit(x);
			}
			
			else if(operations[0]=="read")
			{
				//double x = Double.parseDouble(operations[1]);
				obj.read();
			}
			
			else if(operations[0]=="debit")
			{
				double x = Double.parseDouble(operations[1]);
				obj.debit(x);
			}
			
			else if(operations[0]=="abort")
			{
				int x = Integer.parseInt(operations[1]);
				obj.abort(x);
			}
			
			else if(operations[0]=="commit")
			{
				obj.commit();
			}
			
			else if(operations[0]=="rollback")
			{
				int x = Integer.parseInt(operations[1]);
				obj.rollback(x);
			}
		}
		
		sc.close();
	}
}
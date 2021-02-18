import java.io.*;
import java.util.*;
class FIFO
{
	public static void main(String args[]) throws IOException
	{
		int fifo[]=new int[3];
		int n;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the number of inputs:");
		n=Integer.parseInt(br.readLine());
		int inp[]=new int[n];
		System.out.println("Enter the inputs:");
		for(int i=0;i<n;i++)
		{
			inp[i]=Integer.parseInt(br.readLine());
		}
		System.out.println("—————");
		for(int i=0;i<3;i++)
		{
			fifo[i]=-1;
		}
		int Hit=0;
		int Fault=0;
		int j=0;
		boolean check;
		for(int i=0;i<n;i++)
		{
			check=false;

			for(int k=0;k<3;k++)
			if(fifo[k]==inp[i])
				{
					check=true;
					Hit=Hit+1;
				}
			if(check==false)
				{
					fifo[j]=inp[i];
					j++;
					if(j>=3)
					{
						j=0;
					}
					Fault=Fault+1;
				}

		}
		System.out.println("HIT:"+Hit+"FAULT:"+Fault);
	}
}
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution 
{

    public static void main(String[] args) 
    {
        Scanner in=new Scanner(System.in);
       long n=in.nextLong();
            long  digits=SUM1(n);
       
          long  factors=SUM2(n);
       
            if(digits==factors)
                System.out.print("1");
            else
              System.out.print("0");  
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
    
    public static long SUM1(long n)
        {
        long s=0;
        while(n!=0)
            {
            long rem=n%10;
             s=s+rem;
           long  num=n/10;
            n=num;
        }
        return s;
            }
    public static long SUM2(long n)
        {
        long add=0;
        while(n%2==0)
            {
             add=add+2;
            n=n/2;
        }
        for(long j=3;j<=Math.sqrt(n);j=j+2)
            {
            while(n%j==0)
                {
                if(j>=10)
                    {
                      long  p=j;
                    while(p!=0)
                  {
                    long r=p%10;
                    add=add+r;
                    p=p/10;
                    }}
                else
                {
                  add=add+j;
                }
         n=n/j;
            }
        }
        if(n>1)
            {
            while(n!=0)
                {
            long r=n%10;
            add=add+r;
            n=n/10;
            }
            
        }
        return add;
    }
    }

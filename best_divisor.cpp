#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int factors[50000];
    int sum_factors[50000];
    int i;
    int count=0;
    for(i=1; i<=n/2; i++)
    {
        if(n%i==0)
        {
            factors[count]=i;
            //cout<<factors[count];
            count++;
           // cout<<count;
        }
        
    }
    factors[count]=n;
    //cout<<count;
    int temp[count];

    int max_sum=1;
    for(int j=0; j<=count; j++)
    {
        temp[j]=factors[j];
        do 
        {
            sum_factors[j]+=(factors[j]%10);
            factors[j]/=10;
            if(factors[j]/10<1)
            sum_factors[j]+=(factors[j]%10);

            //cout<<sum_factors[j];
        }
        while(factors[j]/10!=0);

        if(sum_factors[j]>max_sum)
        max_sum=sum_factors[j];
    }
    //cout<<max_sum;
    //for(int b=0; b<=count; b++)
    //{
    //cout<<temp[count];
    //}*/

    int fact[10000];
    int flag=0;
    
    for(int k=0; k<=count; k++)
    {
        if(sum_factors[k]==max_sum)
        {
            fact[flag]=temp[k];
            //cout<<fact[flag];
            flag++;
            //cout<<flag;
        }
        
    }
    int best;
    int min;
    for(int q=0; q<flag; q++)
    {
        min=q;
        //cout<<best;
        for(int t=q+1; t<flag; t++)
        {
            if(fact[t]<fact[min])
            min=t;
        }
        int faltu;
        faltu=fact[min];
        fact[min]=fact[q];
        fact[q]=faltu;

    }
    best=fact[0];
    cout<<best;


    return 0;
}

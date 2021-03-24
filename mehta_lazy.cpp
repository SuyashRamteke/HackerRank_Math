


#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    long long int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long int i,j,k,l,m,n,o,p,t;
    long long int b[10001];
    
    cin>>t;
    while(t--)
    {
        cin>>n;
        l=0;
        j=sqrt(n);
        k=0;m=0;
        for(i=1;i<=(j);i++)
        {
           if(n%i==0)
           {
               b[l++]=i;
               k++;
               if((n/i)!=i&&i!=1)
               {
               k++;
               b[l++]=n/i;
               }
           }
        }
        sort(b,b+l);
        for(j=0;j<l;j++)
        {
            if(b[j]%2==0)
            {
                if(sqrt(b[j])==ceil(sqrt(b[j])))
                m++;
            }
        }
        
        if(m==0)
        cout<<0<<endl;
        else 
        {
            o=gcd(m,k);
            m=m/o;
            k=k/o;
           cout<<m<<"/"<<k<<endl;
        }
    }
    return 0;
}
/* 0
0 2 / 19 0 1 / 31 0 0 0 0 0 0 0 0 0 0 1 / 31 4 / 35 1 / 11 1 / 23 0*/



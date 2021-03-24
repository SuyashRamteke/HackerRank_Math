#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Complete the solve function below.
int power(double p)
{
double loga = log2(p);


long long int op = int(loga);

int ans;

if(op==0)
return 2;

if(op==1)
ans = 4;
else 
ans = 6;

//cout<<ans;
return ans;
}

int power4(long long int p)
{
int ans;

if(p==0)
return 1;

if(p%2==1)
ans = 4;
else 
ans = 6;

//cout<<ans;
return ans;
}


int solve(long long int n) {

long long int S2=0;
int ans;
int S = (power4(n+1)-1)*(7);
int S1 = (S)%10;

//S1=S1%10;
//cout<<S<<" ";
int i=0;
double a=1;

while(a<=n)
{   
    
    S2=S2+(power(a))%10;
    S2=S2%10;
    
    cout<<S2<<" "<<S1;
    
    i++;
    a=pow(2,i);
}

/*if(sum==7)
return 6;
else if(sum==9)
return 4;
else if(sum==3)
return 2;
else if((sum==5)&&(n%2==1))
return 0;
else 
return 8;*/

ans=(S1*S2)%10;

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long long int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Complete the solve function below.
long long int fast(int n)
{
    long long int c = 1000000007;

    long long int prod;
    if(n==1)
    return 2;

    if(n%2==1)
    prod = 2*fast(n-1);

    else
    prod = ((fast(n/2)%c)*(fast(n/2)%c))%c;

    return prod;
}

long long int solve(long long int n) {

    long long int c = 1000000007;
if(n==0)
return 4;

if(n==1)
return 6;

long long int ans; 


//long long int i;

/*for(i=1; i<=n; i++)
{
    prod=((prod%c)*(2%c))%c;
}*/

ans=4+(2*(fast(n)-1));

return ans%c;

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

        long long int result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

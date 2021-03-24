#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;

// Complete the solve function below.
string solve(long int n) {

long double prod=2*n;
double root = pow(prod, 0.5);
int div = floor(root);


long int i=1;
string ans;
/*while(sum<=n)
{
    sum=sum+i;
    i++;
}*/
string num = to_string(div);

if(n==2)
ans = "Better Luck Next Time";

if(n==1)
ans = ans = "Go On Bob 1";  

if((prod/div==(div+1))&&(n>2))
ans = "Go On Bob "+num;
else
ans= "Better Luck Next Time";

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

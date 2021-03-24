#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Complete the solve function below.
long long int solve(long long int x) {

long double count=cbrt(3*x);
long long int gin = floor(count);

long long int sum = gin*(gin+1)*(2*gin+1)/6;

while(sum>x)
{
    gin--;
    sum = gin*(gin+1)*(2*gin+1)/6;
}

return gin; 



/*long long int i = 1; 
long double sum = 0;
 while(sum<=x)
 {
     sum = i*(i+1)*(2*i+1)/6;
     count++;
     i++;
 }
if(sum==i)
return (count);
else
return (count-1);
*/

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long long int x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long long int result = solve(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

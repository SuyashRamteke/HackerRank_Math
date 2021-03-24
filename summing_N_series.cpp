#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
 * Complete the summingSeries function below.
 */
int summingSeries(long n) {
    /*
     * Write your code here.
     */
long p = pow(10,9)+7;
long S = ((n%p)*(n%p))%p;


return S;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = summingSeries(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
 


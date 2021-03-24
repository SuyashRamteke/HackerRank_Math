#include <bits/stdc++.h>
#include<math.h>
using namespace std;

/*
 * Complete the lights function below.
 */
int lights(int n) {
    /*
     * Write your code here.
     */
     int p=pow(10,5);
     int ans=1;

     for(int i=1; i<=n; i++)
     {
         ans=ans*2;
         ans=ans%p;
     }
     return ans-1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = lights(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

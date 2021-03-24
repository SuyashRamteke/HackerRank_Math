
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
const long long int g=1000000007;

vector<string> split_string(string);

// Complete the solve function below.

long long int factorial(long long int a)
{   
    long long int ans;
    if(a==0)
    return 1;
    ans = (a%g)*((factorial(a-1))%g)%g;
    
    return ans;
}

/*long long int fastexp(long long int c,long long int d)
{
     long long int ret=1;
    long long int b=c;
    while(d)
    {
        if(d&1)
        ret=(ret*b)%g;  //if(n==odd)    
        b=(b*b)%g;        
        d>>=1;             // n/=2
    }
    return (long long int)ret;
}*/
long long int power(long long int x, long long int y, long long int m) 
{ 
    if (y == 0) 
        return 1; 
    if (y==1)
        return x;

    long long int p = power(x, y/2, m) % m; 
    p = ((p%m)*(p%m)) % m; 
  
    return (y%2 == 0)? p : ((x%m)*(p%m)) % m; 
} 



long long int solve(long long int n, long long int m) {
    
   /* long int num=factorial(m+n-2);
    long int den=factorial(m-1)*factorial(n-1);
    int ans = num/den;*/
    
    //long int g=pow(10,9)+7;
    long long int num, den;
    long long int ans;
    
    num=factorial(m+n-2);
    den=power((factorial(m-1)*factorial(n-1)), g-2, g);
    
    ans=((num)*(den));
    
    //if(ans>g)
    //return (ans%g);
    //else
    return ans%g;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        long long int n = stoll(nm[0]);

        long long int m = stoll(nm[1]);

        long long int result = solve(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

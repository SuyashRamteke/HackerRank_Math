#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

// Complete the solve function below.
string solve(string n) {

int len = n.length();
string ans;
string s;

if(len==1)
{
    if(n=="8")
    return "YES";
}

int i=0;
if(len>=3)
{   
    while(i<=len-2)
    {
    s = n.substr(i,3); 
    int r0 = stoi(s);
    string a = s.substr(0,1);
    string b = s.substr(1,1);
    string c = s.substr(2,1);

    string p1 = b+a+c;
    int r1 = std::stoi(p1);
    string p2 = b+c+a;
    int r2 = std::stoi(p2);
    string p3 = a+c+b;
    int r3 = std::stoi(p3);
    string p4 = c+b+a;
    int r4 = std::stoi(p4);
    string p5 = c+a+b;
    int r5 = std::stoi(p5);
    
    if((r0%8==0)||(r1%8==0)||(r2%8==0)||(r3%8==0)||(r4%8==0)||(r5%8==0))
    {
        ans = "YES";
        break;
    }
    else
    ans = "NO";

    i++;
    }
}

else
{   
    string a = n.substr(0,1);
    string b = n.substr(1,1);

    string q1 = a+b;
    int t1 = std::stoi(q1);
    string q2 = b+a;
    int t2 = std::stoi(q2); 

    if((t1%8==0)||(t2%8==0))
    ans = "YES";
    else
    ans = "NO";
}

return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n;
        getline(cin, n);

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

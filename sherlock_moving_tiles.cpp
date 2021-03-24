#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>
using namespace std;

vector<string> split_string(string);

/*
 * Complete the movingTiles function below.
 */

double root(double n)
{
    double ans;
    ans=pow(n,0.5000000);

    return ans;
}

vector<long double> movingTiles(long int l, long int s1, long int s2, vector<long double> queries) {
    /*
     * Write your code here.
     */
    

     long int i = 0;
     //double temp = 10;
     long int tot = (queries.size());
     vector<long double> times(tot);
     double val=sqrt(2);
     //cout<<val;

     for (i=0;i<=tot-1;i++)
     {
         double r = root(queries[i]);
         
        if((s2>s1))
            times[i]=(val*(l-r)/(s2-s1));
        else if((s1>s2))
            {
                times[i]=(val*(l-(sqrtl(queries[i])))/(s1-s2));
                //cout<<fixed<<setprecision(7)<<std::pow(queries[i],0.5);
            }
        else 
            times[i]=0;
     //times[i]= temp;
     }
     return times;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lS1S2_temp;
    getline(cin, lS1S2_temp);

    vector<string> lS1S2 = split_string(lS1S2_temp);

    long int l = std::stol(lS1S2[0]);

    long int s1 = std::stol(lS1S2[1]);

    long int s2 = std::stol(lS1S2[2]);

    long int queries_count;
    cin >> queries_count;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long double> queries(queries_count);

    for (long int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        long double queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<long double> result = movingTiles(l, s1, s2, queries);

    for (long int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout <<fixed<<setprecision(50)<<result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    //sort(a.begin(),a.end());
    long long max=*max_element(a.begin(),a.end());
    long long count=0;
    for(int i=1;i<=max;i++)
        {
         count=0;
         for(int j=0;j<n;j++)
             {
              if(a[j]%i!=0)
                  count++;
              if(count>1)
                  break;
             }
         if(count==1)
             {
              cout<<i<<endl;
              break;
             }
        }
    return 0;
}

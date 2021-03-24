#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int t=0;
    cin>>t;
    int count=0;
    
if(t<15)
    while(count<t)
        {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            int x3=(2*x2)-x1;
            int y3=(2*y2)-y1;
        if((x1, x2, y1, y2<100)&&(x1, x2, y1, y2>-100))
        {
            cout<<x3<<" "<<y3;
            cout<<endl;
            
        }
        count++;    
    }
    return 0;
}

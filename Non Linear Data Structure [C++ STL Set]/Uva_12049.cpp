/**
    @author Reza
    Samsung Research, Bangladesh
    @email rakib08cse@gmail.com
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

typedef long long ll;
typedef long l;
typedef vector<string> vs;

int main()
{
    //freopen("input.txt","r",stdin);

    ll n,m,x,TC,cnt;
    cin >> TC;

    while(TC--)
    {
        multiset<ll>MS;
        cnt=0; // Trace the no. of common value //
        cin >> n >> m;
        for(ll i=0; i<n; i++)
        {
            cin >> x;
            MS.insert(x);
        }

        for(ll i=0; i<m; i++)
        {
            cin >> x;
            multiset<ll>::iterator it = MS.find(x);
            if(it!=MS.end())
            {
                MS.erase(it);
                cnt++;
            }
        }

        //for (multiset<ll>::iterator it=MS.begin(); it!=MS.end(); ++it)
        cout << (n+m)-(2*cnt) << "\n";

    }

    return 0;
}

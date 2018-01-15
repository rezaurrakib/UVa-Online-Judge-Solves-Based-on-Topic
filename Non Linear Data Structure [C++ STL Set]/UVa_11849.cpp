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

using namespace std;

typedef long long ll;
typedef long l;
typedef vector<string> vs;

int main()
{

    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n, m, x;

    while(cin >> n >> m)
    {
        if(n==0 && m==0) break;
        map<ll,ll> data;
        ll cnt=0;
        for(ll i=0; i<n; i++)
        {
            cin >>  x;
            data[x]++;
        }

        for(ll i=0; i<m; i++)
        {
            cin >> x;
            if(data[x]==1)
                cnt++;
        }

        cout << cnt << "\n";

    }
    return 0;
}

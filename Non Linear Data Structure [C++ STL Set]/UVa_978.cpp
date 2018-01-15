/**
    @author Reza
    Samsung Research, Bangladesh
    @email rakib08cse@gmail.com
*/

#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>

using namespace std;

typedef long long ll;


#define MAX 1000
#define READ(filename) freopen(filename,"r",stdin)
#define OUTPUT(filename) freopen(filename,"w",stdout)


/*void print(multiset<ll,greater<ll> > Data)
{
    for(multiset<ll>::iterator it=Data.begin(); it!=Data.end(); it++)
        cout << *it<< " -> ";

}*/

int main()
{
    //READ("input.txt");
    //OUTPUT("output.txt");

    bool sp=false;
    ll TC,Battle,G,B,a;
    cin >> TC;

    while(TC--)
    {
        if(sp) cout << "\n";
        else sp=true;

        cin >> Battle >> G >> B;
        multiset<ll,greater<ll> > SGreen; // Descending order
        multiset<ll,greater<ll> > SBlue;


        for(ll i=0; i<G; i++)
        {
            cin >> a;
            SGreen.insert(a);
        }
        //print(SGreen);

        for(ll i=0; i<B; i++)
        {
            cin >> a;
            SBlue.insert(a);
        }

        //cout << "Trace : " << mBattle << "\n";

        while(!SBlue.empty() && !SGreen.empty())
        {

            vector<ll> tempGreen;
            vector<ll> tempBlue;

            ll mBattle = min(SBlue.size(),SGreen.size());
            mBattle = min(mBattle,Battle);

            for(ll i=0; i<mBattle; i++)
            {
                ll gData = *(SGreen.begin());
                ll bData = *(SBlue.begin());

                if(gData>bData)tempGreen.push_back(gData-bData);
                else if(bData>gData) tempBlue.push_back(bData-gData);

                SBlue.erase(SBlue.begin());
                SGreen.erase(SGreen.begin());
            }

            for(ll i =0; i<tempGreen.size(); i++) SGreen.insert(tempGreen[i]);
            for(ll i =0; i<tempBlue.size(); i++) SBlue.insert(tempBlue[i]);

        }

        if(SBlue.empty() && SGreen.empty())
            cout << "green and blue died\n";

        else if(SBlue.empty())
        {
            cout << "green wins\n";

            while(!SGreen.empty())
            {
                cout << *(SGreen.begin()) << "\n";
                SGreen.erase(SGreen.begin());
            }
        }

        else if(SGreen.empty())
        {
            cout << "blue wins\n";

            while(!SBlue.empty())
            {
                cout << *(SBlue.begin()) << "\n";
                SBlue.erase(SBlue.begin());
            }
        }

    }

    return 0;
}

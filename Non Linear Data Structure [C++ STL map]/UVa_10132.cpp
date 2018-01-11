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


bool solFound(string bitPattern, vector<string> Frgmnts)
{
    //cout << "Trace : bitPattern = " << bitPattern << "\n";
    ll fullFrg=0;

    for(ll i=0; i<Frgmnts.size(); i++)
        for(ll j=i+1; j<Frgmnts.size() && Frgmnts[i]!="#"; j++)
        {
            if((Frgmnts[i]+Frgmnts[j])==bitPattern || (Frgmnts[j]+Frgmnts[i])==bitPattern)
            {
                //cout << "Trace : Frgmnts[i]+Frgmnts[j] = " << Frgmnts[i]+Frgmnts[j] << "\n";
                Frgmnts[i]="#";
                Frgmnts[j]="#";
                fullFrg++;
                break; // The ith string is already assigned, so no need to check
            }
        }

    if(fullFrg==Frgmnts.size()/2) return true;
    else return false;
}


int main()
{
    //READ("input.txt");
    //OUTPUT("output.txt");


    ll TC,noFrg,bitSum;
    bool sp=false;
    cin >> TC;
    getchar();
    getchar();

    while(TC--)
    {
        //getchar();
        if(sp) cout << "\n";
        else sp=true;

        noFrg=0,bitSum=0;
        vector<string> Frgmnts;
        string str;

        while(getline(cin,str) && !str.empty()) // It works for an extra blank
        {
            noFrg++;
            Frgmnts.push_back(str);
            bitSum+=str.length();
        }
        ll actualFrgmnts = (bitSum*2)/noFrg;
        //cout << "Trace : actualFrgmnts = " << actualFrgmnts << "\n";
        string output="";
        bool breakNecessary=false;

        for(ll i=0; i<noFrg; i++)
        {
            for(ll j=i+1; j<noFrg; j++)
            {
                if((Frgmnts[i]+Frgmnts[j]).length()==actualFrgmnts)
                {
                    if(solFound(Frgmnts[i]+Frgmnts[j],Frgmnts))
                    {
                        output=Frgmnts[i]+Frgmnts[j];
                        breakNecessary=true;

                    }

                    else if(solFound(Frgmnts[j]+Frgmnts[i],Frgmnts))
                    {
                        output=Frgmnts[j]+Frgmnts[i];
                        breakNecessary=true;
                    }

                }

            }
            if(breakNecessary) break;
        }

        cout << output << "\n";

    }


    return 0;
}

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
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-12

struct MyStruct
{
    string time;
    string state;
    ll location;

    bool operator < (const MyStruct &other)
    {
        return time < other.time;
    }
} obj;

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");

    ll TC;

    cin >> TC;

    bool sp = false;

    while (TC--)
    {
        if(sp) cout << "\n";
        else sp=true;

        ll TollCount[25];
        for(ll i=0; i<24; i++)
            cin >> TollCount[i];

        string str;
        map<string,vector<MyStruct> > Data;

        getchar();

        while(getline(cin,str) && !str.empty())
        {
            string time,name,state;
            ll location;

            stringstream ss(str);

            ss >> name >> time >> state >> location;
            //cout << name << " -> "  << time << " -> " << state << " -> " << location << "\n";

            obj.time=time;
            obj.location = location;
            obj.state = state;

            Data[name].push_back(obj);

        }

        for(map<string,vector<MyStruct> >::iterator it = Data.begin(); it!=Data.end(); it++)
        {
            double cost=0; // cost calculation in cents

            sort(it->second.begin(),it->second.end());

            for(ll i=1; i<it->second.size(); i++)
            {
                if(it->second[i].state[1]=='x' && it->second[i-1].state[1]!='x') // e(n)ter follows e(x)it ... bracket chars for comparison //
                {
                    ll hour = (it->second[i-1].time[6] - 48) * 10 +  (it->second[i-1].time[7] - 48); // string to ll conversion

                    ll kmTravel = abs(it->second[i].location - it->second[i-1].location);
                    cost += (kmTravel * TollCount[hour]) + 100; // 100 cent(1$) for per trip

                    //cout << "Cost so  far : " << cost << "\n";

                }

            }

            if(cost>0) cout << it->first << " $" << fixed <<  setprecision(2) << (cost/100.0)+2.0 << "\n";

        }

    }

    return 0;
}

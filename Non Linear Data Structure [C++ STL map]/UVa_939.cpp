/**
    @author Reza
    Mobile Solution Group
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
#include <bitset>

using namespace std;

typedef long long ll;

#define MAX 10000000
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)


map<string,string> GeneInfo;
map<string,pair<string,string> > ChildInfo;

void GeneMapping(string a, string b, string child)
{
    //cout << a << " -> " << b << " -> " << child << "\n";

    if(a=="dominant" && b=="dominant")
        GeneInfo[child]="dominant";

    else if(a=="dominant" && b=="recessive")
        GeneInfo[child]="dominant";

    else if(a=="recessive" && b=="dominant")
        GeneInfo[child]="dominant";

    else if(a=="non-existent" && b=="non-existent")
        GeneInfo[child]="non-existent";

    else if(a=="non-existent" && b=="recessive")
        GeneInfo[child]="non-existent";

    else if(b=="non-existent" && a=="recessive")
        GeneInfo[child]="non-existent";

    else GeneInfo[child]="recessive";

}

void checkInfoChild(string a, string b, string child)
{
    if(GeneInfo[a]!="" && GeneInfo[b]!="")
    {
        GeneMapping(GeneInfo[a],GeneInfo[b],child);
        return ;
    }
    else if(GeneInfo[a]=="")
        checkInfoChild(ChildInfo[a].first,ChildInfo[a].second,a); // recursive call
    else if(GeneInfo[b]=="")
        checkInfoChild(ChildInfo[b].first,ChildInfo[b].second,b); // recursive call

    return ;

}

void clear()
{
    GeneInfo.clear();
    ChildInfo.clear();
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");

    ll N;

    //while(cin >> N)
    cin >> N;
    getchar();
    string a,b;

    for(ll i =0; i<N; i++)
    {
        cin >> a >> b;

        if(b=="non-existent" || b=="recessive" || b=="dominant")
            GeneInfo[a]=b;
        else
        {
            if(ChildInfo[b].first=="" && ChildInfo[b].second=="")
                ChildInfo[b].first=a;

            else if(ChildInfo[b].second=="" && ChildInfo[b].first!=a)
                ChildInfo[b].second=a;
        }
    }

    /*
    for(map<string,string>::iterator it = GeneInfo.begin(); it!=GeneInfo.end();  it++)
    	cout << it->first << " " << it->second << "\n";

    cout << "\n\n\n";
    for(map<string,pair<string,string> >::iterator it = ChildInfo.begin(); it!=ChildInfo.end(); it++)
    {
    	cout << it->first << "<=> ( " <<  it->second.first << ", " << it->second.second << " )\n";

    }
    cout << "\n\n\n";
    */

    for(map<string,pair<string,string> >::iterator it = ChildInfo.begin(); it!=ChildInfo.end(); it++)
    {
        while(GeneInfo[it->first]=="")
        {
            checkInfoChild(it->second.first, it->second.second,it->first);
        }

    }

    for(map<string,string>::iterator it = GeneInfo.begin(); it!=GeneInfo.end();  it++)
        cout << it->first << " " << it->second << "\n";

    //clear();
    return 0;
}

/**
    @author Reza
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


bool checkData(string  a, string b)
{
	string tm1="",tm2="";

	for(ll i=0; i<a.length(); i++)
		if(a[i]!=32)
			tm1+=a[i];

	for(ll i=0; i<b.length(); i++)
		if(b[i]!=32)
			tm2+=b[i];

	sort(tm1.begin(),tm1.end());
	sort(tm2.begin(),tm2.end());

	if(tm1==tm2) return true;
	else return false;
}




int main()
{
    //READ("input.txt");
	//WRITE("output.txt");

	ll TC;
	string str;
	bool sp=false;
	cin >> TC;
	getchar();
	getchar();

	while (TC--)
	{
		if(sp) cout << "\n";
		else sp=true;

		vector<string> Data;
		map<string,multiset<string> > MP;

		while (getline(cin,str) && !str.empty())
			Data.push_back(str);

		ll sz = Data.size();

		for(ll i=0; i<sz; i++)
		{
			for(ll j=i+1; j<sz; j++)
			{
				if(checkData(Data[i],Data[j]))
				{
					if(Data[i]<Data[j]) MP[Data[i]].insert(Data[j]);
					else MP[Data[j]].insert(Data[i]);
				}

			}

		}

		for(map<string,multiset<string> >::iterator it = MP.begin(); it!=MP.end(); it++){
			for(multiset<string>::iterator iit=(it->second).begin(); iit!=(it->second).end(); iit++)
				cout << (it->first) << " = " <<  *(iit) << "\n";

		}

	}



    return 0;
}

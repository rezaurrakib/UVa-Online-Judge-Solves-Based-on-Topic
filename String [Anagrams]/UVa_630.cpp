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
#include <sstream>

using namespace std;

typedef long long ll;


#define MAX 1000
#define READ(filename) freopen(filename,"r",stdin)
#define OUTPUT(filename) freopen(filename,"w",stdout)


bool checkAnagrams(string a, string b)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	if(a==b) return true;
	else return false;

}


int main()
{
	//READ("input.txt");
	//OUTPUT("output.txt");

	ll TC,N;

	cin >> TC;
	getchar();
	getchar();

	bool sp=false;

	while(TC--)
	{
		if(sp) cout << "\n";
		else sp=true;

		cin >> N;
		getchar();
		string str;
		vector<string> VS;

		for (ll i=0; i<N; i++)
		{
			cin >> str;
			VS.push_back(str);
		}

		while(cin >> str)
		{
			if(str=="END") break;

			ll n=1;
			bool notFound=true;

			cout << "Anagrams for: " << str << "\n";

			for(ll i=0; i<VS.size(); i++)
			{
				if(checkAnagrams(str,VS[i]))
				{
					cout << right << setw(3) << n++ << ") " << VS[i] << "\n";
					notFound=false;
				}

			}

			if(notFound) cout << "No anagrams for: " << str << "\n";

		}

	}


	return 0;
}

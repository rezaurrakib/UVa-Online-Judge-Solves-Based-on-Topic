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

	set<string> VS;
	string str;

	while(cin >> str)
	{
		if(str=="XXXXXX") break;
		VS.insert(str);
	}


	while(cin >> str)
	{
		if(str=="XXXXXX") break;

		bool notFound=true;

		for(set<string>::iterator it=VS.begin(); it!=VS.end(); it++)
		{
			if(checkAnagrams(str,*it)){
				cout << *it << "\n";
				notFound=false;
			}
		}

		if(notFound) cout << "NOT A VALID WORD\n";
		cout << "******\n";

	}


	return 0;
}

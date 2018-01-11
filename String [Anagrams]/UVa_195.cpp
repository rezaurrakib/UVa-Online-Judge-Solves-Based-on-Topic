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

struct MyStruct
{
	bool operator()(const char &a, const char &b)
	{
		ll diff = (a|32) - (b|32); // letter = letter|32 return the lowercase conversion value of letter //
		if(diff) return  diff<0;
		else return a<b;
	}
}obj;

int main()
{
	//READ("input.txt");
	ll TC;
	string str;
	cin >>TC;
	getchar();

	while(TC--)
	{
		getline(cin,str);
		sort(str.begin(),str.end(),obj);
		cout << str << "\n";
		while(next_permutation(str.begin(), str.end(), obj)){
			cout << str << "\n";
		}

	}

    return 0;
}

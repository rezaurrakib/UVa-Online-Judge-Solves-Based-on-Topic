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


void print(multiset<ll> Data)
{
    for(multiset<ll>::iterator it=Data.begin(); it!=Data.end(); it++)
        cout << *it<< " -> ";

}

int main()
{
	// READ("input.txt");
	// OUTPUT("output.txt");

    ll N,a,num;

    while(cin >> N && N){

        multiset<ll> DataBill;
        ll sum=0;

        for(ll i=0; i<N; i++)
        {
            cin >> a;

            for(ll j=0; j<a; j++){
                cin >> num;
                DataBill.insert(num);
            }
            //cout << "Previous State : ";
            //print(DataBill);
            sum+= (*(DataBill.rbegin())) - (*(DataBill.begin()));
            DataBill.erase(DataBill.begin());
            DataBill.erase(--DataBill.end());
            //cout << "After State : ";
            //print(DataBill);
            //cout << "\n";
        }

        cout << sum << "\n";
    }


	return 0;
}

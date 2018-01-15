/**
    @author Reza
    Samsung Research, Bangladesh
    @email rakib08cse@gmail.com
*/

// 3 TLE ..... :(, you need to check the iterator simultaneously w.r.t check the GET transaction
// If current data is smaller than iterator =, then decrement it //

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



int main()
{
	//READ("input.txt");
	//OUTPUT("output.txt");


    ll TC,N,M,a;
    bool sp=false;
    cin >> TC;

    while(TC--){

        if(sp) cout << "\n";
        else sp=true;

        vector<ll> V;
        multiset<ll> Data;
        multiset<ll>::iterator it;
        cin >> N >> M;

        for(ll i=0; i<N; i++){
            cin >> a;
            V.push_back(a);
        }

        Data.insert(V[0]);
        it=Data.end();
        it--;
        ll index=1;
        bool firstData=false;

        for(ll i=0; i<M; i++){
            cin >> a;

            if(a>Data.size()){

                for(ll j=index; j<a; j++){
                    Data.insert(V[j]);
                    if(*it>V[j]) it--;
                }

                index=a;
            }

            if(firstData==false) firstData=true;
            else it++;
            cout << *it << "\n";

        }


    }


	return 0;
}

/**
    @author Reza
    @email rakib08cse@gmail.com
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    long N;
    string s;
    cin >> N;

    while(N--)
    {
        cin >> s;
        sort(s.begin(),s.end());

        for(int i=0; i<s.length(); i++)
            cout << s[i];
        cout << "\n";

        while(next_permutation(s.begin(),s.end()))
        {
            for(int i=0; i<s.length(); i++)
                cout << s[i];
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}

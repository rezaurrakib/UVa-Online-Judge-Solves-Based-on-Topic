/**
    @author Reza
    Samsung Research, Bangladesh
    @email rakib08cse@gmail.com
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;
typedef long l;
typedef vector<string> vs;

int main()
{
    // freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    string str;
    map<string ,int> data;

    while(getline(cin,str))
    {
        vector<string>vs;

        int (*temp)(int)=tolower;
        transform(str.begin(),str.end(),str.begin(),temp);

        // Conversion from string to char * //
        char *NEW = new char[str.size()+1];
        NEW[str.size()]=0;
        memcpy(NEW,str.c_str(),str.size());

        char *pch = strtok(NEW," ");

        while(pch!=NULL)
        {
            string s(pch);
            //cout << s <<"\n";
            vs.push_back(s);
            pch = strtok(NULL," ");
        }


        for(ll i=0; i<vs.size(); i++)
        {
            string temp="";
            for(ll j=0; j<vs[i].length(); j++)
            {
                if(isalpha(vs[i][j]))
                    temp.push_back(vs[i][j]);

                else
                {
                    data[temp]++;
                    temp="";
                }
            }

            data[temp]++;
        }
    }

    for(map<string,int>:: iterator it=data.begin(); it!=data.end(); it++)
        if(it->first!="")
            cout << it->first << "\n";

    return 0;
}

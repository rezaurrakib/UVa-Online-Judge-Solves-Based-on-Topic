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
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string str,actual="";
    map<string,int> data;
    bool found=false;

    while(getline(cin,str))
    {
        if(found==false) actual += " ";

        if(str[str.length()-1]=='-'){
            for(ll i=0; i<str.length()-1; i++)
                actual += str[i];
            found=true;
        }

        else{
            actual += str;
            found=false;
        }

    }

    // Space Tokenization //

    for(ll i=0; i<actual.size(); i++)
    {
        if(isalpha(actual[i]))
            tolower(actual[i]);
        else if(actual[i]!='-')
            actual[i]=' ';
    }

    vector<string>vs;

    int (*temp)(int)=tolower;
    transform(actual.begin(),actual.end(),actual.begin(),temp);

    // Conversion from string to char * //
    char *NEW = new char[actual.size()+1];
    NEW[actual.size()]=0;
    memcpy(NEW,actual.c_str(),actual.size());

    char *pch = strtok(NEW," ");

    while(pch!=NULL)
    {
        string s(pch);
        //cout << s <<"\n";
        vs.push_back(s);
        pch = strtok(NULL," ");
    }

    for(ll i=0; i<vs.size(); i++)
        data[vs[i]]++;


   for(map<string,int>:: iterator it = data.begin(); it!=data.end(); it++)
        cout << it->first << "\n";

    return 0;
}

/**
    @author Reza
    @email rakib08cse@gmail.com
    Runtime : 0.024sec
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
vector <string> dictionary;
vector <string> ananargram;
vector <string>:: iterator it;

bool Match_Function(string a, string b)
{
    int (*temp)(int)=tolower;

    transform(a.begin(),a.end(),a.begin(),temp);
    sort(a.begin(),a.end());

    transform(b.begin(),b.end(),b.begin(),temp);
    sort(b.begin(),b.end());

    if(a==b)
    return true; // find match //

    else
    return false;

}

int main()
{
    string a;
    int no_words=0,i,j;
    bool match,conditional;

    while(1)
    {
        cin >> a;
        if(a=="#")
        break;
        dictionary.push_back(a);
        no_words++;
    }

    for(i=0; i<no_words; i++)
    {
        match=false;
        conditional=false;

        for(j=i+1; j<no_words; j++)
        {
            if(dictionary[j]=="")
            continue;

            match = Match_Function(dictionary[i],dictionary[j]);

            if(match==true)
            {
                dictionary[j].clear();
                conditional=true;
            }

        }

        if(conditional==true)
        dictionary[i].clear();

        else if(dictionary[i]!="")
        ananargram.push_back(dictionary[i]);

    }

    // lexicographical sort //
    sort(ananargram.begin(),ananargram.end());

    for(it=ananargram.begin(); it!=ananargram.end(); it++)
    cout << *it << "\n";

    return 0;
}

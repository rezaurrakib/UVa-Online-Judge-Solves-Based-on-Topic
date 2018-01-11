/**
    @author Reza
    @email rakib08cse@gmail.com
*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

void index_calculation();

long int r,i,j,k,l,m;
char w[83682][6],inp[7];


void index_calculation()
{

    r=0;
    for(i=0; i<26; i++)
        w[r++][0]='a'+i;


    for(i=0; i<25; i++)               // ab-->a[26,0]b[26,1] //
    {
        for(j=i+1; j<26; j++)
        {
            w[r][0]='a'+i;
            w[r++][1]='a'+j;
        }
    }

    for(i=0; i<24; i++)               // abc-->a[26,0]b[26,1] //
    {
        for(j=i+1; j<25; j++)
        {

            for(k=j+1; k<26; k++)
            {
                w[r][0]='a'+i;
                w[r][1]='a'+j;
                w[r++][2]='a'+k;
            }
        }
    }

    for(i=0; i<23; i++)               // wxyz-->4 columns[17901] //
    {
        for(j=i+1; j<24; j++)
        {

            for(k=j+1; k<25; k++)
            {

                for(l=k+1; l<26; l++)
                {
                    w[r][0]='a'+i;
                    w[r][1]='a'+j;
                    w[r][2]='a'+k;
                    w[r++][3]='a'+l;
                }
            }
        }
    }


    for(i=0; i<22; i++)               // abcde-->5 columns[17902] //
    {
        for(j=i+1; j<23; j++)
        {

            for(k=j+1; k<24; k++)
            {

                for(l=k+1; l<25; l++)
                {
                    for(m=l+1; m<26; m++)
                    {
                        w[r][0]='a'+i;
                        w[r][1]='a'+j;
                        w[r][2]='a'+k;
                        w[r][3]='a'+l;
                        w[r++][4]='a'+m;
                    }


                }
            }
        }
    }

}

int main()
{

    index_calculation();

    while(gets(inp))
    {
        int c=0;
        for(i=0; i<r; i++)
        {
            if(strcmp(inp,w[i])==0)
            {
                cout << i+1 << endl;
                c=1;
            }

        }

        if(c==0)
            cout << "0\n";

    }


    return 0;
}



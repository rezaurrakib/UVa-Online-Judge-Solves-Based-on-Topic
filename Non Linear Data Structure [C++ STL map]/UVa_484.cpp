/**
    @author Reza
    @email rakib08cse@gmail.com
*/

#include"stdio.h"
#define N 10000

int a[N],j,f,l,n,k;
void freq(int a[],int);

int main()
{
    int i=0;

    while(scanf("%d",&n)!=EOF)
    {
        a[i]=n;
        i++;
    }

    freq(a,i);

    return 0;
}

void freq(int a[],int i)
{
    for (j=0; j<i; j++)
    {
        if(j==0)
        {
            f=0;

            for(k=j; k<i; k++)
            {
                if(a[j]==a[k])
                    f++;
            }

            printf("%d %d\n",a[j],f);

        }

        else
        {
            for(l=j-1; l>=0; l--)
            {
                if(a[j]==a[l])
                    break;

                if(l==0)
                {
                    f=0;

                    for(k=j; k<i; k++)
                    {
                        if(a[j]==a[k])
                            f++;
                    }

                    printf("%d %d\n",a[j],f);
                }
            }
        }
    }

}

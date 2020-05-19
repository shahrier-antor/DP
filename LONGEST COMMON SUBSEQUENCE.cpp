#include<bits/stdc++.h>
using namespace std;
void lcs(char *x,char *y,int m,int n)
{
    int L[m+1][n+1];
    // build the dp on the bottom up approach
    for(int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                L[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;

            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    // the following code is to print the lsc
    int idx=L[m][n];
    char lsc[idx+1];
    lsc[idx]='\0';


    int i=m,j=n;

    while(i>0&&j>0)
    {
        // if current charecter of x and y are same the input them
        if(x[i-1]==y[j-1])
        {
            lsc[idx-1]=x[i-1];
            x--;
            y--;
            idx--;

        }
        else if(L[i-1][j]>L[i][j-1])
        {
            i--;
        }
        else
            j--;
    }
    cout<< "LSC IS"<< " "<< lsc<< endl;
}
int main()
{
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    int m=strlen(x);
    int n=strlen(y);
    lcs(x,y,m,n);
}

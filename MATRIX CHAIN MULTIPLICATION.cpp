#include<bits/stdc++.h>
using namespace std;
int tdp[100][100];



// top dowm approach



int matrixchain(int m[],int i,int j)
{
    if(i==j)
    {
        tdp[i][j]=0;
        return 0;
    }
    if(tdp[i][j]!=-1)
    {
        return tdp[i][j];

    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=matrixchain(m,i,k)+matrixchain(m,k+1,j)+ m[i-1]*m[k]*m[j];
        ans=min(ans,temp);
    }
    tdp[i][j]=ans;
    return ans;
}

// bottom up approach
int matrixchainbup(int m[],int n)
{
    int dp[100][100];
    int i,j,k,l;
    // make diagonal element zero
    for(int i=1;i<n;i++)
        dp[i][i]=0;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<=n-l;i++)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<=j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j]);
        }
    }
    return dp[1][n-1];




}



int main()
{
    int matrix[]={1,2,3,4};
    // represents (1,2)(2,3)(3,4);
    int n=sizeof(matrix)/sizeof(int);
    memset(tdp,-1,sizeof tdp);
    cout<<matrixchain(matrix,1,n-1)<< endl;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {
            cout<< tdp[i][j]<< " ";
        }cout<< endl;
    }
    cout<< endl<<endl;
    cout<< "bottom up   "<<  matrixchainbup( matrix, n)<<endl;
    return 0;
}

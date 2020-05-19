#include<bits/stdc++.h>
using namespace std;
// to search the numbers in array with freq.......................................................

// recursive approach.....ektu problem aasee.................
int dp[100][100];
int tdp(int input[],int freq [],int low,int high,int level )
{

    if(low>high)
    {//dp[low][high]=0;
       return 0;}
    if(dp[low][high]!=-1)return dp[low][high];
    int min=INT_MAX;
    for(int i=low;i<=high;i++)
    {
        int val=tdp(input,freq,low,i-1,level+1)+tdp(input,freq,i+1,high,level+1)+level*freq[i];
        if(val<min){
            min=val;
        }
    }
    //return dp[low][high];
  return  min;

}
// bottom up approach................................................................................

int getsum(int freq[],int i,int j)
{
    int sum=0;
    for(int x=i;x<=j;x++)
    {
        sum+=freq[x];
    }
    return sum;
}

int bup(int intput[],int freq[] ,int n)
{
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=freq[i];
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-1;i++)
        {
            int j=l+i-1;
            dp[i][j]=INT_MAX;
            int sum=getsum(freq,i,j);
            for(int k=i;k<=j;k++)
            {
                int val=sum+(k-1<i?0:dp[i][k-1])+(k+1>j?0:dp[k+1][j]);
                if(val<dp[i][j])
                {
                    dp[i][j]=val;
                }
            }

        }
    } return dp[0][n-1];
}


int main()
{
    int input[]={10,12,16,21};
    int freq[]={4,2,6,3};
    int n=sizeof(input)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }


    cout<< tdp(input,freq,0,n-1,1)<< endl;
    cout<< bup(input,freq,n)<<endl;
}



#include<bits/stdc++.h>
using namespace std;
bool subsum(int a[],int n,int sum)
{
    bool subset[n+1][sum+1];
     for(int i=0;i<=n;i++)
     {

             subset[i][0]=true;
     }
      for(int i=1;i<=sum;i++)
     {

             subset[0][i]=false;
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=sum;j++)
         {
             int k =(2*a[i-1]);
             if(j<a[i-1])subset[i][j]=subset[i-1][j];
             if(j>=a[i-1])subset[i][j]=subset[i-1][j]||subset[i-1][j-a[i-1]];
             if(j>=k)subset[i][j]=subset[i-1][j]||subset[i-1][j-a[i-1]]||subset[i-1][j-k];
         }
     }

for(int i=0;i<=n;i++)
{
    for(int j=0;j<=sum;j++)
    {
        cout<<setw(3)<< subset[i][j];
    }cout<< endl;
}
cout<< endl;
}
int main()
{
    int n,sum;
    cin>> n>>sum;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>> a[i];
    }
    int ans=subsum(a,n,sum);
    if(ans)cout<< "yes"<<endl;
}



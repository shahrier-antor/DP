
#include<bits/stdc++.h>
#define mx 100
using namespace std;

int coin[mx];
bool possible[mx];
int main()
{
    int n,k;
    cin>> k>> n;
    for(int i=1;i<=k;i++)
    {
        cin>> coin[i];
    }



    // varient 1....................................................................
   // possible to sum with infinite supply....



   /*  possible[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        if(i>=coin[j])
            possible[i]|=possible[i-coin[j]];
    }
    if(possible[n])
        cout<< "possible "<< endl;
    else
        cout<< "not possible"<< endl;*/



     // varient 2.....................................................................
   // total number of ways to get the sum with infinite supply....



  int way[n+1]={0};
   way[0]=1;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=k;j++)
       {
           if(i>=coin[j])
           way[i]+=way[i-coin[j]];
       }
   }
   for(int i=1;i<=n;i++)
   {
       cout<<way[i]<< " ";
   }cout<< endl;


   //varient 3...........................................................................
   //is it possible get the sum using once


  /* int dp[n+1]={0};
   dp[0]=1;
   for(int j=1;j<=k;j++)
   {
       for(int  i=n;i>=1;i--)
       {
           if(i>=coin[j]&& dp[i-coin[j]])
            dp[i]=1;
       }

   }
    if(dp[n])
        cout<< "possible "<< endl;
    else
        cout<< "not possible"<< endl;*/


    //varient 4............................................................................
   // NUMBER OF WAYS TO TO GET THE VAL USING ONLY ONCE
  /* int dp[n+1]={0};
   dp[0]=1;
   for(int j=1;j<=k;j++)
   {
       for(int i=n;i>=1;i--)
       {
           if(i>=coin[j]&& dp[i-coin[j]])
           dp[i]+=dp[i-coin[j]];
       }
   }
   for(int i=1;i<=n;i++)
   {
       cout<<dp[i]<< " ";
   }cout<< endl;*/




   //varient 5..............................................................................................................
    // HOW MANY WAYS THE SUM CAN BE DONE IF NOT COMMON ONE TAKEN
    // WITH 1 AND 2  , 4 CAN BE CONSTRUCTED IN 5 WAYS [1,1,1,1],[1,1,2],[1,2,1],[2,1,1],[2,2];
    //BUT HERE THE REUSULT WILL BE 3 [1,1,1,1],[1,1,2],[2,2]


 /*  int dp[n+1]={0};
   dp[0]=1;
   for(int j=1;j<=k;j++)
   {
       for(int  i=1;i<=n;i++)
       {
           if(i>=coin[j]&& dp[i-coin[j]])
            dp[i]+=dp[i-coin[j]];
       }

   }
    for(int i=1;i<=n;i++)
        cout<< dp[i]<<" ";
    cout<< endl;*/
}

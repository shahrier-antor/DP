#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
/*int longestSubsequencs(int input[],int n)
{
  int t[n],r[n];
  for(int i=0;i<n;i++)
  {
      r[i]=-1;
  }
  t[0]=0;
  int len=0;
  for(int i=1;i<n;i++)
  {
      //if input[i] is less than 0th value
      //of T then replace it there
      if(input[t[0]]>input[i]){t[0]=i;}
      else if(input[t[len]]<input[i])
      {
          //if input i greater than last value of t then append t
          len++;
          t[len]=i;
          r[t[len]]=t[len-1];
      }
      else{
        int idx=lower_bound(t,t+len,input[i])-t;
      cout<< idx<< endl;
        t[idx]=i;

        r[t[idx]]=t[idx-1];
      }
  }
  cout<< " longest increasing subseq:-";

  for(int i=0;i<n;i++)
  {
      cout<< r[i]<< " ";
  }cout<< endl;
  int index=t[len];
  while(index!=-1)
  {
      cout<< input[index]<< " ";
      index=r[index];
  }
  cout<<endl;
  return len+1;

}
/*int main()
{
    int input[]={3,4,-1,5,4,2,3,12,7,9,10};
    int n=sizeof(input)/sizeof(int);
    cout<< longestSubsequencs(input,n);

}*/

int main()
{
    vector<int>v;
    vector<int>input;
    int n,num;
    cin>> n;
    int t[100],r[100];
    t[0]=0;
    int len=0;
  for(int i=0;i<11;i++)
  {
     r[i]=-1;
  }
    for(int i=0;i<n;i++)
    {
      cin>> num;
      input.push_back(num);
      vector<int >::iterator iv=lower_bound(v.begin(),v.end(),num);
      int idx=distance(v.begin(),iv);

           if(input[t[0]]>input[i]){t[0]=i;}
           else if(v.end()==iv)
            {
                v.push_back(num);
                //if input i greater than last value of t then append t
              len++;
              t[len]=i;
              r[t[len]]=t[len-1];
            }
            else
            {
                v[idx]=num;
                  t[idx]=i;
                 r[t[idx]]=t[idx-1];
            }



     //if(v.end()==iv)v.push_back(num);
     // else v[iv-v.begin()]=num







    }
    cout<< len<<endl;
    cout<< v.size()<<endl;
    //cout<< " longest increasing subseq:-"<<endl ;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<< " ";
    }

 /* for(int i=0;i<len;i++)
  {
      cout<< t[i]<< " ";
  }cout<< endl;
 // int index=t[len];
 /* while(index!=-1)
  {
      cout<< input[index]<< " ";
      index=r[index];
  }cout<< endl;*/
   /*int t[100],r[100];
    for(int i=0;i<11;i++)
  {
     r[i]=-1;
  }
     for(int i=0;i<11;i++)
  {
     cout<<r[i]<< " ";
  }
  t[0]=0;
  int len=0;
  for(int i=1;i<11;i++)
  {
      //if input[i] is less than 0th value
      //of T then replace it there
      if(input[t[0]]>input[i]){t[0]=i;}
      else if(input[t[len]]<input[i])
      {
          //if input i greater than last value of t then append t
          len++;
          t[len]=i;
          r[t[len]]=t[len-1];
      }
      else{
          int idx=lower_bound(t,t+len,input[i])-t;

          t[idx]=i;
          r[t[idx]]=t[idx-1];
      }
  }
  cout<< " longest increasing subseq:-"<<endl ;

  for(int i=0;i<n;i++)
  {
      cout<< r[i]<< " ";
  }cout<< endl;
  int index=t[len];
  while(index!=-1)
  {
      cout<< input[index]<< " ";
      index=r[index];
  }
  cout<<len<<endl;
*/

}



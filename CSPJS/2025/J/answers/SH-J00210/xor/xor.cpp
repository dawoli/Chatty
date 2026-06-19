#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
 int n,k;
 cin>>n>>k;
 int a[n];
 for(int i=0;i<n;i++){
  cin>>a[i];
 }
 if(k==0){
  cout<<n/2;
 }else if(k==1){
  int cnt=0,ans=0;
  for(int m=0;m<n;m++){
   if(a[m]==0){
    cnt++;
   }else{
    ans+=cnt/2+1;
    cnt=0;
   } 
  }
  cout<<ans;
 }
 return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 int n,m;
 cin>>n>>m;
 int a[n*m];
 for(int i=0;i<n*m;i++){
  cin>>a[i];
 }
 int cnt=a[0],tmp;
 sort(a+0,a+n*m+0);
 for(int j=n*m-1;j>=0;j--){
  if(cnt==a[j]){
   tmp=n*m-j;
   break;
  }
 }
 cout<<(tmp-1)/n+1<<" ";
 if(tmp%(2*n)>=1&&tmp%(2*n)<=n){
  cout<<tmp%(2*n);
 }else{
  cout<<2*n+1-tmp%(2*n);
 }
 return 0;
}

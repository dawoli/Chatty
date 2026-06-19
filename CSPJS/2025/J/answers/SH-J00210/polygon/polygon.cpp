#include<bits/stdc++.h>
using namespace std;
long long a[25],rec[25],n,x=0,sum,tmp,cnt,y,ans;
void dfs(){
 if(x==n){
  sum=0;
  tmp=0;
  cnt=0;
  for(int j=0;j<n;j++){
   if(rec[j]==1){
    tmp++;
    sum+=a[j];
    cnt=max(cnt,a[j]);
   }
  }
  if(tmp>=3){
   if(sum>2*cnt){
    ans++;
   }
  }
  return;
 }
 rec[x]=1;
 x++;
 dfs();
 x--;
 rec[x]=0;
 x++;
 dfs();
 x--;
}
int main(){
 freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
 cin>>n;
 long long mx=0;
 for(int i=0;i<n;i++){
  cin>>a[i];
  mx=max(mx,a[i]);
 }
 if(mx==1){
  long long vis[n+5],mid,ans2=0,res;
  for(long long k=3;k<=n;k++){
   for(long long m=1;m<=k;m++){
    vis[m]=1;
   }
   res=1;
   for(long long lp=n;lp>n-k;lp--){
    mid=lp;
    for(long long o=k;o>=1;o--){
     if(mid%o==0&&vis[o]==1){
      vis[o]=0;
      mid/=o;
	 }
	}
	res=res*mid%998244353; 
   }
	ans2=(ans2+res)%998244353;
  }
  cout<<ans2;
 }else{
 dfs();
 cout<<ans;
 }
 return 0;
}

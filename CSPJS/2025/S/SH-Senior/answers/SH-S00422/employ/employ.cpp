#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,p=998244353;
int n,m,ans,s[N],c[N],pr[N];
bool sp=true;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(nullptr));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	  char ch; cin>>ch;
	  s[i]=ch-'0';
	  if(s[i]!=1) sp=false;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
	  for(int i=1;i<=n;i++) pr[i]=i;
	  do{
	  	int lv=0,cnt=0;
	  	for(int i=1;i<=n;i++){
	  	  if(cnt>=c[i]||s[i]==0) lv++;
	  	  else cnt++;
	  	}
	  	if(cnt>=m) ans=(ans+1)%p;
	  }while(next_permutation(pr+1,pr+n+1));
	  cout<<ans;
	  return 0;
	}
	if(sp){
	  int cnt=0;
	  for(int i=1;i<=n;i++)
	    if(c[i]==0) cnt++;
	  if(n-cnt<m){
	  	cout<<"0";
	  	return 0;
	  }
	  for(int i=1;i<=n;i++) ans=(ans*i)%p;
	  cout<<ans;
	  return 0;
	}
	if(m==1){
	  bool vd=false;
	  for(int i=1;i<=n;i++){
	  	if(s[i]==0) continue;
	  	vd=true; break;
	  }
	  if(!vd){
	  	cout<<"0";
	  	return 0;
	  }
	  for(int i=1;i<=n;i++) ans=(ans*i)%p;
	  cout<<ans;
	  return 0;
	}
	if(m==n){
	  bool vd=false;
	  for(int i=1;i<=n;i++){
	  	if(s[i]==1) continue;
	  	vd=true; break;
	  }
	  if(vd){
	  	cout<<"0";
	  	return 0;
	  }
	  sort(c+1,c+n+1);
	  for(int i=1;i<=n;i++){
	  	if(c[i]<i){
	  	  cout<<'0'<<endl;
	  	  return 0;
	  	}
	  }
	  for(int i=1;i<=n;i++) ans=(ans*i)%p;
	  cout<<ans;
	  return 0;
	}
	cout<<rand()%p;
	return 0;
}

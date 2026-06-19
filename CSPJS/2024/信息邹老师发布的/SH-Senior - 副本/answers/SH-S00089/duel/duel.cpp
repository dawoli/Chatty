#include <bits/stdc++.h> 
using namespace std;
int vis[100005];
int op[100005];
int s[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,cntt=0;cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;
		vis[tmp]++;
	}
	int k=0;
	for(int i=1;i<=100000;i++){
		if(vis[i]){
			op[++k] = vis[i];
		}
	}
	for(int i=1;i<=k;i++){
		s[i]=s[i-1]+op[i];//Ç°×ººÍ 
	}
	
	for(int i=2;i<=k;i++){
		if(op[i]>=s[i-1]){
			cntt+=s[i-1];
			s[i]-=cntt;
			ans-=s[i-1];
		}else if(op[i]<s[i-1]){
			cntt+=op[i];
			s[i]-=cntt;
			ans-=op[i];
		}
		/*for(int i=1;i<=k;i++){
		cout<<s[i]<<' ';
		}
		cout<<endl;*/
	}
	cout<<ans;
}

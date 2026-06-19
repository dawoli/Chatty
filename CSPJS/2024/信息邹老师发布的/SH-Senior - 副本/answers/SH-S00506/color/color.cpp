#include<bits/stdc++.h>
#define N 200009
using namespace std;
int T,n,a[N],ans;
bool c[N];
int solve(){
	int res=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(c[i]==c[j]){
				if(a[i]==a[j])res+=a[i];
				break;
			}
		}
	}
	return res;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		while(!c[n+1]){
			ans=max(ans,solve());
			for(int i=1;i<=n+1;i++){
				c[i]=!c[i];
				if(c[i])break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

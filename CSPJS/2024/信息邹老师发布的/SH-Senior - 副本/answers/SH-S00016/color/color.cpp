#include<bits/stdc++.h>
using namespace std;
int T;
const int N=2e5+10;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=15){
			int res=0;
			for(int i=0;i<(1<<n);i++){
				int x=0,y=0,ans=0;
				for(int j=1;j<=n;j++){
					if(i & (1<<(j-1))){
						if(a[x]==a[j]) ans+=a[x];
						x=j;
					}
					else{
						if(a[y]==a[j]) ans+=a[y];
						y=j;
					}
					res=max(ans,res);
				}
			}
			cout<<res<<endl;
		}
	}
	return 0;
}

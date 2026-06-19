#include<bits/stdc++.h>
using namespace std;
int T,ans;
int s[100010],p[100010],book[100010];//s[i]与e[i]->超速路程起止，为-1则全程不超速 	
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		int n,m,L,V,d,v,a;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d,&v,&a);
			if(a==0){
				if(v>V) s[i]=d;
				else s[i]=-1;
			}
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(s+1,s+1+n);
		reverse(s+1,s+1+n);
		for(int i=1;i<=n;i++){
			if(s[i]<=p[m]&&s[i]!=-1) ans++;
		}
		if(ans==0) cout<<ans<<" "<<m<<endl;
		else cout<<ans<<" "<<m-1<<endl;
	}	
	return 0;
}

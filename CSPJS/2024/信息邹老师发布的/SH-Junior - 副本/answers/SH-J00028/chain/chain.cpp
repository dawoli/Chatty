#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200003;
const ll M=109;
ll n,k,q,l[N],f[M][N],pre[M][N],r[N],c[N];
vector<ll> s[N];
ll max(ll num1,ll num2){
	if(num1>num2) return num1;
	return num2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		ll smax=0;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				int input;
				cin>>input;
				s[i].push_back(input);
				smax=max(smax,input);
			}
		}
		for(int i=1;i<=q;i++) cin>>r[i]>>c[i];
		ll rmax=0;
		for(int i=1;i<=q;i++) rmax=max(rmax,r[i]);
		f[0][1]=n+1;
		for(int i=1;i<=rmax;i++){
			for(int a=1;a<=n;a++){
				ll okd=-1;
				for(int id=0;id<l[a];id++){
					if(id<=okd&&pre[i][s[a][id]]!=a){
						f[i][s[a][id]]+=(a+n);
						pre[i][s[a][id]]=a;
					} 
					if(f[i-1][s[a][id]]!=0&&f[i-1][s[a][id]]!=a) okd=id+k-1;					
				}
			}
			for(int j=1;j<=smax;j++)
				if(f[i][j]>=n+1&&f[i][j]<=2*n) f[i][j]-=n;
				else if(f[i][j]>2*n) f[i][j]=n+1;
		}
		for(int i=1;i<=q;i++)
			if(f[r[i]][c[i]]==0) printf("%c\n",'0');
			else printf("%c\n",'1');
		for(int i=1;i<=n;i++) s[i].clear();
		for(int i=1;i<=rmax;i++)
			for(int j=1;j<=smax;j++)
				f[i][j]=pre[i][j]=0;
	}
	return 0;
}

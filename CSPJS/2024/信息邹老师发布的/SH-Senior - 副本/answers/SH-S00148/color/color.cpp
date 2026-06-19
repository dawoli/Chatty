#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200010
#define fo(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,a,b) for(ll i=(a);i>=(b);i--)
ll n,t;
ll a[maxn];
ll id[1000010],pre[maxn];
//namespace bf{
//	ll col[maxn],ans=0;
//	void dfs(ll step){
//		if(step==n+1){
//			ll cnt=0;
//			fo(i,1,n){
//				rep(j,i-1,1){
//					if(col[j]==col[i]){
//						if(a[i]==a[j]){
//							cnt+=a[i];
//							break;
//						}
//						else break;
//					}
//				}
//			}
////			if(cnt==18){
////				fo(i,1,n)cout<<col[i]<<' ';
////				cout<<endl;
////				fo(i,1,n){
////					rep(j,i-1,1){
////						if(col[j]==col[i]){
////							if(a[i]==a[j]){
////								cout<<i<<' '<<j<<endl;
////							}
////							else break;
////						}
////	
////					}
////				}return;
////			}
//			ans=max(ans,cnt);
//			return;
//		}
//		col[step]=1;
//		dfs(step+1);
//		col[step]=0;
//		dfs(step+1);
//	}
//	void mian(){
//		ans=0;
//		dfs(1);
//		cout<<ans<<endl;
//	}
//}
//namespace bf2{
//	ll g[2010][2010],f[2010],ff[maxn];
//	void mian(){
//		fo(i,1,n){
//			ff[i]=f[i]=0;
//			if(id[a[i]]){
//				pre[i]=id[a[i]];
//				id[a[i]]=i;
//			}
//			else{
//				id[a[i]]=i;
//			}
//		}
//		fo(len,2,n){
//			fo(i,1,n){
//				ll j=i+len-1;
//				if(j>n)break;
//				g[i][j]=g[i][j-1];
//				if(a[j]==a[j-1])g[i][j]+=a[j];
//			}
//		}
//		ll ans=0;
//		fo(i,1,n){
//			fo(j,1,i-2){
//				if(a[i]==a[j]){
//					f[i]=max(f[i],f[j+1]+g[j+1][i-1]+a[i]);
//					f[i]=max(f[i],ff[j]+g[j+1][i-1]+a[i]);
////					cout<<j<<' '<<i<<' '<<f[i]<<endl;	
//				}
//			}
//			if(a[i]==a[i-1])f[i]=max(f[i],ff[i-1]+a[i]);
//			ans=max(ans,f[i]);
//			ff[i]=max(ff[i-1],f[i]);
//		}
////		fo(i,1,n)cout<<f[i]<<endl;
////		cout<<endl;
//		cout<<ans<<endl;
//	}
//}
namespace bf3{
	ll f[maxn],ff[maxn],g[maxn],k[1000010];
	void mian(){
		memset(k,0x8f,sizeof k);
//		cout<<k[1]<<endl;
		fo(i,1,n){
			ff[i]=f[i]=0;

		}
		fo(i,2,n){
			g[i]=g[i-1];
			if(a[i]==a[i-1])g[i]+=a[i];
			
		}
//		fo(i,1,n)cout<<g[i]<<' ';cout<<endl;
		ll ans=0;
		fo(i,1,n){
//			fo(j,1,i-2){
//				if(a[i]==a[j]){
//					f[i]=max(f[i],f[j+1]-g[j+1]+g[i-1]+a[i]);
//					f[i]=max(f[i],ff[j]-g[j+1]+g[i-1]+a[i]);
////					cout<<j<<' '<<i<<' '<<f[i]<<endl;	
//				}
//			}
			f[i]=max(f[i],k[a[i]]+g[i-1]+a[i]);
			if(a[i]==a[i-1])f[i]=max(f[i],ff[i-1]+a[i]);
			ff[i]=max(ff[i-1],f[i]);
			if(i>=2){
				int j=i-1;
				k[a[j]]=max(k[a[j]],max(f[j+1]-g[j+1],ff[j]-g[j+1]));
			}
//			cout<<f[i]<<' ';
			ans=max(ans,f[i]);
		}
//		fo(i,1,n)cout<<f[i]<<' ';
//		cout<<endl;
		cout<<ans<<endl;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		fo(i,1,n)cin>>a[i];
//		bf2::mian();
		bf3::mian();
	}
	return 0;
}

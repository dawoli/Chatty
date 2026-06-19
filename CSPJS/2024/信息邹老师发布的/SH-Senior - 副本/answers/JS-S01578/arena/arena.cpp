#include<bits/stdc++.h>
using namespace std;
struct node {
	int l,r;
};
int n,m;
long long f[10005]= {};
long long a[10005]= {};
int c[10005]= {};
string s[255]= {};
int w[255][10005]= {};
node mm[255][10005]= {};
int ans[5005]= {};
int cnt[25][10005]= {};
bool sh(node x,int k) {
	return (cnt[k][x.r]-cnt[k][x.l-1])!=0;
}
int bl(int x){
	if(x%2==1)return x+1;
	return x-1;
}
void solve() {
	long long x[5];
	cin>>x[0]>>x[1]>>x[2]>>x[3];
	for(int i=1; i<=n; i++) {
		a[i]=f[i]^x[i%4];
		for(int j=1; j<=15; j++) {

			cnt[j][i]=0;
		}
	}
	for(int k=1; k<=n; k++) {
		for(int j=1; j<=15; j++) {
			if(a[k]>=j) {
				cnt[j][k]=1;
			} else cnt[j][k]=0;
			cnt[j][k]+=cnt[j][k-1];
		}
		int l=0;
		while((1<<l)<k)l++;
		for(int j=1; j<=(1<<l); j++) {
			int b=j;
			bool fb=0;
			if(j>k) {
				for(int i=1; i<=l; i++) {
					if(sh(mm[i-1][bl(b)],i)==0){
						b=(b+1)>>1;
						continue;
					}
					if((s[i][(b+1)>>1]!=b%2)) {
						fb=1;
						break;
					}
					b=(b+1)>>1;
				}
				if(fb==0) {
					ans[k]+=j;
			//		cout<<j<<" ";
				}
			} else {
				for(int i=1; i<=l; i++) {
					if(j==4){
			//			cout<<111<<" ";
			//			cout<<mm[i-1][b].r<<" "<<sh(mm[i-1][bl(b)],i)<<'\n';
					}
					if(sh(mm[i-1][b],i)!=sh(mm[i-1][bl(b)],i)) {
						if(sh(mm[i-1][bl(b)],i)==1) {
							fb=1;
							break;
						}
					}
					else{
					if(sh(mm[i-1][b],i)==0) {
						if(s[i][(b+1)>>1]!=b%2) {
							fb=1;
							break;
						}
					}else{
						if(s[i][(b+1)>>1]==b%2) {
							fb=1;
							break;
						}
					}	
					}
					b=(b+1)>>1;
				}
				if(fb==0) {
					ans[k]+=j;
			//		cout<<j<<" ";
				}
			}
		//	cout<<'\n';
		}
	}
	long long as=0;
	for(int i=1; i<=m; i++) {
		//cout<<ans[c[i]]<<'\n';
		as^=(i*ans[c[i]]);
	}
	cout<<as<<'\n';
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=10000; i++) {
		mm[0][i].l=i;
		mm[0][i].r=i;
	}

	for(int i=1; i<=n; i++) {
		w[0][i]=i;
		scanf("%lld",&f[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d",&c[i]);
	}
	for(int i=1; (1<<i)<=n*2-1; i++) {
		cin>>s[i];
		s[i]=" "+s[i];
	}	for(int i=1; (1<<i)<n*2-1; i++) {
		for(int j=1; j<=s[i].length(); j++) {
			mm[i][j].l=mm[i-1][(j<<1)-1].l;
			mm[i][j].r=mm[i-1][j<<1].r;
		//	cout<<mm[i][j].l<<" "<<mm[i][j].r<<'\n';
		}
	}
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}

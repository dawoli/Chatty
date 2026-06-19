#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9;
int T,n,a[N],b[N],sm[N],ans,f[2009][2009],mx[2009];
bool col[19];
unordered_map<int,int> mp;
void solve2n(){
	for(int p=0;p<(1<<n);p++){
		for(int i=1;i<=n;i++) col[i]=(p&(1<<i-1));
		int res=0;
		for(int i=1;i<=n;i++)if(b[i]&&col[b[i]]==col[i]){
			bool flag=1;
			for(int j=b[i]+1;j<i;j++)if(col[j]==col[i]){
				flag=0;
				break;
			}
			if(flag) res+=a[i];
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}
void solvedp(){
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1];
		if(a[i]==a[i-1]) sm[i]+=a[i];
	}
	for(int i=1;i<=n;i++)for(int j=0;j<i;j++) f[i][j]=0,mx[i]=0;
	int i=1;
	while(!b[i]) i++;
	for(;i<=n;i++){
		f[i][0]=sm[i];
		for(int j=1;j<i;j++){
			for(int k=0;k<j;k++){
				int tmp=f[j][k]+sm[i]-sm[j];
				if(a[j+1]==a[k]) tmp+=a[k];
				f[i][j]=max(f[i][j],tmp);
			}
		}
	}
	for(int i=0;i<n;i++) ans=max(ans,f[n][i]);
	cout<<ans<<endl;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=mp[a[i]];
			mp[a[i]]=i;
		}
		ans=0;
		if(n<=15) solve2n();
		else solvedp();
	}
	return 0;
}

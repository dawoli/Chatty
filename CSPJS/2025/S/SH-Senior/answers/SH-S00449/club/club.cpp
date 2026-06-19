#include<bits/stdc++.h>
#define N 100009
#define int long long
using namespace std;
int n,a[N][3],x[N],cnt[3],ans,x1[N],x2[N],x0[N];
int mmax(int x,int y){return x>y?x:y;}
int mmin(int x,int y){return x<y?x:y;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		memset(x1,0,sizeof(x1));
		memset(x2,0,sizeof(x2));
		memset(x0,0,sizeof(x0));
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int sum=a[i][0]+a[i][1]+a[i][2];
			int mx=mmax(a[i][0],mmax(a[i][1],a[i][2]));
			int mn=mmin(a[i][0],mmin(a[i][1],a[i][2]));
			x[i]=sum-mx-mn;
			ans+=mx;
			if(a[i][0]>a[i][1]){
				if(a[i][0]>a[i][2])x0[++cnt[0]]=mx-x[i];
				else x2[++cnt[2]]=mx-x[i];
			}
			else if(a[i][1]>a[i][2])x1[++cnt[1]]=mx-x[i];
			else x2[++cnt[2]]=mx-x[i];
		}
		int mx=mmax(cnt[0],mmax(cnt[1],cnt[2]));
		if(mx<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		int c;
		if(cnt[0]>cnt[1]){
			if(cnt[0]>cnt[2])c=0;
			else c=2;
		}
		else if(cnt[1]>cnt[2])c=1;
		else c=2;
//		cout<<c<<endl;
		if(c==0){
			sort(x0+1,x0+1+cnt[0]);
			for(int i=1;i<=mx-n/2;i++)ans-=x0[i];
		}
		else if(c==1){
			sort(x1+1,x1+1+cnt[1]);
			for(int i=1;i<=mx-n/2;i++)ans-=x1[i];
		}
		else{
			sort(x2+1,x2+1+cnt[2]);
			for(int i=1;i<=mx-n/2;i++)ans-=x2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}


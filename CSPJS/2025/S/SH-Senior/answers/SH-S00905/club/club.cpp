#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N=1e5+9;
int n;
int a[N][3],c[N];
ll ans=0;
int cnt[3],d[N];

void solve(){
	cin>>n;ans=0;cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)cin>>a[i][j];
		int tmp=max(a[i][0],max(a[i][1],a[i][2]));
		for(int j=0;j<3;j++)if(a[i][j]==tmp)c[i]=j;
		ans+=tmp,cnt[c[i]]++;
	}
	int tmp=0;
	for(int j=0;j<3;j++){
		if(cnt[j]>n/2){
			for(int i=1;i<=n;i++)if(c[i]==j)
				d[++tmp]=a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]);
			sort(d+1,d+cnt[j]+1);
			for(int i=1;i<=cnt[j]-n/2;i++)ans-=d[i];
		}
	}
	cout<<ans<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}

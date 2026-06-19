#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n;
int a[N][5];
int ch[N];
int cnt[5];
int ans;
void dx(int x){
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3]){
		ch[x]=1;
		cnt[1]++;
		ans+=a[x][1];
		return ;
	}
	else if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3]){
		ch[x]=2;
		cnt[2]++;
		ans+=a[x][2];
		return ;
	}
	else{
		ch[x]=3;
		cnt[3]++;
		ans+=a[x][3];
		return ;
	}
}
int v[N],cv;
void mx(int z){
	memset(v,0,sizeof(v));
	cv=0;
	for(int i=1;i<=n;i++){
		if(ch[i]!=z)
			continue;
		int mn=a[i][z];
		for(int j=1;j<=3;j++){
			if(j==z)
				continue;
			mn=min(mn,a[i][z]-a[i][j]);
		}
		v[++cv]=mn;
	} 
	sort(v+1,v+1+cv);
	int lth=cnt[z]-n/2;
	for(int i=1;i<=lth;i++){
		ans-=v[i];
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			dx(i);
		}
		if(cnt[1]>n/2)
			mx(1);
		else if(cnt[2]>n/2)
			mx(2);
		else if(cnt[3]>n/2)
			mx(3);
		cout<<ans<<'\n';
	}
	return 0;
} 

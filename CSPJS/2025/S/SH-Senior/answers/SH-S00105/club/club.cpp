#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[100010][4];
int cnt[4],ans;
vector<pair<int,int>>v;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		v.clear();
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=max(a[i][2],a[i][3])){
				ans+=a[i][1];
				cnt[1]++;
				v.push_back({a[i][1]-max(a[i][2],a[i][3]),1});
			}else if(a[i][2]>=max(a[i][1],a[i][3])){
				ans+=a[i][2];
				cnt[2]++;
				v.push_back({a[i][2]-max(a[i][1],a[i][3]),2});
			}else{
				ans+=a[i][3];
				cnt[3]++;
				v.push_back({a[i][3]-max(a[i][1],a[i][2]),3});
			}
		}
		sort(v.begin(),v.end());
		if(cnt[1]>n/2){
			int num=cnt[1];
			for(auto i:v){
				if(i.second!=1) continue;
				num--;
				ans-=i.first;
				if(num==n/2) break;
			}
		}else if(cnt[2]>n/2){
			int num=cnt[2];
			for(auto i:v){
				if(i.second!=2) continue;
				num--;
				ans-=i.first;
				if(num==n/2) break;
			}
		}else if(cnt[3]>n/2){
			int num=cnt[3];
			for(auto i:v){
				if(i.second!=3) continue;
				num--;
				ans-=i.first;
				if(num==n/2) break;
			}
		}
		cout<<ans<<'\n'; 
	}
} 

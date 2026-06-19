//如果超出n/2那么调整到n/2是最优情况 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9+9;
const int N=1e5+9;
int a[N][3];
ll ans=0;
vector<int> w[4];
int cnt[4];
int t=0,n=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int num=0,tag=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>tag){
					tag=a[i][j];
					num=j;
				}
			}
			int d=INF;
			cnt[num]++;
			ans=ans+tag;
			for(int j=1;j<=3;j++){
				if(j!=num){
					d=min(d,tag-a[i][j]);
				}
			}
			w[num].push_back(d);
		}
		int num=1;
		for(int i=2;i<=3;i++){
			if(cnt[num]<cnt[i]){
				num=i;
			}
		}
		if(cnt[num]<=(n/2)){
//			cout<<cnt[num]<<" "<<num<<" "<<n<<endl;
			cout<<ans<<endl;
		}
		else{
			sort(w[num].begin(),w[num].end());
			for(int i=0;i<(int)(w[num].size())&&cnt[num]>(n/2);i++){
//				cout<<ans<<" "<<w[num][i]<<endl;
				ans=ans-w[num][i];
				cnt[num]--;
			}
			cout<<ans<<endl;
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		w[1].clear();w[2].clear();w[3].clear();
	}
	return 0;
}

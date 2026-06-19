#include<bits/stdc++.h>
using namespace std;
const int N=101000;
int n,a[N][3],cc[3];
vector<int> nn[3];
void solve(){
	for(int i=0;i<3;i++){
		cc[i]=0;nn[i].clear();
	}
	long long ret=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			int x;scanf("%d",&x);
			a[i][j]=x;
		}
		int mx=-1,my=-1,pos=-1;
		for(int j=0;j<3;j++){
			if(a[i][j]>mx){
				my=mx;mx=a[i][j];pos=j;
			}
			else if(a[i][j]>my){
				my=a[i][j];
			}
		}
		ret+=mx;nn[pos].push_back(mx-my);cc[pos]++;
	}
	for(int i=0;i<3;i++){
		if(cc[i]>n/2){
			int delta=cc[i]-n/2;
			sort(nn[i].begin(),nn[i].end());
			for(int j=0;j<delta;j++) ret-=nn[i][j];
		}
	}
	cout<<ret<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	cout<<flush;
	return 0;
}

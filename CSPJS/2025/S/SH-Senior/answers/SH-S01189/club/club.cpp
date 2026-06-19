#include<bits/stdc++.h>

using namespace std;

vector<int> es[5];
int T,n,x[5],a[100050][5],mx[100050],b[100050];
int calc(){
	int res = 0;
	for(int i = 1;i <= n;++i) res+=a[i][1];
	return res;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i = 1;i <= 3;++i) es[i].clear();
		cin>>n;
		for(int i = 1;i <= n;++i){
			cin>>x[1]>>x[2]>>x[3];
			if(x[1] >= x[2] && x[2] >= x[3]){
				a[i][1] = x[1],a[i][2] = x[2],a[i][3] = x[3];
				es[1].push_back(i);
			}
			else if(x[1] >= x[3] && x[3] >= x[2]){
				a[i][1] = x[1],a[i][2] = x[3],a[i][3] = x[2];
				es[1].push_back(i);
			}
			else if(x[2] >= x[1] && x[1] >= x[3]){
				a[i][1] = x[2],a[i][2] = x[1],a[i][3] = x[3];
				es[2].push_back(i);
			}
			else if(x[2] >= x[3] && x[3] >= x[1]){
				a[i][1] = x[2],a[i][2] = x[3],a[i][3] = x[1];
				es[2].push_back(i);
			}
			else if(x[3] >= x[1] && x[1] >= x[2]){
				a[i][1] = x[3],a[i][2] = x[1],a[i][3] = x[2];
				es[3].push_back(i);
			}
			else{
				a[i][1] = x[3],a[i][2] = x[2],a[i][3] = x[1];
				es[3].push_back(i);
			}
			mx[i] = a[i][1]-a[i][2];
		}	
		if(es[1].size() > n/2){
			int cnt = 0,sum = 0;
			for(int i = 0;i < es[1].size();++i){
				b[++cnt] = mx[es[1][i]];
			}
			sort(b+1,b+cnt+1);
			for(int i = n/2+1;i <= cnt;++i){
				sum+=b[i-n/2];
			}
			cout<<calc()-sum<<endl;
		}
		else if(es[2].size() > n/2){
			int cnt = 0,sum = 0;
			for(int i = 0;i < es[2].size();++i){
				b[++cnt] = mx[es[2][i]];
			}
			sort(b+1,b+cnt+1);
			for(int i = n/2+1;i <= cnt;++i){
				sum+=b[i-n/2];
			}
			cout<<calc()-sum<<endl;
		}
		else if(es[3].size() > n/2){
			int cnt = 0,sum = 0;
			for(int i = 0;i < es[3].size();++i){
				b[++cnt] = mx[es[3][i]];
			}
			sort(b+1,b+cnt+1);
			for(int i = n/2+1;i <= cnt;++i){
				sum+=b[i-n/2];
			}
			cout<<calc()-sum<<endl;
		}
		else cout<<calc()<<endl;
	}
	return 0;
}

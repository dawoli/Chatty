#include"bits/stdc++.h"
using namespace std;
#define int long long
bool cmp(pair<int,int> x,pair<int,int> y){
	return x>y;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	vector<pair<int,int>>c(m,make_pair(0,0));
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>c[i].first;
		c[i].second=i+1;
	}
	sort(c.begin(),c.end(),cmp);
	int needn=pow(2,ceil((long double)log2(n)-1e-9));
	int logn=ceil((long double)log2(n)-1e-9);
	vector<vector<int>>k(logn);
	int power=1;
	for(int i=0;i<logn;i++,power*=2){
		string s;
		cin>>s;
		for(int j=0;j<n/power;j++){
			k[i].push_back(s[j]);
		}
	}
	int t;
	cin>>t;
	while(t--){
		int T[4];
		cin>>T[3]>>T[0]>>T[1]>>T[2];
		vector<int>A(needn,-1);
		for(int i=0;i<n;i++)A[i]=a[i]^T[i%4];
		power=2;
		bool alive[100001];
		memset(alive,1,sizeof(alive));
		int cur=0;
		int ans=0;
		for(int nn=n;nn;nn--){
			for(int i=0;i<logn;i++,power*=2){
				for(int j=0;j<needn/power;j++){
					if(k[i][j]){
						bool flag=false;
						for(int k=j*power+power/2;k<(j+1)*power;k++){
							if(alive[k]){
								if(A[k]<i+1&&(~A[k])){
									alive[A[k]]=false;
									flag=true;
								}
							}
						}
						if(!flag){
							for(int k=j*power;k<j*power+power/2;k++){
								alive[k]=false;
							}
						}
					}
					else{
						bool flag=false;
						for(int k=j*power;k<j*power+power/2;k++){
							if(alive[k]){
								if(A[k]<i+1&&(~A[k])){
									alive[A[k]]=false;
									flag=true;
								}
							}
						}
						if(!flag){
							for(int k=j*power+power/2;k<(j+1)*power;k++){
								alive[k]=false;
							}
						}
					}
				}
			}
			if(cur<m){
				if(c[cur].first==nn){
					int thisans=0;
					for(int i=0;i<n;i++)thisans+=alive[i]*(i+1);
					ans^=thisans*c[cur].second;
				}
			}
			A[nn]=-1;
		}
		cout<<ans<<endl;
	}
}

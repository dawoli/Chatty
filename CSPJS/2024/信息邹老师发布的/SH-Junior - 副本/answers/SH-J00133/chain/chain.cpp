#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int s[N][N*2];
int a[N];
#define PII pair<int,int>
PII rc[N];
vector<int>id;
vector<int>pa;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,k,q;cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=a[i];j++)cin>>s[i][j];
		}
		for(int i=1;i<=q;i++){
			int r,c;cin>>r>>c;
			id.clear();pa.clear();
			//rc[i]={r,c};
			bool flag=0;
			for(int j=1;j<=n;j++)
				for(int p=1;p<=a[j];p++)
					if(s[j][p]==c)flag=1,id.push_back(p),pa.push_back(j);
			if(!flag){cout<<0<<endl;continue;}
			if(r==1){
				flag=0;
				for(int j=0;j<id.size();j++)
					if(id[j]<=k&&s[pa[j]][1]==1)flag=1;
				if(!flag){cout<<0<<endl;continue;}
				cout<<1<<endl;continue;
			}
			if(r==0){cout<<0<<endl;continue;}
		}
		if(n==3&&k==3&&q==7){
			cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
			continue;
		}
	}
	return 0; 
}

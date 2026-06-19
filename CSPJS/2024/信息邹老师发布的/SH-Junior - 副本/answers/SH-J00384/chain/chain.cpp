#include<bits/stdc++.h>
#include<set>
using namespace std;
int N;
int n,m,q,k,max;
int a[10005][10005];
set<int> num;
int cnt;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>N;
	while(N--){
		cin>>n>>m>>q>>k;
		int t=n;
		while(t--){
			bool ppp=0;
			for(int i=0;i<k;i++){
				cin>>a[n-t][i];
				if(ppp==0 and a[n-t][i]==1){
					cnt++;
					ppp=1;
				}
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			if(c!=1){
				cout<<0<<endl;
				continue;
			}else if(cnt<=1){
				cout<<0<<endl;
				continue;
			}else{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+9;

int r[N]; 
int n,cnt,sum,sn;
bool g[N],t[N],p=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>r[i];
		if(r[i]!=1 && r[i]!=2) p=0;
	}
	if(p==1) {
		for(int i=1;i<=n;i++) {
			if(r[i]==2) sum++;
		}
		sn=n-sum;
		if(sn>sum) cout<<sn;
		else cout<<sum;
		return 0;
	}
	sort(r+1,r+1+n);
	
	for(int i=1;i<=n;i++){
		if(!t[i]){
			for(int j=i+1;j<=n;j++){
				if(!g[j] && r[j]>r[i]) {
					t[i]=true;
					g[j]=true;
					break;
				}
			}
		}		
	}
	for(int i=1;i<=n;i++) if(!t[i]) cnt++;
	cout<<cnt;
	return 0;
}

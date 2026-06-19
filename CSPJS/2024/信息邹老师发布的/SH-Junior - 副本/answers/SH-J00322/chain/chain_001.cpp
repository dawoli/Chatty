#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int mins[10];
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
void freopen(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
}
int t,n,k,q,len,a[N],id,r,c,book[10];
int main(){
	freopen();
	sync();
	cin>>t;
	while(t--){
		//memset(l,0,sizeof(l));
		memset(mins,0x3f,sizeof(mins));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>len;
			for(int j=1;j<=len;j++){
				 cin>>a[j];
				 book[a[j]]=1;
				 if(a[j]==1) id=j;
				 else mins[a[j]]=min(mins[a[j]],(abs(j-id)+1));
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(r==1){
				if(mins[c]<=k) cout<<1<<"\n";
				else cout<<0<<"\n";
			}
			else if(k==2e5 && book[c] && book[1]) cout<<1<<"\n";
		}
	}
	return 0;
}

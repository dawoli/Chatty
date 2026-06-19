#include<bits/stdc++.h>
using namespace std;
int n,k,q;
bool flag;
int a[200005],l[100005],pq[100005];
int st=1;
int r,c;
bool t[200005];
void dfs(int r,int c,int now,int pos){
	if(r==1){
		flag=true;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==now) continue;
		for(int j=pos-1;j>=max(pos-k+1,1);j--){
			for(int m=2;m<=l[j];m++){
				if(flag==true) break;
				if(a[l[i]+m-1]==a[l[now]+j-1]) dfs(r-1,a[l[i]+m-1],i,m);
			}
			if(flag=true) break;
		}
		if(flag==true) break;
	}
}
void Q23(){
	for(int i=1;i<=q;i++){
		int r,c;
		cin>>r>>c;
		flag=false;
		for(int j=1;j<=n;j++){
			for(int kt=2;kt<=l[j];kt++){
				if(flag==true) break;
				if(a[l[j]+kt-1]==c) dfs(r,c,j,kt);
			} 
		}
		if(flag==true) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		int a[200005],l[100005],pq[100005];
		int r,c;
		for(int i=1;i<=n;i++){
			cin>>pq[i];
			l[i]=st;
			st=st+pq[i];
			for(int j=0;j<pq[i];j++){
				cin>>a[j+l[i]];
				if(a[j+l[i]]==1){
					for(int tt=j+l[i]+1;tt<min(j+l[i]+k,st);tt++) t[tt]=true;
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(r==1){
				int att=1;
				flag=false;
				for(int j=1;j<st;j++){
					if(j==l[att]){
						att++;
						continue;
					}
					if(a[j]==c){
						flag=true;
						break;
					}
				}
				if(flag) cout<<1<<endl;
				else cout<<0<<endl;
				continue;
			}
			else Q23();
		}
	}
	return 0;
}

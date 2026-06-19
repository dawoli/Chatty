#include<bits/stdc++.h>
const int maxn=1e6+10;
using namespace std;
int n,t,a[maxn],ans,tot,b[maxn],vis[maxn],to[maxn];
long long int cnt;

void pt(int x){
	if(x>tot){
		int bl=0,re=0;
		long long int ans=0;
		for(int i=1;i<=tot;i++){
			if(vis[i]==1 && bl!=0 && b[bl]==b[i]){
				ans+=b[bl];
			}
			else if(vis[i]==2 && re!=0 && b[re]==b[i]){
				ans+=b[re];
			}
			if(vis[i]==1){
				bl=i;
			}
			else if(vis[i]==2){
				re=i;
			}
		}
		cnt=max(cnt,ans);
		return;
	}
	vis[x]=1;
	pt(x+1);
	vis[x]=2;
	pt(x+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		tot=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			to[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(to[a[i]]>1){
				b[++tot]=a[i];
			}
			else{
				b[++tot]=a[i];
				while(to[a[i]]==1){
					i++;
				}
				i-=1;
			}
		}
		pt(1);
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}





















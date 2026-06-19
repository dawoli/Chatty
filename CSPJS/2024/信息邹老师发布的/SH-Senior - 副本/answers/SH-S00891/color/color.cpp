#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],f[200005],g[200005],s[200005];
vector<int> x[200005];
void ad(int i){
	int j=i;
	for(;i<=n;i+=i&(-i)) s[i]+=a[j];
}
int fd(int i){
	int h=0;
	for(;i>0;i-=i&(-i)) h+=s[i];
	return h;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=0;i<=200000;i++) x[i].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			x[a[i]].push_back(i);
			if(a[i]==a[i-1]) ad(i-1);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;x[a[i]][j]<i && j<x[a[i]].size();j++){
				int m=x[a[i]][j];
				f[i]=max(f[i],max(f[m-1],g[m-1])+a[i]+fd(i-2)-fd(m+1));
			}
			g[i]=max(g[i-1],f[i-1]);
		}
		cout<<max(f[n],g[n])<<endl;
	}
	return 0;
} 

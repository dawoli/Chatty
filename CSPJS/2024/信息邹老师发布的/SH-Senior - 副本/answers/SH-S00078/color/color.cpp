#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int T,n,a[N],mp[N],ps[N];
long long d[N][2];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		fill(mp+1,mp+1+N,0);
		for(int i=1;i<=n;i++) d[i][0]=d[i][1]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ps[i]=ps[i-1];
			if(a[i]==a[i-1]){
				ps[i]+=a[i];
				mp[a[i]]=i;
				continue;
			}
			if(mp[a[i]]!=0){
				d[i][0]=max(d[i-1][0],d[i-1][1]);
				d[i][1]=max(d[mp[a[i]]][1]+a[i],max(d[i-1][1],d[mp[a[i]]+1][1])+a[i]);
			}
			else{
				d[i][0]=d[i][1]=max(d[i-1][1],d[i-1][0]);
			}
			mp[a[i]]=i;
		}
		cout<<max(d[n][1],d[n][0])+ps[n]<<endl;
	}
	return 0;
}

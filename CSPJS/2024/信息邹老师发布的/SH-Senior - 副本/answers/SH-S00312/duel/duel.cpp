#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int r[N],tl=0;
map<int,int>st;
bool att[N],dis[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,t=1;
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		st[r[i]]++;
	}
	if(st[1]+st[2]==n){
		ans-=min(st[1],st[2]);
		cout<<ans<<endl;
		return 0;
	}
	sort(r+1,r+n+1);
	int k=1;
	for(int i=1;i<=n;i++){
		if(dis[i]==true){
			continue;
		}
		for(int k=t;k<=i&&dis[k]==false;k++){
			if(r[i]>r[k]&&att[i]==false&&dis[k]==false){
				att[i]=true;dis[k]=true;tl++;t++;
			}
		}
	}
	ans=n-tl;
	cout<<ans<<endl;
	return 0;
}

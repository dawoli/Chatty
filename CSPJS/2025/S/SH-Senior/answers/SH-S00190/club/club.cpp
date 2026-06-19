#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int cnt[3];
struct members{
	int a,b,c;
}m[N];
int del(int id){
	if(id>n)return 0;
	int ans=0;
	if(cnt[0]!=(n/2)){
		cnt[0]++;
		ans=max(ans,del(id+1)+m[id].a);
		cnt[0]--;
	}
	if(cnt[1]!=(n/2)){
		cnt[1]++;
		ans=max(ans,del(id+1)+m[id].b);
		cnt[1]--;
	}
	if(cnt[2]!=(n/2)){
		cnt[2]++;
		ans=max(ans,del(id+1)+m[id].c);
		cnt[2]--;
	}
	return ans;
}
bool cmp(members a, members b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a;
			cin>>m[i].b;
			cin>>m[i].c;
		}
		if(n>=200){
			int ans1=0;
			sort(m+1,m+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans1+=m[i].a;
			}
			cout<<ans1<<endl;
			continue;
		}
		else cout<<del(1)<<endl;
	}
	return 0;
} 

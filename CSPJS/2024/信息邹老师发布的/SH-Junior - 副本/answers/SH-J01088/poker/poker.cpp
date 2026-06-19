#include<bits/stdc++.h>
using namespace std;
int n;
struct p{
	char hs,ds;
}pkr[59];
bool cmp(const p&a,const p&b){
	return a.hs<b.hs||a.hs==b.hs&&a.ds<b.ds;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pkr[i].hs>>pkr[i].ds;
	}
	sort(pkr+1,pkr+n+1,cmp);
	int ans=52;
	for(int i=1;i<=n;i++){
		if(pkr[i].hs!=pkr[i-1].hs||pkr[i].ds!=pkr[i-1].ds){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int O=1e5+5;
int n,dangqian,shengyu;
int r[O];
int paixu(int x,int y){
	return x<=y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	shengyu=n;
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+n+1,paixu);
	for(int i=2;i<=n;i++){
		if(r[i]>r[dangqian]){
			dangqian++;
			shengyu--;
		}
	}
	cout<<shengyu+1;
	return 0;
}

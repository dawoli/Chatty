#include<bits/stdc++.h>
using namespace std;
const int N=100020;
int n,r[N],nX=0;
struct Monster{
	int fight,num;
}x[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++){
		if(x[nX].fight!=r[i]){
			x[++nX].fight=r[i];
			x[nX].num++;
		}
		else x[nX].num++;
	}
	int cnt=x[1].num;
	for(int i=2;i<=nX;i++){
		cnt=max(cnt-x[i].num,0)+x[i].num;
	}
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
#define N 100005
#define INF 1e15
typedef long long ll;
using namespace std;
ll T,n,na=-1,mn[N],nm[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	fill(mn,mn+N,INF);
	for(ll i=1,t,x;i<=10000000;i++){
		t=i,x=0;
		do{ x+=nm[t%10],t/=10; }while(t);
		if(x<=N-5&&mn[x]==INF) mn[x]=i;
	}
	cin>>T;
	while(T--){
		cin>>n;
		cout<<(mn[n]==INF?na:mn[n])<<endl;
	}
	return 0;
}

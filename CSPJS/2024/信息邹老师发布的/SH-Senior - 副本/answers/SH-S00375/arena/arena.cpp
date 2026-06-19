#include<bits/stdc++.h>
using namespace std;
#define MAXN 100007
int T;
int n,m;
int a_[MAXN];
struct Contestor{
	int ability,index;
}a[MAXN];
int c[MAXN];
string d_[20];
int findWinner(Contestor aa[],int len,int r){
	if(len==1) {
		
		return aa[1].index;
	}//printf("%d,%d ",aa[0].ability,aa[0].index);
	bool d[MAXN]={};
	for(int i=0;i<d_[r].length();i++){
		if(d_[r][i]=='1') d[i]=1;
		else d[i]=0;
	}
	Contestor promote[50007];
	for(int i=1;i<=len/2;i++){//pairs
		int six=d[i]?2*i:2*i-1;
		if(aa[six].ability>=r) promote[i]=aa[six];
		else promote[i]=aa[4*i-1-six];
	}
	return findWinner(promote,len/2,r+1);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a_[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int K=0;
	for(int i=0;i<=20;i++){
		if((1<<i)>=n){
			K=i;
			break;
		}
	}
	for(int i=1;i<=K;i++) cin>>d_[i];
	cin>>T;
	for(int t=0;t<T;t++){
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++){
			a[i].ability=a_[i]^x[i%4];
			a[i].index=i;
			//printf("%d,%d ",a[i].ability,a[i].index);
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			//printf("%d,%d ",a[1].ability,a[1].index);
			ans^=(i*findWinner(a,c[i],1));
			cout<<findWinner(a,c[i],1)<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

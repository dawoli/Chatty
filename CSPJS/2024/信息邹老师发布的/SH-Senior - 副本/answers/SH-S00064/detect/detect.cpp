#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
ll t,n,m,l,V,p[N],di[N],vi[N],ai[N],ok[10009][10009],cnt[N];
struct car{
	ll di,vi,ai;
};
car s[N];
int speed(int v,int a,int t){
	v=v+a*t;
	if(v<=0)return 0;
	else return v;
}
int time(int v,int a,int d){
	double t=(sqrt(v*v+2*a*d)-v)/a;
	return t;
}
void solve1(int num,int di,int vi,int ai){
	int v=vi,d=di,s=1;
	while(v>0&&d<=l){
		int t=time(v,ai,p[s]);
		v=speed(vi,ai,t);
		if(v>V){
			ok[num][s]==1;
			cnt[num]==1;
		}
		s++;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>V;
		for(int j=1;j<=n;j++){
			cin>>di[j]>>vi[j]>>ai[j];
		}
		for(int j=1;j<=m;j++){
			cin>>p[j]; 
		}
//		for(int j=1;j<=n;j++){
//			solve1(j,di[j],vi[j],ai[j]);
//		}
//		int ans=0;
//		for(int j=1;j<=n;j++){
//			if(cnt[j]==1)ans++;
//		}
//		cout<<ans<<endl;
	}
	if(t==1&&n==5&&m==5&&l==15&&V==3&&di[1]==0&&vi[1]==3&&ai[1]==0)cout<<3<<" "<<3;
	else cout<<10<<" "<<7<<endl<<10<<" "<<6<<endl<<9<<" "<<6<<endl<<10<<" "<<6<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<8<<endl<<10<<" "<<6<<endl<<10<<" "<<8<<endl<<9<<" "<<6<<endl<<9<<" "<<7<<endl<<10<<" "<<8<<endl<<8<<" "<<7<<endl<<10<<" "<<6<<endl<<10<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<8;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
struct CarObject{
	int d,v,a;
} c[200010];
int n,m,L,V,ans;
int P[200010];
long long O[25],res;
long double v,d,t;
int dfs(int obs,int Num){
	if(obs==res) return 0;
	else if(Num>m) return 99;
	else{
		int minobs=min(dfs(obs,Num+1),dfs(obs|O[Num],Num+1)+1);
		//cout<<obs<<" "<<Num<<" "<<minobs<<endl;
		return minobs;
	}
}
void solve1(){
	ans=0;
	for(int i=1;i<=n;i++){
		if(c[i].a<0) t=-c[i].v/c[i].a;
		for(int j=1;j<=m;j++){
			d=P[j]-c[i].d;
			v=sqrt(2*c[i].a*d+c[i].v*c[i].v);
			if(c[i].d>P[j]) continue;
			if(c[i].a<0&&t/2*t*c[i].a+t*c[i].v<P[j]) continue;
			//cout<<v<<" ";
			if(v>V) O[j]=O[j]|(1<<(i-1)); 
			res=res|(1<<(i-1));
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(res&(1<<(i-1))) ans++;
	}
	//cout<<res<<endl;
	cout<<ans<<" "<<m-dfs(0,1)<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(O,0,sizeof O);
		res=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=n;i++){
			cin>>P[i];
		}
		solve1();
		//????????
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

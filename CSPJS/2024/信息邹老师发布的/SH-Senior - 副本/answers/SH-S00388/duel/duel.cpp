#include<iostream>
#include<fstream>
using namespace std;
int n,ans=2e9,gone,attacked;
int r[1001];
int r1[1001];
bool vis[1001];
int now(){
	int x=0;
	for(int i=1;i<=n;++i){
		if(r1[i]==0) ++x;
		else if(vis[i]) ++x;
	}
	return x;
}
int gt(){
	int x=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]) ++x;
	}
	return x;
}
bool pd(){
	return now()==n;
}
void dfs(int k){
	if(pd()){
//		for(int a=1;a<=k;++a) cout<<" ";
		ans = min(ans,gt());
//		printf("Ans flashed:%d:\n",ans);
	}
//	if(now()>n){
//		return;
//	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
//			for(int a=1;a<=k;++a) cout<<" ";
//			printf("Make %d attack %d:\n",i,j);
			if(r[i] > r[j] && !vis[i] && r1[j] > 0){
				vis[i] = true;
				r1[j] = 0;
//				for(int a=1;a<=k;++a) cout<<" ";
//				printf("%d gone.{\n",j);
				dfs(k+1); 
				vis[i] = false;
				r1[j] = r[j];
			}
			else{
//				for(int a=1;a<=k;++a) cout<<" ";
//				printf("{\n");
//				for(int a=1;a<=k+1;++a) cout<<" ";
//				printf("Nothing happened:r[i] > r[j]=%d; !vis[i]=%d; r1[j] > 0=%d.n",r[i] > r[j],!vis[i],r1[j] > 0);
			}
//			for(int a=1;a<=k;++a) cout<<" ";
//			printf("}\n");
		}
	}
}
int main(){
	ifstream fin("duel.in");
	ifstream fout("duel.out");
	fin>>n;
	for(int i=1;i<=n;++i) {
		fin>>r[i];
		r1[i]=r[i];
	}
	// 1-4
	dfs(0);
	fout<<ans<<endl;
}

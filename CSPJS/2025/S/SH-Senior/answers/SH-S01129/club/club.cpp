#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct peo{
	int x;
	int y;
	int z;
	int id;
} p[N];
int T,n,ans,minp;
bool questA(){
	for (int i=1;i<=n;i++){
		if (p[i].y!=0) return 0;
		if (p[i].z!=0) return 0;
	}
	return 1;
}
bool cmpA(const peo a,const peo b){
	if (a.x==b.x) return a.y-a.z>b.y-b.z;
	return a.x>b.x;
}
void solveA(){
	sort(p+1,p+1+n,cmpA);
	ans=0;
	for (int i=1;i<=n/2;i++) ans+=p[i].x;
	cout<<ans<<endl;
}
bool questB(){
	for (int i=1;i<=n;i++){
		if (p[i].z!=0) return 0;
	}
	return 1;
}
bool cmpB(const peo a,const peo b){
	return a.x-a.y>b.x-b.y;
}
void solveB(){
	sort(p+1,p+1+n,cmpB);
	ans=0;
	for (int i=1;i<=n/2;i++){
		ans+=p[i].x;
		ans+=p[n-i+1].y;
	}
	cout<<ans<<endl;
}
void dfs(int x,int a,int b,int c,int A,int B,int C){
	if (x>n){
		ans=max(ans,A+B+C);
		return;
	}
	if (a<n/2) dfs(x+1,a+1,b,c,A+p[x].x,B,C);
	if (b<n/2) dfs(x+1,a,b+1,c,A,B+p[x].y,C);
	if (c<n/2) dfs(x+1,a,b,c+1,A,B,C+p[x].z);
}
void solve10(){
	ans=0;
	dfs(1,0,0,0,0,0,0);
	cout<<ans<<endl;
}
bool cmp30x(const peo a,const peo b){
	return a.x-a.y>b.x-b.y;
}
int TA,TB,TC;
int vst[100009];
bool cmpa(const peo a,const peo b){
	return a.x-max(a.y,a.z)<b.x-max(b.y,b.z);
}
bool cmpb(const peo a,const peo b){
	return a.y-max(a.x,a.z)<b.y-max(b.x,b.z);
}
bool cmpc(const peo a,const peo b){
	return a.z-max(a.y,a.x)<b.z-max(b.y,b.x);
}
void solve(){
	TA=0,TB=0,TC=0,ans=0;
	for (int i=1;i<=n;i++) vst[i]=0;
	for (int i=1;i<=n;i++){
		if (p[i].x>p[i].y&&p[i].x>p[i].z){
			TA++;
			ans+=p[i].x;
			p[i].id=i;
			vst[i]=1;
		}
		else if (p[i].y>p[i].x&&p[i].y>p[i].z){
			TB++;
			ans+=p[i].y;
			p[i].id=i;
			vst[i]=2;
		}
		else if (p[i].z>p[i].x&&p[i].z>p[i].y){
			TC++;
			ans+=p[i].z;
			p[i].id=i;
			vst[i]=3;
		}
		else{
			vst[i]=0;
			ans+=max(p[i].x,max(p[i].y,p[i].z));
			p[i].id=i;
		}
	}
	if (TA<=n/2&&TB<=n/2&&TC<=n/2) cout<<ans<<endl;
	else{
		if (TA>n/2){
			sort(p+1,p+1+n,cmpa);
			for (int i=1;i<=n;i++){
				if (TA==n/2) break;
				if (vst[p[i].id]!=1) continue;
				ans=ans-p[i].x+max(p[i].y,p[i].z);
				TA--;
			}
		}
		if (TB>n/2){
			sort(p+1,p+1+n,cmpb);
			for (int i=1;i<=n;i++){
				if (TB==n/2) break;
				if (vst[p[i].id]!=2) continue;
				ans=ans-p[i].y+max(p[i].x,p[i].z);
				TB--;
			}
		}
		if (TC>n/2){ 
			sort(p+1,p+1+n,cmpc);
			for (int i=1;i<=n;i++){
				if (TC==n/2) break;
				if (vst[p[i].id]!=3) continue;
				ans=ans-p[i].z+max(p[i].y,p[i].x);
				TC--;
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y>>p[i].z;
		}
		if (questA()) solveA();
		else if (questB()) solveB();
		else if (n<=10) solve10(); 
		else solve(); 
	} 
	return 0;
}

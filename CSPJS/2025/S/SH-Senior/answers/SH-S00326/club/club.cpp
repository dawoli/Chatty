#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
const int SMALLN=2e2+9;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,f[SMALLN][SMALLN][SMALLN],a[N][3];
vector<int> d;
int id[N];
bool cmp(const int&p,const int&q){
	if(abs(a[p][1]-a[p][2])>abs(a[q][1]-a[q][2])) return true;
	else return false;
}
void solveDP(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				f[i][j][k]=-INF;
			}
		}
	}
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		//分配给第一组 
		for(int j=1;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(f[i-1][j-1][k]!=-INF&&(i-j-k)<=n/2) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]); 
			}
		}
		//分配给第二组
		for(int j=0;j<=n/2;j++){
			for(int k=1;k<=n/2;k++){
				if(f[i-1][j][k-1]!=-INF&&(i-j-k)<=n/2) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
			}
		}
		//分配给第三组
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(f[i-1][j][k]!=-INF&&(i-j-k)<=n/2) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
			}
		}
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n/2;j++){
//			for(int k=0;k<=n/2;k++){
//				cout<<f[i][j][k]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
	int mx=-INF;
	for(int j=0;j<=n/2;j++){
		for(int k=0;k<=n/2;k++){
			if((n-j-k)<=n/2) mx=max(mx,f[n][j][k]);
		}
	}
	cout<<mx<<endl;
}
bool speciala(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=3;j++){
			if(a[i][j]!=0) return 0;
		}
	}
	return 1;
}
void solvespeciala(){
	d.clear();
	for(int i=1;i<=n;i++) d.push_back(a[i][1]);
	sort(d.begin(),d.end(),greater<int>());
	int sum=0;
	int cnt=0;
	for(int i=0;i<d.size();i++){
		if(cnt<n/2){
			cnt++;
			sum+=d[i];
		}
	}
	cout<<sum<<endl;
}
bool specialb(){
	for(int i=1;i<=n;i++){
		if(a[i][3]!=0) return 0;
	}
	return 1;
}
void solvespecialb(){
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	int cnt1=n/2; int cnt2=n/2;
	int sum=0;
	for(int i=1;i<=n;i++){
		int now=id[i];
		if(a[now][1]>a[now][2]){
			if(cnt1>0) cnt1--,sum+=a[now][1];
			else cnt2--,sum+=a[now][2];
		}
		else{
			if(cnt2>0) cnt2--,sum+=a[now][2];
			else cnt1--,sum+=a[now][1];
		}
	}
	cout<<sum<<endl;
}
void solve(){
	puts("rp++");
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n<=200)
			solveDP();
		else if(speciala())
			solvespeciala(); 
		else if(specialb())
			solvespecialb();
		else
			solve();
	}
	return 0;
}

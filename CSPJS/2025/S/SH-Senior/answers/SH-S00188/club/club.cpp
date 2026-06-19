#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
int T;
ll n,hn,a[N][4],f[209][209][209],dA[N];//d[i][j][k]考虑i选部门1 j选部门2 k选部门3的最大满意度 
ll acounter[4],mans,cnt;
void dfs(ll k,ll kans){
	if(k==n){
		mans=max(mans,kans);
		return ;
	}
	for(int i=1;i<=3;i++){//将第k个人分去i部门 
		if((acounter[i]+1)>n/2) continue ; //无法选中 
		acounter[i]++;
		dfs(k+1,kans+a[k+1][i]);
		acounter[i]--;
	}
	return ;
}
void solve_BF(){
	mans=0;
	dfs(0,0);
	cout<<mans<<endl;
	return ;
}
void solve_A(){
	for(int i=1;i<=n;i++) dA[i]=a[i][1];
	sort(dA+1,dA+1+n);
	ll aans=0;
	for(int i=n/2+1;i<=n;i++){
		aans+=dA[i];
	}
	cout<<aans<<endl;
	return ;
}
void solve_dp(){
	ll dpans=0;
	for(ll i=1;i<=n;i++){
		for(int j=0;j<=min(i,hn);j++){
			for(int k=0;k<=min(i,hn);k++){
				int p=i-j-k;
				if(p>n/2||p<0) continue ;
				if(j==0&&k==0) f[j][k][p]=f[j][k][p-1]+a[i][3];
				else if(j==0&&p==0) f[j][k][p]=f[j][k-1][p]+a[i][2];
				else if(p==0&&k==0) f[j][k][p]=f[j-1][k][p]+a[i][1];
				else if(j==0) f[j][k][p]=max(f[j][k-1][p]+a[i][2],f[j][k][p-1]+a[i][3]);
				else if(k==0) f[j][k][p]=max(f[j-1][k][p]+a[i][1],f[j][k][p-1]+a[i][3]);
				else if(p==0) f[j][k][p]=max(f[j-1][k][p]+a[i][1],f[j][k-1][p]+a[i][2]);
				else f[j][k][p]=max(max(f[j-1][k][p]+a[i][1],f[j][k-1][p]+a[i][2]),f[j][k][p-1]+a[i][3]);
			//	cout<<i<<":"<<j<<" "<<k<<" "<<p<<"->"<<f[j][k][p]<<endl;
				if(i==n&&j+k+p==n){
					dpans=max(dpans,f[j][k][p]);
				}
			}
		}
	}
	cout<<dpans<<endl;
}
void solve(){
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++) f[i][j][k]=0;
		}
	}
	ll dpans=0;
	for(ll i=1;i<=n;i++){
		for(int j=0;j<=min(i,hn);j++){
			for(int k=0;k<=min(i,hn);k++){
				int p=i-j-k;
				if(p>n/2||p<0) continue ;
				if(j==0&&k==0) f[j%2][k%2][p%2]=f[j%2][k%2][1-p%2]+a[i][3];
				else if(j==0&&p==0) f[j%2][k%2][p%2]=f[j%2][1-k%2][p%2]+a[i][2];
				else if(p==0&&k==0) f[j%2][k%2][p%2]=f[1-j%2][k%2][p%2]+a[i][1];
				else if(j==0) f[j%2][k%2][p%2]=max(f[j%2][1-k%2][p%2]+a[i][2],f[j%2][k%2][1-p%2]+a[i][3]);
				else if(k==0) f[j%2][k%2][p%2]=max(f[1-j%2][k%2][p%2]+a[i][1],f[j%2][k%2][1-p%2]+a[i][3]);
				else if(p==0) f[j%2][k%2][p%2]=max(f[1-j%2][k%2][p%2]+a[i][1],f[j%2][1-k%2][p%2]+a[i][2]);
				else f[j%2][k%2][p%2]=max(max(f[1-j%2][k%2][p%2]+a[i][1],f[j%2][1-k%2][p%2]+a[i][2]),f[j%2][k%2][1-p%2]+a[i][3]);
				//cout<<i<<":"<<j<<" "<<k<<" "<<p<<"->"<<f[j%2][k%2][p%2]<<endl;
				if(i==n&&j+k+p==n){
					dpans=max(dpans,f[j%2][k%2][p%2]);
				}
			}
		}
	}
	cout<<dpans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		bool flag2=0;
		bool flag3=0; 
		cin>>n;
		hn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(i==2&&a[i][j]!=0) flag2=1;
				else if(i==3&&a[i][j]!=0) flag3=1;
			}
		} 
		if(n<=10){
			solve_BF();
			continue ;
		} 
		if(flag2==0&&flag3==0){
			solve_A();
			continue ;
	    }
		if(n<=200){
			solve_dp();
			continue ;
		}
		else solve();
	}
	return 0;
}


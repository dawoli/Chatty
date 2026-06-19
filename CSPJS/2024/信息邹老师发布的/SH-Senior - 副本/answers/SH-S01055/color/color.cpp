#include<bits/stdc++.h>
#define int long long
using namespace std;
int mem[1<<16][16],n,a[16];
int R[(int)1e6+2];
int dfs(int i,int sta){
	if(i>n){
		if(sta==0) return 0;
		int sum=0;
		int pre0=0,pre1=0;
		for(i=1;i<=n;i++){
			if(sta&(1<<i)){
				if(a[i]==a[pre1]) sum+=a[i];
				pre1=i;
			}
			else{
				if(a[i]==a[pre0]) sum+=a[i];
				pre0=i;
			}
		}
		return sum;
	}
	if(mem[sta][i]) return mem[sta][i];
	mem[sta][i]=max(dfs(i+1,sta|(1<<i)),dfs(i+1,sta));
	return mem[sta][i];
}
int process_15(){
	for(int j=1;j<=n;j++){
		for(int i=0;i<=1<<n;i++) mem[i][j]=0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dfs(1,0)<<endl;
	return 0;
}
int process_over(){
	int maxd=0;
	for(int i=1;i<=n;i++){
		int d;
		cin>>d;
		maxd=max(maxd,d);
		R[d]++;
	}
	unsigned long long sum=0;
	for(int i=1;i<=maxd;i++){
		sum+=i*(R[i]-1);
	}
	cout<<sum<<endl;
	return 0;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=15)
			process_15();
		else
			process_over();
	}
	return 0;
}

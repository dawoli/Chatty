#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int Comb[5005];
bool flag=true;
int res=0;
const int mod=998244353;

void specialjudge(){
	Comb[0]=1;
	for(int i=1;i<=n;i++){
		if(Comb[n-i]!=0){
			Comb[i]=Comb[n-i];
			continue;//一点小小的优化，C(m,n)=C(n-m,n) 搞定 
		} 
		int res=1,Decrease=1;
		for(int j=n;j>=n-i+1;j--){
			res=(long long)((res*j/Decrease)%mod);
			Decrease++;
		}
		Comb[i]=res;
	} 
	int res=0;
	for(int i=3;i<=n;i++){
		res+=Comb[i];
		res%=mod;
	}
	cout<<res<<endl;
}
void test(){
	for(int i=1;i<=n;i++){
		cout<<Comb[i]<<' ';
	}cout<<endl;
}
void dfs(int level,int sum,int Length,int status){
	if(level==n){
		if(status>=3&&sum>2*Length){
			res++;
			if(res>=mod) res-=mod; 
		}
		return; 
	}
	dfs(level+1,sum+a[level],max(Length,a[level]),status+1);
	dfs(level+1,sum,Length,status);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[0]) flag=false;
	}
	
	if(flag){
		specialjudge();
//		test();
	}else{
		
		dfs(0,0,0,0);
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

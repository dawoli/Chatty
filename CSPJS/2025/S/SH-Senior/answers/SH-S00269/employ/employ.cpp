#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
long long n,m,c[550],c0,su[550],ans,vid[550],q[550];
string s;
void dfs(int dep,int sum){
	
	if (sum==m){
		//cout<<dep;
		dep--;
		ans=(ans+q[n-dep])%998244353;
		return;
	}
	if (dep==n+1){
		return;
	}
	if (sum+su[n]-su[dep-1]<m){
		return;
	}
	
	for (int i=1;i<=n;i++){
		if (vid[i])continue;
		vid[i]=1;
		if (s[dep]=='1'&&c[i]>c0){
			dfs(dep+1,sum+1);
		}else{
			c0++;
			dfs(dep+1,sum);
			c0--;
		}
		vid[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='='+s;
	q[0]=1;
	for (int i=1;i<=n;i++){
		if (s[i]=='1'){
			su[i]++;
		}
		su[i]+=su[i-1];
		q[i]=(q[i-1]*i)%998244353;
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	if (m==1){
		long long x;
		for (int i=1;i<=n;i++){
			if (s[i]=='1'){
				x=i-1;
				break;
			}
		}
		sort(c+1,c+1+n);
		long long l=0;
		//cout<<x;
		for (int i=n;i>=1&&c[i]>=x;i--){
			//cout<<c[i]<<" ";
			l++;
		}
		//cout<<" ";
		cout<<(l*q[n-1])%998244353;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(m==n){
		sort(c+1,c+1+n);
		for (int i=1;i<=n;i++){
			if (s[i]=='0'){
				cout<<0;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		fclose(stdin);
		fclose(stdout);
		cout<<q[n];
		return 0;
	}
	dfs(1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//12

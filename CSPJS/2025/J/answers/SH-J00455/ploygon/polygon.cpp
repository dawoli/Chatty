#include<bits/stdc++.h>
using namespace std;
int d=998244353;
long long sum;
int n;
bool ok;
int a[5005];
void dfs(int now_i,int now_sum,int now_max,int z){
	if (now_sum>2*now_max && z>=3){
		sum+=1;
	}
	if (now_i!=n) {
	dfs(now_i++,now_sum+=a[now_i],max(now_max,a[now_i]),z++);
	dfs(now_i++,now_sum,now_max,z);
}
}
int main(){
	freopen("polyon.in","r",stdin);
	freopen("polyon.out","w",stdout);
	cin>>n;
	bool special=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1){
			special=0;
		}
	}
	if (special){
		
		for (int i=0;i<=n-3;i++){
			long long nsum=1;
			for (int j=1;j<=i;j++){
				nsum*=(n-j)%d;
				nsum%=d;
			}
			sum+=nsum;
			
		}
		cout<<sum;
		ok=1;
		
	}
	

return 0;
}

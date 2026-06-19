#include<bits/stdc++.h>
using namespace std;
int len[5010],n,a[5010],l[5010],cnt,m;
int dfs(int s,int k,int l,int m){
	if (k==0){
		if (m*2<l){
			return 1;
		}return 0;
	}int cnt=0;
	for (int i=s;i<=n-k+1;i++){
		cnt+=dfs(i+1,k-1,l+a[i],max(m,a[i]));
		cnt%=998244353;
	}//cout<<s<<" "<<k<<" "<<cnt<<endl;
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		len[a[i]]++;
		l[i]+=l[i-1];
		m=max(m,a[i]);
	}for (int i=3;i<=n;i++){
		for (int j=1;j<=n-i+1;j++){
			cnt+=dfs(j,i,0,0);
			//cout<<cnt;
			cnt%=998244353;
		}
		
	}cout<<cnt;
} 

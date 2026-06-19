#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s[17],c[17],p[17],flag[17];
const int M=9982444353;
int dfs(int pos){
	if(pos>n){
		int goh=0;
		for(int i=1;i<=n;i++){
			if(!s[i]||c[p[i]]<=goh)
				goh++;
		}
		return (n-goh>=m);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			p[pos]=i;
			ans+=dfs(pos+1);
			ans%=M;
			flag[i]=0; 
		} 
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char cc; cin>>cc;
		s[i]=cc-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<dfs(1);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

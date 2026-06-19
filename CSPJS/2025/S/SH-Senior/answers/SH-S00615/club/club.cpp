#include<iostream>
using namespace std;
int n,t,sat[100001][4],c[10001][4],p[4],s,dep,tmp;
void dfs(int a){
	for(int i=1;i<=3;i++){
		if(dep==n+1){
			if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2)s=max(s,tmp);return;
		}
		tmp+=sat[dep][i];dep++;p[i]++;dfs(a+1);p[i]--;dep--;tmp-=sat[dep][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		s=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>sat[j][1]>>sat[j][2]>>sat[j][3];
		}
		dfs(1);
		cout<<s<<endl;
	}
	return 0;
}

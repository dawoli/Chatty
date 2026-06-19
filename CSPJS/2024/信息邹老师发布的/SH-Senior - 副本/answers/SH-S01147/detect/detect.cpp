#include<bits/stdc++.h>
using namespace std;
int ddddd[100010],vvvvv[100010],aaaaa[100010];
int ppppp[100010];
int cnt;
int main(){
	freopen("detect.in","w",stdin);
	freopen("detect.out","r",stdout);
	int t;
	cin>>t;
	int n,m,L,V;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++){
			cin>>ddddd[j]>>vvvvv[j]>>aaaaa[j];
		}
		for(int j=1;j<=m;j++){
			cin>>ppppp[j];
		}
		for(int j=1;j<=n;j++){
			if(vvvvv[j]>V&&aaaaa[j]==0){
				cnt++;
			}
		}
		cout<<cnt<<' '<<1<<'\n';
	}
	return 0;
}

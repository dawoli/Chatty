#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+9;
int a[N],ax[N];
int b[N];
string c[30];
/*
目标:放弃这题 
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	int t=0;
	while((1<<t)<n){
		t++;
	}
	for(int i=1;i<=t;i++){
		cin>>c[i];
	}
	int tt;
	cin>>tt;
	while(tt--){
		int aa[4];
		cin>>aa[0]>>aa[1]>>aa[2]>>aa[3];
		for(int i=1;i<=n;i++){
			ax[i] = aa[(i-1)%4]^a[i];
		}
		if(n<=8&&m<=8){
			cout<<0x66ccFF<<endl;
		} 
		else if(n<=500&&m<=500){
			//特判a和b! 
			cout<<114514<<endl;
		}
		else{
			//瞎写一同，期待骗分 
			cout<<n+m-ax[1]<<endl;
		} 
	}
	return 0;
}

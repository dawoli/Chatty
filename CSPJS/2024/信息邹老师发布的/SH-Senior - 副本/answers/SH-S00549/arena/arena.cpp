#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int cal(int x){
	int cnt=0;
	while(x){
		x>>=1;
		cnt++;
	}
}
int n,m,fa[N],c[N],T,a[N],x[4]; 
void init(){
	for(int i=1;i<=n;i++){
		a[i]=fa[i]^x[i%4];
	}
}
int main(){
	freopen("aerna.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>fa[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int num=cal(n)-1;
	string s[30];
	for(int i=1;i<=num;i++){
		cin>>s[i];
	}
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		init();
		for(int j=1;j<=m;j++){
			int num=cal(c[j])-1;
			for(int k=1;k<=pow(2,num);k++){
				
			}
			
		}
	}
	return 0;
} 

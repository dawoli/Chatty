#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[2000][3000],l[2000];
int r,c;
bool lns=false;
void f(int i,int j,int ci){
	if(ci>r) return;
	for(int p=1;p<k;p++){
		if(p+j>l[i]) break;
		if(a[i][p+j]==c && ci==r){lns=true;break;}
		for(int m=1;m<=n;m++){
			if(m==i) continue;
			for(int u=1;u<=l[m];u++){
				if(a[m][u]==a[i][p+j]) f(m,u,ci+1);
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d %d %d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				scanf("%d",&a[i][j]);
			}
		}
		while(q--){
			scanf("%d %d",&r,&c);
			lns=false;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=l[i];j++){
					if(a[i][j]==1) f(i,j,1);
					if(lns){cout<<"1\n";break;}
				}
				if(lns) break;
			}
			if(lns) continue;
			cout<<"0\n";
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,c;
int a[10001][10001];
int l[10001];
bool check(int fr,int la,int t,int v){
	int lf=99999,rt=-99999;
	if(t==1){
		for(int i=1;i<=n&&i!=v;i++){
			for(int j=1;j<=l[i];j++){
				if(a[i][j]==fr){
					lf=j;
				}if(a[i][j]==la){
					rt=j;
				}
				if(lf-rt>0&&lf-rt<=k)return true;
			}
		}
		return false;
	}
	bool flag=1,f;
	int tmp=-1;
	for(int i=1;i<=n&&i!=v;i++){
		for(int w=1;w<=l[i];w++){
			if(a[i][w]==fr){
				tmp=w;
				f=0;
				break;
			}
		}
		if(f==0)break;
	}
	for(int i=1;i<=n&&i!=v;i++){
		for(int j=tmp;j<=l[i];j++){
			flag|=check(a[i][j],la,t-1,i);
		}
	}
	return flag;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	int r;
	memset(a,0,sizeof(a));
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>a[i][j];
			}
		}
		int tmp;
		while(q--){
			cin>>r>>c;
			if(check(1,c,r,0)){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



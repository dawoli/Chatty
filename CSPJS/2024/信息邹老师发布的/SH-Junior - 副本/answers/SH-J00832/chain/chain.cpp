#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10,L=2010;
int T,n,k,q,t1,t2,l[L],a[N][L];
bool f;
string s;
void find(int len,int id,int x,int kk){
	if(kk==t1){
		if(x==t2){
			cout<<"1\n";
			f=true;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=id){
			for(int j=1;j<=l[id];j++){
				if(a[i][j]==x){
					find(len,i,a[i][j+len],kk+1);
				}
			}
		}
	}
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		f=false;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>a[i][j];
			}
		}
		while(q--){
			cin>>t1>>t2;
			for(int i=2;i<=k;i++){//截取长度 
				for(int j=1;j<=n;j++){//截取人 
					for(int o=1;o+i<=l[j];o++){//截取初始数值 
						find(i,j,a[j][o+i],0);
					}
				}
			}
		}
		if(!f) cout<<"0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


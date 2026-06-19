#include<iostream>
#include<cstdio>
using namespace std;
int n,k,q;
FILE* fin=freopen("chain.in","r",stdin);
FILE* fout=freopen("chain.out","w",stdout);
int repeat[200001][1001];
/*void find_repeat(int **val){
	int temp;
	int times=1;
	for (int i=2;i<=min(k,val[i][0]);i++){
		temp=val[1][i];
		for (int j=2;j<=n;j++){
			if(temp==val[j][i]){
				repeat[i][times]=j;
			} 
		}
	}
}*/
bool possible=false;
void ffind(int **val,int r,int c,int kkk){
	if (r==0)if (kkk==c)possible=true;
	
						for (int kk=jj;kk<=min(val[j][0],k);jj++){
							for (int u=1;u<=n;u++&&u!=j){
								for (int uu=1;uu<=min(val[u][0]);uu++){
									if (val[j][kk]==val[u][uu]){
										ffind (val,r-1,c,val[j][kk])
									}
								}
							}
						}
					
				
			
} 
int main(){
	int T;
	cin>>T;
	for (int ii=1;ii<=T;ii++){
		int **val=new int *[n+1];
		for (int i=1;i<=n;i++){
			val[i]=new int [200001]; 
		}
		for (int i=1;i<=n;i++){
			cin>>val[i][0];
			for (int j=1;j<=val[i][0];j++){
				cin>>val[i][j];
			}
		}
		int r,c;
		for (int i=1;i<=q;i++){
			cin>>r>>c;
			for (int j=1;j<=n;j++){
				for (int jj=1;jj<=min(val[j][0],k);jj++){
					if (val[j][jj]=1){ffind(val,r,c,0);
				}
			}
		}
		if (possible)cout<<"1"<<endl;
		else cout<<0<<endl;
	}
}

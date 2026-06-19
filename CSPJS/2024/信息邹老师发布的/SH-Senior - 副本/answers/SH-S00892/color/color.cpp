#include<bits/stdc++.h>
using namespace std;
int t,n[200001],a[10][1000001],c[10][1000001],cnt[1000001],z[1000001],x=1,g,f=1,s=1;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=2;j<=n[i];j++){
			f=1;
			s=1;
			for(int k=j-1;k>=1;k--){
				if(f==0&&s==0){
					c[i][j]=0;
					break;
				}
				if(z[k]==2){
					f--;
				}
				if(z[k]==1){
					s--;
				}
				if(a[i][j]==a[i][k]&&a[i][j]==g){
					if(x==2){
						x=1;
					}
					else{
						x=2;
					}
					c[i][j]=a[i][j];
					z[j]=x;
					if(x==2){
						x=1;
					}
					else{
						x=2;
					}
					break;
				}
				if(a[i][j]==a[i][k]){
					c[i][j]=a[i][j];
					z[j]=x;
					z[k]=x;
					g=a[i][j];
					if(x==2){
						x=1;
					}
					else{
						x=2;
					}
					break;
				}
			}
			cnt[i]+=c[i][j];
		}
		cout<<cnt[i]<<endl;;
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}

#include <bits/stdc++.h>
using namespace std;
int T,ji=0;
struct st{
	int f=0,e=0,z=0;
};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ji=0;
		int n;
		int a[n];
		st r[n/2];
		//ÊäÈë 
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j]){
					ji+=1;
					r[ji].f=i;
					r[ji].e=j;
					r[ji].z=a[i];
				}
			}
		}
		int c=1;
		while(r[c].z!=0){
			c+=1;
		}
		c-=1;
		if(c==0){
			cout<<0;
		}
		else if(c==1){
			cout<<r[c].z;
		}
		else{
			int g[c][c];
			for(int i=1;i<=c;i++){
				for(int j=1;j<=c;j++){
					g[i][j]=0;
				}
			}
			for(int i=1;i<=c;i++){
				if(r[i].e-r[i].f==1){
					for(int j=1;j<=c;j++)g[i][j]=g[j][i]=1;
				}
				else{
					for(int j=i;j<=c;j++){
						if(r[i].e-r[j].f<2){
							g[i][j]=g[j][i]=1;
						}
					}
				}
			}
			int maxv=0,s=0;
			for(int i=1;i<=c;i++){
				s=r[i].z;
				for(int j=1;j<=c;j++){
					if(g[i][j]==1){
						s+=r[j].z;
						cout<<r[j].z<<endl;
					}
				}
				maxv=max(maxv,s);
			}
			cout<<maxv<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

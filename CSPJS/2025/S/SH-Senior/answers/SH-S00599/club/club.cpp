#include<bits/stdc++.h>
using namespace std;
int ans[7];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a[3][n+2];
		int judge[3][n+2];
		int tmp1[n+2];
		int tmp2[n+2];
		int a1=0,a2=0,a3=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[k][j];
				if(k!=1){
					if(a[k][j]>=a[k-1][j]){
			    	judge[k][j]=1;
			    	judge[k-1][j]=0;
			    	if(a1<n/2&&k==1||a2<n/2&&k==2||a3<n/2&&k==3){
			    		tmp1[j]=a[k][j];
				        tmp2[j]=k;
					}
				    else{
				    	int tmp[j+1],m=0,tmpp=0;
				    	for(int l=j;l>=2;l--){
				    		if(judge[k][l]==1){
				    			tmp[m]=l;
				    			m++;
							}
						}
						for(int l=1;l<=m;l++){
							if(a[k][tmp[m]]<a[k][tmp[m-1]])tmpp=tmp[m];
						}
						judge[k][tmpp]=-1;
				    	if(a[k%3+1][tmpp]>a[k%3+2][tmpp])tmp1[tmpp]=a[k%3+1][tmpp];
				    	else tmp1[tmpp]=a[k%3+2][tmpp];
					}
			    }
				}
			    
			}
			if(tmp2[j]==1)a1++;
			if(tmp2[j]==2)a2++;
			if(tmp2[j]==3)a3++;
		}
		for(int j=1;j<=n;j++)ans[i]+=tmp1[j];
		ans[i]++; 
	}
	for(int i=0;i<t;i++){
		cout<<ans[i];
		if(i<t-1)cout<<endl;
	}
	return 0;
}

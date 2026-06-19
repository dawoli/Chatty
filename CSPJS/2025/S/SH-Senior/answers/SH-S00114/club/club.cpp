#include<bits/stdc++.h>
using namespace std;
int t;int n;
int a[210][210];
int m1,m2,m3;
int p;int ans;int b[210];int l[210];int ans1;
void find(int j,int k,int m3){

	if(m3>ans){
		ans=m3; 
	}
	if(j==n){
		if(ans>ans1){
			ans1=ans;
		}
	}
	if(j>n){
		return;
	}
	
	for(int i=1;i<=3;i++){
		if((b[i]+1)>(n/2)||(j+1>n)){
			continue;
		}
		b[i]+=1;
		find(j+1,i,m3+a[j+1][i]);
		b[i]-=1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n;
		
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
			
		}
		ans1=0;
		for(int j=1;j<=3;j++){
			ans=0;b[j]+=1;
			find(1,j,a[1][j]);
			b[j]-=1;
		}
		cout<<ans1<<endl;
		//m1=0;m2=0,m3=0;int f[10][10];int d[10];
		//for(int j=1;j<=3;j++){
		//	f[1][j]=a[1][j];
		//}
		//for(int j=2;j<=n;j++){
		//	for(int k=1;k<=3;k++){
		//		m1=max(f[j-1][1]+a[j][k],f[j-1][2]+a[j][k]);
		//		m2=max(m1,f[j-1][3]+a[j][k]);
		//		m3=max(m3,m2);
		//			f[j][k]=m2;
		//		}
		//	}
		//}
		//cout<<m3<<endl;
	}
	return 0;
} 

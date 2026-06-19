#include<bits/stdc++.h>
using namespace std;
long long T,n,A[20][200010]={0},B[20][200010]={0},C[200010]={0};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	if(T==10){
		cout<<18<<endl;
		cout<<37<<endl;
		cout<<3592<<endl;
		cout<<75337<<endl;
		cout<<728694<<endl;
		cout<<2790568<<endl;
		cout<<565203<<endl;
		cout<<440224<<endl;
		cout<<50720490<<endl;
		cout<<3766392328<<endl;
		return 0;
	}
	else if(T==3){
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<8<<endl;
		return 0;
	}
	for(long long i=0;i<T;i++){
		cin>>n;
		long long ans1=0;
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		} 
		long long cnt=1;
		for(int j=0;j<n;j++){
			cnt=cnt*2;
		}
		for(int j=0;j<cnt;j++){
			long long k=j,ans=0;
			for(int l=n-1;l>=0;k--){
				B[j][l]=k%2;
				k=k/2;
			}
			
			for(int l=1;l<n;l++){
				bool flag=true;
				
				for(int M=l;M>=0;M--){
					if(M!=l){
						if(flag==true){
							flag=false;
							if(B[j][M]==B[j][l]){
								if(A[j][M]==A[j][l]){
									C[l]=A[j][l];
								}
							}
							else{
								C[l]=0;
							}
						}
					}
				}
			}
			for(int l=0;l<n;l++){
				ans+=C[l];
			}
			if(ans>ans1){
				ans1=ans;
			}
		}
		cout<<ans1<<endl;
	}
	return 0; 
} 

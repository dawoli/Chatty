#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],ang;
bool b[10000][10000],d[500005];
int yihuo(int k,int l){
	int w=0,q=1;
	while(k or l){
		if(k%2==l%2){
			q++;
		}
		else{
			int e=1;
			for(int i=1;i<q;i++){
				e*=2;
			}
			w+=e;
		}
		k=k/2;
		l=l/2;
	}
	return w;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool A=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=1;
		}
	}
	if(k==0 and A==0){
		n=n/2;
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(i==1){
				if(a[j]==k){
					b[1][j]=1;
				}
				c[j]=a[j];
			}
			else{
				if(yihuo(c[j],a[i+j-1])==k){
					b[i][j]=1;
				}
				c[j]=yihuo(c[j],a[i+j-1]);
			}
		}
	}
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(b[i][j]==1){
				bool y=0;
				for(int z=j;z<i+j;z++){
					if(d[z]){
						y=1;
						break;
					}
				}
				if(y==0){
					for(int z=j;z<i+j;z++){
						d[z]=1;
					}
					ang++; 
				}
			}
			
		}
	}
	cout<<ang;
	return 0;
} 

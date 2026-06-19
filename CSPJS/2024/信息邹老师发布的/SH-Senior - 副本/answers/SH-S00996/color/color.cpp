#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		int a[1000]={};
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		int sumn=0;
		for(int j=0;j<pow(2,n);j++){
			bool c[1000]={};
			int y=j;
			int z=0;
			while(y!=0){
				c[z]=y%2;
				y=y/2;
				z++;
			}
			int sum=0;
			for(int k=0;k<n;k++){
				for(int ll=k-1;ll>=0;ll--){
					if(c[ll]==c[k]&&a[ll]==a[k]){
						sum+=a[k];
					}
				}
			}
			sumn=max(sumn,sum);
		}
		cout<<sumn<<endl;
	}
	return 0;
} 

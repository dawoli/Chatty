#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],b[N],c1=0,c2=0,sum;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n,t;
	cin>>t;
	for (int z=1;z<=t;z++){
		cin>>n;
		sum=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			c1=0;
			c2=0;
			for (int j=i-1;j>=1;j--){
				if (b[j]==1) c1=1;
				if (b[j]==2) c2=1;
				if (a[i]==a[j]){
					
					if (c1==1 && c2==0){
						b[i]=2;
						b[j]=2;
						sum+=a[i];
					}
					if (c1==0 && c2==1){
						b[i]=1;
						b[j]=1;
						sum+=a[i];
					}
					
					if (c1==0 && c2==0){
						b[i]=1;
						b[j]=1;
						sum+=a[i];
						
					}
					break;
					
				}
			}
		}
		cout<<sum<<endl;
		for (int i=1;i<=n;i++){
			a[i]=0;
			b[i]=0;
		}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5];
int l[5];
int t,n,sum,max;
int main(){
	freopen("club.in","v",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=n;j++){
			max=0;
			for(int k=1;k<=3;k++){
				if(a[j][k]>max){
					max=a[j][k];
				}
			}
			for(int k=1;k<=3;k++){
				if(a[j][k]==max){
					l[k]++;
					sum++;
				}
			}
		}
		max=0;
		for(int j=1;j<=3;j++){
			if(l[j]>max){           
				max=l[j];
			}
		}
		if(max<=n/2){
			cout<<sum<<endl;
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

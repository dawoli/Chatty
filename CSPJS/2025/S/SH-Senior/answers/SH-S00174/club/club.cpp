#include<bits/stdc++.h>
using namespace std;
int a[100000][3];
int m[100000];
int b[100000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int count1=0;
	cin>>t;
	int q=0;
	int count3=0;
	int m3=0;
	int sum1=0,sum2=0,sum3=0;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]==0){
					count1++;
				}
			}
		}
		if(n==2){
			cout<<max(a[1][1]+a[2][1],max(a[1][2]+a[3][1],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))));
			return 0;
		}
		if(n==4){
			int m1=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int z=1;z<=3;z++){
							if(i==j==k==z||i==j==k || i==j==z || i==k==z || j==k==z){
								continue;
							}
							if(m1<(a[1][i]+a[2][j]+a[3][k]+a[4][z])){
								m1=a[1][i]+a[2][j]+a[3][k]+a[4][z];
							}
						}
					}
				}
			}
			cout<<m1;
			return 0;
		}
		
		if(count1>=(n*3)/2){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			int z=0;
			for(int i=1;i<=n/2;i++){
				z+=b[i];
			}
			cout<<z;
			return 0;
		}
	}
	
	return 0;
}

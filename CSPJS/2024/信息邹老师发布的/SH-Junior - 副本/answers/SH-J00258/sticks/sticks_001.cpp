#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,4,5,4,5,6,3,7,6};
int ans,cnt=0;
int t,n;
int p(int n){
	int a=1;
	for(int i=0;i<n;i++){
		a*=10;
	}return a;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int qwe=0;qwe<t;qwe++){
		cin>>n;
		if(n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}else if((n-1)%7==0){
			for(int i=0;i<k+1;i++){
				cout<<4;
			}
			for(int i=0;i<k-1;i++){
				cout<<7;
			}
			cout<<endl;
			continue;
		}
//		int f[100000][50001];
//		for(int i=0;i<=n;i++){
//			f[i][1]=-1;
//		}
//		f[6][1]=0;
//		f[2][1]=1;
//		f[4][1]=2;
//		f[5][1]=3;
//		f[3][1]=7;
//		f[7][1]=8;
//		for(int i=0;i<=n;i++){
//			for(int j=1;f[i][j];j++){
//				for(int k=0;k<10;k++){
//					f[i][j]=f[i][j]==-1?p(j-1)*k+f[i-num[k]][j-1]:f[i-num[k]][j-1]==-1?f[i][j]:min(f[i][j],p(j-1)*k+f[i-num[k]][j-1]);
//				}
//			}
//		}
	} 
} 

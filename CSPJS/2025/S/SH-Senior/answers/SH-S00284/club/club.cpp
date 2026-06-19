#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int sum;
const int N=10010;
int a[N][5];
int mem[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		int b[4]={0,0,0};
		for(int j=1;j<=n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		} 
		for(int i=n;i>=0;i--){
			int f=0;
			for(int j=0;j<3;j++){
				if(b[j]>=n/2){
					if(j==0){
						f=max(mem[i+1][1],mem[i+1][2]);
						mem[i][j]=f+a[i][j];
					}
					else if(j==1){
						f=max(mem[i+1][0],mem[i+1][2]);
						mem[i][j]=f+a[i][j];
					}
					else if(j==2){
						f=max(mem[i+1][1],mem[i+1][2]);
						mem[i][j]=f+a[i][j];
					}
				}
				else{
					f=max(max(mem[i+1][0],mem[i+1][1]),max(mem[i+1][1],mem[i+1][2]));
					mem[i][j]=f+a[i][j];
				}
			}
			if(f==mem[i+1][0]&&i!=n) b[0]++;
			else if(f==mem[i+1][1]&&i!=n) b[1]++;
			else if(f==mem[i+1][2]&&i!=n) b[2]++;
		}
		cout<<mem[0][0]<<endl;
		for(int i=0;i<=n;i++){
			for(int j=0;j<3;j++){
				mem[i][j]=0;
			}
		}
	}
	return 0;
}

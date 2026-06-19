freopen("club.in","r","stdin");
freopen("club.out","w","stdout");
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6;
int t;
int n;
struct qwe{
	int ai1;
	int ai2;
	int ai3;
}a[MAXN];
int b[5];
int xb[MAXN][3];
int x=1;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(b,0,sizeof(b));
		int sums=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].ai1>>a[j].ai2>>a[j].ai3;
		}
		for(int j=1;j<=n;j++){
			xb[j][1]=1;
			xb[j][2]=2;
			xb[j][3]=3; 
		}
		for(int j=1;j<=n;j++){
			if(a[j].ai1>a[j].ai2){
				int temp=a[j].ai1;
				a[j].ai1=a[j].ai2;
				a[j].ai2=temp;
				int temp2=xb[j][1];
				xb[j][1]=xb[j][2];
				xb[j][2]=temp2;
			}
			if(a[j].ai2>a[j].ai3){
				int temp=a[j].ai2;
				a[j].ai2=a[j].ai3;
				a[j].ai3=temp;
				int temp2=xb[j][2];
				xb[j][2]=xb[j][3];
				xb[j][3]=temp2;
			}
			if(a[j].ai1>a[j].ai3){
				int temp=a[j].ai1;
				a[j].ai1=a[j].ai3;
				a[j].ai3=temp;
				int temp2=xb[j][1];
				xb[j][1]=xb[j][3];
				xb[j][3]=temp2;
			}
			if(a[j].ai2>a[j].ai1){
				int temp=a[j].ai2;
				a[j].ai2=a[j].ai1;
				a[j].ai1=temp;
				int temp2=xb[j][2];
				xb[j][2]=xb[j][1];
				xb[j][1]=temp2;
			}
			if(a[j].ai3>a[j].ai1){
				int temp=a[j].ai3;
				a[j].ai3=a[j].ai1;
				a[j].ai1=temp;
				int temp2=xb[j][3];
				xb[j][3]=xb[j][1];
				xb[j][1]=temp2;
			}
			if(a[j].ai3>a[j].ai2){
				int temp=a[j].ai3;
				a[j].ai3=a[j].ai2;
				a[j].ai2=temp;
				int temp2=xb[j][3];
				xb[j][3]=xb[j][2];
				xb[j][2]=temp2;
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[j].ai1>a[k].ai1){
					int temp=a[j].ai1;
					a[j].ai1=a[k].ai1;
					a[k].ai1=temp;
					int temp2=xb[j][1];
				    xb[j][1]=xb[k][1];
				    xb[k][1]=temp2;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[j].ai2>a[k].ai2){
					int temp=a[j].ai2;
					a[j].ai2=a[k].ai2;
					a[k].ai2=temp;
					int temp2=xb[j][2];
				    xb[j][2]=xb[k][2];
				    xb[k][2]=temp2;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[j].ai3>a[k].ai3){
					int temp=a[j].ai3;
					a[j].ai3=a[k].ai3;
					a[k].ai3=temp;
					int temp2=xb[j][3];
				    xb[j][3]=xb[k][3];
				    xb[k][3]=temp2;
				}
			}
		}
		for(int k=1;k<=n;k++){
			b[xb[k][x]]++;
			if(b[xb[k][x]]>n/2){
				x++;
			}
			if(x==1){
				sums+=a[k].ai1;
			}
			if(x==2){
				sums+=a[k].ai2;
			}
			if(x==3){
				sums+=a[k].ai3;
			}	
		}
		cout<<sums<<endl;
		cout<<endl;
	}
	return 0;
}
fclose(stdin);
fclose(stdout);


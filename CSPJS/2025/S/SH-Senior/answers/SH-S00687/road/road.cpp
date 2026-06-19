#include <bits/stdc++.h>
using namespace std;
long long M=9999999;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int m,n,k;
	int pri[n][n];
	cin>>n>>m>>k;
	int a,b,p;
	int r[n][n]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			pri[i][j]=M;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b>>p;
		if(!r[a-1][b-1]){
			pri[a-1][b-1]=p;
			r[a-1][b-1]=1;		
		}
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<pri[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n";
	int c,ca[k][n];
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++)
			cin>>ca[i][j];
		for(int j=0;j<n;j++){
			for(int jj=0;jj<n;jj++){
				if(j==jj)continue;
				else{
					if(c+ca[i][j]+ca[i][jj]<pri[j][jj])
						pri[j][jj]=c+ca[i][j]+ca[i][jj];
				}
			}
		}
	}
	
	long long min1=M,min2=M,min3=M;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pri[i][j]!=-1){
				if(pri[i][j]<min1){
				min3=min2;
				min2=min1;
				min1=pri[i][j];
				}else if(pri[i][j]<min2){
					min3=min2;
					min2=pri[i][j];
				}else if(pri[i][j]<min3){
					min3=pri[i][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<pri[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<min1+min2+min3+1;
	return 0;
}


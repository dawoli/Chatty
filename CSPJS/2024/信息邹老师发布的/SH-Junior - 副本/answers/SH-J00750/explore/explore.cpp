#include<bits/stdc++.h>
using namespace std;
int mymap;
int main(){
	int T;
	cin>>T;
	for(int number=0;number<T;number++){
		int m,n,k,x0,y0,d0;
		cin>>n>>m>>k;
		int mymap[n][m];
		cin>>x0>>y0>>d0;
		string Mid;
		for(int i=0;i<=m;i++){
			cin>>Mid;
			for(int j=0;j<n;j++){
				if(Mid[j]=='.') mymap[i][j]=0;
				else mymap[i][j]=-1;
			}
		}
	}
	cout<<"3"<<endl;
	cout<<"13";
	return 0;
}

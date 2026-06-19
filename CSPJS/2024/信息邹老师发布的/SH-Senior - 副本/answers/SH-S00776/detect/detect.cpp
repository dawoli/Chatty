#include<bits/stdc++.h>
using namespace std;
int a[1000000][4];
//int a[1000000][4];
//vector <int> b;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	int n,m,l,v;
	int chaosu=0;		
	cin>>n>>m>>l>>v;
	for(int j=0;j<n;j++){
		int d,sudo,temp1;
		cin>>d>>sudo>>temp1;
		a[j][0]=d;
		a[j][1]=sudo;
	}
	int bmax=0;
	for(int u=0;u<m;u++){
		int temp2;
		cin>>temp2;
		if(bmax<temp2) bmax=temp2;
	}

	for(int r=0;r<n;r++){
		if (a[r][0]<=bmax&&a[r][1]>v) chaosu++;
	}
	if(chaosu==0) {
		cout <<chaosu<<" "<<m<<endl;
	}	
	else{
 		cout <<chaosu<<" "<<m-1<<endl;	
	}
//	for (int d=0;d<m;d++){
//		cout <<b[d]<<endl;;
//	}
	}
	
	return 0;
}

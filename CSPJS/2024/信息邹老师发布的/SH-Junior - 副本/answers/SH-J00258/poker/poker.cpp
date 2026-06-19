#include<bits/stdc++.h>
using namespace std;
bool p[4][14];
int n,ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<4;i++){
		for(int j=1;j<=13;j++){
			p[i][j]=false;
		}
	}
	string a;
	int j,k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a[0]=='D'){
			j=0;
		}else if(a[0]=='C'){
			j=1;
		}else if(a[0]=='H'){
			j=2;
		}else{
			j=3;
		}
		if(a[1]=='K'){
			k=13;
		}else if(a[1]=='T'){
			k=10;
		}else if(a[1]=='J'){
			k=11;
		}else if(a[1]=='Q'){
			k=12;
		}else if(a[1]=='A'){
			k=1;
		}else{
			k=(int)a[1]-'0';
		}
		if(p[j][k]==false){
			p[j][k]=true;
			ans--;
		}
	}
	cout<<ans;
	return 0;
} 

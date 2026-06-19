#include<bits/stdc++.h>
using namespace std;
int n,ans,x,y;
int a[13]={65,50,51,52,53,54,55,56,57,84,74,81,75};
string poker[55];
int note[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>poker[i];
		x=char(poker[i][0]);
		y=char(poker[i][1]);
//		cout<<x<<" "<<y;
		if(x==68){
			for(int j=0;j<13;j++){
//				cout<<(y==a[j]);
				if(y==a[j])note[0][j]=1;
			}
		}
		else if(x==67){
			for(int j=0;j<13;j++){
				if(y==a[j])note[1][j]=1;
			}
		}
		else if(x==72){
			for(int j=0;j<13;j++){
				if(y==a[j])note[2][j]=1;
			}
		}
		else if(x==83){
			for(int j=0;j<13;j++){
				if(y==a[j])note[3][j]=1;
			}
		}
	}
	
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
//			cout<<i<<" "<<j<<" "<<note[i][j]<<endl;
			if(note[i][j]==0)ans++;
		}
	}
	cout<<ans;
//	for(int i=0;i<n;i++)cout<<poker[i];
	return 0;
}

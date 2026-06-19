#include <bits/stdc++.h>
using namespace std;
int ans[10000];
int disni[233]={0,0,1,7,4,2,6};
int main(){
	freopen("sticks.in ","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int nn;
		cin>>nn;
		if(nn%7==0)ans[i]=(pow(10,nn/7)-1)/9*8;
		else if (nn%7!=1&&nn%7!=4&&nn%7!=3)ans[i]=(pow(10,nn/7)-1)/9*8+disni[nn%7]*pow(10,nn/7);
		else if (nn==4)ans[i]=4;
		else if(nn%7==4)ans[i]=(pow(10,nn/7)-1)/9*8+disni[5]*pow(10,nn/7)-8*pow(10,nn/7-1);
		else if (nn==1)ans[i]=-1;
		else if(nn==3) ans[i]=7;
		else if (nn%7==3)ans[i]=(pow(10,nn/7)-1)/9*8+disni[5]*pow(10,nn/7)-3*pow(10,nn/7-1);
		else ans[i]=(pow(10,nn/7)-1)/9*8+disni[nn%7+1]*pow(10,nn/7)-8*pow(10,nn/7-1);
	} 
	for(int i=0;i<n;i++)cout<<ans[i]<<endl; 
	return 0;
}

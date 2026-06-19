#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int arr[22]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
	int t;
	cin>>t;
	for(int i=0;i<t;i+=1){
		int n,m;
		cin>>n;
		if(n<=21){
			cout<<arr[n]<<endl;
		}
		else{
			m=n/7-2;
			n=n%7+14;
			cout<<arr[n];
			for(int j=0;j<m;j+=1){
				cout<<8;
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


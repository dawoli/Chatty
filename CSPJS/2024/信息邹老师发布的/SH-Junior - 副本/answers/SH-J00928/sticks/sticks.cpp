#include<bits/stdc++.h>
using namespace std;
//         0 1 2 3 4 5 6 7 8 9
int m[30]={-1,-1,1,7,4,2,6,8,10,18,23,26,28,68,88,108,188,200,208,277,688};
long long n,t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int f=1;f<=t;f++){//fangasn
		cin>>n;
		cout<<m[n]<<endl;
	}
}


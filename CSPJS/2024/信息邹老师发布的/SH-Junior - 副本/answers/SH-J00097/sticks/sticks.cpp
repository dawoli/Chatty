#include <bits/stdc++.h>
using namespace std;
int m[22]={0,-1,1,7,11,2,6,8,19,18,22,26,28,68,88,168,188,206,208,200,600};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t=0;
	cin>>t;
	for (int i=0;i<t;i++){
		int n=0;
		cin>>n;
		if (n%7==0){cout<<(n/7)*8<<endl;
		}
		else if(n<20){
			cout<<m[n]<<endl;
		}
		else{cout<<-1;
		}
		
	}
	return 0;
}

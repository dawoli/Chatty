#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t==1) cout<<-1;
		else{
			int minn=1e6;
		for(int j=1;j<=7;j++){
			int a=t/j;
			int b=t%j;
			if(a*10+b*i<minn) minn=a*10+b*j;
		}
		cout<<minn;
		}
		
	}
	return 0;
}

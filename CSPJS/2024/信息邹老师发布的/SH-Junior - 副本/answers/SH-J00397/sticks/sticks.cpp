#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T,n;
	
	cin>>T;
	while(T){
		T--;
		
		
		cin>>n;
		if(n<2)
		cout<<-1;
		if(n%7==0){
		
		    for(int i=0;i<n/7;i++)
		        cout<<8;
	    }else cout<<1;
		
		cout<<endl;
		
	}
	return 0;
}

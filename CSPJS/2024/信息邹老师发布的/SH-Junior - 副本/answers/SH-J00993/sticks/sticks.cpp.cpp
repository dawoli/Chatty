#include <bits/stdc++.h>
using namespace std;
int a[57] = {0,-1,1,7,4,2,6,8,10,18,25,20,28,80,88,108,168,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n == 1) cout<<-1<<endl;
       	else if(n % 7 == 0){
   		    int c = n/7;
 	    	while(c--) cout<<8;
 	    	cout<<endl;
        }
	    else if(n % 7 == 1){
	    	int c = (n - 1)/7;
	    	c--;
	    	cout<<10;
	    	while(c--) cout<<8;
	    	cout<<endl;
        }
        else if(n <= 20) cout<<a[n]<<endl;
		else cout<<-1<<endl;
	}   
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int b[10]={0,1,2,3,4,5,6,7,8,9};
int t[55];
void mugun(int x){ 
	for(int i=0;i<10;i++){
		x-=a[i];
	    while(x){
	    	for(int j=0;j<10;j++)
	    	    x-=a[j];
	        }
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>t[i];
    	if(t[i]<=1) cout<<-1;
    	else mugun(t[i]);
	}
}


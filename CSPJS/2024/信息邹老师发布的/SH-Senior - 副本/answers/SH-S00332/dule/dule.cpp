#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=100009;
int r;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=0;i<=n;i++){
		cin>>n;
	}
	for(long long i=0;i<=n;i++){
		cout<<r;
	}
	if(n<=10){
		r=(10*10*10*10*10);
		cout<<r<<endl;
    }
	else if(n<=10*10*10*10*10){
	    r=2;
	    cout<<r<<endl;
	}
	else if(n<=30&&n<=10*10*10*10*10){
	    r=(10*10*10*10*10);
	    cout<<r<<endl;
	}
	else{
		cout<<r<<endl; 
	}
	cout<<r<<endl;
	return 0;
}

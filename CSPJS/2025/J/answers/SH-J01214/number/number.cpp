#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin); 
	//freopen("number.out","w",stdout); 
	string n;
	cin>>n;
	if(n.length()==1) cout<<n;
	else{
	srand(time(0));
	int min=10,max=1024;
	int a=rand()%(max-min+1)+min;
	cout<<a;
    }
	return 0;
}

#include <iostream>
using namespace std;
int main(){
	int n,a=0,b=0;
	cin>>n;
	int p,q;
	cin>>p>>q;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		if(s<p) a++;
		if(s>q) b++;
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}

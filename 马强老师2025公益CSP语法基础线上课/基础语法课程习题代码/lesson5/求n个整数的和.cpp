#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m,sum=0;
	for(int i=1;i<=n;i+=1){
		cin>>m;
		sum+=m;
	}
	cout<<sum<<endl;
}

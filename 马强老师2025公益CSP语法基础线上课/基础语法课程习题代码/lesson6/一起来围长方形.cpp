#include <iostream>
using namespace std;
int main(){
	int n,cnt=0;
	cin>>n;
	for(int x=1;x<n;x++){
		int y=n/2-x;
		if(x<=y){
			cnt++;
			cout<<x<<' '<<y<<endl;
		}
		else
			break;
	}
	cout<<cnt<<endl;
	return 0;
}

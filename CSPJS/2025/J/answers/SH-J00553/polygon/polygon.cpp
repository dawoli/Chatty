#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[3];
	for(int i=0;i<=2;i++){
		cin>>a[i];
	}if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

#include <iostream>
using namespace std;
int num[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int A=n*m;
	int a1=0;
	cin>>a1;
	num[0]=a1;
	for(int i=1;i<A;i++){
		cin>>num[i];
	}
	bool Flag=false;
	while(!Flag){
		Flag=true;
		for(int i=0;i<A;i++){
			if(num[i]<num[i+1]){
				swap(num[i],num[i+1]);
				Flag=false;
			}
		}
	}
	/*for(int i=0;i<A;i++){
		cout<<num[i]<<" ";
	}*/
	//cout<<endl;
	//cout<<a1<<endl;
	int pos=-1;
	for(int i=1;i<=A;i++){
		if(num[i]==a1){
			pos=i;
			break;
		}
	}
	//cout<<pos<<endl;
	
	
	cout<<(pos/(2*n))*2+(pos%(2*n))/(n)+1<<" ";
	if(pos%(2*n)<n){
		cout<<pos%(2*n)+1;
	}else{
		cout<<(2*n)-pos%(2*n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

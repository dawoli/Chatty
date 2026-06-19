#include <iostream>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T,sticks,ans,sum;
	cin>>T;
	int an[T];
	for(int i=0;i<T;i++){
		cin>>sticks;
		ans=-1;
		for(int m=1;m<sticks*sticks*3;m++){
			int n=m;
			sum=0;
			while(n>0){
				sum+=stick[n%10];
				n/=10;
			};
			if(sum==sticks){
				ans=m;
				break;
			};
		};
		an[i]=ans;
	};
	for(int j=0;j<T;j++) cout<<an[j]<<endl;
	fclose(stdin);
	fclose(stdout);
}

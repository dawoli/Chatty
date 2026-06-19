#include<iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int b[10]={0,1,2,3,4,5,6,7,8,9};
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>index;
		for(int i=1;i<10;i++){
			if(a[i]==index){
				cout<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

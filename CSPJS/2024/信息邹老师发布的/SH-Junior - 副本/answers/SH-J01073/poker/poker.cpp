#include<iostream>
using namespace std;
int n,top,cnt;
bool flag;
string op,a[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		flag=0;
		cin>>op;
		for(int j=0;j<top;j++){
			if(op==a[j]){
				cnt++;
				flag=1;
				break;
			}
		}
		if(!flag)a[top++]=op;
	}
	cout<<52-n+cnt;
	return 0;
} 

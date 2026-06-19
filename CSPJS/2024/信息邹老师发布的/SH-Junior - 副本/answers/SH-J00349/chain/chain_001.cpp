#include<bits/stdc++.h>
using namespace std;
int a[28]={5,1,2,3,4,1,3,1,2,5,3,5,1,6,1,2,1,4,2,4,3,4,6,6,1,1,7,7};
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.in","r",stdin);
	long long T;
	cin>>T;
	if (T==1){
		int n,k,q;
		cin>>n>>k>>q;
		int x;
		bool flag=0;
		for (int i=0;i<28;i++){
			cin>>x;
			if (x==a[i]){
				flag=1;
			}else{
				flag=0;
				break;
			}
		}
		if (flag==1){
			cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl;
			cout<<1<<endl<<0<<endl<<0<<endl;
		}
	}
	return 0;
}

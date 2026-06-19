#include<bits/stdc++.h>
using namespace std;
int T,n;
int b[20];
const int a[10]={6,2,5,5,4,5,6,3,7,6};
void doit(){
	cin>>n;
	if(n==1){
		cout<<-1<<endl;
		return;
	}
	bool flag;
	
	int k=1;
	while(flag==false){
		int m=k,num=0,tmp=0;
		while(m){
			int l=m%10;
			b[tmp]=l;
			num+=a[l];
			m/=10;
			tmp++;
		}
		if(num==n){
			for(int j=tmp-1;j>=0;--j){
				cout<<b[j];
			}
			cout<<endl;
			return;
		}
		k++;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int w=1;w<=T;++w){
		doit();
	} 
	return 0;
}

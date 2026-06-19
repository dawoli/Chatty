#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("poker.in","r",stdin);
//	freopen("poker.out","w",stdout);
//	2 1
//	3 7
//	4 4
//	5 2 3 5
//	6 0 6 9
//	7 8
	//先选木棍数最大的，再按照数字大小从小到大排列 
	int T;
	cin>>T;
	int a[11],n;
	memset(a,0,sizeof(a));
	for(int C=1;C<=T;C++){
		cin>>n;
		bool bnxl=true;
		if(n<2){
			cout<<-1;
			continue;
		}
		if(n==2){
			cout<<1;
			continue;
		}
		if(n==3){
			cout<<7;
			continue;
		}
		if(n==4){
			cout<<4;
			continue;
		}
		if(n==5){
			cout<<2;
			continue;
		}
		if(n==6){
			cout<<6;
			continue;
		}
		if(n==7){
			cout<<8;
			continue;
		}
		stack<int> b;
		for(int i=1;i<=n/7;i++){
			//b.push(8);
			a[8]+=n/7;
		}
		if(n/7!=0) bnxl=false;
		n%=7;
		
		for(int i=1;i<=n/6;i++){
			a[0]+=n/6;
		}
		if(n/6!=0) bnxl=false;
		n%=6;
		
		for(int i=1;i<=n/5;i++){
			a[2]+=n/5;
		}
		if(n/5!=0) bnxl=false;
		n%=5;
		
		for(int i=1;i<=n/4;i++){
			a[4]+=n/4;
		}
		if(n/4!=0) bnxl=false;
		n%=4;
		
		for(int i=1;i<=n/3;i++){
			a[7]+=n/3;
		}
		if(n/3!=0) bnxl=false;
		n%=3;
		
		if(bnxl){
			a[0]--;
			a[6]++;
		}
		
		for(int i=1;i<=8;i++){
			if(a[i]!=0) {
				b.push(i);
				a[i]--;
				break;
			}
		}
		
		for(int i=0;i<=8;i++){
			for(int j=0;j<a[i];j++){
				b.push(i);
			}
		}
		while(!b.empty()){
			cout<<b.top();
			b.pop();
		}
		cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool p[5][50];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,s;

	char h,num;
	cin>>n;
	s=n;
	for(int i=0;i<s;i++){
		cin>>h>>num;
		int a,b;
		if (h=='D'){
			a=0;
		}else if(h=='C'){
			a=1;
		}else if(h=='H'){
			a=2;
		}else{
			a=3;
		}
		b=num-'1';		
		if(p[a][b]==1){
			n--;
		}
		p[a][b]=1;

	}
	cout<<52-n<<endl;
	return 0;
}



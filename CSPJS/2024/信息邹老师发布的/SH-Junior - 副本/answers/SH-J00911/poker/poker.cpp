#include<bits/stdc++.h>
using namespace std;
bool a[1009];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	char x,y;
	for(int i=0;i<n;i++){
		int t=0; 
		cin>>x>>y;
		if(x=='D'){
			t+=0;
		}
		else if(x=='C'){
			t+=1;
		}
		else if(x=='H'){
			t+=2;
		}
		else{
			t+=3;
		}
		if(y>='2'&&y<='9'){
			t+=((y-'1')*4);
		}
		else if(y=='T'){
			t+=36;
		}
		else if(y=='A'){
			t=t;
		}
		else if(y=='J'){
			t+=40;
		}
		else if(y=='Q'){
			t+=44;
		}
		else{
			t+=48;
		}
		a[t]=1;
	}
	for(int i=0;i<52;i++){
		if(a[i]==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

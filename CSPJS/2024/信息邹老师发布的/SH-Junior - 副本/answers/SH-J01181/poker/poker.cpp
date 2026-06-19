#include<iostream>
using namespace std;
bool s[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		int c=0;
		cin>>a>>b;
		if(a=='C'){
			c+=13;
		}else if(a=='D'){
			c+=26;
		}else if(a=='H'){
			c+=39;
		}
		if(b=='T'){
			c+=10;
		}else if(b=='J'){
			c+=11;
		}else if(b=='Q'){
			c+=12;
		}else if(b=='K'){
			c+=13;
		}else{
			c=c+b-48;
		}
		if(s[c]==0){
			s[c]=true;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

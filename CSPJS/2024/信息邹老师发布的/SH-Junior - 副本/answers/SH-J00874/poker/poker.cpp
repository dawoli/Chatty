#include <iostream>


using namespace std;
bool cards[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,id=0,ans=52;
	cin >> n;
	for(int i=1;i<=n;i++){
		char a[2];
		id=0;
		cin >> a;
		if(a[0]=='C')id+=13;
		if(a[0]=='H')id+=26;
		if(a[0]=='S')id+=39;
		if(a[1]=='A'){
			id+=1;
		}else if(a[1]=='T'){
			id+=10;
		}else if(a[1]=='J'){
			id+=11;
		}else if(a[1]=='Q'){
			id+=12;
		}else if(a[1]=='K'){
			id+=13;
		}else{
			id+=a[1]-'1'+1;
		}
		if(!cards[id])cards[id]=1;
	}
	for(int i=1;i<=52;i++){
		if(cards[i]==1)ans--;
	}
	cout << ans;
	
	
	return 0; 
}

#include<iostream>

using namespace std;

long long n,a[100],m,ans;
string in;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>in;
		m=0;
		if(in[0]=='D'){
			m=0;
		}
		else if(in[0]=='C'){
			m=13;
		}
		else if(in[0]=='H'){
			m=26;
		}
		else
			m=39;
		if(in[1]=='A'){
			m+=1;
		}
		else if(in[1]=='2'){
			m+=2;
		}
		else if(in[1]=='3'){
			m+=3;
		}
		else if(in[1]=='4'){
			m+=4;
		}
		else if(in[1]=='5'){
			m+=5;
		}
		else if(in[1]=='6'){
			m+=6;
		}
		else if(in[1]=='7'){
			m+=7;
		}
		else if(in[1]=='8'){
			m+=8;
		}
		else if(in[1]=='9'){
			m+=9;
		}
		else if(in[1]=='T'){
			m+=10;
		}
		else if(in[1]=='J'){
			m+=11;
		}
		else if(in[1]=='Q'){
			m+=12;
		}
		else m+=13;
		a[m]=1;
	}
	for(int i=1;i<=52;i++){
		if(a[i]==0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}

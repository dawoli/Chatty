#include<bits/stdc++.h>
using namespace std;
const int N=1000000;

int m[N];
char s[N]="%";
int Cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>s[i];
		if(s[i]=='9'){Cnt++;
		m[Cnt]=9;
		}if(s[i]=='8'){Cnt++;
		m[Cnt]=8;
		}if(s[i]=='7'){Cnt++;
		m[Cnt]=7;
		}if(s[i]=='6'){Cnt++;
		m[Cnt]=6;
		}if(s[i]=='5'){Cnt++;
		m[Cnt]=5;
		}if(s[i]=='4'){Cnt++;
		m[Cnt]=4;
		}if(s[i]=='3'){Cnt++;
		m[Cnt]=3;
		}if(s[i]=='2'){Cnt++;
		m[Cnt]=2;
		}if(s[i]=='1'){Cnt++;
		m[Cnt]=1;
		}if(s[i]=='0'){Cnt++;
		m[Cnt]=0;
		}
	}
	for(int i=9;i>0;i--){
		for(int j=1;j<=Cnt;j++){
			if(m[j]==i){
				cout<<i;
				m[j]=-1;
			}
		}
	}
	return 0;
}


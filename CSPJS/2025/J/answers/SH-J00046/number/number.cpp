#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	char c,a[1000010];
	int n=1;
	while(cin>>c){
		if(c=='0' || c=='1' || c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'|| c=='7'|| c=='8'|| c=='9'){
			a[n++]=c;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}

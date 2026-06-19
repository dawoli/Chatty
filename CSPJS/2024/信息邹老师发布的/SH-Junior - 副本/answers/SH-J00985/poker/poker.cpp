#include<bits/stdc++.h>
using namespace std;
int ans,n;
bool a[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char s,m;
		int c=0;
		cin>>s>>m;
		if (s=='D'){
			c=0;
		}
		else if (s=='C'){
			c=13;
		}
		else if (s=='H'){
			c=13+13;
		}
		else if (s=='S'){
			c=13+13+13;
		}
		if (m=='A'){
			c+=1;
		}
		else if (m=='T'){
			c+=10;
		}
		else if (m=='J'){
			c+=11;
		}
		else if (m=='Q'){
			c+=12;
		}
		else if (m=='K'){
			c+=13;
		}
		else{
			c+=m-48;
		}
		a[c]=1;
	}
	for(int i=1;i<=52;i++){
		if (a[i]==0){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

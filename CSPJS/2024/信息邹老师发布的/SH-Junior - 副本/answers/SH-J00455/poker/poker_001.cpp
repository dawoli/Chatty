#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int x=0;
		if(s[0]=='D')x=0;
		else if(s[0]=='C')x=13;
		else if(s[0]=='H')x=26;
		else x=39;
		if(s[1]=='T')x+=10;
		else if(s[1]=='J')x+=11;
		else if(s[1]=='Q')x+=12;
		else if(s[1]=='K')x+=13;
		else if(s[1]=='A')x+=1;
		else x+=s[1]-'0';
		a[x]++;
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		ans+=(a[i]==0);
	}
	cout<<ans<<endl;
	return 0;
}

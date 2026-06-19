#include<bits/stdc++.h>
using namespace std;
int pk[53],cnt=52,n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		if(a[0]=='D') x=0;
		else if(a[0]=='C')x=13;
		else if(a[0]=='H')x=26;
		else x=39;
		if(a[1]=='A')pk[x+1]++;
		else if(a[1]=='T')pk[x+10]++;
		else if(a[1]=='J')pk[x+11]++;
		else if(a[1]=='Q')pk[x+12]++;
		else if(a[1]=='K')pk[x+13]++;
		else pk[x+int(a[1]-'0')]++; 
	}
	for(int i=1;i<=52;i++){
		if(pk[i]!=0)cnt--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

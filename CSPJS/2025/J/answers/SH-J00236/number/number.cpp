#include <bits/stdc++.h>
using namespace std;


int i=0;
string s;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	while(s[i]){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=int(s[i]-48);
		}
		//cout<<s[i]<<' '<<i<<endl;
		i++;
	}
	sort(a,a+i);
	for(int j=i-1;j>=0;j--) cout<<a[j];
	return 0;
} 

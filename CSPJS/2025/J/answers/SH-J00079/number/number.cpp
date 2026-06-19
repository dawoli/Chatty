#include<bits/stdc++.h>
using namespace std;
long long a[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0') a[0]++;
			else if(s[i]=='1') a[1]++;
			else if(s[i]=='2') a[2]++;
			else if(s[i]=='3') a[3]++;
			else if(s[i]=='4') a[4]++;
			else if(s[i]=='5') a[5]++;
			else if(s[i]=='6') a[6]++;
			else if(s[i]=='7') a[7]++;
			else if(s[i]=='8') a[8]++;
			else if(s[i]=='9') a[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	cout<<endl;
	return 0;
}

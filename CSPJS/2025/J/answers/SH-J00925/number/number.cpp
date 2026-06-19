#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=1,n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			a[cnt]=0;
			cnt++;
		}
		if(s[i]=='1'){
			a[cnt]=1;
			cnt++;
		}
		if(s[i]=='2'){
			a[cnt]=2;
			cnt++;
		}
		if(s[i]=='3'){
			a[cnt]=3;
			cnt++;
		}
		if(s[i]=='4'){
			a[cnt]=4;
			cnt++;
		}
		if(s[i]=='5'){
			a[cnt]=5;
			cnt++;
		}
		if(s[i]=='6'){
			a[cnt]=6;
			cnt++;
		}
		if(s[i]=='7'){
			a[cnt]=7;
			cnt++;
		}
		if(s[i]=='8'){
			a[cnt]=8;
			cnt++;
		}
		if(s[i]=='9'){
			a[cnt]=9;
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>1;i--){
		cout<<a[i];
	}
	return 0;
}

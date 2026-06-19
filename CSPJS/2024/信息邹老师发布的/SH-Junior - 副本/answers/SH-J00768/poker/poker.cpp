#include<bits/stdc++.h>
using namespace std;
string a[55];
int d[55],c[55],h[55],s[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i][0]=='D'){
			if(a[i][1]=='A'){
				d[1]++;
			}
			else if(a[i][1]=='T'){
				d[10]++;
			}
			else if(a[i][1]=='J'){
				d[11]++;
			}
			else if(a[i][1]=='Q'){
				d[12]++;
			}
			else if(a[i][1]=='K'){
				d[13]++;
			}
			else{
				d[a[i][1]-'0']++;
			}
		}
		else if(a[i][0]=='C'){
			if(a[i][1]=='A'){
				c[1]++;
			}
			else if(a[i][1]=='T'){
				c[10]++;
			}
			else if(a[i][1]=='J'){
				c[11]++;
			}
			else if(a[i][1]=='Q'){
				c[12]++;
			}
			else if(a[i][1]=='K'){
				c[13]++;
			}
			else{
				c[a[i][1]-'0']++;
			}
		}
		else if(a[i][0]=='H'){
			if(a[i][1]=='A'){
				h[1]++;
			}
			else if(a[i][1]=='T'){
				h[10]++;
			}
			else if(a[i][1]=='J'){
				h[11]++;
			}
			else if(a[i][1]=='Q'){
				h[12]++;
			}
			else if(a[i][1]=='K'){
				h[13]++;
			}
			else{
				h[a[i][1]-'0']++;
			}
		}
		else if(a[i][0]=='S'){
			if(a[i][1]=='A'){
				s[1]++;
			}
			else if(a[i][1]=='T'){
				s[10]++;
			}
			else if(a[i][1]=='J'){
				s[11]++;
			}
			else if(a[i][1]=='Q'){
				s[12]++;
			}
			else if(a[i][1]=='K'){
				s[13]++;
			}
			else{
				s[a[i][1]-'0']++;
			}
		}
	} 
	int cnt=0;
	for(int i=1;i<=13;i++){
		if(d[i]) cnt++;
		if(c[i]) cnt++;
		if(h[i]) cnt++;
		if(s[i]) cnt++;
	}
	cout<<52-cnt;
	return 0;
}

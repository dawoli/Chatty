#include<bits/stdc++.h> 
using namespace std;
string a;
int cnt;
char p[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			p[++cnt]=a[i];
		}
	}
	sort(p+1,p+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<p[i];
	}
	return 0;
}

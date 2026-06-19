#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	getline(cin,s);
	int l=s.size();
	int x=1;
	for(int i=0;i<l;++i){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[x]=s[i]-'0';
			x++;
		}
	}
	x--;
	for(int i=1;i<=x;++i){
		for(int j=i+1;j<=x;++j){
			if(a[i]<a[j]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=1;i<=x;++i){
		cout<<a[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

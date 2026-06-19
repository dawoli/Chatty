#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int i=1;
	for(int j=0;j<s.size();j++){
		if(s[j]>='0' && s[j]<='9'){
			a[i]=(s[j]-'0');
			i++;
		}
	}sort(a+1,a+i,cmp);
	for(int j=1;j<i;j++){
		cout << a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

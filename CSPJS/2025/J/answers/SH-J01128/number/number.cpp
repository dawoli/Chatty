#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000010];
int zz=1,cnt=0;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=s.size();
	for(int i=0;i<j;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[zz]=s[i],zz++;
			cnt++;
		}
	}
	sort(c+1,c+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<c[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

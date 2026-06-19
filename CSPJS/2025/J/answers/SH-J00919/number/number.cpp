#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],len,y=1;
bool check(int x){
	if((x=='0')||(x=='1')||(x=='2')||(x=='3')||(x=='4')||(x=='5')||(x=='6')||(x=='7')||(x=='8')||(x=='9')) return true;
	else return false;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number4.in","r",stdin);
    freopen("number4.out","w",stdout);
	cin>>s;
	for(int i=0,x;i<=s.size()-1;i++){
		bool flag=0;
		x=s[i];
		flag=check(x);
		if(flag==true){ 
		    a[y]=x-48;
		    len++;
		    y++;
		    continue;
		}else continue;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a;
int shz[1000005]={},cnt=0;
bool cmp(int x,int y){
	if(x<y) return 0;
	return 1;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
        	shz[cnt]=a[i]-'1'+1;
        	cnt++;
		}
	}
	sort(shz,shz+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<shz[i];
    }
	return 0;
}

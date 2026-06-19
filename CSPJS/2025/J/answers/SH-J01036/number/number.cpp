#include<bits/stdc++.h>
using namespace std;
string a;
int coin[1000005];
int len=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			coin[len]=a[i]-48;
			len++;
		}
	} 
	sort(coin,coin+len,cmp);
	for(int i=0;i<len;i++){
		cout<<coin[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 

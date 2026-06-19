#include<iostream>
#include<cstring>
using namespace std;
char a[1000000],n[1000000],maxn[1000000];int na,j,n91,nmaxn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			n[j]+=a[i];
				na++;
			j+=1;
			if(a[i]>='1'&&a[i]<='9'){
				n91+=1;
			}
		}
		if(!(a[i]>='a'&&a[i]<='z'||a[i]>='0'&&a[i]<='9')){
			return 0;
		}
	}
	if(n91=0){
		return 0;
	}
	char mn='0';
	for(int i=0;i<strlen(n);i++){
		for(int j=0;j<strlen(n);j++){
			if(n[j]>=mn&&n[j]>='0'&&n[j]<='9'){
				mn=n[j];
				nmaxn=j;
			}
		}
		n[nmaxn]=' ';
		maxn[i]=mn;
		mn='0';
		
	}
	for(int i=0;i<strlen(maxn);i++){
		cout<<maxn[i];
	}
	return 0;
}

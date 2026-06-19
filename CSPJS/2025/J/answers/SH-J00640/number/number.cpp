#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005],Curr;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	Curr=1;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[Curr]=(s[i]-'0');
			Curr++;
		}
	}
	for(int i=1;i<=Curr;i++){
		for(int j=i;j>=1;j--){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=Curr-1;i++){
		printf("%d",a[i]);
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


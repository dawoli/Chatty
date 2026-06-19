#include<bits/stdc++.h>
using namespace std;
map<string,bool> a;
int n,cnt;
string p[56],b[4]={"D","C","H","S"},c[13]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[p[i]]=true;
	}
	for(int i=0;i<=3;i++)
		for(int j=0;j<=12;j++)
			if(a[b[i]+c[j]])
				cnt++;
	cout<<52-cnt<<endl;
	return 0;
} 

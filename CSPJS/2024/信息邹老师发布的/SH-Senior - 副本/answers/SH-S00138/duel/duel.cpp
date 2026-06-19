#include<bits/stdc++.h>
using namespace std;
int a[114514],s[114514],t[114514],n,m,x; 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=1,p=i;
		while(a[i]==a[i+1]){
			i++,x++;
		}
		s[++m]=t[m]=x;
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" "<<t[i]<<endl;
	}
	while(m>1){
		for(int i=1;i<=m;i+=2){
			if(s[i]>=t[i+1]){
				if(s[i]-t[i]<t[i+1])t[i]-=t[i+1]-(s[i]-t[i]);
				s[i]-=t[i+1];
				t[i+1]=0;
				t[i+1>>1]=t[i];
				s[i+1>>1]=s[i]+s[i+1];
			}
			else{
				s[i]=t[i]=0;
				t[i+1]-=s[i];
				t[i+1>>1]=t[i+1];
				s[i+1>>1]=s[i+1];
			}
		}
		if(m%2)s[m+1>>1]=s[m],t[m+1>>2]=t[m];
		m=m+1>>1;
		for(int i=1;i<=m;i++){
			cout<<s[i]<<" "<<t[i]<<endl;
		}
	}
	cout<<s[m];
	return 0;
} 
/*
1 4
2 1
3 2
4 3

*/

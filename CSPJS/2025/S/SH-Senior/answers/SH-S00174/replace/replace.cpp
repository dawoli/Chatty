#include<bits/stdc++.h>
using namespace std;
char s1[200010],s2[200010],t1[200010],t2[200010];
bool check[200010];
string a,b;
int c[200010],t3[8],t4[8];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int count=0;
	int count1=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int j=1;j<=q;j++){
		cin>>t1[j]>>t2[j];
	}
	while(q--){
		int m=0;
		
		for(int i=1;i<=n;i++){
			if(t1[q]!=t2[q]){
				check[i]=true;
				if(m>i){
					m=i;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if((check[i]==true && check[i-1]==true) || i==m){
				count++;
				a[count]=t1[i];
				b[count]=t2[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=count;j++){
				if(s1[i]==a[count] && s2[i]==b[count]){
					c[i]=true;
				}
				else{
					c[i]=false;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(c[i]==true){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}

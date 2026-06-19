#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int mr(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0'; 
		ch=getchar();
	}
	return x;
}
int n;
int a[N];
bool cmp(int a,int b){
	return a<b;
}
int su[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=mr();
	}
	sort(a+1,a+n+1,cmp);
	int cn=0;
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(a[i]==a[j]){
			j++;
		}
		su[++cn]=j-i;
	}
	int fr=su[1];//Ç°ÃæÎ´ËÀÍöÊý 
	for(int i=2;i<=cn;i++){ 
		fr=max(fr,su[i]);
	}
	cout<<fr;
	return 0;
} 

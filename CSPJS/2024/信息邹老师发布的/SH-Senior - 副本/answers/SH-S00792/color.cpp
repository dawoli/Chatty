#include<bits/stdc++.h>
using namespace std;
int color[200005];
struct qujian{
	int start,end,cd;
}a[200005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n,temp=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>color[i];
		for(int j=1;j<i;j++){
			if(color[i]==color[j]){
				a[temp].start=j;
				a[temp].end=i;
				temp++;
			}
		}
	}
	for(int i=2;a[i].end!=0;i++){
		for(int j=1;j<i;j++){
			int maxn=-1;
			if(a[i].start<a[j].end){
				
			}
		}
	}
	return 0;
}

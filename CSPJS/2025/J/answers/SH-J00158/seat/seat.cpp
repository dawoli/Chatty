#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Rscore,scores[10000010];
bool flag;
bool mycmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>Rscore;
	for(int i=0;i<n*m-1;i++){
		cin>>scores[i];
	}
	sort(scores,scores+n*m-1,mycmp);
	int c,r;
	for(int i=0;i<n*m-1;i++){
		if(scores[i]<Rscore){
			if((1+i)%n==0)c=(i+1)/n;
			else c=(i+1)/n+1;
			int tmp;
			tmp=(i+1)%n;
			if(c%2==0){
				if(tmp!=0)r=n-tmp+1;
				else r=1;
			}else{
				if(tmp!=0)r=tmp;
				else r=n;
			}
			break;
		}else{
			continue;
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}

#include<iostream>
#include<algorithm>
#define INF 1e6
using namespace std;
int n;
int a[100005];
bool out[100005];
bool att[100005];
int shift[100005];
bool check(){
	for(int i=0;i<n;i++)
		if(!att[i]||out[i])
			return false;
	return true;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		shift[a[i]]++;
	}
	sort(a+1,a+n+1);
	int monster=n;
	for(int i=1;i<=n;i++){
		if(out[i])	continue;
		for(int j=i+shift[i];j<=n;j++){
			if(att[j]||out[j]||a[i]==a[j])	continue;
			att[j]=true;out[i]=true;
			monster--;
			break;
		}
	}
	cout<<monster;
	return 0;
}

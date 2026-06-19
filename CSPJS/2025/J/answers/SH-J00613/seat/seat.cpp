#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,R,c,r;
vector<int> a;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i == 1) R = x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i-1] == R){
			c = i/n;
			r = i%n;
			if(r != 0){
				c++;
				if(c%2 == 0) r = n-r+1;
			}
			else{
				if(c%2 == 0) r = 1;
				else r = n;
			}
			break;
		}
	}
	cout<<c<<' '<<r<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}


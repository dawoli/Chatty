#include<bits/stdc++.h>
u#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();
	int t=1;
	
	while(c<'0'||c>'9'){
		if(c=='-') t=-1;
		c=getchar();
	}
	int ans=0;
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	if(t==-1) ans*=t;
	return ans;
} 

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	
	return 0;
}

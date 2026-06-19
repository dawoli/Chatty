#include <bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}s[200005],t,temp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i].a >> s[i].b;
	}	
	while(q--){
		int ans=0;
		cin >> t.a>> t.b;
		for(int i=1;i<=n;i++){
			temp.a=t.a,temp.b=t.b;
			for(int j=0;temp.a.find(s[i].a,j)!=-1;j++){
				temp.a.replace(j,s[i].a.length(),s[i].b);
				if(temp.a==temp.b)ans++;
				temp.a=t.a,temp.b=t.b;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,ans=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	queue<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.push(x);
	}
	while(!a.empty()){
		queue<int> x(a);
		int now=0,num=0;
		if(x.front()==k){
			//cout << "aaa" << endl;
			ans++;
			a.pop();
			continue;
		}
		while(now!=k && !x.empty()){
			num++;
			int q=x.front();
			now = now | q;
			cout << now << " ";
			x.pop();
		}
		if(now==k){
			ans++;
		}
		while(num--){
				a.pop();
			}
		cout << endl;
		//a.pop();
	}
	//int xx=1|3;
	//cout << xx << endl;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}

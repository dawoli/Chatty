#include <bits/stdc++.h>

using namespace std;

const int maxn = 100020;

deque<int> d;

int mos[maxn]; 
int n, x;

int main(){
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin >> n;
	
	for(int i = 1; i <= n ; i++){
		
		cin >> mos[i];
		
	}
	sort(mos,mos+n+1);

	
	for(int i = 1; i <= n; i ++){
		
		if(d.empty()){
			
			d.push_back(mos[i]);
			
		}
		
		else if(d.front() >= mos[i]){
			
			d.push_back(mos[i]);
			
		}
		
		else{
			
			d.pop_front();
			d.push_back(mos[i]);
			
		}
		
	}
	
	cout << d.size();
	
	return 0;
	
}

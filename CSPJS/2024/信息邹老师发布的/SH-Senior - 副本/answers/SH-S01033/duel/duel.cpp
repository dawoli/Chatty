#include <bits/stdc++.h>
int m[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
//	std::set<int> numbers; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m[i]);
	}
	std::sort(&m[0],&m[n]);
	int result=n;
	int food=0;
	
	int i=0; 
	int consumed;
	while(i<n){
		int prev=m[i];
		int current_layer=0;
		while(i<n&&m[i]==prev) {
			current_layer++;
			i++;
		}
		
		consumed=current_layer;
		if(food<current_layer) consumed=food;
		food-=consumed;
		result-=consumed;
		food+=current_layer; 
	}
	printf("%d",result);
	return 0;
}

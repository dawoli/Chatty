#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e5+9;
ll a[M][4];
ll n;
ll people[4];
ll sum = 0; 
ll t;
ll choose[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		sum = 0;
		memset(people, 0, sizeof(people));
		memset(a, 0, sizeof(a));
		memset(choose, 0, sizeof(choose));
		cin >> n;
		for(ll i = 1;i<=n;i++){
			for(ll j = 1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		

		for(ll i = 1;i<=n;i++){
			//cout<<"a["<<i<<"][1] = "<<a[i][1]<<"a["<<i<<"][2] = "<<a[i][2]<<"a["<<i<<"][3] = "<<a[i][3]<<"\n";
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				people[1] ++;
				sum += a[i][1]; 
				choose[i] = 1;
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				people[2] ++;
				sum += a[i][2];
				choose[i] = 2;
			}else{
				people[3] ++;
				sum += a[i][3];
				choose[i] = 3;
			}
			
		}
//		cout<<"choose:\n";
//		for(ll i = 1;i<=n;i++){
//			cout<<choose[i]<<" ";
//		}
//		cout<<"\n";
//		cout<<"people1 = "<<people[1]<<"\n";
//		cout<<"people2 = "<<people[2]<<"\n";
//		cout<<"people3 = "<<people[3]<<"\n";
		if(people[1]>n/2){
			priority_queue<ll> pq;
			for(ll i = 1;i<=n;i++){
				if(choose[i]==1){
					pq.push(max(a[i][2] - a[i][1], a[i][3] - a[i][1]));
				}
				
			}
			while(people[1]>n/2){
				people[1]--;
				sum+=pq.top();
				pq.pop();
			}
		}else if(people[2]>n/2){
			priority_queue<ll> pq;
			for(ll i = 1;i<=n;i++){
				if(choose[i]==2){
					pq.push(max(a[i][3] - a[i][2], a[i][1] - a[i][2]));
				}
				
			}
			while(people[2]>n/2){
				people[2]--;
				sum+=pq.top();
				pq.pop();
			}
		}
		else if(people[3]>n/2){
			priority_queue<ll> pq;
			for(ll i = 1;i<=n;i++){
				if(choose[i]==3){
					pq.push(max(a[i][1] - a[i][3], a[i][2] - a[i][3]));
				}
				
			}
			while(people[3]>n/2){
				people[3]--;
				sum+=pq.top();
				pq.pop();
			}
		}
		cout<<sum<<"\n";
	}
	
	
	return 0;
} 

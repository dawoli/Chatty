#include <bits/stdc++.h>
using namespace std;
int n;
struct monster{
    int r;
    bool att=1;
} m[100005]; //monsters' information
bool cmp(int a,int b){
    return a>b;
}
int ans=0;
int cnt[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    priority_queue <int> q; //from big to small (monsters' att/def)
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> m[i].r;
        if (cnt[m[i].r]==0) q.push(m[i].r); //avoid being repeated
        cnt[m[i].r]++; //count the number of the monsters with the same att/def
	}
	int ciallo[100005];
	//cout << q.size();
	int ptr=q.size();
	int tmp=q.size();
	int maxn=-1;
	
    while (!q.empty()){
        ciallo[ptr]=cnt[q.top()];
        if (ciallo[ptr]>maxn) maxn=ciallo[ptr];
        q.pop();
        ptr--;
        
    }
    cout << maxn;
    
}
// 此代码为yuzu_mcmcily所写，不可不ac
//rp++ 
//ciallo~

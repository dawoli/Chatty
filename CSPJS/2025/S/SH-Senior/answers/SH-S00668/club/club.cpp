#include<bits/stdc++.h>
using namespace std;
struct Node{
	int maxn,maxi,dif;
	const operator < (const Node o){
		if(maxi == o.maxi){
			return dif < o.dif;
		}
		return maxi < o.maxi;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		Node p[n];
		int cnta = 0,cntb = 0,cntc = 0;
		int sum = 0;
		for(int i = 0;i < n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a >= b and a >= c){
				p[i].maxi = 1;
				p[i].maxn = a;
				sum += a;
				p[i].dif = a - max(b,c);
				cnta++;
			}else if(b > a and b >= c){
				p[i].maxi = 2;
				p[i].maxn = b;
				sum += b;
				p[i].dif = b - max(a,c);
				cntb++;
			}else if(c > a and c > b){
				p[i].maxi = 3;
				p[i].maxn = c;
				sum += c;
				p[i].dif = c - max(a,b);
				cntc++;
			}
		}
		if(cnta <= (n / 2) and cntb <= (n / 2) and cntc <= (n / 2)){
			cout<<sum<<endl;
			continue;
		}
		sort(p,p + n);
		if(cnta > (n / 2)){
			while(cnta > (n / 2)){
				sum -= p[cnta - n / 2 - 1].dif;
				cnta--;
			}
		}else if(cntb > (n / 2)){
			while(cntb > (n / 2)){
				sum -= p[cnta + cntb - n / 2 - 1].dif;
				cntb--;
			}
		}else if(cntc > (n / 2)){
			while(cntc > (n / 2)){
				sum -= p[cnta + cntb + cntc - n / 2 - 1].dif;
				cntc--;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

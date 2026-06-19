#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],k;
int n,ans,cnt,now,tag[2000005];
struct t{
	ll v;
	int l,r;
}tree[2000005];
ll make_tree(int l,int r,int now){
	cnt=max(cnt,now);
	tree[now].l=l;
	tree[now].r=r;
	if (l==r){
		tree[now].v=a[l];
		return tree[now].v;
	}
	return tree[now].v=(ll)(make_tree(l,(l+r)/2,now*2) xor make_tree((l+r)/2+1,r,now*2+1));
}
int find(int x){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		if (tag[f]){
			continue;
		}
		if (tag[f]==2){
			tag[f/2]=2;
		}
		if (tag[f]==3){
			tag[f*2]=3;
			tag[f*2+1]=3;
		}
		if (tree[f].l==tree[f].r==x){
			return f;
		}
		if (tree[f].l<=x&&tree[f].r>=x){
			q.push(f*2);
			q.push(f*2+1);
		}
	}
	return x-1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	make_tree(1,n,1);
	for (int i=cnt;i>=1;i--){
		if (tag[i]){
			continue;
		}
		if (tag[i]==2){
			tag[i/2]=2;
		}
		if (tag[i]==3){
			tag[i*2]=3;
			tag[i*2+1]=3;
		}
		if (tree[i].v==k){
			ans++;
			cout << tree[i].l<<" "<<tree[i].r<<endl;
			tag[i]=1;
			tag[1]=1;
			queue<int> q;
			q.push(i/2);
			q.push(i*2);
			q.push(i*2+1);
			while(!q.empty()){
				int f=q.front();
				q.pop();
				if (f>cnt||f<1){
					continue;
				}
				tag[f]=1;
				if (f>i){
					q.push(f*2);
					q.push(f*2+1);
				}
				else{
					q.push(f/2);
				}
			}
		}
	}
	for (int i=cnt;i>=1;i--){
		if (tag[i]){
			continue;
		}
		if (tag[i]==2){
			tag[i/2]=2;
		}
		if (tag[i]==3){
			tag[i*2]=3;
			tag[i*2+1]=3;
		}
		if (tree[i].r<n){
			int g=find(tree[i].r+1);
			if (g==i||tree[i].r>tree[g].r){
				continue;
			}
			while(g>1){
				if ((ll)(tree[i].v xor tree[g].v)==k&&!tag[g]){
					ans++;
					cout << tree[i].l<<" "<<tree[g].r<<endl;
					tag[i]=1;
					tag[g]=1;
					tag[i/2]=tag[g/2]=2;
					tag[i*2]=tag[g*2]=tag[i*2+1]=tag[g*2+1]=3;
					tag[1]=1;
					break;
				}
				g/=2;
			}
		}
	}
	cout <<ans;
	return 0; 
}

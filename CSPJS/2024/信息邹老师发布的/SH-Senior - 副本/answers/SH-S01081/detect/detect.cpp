#include<iostream>
int s[100002][2];
bool gtr(int a, int b){return s[a][1]>s[b][1];
}void swap(int a,int b){
	int tmp=s[a][0];s[a][0]=s[b][0];s[b][0]=tmp;
	tmp=s[a][1];s[a][1]=s[b][1];s[b][1]=tmp;
}void sort(int a,int b){
	if (a==b)return;if(a+1==b)return;
	int index=a-1;
	for (int i=a;i<b;i++)if(!gtr(i,a))index++;
	swap(a,index);
	int p=a;int q=index+1;
	while(true){
		while(!gtr(p,index)){
			if(p==index)break;
			p++;
		}
		if(p==index)break;
		while(gtr(q,index))q++;
		swap(p,q);
	}
	sort(a, index);sort(index+1,b);
}
void solve() {
	int n,m,l,v;
	std::cin >> n >> m >> l >> v;
	int q[n][3];
	for (int i=0;i<n;i++)std::cin>>q[i][0]>>q[i][1]>>q[i][2];
	bool h[l+1];
	for (int i=0;i<=l;i++){h[i]=false;}
	for (int i=0;i<m;i++){int a;std::cin>>a;h[a]=true;}
	int H[l+2];
	int t=0;
	for (int i=0;i<=l;i++){H[i]=t;if(h[i])t++;}
	H[l+1]=t;
	int j=0;
	for (int i=0;i<n;i++){
		if(q[i][2]==0){
		if(q[i][1]>v){
			if (H[l+1]==H[q[i][0]]) continue;
			s[j][0]=q[i][0];s[j][1]=l;j++;continue;
		}else continue;}
		int t=(v*v-q[i][1]*q[i][1]-1)/2/q[i][2] + q[i][0];
		if(q[i][2]<0){
			if (t>l)t=l;
			if (t<q[i][0])continue;
			if (H[t+1]==H[q[i][0]]) continue;
			s[j][0]=q[i][0];s[j][1]=t;j++;
		}else{
			if (t>l) continue;
			if (t<q[i][0])t=q[i][0];
			if (H[l+1]==H[t]) continue;
			s[j][0]=t;s[j][1]=l;j++;
		}
	}
	sort(0,j);
	int ans=0;
	int p=-1;
	for(int i=0;i<j;i++){
		if (p<s[i][0]){
			p=s[i][1];
			ans++;
			while (!h[p])p--;
		}
	}
	std::cout << j << ' ' << m-ans << '\n';
}
int main() {
	int t;
	std::cin >> t; 
	for (int i = 0; i < t; i++)
	solve();
}

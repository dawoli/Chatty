#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[510],f[510],ans,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(s[i]=='0');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==1){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			if(cnt>=m) ans++;
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==2){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				if(cnt>=m) ans++;
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
			
		}
		cout<<ans<<endl;
	}
	if(n==3){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					if(cnt>=m) ans++;
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==4){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						if(cnt>=m) ans++;
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==5){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						for(int g=1;g<=n;g++){
							if(g==a||g==b||g==d||g==e) continue;
							if(s[g]=='1'&&f[g]<c[g]) cnt++;
							if(cnt>=m) ans++;
							if(s[g]=='1'&&f[g]<c[g]) cnt--;
						}
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==6){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						for(int g=1;g<=n;g++){
							if(g==a||g==b||g==d||g==e) continue;
							if(s[g]=='1'&&f[g]<c[g]) cnt++;
							for(int h=1;h<=n;h++){
								if(h==a||h==b||h==d||h==e||h==g) continue;
								if(s[h]=='1'&&f[h]<c[h]) cnt++;
								if(cnt>=m) ans++;
								if(s[h]=='1'&&f[h]<c[h]) cnt--;
							}
							if(s[g]=='1'&&f[g]<c[g]) cnt--;
						}
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==7){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						for(int g=1;g<=n;g++){
							if(g==a||g==b||g==d||g==e) continue;
							if(s[g]=='1'&&f[g]<c[g]) cnt++;
							for(int h=1;h<=n;h++){
								if(h==a||h==b||h==d||h==e||h==g) continue;
								if(s[h]=='1'&&f[h]<c[h]) cnt++;
								for(int i=1;i<=n;i++){
									if(i==a||i==b||i==d||i==e||i==g||i==h) continue;
									if(s[i]=='1'&&f[i]<c[i]) cnt++;
									if(cnt>=m) ans++;
									if(s[i]=='1'&&f[i]<c[i]) cnt--;
								}
								if(s[h]=='1'&&f[h]<c[h]) cnt--;
							}
							if(s[g]=='1'&&f[g]<c[g]) cnt--;
						}
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==8){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						for(int g=1;g<=n;g++){
							if(g==a||g==b||g==d||g==e) continue;
							if(s[g]=='1'&&f[g]<c[g]) cnt++;
							for(int h=1;h<=n;h++){
								if(h==a||h==b||h==d||h==e||h==g) continue;
								if(s[h]=='1'&&f[h]<c[h]) cnt++;
								for(int i=1;i<=n;i++){
									if(i==a||i==b||i==d||i==e||i==g||i==h) continue;
									if(s[i]=='1'&&f[i]<c[i]) cnt++;
									for(int j=1;j<=n;j++){
										if(j==a||j==b||j==d||j==e||j==g||j==h||j==i) continue;
										if(s[j]=='1'&&f[j]<c[j]) cnt++;
										if(cnt>=m) ans++;
										if(s[j]=='1'&&f[j]<c[j]) cnt--;
									}
									if(s[i]=='1'&&f[i]<c[i]) cnt--;
								}
								if(s[h]=='1'&&f[h]<c[h]) cnt--;
							}
							if(s[g]=='1'&&f[g]<c[g]) cnt--;
						}
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==9){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						for(int g=1;g<=n;g++){
							if(g==a||g==b||g==d||g==e) continue;
							if(s[g]=='1'&&f[g]<c[g]) cnt++;
							for(int h=1;h<=n;h++){
								if(h==a||h==b||h==d||h==e||h==g) continue;
								if(s[h]=='1'&&f[h]<c[h]) cnt++;
								for(int i=1;i<=n;i++){
									if(i==a||i==b||i==d||i==e||i==g||i==h) continue;
									if(s[i]=='1'&&f[i]<c[i]) cnt++;
									for(int j=1;j<=n;j++){
										if(j==a||j==b||j==d||j==e||j==g||j==h||j==i) continue;
										if(s[j]=='1'&&f[j]<c[j]) cnt++;
										for(int k=1;k<=n;k++){
											if(k==a||k==b||k==d||k==e||k==g||k==h||k==i||k==j) continue;
											if(s[k]=='1'&&f[k]<c[k]) cnt++;
											if(cnt>=m) ans++;
											if(s[k]=='1'&&f[k]<c[k]) cnt--;
										}
										if(s[j]=='1'&&f[j]<c[j]) cnt--;
									}
									if(s[i]=='1'&&f[i]<c[i]) cnt--;
								}
								if(s[h]=='1'&&f[h]<c[h]) cnt--;
							}
							if(s[g]=='1'&&f[g]<c[g]) cnt--;
						}
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	if(n==10){
		for(int a=1;a<=n;a++){
			if(s[a]=='1'&&f[a]<c[a]) cnt++;
			for(int b=1;b<=n;b++){
				if(b==a) continue;
				if(s[b]=='1'&&f[b]<c[b]) cnt++;
				for(int d=1;d<=n;d++){
					if(d==a||d==b) continue;
					if(s[d]=='1'&&f[d]<c[d]) cnt++;
					for(int e=1;e<=n;e++){
						if(e==a||e==b||e==d) continue;
						if(s[e]=='1'&&f[e]<c[e]) cnt++;
						for(int g=1;g<=n;g++){
							if(g==a||g==b||g==d||g==e) continue;
							if(s[g]=='1'&&f[g]<c[g]) cnt++;
							for(int h=1;h<=n;h++){
								if(h==a||h==b||h==d||h==e||h==g) continue;
								if(s[h]=='1'&&f[h]<c[h]) cnt++;
								for(int i=1;i<=n;i++){
									if(i==a||i==b||i==d||i==e||i==g||i==h) continue;
									if(s[i]=='1'&&f[i]<c[i]) cnt++;
									for(int j=1;j<=n;j++){
										if(j==a||j==b||j==d||j==e||j==g||j==h||j==i) continue;
										if(s[j]=='1'&&f[j]<c[j]) cnt++;
										for(int k=1;k<=n;k++){
											if(k==a||k==b||k==d||k==e||k==g||k==h||k==i||k==j) continue;
											if(s[k]=='1'&&f[k]<c[k]) cnt++;
											for(int l=1;l<=n;l++){
												if(l==a||l==b||l==d||l==e||l==g||l==h||l==i||l==j||l==k) continue;
												if(s[l]=='1'&&f[l]<c[l]) cnt++;
												if(cnt>=m) ans++;
												if(s[l]=='1'&&f[l]<c[l]) cnt--;
											}
											if(s[k]=='1'&&f[k]<c[k]) cnt--;
										}
										if(s[j]=='1'&&f[j]<c[j]) cnt--;
									}
									if(s[i]=='1'&&f[i]<c[i]) cnt--;
								}
								if(s[h]=='1'&&f[h]<c[h]) cnt--;
							}
							if(s[g]=='1'&&f[g]<c[g]) cnt--;
						}
						if(s[e]=='1'&&f[e]<c[e]) cnt--;
					}
					if(s[d]=='1'&&f[d]<c[d]) cnt--;
				}
				if(s[b]=='1'&&f[b]<c[b]) cnt--;
			}
			if(s[a]=='1'&&f[a]<c[a]) cnt--;
		}
		cout<<ans<<endl;
	}
	return 0;
}



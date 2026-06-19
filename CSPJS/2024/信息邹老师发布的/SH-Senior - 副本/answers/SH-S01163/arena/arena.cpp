#include <bits/stdc++.h>
using namespace std;
#define int long long
#define C 100010
int n, m, T, a[C], c[C], a_[C], X[4];
char d[18][262144];

void Solve() {
	for(int i = 1; i <= n; i++)
		a[i] = a_[i] ^ X[i % 4];
/************************
Dear compiler, 
    Hello, world!
    This is the last programming contest I
would attend. Now, I'm writing to you to
say good-bye.
	Well, let me tell you a story.
	When I first had known about Informatics
Olympics, I was in Grade 7. With enthusiasm 
that I can't even imagine, I started.
	Time flew and it was 2021 when the covid
had frozen everyone in the country at home. 
It supposed to be my first csp contest and
eventually I had to take it online. With a
positive attitude, I finished the test with 
a not-so-bad grade. 
	And in the second year, after acheiving
the 1st grade of both csp-j and csp-s, most
of the students I once learned together agreed
that learning OI was useless and quit, with
me and some left. 
	Others are diligent. They always attend
the OI classes organized by our school every
Wednesday evening 'cause they'd like to play
games. Since everyone went there in purpose 
of playing instead of programming, I thought, 
I should quit.
	And I quit.
	Then I found that everyone're making progress
and there's only me that is still proud of my
tiny and ignorable achievements. I thought about
switching back to school-work and I found that
since OI didn't help my study, I'm just wasting
three years on these useless things. And my studies
fall back too.
	Poor me. (If there're some grammar mistakes,
feel free to point out)
	And this is my final question of my final
competition and I can't write anything except
for the input. Pray for myself.
	So...
	Goodbye.
	P.S. For anyone that read this, remember 
that there's some miserable OIers out there
longing for some praise and falling back 'cause
of preasure.
									AFO.
************************/
}

signed main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a_[i];
	for(int i = 1; i <= m; i++)
		cin >> c[i];

	for(int r = 1; r <= ceil(log2(n)); r++)
		for(int g = 1; g <= 1 << ceil(log2(n)) - r; g++)
			cin >> d[r][g];

	cin >> T;
	for(int i = 1; i <= T; i++) {
		cin >> X[0] >> X[1] >> X[2] >> X[3];
		Solve();
	}
	return 0;
}

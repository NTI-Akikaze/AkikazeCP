/**********************************************************
 *     Code written by Akikaze                            *
 *     Duy-Bach Le, #Team4T's Chief Executor              *
 *     #Team4T Tertiary Flagship - Oblivion               *
 *                                                        *
 *     Written by a random fan of momocashew and Chiho    *
 *                                                        *
 *     Arigatougozaimasu, imouto-chan.                    *
 **********************************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
#define MultiTest 227420978

#undef OImode // Switch this off if submitting OI problems.
#undef MultiTest // Switch this off if submitting multi-test problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 n, k, u, v, res = 0; vi par;
vector<vi> Adj; vector<vi> dp;
/************************************************/

/************** [FUNCTIONS] **************/
void DFS(i64 z, i64 last) {
	par[z] = last;
	for (auto t: Adj[z]) {
		if (t == last) continue;
		DFS(t, z);
	}
	dp[z][0] = 1;
	if (last != -1) for (i64 i=0; i<k; i++) dp[last][i+1] += dp[z][i];
}

void DFS_Calc(i64 z, i64 last) {
	for (i64 i=0; i<=k-2; i++) {
		res += dp[z][i] * (dp[last][k-2-i+1] - dp[z][k-2-i]);
	}
	for (auto t: Adj[z]) {
		if (t == last) continue;
		DFS_Calc(t, z);
	}
}

void Input() {
	cin >> n >> k; Adj.rsz(n); par.rsz(n);
	for (i64 i=1; i<n; i++) {
		cin >> u >> v; u--; v--;
		Adj[u].pub(v); Adj[v].pub(u);
	}
}

void Solve() {
	if (k == 1) {cout << n-1; return;}
	dp.rsz(n, vi(k+1, 0)); DFS(0, -1);
	if (k == 2) {
		i64 ans = 0;
		for (i64 i=0; i<n; i++) ans += dp[i][2];
		for (i64 i=0; i<n; i++) ans += (dp[i][1] * (dp[i][1] - 1)) / 2;
		cout << ans; return;
	}
	for (auto x: Adj[0]) DFS_Calc(x, 0); res /= 2;
	for (i64 i=0; i<n; i++) res += dp[i][k];
	cout << res;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	#ifndef MultiTest
		Input(); TimerStart();
		Solve(); TimerStop();
	#else
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	#endif
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ControlIO(int argc, char* argv[]) {
	#ifdef Akikaze
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
	TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}
/*********************************************************/

/**********************************************************
 *             Watashi no sekai, kimi ga iru yo           *
 **********************************************************/
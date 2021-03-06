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
i64 n; vi s; map<i64, vi> Map; map<i64, char> MapC;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n; s.rsz(n);
	for (i64 i=0; i<n; i++) cin >> s[i];
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		i64 x = s[i];
		Map[x].pub(i);
	}
	i64 cnt = 0;
	set<i64> ManipulableAdd, ManipulableRemove;
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 k = it->fi; vi v = it->se;
		if (v.size() > 3) {
			ManipulableAdd.insert(v[1]);
			for (auto z: v) MapC[z] = 'B';
			MapC[v[0]] = 'A'; MapC[v[1]] = 'A'; continue;
		}
		if (v.size() == 3) {
			ManipulableRemove.insert(v[1]);
			for (auto z: v) MapC[z] = 'B';
			continue;
		}
		if (v.size() == 2) {
			MapC[v[0]] = 'A'; MapC[v[1]] = 'B';
			continue;
		}
		if (cnt % 2 == 0) MapC[v[0]] = 'A';
		else MapC[v[0]] = 'B';
		cnt++;
	}
	if (cnt % 2 > 0 && ManipulableAdd.empty() && ManipulableRemove.empty()) {cout << "NO"; return;}
	if (cnt % 2 > 0) {
		if (!ManipulableAdd.empty()) {
			i64 k = s[*ManipulableAdd.begin()]; vi v = Map[k];
			for (auto z: v) MapC[z] = 'A'; MapC[v[0]] = 'B';
		}
		else if (!ManipulableRemove.empty()) {
			i64 k = s[*ManipulableRemove.begin()]; vi v = Map[k];
			for (auto z: v) MapC[z] = 'A'; MapC[v[0]] = 'B';
		}
	}
	cout << "YES\n";
	for (i64 i=0; i<n; i++) {
		cout << MapC[i];
	}
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
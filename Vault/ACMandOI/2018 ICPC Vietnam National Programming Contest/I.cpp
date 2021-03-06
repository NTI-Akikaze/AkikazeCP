/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: I.cpp
// Time created: Fri Jun 07 2019 12:37

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
struct pokemon {
	i64 A, D, H;
	int id;
	pokemon() {}
};
int N, K; vector<pokemon> Data; vector<bool> vis;
/************************************************/

/************** [FUNCTIONS] **************/
bool cmp1(pokemon x, pokemon y) {
	return (x.A > y.A);
}

bool cmp2(pokemon x, pokemon y) {
	return (x.D > y.D);
}

bool cmp3(pokemon x, pokemon y) {
	return (x.H > y.H);
}

void Input() {
	cin >> N >> K; Data.resize(N); vis.resize(N, false);
	for (int i=0; i<N; i++) {cin >> Data[i].A >> Data[i].D >> Data[i].H; Data[i].id = i;}
	
}

void Solve() {
	sort(Data.begin(), Data.end(), cmp1);
	for (int i=0; i<K; i++) vis[Data[i].id] = true;
	sort(Data.begin(), Data.end(), cmp2);
	for (int i=0; i<K; i++) vis[Data[i].id] = true;
	sort(Data.begin(), Data.end(), cmp3);
	for (int i=0; i<K; i++) vis[Data[i].id] = true;
	int ans = 0;
	for (int i=0; i<N; i++) ans += (vis[i]);
	cout << ans;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifdef Akikaze
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Input: " << ((OImode) ? infile : "stdin");
		cout << " | Output: " << ((OImode) ? outfile : "stdout") << endl << endl;
		cout << "MultiTest-Mode: " << ((MultiTest) ? "ON\n" : "OFF\n");
		cout << "Interactive-Mode: " << ((Interactive) ? "ON\n\n" : "OFF\n\n");
	#else
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/
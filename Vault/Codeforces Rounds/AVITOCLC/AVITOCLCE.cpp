/*********************************************************
*     Code written by Akikaze                            *
*     Duy-Bach Le, #Team4T's Chief Executor              *
*     #Team4T Tertiary Flagship - Oblivion               *
*                                                        *
*     Written by a random fan of momocashew and Chiho    *
*                                                        *
*     Arigatougozaimasu, imouto-chan.                    *
*********************************************************/

/***********************************************
** File name: AVITOCLCE.cpp                   **
** Time created: Sun Dec 16 2018 14:14pm      **
***********************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
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
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
#define MultiTest 227420978
#define Interactive 227420978

#undef OImode // Switch this off if submitting OI problems.
#undef MultiTest // Switch this off if submitting multi-test problems.
#undef Interactive // Switch this off if submitting interactive problems. Also required when you need to debug step-by-step.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
string cppstr_infile = "FILE.IN";
string cppstr_outfile = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 n; vi x, sum;
vector<set<pii>> sst, sen;
vector<vi> st, en;
/************************************************/

/************** [FUNCTIONS] **************/
pii findPair(i64 sum, i64 diff) {
	i64 lo = (sum - diff) / 2;
	i64 hi = (sum + diff) / 2;
	return mp(lo, hi);
}

i64 sqr(i64 z) {
	return (z * z);
}

void Input() {
	cin >> n; x.rsz(n); sum.rsz(n);
	for (i64 i=1; i<n; i+=2) cin >> x[i];
}

void Solve() {
	sst.rsz(n); sen.rsz(n);
	st.rsz(n); en.rsz(n);
	for (i64 i=1; i<n; i+=2) {
		i64 cnt = 0;
		for (i64 d=1; d<=sqrt(x[i]); d++) {
			if (x[i] % d != 0) continue;
			i64 dd = x[i] / d;
			if (dd % 2 != d % 2) continue;
			if (dd == d) continue;
			pii Pair = findPair(dd, d);
			i64 lo = Pair.fi, hi = Pair.se;
			sst[i].insert(mp(lo, cnt)); sen[i].insert(mp(hi,cnt));
			st[i].pub(lo); en[i].pub(hi); cnt++;
		}
		if (st[i].empty()) {cout << "No\n"; return;}
		i64 TokenEn, TokenSt;
		if (i == 1) {
			TokenEn = sen[i].begin()->fi;
			i64 id = sen[i].lower_bound(mp(TokenEn, -LINF))->se;
			TokenSt = st[i][id];
		}
		else {
			if (sst[i].lower_bound(mp(sqrt(sum[i-2]), +LINF)) == sst[i].end()) {cout << "No\n"; return;}
			TokenSt = sst[i].lower_bound(mp(sqrt(sum[i-2]), +LINF))->fi;
			i64 id = sst[i].lower_bound(mp(TokenSt, -LINF))->se;
			TokenEn = en[i][id];
		}
		if (i == 1) {
			x[i-1] = sqr(TokenSt);
			sum[i-1] = x[i-1]; sum[i] = sum[i-1] + x[i];
		}
		else {
			sum[i] = sqr(TokenEn);
			sum[i-1] = sqr(TokenSt);
			x[i-1] = sum[i-1] - sum[i-2];
		}
	}
	cout << "Yes\n";
	for (auto z: x) cout << z << " "; cout << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	
	#ifndef Interactive
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	#else
	ios_base::sync_with_stdio(0);
	#endif
	
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
	char* infile = new char[cppstr_infile.size()+1];
	char* outfile = new char[cppstr_outfile.size()+1];
	strcpy(infile, cppstr_infile.c_str());
	strcpy(outfile, cppstr_outfile.c_str());
	#ifdef Akikaze
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by #Team4T-Akikaze.\n";
	cout << "Current time: ";
	cout << (now->tm_year + 1900) << '-' 
	<< ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
	<< ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
	<< ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
	<< ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
	<< ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
	<< "\n\n";
	
	#ifdef OImode
	cout << "OI-Mode: ON\n";
	cout << "Input file: " << infile << endl;
	cout << "Output file: " << outfile << endl;
	cout << "\n";
	#else
	cout << "OI-Mode: OFF\n";
	cout << "Input file: NULL\n";
	cout << "Output file: NULL\n";
	cout << "\n";
	#endif
	
	#ifdef MultiTest
	cout << "MultiTest-Mode: ON\n";
	#else
	cout << "MultiTest-Mode: OFF\n";
	#endif
	
	#ifdef Interactive
	cout << "Interactive-Mode: ON\n\n";
	#else
	cout << "Interactive-Mode: OFF\n\n";
	#endif
	
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);
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

/*********************************************************************************************************************************************************************************************************
* ti;.                               .:,:i:         :,;;itt;.        fDDEDDEEEEEEKEEEEEKEEEEEEEEEEEEEEEEE###WKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWW#WWWWWKKKKKEE      :,:.    f::::. .,ijLGDDDDDDDEEEEEEE*
*ti;.                               .:,:i:          .:,;itt;:      GLDEEGEEEEEEEEEEEEEEEEEEDEEEEEEEEEEE#W#WEKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWWWWWKKKKKKG.     .::.      f:,...,ijLGDDDDDDDDEEEEEE *
*ti;.                               .:,:i:            :,;;iti,    :fDDEEEEEEEEEEEEEEEKEEEEDEEEEEEEEEEEW##WEEEKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWWWWWWKKKKKKEG     .::.       .f,::,ijLGDDDDDDDDEEEEEE *
*ti;.                               .:,:i:             .,,;iti;.  LDDEEEEEEEEEEKEEEEWEEEDDEEEEEEEEEEE#WWWEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWWKKKKKEDj    .::.        .:L;;ijfGDDDDDDDDDEEEEE *
*ti;.                               .:,:i:              .:,;;iii:LLDEEEEEEEEEEEKEEEEEEEEDEEEEEEEEEEEW#WWEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKWWKWWWWWWWWWWWWWWKKKKKKKEL    .::.         .:;LijLGGDDDDDDDDEEEEE *
*ti;.                               .:,:;:                :,;;ittfDEEEEEEEEEEEEEEEEKEEEGEEEEEEEEEEEKWWWEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWKKKKKKKELj   .::.          :,;jffGGDDDDDDDDDEEEE *
*ti;.                               .:,:i:                 .,;;tGGDEEEEEEEEEEEKEEEKEEEDEEEEEEEEEEEEWWWEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWKWWWWWWKKKKKKKEEL   .::.          .:;itDGGDDDDDDDDDEEEE *
*ti;.                               .:::;:                   :;ifDEEEEEEEEEEEEKEEEKEEEEEEEEEEEEEEEWWWEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#WWWKKKKKKKKEEf   .::.           :,itfGEDDDDDDDDDDDEE *
*ti;.                               .:::;:                    :GGEEEEEEEEEEEKEKEEKEEEEEEEEEEEEEEEEWWEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#WKKKKKKKKKEEDG  .::.           .,;jfLGKDLDDDDDDEEDD *
*ti;.                               .:::;:                     fDEEEEEEKKKKKKKKKEKEEEEEEEEEEEEEEE#WEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#KKKKKKKKKKEEf .:::.           .,;tfLGDEDDDDDDDDEEE *
*ti;.                                :::;:                    fDEEEEEEKKKKKKKKKKWKEEEEEEEEEEEEEEEWKEEEEEEEEEEEEEEEEEEEEKEKKKKKKKKKKKKKKKKKKKKKKKKKKKKW##KKKKKKKKKEEft :::.           .,;tfLGDDDKDDDDDDDDD *
*ti;.                                .::;:                    fDEEEEEEKKKKKKKWKKKKKEEEEEEEEEEEEE#WEEWEEEEEDEEDEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#WKKKKKKKKEEGG :,:.           .,;tfLGGDDDKDDDDDDDD *
*ti;.                                .:.;:                   tGDEEEEKKKKKKKKKKKKKKKKKEEEEEEEEEEEWEEKWEEEEEEEDEEEEEEEEEEEEEEKEKKKKKKKKKKKKKKKKKKKKKKKKKKWWWKKKKKKKEEDf :::.           .,;tfLGGDDDDEDDDDDDD *
*ti;.                                .::;:                   fDEEEEEKKKKKKKKKKKWKKKKKKKKEEEEEEEWWEEWEEEEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKW##KKKKKKKEEEft.::.           .,;tfLGGDDDDDDEDDDDD *
*ti;.                                .:.;:                  tGDEEEKKKKKKKKKKKKKKKKKKKKKKEKEEEEE#EEWWEEEEEEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKW#WKKKKKKEEEGD:::.           .,;tfLGGDDDDDDDEDDDD *
*ti;.                                .:.,.                  LDEEEEKKKKKKKKKKWKWKKKKKKKKKKKKEEEKWEKW#EEEEEEEEEEEEEEEEKEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKW##KKKKKKEEEEf,,:.           .,;tfLGGDDDDDDDDEDDD *
*ti;.                               ..:.,.                 LGDEEEEKKKKKKKKKKWKKKKKKKKKKKKKKKKKWEEW#WEEEEEEEEEEEEEEEKEEEEEEEEEEEEEEEEEEEKEKKKKKKKKKKKKKKKK##KKKKKEEEEEfi;,.           .,;tfLGGDDDDDDDDDKDD *
*tt;.                                .:.,:                 jDEEEEKKKKKKKKKKWWKKKKKKKKKKKKKKKKKWKE#WWEEEEEEEEEEEEEEWEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKWWKKKKEEEEDfG;,:           .,;tfLGGDDDDDDDDDDKD *
*tii,.                               .:.,.                tGDEEEEKKKKKKKKKKWWWKKKKKKKKKKKKKKKWKKWWWKEEEEEEEEEEEEEKEEEEEEEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKW#KKKKEEEEDGGi;,.          .,;tfLGGDDDDDDDDDDDE *
*ti;;,:.                             .:.,:                fDEEEEKKKKKKKKKKKWKKKKKKKKKKKKKKKKKWEK#WWKEEEEEEEEEEEEDEEEEEEEEEEEEEEGEEEEEEEEEEEEEEEEEEEKKKKKKKWWKKEEEEEEDDf;;;,.         .,;tfLGGDDDDDDDDDDDD *
*tii;,,:..                           ...,.               ;LEEEEEKKKKKKWKKKKWKKKKKKKKKKKKKKKKKEKKW#WEEEEEEEEEEEEEjEEEEEEEEEKEEEEGEEEEEEEEEKEEEEEEEEEEEEEEEEE#WKEEEEEEDDf;;;;,:        .,itfLGGDDDDDDDDDDDD *
*ti;,,,,,:.                          ...,.               LDEEEEKKKKKKKKKKKWWWKKKKKKKKKKKKKKKWKK#W#WEEEEEEEEEEEDDLEEEEEEEEEWEEEEDEEEEEEEEEKEEEEEEEEEEEEEEEEEWWEEEEEEEDDfj,,,,,:.      .,itfGGGDDDDDDDDDDDD *
*tii,,,,::::.                        ...,:              .fDEEEEKKKKKKWKKKKWWWKKKKKKKKKKKKKKKEKKW#WWEEEEEEEEEEEKiKEEKEEEEEEWEEEEDEEEEEEEEEEEEEEEEEEEEEEEEEEEWWEEEEEEEDDLD:::,,,:.     .,ijfGGGDDDDDDDDDDDD *
*ti;:::::::::..                      .:.,:              LDEEEEKKKKKKKWKKKKWWKKKKKKKKKKKKKKKKtKKWWWWKEEEEEEEEEDiiDEEEEEEEEWWEEEEEEDEEEEEEEEEEEEEEEEEEEEEEEEEEWKEEEEEDDDGL:. .:,,,:    .,ijLGGGDDDDDDDDDDDD *
*tt;. .::::::::..                    ...,:             :fDEEEKKKKKKKKKKKKWW#KKKKKKKKKKKKKKKKfKKWWWWKEEEEEEEEDti,DEKEEEEEEWWEEEDEEEEEEEEEKEEEEEEEEEEEEEDEEEEE#WEEEEEGGDGf:.  .:,;,:.  .,ijLGGDDDDDDDDDDDDD *
*tt;.   .:::::::..                   ...,:             GDEEEKKKKKKKKWKKKKWWWKKKWKKKKKKKWWWKDEKLWWWWKKEEEEEEDEi,LDEEEEEEEEWWEEEEEEEEEEEEEEEEEEEEEEEEEDEDEEEEEW#EEEEDDDDGf,.    :,,,:...,ijLGGGDDDDDDDDDDDD *
*tt;.    .....::::..                 ...,:             fDEEEKKKKKKKKWKKKKWWWWKKKWKKKKKKKKKKfWKiWWW#KKEEEEEEEi;.EDfEEEDEEiWWEEEEEEEEEEEEDGKEEEEEEEEEEDEEEEEEEWWEEEEDDDGGLi.     .,;,:::,ijLGGGDDDDDDDDDDDD *
*tt;.      ....:::::.                ...,.            iDEEEEKKKKKKKKWKKWKWWWWWKKWWWKKKKKKKKtWKt#WWWKKEEEEEDji..DDKDDEDEGiWKEEEEEEEEEEDDEjEEEEEEEEEEEDEEEEEEEKWKEEDDDDGGff.      .:,;,,;ijLGGGDDDDDDDDDDDD *
*tt;.        ....::::..              .:.,:           .LDEEEKKKKKKKKKKKKWWWWKWWWWWWWWWWKKKKWtKKiDWWWKKKEEEEKi:..DEDDDDDDiiWKEEEEEEEEEEDDEijDEEEEEKEEEEEEEEEEEEWWEEGDDDGGLG.       .:,;;iijLGGGDDDDDDDDDDDD *
*tt;.          .....:::..            ...,.           .fEEEEKKKKKKKKWKKKKWWWWWWWWWWWWWWKWKKKiKDiLWWWWKEEEEEi,..fD:DDDDDti;WEEEEEEEEEEKDDi:iDDEEEEWEEEEEEEEEEEE#WEEGDDDDGGG.         :,iitjLGGGDDDDDDDDDDDD *
*tti.            .....:::..          ...,.           GDEEEKKKKKKKKKWKKKWWW#WWWWWWWWWWWKWKKjiEjitWWWKKWEEEDi...DDLDDDDji;;WEEEEEEEEEEEDEj.iDDEEEEWEEEEEEEEEEEEWWEEDDDDDDGf.          .,;tjfLGGDDDDDDDDDDDD *
*tti.              ....::::..        ...,.           fEEEKKKKKKKKKKKKKKKW#WWWWWWWWWWWWWWWWtiEiiiWWWKKEWKEi....D.EDDDEi;.fWEEEEEEEEEEDDfL.;EDDEEEWEEEEEEEEEEEEWWEEEDDDDDGf.           :;ijfLGGDDDDDDDDDDDD *
*tti.                ....::::..      ...,.          LDEEEKKKKKKKKKKKKKKWWWWWWWWWWWWWWWW####WKiiiWWWKKKEEK,...:E:DDDEii..GWEEEEEEEEDWDDiL.,KDDEEEWEEEEEEEEEEEEWWKEEDDDDDGf:           .,itfLGGDDDDDDDDDDDD *
*tti.                 .....:::..     ...,.          fDEEEKKKKKKKKKWKKKKWWWWWWWWWWWWW########WLiiWWWKKKEEjD...G,DDDDi;...EWEEEEEEEEDKDEii..LDDEEEWEEEEEEEEEEEEWWWEEDDDDDGfi           .,;tfLGGGDDDDDDDDDDD *
*tti.                   .....:::..   ...,.         iGEEEKKKKKKKKKKWKKKKWWWWWWWWWWWW###########KiWWWKKEEE,.D..D.DDDii:...KKEEEEEEEEEDDj:...tEDEEEWEEEEEEEEEEEEWWWEEEDDDDDLL           .,;tjLLGGDDDDDDDDDDD *
*tti.                     ....::::......:.         LEEEKKKKKKKKKKWWKKKWWW#KWWWWWWWW#####W####W##KWWKKEEL..:D.jjDDi;,....KKEEEEEEEDfDDi...:iKDEEEWKEEEEEEEEEEEWWWEEEEDDDDLG           .,;tjLLGGDDDDDDDDDDD *
*tti.                        ...::::::..,.        :GEEEKKKKKKKKKKKKWWWWW##WWWWWWWWW##WKWK#W#W####WWKEEK.....G.DDti,.....KKEEEEEEDWGDf.,...iKDEEEWWEEEEEEEEEEEW#WEEEEEDDDGL           .,;tjLLGGDDDDDDDDDDD *
*tti.                         ....::::::,.        GDEEKKKKKKKKKKKKKWWWW###WWWWWWWWWW#WWWK###W#####WKEKK.....jDDL;;......KKEEEEEEEEEDi.f...;KDEEEWWEEEEEEEEEEEWWWWEEEEEDDGf           .,;tjLLGGDDDDDDDDDDD *
*tti.                           ....:::,,.       .LEEEKKKKKWKKKKKWWWWWW###WWWWWWWWWW#WWKW#WW##W#WWWKEKD:....:DD:;......;KEEEEEEEKiDD..f...,KKEEEWWEEEEEEEEEEEWWWWEEEEEDDDf           .:;tjLLGGGDDDDDDDDDD *
*tti.                             ...::,,,:.     GDEEKKKKKKKKKKKKWWWWWWW#WWWWWWWWWWW#KjKWWWWWWWWWWWWEK.j,..;fD.;.......fKEEEEEDKG:Di..,....DKEEEWWEEEEEEKEKKKWWWWEEEEEEDDf           .:;tjLLGGDDDDDDDDDDD *
*jti.                              ...::,,,,:.  .fEEEKKKKKWKKKKKKWWWWWWW#WWWWWWWWWWK#KKKWWWWWWWWWWWWWK..f:.:G.,:.......EKEEEEEKK;:E:.......fKEEEWWKEKEKKKKKKKW#WWEEEEEEDDf:          .,;tfLLGGDDDDDDDDDDD *
*tti.                               ...:,,,;;,: iDEEKKKKKWKKKKKKKWWWWWWW#WWWWWWWWWWK#WDKWWKKWWWWWWWWWE..;G:G..,........KKEEEEEKi.Gi..:.....tKEEKWWWKKKKKKKKKKW##WKEEEEEEDfi          .,;tfLLGGGDDDDDDDDDD *
*tti.                               ....::,,;;;,LEEKKKKKKWKKKKKWWWWWWW###WWWWWWWWWWKWWDKWEEEWKKWWWWWKKj.:LG..;.........EKEEEEKG;.G...;.....;KKEKWWWKKKKKKKKKKW##WWKEEEEEDfL          .,;tfLGGGDDDDDDDDDDD *
*jti.                                ...::::,;ijDEEKKKKKWKKKKKKWKWWWWW##WWWWWWWWWWWKK#KKGDGDWEEWKKWKKGE,.i;.:.........:EKEEEKE;.:L...j.....,KWEKWWWKKKKKKKKKK####WKKEEEEDLG          .,;tfLGGGGDDDDDDDDDD *
*jti.                                ...:...,,;GEEKKKKKWWKKKKKWWWWWWWW###WWWWWWWWWKKKWWKiLGGEDEDEKGKKiEG..;...........jKEEEKK;:.G....,.....:KKEWWWWKKKKKKKWKK####WKKKKEEEGL          .,;tfLGGGGDDDDDDDDDD *
*jti.                                ...:.  .:,GEEKKKKKWKKKKKWWWWWWWW####WWWWWWWWWKKKWWKii;fDLGDK: EEi:E:.............EKEEKK;;..L...........KKKWWWWKKKKKKKWKK####WKKKWKEEDf          .,;tfGGGGDDDDDDDDDDD *
*jti.                                ...:.    ,EEKKKKKWWKKKKKWWWWWWWWW###WWWWWWWWKKKKfWWLt;i,. fi  EG..D:.............EKEKK;;..t....:.......KWKWWWWKKKKKKKWKK####WKKKWEEEDf:.        .,;tfGGGGDDDDDDDDDDD *
*jti.                                ...:.    GEEKKKKKWKKKKKWWWWWWWWW####WWWWWWWKKKKKt;KKEfff     .;t.................KKKKi;:..GtGGfG.......KWWWWWWKKKKKKKWKK###WWWKKKKEEEf,,:       .,;tfGGGGDDDDDDDDDDD *
*jti.                                ...:.    GEKKKKKWWKKKKKWWWWWWWWWW##WWWWWWWKKKKKKt;EiKKKK,   ...t................jEKKG;;..,.....,LGi....KWWWWWWKKKKKKWKKKW####WKKKKKEEL,,,:.     .,;tfGGGDDDDDDDDDDDD *
*jti.                                ...:.  .GEEKKKKKWKKKKKWWWWWWWWWW###WWWWWWWKKKKKKtiE::tGG........................EEEj;;...,.........:D..DKWWWWWWKKKKK#KKW###W#WKKKKKEEfj:,,,:.   .,;tfGGGDDDDDDDDDDDD *
*jti.                                ...:.   DEKKKKKWWKKKKKWWWWWWWWW####WWWWWWWKKKKKKiiE:::.::.......................EEi;;...j.....f......:iDKWWWWWWKKKKK#WW######WKKKKKEELG :,,,,:. .,;tfGGGDDDDDDDDDDDD *
*jti.                                ...:.  fEEKKKKWWKKKKWWWWWWWWWWW###WWWWWWWWKKKKKK;tE::..........................DD;.;,.::......;........EWWWWWWWKKKKW#WW#####WWKKKWKKELG  .:,,,:::,;tfGGGDDDDDDDDDDDD *
*jti.                                ...:. .DEKEKKKWWKKKKWWWWWWWWWWW###WWWWWWWWKKKKKE,iD::..........................D..,;.,;tLffi...........DWDWWWW#KKKWWWWW#####W#KKKWKEEGL    .:,;,,,;tfGGGDDDDDDDDDDDD *
*jti.                                ...:. ;EEKKKKWWKKKKKWWWWWW#WWWW####WWWWWWKKKKKEL:iD:..........................j ..;..;;:.....i,........DKtWWWWWKKWWWWWW#####WWWKKKEKEDf     .:,;;;itfGGGDDDDDDDDDDDD *
*jti.                                ...:. DEKKKKKWWKKKKWWWWWWW#WWWW####WWWWWWKKKKKEj:iG...............................:....................GKiWWWWWKKWW#WWW######WWKKKKKEEf       .,;iitfGGGDDDDDDDDDDDD *
*jti.                                ...:.:EKKKKKWWKKKKKWWWWWWW#WWW#####WWWWWKWKKKKEi:if:.................................iEKEKKKKKKDj......DKiWWWWWKWK##WW#######WWKKK:KEEL        .:;itfGGGDDDDDDDDDDDD *
*jji.                                ...:,DEEKKKWWWKWKKWWWWWWWWWWWW#####WWWWWWWKKKKEi:it..................................j.  KKKKKKKKKKKf..DKiWWWWWKWW##WW#######WWKKK,KEEf         .,;tfGGGDDDDDDDDDDDD *
*jji.                                ..L:iDEEKKKWWKKKKKWWWWWWWWWWWW#####WWWWWKWKKKKKi.i;..................................  . KKKWWWWWWWWK..DGiWWWWWKK##WWW#####W#WWKKKjEKEL,        .:;tfGGGDDDDDDDDDDDD *
*jji.                               .f:::EEEKKKWWWKKKKKWWWWWWWWWWWW#####WWWWWKWKKKKK;.i,.................................::  KKEKWWWWWWfWK..EiiWWWWWKWW#WW##########KKKD,KELj        .:;tfGGDDDDDDDDDDDDD *
*jji.                             .t::::,DEEKKKWWKKKKWWWWWWWWW#WWWW#####WWWWKKWKKKEK;.i:.................................GDDEEEKKKWWWWWtWWD.E;iWWWWWW###WW#########WWKKK.EEDG        .:;tfGGGDDDDDDDDDDDD *
*jji.                          . j..::::EKEKKKWWWKKKKWWWWWWWWW#WWW######WWWWKKWKKKEK;.t:.................................ELLEDDEEEWWWWEtWK,.KiiWWWWWW###W##########WWKKK:EEEG     .;tjfLLGDDDDDDDDDDDDDDD *
*jji.                          i.::::::,EEEKKWWWKKKKKWWWWWWWWW#WWW#####WWWWWKWKKKKEE,.t..................................DfiEGDDDEEKKKttKWG.KiiWWWWW##WWW##########WWKKK:fEEL  ,fGGGDDDDDDDDEEEDDDDDDDDDD *
*jji.                        .;:..:::::DEEEKKWWWKKKKKWWWWWWWWW#WWWW####WWWWWWWKKKKED,.t..................................ifjDDGGEGDKK.ttKKE.DiWWWWW###WW##########WWWKKK:.KELiLGGGGDDDDDDDDDDDDEEEDDDDDDD *
*jji.                       i.:.::::::,KEEKKWWWKKKKKKWWWWWWWWW#WWWW####WWWWWWWKKKKEL:.j..................................GGf,;ifLLED .iiKKi:fWWWWWW##W#W##########WWWKKK:.KKLGGDDDDDDDDDDDDDDDDEDDEEDDDDD *
*jji.                     .j:.::::::::EEEKKKWWWKKKKKKWWWWWWWW##WWW#####WWWWWWWKKKKKf:.f..................................:EEfftf .,. ;iE,..jWWWWWWW###W############WWKKK,:KKGDDDDDDDDDDDDDDDDDDDDDDDEDDDD *
*jji.                    .:.::::::::,,EEEKKWWWKKKKKKKWWWWWWWW##WWW#####WWWWWWWKKKKKt..G....................................EEELL;   .j....tKWWWWWWW################WWWKKtfGKGEDDDDDDDDDDDDDDDDDDDDDDDEEDD *
*jji.                   :...:::::::,,jEEKKWWWWKKKKKKWWWWWWWWW##KWW#####KWWWWWWKKKKEi..D....................................:jEEE.........;KKWWWWWWWW#WW##W##########WWKKDLGKEKDDDDDDDDDDDDDDDDDDDDDDDDDED *
*jji.                  i:.::::::::,,,EEEKKWWWWKKKKKWWWWWWWWWW##WWW#####WWWWWWWKKKKKi..D......................................:::::......,KKKWWWWWWWWW#####W########WWWKKKGGKKEGGGGGGGGDDDDDDDDDDDDDDDDDDE *
*jji.                 i..:::::::::,,tEEKKWWWWKKKKKWWWWWWWWWWW##WW######WWWWWWWKKKKKi..D......................................::::......:EKKKWWWWWWWWWWW##WW########W#WKKWGGKKGGGGGGGGGGGGGGGDDDDDDDDDDDDD *
*jji.                .:::::::::::,,,EEEKKWWWWKKKKKWWWWWWWWWWW##WW#####WWWWWWWWKKKKKi..D....................................:::::::::..tELii;KWWWWWWWWWW##WW######WWWWWWKWGGGKGGGGGGGGGGGGGGGGGGGGGGGGGGDG *
*jjt.                :.::::::::,,,,fEEKKWWWWKKKKKKWWWWWWWWWW###WW####WWWWWWW#WKKKKKi..D....................................:::::::.:.,;;;;;;,KKWWWWWWWWW#WW########WWWKKWGGGKGGGGGGGGGGGGGGGGGGGGGGGGGGGG *
*jji.               ;.::::::::,,,,;EEEKWWWWWKKKKKWWWWWWWWWWWW##WW###WKWWWWWK#WKKKKKi..G......................................:::::::,;;;;:...KKKWWWWWWWWWKWW#######WWWWKKGLGKDGGGGGGLLGGGGGGGGGGGGGGGGGGG *
*jjt.              f.:::::::::,,,,fEEKKWWWWWKKKKKWWWWWWWWWWW###WW##WKKWWWWWW#WKKKKK;.jt........i.............................:::::::;j;;....:E.KKKWWWWWWWKWW#####W#WWWWKKLLGWEEGGGGGLGGGGGGGGGGGGGGGGGGGG *
*jjt.             ...:::::::,,,,,;DEEKWWWWWKKKKKWWWWWWWWWWWW####WWWKKKWWWWWWWWKKKKK;.E;.........t.............................:::::ii;;.....D...KKWWWWWWWKWW#####WWEWWWKKGGGEKKGGGGGLGGGGGGGGGGGGGLGGGGGG *
*fji.             ;.:::::::,,,,,;LEEKKWWWWWKKKKKWWWWWWWWWWWW####KWKKKKWWWWWWWWKKKKKi.D;..........j.............................:::tt;,.....:.....KKWWWWWWKWWWW##WWWGWWWKKGGGGKEGGGGGGGGGGGGGGGGGGGLLGGGGL *
*fji.            t::::::::,,,,,,;EEEKWWWWWKKKKKKKWWWWWWWWWWW##WKWKKKKKWWWWWWWWKKKKKi:D;............j...........................::LL;,.............KKWWWWWKWWWWWWWWWGWWWKKGGGGKGGGGGGGGGGGGGGGGGGGGLLGGGGL *
*fjt:            .:::::::,,,,,,,DEEKWWWWWWKKKKKKKWWWWWWWWWWWWKKWKKKKKKWWWWK#WWKKKKWitE;........... ............................:G;;:...............KKKWWKKWWWWWWWWWGWWWKKGGGGWGGGGGGGGGGGGGGGGGGGGGGGGGGL *
*fjji;:.       .f:::::::,,,,,,,;EEEKWWWWWWKKKKKKWWWWWWWWWWWKKKKKKKKKKKWWKWWWWWKKKKWGKD;........................................L;;..................DKKWKKWWWWWWWWWGWWWKKDGGGKDGGGGGGGGGGGGGGGGGGGGGGGGGG *
*fjjtii;,:.     :::::::,,,,,,,;EEEKWWWWWWKKKKKKWWWWWWWWWWKKKKKKKKKKKKWWWWWW#WWKKKKWiEj;......................................:i,;....,...............;KKEKWWWWWWWWWGKWWKKDDGGDEGGGDGGGGGDGGGGGGGGGGGGGGGG *
*fjtiiiii;;:.  j::::::,,,,,,,;;EEEKWWWWW#KKKKKWWWWWWWWWKKKKKKWKKKKKKKWWWWWWWWWKKKKWtEL;:....................................;;;:...,;j................:KEEWWWWWWWWWDDWWKKDDDDDKDDDDDDDDDDDDDDDGGGGGGGGGGG *
*fjti;;iiii;;,:::::::,,,,,,,,;EEEKWWWWWWWKKKKWWWWWWWWKKKKKKKWKKKKKKKWWWWWWW#W#KKKKWEEii;...................................f;:....,;L...................EEKWWWWWWWWDDWWKKDDDDDKEDDDDDDDDDDDDDDDDDDDDDGGGG *
*fjt,,,;;;;ii;f::::::,,,,,,,;;EEKWWWWWWWKKKKKWWWKWWKKKKKKKKKKKKKKKKKWWWWWWW#W#KKKKWKEij;:...............................:G;,.....,;f....................:tKKWWWWWWWDDWWKKDDDDDKKDDDDDDDDDDDDDDDDDDDDDDDDD *
*jjt. ..:,;;;;,::::,,,,,,,,;;GEEWWWWWWWWKKKKWKKWKKKKKKKKKKKKKKKKKKKKWWWWWWW#W#KKKKWEDi;j;............................,Li;L;;;..,;;f........................KKKKWWWKDDWWKKDDDGDKKGGGGGGGGDGDDDDDDDDDDDDDDD *
*fjt.    .:,,,:::::,,,,,,,;;;EEKWWWWWWWKKKKKKWKKKKKKKKKKKKKKKKKKKKKWKKKWKW##W#KKKKWEti;;G;........................tEEEL;;;;;;;;;;L..........................DKKKKKEDDWWKEDGftiLE;;;;itjLGGGGGGDDDDDDDDDDD *
*fjt.       .j::::,,,,,,,;;;DEEWWWWWWWWKKKKWKKKKKKKKKKKKKKKKKKKKKKKWKKWWWK##W#KKKKKEii;;;L;...................iDEEEEEEKKi;j;;;;jD.....:......................,KKKKDGGEKKE:::::;E::::::::::,tLGGDDDDDDDDDD *
*fjt.       .;:::,,,,,,,;;;;EEKWWWWWWWWKWKKKKKKKKKKKKKKKWKKKKKKKKKKWKKWWWW#WW#KKKKKKii;;;;f;.............:tDEEEEEKKKKKKKKEti;;;L...............................EEKf;:iKKE::::::E::::::::::::::ifDDDDDDDDD *
*fjt:        :::,,,,,,,,;;;DEEWWWWWWWWWEKKKKKKKKKKKKKKKKKKKKKKKKKKWWKKWWWW####KKKKKEiii;;;;f,.........iDEEEEKKKKKKKKKKKKKKKf;iG......i..........................fK::::KKE::::::E::::::::::::::::,tGGDDDDD *
*fjt:       t:::,,,,,,;;;;iDEKWWWWWWKEKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWKKWWWW####WKKKKLiii;;;;;L,....,Li;EDEEEEKKKKKKKKKKKKKKKKiG......;:...........................:i:::KKE:::::,E,::::::::::::::::::iGDDDD *
*jjt.       f::,,,,,,,;;;;GEEWWWWKEEKEKKKKKKKKKKKKKKKKWKKKKKKKKKKKWWKWWWWW###WWKKKKiii;;;;;;;G,;L;;iiEEEEEEEKKKKKKKKKKKKKWWKE......;t.........:....................j::KEE:,::,,D,,::::,,,,,,:::::::::tDDD *
*fjt:.      ,::,,,,,,,;;;;EEWWKEEEEEEKKKKKKKKKKKKKKKKWKKKKKKKKKKKWWKKWWWWW#W#KKKKKKiiiiii;;;;;i;;iiiEEKEEKKWKKKKKKKWKKKKKWWWGi;...;t......,;;;;,....................:,EEE,,,,,,D,,,,,,,,,,,,,,,,::,::::tG *
*fjt:.     ,::,,,,,,,;;;;DEKEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWW#W#KKKKKKiiiii;;i;;;;;iiiKKKEKKKKWWKWWWWWWKKKKWWWWW;;;:;L.....;;;;;;;;;....................,KEE,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,,; *
*fjt:.     f:,,,,,,,;;;;jEDEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWW#W##KKKKKKiiiiiiii;i;;iiiEKKKKKKKKWKWWWWWWWWKKKWWWWWKi;;i.....,jEEfGi;;;;;...................EED,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,,, *
*fjt:.    .f::,,,,,,;;jEEDEEEEEEEEEEKKKKKKKKKKKKKKKWKKKKKKKKKKKKKWWWKWWWWW###KKKKKLiiiiiiiiiiiiiiEEKKKKKKKKWWWWWWWWWWWWKWWWWWWGi;i;,..;jDDDKEGi;;;;;;:................EED,,,,,,D,,,,,,,,,,,,,,,,,,,,,,,,, *
*fjt:.  .. ;::,,,,,;;EDDEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWKKW#WW####KWKKKiiiiiiiiiiiiijKKKKKKKKKKWWWWWWWWWWWWWWWWWWWWWt;i;;;;i;DDDDDDGi;;;;;;;;:.............EDf;,,,;,G;;;;;;;;;;;;;;;,,,,,,,,,, *
*fjt:......:,,,,,,;LDDDEEEEEEEEEEEKKKKKKKKKKKKKKKKWKKKKKKKKKKKKKWWWWKWWWW####KKKKKiiiiiiiiiiijKEKKWKKKKKKKWWWWWWWWWWWWWWWWWWWWWWiLiii;i;DEEEEDDE;i;;;;;;;;;:..........EDi,;;;;;L;;;;;;;;;;;;;;;;;;,,,,,,, *
*fjt:......:,,,,,;EDDDEEKEEEEEEEEEKKKKKKKKKKKKKKKWKKKKKKKKKKKKKKWWWWKKWWW##W#KWKKWEiiiiiijGKKKKKWWKKKKKKKKWWWWWWWWWWWWWWWWWWWWWWKi;iiiiDDEEEEEEDEi;;;;;;;;;;;;;,:.....ED;;;;;;;j;;;;;;;;;;;;;;;;;;;;;;;,, *
*fjt:.....t,,,,,;DDDDEEEKEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWKKKWWWW##WKWKKWKiiiKKKKKKKKKWWKKKKKKKKWWWWWWWWWWWWWWW#WWWWWWWWWiiiiifLEEEEEEEEDi;i;;;;;;;;;;;;.....DD;;;;;;;i;;;;;;;;;;;;;;;;;;;;;;;;; *
*fjt:.....G,,,,,GDDDEEEEEEEEEEEEKKKKKKKKKKKKKKKKWKKKKKKKKKKKKKKKWWWKKKWWW###WKWKKWKitKKKKKKKKKWKKKKKKKKKKWWWWWWWWWWWWWW###WWWWWWWWEiiiiiiiEEEEEEEEDGiiii;;;;;;;;;.....GD;;;;;;;i;;;;;;;;;;;;;;;;;;;;;;;;; *
*fjt:.....L,,,,;GDDDEEEEEEEEEEKEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWDGWWW###KKWWKWKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWW####WWWWWWWWWiiiiiiiiEEEEEEEEEEDi;i;;;;;;;;.....Lj;;;;;;i;iiiiii;;;;;;ii;;;;;;;;;;; *
***********************************************************************************************************************************************************************************************************/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define SZ(x) ((int)(x.size()))
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for( i = int(a); i >= int(n); i--)
#define IN(x, y) ((y).find(x) != (y).end())
#define ALL(t) t.begin(),t.end()
#define MSET(tabl,i) memset(tabl, i, sizeof(tabl))
#define PSET(x,y) fixed<<setprecision(y)<<lf(x)
#define DBG(c) cout << #c << " = " << c << endl;
#define RTIME ((double)clock()/(double)CLOCKS_PER_SEC)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Mod 1000000007

typedef long long int ll;
typedef long double lf;
typedef pair < ll, ll > pii;
typedef pair < ll, ll > pll;
typedef vector < ll > vi;
typedef vector<vi> vvi;
typedef complex<double> base;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1> 
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const int N = 1e5 + 5;
const int lgN = 1e6+5;
const int te = 3e8+1;
const ll MOD = 998244353;
const lf pi = 3.141592653589793238462643383;
const ll IMAX = 1e9 + 5; 
const double PI = 3.141592653589793;


template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>; 
template<class T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll x,y;
template<class T> T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 

ll modInverse(ll A, ll M)
{
    gcd(A,M);
    return (x%M+M)%M;    //x may be negative
}




int main()
{
    ll n,i;
    cin>>n;
    string s;
    cin>>s;
    vvi dp1(n+1, vi (2)),dp2(n+1, vi (2)),dp3(n+1, vi (2));
    vector<char> v(n+1);  // B G R
    FOI(i,1,n)
    {
        ll a=0,b=0,c=0;
        if(s[i-1]=='B')
        a++;
        if(s[i-1]=='G')
        b++;
        if(s[i-1]=='R')
        c++;

        //trace(a,b,c);
        if(dp2[i-1][0]<dp3[i-1][0])
        {
            dp1[i][0]=dp2[i-1][0]+1-a;
            dp1[i][1]=2;
        }
        else
        {
            dp1[i][0]=dp3[i-1][0]+1-a;
            dp1[i][1]=3;
        }


        if(dp1[i-1][0]<dp3[i-1][0])
        {
            dp2[i][0]=dp1[i-1][0]+1-b;
            dp2[i][1]=1;
        }
        else
        {
            dp2[i][0]=dp3[i-1][0]+1-b;
            dp2[i][1]=3;
        }


        if(dp2[i-1][0]<dp1[i-1][0])
        {
            dp3[i][0]=dp2[i-1][0]+1-c;
            dp3[i][1]=2;
        }
        else
        {
            dp3[i][0]=dp1[i-1][0]+1-c;
            dp3[i][1]=1;
        }



       // trace(dp1[i][0],dp2[i][0],dp3[i][0],dp1[i][1],dp2[i][1],dp3[i][1]);
    }
    ll k;
    cout<<min(dp1[n][0],min(dp2[n][0],dp3[n][0]))<<"\n";
    if(dp1[n][0]<=dp2[n][0]&&dp1[n][0]<=dp3[n][0])
    k=1;
    else if(dp2[n][0]<=dp1[n][0]&&dp2[n][0]<=dp3[n][0])
    k=2;
    else if(dp3[n][0]<=dp2[n][0]&&dp3[n][0]<=dp1[n][0])
    k=3;
    FOD(i,n,1)
    {
        
        if(k==1)
        {
            v[i]='B';
            k=dp1[i][1];
        }
        else if(k==2)
        {
            v[i]='G';
            k=dp2[i][1];
        }
        else if(k==3)
        {
            v[i]='R';
            k=dp3[i][1];
        }
        //trace(v[i],k);
        
    }
    FOI(i,1,n)
    cout<<v[i];
}

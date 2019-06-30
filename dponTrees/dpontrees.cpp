//adjacency list
//adj[i] contains all neighbors of i
vector<int> adj[N];

//functions as defined above
int dp1[N],dp2[N];

//pV is parent of node V
void dfs(int V, int pV){

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    int sum1=0, sum2=0;

    //traverse over all children
    for(auto v: adj[V]){
    if(v == pV) continue;
    dfs(v, V);
    sum1 += dp2[v];
    sum2 += max(dp1[v], dp2[v]);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}


// // #include<iostream>
// // #include<unordered_map>
// // #include<list>
// // #include<queue>
// // using namespace std;

// // class graph
// // {
// //     public:
// //         unordered_map<int, list<int> > adj;
// //         void addEdge(int u, int v, bool direction){
// //             //direction --> 0 --> undirected
// //             //direction --> 1 --> directed

// //             adj[u].push_back(v);
// //             if(direction==0) adj[v].push_back(u);
// //         }

// //         void printAdjList(){
// //             for(auto i:adj){
// //                 cout<<i.first<<" -> ";
// //                 for(auto j:i.second){
// //                     cout<<j<<", ";
// //                 }
// //                 cout<<endl;
// //             }
// //         }

// //         void bfsTraversal(){
// //             vector<int> vis;
// //             vis[0] = 1;
// //             vector<int> bfs;
// //             queue<int> q;
// //             q.push(0);

// //             while(!q.empty()){
// //                 int node = q.front();
// //                 q.pop();
// //                 bfs.push_back(node);

// //                 for(auto it : adj[node]){
// //                     if(!vis[it]){
// //                         vis[it] = 1;
// //                         q.push(it);
// //                     }
// //                 }
// //             }

// //             for(auto j: bfs){
// //                 cout<<bfs[j]<<" ";
// //             }
// //         }
// // };

// // int main()
// // {
// //     int n, m;
// //     cout<<"Enter the number of nodes: ";
// //     cin>>n;
// //     cout<<"Enter the number of edges: ";
// //     cin>>m;

// //     graph g;

// //     for(int i=0; i<m; i++){
// //         int u, v;
// //         cin>> u >> v;
// //         g.addEdge(u,v,0);
// //     }

// //     g.printAdjList();

// //     return 0;
// // }

// #include<iostream>
// using namespace std;

// int main()
// {
//     long long int ans = 11;
//     for(int i=0; i<11; i++){
//         ans = pow(11,ans);
//     }
//     cout<<ans;
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> arr) {
    int n = arr.size();
    int leftPointer = 0;
    int rightPointer = n - 1;
    int operations = 0;

    while (leftPointer < rightPointer) {
        while (leftPointer < n && arr[leftPointer] == 1) {
            ++leftPointer;
        }

        while (rightPointer >= 0 && arr[rightPointer] == 1) {
            --rightPointer;
        }

        if (leftPointer < rightPointer) {
            operations += (rightPointer - leftPointer);
        }
    }

    return operations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(arr) << endl;
    }

    return 0;
}

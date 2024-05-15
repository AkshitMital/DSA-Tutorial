#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUltimateParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v ){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v ){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            
        }

};

int main()
{
    // DisjointSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout<<"Same"<<endl;
    // else cout<<"Not same"<<endl;

    // ds.unionByRank(3,7);
    // if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout<<"Same"<<endl;
    // else cout<<"Not same"<<endl;

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;

    ds.unionBySize(3,7);
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;

    return 0;
}
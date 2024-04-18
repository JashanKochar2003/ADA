#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;
const int size = 50000;
template <typename T>



class graph {
    public:
    unordered_map<T,vector<pair<T,int>>> adj;
    vector<vector<int>> cost;

   graph(int n){
        cost.resize(n, vector<int>(n, INT16_MAX));
        cout << "done1" << endl;
    }
    
    void addEdge(T u, T v ,int w, int dir){
        adj[u].push_back(make_pair(v,w));
        cost[u][v]=w;
        if(dir == 0){
        adj[v].push_back(make_pair(u,w));
        cost[v][u]=w;
        }
    }

    void printGraph(){
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"["<<j.first<<","<<j.second<<"]"<<", ";
            }
            cout<<endl;
        }
    }

    void printCost(){
        for(int i=0;i<cost.size();i++){
            for(int j=0;j<cost[i].size();j++){
                cout<<cost[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

void adding_multiple_edges(graph<int> &g,int vertices, int edges, int direction){
    int i=0;
    while(i<edges){
        int p,q,w;
        p = rand()%vertices;
        q = rand()%vertices;
        w = rand()%100;
        if(g.cost[p][q]!=INT16_MAX){
            cout<<"entered vertices are already present"<<endl;
        }
        else{
            g.addEdge(p,q,w,direction);
            i++;
        }
    }
}

void prims(graph<int> g, int n,int t[50][2]){
    int min = g.cost[0][0];
    int k;
    int l;
    int near[n];
    int mincost = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g.cost[i][j]<min){
                min = g.cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[0][0]=k;
    t[0][1]=l;

    for(int i=0;i<n;i++){
        if(g.cost[i][k]<g.cost[i][l])
            near[i]=k;
        else{
            near[i]=l;
        }    
    }
    near[k]=-1;
    near[l]=-1;
    mincost += g.cost[k][l];
    for(int j=1;j<n;j++){
        int minimum = INT16_MAX;
        int v1;
        int v2;
        for(int u=0;u<n;u++){
            if(near[u]!=-1 && g.cost[u][near[u]]<minimum){
                    minimum = g.cost[u][near[u]];
                    v1 = u;
                    v2 = near[u];
            }
        }
        t[j][0]=v1;
        t[j][1]=v2;
        mincost += g.cost[v1][v2];
        near[v1]=-1;

        for(int w=0;w<n;w++){
            if(near[w]!=-1 && g.cost[w][near[w]]>g.cost[v1][w])
            near[w]=v1;
        }
    }

}

int main(){
    int dir;
    cout<<"enter 1 for directed and 0 for undirected graph : ";
    cin>>dir;
    fstream file;
    file.open("prims_complexity.txt",ios::out);
    for(int i=10; i<=size;){
    int avg_time =0;
    int total_time = 0;
   int p = 0;
    while(p<2){
    int n = i;
    int m = n+10;
    int t[i][2];
    graph<int> g(n);
    adding_multiple_edges(g,n,m,dir);
    auto start = high_resolution_clock::now();
    prims(g,n,t);
    auto stop = high_resolution_clock::now();
    //for(int k=0;k<n-1;k++){
    //cout<<t[k][0]<<" "<<t[k][1]<<endl;
    //}
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    cout<<"time "<<p<<" added"<<endl;
    p++;
    }
    avg_time = total_time/2;
    cout<<"avg time taken for vertices = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<"   "<<avg_time<<endl;
     if(i<1000)
     i *=10;
     else if(i>=1000)
     i+=1000;
    }
    return 0;
}

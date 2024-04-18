#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std ;
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
        cout<<"enter vertices in which edge is present and weight of edge : "<<endl;
        int p,q,w;
        cin>>p>>q>>w;
        if(p>=vertices || q>=vertices){
            cout<<"entered vertices are not present"<<endl;
        }
        else{
            g.addEdge(p,q,w,direction);
            i++;
        }
    }
}

void findr(graph<int> g, int j,int n,int fCost[],int &r){
    int min = INT16_MAX;
    for(int i=j+1;i<n;i++){
        if(g.cost[j][i]!=0 && g.cost[j][i]!=INT16_MAX && g.cost[j][i]+fCost[i]<min){
                        r=i;
                        min = g.cost[j][i]+fCost[i];
        }
    }
}

int number_of_stages(graph <int> g,vector<int> list,int n,int k=1){
    vector<int> new_list;
    for(int i=0;i<list.size();i++){
        for(int j=0;j<n;j++){
            if(g.cost[list[i]][j]>0 && g.cost[list[i]][j]<INT16_MAX){
                new_list.push_back(j);
            }
        }
    }
    if(new_list.size()==0)
    return k;
    k = number_of_stages(g,new_list,n,k+1);
    cout<<"number of stages : "<<k<<endl;
    return k;
}

void fCost_algo(graph <int> g,int n , int k){
    int fcost[n];
    int r;
    int d[n];
    int p[k];
    d[n-1]=-1;
    fcost[n-1]=0;
    p[0]=0;
    p[k-1]=n-1;
    for(int j=n-2;j>=0;j--){
        findr(g,j,n,fcost,r);
        fcost[j]=g.cost[j][r]+fcost[r];
        d[j]=r;

    }
    for(int j=1;j<k-1;j++){
        p[j]= d[p[j-1]];
    }

    for(int i=0;i<k;i++){
        cout<<p[i]<<"\t";
    }
}

int main(){
    int n;
    int m;
    int dir;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<"enter number of edges : ";
    cin>>m;
    cout<<"enter 1 for directed and 0 for undirected graph : ";
    cin>>dir;
    graph<int> g(n);
    adding_multiple_edges(g,n,m,dir);
    vector <int> list;
    list.push_back(0);
   int k = number_of_stages(g,list,n);
   fCost_algo(g,n,k);
    return 0;
}

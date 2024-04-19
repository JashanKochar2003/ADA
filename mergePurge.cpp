#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> mergePurge(vector<pair<int,int>> v1 , vector<pair<int,int>> v2){
    vector<pair<int,int>>v3;
    int m = v1.size();
    int n = v2.size();
    cout<<m<<" "<<n<<endl;
    int i=0;
    int j=0;
    int k=0;
    while(i<m || j<n){
        cout<<"done1"<<endl;
        while(i<m && j<n){
             cout<<"done2"<<endl;
        if(v1[i].first < v2[j].first){
            if(k==0){
                 cout<<"done3"<<endl;
                v3.push_back(v1[i]);
                k++;
                i++;
            }
            else if(v3[k-1].second > v1[i].second){
                k--;
                v3[k].first = v1[i].first;
                v3[k].second = v1[i].second;
                k++;
                i++;
                 cout<<"done4"<<endl;
            }
            else{
                 cout<<"done5"<<endl;
                v3.push_back(v1[i]);
                k++;
                i++;
            }
        }
        else{
                if(k==0){
                     cout<<"done6"<<endl;
                v3.push_back(v2[j]);
                k++;
                j++;
            }
            else if(v3[k-1].second > v2[j].second){
                k--;
                v3[k].first = v2[j].first;
                v3[k].second = v2[j].second;
                k++;
                j++;
                 cout<<"done6"<<endl;
            }
            else{
                v3.push_back(v2[j]);
                k++;
                j++;
                 cout<<"done7"<<endl;
            }
        }
    }
    if(i<m){
         cout<<"done8"<<endl;
            if(k==0){
                v3.push_back(v1[i]);
                k++;
                i++;
                 cout<<"done9"<<endl;
            }
            else if(v3[k-1].second > v1[i].second){
                k--;
                v3[k].first = v1[i].first;
                v3[k].second = v1[i].second;
                k++;
                i++;
                 cout<<"done10"<<endl;
            }
            else{
                v3.push_back(v1[i]);
                k++;
                i++;
                 cout<<"done11"<<endl;
            }
    }
    else if(j<n){
             if(k==0){
                v3.push_back(v2[j]);
                k++;
                j++;
                 cout<<"done12"<<endl;
            }
            else if(v3[k-1].second > v2[j].second){
                k--;
                v3[k].first = v2[j].first;
                v3[k].second = v2[j].second;
                k++;
                j++;
                 cout<<"done13"<<endl;
            }
            else{
                v3.push_back(v2[j]);
                k++;
                j++;
                 cout<<"done14"<<endl;
            }
    }
    }
    return v3;
}

vector<pair<int,int>> setMaker(vector<pair<int,int>> s ,vector<vector<pair<int,int>>> &s2 , int profitList[] , int weightList[] ,int i, int maxW){
        vector<pair<int,int>> temp;
        cout<<"set4"<<endl;
        int sum1 = 0;
        int sum2 = 0;
        for(int j=0;j<s.size();j++){
            sum1 = s[j].first+profitList[i];
            sum2 = s[j].second+weightList[i];
            if(sum2<=maxW)
            temp.push_back(make_pair(sum1,sum2));
        }
        s2.push_back(temp);
        cout<<"set5"<<endl;
}

int main(){
    vector<pair<int,int>> v2;
    vector<vector<pair<int,int>>> s;
    vector<vector<pair<int,int>>> s2;
    v2.push_back(make_pair(0,0));
    s.push_back(v2);
    int weightList[] ={5,3,4,6};
    int profitList[] = {10,30,45,70};
    int maxW = 10;
    for(int i=1;i<=4;i++){
        cout<<"set1"<<endl;
        setMaker(s[i-1],s2,profitList,weightList,i-1,maxW);
        cout<<"set2"<<endl;
        s.push_back(mergePurge(s[i-1],s2[i-1]));
        cout<<"set3"<<endl;
        for(int j=0;j<s[i].size();j++){
            cout<<s[i][j].first<<","<<s[i][j].second<<"\t";
        }
        cout<<endl;
    } 
    return 0;

}
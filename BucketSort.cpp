#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


void Bucket(vector<float>&v,int n){
    //Creating a bucket
    vector<vector<float>> bucket(n,vector<float> ());

    //Inserting an elements
    for(int i=0;i<n;i++){
        int Idx = v[i]*n;
        bucket[Idx].push_back(v[i]);
    }

    //Sorting Individual buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    //Combining Elements from buckets
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            v[k++] = bucket[i][j];
        }
    }
}




int main(){
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;

    vector <float> v(n);


    cout<<"Enter element of array: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    Bucket(v,n);

    cout<<"Sorted Array:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;

}
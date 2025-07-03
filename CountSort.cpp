#include<iostream>
#include<vector>

using namespace std;


void Count(vector<int> &v,int n){
    int max_ele = v[0];
    for(int i=1;i<n;i++){
        max_ele = max(v[i],max_ele);
    }

    vector<int>freq(max_ele+1,0);
    int ans[n];

    for(int i=0;i<max_ele+1;i++){
        freq[i]=0;
    }

    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }

    for(int i=1;i<max_ele+1;i++){
        freq[i] = freq[i-1] + freq[i];
    }

    for(int i=n-1;i>=0;i--){
        int ansIdx= --freq[v[i]] ;
        ans[ansIdx]=v[i];
    }

    for(int i=0;i<n;i++){
        v[i] = ans[i];
    }

}
int main(){

    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;

    vector <int> v(n);


    cout<<"Enter element of array: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    Count(v,n);

    cout<<"Sorted Array:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
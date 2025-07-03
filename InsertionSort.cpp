#include<iostream>
#include<vector>
using namespace std;


void Insertion(vector<int> &v){
    for(int i=1;i<v.size();i++){
        int curr = v[i];
        int j = i-1;
        while(v[j] > curr && j>=0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = curr;
    }
}

int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    vector<int> v(n);

    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    Insertion(v);

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}
#include<iostream>
#include<vector>

using namespace std ;

void Selection(vector<int> &v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            int min_idx = i;
            if (v[j] < v[min_idx]){
                min_idx = j;
            }

            if(min_idx != i){
                swap(v[min_idx],v[i]);
            }
        }
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

    Selection(v);

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}
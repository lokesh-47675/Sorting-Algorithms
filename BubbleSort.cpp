#include<iostream>
#include<vector>

using namespace std ;

void Bubble(vector<int> &v){
    for(int i=0;i <v.size()-1;i++){
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
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

    Bubble(v);

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}
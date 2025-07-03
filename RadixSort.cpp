#include<iostream>
#include<vector>

using namespace std;


void Count(vector<int> &v,int n,int pos){
    vector<int>freq(10,0);
    int ans[n];

    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]++;
    }

    for(int i=1;i<10;i++){
        freq[i] = freq[i-1] + freq[i];
    }

    for(int i=n-1;i>=0;i--){
        int ansIdx= --freq[(v[i]/pos)%10] ;
        ans[ansIdx]=v[i];
    }

    for(int i=0;i<n;i++){
        v[i] = ans[i];
    }

}


void Radix(vector <int> &v,int n){
    int max_ele = v[0];
    for(int i=0;i<n;i++){
        max_ele = max(max_ele,v[i]);
    }

    for(int pos=1;(max_ele/pos)>0;pos*=10){
        Count(v,n,pos);
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

    Radix(v,n);

    cout<<"Sorted Array:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}


// int main(){
//     cout<<832/1000;
// }
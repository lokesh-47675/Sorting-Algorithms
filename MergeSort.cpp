#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


void Merge(vector<int> &v,int l ,int mid, int r){
    int an = mid-l+1;
    int bn = r - mid;

    int a[an],b[bn];

    for(int i=0;i<an;i++){
        a[i]=v[l+i];
    }

    for(int j=0;j<bn;j++){
        b[j]=v[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<an && j<bn){
        if(a[i] < b[j]){
            v[k++] = a[i++];
        }
        else{
            v[k++] = b[j++];
        }
    }
    while(i < an){
        v[k++] = a[i++];
    }
    while(j < bn){
        v[k++] = b[j++];
    }
}

void MergeSort(vector<int> &v,int l,int r){
    int mid = floor((l+r)/2);
    if(l>=r){
        return ;
    }

    MergeSort(v,l,mid);
    MergeSort(v,mid+1,r);
    Merge(v,l,mid,r);
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

    int l = 0;
    int r = n-1;
    MergeSort(v,l,r);

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}
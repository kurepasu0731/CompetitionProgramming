#include<iostream>
#include <vector>  
#include <string>  
using namespace std;


int main(void){
    long n, l;
    long x[100000],a[100000];
    cin>> n >> l;
    int i,j;
    unsigned long distance;
    for(i=0;i<n;i++){
        cin >> x[i]>>a[i];
    }
    for(i=0;i<n;i++){
        long sum=0;
        for(j=0;j<n;j++){
            distance = labs(x[i]-x[j]);
            if(2*distance > l){
                distance = l-distance;
            }
            sum+=(distance*a[j]);
        }
        cout << sum<< endl;
    }
}
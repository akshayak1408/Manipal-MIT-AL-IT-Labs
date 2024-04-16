#include<iostream>
using namespace std;

int Max,Min;
int a[20];
void maxmin(int i,int j){

int max1,min1,mid;
if(i==j)
{
    Max=Min=a[i];
}
else {
    if(i==j-1){
        if(a[i]<a[j]){
            Max=a[j];
            Min=a[i];
        }
        else{
            Max=a[i];
            Min=a[j];
        }
    }
    else{
        mid=(i+j)/2;
        maxmin(i,mid);
        max1=Max;
        min1=Min;
        maxmin(mid+1,j);
        if(Max<max1)
            Max=max1;
        if(Min>min1)
            Min=min1;
    }
}
}



int main(){

int i,j,n;

cout<<"Enter the size of array";
cin>>n;

cout<<"Enter the array";
for(int i=0;i<n;i++)
cin>>a[i];

Max=a[0];
Min=a[0];

maxmin(0,n-1);

cout<<"The maximum element is: "<<Max<<endl;
cout<<"The minimum element is: "<<Min;



}

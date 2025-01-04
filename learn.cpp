# include <iostream>
#include <math.h>
using namespace std ;



// find the no of occurance in array
// find the peak in mountain 
// PIVOT IN AN ARRAY ;(PRACTICE)


int firstocc(int a[],int n,int key){
    int s=0,e=n-1 ;
    int mid = s + (e-s)/2 ;
    int ans ;
    while(s<=e){
        if(a[mid]==key){
            ans = mid ;
            e= mid -1 ;
        }
        else if(a[mid]>key){
            e = mid -1 ;
        }
        else if(a[mid]<key){
            s= mid+ 1;
        }
        mid = s + (e-s)/2 ;
    }
    return ans ;
}

int lastocc(int a[],int n,int key){
    int s=0,e=n-1 ;
    int mid = s + (e-s)/2 ;
    int ans ;
    while(s<=e){
        if(a[mid]==key){
            ans = mid ;
            s= mid + 1;
        }
        else if(a[mid]>key){
            e = mid -1 ;
        }
        else if(a[mid]<key){
            s= mid+ 1;
        }
        mid = s + (e-s)/2 ;
    }
    return ans ;
}



int main(){
    // int array[7]= {2,5,5,5,5,7,7};
    // int key = 5 ;
    // cout<<"the first occurance of key is "<<firstocc(array,7,7)<<endl;
    // cout<<"the last occurance of key is "<<lastocc(array,7,7)<<endl ;

    int n =4 ;
    int ans=0 ;
    int i =0 ;
    while(n!=0){
        int bit = n&1 ;
        ans =(bit * pow(10,i)) + ans;
        n = n >> 1 ;
        i++ ;
    }
    cout<<ans ;
}



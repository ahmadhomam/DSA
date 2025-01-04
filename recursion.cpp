#include <iostream>
#include <vector>
using namespace std ;

int fabonacci(int n){
    int sum ;
    //base case 
    if(n==1)
    return 0 ;
    if(n==2)
    return 1;
    else{
        return sum = fabonacci(n-1)+fabonacci(n-2) ;
    }

}

void print(int arr[],int s,int e){

    for(int i =s;i<=e;i++){
        cout<<arr[i]<<" " ;

    }
    cout<<endl ;
}

int sum(int *arr,int n ){
    if(n==0){
        return 0 ;
    }
    else if(n==1){
        return arr[0] ;
    }
    else{
        int total =arr[0] + sum(arr+1,n-1) ;
        return total ;
    }
}

bool linearsearch(int *arr,int n ,int element){
    if(n==0){
        return false ;
    }
    if(arr[0] == element)
    return true ;
    else{
        bool ans = linearsearch(arr+1,n-1,element) ;
        return ans ;
    }
}


bool binarysearch(int *arr,int s ,int e,int k){
    print(arr,s,e) ;

    int mid = s + (e-s)/2 ;
    cout<<"the value of mid is : "<<arr[mid]<<endl ;
    if(s>e){
        return false ;
    }
    if(arr[mid] == k){
        return true ;
    }
    if(arr[mid]< k){
       return binarysearch(arr,mid+1,e,k) ;
    }
    if(arr[mid]> k){
       return binarysearch(arr,s,mid-1,k) ;
    }
}



bool Bsearch(int *arr,int s ,int e,int k){
    int mid = s + (e-s)/2 ;
    //base case 
    if(s>=e)
    return false ;
    if(arr[mid]== k){
        return true ;
    }
    else if(arr[mid]<k){
        return Bsearch(arr,mid+1,e,k) ;
    }
    else if(arr[mid]>k){
        return Bsearch(arr,s,mid-1,k) ;
    }
}

int Peak(int *arr,int s,int e){
    int mid = s + (e-s)/2 ;
    print(arr,s,e) ;
    cout<<"the value of mid is : "<<arr[mid]<<endl ;
    //base case
    if((arr[mid]>arr[mid+1] || mid+1>e) && arr[mid]>arr[mid-1]){
        return mid ;
    }
    else if(arr[mid]>arr[mid+1]){
        return Peak(arr,s,mid) ;
    }
    else if(arr[mid]<arr[mid+1]){
        return Peak(arr,mid+1,e) ;
    }

}

string rev(string s,int n){
    //base case 
    if(n==1){
        cout<<s[0]<<endl ;
    }
    else{
        cout<<s[n-1]<<" " ;
        return rev(s,n-1) ;
    }
}

// void rever(string &s,int i ,int j){
//     //base case
//     if(i>j){
//         return ;
//     }
//         swap(s[i],s[j]) ;
//         i++ ;
//         j-- ;
//         rever(s,i,j) ;
    
// }

// int power(int a,int b){
//     //base case ;
//     if(b==0)
//     return 1 ;
//     else if(b==1)
//     return a ;

//     //recursive call 
//     else{
//         return a*(power(a,b-1)) ;
//     }

// }

int power(int a , int b){
    if(b==0)
    return 1 ;
    else if(b==1)
    return a ;
    
    int ans = power(a,b/2) ;

    if(b%2 == 0){
        return ans*ans ;
    }
    else{
        return a*ans*ans ;
    }
}
// SORTING USING RECURSION ;
void bubblesort(int *arr,int n ){
    //base case 
    if(n==0 || n==1)
    return ;

    else{
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]) ;
            }
        }
        return bubblesort(arr,n-1) ;
    }
}


void selectionsort(int *arr,int n){
    //base case 
    if(n==1 || n==0)
    return ;

    else{
            int minindex = 0 ;
        for(int i =0;i<n-1;i++){

            if(arr[minindex] > arr[i+1]){
                minindex = i+1 ;
            }
        }
        swap(arr[minindex],arr[0]) ;
        return selectionsort(arr+1,n-1) ;
    }
}

void secsort(int a[],int s, int e){
    if(s>=e)
    return ;

        int minindex = s ;
    for(int i =s+1;i<=e;i++){
        if(a[minindex]>a[i]){
            minindex = i ;
        }
    }
    swap(a[s],a[minindex]) ;
    return secsort(a,s+1,e) ;
}

// MERGE SORT USING RECURSION ;
int merge(int *arr,int s ,int e){
    int mid = s+ (e-s)/2; 

    int len1 = mid-s + 1;
    int len2 = e- mid ;

    int *first = new int[len1] ;
    int *second = new int[len2] ;

    int mainindex = s ;
    for(int i =0;i<len1;i++){
        first[i] = arr[mainindex++] ;
    }
    for(int i =0;i<len2;i++){
        second[i] = arr[mainindex++] ;
    }

    //merge two sorted array ;
    mainindex = s;
    int index1 = 0; 
    int index2 = 0 ;

    while(index1 <len1 && index2 <len2 ){
        if(first[index1]<second[index2]){
            arr[mainindex++]= first[index1++] ;
        }
        else {
            arr[mainindex++] = second[index2++] ;
        }
    }
    while(index1<len1){
        arr[mainindex++]= first[index1++] ; 
    }
    while(index2 <len2){
        arr[mainindex++] = second[index2++] ;
    }
}

void mergesort(int *arr,int s,int e){
    //base case 
    if(s>=e){
        return ;
    }
    int mid = s + (e-s)/2 ;

    // sort left part
    mergesort(arr,s,mid) ;

    //sort right part 
    mergesort(arr,mid+ 1,e) ;

    merge(arr,s,e) ;
}

int partition(int *arr,int s,int e){
    int pivot = arr[s] ;
    int cnt = 0 ;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt ++ ;
        }
    }
    int pivotindex = s+ cnt ;
    swap(arr[s],arr[pivotindex]) ;

    // left aur right wale ko sambhal lenge ;
    int i =s,j=e ;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot){
            i++ ;
        }
        while(arr[j]>=pivot){
            j-- ;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]) ;
        }
    }
    return pivotindex ;
}

void quicksort(int *arr,int s ,int e){
    if(s>=e)
    return ;

    //partition find karenge ;
    int p = partition(arr,s,e) ;

    //left wala
    quicksort(arr,s,p-1) ;

    //right wala
    quicksort(arr,p+1,e) ;
}
 
// SUBSET AND SUBSEQUENCE OF ARRAY  ;
void subset(vector<int> input,vector<int>output,vector<vector<int>> &ans,int index){
    // base case
    if(index >=input.size()){
        ans.push_back(output) ;
        return ;
    }

    //exclude(recursive call) ;
    subset(input,output,ans,index+1) ;

    //include(recursive call) ;
    int element = input[index] ;
    output.push_back(element) ;
    subset(input,output,ans,index+1) ;
    
}
// int main(){
//     int a[7] = {5,3,6,8,1,1,2} ;
//     selectionsort(a,7) ;
//     for(int i =0;i<7;i++){
//         cout<<a[i]<<" " ;
//     }
//     cout<<endl ;
// }




int main(){
    // int arr[6] = {4,6,7,33,850,333} ;
    // if(Bsearch(arr,0,5,333)){
    //     cout<<"the element is found "<<endl ;
    // }
    // else{
    //     cout<<"the element is not found"<<endl ;
    // }
    // cout<<"the peak of array is at index : "<<Peak(arr,0,5)<<endl ;

    // string name = "Homam" ;
    // rev(name,5) ;

    // int a,b ;
    // cin>>a>>b ;
    
    // cout<<power(a,b)<<endl ;
    vector<int> input = {55,3,6,2,11,15,1} ;
    vector<int> output ;
    vector<vector<int>> ans ;
    int index = 0 ;
    subset(input,output,ans,index) ;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" " ;
    }
}

#include <iostream>
using namespace std ;
#include <climits>
#include <algorithm>
#include <stdio.h>

//   // sum of n numbers ;
//  int n ;
//  cin>>n ;
//  int sum= 0 ;
//  for (int i=1;i<=n;i++){
//   sum= sum+i ;

//  }
//  cout<<sum <<endl ;

// int n ;
// cin>>n ;
// int a=0,b=1;
// int sum ;
// cout<<a<<" "<<b<<" " ;
// for(int i=1;i<=n ;i++){
//   sum =a+ b;
//   a= b;
//   b=sum ;
//   cout<<sum<<" " ;
// }


// converting decimal to binary


// int n;
// cin>>n ;
// int i= 0 ;
// float ans= 0 ;
// while(n!=0){
//   int bit = n&1 ;
//   ans = (bit*pow(10,i)) + ans ;
//   n=n>>1 ;
//   i++ ;

// }
// cout<<"the binary of the number is "<<ans<<endl;


// converting binary into decimal

// int n; 
// cin>>n; 
// int ans= 0 , i= 0;
// while(n!=0){
//   int digit = n%10;
//   ans = digit*pow(2,i) + ans ;
//   n= n/10 ;
//   i++ ;
  
// }
// cout<<"the decimal number of the given binary is "<<ans<<endl ;


// switch case 
// int num ;
// cin>>num ;
// int n= 23;
// switch (num){
//     case 1 : cout<<"you enter a number"<<num<<endl ;
//     case 2 : {if(n>10){
//         cout<<"the value of n is greater than 10"<<endl ;
//     }
//         cout<<"the value you enter is"<<num<<endl ;
//     }
// }

// int factorial (int n) {
//     int ans = 1 ;
//     for(int i= 1 ;i<=n; i++){
//         ans= ans* i ;

//     }
//     return ans ;
// }


// int nCr (int n,int r){
//     int num = factorial(n) ;
//     int deno = factorial(r)*factorial(n-r) ;

//     int answer = num/deno ;

//     return answer ;
// }

// bool isprime(int n){
//     for(int i= 2;i<n;i++){
//         if(n%i==0){
//             return 0 ;
//         }
//     }
//     return 1 ;

// }
// int main(){
//     int n ;
//     cout<<"enter a number : "<<endl ;
//     cin>>n ;
//     if(isprime(n)){
//         cout<<"this is a prime no."<<endl ;
//     }
//     else
//     cout<<"this is not a prime no."<<endl ;

// }

// int main(){
//     int dost[] = {34,54,56,76,66} ;
//     getmax(dost,5) ;
//     getmin(dost,5) ;

// }

// int sum(int a , int b){
//     a = 20 ;  
//     int add = a+ b; 
//     cout<<"the value of a+b inside the function is "<<add<< endl ;

// }

// int main(){
//     int a= 5,b= 6;
//     sum(a,b);

//     int summation = a+ b ;
//     cout<<"the value of a+b in main function is "<<summation<<endl ;

// }


// int main(){
//     int array[50] ;
//     cout<<"enter the size of array"<<endl ;
//     int n ;
//     cin>>n ;
//     cout<<"enter the values of array"<<endl ;
//     for(int i= 0;i<n;i++){
//         cin>>array[i] ;
//     }
//     cout<<sumarr(array,n)<<endl ;
// }

// int main(){
//     int arr[6] = {5,6,9,1,7,3} ;
//     //reversing the array ;
//     int start = 0 ;
//     int end = 5 ;
//     while(end>=start){
//         swap(arr[start],arr[end]) ;
//         start++ ;
//         end-- ;
//     }
//     for(int i= 0 ;i<6;i++){
//         cout<<arr[i]<<" "<<endl ;
//     }

// }

// int altrev(int arr[],int size){
//     int start = 0 ;
//     while(start<size-1){
//         swap(arr[start],arr[start+1]) ;
//         start = start +2 ;
//     }
// }
// int main(){
//     int array[5]= {66,55,88,77,99};
//     altrev(array,5) ;

//     for(int i=0;i<5;i++){
//         cout<<array[i]<<" " ;
//     }
// }

//finding unique element 
// int uni(int arr[],int size){
//     int ans = 0 ;
//     for(int i= 0;i<size;i++){
//         ans = ans^arr[i] ;
//     }
//     return ans ;
// }
// int main(){
//     int array[6] = {3,8,3,6,6,3};
//     cout<<uni(array,6)<<endl ;
// }


// WITHOUT USING TWO POINTERS :

// // intersection of arrays 
// int intsec(int arr[],int array[],int n,int m){
//     int ans;
//     for (int i=0;i<n;i++){
//         for (int j=0;j<m;j++){
//             if (arr[i]==array[j]){
//                 ans = array[j];
//                 cout<<ans<<endl ;
//                 array[j]= INT_MIN ;
//                 break ;
//             }
//         }
//     }
//     return ans ;
// }

// int main(){
//     int dost[5]= {3,2,3,6,4} ;
//     int money[4]= {3,4,3,5};
//     intsec(dost,money,5,4);
// }


// USING TWO POINTERS :

// int intersection(int a[],int b[],int n,int m){
//     int i =0 ;
//     int j=0 ;
//     while(i<n &&j<m){
//         if(a[i]==b[j]){
//             cout<<a[i]<<" " ;
//             i++ ;
//             j++ ;
//         }
//         else if(a[i]>b[j]){
//             j++ ;
//         }
//         else if(a[i]<b[j]){
//             i++ ;
//         }
//     }
// }

// int main(){
//     int a[] = {1,3,4,6,6,9} ;
//     int b[] = {2,3,6} ;
//     intersection(a,b,6,3) ;
// }

// array = {1,0,0,1,0,1,1}
// sort the array keeping zeros at side and 1's another side.
// we use two pointer approach ;

// int sort(int a[],int n){
//     int start =0 ;
//     int end = n-1 ;
//     while(start<end){
//         if(a[start]==0 && a[end]==1){
//             swap(a[start],a[end]) ;
//             start++ ;
//             end-- ;
//         }
//         else if(a[start]==1){
//             start++ ;
//         }
//         else if(a[end]==0){
//             end-- ;
//         }
//     }
// }

// int main(){
//     int array[8] = {1,1,0,0,0,0,1,0} ;
//     sort(array,8) ;
//     printarray(array,8) ;
// }

// int sort(int a[],int n){
//     int i= 0 ,j=0 ;
//     int b = n-1 ;
//     while(i<n){
//         if(a[i]==0){
//             swap(a[i],a[j]) ;
//             i++;
//             j++ ;
//         }
//         else if(a[i]==1){
//             i++ ;
//         }
//         else {
//             swap(a[i],a[b]) ;
//             b-- ;
//         }
//     }
// }

// int main(){
//     int array[9] = {0,2,2,1,0,1,1,0,2} ;
//     sort(array,9) ;
//     printarray(array,9) ;
// }

// BINARY SEARCH 
//ONLY WORKS FOR MONOTONOUS FUNCTION(INC/DEC ORDER)
// int binary(int arr[],int size,int key){
//     int start = 0 ;
//     int end = size -1 ;
//     int mid = (start+ end)/2 ;
//     while(start <=end){
//         if(key ==arr[mid]){
//             return mid ;
//         }
//         else if(key <arr[mid]){
//             end = mid -1 ;
//         }
//         else
//         start = mid + 1;

//        // mid = (start + end)/2 ;
//        mid = start + (end- start)/2 ;
//     }
// }

// int main(){
//     int a[7] = {2,6,9,13,17,18,22} ;
//     int key = 13 ;
//     cout<<"the index of searched key is "<<binary(a,7,key)<<endl ;
// }


int max(int a[],int size){
    int ans ;
    int start =0,end = size-1 ;
    int mid = start + (end-start)/2 ;
    while(start<=end){
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            return mid ;
        }
        else if(a[mid]<a[mid+1]){
            start = mid + 1 ;
        }
        else if (a[mid]>a[mid+ 1]){
            end= mid -1 ;
        }
        mid = start + (end-start)/2 ;
    }
}




// 2 APPROACH OF FINDING IN ROTATED SORTED ARRAY :



// int binary(int arr[],int size,int key,int start,int end){
//     start = 0 ;
//     int mid = (start + (end-start)/2 );
//     while(start<=end){
//         if(arr[mid]==key){
//             return mid ;
//         }
//         else if(arr[mid]>key){
//             end = mid -1 ;
//         }
//         else{
//             start = mid + 1 ;
//         }
//         mid = (start + (end-start)/2 );
//     }
//     return mid ;
// }



// int getpivot(int a[],int size){
//     int s = 0 ;
//     int e = size -1 ;
//     int mid = s + (e-s)/2 ;
//     while(s<e){
//         if(a[mid]>=a[0]){
//             s = mid + 1 ;
//         }
//         else{
//             e  = mid ;
//         }
//         mid = s + (e-s)/2 ;
//     }
//     return mid ;
// }

// int main (){
//     int array[7] = {13,17,21,2,3,5,6} ;
//     int key = 3 ;
//     int pivot = getpivot(array,7) ;
//     cout<<pivot<<endl ;

//     if(key <= array[pivot-1] && key >= array[0]){
//         cout<<binary(array,7,key,0,pivot-1)<<endl  ;
//     }
//     else if(key>= array[pivot] && key <=array[6]){
//         cout<<binary(array,7,key,pivot,7)<<endl  ;
//     }
// }

// int search(int a[],int size,int key){
//     int s = 0 ,e = size -1 ;
//     int mid = s+ (e-s)/2 ;
//     while(s<= e){
//         if(a[mid]==key){
//             return mid ;
//         }

//         else if(a[mid] > a[0]){
//             // we are in 1st parat ;
//             if(a[0]<= key && key<= a[mid]){
//                 e = mid -1 ;
//             }
//             else{
//                 s = mid + 1;
//             }
//         }
        
//         else if(a[mid] < a[0]){
//             //2nd part me hai ;
//             if(a[mid]<= key && key <= a[e]){
//                 s= mid + 1;
//             }
//             else{
//                 e = mid -1  ;
//             }
//         }
//         mid = s+ (e-s)/2 ;
//     }
// }

// int main() {
//     int array[7] = {4,5,6,7,0,1,2}; 
//     int key = 2 ;
//     cout<<" the index is "<<search(array,7,key)<<endl ;
// }

//SQUARE ROOT WITH PRICISION ;

// int sqrt(int n){
//     int start = 0 ;
//     int end = n ;
//     int mid = start + (end - start)/2 ;
//     long long int ans ;
//     while(start<=end){
//     long long int factor = mid * mid ;
//         if(factor <= n){
//             ans = mid ;
//             start = mid + 1;
//         }
//         else{
//             end = mid -1;
//         }

//         mid = start + (end - start)/2 ;

//     }
//     return ans ;
// }

// double moreprecision(int n,int order){
//     double factor =1;
//     double ans = sqrt(n) ;
//     for(int i=0 ;i<order;i++){
//         factor = factor/10 ;
//         // while(ans*ans<=n){                   
//         //    ans= ans + factor ; 
//         //   }
//         // ans = ans - factor ;                     (IMPORTANT)
//         for(double j= ans;j*j<=n;j=j+factor){
//             ans = j ;
//         }
//         ans = ans - factor ;
//     }
//     return ans ;
// }

// int main(){
//     cout<<"enter a number"<<endl ;
//     int n ;
//     cin>>n;
//     cout<<"the sqrt of n is in integer "<<sqrt(n)<<endl ;
//     cout<<"the precise value of sqrt is "<<moreprecision(n,3)<<endl ;
// }

//BOOK ALLOCATION PROBLEM :

// bool ispossible(int a[],int n, int m,int mid){
//     int studentcount = 1 ;
//     int pagesum = 0 ;
//     for(int i = 0;i<n ;i++){
//         if(pagesum + a[i] <= mid){
//             pagesum += a[i] ;
//         }
//         else{
//             studentcount++ ;
//             if(studentcount<= m && a[i]<= mid){
//                 pagesum = a[i] ;
//             }
//             else {
//                 return false ;
//             }
//         }
//     }
//     return true ;
// }

// int allocate(int a[],int n,int m,int mid){         // m is number of people/students ;
//     int s = 0,sum = 0 ;

//     for(int i =0;i<n;i++){
//         sum = sum + a[i] ;
//     }
//     int e = sum ;
//     mid = s + (e-s)/2 ;
//     int ans ;
//     while(s<=e){
//         if(ispossible(a,n,m,mid)){
//             ans = mid ;
//             e = mid -1 ;
//         }
//         else{
//             s= mid + 1;
//         }
//         mid = s + (e-s)/2 ;
//     }
//     return ans ;
// }

// int main (){
//     int a[4] = {10,20,30,40} ;
//     cout<<"the book allocation of this array is "<<allocate(a,4,2,2)<<" among two students"<<endl ;
// }

// PAINTORS PARTITION PROBLEM : - 

// bool ispossible(int a[],int n,int k,int mid){
//     int paintercount = 1;
//     int boardcount = 0 ;
//     for(int i = 0;i<n;i++){
//         if(boardcount + a[i] <= mid){
//             boardcount += a[i] ;
//         }
//         else{
//             paintercount++ ;
//             if(paintercount <=k && a[i]<=mid){
//                 boardcount = a[i] ; 
//             }
//             else{
//                 return false ; 
//             }
//         }
//     }
//     return true ; 
// }

// int partition(int a[],int n ,int k,int mid){
//     int s =0 ;
//     int sum = -1 ;
//     for(int i=0;i<n;i++){
//         sum = sum + a[i] ;
//     }
//     int e = sum ;
//     mid = s + (e-s)/2 ;
//     int ans ;
//     while(s<= e){
//         if(ispossible(a,n,k,mid)){
//             ans = mid ;
//             e = mid -1 ;
//         }
//         else{
//             s= mid + 1;
//         }
//         mid = s + (e-s)/2 ;
//     }
//     return ans ;
// }

// int main(){
//     int arr[4] = {7,11,13,19} ;
//     cout<<"the painter partition of the given array is  "<<partition(arr,4,2,2)<<endl ;
// }

//AGGRESIVE COW PROBLEM : - 

// bool ispossible(int a[],int n,int k,int mid){
//     int cowcount = 1 ;
//     int lastp = a[0] ;
//     for(int i = 0;i<n;i++){
//         if(a[i]- lastp >= mid ){
//             cowcount ++ ;
//             if(cowcount == k){
//                 true ;
//             }
//             lastp = a[i] ;
//         }
//     }
//     return false ;
// }

// int aggcow(int a[],int n,int k,int mid){
//     int s = 0 ;
//     int maxi =0;
//     sort(a.begin(),a.end()) ;
//     for(int i = 0 ;i<n;i++){
//         maxi = max(maxi,a[i]) ;
//     }
//     int e = maxi ;
//     mid = s + (e-s)/2 ;
//     int ans = 0 ;
//     while(s<=e){
//         if(ispossible(a,n,k,mid)){
//             s= mid + 1;
//             ans = mid ;
//         }
//         else{
//             e = mid -1 ;
//         }
//         mid = s + (e-s)/2 ;
//     }
//     return ans ;
// }

//  CHOP M METERS OF WOOD 

bool ispossible(int a[],int n,int k,int mid){
    int totallen = 0 ;
    for(int i =0;i<n;i++){
        int rempart = a[i]- mid ;
        if(rempart>=0){
            if(totallen + rempart <= k){
                totallen += rempart ;
            }
            else{
                return false ;
            }
        }
        else{
            continue;
        }
        
    }
    return true ;
}

int cut(int a[],int n,int k){  //k is total length of wood required ;
int s = 0 ;
int maxi = -1 ;
for(int i=0;i<n;i++){
    maxi = max(maxi,a[i]) ;
    }
int e = maxi ;
int mid = s + (e-s)/2 ; 
int ans ;
while(s<=e){
    if(ispossible(a,n,k,mid)){
        ans = mid ;
        e = mid - 1 ;
    }
    else{
        s = mid +1  ;
    }
    mid = s + (e-s)/2 ;
    }
    return ans ;
}

// int main(){
//     int len[4] = {20,15,10,17} ;
//     cout<<cut(len,4,5)<<endl ;
// }

// // SELECTION SORT : - 

// int selectionsort (int a[],int n){
//     for(int i= 0;i<n-1;i++){ 
//         int minindex = i ;
//         for(int j= i+1;j<n;j++){
//             if(a[minindex] > a[j]){
//                 minindex = j ;
//             }
//         }
//         swap(a[i],a[minindex]) ;
//     }
// }


// // BUBBLE SORT :
// int bubblesort(int a[],int n){
//     //round wise
//     // from round 1 to n-1 ;
//     for(int i=1;i<n;i++){
//         int swapped = -1 ;
//         for(int j=0;j<n-i;j++){
//             if(a[j]>a[j+1]){
//                 swap(a[j],a[j+1]) ;
//                 swapped = 1 ;
//             }
//         }
//         if(swapped== -1){
//             break ;
//         }
//     }
// }

int insertionsort(int a[],int n ){
    for(int i=1;i<n ;i++){
        int temp = a[i] ;
        int j=i-1 ;
        for(;j>=0;j--){
            if(a[j]>temp){
                a[j+1] = a[j] ;
            }
            else
            break ;
        }
        a[j+1] =  temp ;
    }
}

// int insertionsort(int a[],int n){
//     // assume that a[0] is sorted therefore start from i=1 ;
//     for(int i=1;i<n;i++){
//         int temp = a[i] ;
//         int j= i-1 ;
//         while(j>=0){
//             if(a[j]>temp){
//                 a[j+1] = a[j] ;
//             }
//             else{
//                 break ;
//             }
//             j-- ;
//         }
//         a[j+1] = temp ;
//     }
// }


// int main (){
//     int a[7] = {10,1,7,4,8,2,11} ;
//     insertionsort(a,7) ;
//     cout<<"the sorted array through insertion sort is "<<endl ;
//     for(int i=0;i<7;i++){
//         cout<<a[i]<<" " ;
//     }
//     cout<<endl ;
//     bubblesort(a,7) ;
//     cout<<"the sorted array through bubble sort is "<<endl ;
//     for(int i=0;i<7;i++){
//         cout<<a[i]<<" " ;
//     }
// }

int getlength(char a[]){
    int count = 0 ;
    for(int i=0;a[i] != '\0';i++){
        count ++ ;
    }
    return count ;
}

int reverse(char a[],int n){
    int s= 0;
    int e = n-1 ;
    while(s<=e){
        swap(a[s],a[e]) ;
        s++ ;
        e-- ;
    }
}
// char lowercase(char a){
//     if (a >= 'A' && a<= 'Z'){
//         char temp = a - 'A' + 'a' ;
//         return temp ;
//     }
//     else
//     return a ;
// }

// bool palindrome(char a[],int n){
//     int s = 0 ;
//     int e = n-1 ;
//     while(s<=e){
//         if((a[s]) != (a[e])){
//             return false ;
//         }
//         s++ ;
//         e-- ;
//     }
//     return true ;
// }



bool validch(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ||(ch>='0' && ch<='9')){
        return true ;
    }
    return false ;
}

char lowercase(char a){
    if (a >= 'A' && a<= 'Z'){
        char temp = a - 'A' + 'a' ;
        return temp ;
    }
    else
    return a ;
}

bool palindrome(string st){
    int s = 0 ;
    int e = st.length()-1 ;
    while(s<=e){
        if((st[s]) != (st[e])){
            return false ;
        }
        s++ ;
        e-- ;
    }
    return true ;
}

bool ispalindrome(string s){
    string temp  = "" ;
    // faltu numbers ko hta do.
    for(int i =0;i<s.length();i++){
        if(validch(s[i])){
            temp.push_back(s[i]) ;
        }
    }
    // sabko lowercase me convert kardo ;
    for(int i =0;i<temp.length();i++){
        temp[i] = lowercase(temp[i]) ;
    }
    return palindrome(temp) ;
}



// int main(){
//     // char name[26] ;
//     // cout<<"enter your name :"<<endl ;
//     // cin>>name ;
//     // cout<<"your name is "<<name<<endl ;

//     // int len = getlength(name) ;
//     // cout<<"length is :"<<len<<endl ;

//     // reverse(name,len); 
//     // cout<<"reverse is :"<<name <<endl ;

//     // cout<<"Palindrome or not :"<<palindrome(name,len)<<endl ;
//     string str = "homam" ;
//     str.push_back('L') ;
//     cout<<str<<endl ;
//     str.pop_back() ;
//     cout<<str<<endl ;

//     string s = "race a car"    ;
//     cout<<"This is a palindrome : "<<ispalindrome(s)<<endl ;
// }

char maxocc(string s){
    int arr[26] = {0} ;
    int number ;
    // count of char at their positions  ;
    for(int i =0;i<s.length();i++){
        if(s[i]>= 'a' && s[i]<= 'z'){
            number = s[i] - 'a' ;
        }
        else if(s[i] >= 'A' && s[i]<= 'Z'){
            number = s[i] - 'A' ;
        }
        arr[number] ++ ; 
    }
    // max occurance ;
    int maxi = -1 ;
    int ans ;
    for(int i =0;i<26;i++){
        if(arr[i]> maxi){
            ans = i ;
            maxi = arr[i] ;
        }
    }
    char finalans = ans + 'a' ;
    return finalans ;
}

// int main(){
//     string s ;
//     cout<<"enter the string :"<<endl ;
//     cin >> s ;
//     cout<<maxocc(s)<<endl ;
// }

string replace(string s){
    string temp = "" ;
    for(int i =0;i<s.length();i++){
        if(s[i] == ' '){
            temp.push_back('@') ;
            temp.push_back('4') ;
            temp.push_back('0') ;
        }
        else{
            temp.push_back(s[i]) ;
        }
    }
    return temp ;
} 

int rowsum(int a[][4],int row ,int col){
    for(int i =0;i<row;i++){
            int sum =0 ;

        for(int j=0;j<col;j++){
            sum = sum + a[i][j] ;
        }
        cout<<"the sum of "<<i+1<<" row is "<<sum <<endl ;
    }
}
int max(int a[][4],int row,int col){
    int maxi = -1 ;
    int index ;
    for(int i =0;i<row;i++){
            int sum =0 ;

        for(int j=0;j<col;j++){
            sum = sum + a[i][j] ;
        }
        cout<<"the sum of "<<i+1<<" row is "<<sum <<endl ;

        if(maxi<sum){
            maxi = sum ;
            index = i ;
        }
    }
    cout<<"the maximu row sum is "<<maxi <<endl ;
    cout<<"And the index of the row is "<<index <<endl ;
}

int wave(int a[][4],int row ,int col){
    for(int i=0;i<col;i++){
        if(i&1){
            for(int j = row -1;j >=0;j--){
                cout<<a[j][i]<<" " ;
            }
        }
        else{
            for(int j=0;j<row;j++){
                cout<<a[j][i]<<" " ;
            }
        }
    }
    cout<<endl ;
}

// int main(){
//     int arr[3][4] = {4,6,3,7,9,8,201,22,77,94,14,2} ;
//     for(int i =0;i<3;i++){
//         for(int j =0;j<4;j++){
//             cout<<arr[i][j]<<" " ;
//         }
//         cout<<endl ;
//     }

//     // cout<<"enter the element to check "<<endl ;
//     // int target ;
//     // cin>>target ;
//     // if(find(arr,target,3,4)){
//     //     cout<<"the element is present "<<endl ;
//     // }
//     // else
//     // cout<<"the element is not present "<<endl ;

//     //rowsum(arr,3,4) ;
//     max(arr,3,4) ;
//     wave(arr,3,4) ;
// }

int gcd(int a ,int b){

    while(a!=b){
        if(a>b){
            a= a-b ;
        }
        else if(b>a){
            b = b-a ;
        }
    }
    return a ;
}

// int main(){
//     int a,b ;
//     cout<<"enter the two numbers : "<<endl ;
//     cin>>a>>b ;
//     cout<<"the greatest commont divisor is "<<gcd(a,b)<<endl ;
// }

// POINTERS :- STORES ADDRESS OF SOME DATA 

int getsum(int arr[],int n){

    int sum =0 ;
    for(int i =0;i<n;i++){
        sum += arr[i] ;
    }
return sum ;
}

// int update(int **p){
//     **p = **p+ 1 ;
// }
int update(int &n){
    n++ ;
}
int sum(int arr[],int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i] ;
    }
    return sum ;
}

int main(){
    
/*  int arr[10] = {0,3,2,6} ;
    int *pt = &arr[0];
    cout<<arr<<endl ;
    cout<<*pt<<endl ;
    cout<<pt<<endl ;
    cout<<&pt<<endl ;
    int temp[10] = {3,4,6};
    cout<<*temp<<endl;
    cout<<*(temp+ 2)<<endl ;
    cout<<endl ;
    cout<<endl ;

    
    char ch[7] = "abcdeg" ;
    cout<<ch<<endl ;
    char *c = &ch[0] ;
    cout<<c<<endl ;
    cout<<*c<<endl ;
    cout<<&ch[0]<<endl ;
    cout<<endl ;
    
    char t = 'm' ;
    char *b = &t ;
    cout<<b<<endl ;
    cout<<*b<<endl ;  
    cout<<t<<endl ;
    cout<<&t<<endl ;
    cout<<endl ;
    

    int a = 10 ;
    int *p = &a ;
    int** p2 = &p ;
    cout<<"1st : "<<a <<endl ;
    cout<<"2nd : "<<p<<endl ;
    cout<<"3rd : "<<p2<<endl ;
    cout<<endl ;
    cout<<"updated"<<endl ;

    update(p2) ;
    cout<<"1st : "<<a <<endl ;
    cout<<"2nd : "<<p<<endl ;
    cout<<"3rd : "<<p2<<endl ;
    

   // MAKING ARRAY AT RUNTIME (WHICH IS A BAD PRACTICE FIRST) USING POINTERS AND DYNAMIC MEMORY
   int i =5 ;
   int &j = i ;

   int *arr = new int[5] ;

   int n ;
   cin>>n;
   for(int i =0;i<n;i++){
    cin>>arr[i] ;
   }
   cout<<"sum "<<sum(arr,5)<<endl ;
    

   //creating 2d array dynamically ;
   int row ,col ;
   cin>>row>>col ;
   int **arr = new int*[row] ;
   for(int i=0;i<row;i++){
    arr[i] = new int[col] ;
   }

   for(int i =0;i<row;i++){
    for(int j =0;j<col;j++){
        cin>>arr[i][j] ;
    }
   }

   for(int i =0;i<row;i++){
    for(int j =0;j<col;j++){
        cout<<arr[i][j]<<" " ;
    }
    cout<<endl ;
   }
   */
//   const int name = 5 ;
//   cout<<name<<endl ;
//   //name++ ; CANNOT BE MODIFIED ;

//   int a[6] = {4,99,6,7,1,3} ;
//   for(int i=0;i<6;i++){
//     cout<<a[i]<<" " ;
//   }
//   cout<<endl; 
int arr[5] = {5,4,3,2,1} ;
insertionsort(arr,5) ;
for(int i =0;i<5;i++){
    cout<<arr[i]<<" " ;
}
}
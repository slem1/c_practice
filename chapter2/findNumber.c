#include<stdio.h>


int find (int, int[], int);


int main(){

    int v[] = {15,18, 45,48,64};

    int r ;    

    for (int i = 0; i< 5; i++){
        r= findOneTest(v[i], v, 5);
        printf("(%d)r=%d\n",v[i],r);
    }

}

int find (int x, int v[], int n){

    int mid=0;
    int hi = n - 1;
    int lo = 0;

    while(hi >= lo){
        mid = (hi + lo) /2;

        if( x == v[mid]){
            return mid;
        } else if(x < v[mid]){
            hi = mid - 1;
        } else if( x > v[mid]){
            lo = mid + 1;
        }     
    }

    return -1;
}

int findOneTest (int x, int v[], int n){

    int mid=0;
    int hi = n - 1;
    int lo = 0;

    while(hi >= lo && x != v[mid]){
        mid = (hi + lo) /2;        
        if(x < v[mid]){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }     
    }

    if(v[mid] == x){
        return mid;
    }else {
        return -1;
    }

}
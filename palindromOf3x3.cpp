#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int product){
    int temp = product;
    int digit, result = 0;
    while(temp != 0){
        digit = temp%10;
        result = (result * 10) + digit;
        temp = temp/10;
    }
    if(result != product){
        return false;
    }

    return true;
}

int main(){

    
    
    int maxPlaindrome = 0;


    for(int i = 1000; i > 900 && maxPlaindrome == 0; i--){
        for(int j = 1000; j > 900 && maxPlaindrome == 0; j--){
            int product;
            product = j * i;
            
            if(checkPalindrome(product)){
                cout<<"\nj : "<<j;
                cout<<"\ni : "<<i;
                maxPlaindrome = product;
            }
            
        }
    }

    cout<<"\nmaximum of palindrome : "<<maxPlaindrome;
    return 0;
}


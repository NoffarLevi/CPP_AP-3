#pragma once
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int fib_help(int f, int s){
    return (f+s);
}

template <typename T>
bool Fib(T start, T end){

    if(*start <= 0){ return false; }
  
    int ans1 = 1;
    int ans2 = 1;
    int res = 0;
    if(*start == 1){
        start++;
        if(*start != 1 && *start > 2){
            return false;
        }
        start++;
    }

    while (start != end)
    {
        res = fib_help(ans1, ans2);
        ans1 = ans2;
        ans2 = res;
        if(*start != res && *start < res){ return false; }
        if(*start == res){ start++; } 
        
    }
    return true;   
}


template <typename T>
T Transpose(T start, T end){
    
    T beg = start;
    T e = end;
     
    if((end - start) % 2 != 0 || (end - start) == 0){
        return beg;
    }
    while(beg != e){
        iter_swap(beg, beg+1);
	    beg += 2;
    }
    return end;
}

template <typename T, typename P, typename F>
P Transform2(T start, T end, P b2, F func){
    int last = 0;

    if((end - start) % 2 != 0){
        last = 1;    
    }   

    while(start != (end - last)){
        auto res = func(*start, *(start+1));
        *b2 = res;
        ++b2;
        start+=2;
    }
        return b2;
}

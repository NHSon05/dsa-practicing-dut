#include <stdio.h>

bool checkNT(int x){
    if (x == 0 ) 
        return false;
    while (x > 0)
    {
        int d = x % 10;
        if (!(d == 2 || d == 5 || d == 7 || d == 9)) return false;
        x /= 10;
    }
    return true;
}

int tinhTong(int x){
    int s = 0;
    while ( x > 0 ){
        s += x % 10;
        x /= 10;
    }
    return s;
}


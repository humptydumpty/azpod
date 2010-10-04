#include<stdio.h>

int* r() {
    int *a = (int *) malloc(10);
    a[0] = 2;
    return a;
}

int main() {
    int *p = r();
    printf("%d", p[0]);
    return 0;
}
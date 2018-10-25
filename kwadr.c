#include <stdio.h>
#include <stdbool.h>

#define TEST

bool rozwiaz_rownanie_kwadratowe(int a, int b, int c, double *px1, double *px2) {

    return false;

}

#ifdef TEST

void nd(int licznik) { printf("Test nr %i nie działa\n", licznik); }

// tutaj należy umieszczać kolejne testy




void test1_rownanie_kwadratowe(int licznik) {
   double x1;
   double x2;
   //dla 0,0,5 - rozwiazanie nie istnieje - funkcja jest sprzeczna
    if(rozwiaz_rownanie_kwadratowe(0,0,5, &x1, & x2)) nd(licznik);
    

}

void run_test_pool() {
    int licznik = 0;
// tutaj wywołujemy testy
    test1_rownanie_kwadratowe(++licznik);

}

#endif


int main() {

#ifndef TEST
    // uruchom program


#else
    // uruchom testy
    run_test_pool();

#endif

    return 0;
}
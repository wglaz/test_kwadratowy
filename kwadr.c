#include <stdio.h>
#include <stdbool.h>

#define TEST

int rozwiaz_rownanie_kwadratowe(double a, double b, double c, double *px1, double *px2) {

    if(a==0.0 && b==0.0 && c!=0.0) {
        printf("Równie jest tautologia\n");
        return 1;
    }
    if(a==0.0 && b==0.0 && c!=0.0) {
        printf("Równie dla podanych parametrów jest sprzeczne.\n");
        return 2;
    }
    if(a==0.0) {
        printf("Równie jest liniowe\n");
        *px1 = -c/b;
        return 3;
    }
    return 0;
}

#ifdef TEST

void nd(int licznik) { printf("Test nr %i nie działa\n", licznik); }

// tutaj należy umieszczać kolejne testy



void test1_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;
    //dla 0,0,0 - nieskonczenie wiele rozwizan- tautologia jest prawdziwe
    if(rozwiaz_rownanie_kwadratowe(0,0,0, &x1, & x2) !=1) nd(licznik);


}
void test2_rownanie_kwadratowe(int licznik) {
   double x1;
   double x2;
   //dla 0,0,5 - rozwiazanie nie istnieje - funkcja jest sprzeczna
    if(rozwiaz_rownanie_kwadratowe(0,0,5, &x1, & x2) !=2) nd(licznik);
    if(rozwiaz_rownanie_kwadratowe(0,0,-3.4, &x1, & x2) !=2) nd(licznik);

}


void test3_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    if(rozwiaz_rownanie_kwadratowe(0,2.0,5.0, &x1, & x2) !=3) nd(licznik);
    if(x1 !=-5.0/2.0) nd(licznik);

    if(rozwiaz_rownanie_kwadratowe(0,-52.0,6.2, &x1, & x2) !=3) nd(licznik);
    if(x1 !=-6.2/52.3) nd(licznik);
}
//void test4_rownanie_kwadratowe(int licznik) {
//    double x1;
//    double x2;
//
//    if(rozwiaz_rownanie_kwadratowe(0,2.0,5.0, &x1, & x2) !=3) nd(licznik);
//    if(rozwiaz_rownanie_kwadratowe(0,-52.0,6.2, &x1, & x2) !=3) nd(licznik);
//}
void run_test_pool() {
    int licznik = 0;
// tutaj wywołujemy testy
    test2_rownanie_kwadratowe(++licznik);
    test1_rownanie_kwadratowe(++licznik);
    test3_rownanie_kwadratowe(++licznik);
   //test4_rownanie_kwadratowe(++licznik);
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
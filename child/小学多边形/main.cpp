//#include <string.h>
//#include <stdlib.h>
//#include "Polygon.h"
#include "Test.h"
//#include <iostream>
//using namespace std;

int main() {
    Test *test = new Test; // construct a test include choose the counts of the 
    test->Answer();        //answer the test
    test->Goback();        // goback and check the answer
    test->Submit();        // submit and show your scores
    delete test;
    return 0;
}

#include <iostream>
#include <cstdlib>
#include "poly.h"
using namespace std;
int main()
{
cout << "Hello\n";
int arr1[5]={5,2,0,3,8};
int arr2[4]={7,0,4,2};
Poly p1(4,arr1);
Poly p2(3,arr2);
Poly p3 = p2*p1;
cout << p3 << endl;
system("PAUSE");
}
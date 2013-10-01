#include <iostream>
#include <cstdlib>
using namespace std;
class Poly{
private:
	int order;	//order of the polynomial
	int *coeff;	// pointer to array of coeff on the heap
			// size of coeff array predicated on (order + 1)
public:
	Poly( );
	Poly(int Order , int Default = 0) ; 
	Poly(int Order, int *Coeff); //creates an Nth order           //polynomial & inits 
	~Poly( ) {};			// destructor
	Poly(const Poly & rhs);    // copy constructor

//mutators  & accessors
void set( );// Query user for input coefficient values
void set(int Coeff[ ], int size);
int getOrder( )const;  // get order of polynomial
int * get( )const; 	      //returns pointer to coeff array

//overloaded operators
Poly operator+( const Poly &rhs);		// add two polynomials
Poly operator-( const Poly &rhs);		// subt two polynomials
    
Poly operator*( const int scale);		// scale a  polynomial
    
Poly operator*(const Poly &rhs);		// mult two polynomials
bool  operator==(const Poly &rhs);		// equality operator
  
Poly & operator=(const Poly & rhs);            //assignment operator

const int & operator[ ](int I)const;       // return the Ith coefficient
int & operator[ ](int I);                 	// return the Ith coefficient

int operator( )(int X);			// evaluate P(x) according 
  
friend ostream & operator<<(ostream & Out, const Poly &rhs);
friend istream & operator >>(istream & In, Poly &rhs);
};
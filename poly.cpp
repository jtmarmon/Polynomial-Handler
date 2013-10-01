#include "poly.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
//*********CONSTRUCTORS*******************
Poly::Poly():order(0) //default constructor definition. initializes order to zero
{
coeff = new int[order];
coeff[0]=1;
};
Poly::Poly(int Order, int Default /* = 0 */): order(Order) //param. constructor: second paramater is default
{
coeff = new int[Order];
for (int i=0; i<Order; i++)
	coeff[Order]=Default;
};
Poly::Poly(int Order, int *Coeff): order(Order) // param. constructor: pass an array and a 
{
coeff = new int[Order];
coeff=Coeff;
};
Poly::Poly(const Poly & rhs)
{
	order = rhs.getOrder();
    coeff = rhs.get();
};



//*********SET/GET FUNCTIONS*******************
void Poly::set( )// Query user for input coefficient values
{
cout << "Enter the order of the polynomial" << endl;
int Order;
cin >> Order;
this->order=Order;
cout << "Enter each coefficient value in descending order, followed by pressing the enter key (e.g. 5x^3 + 2x + 6 is entered as 5 [enter] 0 [enter] 2 [enter] 6 [enter].  Enter \" Done \" when finished." << endl;
int *Coeff = new int[Order];
for (int i=0; i<Order; i++)
	cin >> Coeff[i];
this->coeff=Coeff;
};
void Poly::set(int Coeff[ ], int size) //DOUBLE CHECK IF THIS IS RIGHT? ALSO NEEDS TO ALLOCATE MEMORY
{
	this->coeff=new int[size];
	this->coeff=Coeff;
	this->order=size;
};
int Poly::getOrder( )const// get order of polynomial
{
return order;
};  
int* Poly::get( )const//returns pointer to coeff array
{
return coeff;
};
//***********OVERLOADED OPERATORS***********************

Poly Poly::operator+(const Poly &rhs)	// add two polynomials
{

	int* thisCoeff = this->coeff; // {5,3,2,6,1}
	int  thisOrder=this->order; //4th order
	int thisSize = thisOrder+1;

	int* rhsCoeff = rhs.get(); // {3,2}
	int  rhsOrder = rhs.getOrder(); // 1st order
	int rhsSize = rhsOrder+1;
	int difference;
		
	int* newArray;
	int newOrder;
	if (thisOrder>rhsOrder)
	{
		newOrder=thisOrder;
		newArray = new int[thisSize];
		difference=thisOrder-rhsOrder;

		for (int i=0; i<thisSize; i++) /* this section is a bit confusing, but basically we calculate the "difference" first to see how many terms in the larger polynomial we have to account for. for example, if one polynomial is of 7th order and another is of 5th order, the first two coefficients aren't added to anything, so we just set those coefficients to the new array.*/
		{
			if (i<thisSize-difference) // (in examle) if less than 4, meaning that
				newArray[i]=(rhsCoeff[i] + thisCoeff[i]);
			else //if we're in the section that only applies to the larger polynomial
				newArray[i]=thisCoeff[i];
		}
	}
	else if (rhsOrder>thisOrder)
	{
		newOrder=rhsOrder;
		newArray = new int[rhsSize];
		difference=rhsOrder-thisOrder;

		for (int i=0; i<rhsSize; i++) 
		{
			if (i<rhsSize-difference) // (in examle) if less than 5, meaning that
			{
				newArray[i]=(rhsCoeff[i] + thisCoeff[i]);
			}
			else //if we're in the section that only applies to the larger polynomial
				newArray[i]=rhsCoeff[i];
		}
	}
	else //thisOrder=rhsOrder
	{	
		newOrder=rhsOrder; //could be "thisOrder" instead; theyre the same value so it doesn't matter
		newArray = new int[rhsSize /*also could be "thisOrder" */];
		//no difference calculated because same order

		for (int i=0; i<rhsSize /*again, could be "thisOrder" instead. doesn't matter. */; i++)
			newArray[i]=(rhsCoeff[i] + thisCoeff[i]);
	}
	return Poly(newOrder, newArray);

};
ostream & operator<<(ostream & Out, const Poly &rhs)
{
	cout << "(";
	int order = rhs.getOrder();
	int *coeff = new int [order+1];
	coeff=rhs.get();

	for (int i=order; i>=0; i--)
	{
		if (coeff[i]!=0) // if coeff[i] is 0 we print nothing for this power of X because 0* anything = 0
		{
			if (i!=0) 
				Out << coeff[i] << "X^" << i; //ONE OF THE TWO HAPPEN FOR SURE - i is either 0 or not zero
			else
				Out << coeff[i];
			if (i!=0 && coeff[i]!=0) // prevent the printing of + after the last coefficient or after a non printed coefficient
				Out << " + ";
		}
	}
	cout << ")";
	return Out;
};
istream & operator >>(istream & In, Poly &rhs)
{
	cout << "Enter the order of the polynomial : ";
	int order;
	cin >> order;
	int* coeff = new int [order+1];
	for (int i=order; i>=0; i--)
		{
			cout << "Enter the coefficient of (X^" << i << "):  ";
			cin >> coeff[i];
		}
	rhs.set(coeff, order);
	
	return In;

};

Poly Poly::operator-(const Poly &rhs)	// subt two polynomials
{
int* thisCoeff = this->coeff; // {5,3,2,6,1}
	int  thisOrder=this->order; //4th order
	int thisSize = thisOrder+1;

	int* rhsCoeff = rhs.get(); // {3,2}
	int  rhsOrder = rhs.getOrder(); // 1st order
	int rhsSize = rhsOrder+1;
	int difference;
		
	int* newArray;
	int newOrder;
	if (thisOrder>rhsOrder)
	{
		newOrder=thisOrder;
		newArray = new int[thisSize];
		difference=thisOrder-rhsOrder;

		for (int i=0; i<thisSize; i++) /* this section is a bit confusing, but basically we calculate the "difference" first to see how many terms in the larger polynomial we have to account for. for example, if one polynomial is of 7th order and another is of 5th order, the first two coefficients aren't added to anything, so we just set those coefficients to the new array.*/
		{
			if (i<thisSize-difference) // (in examle) if less than 4, meaning that
				newArray[i]=(thisCoeff[i]-rhsCoeff[i]);
			else //if we're in the section that only applies to the larger polynomial
				newArray[i]=thisCoeff[i]; 
		}
	}
	else if (rhsOrder>thisOrder)
	{
		newOrder=rhsOrder;
		newArray = new int[rhsSize];
		difference=rhsOrder-thisOrder;

		for (int i=0; i<rhsSize; i++) 
		{
			if (i<rhsSize-difference) // (in examle) if less than 5, meaning that
			{
				newArray[i]=(thisCoeff[i]-rhsCoeff[i]);
			}
			else //if we're in the section that only applies to the larger polynomial
				newArray[i]=-rhsCoeff[i]; //negative because rhs is bigger than lhs
		}
	}
	else //thisOrder=rhsOrder
	{	
		newOrder=rhsOrder; //could be "thisOrder" instead; theyre the same value so it doesn't matter
		newArray = new int[rhsSize /*also could be "thisOrder" */];
		//no difference calculated because same order

		for (int i=0; i<rhsSize /*again, could be "thisOrder" instead. doesn't matter. */; i++)
			newArray[i]=(thisCoeff[i]-rhsCoeff[i]);
	}
	return Poly(newOrder, newArray);

};

Poly Poly::operator*(const int scale)	// scale a  polynomial
{
    int order = this->getOrder();
    int* coeff = new int [order+1];
    int* newCoeff= new int [order+1];
    coeff = this->get();
    for (int i=0; i<order+1; i++)
        newCoeff[i]=(scale*coeff[i]);
    return Poly(order,newCoeff);    
};

Poly Poly::operator*(const Poly &rhs)	// mult two polynomials
{
	int rhsOrder=rhs.getOrder();
	int* rhsCoeff=rhs.get();
	rhsCoeff=new int [rhsOrder+1];

	int thisOrder=this->getOrder();
	int* thisCoeff=this->get();
	thisCoeff= new int[thisOrder+1];

	int* newCoeff;
	int newOrder = thisOrder+rhsOrder; //gives us an order for the quotient polynomial. always will be the sum of the orders of the two polynomials being added.
	Poly* quotients;
	int loopControl=0;
	//main logic/control
	if(rhsOrder>thisOrder)
	{
		newCoeff = new int[rhsOrder+1];//newCoeff array initialized to larger size b/c stfu i'm too tired to explain why this makes sense i'm never going to reread this code again
		quotients = new Poly[thisOrder+1];//initialize quotient array to the size of the smaller order polynomial
		for (int a=0; a<thisOrder; a++) // control loop.  iterates through each term of the small polynomial
		{

			for (int b=0; b<rhsOrder;b++) //inner loop. each iteration multiplies the current term of "this" polynomial by rhsCoeff[i] and stores
				{
                    cout << "loop n shit\n";
					newCoeff[b]=(thisCoeff[loopControl] * rhsCoeff[b]); //stores coefficients in an array
					quotients[a] = Poly((rhsOrder+loopControl), newCoeff);
				} 
			loopControl++;
		}
	}
	else if (thisOrder>rhsOrder)
	{
		quotients = new Poly[rhsOrder+1];
	}
	else
	{
		quotients = new Poly [rhsOrder+1];  // could be either rhsOrder or thisOrder since they are equal at this point in the code
	}
	//end loop. adds up each elements of "quotients" array into a single sum which is then returned
	Poly p_sum;
	for (int i=0; i<thisOrder;i++)
		p_sum = quotients[i]+p_sum;
	return p_sum;
}; 
bool Poly::operator==(const Poly &rhs)	// equality operator
{ 
    int thisOrder = this->getOrder();
    int* thisCoeff = new int [thisOrder+1];
    thisCoeff = this->get();
    
    int rhsOrder = rhs.getOrder();
    int* rhsCoeff = new int [rhsOrder+1];
    rhsCoeff = rhs.get();
    
    if (thisOrder!=rhsOrder)
        return false;
    for (int i=0; i<thisOrder /*could also be rhsOrder since they are now definitely equal */; i++)
        if (rhsCoeff[i]!=thisCoeff[i])
            return false;
    return true;
};

Poly &Poly::operator=(const Poly & rhs)  //assignment operator
{
    this->order = rhs.getOrder();
    this->coeff = new int[order+1];
    coeff=rhs.get();
    return *this; 
};

const int &Poly::operator[ ](int I)const      // return the Ith coefficient
{
    int order = this->getOrder();
    if (I>order+1)
        cout << "Error: " << I << " is out of bounds of this polynomial." << endl;
    const int* coeff = new int [order+1];
    coeff = this->get();
    return coeff[I];
};	
int &Poly::operator[ ](int I)       	// return the Ith coefficient
{
    int order = this->getOrder();
    if (I>order)
        cout << "Error: " << I << " is out of bounds of this polynomial." << endl;
    int* coeff = new int [order+1];
    coeff = this->get();
    return coeff[I];
};
int Poly::operator( )(int X)			// evaluate P(x) according 
{
    int order = this->getOrder();
    int* coeff = new int [order+1];
    coeff = this->get();
    float x = X; //allows specificity of pow function
    int sum=0;
    //first get x to the power of i, then multiply by coeff[i];
    for (int i=0; i<order+1; i++)
        sum+= (coeff[i]*pow(x,i));
    return sum;
};
#ifndef Invoice_H
#define Invoice_H

#include <iostream>
//#include "Add.h"
//#include "Cloths.h"
//#include "Male.h"
//#include "Female.h"
//#include "Children.h"
#include "Payment.h"

using namespace std;

class Invoice //: public Male, public Female, public Children
{

    // private:
    // Payment *objPayment;

public:
    Invoice() {}
    void display_invoice();
};

#endif
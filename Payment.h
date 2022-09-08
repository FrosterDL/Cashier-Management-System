#ifndef Payment_H
#define Payment_H
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

class Payment
{

    char payment_option;

    long double card_number;

    unsigned int credit_card_creation_date;
    unsigned int credit_card_creation_month;
    unsigned int credit_card_creation_year;
    unsigned int credit_card_expiry_date;
    unsigned int credit_card_expiry_month;
    unsigned int credit_card_expiry_year;

    string country;
    string city;
    string society;
    string block;
    string lane;
    string house_number;

public:
    Payment()
    {
    }

    void payment_interface();
};

#endif

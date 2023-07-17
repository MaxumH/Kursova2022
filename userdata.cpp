#include "userdata.h"

UserData::UserData()
{};
void UserData::setincome(int income)
{
    this->income=income;
}
void UserData::setnumber_of_registered(int number_of_registered)
{
    this->number_of_registered=number_of_registered;
}
void UserData::setresedintial_communal_services(int resedintal_communal_services)
{
    this->resedintal_communal_services=resedintal_communal_services;
}
void UserData::setlast_name(QString last_name)
{
     this->last_name=last_name;
}
void UserData::setmandatory_payment(int mandatory_payment)
{
    this->mandatory_payment=mandatory_payment;
}
void UserData::setsubsidy(int subsidy)
{
    this->subsidy=subsidy;
}
int UserData::getincome()const
{
    return income;
}
int UserData::getnumber_of_registered() const
{
    return number_of_registered;
}
int UserData::getresedintal_communal_services() const
{
    return resedintal_communal_services;
}

int UserData::getmandatory_payment() const
{
    return mandatory_payment;
}
int UserData::getsubsidy() const
{
    return subsidy;
}
QString UserData::getlast_name() const
{
    return last_name;
}

#ifndef USERDATA_H
#define USERDATA_H
#include <QString>
#define cost_of_living 2294
#define procent 0.15

class UserData
{
    int income;
    int number_of_registered;
    int resedintal_communal_services;
    int mandatory_payment;
    int subsidy;
    QString last_name;
public:
    UserData();
    void setlast_name(QString last_name);
    void setincome(int income);
    void setnumber_of_registered(int number_of_registered);
    void setresedintial_communal_services(int resedintal_communal_services);
    void setmandatory_payment(int mandatory_payment);
    void setsubsidy(int subsidy);
    int getincome()const;
    int getnumber_of_registered() const;
    int getresedintal_communal_services() const;
    int getmandatory_payment() const;
    int getsubsidy() const;
    QString getlast_name() const;
};

#endif // USERDATA_H

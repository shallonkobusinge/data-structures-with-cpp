#include "Sale.h";

class MailedSale{

    MailedSale();
    MailedSale(double thePrice,double theDiscount, double theShipFee);
    double getShipFee() const;
    void setShipFee(double shipFee);
    double bill() const;

};


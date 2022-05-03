////#include <iostream>
////using namespace std;
////class DiscountSale: public Sale{
////public:
////    DiscountSale();
////	DiscountSale(double thePrice,double Discount);
////
////		double getDiscount() const;
////			void setDiscount(double newDiscount);
////			double bill() const;
////			private:double discount;
////
////
////		 };
////
////		  	double DiscountSale::bill() const{
////				double fraction = discount/100;
////				return (1 - fraction)*getPrice();
////			}
////
////
#include "Sale.h"
using namespace std;
class DiscountSale:public Sale
{
	Sale s1;
public:
	DiscountSale();
	DiscountSale(double thePrice,double theDiscount);
	double getDiscount() const;
	void setDiscount(double newDiscount);
	double bill() const;
private:
	double discount;
};


DiscountSale::DiscountSale():Sale(), discount(0){};
DiscountSale::DiscountSale(double thePrice, double theDiscount) : Sale(thePrice), discount(theDiscount) {}

double DiscountSale::getDiscount() const{
return discount;
}

void DiscountSale::setDiscount(double newDiscount){
	discount = newDiscount;
}

 	double DiscountSale::bill() const{
				double fraction = discount/100;
				return (1 - fraction)*getPrice();
			}


#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Clothing : public Product
{
  public:
    Clothing(const std::string category, const std::string name, double price, int qty, string size, string brand);
    std::set<std::string> keywords() const;
    void dump(std::ostream& os) const;
    std::string displayString() const;

  private:
    string size_;
    string brand_;
};




#endif
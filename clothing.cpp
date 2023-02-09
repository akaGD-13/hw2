#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"
#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, string size, string brand)
  : Product(category, name, price, qty),
  size_(size),
  brand_(brand)
{

}

set<std::string> Clothing::keywords() const
{
  set<string> output;
  set<string> temp = parseStringToWords(name_ + " " + brand_);
  for (set<string>::iterator i= temp.begin(); i != temp.end(); i++){
    string x = *i;
    transform((x).begin(), (x).end(), (x).begin(), ::tolower);
    output.insert(x);
  }
  return output;
}


void Clothing::dump(std::ostream& os) const
{
  os << "clothing" << endl;
  os << getName() << endl;
  os << getPrice() << endl;
  os << getQty() << endl;
  os << size_ << endl;
  os << brand_ << endl;
}

std::string Clothing::displayString() const
{
  string temp = getName() + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(getPrice()) + " " + to_string(getQty()) + " left." + "\n";

  return temp;
}
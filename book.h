#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;


class Book : public Product
{
  public:
    Book(const std::string category, const std::string name, double price, int qty, string ISBN, string author);
    std::set<std::string> keywords() const;
    void dump(std::ostream& os) const;
    std::string displayString() const;

  private:
    string isbn_;
    string author_;
};








#endif
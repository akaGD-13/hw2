#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, string ISBN, string author)
  : Product(category, name, price, qty),
  isbn_(ISBN),
  author_(author)
{

}

set<std::string> Book::keywords() const
{
  set<string> output;
  set<string> temp = parseStringToWords(name_ + " " + author_);
  for (set<string>::iterator i= temp.begin(); i != temp.end(); i++){
    string x = *i;
    transform((x).begin(), (x).end(), (x).begin(), ::tolower);
    output.insert(x);
  }
  output.insert(isbn_); // add isbn as an keyword
  return output;
}


void Book::dump(std::ostream& os) const
{
  os << "book" << endl;
  os << getName() << endl;
  os << getPrice() << endl;
  os << getQty() << endl;
  os << isbn_ << endl;
  os << author_ << endl;
}

std::string Book::displayString() const
{
  string temp = getName() + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(getPrice()) + " " + to_string(getQty()) + " left." + "\n";

  return temp;
}
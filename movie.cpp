#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"
#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, string genre, string rating)
  : Product(category, name, price, qty),
  genre_(genre),
  rating_(rating)
{

}

set<std::string> Movie::keywords() const
{
  set<string> output;
  set<string> temp = parseStringToWords(name_ + " " + genre_);
  for (set<string>::iterator i= temp.begin(); i != temp.end(); i++){
    string x = *i;
    transform((x).begin(), (x).end(), (x).begin(), ::tolower);
    output.insert(x);
  }
  return output;
}


void Movie::dump(std::ostream& os) const
{
  os << "movie" << endl;
  os << getName() << endl;
  os << getPrice() << endl;
  os << getQty() << endl;
  os << genre_ << endl;
  os << rating_ << endl;
}

std::string Movie::displayString() const
{
  string temp = getName() + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(getPrice()) + " " + to_string(getQty()) + " left." + "\n";

  return temp;
}
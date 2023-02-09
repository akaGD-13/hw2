#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;


class Movie : public Product
{
  public:
    Movie(const std::string category, const std::string name, double price, int qty, string genre, string rating);
    std::set<std::string> keywords() const;
    void dump(std::ostream& os) const;
    std::string displayString() const;

  private:
    string genre_;
    string rating_;
};








#endif
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "MyDataStore.h"

using namespace std;

MyDataStore::~MyDataStore()
{
  for (size_t i=0; i < product_.size();i++){
    delete product_[i];
  }
  for (size_t i=0; i < users_.size();i++){
    delete users_[i];
  }
}

void MyDataStore::addProduct(Product* p){
  product_.push_back(p);
}

void MyDataStore::addUser(User* u){
  users_.push_back(u);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  vector<Product*> output;
  // transform all terms to lower case
  for (size_t i=0; i < terms.size(); i++){
    transform((terms[i]).begin(), (terms[i]).end(), (terms[i]).begin(), ::tolower);
  }

  if (type == 0){ // AND search
    for (size_t i=0; i < product_.size();i++){ //loop through the product_
      set<string> temp = product_[i]->keywords(); // temp is the keywords of the product
      bool check = true; // check is a bool to check if the terms are all in the keywords

      for (size_t j=0; j < terms.size(); j++){ // check all the terms

        if (temp.find(terms[j]) == temp.end()){ //if some term is not in the keywords
          check = false;
          break; //exit the inner loop
        }

      }
      if (check){
        output.push_back(product_[i]);
      }

    }

  }

  else if (type == 1){ //OR search
    for (size_t i=0; i < product_.size();i++){ //loop through the product_

      set<string> temp = product_[i]->keywords(); // temp is the keywords of the product
      bool check = false; // check if the product keywords have intersection with terms

      for (size_t j=0; j < terms.size(); j++){ // check all the terms

        if (temp.find(terms[j]) != temp.end()){ //if some term is in the keywords of the product
          check = true;
          break; // exit the inner loop since the product can be push_back now
        }

      }
      if (check){
        output.push_back(product_[i]);
      }

    }

  }

  return output;
}

void MyDataStore::dump(std::ostream& ofile)
{
  //products
  ofile << "<products>" << endl;
  for (size_t i=0; i < product_.size();i++){
    product_[i]->dump(ofile);
  }
  ofile << "</products>" << endl;

  //users
  ofile << "<users>" << endl;
  for (size_t i=0; i < users_.size();i++){
    users_[i]->dump(ofile);
  }
  ofile << "</users>" << endl;
}
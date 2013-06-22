#include <iostream>
using namespace std;
 
// Define a new mixin class with a constructor that accepts all arguments.
 
class Customer
{
  public:
    Customer(const char* fn,const char* ln)
      :firstname_(fn),lastname_(ln)
    {}
    void print() const
    {
      cout << firstname_
           << ' '
           << lastname_;
    }
 
  private:
    const char *firstname_,
               *lastname_;
};
 
// The new mixin class will be defined using multiple inheritance.
// Therefore Base must be turned into a virtual base class.
template <class Base>
class PhoneContact: virtual public Base
{
  public:
    PhoneContact(const char* fn,const char* ln,const char* pn)
      :Base(fn,ln),phone_(pn)
    {}
    void print() const
    {
      Base::print();
      basicprint();
    }
 
  protected:
    // We need an "inner" print method that prints the PhoneContact-specific
    // information only.
    void basicprint() const
    {
      cout << ' ' << phone_;
    }
  private:
    const char *phone_;
};
 
// Base has to be declared as virtual base class here, too.
template <class Base>
class EmailContact: virtual public Base
{
  public:
    EmailContact(const char* fn,const char* ln,const char* e)
      :Base(fn,ln),email_(e)
    {}
 
    void print() const
    {
      Base::print();
      basicprint();
    }
  protected:
    // We need an "inner" print method that prints the EmailContact-specific
    // information only.
    void basicprint() const
    {
      cout << ' ' << email_;
    }
  private:
    const char *email_;
};
 
template <class Base>
class PhoneAndEmailContact :
         public PhoneContact<Base>,
         public EmailContact<Base>
{
  public:
    // Because Base is a virtual base class, PhoneAndEmailContact is now
    // responsible for its initialization.
    PhoneAndEmailContact(const char* fn,
                         const char* ln,char* pn,const char* e)
     :PhoneContact<Base>(fn,ln,pn),
      EmailContact<Base>(fn,ln,e),
      Base(fn,ln)
      {}
      void print() const
      {
         Base::print();
         PhoneContact<Base>::basicprint();
         EmailContact<Base>::basicprint();
      }
};
 
int main()
{
  Customer c1("Teddy","Bear");
  c1.print(); cout << endl;
  PhoneContact<Customer> c2("Rick","Racoon","050-998877");
  c2.print(); cout << endl;
  EmailContact<Customer> c3("Dick","Deer","dick@deer.com");
  c3.print(); cout << endl;
  PhoneAndEmailContact<Customer>
  c4("Eddy","Eagle","049-554433","eddy@eagle.org");
  c4.print(); cout << endl;
  return 0;
}

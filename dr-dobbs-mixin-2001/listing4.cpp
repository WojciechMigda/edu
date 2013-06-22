#include <iostream>
using namespace std;
 
// Define special intialization methods in each class and no longer rely
// on the proper initialization though constructors.
 
class Customer
{
  public:
    // Initialization method for Customer.
    // A default constructor will be generated automatically.
    void init(const char* fn,const char* ln)
    {
      firstname_ = fn;
      lastname_ = ln;
    }
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
 
template <class Base>
class PhoneContact: public Base
{
  public:
    // Initialization method for PhoneContact only.
    // A default constructor will be generated automatically.
    void init(const char* pn)
    {
      phone_ = pn;
    }
 
    void print() const
    {
      Base::print();
      cout << ' ' << phone_;
    }
  private:
    const char *phone_;
};
 
template <class Base>
class EmailContact: public Base
{
  public:
    // Initialization method for EmailContact only.
    // A default constructor will be generated automatically.
    void init(const char* e)
    {
      email_ = e;
    }
 
    void print() const
    {
      Base::print();
      cout << ' ' << email_;
    }
  private:
    const char *email_;
};
 
int main()
{
  // Compiler generated default constructor gets called.
  Customer c1;
  // Now explicitly invoke the initialization method.
  c1.init("Teddy","Bear");
  c1.print(); cout << endl;
  // Basically the same as above.
  PhoneContact<Customer> c2;
  // But initialization method for Customer must also be explicitly invoked!
  c2.Customer::init("Rick","Racoon");
  c2.init("050-998877");
  c2.print(); cout << endl;
  // Basically the same as above.
  EmailContact<Customer> c3;
  c3.Customer::init("Dick","Deer");
  c3.init("dick@deer.com");
  c3.print(); cout << endl;
  // Now the three initialization methods of three different mixin classes
  // must be explicitly invoked! The composed class does not provide its own
  // initialization method.
  EmailContact<PhoneContact<Customer> > c4;
  c4.Customer::init("Eddy","Eagle");
  c4.PhoneContact<Customer>::init("eddy@eagle.org");
  c4.EmailContact<PhoneContact<Customer> >::init("049-554433");
  c4.print(); cout << endl;
  // Basically the same as above.
  PhoneContact<EmailContact<Customer> > c5;
  c5.Customer::init("Eddy","Eagle");
  c5.EmailContact<Customer>::init("eddy@eagle.org");
  c5.PhoneContact<EmailContact<Customer> >::init("049-554433");
  c5.print(); cout << endl;
  return 0;
}

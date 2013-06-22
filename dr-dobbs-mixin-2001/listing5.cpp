#include <iostream>
using namespace std;
 
// Define additional constructors that will be instantiated only if required.
 
class Customer
{
  public:
    Customer(const char* fn,const char* ln):firstname_(fn),lastname_(ln)
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
 
template <class Base>
class PhoneContact: public Base
{
  public:
    // The following constructors will be instantiated only if required.
    PhoneContact( const char* fn,const char* ln,
                  const char* pn):Base(fn,ln),phone_(pn)
    {}
    PhoneContact( const char* fn,const char* ln,
                  const char* pn,const char* e)
      :Base(fn,ln,e),phone_(pn)
    {}
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
    // The following constructors will be instantiated only if required.
    EmailContact( const char* fn, const char* ln,
                  const char* e):Base(fn,ln),email_(e)
    {}
    EmailContact( const char* fn,const char* ln,
                  const char* pn,const char* e)
      :Base(fn,ln,pn),email_(e)
    {}
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
  Customer c1("Teddy","Bear");
  c1.print(); cout << endl;
  PhoneContact<Customer> c2("Rick","Racoon","050-998877");
  c2.print(); cout << endl;
  EmailContact<Customer> c3("Dick","Deer","dick@deer.com");
  c3.print(); cout << endl;
  EmailContact<PhoneContact<Customer> >
  c4("Eddy","Eagle","049-554433","eddy@eagle.org");
  c4.print(); cout << endl;
  PhoneContact<EmailContact<Customer> >
  // The following composition prints the last two arguments in reverse
  // order because the print() method is composed differently than previously.
  c5("Eddy","Eagle","049-554433","eddy@eagle.org");
  c5.print(); cout << endl;
  return 0;
}

#include <iostream>
using namespace std;
// Define a class that wraps the union of all constructor arguments
// of Customer and all derived mixin classes.
 
// CustomerParameter combines all constructor arguments of CustomerParameter
// and its derived mixin classes. The default values for the last two
// arguments provide some convenience to the client programmer.
struct CustomerParameter
{
  const char
    * fn,
    * ln,
    * pn,
    * e;
  CustomerParameter( const char* fn_,const char*ln_,
                     const char* pn_ = "",const char* e_ = "")
    :fn(fn_),ln(ln_),pn(pn_),e(e_)
  {}
};
 
class Customer
{
  public:
    Customer(const CustomerParameter& cp)
      :firstname_(cp.fn),lastname_(cp.ln)
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
    PhoneContact(const CustomerParameter& cp)
      :Base(cp),phone_(cp.pn)
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
    EmailContact(const CustomerParameter& cp)
      :Base(cp),email_(cp.e)
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
  Customer c1(CustomerParameter("Teddy","Bear"));
  c1.print(); cout << endl;
  PhoneContact<Customer>
  c2(CustomerParameter("Rick","Racoon","050-998877"));
  c2.print(); cout << endl;
  EmailContact<Customer>
  c3(CustomerParameter("Dick","Deer","","dick@deer.com"));
  c3.print(); cout << endl;
  EmailContact<PhoneContact<Customer> >
  c4(CustomerParameter("Eddy","Eagle","049-554433","eddy@eagle.org"));
  c4.print(); cout << endl;
  PhoneContact<EmailContact<Customer> >
  // The following composition prints the last two arguments in a
  // reverse order because the print() method is now composed differently.
  c5(CustomerParameter("Eddy","Eagle","049-554433","eddy@eagle.org"));
  c5.print(); cout << endl;
  return 0;
}

#include <iostream>
using namespace std;
class Base {
   int data;
public:
   Base( int v = 0 ) :data( v ) {
      cout << "[CBase: " << data << "](" << &data << ")\n";
   }
   virtual ~Base( ) {
      cout << "[~Base: " << data << "](" << &data << ")\n";
   }
   virtual ostream& show( ostream& os )const {
      return os << "[Base: " << data << "](" << &data << ")";
   }
};
ostream& operator<<( ostream& os, const Base& B ) {
   return B.show( os );
}
class B1 :virtual public Base {
   int data;
public:
   B1( int v = 0 ) :Base( v + 1 ), data( v ) {
      cout << "[CB1: " << data << "]\n";
   }
   virtual ~B1( ) {
      cout << "[~B1: " << data << "]\n";
   }
   virtual ostream& show( ostream& os )const {
      Base::show( os );
      return os << "[B1: " << data << "]";
   }
};

class Derived :public B1{
   int data;
public:
   Derived( int v ) :B1( v + 10 ), data( v ) {
      cout << "[CD: " << data << "]\n";
   }
   virtual ~Derived( ) {
      cout << "[~D: " << data << "]\n";
   }
   virtual ostream& show( ostream& os )const {
      os << "========================" << endl;
      Base::show( os ) << endl;
      B1::Base::show( os ) << endl;
      B1::show( os ) << endl;
      os << "[D: " << data << "]" << endl;
      return os << "========================" << endl;
   }
};
int main( ) {
   Derived D( 200 );
   cout << D << endl;
   return 0;
}
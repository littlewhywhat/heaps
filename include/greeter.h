#include <iostream>

//! Greeter greets smb in provided stream
/*!
    Says hello to anybody you want in stream you like
*/
class Greeter {
  public:
  	//! Greets whom in out
    /*!
        Greets in provided stream smb in whom
    */
    void greet(std::ostream & out, const char * whom);
};
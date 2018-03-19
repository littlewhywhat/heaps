#include "greeter.h"

void Greeter::greet(std::ostream & out, const char * whom) {
	out << "Hello, " << whom << "!\n";
}

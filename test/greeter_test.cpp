#include <gtest/gtest.h>

#include "greeter.h"

using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStdout;

//! Tests Greeter
class GreeterTest : public ::testing::Test {
  public:
    //! Tests greet method
  	void test_greet() {
  	  const char * greeting = "Hello, test!\n";
  	  const char * whom   = "test";
      CaptureStdout();
      this->greeter.greet(std::cout, whom);
      std::string stdout_ = GetCapturedStdout();
      ASSERT_STREQ(stdout_.c_str(), greeting);
  	}
  private:
    //! Tested greeter
  	Greeter greeter;
};

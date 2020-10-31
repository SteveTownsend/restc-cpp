// Include before boost::log headers
#include "restc-cpp/logging.h"

#ifdef RESTC_CPP_LOG_WITH_BOOST_LOG
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#endif


#include <boost/fusion/adapted.hpp>

#include "restc-cpp/restc-cpp.h"
#include "restc-cpp/RequestBuilder.h"

#include "restc-cpp/test_helper.h"
#include "lest/lest.hpp"

using namespace std;
using namespace restc_cpp;

const lest::test specification[] = {

STARTCASE(TestDataWithCString)
{
    RequestBuilder rb;
    rb.Data("{}");
    CHECK_EQUAL("{}", rb.GetData());

} ENDCASE

STARTCASE(TestDataWithCStringLen)
{
    RequestBuilder rb;
    rb.Data("{}12345", 2);
    CHECK_EQUAL("{}", rb.GetData());

} ENDCASE

STARTCASE(TestDataWithString)
{

    const string data{"{}"};

    RequestBuilder rb;
    rb.Data(data);
    CHECK_EQUAL(data, rb.GetData());

} ENDCASE


}; // lest


int main( int argc, char * argv[] )
{
    return lest::run( specification, argc, argv );
}

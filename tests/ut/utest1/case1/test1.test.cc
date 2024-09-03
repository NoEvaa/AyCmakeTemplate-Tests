#include <aytest/singleton.hpp>
#include <testlib.h>

void testtt();

struct TTT{
    TTT()
{
aytest::Singleton<AA>::instance().a_ = 20; 
    }
};
static TTT sss;
void testtt()
{

}

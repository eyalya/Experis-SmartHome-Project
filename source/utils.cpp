#include <limits>

#include "utils.hpp"
#include "prime_table.hpp"

namespace advcpp
{

namespace numbers
{
const size_t sizeLimit = 10000;  //std::numeric_limits<std::size_t>::max();

size_t FindNextPrime(size_t a_num)
{
    static PrimeTable<size_t> s_table(sizeLimit);

    return s_table.FindNextPrime(a_num);
}





} // end number

} // end cpp

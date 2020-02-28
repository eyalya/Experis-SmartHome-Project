#ifndef PRIME_TABLE_HPP
#define PRIME_TABLE_HPP

#include "utils.hpp"

namespace advcpp
{
namespace numbers
{

template <typename T> 
//T:: must be a number type 
class PrimeTable {
public:
    PrimeTable(size_t a_maxNum);
    /*
	~PrimeTable(); = default
	PrimeTable(const PrimeTable& a_rhs); = default
	operator = (const PrimeTable& a_rhs); = default
	*/

    bool IsPrime(T a_num);
    T FindNextPrime(T a_num);

private:
    void FillPrimeTable();
    bool IsPrimeItirate(T a_num);

private:
    std::set<T> m_pTable;
    T m_maxNum;
};


////////////// PrimeTable //////////////////////////////////////////////////////////////
template <typename T>
advcpp::numbers::PrimeTable<T>::PrimeTable(size_t a_maxNum)
: m_pTable() 
,m_maxNum(a_maxNum)
{
    FillPrimeTable();
}

template <typename T>
bool advcpp::numbers::PrimeTable<T>::IsPrime(T a_num)
{
    typename std::set<T>::iterator it = m_pTable.find(a_num);
    if (it == m_pTable.end())
    {
        return false;
    }
    return true;
}

template <typename T>
T advcpp::numbers::PrimeTable<T>::FindNextPrime(T a_num)
{
    while (!IsPrime(a_num))
    {
        ++a_num;
    }
    return a_num;
}

template <typename T>
void advcpp::numbers::PrimeTable<T>::FillPrimeTable()
{
    for (T i = 1; i < m_maxNum; ++i)
    {
        if (IsPrimeItirate(i))
        {
            m_pTable.insert(i);
        }
    }
}

template <typename T>
bool advcpp::numbers::PrimeTable<T>::IsPrimeItirate(T a_num)
{   /* Check if a prime number, check the first 5 number manually and than skip by 6 */ 
    if (a_num % 2 == 0 || a_num % 3 == 0)
    {
        return false;
    }

	const int primeSkipFactor = 6;
    for (size_t i = 2; (i * i) <= a_num; i += primeSkipFactor)
    {
        if (a_num % i == 0)
        {
            return false;
        } 
    }
    return true;
}


} // ending numbers
} // ending advcpp
#endif //PRIME_TABLE_HPP
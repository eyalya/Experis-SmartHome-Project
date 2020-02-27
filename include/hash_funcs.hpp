#ifndef HASH_FUNCS_HPP
#define HASH_FUNCS_HPP

#include <cstdlib>
#include <cstring> //strlen 
#include <string> //string 

namespace advcpp
{
template <typename Key>
class DefaultHasher {
public:
    size_t operator () (Key const& a_key) const;
};

template <typename Key>
size_t hash (Key const& a_key);

size_t hash (int const& a_num);

size_t hash(char *a_key);
///////////// Public Functions //////////////////////////////////////////////////////////////////////////////////////
template <typename Key>
size_t DefaultHasher<Key>::operator () (Key const& a_key) const
{
    return hash(a_key);
}

template <typename Key>
size_t hash (Key const& a_key)
{
    return a_key.hash();
}

size_t hash (int const& a_num)
{
//    TODO: find a better one
    return static_cast<size_t>(a_num);
}

size_t hash(char *a_key)
{
    size_t hash, i;
    size_t len = strlen(a_key);
    for(hash = i = 0; i < len; ++i)
    {
        hash += a_key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

size_t hash(std::string a_key)
{
    size_t hash, i;
    size_t len = a_key.size();

    for(hash = i = 0; i < len; ++i)
    {
        hash += a_key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

} // advcpp
#endif //HASH_FUNCS_HPP
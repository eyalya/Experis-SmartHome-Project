#include <iostream>
#include "hash_table.hpp"
#include "locks.hpp"

namespace advcpp
{

const size_t g_nBucketsPerLock = 50;

template <typename Key, typename Value, typename Hasher>
HashTable<Key, Value, Hasher>::HashTable (size_t a_capacity, Hasher a_func)
: Index(numbers::FindNextPrime(a_capacity)) 
, m_capacity(numbers::FindNextPrime(a_capacity))
, m_hasFunc(a_func)
, m_size(0)
, m_nlocks(a_capacity / g_nBucketsPerLock + 1)
{
   assert(this->size() == numbers::FindNextPrime(a_capacity));
   
   lockCreator();
   assert(m_nlocks == m_locks.size());
}

template <typename Key, typename Value, typename Hasher>
typename HashTable<Key, Value, Hasher>::iterator 
HashTable<Key, Value, Hasher>::Insert (Key const& a_key, Value& a_value)
{
    Triplet<Key, Value> item(a_key, a_value, 0);
	Bucket<Key, Value>& bucket = getBacket(item);
    Guard(*getLock(item));

	iterator it = bucket.Insert(item);
	
	if (it == bucket.End())
	{
	    return End(); 
	}

    ++getSize();
	return it;
}

template <typename Key, typename Value, typename Hasher>
typename HashTable<Key, Value, Hasher>::iterator 
HashTable<Key, Value, Hasher>::Find (Key const& a_key)
{
    Triplet<Key, Value> item(a_key);
    BucketT& bucket = getBacket(item);

	typename BucketT::iterator it = bucket.Find (item);
    typename BucketT::iterator end = bucket.End();
	
	if (it == end)
	{
	    return End(); 
	}

	return it;
}

template <typename Key, typename Value, typename Hasher>
bool HashTable<Key, Value, Hasher>::Remove (Key const& a_key, Value& a_removedValue)
{
    Triplet<Key, Value> item(a_key, a_removedValue, 0);
    BucketT& bucket = getBacket(item);

    advcpp::Guard(*getLock(item));
    return bucket.Remove(item);;
}

template <typename Key, typename Value, typename Hasher>
typename advcpp::HashTable<Key, Value, Hasher>::iterator
HashTable<Key, Value, Hasher>::operator [] (Key const& a_key)
{
    Triplet<Key, Value> item(a_key);
    size_t index = getIndex(item);
	assert(index < Index::size());

    BucketT& bucket = Index::operator[](index);
    return bucket.Begin();
}


template <typename Key, typename Value, typename Hasher>
typename HashTable<Key, Value, Hasher>::iterator
HashTable<Key, Value, Hasher>::Begin()
{
    BucketT& firstBucket = *(Index::begin());
    return firstBucket.Begin();
}

template <typename Key, typename Value, typename Hasher>
typename HashTable<Key, Value, Hasher>::const_iterator
HashTable<Key, Value, Hasher>::Begin() const
{
    return Begin();
}

template <typename Key, typename Value, typename Hasher>
typename HashTable<Key, Value, Hasher>::iterator
HashTable<Key, Value, Hasher>::End()
{
    BucketT& lastBucket = *(--Index::end());
    return lastBucket.End();
}

template <typename Key, typename Value, typename Hasher>
typename HashTable<Key, Value, Hasher>::const_iterator
HashTable<Key, Value, Hasher>::End() const
{
    return End();
}

template <typename Key, typename Value, typename Hasher>
size_t HashTable<Key, Value, Hasher>::Capacity() const
{
	return getCapacity();
}

template <typename Key, typename Value, typename Hasher>
size_t HashTable<Key, Value, Hasher>::Size() const
{
	return getSize();
}

template <typename Key, typename Value, typename Hasher>
double HashTable<Key, Value, Hasher>::LoadFactor() const
{
    return static_cast<double>(Size())/Capacity();
}

/*
template <typename Key, typename Value, typename Hasher>
void HashTable<Key, Value, Hasher>::Resize(size_t a_size)
{
    std::vector<Bucket<const Key, Value> > temp = *this;
    Clear();
    Index::resize(numbers::FindNextPrime(a_size));

//     typename Index::iterator it = temp.begin();
//     while (it != temp.end())
//     {
//         ReIndexBucket(*it);
//         ++it;
//     }
// }
*/

template <typename Key, typename Value, typename Hasher>
void HashTable<Key, Value, Hasher>::Clear()
{
    typename Index::iterator it = Index::begin();
    while (it != Index::end())
    {
        it->Clear();
        ++it;
    }
    getSize() = 0;

    // typename Index::iterator begin = Index::begin();
    // typename Index::iterator end = Index::end();

    // std::for_each(begin, end, Bucket().clear);
}

template <typename Key, typename Value, typename Hasher>
void HashTable<Key, Value, Hasher>::swap (HashTable& a_rhs)
{
    advcpp::utils::Swap (m_capacity, a_rhs.m_capacity);
    advcpp::utils::Swap (m_hasFunc, a_rhs.m_hasFunc);
    advcpp::utils::Swap (m_size, a_rhs.m_size);
    this->swap(a_rhs);
}

template <typename Key, typename Value, typename Hasher>
Mutex* HashTable<Key, Value, Hasher>::getLock(Triplet<Key, Value> const& a_item)
{
    assert (m_nlocks != 0);

    size_t lockIndex = a_item.m_hashVal % m_nlocks;
    return m_locks[lockIndex];
}

template <typename Key, typename Value, typename Hasher>
size_t HashTable<Key, Value, Hasher>::getIndex(Triplet<Key, Value>& a_item)
{
	a_item.m_hashVal = getHasher()(a_item.m_key);
	return a_item.m_hashVal % Capacity(); 
}

// template <typename Key, typename Value, typename Hasher>
// size_t HashTable<Key, Value, Hasher>::getIndex(Triplet<Key, Value>& a_item) const
// {
// 	a_item.m_hashVal = getHasher()(a_item.m_key);
// 	return a_item.m_hashVal % Capacity(); 
// }

template <typename Key, typename Value, typename Hasher>
Hasher& HashTable<Key, Value, Hasher>::getHasher()
{
	return m_hasFunc;
}

template <typename Key, typename Value, typename Hasher>
Hasher const& HashTable<Key, Value, Hasher>::getHasher() const
{
	return m_hasFunc;
}

template <typename Key, typename Value, typename Hasher>
Bucket<Key, Value>& HashTable<Key, Value, Hasher>::getBacket(Triplet<Key, Value>& a_item)
{
    size_t index = getIndex(a_item);
	assert(index < Index::size());

    BucketT& bucket = Index::at(index);
    return bucket;
}


template <typename Key, typename Value, typename Hasher>
void HashTable<Key, Value, Hasher>::reIndexBucket(BucketT& a_bucket)
{
    iterator it = a_bucket.Begin();
    iterator end = a_bucket.End();
    while (it != end)
    {
        Insert(it->first, it->second);
        ++it;
    }
}

template <typename Key, typename Value, typename Hasher>
void HashTable<Key, Value, Hasher>::lockCreator()
{
    for (size_t i = 0; i < m_nlocks; ++i)
    {
        Mutex* newLock = new Mutex();
        m_locks.push_back(newLock);
    }
}

template <typename Key, typename Value, typename Hasher>
size_t& HashTable<Key, Value, Hasher>::getSize() 
{
    return m_size;
}

template <typename Key, typename Value, typename Hasher>
size_t const& HashTable<Key, Value, Hasher>::getSize() const
{
    return m_size;
}

template <typename Key, typename Value, typename Hasher>
size_t& HashTable<Key, Value, Hasher>::getCapacity()
{
    return m_capacity;
}

template <typename Key, typename Value, typename Hasher>
size_t const& HashTable<Key, Value, Hasher>::getCapacity() const
{
    return m_capacity;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Key, typename Value>
typename Bucket<Key, Value>::iterator
Bucket<Key, Value>::Insert (TripletV const& a_item)
{
    iterator it = Find(a_item);

    if (it == list().end())
    {
        list().push_front(a_item);
        return list().begin();
    }
    
    return it;
}

template <typename Key, typename Value>
bool Bucket<Key, Value>::Remove (TripletV& a_removable)
{
    iterator it = Find(a_removable);
    if (it == list().end())
    {
        return false;
    }

    a_removable.m_value = it->m_value;
    list().erase(it);
    return true; 
}

template <typename Key, typename Value>
typename Bucket<Key, Value>::iterator Bucket<Key, Value>::Find (TripletV const& a_item)
{
    HashPred<Key, Value> pred(a_item);
    return std::find_if(Begin(), End(), pred);
}


template <typename Key, typename Value>
void Bucket<Key, Value>::Print(std::ostream& os)
{
    // const_iterator it = List().begin();
    // const_iterator end = List().end();

    // while (it != end)
    // {
    //     if (a_key == it->first)
    //     {
    //         return it;
    //     }
    //     ++it;
    // }

    //return Find();
}

template <typename Key, typename Value>
void Bucket<Key, Value>::Clear()
{
    list().clear();
}

template <typename Key, typename Value>
std::list<Triplet<Key, Value> > const& 
Bucket<Key, Value>::list() const
{
	return m_list;
}

template <typename Key, typename Value>
std::list<Triplet<Key, Value> >& 
Bucket<Key, Value>::list()
{
	return m_list;
}


template <typename Key, typename Value>	
typename std::list<Triplet<Key, Value> >::iterator 
Bucket<Key, Value>::End()
{
    return list().end();
}

template <typename Key, typename Value>
typename std::list<Triplet<Key, Value> >::const_iterator 
Bucket<Key, Value>::End() const
{
    return list().end();
}

template <typename Key, typename Value>	
typename std::list<Triplet<Key, Value> >::iterator 
Bucket<Key, Value>::Begin()
{
    return list().begin();
}

template <typename Key, typename Value>
typename std::list<Triplet<Key, Value> >::const_iterator 
Bucket<Key, Value>::Begin() const
{
    return list().begin();
}
    
template <typename Key, typename Value>
size_t Bucket<Key, Value>::Size() const
{
    return list().size();
}

// ///////////// Pred //////////////////////////////////////////////////////////////////////////////////////
template <typename Key, typename Value>
HashPred<Key, Value>::HashPred(Triplet<Key, Value> const& a_objectVal)
: m_objectVal (a_objectVal)
{
}

template <typename Key, typename Value>
bool HashPred<Key, Value>::operator () (Triplet<Key, Value> const& a_val)
{
    if (m_objectVal.m_hashVal != a_val.m_hashVal)
    {
        return false;
    }
    if (m_objectVal.m_key != a_val.m_key) 
    {
        return false;
    }
    return true;
}

///////////// Triplet //////////////////////////////////////////////////////////////////////////////////////
template <typename Key, typename Value>
advcpp::Triplet<Key, Value>::Triplet(Key const& a_key, Value& a_val, size_t a_hashVal)
: m_key(a_key)
, m_value(a_val)
, m_hashVal(a_hashVal)
{
}

template <typename Key, typename Value>
advcpp::Triplet<Key, Value>::Triplet(Key const& a_key, Value const& a_val, size_t a_hashVal)
: m_key(a_key)
, m_value(a_val)
, m_hashVal(a_hashVal)
{
}


template <typename Key, typename Value>
advcpp::Triplet<Key, Value>::Triplet(Key const& a_key)
: m_key(a_key)
{
}


} // namespace advcpp
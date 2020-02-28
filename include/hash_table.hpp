#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector> 
#include <list>
#include <utility>
#include <cassert>
#include <iostream>
#include <algorithm> //find_if

#include "utils.hpp"
#include "util.hpp"
#include "hash_funcs.hpp"
#include "locks.hpp"

namespace advcpp
{

template <typename Key, typename Value>
struct Triplet {
    Triplet(Key const& a_key);
    Triplet(Key const& a_key, Value& a_val, size_t a_hashVal);
    Triplet(Key const& a_key, Value const& a_val, size_t a_hashVal);

    const Key m_key;
    Value m_value;
    size_t m_hashVal;
};

template <typename Key, typename Value>
class Bucket {
public:
    typedef typename advcpp::Triplet<Key, Value> TripletV;
    typedef typename std::list<TripletV>::iterator iterator;
    typedef typename std::list<TripletV>::const_iterator const_iterator;
    
    /*
    Bucket();
	Bucket(const Bucket& a_rhs);
	~Bucket(); = default
    Bucket& operator = (const Bucket& a_rhs);
	*/

    iterator Insert (TripletV const& a_item);
	bool Remove (TripletV& a_removable);

    iterator Find (TripletV const& a_item);

	iterator Begin();
    const_iterator Begin() const;
    iterator End();
    const_iterator End() const;

    size_t Size() const;

    void Print(std::ostream& os);
    void Clear();

private:
	std::list<TripletV>& list();
	std::list<TripletV> const& list() const;
	  
private:
    std::list<TripletV> m_list;
};

template <typename Key, typename Value, typename Hasher = DefaultHasher<Key> >
//Key:: must have == operator and be assignable, destructable and copyiable
//Value:: must have default constructor  
//Hasher:: callable with &Key must return size_t num
class HashTable: private std::vector<Bucket<Key, Value> > {
public: 
    typedef Bucket<Key, Value> BucketT;
    typedef typename std::vector<BucketT> Index;
    typedef typename BucketT::iterator iterator;
    typedef typename BucketT::const_iterator const_iterator;

    template <typename T, typename Iter>
    friend class MyHashIter;

	HashTable(size_t a_capacity = 1000, Hasher a_func = DefaultHasher<Key>());
	
	/*
	~HashTable(); = default
	HashTable(const HashTable& a_rhs); = default
	operator = (const HashTable& a_rhs); = default
	*/
	
	iterator Insert (Key const& a_key, Value& a_val);
	bool Remove (Key const& a_key, Value& a_removedValue);
	
	iterator Find (Key const& a_key);
	const_iterator Find (Key const& a_key) const;
	iterator operator [] (Key const& a_key);
	
    iterator Begin();
    const_iterator Begin() const;
    iterator End();
    const_iterator End() const;    
    
	size_t Size() const;
	size_t Capacity() const;
    double LoadFactor() const;

    //void Resize(size_t a_size);
	void Clear();
    void swap (HashTable& a_rhs);

private: 
	Hasher& getHasher();
	Hasher const& getHasher() const;

    Mutex* getLock(Triplet<Key, Value> const& a_item);
	
	size_t getIndex(Triplet<Key, Value>& a_item);
    BucketT& getBacket(Triplet<Key, Value>& a_item);
    void reIndexBucket(BucketT& a_bucket);
    
    void lockCreator();
    void LockAll();
    void UnlockAll();

    size_t& getSize();
    size_t const& getSize() const;

    size_t& getCapacity();
    size_t const& getCapacity() const;

private:
	size_t m_capacity;
	Hasher m_hasFunc;
	size_t m_size;
    size_t m_nlocks;
    std::vector<Mutex*> m_locks; 
};

template <typename Key, typename Value>
struct HashPred {
    HashPred(Triplet<Key, Value> const& a_objectVal);
    bool operator () (Triplet<Key, Value> const& a_val);

    Triplet<Key, Value> m_objectVal;
};

template <typename Key, typename Value, typename H>
void swap (HashTable<Key, Value, H>& a_lhs, HashTable<Key, Value, H>& a_rhs);

// template <typename Key, typename Value ,typename Pred>
// typename advcpp::Bucket<Key, Value>::iterator Find (Bucket<Key, Value>& a_bucket, Pred a_pred);
////////////////////////////////////////////////////////////////////////////////////////////////////////////



} // namespace advcpp

#include "hash_table.inl"
#endif //HASH_TABLE_HPP

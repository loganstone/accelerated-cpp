// Copyright 2018, loganstone

#ifndef CHAPTER11_VEC_H_
#define CHAPTER11_VEC_H_

#include <algorithm>
#include <cstddef>
#include <memory>

template <class T>
class Vec {
 public:
  typedef T* Iterator;
  typedef const T* ConstIterator;
  typedef std::size_t SizeType;
  typedef T ValueType;
  typedef std::ptrdiff_t DifferenceType;
  typedef T& Reference;
  typedef const T& ConstReference;

  Vec() { Create(); }
  explicit Vec(SizeType n, const T& t = T()) { Create(n, t); }

  Vec(const Vec& v) { Create(v.begin, v.end()); }
  Vec& operator=(const Vec&);
  ~Vec() { Uncrate(); }

  T& operator[](SizeType i) { return data[i]; }
  const T& operator[](SizeType i) const { return data[i]; }

  void PushBack(const T& t) {
    if (avail == limit) {
      Grow();
    }
    UncheckedAppend(t);
  }

  SizeType Size() const { return limit - data; }

  Iterator Begin() { return data; }
  ConstIterator Begin() const { return data; }

  Iterator End() { return limit; }
  ConstIterator End() const { return limit; }

 private:
  Iterator data;
  Iterator avail;
  Iterator limit;

  std::allocator<T> alloc;

  void Create();
  void Create(SizeType, const T&);
  void Create(ConstIterator, ConstIterator);

  void Uncrate();

  void Grow();
  void UncheckedAppend(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
  if (&rhs != this) {
    Uncrate();

    create(rhs.Begin(), rhs.End());
  }
  return *this;
}

template <class T>
void Vec<T>::Create() {
  data = avail = limit = 0;
}

template <class T>
void Vec<T>::Create(SizeType n, const T& val) {
  data = alloc.allocate(n);
  limit = avail = data + n;
  std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::Create(ConstIterator i, ConstIterator j) {
  data = alloc.allocate(j - i);
  limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::Uncrate() {
  if (data) {
    Iterator it = avail;
    while (it != data) {
      alloc.destroy(--it);
    }
    alloc.deallocate(data, limit - data);
  }
  Create();
}

template <class T>
void Vec<T>::Grow() {
  SizeType new_size = std::max(2 * (limit - data), ptrdiff_t(1));

  Iterator new_data = alloc.allocate(new_size);
  Iterator new_avail = std::uninitialized_copy(data, avail, new_data);

  Uncrate();

  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

template <class T>
void Vec<T>::UncheckedAppend(const T& val) {
  alloc.construct(avail++, val);
}

#endif  // CHAPTER11_VEC_H_

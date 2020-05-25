#include <memory>
#include <algorithm>

template <class T>
  class Vector {
    public: // interfeisas
      typedef T* iterator;
      typedef const T* const_iterator;
      typedef size_t size_type;
      typedef T value_type;
      typedef ptrdiff_t difference_type;
      typedef value_type& reference;
      typedef const value_type& const_reference;

      // rule of three
      Vector() { create(); }
      explicit Vector(size_type n, const T& t = T{}) { create(n, t); }
      Vector(const Vector& v) { create(v.begin(), v.end()); }

      Vector& operator=(const Vector&);
      ~Vector() { uncreate(); }

      T& operator[](size_type i) { return Data[i]; }
      const T& operator[](size_type i) const { return Data[i]; }
      void push_back(const T& t) {
        if (avail == limit)
          grow();
        unchecked_append(t);
      }

      size_type size() const { return avail - Data; }
      size_type capacity() const { return limit - Data; }
      iterator begin() { return Data; }
      const_iterator begin() const { return Data; }
      iterator end() { return avail; }
      const_iterator end() const { return avail; }
      iterator rbegin() { return avail-1; }
      const_iterator rbegin() const {return avail-1; }
      iterator rend() { return Data-1; }
      const_iterator rend() const {return Data-1; }
      reference at(size_type i) {
        if(Data+i>=avail)std::cout << "out of range!" << std::endl;
        else return Data[i]; }
      reference front() { return *Data; }
      const_reference front() const { return *Data; }
      reference back() {iterator a=avail-1; return *a; }
      const_reference back() const {iterator a=avail-1; return *a; }
      reference data() { return Data; }
      const_reference data() const { return Data; }
      [[nodiscard]] constexpr bool empty() const noexcept{
            if(avail-Data>0) return false;
            else return true; }
      //size_type max_size() const { std::distance(begin(), end()); }
       void clear();
       void reserve(size_type);
       // sunaikinti elementus array ir atlaisvinti atmintį
      void uncreate();




    // likusi interfeiso realizacija
    private:
      iterator Data; // pakeista iš T* į iterator
      iterator avail; // pirmasis po paskutiniojo sukonstruoto Vector elementas
      iterator limit; // pakeista iš T* į iterator

      // atminties išskyrimo valdymui
      std::allocator<T> alloc; // objektas atminties valdymui
      // išskirti atmintį (array) ir ją inicializuoti
      void create();
      void create(size_type, const T&);
      void create(const_iterator, const_iterator);

      // pagalbinės funkcijos push_back realizacijai
      void grow();
      void unchecked_append(const T&);
};

template <class T>
  void Vector<T>::create() {
    Data = avail = limit = nullptr;
  }
template <class T>
  void Vector<T>::create(size_type n, const T& val) {
    Data = alloc.allocate(n); // grąžina ptr į array pirmą elementą
    limit = avail = Data + n; // sustato rodykles į vietas
    std::uninitialized_fill(Data, limit, val); // inicializuoja elementus val reikšme
  }
template <class T>
  void Vector<T>::create(const_iterator i, const_iterator j) {
    Data = alloc.allocate(j - i); // išskirti vietos j-i elementams
    limit = avail = std::uninitialized_copy(i, j, Data); // nukopijuoja elementus iš intervalo
  }

template <class T>
  void Vector<T>::uncreate() {
    if (Data) {
    // sunaikinti (atbuline tvarka) sukonstruotus elementus
      iterator it = avail;
      while (it != Data)
        alloc.destroy(--it);
      // atlaisvinti išskirtą atmintį. Turi būti Data != nullptr
      alloc.deallocate(Data, limit - Data);
    }
    // reset'inam pointer'iuss - Vector'ius tuščias
    Data = limit = avail = nullptr;
  }

template <class T>
  void Vector<T>::clear()  {
    if (Data) {
    // sunaikinti (atbuline tvarka) sukonstruotus elementus
      iterator it = avail;
      while (it != Data)
        alloc.destroy(--it);
    }}

template <class T>
  void Vector<T>::reserve(size_type new_cap) {
    if(new_cap > limit - Data){
    //new_cap = new_cap-(limit-Data);
    size_type new_size = new_cap;
    // išskirti naują vietą ir perkopijuoti egzistuojančius elementus
    iterator new_Data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(Data, avail, new_Data);
    // atlaisvinti seną vietą
    uncreate();
    // reset'int rodykles į naujai išskirtą vietą
    Data = new_Data;
    avail = new_avail;
    limit = Data + new_size;
  }}

template <class T>
  void Vector<T>::grow() {
    // dvigubai daugiau vietos, nei buvo
    size_type new_size = std::max(2 * (limit - Data), ptrdiff_t(1));
    // išskirti naują vietą ir perkopijuoti egzistuojančius elementus
    iterator new_Data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(Data, avail, new_Data);
    // atlaisvinti seną vietą
    uncreate();
    // reset'int rodykles į naujai išskirtą vietą
    Data = new_Data;
    avail = new_avail;
    limit = Data + new_size;
  }
// tariame, kad `avail` point'ina į išskirtą, bet neinicializuotą vietą
template <class T>
  void Vector<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
  }

// priskyrimo operatoriaus realizacija
template <class T>
  Vector<T>& Vector<T>::operator=(const Vector& rhs) {
    // patikriname ar ne lygu
    if (&rhs != this) {
    // atlaisviname seną this objekto atmintį
      uncreate();
      // perkopijuojame elementus iš rhs į lhs (this)
      create(rhs.begin(), rhs.end());
    }
    return *this;
  }

template<class T> class allocator {
  public:
    T* allocate(size_t); // išskirti `raw` atmintį
    void deallocate(T*, size_t); // atlaisvinti atmintį
    void construct(T*, const T&); // sukonstruoti 1 objektą
    void destroy(T*); // sunaikinti 1 objektą
};

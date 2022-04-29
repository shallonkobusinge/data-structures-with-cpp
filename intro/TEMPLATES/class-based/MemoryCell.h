template < class T>


class MemoryCell
{
    public:
      MemoryCell(const T& initVal = T());
      const T& read( ) const;
      void write(const T& x);

    private:
       T storedValue;
};

template < class T>
MemoryCell<T>::MemoryCell(const T& initVal) : storedValue(initVal){}

template < class T>
const T& MemoryCell<T>::read() const {
    return storedValue;
}

template < class T>
void MemoryCell<T>::write(const T& x){
    storedValue = x;
}


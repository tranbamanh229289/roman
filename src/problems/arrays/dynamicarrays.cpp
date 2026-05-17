using namespace std;

template <typename T>
class DynamicArray {
  T* data;
  int cap, size;

  public: 
    DynamicArray(): data(new T[1]), cap(1), size(0) {}
    DynamicArray(int cap): data(new T[cap]), cap(cap), size(0){}
    ~DynamicArray() {delete[] data;}
    T& operator[](int i) {
      return data[i];
    }

    void push_back(T val) {
      if(cap == size) {
        cap *= 2;
          T* tmp = new T[cap];
        for (int i = 0; i < size; i ++) {
          tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
      }
      
      data[size++] = val;
    }
};

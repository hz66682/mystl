#include <iostream>
struct Any {
    
    template<typename T>
    Any(const T& t) : data(new Data<T>(t)) {}
    Any(const Any& A) : data(A.data->clone()) {}
    Any(Any&& A) noexcept {
        data = A.data;
        A.data = nullptr;
    }
    Any& operator=(Any&& A) noexcept {
        if (this->data != nullptr) {
            delete this->data;
        }
        data = A.data;
        A.data = nullptr;
        return *this;
    }
    struct Fa {
        virtual Fa* clone() = 0;
        virtual std::ostream& print(std::ostream& os) = 0;
    };
    template<typename T>
    struct Data : Fa {
        T value;
        virtual Fa* clone() {
            return new Data<T>(value);
        }
        Data(const T& t) : value(t) {}
        virtual std::ostream& print(std::ostream& os) {
            os << value;
            return os;
        }
    };
    Fa* data;
    template<typename T>
    T& get() {
        return ((Data<T>*)data) -> value;
    }
    ~Any() {
        if (data != nullptr) {
            delete data;
        }
    }
};
std::ostream &operator<<(std::ostream &os, const Any& A) {
    A.data->print(os);
    return os;
}

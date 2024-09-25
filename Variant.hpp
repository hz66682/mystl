#include <cstring>
template<typename T>
struct remove_type {
    using type = T;
};
template<typename T>
struct remove_type<T &> {
    using type = T;
};
template<typename T>
struct remove_type<T&&> {
    using type = T;
};
template<typename T1, typename ...T2>
struct Size {
    constexpr static int size = sizeof(T1) > Size<T2...>::size ? sizeof(T1) : Size<T2...>::size;
};
template<typename T>
struct Size<T> {
    constexpr static int size = sizeof(T);
};
template<int id, typename T1, typename ...T2>
struct getType {
    using type = typename getType<id - 1, T2...>::type;
};
template<typename T1, typename ...T2>
struct getType<0, T1, T2...> {
    using type = T1;
};

template<typename T1, typename ...T2>
struct Variant {
    char data[Size<T1, T2...>::size] = {0};
    template<typename T>
    void operator= (const T& t) {
        using rm = typename remove_type<T>::type;
        memset(data, 0, sizeof(rm));
        *reinterpret_cast<T*>(data) = t;
    }
    template<int id>
    auto& get() {
        return *reinterpret_cast<typename getType<id, T1, T2...>::type*>(data);
    }
};

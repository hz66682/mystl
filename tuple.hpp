
template <typename ...T> struct tuple;
template<> struct tuple<> {
    bool equal(const tuple<>& t) {
        return true;
    }
};
template<typename T1, typename ...T2>
struct tuple<T1, T2...> : public tuple<T2...> {
    T1 val;
    using Base = tuple<T2...>;
    tuple() {}
    tuple(T1 v, T2... t) : val(v), Base(t...) {}
    Base& getbase() {
        return *this;
    }
    template<typename ...U>
    bool equal (const tuple<U...>& t) {
        return val == t.getval() && Base::equal(t.getbase());
    }
};
template<int idx, typename T>
struct getTuple {  
    using Type = typename getTuple<idx - 1, typename T::Base>::Type;
};
template<typename T>
struct getTuple<0, T> {
    using Type = T;
};
template<int idx, typename Tuple>
constexpr auto& get(Tuple& t) {
    using Type = typename getTuple<idx, Tuple>::Type;
    return static_cast<Type&>(t).val;
}
template<typename ...T1, typename ...T2>
bool operator==(const tuple<T1...>& t1, const tuple<T2...>& t2) {
    return t1.equal(t2);
}
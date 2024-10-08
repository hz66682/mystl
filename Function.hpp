template <typename Ret, typename... Args>
struct Function;

template<typename Ret, typename... Args>
struct Function<Ret(Args...)> {
    struct Vir {
        virtual Vir* clone() const = 0;
        virtual Ret operator()(Args &&... args) = 0;
        // virtual ~Vir() = default;
    };
    template<typename T>
    struct Impl : Vir {
        T func;
        Impl(const T& f) : func(f) {}
        virtual Vir* clone() const {
            return new Impl<T>(func);
        }
        virtual Ret operator()(Args &&... args) {
            return func(std::forward<Args>(args)...);
        }
    };
    Vir* ptr;
    Function() : ptr{nullptr} {}
    template<typename T>
    Function(T&& t) {
        ptr = new Impl<T>(t);
    }
    Function(const Function &f) {
        ptr = f.ptr->clone();
    }
    Function &operator=(const Function &f) {
        if (ptr) {
            delete ptr;
        }
        ptr = f.ptr->clone();
        return *this;
    }
    Function(Function &&f) {
        ptr = f.ptr;
        if (f.ptr) {
            f.ptr = nullptr;
        }
    }
    Function &operator=(Function &&f) {
        if (ptr) {
            delete ptr;
        }
        ptr = f.ptr;
        if (f.ptr) {
            f.ptr = nullptr;
        }
        return *this;
    }
    Ret operator()(Args... args) {
        return (*ptr)(std::forward<Args>(args)...);
    }
    ~Function() {
        if (ptr) {
            delete ptr;
        }
    }
};
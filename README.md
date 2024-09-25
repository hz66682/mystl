# mystl

## 1. 项目介绍

通过学习网上的c++ STL教程，尝试自己实现一些简单的STL容器

## 2. 项目结构

```
mystl
├── include
│   ├── Tuple.hpp
│   ├── Variant.hpp
│   ├── Any.hpp
└── test
    ├── test_Tuple.cpp
    ├── test_Any.cpp
    ├── test_Variant.cpp    
```

## 还差些什么
### any

看源码似乎使用union实现的，有时间去学一下

### variant

似乎也是用union实现更好一些

没有办法重构析构函数，即在析构variant时调用对应类型的析构函数

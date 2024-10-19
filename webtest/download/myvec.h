#ifndef VEC_H
#define VEC_H

//作为工具使用就默认清楚如何使用，遇到错误就直接跑出错误示例了，不返回false

// 设计思路：
// 1. 实现一个动态数组类Myvec，支持常量下标、修改下标、+=运算符、交换两个Myvec的元素、调整动态数组的大小、获得当前元素容量、获得当前容器的大小、尾部插入元素、尾部插入Myvec、移除第i个元素、等于号的作用、插入元素到第n个位置、查询元素对应下标

// 函数功能表：

// 1. Myvec()：默认构造函数，分配1000个元素的内存空间，长度为0
// 2. Myvec(size_t n)：构造函数，分配n个元素的内存空间，长度为0
// 3. Myvec(const Myvec& other)：拷贝构造函数，拷贝other的元素到当前Myvec
// 4. Myvec(int n, const T& value)：构造函数，分配n个元素的内存空间，长度为n，并将value值赋给每个元素

// 5. ~Myvec()：析构函数，释放内存

// 6. Myvec& operator=(const Myvec& other)：等号重载，赋值运算符，将other的元素赋值给当前Myvec
// 7. const T& operator[](const size_t index) const：常量下标符号，返回第index个元素的值
// 8. T& operator[](const size_t index)：修改下标符号，返回第index个元素的引用
// 9. Myvec& operator+=(const Myvec& other)：+=运算符，将other的元素添加到当前Myvec的尾部

// 10. void swap(Myvec& other)：交换两个Myvec的元素
// 11. void resize(size_t n)：调整动态数组的大小
// 12. size_t length()：获得当前元素容量
// 13. size_t size()：获得当前容器的大小
// 14. void pushback(const T& value)：尾部插入元素
// 15. void pushback(const Myvec& other)：尾部插入Myvec
// 16. void move(size_t index)：移除第i个元素
// 17. T at(const size_t index)：等于号的作用，返回第index个元素的值
// 18. size_t get(const T value)：查询元素对应下标
// 19. void insert(size_t n, const T& value)：插入元素到第n个位置
// 20. void clear()：清空容器
// 21. void pop_back()：移除最后一个元素
// 22. bool empty()：判断容器是否为空
// 23. void reserve(size_t n)：调整容器的容量
// 24. To begin()：返回指向第一个元素的迭代器
// 25. To end()：返回指向最后一个元素的迭代器

// 注意事项：
// 1. 为了防止溢出，Myvec的容量是Myvec_SIZE，默认值为1000，可以通过调整Myvec_SIZE来调整Myvec的容量
// 2. 为了防止内存泄漏，Myvec的析构函数释放了Myvec的内存空间
// 3. 为了方便使用，Myvec的下标从0开始，而不是从1开始
// 4. 为了方便使用，Myvec的元素类型为T_vec，而不是T，T_vec可以是任意类型
// 5. 为了方便使用，Myvec的迭代器类型为To，而不是T_vec*，To可以用来遍历Myvec的元素
// 6. 为了方便使用，Myvec的迭代器的前置++运算符返回To，而不是T_vec*，后置++运算符返回To，而不是void*

namespace myvec{



template <typename T_vec>

class Myvec
{
public:

    class To
    {

    public:
        To() : to(nullptr), My_weizhi(-1) {}
        To(T_vec *to, size_t My_weizhi) : to(to), My_weizhi(My_weizhi) {}

        ~To()
        {
            // 只是一个指向性位置的指针，不需要清掉内存
        }

        To &operator=(const To &other)
        {
            if (this == &other)
            {
                return *this;
            }
            to = other.to;
            My_weizhi = other.My_weizhi;
            return *this;
        }

        To &operator++()
        {
            if (to == nullptr)
            {
                throw std::runtime_error("空指针");
            } // 没有指向时问题出现

            if (My_weizhi < 0)
            {
                throw std::out_of_range("指针越界");
            } // 超出申请内存问题出现

            to++;
            My_weizhi++;
            return *this;
        }

        T_vec &operator*()
        {
            if (to == nullptr)
            {
                throw std::runtime_error("空指针");
            } // 没有指向时问题出现

            if (My_weizhi < 0 )
            {
                throw std::out_of_range("指针越界");
            } // 超出申请内存问题出现

            return *to;
        }

        bool operator==(const To &other)
        {
            return to == other.to && My_weizhi == other.My_weizhi;
        }

        bool operator!=(const To &other)
        {
            return to != other.to || My_weizhi != other.My_weizhi;
        }

        void next(size_t t)
        {
            next_to(t);
        }

    private:

        T_vec *to;
        size_t My_weizhi;

        void next_to(size_t n)
        {
            for (int i = 0; i < n;i++)
            {
                ++*(this);
            }
        }
    };

    // 公有成员变量,设置初始的默认化尺寸
    const size_t Myvec_SIZE = 1000;

    

    // 构造函数部分

    Myvec() : data(new T_vec[Myvec_SIZE]), Vec_size(Myvec_SIZE), Vec_length(0) {} // 纯初始化

    Myvec(size_t n) : data(new T_vec[max(n, Myvec_SIZE)]), Vec_size(max(n, Myvec_SIZE)), Vec_length(0) {} // 设置好内存和长度的初始化

    Myvec(const Myvec &other) : data(new T_vec[other.Vec_size]), Vec_size(other.Vec_size), Vec_length(other.Vec_length)
    {
        for (size_t i = 0; i < other.Vec_length; i++)
        {
            data[i] = other.data[i];
        }
    } // 拷贝构造函数

    Myvec(int n, const T_vec &value) : data(new T_vec[max(n, Vec_size)]), Vec_size(max(n, Myvec_SIZE)), Vec_length(n)
    {
        for (size_t i = 0; i < n; i++)
        {
            data[i] = value;
        }
    } // 多元素初始化输入

    // 析构函数部分
    ~Myvec()
    {
        delete[] data;
    }
    // 重载运算符

    Myvec &operator=(const Myvec &other) // 等号
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] this->data; // 清除原来的数据

        this->data = new T_vec[other.Vec_size]; // 分配新的内存

        this->Vec_size = other.Vec_size;
        this->Vec_length = other.Vec_length;

        for (size_t i = 0; i < other.Vec_length; i++)
        {
            this->data[i] = other.data[i];
        }

        return *this;
    }

    const T_vec &operator[](const size_t index) const // 常量下标符号
    {
        if (index >= Vec_size || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return data[index];
        }
    }

    T_vec &operator[](const size_t index) // 修改下标符号
    {
        if (index >= Vec_size || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            Vec_length = max(Vec_length, index + 1);
            return data[index];
        }
    }

    Myvec &operator+=(const Myvec &other)
    {
        if (Vec_length + other.Vec_length > Vec_size)
        {

            resize(Vec_length + other.Vec_length + Myvec_SIZE);
        }

        for (size_t i = 0; i < other.Vec_length; i++)
        {
            data[Vec_length + i] = other.data[i];
        }

        Vec_length += other.Vec_length;

        return *this;
    }

    // 功能函数部分

    void swap(Myvec &other)
    {
        jiaohuan(other);
    } // 交换两个Myvec的元素

    void resize(size_t n)
    {
        kuorong(n);
    } // 调整动态数组的大小

    size_t length()
    {
        return get_size();
    } // 获得当前元素容量

    size_t size()
    {
        return get_real();
    } // 获得当前容器的大小

    void pushback(const T_vec &value)
    {
        putend(value);
    } // length尾部插入元素

    void pushback(const Myvec &other)
    {
        putendvec(other);
    } // legth尾部插入Myvec

    void move(size_t index)
    {
        shanchu(index);
    } // 移除第i个元素

    T_vec at(const size_t index)
    {
        return huoqu(index);
    }

    T_vec at(To to)
    {
        return huoqu(to);
    }

    size_t get(const T_vec value)
    {
        return dedao(value);
    } // 查询元素对应下标

    void insert(size_t n, const T_vec &value)
    {
        charu(n, value);
    } // 插入元素到第n个位置

    void clear()
    {
        qingchu();
    } // 清空容器

    void pop_back()
    {
        tichu();
    } // 移除最后一个元素

    bool empty()
    {
        return emptym();
    } // 判断容器是否为空

    void reserve(size_t n)
    {
        gairongliang(n);
    } // 调整容器的容量

    To begin()
    {
        return beginvec();
    }

    To end()
    {
        return endvec();
    }

private:
friend class To;
    // 私有成员变量
    T_vec *data;
    size_t Vec_size;
    size_t Vec_length;

    // 私有函数功能部分实现

    template <typename TP>
    TP min(TP a, TP b)
    {
        return a < b ? a : b;
    }

    template <typename TK>
    TK max(TK a, TK b)
    {
        return a > b ? a : b;
    }

    // 交换两个Myvec的元素
    void jiaohuan(Myvec<T_vec> &va)
    {
        Myvec<T_vec> temp;
        temp = va;
        va = *this;
        *this = temp;
    }

    // 调整动态数组的大小
    void kuorong(const size_t n)
    {
        if (n < 0)
        {
            throw std::invalid_argument("Invalid argument");
        }
        else
        {
            T_vec *ndata = new T_vec[n];
            for (size_t i = 0; i < min(n, Vec_length); i++)
            {
                ndata[i] = data[i];
            }
            if (ndata == nullptr) // 内存分配失败
            {
                throw std::bad_alloc();
            }
            delete[] data;
            data = ndata;
            Vec_size = n;
            Vec_length = min(n, Vec_length);
        }
    }
    size_t get_size()
    {
        return Vec_length;
    }
    size_t get_real()
    {
        return Vec_size;
    }
    void putend(const T_vec &value)
    {
        if (Vec_length >= Vec_size)
        {
            kuorong(Vec_length + Myvec_SIZE);

        } // 王海光
        data[Vec_length++] = value;
    }

    void putendvec(const Myvec &other)
    {
        *this += other;
    }

    void shanchu(const size_t index)
    {
        if (index >= Vec_length || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            for (int i = index + 1; i < Vec_length; i++)
            {
                data[i - 1] = data[i];
            }
            Vec_length--;
        }
    }

    void shanchu(To to)
    { // 王海光
        if (to.to == nullptr)
        {
            throw std::runtime_error("空指针");
        }
        else
        {
        size_t index = to.My_weizhi;
        if (index >= Vec_length || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            for (int i = index + 1; i < Vec_length; i++)
            {
                data[i - 1] = data[i];
            }
            Vec_length--;
        }
        }

    }

    T_vec huoqu(const size_t index)
    {
        if (index >= Vec_length || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return data[index];
        }
    }

    T_vec huoqu(To to)
    {
        if (to.to == nullptr)
        {
            throw std::runtime_error("nullptr");
        }
        else
        {
            if (to.My_weizhi < 0 || to.My_weizhi > Vec_size)
            {
                throw std::out_of_range("Index out of range");
            }
            else
            {
                return *to.to;
            }
        }
    }

    To dedao(const T_vec &value)
    { // 王海光
       
        for (size_t i = 0; i < Vec_length; i++)
        {
            if (data[i] == value)
            {
                return  To(data+i,i);
            }
        }
        return -1; // 没找到
    }

    

    To charu(To& to, const T_vec& value)
    {
        size_t n = to.My_weizhi;
        if (to.to == nullptr)
        {
            throw std::runtime_error("空指针");
        }
        if (n < 0 || n >= Vec_length)
        {
            throw std::out_of_range("容器越界");
        }
        else
        {
            if (Vec_length >= Vec_size)
            {
                kuorong(Vec_length + Myvec_SIZE);
            }

            for (size_t i = Vec_length - 1; i >= n; i--)
            {
                data[i + 1] = data[i];
            }
            data[n] = value;
            Vec_length++;
            return To(to.to+1, n+1);
        }
    }

    void qingchu()
    {
        if (Vec_length != 0)
        {
            if (Vec_size > Myvec_SIZE)
                kuorong(Myvec_SIZE); // 防止多余内存占用空间

            Vec_length = 0;
        }
    }

    void tichu()
    {
        if (Vec_length == 0) // 数组空的情况
        {
            throw std::overflow_error("Vector is empty");
        }

        else
        {
            if (Vec_size - Vec_length > 2 * Myvec_SIZE)
            {
                kuorong(Vec_size - Myvec_SIZE); // 减少内存占用空间,避免过度占用空间
            }

            Vec_length--;
        }
    }

    bool emptym()
    {
        return Vec_length == 0;
    }

    void gairongliang(size_t n) // 可以设置预留空间
    {
        if (n < 0)
        {
            throw std::invalid_argument("Invalid argument");
        }
        if (n <= Vec_size)
        {
            Vec_length = n;
        }
        else
        {
            kuorong(n);
        }
    }

    To beginvec()
    {
        To to(data,0);
        return to;
    }

    To endvec()
    {
        if(Vec_size==Vec_length)
        {
            kuorong(Vec_size + Myvec_SIZE);
        }
        To to(data+Vec_length,Vec_length);
        return to;
    }
};
};
#endif
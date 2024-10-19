#ifndef LIST_List_H
#define LIST_List_H

//使用双向链表实现的列表

namespace mylist{
    
   


template<typename T_List>
class MyList {
    public:

    // 自定义节点结构
    struct node
    {
        node *Mylist_pre;
        T_List data;
        node *Mylist_Next;
    };

     //自定义指针结构
     class To{

     public:
        To() : To_List_weizhi(-1), To_where(nullptr) {
        }
        To(size_t weizhi, node* where) : To_List_weizhi(weizhi), To_where(where) {}
        To(const To& other) : To_List_weizhi(other.To_List_weizhi), To_where(other.To_where) {}

        To& operator=(const To& other) {
            if (this == &other) return *this;
            To_List_weizhi = other.To_List_weizhi;
            To_where = other.To_where;
            return *this;
        }
        
        To& operator++()
        {
            if(To_where!=nullptr)
            {
                To_where=To_where->Mylist_Next;
                To_List_weizhi++;
            }
            
            else
            {
                throw std::out_of_range("超出范围");
                return *this;
            }
            return *this;
        }

        T_List& operator*()
        {
            if(To_where!=nullptr)
            {
                return To_where->data;
            }
            else
            {
                throw std::out_of_range("超出范围");
            }
        }

        bool operator==(const To& other) const
        {
            return To_List_weizhi == other.To_List_weizhi && To_where == other.To_where;
        }

        bool operator!=(const To& other) const
        {
            return !(*this == other);
        }

        void next(size_t n)
        {
            set_to(n);
        }



        


    private:
        size_t To_List_weizhi=-1;
        node *To_where;
        friend class MyList;

        void set_to(size_t n) {
            for(size_t i=0;i<n;i++)
            {
                ++(*this);
            }
        }
        


    };

    //构造函数
        MyList() : head{0,0,nullptr,nullptr,0} {
            node* temp = new node;
            if (temp == nullptr) throw std::bad_alloc();
            else
            {
                head.List_First = temp;
                head.List_Last = temp;
                temp->Mylist_pre = nullptr;
                temp->Mylist_Next = nullptr;
                head.size = 0;
                head.length = 0;
            }
        }

        MyList(const size_t n,T_List data) : head{0,0, nullptr, nullptr,0} 
        {//王海光
            node *temp = new node;
            if (temp == nullptr)
                throw std::bad_alloc();
            else
            {
                head.List_First = temp;
                head.List_Last = temp;
                temp->Mylist_pre = nullptr;
                temp->Mylist_Next = nullptr;
                head.size = 0;
                head.length = 0;
            }
            for (size_t i = 0; i < n; i++) 
            {
                jianliyige(head);
            }
            node* tem = head.List_First;

            while(tem!=head.List_Last)
            {
                tem->data=data;
                tem=tem->Mylist_Next;
            }
        }//主动预留空间

        MyList(const MyList& other) : head{0,0,nullptr,nullptr,0} {

            node *temp = new node;
            if (temp == nullptr)
                throw std::bad_alloc();
            else
            {
                head.List_First = temp;
                head.List_Last = temp;
                temp->Mylist_pre = nullptr;
                temp->Mylist_Next = nullptr;
                head.size = 0;
                head.length = 0;
            }

            for (node* p = other.head.List_First; p!=other.head.List_Last; p = p->Mylist_Next) {
                pushback(p->data);
            }
        }




        //析构函数
        ~MyList() {
            node* dangqian = head.List_First;
            while (dangqian) 
            {
                node* shan = dangqian;
                dangqian  = dangqian->Mylist_Next;
                delete shan;
            }
        }

        MyList &operator=(const MyList &other) {
            if (this == &other) return *this;
            clearlist();
            for (node* p = other.head.List_First; p!= other.head.List_Last; p = p->Mylist_Next) {
                pushback(p->data);
            }
            return *this;
        }
        //[]重载
        T_List& operator[](size_t n)
        {
            if(n<head.size)
            {
                node* temp=next_node(head.List_First,n);
                if(temp!=head.List_Last)
                {
                    return temp->data;
                }
                else
                {
                    throw std::out_of_range("超出范围");
                }
            }
            else
            {
                throw std::out_of_range("超出范围");
            }
        }

        
        //功能函数

        void push_back(T_List data)//在尾部推入数据
        {
            pushback(data);
        }
        
        To begin()//返回头节点指针
        {
            return list_begin();
        }//王海光

        To end()//返回尾节点指针
        {
            return list_end();
        }

        T_List at(To to)//读取当前指针数据
        {
            return list_at(to);
        }

        void clear()//清空列表
        {
            clearlist();
        }

        void pop_back()//弹出尾部的数据
        {
            tuidan();
        }

        bool empty()//判断列表是否为空
        {
            return panduan();
        }

        size_t size()//返回列表大小
        {
            return Lsize();
        }

        size_t length()//返回列表长度
        {
            return Llength();
        }

        To insert(To& to,T_List data)
        {
            return insert_list(to,data);
        }

        T_List top()//返回顶部节点数据
        {
            if(!panduan())
            {
                return top_back();
            }
            else
            {
                throw std::out_of_range("空列表");
            }
        }

        T_List front()//返回头部节点数据
        {
            if(!panduan())
            {
                return top_front();
            }
            else
            {
                throw std::out_of_range("空列表");
            }
        }

        To erase(To& to)//删除指定位置节点
        {
            return list_shanchu(to);
        }







    private:
    friend class To;

    //头节点
    struct Head{
        size_t size;
        size_t length;//其实是没必要设计size和length两个变量，只需要一个变量即可，但是为了方便使用者优化性能，还是设计了两个变量
        node* List_First;
        node* List_Last;//2023040093
        int someting;//方便使用者想记录一些其他数据
    };
    //私有数据
    Head head;//唯一性头节点
    
    //功能函数实现

    void jianliyige(Head& h)//在头节点后面插入
    {  if(h){
        node *temp=new node;
        if (temp==nullptr)  throw std::bad_alloc();//无空间可用
        else
        if(h.List_First==h.List_Last)
        {
            temp->prve = nullptr;
            temp->Mylist_Next=h.List_Last;
            h.List_First = temp;
            h.List_Last->Mylist_pre = temp;
        }
        else
        {
            temp->Mylist_Next = h.List_First;
            temp->Mylist_pre = nullptr;
            h.List_First->Mylist_pre = temp;
            h.List_First = temp;

        }
        head.size++;
        head.length++;
        }
    }

    void jianliyige(node* &p)//在某一节点后面插入
    {if(p!=head.List_Last)
    {
        node *temp=new node;
        if (temp==nullptr)  throw std::bad_alloc();//无空间可用
        else
        {//王海光
            if(p!=head.List_Last)
            {
              temp->Mylist_Next = p->Mylist_Next;
              temp->Mylist_pre = p;
              p->Mylist_Next = temp;
              temp->Mylist_Next->Mylist_pre = temp;
               
            }
            else
            {
                throw std::out_of_range("超出范围");
            }
        }
        head.size++;
        head.length++;
    }
    }
    
    node *next_node(node *p,size_t n)//移动指针到想要的位置
    {
        if (n == 0) return p;
        else
        {
            if(p!=head.List_Last)
            {
                for (size_t i = 0; i < n; i++)
                {
                    if (p!= head.List_Last) p = p->Mylist_Next;
                    else return nullptr;
                }
                return p;
            }
            else return nullptr;
        }
    }

    void clearlist()//清空列表
    {
        node* dangqian = head.List_First;
        while (dangqian) 
        {
            node* shan = dangqian;
            dangqian  = dangqian->Mylist_Next;
            delete shan;
        }
        node *temp = new node;
        if (temp == nullptr) throw std::bad_alloc();
        else
        {
            head.List_First = temp;
            head.List_Last = temp;
            temp->Mylist_pre = nullptr;
            temp->Mylist_Next = nullptr;
            head.size = 0;
            head.length = 0;
        }
    
    }
    
    void pushback(T_List data)//在尾部推入数据
    {
        
        
            if(head.length<head.size)
            {
                node *temp = head.List_First;
                temp=next_node(temp,head.length-1);
                if(temp!=nullptr||temp!=head.List_Last)
                temp->data=data;
               else//这一步表示：程序以想不到的方式出错了:(,只能使用特殊的方式进行修补，所以不建议使用预留空间的方式
               {
                   throw std::out_of_range("超出范围");
               }
            }
            else
            {   node* temp = new node;
                if (temp == nullptr) throw std::bad_alloc();
                else
                {
                    temp->data = data;      
                    temp->Mylist_Next = head.List_Last;
                    if (head.List_First!= head.List_Last) 
                    {
                        temp->Mylist_pre = head.List_Last->Mylist_pre;
                        head.List_Last->Mylist_pre->Mylist_Next = temp;
                        head.List_Last->Mylist_pre = temp;

                    }
                    else 
                    {
                    
                    head.List_First = temp;
                    temp->Mylist_pre = nullptr;
                    head.List_Last->Mylist_pre = temp;


                    }
                    head.size++;
                    head.length++;
                }
            }
        
    }
    bool panduan()//判断列表是否为空
    {
        if(head.List_First==head.List_Last||head.size==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
        
    

    void tuidan()//弹出尾部的数据
    {
        if(!panduan())
        {
            if(head.size==1)
            {
                node* temp=head.List_First;
                head.List_First=head.List_Last;
                delete temp;
                head.size--;
                head.length--;
            }
            else
            {
                node *temp = head.List_Last->Mylist_pre;
                temp->Mylist_pre->Mylist_Next = head.List_Last;
                head.List_Last->Mylist_pre = temp->Mylist_pre;
                delete temp;
                head.size--;
                head.length--;
            }
        }
        else
        {
            throw std::out_of_range("空列表");
        }
    }

    T_List list_at(To to)//读取当前指针数据
    {
        if(to.To_List_weizhi<head.size)
        {
            return to.To_where->data;
        }
        else
        {
            throw std::out_of_range("超出范围");
        }
    }

    To list_begin()//返回头节点指针
    {if(!panduan())
        return To(0,head.List_First);
        else
        {
           
            throw std::out_of_range("空列表");
        }
    }

    To list_end()//返回尾节点指针
    {
        if(!panduan())
        return To(head.size,head.List_Last);
        else
        {
           
            throw std::out_of_range("空列表");
        }
    }

    size_t Lsize()//返回列表大小
    {
        return head.size;
    }

    size_t Llength()//返回列表长度
    {
        return head.length;
    }

    // void insert_list(To &to, T_List data)//在指定位置前插入数据
    // {
    //     node *no = to.To_where;
    //     if (no == nullptr||to.To_List_weizhi>head.size) throw std::out_of_range("出界");
    //     else
    //     {       node *temp = new node;
    //             temp->data = data;
    //             if (temp == nullptr) throw std::bad_alloc();
    //             if(no==head.List_First)
    //             {
    //                 temp->Mylist_pre = nullptr;
    //                 temp->Mylist_Next = head.List_First;
    //                 head.List_First->Mylist_pre = temp;
    //                 head.List_First = temp;
    //                 to.To_List_weizhi++;
    //             }
    //             else
    //             {
    //                 temp->Mylist_pre = no->Mylist_pre;
    //                 temp->Mylist_Next = no;
    //                 no->Mylist_pre->Mylist_Next = temp;
    //                 no->Mylist_pre = temp;
    //                 to.To_List_weizhi++;
    //             }
    //             head.size++;
    //             head.length++;
    //     }
            
    // }

    To insert_list(To& to,T_List data)
    {
        node *no = to.To_where;
        if (no == nullptr || to.To_List_weizhi > head.size)
            throw std::out_of_range("出界");
        else
        {
            node *temp = new node;
            temp->data = data;
            if (temp == nullptr)
                throw std::bad_alloc();
            if (no == head.List_First)
            {
                temp->Mylist_pre = nullptr;
                temp->Mylist_Next = head.List_First;
                head.List_First->Mylist_pre = temp;
                head.List_First = temp;
                to.To_List_weizhi++;
            }
            else
            {
                temp->Mylist_pre = no->Mylist_pre;
                temp->Mylist_Next = no;
                no->Mylist_pre->Mylist_Next = temp;
                no->Mylist_pre = temp;
                to.To_List_weizhi++;
            }
            head.size++;
            head.length++;
            return To(to.To_List_weizhi,temp);
        }
    }

    To list_shanchu(To& to)
    {
        if(to.To_List_weizhi>=head.size||to.To_where==nullptr||to.To_where==head.List_Last)
        {
            throw std::out_of_range("出界");
        }
        else
        {
            node* temp=to.To_where;
            node *temp2=temp->Mylist_Next;
            if(temp->Mylist_pre!=nullptr)
            {
                temp->Mylist_pre->Mylist_Next=temp->Mylist_Next;
            }
            else
            {
                head.List_First=temp->Mylist_Next;
            }
            temp->Mylist_Next->Mylist_pre=temp->Mylist_pre;
            to.To_where=temp2;
            delete temp;
            head.size--;
            head.length--;
            return To(to.To_List_weizhi,to.To_where);
        }
    }

    T_List top_back()
    {
        if (!panduan())
        {
            return head.List_Last->Mylist_pre->data;
        }
        else
        {
            throw std::out_of_range("空列表");
            return 0;
        }
    }
    
    T_List top_front()
    {
        if (!panduan())
        {
            return head.List_First->data;
        }
        else
        {
            throw std::out_of_range("空列表");
            return 0;
        }
    }
        
    


};

    
};

#endif // LIST_List_H
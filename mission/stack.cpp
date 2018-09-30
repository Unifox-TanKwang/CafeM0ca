// g++ -o stack stack.cpp -std=c++17

#include <iostream>
#include <cstring>
using namespace std;

template <typename TYPE>
class stack{
public:
        stack(){ m_data = new TYPE[m_max_len]; }
        ~stack() { safe_delete(); }
        void push(TYPE);
        void pop();
        bool empty() const;
        void swap(stack<TYPE>&);
        TYPE top() const;
        inline auto size() const { return m_size; }

//      template <typename Friend>
//      friend ostream& operator<<(ostream& os, const stack<Friend>&);                                          // ostream 객체는 stack<Friend> type에 접근 가능
        //friend ostream& operator<<(ostream& os, const stack<TYPE>&);                                          // can't
private:
        void safe_delete();
        void allocate();
        TYPE * m_data = nullptr;

        // member variable
        size_t m_size= 0;
        size_t m_max_len = 8;
};
/* testcode /////////////////////////////////////////////////////////////////////////////////////////
int main()
{
        stack<int> s1, s2;
        cout << "s1 size: " << s1.size() << endl;
        cout << "s1 empty: " << s1.empty() << endl;

        s1.push(10);
        cout << "s1 top: " << s1.top() << endl;
        cout << "s1 size: " << s1.size() << endl;
        cout << "s1 empty: " << s1.empty() << endl;

        s1.push(20);
        s1.push(30);
        cout << "s1 size: " << s1.size() << endl;
        cout << "s2 size: " << s2.size() << endl;


        cout << "s1 s2 swap" << endl;


        s1.swap(s2);

        cout << "s1 size: " << s1.size() << endl;
        cout << "s2 size: " << s2.size() << endl;
        cout << "s2 empty: " << s2.empty() << endl;

        s2.push(50);
        cout << "s2 top: " << s2.top() << endl;
        cout << "s2 size: " << s2.size() << endl;
        cout << "s1 size: " << s1.size() << endl;


        cout << "---s1---" << endl;
        while(!s1.empty()){
                cout << s1.top() << endl;
                s1.pop();
        }
        cout << "---s2---" << endl;
        while(!s2.empty()){
                cout << s2.top() << endl;
                s2.pop();
        }


        for(int i = 0; i < 31; i++){
                s2.push(i);
        }

        cout << "---s2---" << endl;
        while(!s2.empty()){
                cout << s2.top() << endl;
                s2.pop();
        }


        return 0;
}
/////////////////////////////////////////////////////////////////////////////////////// */
template <typename TYPE>
void stack<TYPE>::push(TYPE data) {
        if(m_size == m_max_len){
                allocate();
                cout << size() << ", maxlen: " << m_max_len << endl;
        }
        m_data[m_size++] = data;
}

template <typename TYPE>
void stack<TYPE>::pop(){
        if(m_size > 0){
                if(m_size < m_max_len / 2){
                        allocate();
                        cout << m_size << ", maxlen: " << m_max_len << endl;
                }
                --m_size;
        }
}

template <typename TYPE>
bool stack<TYPE>::empty() const{
        if(size() == 0) return true;
        else                    return false;
}

template <typename TYPE>
TYPE stack<TYPE>::top() const{
        try{
                return m_data[m_size-1];
        }
        catch(exception& e){
                cerr << "Error: " << e.what() << endl;
        }
}

template <typename TYPE>
void stack<TYPE>::swap(stack<TYPE>& s){
        /*
        cout << "rhs addr" << hex << s.m_data << endl;
        cout << "lhs addr" << m_data << endl;
        */

        TYPE *temp_data = s.m_data;
        s.m_data = m_data;
        m_data = temp_data;

        /*
        cout << "rhs addr" << s.m_data << endl;
        cout << "lhs addr" << m_data << dec << endl;
        */

        auto temp_mml = s.m_max_len;
        s.m_max_len = m_max_len;
        m_max_len = temp_mml;

        auto temp_size = s.m_size;
        s.m_size = m_size;
        m_size = temp_size;

}

template <typename TYPE>
void stack<TYPE>::safe_delete() {
        if(m_data != nullptr){
                delete []m_data;
                m_data = nullptr;
        }
}

template <typename TYPE>
void stack<TYPE>::allocate(){
        TYPE *temp = nullptr;
        if(m_size *2 < m_max_len) {
                m_max_len /= 2;
                cout << "mml : " << m_max_len << ", size: " << m_size << endl;
                temp = new TYPE[m_max_len];
        }
        else {
                m_max_len *= 2;
                cout << "mml : " << m_max_len << ", size: " << m_size << endl;
                temp = new TYPE[m_max_len];
        }
        memcpy(temp, m_data, sizeof(&m_data[0]) * m_size);
        cout << "copy" << endl;
        for(int i = 0; i < m_size;i++){
                cout << temp[i] << endl;
        }

        cout << "temp addr : " << hex << temp << endl;
        cout << "original addr : " << m_data << dec <<endl;
        safe_delete();
        m_data = temp;
        temp = nullptr;
}

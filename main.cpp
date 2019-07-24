#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <list>
#include <list>
#include <list>
#include <list>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <valarray>
#include <hash_set>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <forward_list>

#include <type_traits>

template <class T>
void swap(T& a, T& b)
{
    static_assert(std::is_copy_constructible<T>::value,
                  "Swap requires copying");
    static_assert(std::is_nothrow_move_constructible<T>::value
                  && std::is_nothrow_move_assignable<T>::value,
                  "Swap may throw");
    auto c = b;
    b = a;
    a = c;
}

using namespace std;
typedef std::unordered_map<std::string, std::string> stringmap;

enum {
    BIG_CONTAINER_SIZE = 80000,
    SMALL_CONTAINER_SIZE = 8
};

struct simple {

    simple(int id, const char *name) : id(id), name(name) {
    }

    int id;
    char const *name;
};

struct S {

    S() {
        Init();

        int a = 5;
    }

    void Init() {
        for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
            qSimple.push(simple(i, "May"));

            for (int j = 0; j < 2; ++j) {
                map<int, simple> m;
                m.insert(make_pair(i+j, simple(i, "May")));
                vmSimple.push_back(m);
            }
        }
    }

    queue<simple> qSimple;
    vector<map<int, simple>> vmSimple;
};

class A {

public:
    void Init() {
        for (int i = 0; i < 3; ++i)
            listS.push_back(S());
    }

    A() {
        Init();

        int a = 5;
    }


private:
    list<S> listS;
};


struct Foo
{
    Foo()      { std::cout << "Foo::Foo\n";  }
    ~Foo()     { std::cout << "Foo::~Foo\n"; }
    void bar() { std::cout << "Foo::bar\n";  }
};

void f(const Foo &)
{
    std::cout << "f(const Foo&)\n";
}

int main() {

    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);

    std::string str_dec = "2001, A Space Odyssey";
    std::string str_hex = "40c3";

    const char cdata[4] = {0x0055, 0x006e, (const char) 0x10e3, (const char) 0x03a3};
    string string1(cdata);

    std::vector<std::string> vStr;
    vStr.push_back("a");

    std::deque<std::string> dStr;
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        dStr.push_back("b");
    }

    std::queue<std::string> qStr;
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        qStr.push("c");
    }

    std::list<std::string> lStr;
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        lStr.push_back("d");
    }


    std::set<std::string> sStr;
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        sStr.insert("e");

    }

    std::bitset<SMALL_CONTAINER_SIZE> bsStr;
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        bsStr[i] = "f";
    }

    std::map<std::string, std::pair<std::string, std::string> > mStr;
    {
        mStr.insert(mStr.end(), std::make_pair("1", std::pair<std::string, std::string>("key1", "val1")));
        mStr.insert(mStr.end(), std::make_pair("2", std::pair<std::string, std::string>("key2", "val2")));
        mStr.insert(mStr.end(), std::make_pair("3", std::pair<std::string, std::string>("key3", "val3")));
        mStr.insert(mStr.end(), std::make_pair("4", std::pair<std::string, std::string>("key4", "val4")));
        mStr.insert(mStr.end(), std::make_pair("5", std::pair<std::string, std::string>("key5", "val5")));
    }

    for (std::map<std::string, std::pair<std::string, std::string>>::iterator it=mStr.begin(); it!=mStr.end(); ++it)
        std::cout << it->first << " : " << it->second.first << " " << it->second.second << '\n';

    std::map<char,int> mymap;
    {
        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;
    }

    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
        char itfirst = it->first;
        int itsecond = it->second;
        std::cout << it->first << " => " << it->second << '\n';
    }

    {
/*        std::unique_ptr<Foo> pFoo1(new Foo);  // p1 owns Foo
        if (pFoo1) pFoo1->bar();


            std::unique_ptr<Foo> pFoo2(std::move(pFoo1));  // now p2 owns Foo

        if (pFoo2) pFoo2->bar();*/

    }

    std::valarray<std::string> valStr("h", 4);

    std::string mystrs[] = {"i", "j", "k", "l"};

    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > pqStr(mystrs, mystrs + 4);
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        pqStr.push("i");
    }

    std::unordered_set<std::string> usStr({"m", "n", "o", "p"});
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        usStr.insert("m");
    }

    std::unordered_map<std::string, std::string> umStr({{"q", "r"},
                                                        {"s", "t"}});
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        umStr.insert({"o", "o"});
    }

    std::forward_list<std::string> flStr = {"u", "v"};
    for (int i = 0; i < SMALL_CONTAINER_SIZE; ++i) {
        flStr.push_front("u");
    }

    std::array<std::string, 2> aStr = {"w", "x"};

    A a1;
    A arrBig[BIG_CONTAINER_SIZE];

    int data[10000];
    for (int i = 0; i < 100; i += 2) {
        data[i] = i; // set breakpoint here
//        arrBig[i] = A(); // set breakpoint here
    }

    cout << "Hello, World!" <<  endl;

    return 0;
};
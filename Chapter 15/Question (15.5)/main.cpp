#include <iostream>
#include <string>

template<typename T,typename U,typename V>
class Triad{

private:
    T m_x{};
    U m_y{};
    V m_z{};
public:
    Triad(const T x,const U y,const V z)
        :m_x{x},m_y{y},m_z{z}
        {
        }

     T& x() { return m_x; }
	 U& y() { return m_y; }
	 V& z() { return m_z; }

	 void print();
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print(){

        std::cout << '[' << m_x << ", " << m_y << ", " << m_z << ']';
    }

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.x() << '\n';

	using namespace std::literals::string_literals;
    Triad<int, double, std::string> t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}

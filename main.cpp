#include <iostream>
using namespace std;

struct Box
{
private:
    int* _width;
    int* _length;
    int* _x;
    int* _y;
public:
    Box()
    {
        _width = nullptr;
        _length = nullptr;
        _x = nullptr;
        _y = nullptr;
    }

    Box(int width) : Box()
    {
        setWidth(width);
    }
    Box(int width, int length) : Box(width)
    {
        setLength(length);
    }
    Box(int width, int length, int x) : Box(width, length)
    {
        setX(x);
    }
    Box(int width, int length, int x, int y) : Box(width, length, x)
    {
        setY(y);
    }

    ~Box()
    {
        std::cout << "Box destroyed" << std::endl;
        deallocateWidth();
        deallocateLength();
        deallocateX();
        deallocateY();
    }

    //Deallocate

    void deallocateWidth()
    {
        if (_width != nullptr)
        {
            delete _width;
            _width = nullptr;
        }
    }

    void deallocateLength() {

        if (_length != nullptr)
        {
            delete _length;
            _length = nullptr;
        }
    }

    void deallocateX() {

        if (_x != nullptr)
        {
            delete _x;
            _x = nullptr;
        }
    }

    void deallocateY() {

        if (_y != nullptr)
        {
            delete _y;
            _y = nullptr;
        }
    }

    //Getters
    int getWidth() { return  (_width == nullptr) ? 0 : *_width; }
    int getLength() { return (_length == nullptr) ? 0 : *_length; }
    int getX() { return (_x == nullptr) ? 0 : *_x; }
    int getY() { return (_y == nullptr) ? 0 : *_y; }

    //Setters

    void setWidth(int width) {
        deallocateWidth();
        _width = new int{ (width > 0) ? width : 1 };
    }
    void setLength(int length) {
        deallocateLength();
        _length = new int{ (length > 0) ? length : 1 };
    }
    void setX(int x) {
        deallocateX();
        _x = new int{ (x > 0) ? x : 0 };
    }
    void setY(int y) {
        deallocateY();
        _y = new int{ (y > 0) ? y : 0 };
    }
};

void deplace_restagle(Box& box, int x, int y) {
    box.setX(x);
    box.setY(y);
}

void resize_restagle(Box& box, int length, int width) {
    box.setLength(length);
    box.setWidth(width);
}

void print_restagle(Box& box, int x, int y, int length, int width) {
    for (int i = 0; i < y; i++)//move y(down)
    {
        cout << endl;
    }

    for (int i = 0; i < width; i++)
    {
        for (int i_x = 0; i_x < x; i_x++)
        {
            cout << " ";//space to show x move
        }
        for (int j = 0; j < length; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{

    Box* box = new Box(3, 5, 2, 0);
    std::cout << "Width: " << box->getWidth() << std::endl;
    std::cout << "Length: " << box->getLength() << std::endl;
    std::cout << "X: " << box->getX() << std::endl;
    std::cout << "Y: " << box->getY() << std::endl;

    cout << "Your start restagle: " << endl;
    print_restagle(*box, box->getX(), box->getY(), box->getLength(), box->getWidth());

    int x;
    cout << "Enter x: ";
    cin >> x;

    int y;
    cout << "Enter y: ";
    cin >> y;

    deplace_restagle(*box, x, y);

    int length;
    cout << "Enter length: ";
    cin >> length;

    int width;
    cout << "Enter width: ";
    cin >> width;

    resize_restagle(*box, length, width);

    cout << "Your new restagle: " << endl;
    print_restagle(*box, x, y, length, width);

    delete box; // call destructor
    cout << "End of program" << endl;


    return 0;
}
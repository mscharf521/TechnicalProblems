//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    int l,b,h;
public:
    Box()
    {
        l = b = h = 0;
    }
    Box(int p_l, int p_b, int p_h)
    {
        l = p_l;
        b = p_b;
        h = p_h;
    }
    Box(Box &p_b)
    {
        l = p_b.l;
        b = p_b.b;
        h = p_b.h;
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight ()
    {
        return h;
    }
    long long CalculateVolume()
    {
        return static_cast<long long>(l) 
             * static_cast<long long>(b)
             * static_cast<long long>(h);
    }
    bool operator<(Box& b_box)
    {
        if( ( l < b_box.l                                 )
         || ( b < b_box.b && l == b_box.l                 )
         || ( h < b_box.h && b == b_box.b && l == b_box.l ) )
        {
            return true;   
        }
        return false;
    }
    friend ostream& operator<<(ostream& out, Box& B)
    {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};
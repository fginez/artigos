#include <memory>
#include <iostream>

using namespace std;

typedef struct DATA{
    unsigned long lNum;
    unsigned char fieldA[30];
    bool bFlag;

    ~DATA(){
        cout << "DATA destruction" << endl;
    }
} DATA, *PDATA;

ostream& operator<<(ostream& os, const DATA& d){
    os << "DATA contents:" << endl;
    os << "\t" << "lNum=" << d.lNum << endl;
    os << "\t" << "fieldA=" << (int) d.fieldA[0] << (int) d.fieldA[1] << "..." << (int) d.fieldA[28] << (int) d.fieldA[29] << endl;
    os << "\t" << "bFlag=" << d.bFlag << endl;
    return os;
}

int main(int argc, char* argv[])
{
    const int excessiveLen=100;
    cout << "Alloc mem 4 DATA" << endl;
    unique_ptr<DATA> p = make_unique<DATA>();
    unique_ptr<unsigned char[]> q = make_unique<unsigned char[]>(excessiveLen);

    p.get()->lNum=9;
    fill(p.get()->fieldA, p.get()->fieldA + sizeof(DATA::fieldA), 0xFF);

    PDATA r = reinterpret_cast<PDATA>( q.get() );
    r->bFlag = true;
    r->lNum=10;

    cout << *p << endl;
    cout << *r << endl;

    cout << "This is the end" << endl;
    return 0;
}

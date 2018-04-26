#include <iostream>

using namespace std;
class Matrix
{
private:
        int aMas [3][3];
 
public:
        Matrix(){}
        void Vvod();
        void Vivod();
    Matrix operator+ (const Matrix&);
    Matrix operator- (const Matrix&);
};
 
void Matrix::Vvod() 
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> aMas[i][j];
        }
    }
}
 
void Matrix::Vivod() 
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << aMas[i][j] << " ";
        }
        cout << endl;
    }
}
 
Matrix Matrix::operator+(const Matrix &rhs)
{
    Matrix result(*this);
      for (size_t i = 0; i < 3; ++i)
      {
        for (size_t j = 0; j < 3; ++j)
        {
            result.aMas[i][j] += rhs.aMas[i][j];
        }
      }
    return result;
}
 
Matrix Matrix::operator-(const Matrix &rhs)
{
    Matrix result(*this);
 
    for (size_t i = 0; i < 3; ++i)
     {
        for (size_t j = 0; j < 3; ++j)
            result.aMas[i][j] -= rhs.aMas[i][j];
     }
 
    return result;
}
 
int main()
{
    Matrix m, m2;
    cout << "Vvod: \n";
    m.Vvod();
    cout << "Vivod: \n";
    m.Vivod();
    cout << "Vvod: \n";
    m2.Vvod();
    cout << "Vivod: \n";
    m2.Vivod();
    m2 = m2 + m;
    cout << "Vivod: resulta\n";
    m2.Vivod();
}
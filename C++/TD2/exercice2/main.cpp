#include "matrixNumerical.h"

int main(int argc, char const *argv[])
{
    MatrixNumerical<double> mat1(3, 3);
    mat1.addElement(0, 0, 1); mat1.addElement(0, 1, 2); mat1.addElement(0, 2, 3);
    mat1.addElement(1, 0, 0); mat1.addElement(1, 1, 1); mat1.addElement(1, 2, 4);
    mat1.addElement(2, 0, 5); mat1.addElement(2, 1, 6); mat1.addElement(2, 2, 0);
    
    std::cout << "Matrice 1:" << std::endl;
    mat1.display();
    
    std::cout << "\nDeterminant: " << mat1.getDeterminant() << std::endl;
    
    MatrixNumerical<double> identity = MatrixNumerical<double>::getIdentity(3);
    std::cout << "\nMatrice Identite:" << std::endl;
    identity.display();
    
    MatrixNumerical<double> mat2(3, 3, 1.0);
    std::cout << "\nMatrice 2:" << std::endl;
    mat2.display();
    
    MatrixNumerical<double> sum = mat1 + mat2;
    std::cout << "\nMat1 + Mat2:" << std::endl;
    sum.display();
    
    MatrixNumerical<double> product = mat1 * identity;
    std::cout << "\nMat1 * Identity:" << std::endl;
    product.display();
    
    return 0;
}

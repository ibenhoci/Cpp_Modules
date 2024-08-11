# include "Array.hpp"
# include "Array.cpp"

int main() {
    try {
        Array<int> iArr;
        std::cout << "Size of the array: " << iArr.getN() << std::endl;
        std::cout << "Ptr address of the array: " << iArr.getTab() << std::endl;
        std::cout << std::endl;


        Array<double> dArr(5);
        std::cout << "Size of the array: " << dArr.getN() << std::endl;
        std::cout << "Ptr address of the array: " << dArr.getTab() << std::endl;
        std::cout << std::endl;
        
        Array<double> dArrCopy;
        dArrCopy = dArr;
        std::cout << std::endl;
        
        try {
            dArrCopy[6] = 42.0; // This should throw an BadIndex exception
        } catch (const Array<double>::BadIndex& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        std::cout << std::endl;
        Array<double> dArrCopy2(dArrCopy);
        
        std::cout << std::endl;
        std::cout << "Size of doubleArrayCopy: " << dArrCopy.getN() << std::endl;
        std::cout << "Ptr address of the array: " << dArrCopy.getTab() << std::endl;
        std::cout << "Size of doubleArrayCopy2: " << dArrCopy2.getN() << std::endl;
        std::cout << "Ptr address of the array: " << dArrCopy2.getTab() << std::endl;


    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
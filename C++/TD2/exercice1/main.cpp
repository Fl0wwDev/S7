#include <iostream>
#include <vector>
#include "linearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main(int argc, char const *argv[])
{
    // Vecteur trié pour les tests
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int target = 13;
    
    std::cout << "=== Test Linear Search ===" << std::endl;
    LinearSearch ls;
    int result1 = ls.search(data, target);
    ls.displaySearchResults(std::cout, result1, target);
    
    std::cout << "\n=== Test Jump Search ===" << std::endl;
    JumpSearch js;
    int result2 = js.search(data, target);
    js.displaySearchResults(std::cout, result2, target);
    
    std::cout << "\n=== Test Binary Search ===" << std::endl;
    BinarySearch bs;
    int result3 = bs.search(data, target);
    bs.displaySearchResults(std::cout, result3, target);
    
    // Test avec élément non présent
    std::cout << "\n=== Test avec élément non trouvé ===" << std::endl;
    int result4 = ls.search(data, 100);
    ls.displaySearchResults(std::cout, result4, 100);
    
    return 0;
}

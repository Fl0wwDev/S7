#include "searchingAlgorithm.h"

// Initialisation des variables statiques
int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
int SearchingAlgorithm::averageComparisons = 0;

void SearchingAlgorithm::displaySearchResults(std::ostream &os, int results, int target) {
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    if (results != -1) {
        os << "Element " << target << " trouvé à l'indice " << results << std::endl;
        os << "Nombre de comparaisons: " << numberComparisons << std::endl;
    } else {
        os << "Element " << target << " non trouvé" << std::endl;
        os << "Nombre de comparaisons: " << numberComparisons << std::endl;
    }

    os << "Total de comparaisons: " << totalComparisons << std::endl;
    os << "Nombre total de recherches: " << totalSearch << std::endl;
    os << "Moyenne de comparaisons: " << averageComparisons << std::endl;
}
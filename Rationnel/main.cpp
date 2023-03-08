#include <iostream> // cin, cout et endl
#include <iomanip> // setw()
#include <conio.h> // _getch()
#include "Rationnel.h"
// Fonction d'affichage de fraction.
// Param�tres:
// chaine : �tiquette � afficher avant la fraction
// r : fraction � afficher
void afficherRationnel(const char* chaine, Rationnel& r) {
	std::cout << chaine << '\t';
	r.affichageFraction();
	std::cout << ", \t";
	r.affichageFlottant();
	std::cout << std::endl;
}
// Programme principal : teste la classe Rationnel
int main(int argc, char* argv[]) {
	Rationnel r1, // devrait �tre 1/1
		r2(2), // devrait �tre 2/1
		r3(6, 9), // devrait �tre 2/3
		r4(3, -5); // devrait �tre -3/5 (signe toujours �tre attribu� au num�rateur)
	// Afficher les instances pour validation
	afficherRationnel("r1 = ", r1); // devrait afficher 1/1, 1
	afficherRationnel("r2 = ", r2); // devrait afficher 2/1, 2
	afficherRationnel("r3 = ", r3); // devrait afficher 2/3, 0.666667
	afficherRationnel("r4 = ", r4); // devrait afficher -3/5, -0.6
	// Tester l'addition de r2 � r4, puis afficher le r�sultat pour validation
	r4.additionner(r2);
	afficherRationnel("\nr4 = r4 + r2 >>> r4 = ", r4); // devrait afficher 7/5, 1.4
	// Tester la soustraction de r3 � r4, puis afficher le r�sultat pour validation
	r4.soustraire(r3);
	afficherRationnel("r4 = r4 - r3 >>> r4 = ", r4); // devrait afficher 11/15, 0.733333
	// Tester la division de r4 � r3, puis afficher le r�sultat pour validation
	r4.diviser(r3);
	afficherRationnel("r4 = r4 / r3 >>> r4 = ", r4); // devrait afficher 11/10, 1.1
	// Tester la multiplication de r2 � r4, puis afficher le r�sultat pour validation
	r4.multiplier(r2);
	afficherRationnel("r4 = r4 * r2 >>> r4 = ", r4); // devrait afficher 11/5, 2.2
	// Attendre confirmation pour fermer la console
	std::cout << "\n\nPressez une touche pour terminer..." << std::endl;
	_getch();
	return 0;
}
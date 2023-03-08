#include "Rationnel.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Constructeur
Rationnel::Rationnel(int numerateur, int denominateur) :
    m_numerateur(numerateur),
    m_denominateur(denominateur)
{
    reduire(); // Réduire la fraction à sa plus simple expression
}

// Réduction de fraction
void Rationnel::reduire()
{
    if (m_denominateur == 0) {
        std::cout << "Erreur : division par zéro." << std::endl;
        return;
    }
    if (m_denominateur < 0) { // On s'assure que le signe est au numérateur
        m_numerateur *= -1;
        m_denominateur *= -1;
    }
    int diviseur = pgcd(abs(m_numerateur), m_denominateur);
    m_numerateur /= diviseur;
    m_denominateur /= diviseur;
}

// Plus grand diviseur commun
int Rationnel::pgcd(int a, int b)
{
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Addition de fractions
void Rationnel::additionner(const Rationnel& r)
{
    m_numerateur = m_numerateur * r.m_denominateur + m_denominateur * r.m_numerateur;
    m_denominateur *= r.m_denominateur;
    reduire();
}

// Soustraction de fractions
void Rationnel::soustraire(const Rationnel& r)
{
    m_numerateur = m_numerateur * r.m_denominateur - m_denominateur * r.m_numerateur;
    m_denominateur *= r.m_denominateur;
    reduire();
}

// Multiplication de fractions
void Rationnel::multiplier(const Rationnel& r)
{
    m_numerateur *= r.m_numerateur;
    m_denominateur *= r.m_denominateur;
    reduire();
}

// Division de fractions
void Rationnel::diviser(const Rationnel& r)
{
    if (r.m_numerateur == 0) {
        std::cout << "Erreur : division par zéro." << std::endl;
        return;
    }
    m_numerateur *= r.m_denominateur;
    m_denominateur *= r.m_numerateur;

}

// Affichage de fraction
void Rationnel::affichageFraction() const
{
    std::cout << m_numerateur << '/' << m_denominateur;
}

// Affichage en flottant
void Rationnel::affichageFlottant() const
{
    double resultat = static_cast<double>(m_numerateur) / static_cast<double>(m_denominateur);
    std::cout << std::fixed << std::setprecision(6) << resultat;
}




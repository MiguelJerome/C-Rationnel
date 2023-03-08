#pragma once
class Rationnel {
public:
    Rationnel(int numerateur = 1, int denominateur = 1); // Constructeur
    void additionner(const Rationnel& r); // Addition
    void soustraire(const Rationnel& r); // Soustraction
    void multiplier(const Rationnel& r); // Multiplication
    void diviser(const Rationnel& r); // Division
    void affichageFraction() const; // Affichage fraction
    void affichageFlottant() const; // Affichage flottant

private:
    void reduire(); // Réduction
    int pgcd(int a, int b); // PGCD
    int m_numerateur;
    int m_denominateur;
};
# Rtti-Cpp
## Description
Ce projet à pour but d'implementer un equivalent au RTTI (https://en.wikibooks.org/wiki/C%2B%2B_Programming/RTTI) en essayant d'être le plus proche possible de ce qui devrait être produit par le compilateur (chaine de caractère auto générée, tableau de rtti).

Il y a 2 types d'information différent :
 - Les Types Fondamentales (TypeInfo_t)
 - Les Classes (ClassInfo_t)

Les types fondamentales fournissent comme information :
 - Les operateurs
 - Les conversions
 - Les conversions exterieures
 - Le nom

Les Classes sont des améliorations des Types fondamentales et fournissent en plus :
 - les fonctions membres

## Regle
Le .h contient seulement le prototype / define / alias, l'implementation se trouve dans le .hpp (qui peut inclure les .tpp ou .inl).

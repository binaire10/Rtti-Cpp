# Rtti-Cpp
## Description
C'est un projet qui à pour but d'essayer d'implementer un equivalent au RTTI (https://en.wikibooks.org/wiki/C%2B%2B_Programming/RTTI) en essayant d'être le plus proche de ce qui devrait être produit par le compilateur (chaine de caractére auto généré, tableau de rtti).

Il 3 types d'information différent :
 - Les Types Fondamentales (TypeInfo_t)
 - Les Classes (ClassInfo_t)

Les types fondamentales fournisse comme information :
 - les operateurs
 - les conversions
 - les conversions exterieurs
 - le nom

Les Classes sont des améliorations des Types fondamentales et fournisse en plus :
 - les fonctions membres
## Regle
Le .h contient seulement le prototype / define / alias, l'implementation elle ce trouve dans le .hpp (qui peut inclure les .tpp ou .inl).

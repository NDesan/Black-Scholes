# Équation de Black et Scholes

**Projet PAP - ENSIIE S3**  
**David Mielle, Nicolas Desan**  
**Décembre 2022**

---

## Table des matières
1. [Introduction](#introduction)
2. [Modèles mathématiques](#modèles-mathématiques)
    - [Discrétisation de l'espace-temps](#discrétisation-de-lespace-temps)
    - [Discrétisation de l'équation](#discrétisation-de-léquation)
3. [Implémentation](#implémentation)
    - [Structure du code](#structure-du-code)
    - [Classes principales](#classes-principales)

---

## Introduction

Ce projet implémente une résolution numérique de l'équation de Black et Scholes, utilisée dans la finance pour modéliser la variation des prix des options. Trois méthodes numériques sont implémentées : le schéma explicite, implicite et Crank-Nicholson.

---

## Modèles mathématiques

### Discrétisation de l'espace-temps
- **Temps :** L'intervalle \[0; T\] est divisé en M points, avec un pas de temps Δt = T/M.
- **Espace :** L'intervalle spatial \[0; L\] est divisé en N points, avec un pas d'espace Δs = L/N.

### Discrétisation de l'équation
- **Schéma explicite :** Approche centrée en temps et espace pour une solution directe.
- **Schéma implicite :** Approche rétrograde pour une meilleure stabilité.
- **Crank-Nicholson :** Moyenne des méthodes explicite et implicite pour combiner précision et stabilité.

---

## Implémentation

### Structure du code
Le code est organisé en plusieurs modules pour gérer les matrices, les conditions initiales et les calculs des schémas numériques.

### Classes principales
1. **`Matrix` :** Manipule les matrices utilisées pour résoudre les équations.
2. **`BlackScholes` :** Classe abstraite pour les calculs liés aux méthodes numériques.
3. **`Payoff` :** Définit les conditions terminales pour les options de type `Call` ou `Put`.




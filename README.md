## 🐜 Projet Fourmilière - README

### 🎯 **Problématique**

Ce projet avait pour objectif de simuler une fourmilière en C++, modélisée par une structure de données dynamique. Il s'agissait d'un travail en groupe, avec comme but final de représenter le déplacement de fourmis à travers une structure de type graphe, chaque cellule étant un nœud, et chaque passage possible un arc.

---

### 🧩 **Analyse du problème**

Nous devions :

* Créer une structure de données capable de représenter la fourmilière
* Simuler le déplacement d'agents (les fourmis) à travers cette structure
* Penser à l’avenir à une stratégie de parcours (DFS, BFS, etc.)
* Travailler à plusieurs sur la conception, l’implémentation et la réflexion

---

### 🔧 **Travail réalisé**

#### Structure de données mise en place :

* Liste doublement chaînée représentant les cellules
* Déplacements de la fourmi simulés via des fonctions `allerAuDebut`, `allerSuivant`, etc.
* Ajout de nouvelles idées :

  * Capacité de la cellule (`taille`)
  * Liste des fourmis présentes (`vector<Cellule*>`)
  * Pointeur `suiv2` pour former un arbre binaire / graphe

#### Organisation :

* Le projet a été principalement abordé sur la deuxième semaine
* La première semaine a surtout été consacrée à la compréhension et à la théorie
* Le code produit aujourd’hui est solide en termes de base structurelle, prêt à accueillir les algorithmes de déplacement

---

### 🤝 **Travail en groupe**

Ce projet a révélé des difficultés dans l'organisation collective :

* Une collègue, prise par d'autres examens, a été très peu disponible.
* Un autre membre de l'équipe avance à un rythme beaucoup plus lent, ce qui a rendu la répartition des tâches techniques (pointeurs, dynamique, etc.) délicate.
* En pratique, une grande partie du travail de conception et d’implémentation a été menée de façon individuelle, dans l’esprit de faire progresser tout le groupe.

---

### 📚 **Ce que j’ai appris**

* Manipulation avancée des pointeurs et des structures chaînées
* Début de réflexion sur la transformation d’une liste en graphe/arbre
* Gestion de la mémoire dynamique
* Approche itérative : poser les bases avant d’implémenter l’algorithme
* Organisation et réalités du travail de groupe dans un cadre technique

---

### 📉 **Limites**

* Pas d’algorithme de déplacement implémenté
* Une seule fourmi simulée pour l’instant
* La dynamique de groupe a ralenti fortement la progression prévue
* Le travail a démarré trop tard (semaine 2), limitant la portée finale

---

### ✅ **Conclusion**

Le projet n’est pas terminé, mais il représente un socle très solide pour une poursuite post-rendu. Toutes les structures nécessaires sont prêtes pour implémenter les logiques de parcours et de gestion de plusieurs fourmis. Malgré une gestion de temps et d'équipe compliquée, ce projet a permis **une montée en compétence réelle**, surtout en ce qui concerne la manipulation bas-niveau en C++.

La suite du projet reste ouverte — et prometteuse.

---

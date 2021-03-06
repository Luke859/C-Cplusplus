---
marp: false
---

# **C and C++**

## Apprendre le C et le C++ :) 

---
&nbsp;

1- Les commandes pour compiler le programme -> 
>`g++ hello.cpp -o hello && ./hello`

- <span style="color: lightblue"> **hello.cpp** </span> ->  le nom du fichier

- Le <span style="color: lightblue"> **-o** </span> -> désigne le fichier de sortie ou output 

2- Ensuite -> 
>``./hello Luke``

- On ajoute le mot ici c'est <span style="color: lightblue"> **Luke** </span> <- argument 
- Apres le <span style="color: lightblue"> **./hello** </span>` <- le nom du fichier

&nbsp;

---
## Le code 
---
&nbsp;

Code -> <span style="color: pink"> hello.cpp </span>

```
#include <iostream>

int main(int argc, char** argv){
    std::cout << "Hello, " << argv[1] << "!" << std::endl;
    return 0;
}
```

Description du code : 
  
- ``#include <iostream>`` est un compilateur, ici on va lui demander d'utiliser du code externe grâce à des directives de pré-processeur.

**Ex:** en GO on utilise des packages, le compilateur est le package mais en C.

- ``#include`` va inclure le fichier demander qui est ici ``<iostream>`` 

&nbsp;

<span style="color: orangered"> Liste des compilateurs (packages) que l'on peut utiliser [listes](https://www.cplusplus.com/reference/) </span>.

&nbsp;

Grâce à cette **bibliothèque standard** (``<iostream>``) qui contient des fonctionnalités, on peut **afficher du texte dans la console** en C++.

&nbsp;

Voici une fonctionnalité de ``<iostream>``:
```
td::cout << "Texte" << std::endl;
```

L'opérateur ``<<`` sert à manipuler **les flux** (suite infinie d'élements gérés de façon temporelle) ou  en anglais : **stream**.

&nbsp;

Code -> <span style="color: pink"> add.cpp </span>

**Enoncé :**
&nbsp;

![Enonce](Images/Capture.PNG)

&nbsp;

**Code :**
```
# include <iostream>

int main() {
    int a =7;
    int b = 5;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    return 0;
}
```
Ce programme nous a permit d'additonner des valeurs numériques et d'afficher le résultat dans la console.

&nbsp;

Résultat :
> ./add
>
> 7 + 5 = 12

&nbsp;

---
# COURS
## Types et variables
---

&nbsp;

## **<span style="color: lightgreen">I- Déclarer une variable**</span>

- Le compilateur doit connaître à l'avance la taille des données.
```
type nomDeVariable = valeur;
```
C'est le nom du type que l'on utilise pour déclarer une variable.

&nbsp;

## **<span style="color: lightgreen">II- Types primitifs**</span>

- >``int`` -> Un entier ( 4 octets )
- >``float`` -> Un décimal ( 4 octets, utilise d'autres registres du processeur)
- >``char`` -> un caractère ASCII ( 1 octet )
- >``bool`` -> Un booléen ( 1 octet)
- >``long`` -> Un gros entier ( 8 octets )
- >``double`` -> Un décimal à double précision ( 8 octets )

&nbsp;

 Les valeurs numériques peuvent être **unsigned**, donc des valeurs que positives:
 - >``char`` (-128..127)
 - > ``**unsigned** char`` (0..255)

Exemple: 
```
int one = 1;
bool isFalse = false;
float someFloat = 0.5f;
double someDouble = 3.4;
```

&nbsp;

## **<span style="color: lightgreen">III- Réassigner une variable**</span>

Une fois une variable déclarée on peu lui réasigner une nouvelle valeur avec le `` = ``

!!!!:warning: UNE VARIABLE NE PEUT PAS CHANGER DE TYPE :warning:!!!!

&nbsp;

**Exemple:**
```
int number = 2;
number = 5;
```

```
char letter = 'a';
letter = 63;
```
&nbsp;

## **<span style="color: lightgreen">IV- Tableaux**</span>

## 1- Pour créer un tableau : 

&nbsp;
```
type nomDeVariable[tailleDuTableau];
```
:warning: Une fois le tableau déclarés, ils conservent leur taille durant toute la durée d'exécution.

&nbsp;

Exemple:
```
float vitesse[8];
int numbers[5] = {4, 8, 3, 2, 4}
```
- Les tableaux sont de tailles fixe et connue à la compilation.

- Un tableau en C/C++ est une succession en mémoire des éléments à partir du premier.

- On peut donc représenter un tableau grâce à un pointeur vers son premier élément,son type et sa taille!

&nbsp;

## 2- Index tableau

&nbsp;

- Pour accéder à l'index du tableau ( ex: 0 qui est le 1er element du tableau), on utilise ``arr`` plus précisement ``arr[n]``

&nbsp;

**Exemple:**
```
int arr[4];
arr[2] = 3.2;
```

&nbsp;

## 3- Taille d'un tableau

&nbsp;


- Si on ne connait pas la taille en éléments d'un tableau, on peut la déduire par sa taille en octets divisé par la taille du premier élément.

```
int length = sizeof(array) / sizeof(array[O])
```
- Si ``sizeof(array)`` est ``0``, on peut écrire :
```
int length = sizeof(array) / sizeof(int)
```

&nbsp;

- Quand on ne connait pas la taille d'un tableau en argument, on peut l'écrire comme ceci -> ``type nomDArgument[]``
- Déclarer un tableau dynamique ``std::vector`` 

&nbsp;

## **<span style="color: lightgreen">V- Chaines de caractères**</span>

- Une chaîne de caractères est un tableau de ``char`` dont le dernier élément est le caractère nul \0.
```
char chaine[20]
```
avec dernier element \0 (nul)

OU 
```
char* chaine = "Bonjour";
```
Voir exo aide -> [code](/Hello[]/hello.cpp)


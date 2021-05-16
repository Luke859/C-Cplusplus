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
## Types et variables
---

&nbsp;

### **<span style="color: green">I- Déclarer une variable**</span>

- Le compilateur doit connaître à l'avance la taille des données.
```
type nomDeVariable = valeur;
```
C'est le nom du type que l'on utilise pour déclarer une variable.

&nbsp;

### **<span style="color: orange">II- Types primitifs**</span>

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

### **<span style="color: lightgreen">III- Réassigner une variable**</span>

Une fois une variable déclarée en peu lui réasigner une nouvelle valeur avec le `` = ``

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


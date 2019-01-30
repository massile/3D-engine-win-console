# Moteur 3D sur l'invité de commandes Windows

### Vidéo associée : [Cliquez ici](https://www.youtube.com/watch?v=MSnGzXLHSvA&feature=share)

Ce projet contruit, à partir de zéro, un moteur de 3D sur l'invité de commandes Windows.

L'objectif du projet était de montrer qu'il est possible de créer son propre moteur à partir:

- des opérations arithmétiques de base (addition, soustraction, multiplication, division)
- de techniques de programmation usuelles (boucles, recursivité, conditions, classes, ...)
- de **beaucoup** de mathématiques

## Contraintes et outils utilisés

**Aucune bibliothèque n'a été utilisée**. Pour pouvoir communiquer avec le système, seuls ces deux fichiers d'entête ont du être importés:

- `<windows.h>` pour pouvoir redimensionner la console et afficher des caractères.
	[Ici](https://github.com/massile/Win32-console-3D-engine/blob/master/window.h#L2) dans le code source.
	
- `<stdio.h>` pour pouvoir lire le contenu d'un fichier. (pour importer des modèles depuis [Blender 3D](https://www.blender.org/)).
[Ici](https://github.com/massile/Win32-console-3D-engine/blob/master/ObjModel.h#L2) dans le code source.

Ce qui nous impose de redéfinir des fonctions mathématiques comme `cosinus`, `sinus` ou encore `racine carrée`.

Le projet a été écrit avec [Sublime Text](https://www.sublimetext.com/3) et compilé avec [MinGW](http://www.mingw.org/) à l'aide de la commande suivante:

```
g++ *.cpp
```
----

### ...Place aux explications  !


# 1. Fonctions mathématiques préliminaires

## Reconstruire les fonctions trigo (cosinus, sinus, cotangente)

Ces fonctions mathématiques sont vitales, elles nous serviront pour définir la [projection en perspective](https://github.com/massile/Win32-console-3D-engine/blob/master/matrix.cpp#L66-L75) et la [rotation](https://github.com/massile/Win32-console-3D-engine/blob/master/matrix.cpp#L30-L55) d'un objet selon un axe.

### Cosinus

#### Cas des grands angles ( > 0.01 radians)

Nous avons besoin d'utiliser la formule trigonométrique suivante:

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Ccos%20%5Ctheta%20%3D%202%5Ccos%28%5Cfrac%7B%5Ctheta%7D%7B2%7D%29%5E2%20-%201)

Cette équation est intéressante car elle définit la fonction cosinus à partir d'**elle-même**, mais avec angle **plus petit**. A première vue cela peut paraître stupide, mais en réalité cela va nous permettre de **restreindre le calcul** de cosinus de (très) petits angles.

Prenons par exemple le cas de `cos(1)`:

En utilisant la formule du dessus:

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Ccos%201%20%3D%202%5Ccos%280.5%29%5E2%20-%201)

Donc pour calculer `cos 1`, il me suffit de calculer `cos(0.5)`, pour calculer `cos(0.5)`... on réitère:

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Ccos%200.5%20%3D%202%5Ccos%280.25%29%5E2%20-%201)

l'angle est divisé par deux à chaque itération, il suffit donc de continuer jusqu'à atteindre un angle suffisamment petit.

#### Cas des (très) petits angles (< 0.01 radians)

Pour de (très) petits angles, on approxime `cosinus` en utilisant son [développement limité](https://fr.wikipedia.org/wiki/D%C3%A9veloppement_limit%C3%A9) autour de 0 (je suis monté à l'ordre 4, mais on aurait pu s'arrêter avant): 

Pour `x` très petit on a donc: 

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Ccos%20x%20%5Capprox%201%20-%20%5Cfrac%7Bx%5E%7B2%7D%7D%7B2%7D%20&plus;%20%5Cfrac%7Bx%5E%7B4%7D%7D%7B24%7D)


En rouge j'ai tracé la fonction cos, et en bleu son développement limité, on voit que pour de petits angles, c'est une bonne approximation.

![](https://image.noelshack.com/fichiers/2019/05/3/1548881564-capture.png)

Son implémentation se trouve [ici](https://github.com/massile/Win32-console-3D-engine/blob/master/math.cpp#L5-L12). J'ai un peu factorisé le développement limité de cosinus pour éviter les calculs redondants.
![](https://latex.codecogs.com/gif.latex?1%20-%20%5Cfrac%7Bx%5E%7B2%7D%7D%7B2%7D%20&plus;%20%5Cfrac%7Bx%5E%7B4%7D%7D%7B24%7D%20%3D%201%20&plus;%20x%5E%7B2%7D%28%5Cfrac%7Bx%5E%7B2%7D%7D%7B24%7D%20-%20%5Cfrac%7B1%7D%7B2%7D%29)

### Sinus

En connaissant `cosinus`, c'est immédiat ! Il suffit de prendre la formule suivante:

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Csin%20x%20%3D%20%5Ccos%20%28x%20-%20%5Cfrac%7B%5Cpi%7D%7B2%7D%29)

Une valeur approximative de `pi` a été écrite en dure dans le fichier [math.h](https://github.com/massile/Win32-console-3D-engine/blob/master/math.h#L7). L'implémentation de sinus se trouve [ici](https://github.com/massile/Win32-console-3D-engine/blob/master/math.h#L7).

### Cotangente

Par définition:

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Ccot%20x%20%3D%20%5Cfrac%7B%5Ccos%20x%7D%7B%5Csin%20x%7D)

 ...et on sait déjà calculer `cosinus` et `sinus` !
 L'implémentation de cotangente se trouve [ici](https://github.com/massile/Win32-console-3D-engine/blob/master/math.cpp#L18-L20).

(ce n'est pas ce qu'il y a de plus optimal, mais c'est largement suffisant)

## Reconstruire racine carrée

Cette fonction nous servira à déterminer la distance en deux points dans l'espace (via le théorème de Pythagore).

![](http://www.univ-st-etienne.fr/wikimastersig/lib/exe/fetch.php/glossaire:distance.png?cache=)

Cela nous sera notamment utile pour les calculs de luminosité (plus un point est éloigné de la source lumineuse, moins il est éclairé)

### Méthode

On souhaite trouver la racine carrée d'un nombre que je vais appeler **`x`**. 
On peut aussi traduire cela, en disant que l'on cherche **`r`** tel que,

![](https://latex.codecogs.com/gif.latex?%5Clarge%20r%20%3D%20%5Csqrt%20x)

ou encore que l'on veut résoudre l'équation,

![](https://latex.codecogs.com/gif.latex?%5Clarge%20%5Csqrt%20x%20-%20r%20%3D%200)

Si on pose,

![](https://latex.codecogs.com/gif.latex?%5Clarge%20f%28x%29%20%3D%20%5Csqrt%20x%20-%20r)

avec ce que l'on a de dit juste avant, rechercher la racine carrée de x, revient à chercher pour quelle valeur de `x` la fonction `f` s'annule.

### Trouver où la fonction s'annule

J'ai utilisé [la méthode de Newton](https://fr.wikipedia.org/wiki/M%C3%A9thode_de_Newton) pour trouver cette valeur. On obtient que la suite U(n) telle que:

![](https://latex.codecogs.com/gif.latex?%5Clarge%20u_%7B0%7D%3Dx)
![](https://latex.codecogs.com/gif.latex?%5Clarge%20u_%7Bn%7D%3D%5Cfrac%7B1%7D%7B2%7D%28u_%7Bn-1%7D%20&plus;%20%5Cfrac%7Br%7D%7Bu_%7Bn-1%7D%7D%29)

converge vers racine de x.

---

Pour obtenir le résultat, il suffit alors de calculer les valeurs successives de U(n) jusqu'à une valeur de `n` suffisamment grande (j'ai pris 50). L'implémentation se trouve [ici](https://github.com/massile/Win32-console-3D-engine/blob/master/math.cpp#L22-L28).

# 2. Créer des pixels avec les caractères de la console.

[TODO]
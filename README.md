# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`

# Étienne Lapointe

### Fonctionnalité choisis

1. **Interface et Expérience Utilisateur**
    - (2) Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres. (2)

2. **Gestion des Données**
    - (1) Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

3. **Corriger un bug**
    - (2) Si on lance sans –data-dir, saveLibraryData essaie d’écrire dans "" et échoue silencieusement.

### Réponses

1. Nous n'avons pas beaucoup explorer la lecture et la sauvegarde de donner dans des fichiers externes, comme les fichiers .txt dans le dossier data. L'entierter du ficher filemanager nous à été fournis sans vrai explication. Même si de première vue, elle partage plusieurs similarité avec le language pithon, le C++ n'est pas exactement pareil.

2. Une première idée de dévellopement serait de remplacer la sauvegarde par ficher texte par des fichiers JSON, et adapté le code pour intéragir plus dynamiquement avec ces fichiers, sans avoir a déclarer les fichers de sauvegarde avec un –data-dir par example. On pourrais aussi pousser se logiciel avec un interface graphique, en reformatant le code sous une structure MCV.
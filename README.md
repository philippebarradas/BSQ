# BSQ - 42 Piscine C projet final

Le plus grand carré :
  1. Il s’agit de trouver le plus grand carré possible sur un plateau en évitant des obstacles.
  2. Un plateau vous est transmis dans un fichier passé en argument du programme.
  3. La première ligne du plateau contient les informations pour lire la carte :
    – Le nombre de lignes du plateau ;
    – Le caractère "vide" ;
    – Le caractère "obstacle" ;
    – Le caractère "plein".

  4. Le plateau est composé de lignes de ’caractère "vide"’ et de ’caractère "obstacle"’.
  5. Lebutduprogrammeestderemplacerles’caractère "vide"’pardes’caractère "plein"’ pour représenter le plus grand carré possible.
  6. Dans le cas où il y en a plusieurs solutions, on choisira de représenter le carré le plus en haut à gauche.

Carte valide :
  1. Toutes les lignes doivent avoir la même longueur.
  2. Il y a au moins une ligne d’au moins une case.
  3. Àlafindechaqueligneilyaunretouràlaligne.
  4. Les caractères présent dans la carte doivent être uniquement ceux présenté à la première ligne.
  5. En cas de carte invalide vous afficherez sur la sortie d’erreur : map error suivi d’un retour à la ligne puis il passera traitement du plateau suivant.

Exemple de fonctionnement :

%>cat example_file\
9.ox\
...........................\
....o......................\
............o..............\
...........................\
....o......................\
...............o...........\
...........................\
......o..............o.....\
..o.......o................\
%>./bsq example_file\
.....xxxxxxx...............\
....oxxxxxxx...............\
.....xxxxxxxo..............\
.....xxxxxxx...............\
....oxxxxxxx...............\
.....xxxxxxx...o...........\
.....xxxxxxx...............\
......o..............o.....\
..o.......o................\
%>\
\
![10042](https://user-images.githubusercontent.com/52048966/113505196-96c57a00-953d-11eb-9be8-a3a58cadf38f.png)

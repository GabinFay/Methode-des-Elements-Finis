# MEF

Imane Hasbaoui
Gabin Fay

Commandes de compilation :
$ cd build/tp5
$ make clean && make && ./tp5.exe

Pour générer automatiquement le fichier contenant les résultats pour plusieurs valeurs du pas h
$ cd build/tp5_plot
$ make clean && make && ./tp5_plot.exe

puis nous avons utilisé le fichier python mef.py pour générer les graphes, en changeant à chaque fois les légendes

######################## Nota Bene ###############################

Le fichier TP3/parameters.c contient les définitions de chaque paramètre de l'équation

Les numéros de référence ne sont pas lus dans un fichier, ils sont directement indiqués dans le programme tp5.c

On a choisi de garder une arborescence suivant l'évolution des TP, mais le code étant terminé, on aurait pu regrouper ADWDW.c, WW.c, W.c dans le même fichier (par exemple) et regrouper les fonctions dans un unique dossier, le nombre de fichiers étant au final assez limité.
Pour plus de simplicité lors du développement, nous avons créé des headers de headers pour chaque TP, afin de s'assurer que les fonctions soient définies. Ce n'est pas optimal.

Enfin, l'utilisation de la mémoire n'est probablement pas optimale, il faudrait peut être utiliser realloc une fois que l'on connaît NbCoefP et NbCoefO, ou utiliser la même zone de mémoire pour les matrices.
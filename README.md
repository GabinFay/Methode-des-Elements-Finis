# MEF 2020

Projet final du module sur la méthode des élements finis du M1 CSM (Calcul Scientifique et Modélisation) de Rennes 1.

Imane Hasbaoui
Gabin Fay

# How to use

Commandes de compilation :
$ cd build/tp5
$ make clean && make && ./tp5.exe

Pour générer automatiquement le fichier contenant les résultats pour plusieurs valeurs du pas h
$ cd build/tp5_plot
$ make clean && make && ./tp5_plot.exe

puis nous avons utilisé le fichier python mef.py pour générer les graphes, en changeant à chaque fois les légendes

# NB

Le fichier TP3/parameters.c contient les définitions de chaque paramètre de l'équation

Les numéros de référence ne sont pas lus dans un fichier, ils sont directement indiqués dans le programme tp5.c

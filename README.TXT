# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.TXT                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: croy <croy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/24 13:27:57 by croy              #+#    #+#              #
#    Updated: 2014/03/24 13:34:54 by croy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

======================= Test du 42sh dossier kelickel =======================

Gros probleme de fuite memoire.

Quand on execute la commande et que l'on fait Ctrl + c : Double affichage du prompt.
Quand on rentre une commande invalide pas de message d'erreur.

Message d'erreur du setenv a modifier => invalid arg of fuction setenv
setenv test test => Segfault.

env -i ./42sh => Le shell s'execute et le setenv fonctionne 
=> Conclusion le probleme du setenv vient de l'allocation memoire du tableau surement.

CTRL + D => On peu rajouter un petit message : exit (mais c'est du detail).

quand on fait le echo avec plus d'un argument =>
______________________________________________________________________________________

$>echo -c lol
-c

______________________________________________________________________________________
commande ls & ls du 42sh

$>ls & ls
242sh		ft_atoi.o	ft_putstr.o	ft_strcmp.o	ft_strnew.c	ft_system.o	main.c
Makefile	ft_env.c	ft_sh.h		ft_strdup.c	ft_strnew.o	ft_unsetenv.c	main.o
builtins.c	ft_exec.c	ft_strcat.c	ft_strdup.o	ft_strsplit.c	ft_unsetenv.o	path.c
builtins.o	ft_exec.o	ft_strcat.o	ft_strlen.c	ft_strsplit.o	get_next_line.c	path.o
ft_atoi.c	ft_putstr.c	ft_strcmp.c	ft_strlen.o	ft_system.c	get_next_line.o
42sh		ft_atoi.o	ft_putstr.o	ft_strcmp.o	ft_strnew.c	ft_system.o	main.c
Makefile	ft_env.c	ft_sh.h		ft_strdup.c	ft_strnew.o	ft_unsetenv.c	main.o
builtins.c	ft_exec.c	ft_strcat.c	ft_strdup.o	ft_strsplit.c	ft_unsetenv.o	path.c
builtins.o	ft_exec.o	ft_strcat.o	ft_strlen.c	ft_strsplit.o	get_next_line.c	path.o
ft_atoi.c	ft_putstr.c	ft_strcmp.c	ft_strlen.o	ft_system.c	get_next_line.o

commande ls & ls dans le zsh & csh

e1r1p6% ls & ls
[1] 72419
Desktop		Downloads	Movies		Pictures
Documents	Library		Music		Public
Desktop		Downloads	Movies		Pictures
Documents	Library		Music		Public
[1]  + done       ls
_______________________________________________________________________________________

Ctrl + Z et FG

mauvaise reaction du shell => il quitte mais ne reviens pas quand on fait fg.
_______________________________________________________________________________________

Commande CD

$>pwd
/nfs/zfs-student/users/2013/croy/Documents/42sh/kelickel
$>cd ..
..
zsh: segmentation fault  ./42sh

$>cd
/nfs/zfs-student/users/2013/croy
zsh: segmentation fault  ./42sh
_______________________________________________________________________________________

Gestion du prompt a faire.
Bug d'affichage pour les caracteres speciaux...
_______________________________________________________________________________________

$> env -i

Affichage de l'environnement alors qu'il ne devrai pas, il faut faire une condition pour dire qu'il n'interpretre que env.
_______________________________________________________________________________________


PRIORITE SUR LES FUITES MEMOIRES ET LES ERREURS POUVANT FAIRE MAL REAGIR LE PROGRAMME BISOUS <3

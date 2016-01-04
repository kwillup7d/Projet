READ ME

Ce programme sert à émuler toutes sortes de jeux de courses sur plateau.

INSTALLATION

L'archive contient un Makefile gnu.
Il suffit d'entrer la commande make pour compiler, puis d'entrer ./game.exe pour utiliser le programme.


HOW TO USE

Tout d'abord vous sera demandé le nombre de cases que vous souhaitez accorder à votre plateau. Un nombre entre 25 et 80 sera demandé. 
Ensuite, il faudra indiquer un nombre de joueurs ( de un à quatre ), combien de robots ( dépendant du nombre de joueurs ) et combien de
pions par joueurs ( minimum un). Chaque joueur devra ensuite indiquer la manière dont il souhaite jouer :

Normal :  On choisit le pion à avancer, et on avance selon le résultat d'un nombre aléatoire entre 1 et 6. Un robot choisira de manière aléatoire
le pion à avancer. Quand on arrive sur une case, un effet peut s'appliquer comme suit :

Toutes les neuf cases, la case fait passer un tour au joueur.

Toutes les treize cases, la case permet au joueur de rejouer.

Toutes les dix-sept cases, la case envoie le pion du joueur au moins sept cases plus loin ( mais au plus à deux cases de l'arrivée ).

Toutes les dix-neufs cases, la case fait reculer le pion d'au moins six cases, sans retourner au départ.

Arriver sur une case déjà occupée ( sauf l'arrivée ) renvoie le pion au départ. Dépasser l'arrivée fait reculer ( depuis l'arrivée ) d'autant.

Question : On choisit le pion à avancer, puis on répond à une question mathématique. En cas de réponse exacte, le pion est avancé tel que ci-dessus, excepté
le fait que les cases de recul ne l'affectent pas. En cas de réponse fausse, le pion reste sur place ou, s'il est sur une case de recul, le pion recule comme
indiqué.

Les questions sont des opérations mathématiques basiques. Pour la division, un arrondi au centième sera demandé. Pour un robot, il a cinquante pour cent de chances
 d'avoir faux.

Cartagena : Toutes les cases possèdent un symbole. "a", "b", "c", ou "d". Chaque joueur commence avec une main de huit cartes, 
chacune ayant un symbole "a", "b", "c" ou "d".

Pour avancer, on choisit une carte, qui nous amène à la première case libre du symbole correspondant.

Une option supplémentaire, "p", nous permet de piocher une carte au prix d'un recul jusqu'à la première case possédant un pion.

Utiliser une carte dont le symbole n'apparait pas au delà du pion revient à passer son tour.

Un robot joue ses cartes aléatoirement, dans la mesure du possible.

Fin du jeu : Le jeu se termine quand un joueur atteint l'arrivée avec tous ses pions. Il gagne la partie et le programme s'arrète.

BUGS CONNUS 

Un SegFault apparaît lors de l'exécution sous Cygwin64, mais pas lors de l'exécution sous logiciel Code::Blocks. Nous n'avons pas eu le temps de 
corriger ce défaut.

Entrer autre chose qu'un nombre lorsqu'un nombre est demandé entraîne un plantage du jeu. Nous n'avons pas eu le temps de corriger ce défaut.

AUTEURS :

REVAUD Gaid
WILLAIME--ANGONIN Kévin

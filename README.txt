READ ME

Ce programme sert � �muler toutes sortes de jeux de courses sur plateau.

INSTALLATION

L'archive contient un Makefile gnu.
Il suffit d'entrer la commande make pour compiler, puis d'entrer ./game.exe pour utiliser le programme.


HOW TO USE

Tout d'abord vous sera demand� le nombre de cases que vous souhaitez accorder � votre plateau. Un nombre entre 25 et 80 sera demand�. 
Ensuite, il faudra indiquer un nombre de joueurs ( de un � quatre ), combien de robots ( d�pendant du nombre de joueurs ) et combien de
pions par joueurs ( minimum un). Chaque joueur devra ensuite indiquer la mani�re dont il souhaite jouer :

Normal :  On choisit le pion � avancer, et on avance selon le r�sultat d'un nombre al�atoire entre 1 et 6. Un robot choisira de mani�re al�atoire
le pion � avancer. Quand on arrive sur une case, un effet peut s'appliquer comme suit :

Toutes les neuf cases, la case fait passer un tour au joueur.

Toutes les treize cases, la case permet au joueur de rejouer.

Toutes les dix-sept cases, la case envoie le pion du joueur au moins sept cases plus loin ( mais au plus � deux cases de l'arriv�e ).

Toutes les dix-neufs cases, la case fait reculer le pion d'au moins six cases, sans retourner au d�part.

Arriver sur une case d�j� occup�e ( sauf l'arriv�e ) renvoie le pion au d�part. D�passer l'arriv�e fait reculer ( depuis l'arriv�e ) d'autant.

Question : On choisit le pion � avancer, puis on r�pond � une question math�matique. En cas de r�ponse exacte, le pion est avanc� tel que ci-dessus, except�
le fait que les cases de recul ne l'affectent pas. En cas de r�ponse fausse, le pion reste sur place ou, s'il est sur une case de recul, le pion recule comme
indiqu�.

Les questions sont des op�rations math�matiques basiques. Pour la division, un arrondi au centi�me sera demand�. Pour un robot, il a cinquante pour cent de chances
 d'avoir faux.

Cartagena : Toutes les cases poss�dent un symbole. "a", "b", "c", ou "d". Chaque joueur commence avec une main de huit cartes, 
chacune ayant un symbole "a", "b", "c" ou "d".

Pour avancer, on choisit une carte, qui nous am�ne � la premi�re case libre du symbole correspondant.

Une option suppl�mentaire, "p", nous permet de piocher une carte au prix d'un recul jusqu'� la premi�re case poss�dant un pion.

Utiliser une carte dont le symbole n'apparait pas au del� du pion revient � passer son tour.

Un robot joue ses cartes al�atoirement, dans la mesure du possible.

Fin du jeu : Le jeu se termine quand un joueur atteint l'arriv�e avec tous ses pions. Il gagne la partie et le programme s'arr�te.

BUGS CONNUS 

Un SegFault appara�t lors de l'ex�cution sous Cygwin64, mais pas lors de l'ex�cution sous logiciel Code::Blocks. Nous n'avons pas eu le temps de 
corriger ce d�faut.

Entrer autre chose qu'un nombre lorsqu'un nombre est demand� entra�ne un plantage du jeu. Nous n'avons pas eu le temps de corriger ce d�faut.

AUTEURS :

REVAUD Gaid
WILLAIME--ANGONIN K�vin

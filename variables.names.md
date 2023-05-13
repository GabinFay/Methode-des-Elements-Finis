# MEF
# ##########  TP1 : variable explorer  ###############
## Création du fichier de maillage ##

char *ficmai : nom du fichier de maillage

int t : type d'éléments

int n1 : nombre de points selon x1

int n2 : nombre de points selon x2

int nrefdom : numéro de référence du domaine

int nrefcot[4] : numéro de référence des bords du domaine

int nbtel : nombre total d'éléments {m}

int nbtng : nombre total de noeuds {n, NbLign}

int nbaret : nombre d'arêtes par élément {q}

int nbneel : nombre de noeuds par élément, {p}

# Lecture du fichier de maillage

int nRefAr[nbtel][nbaret] : numéros de référence des arêtes de tous les éléments

float coord[nbtng][2] : coordonnées de tous les noeuds du maillage

int ngnel[nbtel][nbneel] : numéros globaux des noeuds de tous les élements



# ##########   TP2a : Variable explorer   ############

float *xref : cordonnées d'un point dans l'élément de référence

float *x : coordonnées d'un point dans K (x = transFK(xref))

int q : nombre de points de quadrature

float wk[q] : poids de quadrature

float xk[q][2] : coordonnées des points de quadrature

float x[2] : coordonnées d'un point

float fctbas[nbneel] : valeur des nbneel fonctions de base de l'élément de référence

float derfctbas[nbneel][2] : valeur des dérivées par rapport à x1 et x2 des nbneel fonctions de base de l'élément de référence

float coorEl[nbneel][2] : coordonnées des noeuds d'un élément, |4,2|

int d : dimension de l'espace de départ

float Jac[2][d] : JFK : d = 1 : segment, 

float M[2][2] : une matrice 2x2 à inverser

float det : determinant de la matrice à inverser

float invertM[2][2] : inverse de la matrice 2x2

float invJac[2][2] : l'inverse de la matrice Jacobienne de FK

float x[2] : coordonnées dans K  d'un point de l'element de référence

int num_ar : numéro local d'une arête

int nunear[2] : numéro locaux des sommets d'une arête

float coorEns[variable][2] : coordonnées d'un ensemble de points du maillage

float coorSel[nb][2] : coordonnées des nb points choisis dans coorEns

int nb : nombre de points de coorEns à sélectionner

int num : numéros des points de coorEns que l'on souhaite sélectionner

# ##################   TP2b : Variable Explorer   #################"

float eltdif : poids de quadrature * abs(det(JFK))

float cofvar : FOMEGA(x), FN(x), BN(x) ou AOO(x)

float A[2][2] : [A11(x), A12(x) ; A21(x), A22(x)]

int K = numéro d'un élément, 0<=K<nbtel (progra), 1<=K<=nbtel (maths)

float MatElem[nbneel][nbneel] : matrice élémentaire finale

float MatAret[2][2] : matrice élémentaire d'arête
|nbneel,2|

float SMbrElem[nbneel] : second membre élémentaire final

float SMbrAret[2] : second membre élémentaire d'arête
|nbneel|

int nRefArEl[nbaret] : numéros de référence des arêtes d'un élément

int NuDElem[nbneel] : indique si les noeuds de l'élément appartiennent à Dirichlet

int uDElem[nbneel] : NuDElem[I] =-1 => uDelem[I] = UD(coor[ngnel[K][I]]))

int nbRefD0 : nombre de bords du domaine avec condition Dirichlet homogène

int nbRefD1 : nombre de bords du domaine avec condition Dirichlet non homogène

int nbRefF1 : nombre de bords du domaine avec condition Neumann/Fourier

int numRefD0[nbRefD0] : numéros de référence des bords Dirichlet homogène

int numRefD1[nbRefD1] : numéros de référence des bords Dirichlet non homogène

int numRefF1[nbRefF1] : numéros de référence des bords Neumann/Fourier

float coorAr[2][2] : coordonnées des sommets d'une arête : {{x1,y1}, {x2,y2}}


# ============ TP3 Variable Explorer ==============

Nblign = nbtng;

int NbCoefMax = 0.5*nbtng*(nbtng-1) #nombre maximum d'éléments de LowMat

A[nbtng][nbtng] : matrice pleine résultant de l'assemblage. On ne la créera pas. à ne pas confondre avec A[2][2], matrice des coeffs A11 etc ..

int NbCoef : nombre de coefficients mémorisés, NbCoef = AdPrCoefLi(nbtng) - 1
NbCoef <= NbCoefMax

float DiagMat[nbtng] : coefficients diagonaux de A

float LowMat[NbCoef] : coefficients mémorisés de la partie triangulaire inférieure stricte de A

float Matrice[>=(nbtng+NbCoef)] : matrice assemblée, Matrice = DiagMat][LowMat; ][ signifie concaténation

int AdPrCoefLi[>=nbtng] : contient pour chaque ligne de LowMat, la position du 1er coef !=0 de cette ligne,
    
    AdPrCoefLi[I-1] = la position (ds LowMat) du 1er coef de la ligne I de A.
    AdPrCoefLi[I-1] = 0 si la ligne est nulle (diag non compris)

int AdSuccLi[>=NbCoef] : contient pour chaque coef de LowMat, la position du coef suivant (sur la meme ligne)
                    
                       = 0 si le coef est le dernier mémorisé sur la ligne.

int NumCol[>=NbCoef] : numero de colonne du coef.


float SecMembre[>=nbtng] : second membre assemblé

int NumDLDir[nbtng] : indique si le noeud global appartient à Dirichlet

float ValDLDir[nbtng] : indique la valeur en le noeud global de la condition de Dirichlet

int I : numéro global d'un élément

int J : autre numéro global du même élément que I

float X : A[I][J] = X = MatElem[i][j]

int NextAd : indice dans LowMat du prochain emplacement disponible.

assmat_ : - crée le coef de la colonne J de la ligne I de A, 
            dans LowMat à l'adresse (position) indiqué par NextAd,
            si ce coef n'existe pas : A[I][J] = X, 
            si ce coef existe deja ds LowMat : A[I][J] += X


# #########  TP4  #################

int NbCoefO : NbCoefO <= NbCoef
float MatriceO[nbtng+NbCoefO] : Matrice Ordonnée
float SecMembO[nbtng] : Second Membre Ordonnée
float DiagMat[nbtng] : Coefficients diagonaux de Matrice0
float LowMat[NbCoefO] : Coeffs ordonnés de la matrice triangulaire inférieure de MatriceO
int AdPrCoLiO[nbtng] : AdPrCoLiO(nbtng-1) = NbCoef+1;
int NumColO[NbCoefO] : 


# ################ TP5  ################

int NbCoefP = Profil[nbtng-1] -1;
int Profil[nbtng] :
float MatProf[nbtng+NbCoefP] :
|nbtng + NbCoefMax|

float U[nbtng] : solution approchée :
float UEX[nbtng] : solution exacte :
int codret : code de retour pour tester la validité de dmoapr
float DiagMatProf[nbtng];

float LowMatProf[NbCoefP];
|NbCoefMax|

float DiagL[nbtng];

float LowMatL[?];
|NbCoefMax|

float eps : #seuil de singularité de MatProf#

int nucas : numéro du cas traité

//TP2: initialisation des n premiers éléments d'un tableau à 0
//Objectifs du TP: 
//      - Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire.
//      - codage de la fonction InitWithZero à partir de l'ACSL
//      - preuve

#define SIZE_MAX 1000

/*@
  @ requires R1: 0<n && n < SIZE_MAX; //Analyse cette clause requires à mettre ici. Faire de même pour chaque ligne du contrat ACSL.
  @ requires R2: \valid(t+(0..n-1));
  @ ensures E1: \forall integer k; 0<=k<n ==> t[k]==0;
  @ assigns t[0..(n-1)];
*/
void InitWithZero(int *t, int n) {
	int i;

	/*@
	  @ loop invariant I_RANGE_i: 0 <= i <= n; //Analyse cette clause loop invariant à mettre ici. Faire de même pour chaque ligne du contrat ACSL.
	  @ loop invariant I_E1: \forall integer k; 0<=k<i ==> t[k]==0;
	  @ loop assigns i, t[0..(n-1)];
	  @ loop variant n-i;
	*/
	for(i=0;i<n;i++) {
		t[i] = 0;
	}

}

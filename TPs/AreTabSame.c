//La fonction doit retourner 1 si les n premiers éléments des tableaux T1 et T2 sont égaux, ou 0 dans le cas contraire. 
//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. Penser à mettre un commentaire en bout de chaque ligne d'ACSL (comme pour les TPs précédents)
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

/*@ requires n>0;
  @ assigns \nothing; 
  @ behavior B1:
  @   assumes n==2 && T1 ==  T2; 
  @   ensures .\result == 1;
  @ behavior B2:
  @   assumes n==2 && T1 !=  T2; 
  @   ensures .\result == 0;
  @ complete B1, B2;
  @ disjoint B1, B2;
*/
_Bool AreTabSame(int *T1, int *T2, int n) {

  int i = 0;

  /*@
	  @ loop invariant I_RANGE_i: 0 <= i <= n; //Analyse cette clause loop invariant à mettre ici. Faire de même pour chaque ligne du contrat ACSL.
	  @ loop invariant I_E1: \forall integer k; 0<=k<i ==> T1[k]==T2[k];
	  @ loop assigns i, t[0..(n-1)];
	  @ loop variant n-i;
	*/

  for (i=0;i<n;i++){
    if(T1[i] != T2[i]) return 0;
  }
  return 1;
}

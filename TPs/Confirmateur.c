//TP1: Réalisation d'un confirmateur
//Objectifs du TP: 
//	- Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire
//	- codage de la fonction confirmateur à partir de l'ACSL
//	- preuve

//Entrée:
_Bool E;

//Sortie:
_Bool S;

//Compteur (état interne) = nombre de ticks d'une horloge temps-réel
static unsigned int Cpt;

//Temps de confirmation (configuration) en nombre de de ticks de la même horloge temps-réel
extern unsigned int ConfTime;


/*@
  @ requires ConfTime >= 1; //La variable ConfTime nécessite d'avoir une valeur égale ou supérieure à 1.
  @ assigns S, Cpt;     // Seules les variables S et Cpt doivent être modifiées/mises à jour dans la fonction.
  @ behavior OutputSetTo1: // Début du comportement OutputSetTo1 permettant de composer la fonction en plusieurs comportements distincts, possibles
  @   assumes E == 1 && Cpt >= ConfTime; // Condition d'activation du comportement OutputSetTo1 (ce comportement va s'activer si E est egal à 1 et si Cpt est superior ou égal à Conftime au début de l'appel de la fonction)
  @   ensures Output: S == 1;            // Il vérifie que la condition S == 1 est garantie dans le post state.
  @   ensures Cpt == \old(Cpt) + 1;      // Il vérifie que cette condition liée à Cpt est garantie dans le post state.
  @   assigns S, Cpt;                    // Seules les variables S et Cpt doivent être modifiées/mises à jour dans la fonction.
  @ behavior OutPutSetTo0Input0:         // Début du comportement OutPutSetTo0Input0
  @   assumes E == 0;                    // Condition d'activation du comportement OutPutSetTo0Input0 (ce comportement va s'activer si E == 0 au début de l'appel de la fonction)
  @   ensures S == 0;                    // Il vérifie que la condition S == 0 est garantie dans le post state.
  @   ensures Cpt == 0;                  // Il vérifie que la condition Cpt == 0 est garantie dans le post state.
  @   assigns S, Cpt;                    // Seules les variables S et Cpt doivent être modifiées/mises à jour dans la fonction.
  @ behavior OutPutSetToInput1NotConfirmed: // Début du comportement OutPutSetToInput1NotConfirmed
  @  assumes E == 1 && Cpt < ConfTime;      // Condition d'activation du comportement OutPutSetToInput1NotConfirmed (ce comportement va s'activer si E == 1 et si Cpt est inférieur à ConfTime au début de l'appel de la fonction)
  @  ensures S == 0;                        // Il vérifie que la condition S == 0 est garantie dans le post state.
  @  ensures Cpt == \old(Cpt) + 1;          // Il vérifie que la condition Cpt == \old(Cpt) + 1 est garantie dans le post state.
  @  assigns S, Cpt;                        // Seules les variables S et Cpt doivent être modifiées/mises à jour dans la fonction.
  @
  @ complete behaviors OutputSetTo1, OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed; // Tous les cas listés sont possibles, au moins un des comportements doit avoir son assumes vrai. Il ne manque aucun cas. 
  @ disjoint behaviors OutputSetTo1, OutPutSetTo0Input0;                                // OutputSetTo1 et OutPutSetTo0Input0 sont exclusifs, ils ne peuvent pas s'appliquer simultanémenet pour éviter toute ambiguité
  @ disjoint behaviors OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed;                // OutPutSetT0Input0 et OutPutSetToInput1NotConfirmed sont exclusifs, ils ne peuvent pas s'appliquer simultanémenet pour éviter toute ambiguité
  @ disjoint behaviors OutputSetTo1, OutPutSetToInput1NotConfirmed;                     //  OutputSetTo1 et OutPutSetToInput1NotConfirmed sont exclusifs, ils ne peuvent pas s'appliquer simultanémenet pour éviter toute ambiguité
*/
void Conf(void) {

  if(E==0){
    Cpt = 0;
    S = 0;
  } else {
    if (Cpt>=ConfTime) {
      S = 1;
    } else {
      S = 0;
    }
    Cpt++;  
  }
}

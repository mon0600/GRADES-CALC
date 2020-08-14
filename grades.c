#include  <stdio.h>
#include  <math.h>


/*FUNCTIN CALCULATES NUMERIC SCORE*/
double numeric_score (int am, int deduct, int grd[], int weit [], int leit[], int dropped[]){
  int l;
  double pure = 0;
  double late_penalty = 0;
  double pure_divided;
  for (l = 1; l <= am; l++){
    late_penalty = (grd[l]-(deduct * leit[l]));
    if (late_penalty < 0){
      late_penalty = 0; 
  }
  pure +=  late_penalty * (weit[l] * .01 * dropped[l]);


  pure_divided += (weit[l] * dropped[l]);
  
  }
  
  
  return (pure/pure_divided) *100;
}

/*FUNCTION CALCULATES MEAN*/
double mean (int am, int deduct, int grd[], int leit[]){
  int l;
  double cure =0;
  double pure = 0;
  double late_penalty = 0;
 /* double min;
  double vari;
  double sqrtt;*/

  for (l = 1; l <= am; l++){
    late_penalty = (grd[l]-(deduct * leit[l]));
    if (late_penalty < 0){
      /* makes the late penalty score instead of a negative number*/
      late_penalty = 0; 
      
  }
  cure +=  late_penalty ;
  pure = (cure/am);
  }

 
  return pure;
}

/*FUNCTION CALCULATES THE STANDARD DEVIATION; SQUARED*/
double stan_dev (int am, int deduct, int mean3, int grd[], int leit[]){
  int l ;
  double minused = 0;
  
  double variance = 0;
  double roott = 0;
  double late_penalty = 0;
  
 for (l = 1; l <= am; l++){
   late_penalty = (grd[l] - (deduct * leit[l]));

    if (late_penalty < 0){
      late_penalty = 0; 
      minused = late_penalty;

    }else{
   minused = (late_penalty - mean3);
 }
   variance += minused * minused;
   
  }
  
  roott = (variance/am);
  
  
  return roott;


}


int main(){

  

  int num = 0, grde = 0, w8 = 0, l8 = 0;
  int q;
  #define MAX_ASSIGN 51
  double score1 = 0;
  double mean1 = 0;
  int  drop = 0;
  char stat;
  int ppdl = 0, number_assign = 0;
  int i, j, k, p;

  int w8_total = 0;

  int score [MAX_ASSIGN];
  int weight [MAX_ASSIGN];
  int late [MAX_ASSIGN];
  int value [MAX_ASSIGN];
  int drop_G [MAX_ASSIGN];
  int curr = 0;
  int tmp = 100000;
  double pure1;
  double pure2;


  scanf(" %d %d %c", &ppdl, &drop, &stat);
  scanf(" %d", &number_assign);

  /* ARRANGE INTO ARRAY */


  for(q = 1; q <= number_assign; q++){

  scanf( " %d, %d, %d, %d", &num, &grde, &w8, &l8);
  
  score[num] = grde;
  weight[num] = w8;
  late[num] = l8;
  value[num] = grde * w8;
  drop_G[num] = 1;

  w8_total += w8;
  }

  if ( w8_total != 100 ){
  
  printf("ERROR: Invalid values provided\n");
  }else {

/* puts 0s in place of ones iin drop array
* so as to make the score zero; helps in calculations*/
  if (drop > 0){
  for(j = 1; j <= drop; j++){
   tmp = 100000;
  
      for (k = 1; k <= number_assign; k++){
        
      
       

        if (value[k] < tmp && drop_G[k] * 100 != 0) {
          tmp = value[k];
          curr = k;
          
           }
       
           
       }

       /* runs trhough array one more time to find out if any two scores are same;
       drops the value with the lowest position */
       for (p = 0; p <= number_assign; p++){
        if (value[curr] == value [p]){
          if ( p < curr){
            drop_G[p] = 0;
          }else {
            drop_G[curr] = 0;
          }
        }

       }
          
           /*printf("curr is %d\n", drop_G[curr]);*/
  }
  }

/*for (l = 1; l<= number_assign; l++ ){
  printf("drop assignment %d --> %d", l, drop_G[l]);
  printf("value of k is %d\n", value[l]);
}*/

  score1 = numeric_score(number_assign, ppdl, score, weight, late, drop_G );
  mean1 = mean(number_assign, ppdl, score, late);
  pure1 = stan_dev(number_assign, ppdl, mean1, score, late);
  /*finds square root of squared standard deviation*/
  pure2 = sqrt(pure1);
      printf("Numeric Score: %5.4f\n", score1);

      printf("Points Penalty Per Day Late: %d\n", ppdl);
 
      printf("Number of Assignments Dropped: %d\n", drop);
  
      printf("Values Provided: \n");

      /*print data */
      printf("Assignment, Score, Weight, Days Late\n");
      for(i = 1; i <= number_assign; i++) {
    	printf("%d, %d, %d, %d\n", i, score[i], weight[i], late[i]);

     




  }

    if (stat == 'y'|| stat =='Y'){

         printf("Mean: %5.4f, Standard Deviation: %5.4f\n", mean1, pure2);

      }
}

  return 0;
}

/*
 * CALCULO DETERMINANTE 3 X 3
 * 05 / 09 / 2018
 * netinho340@gmail.com
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	
	int vetor[3][3] = {
		{1, 3, 4},
		{2, 9, 5},
		{7, 2, 0}};

/* DIAGONAL PRINCIPAL  = 161
 * DIAGONAL SECUNDARIA = 287
 		{1, 3, 4|1, 3}
		{2, 9, 5|2, 9}
		{7, 7, 0|7, 7} */

	int vetor_dp[3][3];
	int vetor_ds[3][3];
	int vetor_tmp[3][3];
	
	static int i, j, q, tmp, det, tmp_2;

	det = 0;
	
	cout << "Matriz Original\n";
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cout << vetor[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "-----\n";
	/* ordena a matriz de forma que
	 * o calculo da diagonal principal
	 * fica em colunas. */
	
	 cout << "Diagonal Principal ordenada em colunas\n";
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			q = (i + j) % 3;
			vetor_dp[i][j] = vetor[i][q];
			cout << vetor[i][q] << " ";
		}
		cout << '\n';
	}
	cout << "-----\n";
	/* ira multiplicar cada coluna para
	 * achar a diagonal principal. */
	 for(i = 0; i < 3; i++){
		 tmp = 1;
		 for(j = 0; j < 3; j++){
			 tmp *= vetor_dp[j][i];
		 }
		 det += tmp;
	 }
	 
	 /* ordena a matriz de forma que o
	  * calculo da diagonal secundaria
	  * fique em colunas */
	cout << "Reordena a Matriz de modo que a Diagonal Secundaria passe a ser o calculo da Diagonal Principal\n";
	 for(i = 0; i < 3; i++){
		 for(j = 2; j > -1; j--){
			 q = (i + j) % 3;
			 cout << vetor[i][q] << ' ';
			 vetor_tmp[i][j] = vetor[i][q];
		 }
		 cout << '\n';
	 }
	 cout << "-----\n";
	 cout << "Ordena a Matriz anterior de modo que a Diagonal Secundaria fique em colunas\n";
	 for(i = 0; i < 3; i++){
		 for(j = 0; j < 3; j++){
			 q = (i + j) % 3;
			 cout << vetor_tmp[i][q] << " ";
			 vetor_ds[i][j] = vetor_tmp[i][q];
		 }
		 cout << '\n';
	 }
	 cout << "-----\n";

	/* ira multiplicar cada coluna para 
	 * achar a diagonal secundaria */
	 tmp_2 = 0;
	 for(i = 0; i < 3; i++){
		 tmp = 1;
		 for(j = 0; j < 3; j++){
			 tmp *= vetor_ds[j][i];
		 }
		 tmp_2 += tmp;
	 }
	 
	 det += ( -1 * tmp_2 );
	 
	 cout << '\n' <<"O valor do determinante e': " << det << '\n';
	 
	return 0;
}

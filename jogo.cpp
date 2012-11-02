#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

/* TODO
-- 
*/
	/* Variaves necessarias par ao funcionamento do programa.*/
	int acao;
	int sairDoJogo = 0;
	char menu;
	int morte = 0;
	int rounds = 1;
	int result_of_battle;
	static float exp_gain;
	int num_rand;

	/* {Atk, Def, Exp} */
	static float lukas[3] = {10,10,100};
	static float person[3] = {10,10,100};

	/* Declração dos poderes */
	static float soco = 5;
	static float chute = 6;
	static float defesabasica = 10;
	static int poderes[3] = {5,6,10};

	/* Variaveis usadas para realizar o Combo */
	int golpe1, golpe2, golpe3;


	/* Formula para calculo do dano, soco+atk+exp. */
	static int dano_lukas;
	static int dano_person;
	static float life_lukas = 100;
	static float life_boot = 100;
	static int life_boot_inicial = 100;
	/* Array com os poderes pelos poderes e pelos ganhos de XP para liberação.
	Declara a matriz.
	array[1][1] = {codigo do golpe};
	array[1][2] = {dano do golpe};
	array[1][3] = {quanto de xp precisa para ser liberado} 
	static float poderes[5][2]; */

int main(){

	/* Core do jogo  */
	while (sairDoJogo == 0) {
		cout << "----" << endl;
		cout << "Seja bem vindo ao RPGPrompt!" << endl;
		cout << "Menu: 1 -- Inicar luta.  2 -- Sair do jogo.  3 -- Meu STatus" << endl;
		cin >> menu;

		switch (menu){
			case '1':
				while (morte == 0) {	
				cout << "############# Round "<<rounds<<"!!"<<endl;
				cout << " Lista de Skills:" << endl;
				cout << "1 --- Soco" << endl;
				cout << "2 --- Chute" << endl;
				cout << "3 --- Defesa basica" << endl;				

				/* Código reposavél por gerenciar o COMBO! */
				int num_aleatorio = rand() % 5 + 0;
				if (num_aleatorio >= 4)
				{
					cout << "Combo! Você ganhou a chance de realizar um combo!" << endl;
					cin >> golpe1;
					dano_lukas = ((poderes[golpe1-1]+lukas[0])+lukas[2]);
					cin >> golpe2;
					dano_lukas = (((poderes[golpe2-1]+lukas[0])+lukas[2])+dano_lukas);
					cin >> golpe3;
					dano_lukas = (((poderes[golpe3-1]+lukas[0])+lukas[2])+dano_lukas);

				} else {
					cin >> acao;
					dano_lukas = ((poderes[acao-1]+lukas[0])+lukas[2]);
				}
				
				/* Calculo do dano de cada round */
				num_rand = rand() % 2 + 0;
				dano_person = ((poderes[num_rand]+person[0])+person[2]);
				
				/* Mostra o resultado do dano */
				cout << "Lukas ataca causandao um dano de:" << dano_lukas << endl;
				cout << "Person ataca causando um dano de: " << dano_person << endl;
				result_of_battle = dano_lukas-dano_person;	
				/* Caso o dano do boot seja maior que o do lukas, lukas leva o dano e mostra a mensagem */
				if (result_of_battle < 0)
				{
					life_lukas = life_lukas-abs(result_of_battle);
					cout << "Lukas recebe o dano! Life:" << life_lukas << endl;
					/* Se o life de lukas chegar a zero, ele morre */
					if (life_lukas < 0) { 
						morte = 1;
						cout << "Loser! Você morreu!" << endl;
					}
				} else if (result_of_battle == 0)
				{
					cout << "Empate, ninguem recebe o dano!" << endl;
				} else {
					life_boot = life_boot-abs(result_of_battle);
					cout << "Person recebe o dano! Life:" << life_boot << endl;

					if (life_boot < 0) { 
						morte = 1;
						cout << "Winner! Você venceu!" << endl;
						/* Ganho da experiencia  */
						exp_gain = (life_boot_inicial/rounds);
						cout << "Você ganhou "<<exp_gain<<" de experiência!" << endl;
						lukas[2] = lukas[2] + exp_gain;
						lukas[0] = lukas[0] + (exp_gain/10);
						lukas[1] = lukas[1] + (exp_gain/10);
						life_lukas = life_lukas + (exp_gain/10);
					}
				}
				cout << "--------------"<<endl;
				cout << "" << endl;
				rounds = rounds +1;
				}
				break;
			case '2':
				cout << "Saindo do jogo,obrigado por jogar." << endl;
				cout << "Não se esqueça de voltar para ficar mais forte!!" << endl;
				sairDoJogo = 1;
				break;
			case '3':
				cout << "Ataque:" << lukas[0] << endl;
				cout << "Defesa:" << lukas[1] << endl;
				cout << "XP: " << lukas[2] << endl;
				cout << "Life:" << life_lukas << endl;
				break;
			default:

				break;
		}
	}
	return 0;
}
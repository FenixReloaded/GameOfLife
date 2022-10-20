int maximoEixoX = 20;
int maximoEixoY = 20;
int numGeracaoAtual = 0;

void limparTela () {
	system("cls");
}

void tamanhoMapa() {

	limparTela();

	int tamanho = 0;

	printf("Insira o tamanho do mundo no jogo:\n");
	scanf("%d", &tamanho);

	if (10 > tamanho || tamanho > 60) {
		printf("O tamanho inserido deve estar entre 10 e 60\n");
		tamanhoMapa();
		return tamanho;
	}
	maximoEixoX = tamanho;
	maximoEixoY = tamanho;
}

void configuracaoGeral(int matrizJogo[100][100]) {

	limparTela();

	int opcao = 0;

	printf("1 - Alterar tamanho do mundo do jogo\n");
	printf("2 - Voltar\n\n");

	printf("Selecione uma op��o:\n");
	scanf("%d", &opcao);

	limparTela();

	switch (opcao) {

	case 1:
		tamanhoMapa();
		break;

	case 2:
		return;
		break;
	}
}

void insereSerVivo(int matrizJogo[100][100]) {
	while (!0) {
		int posicaoX = 0;
		int posicaoY = 0;

		printf("Insira coordenadas para o nascimento do ser vivo(exemplo: X Y)\n");
		printf("Caso voce queria sair, insira -1 -1\n");
		scanf("%d %d", &posicaoX, &posicaoY);

		if (posicaoX == -1 && posicaoY == -1) {
			return;
		}

		matrizJogo[posicaoY][posicaoX] = 1;

		printf("A posicao %d %d foi marcada como um ser vivo!\n", posicaoX, posicaoY);

		//inserir uma forma de ver o mapa com os locais dos seres que foram criados
	}
}


void tamanhoAtual(){
	printf("Carregando as informacoes salvas sobre o seu jogo. Por favor aguarde...\n");
	Sleep(2000);
	printf("O tamanho atual do mapa do jogo e: %d por %d\n", maximoEixoX, maximoEixoY);
	Sleep(2000);
	printf("Voltando automaticamente para o menu principal...\n");
	Sleep(2000);
}

void creditos() {
	limparTela();
	printf("Projeto Jogo da Vida para a Disciplina de Laboratorio de Programacao LP\n");
	Sleep(2000);
	printf("Pontificia Universidade Catolica de Sao Paulo (PUC-SP), 2022 - Turma COM-MA2A\n");
	Sleep(2000);
	printf("Professor Julio Arakaki\n");
	Sleep(2000);
	printf("Grupo: Alice de Oliveira, Bruno dos Santos, Caio Pereira e Joao Pedro do Carmo\n");
	Sleep(2000);
	printf("Levando voce de Volta ao Menu. Obrigado por visitar os creditos!\n");
	Sleep(4000);

	limparTela();

}

void saida() {
	char opcao = ' ';

	printf("Voce realmente deseja sair do jogo? S - Sim ou N - Nao\n");
	scanf(" %c", &opcao);

	if (opcao == 'S' || opcao == 's'){ 
		printf("Obrigado por jogar o Jogo da Vida!\n");
		printf("Saindo do Jogo... Por favor aguarde enquanto encerramos o jogo corretamente\n\n");
		exit(0);
	}
	else if (opcao == 'N' || opcao == 'n'){
		return;
	}
	else{
		printf("A opcao selecionada e invalida, por favor insira novamente corretamente a opcao!\n\n");
		saida();
	}
}

//exporta o mapa do jogo de uma tela para outra mantendo o jogo funcionando
void copiarMapa(int matrizJogo[100][100], int geracaoSeguinte[100][100]) {

	int auxComanX = 0;

	while (maximoEixoX > auxComanX) {
		
		int auxComanY = 0;
		while (maximoEixoY > auxComanY) {
			geracaoSeguinte[auxComanX][auxComanY] = matrizJogo[auxComanX][auxComanY];
			auxComanY++;
		}
		auxComanX++;
	}

}

/*copia a geracao para a matriz do jogo mantendo o funcionamento correto do codigo 
ao armazenar tudo em suas respectivas posicoes corretamente*/
void copiarGeracao(int matrizJogo[100][100], int geracaoSeguinte[100][100]) {

	int auxComanX = 0;

	while (maximoEixoX > auxComanX) {
		int auxComanY = 0;

		while (maximoEixoY > auxComanY) {

			matrizJogo[auxComanX][auxComanY] = geracaoSeguinte[auxComanX][auxComanY];
			auxComanY++;
		}
		auxComanX++;
	}

}

//faz o funcionamento principal do jogo
void analisaJogo(int matrizJogo[100][100], int geracaoSequinte[100][100]) {

	//roda a pr�xima gera��o do jogo fazendo com que o jogo continue em funcionamento
	int auxComanX = 0;
	while (maximoEixoX > auxComanX) {

		int auxComanY = 0;
		while (maximoEixoY > auxComanY) {

			//verifica as casas vizinhas e  suas respectivas posi��es
			int vizinhos = vizinhoPosicaoAtual(auxComanX, auxComanY, matrizJogo, maximoEixoX, maximoEixoY);

			if (matrizJogo[auxComanX][auxComanY] == 1) {
				if (2 > vizinhos) {
					geracaoSequinte[auxComanX][auxComanY] = 0;
				}
				else if (vizinhos > 3) {
					geracaoSequinte[auxComanX][auxComanY] = 0;
				}
				else {
					geracaoSequinte[auxComanX][auxComanY] = 1;
				}
			}
			else {
				if (vizinhos == 3) {
					geracaoSequinte[auxComanX][auxComanY] = 1;
				}
			}
			auxComanY++;
		}
		auxComanX++;
	}

}

int vizinhoPosicaoAtual(int x, int y, int matrizJogo[100][100], int maxX, int maxY) {

	int vizinhos = 0;

	int cimaX = -1;
	int cimaY = -1;
	int baixoX = 1;
	int baixoY = 1;

	if (0 >= x) {
		cimaX = 0;
	}
	if (0 >= y) {
		cimaY = 0;
	}
	if (x >= maxX - 1) {
		baixoX = 0;
	}
	if (y >= maxY - 1) {
		baixoY = 0;
	}

	int auxComanX = cimaX;

	while (baixoX >= auxComanX) {
		int auxComanY = cimaY;
		while (baixoY >= auxComanY) {
			int novoX = x + auxComanX;
			int novoY = y + auxComanY;

			if (x != novoX || y != novoY) {
				if (matrizJogo[x + auxComanX][y + auxComanY] == 1) {
					vizinhos++;
				}
			}
			auxComanY++;
		}
		auxComanX++;
	}
	return vizinhos;
}

//faz com que o jogador possa visualizar corretamente qual ser� o pr�ximo mapa ap�s o comando de gera��o
//menu de op��es dentro da jogada
void mostrarGeracaoSeguinte(int geracaoSeguinte[100][100]) {

	int auxComanX = 0;
	while (maximoEixoX > auxComanX) {

		int auxComanY = 0;
		while (maximoEixoY > auxComanY) {

			if (geracaoSeguinte[auxComanX][auxComanY] == 0) {

				printf("*", geracaoSeguinte[auxComanX][auxComanY]);
			}
			else {
				printf(" ");
			}
			auxComanY++;
		}
		int quociente = maximoEixoX / 2;
		printf("|"); 

		if (auxComanX == quociente - 2) {

			printf("N�mero de c�lulas vivas �: %d", qtdSeresVivos(geracaoSeguinte));
		}
		if (auxComanX == quociente) {
			printf("Para escolher um padr�o aperte P");
		}
		if (auxComanX == quociente + 1) {
			printf("Para salvar aperte S");
		}
		if (auxComanX == quociente + 2) {
			printf("Para avan�ar aperte A");
		}
		if (auxComanX == quociente + 3) {
			printf("Para simular automaticamente aperte J");
		}
		if (auxComanX == quociente + 4) {
			printf("Para voltar ao menu anterior aperte M");
		}
		if (auxComanX == quociente + 5) {
			printf("Para fazer a limpeza das c�lulas do mundo aperte X");
		}
		printf("\n");
		auxComanX++;
	}

}

//Faz o c�lculo de quantos seres vivos est�o ativos no mapa do jogo
int qtdSeresVivos(int geracaoSeguinte[100][100]) {

	int auxComanX = 0;
	int i = 0;

	while (100 > auxComanX) {

		int auxComanY = 0;

		while (100 > auxComanY) {

			if (geracaoSeguinte[auxComanX][auxComanY] == 1) {
				i++;
			}
			auxComanY++;
		}
		auxComanX++;
	}
	return i;
}

//carrega um jogo salvo de um arquivo externo
void carregarJogo(int matrizJogo[100][100], bool preVisualizacao) {

	char* nomeFileSaveLoad = "salvar-carregar.txt";
	FILE* arquivo;
	char linhasTotais[100];
	char* resultado;

	int i;
	arquivo = fopen(nomeFileSaveLoad, "rt");

	if (arquivo == NULL) {
		printf("Problemas na abertura do arquivo: %s\n", nomeFileSaveLoad);
		return;
	}
	i = 0;

	bool header = true;
	int atual = 0;

	while (!feof(arquivo)) {
		resultado = fgets(linhasTotais, 102, arquivo);

		if (resultado) {
			if (header) {
				char* aux;
				char* item;

				aux = strtok(resultado, ";");
				maximoEixoX = strtol(aux, &item, 10);
				aux = strtok(NULL, ";");
				maximoEixoY = strtol(aux, &item, 10);
				aux = strtok(NULL, ";");
				numGeracaoAtual = strtol(aux, (char**)NULL, 10);
				header = false;
			}
			else {
				int index = 0;

				for (index = 0; 100 > index; index++) {
					char lt = linhasTotais[index];
					if (lt == 'O') {
						matrizJogo[atual][index] = 0;
					}
					else {
						matrizJogo[atual][index] = 1;
					}
				}
				atual++;
			}
		}
		i++;
	}
	if (preVisualizacao) {
		printf("Pr�-Visualiza��o do jogo carregado\n");
		mostrarGeracaoSeguinte(matrizJogo);
		printf("Aperte qualquer tecla para continuar...");
		getch();
	}
	fclose(arquivo);
}

//limpa por completo todas as entradas
void limpezaTotal(int matrizJogo[100][100]) {

	int auxComanX = 0;
	while (100 > auxComanX) {

		int auxComanY = 0;
		while (100 > auxComanY) {
			matrizJogo[auxComanX][auxComanY] = 0;
			auxComanY++;
		}
		auxComanX++;
	}
	limparTela();
	printf("Aplicando configura��es. Isto ser� r�pido, eu prometo...\n");
}
int valorSize = 10; //Come�a com o valor m�nimo poss�vel, pode ser alterado pelo usu�rio

int minSize = 10; //Define o tamanho M�NIMO do campo de jogo
int maxSize = 60; //Define o tamanho M�XIMO do campo de jogo

int atrasoAmostragem = 0; //Define um atraso at� mostrar a pr�xima gera��o

int autoGerar = 0; //Define quantas vezes uma simula��o ir� gerar de pe�as

int geracao = 0; //Indica qual o n�mero da gera��o atual do jogo

bool simularProximo = true; //Indica se tudo est� pronto ou n�o para a pr�xima gera��o


//Limpa totalmente a tela exibida atualmente no console
void limparTelaTotalmente() {
	system("cls");
}

//Abre as configura��es do mundo para o jogador definir novos par�metros e personalizar o jogo
void configuracoes() {

	printf("\n\n");
	printf("Insira o Tamanho do Mapa do Jogo\nValor M�nimo - 10 | Valor M�ximo - 60\t");
	scanf("%i", &valorSize);

	if (valorSize >= minSize && valorSize <= maxSize) {
		int* mapaJogo = malloc(sizeof(int) * valorSize);

		Sleep(2000);

		printf("O valor do mapa do jogo foi setado como %d\n\n", valorSize);
		printf("Carregando o menu inicial. Por favor aguarde...");
		printf("\n\n");
		Sleep(3000);

		limparTelaTotalmente();

		main();
	}
	else {
		printf("O valor inserido � inv�lido, por favor insira um valor que seja no m�nimo 10 e no m�ximo 60\n");
		configuracoes();
	}
}

//Permite que o usu�rio veja qual o valor que est� setado como o tamanho atual do mapa do jogo
void verTamanhoAtual() {

	int opcao = 0; //O Valor da op��o que pode ser escolhido pelo usu�rio na sele��o

	if (valorSize == 10) {
		printf("Carregando Dados Salvos. Por favor aguarde...\n");
		Sleep(1500);
		printf("\n");
		printf("O Tamanho Atual do Mapa � 10 (� o Valor Padr�o, voc� pode alterar este valor no menu inicial do jogo!)\n\n");
		Sleep(3000);
		
		printf("Deseja voltar para o menu inicial do jogo? 1 - Sim | 2 - N�o \n");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1: 
				printf("Levando voc� de volta para o menu do jogo. Por favor aguarde...\n");
				Sleep(2000);
				limparTelaTotalmente();
				main();
				break;
			case 2:
				limparTelaTotalmente();
				verTamanhoAtual();
				break;
		}
	}
	else {
		printf("Carregando Dados Salvos. Por favor aguarde...\n");
		Sleep(1500);
		printf("\n");
		printf("O Tamanho Atual do Mapa � de %d (Voc� pode alterar este valor no menu inicial do jogo!)\n\n", valorSize);

		printf("Deseja voltar para o menu inicial do jogo? 1 - Sim | 2 - N�o \n");
		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("Levando voc� de volta para o menu do jogo. Por favor aguarde...\n");
			Sleep(2000);
			limparTelaTotalmente();
			main();
			break;
		case 2:
			limparTelaTotalmente();
			verTamanhoAtual();
			break;
		}
	}
}

//Cr�ditos aos criadores e professor
void mostrarCreditos() {
	printf("Projeto Jogo da Vida para a Disciplina de Laborat�rio de Programa��o LP\n");
	Sleep(2000);
	printf("Pontif�cia Universidade Cat�lica de S�o Paulo (PUC-SP), 2022 - Turma COM-MA2A\n");
	Sleep(2000);
	printf("Professor J�lio Arakaki\n");
	Sleep(2000);
	printf("Grupo: Alice de Oliveira, Bruno dos Santos, Caio Pereira e Jo�o Pedro do Carmo\n");
	Sleep(2000);
	printf("Levando voc� de Volta ao Menu. Obrigado por visitar os cr�ditos!\n");
	Sleep(4000);
	limparTelaTotalmente();
	main();
}

//Confirma��o e validador de sa�da do jogo
void sairJogo() {

	char opcao = ' ';

	printf("Voc� realmente deseja sair do jogo? S - Sim ou N - N�o\n");
	scanf(" %c", &opcao);

	if (opcao == 'S' || opcao == 's') { //Faz funcionar tanto com letras mai�sculas quanto com letras min�sculas
		printf("Obrigado por jogar o Jogo da Vida!\n");
		Sleep(1000);

		printf("Saindo do Jogo... Por favor aguarde enquanto encerramos o jogo corretamente\n\n");
		Sleep(2000);

		exit(1);
	}
	else if (opcao == 'N' || opcao == 'n') { //Faz funcionar tanto com letras mai�sculas quanto com letras min�sculas
		main();
	}
	else {
		printf("A op��o selecionada � inv�lida, por favor insira novamente corretamente a op��o!\n\n");
		sairJogo();
	}
}

//Mostra todas as op��es dispon�veis quando um jogo estiver em execu��o
void menuInternoJogo() {
	int opcao = 0; //Mostra as op��es do menu interno do jogo

	Sleep(1000);
	printf("\nO que voc� deseja fazer agora?\n");
	printf("1 - Simular Pr�xima Gera��o (Manual)\n");
	printf("2 - Simular Pr�xima Gera��o (Autom�tica)\n");
	printf("3 - Limpar a Tela\n");
	printf("4 - Sair do Jogo\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1: 
			//Simular Pr�xima Gera��o (Manual)
			break;
		case 2:
			//Simular Pr�xima Gera��o (Autom�tica)
			break;
		case 3:
			//Limpar a Tela
			break;
		case 4:
			//Sair do Jogo
			break;
	}
}

//Fun��o principal do funcionamento do jogo
void comecaJogo(valorSize) {
	for (int i = 0; i <= valorSize; i++) {
		printf("\n");
		printf("- ");
		for (int j = 0; j <= valorSize; j++) {
			printf("- ");
		}
	}

	menuInternoJogo(); //Mostra as op��es in-game
}

//Mostra o menu inicial do jogo ao jogador
void aberturaJogo() {

	int opcao = 0; //Op��o do menu

	printf("\n");
	printf("\t\t\t\t\t\t==========================\n");
	printf("\t\t\t\t\t\tBem-Vindo ao Jogo da Vida!\n");
	printf("\t\t\t\t\t\t==========================\n\n");

	printf("Selecione um comando de a��o para prosseguir:\n");
	printf("1 - Jogar\n");
	printf("2 - Configurar Mundo\n");
	printf("3 - Tamanho Atual do Mapa\n");
	printf("4 - Reiniciar Jogo\n");
	printf("5 - Ver Cr�ditos\n");
	printf("6 - Sair do Jogo\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1:
			printf("Aguarde alguns instantes enquanto carregamos o seu jogo...\n\n");
			Sleep(2000);
			printf("Tudo pronto para come�armos a jogar! ;) \n");
			Sleep(2000);
			limparTelaTotalmente();
			comecaJogo(valorSize);
			break;

		case 2:
			configuracoes();
			break;

		case 3:
			verTamanhoAtual();
			break;

		case 4:
			printf("Reiniciando o jogo, por favor aguarde alguns instantes...\n\n\n");
			Sleep(3000);
			limparTelaTotalmente();
			main();
			break;

		case 5:
			mostrarCreditos();
			break;

		case 6:
			sairJogo();
			break;
	}
}
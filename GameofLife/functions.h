int valorSize = 10; //Começa com o valor mínimo possível, pode ser alterado pelo usuário

int minSize = 10; //Define o tamanho MÍNIMO do campo de jogo
int maxSize = 60; //Define o tamanho MÁXIMO do campo de jogo

int atrasoAmostragem = 0; //Define um atraso até mostrar a próxima geração

int autoGerar = 0; //Define quantas vezes uma simulação irá gerar de peças

int geracao = 0; //Indica qual o número da geração atual do jogo

bool simularProximo = true; //Indica se tudo está pronto ou não para a próxima geração


//Limpa totalmente a tela exibida atualmente no console
void limparTelaTotalmente() {
	system("cls");
}

//Abre as configurações do mundo para o jogador definir novos parâmetros e personalizar o jogo
void configuracoes() {

	printf("\n\n");
	printf("Insira o Tamanho do Mapa do Jogo\nValor Mínimo - 10 | Valor Máximo - 60\t");
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
		printf("O valor inserido é inválido, por favor insira um valor que seja no mínimo 10 e no máximo 60\n");
		configuracoes();
	}
}

//Permite que o usuário veja qual o valor que está setado como o tamanho atual do mapa do jogo
void verTamanhoAtual() {

	int opcao = 0; //O Valor da opção que pode ser escolhido pelo usuário na seleção

	if (valorSize == 10) {
		printf("Carregando Dados Salvos. Por favor aguarde...\n");
		Sleep(1500);
		printf("\n");
		printf("O Tamanho Atual do Mapa é 10 (É o Valor Padrão, você pode alterar este valor no menu inicial do jogo!)\n\n");
		Sleep(3000);
		
		printf("Deseja voltar para o menu inicial do jogo? 1 - Sim | 2 - Não \n");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1: 
				printf("Levando você de volta para o menu do jogo. Por favor aguarde...\n");
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
		printf("O Tamanho Atual do Mapa é de %d (Você pode alterar este valor no menu inicial do jogo!)\n\n", valorSize);

		printf("Deseja voltar para o menu inicial do jogo? 1 - Sim | 2 - Não \n");
		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("Levando você de volta para o menu do jogo. Por favor aguarde...\n");
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

//Créditos aos criadores e professor
void mostrarCreditos() {
	printf("Projeto Jogo da Vida para a Disciplina de Laboratório de Programação LP\n");
	Sleep(2000);
	printf("Pontifícia Universidade Católica de São Paulo (PUC-SP), 2022 - Turma COM-MA2A\n");
	Sleep(2000);
	printf("Professor Júlio Arakaki\n");
	Sleep(2000);
	printf("Grupo: Alice de Oliveira, Bruno dos Santos, Caio Pereira e João Pedro do Carmo\n");
	Sleep(2000);
	printf("Levando você de Volta ao Menu. Obrigado por visitar os créditos!\n");
	Sleep(4000);
	limparTelaTotalmente();
	main();
}

//Confirmação e validador de saída do jogo
void sairJogo() {

	char opcao = ' ';

	printf("Você realmente deseja sair do jogo? S - Sim ou N - Não\n");
	scanf(" %c", &opcao);

	if (opcao == 'S' || opcao == 's') { //Faz funcionar tanto com letras maiúsculas quanto com letras minúsculas
		printf("Obrigado por jogar o Jogo da Vida!\n");
		Sleep(1000);

		printf("Saindo do Jogo... Por favor aguarde enquanto encerramos o jogo corretamente\n\n");
		Sleep(2000);

		exit(1);
	}
	else if (opcao == 'N' || opcao == 'n') { //Faz funcionar tanto com letras maiúsculas quanto com letras minúsculas
		main();
	}
	else {
		printf("A opção selecionada é inválida, por favor insira novamente corretamente a opção!\n\n");
		sairJogo();
	}
}

//Mostra todas as opções disponíveis quando um jogo estiver em execução
void menuInternoJogo() {
	int opcao = 0; //Mostra as opções do menu interno do jogo

	Sleep(1000);
	printf("\nO que você deseja fazer agora?\n");
	printf("1 - Simular Próxima Geração (Manual)\n");
	printf("2 - Simular Próxima Geração (Automática)\n");
	printf("3 - Limpar a Tela\n");
	printf("4 - Sair do Jogo\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1: 
			//Simular Próxima Geração (Manual)
			break;
		case 2:
			//Simular Próxima Geração (Automática)
			break;
		case 3:
			//Limpar a Tela
			break;
		case 4:
			//Sair do Jogo
			break;
	}
}

//Função principal do funcionamento do jogo
void comecaJogo(valorSize) {
	for (int i = 0; i <= valorSize; i++) {
		printf("\n");
		printf("- ");
		for (int j = 0; j <= valorSize; j++) {
			printf("- ");
		}
	}

	menuInternoJogo(); //Mostra as opções in-game
}

//Mostra o menu inicial do jogo ao jogador
void aberturaJogo() {

	int opcao = 0; //Opção do menu

	printf("\n");
	printf("\t\t\t\t\t\t==========================\n");
	printf("\t\t\t\t\t\tBem-Vindo ao Jogo da Vida!\n");
	printf("\t\t\t\t\t\t==========================\n\n");

	printf("Selecione um comando de ação para prosseguir:\n");
	printf("1 - Jogar\n");
	printf("2 - Configurar Mundo\n");
	printf("3 - Tamanho Atual do Mapa\n");
	printf("4 - Reiniciar Jogo\n");
	printf("5 - Ver Créditos\n");
	printf("6 - Sair do Jogo\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1:
			printf("Aguarde alguns instantes enquanto carregamos o seu jogo...\n\n");
			Sleep(2000);
			printf("Tudo pronto para começarmos a jogar! ;) \n");
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
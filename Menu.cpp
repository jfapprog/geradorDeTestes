/*
 * Menu.cpp
 *
 *  Created on: 27/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include "Menu.h"

//construtor sem parâmetros
Menu::Menu() :
		questoes(), testes(), opcao(-1), subOpcao(-1)
{
	inicializar();
}

//destrutor
Menu::~Menu()
{
}

//inicializa a lista de questoes e de testes
void Menu::inicializar()
{
	Disciplina mat("Matematica");
	Materia adi1("Adicao", 1, mat);
	Materia sub1("Subtracao", 1, mat);
	Materia adi2("Adicao", 2, mat);
	Materia sub2("Subtracao", 2, mat);
	Materia mul("Multiplicacao", 2, mat);
	Materia num("Numeros", 2, mat);

	questoes.adicionar(Questao(1, adi1, "1 + 3", "4"));
	questoes.adicionar(Questao(2, adi1, "12 + 5", "17"));
	questoes.adicionar(Questao(3, sub1, "9 - 3", "6"));
	questoes.adicionar(Questao(3, sub1, "15 - 12", "3"));
	questoes.adicionar(Questao(1, adi2, "72 + 10", "82"));
	questoes.adicionar(Questao(1, adi2, "54 + 12", "66"));
	questoes.adicionar(Questao(2, sub2, "37 - 7", "30"));
	questoes.adicionar(Questao(3, mul, "3 * 5", "15"));
	questoes.adicionar(Questao(3, mul, "2 * 7", "14"));
	questoes.adicionar(Questao(4, mul, "8 * 6", "48"));
	questoes.adicionar(
			Questao(4, num, "Escreve 83 por extenso", "oitenta e tres"));
	questoes.adicionar(
			Questao(2, sub2,
					"O Manuel leu 50 paginas de um livro com 90 paginas, quantas faltam ler?",
					"40 paginas"));

	Disciplina por("Portugues");
	Materia abc("Abecedario", 1, por);
	Materia sin("Sinais graficos", 2, por);
	Materia sil("Silabas", 2, por);

	questoes.adicionar(Questao(1, abc, "a b c ? e", "d"));
	questoes.adicionar(Questao(1, abc, "a e ? o u", "i"));
	questoes.adicionar(
			Questao(2, abc, "Identifica as vogais na palavra \"escola\"",
					"a e o"));
	questoes.adicionar(
			Questao(3, sin, "Como se chama o sinal\"?\"",
					"ponto de interrogacao"));
	questoes.adicionar(Questao(2, sil, "Quantas silabas tem \"amigos\"?", "3"));
	questoes.adicionar(Questao(2, sil, "Quantas silabas tem \"ontem\"?", "2"));

	Disciplina esm("Estudo do meio");
	Materia cas("Casa", 2, esm);

	questoes.adicionar(Questao(1, cas, "O que fazes no quarto?", "dormir"));
	questoes.adicionar(
			Questao(2, cas,
					"Qual objeto usas na casa de banho? \"toalha\" ou \"panela\"",
					"toalha"));

	Data data(3, 5, 2015);

	testes.adicionar(Teste(data, mat, questoes.gerarTeste(5, mat)));
	testes.adicionar(Teste(data, mat, questoes.gerarTeste(5, mat)));
	testes.adicionar(Teste(data, por, questoes.gerarTeste(5, por)));
	testes.adicionar(Teste(data, esm, questoes.gerarTeste(5, esm)));
}

//retorna a opcao
int Menu::getOpcao() const
{
	return opcao;
}

//retorna a subopcao
int Menu::getSubOpcao() const
{
	return subOpcao;
}

//apresenta o menu e lê a opcão escolhida
void Menu::lerOpcao()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Menu";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Gerir lista de questoes" << endl;
	cout << "2 - Gerir lista de testes" << endl;
	cout << "3 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o subMenu e lê a opcão escolhida
void Menu::lerSubOpcao(int subMenu)
{
	if (subMenu == 1)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Submenu - Gerir lista de questoes";
		cout << "\n--------------------------------------" << endl;
		cout << "1 - Adicionar questao" << endl;
		cout << "2 - Remover questao" << endl;
		cout << "3 - Listar questoes" << endl;
		cout << "4 - Listar questoes de disciplina" << endl;
		cout << "5 - Listar questoes de materia" << endl;
		cout << "6 - Sair do submenu" << endl;
	}
	else
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Submenu - Gerir lista de testes";
		cout << "\n--------------------------------------" << endl;
		cout << "1 - Gerar teste de disciplina" << endl;
		cout << "2 - Gerar teste de materia" << endl;
		cout << "3 - Remover teste" << endl;
		cout << "4 - Listar testes" << endl;
		cout << "5 - Listar testes de disciplina" << endl;
		cout << "6 - Analisar teste" << endl;
		cout << "7 - Resolver teste" << endl;
		cout << "8 - Exportar teste" << endl;
		cout << "9 - Sair do submenu" << endl;
	}
	cout << "\nSubopcao: ";
	string linha = "";
	getline(cin, linha);
	subOpcao = atoi(linha.c_str());
}

//adiciona uma questao à lista de questões
void Menu::adicionarQuestao()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Adicionar questao" << endl;
	string linha1 = "", linha2 = "", linha3 = "";
	cout << "Disciplina: ";
	getline(cin, linha1);
	Disciplina d(linha1);
	cout << "Materia: ";
	getline(cin, linha1);
	cout << "Serie: ";
	getline(cin, linha2);
	Materia m(linha1, atoi(linha2.c_str()), d);
	cout << "Bimestre: ";
	getline(cin, linha1);
	cout << "Enunciado: ";
	getline(cin, linha2);
	cout << "Gabarito: ";
	getline(cin, linha3);
	Questao q(atoi(linha1.c_str()), m, linha2, linha3);
	cout << "\n--------------------------------------" << endl;
	questoes.adicionar(q);
	cout << "Questao adicionada a lista de questoes" << endl;
}

//remove uma questão à lista de questões
void Menu::removerQuestao()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Remover questao" << endl;
	string linha = "";
	cout << "Indice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	cout << "--------------------------------------" << endl;
	int indPoss = questoes.getNumeroQuestoes();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else
	{
		questoes.remover(indice - 1);
		cout << "Questao removida da lista de questoes" << endl;
	}
}

//escreve a lista de questões
void Menu::listarQuestoes() const
{
	cout << "\n--------------------------------------" << endl;
	cout << "A lista tem " << questoes.getNumeroQuestoes() << " questoes";
	cout << "\n--------------------------------------" << endl;
	questoes.escrever();
}

//escreve a lista de questões de uma disciplina
void Menu::listarQuestoesDisc() const
{
	cout << "\n--------------------------------------" << endl;
	string linha = "";
	cout << "Disciplina: ";
	getline(cin, linha);
	Disciplina d(linha);
	cout << "A lista tem " << questoes.getNumeroQuestoes(d) << " questoes de "
			<< d.getNome();
	cout << "\n--------------------------------------" << endl;
	questoes.escrever(d);
}

//escreve a lista de questões de uma matéria
void Menu::listarQuestoesMat() const
{
	cout << "\n--------------------------------------" << endl;
	string linha1 = "", linha2 = "";
	cout << "Disciplina: ";
	getline(cin, linha1);
	Disciplina d(linha1);
	cout << "Materia: ";
	getline(cin, linha1);
	cout << "Serie: ";
	getline(cin, linha2);
	Materia m(linha1, atoi(linha2.c_str()), d);
	cout << "A lista tem " << questoes.getNumeroQuestoes(m) << " questoes de "
			<< m.getNome() << " - Serie " << m.getSerie() << " - "
			<< m.getDisciplina().getNome();
	cout << "\n--------------------------------------" << endl;
	questoes.escrever(m);
}

//gera um teste de uma disciplina e adiciona um teste à lista de testes
void Menu::gerarTesteDisc()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Gerar teste de disciplina" << endl;
	string linha1 = "", linha2 = "", linha3 = "";
	cout << "Dia: ";
	getline(cin, linha1);
	cout << "Mes: ";
	getline(cin, linha2);
	cout << "Ano: ";
	getline(cin, linha3);
	Data data(atoi(linha1.c_str()), atoi(linha2.c_str()), atoi(linha3.c_str()));
	cout << "Disciplina: ";
	getline(cin, linha1);
	Disciplina d(linha1);
	cout << "Numero de questoes: ";
	getline(cin, linha1);
	cout << "--------------------------------------" << endl;
	Teste t(data, d, questoes.gerarTeste(atoi(linha1.c_str()), d));
	t.escrever(true);
	testes.adicionar(t);
	cout << "\nTeste adicionado a lista de testes" << endl;
}

//gera um testes de uma matéria e adiciona um teste à lista de testes
void Menu::gerarTesteMat()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Gerar teste de materia" << endl;
	string linha1 = "", linha2 = "", linha3 = "";
	cout << "Dia: ";
	getline(cin, linha1);
	cout << "Mes: ";
	getline(cin, linha2);
	cout << "Ano: ";
	getline(cin, linha3);
	Data data(atoi(linha1.c_str()), atoi(linha2.c_str()), atoi(linha3.c_str()));
	cout << "Disciplina: ";
	getline(cin, linha1);
	Disciplina d(linha1);
	cout << "Materia: ";
	getline(cin, linha1);
	cout << "Serie: ";
	getline(cin, linha2);
	Materia m(linha1, atoi(linha2.c_str()), d);
	cout << "Numero de questoes: ";
	getline(cin, linha1);
	cout << "--------------------------------------" << endl;
	Teste t(data, m.getDisciplina(),
			questoes.gerarTeste(atoi(linha1.c_str()), m));
	t.escrever(true);
	testes.adicionar(t);
	cout << "\nTeste adicionado a lista de testes" << endl;
}

//remove um teste
void Menu::removerTeste()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Remover teste" << endl;
	string linha = "";
	cout << "Indice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	cout << "--------------------------------------" << endl;
	int indPoss = testes.getNumeroTestes();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else
	{
		testes.remover(indice - 1);
		cout << "Teste removido da lista" << endl;
	}
}

//escreve a lista de testes
void Menu::listarTestes() const
{
	cout << "\n--------------------------------------" << endl;
	cout << "A lista tem " << testes.getNumeroTestes() << " testes";
	cout << "\n--------------------------------------" << endl;
	testes.escrever();
}

//escreve a lista de testes de uma disciplina
void Menu::listarTestesDisc() const
{
	cout << "\n--------------------------------------" << endl;
	string linha = "";
	cout << "Disciplina: ";
	getline(cin, linha);
	Disciplina d(linha);
	cout << "A lista tem " << testes.getNumeroTestes(d) << " testes de "
			<< d.getNome();
	cout << "\n--------------------------------------" << endl;
	testes.escrever(d);
}

//apresenta um teste com todas as questões e seus atributos
void Menu::analisarTeste() const
{
	cout << "\n--------------------------------------" << endl;
	cout << "Analisar teste" << endl;
	string linha = "";
	cout << "Indice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	cout << "--------------------------------------" << endl;
	int indPoss = testes.getNumeroTestes();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else
		testes[indice - 1].escrever(true);
}

//apresenta o enunciado de um teste
void Menu::resolverTeste() const
{
	cout << "\n--------------------------------------" << endl;
	cout << "Resolver teste" << endl;
	string linha = "";
	cout << "Indice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	cout << "--------------------------------------" << endl;
	int indPoss = testes.getNumeroTestes();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else
	{
		testes[indice - 1].escrever(false, true);
		cout << "\n--------------------------------------" << endl;
		cout << "Quando terminar, apresentar gabarito?" << endl;
		cout << "s - sim: ";
		getline(cin, linha);
		cout << "--------------------------------------" << endl;
		if (tolower(linha[0]) == 's')
			testes[indice - 1].escrever(false, true, true);
	}
}

//exporta enunciado e gabarito para ficheiros
void Menu::exportarTeste() const
{
	cout << "\n--------------------------------------" << endl;
	cout << "Exportar teste e gabarito" << endl;
	string linha = "";
	cout << "Indice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	cout << "--------------------------------------" << endl;
	int indPoss = testes.getNumeroTestes();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else
	{
		ofstream fEnu("Enunciado.txt");
		ofstream fGab("Gabarito.txt");
		if (fEnu)
		{
			testes[indice - 1].escrever(false, true, false, fEnu);
			cout << "Enunciado exportado com sucesso" << endl;
		}
		else
			cout << "Erro a exportar o enunciado" << endl;
		if (fGab)
		{
			testes[indice - 1].escrever(false, false, true, fGab);
			cout << "Gabarito exportado com sucesso" << endl;
		}
		else
			cout << "Erro a exportar o gabarito" << endl;
	}
}

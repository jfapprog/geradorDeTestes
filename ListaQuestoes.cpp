/*
 * ListaQuestoes.cpp
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include <cstdlib>
#include "ListaQuestoes.h"

//construtor sem parâmetros
ListaQuestoes::ListaQuestoes()
{
}

//destrutor
ListaQuestoes::~ListaQuestoes()
{
}

//adiciona uma questão ao topo
void ListaQuestoes::adicionar(const Questao &q)
{
	lista.push_back(q);
}

//revome a questão de índice indicado
void ListaQuestoes::remover(int indice)
{
	lista.erase(lista.begin() + indice);
}

//retorna uma referência constante para a questão de índice indicado
const Questao & ListaQuestoes::operator[](int indice) const
{
	return lista[indice];
}

//retorna o número de questões da lista
int ListaQuestoes::getNumeroQuestoes() const
{
	return (int) lista.size();
}

//retorna o número de questões da disciplina indicada
int ListaQuestoes::getNumeroQuestoes(const Disciplina &d) const
{
	int n = 0;
	for (vector<Questao>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
		if (iter->getMateria().getDisciplina() == d)
			n++;
	return n;
}

//retorna o número de questões da disciplina e matéria indicadas
int ListaQuestoes::getNumeroQuestoes(const Materia &m) const
{
	int n = 0;
	for (vector<Questao>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
		if (iter->getMateria() == m)
			n++;
	return n;
}

//escreve a lista de questões
void ListaQuestoes::escrever() const
{
	int n = 1;
	for (vector<Questao>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
	{
		cout << "\n#Questao " << n++ << endl;
		iter->escrever();
	}
}

//escreve a lista de questões da disciplina indicada
void ListaQuestoes::escrever(const Disciplina &d) const
{
	int n = 1;
	for (vector<Questao>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
	{
		if (iter->getMateria().getDisciplina() == d)
		{
			cout << "\n#Questao " << n << endl;
			iter->escrever();
		}
		n++;
	}
}

//escreve a lista da matéria indicada
void ListaQuestoes::escrever(const Materia &m) const
{
	int n = 1;
	for (vector<Questao>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
	{
		if (iter->getMateria() == m)
		{
			cout << "\n#Questao " << n << endl;
			iter->escrever();
		}
		n++;
	}
}

//gera um teste da disciplina indicada e com o número indicado de questões
list<Questao> ListaQuestoes::gerarTeste(int numeroQuestoes,
		const Disciplina &d) const
{
	list<Questao> teste;
	//se o número de questões requerido for superior ou igual ao numQuestDisc insere todas
	if (numeroQuestoes >= this->getNumeroQuestoes(d))
	{
		for (vector<Questao>::const_iterator iter = lista.begin();
				iter != lista.end(); iter++)
			if (iter->getMateria().getDisciplina() == d)
				teste.push_back(*iter);
	}
	else
	{
		//vetor para guardar os índices das questões que são da disciplina indicada
		vector<int> indices;
		int indice = 0;
		//percorre a lista de questões e se é da disciplina indicada guarda o seu índice
		for (vector<Questao>::const_iterator iter = lista.begin();
				iter != lista.end(); iter++)
		{
			if (iter->getMateria().getDisciplina() == d)
				indices.push_back(indice);
			indice++;
		}
		for (int i = 0; i < numeroQuestoes; i++)
		{
			//determina um número aleatório entre 0 e o número de índices
			int alea = rand() % indices.size();
			//coloca a questão com esse índice no teste
			teste.push_back(lista[indices[alea]]);
			//apaga esse índice do vetor de índices
			indices.erase(indices.begin()+alea);
		}
	}
	return teste;
}

//gera um teste da matéria indicada e com o número indicado de questões
list<Questao> ListaQuestoes::gerarTeste(int numeroQuestoes,
		const Materia &m) const
{
	list<Questao> teste;
	//se o número de questões requerido for superior ou igual ao numQuestDisc insere todas
	if (numeroQuestoes >= this->getNumeroQuestoes(m))
	{
		for (vector<Questao>::const_iterator iter = lista.begin();
				iter != lista.end(); iter++)
			if (iter->getMateria() == m)
				teste.push_back(*iter);
	}
	else
	{
		//vetor para guardar os índices das questões que são da materia indicada
		vector<int> indices;
		int indice = 0;
		//percorre a lista de questões e se é da matéria indicada guarda o seu índice
		for (vector<Questao>::const_iterator iter = lista.begin();
				iter != lista.end(); iter++)
		{
			if (iter->getMateria() == m)
				indices.push_back(indice);
			indice++;
		}
		for (int i = 0; i < numeroQuestoes; i++)
		{
			//determina um número aleatório entre 0 e o número de índices
			int alea = rand() % indices.size();
			//coloca a questão com esse índice no teste
			teste.push_back(lista[indices[alea]]);
			//apaga esse índice do vetor de índices
			indices.erase(indices.begin()+alea);
		}
	}
	return teste;
}


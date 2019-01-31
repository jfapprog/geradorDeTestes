/*
 * ListaTestes.cpp
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "ListaTestes.h"

//construtor
ListaTestes::ListaTestes()
{
}

//destrutor
ListaTestes::~ListaTestes()
{
}

//adiciona um teste à lista
void ListaTestes::adicionar(const Teste &t)
{
	lista.push_back(t);
}

//remove o teste de índice indicado
void ListaTestes::remover(int indice)
{
	lista.erase(lista.begin() + indice);
}

//retorna uma referência constante para o teste de índice indicado
const Teste & ListaTestes::operator[](int indice) const
{
	return lista[indice];
}

//retorna o número de testes
int ListaTestes::getNumeroTestes() const
{
	return lista.size();
}

//retorna o número de testes da disciplina indicada
int ListaTestes::getNumeroTestes(const Disciplina &d) const
{
	int n = 0;
	for (vector<Teste>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
		if (iter->getDisciplina() == d)
			n++;
	return n;
}

//escreve a data e a disciplina dos testes
void ListaTestes::escrever() const
{
	int n = 1;
	for (vector<Teste>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
	{
		cout << "\n#Teste " << n++ << endl;
		cout << "Data: " << iter->getData().getDia() << " - "
				<< iter->getData().getMes() << " - " << iter->getData().getAno()
				<< endl;
		cout << "Disciplina: " << iter->getDisciplina().getNome() << endl;
	}
}

//escreve a data dos testes da disciplina indicada
void ListaTestes::escrever(const Disciplina &d) const
{
	int n = 1;
	for (vector<Teste>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
	{
		if (iter->getDisciplina() == d)
		{
			cout << "\n#Teste " << n << endl;
			cout << "Data: " << iter->getData().getDia() << " - "
					<< iter->getData().getMes() << " - "
					<< iter->getData().getAno() << endl;
		}
		n++;
	}
}


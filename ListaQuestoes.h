/*
 * ListaQuestoes.h
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef LISTAQUESTOES_H_
#define LISTAQUESTOES_H_

#include <vector>
#include <list>
#include "Questao.h"

using namespace std;

class ListaQuestoes
{
private:
	vector<Questao> lista;

public:
	ListaQuestoes();
	virtual ~ListaQuestoes();

	void adicionar(const Questao &);
	void remover(int);

	const Questao & operator[](int) const;
	int getNumeroQuestoes() const;
	int getNumeroQuestoes(const Disciplina &) const;
	int getNumeroQuestoes(const Materia &) const;

	void escrever() const;
	void escrever(const Disciplina &) const;
	void escrever(const Materia &) const;

	list<Questao> gerarTeste(int, const Disciplina &) const;
	list<Questao> gerarTeste(int, const Materia &) const;
};

#endif /* LISTAQUESTOES_H_ */

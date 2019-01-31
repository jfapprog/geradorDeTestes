/*
 * Teste.h
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef TESTE_H_
#define TESTE_H_

#include <list>
#include <fstream>
#include "Questao.h"
#include "Data.h"

class Teste
{
private:
	Data data;
	Disciplina disciplina;
	list<Questao> lista;

public:
	Teste();
	Teste(const Data &, const Disciplina &, const list<Questao> &);
	virtual ~Teste();

	const Data & getData() const;
	const Disciplina & getDisciplina() const;

	void escrever(bool, bool = false, bool = false, ostream & =cout) const;
};

#endif /* TESTE_H_ */

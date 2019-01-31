/*
 * ListaTestes.h
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef LISTATESTES_H_
#define LISTATESTES_H_

#include <vector>
#include "Teste.h"

class ListaTestes
{
private:
	vector<Teste> lista;
public:
	ListaTestes();
	virtual ~ListaTestes();

	void adicionar(const Teste &);
	void remover(int);

	const Teste & operator[](int) const;
	int getNumeroTestes() const;
	int getNumeroTestes(const Disciplina &) const;

	void escrever() const;
	void escrever(const Disciplina &) const;
};

#endif /* LISTATESTES_H_ */

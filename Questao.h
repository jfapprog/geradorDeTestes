/*
 * Questao.h
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef QUESTAO_H_
#define QUESTAO_H_

#include "Materia.h"

class Questao
{
private:
	int bimestre;
	Materia materia;
	string enunciado;
	string gabarito;

public:
	Questao();
	Questao(int, const Materia &, string, string);
	Questao(const Questao &);
	virtual ~Questao();

	int getBimestre() const;
	const Materia & getMateria() const;
	string getEnunciado() const;
	string getGabarito() const;

	void setBimestre(int);
	void setMateria(const Materia &);
	void setEnunciado(string);
	void setGabarito(string);

	void escrever() const;
};

#endif /* QUESTAO_H_ */

/*
 * Materia.h
 *
 *  Created on: 25/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef MATERIA_H_
#define MATERIA_H_

#include "Disciplina.h"

class Materia
{
private:
	string nome;
	int serie;
	Disciplina disciplina;

public:
	Materia();
	Materia(string, int, const Disciplina &);
	Materia(const Materia &);
	virtual ~Materia();

	string getNome() const;
	int getSerie() const;
	const Disciplina & getDisciplina() const;

	void setNome(string);
	void setSerie(int);
	void setDisciplina(const Disciplina &);

	bool operator==(const Materia &) const;

	void escrever() const;
};

#endif /* MATERIA_H_ */

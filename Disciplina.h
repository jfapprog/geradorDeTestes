/*
 * Disciplina.h
 *
 *  Created on: 25/04/2015
 *      Author: José Félix Póvoa
 */

#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <string>

using namespace std;

class Disciplina
{
private:
	string nome;

public:
	Disciplina(string ="");
	Disciplina(const Disciplina &);
	virtual ~Disciplina();

	string getNome() const;

	void setNome(string);

	bool operator==(const Disciplina &) const;
};

#endif /* DISCIPLINA_H_ */

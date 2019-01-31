/*
 * Teste.cpp
 *
 *  Created on: 26/04/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Teste.h"

//construtor sem parâmetros
Teste::Teste() :
		data(), disciplina(), lista()
{
}

//construtor elementar
Teste::Teste(const Data &d, const Disciplina &disc, const list<Questao> &l) :
		data(d), disciplina(disc), lista(l)
{
}

//destrutor
Teste::~Teste()
{
}

//retorna a Data
const Data & Teste::getData() const
{
	return data;
}

//retorna uma referência constante para a disciplina
const Disciplina & Teste::getDisciplina() const
{
	return disciplina;
}

//escreve o teste com todas as informações, apenas o enunciado, apenas o gabarito ou ambos
void Teste::escrever(bool completo, bool enunciado, bool gabarito,
		ostream &fout) const
{
	fout << "\nTeste" << endl;
	fout << "Data: " << data.getDia() << " - " << data.getMes() << " - "
			<< data.getAno() << endl;
	fout << "Disciplina: " << disciplina.getNome() << endl;
	int n = 1;
	for (list<Questao>::const_iterator iter = lista.begin();
			iter != lista.end(); iter++)
	{
		fout << "\n#Questao " << n++ << endl;
		if (completo)
			iter->escrever();
		else
		{
			if (enunciado)
				fout << iter->getEnunciado() << endl;
			if (gabarito)
				fout << "G: " << iter->getGabarito() << endl;
		}
	}
}
